/**
*********************************************************************
*********
* @project_name :lvgl
* @file : Pawn.h
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/10/5 
*********************************************************************
*********
*/
//

#ifndef CPROJECT_PAWN_H
#define CPROJECT_PAWN_H
#include "ChessPiece.h"

class Pawn: public ChessPiece{
public:
    Pawn(const PointChess& point, bool color, ChessBoard& chessboard);
    virtual bool CanMoveTo(const PointChess& point)const override;
    virtual const char * GetName()const ;
    virtual const bool CanCrossTheRiver()const;

};


#endif //CPROJECT_PAWN_H
