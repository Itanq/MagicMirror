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
    m_faceDetector = new seeta::FaceDetection(model_path.c_str());
}

seetaFaceDetector::~seetaFaceDetector()
{
    if(m_faceDetector)
        delete m_faceDetector;
}

void seetaFaceDetector::Initialize()
{
    m_faceDetector->SetMinFaceSize(40);
    m_faceDetector->SetScoreThresh(2.0f);
    m_faceDetector->SetImagePyramidScaleFactor(0.8f);
    m_faceDetector->SetWindowStep(4, 4);

}

std::vector<cv::Rect> seetaFaceDetector::Detect(cv::Mat& srcImage)
{
    if(srcImage.channels() == 3)
        cv::cvtColor(srcImage, srcImage, cv::COLOR_BGR2GRAY);

    assert(srcImage.channels() == 1);

    seeta::ImageData detectImage;
    detectImage.data = srcImage.data;
    detectImage.width = srcImage.cols;
    detectImage.height = srcImage.rows;

    std::vector<seeta::FaceInfo> faceInfo = m_faceDetector->Detect(detectImage);

    uint16_t num_face = static_cast<uint16_t>(faceInfo.size());
    for(uint16_t i=0; i<num_face; ++i)
    {
        m_faceDetectRect[i].x = faceInfo[i].bbox.x;
        m_faceDetectRect[i].y = faceInfo[i].bbox.y;
        m_faceDetectRect[i].width = faceInfo[i].bbox.width;
        m_faceDetectRect[i].height = faceInfo[i].bbox.height;
    }
    return m_faceDetectRect;
}

