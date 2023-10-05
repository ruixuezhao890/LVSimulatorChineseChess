/**
*********************************************************************
*********
* @project_name :lvgl
* @file : PointChess.cpp
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/9/29 
*********************************************************************
*********
*/
//
#include "Chess/Point/PointChess.h"
bool operator==(const PointChess&a, const PointChess&b) {
    return a.m_x==b.m_x&&a.m_y==b.m_y;
}

PointChess::PointChess() {

}
