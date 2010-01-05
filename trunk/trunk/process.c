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
	}
	cvReleaseVideoWriter( &writer );
	cvReleaseImage( &logpolar_frame );
	cvReleaseCapture( &capture );
	return(0);
}
