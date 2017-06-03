
#include "seetaFaceDetect.hpp"

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <vector>
#include <iostream>

int main(int argc, char* argv[])
{
    seetaFaceDetector  detect(argv[2]);

    detect.Initialize();

    cv::Mat srcImage = cv::imread(argv[1], 1);

    std::vector<cv::Rect> res = detect.Detect(srcImage);
    std::cout << " Num Face Is : " << res.size() << std::endl;

    for(int i=0; i<res.size(); ++i)
    {
        cv::rectangle(srcImage, res[i], CV_RGB(0,0,255), 4, 8, 0);
    }
    cv::imshow("faceDetect", srcImage);
    cv::waitKey(0);
    return 0;
}
