#include <bits/stdc++.h>
using namespace std;

//We have to print the names of students along with their count if they are repeating.
//If no name is repeating, print -1. So make a map/unodered_map and count the freq of the
//name. Print the names having frequency gretaer than one.
//A bool variables helps to tell whether all the names are uniwue or not.


int main() {
    string str;
    getline(cin, str);
    
    map<string, int> names;
    int count = 1;
    
    string word ="";
    //Since, the string have space between the words, so this is how we deal with the spaces
    for(int i=0; i< str.length(); i++){
    	char x = str[i];
    	if (x == ' '){
    		++names[word];
    		count++;
    		word = "";
		}
		else{
			word += x;
		}
	}
    names[word]++;
    
    bool name_freq_more_than_one = false;
    for(auto pair : names){
    	if(pair.second > 1){
    		name_freq_more_than_one = true;
    		cout << pair.first << " " << pair.second << endl;
		}
	}
	
	if(!name_freq_more_than_one){
		cout << -1 ;
	}
}





/*Other solution

int main(){
	string str;
	getline(cin, str);
	
	unordered_map<string, int> freq;
	
	istringstream stream(str);
	do{
		string word;
		stream >> word;
		++freq[word];
	} while (stream);
	
	bool isNamePrinted = false;
	
	for(auto pair : freq){
		if(pair.second > 1){
			isNamePrinted = true;
			cout << pair. first << " "<< pair.second<< endl;
		}
	}
	
	if(!isNamePrinted){
		cout << -1 <<end;
	}
}

*/

/*
A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin).

Basic methods are –

clear() — to clear the stream
str() — to get and set string object whose content is present in stream.
operator << — add a string to the stringstream object.
operator >> — read something from the stringstream object,
*/

