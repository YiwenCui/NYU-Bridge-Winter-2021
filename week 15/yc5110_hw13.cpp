#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
const int ROW_RANGE = 20, COLUMN_RANGE = 20;
// const int ROW_RANGE = 5, COLUMN_RANGE = 5;
const int INITIAL_ANT_POPULATION = 100, INITIAL_DOODLEBUG_POPULATION = 5;
// const int INITIAL_ANT_POPULATION = 1, INITIAL_DOODLEBUG_POPULATION = 2;
const int ANT_BREED_STEP = 3, DOODLEBUG_BREED_STEP = 8;
const int DOOLEBUG_STARVE_STEP = 3;
const char NONE = '-', ANT = 'o', DOODLEBUG = 'X';
const int MOVE_UP = 1, MOVE_DOWN = 2, MOVE_LEFT = 3, MOVE_RIGHT = 4;

class Organism
{
public:
    Organism(int i, int j)
    {
        
        this->species = "NONE";
        this->sym = '-';
        this->starveStep = 0;
        this->i=i;
        this->j=j;
        this->breedStep=0;
    }
    Organism(string species,int i, int j)
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
        this->i=i;
        this->j=j;
        this->breedStep=0;
        this->starveStep = 0;
    }
    int starveStep;
    int breedStep;
    string get_species() { return this->species; };
    char get_sym() { return this->sym; };
    virtual void move(int i, int j, vector<vector<Organism *> > &world) {};
    virtual void breed(vector<vector<Organism *> > &world){};
    virtual void starve(vector<vector<Organism *> > &world) {};
    void set_location(int i,int j){this->i =i; this->j = j;};
    int i;
    int j;

private:
    string species;
    char sym;

    
};

class DoodleBug : public Organism
{
public:
    DoodleBug(int i, int j) : Organism("DOODLEBUG", i,j){};
    void starve(vector<vector<Organism *> > &world);
    void breed(vector<vector<Organism *> > &world);
    void move(int i, int j, vector<vector<Organism *> > &world);
};

class Ant : public Organism
{
public:
    Ant(int i, int j) : Organism("ANT", i, j){};
    void move(int i, int j, vector<vector<Organism *> > &world);
    void breed(vector<vector<Organism *> > &world);
};

void DoodleBug::starve(vector<vector<Organism *> > &world){
    if (this->starveStep>=3){
        world[this->i][this->j]=new Organism(this->i,this->j);
    }
}
void Ant:: breed(vector<vector<Organism *> > &world){
    vector<int> slot;
    if (this->breedStep != 0 && this->breedStep % ANT_BREED_STEP == 0)
    {
        if (this->i - 1 >= 0)
        {
            if (world[this->i - 1][this->j]->get_species() == "NONE")
            {
                slot.push_back(MOVE_UP);
            }
        }
        if (this->i + 1<= ROW_RANGE-1)
        {
            if (world[this->i + 1][this->j]->get_species() == "NONE")
            {
                slot.push_back(MOVE_DOWN);
            }
        }
        if (this->j - 1 >= 0)
        {
            if (world[this->i][this->j-1]->get_species() == "NONE")
            {
                slot.push_back(MOVE_LEFT);
            }
        }
        if (this->j + 1 <= COLUMN_RANGE-1)
        {
            if (world[this->i][this->j+1]->get_species() == "NONE")
            {
                slot.push_back(MOVE_RIGHT);
            }
        }

        if (slot.size() != 0) {
            srand(time(NULL));
            int random = rand() % slot.size();

            if (slot[random] == MOVE_UP)
            {
                world[this->i - 1][this->j] = new Ant(this->i - 1, this->j);
            }
            else if (slot[random] == MOVE_DOWN)
            {
                world[this->i + 1][this->j] = new Ant(this->i + 1, this->j);
            }
            else if (slot[random] == MOVE_LEFT)
            {
                world[this->i][this->j-1] = new Ant(this->i, this->j-1);
            }
            else if (slot[random] == MOVE_RIGHT)
            {
                world[this->i ][this->j+1] = new Ant(this->i, this->j+1);
            }
        }
    }

}

void DoodleBug:: breed(vector<vector<Organism *> > &world){
    vector<int> slot;
    if (this->breedStep != 0 && this->breedStep % DOODLEBUG_BREED_STEP == 0 )
    {
        if (this->i - 1 >= 0)
        {
            if (world[this->i - 1][this->j]->get_species() == "NONE")
            {
                slot.push_back(MOVE_UP);
            }
        }
        if (this->i + 1<= ROW_RANGE-1)
        {
            if (world[this->i + 1][this->j]->get_species() == "NONE")
            {
                slot.push_back(MOVE_DOWN);
            }
        }
        if (this->j - 1 >= 0)
        {
            if (world[this->i][this->j-1]->get_species() == "NONE")
            {
                slot.push_back(MOVE_LEFT);
            }
        }
        if (this->j + 1 <= COLUMN_RANGE-1)
        {
            if (world[this->i][this->j+1]->get_species() == "NONE")
            {
                slot.push_back(MOVE_RIGHT);
            }
        }
        if (slot.size() != 0)
        {
            srand(time(NULL));
            int random = rand() % slot.size();

            if (slot[random] == MOVE_UP)
            {
                world[this->i - 1][this->j] = new DoodleBug(this->i - 1, this->j);
            }
            else if (slot[random] == MOVE_DOWN)
            {
                world[this->i + 1][this->j] = new DoodleBug(this->i + 1, this->j);
            }
            else if (slot[random] == MOVE_LEFT)
            {
                world[this->i][this->j - 1] = new DoodleBug(this->i, this->j - 1);
            }
            else if (slot[random] == MOVE_RIGHT)
            {
                world[this->i][this->j + 1] = new DoodleBug(this->i, this->j + 1);
            }
        }
    }

}
void DoodleBug::move(int i, int j, vector<vector<Organism *> > &world)
{
    vector<int> antLocation;
    vector<int> emptyLocation;
    
    //check up position
    if (i - 1 >= 0)
    {
        if (world[i - 1][j]->get_species() == "ANT")
        {
            antLocation.push_back(MOVE_UP);
        }
        else if (world[i - 1][j]->get_species() == "NONE")
        {
            emptyLocation.push_back(MOVE_UP);
        }
    }
    //check down position
    if (i + 1 <= ROW_RANGE-1)
    {
        if (world[i + 1][j]->get_species() == "ANT")
        {
            antLocation.push_back(MOVE_DOWN);
        }
        else if (world[i + 1][j]->get_species() == "NONE")
        {
            emptyLocation.push_back(MOVE_DOWN);
        }
    }
    //check left position
    if (j - 1 >= 0)
    {
        if (world[i][j - 1]->get_species() == "ANT")
        {
            antLocation.push_back(MOVE_LEFT);
        }
        else if (world[i][j - 1]->get_species() == "NONE")
        {
            emptyLocation.push_back(MOVE_LEFT);
        }
    }
    //check right position
    if (j + 1 <=COLUMN_RANGE-1)
    {
        if (world[i][j + 1]->get_species() == "ANT")
        {
            antLocation.push_back(MOVE_RIGHT);
        }
        else if (world[i][j + 1]->get_species() == "NONE")
        {
            emptyLocation.push_back(MOVE_RIGHT);
        }
    }
    
    if (antLocation.size() != 0)
    {
        this->starveStep =0;
        srand(time(NULL));
        int random = rand() % antLocation.size();
        if (antLocation[random] == MOVE_UP)
        {
            world[i - 1][j] = world[i][j];
            world[i - 1][j]->set_location(i - 1, j);
        }
        else if (antLocation[random] == MOVE_DOWN)
        {
            world[i + 1][j] = world[i][j];
            world[i + 1][j]->set_location(i + 1, j);
        }
        else if (antLocation[random] == MOVE_LEFT)
        {
            world[i][j - 1] = world[i][j];
            world[i][j - 1]->set_location(i, j - 1);
        }
        else if (antLocation[random] == MOVE_RIGHT)
        {
            world[i][j + 1] = world[i][j];
            world[i][j + 1]->set_location(i, j + 1);
        }
        world[i][j] = new Organism(i, j);
    }

    else if (antLocation.size() == 0 && emptyLocation.size() != 0)
    {
        srand(time(NULL));
        int random = rand() % emptyLocation.size();

        if (emptyLocation[random] == MOVE_UP)
        {
            world[i - 1][j] = world[i][j] ;
            world[i - 1][j]->set_location(i - 1, j);
        }
        else if (emptyLocation[random] == MOVE_DOWN)
        {
            world[i + 1][j] = world[i][j] ;           
            world[i + 1][j]->set_location(i + 1, j);
        }
        else if (emptyLocation[random] == MOVE_LEFT)
        {   
            world[i][j-1] = world[i][j] ;       
            world[i][j - 1]->set_location(i, j - 1);
        }
        else if (emptyLocation[random] == MOVE_RIGHT)
        {
            world[i][j+1] = world[i][j] ;   
            world[i][j + 1]->set_location(i, j + 1);
        }
        world[i][j] = new Organism(i,j);
    }
    this->starveStep+=1;
    this->breedStep+=1;
}
void Ant::move(int i, int j, vector<vector<Organism *> > &world)
{
    vector<int> emptyLocation;
    
    //check up position
    if (i - 1 >= 0)
    {
        if (world[i - 1][j]->get_species() == "NONE")
        {
            emptyLocation.push_back(MOVE_UP);
        }
    }
    //check down position
    if (i + 1 <= ROW_RANGE-1)
    {       
        if (world[i + 1][j]->get_species() == "NONE")
        {
            emptyLocation.push_back(MOVE_DOWN);
        }
    }
    //check left position
    if (j - 1 >= 0)
    {
        if (world[i][j - 1]->get_species() == "NONE")
        {
            emptyLocation.push_back(MOVE_LEFT);
        }
    }
    //check right position
    if (j + 1 <= COLUMN_RANGE-1)
    {
        if (world[i][j + 1]->get_species() == "NONE")
        {
            emptyLocation.push_back(MOVE_RIGHT);
        }
    }

    if (emptyLocation.size() != 0)
    {
        srand(time(NULL));
        int random = rand() % emptyLocation.size();
        if (emptyLocation[random] == MOVE_UP)
        {
            world[i - 1][j] = world[i][j];
            world[i - 1][j]->set_location(i - 1, j);
        }
        else if (emptyLocation[random] == MOVE_DOWN)
        {
            world[i + 1][j] = world[i][j];
            world[i + 1][j]->set_location(i + 1, j);
        }
        else if (emptyLocation[random] == MOVE_LEFT)
        {
            world[i][j - 1] = world[i][j];
            world[i][j - 1]->set_location(i, j - 1);
        }
        else if (emptyLocation[random] == MOVE_RIGHT)
        {
            world[i][j + 1] = world[i][j];
            world[i][j + 1]->set_location(i, j + 1);
        }
        world[i][j] = new Organism(i, j);
    }
    
    this->breedStep+=1;

}
void printWorld(vector<vector<Organism *> > world)
{
    for (int i = 0; i < ROW_RANGE; i++)
    {
        for (int j = 0; j < COLUMN_RANGE; j++)
        {
            cout << world[i][j]->get_sym() << " ";
        }
        cout << endl;
    }
}
void createAWorld(vector<vector<Organism *> > &world)
{
    // generate 100 ants at random place in the world
    srand(time(NULL));
    int randomX1 = rand() % ROW_RANGE;
    int randomY1 = rand() % COLUMN_RANGE;

    for (int i = 0; i < INITIAL_ANT_POPULATION; i++)
    {
        while (world[randomX1][randomY1]->get_species() != "NONE")
        {
            randomX1 = rand() % ROW_RANGE;
            randomY1 = rand() % COLUMN_RANGE;
        }
        world[randomX1][randomY1] = new Ant(randomX1, randomY1);
    }
    // generate 5 doodlebugs at random place in the world
    srand(time(NULL));
    int randomX2 = rand() % ROW_RANGE;
    int randomY2 = rand() % COLUMN_RANGE;

    for (int i = 0; i < INITIAL_DOODLEBUG_POPULATION; i++)
    {
        while (world[randomX2][randomY2]->get_species() != "NONE")
        {
            randomX2 = rand() % ROW_RANGE;
            randomY2 = rand() % COLUMN_RANGE;
        }

        world[randomX2][randomY2] = new DoodleBug(randomX2,randomY2);
    }
}

int main()
{
    vector<vector<Organism *> > world;

    for (int i = 0; i < ROW_RANGE; ++i)
    {
        world.push_back(vector<Organism *>());
    }
    for (int i = 0; i < ROW_RANGE; i++)
    {
        for (int j = 0; j < COLUMN_RANGE; j++)
        {
            world[i].push_back(new Organism(i, j));
        }
    }
    createAWorld(world);
    printWorld(world);

    while (true)
    {
        cout << "MOVE? press enter to move, ctrl + c if want to stop" << endl;
        cin.ignore();
        vector<Organism *> BugsToMove;
        vector<Organism *> AntsToMove;
        for (int i = 0; i < ROW_RANGE; i++)
        {
            for (int j = 0; j < COLUMN_RANGE; j++)
            {
                if (world[i][j]->get_species() == "DOODLEBUG")
                {
                    BugsToMove.push_back(world[i][j]);
                }
            }
        }

        for (int i = 0; i < BugsToMove.size(); i++)
        {
            BugsToMove[i]->move(BugsToMove[i]->i, BugsToMove[i]->j, world);
            BugsToMove[i]->breed(world);
            BugsToMove[i]->starve(world);
        }

        for (int i = 0; i < ROW_RANGE; i++)
        {
            for (int j = 0; j < COLUMN_RANGE; j++)
            {
                if (world[i][j]->get_species() == "ANT")
                {
                    AntsToMove.push_back(world[i][j]);
                }
            }
        }

        for (int i = 0; i < AntsToMove.size(); i++)
        {
            AntsToMove[i]->move(AntsToMove[i]->i, AntsToMove[i]->j, world);
        }

        for (int i = 0; i < AntsToMove.size(); i++)
        {
            AntsToMove[i]->breed(world);
        }

        cout << endl;

        printWorld(world);
    }

    return 0;
}
