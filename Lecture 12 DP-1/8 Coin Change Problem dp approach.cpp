#include <iostream>
using namespace std;

//time comp => O(n^2)
int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	int output[value+1][numDenominations];
    
    // Fill the enteries for 0 value case 
    for (int i = 0; i < numDenominations; i++) 
        output[0][i] = 1;
    
    // Fill rest of the table entries in bottom up manner  
    for(int i=1; i<= value; i++){
        for(int j=0; j<numDenominations; j++){
            
            // Count of solutions including denominations[j] 
            int x = (i-denominations[j] >= 0) ? output[ i - denominations[j] ][j] : 0; 
  
            // Count of solutions excluding denominations[j] 
            int y = (j >= 1) ? output[i][j - 1] : 0; 
  
            // total count 
            output[i][j] = x + y; 
        }
    }
    return output[value][numDenominations-1];
}

int main(){
	int numDenominations;
	cin >> numDenominations;
	
	int *denominations = new int[numDenominations];

	for (int i = 0; i < numDenominations; i++)
		cin >> denominations[i];

	int value;
	cin >> value;
	cout << countWaysToMakeChange(denominations, numDenominations, value);
	delete[] denominations;
}
