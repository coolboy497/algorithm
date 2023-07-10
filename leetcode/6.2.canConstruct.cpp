#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <cmath>
using namespace std;
//给你两个字符串：ransomNote 和 magazine
//判断 ransomNote 能不能由 magazine 里面的字符构成
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int lens = ransomNote.length();
        int lent = magazine.length();
        unordered_map<char,int>mt;
        for(int i=0;i<lent;i++){
            mt[magazine[i]]++;
        }
        for(int k=0;k<lens;k++){
            if(mt[ransomNote[k]]!=0){
                mt[ransomNote[k]]--;
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
int main(){
    string ransomNote="aa";
    string magazine="ab";
    Solution s1;
    bool k=s1.canConstruct(ransomNote,magazine);
    if(k){
        cout<<"字符串ransomNote能由字符串magazine中的字符构成"<<endl;
    }
    else{
        cout<<"字符串ransomNote不能由字符串magazine中的字符构成"<<endl;
    }
    return 0;
}