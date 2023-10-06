/**
*********************************************************************
*********
* @project_name :lvgl
* @file : Cannon.h
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/10/4 
*********************************************************************
*********
*/
//

#ifndef CPROJECT_CANNON_H
#define CPROJECT_CANNON_H
#include "ChessPiece.h"

class Cannon: public ChessPiece{
public:
    Cannon(const PointChess& point, bool color, ChessBoard& chessboard);
//    void DeleteButton();
    virtual bool CanMoveTo(const PointChess& point)const override;
    virtual const char * GetName()const ;
    virtual const bool CanCrossTheRiver()const;

};


#endif //CPROJECT_CANNON_H
