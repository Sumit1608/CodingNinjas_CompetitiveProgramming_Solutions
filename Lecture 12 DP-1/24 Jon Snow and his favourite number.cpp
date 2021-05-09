#include <bits/stdc++.h>
using namespace std;

//time comp => O(1024*k)
/*
The range of strengths of any ranger at any point of time can be [0,1023]. This allows us 
to maintain a frequency array of the strengths of the rangers.
Now, the updation of the array can be done in the following way: 
Make a copy of the frequency array. If the number of rangers having strength less than a 
strength y is even, and there are freq[y] rangers having strength y, ceil(freq[y] / 2) 
rangers will be updated and will have strengths y^x, and the remaining will retain the same strength. 
If the number of rangers having strength less than a strength y is odd,and there are freq[y] 
rangers having strength y, floor(freq[y] / 2) rangers will be updated and will have strengths y^x, 
and remaining will have the same strength. 
This operation has to be done k times, thus the overall complexity is O(1024 * k).
*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k, x, t;
    cin >> n >> k >> x;
    
    int *arr = new int[1024]();
    for(int i=0; i<n; i++){
        cin>>t;
        arr[t]++;
    }
    
    int *freq = new int[1024]();
    
    while(k--){
        int carry=0;
        // int sum=0;
        
        for(int i=0; i<1024; i++){
            if(arr[i] > 0){
            	// int even, odd;
            	// if (sum % 2 == 0){
            	// odd = (arr[i] + 1) / 2;
            	// even = arr[i] - odd;
            	// }
            	// else{
            	// odd = arr[i] / 2;
            	// even = arr[i] - odd;
            	// }
            	// sum += arr[i];
            	// freq[i] += even;
            	// freq[x^i] += odd;
				int range = arr[i];  
				int add = range/2;
                
     			if( (carry+1)%2 ==1 && range%2==1)
     				add++;
       			carry = carry + range;
     			
                int num = (i^x);
     			freq[num] += add;
      			freq[i] += (arr[i]-add);
     		}
     	}
        
        for(int i=0; i<1024; i++){
            arr[i] = freq[i];
            freq[i] =0;
        }
    }
    
    
    for (int i = 1023; i >= 0; i--){
        if (arr[i] > 0){
            cout << i << " ";
            break;
        }
    }
    for (int i = 0; i < 1024; i++){
        if (arr[i] > 0){
            cout << i;
            break;
        }
    }

    return 0;
}

