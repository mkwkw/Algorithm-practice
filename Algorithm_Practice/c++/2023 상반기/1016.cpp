#include <iostream>
#include <vector>

using namespace std;

int main(){
    //maxNum�� minNum�� ���̴� �ִ� 1000000
    //[0+minNum]~[num.size()-1+minNum]
    vector<bool> num; //minNum���� ũ�ų� ����, maxNum���� �۰ų� ���� ���� �������� ���������°�
    long long minNum, maxNum;
    int answer = 0; 

    cin>>minNum>>maxNum;

    num.assign(1000001, false);

    for(long long i=2; i*i<=maxNum; i++){
        
        long long cnt = minNum/(i*i); //�������� ��� ����
       
        if(minNum%(i*i)==0){
            cnt++;
        }
        
        while(cnt*(i*i)<=maxNum){
            
            if(cnt*(i*i)-minNum>=0){
                num[cnt*(i*i)-minNum] = true;
            }
            cnt++;
            
        }

    }

    for(int i=0; i<=maxNum-minNum; i++){
        if(!num[i]){
            answer++;
        }
    }

    cout<<answer;
}