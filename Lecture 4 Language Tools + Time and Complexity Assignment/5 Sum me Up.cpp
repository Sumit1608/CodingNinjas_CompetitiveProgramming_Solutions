#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll digitSum(ll n){
    if(n <10){
        return n;
    }
    return n%10 + digitSum(n/10);
}

int main() {
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin >>n;
        cout << digitSum(n) <<endl;
    }
}
