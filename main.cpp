/*
Project 3 - Part 1c / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

1) write the 10th UDT
    come up with an object that is made of 5 smaller parts.
    These parts will not be defined using Primitives, but instead will be their own UDTs you'll define in Part 1d
    
    Here is an example:
    Cell Phone

    A Cell Phone is made up of the following 5 properties:
        Display
        Memory
        CPU
        Radio
        Applications

    A Cell Phone has 3 things it can do:
        make a call
        send a text
        run an application.

    Notice that I did not use "has a display" or "Has memory" or "has a cpu" as one of the properties of the CellPhone
    
    Writing 'has a ___" checks whether or not your object **has the ability to do something**.
    Instead, I wrote "Display" or "CPU".  These are specific objects or amounts. 
    
    In C++ terms, this means to I want you to avoid using 'bool' (has a) as a member variable type.
    Instead, prefer the other primitive types.

    When you choose your 5 smaller parts, remember that each of these 5 Sub Objects will need 
    to be defined with 5 primitive properties and 3 actions EACH.  

2) write the name of the primitive type you'll be using after each property in UDTs 1-4:
    pick properties that can be represented with 'int float double bool char std::string'
    example: 
        Display:
            Number of Pixels (int)
            Amount of Power consumed (milliwatt-hours) (float)
            Brightness (double)
            area in cm2 (int)
            brand (std::string)

3) Move the Thing 10 pseudo-code to after your Thing1-4 in the project.
*/

/*
Thing 10) Electric Guitar
5 properties:
    1) Pickups
        Magnet Material (std::string)
        Number of Coils (int)
        Number of Pickups (int)
        distance from strings in cm (float)
        brand (std::string)
    2) Neck
        Fretboard Material (std::string)
        scale length in cm (double)
        number of frets(int)
        fret width in mm (float)
        number of fretboard inlays (int)
    3) Body
        wood type(std::string)
        color (std_string)
        cutout radius in cm (float)
        number of cutouts (int)
        thickness in cm (float)
    4) Tuners
        tuner metal (std::string)
        adjustment key orientation (std::string)
        number of tuners(int)
        tuner height in mm (double)
        tuner gear ratio (float)
    5) Bridge
        type of bridge(std::string)
        number of string poles (int)
        length adjustment screw setting in mm (double)
        type of tremolo (std::string)
        floating bridge tightness setting (std::string)
3 things it can do:
    1) play a chord
    2) generate electrical output
    3) receive new strings
 */




/*
Thing 1) Computer Monitor
5 properties:
    1) screen brightness
    2) supported diplay aspect ratios
    3) number of inputs
    4) type of inputs
    5) screen color settings
3 things it can do:
    1) display input video
    2) adjust video brightness
    3) change aspect ratio
 */

/*
Thing 2) Standing Desk
5 properties:
    1) unladen weight
    2) current surface height
    3) max supported weight
    4) width
    5) composition material
3 things it can do:
    1) support object
    2) adjust height
    3) roll to new location
 */

/*
Thing 3) Guitar amplifier
5 properties:
    1) Preamplifier gain
    2) number of channels
    3) max output power
    4) treble gain
    5) reverb amount
3 things it can do:
    1) amplify guitar input
    2) adjust reverb amount
    3) switch channel
 */

/*
Thing 4) Power strip
5 properties:
    1) Number of power outlets
    2) max surge  protection rating
    3) supported connector formats
    4) wire gauge
    5) number of populated outlets
3 things it can do:
    1) supply power
    2) throw protection fuse
    3) disable power
 */



/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
