#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
    stack<int> s;
    // 入栈
    for(int i=0;i<5;i++){
        s.push(i);
    }
    while(!s.empty()){
        cout<<"栈顶元素为: "<<s.top()<<endl;
        s.pop();
    }
    cout<<"当前栈的大小: "<<s.size()<<endl;
    return 0;
}