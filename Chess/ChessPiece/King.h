/**
*********************************************************************
*********
* @project_name :lvgl
* @file : King.h
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/10/5 
*********************************************************************
*********
*/
//

#ifndef CPROJECT_KING_H
#define CPROJECT_KING_H

#include "ChessPiece.h"
class King: public ChessPiece{
public:
    King(const PointChess& point, bool color, ChessBoard& chessboard);
    virtual bool CanMoveTo(const PointChess& point)const override;
    virtual const char * GetName()const ;
    virtual const bool CanCrossTheRiver()const;

};


#endif //CPROJECT_KING_H
