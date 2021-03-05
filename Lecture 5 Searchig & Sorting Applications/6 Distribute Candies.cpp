#include<bits/stdc++.h>
using namespace std;

//Time comp => O(nlogk)
//Take input ok the candies in each boxes, then we search for the largest number of 
//candies that students can get.  We take mid btw 0 and 10^9 and then check if that 
//no of candies can be distributed or not.
//We check by divinding each box's no of candies with no of candies so that we can get count
//of how many children can get, if count is greater than numChild, than we return true, and 
//check again after making start= mid+1,  if it had returned false, we check for mid with end = mid-1.


bool check(long long *arr, int n, long long numCandies, long long numChild ){
    long long count =0;
    for(int i=0; i<n; i++){
        count += arr[i]/numCandies;
    }
    if(count >= numChild){
        return true;
    }
    return false;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >>n;
        long long k;
        cin>>k;
        
        long long arr[n];
        for(int i=0; i<n; i++){
            cin >>arr[i];
        }
        
        long long start = 0; 
        long long end = 10e9;
        long long ans = 0;
        
        while(start <= end){
            long long mid = (start + end)/2;
            if( check(arr, n, mid, k)){
                start = mid+1;
                ans = mid;
            } else{
                end = mid-1;
            }
        }
        
        cout << ans << endl;
    }
}
