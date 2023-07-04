#include <iostream>
#include <string>
using namespace std;
int main(){
    pair<string,int> p ("tom",20);
    pair<string,int> p2 = make_pair("john",18);
    cout<<"姓名: "<<p.first<<" 年龄: "<<p.second<<endl;
    cout<<"姓名: "<<p2.first<<" 年龄: "<<p2.second<<endl;
}
