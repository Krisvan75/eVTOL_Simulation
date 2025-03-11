

//enumeration for the different states of the eVTOL
enum eVTOLState {
    FLYING,
    WAITING_FOR_CHARGER,
    CHARGING
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
    public:
        //Attributes of the eVTOL
        int cruiseSpeed;
        int batteryCapacity;
        float TimetoCharge;
        float EnergyConsumption;
        int PassengerCount;
        int FaultRate;

        //eVTOL statistics
        float avgFlightTime;
        float avgDistance;
        float avgChargeTime;
        int totalFaults;
        int passengerMiles;    
    
        eVTOL(int speed, int capacity, int chargeTime, int energyConsumption, int passengerCount, int faultRate) {
            cruiseSpeed = speed;
            batteryCapacity = capacity;
            TimetoCharge = chargeTime;
            EnergyConsumption = energyConsumption;
            PassengerCount = passengerCount;
            FaultRate = faultRate;
        }
    
    };

    class Alpha: public eVTOL {
        public:
            Alpha(): eVTOL(120, 320, 36, 1.6, 4, 25) {}
    };
    class Bravo: public eVTOL {
        public:
            Bravo(): eVTOL(100, 100, 12, 1.5, 5, 10) {}
    };

    class Charlie: public eVTOL {
        public:
            Charlie(): eVTOL(160, 220, 48, 2.2, 3, 5) {}
    };

    class Delta: public eVTOL {
        public:
            Delta(): eVTOL(90, 120, 37.2, 0.8, 2, 22) {}
    };

    class Echo: public eVTOL {
        public:
            Echo(): eVTOL(30, 150, 18, 5.8, 2, 61) {}
    };
