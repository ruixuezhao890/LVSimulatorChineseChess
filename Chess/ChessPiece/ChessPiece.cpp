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
#define ROW 10
#define COL 8
#define ChuRiver 40
#define INTERVALX 30  //X前面的间隔
#define INTERVALY 150  //Y前面的间隔
#define CHESS_GRID_SIZE 50  //格子宽度
#define DrawRadiu 40
//#include "lvgl/lvgl.h"
//#include "lvglpp/src/lvglpp/core/display.h" // for scr_act()
//#include "lvglpp/src/lvglpp/widgets/button/button.h" // for Button
//#include "lvglpp/src/lvglpp/widgets/label/label.h" // for Label
//#include "lvglpp/src/lvglpp/core/event.h" // for Event
//#include "lvglpp/src/lvglpp/misc/style.h"   // for Style
//#include "lvglpp/src/lvglpp/widgets/line/line.h"//for Line
//#include "lvglpp/src/lvglpp/widgets/arc/arc.h" // for Arc
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
//    static uint8_t  count=0;
    m_button->set_size(40,40);
    if (m_point.ColorOfArea()&&board.GetChessBoard(m_point)!= nullptr){
        //todo 记得在这里做棋子文字颜色样式判断
//         count++;
        m_button->set_pos((INTERVALX+m_point.m_x*CHESS_GRID_SIZE)-DrawRadiu/2,
                          (INTERVALY+m_point.m_y*CHESS_GRID_SIZE+ChuRiver)-DrawRadiu/2);
//        LV_LOG_WARN("%d  %d  %d %s\n",count,board.GetChessBoard(m_point)->GetPoint().m_x,board.GetChessBoard(m_point)->GetPoint().m_y,
//                    board.GetChessBoard(m_point)->GetName());

    } else if (!m_point.ColorOfArea()&&board.GetChessBoard(m_point)!= nullptr){
        m_button->set_pos((INTERVALX+m_point.m_x*CHESS_GRID_SIZE)-DrawRadiu/2,
                          (INTERVALY+m_point.m_y*CHESS_GRID_SIZE)-DrawRadiu/2);
    }
    //todo 记得在这里做棋子背景样式替换
    m_button->set_style_radius(LV_PCT(DrawRadiu),LV_PART_MAIN);
    m_label->set_text(GetName());m_label->align(LV_DIR_LEFT,-15,0);
//    m_label->set_style_radius(LV_PCT(DrawRadiu),LV_PART_MAIN);
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

//    m_label->release_ptr();
//    m_button->release_ptr();
//

//
    delete m_label;
    delete m_button;//被释放时Object基类会自动调用lv_obj_del函数
    m_label= nullptr;
    m_button= nullptr; lv_refr_now(nullptr);
//    LV_LOG_WARN("delete OK\n");
}

//void ChessPiece::Draw(const PointChess &point) {
//    static uint8_t  count=0;
//    m_button->set_size(40,40);
//    if (point.ColorOfArea()&&board.GetChessBoard(point)!= nullptr){
//        //todo 记得在这里做棋子文字颜色样式判断
//        count++;
//        m_button->set_pos((INTERVALX+point.m_x*CHESS_GRID_SIZE)-DrawRadiu/2,
//                          (INTERVALY+point.m_y*CHESS_GRID_SIZE+ChuRiver)-DrawRadiu/2);
//        LV_LOG_WARN("%d  %d  %d %s\n",count,board.GetChessBoard(point)->GetPoint().m_x,board.GetChessBoard(point)->GetPoint().m_y,
//                    board.GetChessBoard(point)->GetName());
//
//    } else if (!point.ColorOfArea()&&board.GetChessBoard(point)!= nullptr){
//        m_button->set_pos((INTERVALX+point.m_x*CHESS_GRID_SIZE)-DrawRadiu/2,
//                          (INTERVALY+point.m_y*CHESS_GRID_SIZE)-DrawRadiu/2);
//    }
//    //todo 记得在这里做棋子背景样式替换
//    m_button->set_style_radius(LV_PCT(DrawRadiu),LV_PART_MAIN);
//    m_label->set_text(GetName());m_label->align(LV_DIR_LEFT,-15,0);
//}

//void ChessPiece::GreatButton() {
//   auto temp1=new Button(scr_act());
//    auto temp2=new Label(*temp1);
//    m_button=temp1;
//    m_label=temp2;
//}






