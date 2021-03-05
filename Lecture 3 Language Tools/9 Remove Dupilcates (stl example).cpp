#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//Using sorting
vector<int> removeDuplicates2(vector<int> input){
	vector<int> result;
	sort(input.begin(), input.end() );
	result.push_back(input[0]);
	
	for(int i=1; i<input.size(); i++){
		if(input[i] != input[i-1] ){
			result.push_back(input[i]);
		}
	}
	return result;
}

//Using set
vector<int> removeDuplicates1(vector<int> input){
	set<int> s;
	vector<int> result;
	
	for(int i=0; i<input.size(); i++){
		if(s.find(input[i]) == s.end()){
			s.insert(input[i]);
			result.push_back(input[i]);
		}
	}
	return result;
}

int main(){
	int n;
	cin>>n;
	vector<int> v;
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		v.push_back(x);
	}
	
	vector<int> output1 = removeDuplicates1(v);
	for(int i=0; i<output1.size(); i++){
		cout<< output1[i]<<" ";
	}
	cout<<endl;
	
	vector<int> output2 = removeDuplicates2(v);
	for(int i=0; i<output2.size(); i++){
		cout<< output2[i]<<" ";
	}
	cout<<endl;
}
