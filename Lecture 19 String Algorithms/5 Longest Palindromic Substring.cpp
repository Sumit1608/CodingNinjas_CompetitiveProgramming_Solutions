#include<bits/stdc++.h>
using namespace std;

// Time comp => O(n^2)
int lps(string s){
	int n = s.length();
	int ans =1;
	
	for(int i=0; i<n; i++){
		int l=i;
		int r=i;
		
		//odd length
		while(l>=0 && r<n && s[l] == s[r]){
			int len = r-l+1;
			ans = max(ans, len);
			l--;
			r++;
		}
		//even length
		l=i;
		r=i+1;
		while(l>=0 && r<n && s[l] == s[r]){
			int len = r-l+1;
			ans = max(ans, len);
			l--;
			r++;
		}
	}
	return ans;
}

int main(){
	string s;
	cin >> s;
	cout << lps(s) << endl;
	return 0;
}

