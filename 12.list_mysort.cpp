#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;
class Person{
public:
    Person(string name,int age , int height){
        this->name = name;
        this->age = age;
        this->height = height;
    }
    string name;
    int age;
    int height;
};
void printlist(list<Person>const &l){
    for(list<Person>::const_iterator it = l.begin();it!=l.end();it++){
        cout<<"姓名："<<it->name<<" 年龄："<<it->age <<" 身高: "<<it->height<<endl;
    }
}
bool my_compare(Person &l1,Person &l2){
    if(l1.age==l2.age){
        return l1.height>l2.height;
    }
    else{
        return l1.age<l2.age;
    }
}

int main(){
    list<Person> l;
    Person p1("张三",50,174);
    Person p2("李四",50,168);
    Person p3("王五",30,194);
    Person p4("老刘",23,184);
    Person p5("张清",19,192);
    l.push_back(p1);
    l.push_back(p2);
    l.push_back(p3);
    l.push_back(p4);
    l.push_back(p5);
    cout<<"排序前: "<<endl;
    printlist(l);
    l.sort(my_compare);
    cout<<"排序后: "<<endl;
    printlist(l);
    return 0;
}