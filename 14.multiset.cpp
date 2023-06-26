#include <iostream>
#include <set>
using namespace std;
int main(){
    set<int> s;
    pair<set<int>::iterator,bool> ret = s.insert(10);
    if(ret.second){
        cout<<"第一次插入10成功"<<endl;
    }
    else{
        cout<<"第一次插入10失败"<<endl;
    }
    ret = s.insert(10);
    if(ret.second){
        cout<<"第二次插入10成功"<<endl;
    }
    else{
        cout<<"第二次插入10失败"<<endl;
    }

    multiset<int> ms;
    ms.insert(10);
    ms.insert(10);
    for(multiset<int>::iterator it=ms.begin();it!=ms.end();it++){
        cout<<(*it)<<endl;
    }
    return 0;
}