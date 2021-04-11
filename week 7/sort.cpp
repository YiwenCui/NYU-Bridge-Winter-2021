#include<iostream>
using namespace std;

int main(){
    int a[] = {4,3,2,1,0,-1,-2};
    int p = 1;
    int n = sizeof(a) / sizeof(int);
    int i = 0, b=0;
    int j = n -1;
    int temp;

    while(i<j){
        while (i<j && a[i] <p)
            i=i+1;
        while(i<j && a[j] >=p)
            j=j-1;

        if(i<j){
            temp = a[i];
            a[i]=a[j];
            a[j]=temp;
            b++;
        }
    }
    for (int m =0; m<n;m++)
        cout<<a[m]<<endl;
        cout<<b<<endl;
    return 0;

}
    
    