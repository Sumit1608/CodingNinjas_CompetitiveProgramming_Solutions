#include <iostream>
using namespace std;

//time comp => O(N^2)
int size(char s[]){
    int n = 0;
    while (s[n] != '\0')
        n++;
    return n;
}

int countPalindromeSubstrings(char s[]) {
    int n = size(s);
	int ans =0;
	
	for(int i=0; i<n; i++){
		int l=i;
		int r=i;
		
		//odd length
		while(l>=0 && r<n && s[l] == s[r]){
			ans++;
			l--;
			r++;
		}
		//even length
		l=i;
		r=i+1;
		while(l>=0 && r<n && s[l] == s[r]){
			ans++;
			l--;
			r++;
		}
	}
	return ans;
}

int main() {
    char input[10000];
    cin >> input;
    cout << countPalindromeSubstrings(input) << endl;
}
