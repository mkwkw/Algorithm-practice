#include <iostream>
#include <cmath>

using namespace std;

//���� �ڸ����� ��� ���ϸ� �Ǵϱ� ���� �ڸ��� ����� �Լ��� �ʿ�
int one(int num){
    while(num>10){
        num %= 10;
    }
    return num;
}

int main(){
    int t, a, b, answer;
    long long num;

    cin>>t;

    while(t--){
        cin>>a>>b;
        num = a;
        if(a>10){
            num = one(num);
        }
        for(int i=1; i<b; i++){
            num *= a;
            if(num>10){
                num = one(num);
            }
        }
        
        answer = num;
        if(answer==0){
            answer = 10;
        }
        //cout<<num<<'\n';
        cout<<answer<<'\n';
    }

}
//���� �ڸ��� b�� ���鼭 a�� ����. �׳� pow(a,b)�ϸ� overflow�� �߻��ϹǷ�
//�� �� �� ������ ���� �ڸ��� ����� ���� ����Ʈ