/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of each of your user-defined types in the main() function.

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int a; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    a = 0;
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << a << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'a' equal to 0? " << (foo.a == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




struct ComputerMonitor
{
    int screenBrightness = 50;
    int pixelWidth = 1920;
    int pixelHeight = 1080;
    int numInputs = 5;
    std::string brand = "Samsung";
    float redGain = 0.72f;
    

    void displayInput(int selectedInput = 1);
    void adjustBrightness(int brightnessAdjustment = 0);
    float changeAspectRatio(int xDim, int yDim);
};

void ComputerMonitor::displayInput(int selectedInput)
{
    std::cout << "Display " << selectedInput << " is on screen" << std::endl;
}

void ComputerMonitor::adjustBrightness(int brightnessAdjustment)
{
    screenBrightness += brightnessAdjustment;
}

float ComputerMonitor::changeAspectRatio(int xDim, int yDim)
{
    pixelWidth = xDim;
    pixelHeight = yDim;
    return xDim/yDim;
}

struct StandingDesk
{
    float unladenWeight = 10.f;
    float deskHeight = 36.f;
    double maxSupportedWeight = 276.3;
    double width = 48.0;
    std::string compositionMaterial = "glass";
    std::string drawerLocation = "in";

    std::string slideDrawer();
    void changeHeight(float heightChange = 1.f);
    float rollDesk(float xDistance = 0.5f, float yDistance = 0.5f);
};

std::string StandingDesk::slideDrawer()
{ 
    if (drawerLocation == "in") return "out";

    return "in";
}

void StandingDesk::changeHeight(float heightChange)
{
    deskHeight += heightChange;
}

float StandingDesk::rollDesk(float xDistance , float yDistance)
{
    return xDistance + yDistance;
}

struct GuitarAmp
{
    double preampGain = 0.25;
    int numChannels = 2;
    float maxOutPower = 100.f;
    double trebleGain = 0.5;
    double reverbLevel = 0.25;

    struct PowerAmp
    {
        double gain = 0.0;
        std::string ampTopology = "Class AB";
        int outputImpedance = 8;
        int numOutputs = 1;
        std::string powerState = "standby";

        void changeGain(double gainAdjustment);
        void enableAmpStandby();
        int selectImpedance(int impedance = 8) ;
    };


    double amplifyGuitar(double inputVoltage = 0.0, double ampGain = 0.0);
    double adjustReverbAmount(double reverbGain = 1.0);
    int switchChannel(int currentChannel, int newChannel = 0);
};

void GuitarAmp::PowerAmp::changeGain(double gainAdjustment) { gain *= gainAdjustment; }

void GuitarAmp::PowerAmp::enableAmpStandby() { powerState = "standby"; }

int GuitarAmp::PowerAmp::selectImpedance(int impedance) 
{ 
    outputImpedance = impedance;
    return impedance;
}

double GuitarAmp::amplifyGuitar(double inputVoltage, double ampGain) 
{ 
    return inputVoltage * ampGain;
}

double GuitarAmp::adjustReverbAmount(double reverbGain)
{
    reverbLevel *= reverbGain;
    return reverbLevel;
}

int GuitarAmp::switchChannel(int currentChannel, int newChannel)
{
    if (currentChannel == newChannel) return currentChannel;

    return newChannel;
}

struct PowerStrip
{
    int numOutlets = 3;
    float maxSurgeProtection = 2400.0f;
    int wireGauge = 18;
    int numPopulatedOutlets = 2;

    struct Outlet
    {
        int outletNum = 1;
        float currentPower = 0.0;
        std::string GFCIState = "normal";
        std::string connectorFormat = "US";
        bool plugInstalled = false;

        void tripGFCI();
        float getCurrentPower();
        bool isPlugInstalled();
    };

    Outlet outlet1;
    Outlet outlet2;
    Outlet outlet3;

    int insertPlug(Outlet outlet);
    float getOutletPower();
    void disablePower();
};

void PowerStrip::Outlet::tripGFCI()
{
    currentPower = 0.0;
    GFCIState = "tripped";
}

float PowerStrip::Outlet::getCurrentPower() { return currentPower; }

bool PowerStrip::Outlet::isPlugInstalled() { return plugInstalled; }

int PowerStrip::insertPlug(Outlet outlet) 
{
    outlet.plugInstalled = true;
    return outlet.outletNum;
}

float PowerStrip::getOutletPower()
{
    return outlet1.getCurrentPower() + outlet2.getCurrentPower() + 
            outlet3.getCurrentPower();
}

void PowerStrip::disablePower()
{
    outlet1.GFCIState = "off";
    outlet2.GFCIState = "off";
    outlet3.GFCIState = "off";
}

struct Pickup
{
    std::string magnetMaterial = "alnico";
    int numCoils = 2;
    std::string pickupType = "Humbucker";
    double pickupDistance = 3.2;
    std::string brand = "EMG";
    
    void adjustHeight(double heightAdjustment = 0.0);
    int toggleCenterTap();
    double vibToVoltage(double vibrationPower = 0.0);
};

void Pickup::adjustHeight(double heightAdjustment){ pickupDistance -= heightAdjustment; }

int Pickup::toggleCenterTap()
{
    if (pickupType == "Humbucker") 
    {
        if (numCoils == 2) numCoils = 1;
        else               numCoils = 2;
    }

    return numCoils;
}

double Pickup::vibToVoltage(double vibrationPower)
{
    return vibrationPower * pickupDistance;
}

struct Neck
{
    std::string fretboardMaterial = "rosewood";
    double scaleLength = 60.96;
    int numFrets = 24;
    float fretWidth = 0.94f;
    float neckRelief = 0.25f;
    bool fretboardSoiled = false;

    float adjustTrussRod(float numTurns = 0.0);
    int fretNote(int stringNum = 6, int fretNum = 0);
    void cleanFretboard();
};

float Neck::adjustTrussRod(float numTurns)
{
    neckRelief *= numTurns * 0.1f;
    return neckRelief;
}

int Neck::fretNote(int stringNum, int fretNum)
{
    return stringNum + fretNum;
}

void Neck::cleanFretboard() { fretboardSoiled = false; }

struct Body
{
    std::string bodyType = "solid";
    std::string color = "sunburst";
    float cutoutRadius = 2.5f;
    int numCutouts = 2;
    float thickness = 4.76f;

    int selectPickup(int pickup);
    float changeVolume(float newVolume);
    float changeTone(float newTone);
};

int Body::selectPickup(int pickup) { return pickup; }

float Body::changeVolume(float newVolume) { return newVolume; }

float Body::changeTone(float newTone){ return newTone; }

struct Tuners
{
    std::string metal = "Steel";
    double stringTension = 11.8;
    int numTuners = 6;
    double degree = 1.75;
    double gearRatio = 50.0;

    void rotateKey(int keyNum = 1, double numTurns = 0.0);
    void changeStringTension(int keyNum, int tunedNote);
    int getNumInstalledStrings();
    
};

void Tuners::rotateKey(int keyNum, double numTurns) 
{
    degree += keyNum* numTurns / gearRatio * 360.0;
}

void Tuners::changeStringTension(int keyNum, int tunedNote)
{
    stringTension += keyNum * tunedNote * 0.01;
}

int Tuners::getNumInstalledStrings() { return numTuners; }

struct Bridge
{
    std::string type = "floating";
    int numStrings = 6;
    double screwSetting = 0.5;
    std::string tremoloType = "strat";
    std::string tension = "high";

    void adjustScrewSetting(double screwAdjustment);
    void rotateWhammy(std::string direction);
    void changeHeight(double heightAdjustment);
};

void Bridge::adjustScrewSetting(double screwAdjustment) { screwSetting += screwAdjustment; }

void Bridge::rotateWhammy(std::string direction) 
{
    if (direction == "pull") tension = "high";
    else                     tension = "low";
}

void Bridge::changeHeight(double heightAdjustment) { screwSetting += heightAdjustment; }

struct ElectricGuitar
{
    Pickup pickup;
    Neck neck;
    Body body;
    Tuners tuners;
    Bridge bridge;

    void playChord(Neck neckA, int chord = 0, int position = 2);
    double generateVoltage(double strumStrength);
    void tuneStrings(Tuners tunersA);
};

void ElectricGuitar::playChord(Neck neckA, int chord, int position)
{
    neckA.fretNote(6, position + chord);
    neckA.fretNote(5, position + chord + 4);
    neckA.fretNote(4, position + chord + 7);
    neckA.fretNote(3, position + chord + 12);
    neckA.fretNote(2, position + chord  + 16);
    neckA.fretNote(1, position + chord + 19);
}
double ElectricGuitar::generateVoltage(double strumStrength)
{
    return strumStrength * 0.053;
}

void ElectricGuitar::tuneStrings(Tuners tunersA)
{
    tunersA.changeStringTension(0,54);
}

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
    Example::main();
    
    
    std::cout << "good to go!" << std::endl;
}
