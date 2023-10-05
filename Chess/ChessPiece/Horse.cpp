/**
*********************************************************************
*********
* @project_name :lvgl
* @file : Horse.cpp
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/10/4 
*********************************************************************
*********
*/
//

#include "Horse.h"

Horse::Horse(const PointChess &point, bool color, ChessBoard &chessboard) : ChessPiece(point, color, chessboard) {

}

bool Horse::CanMoveTo(const PointChess &point) const {
    if ((board.GetChessBoard(point)== nullptr)||(board.GetChessBoard(point)->ChessColor!=this->ChessColor)) {
        if (point.m_y-m_point.m_y==2&& abs(point.m_x-m_point.m_x)==1){
            if (board.GetChessBoard(m_point.m_x,m_point.m_y+1)== nullptr){
                return true;
            }
            return false;
        }
        if (m_point.m_y-point.m_y==2&& abs(point.m_x-m_point.m_x)==1){
            if (board.GetChessBoard(m_point.m_x,m_point.m_y-1)== nullptr){
                return true;
            }
            return false;
        }
        if (point.m_x-m_point.m_x==2&& abs(point.m_y-m_point.m_y)==1){
            if (board.GetChessBoard(m_point.m_x+1,m_point.m_y)== nullptr){
                return true;
            }
            return false;
        }
        if (m_point.m_x-point.m_x==2&& abs(point.m_y-m_point.m_y)==1){
            if (board.GetChessBoard(m_point.m_x-1,m_point.m_y)== nullptr){
                return true;
            }
            return false;
        }
        return false;


    }
    return false;

}

const char *Horse::GetName() const {
    return "ÒR";
}

const bool Horse::CanCrossTheRiver() const {
    return true;
}



//Button *Horse::getMButton() const {
//    return m_button;
//}
//
//Label *Horse::getMLabel() const {
//    return m_label;
//}

//void Horse::DeleteButton() {
//    delete m_button;
//    delete m_label;
//}
