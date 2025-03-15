#include <queue>
#include <fstream>

enum class ChargingStationState{
    IDLE,
    BUSY
};

class ChargingStation{
public:
    std::queue<std::pair<int,float>> WaitingAircrafts;
    int StationID;
    float chargeTime;
    ChargingStationState state;
    int AircraftOnCharger;
    int waitTime;

    ChargingStation(int stationID){
        StationID = stationID;
        chargeTime = 0;
        state = ChargingStationState::IDLE;
        waitTime = 0;

    }

    int AddAircrafttoQueue(int eVTOL_ID, float chargeTime){
        WaitingAircrafts.push(std::make_pair(eVTOL_ID,chargeTime));
        waitTime += chargeTime;
        return StationID;
    }

    void ChargeAircraft(){
        if(WaitingAircrafts.empty()&& state == ChargingStationState::IDLE){
            return;
        }
        if(!WaitingAircrafts.empty()){
            if(state == ChargingStationState::IDLE){
                std::pair<int,float> aircraft = WaitingAircrafts.front();
                AircraftOnCharger = aircraft.first;
                chargeTime = aircraft.second;
                WaitingAircrafts.pop();
                state = ChargingStationState::BUSY;
            }
            chargeTime--;
            waitTime--;
            //std::cout<<"eVTOL "<<aircraft.first<<" is charging at station "<<StationID<<std::endl;
        }
        if(chargeTime <= 0){
            state = ChargingStationState::IDLE;
        }
    }

    void WriteChargerLog(int time){
        std::ofstream file;
        file.open("ChargerLog_Station"+std::to_string(StationID)+".txt",std::ios_base::app);
        file<<"Time: "<<time<<std::endl;
        file<<"State: "<<(state == ChargingStationState::IDLE ? "IDLE" : "BUSY")<<std::endl;
        file<<"Aircraft on Charger: "<<AircraftOnCharger<<std::endl;
        file<<"Number of Aircrafts in Queue: "<<WaitingAircrafts.size()<<std::endl;
        file<<"Wait Time: "<<waitTime<<" Minutes"<<std::endl;
        file<<"****************************************************"<<std::endl;
        file.close();
    }
    //Reports back which aircraft is currently charging
    int getAircraftOnCharger(){
        return AircraftOnCharger;
    }

    ~ChargingStation()=default;

};

//Create the three charging stations
ChargingStation stations[3] = {ChargingStation(0), ChargingStation(1), ChargingStation(2)};