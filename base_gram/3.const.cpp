#include<iostream>
#include<string>
using namespace std;
class Person{
    public:
    Person(){

    }
    void showperson() const
    { 
        // this->age = 100;
        this->height = 188;
        // this = NULL this指针是不可以修改指针的指向的
    }
    void func(){

    }
    int age;
    mutable int height;
};
void test01(){
    Person p1;
    p1.showperson();
    cout << p1.age << endl;
}
void test02(){
    const Person p2;
    p2.showperson();
    // p2.func();报错，常对象只能调用常函数
    // p2.age = 20;报错，常对象不能修改属性
    p2.height = 172;
}
int main(){
    test01();
    test02();
    return 0;
}
