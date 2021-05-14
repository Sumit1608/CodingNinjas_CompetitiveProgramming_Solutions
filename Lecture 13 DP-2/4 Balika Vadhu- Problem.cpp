#include<bits/stdc++.h>
using namespace std;

//time comp => O(100*100*100*t)       for both codes
/*
for any two strings we have two options 
1.  if the characters of s1 and s2 are not same,  then we call recursion for
   (a).  recur( s1.substrng(1), s2, k)     (b) recur( s2.substrng(1), s1, k)
2.  else when characters of s1 and s2 are same, we can either include that character in our subsequenece or not
    => if we include that character, then call  recur( s1.substrng(1), s2.substrng(1), k-1)
    ==>if we don't include then call    (a).  recur( s1.substrng(1), s2, k)     (b) recur( s2.substrng(1), s1, k)
*/

// checking the subsequences from the last characters of strings
int dp[100][100][101];

int solve(string s1, string s2, int i, int j, int k){
	// base case when the length of subsequence required becomes -1
    if(k == 0)
        return 0;
    // base case when we could not find the subsequence of length k
    if(i == -1 || j == -1)
        return -1;
    // checking whether we found the result for i,j,k before or not
    if(dp[i][j][k] != -2)
       return dp[i][j][k];
    
    int ans1 = -1, ans2 = -1, ans3 = -1;
    if(s1[i] == s2[j]){
        ans1 = solve(s1, s2, i-1, j-1, k-1);
        if(ans1 != -1)
            ans1 += s1[i];
    }
    
    ans2 = solve(s1, s2, i-1, j, k);
    ans3 = solve(s1, s2, i, j-1, k);
    
    int ans = max(ans1, max(ans2, ans3));
    dp[i][j][k] = ans;
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        int k;
        cin>> k;
        int m = s1.length();
        int n = s2.length();
        
        // intialize dp with -2 so that when we fill it if it's not equal to -2
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                for(int h=0; h<=k; h++)
                    dp[i][j][h] = -2;
        
        int ans = solve(s1, s2, m-1, n-1, k);
        if(ans == -1)
            cout << 0 <<endl;
        else
            cout << ans <<endl;
    }
}



/*
// checking the subsequences from the starting characters of strings
int happiness(string s1, string s2, int k, int ***dp){
	if (k == 0)
		return 0;
	if (k > s1.length() || k > s2.length())
		return 0;
    int n=s1.length();
    int m=s2.length();
    if(dp[n][m][k]>=0)
        return dp[n][m][k];
    int ans;
    
	if (s1[0] == s2[0]){
		int ascii_value = s1[0];
		int option1 = ascii_value + happiness(s1.substr(1), s2.substr(1), k - 1, dp);
		if (option1-ascii_value == 0 && k > 1)
		{
			option1= 0;
		}
		int option2 = happiness(s1.substr(1), s2, k, dp);
		int option3 = happiness(s1, s2.substr(1), k, dp);
		ans= max(option1, max(option2, option3));
	}
	else{
		int option1 = happiness(s1.substr(1), s2, k, dp);
		int option2 = happiness(s1, s2.substr(1), k, dp);
		ans= max(option1, option2);
	}
    
    dp[n][m][k]=ans;
    return ans;
}

int main(){
	int t;
	cin >> t;
	while (t--){
		string b1, b2;
		cin >> b1 >> b2;
		int k;
		cin >> k;
        int ***dp=new int**[101];
        
        for(int i=0; i<101; i++){
            dp[i]=new int *[101];
            for(int j=0; j<101; j++){
                dp[i][j]=new int [101];
                for(int k=0; k<101; k++)
                    dp[i][j][k]=-1;
            }
        }
        
		int ans = happiness(b1, b2, k, dp);
        for(int i=0; i<101; i++){
            for(int j=0; j<101; j++)
                delete[]dp[i][j];
            delete []dp[i];
        }
        delete[]dp;
		
        cout << ans <<endl;
	}
}
*/

/*
// Iterative solution
#include <bits/stdc++.h>
using namespace std;

int dp[101][101][101], lcs[101][101];

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        int m = a.size(), n = b.size();
        int k;
        cin >> k;
        memset(dp, 0, sizeof(dp));
        memset(lcs, 0, sizeof(lcs));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]==b[j-1]){
                    lcs[i][j] = 1 + lcs[i-1][j-1];
                }else{
                    lcs[i][j] = max(lcs[i][j-1], lcs[i-1][j]);
                }
            }
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i-1] == b[j-1]) {
                    for (int z = 1; z <= lcs[i][j]; z++) {
                        dp[i][j][z] = max(dp[i-1][j-1][z-1] + a[i-1], dp[i-1][j-1][z]);
                    }
                } else {
                    for (int z = 0; z <= lcs[i][j]; z++) {
                        dp[i][j][z] = max(dp[i-1][j][z], dp[i][j-1][z]);
                    }
                }
            }
        }
        
        if (lcs[m][n] < k) {
            cout << 0 << endl;
        } else {
            cout << dp[m][n][k] << endl;
        }
    }
}
*/

