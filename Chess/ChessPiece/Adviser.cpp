/**
*********************************************************************
*********
* @project_name :lvgl
* @file : Adviser.cpp
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/10/5 
*********************************************************************
*********
*/
//

#include "Adviser.h"

Adviser::Adviser(const PointChess &point, bool color, ChessBoard &chessboard) : ChessPiece(point, color, chessboard) {

}

bool Adviser::CanMoveTo(const PointChess &point) const {
    static const PointChess s[4] = { {1,1},{1,-1},{-1,1},{-1,-1} };//士可以到达的四个点
    if (board.GetChessBoard(point) == nullptr || board.GetChessBoard(point)->ChessColor != this->ChessColor)
    {
        if (ChessColor == point.ColorOfArea() && point.IsInNinePalaces())
        {
            for (auto i : s)
            {
                if (point == PointChess(m_point.m_x + i.m_x, m_point.m_y + i.m_y))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

const char * Adviser::GetName() const {
    return ChessColor?"仕":"士";
}

const bool Adviser::CanCrossTheRiver() const {
    return false;
}
