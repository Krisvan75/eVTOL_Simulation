#pragma once
#include "Aircraft.h"
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

