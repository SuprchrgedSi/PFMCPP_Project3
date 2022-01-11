/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) do this for each class in this project: 
    initialize some of your member variables either in-class or in the Constructor member initializer list.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable
    float b { 2.f }; // in-class initialization
    UDT() : a(0) { } // 'constructor-initializer-list' member variable initialization
    void printAandB()  //the member function
    {
        std::cout << "UDT::printAandB() a:" << a << " b: " << b << std::endl;  //4) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printAandB(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()


struct ComputerMonitor
{
    int screenBrightness = 50;
    int pixelWidth = 1920;
    int pixelHeight = 1080;
    int numInputs = 5;
    std::string brand = "Samsung";
    float redGain = 0.72f;
    
    ComputerMonitor();
    void displayInput(int selectedInput = 1);
    void adjustBrightness(int brightnessAdjustment = 0);
    float changeAspectRatio(int xDim, int yDim);
};

ComputerMonitor::ComputerMonitor(){ std::cout << "ComputerMonitor" << std::endl; }

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

    float aspectRatio = xDim/yDim;
    std::cout << "The new aspect ratio is " << aspectRatio << std::endl;
    return aspectRatio;
}

struct StandingDesk
{
    float unladenWeight = 10.f;
    float deskHeight = 36.f;
    double maxSupportedWeight = 276.3;
    double width = 48.0;
    std::string compositionMaterial = "glass";
    std::string drawerLocation = "in";

    StandingDesk();
    std::string slideDrawer();
    void changeHeight(float heightChange = 1.f);
    float rollDesk(float xDistance = 0.5f, float yDistance = 0.5f);
};

StandingDesk::StandingDesk() { std::cout << "StandingDesk" << std::endl; }

std::string StandingDesk::slideDrawer()
{ 
    if (drawerLocation == "in") { drawerLocation = "out";}
    else                        { drawerLocation = "in";}
    
    std::cout << "The drawer has been slid " << drawerLocation << "." << std::endl;
    return drawerLocation;
}

void StandingDesk::changeHeight(float heightChange)
{
    std::cout << "The current desk height is " << deskHeight << " inches." << std::endl;
    deskHeight += heightChange;
    std::cout << "The new desk height is " << deskHeight << " inches." << std::endl;
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
        double gain = 1.0;
        std::string ampTopology = "Class AB";
        int outputImpedance = 8;
        int numOutputs = 1;
        std::string powerState = "standby";

        PowerAmp();
        void changeGain(double gainAdjustment);
        void enableAmpStandby();
        int selectImpedance(int impedance = 8) ;
    };

    GuitarAmp();
    double amplifyGuitar(double inputVoltage = 0.0, double ampGain = 0.0);
    double adjustReverbAmount(double reverbGain = 1.0);
    int switchChannel(int currentChannel, int newChannel = 0);
};

GuitarAmp::PowerAmp::PowerAmp(){ std::cout << "PowerAmp" << std::endl; }

void GuitarAmp::PowerAmp::changeGain(double gainAdjustment) 
{ 
    gain *= gainAdjustment; 
    std::cout << "The new power amp gain is " << gain << "." << std::endl;
}

void GuitarAmp::PowerAmp::enableAmpStandby() 
{ 
    std::cout << "The power amp is now in standby." << std::endl;
    powerState = "standby"; }

int GuitarAmp::PowerAmp::selectImpedance(int impedance) 
{ 
    if (impedance != outputImpedance)
    {
        std::cout << "The user has selected an impedance of " << impedance << "." << std::endl;
        outputImpedance = impedance;
    }
    return impedance;
}

GuitarAmp::GuitarAmp() {std::cout << "GuitarAmp" << std::endl; }

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
    if (currentChannel == newChannel) 
    {
        std::cout << "The amp is now in channel " << newChannel << "." << std::endl;
        return currentChannel;
    }

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
        float currentPower = 3.1f;
        std::string GFCIState = "normal";
        std::string connectorFormat = "US";
        bool plugInstalled = false;

        Outlet();
        void tripGFCI();
        float getCurrentPower();
        bool isPlugInstalled();
    };

    Outlet outlet1;
    Outlet outlet2;
    Outlet outlet3;

    PowerStrip();
    int insertPlug(Outlet outlet);
    float getPowerStripPower();
    void disablePower();
};

PowerStrip::Outlet::Outlet() { std::cout << "Outlet" << std::endl; }

void PowerStrip::Outlet::tripGFCI()
{
    std::cout << "Outlet " << outletNum << " has tripped." << std::endl;
    currentPower = 0.0;
    GFCIState = "tripped";
}

float PowerStrip::Outlet::getCurrentPower() 
{
    std::cout << "Outlet " << outletNum << " is supplying " << currentPower << " watts of power" << std::endl;
    return currentPower; 
}

bool PowerStrip::Outlet::isPlugInstalled() 
{ 
    if (plugInstalled) { std::cout << "Outlet " << outletNum << " has a plug installed. " << std::endl; }
    else               { std::cout << "Outlet " << outletNum << " does not have a plug installed. " << std::endl; }
    
    return plugInstalled; 
}

PowerStrip::PowerStrip() 
{
    std::cout << "PowerStrip" << std::endl; 
    outlet2.outletNum = 2;    
    outlet3.outletNum = 3;
}

int PowerStrip::insertPlug(Outlet outlet) 
{
    std::cout << "Outlet " << outlet.outletNum << " now has a plug installed. " << std::endl;
    if (outlet1.outletNum == outlet.outletNum) {outlet1.plugInstalled = true;}
    if (outlet2.outletNum == outlet.outletNum) {outlet2.plugInstalled = true;}
    if (outlet3.outletNum == outlet.outletNum) {outlet3.plugInstalled = true;}
    return outlet.outletNum;
}

float PowerStrip::getPowerStripPower()
{
    float totalPower = outlet1.getCurrentPower() + outlet2.getCurrentPower() + outlet3.getCurrentPower();

    std::cout << "The power strip is supplying " << totalPower << "" << " watts of power" << std::endl;

    return totalPower;
}

void PowerStrip::disablePower()
{
    std::cout << "The power strip is now disabled." << std::endl;
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
    
    Pickup();
    void adjustHeight(double heightAdjustment = 0.0);
    int toggleCenterTap();
    double vibToVoltage(double vibrationPower = 0.0);
};

Pickup::Pickup() {std::cout << "Pickup" << std::endl; }

void Pickup::adjustHeight(double heightAdjustment)
{ 
    pickupDistance -= heightAdjustment; 
    std::cout << "The pickups are now " << pickupDistance << " from the strings." << std::endl;
}

int Pickup::toggleCenterTap()
{
    if (pickupType == "Humbucker") 
    {
        if (numCoils == 2) 
        {
            std::cout << "The pickup is now center tapped." <<std::endl;
            numCoils = 1;
        }
        else
        {
            std::cout << "The pickup is not center tapped." <<std::endl;
            numCoils = 2;
        }
    }
    else {std::cout << "Single coil pickups do not have a center tap." << std::endl;}

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

    Neck();
    float adjustTrussRod(float numTurns = 0.0);
    int fretNote(int stringNum = 6, int fretNum = 0);
    void cleanFretboard();
};

Neck::Neck() { std::cout << "Neck" << std::endl; }

float Neck::adjustTrussRod(float numTurns)
{
    neckRelief *= numTurns * 0.1f;
    return neckRelief;
}

int Neck::fretNote(int stringNum, int fretNum)
{
    return stringNum + fretNum;
}

void Neck::cleanFretboard() 
{ 
    std::cout << "The neck is now clean." <<std::endl;
    fretboardSoiled = false; }

struct Body
{
    std::string bodyType = "solid";
    std::string color = "sunburst";
    float cutoutRadius = 2.5f;
    int numCutouts = 2;
    float thickness = 4.76f;

    Body();
    int selectPickup(int pickup);
    float changeVolume(float newVolume);
    float changeTone(float newTone);
};

Body::Body() { std::cout << "Body" << std::endl; }

int Body::selectPickup(int pickup) 
{ 
    std::cout << "Pickup " << pickup << " is now selected." <<std::endl;
    return pickup; 
}

float Body::changeVolume(float newVolume) 
{ 
    std::cout << "The volume knob is now set at " << newVolume << "." << std::endl;
    return newVolume; 
}

float Body::changeTone(float newTone)
{ 
    std::cout << "The tone knob is now set at " << newTone << "." << std::endl;    
    return newTone; 
}

struct Tuners
{
    std::string metal = "Steel";
    double stringTension = 11.8;
    int numTuners = 6;
    double degree = 1.75;
    double gearRatio = 50.0;

    Tuners();
    void rotateKey(int keyNum = 1, double numTurns = 0.0);
    void changeStringTension(int keyNum, int tunedNote);
    int getNumInstalledStrings();
    
};

Tuners::Tuners() { std::cout << "Tuners" << std::endl; }

void Tuners::rotateKey(int keyNum, double numTurns) 
{
    degree += keyNum* numTurns / gearRatio * 360.0;
    std::cout << "Tuner " << keyNum << " is now at " << degree << " degrees." <<std::endl;
}

void Tuners::changeStringTension(int keyNum, int tunedNote)
{
    stringTension += keyNum * tunedNote * 0.01;
}

int Tuners::getNumInstalledStrings() 
{ 
    std::cout << "The guitar has " << numTuners << " tuners." << std::endl; 
    return numTuners; 
}

struct Bridge
{
    std::string type = "floating";
    int numStrings = 6;
    double screwSetting = 0.5;
    std::string tremoloType = "strat";
    std::string tension = "high";

    Bridge();
    void adjustScrewSetting(double screwAdjustment);
    void rotateWhammy(std::string direction);
    void changeHeight(double heightAdjustment);
};

Bridge::Bridge() { std::cout << "Bridge" << std::endl; }

void Bridge::adjustScrewSetting(double screwAdjustment) 
{ 
    screwSetting += screwAdjustment; 
    std::cout << "The bridge screw is now at " << screwSetting << " mm." << std::endl;
}

void Bridge::rotateWhammy(std::string direction) 
{
    if (direction == "pull") 
    {
        std::cout <<  "The whammy bar was pulled up." << std::endl;
        tension = "high";
    }
    else
    {
        std::cout <<  "The whammy bar was pushed down." << std::endl;
        tension = "low";
    }   
}

void Bridge::changeHeight(double heightAdjustment) { screwSetting += heightAdjustment; }

struct ElectricGuitar
{
    Pickup pickup;
    Neck neck;
    Body body;
    Tuners tuners;
    Bridge bridge;

    ElectricGuitar();
    void playChord(Neck neckA, int chord = 0, int position = 2);
    double generateVoltage(double strumStrength);
    void tuneStrings(Tuners tunersA);
};

ElectricGuitar::ElectricGuitar() { std::cout << "ElectricGuitar" << std::endl; }

void ElectricGuitar::playChord(Neck neckA, int chord, int position)
{
    std::cout << "The guitar plays chord " << chord << "." << std::endl;
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
    std::cout << "The guitar is now tuned." << std::endl;
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
    
    StandingDesk standingDesk;
    PowerStrip powerStrip;

    std::cout << "The desk drawer is currently " << standingDesk.drawerLocation << "." << std::endl;
    standingDesk.slideDrawer();
    standingDesk.changeHeight(5.1f);
    std::cout << "The desk rolled " << standingDesk.rollDesk(1.5f, 3.7f) << " feet." << std::endl;

    powerStrip.outlet1.tripGFCI();
    powerStrip.outlet2.currentPower = 1.3f;
    powerStrip.insertPlug(powerStrip.outlet3);

    if (powerStrip.outlet3.isPlugInstalled())
    {
        std::cout << "After running insertPlug function, the isPlugInstalled function verifies plug is installed." << std::endl;
    }

    powerStrip.getPowerStripPower();
    powerStrip.disablePower();
    
    std::cout << "good to go!" << std::endl;
}
