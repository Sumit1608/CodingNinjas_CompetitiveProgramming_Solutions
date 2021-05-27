#include<bits/stdc++.h>
using namespace std;

// time comp => O(nlogn)      sorting
//You are given n activities with their start and finish times. Select the maximum 
//number of activities that can be performed by a single person, assuming that a person 
//can only work on a single activity at a time. 

//explanation
//The greedy choice is to always pick the next activity whose finish time is least among 
//the remaining activities and the start time is more than or equal to the finish time of 
//the previously selected activity. We can sort the activities according to their finishing 
//time so that we always consider the next activity as minimum finishing time activity.
//1) Sort the activities according to their finishing time 
//2) Select the first activity from the sorted array and let ans be 1. 
//3) For the remaining activities in the sorted array, if the start time of this activity is 
//greater than or equal to the finish time of the previously selected activity then select this 
//activity and increment ans.

bool compare(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second < b.second);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector< pair <int,int> > arr;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a>> b;
        arr.push_back( make_pair(a,b) );
    }
    
    // sorting the vector in ascedning order in respect to the second element 
    sort(arr.begin(), arr.end(), compare);
    
    int ans = 1;
    pair<int, int> temp = arr[0];
    for(int i=1; i<n; i++){
        if(temp.second <= arr[i].first){
            ans++;
            temp = arr[i];
        }
    }
    cout << ans << endl;
    
    return 0;
}
