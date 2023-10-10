/**
*********************************************************************
*********
* @project_name :lvgl
* @file : King.cpp
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/10/5 
*********************************************************************
*********
*/
//

#include "King.h"

King::King(const PointChess &point, bool color, ChessBoard &chessboard) : ChessPiece(point, color, chessboard) {

}

bool King::CanMoveTo(const PointChess &point) const {
    static const PointChess s[4] = { {0,1},{0,-1},{1,0},{-1,0} };//將可以到达的四个点
    if (board.GetChessBoard(point) == nullptr || board.GetChessBoard(point)->ChessColor != this->ChessColor)
    {
        if (ChessColor == point.ColorOfArea() && point.IsInNinePalaces())
        {
            for (uint8_t i = 0; i < 4; i++)
            {
                if (point == PointChess(m_point.m_x + s[i].m_x, m_point.m_y + s[i].m_y))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

const char *King::GetName() const {
    return ChessColor?"帅":"将";
}

const bool King::CanCrossTheRiver() const {
    return false;
}
