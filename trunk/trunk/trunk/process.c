#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "cv.h"
#include "highgui.h"



int main (int argc, char *argv[])
{
	IplImage* img = cvCreateImage( cvSize( 500, 500 ), 8, 3 );
	char key;

	fprintf(stderr,"Loading %s@%d...\n",argv[0],getpid());

	cvNamedWindow("win", 1);
        cvShowImage("win", img);

        key = (char) cvWaitKey(0);

	cvDestroyWindow("win");
}
