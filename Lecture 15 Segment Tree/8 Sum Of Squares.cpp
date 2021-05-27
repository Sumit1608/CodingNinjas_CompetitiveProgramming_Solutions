#include<bits/stdc++.h>
using namespace std;


struct node{
    int sum;
    int sum_of_squares;
};

struct lazyNode{
    int setter = 0;
    int incrementor = 0;
};


void buildTree(int *arr, node *tree, int start, int end, int treeNode){
    if(start == end){
        tree[treeNode].sum = arr[start];
        tree[treeNode].sum_of_squares = arr[start]*arr[start];
        return;
    }
    
    int mid = (start + end)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);
    
    tree[treeNode].sum = tree[2*treeNode].sum + tree[2*treeNode+1].sum;
    tree[treeNode].sum_of_squares = tree[2*treeNode].sum_of_squares + tree[2*treeNode+1].sum_of_squares;  
}


void update_setter(node *tree, lazyNode* lazy, int start, int end, int left, int right, int treeNode, int value){
    if(start > end)
        return;
    if(lazy[treeNode].setter != 0){
        tree[treeNode].sum = (right-left+1) * (lazy[treeNode].setter);
		tree[treeNode].sum_of_squares = (right-left+1) * (lazy[treeNode].setter * lazy[treeNode].setter);
		
        if (start != end){
			lazy[2 * treeNode].setter = lazy[treeNode].setter;
			lazy[2 * treeNode+1].setter = lazy[treeNode].setter;
		}
		lazy[treeNode].setter = 0;
    }
    
    //completely outside
	if (start > right || end < left)
		return;
	//complete overlap
	if (start >= left && end <= right){
		tree[treeNode].sum_of_squares = (right-left + 1) * (value * value);
		tree[treeNode].sum = (right-left + 1) *value;
		if (start != end){
			lazy[2 * treeNode].setter = value;
			lazy[2 * treeNode + 1].setter = value;
		}
		return;
	}
    
	//partial overlap
	int mid = (start + end) / 2;
	update_setter(tree, lazy, start, mid, left, right, 2 * treeNode, value);
	update_setter(tree, lazy, mid+1, end, left, right, 2 * treeNode+1, value);
    
	tree[treeNode].sum = tree[2 * treeNode].sum + tree[2 * treeNode + 1].sum;
	tree[treeNode].sum_of_squares = tree[2 * treeNode].sum_of_squares + tree[2 * treeNode + 1].sum_of_squares;
	return;
}


void update_increment(node *tree, lazyNode* lazy, int start, int end, int left, int right, int treeNode, int value){
    if(start > end)
        return;
    
    if(lazy[treeNode].incrementor != 0){
        tree[treeNode].sum += (right-left+1) * (lazy[treeNode].incrementor);
		tree[treeNode].sum_of_squares += (right-left+1) * (lazy[treeNode].incrementor * lazy[treeNode].incrementor) + 2 * lazy[treeNode].incrementor * tree[treeNode].sum;
		
        if (start != end){
			lazy[2 * treeNode].incrementor = lazy[treeNode].incrementor;
			lazy[2 * treeNode+1].incrementor = lazy[treeNode].incrementor;
		}
		lazy[treeNode].incrementor = 0;
    }
    if(lazy[treeNode].setter != 0){
        tree[treeNode].sum = (right-left+1) * (lazy[treeNode].setter);
		tree[treeNode].sum_of_squares = (right-left+1) * (lazy[treeNode].setter * lazy[treeNode].setter);
		
        if (start != end){
			lazy[2 * treeNode].setter = lazy[treeNode].setter;
			lazy[2 * treeNode+1].setter = lazy[treeNode].setter;
		}
		lazy[treeNode].setter = 0;
    }
    
    //completely outside
	if (start > right || end < left)
		return;
	//complete overlap
	if (start >= left && end <= right){
		tree[treeNode].sum_of_squares += (right-left + 1) * (value * value) + 2*value*tree[treeNode].sum;
		tree[treeNode].sum += (right-left + 1) *value;
		if (start != end){
			lazy[2 * treeNode].incrementor += value;
			lazy[2 * treeNode + 1].incrementor += value;
		}
		return;
	}
    
	//partial overlap
	int mid = (start + end) / 2;
	update_increment(tree, lazy, start, mid, left, right, 2 * treeNode, value);
	update_increment(tree, lazy, mid+1, end, left, right, 2 * treeNode+1, value);
    
	tree[treeNode].sum = tree[2 * treeNode].sum + tree[2 * treeNode + 1].sum;
	tree[treeNode].sum_of_squares = tree[2 * treeNode].sum_of_squares + tree[2 * treeNode + 1].sum_of_squares;
	return;
}


node query(node *tree, lazyNode *lazy, int start, int end, int left, int right, int treenode){
	if (start > end)
		return { 0, 0 };
    
	if (lazy[treenode].incrementor != 0){
		tree[treenode].sum_of_squares += 2 * lazy[treenode].incrementor * tree[treenode].sum + lazy[treenode].incrementor * lazy[treenode].incrementor * (right - left + 1);
		tree[treenode].sum += (right - left + 1) * lazy[treenode].incrementor;
		if (start != end){
			lazy[2 * treenode].incrementor = lazy[treenode].incrementor;
			lazy[2 * treenode + 1].incrementor = lazy[treenode].incrementor;
		}
		lazy[treenode].incrementor = 0;
	}
	if (lazy[treenode].setter != 0){
		tree[treenode].sum = (right - left + 1) * lazy[treenode].setter;
		tree[treenode].sum_of_squares = (right - left + 1) * lazy[treenode].setter;
		if (start != end){
			lazy[2 * treenode].setter = lazy[treenode].setter;
			lazy[2 * treenode + 1].setter = lazy[treenode].setter;
		}
		lazy[treenode].setter = 0;
	}
    
	//completely outside
	if (start > right || end < left)
		return { 0, 0 };
	//fully inside
	if (start >= left && end <= right)
		return tree[treenode];
	//partial overlap
    
	int mid = (start + end) / 2;
	node left_child = query(tree, lazy, start, mid, left, right, 2 * treenode);
	node right_child = query(tree, lazy, mid+1, end, left, right, 2 * treenode+1);
	node ans;
	ans.sum = left_child.sum + right_child.sum;
	ans.sum_of_squares = left_child.sum_of_squares + right_child.sum_of_squares;
	return ans;
}




int main(){
    int t, caseNo = 1;;
    cin >> t;
    
    while(t--){
        int n, q;
        cin >> n >> q;
        int *arr = new int[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
        node *tree = new node[4*n]();
        lazyNode *lazy = new lazyNode[4*n]();
        buildTree(arr, tree, 0, n-1, 1);
        
        cout << "Case " << caseNo << ":" <<endl;
        
        while(q--){
            int operation, left, right;
            cin >> operation >> left >> right;
            if(operation == 2){
                node ans = query(tree, lazy, 0, n-1, left-1, right-1, 1);
                cout << ans.sum_of_squares << endl;
            }
            else if(operation == 1){
                int x; 
                cin >> x;
                update_increment(tree, lazy, 0, n-1, left-1, right-1, 1, x);
            }
            else{
                int x; 
                cin >> x;
                update_setter(tree, lazy, 0, n-1, left-1, right-1, 1, x);
            }
        }    
        caseNo++;
    }
    
}
