#include <iostream>
#include <string>
#include <vector>
using namespace std;
void test01(){
    vector<vector<int>> v;
    vector<int> v1;
    vector<int> v2;
    for(int i=0;i<4;i++){
        v1.push_back(i+1);
        v2.push_back(i+2);
    }
    v.push_back(v1);
    v.push_back(v2);
    for(vector<vector<int>>::iterator it = v.begin(); it!=v.end();it++){
        for(vector<int>::iterator ot = (*it).begin();ot!=(*it).end();ot++){
            cout<<(*ot)<<endl;
        }
    }
}
int main(){
    test01();
    return 0;
}