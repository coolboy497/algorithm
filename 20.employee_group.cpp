#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <ctime>
using namespace std;
class Employee{
public:
    Employee(string name, int salary){
        this->name = name;
        this->salary = salary;
    }
    string name;
    int salary;
};
void printvector(vector <Employee> &v){
    for(auto it = v.begin();it!=v.end();it++){
        cout<<"姓名:"<<it->name<<" 薪水:"<<it->salary<<endl;
    }
    cout<<endl;
}
void printmap(multimap<int,Employee>&m){
    for(auto it=m.begin();it!=m.end();it++){
        cout<<"部门: "<<it->first<<" 姓名："<<it->second.name <<" 薪水: "<<it->second.salary<<endl;
    }
    cout<<endl;
}
void createvector(vector <Employee>&v){
    string x = "ABCDEFGHIJ";
    for(int i=0;i<10;i++){
        string name = "员工";
        name += x[i];
        int salary = rand()%10000+10000;
        Employee p(name,salary);
        v.push_back(p);
    }
}

void createmap(multimap<int,Employee>&m,vector <Employee>&v){
    for(auto it = v.begin();it!=v.end();it++){
        int dept = rand()%3;
        m.insert(make_pair(dept,*it));
    }
}
void finddept(multimap<int,Employee>&m,int dept){
    multimap<int,Employee>::iterator pos = m.find(dept);
    int count = m.count(dept);
    int num = 0;
    for(;pos!=m.end()&&num<count;pos++,num++)
    {
        cout<<"部门: "<<pos->first<<" 姓名："<<pos->second.name <<" 薪水: "<<pos->second.salary<<endl;
    }
}
int main(){
    vector <Employee> v;
    createvector(v);
    printvector(v);
    multimap<int,Employee> m;
    createmap(m,v);
    printmap(m);
    finddept(m,2);
    return 0;
}