/*********************************************************
******
******        FileName: include/tqlSeetaFaceDetect.hpp
******          Author: zmant
******      AuthorMail: zmant724@gmail.com
******      CreateTime: 2017-06-03 16:18:32
******   Last Modified: 2017-06-03 16:18:32
******    Description : ----
*********************************************************/

#ifndef _SEETA_FACE_DETECT_HPP_
#define _SEETA_FACE_DETECT_HPP_

#include "face_detection.h"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <vector>
#include <string>

class seetaFaceDetector
{
    public:
        explicit seetaFaceDetector(const std::string& model_path);
        ~seetaFaceDetector();
        
        void Initialize();
        void Detect(const cv::Mat& srcImage);

    private:
        seeta::FaceDetection*               m_faceDetector;
        std::vector<seeta::FaceInfo>        m_faceInfo;
};
#endif

