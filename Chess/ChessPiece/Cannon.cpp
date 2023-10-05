/**
*********************************************************************
*********
* @project_name :lvgl
* @file : Cannon.cpp
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/10/4 
*********************************************************************
*********
*/
//

#include "Cannon.h"

Cannon::Cannon(const PointChess &point, bool color, ChessBoard &chessboard) : ChessPiece(point, color, chessboard) {

}

bool Cannon::CanMoveTo(const PointChess &point) const {
    if (board.GetChessBoard(point) == nullptr) {//Ŀ�ĵ�û������
        if (point.m_x == m_point.m_x) {//�ж�������������Ŀ�ĵ�֮���Ƿ�������
            if (point.m_y < m_point.m_y) {//���Ŀ�ĵ�y����С����������
                for (uint8_t i = point.m_y + 1; i < m_point.m_y; i++) {
                    if (board.GetChessBoard(point.m_x, i)) {
                        return false;
                    }
                }
            } else if(point.m_y > m_point.m_y){//���Ŀ�ĵ�y���������������
                for (uint8_t i = m_point.m_y + 1; i < point.m_y; ++i) {
                    if (board.GetChessBoard(point.m_x, i)) {
                        return false;
                    }
                }
            }
            return true;
        } else if (point.m_y == m_point.m_y) {//�ж����ӵĺ�������Ŀ�ĵ�֮���Ƿ��������
            if (point.m_x < m_point.m_x) {
                for (uint8_t i = point.m_x + 1; i < m_point.m_x; i++) {
                    if (board.GetChessBoard(i, point.m_y)) {
                        return false;
                    }
                }
            } else if (point.m_x > m_point.m_x) {
                for (uint8_t i = m_point.m_x + 1; i < point.m_x; ++i) {
                    if (board.GetChessBoard(i, point.m_y)) {
                        //   LV_LOG_WARN("cannot Move%d%d%d%d\n",m_point.m_x,m_point.m_y,point.m_x,point.m_y);
                        return false;
                    }
                }
            }
            return true;
        }
        return false;
    }else if (board.GetChessBoard(point)->ChessColor != this->ChessColor) {//����
            uint8_t count = 0;
            if (point.m_x == m_point.m_x) {//�ж�������������Ŀ�ĵ�֮���Ƿ�������
                if (point.m_y < m_point.m_y) {//���Ŀ�ĵ�y����С����������
                    for (uint8_t i = point.m_y + 1; i < m_point.m_y; i++) {
                        if (board.GetChessBoard(point.m_x, i)) {
                            count++;
                        }
                    }
                } else {//���Ŀ�ĵ�y���������������
                    for (uint8_t i = m_point.m_y + 1; i < point.m_y; ++i) {
                        if (board.GetChessBoard(point.m_x, i)) {
                            count++;
                        }
                    }
                }
                return true;
            } else if (point.m_y == m_point.m_y) {//�ж����ӵĺ�������Ŀ�ĵ�֮���Ƿ��������
                if (point.m_x < m_point.m_x) {
                    for (uint8_t i = point.m_x + 1; i < m_point.m_x; i++) {
                        if (board.GetChessBoard(i, point.m_y)) {
                            count++;
                        }
                    }
                } else {
                    for (uint8_t i = m_point.m_x + 1; i < point.m_x; ++i) {
                        if (board.GetChessBoard(i, point.m_y)) {
                            //   LV_LOG_WARN("cannot Move%d%d%d%d\n",m_point.m_x,m_point.m_y,point.m_x,point.m_y);
                            count++;
                        }
                    }
                }
                if (count == 1)
                    return true;

            }

            return false;
        }
    return false;
}

const char *Cannon::GetName() const {
    return "��";
}

const bool Cannon::CanCrossTheRiver() const {
    return true;
}


//void Cannon::DeleteButton() {
//    delete m_button;
//    delete m_label;
//}
