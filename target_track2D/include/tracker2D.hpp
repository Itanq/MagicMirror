/*********************************************************
******
******        FileName: include/tracker2D.hpp
******          Author: zmant
******      AuthorMail: zmant724@gmail.com
******      CreateTime: 2017-05-31 23:50:33
******   Last Modified: 2017-05-31 23:50:33
******    Description : ----
*********************************************************/


#ifndef _TRACKER2D_H_
#define _TRACKER2D_H_

#include "kcftracker.hpp"

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

class Tracker2D
{
    public:
        explicit Tracker2D(bool hog=true, bool fixed_window=true, bool multiscale=true, bool lab=true);
        ~Tracker2D();

    private:
        KCFTracker*      m_pTracker;
        cv::Rect        m_trackRect;
};

#endif
