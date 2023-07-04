#include<iostream>
#include<functional>
#include <algorithm>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);//pos迭代器会找到这
    v.push_back(1);
    vector<int>::iterator pos = adjacent_find(v.begin(),v.end());
    if(pos==v.end()){
        cout<<"未找到相邻的重复元素"<<endl;
    }
    else{
        cout<<(*pos)<<endl;
    }
    return 0;
}