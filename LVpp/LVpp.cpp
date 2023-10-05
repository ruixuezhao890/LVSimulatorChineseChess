/**
*********************************************************************
*********
* @project_name :lvgl
* @file : LVpp.cpp
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/9/6 
*********************************************************************
*********
*/
//

#include "LVpp.h"

LvppDisplayer lvppDisplayer1;
void LvppDisplayer::test() {
    auto Father=scr_act();
//
    static Container obj1 = Container(Father);
    obj1.set_size(100, 50);
    obj1.align(LV_ALIGN_CENTER, -60, -30);

    static Style style_shadow;
    style_shadow.set_shadow_width(10);
    style_shadow.set_shadow_spread(5);
    style_shadow.set_shadow_color(palette::main(Color::Blue));


    this->label=new Label(obj1);
  label->center();


}

LvppDisplayer::~LvppDisplayer() {

}





