#include<bits/stdc++.h>
using namespace std;

//First Approach
// As the order of arrival and departure of guest is randomly given, so we check one by one
// for every guest. For exapmle, a guest arrived at 900 and leave at 1800, so we check the 
// no of rest of the guest that are present in between that 900 and 1800 interval.

int main() {
	int n;
    cin>>n;
    
    int arrival[n];
    int departure[n];
    for(int i=0; i<n; i++){
        cin>>arrival[i];
    }
    for(int i=0; i<n; i++){
        cin>>departure[i];
    }
    
    int max_count =0;
    for(int i=0; i<n; i++){
        int count =0;
        int arr = arrival[i];
        int dep = departure[i];
        for(int j=0; j<n; j++){
            if( (arrival[j]< arr && departure[j]>= arr) || (arrival[j]< dep && departure[j]>= dep)){
                count++;
            }
        }        
        max_count = max(max_count, count);
    }
    
    cout <<max_count<<endl;
}


//Second Approach
//First we sort both the arrival and departure arrays,  as the guest arrived will need one chair
//so we take our chair as first,  now until the first guest leave, we count the no guest arrived.
//If a guest leaves, one chair is not needed, then untill the next guest leaves, we add chair for
//the other guest arrived, and we operate for all the guest. We store the maximum chair needed at
//a particular instance in a variable.

/*
int findPlatform(int arr[], int dep[], int n){
	sort(arr, arr+n);
	sort(dep, dep+n);
	
	int chair_needed = 1, result = 1;
	int i=1, j=0;
	
	while(i<n && j<n){
		if(arr[i] <= dep[j]){
			chair_needed++;
			i++;
			if(chair_needed > result){
				result = chair_needed;
			}
		}
		else{
			chair_needed--;
			j++;
		}
	}
	
	return result;
}

int main(){
	int n;
    cin>>n;
    
    int arrival[n];
    int departure[n];
    for(int i=0; i<n; i++){
        cin>>arrival[i];
    }
    for(int i=0; i<n; i++){
        cin>>departure[i];
    }
    
    cout << findPlatform(arrival, departure, n);
    return 0;
}
*/
