// Necessary Headers for file handling, data structure, time, etc.
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace chrono;

int day = 0;

enum health{
    Healthy = 0, // Hasn't been infected
    Infected = 1, // Is infected
    Recovered = 2, // Was infected now has recovered
    Dead = 3// Sucumb to disease
};

struct person
{
    string name;
    int age = 0;
    health condition;
    bool vaccinated; // if true person is vacinated
    int timeInfected = 0;
};

struct region
{
    list<person> residents;
    double GDP;
    int healthy = 0;
    int infected = 0;
    int dead = 0;
    int vaccinated = 0;
    int recovered = 0;
    bool quarantined = 0;
    bool masks = false;
};

map<string, region> regions;

region populate_region(string regionName){
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

        if(fin){
            resident.name = firstName + lastName;
            resident.age = age;

            if(condition == "Healthy") {location.healthy++; resident.condition = Healthy;}
            if(condition == "Infected") {location.infected++; resident.condition = Infected;}
            if(condition == "Recovered") {location.recovered++; resident.condition = Recovered;}
            if(condition == "Dead") {location.dead++; resident.condition = Dead;}

            if(vaccinated == "False") {resident.vaccinated = false;}
            else {resident.vaccinated = true;}

            location.residents.push_back(resident);
        }
    }

    fin.close();
    return location;
}

// A function to start the infection
    // An external file inputs information specific to that region
        // Are people wearing masks
        // Are people quarantining
void spread_infection(string regionName){
    double lethalityRate = 2.5;
    region& place = regions[regionName];

    // Iterates through every individual on the region
    for(person& individual: place.residents){

        // If vaccinated, dead, recovered exit cycle        
        if(individual.vaccinated){return;};
        if(individual.condition == Recovered){return;};


        //If a person has been sick for 14 days they will have recovered
        /*
        if(individual.timeInfected >= 3){
            individual.condition = Recovered;
            place.recovered++;
            place.infected-=1;
        }
        */



        if(individual.condition == Infected){
            individual.timeInfected++;

            if(rand()%100 < 10){
                individual.condition = Dead;

                place.dead++;
                place.infected--;
            }
        }
        // If not infected checks if they will become infected
        if(individual.condition == Healthy){
            if(rand()%50 < 25){ 
                individual.condition = Infected;
                place.healthy--;
                place.infected++;
            }
        }
    }
}

// A function to simulate vaccine rollout
    // Based on a wealth and popularity vaccine rollout will be different for each region
void vaccineRollout(){
    map<string,region>::iterator current = regions.begin();
    map<string,region>::iterator end = regions.end();

    while(end != current){
        region &place = current->second; 

        for(person& individual: place.residents){
            if(rand()%10<5){
                if(individual.vaccinated == false){
                    place.vaccinated++;
                }
                individual.vaccinated = true;
            }
        }
        current++;
    }
}

// print a regionsStats
void print(){
    int width = 15;
    map<string,region>::iterator current = regions.begin();
    map<string,region>::iterator end = regions.end();

    cout << "Day " << day << endl;
    cout << setw(width);
    cout << "Region Name";
    cout << setw(width);
    cout << "Healthy";
    cout << setw(width);
    cout << "Infected";
    cout << setw(width);
    cout << "Dead"; 
    cout << setw(width);
    cout << "Vaccinated";
    cout << setw(width);
    cout << "Recovered";
    cout << setw(width);
    cout << "Quarantine";
    cout << setw(width);
    cout << "Mask Wearing";

    cout << "\n";


    while(current != end){
        cout << setw(width);
        cout << current->first;
        cout << setw(width);
        cout << current->second.healthy;
        cout << setw(width);
        cout << current->second.infected;
        cout << setw(width);
        cout << current->second.dead;
        cout << setw(width);
        cout << current->second.vaccinated;
        cout << setw(width);
        cout << current->second.recovered;
        cout << setw(width);

        if(current->second.quarantined == true){ cout << "Qurantined";}
        else {cout << "None";}
        cout << setw(width);

        cout << current->second.masks;
        cout << "\n";

        current++;
    }
}

// Define a main function
int main(int argc, char const *argv[])
{
    srand(time(NULL));
    regions["Aethria"] = populate_region("Aethria");
    regions["Elysia"] = populate_region("Elysia");
    regions["Kaelan"] = populate_region("Kaelan");
    regions["Nova"] = populate_region("Nova");
    regions["Zephyr"] = populate_region("Zephyr");

    print();


    time_point start = high_resolution_clock::now();
    while(day < 180){
        time_point now = high_resolution_clock::now();

        milliseconds duration = duration_cast<milliseconds>(now - start);
        
        if(duration.count() > 500){
            start = high_resolution_clock::now();
            spread_infection("Aethria");
            spread_infection("Elysia");
            spread_infection("Kaelan");
            spread_infection("Nova");
            spread_infection("Zephyr");
            if(day >= 90){
                vaccineRollout();
            }
            day++;
            print();
        }
    }

    return 0;
}
