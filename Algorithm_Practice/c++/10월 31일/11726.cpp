#include <iostream>
#include <vector>

using namespace std;

int main(){
    //���丮�� �̿��ϴ� ��� - error - 10007���� ������ �� ������ ���� �߻�
    
    // vector<long long> factorial(1005); //���丮�� ������ dp �̿�
    // int n;
    // long long result = 0;
    // factorial[0]=1;
    // factorial[1]=1;

    // for(int i=2; i<=1004; i++){
    //     if((factorial[i-1]*i)%10007!=0){
    //         factorial[i] = (factorial[i-1]*i)%10007; //���⿡�� 10007�� ������ 8! ���� 0�� ��. 
    //     }
    //     else{
    //         factorial[i] = (factorial[i-1]*i);
    //     }
    // }
    // cout<<factorial[8]<<'\n';
    // cin>>n;

    // //result = 1;

    // for(int i=n; i>=0; i-=2){
    //     //2*1: i��, 1*2: (n-i)/2�� 
    //     result += factorial[(n-i)/2+i]/(factorial[(n-i)/2]*factorial[i])%10007;
    //     result %= 10007;
    // }

    // cout<<result;

    vector<int> dp(1005);
    int n;
    cin>>n;
    dp[1]=1;
    dp[2]=2;

    for(int i=3; i<=n; i++){ //(n-1���� �ִ� �迭�� 2*1 �ϳ� �߰�= n-1������ �迭 ����� ����� ��) + (n-2���� �ִ� �迭�� 1*2 �� �� �߰� = n-2������ �迭 ����� ����� ��) 
        dp[i] = (dp[i-1]+dp[i-2])%10007;
    }
    cout<<dp[n];
}