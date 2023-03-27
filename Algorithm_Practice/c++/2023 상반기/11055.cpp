#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, answer=0;
    vector<int> num, dp; 

    cin>>n;

    num.assign(n,0);
    dp.assign(n,0);

    for(int i=0; i<n; i++){
        cin>>num[i];
    }

    for(int i=0; i<n; i++){
        dp[i] = num[i]; //�κ� ���� �ּڰ� = �ڱ��ڽ�
        for(int j=0; j<i; j++){ //�ε��� i ���� ���� �� dp Ž��
            if(num[j]<num[i] && dp[i]<dp[j]+num[i]){ //������ �ִ� ���ڰ� num[i]���� ������ (�����ϴ� ����) && ���� dp[i]���� ���� ���ڱ����� dp ���� + num[i]���� �۴ٸ� ����(�ִ� ��)  
                dp[i] = dp[j]+num[i];
            }
        }
        if(answer<dp[i]){ //�ִ���
            answer = dp[i];
        }
    }
    cout<<answer;
}