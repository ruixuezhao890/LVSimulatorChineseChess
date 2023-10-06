/**
*********************************************************************
*********
* @project_name :lvgl
* @file : Adviser.h
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/10/5 
*********************************************************************
*********
*/
//

#ifndef CPROJECT_ADVISER_H
#define CPROJECT_ADVISER_H
#include "ChessPiece.h"

class Adviser: public ChessPiece{
public:
    Adviser(const PointChess& point, bool color, ChessBoard& chessboard);
    virtual bool CanMoveTo(const PointChess& point)const override;
    virtual const char * GetName()const ;
    virtual const bool CanCrossTheRiver()const;

};


#endif //CPROJECT_ADVISER_H
