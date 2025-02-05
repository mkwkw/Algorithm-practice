#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    long long answer = 0;
    vector<vector<vector<long long>>> dp(101, vector<vector<long long>>(10,vector<long long>(1<<10, 0))); 
    
    //dp[i][j][k]: 길이가 i인 계단수 중에 끝자리가 j인 경우의 수 중 현재까지 방문한 수를 비트로 변환한 값이 k인 경우의 수
    //길이가 1인 계단수: (1), (2), (3), (4), (5), (6), (7), (8), (9) (0은 X)
    //비트마스킹
    for(int j=1; j<=9; j++)
    {
        dp[1][j][1<<j] = 1;
    }

    for(int i=2; i<=100; i++)
    {
        for(int j=0; j<=9; j++)
        {
            for(int k=0; k<(1<<10); k++)
            {
                if (j-1 >= 0)
                    dp[i][j][k | (1 << j)] += dp[i-1][j-1][k]; //k | (1 << j)
                if (j+1 <= 9)
                    dp[i][j][k | (1 << j)] += dp[i-1][j+1][k];
                dp[i][j][k | (1 << j)] %= 1000000000;
            }
        }
    }

    cin>>n;

    for(int j=0; j<=9; j++)
    {
        answer += dp[n][j][1023];
        answer %= 1000000000;
    }

    cout<<answer;
}