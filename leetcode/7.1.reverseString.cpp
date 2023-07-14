#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
using namespace std;
//原地反转字符串
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left=0;
        int right=s.size()-1;
        char temp;
        while(left<right){
            temp = s[left];
            s[left]=s[right];
            s[right]=temp;
            left++;
            right--;
        }
    }
};
void myprint(char c){
    cout<<c<<" ";
}
int main(){
    vector<char>s={'h','e','l','l','o'};
    Solution s1;
    cout<<"反转前:"<<endl;
    for_each(s.begin(),s.end(),myprint);
    cout<<endl;
    s1.reverseString(s);
    cout<<"反转后:"<<endl;
    for_each(s.begin(),s.end(),myprint);
    cout<<endl;
    return 0;
}