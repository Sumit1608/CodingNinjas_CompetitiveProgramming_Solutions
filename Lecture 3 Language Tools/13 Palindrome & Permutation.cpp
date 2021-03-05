#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

char getChar(int i){
	return (char)(i+97);
}
void printPalindromicString(string s){
	//Maintain a map for characters and their occurence on indexes
	map <char, vector<int> > indexesMap;
	for(int i=0; i<s.length(); i++){
		indexesMap[s[i]].push_back(i);
	}
	
	int odd_freq_count =0;
	for(int i=0; i<26; i++){
		if( (indexesMap[getChar(i)].size() %2) != 0){
			odd_freq_count++;
		}
	}
	if(odd_freq_count >1){
		cout << "-1";
		return;
	}
	
	//Now all the character have even frequencies and there maybe only one character with odd freq
	int ans[s.length()];
	int start=0;
	int end = s.length()-1;
	
	for(int i=0; i<26; i++){
		char currentChar = getChar(i);
		for(int j=0; j < indexesMap[currentChar].size(); j+=2 ){
			
			//If any one of the character have odd freq
			if( (indexesMap[currentChar].size() - j) == 1 ){
				ans[s.length()/2] = indexesMap[currentChar][j];
				continue;
			}
			ans[start] = indexesMap[currentChar][j] ;
			ans[end] = indexesMap[currentChar][j+1] ;
			start++;
			end--;
		}
	}
	
	for(int i=0; i<s.length(); i++){
		cout<< ans[i]+1 << " ";
	}
}

int main(){
    int t;
    cin>>t;
    while(t--){
    	string s;
    	cin>>s;
    	printPalindromicString(s);
    	cout << endl;
	}
}
