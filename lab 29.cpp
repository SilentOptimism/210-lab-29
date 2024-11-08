// Necessary Headers for file handling, data structure, time, etc.
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>

using namespace std;

enum health{
    Healthy, // Hasn't been infected
    Infected, // Is infected
    Recovered, // Was infected now has recovered
    Dead // Sucumb to disease
};

struct person
{
    string name;
    int age;
    health condition;
    bool vaccinated; // if true person is vacinated
};

struct region
{
    list<person> population;
    double GDP;
    bool quarantined;
    bool masks;
};

map<string, region> populationCenters;

void makeRegion(string regionName){
    srand(time(NULL));

    ifstream fin;

    fin.open(regionName + "Census.txt");
    if(!fin){
        cout << "File open error" << endl;
        return;
    }

    string firstName;
    string lastName;
    int age;
    string condition;
    string vaccinated;

    while (!fin){
        fin >> firstName;
        cout << firstName;
        fin >> lastName;
        cout << lastName;
        fin >> age;
        cout << age;
        fin >> condition;
        cout << condition;
        fin >> vaccinated;
        cout << vaccinated;
    }

    fin.close();
}

// A function to start the infection
    // Each region's population file is open and has their region populated with people
    // An external file inputs information specific to that region
        // Pop density
        // Where the infection is started
        // Are people wearing masks
        // Are people quarantining
void infectionBegin(){
    
}

// A function to simulate infection spread in a specific region
    // Uses pop density/people wearing masks/people quarantining/already infected
    // To determine how many people are infected or cured
    // Determine time till vaccine
void timepass(){

}

// A function to simulate vaccine rollout
    // Based on a wealth and popularity vaccine rollout will be different for each region
void vaccineRollout(){

}

// print a regionsStats
void print(){

}

// Define a main function
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}


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


