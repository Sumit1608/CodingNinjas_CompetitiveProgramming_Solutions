#include<bits/stdc++.h>
using namespace std;

//Time comp => O(n log(max))
/*
We can solve this problem efficiently using a trie data structure. The idea is to store every element in its binary form in a trie.
Let's say number of bits in max(arr[i]) is 20, then 9 is stored as 00000000000000001001 in trie.
So, now each node of trie has at max two children for 0 and 1.

Now, for each query let the number be x, then we traverse bit by bit through the number along the nodes of the trie with maximizing the xor(This will take O(q*log(max*(arr[i]1))) complexity.
We maximize xor by choosing a bit of opposite parity(if present) from trie. It means if we have 0 bit at any index i
then we select path of node 1 in trie(if present otherwise 0) and vice-versa. By this approach we'll always have the 
maximum xor value with x.

One more thing to note is that if we have 1 at higher index and 0 at lower indices, it will always be greater than 0 at that index and 1 at lower indices.

For example, 8(1000) > 7(0111).
*/

class trieNode{
	public:
	trieNode *left;
	trieNode *right;
};

void insert(int n, trieNode *head){
	trieNode *curr =head;
	for(int i=31; i>=0; i--){
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

int findMaxXorPair(trieNode *head, int *arr, int n){
	int max_xor = INT_MIN;
	
	for(int i=0; i<n; i++){
		int value = arr[i];
		int curr_xor= 0;
		trieNode *curr = head;
		
		for(int j=31; j>=0; j--){
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
	}
	return max_xor;
}

int main(){
	int arr[6] = {8,1,2,15,10,5};
	trieNode *head = new trieNode();
	for(int i=0; i<6; i++){
		insert(arr[i], head);
	}
	
	cout << findMaxXorPair(head, arr, 6) <<endl;
	return 0;
}
