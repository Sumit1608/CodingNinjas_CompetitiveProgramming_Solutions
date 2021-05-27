#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// time comp => 

bool compare(const pair<int, int> &a, const pair<int, int> &b){
	if(a.second != b.second){
		return a.second > b.second;
	}
	return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k;
    cin >> n >> k;
    pair<int, int> *pieces = new pair<int, int>[n];
    for(int i=0; i<n; i++)
        cin >> pieces[i].first >> pieces[i].second ;
    sort(pieces, pieces+n, compare);
    
    multiset<int> m;
    int weight;
    for(int i=0; i<k; i++){
    	cin >> weight;
    	m.insert(weight);
	}
	
	ll ans =0;
	for(int i=0; i<n; i++){
		if(m.empty()){
			break;
		} 
		else if( m.lower_bound(pieces[i].first) != m.end() ) {
			ans += pieces[i].second;
			m.erase( m.lower_bound(pieces[i].first) );
		}
	}
	
	cout << ans <<endl;
	
    return 0;
}

/*
3 2
1 65
5 23
2 99
10
2


164
*/


