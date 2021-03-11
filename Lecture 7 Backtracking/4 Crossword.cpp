#include<bits/stdc++.h>
using namespace std;

#define N 10


void print(char grid[N][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << grid[i][j] ;
        }
        cout << endl;
    }
    cout << endl;
}


bool isValidVertical(char grid[N][N], int row, int col, string word){
    for(int i=0; i< word.length(); i++){
        if(row > 9){
            return false;
        }
        if( grid[row][col] == '+' || (grid[row][col] != '-' && grid[row][col] != word[i]) ){
            return false;
        }
        row++;
    }
    return true;
}
bool isValidHorizontal(char grid[N][N], int row, int col, string word){
    for(int i=0; i< word.length(); i++){
        if(col > 9){
            return false;
        }
        if( grid[row][col] == '+' || (grid[row][col] != '-' && grid[row][col] != word[i]) ){
            return false;
        }
        col++;
    }
    return true;
}

//If the grid's element is '-' then fill it with the ith character of word and push true in vector
//otherwise there must be the ith character available, so push false in vector and continue filling
void setVertical( char grid[N][N], int row, int col, vector<bool> &v, string word ){
    for(int i=0; i<word.length(); i++){
        if( grid[row+i][col] == '-'){
            grid[row+i][col] = word[i];
            v.push_back(true);
        } else{
            v.push_back(false);
        }
    }
}
void setHorizontal( char grid[N][N], int row, int col, vector<bool> &v, string word ){
    for(int i=0; i<word.length(); i++){
        if( grid[row][col+i] == '-'){
            grid[row][col+i] = word[i];
            v.push_back(true);
        } else{
            v.push_back(false);
        }
    }
}

//to reset horizontally or vertically,  set the word's ith index as '-' when the ith element of vector is true
void resetVertical(char grid[N][N], int row, int col, vector<bool> v ){
    for(int i=0; i<v.size(); i++){
        if( v[i] ){
            grid[row+i][col] = '-';
        }
    }
}
void resetHorizontal(char grid[N][N], int row, int col, vector<bool> v ){
    for(int i=0; i<v.size(); i++){
        if( v[i] ){
            grid[row][col+i] = '-';
        }
    }
}


bool solve(char grid[N][N], vector<string> words, int index){
    //base case is if index become == v.size()----> then print the crossword;
	if (index >= words.size()){
		print(grid);
		return true;
	}
    
    //Start filling the words 
    for(int row=0; row< N; row++){
        for(int col=0; col<N; col++){
            //When we counter by '-' or the word's first character, we check it whther it can be filled vertically and horizontally, and then we fill it
            if( grid[row][col] == '-' || words[index][0]){
                
                //Check if the word can be filled vertically
                if( isValidVertical(grid, row, col, words[index]) ){
                    //maintain a helper array to store which characters of word have been used to fill the crossword
					vector<bool>helper;
					//pass this helper array in the function setVertical where this helper array is a boolean array.
					setVertical(grid, row, col, helper, words[index]);
                    //Fill teh remaining words
					if (solve(grid, words, index + 1)){
						return true;
					}
                    
                    //If the other words can't be filled properly, then reset the crossword with the previously installed word
					resetVertical(grid, row, col, helper);
                }
                
                //Check if the word can be filled horizontally
                if( isValidHorizontal(grid, row, col, words[index]) ){
                    //maintain a helper array to store which characters of word have been used to fill the crossword
					vector<bool>helper;
					//pass this helper array in the function setHorizontal where this helper array is a boolean array.
					setHorizontal(grid, row, col, helper, words[index]);
                    //Fill teh remaining words
					if (solve(grid, words, index + 1)){
						return true;
					}
                    
                    //If the other words can't be filled properly, then reset the crossword with the previously installed word
					resetHorizontal(grid, row, col, helper);
                }
            }
        }
    }
    
    return false;
}


int main() {
	char grid[N][N];
	for(int i=0; i<N; i++){
        string s;
		cin >> s;
		for (int j = 0; j < N; j++){
			grid[i][j] = s[j];
		}
    }
    
    string s;
	cin >> s;
	vector<string> words;
	for (int i = 0; i < s.length(); i++){
		int j = i;
		while (s[j] != ';' && j < s.length()){
			j++;
		}
		words.push_back(s.substr(i, j - i));
		i = j;
		j++;
	}
    
    solve(grid, words, 0);
    
}
    
  
