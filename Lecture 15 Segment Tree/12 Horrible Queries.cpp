#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;


void update(ll *tree, ll *lazy, ll start, ll end, ll treeNode, ll left, ll right, ll value){
    if(start > end)
        return;
    if(lazy[treeNode] != 0){
        tree[treeNode] += (end - start + 1) * lazy[treeNode];
        if(start != end){
            lazy[2 * treeNode] += lazy[treeNode];
			lazy[2 * treeNode + 1] += lazy[treeNode];
        }
        lazy[treeNode] = 0;
    }
    
    //completely outside
	if (start > right || end < left)
		return;
	//completely inside
	if (start >= left && end <= right){
		tree[treeNode] += (end - start + 1) * value;
		if(start != end){
            lazy[2 * treeNode] += value;
			lazy[2 * treeNode + 1] += value;
        }
		return;
	}
	//partial overlap
	ll mid = (start + end) / 2;
	update(tree, lazy, start, mid, 2*treeNode, left, right, value);
	update(tree, lazy, mid + 1, end, 2*treeNode+1, left, right, value);
	tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
	return;
}


ll query(ll *tree, ll *lazy, ll start, ll end, ll treeNode, ll left, ll right){
    if(start > end)
        return 0;
    if(lazy[treeNode] != 0){
        tree[treeNode] += (end - start + 1) * lazy[treeNode];
        if(start != end){
            lazy[2 * treeNode] += lazy[treeNode];
			lazy[2 * treeNode + 1] += lazy[treeNode];
        }
        lazy[treeNode] = 0;
    }
    
    //completely outside
	if (start > right || end < left)
		return 0;
	//completely inside
	if (start >= left && end <= right)
        return tree[treeNode];
	//partial overlap
	ll mid = (start + end) / 2;
	ll leftAns = query(tree, lazy, start, mid, 2*treeNode, left, right);
	ll rightAns = query(tree, lazy, mid + 1, end, 2*treeNode+1, left, right);
	return leftAns + rightAns;
}


int main() {
    ll t;
    cin >>t;
    while(t--){
	    ll n, q;
	    cin >> n >> q;
	    ll *tree = new ll[4*n]();
        ll *lazy = new ll[4*n]();
	    
	    while(q--){
	        ll type, left, right;
	        cin >> type >> left >> right;
	        if(type == 0){
	            ll value;
	            cin >> value;
	            update(tree, lazy, 0, n-1, 1, left-1, right-1, value);
	        } else{
	            cout << query(tree, lazy, 0, n-1, 1, left-1, right-1) << endl;
	        }
	    }
    }
}
