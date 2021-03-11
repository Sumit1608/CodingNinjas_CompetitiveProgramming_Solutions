#include <iostream>
using namespace std;

void merge(int input[], int si, int ei){
	int size = ei-si+1;
	int mid = (si+ei)/2;
	int *output = new int[size];
	
	int i=si, j=mid+1, k=0;
	while(i<=mid && j<= ei){
		if(input[i] <= input[j]){
			output[k] = input[i];
			i++;
			k++;
		}
		else{
			output[k] = input[j];
			j++;
			k++;
		}
	}
	
	while(i<=mid){
        output[k] = input[i];
        i++;
        k++;
    }
    while(j<=ei){
        output[k] = input[j];
        j++;
        k++;
    }
    int m=0;
    for(int t =si; t<=ei; t++){
        input[t] = output[m];
        m++;
    }
    delete []output;
}

void mergSortHelper(int input[], int si, int ei){
	//si=  Start index     ei = End index
	if(si>=ei){
		return;
	}
	int mid = (si+ei)/2;
	mergSortHelper(input, si, mid);
	mergSortHelper(input, mid+1, ei);
	merge(input, si, ei);
}

void mergeSort(int input[], int length){
	mergSortHelper(input, 0, length-1);
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
