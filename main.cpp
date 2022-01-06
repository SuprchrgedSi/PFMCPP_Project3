/*
Project 3 - Part 1d / 5
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

    The goal of this step is to get you to think about breaking down an object into smaller and smaller objects, 
    until the smallest object is made of up only C++ primitives and std::string. 

    Continuing the previous example:  Cell Phone

    A Cell Phone is made up of the following 5 properties/sub-objects and 3 actions:
        Display
        Memory
        CPU
        Radio
        Applications
    3 actions:
        make a call
        send a text
        run an application.

    These 5 properties can be broken down into their own sub-objects and properties. 

    If we break down the first property 'Display' into its 5 properties we get:
        brightness
        amount of power consumed.
        pixels
        width in cm
        height in cm

    the Display's brightness can be represented with a Primitive, such as a double. 

    The amount of power consumed can also be represented with a Primitive, such as a float or integer (i.e. 250mWa)
    
    The 'pixels' property must be represented with an array of Pixel instances, as the screen has more than 1 row of pixels.
        Arrays have not been discussed and can't be used in this project.
        Instead, we can use an Integer primitive to store the Number of Pixels:

    Display:
        Number of Pixels
        Amount of Power consumed (milliwatt-hours)
        Brightness
        width in cm
        height in cm
************************

1) Fill in #5 - #9 with plain-english UDTs for the 5 properties you created for UDT #10
    example: 
        If #10's first property was 'Engine', then your `Thing 5)` will be `Engine`
        you will need to provide 5 properties and 3 member functions of that Engine object in plain English
        Remember to pick properties that can be represented with 'int float double bool char std::string'
2) write the name of the primitive type you'll be using after each property
    pick properties that can be represented with 'int float double bool char std::string'
    example: 
        Display:
            Number of Pixels (int)
            Amount of Power consumed (milliwatt-hours) (float)
            Brightness (double)
            width in cm (int)
            height in cm (int)

3) move Thing 5-9 to between your Thing 4 and Thing 10.
*/

/*
Thing 1) Computer Monitor
5 properties:
    1) screen brightness (int)
    2) diplay pixel width (int)
    3) number of inputs (int)
    4) brand (std:: string)
    5) screen red color gain (float)
3 things it can do:
    1) display input video
    2) adjust video brightness
    3) change aspect ratio
 */

/*
Thing 2) Standing Desk
5 properties:
    1) unladen weight in pounds (float)
    2) current surface height in inches (float)
    3) max supported weight in pounds (double)
    4) width in inches (float)
    5) composition material (std::string)
3 things it can do:
    1) support object
    2) adjust height
    3) roll to new location
 */

/*
Thing 3) Guitar amplifier
5 properties:
    1) Preamplifier gain (double)
    2) number of channels (int)
    3) max output power in watts (float)
    4) treble gain (double)
    5) reverb amount (double)
3 things it can do:
    1) amplify guitar input
    2) adjust reverb amount
    3) switch channel
 */

/*
Thing 4) Power strip
5 properties:
    1) Number of power outlets (int)
    2) max surge  protection rating in watts (float)
    3) connector format (std::string) 
    4) wire gauge (int)
    5) number of populated outlets (int)
3 things it can do:
    1) supply power
    2) throw protection fuse
    3) disable power
 */

/*
Thing 5) Pickups
5 properties:
    1) Magnet Material (std::string)
    2) Number of Coils (int)
    3) Number of Pickups (int)
    4) distance from strings in cm (float)
    5) brand (std::string)
3 things it can do:
    1) adjust height
    2) adjust pole pieces
    3) convert vibration to voltage
 */

/*
Thing 6) Neck
5 properties:
    1) Fretboard Material (std::string)
    2) scale length in cm (double)
    3) number of frets(int)
    4) fret width in mm (float)
    5) number of fretboard inlays (int)
3 things it can do:
    1) adjust truss rod
    2) fret note
    3) clean fretboard
 */

/*
Thing 7)  Body
5 properties:
    1) wood type(std::string)
    2) color (std::string)
    3) cutout radius in cm (float)
    4) number of cutouts (int)
    5) thickness in cm (float)
3 things it can do:
    1) select pickup output
    2) adjust pickup volume
    3) adjust pickup tone
 */

/*
Thing 8) Tuners
5 properties:
    1) tuner metal (std::string)
    2) adjustment key orientation (std::string)
    3) number of tuners(int)
    4) tuner height in mm (double)
    5) tuner gear ratio (float)
3 things it can do:
    1) rotate tuner key
    2) adjust string tension
    3) tighten set nut
 */ 

/*
Thing 9) Bridge
5 properties:
    1) type of bridge(std::string)
    2) number of string poles (int)
    3) length adjustment screw setting in mm (double)
    4) type of tremolo (std::string)
    5) floating bridge tightness setting (std::string)
3 things it can do:
    1) adjust string length
    2) move whammy bar
    3) adjust bridge height
 */

/*
Thing 10) Electric Guitar
5 properties:
    1) Pickups
    2) Neck
    3) Body
    4) Tuners
    5) Bridge
3 things it can do:
    1) play a chord
    2) generate electrical output
    3) receive new strings
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
