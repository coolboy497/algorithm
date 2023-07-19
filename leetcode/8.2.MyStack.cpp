#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
#include <deque>
using namespace std;
//用队列实现栈
class MyStack {
public:
    deque<int>din;
    //将元素x压入栈顶
    MyStack() {

    }
    //将元素x压入栈顶
    void push(int x) {
        din.push_back(x);
    }
    //移除并返回栈顶元素
    int pop() {
        int result = din.back();
        din.pop_back();
        return result;
    }
    //返回栈顶元素
    int top() {
        int result = din.back();
        return result;
    }
    //如果栈是空的，返回true
    bool empty() {
        return din.empty();
    }
};
int main(){
    MyStack mystack;
    return 0;
}