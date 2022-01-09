 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
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
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */
struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;
    
    struct Foot
    {
        int stepLength = 1;
        int numSteps = 0;

        int stepSize() { return stepLength;}
        int stepForward()
        { 
            numSteps ++;
            return stepSize();
        }
        
    };

    Foot leftFoot;
    Foot rightFoot;


    void run(bool startWithLeftFoot)
    {
        if ( startWithLeftFoot) 
        {
            distanceTraveled += leftFoot.stepForward() + rightFoot.stepForward();
        }

        distanceTraveled += rightFoot.stepForward() + leftFoot.stepForward();
    }
};




 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have warnings about 'unused parameter', you aren't using one of your function parameters in your implementation.
    use the parameter in your implementation.
    If you have warnings about 'overshadow', a local variable in the function has the same name as a class member.
    change the name of your local variable so it is different from the class member's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */



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
        int selectImpedance( int impedance = 8) ;
    };


    double amplifyGuitar(double inputVoltage = 0.0, double ampGain = 0.0);
    double adjustReverbAmount(double reverbGain = 1.0);
    int switchChannel(int currentChannel, int newChannel = 0);
};

void GuitarAmp::PowerAmp::changeGain(double gainAdjustment) {gain *= gainAdjustment;}
void GuitarAmp::PowerAmp::enableAmpStandby() { powerState = "standby";}
int GuitarAmp::PowerAmp::selectImpedance( int impedance) 
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
float PowerStrip::Outlet::getCurrentPower() { return currentPower;}
bool PowerStrip::Outlet::isPlugInstalled() { return plugInstalled;}

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

void Pickup::adjustHeight(double heightAdjustment){ pickupDistance -= heightAdjustment;}

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

void Neck::cleanFretboard() { fretboardSoiled = false;}

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

int Body::selectPickup(int pickup) { return pickup;}

float Body::changeVolume(float newVolume) { return newVolume;}

float Body::changeTone(float newTone){ return newTone;}

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

void Tuners::rotateKey(int keyNum , double numTurns) 
{
    degree += keyNum*numTurns/gearRatio*360.0;
}

void Tuners::changeStringTension(int keyNum, int tunedNote)
{
    stringTension += keyNum*tunedNote*0.01;
}

int Tuners::getNumInstalledStrings() {return numTuners;}

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

void Bridge::adjustScrewSetting(double screwAdjustment) 
    { screwSetting += screwAdjustment;}

void Bridge::rotateWhammy(std::string direction) 
{
    if (direction == "pull") tension = "high";
    else                     tension = "low";
}

void Bridge::changeHeight(double heightAdjustment) { screwSetting += heightAdjustment;}

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

void ElectricGuitar::playChord(Neck neckA, int chord , int position)
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
    std::cout << "good to go!" << std::endl;
}
