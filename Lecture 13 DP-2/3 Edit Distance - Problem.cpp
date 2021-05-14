#include <bits/stdc++.h>
using namespace std;

/*
m: Length of str1 (first string)
n: Length of str2 (second string)
If last characters of two strings are same, nothing much to do. Ignore last characters 
and get count for remaining strings. So we recur for lengths m-1 and n-1.
Else (If last characters are not same), we consider all operations on ‘str1’, 
consider all three operations on last character of first string, recursively compute 
minimum cost for all three operations and take minimum of three values. 
1. Insert: Recur for m and n-1
2. Remove: Recur for m-1 and n
3. Replace: Recur for m-1 and n-1
*/

/*
//recursive approach
// time comp => O(3^m)
int editDist(string str1, string str2, int m, int n){
    // If first string is empty, the only option is to insert all characters of second string into first
    if(m == 0)
        return n;
    // If second string is empty, the only option is to remove all characters of first string
    if(n == 0)
        return m;
    // If last characters of two strings are same, get count for remaining strings.
    if (str1[m - 1] == str2[n - 1])
        return editDist(str1, str2, m - 1, n - 1);
    // If last characters are not same, consider all three operations on last character of first string,
    // recursively compute minimum cost for all three operations and take minimum of three values.
    //insert
    int ans1 = editDist(str1, str2, m, n - 1);
	// remove
	int ans2 = editDist(str1, str2, m - 1, n);
    // replace
    int ans3 = editDist(str1, str2, m - 1, n - 1);
    
	return 1 + min(ans1, min(ans2, ans3));
}

int editDistance(string s1, string s2){
    return editDist(s1, s2, s1.length(), s2.length());
}
*/

//time comp => O(m*n)
int editDistance(string s1, string s2){
    int m = s1.length();
    int n = s2.length();
    
    int **dp = new int*[m+1];
    for(int i=0; i<=m; i++){
        dp[i] = new int[n+1];
    }
    
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            // If first string is empty, the only option is to insert all characters of second string into first
            if(i == 0)
                dp[i][j] = j;
            // If last characters of two strings are same, get count for remaining strings.
            else if(j == 0)
                dp[i][j] = i;
            // If last characters of two strings are same, get count for remaining strings.
            else if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            // If the last character is different, consider all possibilities and find the minimum
            else
                dp[i][j] = 1 + min( dp[i][j-1], min( dp[i-1][j-1], dp[i-1][j] ) );
        }
    }
    return dp[m][n];
}

int main() {
	string s1;
	string s2;

	cin >> s1;
	cin >> s2;

	cout << editDistance(s1, s2) << endl;
}

