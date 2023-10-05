/**
*********************************************************************
*********
* @project_name :lvgl
* @file : SDLCOOr.cpp
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/10/2 
*********************************************************************
*********
*/
//

#include <SDL2/SDL.h>
#include <cstdio>
#include "SDLCOOr.h"

int SDLCOOr::getMousePosAndStatus(PhysicalPoint& physicalPoint) {
    if (TransmissionLast_x>0&&TransmissionLast_x<SDL_HOR_RES
        &&TransmissionLast_y>0&&TransmissionLast_y<SDL_VER_RES) {
        physicalPoint.x = TransmissionLast_x;
        physicalPoint.y = TransmissionLast_y;
//        LV_LOG_WARN("x%d y%d\n",TransmissionLast_x,TransmissionLast_y);
        TransmissionLast_x = 0;
        TransmissionLast_y = 0;
        return 1;
    }
    return 0;


}

void SDLCOOr::getScreenPosAndStatus() {

}


