#include<bits/stdc++.h>
using namespace std;

/*
Segment Trees can be used to solve this problem.Here, we need to keep information regarding various cumulative sums.
At every Node we store the following:
1) Maximum Prefix Sum,
2) Maximum Suffix Sum,
3) Total Sum,
4) Maximum Subarray Sum

A classical Segment Tree with each Node storing the above information should be enough to aswer each query. The only 
focus here is on how the left and the right Nodes of the tree are merged together. Now, we will discuss how each of the 
information is constructed in each of the segment tree Nodes using the information of its left and right child.

Maximum Prefix Sum = max( Maximum Prefix Sum of Left Child, Total Sum of Left Child + Maximum Prefix Sum of Right Child)
Maximum Suffix Sum = max(Maximum Suffix Sum of Right Child, Total Sum of Right Child + Maximum Suffix Sum of Left Child)
Total sum = left child total sum + Right child total sum
Maximum Sub-array Sum = max(Maximum Subarray Sum of Left Child, Maximum Subarray Sum of Right Child, Maximum Prefix Sum of Right + Maximum Suffix Sum of Left Child )

*/
struct node {
	int max_sum;
	int sum;
	int best_prefix_sum;
	int best_suffix_sum;
};

void build_tree(int* arr, node* tree, int start, int end, int treenode){
	if (start == end){
		tree[treenode].sum = arr[start];
		tree[treenode].max_sum = arr[start];
		tree[treenode].best_suffix_sum = arr[start];
		tree[treenode].best_prefix_sum = arr[start];
		return;
	}
    
	int mid = (start + end) / 2;
	build_tree(arr, tree, start, mid, 2 * treenode);
	build_tree(arr, tree, mid + 1, end, 2 * treenode + 1);
    
	tree[treenode].sum = tree[2 * treenode].sum + tree[2 * treenode + 1].sum;
	tree[treenode].best_prefix_sum = max(tree[2 * treenode].best_prefix_sum, tree[2 * treenode].sum + tree[2 * treenode + 1].best_prefix_sum);
	tree[treenode].best_suffix_sum = max(tree[2 * treenode + 1].best_suffix_sum, tree[2 * treenode + 1].sum + tree[2 * treenode].best_suffix_sum);
	
    tree[treenode].max_sum = max(tree[2 * treenode].max_sum, max(tree[2 * treenode + 1].max_sum, 
                                max( tree[2 * treenode].sum + tree[2 * treenode + 1].best_prefix_sum,
								max(tree[2 * treenode + 1].sum + tree[2 * treenode].best_suffix_sum, 
                                    tree[2 * treenode].best_suffix_sum + tree[2 * treenode + 1].best_prefix_sum) ) ) );
}

node query(node* tree, int start, int end, int treenode, int left, int right){
	//completely outside
	if (start > right || end < left){
        node ans;
        ans.max_sum = -100000;
        ans.sum = -100000;
        ans.best_suffix_sum = -100000;
        ans.best_prefix_sum = -100000;
		return ans;
	}
	//completely inside
	if (start >= left && end <= right){
		return tree[treenode];
	}
	
    //partially outside and partially inside
	int mid = (start + end) / 2;
	node q1 = query(tree, start, mid, 2 * treenode, left, right);
	node q2 = query(tree, mid + 1, end, 2 * treenode + 1, left, right);
	
    node ans;
	ans.sum = q1.sum + q2.sum;
	ans.best_prefix_sum = max(q1.best_prefix_sum, q1.sum + q2.best_prefix_sum);
	ans.best_suffix_sum = max(q1.best_suffix_sum + q2.sum, q2.best_suffix_sum);
	ans.max_sum = max(q1.max_sum, max(q2.max_sum, max(q1.sum + q2.best_prefix_sum, max(q2.sum + q1.best_suffix_sum, q1.best_suffix_sum + q2.best_prefix_sum) ) ) );
	return ans;
}

int main(){
	int n;
	cin >> n;
	int* arr = new int[n];
	node* tree = new node[4 * n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	build_tree(arr, tree, 0, n - 1, 1);
	
    int m;
	cin >> m;
	while (m--){
		int xi, yi;
		cin >> xi >> yi;
		cout << query(tree, 0, n - 1, 1, xi-1, yi-1).max_sum << endl;
	}
}




