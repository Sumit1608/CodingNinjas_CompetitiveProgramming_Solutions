#include<bits/stdc++.h>
using namespace std;

class trienode{
	public:
    trienode *children[26];
    bool isLeaf = false;
    
    trienode(){
        isLeaf = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
    
};

void insert(string s, trienode *root){
    if (s.length() == 0){
        root->isLeaf = true;
        return;
    }
    
    trienode *current;
    int index = s[0] - 'a';
    if (root->children[index] != NULL)
        current = root->children[index];
    else{
        current = new trienode();
        root->children[index] = current;
        current = root->children[index];
    }
    
    insert(s.substr(1), current);
}

void helper(trienode *current, string prefix){
    if (current->isLeaf){
        cout << prefix << endl;
    }
    
    for (int i = 0; i < 26; i++){
        trienode *temp = current;
        if (temp->children[i] != NULL){
            char suffix = (int)i + (int)'a';
            helper(current->children[i], prefix + suffix);
        }
    }
}

void printer(trienode *root, string s){
    trienode *current = root;
    
    for (int i = 0; i < s.length(); i++){
        int index = s[i] - 'a';
        if (current->children[index] != NULL)
            current = current->children[index];
        else{
            cout << "No suggestions" << endl;
            insert(s, root);
            return;
        }
    }

    helper(current, s);
}

int main(){
    int n;
    cin >> n;
    trienode *root = new trienode();
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        insert(s, root);
    }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++){
        string s;
        cin >> s;
        printer(root, s);
    }
}



