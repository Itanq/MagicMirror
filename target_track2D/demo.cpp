
#include "kcftracker.hpp"

#include <dirent.h>
#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

cv::Rect g_init_rect;
cv::Mat firstFrame, tmpImg;
void on_mouse(int event, int  x, int y, int flags, void* data)
{
    static cv::Point startPoint, endPoint;
    if(event == CV_EVENT_LBUTTONDOWN)
        startPoint = cv::Point(x, y);
    else if(event == CV_EVENT_LBUTTONUP)
    {
        firstFrame.copyTo(tmpImg);
        endPoint = cv::Point(x, y);
        g_init_rect.x = startPoint.x;
        g_init_rect.y = startPoint.y;
        g_init_rect.width = endPoint.x - startPoint.x;
        g_init_rect.height = endPoint.y - startPoint.y;
        cv::rectangle(tmpImg, g_init_rect, cv::Scalar(255,0,0),2,3,0);
        cv::imshow("init_rect", tmpImg);
    }
}
int main(int argc,  char* argv[])
{
    if(argc < 1)
    {
        std::cout << " 请输入视频的路径!!" << std::endl;
        return -1;
    }

    bool HOG=true;
    bool FIXWINDOW=false;
    bool MULTISCALE=true;
    bool SILENT=true;
    bool LAB=false;

    KCFTracker tracker(HOG, FIXWINDOW, MULTISCALE, LAB);

    cv::VideoCapture video(argv[1]);
    video >> firstFrame;
    cv::namedWindow("init_rect");
    cv::setMouseCallback("init_rect", on_mouse, 0);
    cv::imshow("init_rect", firstFrame);
    cv::waitKey(0);

    tracker.init(g_init_rect, firstFrame);

    if(!video.isOpened())
    {
        std::cout << " 视频打开失败！！ " << std::endl;
        return -1;
    }
    
    int curFrame = 0;
    int sumFrame = video.get(CV_CAP_PROP_FRAME_COUNT);

    cv::Mat frame;
    while(curFrame < sumFrame)
    {
        video >> frame;
        cv::Rect res = tracker.update(frame);
        cv::rectangle(frame, res, cv::Scalar(0,0,255),2,3,0);
        cv::imshow("tracker", frame);
        if(static_cast<char>(cv::waitKey(27))==27)
            break;
        ++curFrame;
    }
    return 0;
}

