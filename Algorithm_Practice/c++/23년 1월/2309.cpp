#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//���� - 100 �ؼ� ������ �� �� ���� �� ���̸�ŭ�� �� ���� ��.

int main(){
    int sum=0, diff=0;
    bool flag = false;
    vector<int> dwarf(9,0);
    
    for(int i=0; i<9; i++){
        cin>>dwarf[i];
        sum += dwarf[i];
    }

    diff = sum-100;

    sort(dwarf.begin(), dwarf.end());

    for(int i=0; i<8; i++){
        for(int j=i+1; j<9; j++){
            if(dwarf[i]+dwarf[j]==diff){
                dwarf[i]=0;
                dwarf[j]=0;
                flag = true;
                break;
            }
        }
        if(flag){
            break;
        }
    }

    for(int i=0; i<9; i++){
        if(dwarf[i]!=0){
            cout<<dwarf[i]<<'\n';
        }
    }


}