# eVTOL_Simulation
3-hour simulation of the operation of 20 eVTOL vehicles.

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

eg:
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


