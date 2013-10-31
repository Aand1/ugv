////////////////////////////////////////////////////
//
//  Ŭ���� : CBlobLabeling
//
//                    by ��ƾ(http://martinblog.net)
#pragma once

//#include <cv.h>
#include "opencv2/highgui/highgui.hpp"
#define FALSE 0
#define TRUE 1
typedef struct 
{
	bool	bVisitedFlag;
	CvPoint ptReturnPoint;
} Visited;

class  CBlobLabeling
{
public:
	CBlobLabeling(void);
public:
	~CBlobLabeling(void);

public:
	cv::Mat		m_Image;				// ���̺��� ���� �̹���
	int			m_nThreshold;			// ���̺� ������Ȧ�� ��
	Visited*	m_vPoint;				// ���̺��� �湮����
	int			m_nBlobs;				// ���̺��� ����
	CvRect*		m_recBlobs;				// �� ���̺� ����


public:
	// ���̺� �̹��� ����
	void		SetParam(cv::Mat image, int nThreshold);

	// ���̺�(����)
	void		DoLabeling();

private:
	// ���̺�(����)
	int		 Labeling(cv::Mat image, int nThreshold);

	// ����Ʈ �ʱ�ȭ
	void	 InitvPoint(int nWidth, int nHeight);
	void	 DeletevPoint();

	// ���̺� ��� ���
	void	 DetectLabelingRegion(int nLabelNumber, unsigned char *DataBuf, int nWidth, int nHeight);

	// ���̺�(���� �˰���)
	int		_Labeling(unsigned char *DataBuf, int nWidth, int nHeight, int nThreshold);
	
	// _Labling ���� ��� �Լ�
	int		__NRFIndNeighbor(unsigned char *DataBuf, int nWidth, int nHeight, int nPosX, int nPosY, int *StartX, int *StartY, int *EndX, int *EndY );
	int		__Area(unsigned char *DataBuf, int StartX, int StartY, int EndX, int EndY, int nWidth, int nLevel);
};