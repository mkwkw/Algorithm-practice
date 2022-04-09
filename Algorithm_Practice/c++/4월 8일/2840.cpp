#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(){
    deque<char> wheel;
    //vector<char> wheel;
    int n, k, idx=0, move;
    char top, alpha;
    bool flag = true;
    cin>>n>>k;

    //�⺻������ deque�� ?�� n�� ä���
    for(int i=0; i<n; i++){
        wheel.push_back('?');
    }

    for(int i=0; i<k; i++){
        cin>>move>>alpha;

        //move-1�� �տ��� ���� �ڿ��� �ֱ� 
        for(int j=0; j<move-1; j++){
            top = wheel.front();
            wheel.pop_front();
            wheel.push_back(top);
        }

        //wheel�� �� �� ���Ұ� ���������� ���� ���� ����
        top = wheel.front();
        
        if(top=='?' || top==alpha){
            wheel.pop_front();
            wheel.push_back(alpha);
        }
        else{
            flag=false;
            break;
        }

    }

    if(!flag){
        cout<<"!";
        return 0;
    }

    //�ð�������� ����ؾ��ϹǷ� deque�� �ڿ������� ���
    while(!wheel.empty()){
        top = wheel.back();
        cout<<top;
        wheel.pop_back();
    }
    

}