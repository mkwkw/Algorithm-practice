#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int n;
    vector<int> dp(1001); //�ε����� ����µ� �ʿ��� �� ����
    cin>>n;

    /* �̷� ���� dp Ȱ���� �ǵ��� �� ����. 
    i-1�����ϰ� 1�� �� �������� �Ͱ� i-3�����ϰ� 3�� �� �������� �� ��
    dp[0]=0;
    dp[1]=1; //1
    dp[2]=2; //1+1
    dp[3]=1; //3
    for(int i=4; i<1001; i++){
        dp[i] = min(dp[i-1]+dp[1], dp[i-3]+dp[3]);
    }*/

    //������ 1,3�� ���̹Ƿ� ¦���� ���ϸ� ¦��, Ȧ���� ���ϸ� Ȧ���̴�.
    //��, n�� Ȧ���϶��� CY, ¦���϶��� SK �����Ƽ� ���´�. 
    if(n%2==0){
        cout<<"SK";
    }
    else{
        cout<<"CY";
    }

}