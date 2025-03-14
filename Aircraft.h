#include<cmath>
#include <iostream>
#include <random>
#include "ChargingStation.h"

//eVTOL State Machine
enum class eVTOLState {
    IDLE,
    FLYING,
    WAITING_FOR_CHARGER,
    CHARGING
};


//Vehicle Types
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
        float cruiseSpeed;
        int batteryCapacity;
        float TimetoCharge;
        float EnergyConsumption;
        int PassengerCount;
        float FaultRate;


public:  
        //eVTOL statistics
        int eVTOL_ID;
        float avgFlightTime;
        float avgDistance;
        float avgChargeTime;
        int totalFaults;
        float passengerMiles;
        int TotalFlights;
        eVTOLState state;
        eVTOLCompany Model;

        //variables to keep track of the current flight
        float currentdistance, energyConsumed;
        int currentFlightTime;
        float SOC;
        int assignedCharger;


        eVTOL()=default;
  
    
        void ClassifyeVTOL(eVTOLCompany model, int EVTOL_ID){

            switch(model){
                case eVTOLCompany::ALPHA:
                    cruiseSpeed = 120; batteryCapacity = 320; TimetoCharge = 36; 
                    EnergyConsumption = 1.6; PassengerCount = 4; FaultRate = 0.25; 
                    break;

                case eVTOLCompany::BRAVO:
                    cruiseSpeed = 100; batteryCapacity = 100; TimetoCharge = 12; 
                    EnergyConsumption = 1.5; PassengerCount = 5; FaultRate = 0.10;
                    break;

                case eVTOLCompany::CHARLIE:
                    cruiseSpeed = 160; batteryCapacity = 220; TimetoCharge = 48; 
                    EnergyConsumption = 2.2; PassengerCount = 3; FaultRate = 0.05;
                    break;

                case eVTOLCompany::DELTA:
                    cruiseSpeed = 90; batteryCapacity = 120; TimetoCharge = 37.2; 
                    EnergyConsumption = 0.8; PassengerCount = 2; FaultRate = 0.22;
                    break;

                case eVTOLCompany::ECHO:
                    cruiseSpeed = 30; batteryCapacity = 150; TimetoCharge = 18; 
                    EnergyConsumption = 5.8; PassengerCount = 2; FaultRate = 0.61; 
                    break;

            }
            Model = model;
            state = eVTOLState::IDLE;
            eVTOL_ID = EVTOL_ID;
            SOC = batteryCapacity;
            avgFlightTime = 0;
            avgDistance = 0;
            avgChargeTime = 0;
            totalFaults = 0;
            passengerMiles = 0;
            TotalFlights = 0;
        }

        eVTOLState SimulateFlight(int SimTime){
            /*TODO:
                Fault model that has different severity levels
                P0: Most Critical Fault(Last-Man Standing) - eVTOL is grounded for remainder of simulation
                P1: Critical Fault - 5 faults to trigger aircraft being grounded
                P2: Moderate Fault - Just keep track of the number of faults
            
            */
            if(FaultTriggered())
                totalFaults++;
            
            switch(state){
                case eVTOLState::IDLE:
                    state = eVTOLState::FLYING;
                    TotalFlights++;
                    break;

                case eVTOLState::FLYING:
                    
                    if(SOC>=0){
                        Cruise();
                    }
                    else{

                        state = eVTOLState::WAITING_FOR_CHARGER;
                        assignedCharger = FindCharger(eVTOL_ID);
                        //std::cout<<"eVTOL "<<eVTOL_ID<<" is waiting for charger "<<assignedCharger<<std::endl;

                    }
                    break;

                case eVTOLState::WAITING_FOR_CHARGER:
                    if(stations[assignedCharger].getAircraftOnCharger() == eVTOL_ID){
                        state = eVTOLState::CHARGING;
                    }
                    break;
                case eVTOLState::CHARGING:
                    if(stations[assignedCharger].getAircraftOnCharger() != eVTOL_ID || stations[assignedCharger].state == ChargingStationState::IDLE){
                        SOC = batteryCapacity;
                        state = eVTOLState::IDLE;
                    }
                    
                    break;
            }
            return state;
        }
        bool FaultTriggered(){
            double faultProbPerMin = 1.0 - std::pow(1.0 - FaultRate, 1.0/60.0);
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<double> dist(0.0, 1.0);
            if(dist(gen) < faultProbPerMin){
                return true;
            }
            return false;
        }

        int FindCharger(int ID){
            //Pick charger with the least number of waiting aircrafts
            //TODO: Algorithm to take into account the total charge time of aircrafts in the queue to optimize assigning a charger
            int chargerA = stations[0].WaitingAircrafts.size();
            int chargerB = stations[1].WaitingAircrafts.size();
            int chargerC = stations[2].WaitingAircrafts.size();
            int charger = chargerA<chargerB ? 
            (chargerA<chargerC ? stations[0].AddAircrafttoQueue(ID, TimetoCharge) : stations[2].AddAircrafttoQueue(ID, TimetoCharge)) : 
            (chargerB<chargerC ? stations[1].AddAircrafttoQueue(ID, TimetoCharge) : stations[2].AddAircrafttoQueue(ID, TimetoCharge));
            return charger;
        }

        void Cruise(){
            float CruiseDist = cruiseSpeed/60.0;
            avgDistance += CruiseDist; 
            //std::cout<<"eVTOL "<<eVTOL_ID<<" is cruising at "<<cruiseSpeed<<" mph\t"<<"Distance: "<<avgDistance<<std::endl;
            energyConsumed += static_cast<float>(EnergyConsumption*CruiseDist);
            SOC -= EnergyConsumption*CruiseDist;
            //std::cout<<"eVTOL "<<eVTOL_ID<<" has "<<SOC<<" SOC"<<std::endl;
            passengerMiles += PassengerCount*CruiseDist; 
            avgFlightTime++;
        }

        ~eVTOL()=default;
 
};



