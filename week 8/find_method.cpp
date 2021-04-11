#include<iostream>
#include <string>
using namespace std;


int main(){
    string str="abcdbcdefg";
    cout<<str.find("xyz")<<endl;
    cout<<string::npos;

    return 0;
}