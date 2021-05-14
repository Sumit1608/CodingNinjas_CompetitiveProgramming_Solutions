#include <bits/stdc++.h>
using namespace std;

// time comp => O(n*budget)
// similar problem like knapsack, but here to calculate the minimum weight for max value possible
// so, this can be achieved using two methods : either use pair or use variables to store the max value and maxweight corresponding to that
int main(){
    int budget, n;
    cin >> budget >> n;
    while( budget != 0 && n!= 0){
        int *cost = new int[n];
        int *fun = new int[n];
        for(int i=0; i<n; i++){
            cin >> cost[i] >> fun[i];
        }
        
        int dp[n+1][budget+1];
        int expense = 0, maxValue =0;
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=budget; j++){
            	if( i == 0 || j == 0 )
                    dp[i][j] = 0;
                else{
                    if(cost[i-1] > j)
                        dp[i][j] = dp[i-1][j];
                    else
                        dp[i][j] = max(dp[i-1][j], fun[i-1] + dp[i-1][j - cost[i-1]]);
                }
                if(dp[i][j] > maxValue ){
                    maxValue = dp[i][j];
                    expense = j;
                }
                else if(dp[i][j] == maxValue && j < expense)
                    expense = j;
        	}
        }
        cout << expense << " " << maxValue<<endl;
        cin >> budget >> n;
    }
    return 0;
}


// using pairs
/*
pair<int, int> most_fun(int* enterance_fees, int* fun, int budget, int n, pair<int, int>**dp){
	if (n == 0){
		pair<int, int> p;
		p.first = 0;
		p.second = 0;
		return p;
	}
    
	if (dp[budget][n].first != -1 && dp[budget][n].second != -1)
		return dp[budget][n];
	
	pair<int, int> ans;
	if (enterance_fees[0] <= budget){
		pair<int, int>option1 = most_fun(enterance_fees + 1, fun + 1, budget - enterance_fees[0], n - 1, dp);
		option1.first += enterance_fees[0];
		option1.second += fun[0];
		pair<int, int>option2 = most_fun(enterance_fees + 1, fun + 1, budget, n - 1, dp);
		
        if (option1.second > option2.second)
			ans= option1;
		else if (option2.second > option1.second)
			ans= option2;
		else{
			if (option1.first < option2.first)
				ans= option1;
			else
				ans= option2;
		}
	}
	else
		ans= most_fun(enterance_fees + 1, fun + 1, budget, n - 1, dp);
	
	dp[budget][n] = ans;
	return ans;
}

int main(){
	while (true){
		int budget;
		int n;
		cin >> budget >> n;
		if (budget == 0 && n == 0){
			break;
		}
        
		int* enterance_fees = new int[n];
		int* fun = new int[n];
		for (int i = 0; i < n; i++)
			cin >> enterance_fees[i] >> fun[i];
		
		pair<int, int>** dp = new pair<int, int> * [budget+1];
		for (int i = 0; i < budget+1; i++){
			dp[i] = new pair<int, int>[n + 1];
			for (int j = 0; j < n + 1; j++){
				dp[i][j].first = -1;
				dp[i][j].second = -1;
			}
		}

		pair<int, int> p;
		p = most_fun(enterance_fees, fun, budget, n, dp);
		cout << p.first << ' ' << p.second << endl;

		for (int i = 0; i < budget + 1; i++)
			delete[]dp[i];
		delete[]dp;
	}
}
*/
