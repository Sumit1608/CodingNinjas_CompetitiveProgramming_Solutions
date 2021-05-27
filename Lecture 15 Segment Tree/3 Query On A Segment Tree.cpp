#include<bits/stdc++.h>
using namespace std;

void buildTree(int *arr, int *tree, int start, int end, int treeNodeIndex){
	if(start == end){
		tree[treeNodeIndex] = arr[start];
		return;
	}
	int mid = (start+end)/2;
	buildTree(arr, tree, start, mid, 2*treeNodeIndex);
	buildTree(arr, tree, mid+1, end, 2*treeNodeIndex + 1);
	
	tree[treeNodeIndex] = tree[2*treeNodeIndex] + tree[2*treeNodeIndex + 1];
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
	
	tree[treeNodeIndex] = tree[2*treeNodeIndex] + tree[2*treeNodeIndex + 1];
}

// time comp => O(logn)
// calculating the sum of subset arr[l, r]
int query(int *tree, int start, int end, int treeNodeIndex, int left, int right){
	// Completely outside given range
	if(start > right || end < left){
		return 0;
	}
	// Completely inside given range
	if(start >= left && end <= right){
		return tree[treeNodeIndex];
	}
	// Partially inside and partially outside
	int mid = (start+end)/2;
	int ans1 = query(tree, start, mid, 2*treeNodeIndex, left, right);
	int ans2 = query(tree, mid+1, end, 2*treeNodeIndex + 1, left, right);
	return ans1+ans2;
}


int main(){
	int n = 5;
	int arr[] = {1,2,3,4,5};
	
	int *tree = new int[2*n];	
	buildTree(arr, tree, 0, 4, 1);
	
	for(int i=1; i<10; i++){
		cout << tree[i] <<" ";
	}
	cout << endl;
	// we change arr[2] = 10
	updateTree(arr, tree, 0, 4, 1, 2, 10);
	
	for(int i=1; i<10; i++){
		cout << tree[i] <<" ";
	}
	cout << endl;
	
	// let subset be arr[2,4]
	int ans = query(tree, 0, 4, 1, 2, 4);
	cout << ans << endl;
}
