/*********************************************************
******
******        FileName: src/tracker2D.cpp
******          Author: zmant
******      AuthorMail: zmant724@gmail.com
******      CreateTime: 2017-05-31 23:56:08
******   Last Modified: 2017-05-31 23:56:08
******    Description : ----
*********************************************************/

#include "tracker2D.hpp"

Tracker2D::Tracker2D(bool hog, bool fixed_window, bool multiscale, bool lab)
{
    m_pTracker = new KCFTracker(hog, fixed_window, multiscale, lab);
}

Tracker2D::~Tracker2D()
{
    delete m_pTracker;
}
