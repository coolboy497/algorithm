#include <iostream>
#include <string>
using namespace std;
class MyAdd{
public:
    int myadd(int v1,int v2){
        return v1+v2;
    }
};

// （1）函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
void test01(){
    MyAdd m;
    cout<<"test01:"<<endl;
    cout<<m.myadd(10,10)<<endl;
}
// （2）函数对象超出普通函数的概念，函数对象可以有自己的状态
void test02(){
    
}
// （3）函数对象可以作为参数传递
void test03(){
    
}
int main(){
    test01();
    test02();
    test03();
    return 0;
}