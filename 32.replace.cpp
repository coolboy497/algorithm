#include<iostream>
#include<functional>
#include <algorithm>
#include<vector>
using namespace std;
void myprint(int val){
    cout<<val<<" ";
}
int main(){
    vector <int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(10);
    v.push_back(30);
    v.push_back(40);
    v.push_back(10);
    cout<<"替换前:"<<endl;
    for_each(v.begin(),v.end(),myprint);
    // 将10替换为1000
    cout<<endl;
    replace(v.begin(),v.end(),10,1000);
    cout<<"替换后:"<<endl;
    for_each(v.begin(),v.end(),myprint);
    return 0;
}