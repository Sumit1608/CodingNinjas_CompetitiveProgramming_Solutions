#include<bits/stdc++.h>
using namespace std;

/*
Segment tree can be used to do preprocessing and query in moderate time. With segment tree, preprocessing 
time is O(n) and time to for range minimum query is O(Logn). The extra space required is O(n) to store the segment tree.

Another solution is to create a 2D array where an entry [i, j] stores the minimum value in range arr[i..j]. 
Minimum of a given range can now be calculated in O(1) time, but preprocessing takes O(n^2) time. Also, this 
approach needs O(n^2) extra space which may become huge for large input arrays.

Time Complexity:
=>for tree construction is O(n). There are total 2n-1 nodes, and value of every node is calculated only once in tree construction.
=>to query is O(Logn). To query a range minimum, we process at most two nodes at every level and number of levels is O(Logn).
*/
void buildTree(int *arr, int *tree, int start, int end, int treeNodeIndex){
	if(start == end){
		tree[treeNodeIndex] = arr[start];
		return;
	}
	int mid = (start+end)/2;
	buildTree(arr, tree, start, mid, 2*treeNodeIndex);
	buildTree(arr, tree, mid+1, end, 2*treeNodeIndex + 1);
	
	tree[treeNodeIndex] = min( tree[2*treeNodeIndex], tree[2*treeNodeIndex + 1] );
}


void updateTree(int *arr, int *tree, int start, int end, int treeNodeIndex, int idx, int value){
	if(start == end){
		arr[idx] = value;
		tree[treeNodeIndex] = value;
		return;
	}
	
	int mid = (start+end)/2;
	if(idx > mid){
		// call on right subtree to update
		updateTree(arr, tree, mid+1, end, 2*treeNodeIndex+1, idx, value);
	} else{
		// left subtree will update the value
		updateTree(arr, tree, start, mid, 2*treeNodeIndex, idx, value);
	}
	
	tree[treeNodeIndex] = min( tree[2*treeNodeIndex], tree[2*treeNodeIndex + 1] );
}


int query(int *tree, int start, int end, int treeNodeIndex, int left, int right){
	// Completely outside given range
	if(start > right || end < left){
		return INT_MAX;
	}
	// Completely inside given range
	if(start >= left && end <= right){
		return tree[treeNodeIndex];
	}
	// Partially inside and partially outside
	int mid = (start+end)/2;
	int ans1 = query(tree, start, mid, 2*treeNodeIndex, left, right);
	int ans2 = query(tree, mid+1, end, 2*treeNodeIndex + 1, left, right);
	return min(ans1, ans2);
}


int main() {
    int n, q;
    cin >> n >> q;
    int *arr = new int[n];
    for(int i = 0; i < n ; i++)
        cin >> arr[i];
    
    int *tree = new int [4*n];
    buildTree(arr, tree, 0, n-1, 1);
    
    while(q--){
        char c;
        cin >> c;
        if(c == 'q'){
            int l, r;
            cin >> l >> r;
            cout << query(tree, 0, n-1, 1, l-1, r-1) <<endl;
        } else{
            int idx, value;
            cin >> idx >> value;
            updateTree(arr, tree, 0, n-1, 1, idx-1, value);
        }
	}
}
