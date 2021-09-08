#include<bits/stdc++.h>
using namespace std;

// Time comp => O(m+n)

//lps is longest prefix matching with the suffix
int* getLPS(string pattern){
	int len = pattern.length();
	int *lps = new int[len];
	
	lps[0] =0;
	int i=1;
	int j=0;
	
	while(i<len){
		if(pattern[i] == pattern[j]){
			lps[i] = j+1;
			i++;
			j++;
		} else{
			if(j != 0){
				j = lps[j-1];
			} else{
				lps[i] =0;
				i++;
			}
		}
	}
	return lps;
}

bool kmpSearch(string text, string pattern){
	int lenText = text.length();
	int lenPatt = pattern.length();
	
	int *lps = getLPS(pattern);
	int i=0, j=0;
	while(i<lenText && j<lenPatt){
		if(text[i] == pattern[i]){
			i++;
			j++;
		} else{
			if(j != 0){
				j = lps[j-1];
			} else{
				i++;
			}
		}
	}
	
	if(j == lenPatt){
		return true;
	}
	return false;
}

int main(){
	string str, subStr;
	cin >> str;
	cin >> subStr;
	
	cout << kmpSearch(str, subStr) <<endl;
	return 0;
}

