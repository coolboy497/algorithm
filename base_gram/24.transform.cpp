#include<iostream>
#include<functional>
#include <algorithm>
#include<vector>
using namespace std;
class Transform{
    public:
    int operator()(int val){
        return val+10;
    }
};
class printvector{
    public:
    void operator()(int val){
        cout<<val<<" ";
    }
};
int main(){
    vector<int>source_vector;
    for(int i=0;i<10;i++){
        source_vector.push_back(i);
    }
    vector<int>target_vector;
    target_vector.resize(source_vector.size());//目标容器需要提前开辟空间
    transform(source_vector.begin(),source_vector.end(),target_vector.begin(),Transform());
    for_each(target_vector.begin(),target_vector.end(),printvector());
    return 0;
}