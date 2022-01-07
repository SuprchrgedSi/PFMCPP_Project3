/*
Project 3 - Part 1e / 5
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

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  

    /*
    Pay attention to the member functions that take an instance of 'Car'
    Notice that there is a member variable of the same type.

    It makes sense to pass a Car to the function 'washAndWaxCar' because car washes service MANY cars
    However, they only service ONE car at a time.
    the carBeingServiced's value would change every time you wash and wax the car. 

    I see many students who write code emulating this format, but their usage does not make logical sense.  
    Consider the following snippet:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        // train their skills
        void trainPlayerSkills(Manager managerA);
    
        Manager teamManager;
    };

    It does not make sense to pass in a new Manager whenever you are going to train your team players.
    Soccer teams have ONE manager.

    a much more relevant usage would be adding a member function that hires a new manager:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        void hireNewManager(Manager newManager);
    
        Manager teamManager;
    };

    We can safely assume that the 'Manager' instance that is being passed in will be replacing the current 'teamManager' variable without looking at any other code.
    This is because the function name and function argument clearly indicate what they are/what they do.

    Your function names and parameter names should make LOGICAL SENSE.
    Readers of your code should be able to INTUITIVELY understand what your function implementations will do without actually seeing the implementations.

    Keep this in mind when you define your UDTs in this project part.
    */
};



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

struct ComputerMonitor
{
    // screen brightness
    int screenBrightness = 50;
    // diplay pixel width
    int pixelWidth = 1920;
    // number of inputs
    int numInputs = 5;
    // brand
    std::string brand = "Samsung";
    // screen red color gain
    float redGain = 0.72f;

    //  display input video
    void displayInput(int selectedInput = 1);
    // adjust video brightness
    void adjustBrightness(int brightnessAdjustment = 0);
    // change aspect ratio
    int changeAspectRatio(int xDim, int yDim);
};

/*
Thing 2) Standing Desk
5 properties:
    1) unladen weight in pounds (float)
    2) current surface height in inches (float)
    3) max supported weight in pounds (double)
    4) width in inches (float)
    5) composition material (std::string)
3 things it can do:
    1) Slide keyboard drawer
    2) adjust height
    3) roll to new location
 */

struct StandingDesk
{
    // unladen weight in pounds
    float unladenWeight = 10.f;
    // current surface height in inches
    float deskHeight = 36.f;
    // max supported weight in pounds
    double maxSupportedWeight = 276.3;
    // width in inches
    double width = 48.0;
    // composition material
    std::string compositionMaterial = "glass";

    // Slide keyboard drawer
    std::string slideDrawer();
    // Adjust height
    float changeHeight(float heightChange = 1.f);
    // roll to new location
    float rollDesk(float xDistance = 0.5f, float yDistance = 0.5f);

};
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
struct GuitarAmp
{
    //  Preamplifier gain
    double preampGain = 0.25;
    //  number of channels
    int numChannels = 2;
    // max output power in watts
    float maxOutPower = 100.f;
    // treble gain
    double trebleGain = 0.5;
    // reverb amount
    double reverbLevel = 0.25;

    struct PowerAmp
    {
        // Amp gain
        double gain = 0.0;
        // Power amp config
        std::string ampTopology = "Class AB";
        // output impedance in ohms
        int outputImpedance = 8;
        // number of outputs
        int numOutputs = 1;
        // power state
        std::string powerState = "standby";


        // Change gain
        void changeGain(double gainAdjustment = 1.0);
        // Put amp into standby
        void enableAmpStandby();
        // select new output impedance
        int selectImpedance( int impedance = 8);
    };

    // amplify guitar input
    double amplifyGuitar(double inputVoltage = 0.0, double ampGain = 0.0);
    // adjust reverb amount
    double adjustReverbAmount(double reverbLevel = 0.25, double reverbGain = 1.0);
    // switch channel
    int switchChannel(int currentChannel, int newChannel = 0);
};
/*
Thing 4) Power strip
5 properties:
    1) Number of power outlets (int)
    2) max surge  protection rating in watts (float)
    3) connector format (std::string) 
    4) wire gauge (int)
    5) number of populated outlets (int)
3 things it can do:
    1) Install plug
    2) get current outlet power 
    3) disable power
 */

struct PowerStrip
{
    // Number of power outlets 
    int numOutlets = 5;
    // max surge  protection rating in watts
    float maxSurgeProtection = 2400.0f;
    //  
    
    // wire gauge 
    int wireGauge = 18;
    // number of populated outlets 
    int numPopulatedOutlets = 2;

    struct Outlet
    {
        // which outlet number
        int outletNum = 1;
        // current power
        double currentPower = 0.0;
        // GFCI status
        std::string gfciState = "normal";
        // Connector format
        std::string connectorFormat = "US";
        // plug installed
        bool plugInstalled = false;

        // Trip GFCI breaker
        void tripGFCI();
        // retrieve outlet current power
        double getCurrentPower();
        // return plugged in status (useful for parent functions)
        bool isPlugInstalled();

    };

    // Insert plug
    int insertPlug(Outlet outlet);
    // get current outlet power
    float getOutletPower(int plugNum);
    // disable power
    void disablePower();
      

};
/*
Thing 5) Pickups
5 properties:
    1) Magnet Material (std::string)
    2) Number of Coils (int)
    3) type of pickup
    4) distance from strings in cm (float)
    5) brand (std::string)
3 things it can do:
    1) adjust height
    2) Select tap
    3) convert vibration to voltage
 */
struct Pickup
{
    // Magnet Material 
    std::string magnetMaterial = "alnico";
    // Number of Coils 
    int numCoils = 2;
    // type of pickup 
    std::string pickupType = "Humbucker";
    // distance from strings in cm 
    float pickupDistance = 3.2f;
    // brand 
    std::string brand = "EMG";
    
    // adjust height in mm
    void adjustHeight(double heightAdjustment = 0.0);
    // Select tap
    int toggleCenterTap();
    // convert vibration to voltage
    double vibToVoltage(double vibrationPower = 0.0);
};
/*
Thing 6) Neck
5 properties:
    1) Fretboard Material (std::string)
    2) scale length in cm (double)
    3) number of frets(int)
    4) fret width in mm (float)
    5) nut material (std::string)
3 things it can do:
    1) adjust truss rod
    2) fret note
    3) clean fretboard
 */
struct Neck
{
    // Fretboard Material 
    std::string fretboardMaterial = "rosewood";
    // scale length in cm 
    double scaleLength = 60.96;
    // number of frets(int)
    int numFrets = 24;
    // fret width in mm (float)
    float fretWidth = 0.94f;
    // truss rod neck releief in mm
    float neckRelief = 0.25f;
    //  fretboard soiled
    bool fretboardSoiled = false;

    // adjust truss rod
    float adjustTrussRod(float numTurns = 0.0);
    // fret note
    int fretNote(int stringNum = 6, int fretNum = 0);
    // clean fretboard
    void cleanFretboard();

};
/*
Thing 7)  Body
5 properties:
    1) body type(std::string)
    2) color (std::string)
    3) cutout radius in cm (float)
    4) number of cutouts (int)
    5) thickness in cm (float)
3 things it can do:
    1) select pickup output
    2) adjust pickup volume
    3) adjust pickup tone
 */
struct Body
{
    // body type
    std::string bodyType = "solid";
    // color 
    std::string color = "sunburst";
    // cutout radius in cm 
    float cutoutRadius = 2.5f;
    // number of cutouts 
    int numCutouts = 2;
    // thickness in cm 
    float thickness = 4.76f;

    // select pickup output
    int selectPickup(int pickup);
    // adjust pickup volume
    float changeVolume(float newVolume);
    // adjust pickup tone
    float changeTone(float newTone);
};
/*
Thing 8) Tuners
5 properties:
    1) tuner metal (std::string)
    2) string tension in pounds (double)
    3) number of tuners(int)
    4) tuner angle in degrees (double)
    5) tuner gear ratio (float)
3 things it can do:
    1) rotate tuner key
    2) adjust string tension
    3) tighten set nut
 */ 
struct Tuners
{
    // tuner metal 
    std::string metal = "Steel";
    // adjustment key orientation 
    double stringTension = 11.8;
    // number of tuners
    int numTuners = 6;
    // tuner angle in degrees
    double degree = 1.75;
    // tuner gear ratio 
    float gearRatio = 50.0;

    // rotate tuner key
    void rotateKey(int keyNum = 1, float numTurns = 0.f);
    // adjust string tension
    void changeStringTension(int keyNum, int tunedNote);
    // get number of installed strings
    int getNumInstalledStrings();
    
};
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
struct Bridge
{
    // type of bridge
    std::string type = "floating";
    // number of string poles 
    int numStrings = 6;
    // length adjustment screw setting in mm 
    double screwSetting = 0.5;
    // type of tremolo 
    std::string tremoloType = "strat";
    // floating bridge tension (std::string)
    std::string tension = "high";


    // adjust string length
    void adjustScrewSetting(double screwAdjustment);
    // move whammy bar
    void rotateWhammy(std::string direction);
    // adjust bridge height
    void changeHeight(double heightAdjustment);
};
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
    3) tune strings
 */
struct ElectricGuitar
{
    // Pickups
    Pickup pickup;
    // Neck
    Neck neck;
    // Body
    Body body;
    // Tuners
    Tuners tuners;
    // Bridge
    Bridge bridge;

    // play a chord
    void playChord(Neck neckA, int chord = 62, int position = 2);
    // generate electrical output
    double generateVoltage(double strumStrength);
    // Tune Strings
    void tuneStrings(Tuners tunersA);
};

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
