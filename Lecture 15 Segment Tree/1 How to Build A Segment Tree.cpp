#include<bits/stdc++.h>
using namespace std;

// time comp => O(n)
// the nodes in the tree will be stred from 1st index
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

int main(){
	int n = 9;
	int arr[] = {1,2,3,4,5,6,7,8,9};
	
	int *tree = new int[2*n];
	
	buildTree(arr, tree, 0, 8, 1);
	
	for(int i=1; i<18; i++){
		cout << tree[i] <<endl;
	}
}
