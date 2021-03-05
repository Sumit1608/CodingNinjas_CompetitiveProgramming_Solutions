#include <bits/stdc++.h>
using namespace std;

//The output string should contain each character only once.
//The respective order of characters should remain same, as in the input string.
//So, we make use a map to count the frequency of the characters by traversing
//the string. When our character freq is made to one, then we add that character
//to our answer string.

//Also, we can make a set, if our charac is not in our set, then we add character 
//to the answer, otherwise not.

string uniqueChar(string str) {
	map<char,int> m;
    string ans = "";
    
    for(int i=0; i<str.length(); i++){
        ++m[str[i]];
        if(m[str[i]] == 1){
            ans += str[i];
        }
    }
    
    return ans;
}

/*
string uniqueChar(string str) {
	unordered_set<char> m;
    string ans = "";
    
    for(char ch: str){
    	if(m.find(ch) == m.end()){
    		ans.push_back(ch);
    		m.insert(ch);
		}
	}
    
    return ans;
}
*/

int main() {
    string str;
    cin >> str;
    cout << uniqueChar(str);
}
