#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> sosu;
    vector<bool> prime; //�ε����� ���� �Ҽ����� �ƴ���
    int t;
    
    cin>>t;

    //�� ���� ������ ��, ¦����� ������ �Ҽ��� ������ ��Ÿ�� �� �ִ�.
    //�� ���� ������ ��, Ȧ����� 2+�Ҽ��� ��Ÿ���� ��츸 �Ҽ�+�Ҽ��̴�.
    //�� ���� �� �������� �����ϱ�

    prime.assign(2000001, true);
    prime[0] = false;
    prime[1] = false;
    for(int i=2; i*i<2000000; i++){
        if(prime[i]){
            for(int j=i*i; j<2000000; j+=i){
                prime[j] = false;
            }
        }
    }

    for(int i=2; i<=2000000; i++){
        if(prime[i]){
            sosu.push_back(i);
        }
    }

    for(int i=0; i<t; i++){
        long long a, b, s;
        
        cin>>a>>b;
        
        s = a+b;

        if(s==2 || s==3){
            cout<<"NO\n";
        }
        else if(s%2==0){ //s�� ¦��, ������ �Ҽ�+�Ҽ� ����
            cout<<"YES\n";
        }
        else{// s�� Ȧ��, 2+�Ҽ��� ���
            bool flag = true;
            s -= 2;
            for(int j=0; j<sosu.size() && (long long)(sosu[j]*sosu[j])<=s; j++){
                if(s%sosu[j]==0){ //�Ҽ��� ��������� -> �Ҽ��� �ƴ�
                    flag = false;
                    break;
                }
            }

            if(flag){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }

    }    
}