#include<iostream>
#include<functional>
#include <algorithm>
#include<vector>
#include<ctime>
using namespace std;
void print01(int val){
    cout<<val<<" ";
}
int main(){
    srand((unsigned int)time(NULL));
    vector<int>v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    random_shuffle(v.begin(),v.end());
    for_each(v.begin(),v.end(),print01);
    cout<<endl;
    return 0;
}