/**
*********************************************************************
*********
* @project_name :lvgl
* @file : ChessBoard.cpp
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/9/28 
*********************************************************************
*********
*/
//

#include "ChessBoard.h"
#include "vector"
#include "Chess/ChessPiece/ChessPiece.h"
#include "Chess/ChessPiece/Rook.h"
#include "Chess/ChessPiece/Horse.h"
#include "Chess/ChessPiece/Cannon.h"
#include "Chess/ChessPiece/Elephant.h"
#include "Chess/ChessPiece/King.h"
#include "Chess/ChessPiece/Adviser.h"
#include "Chess/ChessPiece/Pawn.h"

void ChessBoard::DrawChessBoard() {
    static std::vector<lv_point_t> pointsRow;//棋盘的所有行
    static std::vector<lv_point_t> pointsColBlack;//黑方竖线
    static std::vector<lv_point_t> pointsColRed;//红方竖线
    static std::vector<lv_point_t> pointsObliqueLineBlack;//黑色斜线
    static std::vector<lv_point_t> pointsObliqueLineRed;//红色斜线
    lv_point_t tempPoint1={0, 0};
    lv_point_t tempPoint2={0, 0};
    auto root=layer_top();


    static auto label=Label(root);
    static auto label1=Label(root);
    static auto lineRow=Line(root);
    static auto lineColBlack=Line(root);
    static auto lineColRed=Line(root);
    static auto ObliqueLineBlack=Line(root);
    static auto ObliqueLineRed=Line(root);
    label.set_text("楚      河");
    label.set_style_text_font(&myFont,LV_PART_MAIN);
    label.set_style_text_align(LV_TEXT_ALIGN_CENTER,0);
    label.set_style_text_color(palette::black(),0);
    label.set_size(INTERVALX + 8*CHESS_GRID_SIZE+35,ChuRiver*2+10);
   label.align(LV_ALIGN_CENTER,-(INTERVALX+2*CHESS_GRID_SIZE),ChuRiver/2);
   label1.set_text("汉      界");
   label1.set_style_text_font(&myFont,LV_PART_MAIN);
   label1.set_style_text_align(LV_TEXT_ALIGN_CENTER,0);
   label1.set_style_text_color(palette::black(),0);
   label1.set_size(INTERVALX + 8*CHESS_GRID_SIZE+35,ChuRiver*2+10);
   label1.align(LV_ALIGN_CENTER,(INTERVALX+2*CHESS_GRID_SIZE),ChuRiver/2);

    tempPoint1.x=INTERVALX;tempPoint1.y=INTERVALY + (ROW-1) * CHESS_GRID_SIZE+ChuRiver;pointsRow.push_back(tempPoint1);
    tempPoint1.x=INTERVALX;tempPoint1.y=INTERVALY;pointsRow.push_back(tempPoint1);
    tempPoint2.x=INTERVALX + COL*CHESS_GRID_SIZE;tempPoint2.y=INTERVALY;pointsRow.push_back(tempPoint2);
    tempPoint2.x=INTERVALX + COL*CHESS_GRID_SIZE;tempPoint2.y=INTERVALY + (ROW-1) * CHESS_GRID_SIZE+ChuRiver;pointsRow.push_back(tempPoint2);
    tempPoint1.x=INTERVALX;tempPoint1.y=INTERVALY + (ROW-1) * CHESS_GRID_SIZE+ChuRiver;pointsRow.push_back(tempPoint1);
    for (int i = 0; i < 9; i++) {

        if (i % 2 == 0) {//画横线
            tempPoint1.x = INTERVALX;
            int tempy1 = (i > 4 ? INTERVALY + i * CHESS_GRID_SIZE + ChuRiver : INTERVALY + i * CHESS_GRID_SIZE);
            tempPoint1.y = tempy1;
            pointsRow.push_back(tempPoint1);
            tempPoint1.x = INTERVALX;
            int tempy2 = (i >=4? INTERVALY + (i + 1) * CHESS_GRID_SIZE + ChuRiver : INTERVALY +
                    (i + 1) * CHESS_GRID_SIZE);
            tempPoint1.y = tempy2;
            pointsRow.push_back(tempPoint1);
        } else {
            tempPoint2.x = INTERVALX + COL * CHESS_GRID_SIZE;
            int tempy1 = (i > 4 ? INTERVALY + i * CHESS_GRID_SIZE + ChuRiver : INTERVALY + i * CHESS_GRID_SIZE);
            tempPoint2.y = tempy1;
            pointsRow.push_back(tempPoint2);
            tempPoint2.x = INTERVALX + COL * CHESS_GRID_SIZE;
            int tempy2 = (i >=4 ? INTERVALY + (i + 1) * CHESS_GRID_SIZE + ChuRiver : INTERVALY +
                    (i + 1) * CHESS_GRID_SIZE);
            tempPoint2.y = tempy2;

            pointsRow.push_back(tempPoint2);

        }
        if (i<8){//画竖线
            if (i%2!=0){
                tempPoint1.x=INTERVALX+i*CHESS_GRID_SIZE;tempPoint1.y=INTERVALY+4*CHESS_GRID_SIZE;
                pointsColBlack.push_back(tempPoint1);
                tempPoint1.y+=ChuRiver+5*CHESS_GRID_SIZE;pointsColRed.push_back(tempPoint1);//红色方只是在黑色的基础上加了一个楚河的y距离和
                                                                            // 整个红色方占的y轴
                tempPoint1.x=INTERVALX+(i+1)*CHESS_GRID_SIZE;tempPoint1.y=INTERVALY+4*CHESS_GRID_SIZE;
                pointsColBlack.push_back(tempPoint1);
                tempPoint1.y+=ChuRiver+5*CHESS_GRID_SIZE;pointsColRed.push_back(tempPoint1);



            }
            else{
                tempPoint2.x=INTERVALX+i*CHESS_GRID_SIZE;tempPoint2.y=INTERVALY;
                pointsColBlack.push_back(tempPoint2);
                tempPoint2.y+=ChuRiver+5*CHESS_GRID_SIZE;pointsColRed.push_back(tempPoint2);//红色方的列
                tempPoint2.x=INTERVALX+(i+1)*CHESS_GRID_SIZE;tempPoint2.y=INTERVALY;
                pointsColBlack.push_back(tempPoint2);
                tempPoint2.y+=ChuRiver+5*CHESS_GRID_SIZE;pointsColRed.push_back(tempPoint2);

            }



        }else{
            tempPoint1.x=INTERVALX+8*CHESS_GRID_SIZE;tempPoint1.y=INTERVALY;
            pointsColBlack.push_back(tempPoint1);
            tempPoint1.y+=ChuRiver+5*CHESS_GRID_SIZE;
            pointsColRed.push_back(tempPoint1);
        }


    }

    lineRow.set_points(pointsRow);
    lineColBlack.set_points(pointsColBlack);
    lineColRed.set_points(pointsColRed);
    //画斜线
    tempPoint1.x=INTERVALX+3*CHESS_GRID_SIZE;
    tempPoint1.y=INTERVALY;pointsObliqueLineBlack.push_back(tempPoint1);//黑方
    tempPoint1.y=INTERVALY+7*CHESS_GRID_SIZE+ChuRiver;pointsObliqueLineRed.push_back(tempPoint1);//红方

    tempPoint1.x=INTERVALX+5*CHESS_GRID_SIZE;
    tempPoint1.y=INTERVALY;pointsObliqueLineBlack.push_back(tempPoint1);
    tempPoint1.y=INTERVALY+7*CHESS_GRID_SIZE+ChuRiver;pointsObliqueLineRed.push_back(tempPoint1);

    tempPoint1.x=INTERVALX+3*CHESS_GRID_SIZE;
    tempPoint1.y=INTERVALY+2*CHESS_GRID_SIZE;pointsObliqueLineBlack.push_back(tempPoint1);
    tempPoint1.y=INTERVALY+9*CHESS_GRID_SIZE+ChuRiver;pointsObliqueLineRed.push_back(tempPoint1);


    tempPoint1.x=INTERVALX+5*CHESS_GRID_SIZE;
    tempPoint1.y=INTERVALY+2*CHESS_GRID_SIZE;pointsObliqueLineBlack.push_back(tempPoint1);
    tempPoint1.y=INTERVALY+9*CHESS_GRID_SIZE+ChuRiver;pointsObliqueLineRed.push_back(tempPoint1);

    tempPoint1.x=INTERVALX+3*CHESS_GRID_SIZE;
    tempPoint1.y=INTERVALY;pointsObliqueLineBlack.push_back(tempPoint1);//黑方
    tempPoint1.y=INTERVALY+7*CHESS_GRID_SIZE+ChuRiver;pointsObliqueLineRed.push_back(tempPoint1);//红方

    ObliqueLineBlack.set_points(pointsObliqueLineBlack);
    ObliqueLineRed.set_points(pointsObliqueLineRed);






}

ChessBoard::ChessBoard() {

    InitChessPiece();
    DrawChess();
    DrawChessBoard();

}

ChessBoard::~ChessBoard() {
    for (ChessPiece* p : Red)
        delete p;
    for (ChessPiece* p : Black)
        delete p;
}

void ChessBoard::DrawChess() {

    static uint8_t count=0; count++;
    for (int i = 0; i < (COL+1); ++i) {
        for (int j = 0; j <ROW; ++j) {
            if (this->Board[i][j] != nullptr){
                this->Board[i][j]->Draw();
            }
        }
    }

}

void ChessBoard::InitChessPiece() {
    for (auto & i : Board) {
        for (auto & j : i) {
            j = nullptr;

        }
    }
    new Rook(PointChess(0,0),BLACK,*this);
    new Rook(PointChess(0,9),RED,*this);
    new Cannon(PointChess(1,7),RED,*this);//测试
    new Cannon(PointChess(1,2),BLACK,*this);//测试
    new Horse(PointChess(1,9),RED,*this);
    new Horse(PointChess(1,0),BLACK,*this);
    new Elephant(PointChess(2,0),BLACK,*this);
    new Elephant(PointChess(2,9),RED,*this);
    new Adviser(PointChess(3,0),BLACK,*this);
    new Adviser(PointChess(3,9),RED,*this);

    new King(PointChess(4,0),BLACK,*this);
    new King(PointChess(4,9),RED,*this);

    new Rook(PointChess(8,0),BLACK,*this);
    new Rook(PointChess(8,9),RED,*this);
    new Cannon(PointChess(7,7),RED,*this);//测试
    new Cannon(PointChess(7,2),BLACK,*this);//测试
    new Horse(PointChess(7,9),RED,*this);
    new Horse(PointChess(7,0),BLACK,*this);
    new Elephant(PointChess(6,0),BLACK,*this);
    new Elephant(PointChess(6,9),RED,*this);
    new Adviser(PointChess(5,0),BLACK,*this);
    new Adviser(PointChess(5,9),RED,*this);
    new Pawn(PointChess(0,3),BLACK,*this);
    new Pawn(PointChess(2,3),BLACK,*this);
    new Pawn(PointChess(4,3),BLACK,*this);
    new Pawn(PointChess(6,3),BLACK,*this);
    new Pawn(PointChess(8,3),BLACK,*this);
    new Pawn(PointChess(0,6),RED,*this);
    new Pawn(PointChess(2,6),RED,*this);
    new Pawn(PointChess(4,6),RED,*this);
    new Pawn(PointChess(6,6),RED,*this);
    new Pawn(PointChess(8,6),RED,*this);

}

ChessPiece *&ChessBoard::GetChessBoard(const PointChess &point) {
    return Board[point.m_x][point.m_y];
}

void ChessBoard::ReMoveChess(const PointChess &point) {
    if (GetChessBoard(point)) {
        if (GetChessBoard(point)->ChessColor == RED) {
            Red.erase(std::find(Red.begin(), Red.end(), GetChessBoard(point)));//寻找list列表中是否含有相同的的地址将其删除
        } else {
            Black.erase(std::find(Black.begin(), Black.end(), GetChessBoard(point)));
        }
        GetChessBoard(point)->DeleteButton();
        delete GetChessBoard(point);//释放开辟的指针
        GetChessBoard(point) = nullptr;//置为空指针

    }
}

ChessPiece *&ChessBoard::GetChessBoard(int x, int y) {

    return Board[x][y];
}

ChessPiece *const &ChessBoard::GetChessBoard(const PointChess &point) const {
    return Board[point.m_x][point.m_y];
}

bool ChessBoard::KingFaceToFace() const {
 auto r=std::find_if(Red.begin(),Red.end(),[](ChessPiece* p){
  return dynamic_cast<King*>(p)!= nullptr;}),
     b=std::find_if(Black.begin(),Black.end(),[](ChessPiece* p){
  return dynamic_cast<King*>(p)!= nullptr;});
    if (r!=Red.end()&&b!=Black.end()){
        if ((*r)->GetPoint().m_x==(*b)->GetPoint().m_x){
            for (uint8_t i = (*r)->GetPoint().m_y; i < (*b)->GetPoint().m_y; ++i) {
                if (GetChessBoard(PointChess((*r)->GetPoint().m_x,i))){
                    return false;
                }
            }
            return true;
        }

    }

    return false;
}


