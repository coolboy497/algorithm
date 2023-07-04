#include<iostream>
#include<functional>
#include <algorithm>
#include<vector>
using namespace std;
void myprint(int val){
    cout<<val<<" ";
}
int main(){
    vector <int> v1;
    vector <int> v2;
    for(int i=0;i<10;i++){
        v1.push_back(i);
        v2.push_back(i+1);
    }
    vector<int> Target;
    Target.resize(v1.size()+v2.size());
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),Target.begin());
    for_each(Target.begin(),Target.end(),myprint);
    return 0;
}