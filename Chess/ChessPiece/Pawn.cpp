/**
*********************************************************************
*********
* @project_name :lvgl
* @file : Pawn.cpp
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/10/5 
*********************************************************************
*********
*/
//

#include "Pawn.h"

Pawn::Pawn(const PointChess &point, bool color, ChessBoard &chessboard) : ChessPiece(point, color, chessboard) {

}

bool Pawn::CanMoveTo(const PointChess &point) const {
    if (board.GetChessBoard(point) == nullptr || board.GetChessBoard(point)->ChessColor != this->ChessColor)
    {
        int8_t front = (ChessColor == RED ? -1 :1 );//考虑数据的-号
        if (ChessColor == m_point.ColorOfArea())//没过河
            return point == PointChess(m_point.m_x, m_point.m_y + front);
        const PointChess s[3] = { {0,front},{1,0},{-1,0} };
        for (size_t i = 0; i < 4; i++)
        {
            if (point == PointChess(m_point.m_x + s[i].m_x, m_point.m_y + s[i].m_y))
            {
                return true;
            }
        }
    }
    return false;
}

const char *Pawn::GetName() const {
    return ChessColor ? "兵" : "卒";
}

const bool Pawn::CanCrossTheRiver() const {
    return true;
}
