#pragma once
#include "Aircraft.h"
#include "ChargingStation.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

//Function to generate 
std::vector<eVTOLCompany> Generate_eVTOL_Vehicles(int numVehicles){
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    std::vector<eVTOLCompany> eVTOL_IDs(numVehicles);
    for(int i = 0; i < numVehicles; i++){
        eVTOL_IDs[i] = static_cast<eVTOLCompany>(std::rand() % 5);
    }
    return eVTOL_IDs;
}


//function to write iteration results to a file
void Write_Results(int timeStamp ,int eVTOL_ID, eVTOL vehicleData){
    std::ofstream file;
    file.open("eVTOL_" + std::to_string(eVTOL_ID) + "_Results.txt");
    file << "eVTOL ID: " << eVTOL_ID << std::endl;
    file << "Average Flight Time: " << vehicleData.avgFlightTime << std::endl;
    file << "Average Distance: " << vehicleData.avgDistance << std::endl;
    file << "Average Charge Time: " << vehicleData.avgChargeTime << std::endl;
    file << "Total Faults: " << vehicleData.totalFaults << std::endl;
    file << "Passenger Miles: " << vehicleData.passengerMiles << std::endl;
    file.close();
}