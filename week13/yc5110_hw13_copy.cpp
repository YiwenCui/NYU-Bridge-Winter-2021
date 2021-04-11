#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int LINE_RANGE = 20, COLUMN_RANGE = 20;
const int INITIAL_ANT_POPULATION = 100, INITIAL_DOODLEBUG_POPULATION = 5;
const int ANT_BREED_STEP = 3, DOODLEBUG_BREED_STEP = 8;
const int DOOLEBUG_STARVE_STEP = 3;
const char NONE = '-', ANT = 'o', DOODLEBUG = 'X';

class Organism
{
public:
    void move();
    void breed();

    Organism(string species, int line, int column)
    {
        this->species = species;
        this->line = line;
        this->column = column;
    }

private:
    string species;
    int line;
    int column;
};

// class Ants
// {
// public:
//     void beEaten();
//     void move();
//     void breed();
// };

// class DoodleBugs
// {
// public:
//     void eatAnts();
//     void starve();
// };
void createAWorld(char world[][COLUMN_RANGE]);

int main()
{
    char world[LINE_RANGE][COLUMN_RANGE];
    
    createAWorld(world);
    // print the world
    for (int i = 0; i < LINE_RANGE; i++)
    {
        for (int j = 0; j < COLUMN_RANGE; j++)
        {
            cout << world[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}

void createAWorld(char world[][COLUMN_RANGE]){
    //generate an empty world
    for (int i = 0; i < LINE_RANGE; i++)
    {
        for (int j = 0; j < COLUMN_RANGE; j++)
        {
            world[i][j] = NONE;
        }
    }
    // generate 100 ants at random place in the world
    srand(time(NULL));
    int randomX1 = rand() % 20 + 1;
    int randomY1 = rand() % 20 + 1;

    for (int i = 0; i < INITIAL_ANT_POPULATION; i++)
    {
        while (world[randomX1][randomY1] != NONE)
        {
            randomX1 = rand() % 20 + 1;
            randomY1 = rand() % 20 + 1;
        }
        
        world[randomX1][randomY1] = ANT;
        
    }
    // generate 5 doodlebugs at random place in the world
    srand(time(NULL));
    int randomX2 = rand() % 20 + 1;
    int randomY2 = rand() % 20 + 1;

    for (int i = 0; i < INITIAL_DOODLEBUG_POPULATION; i++)
    {
        while (world[randomX2][randomY2] != NONE)
        {
            randomX2 = rand() % 20 + 1;
            randomY2 = rand() % 20 + 1;
        }
        
        world[randomX2][randomY2] = DOODLEBUG;        
    }
}