#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv) {
    Mat img(500, 500, CV_8UC3);
    RNG rng(12345);
    const int Max_nCluster = 5;
    Scalar colorTab[] = {
        Scalar(0, 0, 255),
        Scalar(0, 255, 0),
        Scalar(255, 0, 0),
        Scalar(0, 255, 255),
        Scalar(255, 0, 255)};
    //int numCluster = rng.uniform(2, Max_nCluster + 1);//随机类数
    int numCluster = 3;
    int sampleCount = rng.uniform(5, 1000);  //样本点数量
    Mat matPoints(sampleCount, 2, CV_64FC1); //样本点矩阵：sampleCount X 2
    Mat labels;
    Mat centers;
    // 生成随机数
    for (int k = 0; k < numCluster; k++) {
        Point center; //随机产生中心点
        center.x = rng.uniform(0, img.cols);
        center.y = rng.uniform(0, img.rows);
        Mat pointChunk = matPoints.rowRange(k * sampleCount / numCluster,
                                            (k + 1) * sampleCount / numCluster);
        //-----符合高斯分布的随机高斯
        rng.fill(pointChunk, RNG::NORMAL, Scalar(center.x, center.y, 0, 0), Scalar(img.cols * 0.05, img.rows * 0.05, 0, 0));
    }
    randShuffle(matPoints, 1, &rng); //打乱高斯生成的数据点顺序
    // EM Cluster Train
    Ptr<ml::EM> em_model = ml::EM::create();
    em_model->setClustersNumber(numCluster);
    em_model->setCovarianceMatrixType(ml::EM::COV_MAT_SPHERICAL);
    em_model->setTermCriteria(TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 100, 0.1));
    em_model->trainEM(matPoints, noArray(), labels, noArray());

    // 用不同颜色显示分类
    img = Scalar::all(255);
    for (int i = 0; i < sampleCount; i++) {
        int index = labels.at<int>(i);
        Point p = Point(matPoints.at<double>(i, 0), matPoints.at<double>(i, 1));
        circle(img, p, 2, colorTab[index], -1, 8);
    }
    // classify every image pixels
    Mat sample(1, 2, CV_32FC1);
    for (int row = 0; row < img.rows; row++) {
        for (int col = 0; col < img.cols; col++) {
            sample.at<float>(0) = (float)col;
            sample.at<float>(1) = (float)row;
            int response = cvRound(em_model->predict2(sample, noArray())[1]);
            Scalar c = colorTab[response];
            circle(img, Point(col, row), 1, c * 0.75, -1);
        }
    }
    imshow("Demo", img);
    waitKey(0);
    return 0;
}
