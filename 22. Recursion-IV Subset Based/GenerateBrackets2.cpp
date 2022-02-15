class Solution {
    vector<string> sol;
public:
    void generaterec(string out, int n, int open, int close){
        if(open == n and close == n){
            sol.push_back(out);
            return;
        }
        if(open < n){
            out.push_back('(');
            generaterec(out,n,open+1,close);
            out.pop_back();
        }
        if(close < open){
            out.push_back(')');
            generaterec(out,n,open,close+1);
            out.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        string out="";
        generaterec(out,n,0,0);
        return sol;
    }
};