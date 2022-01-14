/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
#include <cmath>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            bar.num += 1;                    //2a)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()





struct ComputerMonitor
{
    int screenBrightness = 50;
    int pixelWidth;
    int pixelHeight;
    int numInputs;
    std::string brand = "Samsung";
    float redGain = 0.72f;
    
    ComputerMonitor();
    void displayInput(int selectedInput = 1);
    void adjustBrightness(int brightnessAdjustment = 0);
    float changeAspectRatio(int xDim, int yDim);
    int detectActiveInputs();
};

ComputerMonitor::ComputerMonitor() :
pixelWidth(1920), 
pixelHeight(1080), 
numInputs(5)
{ 
    std::cout << "ComputerMonitor" << std::endl; 
}

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

int ComputerMonitor::detectActiveInputs()
{
    int numActiveInputs = 0;
    for(int i = 1; i < numInputs; ++i)
    {
        // say every even input number has video attached 
        if (i % 2) 
        {
            ++numActiveInputs;
            std::cout << "Input " << i << " has active video" << std::endl;
        }
        else std::cout << "Input " << i << " does not have active video" << std::endl;
    }

    return numActiveInputs;
}
struct StandingDesk
{
    float unladenWeight;
    float deskHeight;
    double maxSupportedWeight = 276.3;
    float maxHeight = 48.f;
    double width = 48.0;
    std::string compositionMaterial = "glass";
    std::string drawerLocation;

    StandingDesk();
    std::string slideDrawer();
    void changeHeight(float heightChange = 1.f);
    double rollDesk(double xDistance = 0.5, double yDistance = 0.5);
    int maxOutHeight(float incrementSize);
};

StandingDesk::StandingDesk() :
unladenWeight(10.5f),
deskHeight(36.f),
drawerLocation("in")
{ 
    std::cout << "StandingDesk" << std::endl; 
}

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

double StandingDesk::rollDesk(double xDistance, double yDistance)
{
    return std::pow((std::pow(xDistance, 2) + std::pow(yDistance, 2)), 0.5);
}

int StandingDesk::maxOutHeight(float incrementSize)
{
    int numSteps = 0;
    while (deskHeight < maxHeight)
    {
        if (maxHeight - deskHeight <= incrementSize){
            deskHeight = maxHeight;
            std:: cout << "Increased desk height by " << maxHeight - deskHeight << " inches.  Desk is now at max height of " << maxHeight  << " inches." << std::endl;
            ++numSteps;
            break;
        }
        std:: cout << "Increased desk height by " << incrementSize << " inches.  New height is " << (deskHeight += incrementSize) << " inches." << std:: endl;
        ++numSteps;
    }
    return numSteps;
}

struct GuitarAmp
{
    double preampGain;
    int numChannels;
    float maxOutPower;
    double trebleGain = 0.5;
    double reverbLevel;

    struct PowerAmp
    {
        double gain;
        std::string ampTopology = "Class AB";
        int outputImpedance;
        int numOutputs = 1;
        std::string powerState;

        PowerAmp();
        void changeGain(double gainAdjustment);
        void enableAmpStandby();
        int selectImpedance(int impedance = 8);
        void turnOnStandby();
        bool waitUntilWarm(double targetTemp);
    };

    PowerAmp powerAmp;

    GuitarAmp();
    void turnOnAmp();
    double amplifyGuitar(double inputVoltage = 0.0);
    double adjustReverbAmount(double reverbGain = 1.0);
    int switchChannel(int currentChannel, int newChannel = 0);
    void adjustGainForTargetOutput(double inputVoltage = 0.0, double targetOutput = 0.0);
};

GuitarAmp::PowerAmp::PowerAmp() :
gain(1.0),
outputImpedance(8),
powerState("off")
{ 
    std::cout << "PowerAmp" << std::endl; 
}

void GuitarAmp::PowerAmp::changeGain(double gainAdjustment) 
{ 
    gain *= gainAdjustment; 
    std::cout << "The new power amp gain is " << gain << "." << std::endl;
}

void GuitarAmp::PowerAmp::enableAmpStandby() 
{ 
    std::cout << "The power amp is now in standby." << std::endl;
    powerState = "standby"; 
    
    if (waitUntilWarm(155.2)) std::cout << "The amp is ready for full power." << std::endl;

}

int GuitarAmp::PowerAmp::selectImpedance(int impedance) 
{ 
    if (impedance != outputImpedance)
    {
        std::cout << "The user has selected an impedance of " << impedance << "." << std::endl;
        outputImpedance = impedance;
    }
    return impedance;
}

bool GuitarAmp::PowerAmp::waitUntilWarm(double targetTemp)
{
    double currentTemp = 72;
    while (currentTemp < targetTemp)
    {
        std::cout << "Amp temp is " << currentTemp << ". Checking again in 10 seconds." << std::endl;
        currentTemp += 25.3; 
    }
    return true;
}


GuitarAmp::GuitarAmp() : 
preampGain(0.25),
numChannels(2),
maxOutPower(100.f),
reverbLevel(0.25)
{
    std::cout << "GuitarAmp" << std::endl; 
}

void GuitarAmp::turnOnAmp()
{
    powerAmp.enableAmpStandby();
}

double GuitarAmp::amplifyGuitar(double inputVoltage) 
{ 
    return inputVoltage * preampGain * powerAmp.gain;
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

void GuitarAmp::adjustGainForTargetOutput(double inputVoltage, double targetOutput)
{
    while (amplifyGuitar(inputVoltage) <  targetOutput)
    {
        powerAmp.gain *= 1.5;
    }
    std::cout << "Corrected output gain is " << powerAmp.gain << "." << std::endl;
}

struct PowerStrip
{
    int numOutlets;
    float maxSurgeProtection;
    int wireGauge = 18;
    int numPopulatedOutlets;

    struct Outlet
    {
        static int numOutlets;
        
        int outletNum;
        float currentPower = 3.1f;
        std::string GFCIState = "normal";
        std::string connectorFormat = "US";
        bool plugInstalled;

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
    void enablePower();
    void disablePower();
    void cyclePower(int numCycles);
};

int PowerStrip::Outlet::numOutlets = 0;

PowerStrip::Outlet::Outlet() : 
plugInstalled(false)
{ 
    outletNum = ++numOutlets;
    std::cout << "Outlet" << std::endl; 
}

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

PowerStrip::PowerStrip() : 
numOutlets(3),
maxSurgeProtection(2400.f),
numPopulatedOutlets(0)
{
    std::cout << "PowerStrip" << std::endl; 
    outlet2.outletNum = 2;    
    outlet3.outletNum = 3;
}

int PowerStrip::insertPlug(Outlet outlet) 
{
    std::cout << "Outlet " << outlet.outletNum << " now has a plug installed. " << std::endl;
    if (outlet1.outletNum == outlet.outletNum) outlet1.plugInstalled = true;
    if (outlet2.outletNum == outlet.outletNum) outlet2.plugInstalled = true;
    if (outlet3.outletNum == outlet.outletNum) outlet3.plugInstalled = true;
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

void PowerStrip::enablePower()
{
    std::cout << "The power strip is now enabled." << std::endl;
    outlet1.GFCIState = "on";
    outlet2.GFCIState = "on";
    outlet3.GFCIState = "on";
}

void PowerStrip::cyclePower(int numCycles)
{
    for (int i = 0; i < numCycles; ++i)
    {
        if (outlet1.GFCIState == "off") 
        {
            enablePower();
        }
        else
        {
            disablePower();
            enablePower();
        }
    }
    
}

struct Pickup
{
    std::string magnetMaterial = "alnico";
    int numCoils;
    std::string pickupType;
    double pickupDistance = 3.2;
    std::string brand = "EMG";
    
    Pickup();
    void adjustHeight(double heightAdjustment = 0.0);
    int toggleCenterTap();
    double vibToVoltage(double vibrationPower = 0.0);
};

Pickup::Pickup() : 
numCoils(2),
pickupType("Humbucker")
{std::cout << "Pickup" << std::endl; }

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
    else 
    {
        std::cout << "Single coil pickups do not have a center tap." << std::endl;
    }

    return numCoils;
}

double Pickup::vibToVoltage(double vibrationPower)
{
    return vibrationPower * pickupDistance;
}

struct Neck
{
    std::string fretboardMaterial;
    double scaleLength = 60.96;
    int numFrets;
    float fretWidth = 0.94f;
    float neckRelief = 0.25f;
    bool fretboardSoiled = false;

    Neck();
    float adjustTrussRod(float numTurns = 0.0);
    int fretNote(int stringNum = 6, int fretNum = 0);
    void cleanFretboard();
    void setNeckRelief(float newRelief);
};

Neck::Neck() : 
fretboardMaterial("rosewood"),
numFrets(24)
{ 
    std::cout << "Neck" << std::endl; 
}

float Neck::adjustTrussRod(float numTurns)
{
    neckRelief += numTurns * 0.05f;
    return neckRelief;
}

int Neck::fretNote(int stringNum, int fretNum)
{
    return stringNum + fretNum;
}

void Neck::cleanFretboard() 
{ 
    std::cout << "The neck is now clean." <<std::endl;
    fretboardSoiled = false; 
}

void Neck::setNeckRelief(float newRelief)
{
    while (neckRelief < newRelief)
    {
        std::cout << "Tightening the truss rod 1 turn " << std::endl;
        adjustTrussRod(1.f);
    }

    std::cout << "The neck relief is now at " << neckRelief << "." << std::endl;
}

struct Body
{
    std::string bodyType = "solid";
    std::string color;
    float cutoutRadius = 2.5f;
    int numCutouts;
    float thickness = 4.76f;

    Body();
    int selectPickup(int pickup);
    float changeVolume(float newVolume);
    float changeTone(float newTone);
};



Body::Body() : 
color("sunburst"),
numCutouts(2)
{ 
    std::cout << "Body" << std::endl; 
}

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
    double degree;
    double gearRatio = 50.0;

    Tuners();
    void rotateKey(int keyNum = 1, double numTurns = 0.0);
    void changeStringTension(int keyNum, int tunedNote);
    int getNumInstalledStrings();
    void setDegree(int keyNum, double targetAngle);
    
};

Tuners::Tuners() :
degree(0.0),
gearRatio(50.0)
{ 
    std::cout << "Tuners" << std::endl; 
}

void Tuners::rotateKey(int keyNum, double numTurns) 
{
    degree += numTurns / gearRatio * 360.0;

    if (degree > 360.0) 
        degree -= 360.0;
    else if (degree < 0.0) 
        degree += 360.0;

    std::cout << "Tuner " << keyNum << " is now at " << degree << " degrees." << std::endl;
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

void Tuners::setDegree(int keyNum, double targetAngle)
{
    std::cout << "Tuner " << keyNum << " needs to be at " << targetAngle << " degrees." << std::endl;
    while (targetAngle > degree)
    {
        rotateKey(keyNum, 1);
    }
}

struct Bridge
{
    std::string type;
    int numStrings;
    double screwSetting;
    double height;
    std::string tremoloType;
    std::string tension;

    Bridge();
    void adjustScrewSetting(double screwAdjustment);
    void rotateWhammy(std::string direction);
    void changeHeight(double heightAdjustment);
    void playVibrato(int numberOfMoves);
};

Bridge::Bridge() : 
type("floating"),
numStrings(6),
screwSetting(0.5),
height(6.0),
tremoloType("strat"),
tension("normal")
{ 
    std::cout << "Bridge" << std::endl; 
}

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

void Bridge::changeHeight(double heightAdjustment) 
{ 
    height += heightAdjustment; 
    std::cout << "The bridge height is now at " << height << " mm." << std::endl;
}

void Bridge::playVibrato(int numberOfMoves)
{
    for(int i = 0; i < numberOfMoves; ++i)
    {
        rotateWhammy("push");
        rotateWhammy("pull");
    }
}

struct ElectricGuitar
{
    Pickup pickup;
    Neck neck;
    Body body;
    Tuners tuners;
    Bridge bridge;

    ElectricGuitar();
    void playChord(int chord = 0, int position = 2);
    double generateVoltage(double strumStrength);
    void tuneStrings();
};

ElectricGuitar::ElectricGuitar() { std::cout << "ElectricGuitar" << std::endl; }

void ElectricGuitar::playChord(int chord, int position)
{
    std::cout << "The guitar plays chord " << chord << "." << std::endl;
    neck.fretNote(6, position + chord);
    neck.fretNote(5, position + chord + 4);
    neck.fretNote(4, position + chord + 7);
    neck.fretNote(3, position + chord + 12);
    neck.fretNote(2, position + chord  + 16);
    neck.fretNote(1, position + chord + 19);
}
double ElectricGuitar::generateVoltage(double strumStrength)
{
    return strumStrength * 0.053;
}

void ElectricGuitar::tuneStrings()
{
    std::cout << "The guitar is now tuned." << std::endl;
    tuners.changeStringTension(0, 54);
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
    
    ComputerMonitor computerMonitor;
    StandingDesk standingDesk;
    PowerStrip powerStrip;
    GuitarAmp guitarAmp;
    ElectricGuitar electricGuitar;

    std::cout << "-----------------------" << std::endl;
    
    computerMonitor.displayInput(3);
    computerMonitor.adjustBrightness(5);
    computerMonitor.changeAspectRatio(1280, 720);
    computerMonitor.detectActiveInputs();

    std::cout << "-----------------------" << std::endl;
    
    std::cout << "The desk drawer is currently " << standingDesk.drawerLocation << "." << std::endl;
    standingDesk.slideDrawer();
    standingDesk.changeHeight(5.1f);
    std::cout << "The desk rolled " << standingDesk.rollDesk(1.5, 3.7) << " feet." << std::endl;

    std::cout << "-----------------------" << std::endl;
    
    powerStrip.enablePower();
    powerStrip.outlet1.tripGFCI();
    powerStrip.outlet2.currentPower = 1.3f;
    powerStrip.insertPlug(powerStrip.outlet3);

    if (powerStrip.outlet3.isPlugInstalled())
    {
        std::cout << "After running insertPlug function, the isPlugInstalled function verifies plug is installed." << std::endl;
    }

    powerStrip.getPowerStripPower();
    powerStrip.cyclePower(3);
    
    std::cout << "-----------------------" << std::endl;

    guitarAmp.turnOnAmp();
    guitarAmp.powerAmp.changeGain(0.5);
    guitarAmp.powerAmp.selectImpedance(4);
    guitarAmp.amplifyGuitar(0.01);
    guitarAmp.adjustReverbAmount(0.3);
    guitarAmp.switchChannel(2);
    guitarAmp.adjustGainForTargetOutput(0.01, 10.1);

    std::cout << "-----------------------" << std::endl;

    electricGuitar.playChord(3, 3);
    std::cout << "While plaing, the guitar generats " << electricGuitar.generateVoltage(3.5) << " volts of output." << std::endl;
    electricGuitar.tuneStrings();
    electricGuitar.bridge.adjustScrewSetting(0.5);
    electricGuitar.bridge.changeHeight(0.3);
    electricGuitar.bridge.playVibrato(4);
    electricGuitar.tuners.rotateKey(1, 3);
    electricGuitar.tuners.changeStringTension(5, 6);
    electricGuitar.tuners.getNumInstalledStrings();
    electricGuitar.tuners.setDegree(1, 60.0);

    electricGuitar.neck.adjustTrussRod(0.5);
    electricGuitar.neck.fretNote(3, 11);
    electricGuitar.neck.cleanFretboard();
    electricGuitar.neck.setNeckRelief(0.33f);
    electricGuitar.body.selectPickup(2);
    electricGuitar.body.changeVolume(0.5f);
    electricGuitar.body.changeTone(0.75f);
    

    std::cout << "-----------------------" << std::endl;

    std::cout << "good to go!" << std::endl;
}
