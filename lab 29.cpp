// Necessary Headers for file handling, data structure, time, etc.

// A struct for a person
    // Contains name
    // Age
    // Infected or not

// A region struct
    // A list of people belonging to the region
    // Is it quarantined?
    // Are people wearing masks?

// Necessary function definitions

// A map associating a region the amount of people

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
// End main function


