/***************************************************************************
Module Name:
	KMeans

History:
	2003/10/16	Fei Wang
	2013 luxiaoxun
***************************************************************************/

#pragma once
#include <fstream>

//#include <string.h>
#include <cstring>

class KMeans {
public:
	enum InitMode
	{
		InitRandom,
		InitManual,
		InitUniform,
	};

	KMeans(const int dimNum = 1, const int clusterNum = 2, const int maxIterCnt = 1000);
	~KMeans();

	void SetMean(int i, const double* u){ memcpy(m_means[i], u, sizeof(double) * m_dimNum); }
	void SetInitMode(int i)				{ m_initMode = i; }
	void SetMaxIterNum(int i)			{ m_maxIterNum = i; }
	void SetEndError(double f)			{ m_endError = f; }

	double* GetMean(int i)	{ return m_means[i]; }  // to calc the center
	int GetInitMode()		{ return m_initMode; }
	int GetMaxIterNum()		{ return m_maxIterNum; }
	double GetEndError()	{ return m_endError; }

	/*	SampleFile: <size><dim><data>...
		LabelFile:	<size><label>...
	*/
	void Cluster(const char* sampleFileName, const char* labelFileName);
	void Init(std::ifstream& sampleFile);
	void Init(double *data, int N);
	void Cluster(double *data, int N, int *Label);
	friend std::ostream& operator<<(std::ostream& out, KMeans& kmeans);

private:
	int m_dimNum;
	int m_clusterNum;
	double** m_means;

	int m_initMode;
	int m_maxIterNum;		// The stopping criterion regarding the number of iterations
	double m_endError;		// The stopping criterion regarding the error

	double GetLabel(const double* x, int* label);
	double CalcDistance(const double* x, const double* u, int dimNum);
};
