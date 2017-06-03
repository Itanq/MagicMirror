/*********************************************************
******
******        FileName: src/tqlSeetaFaceDetect.cpp
******          Author: zmant
******      AuthorMail: zmant724@gmail.com
******      CreateTime: 2017-06-03 16:27:39
******   Last Modified: 2017-06-03 16:27:39
******    Description : ----
*********************************************************/

#include "seetaFaceDetect.hpp"
#include <cassert>

seetaFaceDetector::seetaFaceDetector(const std::string& model_path)
{
    m_faceDetectRect.clear();
    m_faceDetector = new seeta::FaceDetection(model_path);
}

seetaFaceDetector::~seetaFaceDetector()
{
    if(m_faceDetector)
        delete m_faceDetector;
}

void seetaFaceDetect::Detect(cv::Mat& srcImage)
{
    if(srcImage.channels() == 3)
        cv::cvtColor(srcImage, srcImage, cv::COLOR_BGR2GRAY);
    assert(srcImage.channels() == 1);
    seeta::ImageData detectImage;
    detectImage.data = srcImage.data;
    detectImage.width = srcImage.cols;
    detectImage.height = srcImage.rows;
}
