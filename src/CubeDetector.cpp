#include "CubeDetector.h"

CubeDetector::CubeDetector(){
    tresholdCannyOne=50;
    tresholdCannyTwo=50;
    windowCamera="Camera";
    windowCanny="Canny";
    windowRubicCube="Cube";
    videoCapture=NULL;
}

CubeDetector::~CubeDetector(){
    if (videoCapture!=NULL)
    delete videoCapture;
}

void CubeDetector::getFrame(){
    (*videoCapture) >> frame;
    if (frame.empty()){
        cout<<"Empty frame!"<<endl;
    }
}

bool CubeDetector::isWorking(){
    char key = (char)waitKey(5);
        if (key=='q'){
            return false;
        }
    return true;
}

void CubeDetector::findCube(){
    squares.clear();
    Mat imageGray;
    vector<vector<Point> > contours;

    Canny(frame, imageGray,tresholdCannyOne,tresholdCannyTwo,3);
    imshow(windowCanny, imageGray);
    findContours(imageGray, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);

    vector<Point> approxs;
    int area;

    for( unsigned contoure = 0; contoure < contours.size(); contoure++ )
    {
        approxPolyDP(Mat(contours[contoure]), approxs, arcLength(Mat(contours[contoure]), true)*0.02, true);
        area = contourArea(Mat(approxs));

        if( approxs.size() == 4 && area > 2500 ){
            squares.push_back(approxs);
        }
    }
}

void CubeDetector::drawCube(){
    Size imageSize = frame.size();
    int minY=imageSize.height-1;
    int minX=imageSize.width-1;
    int maxX=0,maxY=0;
    for( unsigned i = 0; i < squares.size(); i++ )
    {
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
    }

    if (minX+abs(maxX-minX)< imageSize.width-1 && minY+abs(maxY-minY)< imageSize.height-1  && abs(abs(maxX - minX )-abs(maxY-minY)) <10 ){
        Mat dst = frame(Rect(minX,minY,abs(maxX-minX),abs(maxY-minY))).clone();
        imshow(windowRubicCube,dst);
    }
    imshow(windowCamera, frame);
}


bool CubeDetector::init(){
    namedWindow( windowCamera, WINDOW_AUTOSIZE );
    namedWindow( windowCanny, WINDOW_AUTOSIZE );
    namedWindow( windowRubicCube, WINDOW_AUTOSIZE );

    videoCapture = new VideoCapture(0);
    if (!videoCapture->isOpened()) {
        cout << "Failed to open a video device!\nInitialization failed!" << endl;
        return false;
    }
    cout<<"Initialization success!\nPress q to exit!\n"<<endl;
    return true;
}
