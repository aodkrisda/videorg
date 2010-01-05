#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//opencv library
#include "cv.h"
#include "highgui.h"



int main (int argc, char *argv[])
{
	IplImage* img = cvLoadImage(argv[1]);
	char key;

	fprintf(stderr,"Loading %s@%d...\n",argv[0],getpid());

	cvNamedWindow("win", 1);
        cvShowImage("win", img);

        key = (char) cvWaitKey(0);

	cvDestroyWindow("win");
}
