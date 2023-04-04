#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, answer = 0;
    cin>>n;

    if(n==1 || n==2){ 
        answer = 2;
        cout<<answer;
        return 0;
    }

    //�Ҽ�: 2, 3, 5, 7
    //�� �ڸ����� �� ��ü�� �Ӹ���Ҽ�
    for(int i=n; i<=1000000000; i++){
        bool flag = true;
        for(int j=2; j<=(int)sqrt(i); j++){
            if(i%j==0){
                flag = false;
                break;
            }
        }

        
        if(flag){ //�Ҽ�
            //�縰��Ҽ� �˻�
            string numStr = to_string(i);
            int len = numStr.length();
            
            bool flag1 = true;
            for(int i=0; i<len/2; i++){ //�糡���� ���� ����� ���鼭 ������ ��
                if(numStr[i]!=numStr[len-1-i]){
                    flag1 = false;
                    break;
                }
            }
            if(flag1){
                answer = i;
                break;
            }            
        }
    }

    cout<<answer;
}