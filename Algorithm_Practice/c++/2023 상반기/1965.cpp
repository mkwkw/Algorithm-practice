#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, answer=0;
    vector<int> box, dp;

    cin>>n;

    box.assign(n, 0);
    dp.assign(n, 0); //�ش� �ε������� ���� ����

    for(int i=0; i<n; i++){
        cin>>box[i];
    }

    for(int i=0; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(box[j]<box[i] && dp[j]+1>dp[i]){ //���� ���� ũ�� �� �� ���� ���� ���� ��
                dp[i] = dp[j]+1;
            }
        }
        answer = max(answer, dp[i]); 
    }

    cout<<answer; //�׳� dp[n-1] ���� ����ϸ� {1,2,3,1} �̷� ������ �־��� �� ������ 3�� �ƴ϶� 1�� ��µ�.

}