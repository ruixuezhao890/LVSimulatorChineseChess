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
void ChessBoard::DrawChessBoard() {
    static std::vector<lv_point_t> pointsRow;//���̵�������
    static std::vector<lv_point_t> pointsColBlack;//�ڷ�����
    static std::vector<lv_point_t> pointsColRed;//�췽����
    static std::vector<lv_point_t> pointsObliqueLineBlack;//��ɫб��
    static std::vector<lv_point_t> pointsObliqueLineRed;//��ɫб��
    lv_point_t tempPoint1={0, 0};
    lv_point_t tempPoint2={0, 0};
    auto root=scr_act();

    static auto label=Label(root);
    static auto lineRow=Line(root);
    static auto lineColBlack=Line(root);
    static auto lineColRed=Line(root);
    static auto ObliqueLineBlack=Line(root);
    static auto ObliqueLineRed=Line(root);
    static Style style;
    style.set_border_color(palette::black());
    style.set_border_width(2);
    style.set_border_opa(LV_OPA_50);
    style.set_border_side(LV_BORDER_SIDE_FULL);
    label.set_text("chuhe    hanjie");
    label.set_style_text_font(&lv_font_montserrat_16,LV_PART_MAIN);
    label.set_style_text_align(LV_TEXT_ALIGN_CENTER,0);
    label.set_style_text_color(palette::black(),0);
    label.set_size(INTERVALX + 8*CHESS_GRID_SIZE+35,ChuRiver*2+10);
   // label.add_style(style,LV_STATE_DEFAULT);
    label.set_pos(INTERVALX,INTERVALY+4*CHESS_GRID_SIZE);
    //label.center();
    tempPoint1.x=INTERVALX;tempPoint1.y=INTERVALY + (ROW-1) * CHESS_GRID_SIZE+ChuRiver;pointsRow.push_back(tempPoint1);
    tempPoint1.x=INTERVALX;tempPoint1.y=INTERVALY;pointsRow.push_back(tempPoint1);
    tempPoint2.x=INTERVALX + COL*CHESS_GRID_SIZE;tempPoint2.y=INTERVALY;pointsRow.push_back(tempPoint2);
    tempPoint2.x=INTERVALX + COL*CHESS_GRID_SIZE;tempPoint2.y=INTERVALY + (ROW-1) * CHESS_GRID_SIZE+ChuRiver;pointsRow.push_back(tempPoint2);
    tempPoint1.x=INTERVALX;tempPoint1.y=INTERVALY + (ROW-1) * CHESS_GRID_SIZE+ChuRiver;pointsRow.push_back(tempPoint1);
    for (int i = 0; i < 9; i++) {

        if (i % 2 == 0) {//������
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
        if (i<8){//������
            if (i%2!=0){
                tempPoint1.x=INTERVALX+i*CHESS_GRID_SIZE;tempPoint1.y=INTERVALY+4*CHESS_GRID_SIZE;
                pointsColBlack.push_back(tempPoint1);
                tempPoint1.y+=ChuRiver+5*CHESS_GRID_SIZE;pointsColRed.push_back(tempPoint1);//��ɫ��ֻ���ں�ɫ�Ļ����ϼ���һ�����ӵ�y�����
                                                                            // ������ɫ��ռ��y��
                tempPoint1.x=INTERVALX+(i+1)*CHESS_GRID_SIZE;tempPoint1.y=INTERVALY+4*CHESS_GRID_SIZE;
                pointsColBlack.push_back(tempPoint1);
                tempPoint1.y+=ChuRiver+5*CHESS_GRID_SIZE;pointsColRed.push_back(tempPoint1);



            }
            else{
                tempPoint2.x=INTERVALX+i*CHESS_GRID_SIZE;tempPoint2.y=INTERVALY;
                pointsColBlack.push_back(tempPoint2);
                tempPoint2.y+=ChuRiver+5*CHESS_GRID_SIZE;pointsColRed.push_back(tempPoint2);//��ɫ������
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
    //��б��
    tempPoint1.x=INTERVALX+3*CHESS_GRID_SIZE;
    tempPoint1.y=INTERVALY;pointsObliqueLineBlack.push_back(tempPoint1);//�ڷ�
    tempPoint1.y=INTERVALY+7*CHESS_GRID_SIZE+ChuRiver;pointsObliqueLineRed.push_back(tempPoint1);//�췽

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
    tempPoint1.y=INTERVALY;pointsObliqueLineBlack.push_back(tempPoint1);//�ڷ�
    tempPoint1.y=INTERVALY+7*CHESS_GRID_SIZE+ChuRiver;pointsObliqueLineRed.push_back(tempPoint1);//�췽

    ObliqueLineBlack.set_points(pointsObliqueLineBlack);
    ObliqueLineRed.set_points(pointsObliqueLineRed);






}

ChessBoard::ChessBoard() {
    InitChessPiece();
    DrawChessBoard();
    DrawChess();
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
                LV_LOG_WARN("%d  %d  %d %d  %d %s\n",count,Board[i][j]->GetPoint().m_x,Board[i][j]->GetPoint().m_y,i,j,
                            Board[i][j]->GetName());
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
    new Cannon(PointChess(1,7),RED,*this);//����
    new Cannon(PointChess(1,3),BLACK,*this);//����
    new Horse(PointChess(1,9),RED,*this);
    new Horse(PointChess(1,0),BLACK,*this);

}

ChessPiece *&ChessBoard::GetChessBoard(const PointChess &point) {
    return Board[point.m_x][point.m_y];
}

void ChessBoard::ReMoveChess(const PointChess &point) {
    if (GetChessBoard(point)) {
        if (GetChessBoard(point)->ChessColor == RED) {
            Red.erase(std::find(Red.begin(), Red.end(), GetChessBoard(point)));//Ѱ��list�б����Ƿ�����ͬ�ĵĵ�ַ����ɾ��
        } else {
            Black.erase(std::find(Black.begin(), Black.end(), GetChessBoard(point)));
        }
        GetChessBoard(point)->DeleteButton();
        delete GetChessBoard(point);//�ͷſ��ٵ�ָ��
        GetChessBoard(point) = nullptr;//��Ϊ��ָ��
//    Board[point.m_x][point.m_y].;

    }
}

ChessPiece *&ChessBoard::GetChessBoard(int x, int y) {

    return Board[x][y];
}

ChessPiece *const &ChessBoard::GetChessBoard(const PointChess &point) const {
    return Board[point.m_x][point.m_y];
}

bool ChessBoard::KingFaceToFace() const {
// auto r=std::find_if(Red.begin(),Red.end(),[](ChessPiece* p){
//  return dynamic_cast<King*>(p)!= nullptr;}),
//     b=std::find_if(Black.begin(),Black.end(),[](ChessPiece* p){
//  return dynamic_cast<King*>(p)!= nullptr;});
//    if (r!=Red.end()&&b!=Black.end()){
//        if ((*r)->GetPoint().m_x==(*b)->GetPoint().m_x){
//            for (uint8_t i = (*r)->GetPoint().m_y; i < (*b)->GetPoint().m_y; ++i) {
//                if (GetChessBoard(PointChess((*r)->GetPoint().m_x,i))){
//                    return false;
//                }
//            }
//            return true;
//        }
//
//    }
//
    return false;
}

