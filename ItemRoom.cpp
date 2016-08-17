/*********************************************************************
 *** Program Filename: ItemRoom.cpp
 **** Author: Jerry Sylveus
 *** Date:  3/10/16
 *** Description:  This a program a menu driven game in which the user gets
 *** to choose his options to perform certain tasks.
 **** Input: The user gets to pick his options.
 **** Output: Taks are accomplished based on the options chosen, and that
 *is what the program outputs.
 ***********************************************************************/


#include "ItemRoom.hpp"
#include <iostream>
#include "LockedRoom.hpp"
#include "Room.hpp"


// constructor setting the directions to NULL.
ItemRoom::ItemRoom()
{
    toEast = NULL;
    toWest = NULL;
    toNorth = NULL;
    toSouth = NULL;
    showingBasicDescription = true;
    itemFound = false;
}


/*********************************************************************
 **** Program Filename: ItemRoom.cpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:   Returns East, if the user can head East, else it returns
 *   NULL.
 **** Input: Function has no parameter.
 **** Output: Function return East if the user can go East.
 ***********************************************************************/


Room* ItemRoom::getToEast()
{
    if(toEast != NULL)
        return toEast;
    
    return NULL;
}


/*********************************************************************
 **** Program Filename: ItemRoom.cpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:   Returns West, if the user can head West, else it returns
 *    NULL.
 *** Input: Function has no parameter.
 **** Output: Function return Westif the user can go West.
 ***********************************************************************/

Room* ItemRoom::getToWest()
{
    if(toWest != NULL)
        return toWest;
    return NULL;
}


/*********************************************************************
 **** Program Filename: ItemRoom.cpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 *** Description:   Returns South if the user can head South, else it returns
 *   NULL.
 **** Input: Function has no parameter.
 **** Output: Function returns South is the user can go South.
 ***********************************************************************/
Room* ItemRoom::getToSouth()
{
    if(toSouth!= NULL)
        return toSouth;
    return NULL;
}


/*********************************************************************
 **** Program Filename: ItemRoom.cpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:   Returns North, if the user can head North, else it returns
 *    NULL.
 **** Input: Function has no parameter.
 **** Output: Function return North is the user can go North.
 ***********************************************************************/
Room* ItemRoom::getToNorth()
{
    if(toNorth!= NULL)
        return toNorth;
    return NULL;
}



/*********************************************************************
 **** Program Filename: ItemRoom.cpp
 **** Author: Jerry Sylveus
 *** Date:  3/10/16
 **** Description:   Returns both the descrption of a room or item and
 *      extended description
 **** Input: Function has no parameter.
 **** Output: Function returns both the description and extended description.
 ***********************************************************************/

std::string ItemRoom::getDesc()
{
    
    if(showingBasicDescription)
        return description;
    
    return extendedDescription;
}




/*********************************************************************
 *  *** Program Filename: ItemRoom.cpp
 *   *** Author: Jerry Sylveus
 *    *** Date:  3/10/16
 *     *** Description:   Returns the extended descrption of a room or item
 *      *** Input: Function has no parameter.
 *       *** Output: Function returns the extended description.
 ***********************************************************************/
std::string ItemRoom::getExtendedDesc()
{
    
    return extendedDescription;
}


/*********************************************************************
 *  *** Program Filename: BoringRoom.cpp
 *   *** Author: Jerry Sylveus
 *    *** Date:  3/10/16
 *     *** Description: If the item is found, it displays an action by the user.
 *      *** Input: Function has no parameter.
 *       *** Output: Function is void, has no return type
 ***********************************************************************/
void ItemRoom::showMoreOptions()
{
    if(!itemFound)
    {
        std::cout << "5. " << actionDisplay << std::endl;
    }
}


/*********************************************************************
 *** Program Filename: BoringRoom.cpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:   Allow the user to perform a specific task
 **** Input: Function takes an int as a parameter.
 **** Output: Function returns the action that can be done else returns 
 *    an empty string.
 ***********************************************************************/
std::string ItemRoom::itemThatLetsMeDo(int option)
{
    if(option == 5)
        return letsMeDo5;
    return "";
}


/*********************************************************************
 **** Program Filename: BoringRoom.cpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:   Prevents the user to perform a specific task
 *** Input: Function takes an int as a parameter.
 ** Output: Function returns the action that can't be done else returns
 * an empty string.
 ***********************************************************************/
std::string ItemRoom::itemThatPreventsMeDo(int option)
{
    if(option == 5)
        return preventsMeDo5;
    return "";
}



/*********************************************************************
 **** Program Filename: BoringRoom.cpp
 *** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description: If the user is allowd to unlock something, and finds
 *     something, then a bool indicates that to be true, else if the user
 *     fails nothin is unlocked.
 **** Input: Function takes an int as a parameter.
 **** Output: Function returns the action that can be done else returns
 *   false indicating that user has failed and return the parsable command
 *   from the string
 ***********************************************************************/
std::string ItemRoom::makeItSo(int option)
{
    bool userFailed = false; //assume user will unlock something
    
    if((option == 5) && !itemFound)
        itemFound = true;
    else
        userFailed = true; //user fails!  we unlocked NOTHING
    
    if(!userFailed) //if we succeeded, we switch descrition of this room
    {
        showingBasicDescription = false;
        return parsableCommand;
    }
    
    
    return "";
}


/*********************************************************************
 *  *** Program Filename: BoringRoom.cpp
 *   *** Author: Jerry Sylveus
 *    *** Date:  3/10/16
 *     *** Description:   Setter for the parsable command
 *      *** Input: Function takes a string as a parameter.
 *       *** Output: Function is void has no return type
 ***********************************************************************/
void ItemRoom::setParsableCommand(std::string cmd)
{
    parsableCommand = cmd;
}


/*********************************************************************
 *  *** Program Filename: BoringRoom.cpp
 *   *** Author: Jerry Sylveus
 *    *** Date:  3/10/16
 *     *** Description: Setter for the action to be displayed.
 *      *** Input: Function takes a string as a parameter.
 *       *** Output: Function is void, has no return type.
 ***********************************************************************/

void ItemRoom::setActionDisplay(std::string disp)
{
    actionDisplay = disp;
}















































