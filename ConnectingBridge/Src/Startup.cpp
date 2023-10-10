/**
*********************************************************************
*********
* @project_name :my_libarary
* @file : Startup.cpp
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/8/11 
*********************************************************************
*********
*/
#include <unistd.h>
#include "ConnectingBridge/Inc/ConnectCplusplus.h"

#include "Chess/ChessGame/ChessGame.h"
using namespace std;
using namespace lvgl;
using namespace lvgl::core;
using namespace lvgl::misc;
using namespace lvgl::widgets;

void arc_1() {
    static std::vector<lv_point_t> points;//存储绘画点
    lv_point_t lvPoint;
    lvPoint.x=0;lvPoint.y=0;points.push_back(lvPoint);
    lvPoint.x=300;lvPoint.y=600;points.push_back(lvPoint);
    Button* button=new Button(scr_act());
    static auto line=Line(scr_act());
    auto label=new Label(*button);
    auto m_style=new Style();
    label->set_style_text_font(&myFont,LV_STATE_DEFAULT);
    label->set_style_text_color(palette::black(),LV_PART_MAIN);
    label->set_text("兵");
    label->center();
    line.set_points(points);
    button->set_size(60,60);
//    m_style->set_radius(LV_PCT(30));

    m_style->set_bg_color(color::from_rgb(95, 173, 101));
    m_style->set_bg_opa(LV_OPA_COVER);
    m_style->set_outline_width(1);//
    button->add_style(*m_style,LV_PART_MAIN);
//  button.set_style_radius(LV_PCT(30),LV_PART_MAIN);
    button->set_pos(60,150);
//     button->center();
}

void MyMain(){

    RunTimer runtimer(10);
    runtimer.set_callback();
//    ChessGame demo2;
//    arc_1();

for(;;){

    lv_timer_handler();
    usleep(5000);

}

}
