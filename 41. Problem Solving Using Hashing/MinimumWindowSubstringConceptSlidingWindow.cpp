//Problem- Find the smallest window in a string that contains all characters of another string
//string->"hellloeeo world"
//pattern-> "eelo"

#include<iostream>
#include<climits>
#include<string>
using namespace std;

string find_window(string s, string pat){
    //1.Corner case
    int SL = s.length();
    int PL = pat.length();
    if(PL > SL){
        return "None";
    }

    //2.Freq maps
    int FS[256] = {0};
    int FP[256] = {0};
    for(int i = 0; i < PL; i++){
        char ch = pat[i];
        FP[ch]++;
    }

    //3.sliding Window(Expansion and Comtraction + Update the min length window)
    int cnt = 0;
    int start = 0;//left pointer for shrinking the window 
    int min_len = INT_MAX;
    int start_idx = -1;
    for(int i = 0; i < SL; i++){
        char ch = s[i];
        FS[ch]++;

        //Mantain cnt of characters matched
        if(FP[ch] != 0 and FS[ch] <= FP[ch]){
            cnt++;
        }

        //if all the charcters match
        if(cnt == PL){
            //start shrinking eindow from left
            char temp = s[start];
            //Loop to remove all unwanted characters
            while(FP[temp] == 0 or FS[temp] > FP[temp]){
                FS[temp]--;
                start++;
                temp = s[start];
            }   
            int window_len = i-start+1;
            if(window_len < min_len){
                min_len = window_len;
                start_idx = start;
            }
        }

    }
    if(start_idx == -1){
        return "NULL";
    }
    string ans = s.substr(start_idx, min_len);
    return ans;
}

int main(){
    string s = "hllloeaeo world";
    string p = "eelo"; 

    cout<<find_window(s, p)<<endl; 
    return 0;
}


