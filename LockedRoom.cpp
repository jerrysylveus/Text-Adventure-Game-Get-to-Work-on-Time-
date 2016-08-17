/*********************************************************************
 **** Program Filename: LockedRoom.cpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 *** Description:  This a program a menu driven game in which the user gets
 **** to choose his options to perform certain tasks.
 **** Input: The user gets to pick his options.
 **** Output: Taks are accomplished based on the options chosen, and that
 *is what the program outputs.
 ***********************************************************************/


#include <iostream>
#include "LockedRoom.hpp"
#include "Room.hpp"


// Constructor setting the directions to NULL
LockedRoom::LockedRoom()
{
    toEast = NULL;
    toWest = NULL;
    toNorth = NULL;
    toSouth = NULL;
    eastLocked = false;
    westLocked = false;
    northLocked = false;
    southLocked = false;
    showingBasicDescription = true;
}

/*********************************************************************
 **** Program Filename: LockedRoom.cpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:   Returns East, if the user can head East, else it returns
 *    NULL.
 **** Input: Function has no parameter.
 **** Output: Function return East if the user can go East.
 ***********************************************************************/
Room* LockedRoom::getToEast()
{
    if(eastLocked)    // if east is locked
    {
        std::cout << "1. East (It's locked!)" << std::endl;
        return NULL;   // not able to go
    }
    
    if(toEast != NULL)   // if east is not locked
        return toEast;   // return east
    
    return NULL;   // elser it is locked.
}


/*********************************************************************
 **** Program Filename: BoringRoom.cpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:   Returns West, if the user can head West, else it returns
 *    NULL.
 **** Input: Function has no parameter.
 **** Output: Function return West is the user can go West.
 **********************************************************************/
Room* LockedRoom::getToWest()
{
    if(westLocked)
    {
        std::cout << "2. West (It's locked!)" << std::endl;
        return NULL;
    }

    if(toWest != NULL)
        return toWest;
    return NULL;
}

/*********************************************************************
 **** Program Filename: BoringRoom.cpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:   Returns South if the user can head South, else it returns
 *    NULL.
 **** Input: Function has no parameter.
 **** Output: Function returns South is the user can go South.
 ***********************************************************************/

Room* LockedRoom::getToSouth()
{
    if(southLocked)
    {
        std::cout << "3. South (It's locked!)" << std::endl;
        return NULL;
    }
    
    if(toSouth!= NULL)
        return toSouth;
    return NULL;
}

/*********************************************************************
 **** Program Filename: BoringRoom.cpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:   Returns North, if the user can head North, else it returns
 *   NULL.
 **** Input: Function has no parameter.
 **** Output: Function return North is the user can go North.
 ***********************************************************************/
Room* LockedRoom::getToNorth()
{
    if(northLocked)
    {
        std::cout << "4. North (It's locked!)" << std::endl;
        return NULL;
    }
    
    
    if(toNorth!= NULL)
        return toNorth;
    return NULL;
}


/*********************************************************************
 *** Program Filename: BoringRoom.cpp
 **** Author: Jerry Sylveus
 *** Date:  3/10/16
 **** Description:   Returns both the descrption of a room or item and 
 *   extended description
 **** Input: Function has no parameter.
 **** Output: Function returns both the description and extended description.
 ***********************************************************************/

std::string LockedRoom::getDesc()
{
   
    if(showingBasicDescription)
        return description;
    
    return extendedDescription;
}

/*********************************************************************
 **** Program Filename: BoringRoom.cpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:   Returns the extended descrption of a room or item
 *** Input: Function has no parameter.
 **** Output: Function returns the extended description.
 ***********************************************************************/
std::string LockedRoom::getExtendedDesc()
{
  
    return extendedDescription;
}


/*********************************************************************
 **** Program Filename: BoringRoom.cpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:   Shows more options for the locked rooms.  If the r
 rooms are locked it cout that the rooms are locked.
 *** Input: Function has no parameter.
 **** Output: Function is void has no return type.
 ***********************************************************************/
void LockedRoom::showMoreOptions()
{
    if(eastLocked)
    {
        std::cout << "5. Unlock East" << std::endl;
    }
    if(westLocked)
    {
        std::cout << "6. Unlock West" << std::endl;
    }
    if(southLocked)
    {
        std::cout << "7. Unlock South" << std::endl;
    }
    if(northLocked)
    {
        std::cout << "8. Unlock North" << std::endl;
    }
}


/*********************************************************************
 **** Program Filename: BoringRoom.cpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:   Use a parameter to set the option that can be done,
 *    and returns what is being done.
 *** Input: Takes an int as parameter.
 **** Output: Function returns what the user can do based on the situation.
 ***********************************************************************/

std::string LockedRoom::itemThatLetsMeDo(int option)
{
    if(option == 5)
        return letsMeDo5;
    else if(option == 6)
        return letsMeDo6;
    else if(option == 7)
        return letsMeDo7;
    else if(option == 8)
        return letsMeDo8;
    return "";
}


/*********************************************************************
 **** Program Filename: BoringRoom.cpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:  Use a parameter to set the option that cannot be done,
 *     and returns what is being done.
 **** Input: Function takes an int as a parameter.
 **** Output: Function returns what cannot be done based on the situation
 *   that is present.
 ***********************************************************************/
std::string LockedRoom::itemThatPreventsMeDo(int option)
{
    if(option == 5)
        return preventsMeDo5;
    else if(option == 6)
        return preventsMeDo6;
    else if(option == 7)
        return preventsMeDo7;
    else if(option == 8)
        return preventsMeDo8;
    return "";
}


/*********************************************************************
 *** Program Filename: BoringRoom.cpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:  setting the options assuming the user may or may not
 *     lock a room.
 * *** Input: Function takes an int as a parameter.
 **** Output: Function returns an empty string, or the string that was parsed. **********************************************************************/
std::string LockedRoom::makeItSo(int option)
{
    bool userFailed = false; //assume user will unlock something
    std::string usedItem = "";
    if((option == 5) && eastLocked)
    {
        usedItem = letsMeDo5;    // east is being unlocked
        unlockEast();
    }
    else if((option == 6) && westLocked)
    {
        usedItem = letsMeDo6;   // west is being unlocked
        unlockWest();
    }
    else if((option == 7) && southLocked)
    {
        usedItem = letsMeDo7;  // south is being unlocked
        unlockSouth();
    }
    else if((option == 8) && northLocked)
    {
        usedItem = letsMeDo8;
        unlockNorth();     // unlocking north
    }
    else
        userFailed = true; //user fails!  we unlocked NOTHING
    
    if(!userFailed) //if we succeeded, we switch descrition of this room
    {
        showingBasicDescription = false;
        if(usedItem != "")
            return "lose:" + usedItem + "|";
    }
    
    return "";
}

/*********************************************************************
 **** Program Filename: BoringRoom.cpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:  Functions that return true or false based on if East,
 *    West, North, South is either locked or unlocked.
 **** Input: Function takes no parameter.
 **** Output: These functions are void and have no return type.
 ***********************************************************************/

void LockedRoom::lockEast() { eastLocked = true; }
void LockedRoom::lockWest() { westLocked = true; }
void LockedRoom::lockSouth() { southLocked = true; }
void LockedRoom::lockNorth() { northLocked = true; }
void LockedRoom::unlockEast() { eastLocked = false; }
void LockedRoom::unlockWest() { westLocked = false; }
void LockedRoom::unlockSouth() { southLocked = false; }
void LockedRoom::unlockNorth() { northLocked = false; }













































