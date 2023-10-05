/**
*********************************************************************
*********
* @project_name :lvgl
* @file : ChessPiece.h
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/9/29 
*********************************************************************
*********
*/
//

#ifndef CPROJECT_CHESSPIECE_H
#define CPROJECT_CHESSPIECE_H

#include "Chess/ChessBoard/ChessBoard.h"
#include "Chess/ChessPhysicalCoordinates/ChessPhysicalCoordinates.h"

class ChessBoard;
class ChessPiece {
protected:
    Button* m_button;
    Label* m_label;
    PointChess m_point;
    ChessBoard &board;//此棋盘都会和实例化的棋盘绑定 所以只存在一个棋盘
public:
    const bool ChessColor;
    ChessPiece(const PointChess& point, bool color, ChessBoard& chessboard);
    const PointChess& GetPoint();
//    virtual void Draw()=0;
    virtual bool CanMoveTo(const PointChess& point)const=0;
    virtual const char *GetName()const=0;
    virtual const bool CanCrossTheRiver()const=0;
//    virtual void DeleteButton()=0;
    void DeleteButton();
    void GreatButton();
    bool MoveTo(const PointChess &point);
    void Draw();
    void Draw(const PointChess& point);



    PhysicalPoint getScreenPixelsXY();



};


#endif //CPROJECT_CHESSPIECE_H
