#include<iostream>
using namespace std;

class student{
    string name;
    public:
    int age;
    bool gender;
    student(){} // default constructor
    student(string s, int a, bool g){
        name=s;
        age=a;
        gender=g;
    } // parameterised constructor

    student(student &s){
        cout<<"copy constructor"<<endl;
        name=s.name;
        age=s.age;
        gender=s.gender;
    } // copy constructor

    void setname(string s){
        name=s;
    }
    void printInfo(){
        cout<<name<<" "<<age<<" "<<gender<<endl;
    }

    bool operator + (student &s){
        if(name==s.name && gender==s.gender)return true;
        return false;
    }

    ~student(){cout<<"destroyed"<<endl;};
};

int main(){
    // student a();
    // a.name="yash";
    // a.gender=1;
    // a.age=12;
    // a.printInfo(); 
    
    // student arr[2];
    // for(int i=0;i<2;i++){
    //     string s;
    //     cin>>s;
    //     // cin>>arr[i].name;
    //     arr[i].setname(s);
    //     cin>>arr[i].age;
    //     cin>>arr[i].gender;
    // }
    // for(int i=0;i<2;i++){
    //     arr[i].printInfo();
    // }

    student s("urvi",20,0);
    s.printInfo();
    student t(s);
    // can also be written as t=s;
    if(t+s)cout<<"yes"<<endl;   
    // uses the operator created in student class
    return 0;
}