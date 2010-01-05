#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//opencv library
#include "cv.h"
#include "highgui.h"


char example2_4(IplImage* img)
{
	IplImage* out = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);
	char key;

	cvShowImage("Example4-in",img);
	cvSmooth(img,out,CV_GAUSSIAN,3,3);
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

}
