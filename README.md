# 210-lab-29
My project creates an epidemic simulation, A program designed to predict the infection count of within an ecosystem over 365 days or one year. This software will illustrate the potential impact of wearing masks during an epidemic.

Implementation:
I plant to use std::map to store and manage a region which is a struct containing its basic info as are people wearing masks, is it quarantined, and each region will have a list of people structs which will provide a name, age, infected?, alive?. The map will store each region by name.

Simulated Events:
The simulation will focus on four events: initial infection, quarantine, vacine rollout, leaving quarantine. When a certain amount of infections get to high quarantine occurs, as time progresses eventually vacine's rollout, when a portion of the pop is vacinated quarantine ends.
