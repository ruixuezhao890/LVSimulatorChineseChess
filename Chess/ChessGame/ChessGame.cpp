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


ChessGame::ChessGame():nextPlayer(RED) {
   getPos=new SDLCOOr();
    coords.x=-1;
    coords.y=-1;
    from=PointChess(-1,-1);
    to=PointChess(-1,-1);
//    chessBoard.DrawChess();
}

const ChessBoard &ChessGame::getChessBoard() const {
    return chessBoard;
}

bool ChessGame::Move(const PointChess &from, const PointChess &to) {
    if (chessBoard.GetChessBoard(from)&&(chessBoard.GetChessBoard(from)->ChessColor
    ==nextPlayer)){
        if (chessBoard.GetChessBoard(from)->MoveTo(to)){

            nextPlayer=!nextPlayer;//测试记得改回

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
//    if ()
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
            LV_LOG_WARN("Move OK\n");
//           status=First;
            chessBoard.DrawChess();
            from.m_x = from.m_y = to.m_x = to.m_y = -1;
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
//            if(status==First&&chessBoard.GetChessBoard(coords.x, coords.y) != nullptr){
//                from.m_x = coords.x;
//                from.m_y = coords.y;
//                status=Second;
//            }
//            if(status==Second&&chessBoard.GetChessBoard(coords.x, coords.y) == nullptr){
//                to.m_x = coords.x;
//                to.m_y = coords.y;
//                status=Third;
//            }
        if (coords.x >= 0 && coords.y >= 0) {
            if (chessBoard.GetChessBoard(coords.x, coords.y) != nullptr&&(chessBoard.GetChessBoard(coords.x, coords.y)->ChessColor== nextPlayer)) {
                if ( (chessBoard.GetChessBoard(coords.x, coords.y)->ChessColor == nextPlayer)) {

                    from.m_x = coords.x;
                    from.m_y = coords.y;
                   to.m_y=to.m_x=-1;//这里必须要将该坐标设置为负坐标不然会出现bug
                   LV_LOG_WARN("from:%d %d\n", from.m_x, from.m_y);
                    return 1;
                }else{
                    return 0;
                }
                //status == Second &&
            }else if (chessBoard.GetChessBoard(coords.x, coords.y) == nullptr||
                    chessBoard.GetChessBoard(coords.x, coords.y) != nullptr&&( chessBoard.GetChessBoard(coords.x, coords.y)->ChessColor!=nextPlayer)) {

                if ( (coords.x != from.m_x || coords.y != from.m_y)) {
                    to.m_x = coords.x;
                    to.m_y = coords.y;

                   LV_LOG_WARN("to:%d %d\n", to.m_x, to.m_y);

                    return 1;
                } else {
                    return 0;
                }
            } else {
                return 0;
            }
        }

    }
    return 0;
}

