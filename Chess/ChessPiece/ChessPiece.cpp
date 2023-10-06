/**
*********************************************************************
*********
* @project_name :lvgl
* @file : ChessPiece.cpp
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/9/29 
*********************************************************************
*********
*/
//

#include "ChessPiece.h"
//LV_FONT_DECLARE(myFontSong12)
#define ROW 10
#define COL 8
#define ChuRiver 40
#define INTERVALX 30  //X前面的间隔
#define INTERVALY 150  //Y前面的间隔
#define CHESS_GRID_SIZE 50  //格子宽度
#define DrawRadiu 40

#include "Chess/ChessBoard/ChessBoard.h"
using namespace lvgl::core;
using namespace lvgl::widgets;
std::list<Button*> ChessObject;


ChessPiece::ChessPiece(const PointChess &point, bool color, ChessBoard &chessboard): m_point(point), ChessColor(color), board(chessboard) {
    if (ChessColor==BLACK) board.Black.push_back(this);//不简化方便我阅读代码
    else board.Red.push_back(this);
    board.GetChessBoard(m_point)= this;
    m_button=new Button(scr_act());
    m_label=new Label(*m_button);
//    m_arc=new Arc(*m_button);
//    m_style=new Style();
    StyleInit();

}

const PointChess &ChessPiece::GetPoint() {
    return m_point;
}

bool ChessPiece::MoveTo(const PointChess &point) {
    if (CanMoveTo(point)){

        board.GetChessBoard(m_point)= nullptr;
        m_point.m_x=point.m_x;
        m_point.m_y=point.m_y;
        board.ReMoveChess(point);
        board.GetChessBoard(point)= this;

        return true;

    }
    return false;
}

void ChessPiece::Draw() {

    if (board.GetChessBoard(m_point)->ChessColor&&board.GetChessBoard(m_point)!= nullptr){

        m_label->set_style_text_color(palette::main(Color::Red),LV_STATE_DEFAULT);
        if (m_point.ColorOfArea()){
            m_button->set_pos((INTERVALX+m_point.m_x*CHESS_GRID_SIZE)-DrawRadiu/2,
                              (INTERVALY+m_point.m_y*CHESS_GRID_SIZE+ChuRiver)-DrawRadiu/2);

        }else{
            m_button->set_pos((INTERVALX+m_point.m_x*CHESS_GRID_SIZE)-DrawRadiu/2,
                              (INTERVALY+m_point.m_y*CHESS_GRID_SIZE)-DrawRadiu/2);
       }



    } else if (!board.GetChessBoard(m_point)->ChessColor&&board.GetChessBoard(m_point)!= nullptr){
        m_label->set_style_text_color(palette::black(),LV_STATE_DEFAULT);
        if (m_point.ColorOfArea()){
            m_button->set_pos((INTERVALX+m_point.m_x*CHESS_GRID_SIZE)-DrawRadiu/2,
                              (INTERVALY+m_point.m_y*CHESS_GRID_SIZE+ChuRiver)-DrawRadiu/2);

        }else{
            m_button->set_pos((INTERVALX+m_point.m_x*CHESS_GRID_SIZE)-DrawRadiu/2,
                              (INTERVALY+m_point.m_y*CHESS_GRID_SIZE)-DrawRadiu/2);
        }
//        m_button->set_pos((INTERVALX+m_point.m_x*CHESS_GRID_SIZE)-DrawRadiu/2,
//                          (INTERVALY+m_point.m_y*CHESS_GRID_SIZE)-DrawRadiu/2);
    }

    string temp=board.GetChessBoard(m_point)->GetName(); m_label->set_text(temp);
    m_label->center();




}

PhysicalPoint ChessPiece::getScreenPixelsXY() {//得到棋子屏幕像素 方便与点击像素做对比
   PhysicalPoint temp;
   temp.x=m_point.m_x+INTERVALX;
    if (m_point.ColorOfArea()){//红
        temp.y=m_point.m_y+INTERVALY+ChuRiver;

    }
    else{
        temp.y=m_point.m_y+INTERVALY;
    }
    return temp;
}

void ChessPiece::DeleteButton() {


//    delete m_style;
//    delete m_arc;
    delete m_label;
    delete m_button;//被释放时Object基类会自动调用lv_obj_del函数
//    m_style= nullptr;
    m_arc= nullptr;
    m_label= nullptr;
    m_button= nullptr;
    lv_refr_now(nullptr);
//    LV_LOG_WARN("delete OK\n");
}

void ChessPiece::StyleInit() {

    m_button->set_size(40,40);
    m_button->set_style_border_color(palette::black(),LV_STATE_DEFAULT);
    m_button->set_style_border_opa(100, LV_STATE_DEFAULT);
    m_button->set_style_outline_width(1, LV_STATE_DEFAULT);
    m_button->set_style_radius(LV_PCT(DrawRadiu),LV_STATE_DEFAULT);
    m_button->set_style_bg_color(color::from_rgb(234, 236, 234),LV_STATE_DEFAULT);

    m_label->set_style_text_font(&myFont,LV_STATE_DEFAULT);

}







