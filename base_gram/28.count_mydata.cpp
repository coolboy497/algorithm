#include<iostream>
#include<functional>
#include <algorithm>
#include<vector>
using namespace std;
class Person{
public:
    Person(string name,int age){
        this->name = name;
        this->age = age;
    }
    bool operator==(const Person &p){
        if(this->age==p.age){
            return true;
        }
        else{
            return false;
        }
    }
    string name;
    int age;
};
int main(){
    vector<Person> v;
    Person p1("张飞",20);
    Person p2("刘备",40);
    Person p3("关羽",40);
    Person p4("诸葛亮",40);
    Person p5("曹操",50);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    Person pp("李想",40);
    int num=count(v.begin(),v.end(),pp);
    cout<<"与李想同岁的有"<< num <<"人"<<endl;
    return 0;
}