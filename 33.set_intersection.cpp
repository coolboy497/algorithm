#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
void myprint(int val){
    cout<<val<<" ";
}
int main(){
    vector<int>v1;
    vector<int>v2;
    for(int i=0;i<10;i++){
        v1.push_back(i);
        v2.push_back(i+5);
    }
    vector<int>vTarget;
    vTarget.resize(min(v1.size(),v2.size()));
    vector<int>::iterator end = set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());
    //为什么用接收的end，因为可以只打印出相交的部分
    //如果用vTarget.end(),会打印出 5 6 7 8 9 0 0 0 0 0
    for_each(vTarget.begin(),end,myprint);//5 6 7 8 9 
    return 0;
}