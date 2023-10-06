/**
*********************************************************************
*********
* @project_name :lvgl
* @file : Rook.cpp
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/9/30 
*********************************************************************
*********
*/
//

#include "Rook.h"
#include "Chess/ChessBoard/ChessBoard.h"
Rook::Rook(const PointChess &point, bool color, ChessBoard &chessboard) : ChessPiece(point, color, chessboard) {

}

bool Rook::CanMoveTo(const PointChess &point) const {
    if ((board.GetChessBoard(point)== nullptr)||(board.GetChessBoard(point)->ChessColor!=this->ChessColor)){
        if(point.m_x==m_point.m_x){//判断纵轴在棋子与目的地之间是否有棋子
            if (point.m_y<m_point.m_y){//如果目的地y坐标小于棋子坐标
                for (uint8_t i= point.m_y+1;  i<m_point.m_y ; i++) {
                    if (board.GetChessBoard(point.m_x,i)){
                        return false;
                    }
                }
            }else if(point.m_y>m_point.m_y){//如果目的地y坐标大于棋子坐标
                for (uint8_t i= m_point.m_y+1;  i<point.m_y ; ++i) {
                    if (board.GetChessBoard(point.m_x,i)){
                        return false;
                    }
                }
            }
            return true;
        }else if (point.m_y==m_point.m_y){//判断棋子的横坐标与目的地之间是否存在棋子
            if (point.m_x<m_point.m_x){
                for (uint8_t i= point.m_x+1;  i<m_point.m_x ; i++) {
                    if (board.GetChessBoard(i,point.m_y)){
                        return false;
                    }
                }
            }else if(point.m_x>m_point.m_x){
                for (uint8_t i= m_point.m_x+1;  i<point.m_x ; ++i) {
                    if (board.GetChessBoard(i,point.m_y)){
                     //   LV_LOG_WARN("cannot Move%d%d%d%d\n",m_point.m_x,m_point.m_y,point.m_x,point.m_y);
                        return false;
                    }
                }
            }
            return true;
        }
    }
    return false;
}

const char * Rook::GetName() const {
    return "俥" ;
}

const bool Rook::CanCrossTheRiver() const {
    return true;
}




