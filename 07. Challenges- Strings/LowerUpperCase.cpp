#include <iostream>
using namespace std;

int main() 
{
    char a;
    cin>>a;
    if(a >= 'a' && a <= 'z')
    {
        cout<<"L";
    }
    else if(a >='A' && a <= 'Z')
    {
        cout<<"U";
    }
    else
    {
        cout<<"I";
    }

	return 0; 
} 