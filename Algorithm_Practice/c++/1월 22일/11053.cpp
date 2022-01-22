#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> v; //�Է¹��� ���� ������ �迭
    vector <int> dp;//���� ������ �迭
    int maxLen=0; //�ִ� ���� ������ ����
    int n;

    cin>>n;

    v.assign(n,0);
    dp.assign(n,0);
    for(int i=0; i<n; i++){ //���� �Է� �ޱ�
        cin>>v[i];
    }

    for(int i=0; i<n; i++){
        int minLen=0;
        for(int j=0; j<i; j++){
            if(v[j]<v[i]){
                if(minLen<dp[j])
                    minLen=dp[j]; //i ���� ���� �� �ִ� ���� ã��
            }
        }
        dp[i]=minLen+1; //�� �ִ� ���̿� 1���ؼ� ����
        if(maxLen<dp[i]){
            maxLen = dp[i]; //�ִ� ���� ã��
        }
    }

    cout<<maxLen;

}

//�ش� �ε��������� ���� �� �����ϴ� �κ� ������ ���̸� �����ϴ� �迭 dp�� �����Ѵ�.
//6
//10 20 10 30 20 50 �̸�
//dp = {0+1, 1+1, 0+1, 2+1, 1+1, 3+1} = {1,2,1,3,2,4} �̹Ƿ� ���� �� �����ϴ� �κ� ������ ���̴� 4�̴�.