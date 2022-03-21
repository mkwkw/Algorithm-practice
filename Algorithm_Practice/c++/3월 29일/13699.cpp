#include <iostream>
#include <vector>

using namespace std;

//���� �� long long���� �ؾ���. ����
long long t(int n){
    vector<long long>dp(36,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2; i<=n; i++){
        for(int j=0; j<=i-1; j++){
            dp[i] += dp[j]*dp[i-j-1];
            //cout<<"dp["<<i<<"]: "<<dp[i]<<" j: "<<j<<" n-j-1: "<<n-j-1<<'\n';
        }
    }

    return dp[n];
}

int main(){
    long long answer;
    int n;
    cin>>n;

    answer = t(n);

    cout<<answer;
}

//��ȭ��->�ڵ� (�� �ε����� ���� i-1�̾����.)