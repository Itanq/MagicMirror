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

std::vector<cv::Rect> seetaFaceDetector::Detect(const cv::Mat& srcImage)
{
    cv::Mat grayImage;
    if(srcImage.channels() == 3)
        cv::cvtColor(srcImage, grayImage, cv::COLOR_BGR2GRAY);
    else
        grayImage = srcImage;

    assert(grayImage.channels() == 1);

    seeta::ImageData detectImage;
    detectImage.data = grayImage.data;
    detectImage.width = grayImage.cols;
    detectImage.height = grayImage.rows;
    detectImage.num_channels = 1;

    std::vector<seeta::FaceInfo> faceInfo = m_faceDetector->Detect(detectImage);

    cv::Rect face;
    uint16_t num_face = static_cast<uint16_t>(faceInfo.size());
    for(uint16_t i=0; i<num_face; ++i)
    {
        face.x = faceInfo[i].bbox.x;
        face.y = faceInfo[i].bbox.y;
        face.width = faceInfo[i].bbox.width;
        face.height = faceInfo[i].bbox.height;
        m_faceDetectRect.push_back(face);
    }
    return m_faceDetectRect;
}

