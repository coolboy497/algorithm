#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
using namespace std;
typedef struct student{
    string name;
    int age;
    student *next;
}Student;
Student *createlist(int n){
    // Student head放到栈区,函数执行完后自动释放
    string name = "学生";
    Student *head = new Student;//放到堆区，手动决定释放，最后有垃圾回收机制回收
    Student *pre = head;
    for(int i=0;i<n;i++){
        Student *p = new Student;
        p->name = name+to_string(i+1);
        p->age = i+1;
        pre->next = p;
        pre = p;
        p->next = NULL;
    }
    return head;
}
void display(Student *head){
    Student *p = head->next;
    while(p!=NULL){
        cout<<"name: "<<p->name<<endl;
        cout<<"age: "<<p->age<<endl;
        p=p->next;
    }
}
int main(){
    Student *head = new Student;
    head = createlist(5);
    display(head);
    return 0;
}