#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//opencv library
#include "cv.h"
#include "cxtypes.h"
#include "highgui.h"

IplImage* doPyrDown( IplImage* in, int filter = IPL_GAUSSIAN_5x5)
{
	IplImage* out;
	assert(in->width%2 == 0 && in->height%2 == 0);

	out = cvCreateImage(cvSize(in->width/2,in->height/2),in->depth,in->nChannels);
	cvPyrDown(in,out);
	return out;
}

char example2_4(IplImage* img)
{
	IplImage* out = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
	char key;

	cvShowImage("Example4-in",img);
	//cvSmooth(img,out,CV_GAUSSIAN,5,5);
	out = doPyrDown(img);
	cvShowImage("Example4-out",out);
	key = cvWaitKey(33);

	cvReleaseImage(&out);
	return key;
}

int main (int argc, char *argv[])
{
	IplImage* frame;
	char key;
	int frames;
	CvCapture* g_capture;

	cvNamedWindow("Example4-in");
	cvNamedWindow("Example4-out");

	fprintf(stderr,"Loading %s@%d...\n",argv[0],getpid());

	g_capture = cvCreateFileCapture(argv[1]);


	while(1)
	{
		frame = cvQueryFrame(g_capture);
		if (!frame) break;
		key = example2_4(frame);
		if (key == 27) break;
	}


	cvReleaseCapture(&g_capture);
	cvDestroyWindow("Example4-in");
	cvDestroyWindow("Example4-out");

	CvScalar s1 = cvScalar(20.0);
	s1.val[0] = 10.0;

	CvPoint      p = cvPoint(5,5);
	p.x = 10;
	CvRect       r = cvRect(5, 5, 5,5);
	r.x = 9;

	CvMat* t = cvCreateMat(2,2,CV_32FC1);
	CvMat* sec = cvCreateMatHeader(2,2,CV_32FC1);

	float a[] =  {5, 5,
		      5, 5};

	CvMat mat = cvMat(2,2,CV_32FC1,a);

	cvmSet(&mat,0,0,3.0);

	int n = mat.cols;
	float *data = mat.data.fl;
	data[1*n+1] = 3.0;

	int step = mat.step / sizeof(float);
	(data+1*step)[0] = 3.0;

	

	float s = 0.0f;
	for(int row=0; row<mat.rows; row++ ) {
		const float* ptr = (const float*)(mat.data.ptr + row * mat.step);
		for( int col=0; col<mat.cols; col++ ) {
			s += *ptr++;
		}
	}
	
	fprintf(stderr,"sum=%f\n",s);

	cvReleaseMat(&t);
	cvReleaseMat(&sec);



}
