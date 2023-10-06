/**
*********************************************************************
*********
* @project_name :lvgl
* @file : Horse.h
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/10/4 
*********************************************************************
*********
*/
//

#ifndef CPROJECT_HORSE_H
#define CPROJECT_HORSE_H
#include "ChessPiece.h"

class Horse :public ChessPiece{


public:


    Horse(const PointChess& point, bool color, ChessBoard& chessboard);
    virtual bool CanMoveTo(const PointChess& point)const override;
    virtual const char * GetName()const ;
    virtual const bool CanCrossTheRiver()const;

};


#endif //CPROJECT_HORSE_H
