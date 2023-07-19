#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
#include <stack>
using namespace std;
class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;//因为出队列时与入栈顺序不同，需要一个栈来调换顺序
    MyQueue() {

    }
    void push(int x) {
        stIn.push(x);
    }
    int pop() {
        // 出栈为空时，才将入栈中的数据放进来，防止出列顺序混乱
        if(stOut.empty()){
            while(!stIn.empty()){
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }
    int peek() {
        int result = this->pop();
        stOut.push(result);
        return result;
    }
    bool empty() {
        if(stIn.empty()&&stOut.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    MyQueue myqueue;
    return 0;
}