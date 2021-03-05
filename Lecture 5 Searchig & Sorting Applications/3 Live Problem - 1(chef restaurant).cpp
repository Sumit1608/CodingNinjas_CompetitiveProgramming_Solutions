#include<bits/stdc++.h>
using namespace std;

//Time compl => O(m logn)
//m queries and lower_bound take logn time to return an iterator
//Here, we first sort the vector pair and then search for ith query using 
//kower bound function and we check for the 4 conditionsas mentioned in the code.
//sample      1
//4 5
//5 7
//9 10
//2 3
//20 30
//5
//6
//7
//35
//1
//It maybe possible that the query is before time 2   so it will wait 2 - curr_time
//also,  if query is after 30(max) then we print -1
//If it's between the intervals, we check for last position

/*

The lower_bound() method in C++ is used to return an iterator pointing to the first element
in the range [first, last) which has a value not less than val. This means that the function
returns the index of the next smallest number just greater than or equal to that number. If
there are multiple values that are equal to val, lower_bound() returns the index of the first
such value.
The elements in the range shall already be sorted or at least partitioned with respect to val. 

Templates: 
Syntax 1: 
ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val); 
Syntax 2: 
ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, const T& val, Compare comp); 
 

Parameters: The above methods accept the following parameters.  
first, last: The range used is [first, last), which contains all the elements between first and last,
including the element pointed by first but not the element pointed by last.
val: Value of the lower bound to be searched for in the range.
comp: Binary function that accepts two arguments (the first of the type pointed by ForwardIterator,
and the second, always val), and returns a value convertible to bool. The function shall not modify
any of its arguments. This can either be a function pointer or a function object.

Examples: 
Input: 10 20 30 40 50
Output: lower_bound for element 30 at index 2
Input: 10 20 30 40 50
Output: lower_bound for element 35 at index 3
Input: 10 20 30 40 50
Output: lower_bound for element 55 at index 5

*/

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		
		vector< pair<int , int > > intervals;
		for(int i=0; i<n; i++){
			int start, end;
			cin >> start >> end;
			intervals.push_back(make_pair(start, end));
		}
		
		sort(intervals.begin(), intervals.end());
		
		while(m--){
			int curr_time ;
			cin >> curr_time;
			int position = lower_bound(intervals.begin(), intervals.end(), make_pair(curr_time, 0) ) - intervals.begin();
			cout << position<<endl;
			//When curr_time matches with zeroth poisiton
			if(position == 0){
				int ans = intervals[0].first - curr_time;
				cout << ans << endl;
			}
			else{
				int ans = -1;
				//comparing with just before this positon
				if(intervals[position - 1].second > curr_time){
					ans = 0;
				}
				//position lies in intervals
				else if(position < intervals.size()){
					ans = intervals[position].first - curr_time;
				}
				//if ans remained -1 that means position lies out of the bound
				cout << ans << endl;
			}
		}
	}
}
