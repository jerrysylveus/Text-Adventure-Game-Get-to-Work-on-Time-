/*********************************************************************
 **** Program Filename: Room.hpp
 **** Author: Jerry Sylveus
 *** Date:  3/10/16
 **** Description:  This a program a menu driven game in which the user gets 
 **** to choose his options to perform certain tasks.
 **** Input: The user gets to pick his options.
 **** Output: Taks are accomplished based on the options chosen, and that 
 **** is what the program outputs.
 **********************************************************************/



#include <iostream>
#include "BoringRoom.hpp"
#include "LockedRoom.hpp"
#include "ItemRoom.hpp"
#include <limits>

using std::cout;
using std::cin;
using std::endl;

void tallyScore(int minutes, std::string body[10]);
void lookAtSelf(std::string body[10]);


int main(int argc, const char * argv[]) {

    cout<<"                                                                               "<<endl;
    cout<<" ##############################################################################"<<endl;
    cout<<" #                                                                            #"<<endl;
    cout<<" #                         Welcome To Get To Work on Time                     #"<<endl;
    cout<<" #                                                                            #"<<endl;
    cout<<" #  Coding By: Jerry Sylveus.                                                 #"<<endl;
    cout<<" #  CS 162 Final Project                                                      #"<<endl;
    cout<<" #                                                                            #"<<endl;
    cout<<" #                                                                            #"<<endl;
    cout<<" #                         Press Enter To Start Game.                         #"<<endl;
    cout<<" #                                                                            #"<<endl;
    cout<<" # You were out partying all last night.  You came home, you set up your      #"<<endl;
    cout<<" # alarm for the wrong time.  You woke up late this morning, and you are      #"<<endl;
    cout<<" # trying to make it to work on time because today is the big presentation    #"<<endl;
    cout<<" # that can either make or break your career.  Unfortunately things are not   #"<<endl;
    cout<<" # going according to plan, but you still have a chance to make it on         #"<<endl;
    cout<<" # time.  You probably don't remember, when you came home last night, you     #"<<endl;
    cout<<" # trashed the house, and now you don't remember where your things are.  If   #"<<endl;
    cout<<" # you can find your things quickly you will have a chance to make it to      #"<<endl;
    cout<<" # work on time.  In order for you to have a good day at work, you need to    #"<<endl;
    cout<<" # shave, shower, get dress properly, find your keys and drive to work and    #"<<endl;
    cout<<" # make sure you get there by 9:00 am. Strange though, you woke up holding    #"<<endl;
    cout<<" # a nail in your hand.  GOOD LUCK!!!!                                        #"<<endl;
    cout<<" #                                                                            #"<<endl;
    cout<<" ##############################################################################"<<endl;
    cout << " " << endl;
    cout << " " << endl;
    
   
    cout << "PRESS ENTER TO START THE GAME:"<< endl;
    //system("read");
    //cin.ignore(); //Pause Command for Linux Terminal
    std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );

    cout << " " << endl;


//drive to work takes 13 minutes
//leave at 8:47 to win
// game ends at 9:00
//game ending situations:
// clock hits 9:00 while you are in your house: game ends immediatley arrive as-is 30 minutes late
// leave house 8:48-9:00: arrive as-is 1 to 13 minutes late
// leave house before 8:47: arrive as-is early or on time

    int minutes = 11; //36 minutes most efficient route

// setting up the bed. Game start with user waking up in bed.
    BoringRoom *bed = new BoringRoom();
    bed->setName("Your Bed");
    bed->setDesc("What a crazy night! You wake up, slightly hung over. The sun is shining, the birds are singing.  Wait... WHAT?  Oh no, you slept through your alarm! You're going to be late for work!                                                                                     Head North to get out of BED...");
    bed->setExtendedDesc("There's no time to lay around in bed!");
    
    
    BoringRoom *bedroom = new BoringRoom();
    bedroom->setName("The Bedroom");
    bedroom->setDesc("You are in your bedroom.  East is the closet.  South is back in bed. North is hallway 1.");


//Setting up all the rooms and their description
//changes to extended description when item is gotten
    
    ItemRoom *closet = new ItemRoom();  // setting up the closet
    closet->setName("Your closet");
    closet->setDesc("Your suit should be in here, it is not.  You need to find it.  OOPS!!! You just realized, your car keys are on the floor. Head West to go back to the bedroom.");
    closet->setExtendedDesc("There's nothing important in your closet");
    closet->setParsableCommand("get:Holding Car Keys|lose:Missing your Car Keys|");
    closet->setActionDisplay("Pick up Car Keys");
    
    BoringRoom *hallway1 = new BoringRoom();   // setting hallway 1
    hallway1->setName("Hall 1");
    hallway1->setDesc("You are at the beginning of hallway 1.  Your exercise bike is to the East, but this probably isn't the best time to be getting exercise.  Your bedroom is South.  Hallway 2 is West. " );
    
    ItemRoom *exerciseBike = new ItemRoom();  // Exercise bike room in hallway 1
    exerciseBike->setName("Exercise bike");
    exerciseBike->setDesc("It looks like you may have tried to ride this home from the bar last night. At least you didn't drive. A pair of handcuff keys are sitting in the cup holder.  West is back to hallway 1.");
    exerciseBike->setExtendedDesc("You have a vague memory of getting pulled over while riding this thing last night. The cup holder is empty.");
    exerciseBike->setParsableCommand("get:Handcuff Keys|");
    exerciseBike->setActionDisplay("Take Handcuff Keys from Cup Holder");
    
    LockedRoom *hallway2 = new LockedRoom();   // hallway 2 has a locked room which is the bathroom
    hallway2->setName("Hall 2");
    hallway2->setDesc("You are now in Hallway 2.  To your South is the bathroom.  Oh no, you accidentally locked it from the inside!  The door handle has one of those little hole thingies that lets you unlock it, if only you had some sort of nail-like cylinder.           To your west is Hallway 3.  To your East is hallway 1.");
    hallway2->setExtendedDesc("The bathroom door is open!  Your bedroom is to the East, the Kitchen is West, your bathroom is South.");
    hallway2->setLetsMeDo(7, "Holding a Nail");
    hallway2->lockSouth();    // the bathroom door to the south is locked
    
    BoringRoom *bathroom = new BoringRoom();  // setting up the bathroom
    bathroom->setName("It's the bathroom");
    bathroom->setDesc(" You are now in the bathroom.  Your sink is to the West, your shower is to the south, and hallway 2 is North. ");
    
    ItemRoom *shower = new ItemRoom();    // the shower in the bathroom
    shower->setName("Shower");
    shower->setDesc("The water is off.  Also, the shower head is missing.  ");
    shower->setExtendedDesc("This would be a good place to take a shower.  The bathroom is to the North");
    shower->setParsableCommand("lose:Unshowered|lose:Holding an Adjustable Shower Head Nozzle|trade:Wearing Loafers:Wearing Wet Loafers|say:You quickly take off your pajamas, reattach the shower head nozzle and take a quick shower, then get dressed back in your pajamas, all in 1 minute!|");
    shower->setActionDisplay("Take a Quick Shower");
    shower->setPreventsMeDo(5, "Wearing a Suit");
    
    ItemRoom *sink = new ItemRoom();   //the sink in the bathroom
    sink->setName("It's the bathroom sink");
    sink->setDesc("You are unshaven and look hung over.  The bathroom is to the East.");
    sink->setExtendedDesc("Your razor is laying in the sink. You are clean shaven.");
    sink->setParsableCommand("lose:Holding a Chilly Razor|lose:Unshaven|get:Clean Shaven|");
    sink->setActionDisplay("Shave!");

    
    ItemRoom *hallway3 = new ItemRoom();
    hallway3->setName("Hall 3");    // hallway 3
    hallway3->setDesc("You are at the end of hallway 3, you are smelling something. The adjustable shower head nozzle is sitting in a boquet of fake flowers. An odd arrangement.");
    hallway3->setExtendedDesc("You are at the end of a long hallway. You have a vague memory of attempting to fry the TV remote, but you can worry about that later. Your kitchen is to the north.  Hallway 2 is to the East.");
    hallway3->setParsableCommand("get:Holding an Adjustable Shower Head Nozzle|");
    hallway3->setActionDisplay("Take the Adjustable Shower Head Nozzle out of the Vase");
    
    LockedRoom *kitchen = new LockedRoom();  // the kitchen has a fridge that is locked
    kitchen->setName("Kitchen");
    kitchen->setDesc("To your South is the hallway 3.  North is the oven. East is the garage.  Refridgerator to the West. You smell burning TV remote. Somehow the refridgerator has been handcuffed shut. It must have been being naughty...");
    kitchen->setExtendedDesc("The door to the refridgerator hangs open. It won't stay shut for some reason. That explains the handcuffs...");
    kitchen->setLetsMeDo(6, "Handcuff Keys");
    kitchen->lockWest();

    ItemRoom *refridgerator = new ItemRoom();   // the fridge is locked in the kitchen
    refridgerator->setName("Refridgerator");
    refridgerator->setDesc("Your shaving kit is in the refridgerator. You recall thinking this might help with razor burn. You go ahead and lather up with whipped cream.  East is the Kitchen.");
    refridgerator->setExtendedDesc("Razor burn is not a temperature based phenomenon.");
    refridgerator->setParsableCommand("get:Holding a Chilly Razor|");
    refridgerator->setActionDisplay("Take the Chilly Razor");

    ItemRoom *oven = new ItemRoom();
    oven->setName("Oven");
    oven->setDesc("Your shoes are in the oven. They must have gotten wet when you tried drinking champagn out of them. Loafers are probably not the ideal shoe for such an activity.  South is the kitchen.");
    oven->setExtendedDesc("At least the modly smell is gone.");
    oven->setParsableCommand("get:Wearing Loafers|lose:Barefoot|");
    oven->setActionDisplay("Get your Loafers");
    
    BoringRoom *garage = new BoringRoom();   // bathroom leads to the garage
    garage->setName("Garage");
    garage->setDesc("There are about 200 helium balloons floating in your garage. Your car is to the East.  Kitchen is to the West. Your workbench and a handful of tools and half-finished broken projects are to the north.");
    
    ItemRoom *workbench = new ItemRoom();   // the workbench in the garage where the suit is
    workbench->setName("Workbench");
    workbench->setDesc("Your workbench is where you attempt to fix things but usually break them worse. Your suit is here. You vaguely remember attempting to repair a rip in the suit with a soldering iron.  South is the garage.");
    workbench->setExtendedDesc("You should really finish building that drone sometime.");
    workbench->setParsableCommand("lose:Wearing Pajamas|get:Wearing a Suit|say:You quickly change into your suit and toss your pajamas on the floor of the garage.|");
    workbench->setActionDisplay("Get Dressed.");
    
    ItemRoom *car = new ItemRoom();  // car in the garage.
    car->setName("'06 Honda Accord");
    car->setDesc("Your car. Maybe if you get a promotion you can update to the '16 Honda Accord.  West is the garage.");
    car->setLetsMeDo(5, "Holding Car Keys");
    car->setParsableCommand("lose:Holding Car Keys|say:You back out of the garage, running over a basketball, and speed off to work leaving the garage door open!|end:game|");
    car->setActionDisplay("Speed to Work!");



//ROOM CONNECTIONS INDICATING THE DIRECTIONS
//WHERE EACH ROOM LEADS

    bed->setToNorth(bedroom);
    bedroom->setToSouth(bed);
    
    bedroom->setToEast(closet);
    closet->setToWest(bedroom);
    
    bedroom->setToNorth(hallway1);
    hallway1->setToSouth(bedroom);
    
    hallway1->setToEast(exerciseBike);
    exerciseBike->setToWest(hallway1);
    
    hallway1->setToWest(hallway2);
    hallway2->setToEast(hallway1);
    
    hallway2->setToSouth(bathroom);
    bathroom->setToNorth(hallway2);
    
    bathroom->setToWest(sink);
    sink->setToEast(bathroom);
    
    bathroom->setToSouth(shower);
    shower->setToNorth(bathroom);
    
    hallway2->setToWest(hallway3);
    hallway3->setToEast(hallway2);
    
    hallway3->setToNorth(kitchen);
    kitchen->setToSouth(hallway3);
    
    kitchen->setToWest(refridgerator);
    refridgerator->setToEast(kitchen);
    
    kitchen->setToNorth(oven);
    oven->setToSouth(kitchen);
    
    kitchen->setToEast(garage);
    garage->setToWest(kitchen);
    
    garage->setToNorth(workbench);
    workbench->setToSouth(garage);
    
    garage->setToEast(car);
    car->setToWest(garage);
    
    
    Room *playersLocation = bed;



// array that describes the item that the user is carrying and also
// displaying what the user looks like, like a mirror.  User has the option
// of looking at self.  The array is also use as a backpack to allow the user to carry items and get rid of items.

   std::string body[10];
    for(int i=0;i<10;i++)
    {
        body[i] = "";
    }
    body[0] = "Unshaven"; //doing shave removes item
    body[1] = "Unshowered"; //doing shower removes item
    body[2] = "Wearing Pajamas"; //acquiring suit removes item
    body[3] = "Barefoot"; //acquiring shoes removes item
    body[4] = "Holding a Nail"; //hall2 removes item on unlock
    body[6] = "Missing your Car Keys"; //closet get keys removes
    //need: suit
    //need: shoes
    //need: handcuff key
    //need: razor
    //need: carkeys

 
// for every action or every step by the player, one minute in the clock is used
// if the user spends more than one hour going around, he will be late.
//clock hits 9:00 while you are in your house: game ends immediatley arrive as-is 30 minutes late 
     bool quit = false;
     while(!quit)
    {
        cout << "-------- " << playersLocation->getName() << ". 8:" << minutes << "am --------" << endl;
        cout << playersLocation->getDesc() << endl;
        minutes++;
        if(minutes == 61)  // if user spend more than an hour at home, games end automatically.
        {
            minutes += 29;
            cout << "There's no more time! You panick and run out the front door to the bus stop to take the bus to work as-is." << endl;
            tallyScore(minutes, body);
            return 0;
        }
        
        cout << " " << endl;
        cout << "0. Look at Self" << endl;
        
        if(playersLocation->getToEast() != NULL)
        {
            cout << "1. East" << endl;
        }
        if(playersLocation->getToWest() != NULL)
        {
            cout << "2. West" << endl;
        }
        if(playersLocation->getToSouth() != NULL)
        {
            cout << "3. South" << endl;
        }
        if(playersLocation->getToNorth() != NULL)
        {
            cout << "4. North" << endl;
        }
        
        playersLocation->showMoreOptions();
        cout << "9. Quit" << endl;   
        cout << "Where do you want to go? ";
        
        int direction;
        char getch;
        cin >> getch;
        direction = getch - '0';
        cout << endl << endl;

// User is able to look at self with option zero.  If there is no opening in a room meaning that part of the room is not connected to another room, the user cannot go that way.

       if(direction == 0)
        {
            lookAtSelf(body);
        }
        else if(direction == 1)
        {
            if(playersLocation->getToEast() == NULL) cout << "You can't go that way!" << endl;
            else playersLocation = playersLocation->getToEast();
        }
        else if(direction == 2)
        {
            if(playersLocation->getToWest() == NULL) cout << "You can't go that way!" << endl;
            else playersLocation = playersLocation->getToWest();
        }
        else if(direction == 3)
        {
            if(playersLocation->getToSouth() == NULL) cout << "You can't go that way!" << endl;
            else playersLocation = playersLocation->getToSouth();
        }
        else if(direction == 4)
        {
            if(playersLocation->getToNorth() == NULL) cout << "You can't go that way!" << endl;
            else playersLocation = playersLocation->getToNorth();
        }
    
        else if (direction == 9)
        {
       		quit = true;
        }
        else
        {
            bool userFailed = false;


//are there any items that prevent the task, eg: 100 ballons & getting on a train
//If the user dont meet the requirement for a task, that task cannot be performed.
// Example the user cannot shower, if he is dress in his suit.  Needs to shower first before getting dressed
            std::string stoppingItem = playersLocation->itemThatPreventsMeDo(direction);
            if(stoppingItem != "") //there could be something stopping me, do I have it?
            {
                for(int i=0;i<10;i++)
                {
                    if(body[i] == stoppingItem)
                    {
                        cout << "Oops, you can't do that... You are " << body[i] << endl;
                        userFailed = true;
                    }
                }
            }
            
            bool userIsMissingRequiredItem = false;
            //are there any items required to do the task, eg: a ticket to get on a train
            std::string requiredItem = playersLocation->itemThatLetsMeDo(direction);
            if((!userFailed) && (requiredItem != "")) //nothing stopped me, but I need something...
            {
                userIsMissingRequiredItem = true; //assume they don't have it, then search
                for(int i=0;i<10;i++)
                {
                    if(body[i] == requiredItem) //found it!
                    {
                        userIsMissingRequiredItem = false;
                        cout << "You are able to do that because you are " << body[i] << endl << endl;
                    }
                }
            }
            if(userIsMissingRequiredItem)
                userFailed = true;

            if(!userFailed) //user succeeded
            {
           
           //make it so, which gives a potential new location
           //if making it so returns a location, move to it
           //Room *newLocation = playersLocation->makeItSo(direction);
                    
                 std::string result = playersLocation->makeItSo(direction);
            //get:razor|
            //lose:unshaven|lose:razor|get:clean shaven|go:hallway1|
            //If a user performs an action this piece of code allow the user to update self
            // after the action is performed.  For example if the user doens't have car keys
            //when looking at self, when the user picks up the car keys, it will be updated 
            //and if the user looks at self, again, it will say that the user has the car keys.
      
                while(result.length() > 0)
                {
                    int pipeindex = (int)result.find("|");
                    std::string nextCommand = result.substr(0, pipeindex);
                    
                    int colonIndex = (int)nextCommand.find(":");
                    std::string commandType = nextCommand.substr(0, colonIndex);
                    std::string commandMcguffin = nextCommand.substr(colonIndex+1);
                    
                    if(commandType == "get")
                    {
                        for(int i=0;i<10;i++)
                        {
                            if(body[i] == "")
                            {
                                body[i] = commandMcguffin;
                                cout << "Hello, " << commandMcguffin << endl << endl;
                                break;
                            }
                        }
                    }
                    else if(commandType == "lose")
                    {
                        for(int i=0;i<10;i++)
                        {
                            if(body[i] == commandMcguffin)
                            {
                                body[i] = "";
                                cout << "Goodbye, " << commandMcguffin << endl << endl;
                                break;
                            }
                        }
                    }
                    else if(commandType == "say")
                    {
                        cout << commandMcguffin << endl << endl;
                    }
                    else if(commandType == "trade")
                    {

                        
                        int colon2Index = (int)commandMcguffin.find(":");
                        std::string mcguffin1 = commandMcguffin.substr(0, colon2Index);
                        std::string mcguffin2 = commandMcguffin.substr(colon2Index+1);
  
                        for(int i=0;i<10;i++)
                        {
                            if(body[i] == mcguffin1)
                            {
                                body[i] = mcguffin2;
                                break;
                            }
                        }
                    }
                    else if(commandType == "end")
                    {
                        minutes += 9;
                        tallyScore(minutes, body);
                        return 0;
                    }
                    
                    
                    result = result.substr(pipeindex+1);
                    
                }
            }
        }
        
    }
    
    
    return 0;


}



// function to tally the scores for the game
void tallyScore(int minutes, std::string body[10])
{
    int lateOrEarly = minutes - 60;
    if(lateOrEarly < 0)
        cout << "You arrive at work " << (-lateOrEarly) << " minutes early. ";
    else if(lateOrEarly == 0)
        cout << "You arrive at work right on time. ";
    else
        cout << "You arrive at work " << lateOrEarly << " minutes late. ";

    lookAtSelf(body);

    
    int clothingPoints = 4;
    int hygeinePoints = 9;
    for(int i=0;i<10;i++)
    {
        std::string next = body[i];
        if(next == "Barefoot")
            clothingPoints -= 2;
        else if(next == "Wearing Wet Loafers")
            clothingPoints -= 1;
        else if(next == "Wearing Pajamas")
            clothingPoints -= 2;
        else if(next == "Wearing a Suit")
            clothingPoints += 2;
        else if(next == "Wearing Loafers")
            clothingPoints += 4;
        else if(next == "Unshaven")
            hygeinePoints -= 3;
        else if(next == "Unshowered")
            hygeinePoints -= 6;
        else if(next == "Clean Shaven")
            hygeinePoints += 1;
    }
    
    if(clothingPoints < 5)
        cout << "You are poorly dressed, Cheryl from Accounting keeps staring at your feet through the presentation. " << endl;
    else if(clothingPoints < 8)
        cout << "You are partially dressed. Hopefully if you sit through the presentation nobody will notice. ";
    else
        cout << "You look sharp. Your shoes are shiny and smell good from having been steralized in the oven, and the hole in your suit has finally been patched. ";
    
    if(hygeinePoints < 5)
        cout << "You smell pretty bad and look generally messy. ";
    else if(hygeinePoints < 9)
        cout << "A little more time in the bathroom wouldn't have hurt. ";
    else
        cout << "Your hair is perfect and you smell like a boss. ";

     
    int overallScore = hygeinePoints + clothingPoints - minutes/10+9;
    cout << "Your score: " << overallScore << endl;
    if(overallScore == 24)
        cout << "Perfect! Your boss gives you a huge raise and the rest of the week off! Time to party!" << endl;
    else if(overallScore >= 18)
        cout << "Not bad! You get a small raise & the rest of the day off. Time to go home and get some more sleep" << endl;
    else if(overallScore >= 14)
        cout << "At least you didn't get fired. " << endl;
    else if(overallScore > 9)
        cout << "Your boss asks you to clear out your desk and has security escort you from the premises" << endl;
    else if(overallScore > 0)
        cout << "Your bosses face turns red as he spends the next 11 minutes firing you and talking about what a horrible person you are. Cheryl from accounting throws a crumpled up piece of paper at you on the way out and Todd from HR trips you right as you turn around.";
    else if(overallScore == 0)
        cout << "Your boss admires your brazen attitude, showing up looking and smelling like you've spent the last 5 days living in a brothel. Your boss promoted you to the Executive's Board out of fear. You end up fitting right in. Psych!!!!" << endl;
}



// Allowing the user to look at self.
void lookAtSelf(std::string body[10])
{
    cout << "You look at yourself...  You are:" << endl;
    for(int i=0;i<10;i++)
    {
        if(body[i] != "")
            cout << body[i] << endl;
    }
    cout << endl;
}















































