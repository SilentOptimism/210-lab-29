// Necessary Headers for file handling, data structure, time, etc.
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>

using namespace std;


struct person
{
    string region;
    string name;
    int age;
    bool infected;
    bool vaccinated;
};

struct region
{
    list<person> population;
    bool quarantined;
    bool masks;
};



// Necessary function definitions

map<region, int> populationCenters;

void infectionBegin(){
    
}

// A function to start the infection
    // Each region's population file is open and has their region populated with people
    // An external file inputs information specific to that region
        // Pop density
        // Where the infection is started
        // Are people wearing masks
        // Are people quarantining

// A function to simulate infection spread in a specific region
    // Uses pop density/people wearing masks/people quarantining/already infected
    // To determine how many people are infected or cured
    // Determine time till vaccine

// A function to simulate vaccine rollout
    // Based on a wealth and popularity vaccine rollout will be different for each region

// print a regionsStats

// Define a main function

    // Initialize maps region
    // Initialize people to regions

    // Begin a time based simulation for infections
        // For 365 time intervals (1 day each interval)
            // Run infections
            // Every day print out the daily info in each region
                // If enough people in a region get infected people wear masks
                // If even more people in a region get infected people quarantine
                // Eventually a vaccine will be developed
                // If enough people are vacinated quarantine will end and region will be free
// End main function


