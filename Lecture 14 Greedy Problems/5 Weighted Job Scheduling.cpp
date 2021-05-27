#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// time comp => O(nlogn)
/*
1) First sort jobs according to finish time.
2) Now apply following recursive process. 
   // Here arr[] is array of n jobs
   findMaximumProfit(arr[], n){
     a) if (n == 1) return arr[0];
     b) Return the maximum of following two profits.
         (i) Maximum profit by excluding current job, i.e., findMaximumProfit(arr, n-1)
         (ii) Maximum profit by including the current job            
   }
   
For each i from 1 to n, determine the maximum value of the schedule from the subsequence of jobs[0..i]. 
Do this by comparing the inclusion of job[i] to the schedule to the exclusion of job[i] to the schedule, and then taking the max.
*/

struct Job{
    int start, finish, profit;
};

// utility function to sort the array w.r.t. to the finish time 
bool compare(struct Job a, struct Job b){
    return (a.finish < b.finish);
}

// A Binary Search based function to find the latest job (before current job) that doesn't conflict with current
// job.  "index" is index of the current job.  This function returns -1 if all jobs before index conflict with it.
// The array jobs[] is sorted in increasing order of finish time.
int binarySearch(struct Job arr[], int i){
    int start = 0, end= i-1;
    while(start <= end){
        int mid = (start+end)/2;
        if( arr[mid].finish <= arr[i].start ){
            if( arr[mid+1].finish <= arr[i].start )
                start = mid+1;
            else
                return mid;
        }
        else
            end = mid-1;
    }
    return -1;
}

int maxProfit(struct Job arr[], int n){
    sort(arr, arr+n, compare);
    // Create an array to store solutions of subproblems.dp[i] stores the profit for jobs till arr[i] (including arr[i])
    int *dp = new int[n];
    dp[0] = arr[0].profit;
    
    for(int i = 1; i < n; i++){
        int profitIncluding = arr[i].profit;
        int index = binarySearch(arr, i);
        if(index != -1)
            profitIncluding += dp[index];
        // time comp becomes O(n^2) if we search element by this loop
        // for(int j = i-1; j >= 0; j--){
        //     if(arr[j].finish <= arr[i].start){
        //         profitIncluding += dp[j];
        //         break;
        //     }
        // }
        dp[i] = max(profitIncluding, dp[i-1]);
    }
    
    return dp[n-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    Job *arr = new Job[n];
    for(int i=0; i<n; i++)
        cin >> arr[i].start >> arr[i].finish >> arr[i].profit ;
    
    cout << maxProfit(arr, n) << endl;
    
    return 0;
}



