#include <iostream>
#include <set>
#include <string>
using namespace std;
class Person{
public:
    Person(string name,int height){
        this->name = name;
        this->height = height;
    }
    string name;
    int height;
};
class mycompare{
public:
    //必须要写const，因为不允许改变person
    bool operator()(const Person &p1,const Person &p2){
        if(p1.height!=p2.height){
            return p1.height > p2.height;
        }
        else{
            return p1.name > p2.name;
        }
    }
};
int main(){
    //自定义数据类型都要自己指定规则
    set <Person,mycompare> s;
    Person p1("tpj",167);
    Person p2("xly",173);
    Person p3("lmy",169);
    Person p4("zk",160);
    Person p5("aaa",167);
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);
    s.insert(p5);
    for(auto it = s.begin();it!=s.end();it++){
        cout << "姓名:"<<it->name<<" 身高:"<<it->height<<endl;
    }
    return 0;
}