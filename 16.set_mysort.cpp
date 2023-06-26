#include <iostream>
#include <set>
using namespace std;
// 将set容器的默认从小到大规则改变成从大到小
class mycompare{
public:
    bool operator()(int v1,int v2){
        return v1 > v2;
    }
};
int main(){
    set <int,mycompare> s;
    s.insert(10);
    s.insert(30);
    s.insert(20);
    s.insert(50);
    s.insert(40);
    for(auto it = s.begin();it!=s.end();it++){
        cout<<(*it)<<endl;
    }
    return 0;
}