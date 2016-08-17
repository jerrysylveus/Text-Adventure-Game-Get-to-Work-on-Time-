/*********************************************************************
 *** Program Filename: ItemRoom.cpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:  This a program a menu driven game in which the user gets
 *** to choose his options to perform certain tasks.
 **** Input: The user gets to pick his options.
 **** Output: Taks are accomplished based on the options chosen, and that
 * is what the program outputs.
 ***********************************************************************/

#ifndef ItemRoom_hpp
#define ItemRoom_hpp

#include <stdio.h>
#include "Room.hpp"

class ItemRoom : public Room   // class ItemRoom inheriting from Room
{
    
    
public:
    ItemRoom();   // constructor
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
    
    
    std::string parsableCommand;  // parsing a string
    std::string actionDisplay;
    void setParsableCommand(std::string);  // parsing a string function
    void setActionDisplay(std::string);    // setting an action
    
    
    bool itemFound;   // bool to determine if an item has been found
    
    
};


#endif /* ItemRoom_hpp */








































