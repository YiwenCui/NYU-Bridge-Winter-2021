#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
const int ROW_RANGE = 20, COLUMN_RANGE = 20;
const int INITIAL_ANT_POPULATION = 100, INITIAL_DOODLEBUG_POPULATION = 5;
const int ANT_BREED_STEP = 3, DOODLEBUG_BREED_STEP = 8;
const int DOOLEBUG_STARVE_STEP = 3;
const char NONE = '-', ANT = 'o', DOODLEBUG = 'X';
const int MOVE_UP = 1, MOVE_DOWN = 2, MOVE_LEFT = 3, MOVE_RIGHT = 4;

class Organism
{
public:
    Organism()
    {
        this->species = "None";
        this->sym = '-';
    }
    Organism(string species)
    {
        this->species = species;
        if (species == "ANT")
        {
            this->sym = 'o';
        }
        else if (species == "DOODLEBUG")
        {
            this->sym = 'X';
        }
        else
        {
            this->sym = '-';
        }
    }
    string get_species() { return this->species; };
    char get_sym() { return this->sym; };
    void move();
    void breed();

private:
    string species;
    char sym;
};

class DoodleBug : public Organism
{
public:
    DoodleBug() : Organism("DOODLEBUG"){};
};

class Ant : public Organism
{
public:
    Ant() : Organism("ANT"){};
};

void printWorld(vector<vector<Organism> > world)
{
    for (int i = 0; i < ROW_RANGE; i++)
    {
        for (int j = 0; j < COLUMN_RANGE; j++)
        {
            cout << world[i][j].get_sym() << " ";
        }
        cout << endl;
    }
}
void createAWorld(vector<vector<Organism> > &world)
{
    // generate 100 ants at random place in the world
    srand(time(NULL));
    int randomX1 = rand() % 20;
    int randomY1 = rand() % 20;

    for (int i = 0; i < INITIAL_ANT_POPULATION; i++)
    {
        while (world[randomX1][randomY1].get_species() != "None")
        {
            randomX1 = rand() % 20;
            randomY1 = rand() % 20;
        }
        world[randomX1][randomY1] = Ant();
    }
    // generate 5 doodlebugs at random place in the world
    srand(time(NULL));
    int randomX2 = rand() % 20;
    int randomY2 = rand() % 20;

    for (int i = 0; i < INITIAL_DOODLEBUG_POPULATION; i++)
    {
        while (world[randomX2][randomY2].get_species() != "None")
        {
            randomX2 = rand() % 20;
            randomY2 = rand() % 20;
        }

        world[randomX2][randomY2] = DoodleBug();
    }
}

int main()
{
    vector<vector<Organism> > world;
    for (int i = 0; i < ROW_RANGE; ++i)
    {
        world.push_back(vector<Organism>());
    }
    for (int i = 0; i < ROW_RANGE; i++)
    {
        for (int j = 0; j < COLUMN_RANGE; j++)
        {
            world[i].push_back(Organism());
        }
    }

    createAWorld(world);
    printWorld(world);

    return 0;
}
