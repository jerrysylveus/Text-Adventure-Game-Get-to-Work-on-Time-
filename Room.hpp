






/*********************************************************************
 **** Program Filename: Room.hpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:  This a program a menu driven game in which the user gets 
 *to choose his options to perform certain tasks.
 * *** Input: The user gets to pick his options.
 **** Output: Taks are accomplished based on the options chosen, and that 
 *is what the program outputs.
 ***********************************************************************/

#ifndef Room_hpp
#define Room_hpp

#include <stdio.h>
#include <string>

class Room
{
protected:
    Room *toEast;  // pointer to east
    Room *toWest; // pointer to west
    Room *toNorth; // pointer to north
    Room *toSouth;  // pointer to south.
    
    std::string name;
    std::string description;
    std::string extendedDescription;
    
  // allow things to be done, and not be done depending on the situation
  //     // and if certain conditions have been met.

std::string letsMeDo5;
    std::string letsMeDo6;
    std::string letsMeDo7;
    std::string letsMeDo8;
    std::string preventsMeDo5;
    std::string preventsMeDo6;
    std::string preventsMeDo7;
    std::string preventsMeDo8;
    
    
public:
    
    void setName(std::string);  // setter for the Name of the rooms.
    std::string getName();  // return the name
    
    void setDesc(std::string);   // gives a description of the room.
    void setExtendedDesc(std::string);   // gives extended description of the room.
    virtual std::string getDesc() = 0;    // virtual function.
    virtual std::string getExtendedDesc() = 0;  // virtual function.
    
    
    void setLetsMeDo(int, std::string);   // function to let the user perform an action
    void setPreventsMeDo(int, std::string); // prevents certain actions from happening if

    void setToEast(Room *next);   // setter to head east.
    virtual Room* getToEast() = 0;  // virtual function for East
    
    void setToWest(Room *next);   // setter to head west
    virtual Room*getToWest() = 0; // virtual function for West
    
    void setToNorth(Room *next);   // setter to head North
    virtual Room *getToNorth() = 0;  // virtual functionfor north
    
    void setToSouth(Room *next);  // setter to head East
    virtual Room *getToSouth() = 0;  // virtual function for East.

    virtual void showMoreOptions() = 0;   // function to show more options
    virtual std::string makeItSo(int) = 0;  // makes something happened
    virtual std::string itemThatPreventsMeDo(int) = 0;  // virtual to prevent something to be done.
    virtual std::string itemThatLetsMeDo(int) = 0;   // virtual for make it so.
    
    
    bool showingBasicDescription;   // bool to show a basic description.

 
    
    
};

#endif /* Room_hpp */




















