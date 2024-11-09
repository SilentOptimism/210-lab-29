// Necessary Headers for file handling, data structure, time, etc.
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <chrono>

using namespace std;
using namespace chrono;

int day = 0;

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
    list<person> residents;
    double GDP;
    int population;
    int infected;
    int dead;
    bool quarantined;
    bool masks;
};

map<string, region> regions;

region populate_region(string regionName){
    srand(time(NULL));
    region location;

    ifstream fin;
    fin.open(regionName + "Census.txt");

    if(!fin) {
        cout << "File open error" << endl;
    }

    string firstName;
    string lastName;
    int age;
    string condition;
    string vaccinated;

    location.masks = false;
    location.quarantined = false;

    while (fin){
        person resident;
        fin >> firstName;
        fin >> lastName;
        fin >> age;
        fin >> condition;
        fin >> vaccinated;

        resident.name = firstName + lastName;
        resident.age = age;

        if(condition == "Healthy") {resident.condition = Healthy;}
        if(condition == "Infected") {resident.condition = Infected;}
        if(condition == "Recovered") {resident.condition = Recovered;}
        if(condition == "Dead") {resident.condition = Dead;}

        if(vaccinated == "False") {resident.vaccinated = false;}
        else {resident.vaccinated = true;}

        location.population++;
        location.residents.push_back(resident);
    }

    fin.close();
    return location;
}

// A function to start the infection
    // Each region's population file is open and has their region populated with people
    // An external file inputs information specific to that region
        // Pop density
        // Where the infection is started
        // Are people wearing masks
        // Are people quarantining
void spread_infection(string regionName){
    region& place = regions[regionName];

    for(person& individual: place.residents){
        if(individual.vaccinated == true){}
        else if(rand()%50 < 1){ 
            if(individual.condition = Infected) {
                individual.condition = Dead;
                place.dead++;
            }
            else {
                individual.condition = Infected;
                place.infected++;
            }
        }
    }
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
    regions["Aethria"] = populate_region("Aethria");
    regions["Elysia"] = populate_region("Elysia");
    regions["Kaelan"] = populate_region("Kaelan");
    regions["Nova"] = populate_region("Nova");
    regions["Zephyr"] = populate_region("Zephyr");


    auto start = chrono::high_resolution_clock::now();
    while(true){
        auto now = chrono::high_resolution_clock::now();

        if(duration_cast<seconds>(now - start))

    }


    }






    cout << regions["Aethria"].population << endl;
    cout << regions["Elysia"].population << endl;
    cout << regions["Kaelan"].population << endl;
    cout << regions["Nova"].population << endl;
    cout << regions["Zephyr"].population << endl;



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


