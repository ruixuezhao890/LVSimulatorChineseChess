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
  static auto button=Button(scr_act());
  static auto label=Label(button);
  label.set_style_text_font(&myFont,LV_STATE_DEFAULT);
  label.set_text("兵");
  label.center();
  button.set_size(60,60);
//  button.set_style_radius(LV_PCT(30),LV_PART_MAIN);
  button.set_pos(60,60);
     button.center();
}

void MyMain(){

    RunTimer runtimer(10);
    runtimer.set_callback();

//    arc_1();

for(;;){

    lv_timer_handler();
    usleep(5000);

}

}
