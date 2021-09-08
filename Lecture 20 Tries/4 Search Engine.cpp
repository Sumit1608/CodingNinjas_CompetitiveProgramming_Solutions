#include<bits/stdc++.h>
using namespace std;

class trieNode{
	public:
		trieNode **children;
		int weight;
		
		trieNode(){
			children = new trieNode*[26];
			for(int i=0; i<26; i++){
				children[i] = NULL;
			}
			weight =0;
		}
};

void insert(trieNode *root, string s, int weight){
	if(s.length() == 0){
		return;
	}
	
	trieNode *curr;
	int index = s[0] - 'a';
	if(root->children[index] != NULL){
		curr = root->children[index];
	} else{
		curr = new trieNode();
		root->children[index] = curr;
	}
	
	if(root->weight < weight){
		root->weight = weight;
	}
	insert(curr, s.substr(1), weight);
}

int query(trieNode *root, string s){
	int best_weight = INT_MIN;
    int n = s.length();
    trieNode *curr = root;
    
    for(int i=0; i<n; i++){
        int index=s[i]-'a';
        trieNode *child = curr->children[index];
        //if the child is not null we have to update the best weight with
        // current child's weight and move the current pointer to child.
        if(child!=NULL){
            curr = child;
            best_weight = child->weight;
        }
        //if child is null
        else{
            return -1;
        }
        
    }
    return best_weight;
}

int main(){
	int n, q;
	cin >> n >> q;
	trieNode *root = new trieNode();
	
	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		int weight;
		cin >> weight;
		
		insert(root, s, weight);
	}
	
	while(q--){
		string s;
		cin >> s;
		cout << query(root, s) << endl;
	}
	return 0;
}




/*

class trieNode{
	public:
	bool terminal;
	int weight;
	trieNode *children[26];
	
	trieNode(){
		terminal =0;
		weight =0;
		for(int i=0; i<26; i++){
			children[i] = NULL;
		}
	}
};

void insert(trieNode *root, string s, int weight){
	int length = s.size();
	trieNode *curr = root;
	
	for(int i=0; i<length; i++){
		int index = s[i] - 'a';
		if(curr->children[index] == NULL){
			curr->children[index] = new trieNode();
		}
		trieNode *child = curr->children[index];
		child->weight = max(child->weight, weight);
		curr = child;
	}
	curr->terminal = 1;
}

int search(trieNode *root, string s){
	int length=s.size();
	trieNode *node = root;
	
	for(int i=0;i<length;i++) {
		int idx=s[i]-'a';
		if(node->children[idx]==NULL) 
			return -1; 
		node=node->children[idx]; 
	}
	int ans=-1; 
	for(int i=0;i<26;i++) 
		if(node->children[i]!=NULL) { 
			trieNode *child = node->children[i]; 
			ans=max(ans, child->weight); 
		}

	return ans;
}

*/
