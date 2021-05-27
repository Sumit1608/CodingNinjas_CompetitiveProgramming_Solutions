#include<bits/stdc++.h>
using namespace std;


struct node{
    int maxA;
    int maxB;
    int index;
};


void buildTree(pair<int, int> *arr, node *tree, int start, int end, int treeNode){
    if(start == end){
        tree[treeNode].maxA = arr[start].first;
        tree[treeNode].maxB = arr[start].second;
        tree[treeNode].index = start;
        return;
    }
    
    int mid = (start+end)/2;
    buildTree(arr, tree, start, mid, 2*treeNode);
    buildTree(arr, tree, mid+1, end, 2*treeNode+1);
    
    node leftAns = tree[2*treeNode];
    node rightAns = tree[2*treeNode + 1];
    
    if(leftAns.maxA > rightAns.maxA){
        tree[treeNode].maxA = leftAns.maxA ;
        tree[treeNode].maxB = leftAns.maxB ;
        tree[treeNode].index = leftAns.index ;
    }
    else if(leftAns.maxA < rightAns.maxA){
        tree[treeNode].maxA = rightAns.maxA ;
        tree[treeNode].maxB = rightAns.maxB ;
        tree[treeNode].index = rightAns.index ;
    }
    else{
	    tree[treeNode].maxA = leftAns.maxA ;
        if(leftAns.maxB <= rightAns.maxB){
    	    tree[treeNode].maxB = leftAns.maxB ;
        	tree[treeNode].index = leftAns.index ;
    	}
	    else if(leftAns.maxB > rightAns.maxB){
        	tree[treeNode].maxB = rightAns.maxB ;
    	    tree[treeNode].index = rightAns.index ;
    	}
    }
    
}


node query(node *tree, int start, int end, int treeNode, int left, int right){
    //completely outside
	if (start > right || end < left){
		node ans;
		ans.maxA = INT_MIN;
		ans.maxB = INT_MAX;
		ans.index = INT_MAX;
		return ans;
	}
	//completely inside
	if (start >= left && end <= right){
		return tree[treeNode];
	}
    
	//partial overlap
	int mid = (start + end) / 2;
	node left_child = query(tree, start, mid, 2*treeNode, left, right);
	node right_child = query(tree, mid+1, end, 2*treeNode+1, left, right);
	
    if (left_child.maxA > right_child.maxA){
		return left_child;
	}
	else if (left_child.maxA < right_child.maxA){
		return right_child;
	}
	else{
		if (left_child.maxB < right_child.maxB){
			return left_child;
		}
		else if (left_child.maxB > right_child.maxB){
			return right_child;
		}
		else{
			if (left_child.index < right_child.index){
				return left_child;
			}
			else{
				return right_child;
			}
		}
	}
}


int main() {
	int n;
    cin >> n;
    pair<int, int> *arr = new pair<int, int>[n];
    for(int i=0; i<n; i++)
        cin >> arr[i].first ;
    for(int i=0; i<n; i++)
    	cin >> arr[i].second ;
    
    node *tree = new node[4*n]();
    buildTree(arr, tree, 0, n-1, 1);
    
    int q;
    cin >>q;
    while(q--){
        int left, right;
        cin >> left >> right;
        cout << query(tree, 0, n-1, 1, left-1, right-1).index +1 << endl;
    }
    
}
