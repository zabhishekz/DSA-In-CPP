#include<iostream>
#include<stack>
using namespace std;

bool isValidExp(char *exp){
    stack<char> s;
    for(int i = 0; exp[i] != '\0'; i++){
        char ch = exp[i];
        if(ch == '('){
            s.push(ch);
        }
        else if (ch == ')'){
            if(s.empty() or  s.top() != '('){
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main(){
    char exp[16] = "((a+b)+(c-d+f))";
    cout<<isValidExp(exp);
    return 0;
}