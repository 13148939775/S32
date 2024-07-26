//程序介绍：将调用Opencv的工具包来对一些随机数进行聚类，并将结果通过Opencv进行可视化。
//主要是生成一些二维样本数据，每个样本数据都服从高斯分布，我们将通过KMeans算法来对结果进行分类。

#include <iostream>
#include <thread>
#include <chrono>

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv) 
{
 	cv::Mat img(500, 500, CV_8UC3);  
 	cv::RNG rng(12345);  //声明此类用于产生随机数
 	Scalar colorTab[] = {      //定义一个颜色的数组
  		Scalar(0, 0, 255),
  		Scalar(0, 255, 0),
  		Scalar(255, 0, 0),
  		Scalar(0, 255, 255),
  		Scalar(255, 0, 255)
    };
  	const int maxCulster = 5;
  	int numCluster = rng.uniform(2, maxCulster + 1);  //在[2,5)区间，随机生成一个整数
 	printf("number of clusters : %d\n", numCluster);

	int sampleCount = rng.uniform(5, 1000);
 	cv::Mat points(sampleCount, 1, CV_32FC2);  //定义一个矩阵。
 	//points()函数，第一个参数为像素点，第二个参数为列数，第三个参数为类型
 	cv::Mat labels;
 	cv::Mat centers;
 
 	// 生成随机数
 	for (int k = 0; k < numCluster; k++) {
 	 	Point center;   //中心点
  		center.x = rng.uniform(0, img.cols);    //随机点的抽取
  		center.y = rng.uniform(0, img.rows);
  		//图像上一小部分的点找到了
  		cv::Mat pointChunk = points.rowRange(k*sampleCount / numCluster,
            k == numCluster - 1 ? sampleCount : (k + 1)*sampleCount / numCluster);

        // 高斯分布
  		rng.fill(pointChunk, RNG::NORMAL, 
            Scalar(center.x, center.y, 0, 0), Scalar(img.cols*0.05, img.rows*0.05, 0, 0));//用随机数填充矩阵
 	}
 	randShuffle(points, 1, &rng); //将原数组（矩阵）打乱
 	// 使用KMeans
 	kmeans(points, numCluster, labels, 
        TermCriteria(TermCriteria::EPS + TermCriteria::COUNT, 10, 0.1), 3, KMEANS_PP_CENTERS, centers);
 	// 用不同颜色显示分类
 	img = Scalar::all(255);
 	for (int i = 0; i < sampleCount; i++) {  //分类聚类编号，每个点都有编号
 		int index = labels.at<int>(i);
  		Point p = points.at<Point2f>(i);
  		circle(img, p, 2, colorTab[index], -1, 8);
 	}

	// 每个聚类的中心来绘制圆
 	for (int i = 0; i < centers.rows; i++) {
 		int x = centers.at<float>(i, 0);
  		int y = centers.at<float>(i, 1);
  		printf("c.x= %d, c.y=%d", x, y);
  		circle(img, Point(x, y), 40, colorTab[i], 1, LINE_AA);
 	}
 	cv::imshow("KMeans Demo", img);
 	cv::waitKey(0);
 	return 0;
};