#include <iostream>
#include <queue>
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
int main(){
    queue <Person> q;
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);
    while(!q.empty()){
        cout<<"队头元素姓名: "<<q.front().name<<"队头元素年龄: "<<q.front().age<<endl;
        cout<<"队尾元素姓名: "<<q.back().name<<"队尾元素年龄: "<<q.back().age<<endl;
        q.pop();
    }
    return 0;
}