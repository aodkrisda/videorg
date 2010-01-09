#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//opencv library
#include "cv.h"
#include "cxtypes.h"
#include "highgui.h"

void saturate_sv(IplImage* img)
{
	for (int y=0;y<img->height;y++)
	{
		uchar* ptr = (uchar*)(img->imageData + y*img->widthStep);
		for (int x=0;x<img->width;x++)
		{
			ptr[3*x+1] = 255;
			ptr[3*x+2] = 255;
		}
	}
}

int main (int argc, char *argv[])
{
	fprintf(stderr,"Loading %s@%d...\n",argv[0],getpid());




}
