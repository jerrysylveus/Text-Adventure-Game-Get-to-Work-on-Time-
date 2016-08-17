/*********************************************************************
 **** Program Filename: Room.cpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:  This a program a menu driven game in which the user gets
 **** to choose his options to perform certain tasks.
 **** Input: The user gets to pick his options.
 **** Output: Taks are accomplished based on the options chosen, and that
 *is what the program outputs.
 ***********************************************************************/

#include <string>
#include "Room.hpp"

/*********************************************************************
 *  *** Program Filename: Room.hpp
 *   *** Author: Jerry Sylveus
 *    *** Date:  3/10/16
 *     *** Description:  This a program a menu driven game in which the user gets
 *      *** to choose his options to perform certain tasks.
 *       *** Input: Setting the name
 *        *** Output: Function is void, no return type
 ***********************************************************************/

void Room::setName(std::string n)
{
    name = n;
}

/*********************************************************************
 *  *** Program Filename: Room.hpp
 *   *** Author: Jerry Sylveus
 *    *** Date:  3/10/16
 *     *** Description:  This a program a menu driven game in which the user gets
 *      *** to choose his options to perform certain tasks.
 *       *** Input: Setting the description of the rooms and items
 *        *** Output: Function is void, no return type
 ***********************************************************************/
void Room::setDesc(std::string d)
{
    description = d;
}

/*********************************************************************
 *  *** Program Filename: Room.hpp
 *   *** Author: Jerry Sylveus
 *    *** Date:  3/10/16
 *     *** Description:  This a program a menu driven game in which the user gets
 *      *** to choose his options to perform certain tasks.
 *       *** Input: Setting the extended descripton of the room and items
 *        *** Output: Function is void, no return type
 ***********************************************************************/
void Room::setExtendedDesc(std::string d)
{
    extendedDescription = d;
}


/*********************************************************************
 **** Program Filename: Room.hpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:  This a program a menu driven game in which the user gets
 **** to choose his options to perform certain tasks.
 **** Input: Getter for the name of the room
 **** Output: Return the name the rooms
 ***********************************************************************/
std::string Room::getName()
{
    return name;
}

/*********************************************************************
 **** Program Filename: Room.hpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:  This function allows the user to do certain tasks if 
 *    certain conditions are met
 **** Input: Takes item and num as a parameter, and setting the options
 * for let me do.
 **** Output: Function is void, has no return type
 ***********************************************************************/

void Room::setLetsMeDo(int num, std::string item)
{
    if(num == 5)
        letsMeDo5 = item;
    else if(num == 6)
        letsMeDo6 = item;
    else if(num == 7)
        letsMeDo7 = item;
    else if(num == 8)
        letsMeDo8 = item;
}

/*********************************************************************
 **** Program Filename: Room.hpp
 **** Author: Jerry Sylveus
 **** Date:  3/10/16
 **** Description:  This function prevents certain task from being done
 *    if some conditions are not met.
 **** Input: Takes a string item, and an int as parameter.  It sets the option
 *    and use prevents me Do
 **** Output: Function is void, no return type
 ***********************************************************************/

void Room::setPreventsMeDo(int num, std::string  item)
{
    if(num == 5)
        preventsMeDo5 = item;
    else if(num == 6)
        preventsMeDo6 = item;
    else if(num == 7)
        preventsMeDo7 = item;
    else if(num == 8)
        preventsMeDo8 = item;
}



/*********************************************************************
 *  *** Program Filename: Room.hpp
 *   *** Author: Jerry Sylveus
 *    *** Date:  3/10/16
 *     *** Description:  Functions that set heading East.
 *      *** Input: Setting going East.
 *       *** Output: Function is void, no return type
 ***********************************************************************/

void Room::setToEast(Room *next)
{
    toEast = next;
}

/*********************************************************************
 *  *** Program Filename: Room.hpp
 *   *** Author: Jerry Sylveus
 *    *** Date:  3/10/16
 *     *** Description:  Functions that set heading West.
 *      *** Input: Setting going West.
 *       *** Output: Function is void, no return type
 ***********************************************************************/

void Room::setToWest(Room * next)
{
    toWest = next;
}


/*********************************************************************
 *  *** Program Filename: Room.hpp
 *   *** Author: Jerry Sylveus
 *    *** Date:  3/10/16
 *     *** Description:  Functions that set heading North.
 *      *** Input: Setting going North.
 *       *** Output: Function is void, no return type
 ***********************************************************************/
void Room::setToNorth(Room *next)
{
    toNorth = next;
}


/*********************************************************************
 *  *** Program Filename: Room.hpp
 *   *** Author: Jerry Sylveus
 *    *** Date:  3/10/16
 *     *** Description:  Functions that set heading South.
 *      *** Input: Setting going South.
 *       *** Output: Function is void, no return type
 ***********************************************************************/
void Room::setToSouth(Room *next)
{
    toSouth = next;
}


































