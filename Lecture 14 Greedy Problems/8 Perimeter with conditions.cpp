#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// time comp => O(nlogn)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n ;
    
	int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >>arr[i];
    }
    
    // sort array in decreasing order
    sort(arr, arr+n, greater<int>());
    int maxPerimeter = 0 ;
    int a,b,c;
    
    // now, as the array is sorted arr[i] >= arr[i+1] >= arr[i+2]
    // so, they will form a triangle if    arr[i] < (arr[i+1]+arr[i+2])
    // as we have to choose the max perimeter with max sides, so our first 
    // legal triangle will be our answer as array is sorted
    for(int i=0; i<n-2; i++){
        if(arr[i] < (arr[i+1]+arr[i+2]) ){
            maxPerimeter = arr[i] + arr[i+1] + arr[i+2];
            a = arr[i];
            b = arr[i+1];
            c = arr[i+2];
            break;
        }
    }
    
    if(maxPerimeter == 0)
        cout << -1 <<endl;
    else
        cout << c <<" "<<b<<" "<<a<<endl;
    
    return 0;
}



