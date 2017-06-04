
#include "seetaFaceDetect.hpp"

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <vector>
#include <iostream>

int main(int argc, char* argv[])
{
    seetaFaceDetector  detect(argv[2]);

    detect.Initialize();

    cv::Mat srcImage;
    cv::VideoCapture capture(argv[1]);

    std::vector<cv::Rect> res;
    int curFrame=0;
    int totalFrame = capture.get(CV_CAP_PROP_FRAME_COUNT);
    while(curFrame < totalFrame)
    {
        capture >> srcImage;
        res = detect.Detect(srcImage);
        for(int i=0; i<res.size(); ++i)
            cv::rectangle(srcImage, res[i], CV_RGB(0,0,255), 4, 8, 0);
        cv::imshow("faceDetect", srcImage);
        cv::waitKey(0);
    }
    cv::waitKey(0);
    return 0;
}
