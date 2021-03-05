#include<iostream>
#include<string>
using namespace std;



int main(){

	//String
	string s = "simultaneously";
	string s1(s,2,6);
	cout<<s<<endl;
	cout<<s1<<endl;

	string s2 = s.substr(2,4);
	cout<<s2<<endl;

	if(s1.compare(s2) == 0){
	 	cout<<s1 <<"is equal to " << s2<<endl;
	}else{
	 	cout<<s1 <<"is not equal to " << s2<<endl;
	}

	return 0;
}
