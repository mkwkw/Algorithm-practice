#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    map<char, int> alphabet={{'A',3}, {'B', 2}, {'C',1}, {'D', 2}, {'E', 3}, {'F', 3}, {'G', 2}, {'H', 3}, {'I', 3}, {'J', 2}, {'K', 2}, {'L', 1}, {'N', 2}, {'M', 2}, {'O', 1}, {'P', 2},{'Q', 2}, {'R',2}, {'S',1}, {'T',2},{'U',1},{'V',1},{'W',1},{'X',2},{'Y',2},{'Z',1}};
    string a, b, c="";
    int n;
    
    cin>>a>>b;
    n = a.length();

    vector<vector<int>> dp(2*n, vector<int>(2*n,0)); //획수 담을 2차원 배열

    //a와 b 이름 합친 초기 상태
    for(int i=0; i<n; i++){
        c += a[i];
        c += b[i];
    }

    for(int i=0; i<2*n; i++){
        dp[0][i]=alphabet[c[i]]; //주어지는 이름 획수 저장
    }

    for(int i=1; i<2*n; i++){
        for(int j=0; j<2*n-i; j++){
            dp[i][j]= (dp[i-1][j]+dp[i-1][j+1])%10; //더해서 일의 자리만 남김   
        }
    }

    cout<<dp[2*n-2][0]<<dp[2*n-2][1];

}