#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;


struct Interval{
	int st;
	int et;
};

bool compare(Interval i1, Interval i2){
	return i1.st < i2.st;
//	return i1.st > i2.st;  This would be used for decreasing order
}

int main(){
	cout<<"Enter size of array : "<<endl;
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0; i<n;i++){
		cin>>arr[i];
	}
	
	//Inbuilt sort functions
	//Ascending order
	sort(arr, arr+n);
	for(int i=0; i<n;i++){
		cout << arr[i]<<" ";
	}
	cout<<endl;
	// If I pass   sort(arr+2, arr+7),  then it will sort an iterval only
	//Descending order
	sort(arr, arr+n, greater<int>());
	for(int i=0; i<n;i++){
		cout << arr[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
	
	//Sort function for a class
	Interval ar[] = {{6,4}, {3,4}, {4,6}, {8,13}};
	sort(ar, ar+4, compare);
	for(int i=0; i<4; i++){
		cout<<ar[i].st << " : "<<ar[i].et <<endl; 
	}
	cout<<endl;
	
	
	//Inbuilt Searching
	sort(arr, arr+n);
	cout << binary_search(arr, arr+n, 3)<<endl;
	//here, 3 is the number to be searched
	//If returns 1 that means true           if 0 that means false
	cout << lower_bound(arr, arr+n, 3)<<endl;
	//It will give the pointer
	//Below will give the index
	cout << lower_bound(arr, arr+n, 3) - arr<<endl;
	cout<<endl;
	
	
	//GCD 
	cout << __gcd(100, 350) <<endl;
}
