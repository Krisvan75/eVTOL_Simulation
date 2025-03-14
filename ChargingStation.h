#include <queue>
#include <iostream>

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

    ChargingStation(int stationID){
        StationID = stationID;
        chargeTime = 0;
        state = ChargingStationState::IDLE;

    }

    int AddAircrafttoQueue(int eVTOL_ID, float chargeTime){
        WaitingAircrafts.push(std::make_pair(eVTOL_ID,chargeTime));
        return StationID;
    }

    void ChargeAircraft(){
        if(WaitingAircrafts.empty()&& state == ChargingStationState::IDLE){
            return;
        }
        if(!WaitingAircrafts.empty() && state == ChargingStationState::IDLE){
            std::pair<int,float> aircraft = WaitingAircrafts.front();
            AircraftOnCharger = aircraft.first;
            chargeTime = aircraft.second;
            WaitingAircrafts.pop();
            state = ChargingStationState::BUSY;
            chargeTime--;
            std::cout<<"eVTOL "<<aircraft.first<<" is charging at station "<<StationID<<std::endl;
        }
        if(state==ChargingStationState::BUSY){
            chargeTime--;
            std::cout<<"eVTOL "<<AircraftOnCharger<<" is charging at station "<<StationID<<std::endl;
            std::cout<<"Charge Time Remaining: "<<chargeTime<<std::endl;
        }
        if(chargeTime <= 0){
            state = ChargingStationState::IDLE;
        }
    }

    int getAircraftOnCharger(){
        return AircraftOnCharger;

    }

};

//Create the three charging stations
ChargingStation stations[3] = {ChargingStation(0), ChargingStation(1), ChargingStation(2)};