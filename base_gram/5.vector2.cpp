#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Person{
public:
    Person(string name,int age){
        this->name = name;
        this->age = age;
    }
    string name;
    int age;
};
void test01(){
    vector<Person> v;
    Person p1("aaa",18);
    Person p2("bbb",19);
    Person p3("ccc",20);
    Person p4("ddd",21);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    for(vector<Person>::iterator it = v.begin();it!=v.end();it++){
        cout<<"姓名:"<<(*it).name<<" 年龄:"<<(*it).age<<endl;
    }
}
int main(){
    test01();
    return 0;
}