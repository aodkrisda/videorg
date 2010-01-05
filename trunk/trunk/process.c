#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//opencv library
#include "cv.h"
#include "highgui.h"



int g_slider_position = 0;
CvCapture* g_capture = NULL;

void onTrackbarSlide( int pos )
{
	cvSetCaptureProperty(g_capture,CV_CAP_PROP_POS_FRAMES,pos);
}

int main (int argc, char *argv[])
{
	IplImage* frame;
	char key;
	int frames;

	fprintf(stderr,"Loading %s@%d...\n",argv[0],getpid());

	cvNamedWindow("win",CV_WINDOW_AUTOSIZE);
	g_capture = cvCreateFileCapture(argv[1]);

	//attention: this is not working in linux, always return 0
	frames = (int) cvGetCaptureProperty(g_capture,CV_CAP_PROP_FRAME_COUNT);
	fprintf(stderr,"Number of frames: %d\n",frames);

	frames = 100;
	if (frames != 0)
	{
		cvCreateTrackbar("Position","win",&g_slider_position,frames,onTrackbarSlide);
	}

	while(1)
	{
		frame = cvQueryFrame(g_capture);
		if (!frame) break;
		cvShowImage("win",frame);
		key = cvWaitKey(33);
		if (key == 27) break;
	}


	cvReleaseCapture(&g_capture);
	cvDestroyWindow("win");
}
