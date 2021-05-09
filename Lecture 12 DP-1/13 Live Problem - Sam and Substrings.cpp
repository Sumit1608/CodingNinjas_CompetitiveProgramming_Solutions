#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int substrings(string s){
	long long totalSum = s[0] -'0';
	long long lastValue = s[0] - '0';
	
	for(int i=1; i<s.length(); i++){
		lastValue = lastValue*10 + (s[i] - '0')*(i+1);
		lastValue = lastValue%mod;
		totalSum = (totalSum + lastValue) % mod ;
	}
	
	return totalSum;
}

//time comp=> O(n)
int main(){
	string s;
	cin >>s;
	cout << substrings(s)<<endl;
}

/*
Let's look at the algorithm for N = 5312,

all possible substrings are

5 3 1 2 53 31 12 531 312 5312
with a little bit of rearrangement,

5  |  3 53  |  1 31 531  |   2 12 312 5312
The above rearrangement lists all numbers that ends with 5, 3, 1 and 2 respectively.

Let sd[i] hold the sum of all digits that ends at N[i] i.e.,

sd[0] holds the sum of all digits that ends at N[0] = 5
sd[1] holds the sum of all digits that ends at N[1] = 3
sd[2] holds the sum of all digits that ends at N[2] = 1
sd[3] holds the sum of all digits that ends at N[3] = 2

If S is the final answer, then we have

S = sd[0] + sd[1] + sd[2] + sd[3] 
ie., S = ? sd[i] ? 0 = i < len(N)

Now, given sd[i], let us see if we can calculate sd[i+1].

sd[2] = 1 + 31 + 531 = 563

sd[3] = 2 + 12 + 312 + 5312
sd[3] = 2 + 10 + 2 + 310 + 2 + 5310 + 2
sd[3] = 4 * 2 + 10 * (1 + 31 + 531 )
sd[3] = (3 + 1) * *N[3]* + 10 * *sd[2]*
on generalising, we get

sd[i+1] = (i + 2) * N[i] + 10 * sd[i]
sd[0] = N[0]

*/
