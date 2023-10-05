/**
*********************************************************************
*********
* @project_name :lvgl
* @file : ChessGame.h
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/9/29 
*********************************************************************
*********
*/
//

#ifndef CPROJECT_CHESSGAME_H
#define CPROJECT_CHESSGAME_H
#include "Chess/ChessBoard/ChessBoard.h"
#include "Chess/ChessPhysicalCoordinates/ChessPhysicalCoordinates.h"
#include "Chess/ChessPhysicalCoordinates/SDLCOOr.h"


//class GetMousePosTimer:public lvgl::misc::Timer{
//    using Timer::Timer;
//    virtual void callback(Timer&timer)override{
//
//    }
//};
enum Status{
    First=0,
    Second,
    Third
};
class ChessGame {
private:
    ChessPhysicalCoordinates *getPos;
    PhysicalPoint last_mouse_pos;
    PhysicalPoint coords;
    bool nextPlayer;
    ChessBoard chessBoard;
    Container* container;
    PointChess from,to;
    Status status;

//    lv_indev_data_t last_mouse_data;
public:
    ChessGame();
    const ChessBoard& getChessBoard() const;
    bool Move(const PointChess& from, const PointChess& to);
    uint8_t GetWinner() const;
    bool GetNextPlayer() const;
    uint8_t GetScreenPos();
    void Run();
    ~ChessGame();
};

class RunTimer:public lvgl::misc::Timer{
public:
    ChessGame demo2;//该对象只能存在一个
    using Timer::Timer;
    virtual void callback(Timer&timer)override{
        demo2.GetScreenPos();
        demo2.Run();
    }
};
#endif //CPROJECT_CHESSGAME_H
