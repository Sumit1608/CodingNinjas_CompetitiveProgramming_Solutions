#include <iostream>
using namespace std;


// time comp => O(m*n)
int length(char input[]) {
    int len = 0;
    for(int i = 0; input[i] != '\0'; i++) { 
        len++;
    }
    return len;
} 

int findString(char S[], char T[]){
    int n = length(S);
    int m = length(T);
    
    int j=0;
    for(int i=0; i<= (n-m); i++){
        j=0;
        while((j<m) && (S[i + j] == T[j]) ) {
            j++;
        }
        if (j == m) 
            return i;
    }
    return -1;
}
        
int main() {
    char S[1000], T[1000];
    cin.getline(S, 1000);
    cin.getline(T, 1000);
    cout << findString(S, T) << endl;
}

