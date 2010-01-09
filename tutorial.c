#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//opencv library
#include "cv.h"
#include "cxtypes.h"
#include "highgui.h"

void bw(IplImage* img)
{
	for (int y=0;y<img->height;y++)
	{
		uchar* ptr = (uchar*)(img->imageData + y*img->widthStep);
		for (int x=0;x<img->width;x++)
		{
			ptr[3*x+1] = ptr[3*x];
			ptr[3*x+2] = ptr[3*x];
		}
	}
}

int main (int argc, char *argv[])
{
	fprintf(stderr,"Loading %s@%d...\n",argv[0],getpid());
	cvNamedWindow("Tutorial");

	IplImage* img;
	char key;

	img = cvLoadImage(argv[1],1);
	bw(img);
	cvShowImage("Tutorial",img);

	key = cvWaitKey(0);
	cvReleaseImage(&img);
}
