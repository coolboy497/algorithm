#include<iostream>
using namespace std;
int main(){
    int arr[10]={2,4,0,5,7,1,3,8,9,2};
    int len = sizeof(arr)/sizeof(arr[0]);
    // cout << len<<endl;
    int temp;
    for(int i=0;i<len-1;i++){
        for(int j=0;j<len-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for(int i =0;i<len;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}