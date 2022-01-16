#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char a[1000];
    char largest[1000];
    int len = 0;
    int largestlen = 0;
    int n;
    cout<<"Enter number of strings : ";
    cin>>n;
    cin.get();  //for null string

    for(int i =0; i < n; i++){
        cout<<"Enter string: ";
        cin.getline(a, 1000);
        len = strlen(a);
        if(len > largestlen){
            largestlen = len;
            strcpy(largest, a);
        }
    }
    cout<<"Largest string is "<<largest<<" and its length is "<<largestlen;

    return 0;
}