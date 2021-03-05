#include<bits/stdc++.h>
using namespace std;


// Make a student class containing name, roll no and totalmarks of a student
// Make a array of size n to store the students info, then take input one by one
// Now, sort the array according to the toal marks, but if the total marks are same
// then sort according to the roll no, and we will get our required array.
class Student{
    public:
    string name;
    int rollno;
    int totalMarks;
};

bool compare(Student *s1, Student *s2){
    if(s1->totalMarks != s2 ->totalMarks){
        return s1->totalMarks > s2->totalMarks;
    }
    return s1->rollno < s2->rollno;
}

int main()
{
    int n;
    cin>>n;
    
    Student** students = new Student*[n];
    for(int i=0; i<n ; i++){
        students[i] = new Student();
    }
    
    for(int i=0; i<n; i++){
        cin>> students[i]->name;
        students[i]->rollno = i+1;
        
        int m1, m2, m3;
        cin>>m1>>m2>>m3;
        int total = m1+m2+m3;
        
        students[i]->totalMarks = total;
    }
    
    sort(students, students+n, compare);
    for(int i=0; i<n; i++){
        cout<< i+1 <<" " << students[i]->name <<endl;
    }
    
}

