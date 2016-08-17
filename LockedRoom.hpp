/*********************************************************************
 **** Program Filename: LockedRoom.hpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:  This a program a menu driven game in which the user gets
 **** to choose his options to perform certain tasks.
 **** Input: The user gets to pick his options.
 **** Output: Taks are accomplished based on the options chosen, and that
 *is what the program outputs.
 ***********************************************************************/


#ifndef LockedRoom_hpp
#define LockedRoom_hpp

#include <stdio.h>
#include "Room.hpp"

class LockedRoom : public Room
{

    
public:
    LockedRoom();
    Room* getToEast();
    Room* getToWest();
    Room* getToNorth();
    Room* getToSouth();
    std::string getDesc();
    std::string getExtendedDesc();
    
    void showMoreOptions();
    std::string makeItSo(int);
    std::string itemThatLetsMeDo(int);
    std::string itemThatPreventsMeDo(int);
// bool to check if the user can head in specific direction
    bool eastLocked;
    bool westLocked;
    bool northLocked;
    bool southLocked;
    
    void lockEast();  // function to lock east
    void lockWest();  // function to lock west
    void lockSouth();  // function to lock south
    void lockNorth();  // function to lock north
    void unlockEast();  // function to unlock east
    void unlockWest();  // function to unlock west
    void unlockSouth();  // function to unlock south
    void unlockNorth();  // function to unlock north
    
    
    
};



#endif /* LockedRoom_hpp */





















































