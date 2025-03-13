

//enumeration for the different states of the eVTOL
enum class eVTOLState {
    IDLE,
    FLYING,
    WAITING_FOR_CHARGER,
    CHARGING,
    FAULTED
};

enum class eVTOLCompany {
    ALPHA,
    BRAVO,
    CHARLIE,
    DELTA,
    ECHO
};


/* 
    eVTOL Class
    This class is used to define the eVTOL vehicle object. 
    It has the following attributes:
    - cruiseSpeed: The speed at which the eVTOL can travel
    - batteryCapacity: The battery capacity of the eVTOL
    - TimetoCharge: The time it takes to charge the eVTOL, in minutes for simplicity
    - EnergyConsumption: The energy consumption at cruise
    - PassengerCount: The number of passengers the eVTOL can carry
    - FaultRate: The fault rate of the eVTOL
*/
class eVTOL {
private:
        //Attributes of the eVTOL
        int cruiseSpeed;
        int batteryCapacity;
        float TimetoCharge;
        float EnergyConsumption;
        int PassengerCount;
        int FaultRate;
        eVTOLState state;
        eVTOLCompany Model;
public:  
        //eVTOL statistics
        float avgFlightTime;
        float avgDistance;
        float avgChargeTime;
        int totalFaults;
        int passengerMiles;
  
    
        eVTOL(eVTOLCompany model){

            switch(model){
                case eVTOLCompany::ALPHA:
                    cruiseSpeed = 100; batteryCapacity = 100; TimetoCharge = 60; 
                    EnergyConsumption = 1.5; PassengerCount = 4; FaultRate = 5; 
                    break;

                case eVTOLCompany::BRAVO:
                    cruiseSpeed = 120; batteryCapacity = 120; TimetoCharge = 50; 
                    EnergyConsumption = 1.2; PassengerCount = 6; FaultRate = 4;
                    break;

                case eVTOLCompany::CHARLIE:
                    cruiseSpeed = 150; batteryCapacity = 150; TimetoCharge = 40; 
                    EnergyConsumption = 1.0; PassengerCount = 8; FaultRate = 3;
                    break;

                case eVTOLCompany::DELTA:
                    cruiseSpeed = 180; batteryCapacity = 180; TimetoCharge = 30; 
                    EnergyConsumption = 0.8; PassengerCount = 10; FaultRate = 2;
                    break;
                case eVTOLCompany::ECHO:
                    cruiseSpeed = 200; batteryCapacity = 200; TimetoCharge = 20; 
                    EnergyConsumption = 0.6; PassengerCount = 12; FaultRate = 1; 
                    break;

            }
            Model = model;
            state = eVTOLState::IDLE;
            avgFlightTime = 0;
            avgDistance = 0;
            avgChargeTime = 0;
            totalFaults = 0;
            passengerMiles = 0;
        }



        ~eVTOL()=default;
 
};



