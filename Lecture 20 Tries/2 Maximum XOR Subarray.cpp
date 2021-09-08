#include<bits/stdc++.h>
using namespace std;

//time comp => O(n)
/*
1) Create an empty Trie.  Every node of Trie is going to 
   contain two children, for 0 and 1 value of bit.
2) Initialize pre_xor(xor till i) = 0 and insert into the Trie.
3) Initialize result = minus infinite
4) Traverse the given array and do following for every array element arr[i].
       a) pre_xor  = pre_xor  ^ arr[i]
          pre_xor now contains xor of elements from 
          arr[0] to arr[i].
       b) Query the maximum xor value ending with arr[i] 
          from Trie.
       c) Update result if the value obtained in step 
          4.b is more than current value of result.
*/
// note that for two numbers x and y   x^x^y = y
// Xor of a subarray a[l:r] can be written as (a[1:l-1] xor a[1:r]), 
// where a[i, j] is the xor of all the elements with index such that, i <= index <= j. 

class trieNode{
	public:
		trieNode *left;
		trieNode *right;
};

void insert(int n, trieNode *head){
	trieNode *curr = head;
	for(int i=21; i>=0; i--){
		int b = (n>>i) & 1;
		if(b == 0){
			if(!curr->left){
				curr->left = new trieNode();
			}
			curr = curr->left;
		} else{
			if(!curr->right){
				curr->right = new trieNode();
			}
			curr = curr->right;
		}
	}
}

int query(trieNode *head, int value){
	int max_xor = INT_MIN;
	int curr_xor= 0;
	trieNode *curr = head;
		
	for(int j=21; j>=0; j--){
		int b = (value>>j)&1;
		
		if(b == 0){
			if(curr->right){
				curr_xor += pow(2,j);
				curr = curr->right;
			} else{
				curr = curr->left;
			}
		}
		else{
			if(curr->left){
				curr_xor += pow(2,j);
				curr = curr->left;
			} else{
				curr = curr->right;
			}
		}
	}
	max_xor = max(max_xor, curr_xor);
	return max_xor;
}


int main(){
	int n;
	cin >>n;
	int arr[n];
	
	int ans = 0, xor_till_i = 0;
	trieNode *root = new trieNode();
    insert(xor_till_i, root);
    
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        xor_till_i = xor_till_i^arr[i];
        ans = max(ans, query(root, xor_till_i));
        insert(xor_till_i, root);
    }
    
    cout << ans << endl;
}
