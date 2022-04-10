#include<iostream>
#include<stack>
using namespace std;
int main(int argc, char const *argv[])
{
	stack<char> s;
    int t;
    cin>>t;
	string str;
    while(t--){
	cin>>str;
	int flag=0;

	for (int i = 0; i < str.size(); i++)
	{ 
		char ch=str[i];
		if(ch != ')'){
			s.push(ch);
		}
		if(ch == ')'){
			if(s.empty())
				break;
            if(s.top()=='(')
                flag=1;
			else{
				while(s.top()!='('){
					s.pop();		
				}
                s.pop();
            
			}
		}
	}

	if(flag==1)
		cout<<"Duplicate";
	else
		cout<<"Not Duplicate";

    cout<<endl;
    }
	return 0;
}