#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
#include <math.h>
#include <string.h>

using namespace cv;
using namespace std;

char* windowCamera="Camera";
char* windowCanny="Canny";

int tresholdCannyOne=211;
int tresholdCannyTwo=311;

static double angle( Point pt1, Point pt2, Point pt0 )
{
    double dx1 = pt1.x - pt0.x;
    double dy1 = pt1.y - pt0.y;
    double dx2 = pt2.x - pt0.x;
    double dy2 = pt2.y - pt0.y;
    return (dx1*dx2 + dy1*dy2)/sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
}

static void drawSquares( Mat& image, const vector<vector<Point > >& squares )
{
     Vec3b color;
     int maxX,maxY;
    for( size_t i = 0; i < squares.size(); i++ )
    {
        maxX=maxY=0;
        const Point* p = &squares[i][0];
        int n = (int)squares[i].size();
        for (int square=0;square<n;square++){
            if (squares[i][square].x > maxX)
                maxX=squares[i][square].x;
            if (squares[i][square].y > maxY)
                maxY=squares[i][square].y;
        }
        color = image.at<Vec3b>(Point((p->x+maxX)/2,(p->y+maxY)/2));
        polylines(image, &p, &n, 1, true, Scalar(color[0],color[1],color[2]), 1, CV_AA,1);
    }

    imshow(windowCamera, image);

}

void findSquares( const Mat& image, vector<vector<Point> > &squares){
      squares.clear();
    Mat imageGray,imageMixed(image.size(), CV_8U);
    vector<vector<Point> > contours;

    for (int color=0;color<3;color++){
        int channel[] = {color,0};
        mixChannels(&image, 1, &imageMixed, 1, channel, 1);
        Canny(imageMixed, imageGray,tresholdCannyOne,tresholdCannyTwo,3);
        imshow(windowCanny, imageGray);
        findContours(imageGray, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);

        vector<Point> approxs;

            for( size_t i = 0; i < contours.size(); i++ )
            {
                approxPolyDP(Mat(contours[i]), approxs, arcLength(Mat(contours[i]), true)*0.02, true);

                if( approxs.size() == 4 && fabs(contourArea(Mat(approxs))) > 1000 && isContourConvex(Mat(approxs)) ){}
                    double maxCosine = 0;

                    for( int j = 2; j < 5; j++ )
                    {
                        double cosine = fabs(angle(approxs[j%4], approxs[j-2], approxs[j-1]));
                        maxCosine = MAX(maxCosine, cosine);
                    }
                    if( maxCosine < 0.3 )
                        squares.push_back(approxs);
            }
        }
}

int main()
{
    namedWindow( windowCamera, WINDOW_AUTOSIZE );
    namedWindow( windowCanny, WINDOW_AUTOSIZE );
    vector<vector<Point> > squares;
    Mat frame;

    VideoCapture capture(0);
    if (!capture.isOpened()) {
        cerr << "Failed to open a video device or video file!\n" << endl;
        return 1;
    }
    cout<<"Press 'q' to exit"<<endl;
    while (1){
         capture >> frame;
            if (frame.empty())
                    break;
            findSquares(frame,squares);
            drawSquares(frame,squares);
            imshow(windowCamera, frame);
            cout<<"Squares found: "<<squares.size()<<endl;
            char key = (char)waitKey(5);
            if (key=='q'){
                return 0;
            }
    }
    waitKey();
    return 0;
}


