#include<bits/stdc++.h>
using namespace std;


struct node{
    int even;
    int odd;
};


void buildTree(int *arr, node *tree, int start, int end, int treeNode){
    if(start == end){
        if(arr[start]%2 == 0){
            tree[treeNode].odd = 0;
            tree[treeNode].even = 1;
        } else{
            tree[treeNode].odd = 1;
            tree[treeNode].even = 0;
        }
        return;
    }
    
    int mid = (start+end)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);
    
    tree[treeNode].odd = tree[2*treeNode].odd + tree[2*treeNode +1].odd ;
    tree[treeNode].even = tree[2*treeNode].even + tree[2*treeNode +1].even ;
}


void update(int *arr, node *tree, int start, int end, int treeNode, int idx, int value){
    if(start == end){
        arr[idx] = value;
        if(value%2 == 0){
            tree[treeNode].odd = 0;
            tree[treeNode].even = 1;
        } else{
            tree[treeNode].odd = 1;
            tree[treeNode].even = 0;
        }
        return;
    }
    
    int mid = (start+end)/2;
    // right subtree
    if(idx > mid)
        update(arr, tree, mid+1, end, 2*treeNode+1, idx, value);
    else
        update(arr, tree, start, mid, 2*treeNode, idx, value);
    
    tree[treeNode].odd = tree[2*treeNode].odd + tree[2*treeNode +1].odd ;
    tree[treeNode].even = tree[2*treeNode].even + tree[2*treeNode +1].even ;
}


node query(node *tree, int start, int end, int treeNode, int left, int right){
    // completely outside
    node ans;
    if(start > right || end < left){
        ans.even =0;
        ans.odd =0;
        return ans;
    }
    // completely overlapping
    if(start >= left && right >= end){
        return tree[treeNode];
    }
    //partially overlapping
    int mid = (start + end) / 2;
	node left_child = query(tree, start, mid, 2*treeNode, left, right);
	node right_child = query(tree, mid+1, end, 2*treeNode+1, left, right);
	ans.even = left_child.even + right_child.even;
	ans.odd = left_child.odd + right_child.odd;
	return ans;
}


int main() {
	int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    node *tree = new node[4*n]();
    buildTree(arr, tree, 0, n-1, 1);
    
    int q;
    cin >> q;
    while(q--){
        int num, x, y;
        cin >> num >> x >> y;
        if(num  == 0){
            update(arr, tree, 0, n-1, 1, x-1, y);
        }
        else if(num == 1){
            cout << query(tree, 0, n-1, 1, x-1, y-1).even << endl;
        }
        else{
            cout << query(tree, 0, n-1, 1, x-1, y-1).odd << endl;
        }
    }
    
}


