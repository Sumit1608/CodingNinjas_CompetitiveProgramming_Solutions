#include<iostream>
#include<map>
#include<cstring>
using namespace std;

//Make map and count the frequency of the characters
// then traverse the map and return the character whose freq is one
// otherwise return the character stored at 0th index
char nonRepeatingCharacter(string str){
	map<char, int> freq;
	for(int i=0; i<str.length(); i++){
		freq[ str[i] ]++;
	}
	
	for(int i=0; i<str.length(); i++){
		if(freq[str[i] ] == 1){
			return str[i];
		}
	}
	return str[0];
}

int main(){
	string s;
	cin>>s;
	
	cout << nonRepeatingCharacter(s) <<endl;
	
}
