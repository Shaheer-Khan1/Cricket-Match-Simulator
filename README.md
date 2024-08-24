# Cricket Match Simulator

## Overview
This is a Cricket Match Simulator created as part of the **Programming Fundamentals** course project for Spring 2022. The simulator is designed to replicate a cricket match between two teams, each consisting of 11 players. The simulation covers various aspects of a cricket match, including batting, bowling, scoring, and match summary, utilizing arrays and random functions.

## Features
- **Team Creation:** Two teams of 11 players each are created using 1D/2D/3D arrays.
- **Toss Simulation:** A random function determines which team wins the toss and bats first.
- **Scoreboard Updates:** A live scoreboard updates after each ball, showing the current score, overs, run rate, and more.
- **Batting Mechanics:** Batsmen's chances of getting out and scoring are simulated based on predefined probabilities.
- **Bowling Mechanics:** Bowlers are assigned overs, with the last five players of the team being designated as bowlers.
- **Match Progression:** The match is played over a user-defined number of overs, with each ball being bowled by pressing the ENTER key.
- **Innings:** The match includes two innings, with the second innings having additional details such as the target score, required run rate, etc.
- **Result Declaration:** At the end of the match, the batsman with the highest runs and the bowler with the most wickets are declared as the best performers. The winning team is also announced.
- **Match Data:** The match data can be saved to a file and loaded later for review.
- **Error Handling:** The program includes robust error handling to ensure smooth execution.

## How to Run
1. Clone the repository to your local machine.
2. Compile the code using a C++ compiler.
3. Run the executable.
4. Follow the on-screen instructions to simulate the match.
5. The configuration for the number of overs is read from a `configuration.txt` file.

## Configuration
- The number of overs for the match can be configured through the `configuration.txt` file.
- Ensure that the configuration file is in the same directory as the executable.

## Key Functionalities
- **Live Scoreboard:** Keeps track of the match in real-time.
- **Match Summary:** Provides a detailed summary at the end of the match.
- **File Handling:** Saves and loads match data for later review.

## Restrictions
- No global variables are used.
- Only programming constructs taught during the course were used.
- The project is original and does not include any code copied from the internet or peers.

## Project Structure
- `main.cpp`: Contains the main code for the cricket match simulator.
- `configuration.txt`: Configuration file for setting the number of overs.
- `README.md`: This file.
