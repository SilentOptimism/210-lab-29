# 210-lab-29
My project creates an epidemic simulation, A program designed to predict the infection count of within an ecosystem over 2 months. This software will illustrate the potential impact of wearing masks during an epidemic and the effectivenes of vaccines.

Implementation:
I plant to use std::map to store and manage a region which is a struct containing its basic info as are people wearing masks, is it quarantined, and each region will have a list of people structs which will provide a name, age, infected?, alive?. The map will store each region by name.

Simulated Events:
The simulation will focus on four events: initial infection, quarantine, vacine rollout. When a certain amount of deaths occur a quarantine occurs and people start to wear masks, as time progresses eventually a vacine will rollout, when a there are no more infections qurantine/masks/program will end.
