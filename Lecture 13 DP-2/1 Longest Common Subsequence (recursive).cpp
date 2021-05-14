#include <bits/stdc++.h>
using namespace std;

//time comp => O(2^n)
int lcs(char *a, char *b){
	if(a[0] == '\0' || b[0] == '\0'){
		return 0;
	}
	
	if(a[0] == b[0]){
		return 1 + lcs(a+1, b+1);
	} else{
		int ans1 = lcs(a+1, b);
		int ans2 = lcs(a, b+1);
		return max(ans1, ans2);
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    char a[100];
    char b[100];
    cin >>a >> b;
    cout << lcs(a, b) <<endl;
}

