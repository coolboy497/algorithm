#include<iostream>
#include<string>
using namespace std;
// class Building{
//     friend void goodgay(Building &building);//全局函数做友元
// public:
//    Building(){
//     sittingroom = "客厅";
//     bedroom = "卧室";
//    }
//    string sittingroom;
// private:
//    string bedroom;
// };
// void goodgay(Building &building)
// {
//     cout << "好朋友正在游览"<<building.sittingroom<<endl;
//     cout << "好朋友正在游览"<<building.bedroom<<endl;
// }
// void test01(){
//     Building building;
//     goodgay(building);
// }
class Building{
    friend class Goodgay;
public:
   Building();
   string sittingroom;
private:
   string bedroom;
};

Building::Building(){
    sittingroom = "客厅";
    bedroom = "卧室";
}

class Goodgay
{
public:
    Goodgay();
    void visit();
    Building *building;
};

Goodgay::Goodgay(){
    building = new Building;
}

void Goodgay::visit(){
    cout<<"Goodgay类正在访问"<<building->sittingroom <<endl;
     cout<<"Goodgay类正在访问"<<building->bedroom <<endl;
}

void test02(){
    Goodgay gg;
    gg.visit();
}

int main(){
    // test01();
    test02();
    return 0;
}