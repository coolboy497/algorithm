#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
using namespace std;
//字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
//请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        int len = s.length();
        cout<<len<<endl;
        s.resize(s.length()+n);
        for(int i=0;i<n;i++){
            s[len+i]=s[i];
        }
        for(int j=0;j<s.length()-n;j++){
            s[j]=s[j+n];
        }
        s.resize(len);
        return s;
    }
};
void myprint(char c){
    cout<<c<<" ";
}
int main(){
    string s="wusrvaiwcuqzdxxtemgangtpahidjsxokiumpsayxctraifbwgjjtxutlpgmdjqgjyzkzxishmyuxsuldqkosbgeafpnlzzjxtio";
    int k = 56;
    Solution s1;
    cout<<"左旋转前:"<<endl;
    cout<<s<<endl;
    string result = s1.reverseLeftWords(s,k);
    cout<<"左旋转后:"<<endl;
    cout<<result<<endl;
    cout<<endl;
    return 0;
}