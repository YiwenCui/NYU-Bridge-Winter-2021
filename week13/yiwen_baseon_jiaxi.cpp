#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;
// const int ROW_RANGE = 20, COLUMN_RANGE = 20;
const int ROW_RANGE = 5, COLUMN_RANGE = 5;
// const int INITIAL_ANT_POPULATION = 100, INITIAL_DOODLEBUG_POPULATION = 5;
const int INITIAL_ANT_POPULATION = 10, INITIAL_DOODLEBUG_POPULATION = 2;
const int ANT_BREED_STEP = 3, DOODLEBUG_BREED_STEP = 8;
const int DOOLEBUG_STARVE_STEP = 3;
const char NONE = '-', ANT = 'o', DOODLEBUG = 'X';
const int MOVE_UP = 1, MOVE_DOWN = 2, MOVE_LEFT = 3, MOVE_RIGHT = 4;

class Organism
{
public:
    Organism()
    {
        this->species = "NONE";
        this->sym = '-';
        this->age = 0;
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
    int age;
    string get_species() { return this->species; };
    char get_sym() { return this->sym; };
    virtual void move(int i, int j, vector<vector<Organism *> > &world) {};
    void breed();
    virtual void starve(int i, int j, vector<vector<Organism *> > &world) {};

private:
    string species;
    char sym;
    
};

class DoodleBug : public Organism
{
public:
    DoodleBug() : Organism("DOODLEBUG"){};
    void starve(int i, int j, vector<vector<Organism *> > &world);
    void move(int i, int j, vector<vector<Organism *> > &world);
};

class Ant : public Organism
{
public:
    Ant() : Organism("ANT"){};
    void move(int i, int j, vector<vector<Organism *> > &world);
};

void DoodleBug::starve(int i, int j, vector<vector<Organism *> > &world){
    if (this->age==3){
        world[i][j]=new Organism();
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
    //cout<<i<<','<<j<<endl;
    for (int i=0; i<antLocation.size();i++){
        // cout<<antLocation[i]<<'|';
    }
    //cout<<endl;
    for (int i=0; i<emptyLocation.size();i++){
        // cout<<emptyLocation[i]<<'|';
    }
    //cout<<endl;
    
    if (antLocation.size() != 0)
    {
        // cout << i << "," << j << endl;
        // cout<<antLocation.size()<<endl;
        srand(time(NULL));
        int random = rand() % antLocation.size();
        if (antLocation[random] == MOVE_UP)
        {
            world[i - 1][j] = world[i][j] ;
        
        }
        else if (antLocation[random] == MOVE_DOWN)
        {
            world[i + 1][j] = world[i][j] ;
            
            //world[i + 1][j] = new DoodleBug();
        }
        else if (antLocation[random] == MOVE_LEFT)
        {
            world[i][j-1] = world[i][j] ;
            
            //world[i][j - 1] = new DoodleBug();
        }
        else if (antLocation[random] == MOVE_RIGHT)
        {
            world[i][j+1] = world[i][j] ;

            //world[i][j + 1] = new DoodleBug();
        }
        world[i][j] = new Organism();
    }

    else if (antLocation.size() == 0 && emptyLocation.size() != 0)
    {
        srand(time(NULL));
        int random = rand() % emptyLocation.size();
        // cout << i << "," << j << "emoty" << endl;
        // cout<<emptyLocation.size()<<endl;

        if (emptyLocation[random] == MOVE_UP)
        {
            world[i - 1][j] = world[i][j] ;
            //world[i - 1][j]= new DoodleBug();
        }
        else if (emptyLocation[random] == MOVE_DOWN)
        {
            world[i + 1][j] = world[i][j] ;           
            //world[i + 1][j] = new DoodleBug();
        }
        else if (emptyLocation[random] == MOVE_LEFT)
        {   
            world[i][j-1] = world[i][j] ;       
            //world[i][j - 1] = new DoodleBug();
        }
        else if (emptyLocation[random] == MOVE_RIGHT)
        {
            world[i][j+1] = world[i][j] ;   
            //world[i][j + 1] = new DoodleBug();
        }
        world[i][j] = new Organism();
    }
    this->age+=1;
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
        // cout << i << "," << j << endl;
        // cout << emptyLocation.size() << endl;
        srand(time(NULL));
        int random = rand() % emptyLocation.size();
        if (emptyLocation[random] == MOVE_UP)
        {
            world[i - 1][j] = world[i][j] ;
        }
        else if (emptyLocation[random] == MOVE_DOWN)
        {
            world[i + 1][j] = world[i][j] ;
        }
        else if (emptyLocation[random] == MOVE_LEFT)
        {
            world[i][j-1] = world[i][j] ;
        }
        else if (emptyLocation[random] == MOVE_RIGHT)
        {
            world[i][j+1] = world[i][j] ;
        }
        world[i][j] = new Organism();
    }
    this->age +=1;

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
        world[randomX1][randomY1] = new Ant();
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

        world[randomX2][randomY2] = new DoodleBug();
    }
}

int main()
{
    string userInput;
    vector<vector<Organism *> > world;

    for (int i = 0; i < ROW_RANGE; ++i)
    {
        world.push_back(vector<Organism *>());
    }
    for (int i = 0; i < ROW_RANGE; i++)
    {
        for (int j = 0; j < COLUMN_RANGE; j++)
        {
            world[i].push_back(new Organism());
        }
    }
    createAWorld(world);
    printWorld(world);
    
    
    userInput="Yes";
    while (userInput != "exit")
    {
        cout<<"MOVE? enter Yes if you want to move, enter exit if want to stop"<<endl;
        cin>>userInput;
        vector<Organism *> BugsToMove;
        vector<Organism *> AntsToMove;
        vector<int> BugiToMove;
        vector<int> BugjToMove;
        vector<int> AntiToMove;
        vector<int> AntjToMove;
        for (int i = 0; i < ROW_RANGE; i++)
        {
            for (int j = 0; j < COLUMN_RANGE; j++)
            {
                if (world[i][j]->get_species() == "DOODLEBUG")
                {
                    BugsToMove.push_back(world[i][j]);
                    BugiToMove.push_back(i);
                    BugjToMove.push_back(j);
                }
            }
        }

        for (int i = 0; i < BugsToMove.size(); i++)
        {
            BugsToMove[i]->move(BugiToMove[i], BugjToMove[i], world);
        }

        for (int i = 0; i < ROW_RANGE; i++)
        {
            for (int j = 0; j < COLUMN_RANGE; j++)
            {
                if (world[i][j]->get_species() == "ANT")
                {
                    AntsToMove.push_back(world[i][j]);
                    AntiToMove.push_back(i);
                    AntjToMove.push_back(j);
                }
            }
        }

        for (int i = 0; i < AntsToMove.size(); i++)
        {
            AntsToMove[i]->move(AntiToMove[i], AntjToMove[i], world);
        }

        for (int i=0; i<BugsToMove.size();i++){
            BugsToMove[i]->starve(BugiToMove[i], BugjToMove[i], world);
        }

        cout << endl;

        printWorld(world);
        
    }
    
    return 0;
}
