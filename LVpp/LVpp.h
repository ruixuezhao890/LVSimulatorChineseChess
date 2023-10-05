/**
*********************************************************************
*********
* @project_name :lvgl
* @file : LVpp.h
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/9/6 
*********************************************************************
*********
*/
#ifndef LVGL_LVPP_H
#define LVGL_LVPP_H
#include "lvgl/lvgl.h"
#include "lvglpp/src/lvglpp/core/display.h" // for scr_act()
#include "lvglpp/src/lvglpp/widgets/button/button.h" // for Button
#include "lvglpp/src/lvglpp/widgets/label/label.h" // for Label
#include "lvglpp/src/lvglpp/core/event.h" // for Event
#include "lvglpp/src/lvglpp/misc/style.h"   // for Style
#ifdef __cplusplus
extern "C"
{
#endif
/*______________________类的声明在这下面________________:*/

using namespace lvgl::core;
using namespace lvgl::widgets;
class LvppDisplayer{
public:
    void test();
    ~LvppDisplayer();

    Button*  btn0;
    Label* labelBtn0;
    Label* label;

};
extern LvppDisplayer lvppDisplayer1;
#ifdef __cplusplus
}
#endif
#endif //LVGL_LVPP_H
