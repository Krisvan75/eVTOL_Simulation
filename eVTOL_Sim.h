#pragma once
#include "Aircraft.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_map>

std::unordered_map<int,std::string> eVTOL_Translate = {
    {0,"ALPHA"},
    {1,"BRAVO"},
    {2,"CHARLIE"},
    {3,"DELTA"},
    {4,"ECHO"}
};

std::unordered_map<int,std::string> eVTOLState_Translate = {
    {0,"IDLE"},
    {1,"FLYING"},
    {2,"WAITING_FOR_CHARGER"},
    {3,"CHARGING"}
};

//Function to generate 
std::vector<eVTOLCompany> Generate_eVTOL_Vehicles(int numVehicles){
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::vector<eVTOLCompany> eVTOL_IDs(numVehicles);
    for(int i = 0; i < numVehicles; i++){
        eVTOL_IDs[i] = static_cast<eVTOLCompany>(std::rand() % 5);
    }
    return eVTOL_IDs;
}

//function to write the simulation results to a file
void WriteResultsToFile(std::unordered_map<int,eVTOL> eVTOLs){
    std::ofstream file;
    file.open("SimulationResults.txt");
    for(auto ele : eVTOLs){
        file<<"eVTOL ID: "<<ele.first<<std::endl;
        file<<"eVTOL Type: "<<eVTOL_Translate[static_cast<int>(ele.second.Model)]<<std::endl;
        file<<"Average Flight Time: "<<ele.second.avgFlightTime<<std::endl;
        file<<"Average Distance: "<<ele.second.avgDistance<<std::endl;
        file<<"Average Charge Time: "<<ele.second.avgChargeTime<<std::endl;
        file<<"Total Faults: "<<ele.second.totalFaults<<std::endl;
        file<<"Passenger Miles: "<<ele.second.passengerMiles<<std::endl;
        file<<"Total Flights: "<<ele.second.TotalFlights<<std::endl;
        file<<std::endl;
    }
    file.close();
}

//function to write sim log per minute for each eVTOL 
void WriteSimLog(eVTOL vehicle, int time){
    std::ofstream file;
    file.open("SimulationLog_eVTOL"+std::to_string(vehicle.eVTOL_ID)+".txt",std::ios_base::app);
    file<<"Time: "<<time<<std::endl;
    file<<"eVTOL Make: "<<eVTOL_Translate[static_cast<int>(vehicle.Model)]<<std::endl;
    file<<"State: "<<eVTOLState_Translate[static_cast<int>(vehicle.state)]<<std::endl;
    file<<"****************************************************"<<std::endl;
    file.close();
}

//function to write charger Log


