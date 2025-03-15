# eVTOL_Simulation Overview
3-hour simulation of the operation of 20 eVTOL vehicles consisting of 5 different categories. Each type of vehicle has a unique set of characteristics such as, nominal cruise speed, Battery Capacity, and energy consumption per mile. 

The 20 aircrafts are randomly chosen from the set of 5 types and simulate the normal operation of the vehicle over a 3 hour period.

Normal operation of each vehicle consists of 4 states: IDLE, FLIGHT, WAITING FOR CHARGER, CHARGING.

Simulation data recording includes the following statistics for each vehicle type:

  * Average Flight time
  
  * Average Distance Traveled
  
  * Average Time Charging
  
  * Total number of faults
  
  * Total Passenger Miles

## Build Project and Run(UNIX)
```bash
./BuildandRun.sh
```

## Build Project and Run(Windows)
```bash
make
./run
```

## Testing and Data
Output of the simulation is written to individual text files for each of the vehicle types i.e "SimulationResults_ALPHA.txt" and the charger log for each station is also recorded.

eg: SimulationResults_BRAVO.txt
```
eVTOL ID: 8
eVTOL Type: BRAVO
Average Flight Time: 41 Minutes
Average Distance: 68.3333 Miles
Average Charge Time: 11 Minutes
Total Faults: 0
Passenger Miles: 683.333
Total Flights: 2
****************************************************

eVTOL ID: 12
eVTOL Type: BRAVO
Average Flight Time: 41 Minutes
Average Distance: 68.3333 Miles
Average Charge Time: 11 Minutes
Total Faults: 0
Passenger Miles: 683.333
Total Flights: 2
****************************************************

eVTOL ID: 14
eVTOL Type: BRAVO
Average Flight Time: 41 Minutes
Average Distance: 68.3333 Miles
Average Charge Time: 11 Minutes
Total Faults: 1
Passenger Miles: 683.333
Total Flights: 2
****************************************************

Overall Statistics:
Average Flight Time: 41 Minutes
Average Distance: 68.3333 Miles
Average Charge Time: 11 Minutes
Total Faults: 1
Passenger Miles: 2050


