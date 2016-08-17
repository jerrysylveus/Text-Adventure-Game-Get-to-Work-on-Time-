/*********************************************************************
 **** Program Filename: BoringRoom.cpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:  This a program a menu driven game in which the user gets
 **** to choose his options to perform certain tasks.
 **** Input: The user gets to pick his options.
 **** Output: Taks are accomplished based on the options chosen, and that
 *is what the program outputs.
***********************************************************************/

#include <iostream>
#include "BoringRoom.hpp"
#include "Room.hpp"


// constructor setting East, West, North, South to NULL.
BoringRoom::BoringRoom()
{
    toEast = NULL;
    toWest = NULL;
    toNorth = NULL;
    toSouth = NULL;
    showingBasicDescription = true;
}

/*********************************************************************
 *  *** Program Filename: BoringRoom.cpp
 *   *** Author: Jerry Sylveus
 *    *** Date:  3/10/16
 *     *** Description:   Returns East, if the user can head East, else it returns
 *          NUll.
 *           *** Input: Function has no parameter.
 *            *** Output: Function return East if the user can go East.
 ***********************************************************************/

Room* BoringRoom::getToEast()
{
    if(toEast != NULL)
        return toEast;
    return NULL;
}

/*********************************************************************
 **** Program Filename: BoringRoom.cpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:   Returns West, if the user can head West, else it returns
 *     NUll.
 **** Input: Function has no parameter.
 **** Output: Function return East if the user can go West.
 ***********************************************************************/

Room* BoringRoom::getToWest()
{
    if(toWest != NULL)
        return toWest;
    return NULL;
}

/*********************************************************************
 **** Program Filename: BoringRoom.cpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:   Returns South, if the user can head South, else it returns
 *    NUll.
 **** Input: Function has no parameter.
 **** Output: Function return South if the user can go South.
 ***********************************************************************/

Room* BoringRoom::getToSouth()
{
    if(toSouth!= NULL)
        return toSouth;
    return NULL;
}

/*********************************************************************
 *  *** Program Filename: BoringRoom.cpp
 *   *** Author: Jerry Sylveus
 *    *** Date:  3/10/16
 *     *** Description:   Returns North, if the user can head North, else it returns
 *      NUll.
 *       *** Input: Function has no parameter.
 *        *** Output: Function return North if the user can go North.
 ***********************************************************************/

Room* BoringRoom::getToNorth()
{
    if(toNorth!= NULL)
        return toNorth;
    return NULL;
}

/*********************************************************************
 **** Program Filename: BoringRoom.cpp
 *** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:   Returns both the description and the extended 
 *  description.
 **** Input: Function has no parameter.
 **** Output: Function return both the description and the Extended description.
 ***********************************************************************/


std::string BoringRoom::getDesc()
{
    if(showingBasicDescription)   // if true
    {
        if(extendedDescription != "")  // if there is an extended descripton
            showingBasicDescription = false;  // No basic description to be shown.
        return description;
    }
    
    return extendedDescription;
}


/*********************************************************************
 *  *** Program Filename: BoringRoom.cpp
 *   *** Author: Jerry Sylveus
 *    *** Date:  3/10/16
 *     *** Description: Retunrs the extended description.
 *      *** Input: Function has no parameter.
 *       *** Output: returns the extended description of the room or an item.
 ***********************************************************************/

std::string BoringRoom::getExtendedDesc()
{
    return extendedDescription;
}

/*********************************************************************
 *  *** Program Filename: BoringRoom.cpp
 *   *** Author: Jerry Sylveus
 *    *** Date:  3/10/16
 *     *** Description: Displaying what kind of room the room is.
 *      *** Input: Function has no parameter.
 *       *** Output: Function is void has no return type
 ***********************************************************************/

void BoringRoom::showMoreOptions()
{
    std::cout << "Other than that, the room is pretty boring..." << std::endl;
}


/*********************************************************************
 *  *** Program Filename: BoringRoom.cpp
 *   *** Author: Jerry Sylveus
 *    *** Date:  3/10/16
 *     *** Description:  Function returns an empty string.
 *      *** Input: Function takes option as a parameter.
 *       *** Output: Function returns an empty string for the Boring room class.
 ****************************************************************************/

std::string BoringRoom::makeItSo(int option)
{
    return "";
}


/*********************************************************************
 *  *** Program Filename: BoringRoom.cpp
 *   *** Author: Jerry Sylveus
 *    *** Date:  3/10/16
 *     *** Description:   Returns an empty string.
 *      *** Input: Function takes option has a parameter..
 *       *** Output: Function returns an empty string for the BoringRoom class
 ***********************************************************************/
std::string BoringRoom::itemThatLetsMeDo(int option)
{

    return "";
}


/*********************************************************************
 *  *** Program Filename: BoringRoom.cpp
 *   *** Author: Jerry Sylveus
 *    *** Date:  3/10/16
 *     *** Description:   Returns an empty string
 *      *** Input: Function takes an int as parameter.
 *       *** Output: Function returns an empty string.
 ****************************************************************************/
std::string BoringRoom::itemThatPreventsMeDo(int option)
{
    
    return "";
}









































