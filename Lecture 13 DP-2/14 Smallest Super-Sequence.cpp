#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

//time comp => O(n*m)
//method1 
// let str1 and str2 be two strings,  now find the longest common subsequence
// of both the strings,  then (str1.length() + str2.length() - lcs(str1, str2) ) 
// will be the required ans

// example =>  str1 = pqqrpt          str2 = qerepct
// lcs(str1, str2) = 4 ( "qrpt")
// now str1 ans str2 will be  subsequence of =>  "pqqerepct" or "pqeqrepct"
// which is basically   (str1.length() + str2.length() - lcs(str1, str2) )
int lcs(string s, string t){
	int m = s.length();
    int n = t.length();
    
    int** dp = new int*[m + 1];
	for (int i = 0; i <= m; i++) {
		dp[i] = new int[n + 1];
	}

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j<= n; j++) {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
			else if (s[i-1] == t[j-1]) 
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
    
    return dp[m][n];
}

int smallestSuperSequence(string str1, string str2){
	int ans = lcs(str1, str2);
    
    ans = (str1.length() + str2.length()) - ans;
    return ans;
}



// method 2 => using bottom up dp
/*
example => str1 = pqqrpt          str2 = qerepct    dp will be
	  q  e  r  e  p  c  t '\0' 
p	  9  9  8  8  7  7  6  6  
q	  8  8  7  7  6  6  5  5  
q	  7  7  6  6  5  5  4  4  
r	  7  6  5  5  4  4  3  3  
p	  7  6  5  4  3  3  2  2  
t	  7  6  5  4  3  2  1  1  
'\0'  7  6  5  4  3  2  1  0  

Let X[0..m - 1] and Y[0..n - 1] be two  strings and m and n be respective lengths.

  if (m == 0) return n;
  if (n == 0) return m;

  // If last characters are same, then  add 1 to result and recur for X[]
  if (X[m - 1] == Y[n - 1])
     return 1 + SCS(X, Y, m - 1, n - 1);

  // Else find shortest of following two
  //  a) Remove last character from X and recur
  //  b) Remove last character from Y and recur
  else 
    return 1 + min( SCS(X, Y, m - 1, n), SCS(X, Y, m, n - 1) );
*/
/*
int smallestSuperSequence(string str1, string str2){
	int m = str1.length();
    int n = str2.length();
    
    int dp[m+1][n+1];
    int count =0;
    for(int i = n; i >= 0; i--){
        dp[m][i] = count;
        count++;
    }
    count=0;
    for(int i = m; i >= 0; i--){
        dp[i][n] = count;
        count++;
    }
    
    for(int i = m-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(str1[i] == str2[j] )
                dp[i][j] = 1 + dp[i+1][j+1];
            else
                dp[i][j] = 1 + min( dp[i+1][j], dp[i][j+1]);
        }
    }
    
    return dp[0][0];
}
*/










// method 3 =>  top down dp
/*
example => str1 = pqqrpt          str2 = qerepct    dp will be
	 '\0' q  e  r  e  p  c  t  
'\0'   0  1  2  3  4  5  6  7  
p      1  2  3  4  5  5  6  7  
q	   2  2  3  4  5  6  7  8  
q	   3  3  4  5  6  7  8  9  
r	   4  4  5  5  6  7  8  9  
p	   5  5  6  6  7  7  8  9  
t	   6  6  7  7  8  8  9  9  

*/
/*
int smallestSuperSequence(string str1, string str2){
	int m = str1.length();
    int n = str2.length();
    
    int dp[m+1][n+1];
    int count =0;
    for(int i = 0; i <= n; i++){
        dp[0][i] = count;
        count++;
    }
    count=0;
    for(int i = 0; i <= m; i++){
        dp[i][0] = count;
        count++;
    }
    
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(str1[i-1] == str2[j-1] )
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = 1 + min( dp[i-1][j], dp[i][j-1]);
        }
    }
    
    for(int i = 0; i <= m; i++){
        cout <<"  ";
        for(int j = 0; j <= n; j++){
            cout << dp[i][j] <<"  ";
        }
        cout <<endl;
    }
    return dp[m][n];
}
*/

int main()
{
    string str1, str2;
    cin >> str1;
    cin >> str2;
    cout << smallestSuperSequence(str1, str2);
    return 0;
}
