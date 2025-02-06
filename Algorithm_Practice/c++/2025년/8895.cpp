#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, l, r, t;

    vector<vector<vector<long long>>> dp(21, vector<vector<long long>>(21, vector<long long>(21, 0)));

    //dp[n][l][r] : n개 막대, 왼쪽에서 보이는 막대 개수 l개, 오른쪽에서 보이는 막대 개수 r개
    dp[1][1][1] = 1;

    for(int n=2; n<=20; n++)
    {
        for(int l=1; l<=n; l++)
        {
            for(int r=1; r<=n; r++)
            {
                //크기가 2~n인 n-1개의 막대가 배열되어있고, 길이가 1인 막대를 위치시킨다고 했을 때
                //n개의 막대&왼쪽에서 보이는 막대의 개수가 l개&오른쪽에서 보이는 막대의 개수가 r개 
                //= n-1개의 막대&왼쪽에서 보이는 막대의 개수가 l-1개&오른쪽에서 보이는 막대의 개수가 r개     (길이가 1인 막대를 맨 왼쪽에 위치)
                // +n-1개의 막대&왼쪽에서 보이는 막대의 개수가 l개&오른쪽에서 보이는 막대의 개수가 r-1개     (길이가 1인 막대를 맨 오른쪽에 위치)
                // +n-1개의 막대&왼쪽에서 보이는 막대의 개수가 l개&오른쪽에서 보이는 막대의 개수가 r개*(n-2) (길이가 1인 막대를 양끝이 아닌 그 사이에 위치)
                dp[n][l][r] = dp[n-1][l-1][r] + dp[n-1][l][r-1] + dp[n-1][l][r] * (n-2);
            }
        }
    }

    cin>>t;

    for(int i=0; i<t; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;

        cout<<dp[a][b][c]<<'\n';
    }
}