/**
*********************************************************************
*********
* @project_name :lvgl
* @file : Rook.h
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/9/30 
*********************************************************************
*********
*/
//

#ifndef CPROJECT_ROOK_H
#define CPROJECT_ROOK_H
#include "ChessPiece.h"

class Rook: public ChessPiece{
public:
    Rook(const PointChess& point, bool color, ChessBoard& chessboard);
    virtual bool CanMoveTo(const PointChess& point)const override;
    virtual const char *GetName()const ;
    virtual const bool CanCrossTheRiver()const;

//    virtual void Draw();
};


#endif //CPROJECT_ROOK_H
