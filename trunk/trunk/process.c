#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//opencv library
#include "cv.h"
#include "highgui.h"



int main (int argc, char *argv[])
{
	IplImage* frame;
	CvCapture* capture = cvCreateFileCapture(argv[1]);
	char key;

	fprintf(stderr,"Loading %s@%d...\n",argv[0],getpid());

	cvNamedWindow("win",CV_WINDOW_AUTOSIZE);

	while(1)
	{
		frame = cvQueryFrame(capture);
		if (!frame) break;
		cvShowImage("win",frame);
		key = cvWaitKey(33);
		if (key == 27) break;
	}


	cvReleaseCapture(&capture);
	cvDestroyWindow("win");
}
