#include<iostream>
#include<vector>
using namespace std;

class Student{
    public:
    int marks;
    string name;
};

void BucketSort(Student s[], int n)
{
    //assuming marks in rage 0-100
    vector <Student> v[101];

    //O(n) time
    for(int i = 0; i < n; i++)
    {
        int m = s[i].marks;
        v[m].push_back(s[i]); 
    }


    for(int i = 100; i >= 0; i--)
    {
        for(vector <Student>::iterator it=v[i].begin(); it != v[i].end(); it++)
        {
            cout<<(*it).marks<<" "<<(*it).name<<endl;
        }
    }

}

int main()
{
    Student s[100];
    int n;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>s[i].marks>>s[i].name;
    }
    BucketSort(s,n);
    return 0;
}