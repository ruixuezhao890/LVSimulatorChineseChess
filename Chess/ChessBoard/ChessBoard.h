/**
*********************************************************************
*********
* @project_name :lvgl
* @file : ChessBoard.h
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/9/28 
*********************************************************************
*********
*/
//

#ifndef CPROJECT_CHESSBOARD_H
#define CPROJECT_CHESSBOARD_H
#include "lvgl/lvgl.h"
#include "lvglpp/src/lvglpp/core/display.h" // for scr_act()
#include "lvglpp/src/lvglpp/widgets/button/button.h" // for Button
#include "lvglpp/src/lvglpp/widgets/label/label.h" // for Label
#include "lvglpp/src/lvglpp/core/event.h" // for Event
#include "lvglpp/src/lvglpp/misc/style.h"   // for Style
#include "lvglpp/src/lvglpp/widgets/line/line.h"//for Line
#include "lvglpp/src/lvglpp/widgets/arc/arc.h" // for Arc
#include "lvglpp/src/lvglpp/misc/timer.h"
#include "list"
#include "Chess/Point/PointChess.h"
//#include "Chess/ChessPiece/ChessPiece.h"
#define ROW 10
#define COL 8
#define ChuRiver 40
#define INTERVALX 30  //X前面的间隔
#define INTERVALY 150  //Y前面的间隔
#define CHESS_GRID_SIZE 50  //格子宽度
#define DrawRadiu 30
using namespace lvgl::core;
using namespace lvgl::widgets;
class ChessPiece;

class ChessBoard {
private:
    friend class ChessPiece;
    ChessPiece* Board[COL + 1][ROW];//存储棋子
    std::list<ChessPiece*> Red,Black;
    void InitChessPiece();


public:
    const std::list<ChessPiece*> &GetRed() const;
    const std::list<ChessPiece*> &GetBlack() const;
    void DrawChessBoard();
    void DrawChess();
    ChessPiece*& GetChessBoard(const PointChess &point);
    ChessPiece*const& GetChessBoard(const PointChess &point)const;
    ChessPiece*& GetChessBoard(int x, int y);
    ChessBoard();
    ~ChessBoard();

    void ReMoveChess(const PointChess &chess);
    bool KingFaceToFace()const;
};


#endif //CPROJECT_CHESSBOARD_H
