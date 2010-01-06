#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "cv.h"
#include "highgui.h"

main( int argc, char* argv[] ) {
	CvCapture* capture = cvCreateFileCapture( argv[1] );
	IplImage *bgr_frame=cvQueryFrame(capture);//Init the video read
	double fps = cvGetCaptureProperty (
		capture,
		CV_CAP_PROP_FPS
		);
	fprintf(stderr,"fps=%f\n",fps);
	int x  = (int)cvGetCaptureProperty( capture, CV_CAP_PROP_FRAME_WIDTH);
	fprintf(stderr,"x=%d\n",x);
	int y =  (int)cvGetCaptureProperty( capture, CV_CAP_PROP_FRAME_HEIGHT);
	fprintf(stderr,"y=%d\n",y);

<<<<<<< .mine
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

	IplImage *bgr_frame=cvQueryFrame(g_capture);//Init the video read
	//attention: this is not working in linux, always return 0
	frames = (int) cvGetCaptureProperty(g_capture,CV_CAP_PROP_FRAME_COUNT);
	fprintf(stderr,"Number of frames: %d\n",frames);


	while(1)
	{
		frame = cvQueryFrame(g_capture);
		if (!frame) break;
		key = example2_4(frame);
		if (key == 27) break;
=======
	CvSize size = cvSize(
		x,
		y		
		);
	CvVideoWriter *writer = cvCreateVideoWriter(
		argv[2],
		CV_FOURCC('D','I','V','X'),
		fps,
		size
		);
	IplImage* logpolar_frame = cvCreateImage(
		size,
		IPL_DEPTH_8U,
		3
		);
	while( (bgr_frame=cvQueryFrame(capture)) != NULL ) {
		cvLogPolar( bgr_frame, logpolar_frame,
			    cvPoint2D32f(bgr_frame->width/2,
					 bgr_frame->height/2),
			    40,
			    CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS );
		cvWriteFrame( writer, logpolar_frame );
>>>>>>> .r15
	}
	cvReleaseVideoWriter( &writer );
	cvReleaseImage( &logpolar_frame );
	cvReleaseCapture( &capture );
	return(0);
}
