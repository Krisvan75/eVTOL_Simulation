#include <stdint.h>
#include <iostream>
#include <vector>
#include <map>
#include "eVTOL_Sim.h"


#define NUM_EVTOLS 20
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
        std::cout<<"Time: "<<CurrentTime<<std::endl;
        for(int i=0; i<NUM_EVTOLS; i++){
            eVTOLState out = eVTOLs[i].SimulateFlight(CurrentTime);
            if(i==0)
                std::cout<<"eVTOL ID: "<<i<<" State: "<<static_cast<int>(out)<<"\tDist:"<<eVTOLs[i].avgFlightTime<<std::endl;
        }
        CurrentTime++;
    }


    return 0;
}




