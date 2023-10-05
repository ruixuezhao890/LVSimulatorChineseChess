/**
*********************************************************************
*********
* @project_name :lvgl
* @file : SDLCOOr.h
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/10/2 
*********************************************************************
*********
*/
//

#ifndef CPROJECT_SDLCOOR_H
#define CPROJECT_SDLCOOR_H
#include "ChessPhysicalCoordinates.h"
#include "lv_drivers/sdl/sdl_common.h"
class SDLCOOr: public ChessPhysicalCoordinates {
public:
    virtual int getMousePosAndStatus(PhysicalPoint& physicalPoint);

    virtual void getScreenPosAndStatus();
private:
    PhysicalPoint m_physicalPoint;

};


#endif //CPROJECT_SDLCOOR_H
