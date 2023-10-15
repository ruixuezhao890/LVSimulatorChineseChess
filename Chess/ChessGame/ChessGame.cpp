/**
*********************************************************************
*********
* @project_name :lvgl
* @file : ChessGame.cpp
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/9/29 
*********************************************************************
*********
*/
//


#include <SDL2/SDL_mouse.h>
#include "ChessGame.h"
#include "Chess/ChessPiece/ChessPiece.h"
#include "lv_drivers/sdl/sdl_common.h"
#include "Chess/ChessPiece/King.h"


ChessGame::ChessGame():nextPlayer(RED) {
    getPos=new SDLCOOr();
    ControlTimeLabel=new Label(scr_act());
    ControlTimeLabel->align(LV_ALIGN_CENTER,0,ChuRiver/16);
    ControlTimeLabel->set_size(100,50);ControlTime=REMAININGTIME;
    ControlTimeLabel->set_text_fmt("时间剩余%d红方", ControlTime);
    coords.x=-1;
    coords.y=-1;
    from=PointChess(-1,-1);
    to=PointChess(-1,-1);
}

const ChessBoard &ChessGame::getChessBoard() const {
    return chessBoard;
}

bool ChessGame::Move(const PointChess &from, const PointChess &to) {
    if (chessBoard.GetChessBoard(from)&&(chessBoard.GetChessBoard(from)->ChessColor
    ==nextPlayer)){
        if (chessBoard.GetChessBoard(from)->MoveTo(to)){
            nextPlayer=!nextPlayer;
            ControlTime=REMAININGTIME+1;
            return true;
        }
        return false;
    }
    return false;
}

uint8_t ChessGame::GetWinner() const {
    if (chessBoard.KingFaceToFace()) {
        return nextPlayer;
    }
   if(std::find_if(chessBoard.GetRed().begin(),chessBoard.GetRed().end(),[](ChessPiece *p){
       return  dynamic_cast<King*>(p)!= nullptr;})==chessBoard.GetRed().end()){//红方帅被吃
            return BLACK;
       }
    if (std::find_if(chessBoard.GetBlack().begin(),chessBoard.GetBlack().end(),[](ChessPiece *p){
       return  dynamic_cast<King*>(p)!= nullptr;})==chessBoard.GetBlack().end()){//黑方帅被吃
            return RED;
       }
    if (std::count_if(chessBoard.GetRed().begin(), chessBoard.GetRed().end(), [](ChessPiece* p) {return p->CanCrossTheRiver(); }) +
        std::count_if(chessBoard.GetBlack().begin(),chessBoard.GetBlack().end(), [](ChessPiece* p) {return p->CanCrossTheRiver(); }) == 0){
        return DRAW;//双方都不能过河，平局
    }
    return NONE;
}

bool ChessGame::GetNextPlayer() const {
    return nextPlayer;
}

ChessGame::~ChessGame() {

}

void ChessGame::Run() {
    if (from.m_x>=0&&from.m_y>=0&&to.m_x>=0&&to.m_y>=0){
        if ( Move(from,to)) {
//            LV_LOG_WARN("Move OK\n");
            chessBoard.DrawChess();
            from.m_x = from.m_y = to.m_x = to.m_y = -1;
        }
    }
    uint8_t Judge=GetWinner();
    if (Judge!=NONE) {
        if (Judge==RED){
            ControlTimeLabel->set_text("红方胜利");
        } else if (Judge==BLACK){
            ControlTimeLabel->set_text("黑方胜利");
        } else if(Judge==DRAW){
            ControlTimeLabel->set_text("平局");
        }
    }


}

uint8_t ChessGame::GetScreenPos() {

    if (getPos->getMousePosAndStatus(last_mouse_pos)) {

        coords.x = (last_mouse_pos.x - INTERVALX) / CHESS_GRID_SIZE;
        coords.y = (last_mouse_pos.y - INTERVALY) / CHESS_GRID_SIZE;
        if (coords.y < 0 || coords.x < 0||coords.y >= ROW || coords.x >= COL) {
            return 0;
        }
     //   LV_LOG_WARN("%d %d\n", coords.x, coords.y);
        int boardCurrentPixelsY = 0;
        int boardCurrentPixelsX = coords.x * CHESS_GRID_SIZE + INTERVALX;
        if (coords.y > 4) {
            boardCurrentPixelsY = coords.y * CHESS_GRID_SIZE + INTERVALY + ChuRiver;
        } else {
            boardCurrentPixelsY = coords.y * CHESS_GRID_SIZE + INTERVALY;
        }
        if ((last_mouse_pos.x > (boardCurrentPixelsX + CHESS_GRID_SIZE / 2)) &&
            (last_mouse_pos.y < (boardCurrentPixelsY + CHESS_GRID_SIZE / 2))) {
            if (coords.x < COL)
                coords.x++;
        }
        if ((last_mouse_pos.x < (boardCurrentPixelsX + CHESS_GRID_SIZE / 2)) &&
            (last_mouse_pos.y > (boardCurrentPixelsY + CHESS_GRID_SIZE / 2))) {
            if (coords.y < ROW - 1)
                coords.y++;
        }
        if ((last_mouse_pos.x > (boardCurrentPixelsX + CHESS_GRID_SIZE / 2)) &&
            (last_mouse_pos.y > (boardCurrentPixelsY + CHESS_GRID_SIZE / 2))) {
            if (coords.x < COL && coords.y < (ROW - 1)) {
                coords.x++;
                coords.y++;
            }
        }
        if (coords.x >= 0 && coords.y >= 0) {
            if (chessBoard.GetChessBoard(coords.x, coords.y) != nullptr&&(chessBoard.GetChessBoard(coords.x, coords.y)->ChessColor== nextPlayer)) {
                if ( (chessBoard.GetChessBoard(coords.x, coords.y)->ChessColor == nextPlayer)) {
                    //选中时颜色修改
                    if(from.m_x==-1&&from.m_y==-1){//第一次点击
                    chessBoard.GetChessBoard(coords.x,coords.y)->StyleUpdate(color::from_rgb(134, 200, 200));
                    }else if(from.m_x!=-1&&from.m_y!=-1&&(from.m_x!=coords.x||from.m_y!=coords.y)) {
                        chessBoard.GetChessBoard(coords.x,coords.y)->StyleUpdate(color::from_rgb(134, 200, 200));
                        chessBoard.GetChessBoard(from.m_x,from.m_y)->StyleUpdate(palette::white());

                    }
                    from.m_x = coords.x;
                    from.m_y = coords.y;
                    to.m_y = to.m_x = -1;//这里必须要将该坐标设置为负坐标不然会出现bug
                        LV_LOG_WARN("from:%d %d\n", from.m_x, from.m_y);
                        return 1;
                }
            }else if (chessBoard.GetChessBoard(coords.x, coords.y) == nullptr||
                    chessBoard.GetChessBoard(coords.x, coords.y) != nullptr&&( chessBoard.GetChessBoard(coords.x, coords.y)->ChessColor!=nextPlayer)) {

                if ( (coords.x != from.m_x || coords.y != from.m_y)) {
                    to.m_x = coords.x;
                    to.m_y = coords.y;
                    //移动之后颜色清除
                    if (from.m_x != -1 && from.m_y != -1) {
                        chessBoard.GetChessBoard(from.m_x,from.m_y)->StyleUpdate(palette::white());
                    }
                   LV_LOG_WARN("to:%d %d\n", to.m_x, to.m_y);
                    return 1;
                }
            } else {
                return 0;
            }
        }

    }
    return 0;
}

void ChessGame::updateControlTime() {
    static uint32_t count=0;
    count++;
    if (count % 100 == 0) {
        string temp;
        LV_LOG_WARN("count:%d\n", count);
        ControlTime--;
        ControlTimeLabel->set_style_text_font(&myFont,LV_STATE_DEFAULT);
        GetNextPlayer()?temp="时间剩余"+to_string(ControlTime)+"红方":temp="时间剩余"+to_string(ControlTime)+"黑方";
        ControlTimeLabel->set_text(temp);
        if (ControlTime == 0) {
            ControlTimeLabel->set_text("超时");
            ControlTime=REMAININGTIME;
            nextPlayer=!nextPlayer;
        }
        count = 0;
    }
}

