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

void CubeDetector::updateCubeWindow(){
    Size imageSize = frame.size();
    int minY=imageSize.height;
    int minX=imageSize.width;
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
    if (minX+abs(maxX-minX)< imageSize.width-1 && minY+abs(maxY-minY)< imageSize.height-1
        && abs(abs(maxX - minX )-abs(maxY-minY)) <10 ){
        cube.release();
        cube = frame(Rect(minX,minY,abs(maxX-minX),abs(maxY-minY))).clone();
        imshow(windowRubicCube,cube);
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

int CubeDetector::detectSide(){
    Size cubeSize = cube.size();
    int height=cubeSize.height;
    int width=cubeSize.width;
    return getColor(width/2,height/2);
}

int CubeDetector::getColor(int x,int y){
    Mat HSV;
    int d=4;
    int sumH=0,sumS=0,sumV=0;
    if (x>= d && y>= d && x+d <cube.size().width && y+d < cube.size().height){
        vector<Vec3b> colors;
        Mat RGB=cube(Rect(x,y,1,1));
        cvtColor(RGB, HSV,CV_BGR2HSV);
        colors.push_back(HSV.at<Vec3b>(0,0));
        RGB=cube(Rect(x-d,y-d,1,1));
        cvtColor(RGB, HSV,CV_BGR2HSV);
        colors.push_back(HSV.at<Vec3b>(0,0));
        RGB=cube(Rect(x+d,y+d,1,1));
        cvtColor(RGB, HSV,CV_BGR2HSV);
        colors.push_back(HSV.at<Vec3b>(0,0));

        for (unsigned i = 0; i<colors.size(); i++){
            sumH+=int(colors[i][0]); sumS+=int(colors[i][1]); sumV+=int(colors[i][2]);
        }

        Vec3b color=HSV.at<Vec3b>(0,0);
        color[0]=sumH/colors.size();
        color[1]=sumS/colors.size();
        color[2]=sumV/colors.size();
        short whiteLv = 50;
        short blackLv = 60;
        if (color[0]<179 && color[0]>=160 && color[1]>whiteLv && color[2]>blackLv ){
            return RED;
        } else if (color[0]>=0 && color[0]<22 && color[1]>whiteLv && color[2]>blackLv ){
            return ORANGE;
        } else if (color[0]>=22 && color[0]<38 && color[1]>whiteLv && color[2]>blackLv ){
            return YELLOW;
        } else if (color[0]>=38 && color[0]<95 && color[1]>whiteLv && color[2]>blackLv ){
            return GREEN;
        } else if (color[0]>=95 && color[0]<120 && color[1]>whiteLv && color[2]>blackLv ){
            return BLUE;
        } else if (color[1]<whiteLv && color[2]>blackLv){
            return WHITE;
        } else{
            return UNDEF;
        }
    }
    return UNDEF;
}

void CubeDetector::getColors(int * side){
    Size imageSize = cube.size();
    int h=imageSize.height;
    int w=imageSize.width;
    for (int i=0;i<9 ;i++)
        side[i]=UNDEF;

    if (w<=10 || h <= 10)
        return;

    int step= w / 3;
    int start = w*0.17;

    for (unsigned short horizontal = 0; horizontal < 3; horizontal++){
        for (unsigned short vertical = 0; vertical < 3; vertical++){
                if(start+step*horizontal<h && start+step*horizontal<w){
                    circle(cube,Point(start+step*horizontal,start+step*vertical),4,Scalar(0,0,0));
                    side[horizontal+vertical*3]=getColor(start+step*horizontal,start+step*vertical);
                }
        }
    }
    imshow(windowRubicCube,cube);
}

void CubeDetector::print(int * colors){
    cout<<endl<<endl;
    for (int i=1 ; i<=9 ;i++){
        cout<<colors[i-1]<<" ";
        if (i%3==0)
            cout<<endl;
    }
}
