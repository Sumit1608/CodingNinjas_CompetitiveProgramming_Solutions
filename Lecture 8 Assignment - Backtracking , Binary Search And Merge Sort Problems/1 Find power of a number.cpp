#include<iostream>
using namespace std;

//Time comp => O(n)
int power(int x, int n){
    if(n == 0){
        return 1;
    } else if(x == 0){
        return 0;
    }
    return x*power(x, n-1);
}

int main() {
	int x,n;
    cin>>x>>n;
    
	cout <<power(x,n) <<endl;
}

