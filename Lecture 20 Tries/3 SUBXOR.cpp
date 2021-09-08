#include<bits/stdc++.h>
using namespace std;

//time comp => O(n)
/*
If xor[i, j] represents the xor of all elements in the subarray a[i, j], then at an 
index i what we have is, a trie which has xor[1:1], xor[1:2]…..xor[1:i-1] already inserted. 
Now we somehow count how many of these (numbers in trie) are such that its xor with xor[1:i] 
is smaller than k. This will cover all the subarrays ending at the index i and having xor i.e. xor[j, i] <=k;

Now the problem remains, how to count the numbers with xor smaller than k. 
So, for example take the current bit of the ith index element is p, current bit of number 
k be q and the current node in trie be node. 
Take the case when p=1, k=1. Then if we go to the right child the current xor would be 0 
(as the right child means 1 and p=1, 1(xor)1=0).As k=1, all the numbers that are to the right 
child of this node would give xor value smaller than k. So, we would count the numbers that are right to this node. 
If we go to the left child, the current xor would be 1 (as the left child means 0 and p=1, 
0(xor)1=1). So, if we go to the left child we can still find number with xor smaller than k, 
therefore we move on to the left child.

So, to count the numbers that are below a given node, we modify the trie and each node will 
also store the number of leafs in that subtree and this would be modified after each insertion.
Other three cases for different values of p and k can be solved in the same way to the count 
the number of numbers with xor less than k.
*/

class trieNode{
	public:
		int left_count, right_count;
		trieNode *left;
		trieNode *right;
		
		trieNode(){
			left_count =0; 
			right_count =0;
			left = NULL;
			right = NULL;
		}
};

void insert(trieNode *root, int n){
	for(int i = 31; i >= 0; i--){
		int b = (n>>i) & 1;
		if(b == 0){
			root->left_count++;
			if(root->left == NULL){
				root->left = new trieNode();
			}
			root = root->left;
		} else{
			root->right_count++;
			if(root->right == NULL){
				root->right = new trieNode();
			}
			root = root->right;
		}
	}
}

int query(trieNode *root, int n, int k){
	if (root == NULL)
        return 0;
    int res = 0;
    
    for (int i = 31; i >= 0; i--){
        bool current_bit_of_k = (k>>i) & 1;
        bool current_bit_of_element = (n>>i) & 1;
        
        //if the current bit of k is 1
		if (current_bit_of_k){
			//if current bit of element is 1
            if (current_bit_of_element){
                res += root->right_count;
                if (root->left == NULL)
                    return res;
                root = root->left;
            }
			//if current bit of element is 0
            else{
                res += root->left_count;
                if (root->right == NULL)
                    return res;
                root = root->right;
            }
        }
        //if the current bit of k is 0
        else{
        	//if current bit of element is 1
            if (current_bit_of_element){
                if (root->right == NULL)
                    return res;
                root = root->right;
            }
            //if current bit of element is 0
            else{
                if (root->left == NULL)
                    return res;
                root = root->left;
            }
        }
        
    }
    
    return res;
}


int main(){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		int arr[n];
		
		trieNode *root = new trieNode();
		insert(root, 0);
		long long total = 0;
		int pre_xor = 0;
		
		for(int i=0; i<n; i++){
			cin >> arr[i];
			pre_xor = pre_xor ^ arr[i];
			
			total += query(root, pre_xor, k);
			insert(root, pre_xor);
			
		}
		
		cout << total << endl;
	}
}
