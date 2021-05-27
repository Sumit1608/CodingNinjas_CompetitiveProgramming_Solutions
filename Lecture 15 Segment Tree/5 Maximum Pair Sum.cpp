#include<bits/stdc++.h>
using namespace std;

// the treenode stores the two maximum elements from range l to r


void buildTree(int *arr, pair<int, int> *tree, int start, int end, int treeNodeIndex){
	if(start == end){
		// tree[treeNodeIndex].first = arr[start];
        // tree[treeNodeIndex].second = INT_MIN;
		// or
        tree[treeNodeIndex] = make_pair(arr[start], INT_MIN);
		return;
	}
	int mid = (start+end)/2;
	buildTree(arr, tree, start, mid, 2*treeNodeIndex);
	buildTree(arr, tree, mid+1, end, 2*treeNodeIndex + 1);
    
    pair<int, int> leftSubtree = tree[2*treeNodeIndex];
    pair<int, int> rightSubtree = tree[2*treeNodeIndex+1];
    
    // calculating the max data we get from left and right subtree
    tree[treeNodeIndex].first = max( leftSubtree.first, rightSubtree.first);
    // calculating the second max data we get from left and right subtree
    tree[treeNodeIndex].second = min( max(leftSubtree.first, rightSubtree.second), max(leftSubtree.second, rightSubtree.first) );
	
}


void updateTree(int *arr, pair<int, int> *tree, int start, int end, int treeNodeIndex, int idx, int value){
	if(start == end){
        // update the value
		arr[idx] = value;
		tree[treeNodeIndex] = make_pair(value, INT_MIN);
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
	pair<int, int> leftSubtree = tree[2*treeNodeIndex];
    pair<int, int> rightSubtree = tree[2*treeNodeIndex+1];
    
    // updating the max data we get from left and right subtree
    tree[treeNodeIndex].first = max( leftSubtree.first, rightSubtree.first);
    // updating the second max data we get from left and right subtree
    tree[treeNodeIndex].second = min( max(leftSubtree.first, rightSubtree.second), max(leftSubtree.second, rightSubtree.first) );
	
}


pair<int, int> query(pair<int, int> *tree, int start, int end, int treeNodeIndex, int left, int right){
	// Completely outside given range
	if(start > right || end < left){
		pair<int,int> temp = make_pair(INT_MIN, INT_MIN);
		return temp;
	}
	// Completely inside given range
	if(start >= left && end <= right){
		return tree[treeNodeIndex];
	}
	// Partially inside and partially outside
	int mid = (start+end)/2;
	pair<int, int> ans1 = query(tree, start, mid, 2*treeNodeIndex, left, right);
	pair<int, int> ans2 = query(tree, mid+1, end, 2*treeNodeIndex + 1, left, right);
    
    pair<int, int> ans;
    ans.first = max(ans1.first, ans2.first);
    ans.second = min( max(ans1.first, ans2.second), max(ans1.second, ans2.first) );
	return ans;
}


int main() {
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n ; i++)
        cin >> arr[i];
    
    // first will store the maximum element of arr in range (l,r) and second will store the second max element
    pair <int, int>*tree = new pair<int, int>[4*n];
    buildTree(arr, tree, 0, n-1, 1);
    
    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        if(c == 'Q'){
            int l, r;
            cin >> l >> r;
            pair<int, int> ans = query(tree, 0, n-1, 1, l-1, r-1) ;
            cout << (ans.first + ans.second) << endl;
        }
        else{
            int idx, value;
            cin >> idx >> value;
            updateTree(arr, tree, 0, n-1, 1, idx-1, value);
        }
	}
}
