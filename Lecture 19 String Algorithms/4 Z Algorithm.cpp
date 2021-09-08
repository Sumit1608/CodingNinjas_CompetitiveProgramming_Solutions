#include<bits/stdc++.h>
using namespace std;

// Time comp => O(m+n)
void build(int *z, string str){
	int l=0, r=0;
	int n = str.length();
	
	for(int i=1; i<n; i++){
		if(i > r){
			l=i;
			r=i;
			while(r<n && str[r-l] == str[r]){
				r++;
			}
			z[i] = r-l;
			r--;
		}
		else{
			int k= i-l;
			if(z[k] <= r-i){
				z[i] = z[k];
			}
			else{
				l =i;
				while(r<n &&str[r-l] == str[r]){
					r++;
				}
				z[i] = r-l;
				r--;
			}
		}
	}
}

void searchString(string text, string pattern){
	string str = pattern + "$" + text;
	int n = str.length();
	int *z = new int[n]();
	build(z, str);
	
	for(int i=0; i<n; i++){
		if(z[i] == pattern.length()){
			cout << i-1-pattern.length() <<endl;
		}
	}
}

int main(){
	string text, pattern;
	cin >> text;
	cin >> pattern;
	searchString(text, pattern);
	return 0;
}

