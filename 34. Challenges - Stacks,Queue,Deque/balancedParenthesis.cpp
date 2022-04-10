#include<iostream>
#include<stack>
using namespace std;

bool isValidExp(string exp){
    stack<char> s;
    for(int i = 0; exp[i] != '\0'; i++){
        char ch = exp[i];
        if(ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }
        else if(ch == ')'){
            if(s.empty() or  s.top() != '('){
                return false;
            }
            s.pop();
        }
        else if(ch == '}'){
            if(s.empty() or  s.top() != '{'){
                return false;
            }
            s.pop();
        }
        else if(ch == ']'){
            if(s.empty() or  s.top() != '['){
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main(){
    string exp;
    cin>>exp;
    bool i = isValidExp(exp);
    if(i){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
    return 0;
}