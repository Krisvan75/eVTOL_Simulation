#include <stdint.h>
#include <iostream>
#include <vector>
#include <map>
#include "eVTOL_Sim.h"
//#include "ChargingStation.h"
//#include "Aircraft.h"

#define NUM_EVTOLS 20
#define NUM__CHARGING_STATIONS 3
#define SimulationTime 180





int main(){
    int CurrentTime = 0;
    //Generate eVTOL vehicles
    std::vector<eVTOLCompany> eVTOL_IDs = Generate_eVTOL_Vehicles(NUM_EVTOLS);
    std::unordered_map<int, eVTOL> eVTOLs;
    for(int i=0; i<NUM_EVTOLS; i++){
        eVTOLs[i] = eVTOL(static_cast<eVTOLCompany>(eVTOL_IDs[i]));
    }

    //Start of Simulation loop, each iteration represents 1 minute
    while(CurrentTime < SimulationTime){
        
    }

    


    return 0;
}




