#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    
    int a=0, s=0, p=0;
    for(int i=0; i<n; i++){
        if(str[i] =='a'){
            a++;
        } else if(str[i] =='s'){
            s++;
        } else if(str[i] =='p'){
            p++;
        }
    }
    
    cout<<a<<" "<<s<<" "<<p;
}

/*
Approach

Take input of string
Then traverse the character of the string and increase the three integers variables
if one of character come out be 'a', 's', or 'p'.
*/
