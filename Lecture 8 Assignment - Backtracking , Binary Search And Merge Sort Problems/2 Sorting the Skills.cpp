#include<bits/stdc++.h>
using namespace std;

//Time comp => O(n)
//A linear CPP program to check if array becomes sorted after swaps with adjacent elements
bool check(int *arr, int n){
    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            if(arr[i] - arr[i+1] == 1)
                swap(arr[i], arr[i+1]);
            else
                return false;
        }
    }
    return true;
}

int main(){
    int t;
    cin >>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin >>arr[i];
        }
        if( check(arr, n) ){
            cout<< "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
	return 0;
}

