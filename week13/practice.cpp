//Program to demonstrate the CDAccount structure type.
#include <iostream>
using namespace std;

int func1(int a){
    a = a+3;
    return a;
}
void func2(int a){
    a= a+3;
}

void func3(int *a){
    *a =*a +1;
}

int main(){
    int a = 1;
    int* ptr = &a;
    int c = func1(a);
    func2(a);
    func3(ptr);
    cout<<c<<'\t'<<a;
    return 0;
}


