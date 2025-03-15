#include <stdint.h>
#include <iostream>
#include <vector>
#include <map>
#include "eVTOL_Sim.h"


//Made the number of eVTOLs dynamic if needed to changed number of eVTOLs in the simulation
#define NUM_EVTOLS 20

//Simulation time in minutes for simplicity, Will be changed to use a real-time clock in the future with an acceleration factor
#define SIMULATION_TIME 180



int main(){
    int CurrentTime = 0;
    //Generate eVTOL vehicles
    std::vector<eVTOLCompany> eVTOL_IDs = Generate_eVTOL_Vehicles(NUM_EVTOLS);
    std::unordered_map<int, eVTOL> eVTOLs;

    //Hashmap to link all IDs to eVTOL types for Post-Simulation Analysis
    std::unordered_map<eVTOLCompany,std::vector<int>> eVTOL_MasterList;

    for(int i=0; i<NUM_EVTOLS; i++){
        eVTOL_MasterList[eVTOL_IDs[i]].push_back(i);
        eVTOLs[i].ClassifyeVTOL(static_cast<eVTOLCompany>(eVTOL_IDs[i]),i);
    }

    //Start of Simulation loop, each iteration represents 1 minute
    while(CurrentTime < SIMULATION_TIME){
        //std::cout<<"Time: "<<CurrentTime<<std::endl;
        for(int i=0; i<NUM_EVTOLS; i++){
            eVTOLState out = eVTOLs[i].SimulateFlight(CurrentTime);
            //WriteSimLog(eVTOLs[i],CurrentTime);
        }
        for(int i=0; i<3; i++){
            stations[i].ChargeAircraft();
            stations[i].WriteChargerLog(CurrentTime);
        }
        CurrentTime++;
    }

    //End of Simulation loop, reporting results
    WriteResultsToFile(eVTOLs);

    for(auto vehicleType : eVTOL_MasterList){
        float OverallAvgFlightTime=0;
        float OverallAvgDistance=0;
        float OverallAvgChargeTime=0;
        int TotalFaults=0;
        float OverallPassengerMiles=0;
        for(auto ID : vehicleType.second){
            OverallAvgFlightTime += (eVTOLs[ID].avgFlightTime/eVTOLs[ID].TotalFlights)/vehicleType.second.size();
            OverallAvgDistance += (eVTOLs[ID].avgDistance/eVTOLs[ID].TotalFlights)/vehicleType.second.size();
            OverallAvgChargeTime += (eVTOLs[ID].avgChargeTime/eVTOLs[ID].ChargingSessions)/vehicleType.second.size();
            TotalFaults += eVTOLs[ID].totalFaults;
            OverallPassengerMiles += eVTOLs[ID].passengerMiles;
        }
        WriteOverallData(static_cast<int>(vehicleType.first),OverallAvgFlightTime,OverallAvgDistance,OverallAvgChargeTime,TotalFaults,OverallPassengerMiles);

    }

    return 0;
}




