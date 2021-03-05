#include<iostream>
using namespace std;

//Time comp =. O(qLogn)
//Make another array which stores the cummualtive sum of the momos price
//starting from the starting shop, then by using binary search search for
//ith shop number till which the girl can buy momos.

int search(long arr[], int low, int high, long x){ 
    if(low>high) { 
        return -1; 
    } 
    if(x>=arr[high]) {
        return high; 
    } 
    int mid=(low+high)/2;
    if(arr[mid]==x) { 
        return mid;
    }
    if(mid>0 && arr[mid-1]<=x && x<arr[mid]) {
        return mid-1;
    }
    if(x<arr[mid]) { 
        return search(arr,low,mid-1,x); 
    } 
    return search(arr,mid+1,high,x); 
}

int main() {
    int n;
    cin>>n;
    long* arr=new long[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    } 
    long* prefix=new long[n];
    prefix[0]=arr[0];
    for(int i=1;i<n;i++) { 
        prefix[i]=prefix[i-1]+arr[i]; 
    } 
    
    int q;
    cin>>q;
    while(q-->0) {
        long x;
        cin>>x;
        int s=search(prefix,0,n-1,x);
        long val=x;
        if(s!=-1) {
            val-=prefix[s];
        }
        cout<<s+1<<" "<<val<<endl;
    }
}

/*
#include<bits/stdc++.h>
using namespace std;

//Time compl => O(q*n)
//Simply start buying momos from the starting shop one by one till the money
//becomes insufficient to buy momos from ith shop, then print the count and saved money
 
void solution(long long arr[], int n, long long money){
    long long sum =0;
    long long count=0;
    for(int i=0; i<n; i++){
        if(sum + arr[i] <= money){
            sum += arr[i];
            count++;
        } else{
            break;
        }
    }
    cout << count <<" "<< (money - sum) ;
}

int main()
{
    int n;
    cin >>n;
    long long arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int q;
    cin >> q;
    
    while(q--){
        long long money;
        cin>>money;
        solution(arr, n, money);
        cout << endl;
    }
}
*/

