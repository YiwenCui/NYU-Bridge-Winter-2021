#include<iostream>
using namespace std;

// int* f1(int* a);

// int main(){
//     int n =3;
//     int *ptr =&n;
//     f1(ptr);
//     cout<<n;
//     return 0;
// }

// int* f1(int* a){
//     *a = *a+1;
//     return a;
// }

// void f1(int* a);

// int main(){
//     int n =3;
    
//     f1(&n);
//     cout<<n;
//     return 0;
// }

// void f1(int* a){
//     *a = *a+1;
// }

// void printAsc(int start, int end);
// int main(){
//     printAsc(1,4);
//     return 0;

// }
// void printAsc(int start, int end){
//     if(start == end){
//         cout<<start<<endl;
//     }
//     else{
//         cout<<start<<endl;
//         printAsc(start+1, end);
        
//     }
// }

// void func1(int &a, char &b){
//     a =7;
//     b='s';
//     cout<<a<<' '<<b<<endl;
// }

// int main(){
//     int a =5;
//     char b ='g';
//     func1(a,b);
//     cout<<a<<' '<<b<<endl;
//     return 0;
// }

int main(){
    int* arr = new int[6];
    for (int i =0; i<6;i++){
        cout<<arr[i]<<endl;
    }
    return 0;

}