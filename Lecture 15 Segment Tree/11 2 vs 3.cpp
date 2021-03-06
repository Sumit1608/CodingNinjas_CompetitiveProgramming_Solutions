#include<bits/stdc++.h>
using namespace std;


int power[100001];
void buildPower(){
    power[0] = 1;
    for(int i = 1; i < 100001; i++)
        power[i] = (power[i-1]*2) % 3;
}


void buildTree(int *arr, int *tree, int start, int end, int treeNode){
    if(start == end){
        tree[treeNode] = arr[start] ;
        return;
    }
    int mid = (start+end)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);
    
	int left = tree[2 * treeNode];
    int right = tree[2 * treeNode + 1];
	tree[treeNode] = (power[end-mid]*left + right) % 3;
}


void update(int *arr, int *tree, int start, int end, int treeNode, int index){
    if(start == end){
        arr[start] = 1;
        tree[treeNode] = 1;
        return;
    }
    
    int mid = (start+end)/2;
    // right tree
	if (index > mid)
		update(arr, tree, mid+1, end, 2*treeNode + 1, index);
	//left tree
    else
		update(arr, tree, start, mid, 2*treeNode, index);

	int left = tree[2 * treeNode];
    int right = tree[2 * treeNode + 1];
	tree[treeNode] = (power[end-mid]*left + right) % 3;
}


int query(int* tree, int start, int end, int treeNode, int left, int right){
	//completely outside
	if (start > right || end < left)
		return 0;
	//completely inside
	if (start >= left && end <= right)
		return (tree[treeNode]*power[right-end]) % 3;
    
	//partial overlap
	int mid = (start + end)/2;
	int leftAns = query(tree, start, mid, 2*treeNode, left, right);
	int rightAns = query(tree, mid + 1, end, 2*treeNode + 1, left, right);
	return (leftAns + rightAns)%3;
}


int main() {
    buildPower();
    int n;
    cin >> n;
    string s;
    cin >> s;
    int *arr = new int[n];
    for(int i = 0; i < n; i++) 
        arr[i] = s[i]-'0';
    int *tree = new int[4*n]();
    
    buildTree(arr, tree, 0, n-1, 1);
    int q;
    cin >> q;
    
    while(q--){
        int type;
        cin >> type ;
        if(type == 1){
            int index;
            cin >> index;
            update(arr, tree, 0, n-1, 1, index);
        }
        else{
            int left, right;
            cin >> left >> right;
            cout << query(tree, 0, n-1, 1, left, right) <<endl;
        }
    }
}



