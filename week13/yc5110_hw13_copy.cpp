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
const int MOVE_UP = 1, MOVE_DOWN = 2, MOVE_LEFT = 3, MOVE_RIGHT = 4;

class Organism
{
public:
    // void move();
    void breed();

    Organism(string species, int line, int column)
    {
        this->species = species;
        this->line = line;
        this->column = column;
    };

    Organism(int line, int column){
        this->line = line;
        this->column = column;
    }
    string get_species() { return this->species; };
    int get_line() { return this->line; };
    int get_column() { return this->column; };
    void move();

private:
    string species;
    int line;
    int column;
};

class Ants : public Organism
{
public:
    Ants(int line, int column): Organism(line, column){};
    // {
        
    //     // Organism("1",2,3);
    // };
    void move();
    void breed();
    void setLine(int l){this->line = l;};
    void setColumn(int c){this->column = c;};
    int getLine(){return this->line;};
    int getColumn(){return this->column;};

private:
    int line;
    int column;
};

// void Ants::move()
// {

// }

class DoodleBugs : public Organism
{
public:
    DoodleBugs(int line, int column);
    void eatAnts();
    void starve();
    void move();
    void breed();
};

// void DoodleBugs::move()
// {
    
// }

void createAWorld(char world[][COLUMN_RANGE]);
void printWorld(char world[][COLUMN_RANGE]);
vector<Organism> createOrganismVector(char world[][COLUMN_RANGE]);
vector<Ants> createAntsVecotr(vector<Organism> a);
vector<DoodleBugs> createDoodlebugsVecotr(vector<Organism> a);

int main()
{
    
    char world[LINE_RANGE][COLUMN_RANGE];

    createAWorld(world);
    printWorld(world);
    vector<Organism> allAntsDoddlebugs = createOrganismVector(world);
    vector<Ants> allAnts = createAntsVecotr(allAntsDoddlebugs);
    
    
    
    return 0;
}



vector<Organism> createOrganismVector(char world[][COLUMN_RANGE])
{
    vector<Organism> allOrganism;
    Organism *randomObject = NULL;
    for (int i = 0; i < LINE_RANGE; i++)
    {
        for (int j = 0; j < COLUMN_RANGE; j++)
        {
            if (world[i][j] == 'o')
            {
                randomObject = new Organism("ANT", i, j);
            }
            else if (world[i][j] == 'X')
            {
                randomObject = new Organism("DOODLEBUG", i, j);
            }
            else
            {
                randomObject = new Organism("NA", i, j);
            }
            allOrganism.push_back(*randomObject);
        }
    }
    return allOrganism;
}

vector<Ants> createAntsVecotr(vector<Organism> a){
    vector<Ants> allAnts;
    vector<Organism> ants;
    for (int i =0; i<a.size();i++){
        if (a[i].get_species()=="ANT"){
            ants.push_back(a[i]);
        }
    }
    for (int i=0;i<ants.size();i++){
        Ants randomAnt = Ants(ants[i].get_line(), ants[i].get_column());
        allAnts.push_back(randomAnt);
    }

    for (int i=0;i<allAnts.size();i++){
        cout<<allAnts[i].getLine()<<'\t'<<allAnts[i].getColumn()<<endl;
    }

    return allAnts;

}

void createAWorld(char world[][COLUMN_RANGE])
{
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
    int randomX1 = rand() % 20;
    int randomY1 = rand() % 20;

    for (int i = 0; i < INITIAL_ANT_POPULATION; i++)
    {
        while (world[randomX1][randomY1] != NONE)
        {
            randomX1 = rand() % 20;
            randomY1 = rand() % 20;
        }

        world[randomX1][randomY1] = ANT;
    }
    // generate 5 doodlebugs at random place in the world
    srand(time(NULL));
    int randomX2 = rand() % 20;
    int randomY2 = rand() % 20;

    for (int i = 0; i < INITIAL_DOODLEBUG_POPULATION; i++)
    {
        while (world[randomX2][randomY2] != NONE)
        {
            randomX2 = rand() % 20;
            randomY2 = rand() % 20;
        }

        world[randomX2][randomY2] = DOODLEBUG;
    }
}

void printWorld(char world[][COLUMN_RANGE])
{
    // print the world
    for (int i = 0; i < LINE_RANGE; i++)
    {
        for (int j = 0; j < COLUMN_RANGE; j++)
        {
            cout << world[i][j] << " ";
        }
        cout << endl;
    }
}


// void move(char world[][COLUMN_RANGE]){
//     // srand(time(NULL));
//     // int randomDirection = rand() % 4 + 1;
//     int randomDirection=1;
//     if (randomDirection==MOVE_UP){
//         for (int i=1; i<LINE_RANGE;i++){
//             for(int j=0; j< COLUMN_RANGE;j++){
//                 if (world[i][j]=='o'){
//                     if (world[i-1][j]=='-'){
//                         world[i-1][j]='o';
//                         world[i][j]='-';
//                     }
//                     else if(world[i-1][j]=='o'){
//                         world[i-1][j]='o';
//                         world[i][j]='o';
//                     }
//                     else if(world[i-1][j]=='X'){
//                         world[i-1][j]='X';
//                         world[i][j]='o';
//                     }

//                 }
//                 else if(world[i][j]=='X'){
//                     if (world[i-1][j]=='-'){
//                         world[i-1][j]='X';
//                         world[i][j]='-';
//                     }
//                     else if(world[i-1][j]=='o'){
//                         world[i-1][j]='X';
//                         world[i][j]='-';
//                     }
//                     else if(world[i-1][j]=='X'){
//                         world[i-1][j]='X';
//                         world[i][j]='X';
//                     }
//                 }
//             }
//         }
//     }

// }