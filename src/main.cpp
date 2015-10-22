#include <iostream>

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"


using namespace cv;
using namespace std;

char* windowCamera="Camera";
char* windowCanny="Canny";
char* windowRubicCube="Cube";

int tresholdCannyOne=50;
int tresholdCannyTwo=50;

void drawSquares( Mat& image, const vector<vector<Point > >& squares );
void findSquares( const Mat& image, vector<vector<Point> > &squares);


int main()
{
    namedWindow( windowCamera, WINDOW_AUTOSIZE );
    namedWindow( windowCanny, WINDOW_AUTOSIZE );
    namedWindow( windowRubicCube, WINDOW_AUTOSIZE );
    vector<vector<Point> > squares;
    Mat frame;

    VideoCapture capture(0);
    if (!capture.isOpened()) {
        cout << "Failed to open a video device or video file!\n" << endl;
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
            cout<<squares.size()<<endl;
            char key = (char)waitKey(5);
            if (key=='q'){
                return 0;
            }
    }
    waitKey();
    return 0;
}

void drawSquares( Mat& image, const vector<vector<Point > >& squares )
{
    Vec3b color;
    Size imageSize = image.size();
    int minY=imageSize.height-1;
    int minX=imageSize.width-1;
    int maxX=0,maxY=0;
    for( int i = 0; i < squares.size(); i++ )
    {
        const Point* p = &squares[i][0];
        int n = (int)squares[i].size();
        for (int square=0;square<n;square++){
            if (squares[i][square].x > maxX)
                maxX=squares[i][square].x;
            if (squares[i][square].y > maxY)
                maxY=squares[i][square].y;
            if (squares[i][square].x < minX)
                minX=squares[i][square].x;
            if (squares[i][square].y < minY)
                minY=squares[i][square].y;
        }
//        color = image.at<Vec3b>(Point((p->x+maxX)/2,(p->y+maxY)/2));
//        polylines(image, &p, &n, 1, true, Scalar(color[0],color[1],color[2]), 1, CV_AA,1);

    }
    circle(image,Point(maxX,maxY),2,Scalar(255,255,0)); //rysuje prawy dolny róg kostki
    circle(image,Point(minX,minY),2,Scalar(0,255,255)); //rysuje lewy górny róg kostki
    if (minX+abs(maxX-minX)< imageSize.width-1 && minY+abs(maxY-minY)< imageSize.height-1  && abs(abs(maxX - minX )-abs(maxY-minY)) <10 ){
        Mat dst = image(Rect(minX,minY,abs(maxX-minX),abs(maxY-minY))).clone();
        imshow(windowRubicCube,dst);
    }
    imshow(windowCamera, image);

}

void findSquares( const Mat& image, vector<vector<Point> > &squares){
        squares.clear();
        Mat imageGray;
        vector<vector<Point> > contours;

        Canny(image, imageGray,tresholdCannyOne,tresholdCannyTwo,3);
        imshow(windowCanny, imageGray);
        findContours(imageGray, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);

        vector<Point> approxs;
        int area;

        for( int contoure = 0; contoure < contours.size(); contoure++ )
        {
            approxPolyDP(Mat(contours[contoure]), approxs, arcLength(Mat(contours[contoure]), true)*0.02, true);
            area = contourArea(Mat(approxs));

            if( approxs.size() == 4 && area > 2500 ){
                squares.push_back(approxs);
            }
        }
}




