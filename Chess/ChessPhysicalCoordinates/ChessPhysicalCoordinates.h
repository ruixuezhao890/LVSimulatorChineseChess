/**
*********************************************************************
*********
* @project_name :lvgl
* @file : ChessPhysicalCoordinates.h
* @author : zen3
* @brief : None
* @attention : None
* @date : 2023/10/2 
*********************************************************************
*********
*/
//

#ifndef CPROJECT_CHESSPHYSICALCOORDINATES_H
#define CPROJECT_CHESSPHYSICALCOORDINATES_H
struct PhysicalPoint{
    int x,y;
    bool ColorOfArea() const {
        if (y<=4)
            return false;
        return true;
    }
};

class ChessPhysicalCoordinates {
public:
    virtual int getMousePosAndStatus(PhysicalPoint& physicalPoint)=0;

    virtual void getScreenPosAndStatus()=0;


};


#endif //CPROJECT_CHESSPHYSICALCOORDINATES_H
