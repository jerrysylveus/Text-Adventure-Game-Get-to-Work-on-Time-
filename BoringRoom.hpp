/*********************************************************************
 **** Program Filename: BoringRoom.hpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:  This a program a menu driven game in which the user gets
 **** to choose his options to perform certain tasks.
 **** Input: The user gets to pick his options.
 **** Output: Taks are accomplished based on the options chosen, and that
 *is what the program outputs.
 ***********************************************************************/



#ifndef BoringRoom_hpp
#define BoringRoom_hpp

#include <stdio.h>
#include "Room.hpp"

class BoringRoom : public Room
{

    
public:
    BoringRoom();   // consctructor
    Room* getToEast();  // function to head east, returns the room.
    Room* getToWest();  // function to head west, returns the room.
    Room* getToNorth();  // function to head north, returns the room.
    Room* getToSouth();  // function to head south, returns the room.
    std::string getDesc();  // function that gives a description of a room or an item
    std::string getExtendedDesc();  // gives an extended description of a romm or an item
    void showMoreOptions();  // show more options on what is needed to be done
    std::string makeItSo(int);  // make things happen
    std::string itemThatLetsMeDo(int);  // allow the user perform a task
    std::string itemThatPreventsMeDo(int);  // prevents the user to perform a task.

};



#endif /* BoringRoom_hpp */

























