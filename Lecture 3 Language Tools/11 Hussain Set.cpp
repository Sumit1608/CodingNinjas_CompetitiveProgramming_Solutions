#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, m;
    cin>>n>>m;
    //Make an array and insert element
    ll arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
	sort(arr, arr+n);
    // Now we make a queue that will contain the element of array when divided by 2
    queue<ll> q;
    //Count_m keeps the count of mth turn
    int count_m =0;
    int end_p = n-1;

    while(m--){
        int curr_m;
        cin>>curr_m;
        //We store the element to be pushed in queue in the ans
        int ans;

		//We run the loop till the required mth query/turn
        for(; count_m < curr_m; count_m++){
        	//Check the element which is greater in queue or array and insert it in q after dividing it by 2
            if( end_p>=0 && (q.empty() || arr[end_p] >= q.front() ) ){
                ans = arr[end_p];
                end_p--;
            }
            else{
                ans = q.front();
                q.pop();
            }
            q.push(ans/2);
        }
        cout<< ans << endl;
    }
}
