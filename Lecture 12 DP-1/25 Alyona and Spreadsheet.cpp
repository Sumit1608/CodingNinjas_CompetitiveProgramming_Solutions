#include <bits/stdc++.h>
using namespace std;

//time comp => O(n*m)
//For each cell (i, j) compute value up(i, j) equal to minimum r, such that table is 
//non-decreasing in row j if we keep only rows from r to i inclusive. This values can be 
//computed in O(nm) time using the following formulas:
//dp(i, j) = dp(i - 1, j) + 1, if arr[i][j] >= arr[i-1][j];
//dp(i, j) = i+1 otherwise.

//for example arr = 1 2 3 5
//                  3 1 3 2
//                  4 5 2 3
//                  5 5 3 2
//                  4 4 3 4
//the dp wpuld be dp => 1 1 1 1 
//                      1 2 1 2 
//                      1 2 3 2 
//                      1 2 3 4 
//                      5 5 3 4
//Now, store the miminum value from each row to get the maximum increasing non- decreasing sequence from
//ith row to rth row      ans = {1, 1, 2, 2, 3}
//We can simply check for l, r   whether ans[r-1] <= l or not

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin>>n >> m;
    int **arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[m];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >>arr[i][j];
        }
    }
    
    int **dp = new int*[n];
    for(int i=0; i<n; i++){
        dp[i] = new int[m];
    }
    
    for(int i=0; i<m; i++){
        dp[0][i] =1;
    }
    
    for(int j=0; j<m; j++){
        for(int i=1; i<n; i++){
            if(arr[i][j] >= arr[i-1][j]){
                dp[i][j] = dp[i-1][j];
            } else{
                dp[i][j] = i+1;
            }
        }
    }
    
    int *ans = new int[n];
    ans[0] =1;
    for(int i=1; i<n; i++){
        int temp = INT_MAX;
        for(int j=0; j<m; j++){
            temp = min(temp, dp[i][j]);
        }
        ans[i] = temp;
    }
    
    int q;
    cin>>q;
    while(q--){
        int l, r;
        cin >>l >> r;
        
        if(ans[r-1] <= l){
            cout <<"Yes" <<endl;
        } else{
            cout <<"No" <<endl;
        }
    }
}

/*
This problem can be done using oneD arrays,  in which we take two rows at a time and then 
store the ans of the rows by comparing in two dp arrays
The final ans is stored in the another array by comparison

int minimum_element(int *arr, int n){
    int minimum = INT_MAX;
    for (int i = 0; i < n; i++)
        minimum = min(minimum, arr[i]);
    return minimum;
}

int main(){
    int n, m;
    cin >> n >> m;
    int *first_row = new int[m];
    int *second_row = new int[m];

    int *first_dp = new int[m];
    int *second_dp = new int[m];

    int *minimum_row_entry = new int[n];

    for (int i = 0; i < m; i++)
        cin >> first_row[i];
    for (int i = 0; i < m; i++)
        cin >> second_row[i];

    for (int i = 0; i < m; i++)
        first_dp[i] = 0;

    for (int i = 0; i < m; i++){
        if (second_row[i] >= first_row[i])
            second_dp[i] = 0;
        else
            second_dp[i] = 1;
    }
    minimum_row_entry[0] = minimum_element(first_dp, m);
    minimum_row_entry[1] = minimum_element(second_dp, m);

    for (int i = 2; i < n; i++){
        for (int i = 0; i < m; i++)
            first_dp[i] = second_dp[i];

        for (int j = 0; j < m; j++)
            first_row[j] = second_row[j];

        for (int j = 0; j < m; j++)
            cin >> second_row[j];
        
        //Now I have my first and second rows ready.
        for (int j = 0; j < m; j++){
            if (first_row[j] <= second_row[j])
                second_dp[j] = first_dp[j];
            else
                second_dp[j] = i;
        }
        minimum_row_entry[i] = minimum_element(second_dp, m);
    }

    int k;
    cin >> k;
    while (k--){
        int l, r;
        cin >> l >> r;
        if (minimum_row_entry[r - 1] < l)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}

*/

