#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
#include <deque>
#include <stack>
#include <ctype.h>
using namespace std;
//根据逆波兰表示法，求表达式的值。
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       stack<long long>result;
       for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="÷"||tokens[i]=="%"){
               long long second_number = result.top();
               result.pop();
               long long first_number = result.top();
               result.pop();
               if(tokens[i]=="+")result.push(first_number+second_number);
               else if(tokens[i]=="-")result.push(first_number-second_number);
               else if(tokens[i]=="*")result.push(first_number*second_number);
               else if(tokens[i]=="÷")result.push(first_number/second_number);
               else if(tokens[i]=="%")result.push(first_number%second_number);
            }
            else{
                result.push(stoll(tokens[i]));
            }
       }
        return result.top();
    }
};
int main(){
    vector<string>a={"2", "1", "+", "3", "*"};//(2+1)*3=9
    Solution s1;
    int result = s1.evalRPN(a);
    cout<<result<<endl;
    return 0;
}