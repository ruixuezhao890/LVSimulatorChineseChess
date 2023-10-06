/**
*********************************************************************
*********
* @project_name :lvgl
* @file : PointChess.h
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/9/29 
*********************************************************************
*********
*/
//

#ifndef CPROJECT_POINTCHESS_H
#define CPROJECT_POINTCHESS_H
#include <cstdint>

extern const bool BLACK;
extern const bool RED;
extern const uint8_t NONE;

class PointChess {
public:
    int m_x,m_y;
    PointChess();
    PointChess(int x, int y): m_x(x), m_y(y){}
    bool ColorOfArea() const {
        if (m_y<=4)
            return BLACK;
        return RED;
    }

    bool IsInNinePalaces() const {
        return m_x>=3&&m_x<5&&(m_y<2||m_y>=7);
    }


};
bool operator==(const PointChess& a, const PointChess& b);



#endif //CPROJECT_POINTCHESS_H
