#include<bits/stdc++.h>
using namespace std;

//time comp => O(nlogn)
// Calculate the ratio value/weight for each item and sort the item on basis of this ratio. 
// Then take the item with the highest ratio and add them until we can’t add the next item as a 
// whole and at the end add the next item as much as we can. Which will always be the optimal solution to this problem.

struct Item{
	int value;
	int weight;
};

bool compare(struct Item a, struct Item b){
	double value1 = (double)a.value/(double)a.weight;
	double value2 = (double)b.value/(double)b.weight;
	return (value1 > value2) ;
}

double fKnapsack(struct Item arr[], int n, int w){
	int currentWeight = 0;
	double finalValue = 0.0;
	
	for(int i=0; i<n; i++){
		if(currentWeight + arr[i].weight <= w){
			currentWeight += arr[i].weight;
			finalValue += arr[i].value;
		} else{
			int remainingWeight = w - currentWeight;
			finalValue += arr[i].value * ((double)remainingWeight/arr[i].weight);
			break;
		}
	}
	return finalValue;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,w;
    cin >> n >> w;
    Item *arr = new Item[n];
    for(int i=0; i<n; i++)
    	cin >> arr[i].value >> arr[i].weight;
    
    sort(arr, arr+n, compare);
    cout << fixed << setprecision(6) <<fKnapsack(arr, n, w)  <<endl;
    
    return 0;
}
