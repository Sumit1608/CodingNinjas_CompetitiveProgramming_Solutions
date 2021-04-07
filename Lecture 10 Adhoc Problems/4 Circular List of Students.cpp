#include<bits/stdc++.h>
using namespace std;

/*
You are given a circular list of students as follows:
0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 11
This list is circular, means that 11 will follow 0 again. You will be given the 
student number ‘i’ and some position ‘p’. You will have to tell that if the list 
will start from (i+1)th student, then which student will be at pth position.

Time Comp => O(1)
*/

int main(){
    int t;
    cin >>t;
    while(t--){
        int i,p;
        cin >>i >>p;
        cout << (i+p)%12 <<endl;
    }
	return 0;
}

