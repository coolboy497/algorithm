#include<iostream>
#include<string>
using namespace std;
//this指针指向被调用的成员函数所属的对象
//1.解决名称冲突
//2.返回对象本身用*this
class Person{
    public:
    Person(int age){
        this->age=age;
    }
    void personAddAge(Person &p){
        this->age +=p.age;
    }
    Person& personAddAge_2(Person &p){
        this->age +=p.age;
        return *this;
    }
    int age;
};
void test01(){
    Person p1(18);
    cout << p1.age << endl;
}
void test02(){
    Person p1(10);
    Person p2(10);
    // p2.personAddAge(p1);//20
    p2.personAddAge_2(p1).personAddAge_2(p1); //30
    cout << p2.age <<endl;
}
int main(){
    test02();
    return 0;
}
