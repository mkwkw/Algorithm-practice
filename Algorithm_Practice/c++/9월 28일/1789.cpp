#include <iostream>

using namespace std;

//1���� �ϳ��� ���س����� - S�� �ʰ��� ��-1
int main(){
    
    long long s;
    cin>>s;

    long long ssum=0; //�߰� ��
    long long num=1; //�������� ��
    int cnt = 0; //num�� ����

    while(true){
        ssum += num;
        cnt++;

        if(ssum>s){
            break;
        }
        num++;
    }

    cnt--;
    cout<<cnt;

}