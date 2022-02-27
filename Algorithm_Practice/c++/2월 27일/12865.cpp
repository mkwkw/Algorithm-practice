#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<pair<int, int>> item; //무게, 가치
    vector<vector<int>> dp; //인덱스 i일 때=무게가 i일 때, 최대 가치 저장
    int n, k, w, v, answer=0;
    cin>>n>>k;

    item.assign(n+1, {0,0});
    dp.assign(n+1,vector<int>(k+1,0));

    for(int i=1; i<=n; i++){
        cin>>w>>v;
        item[i]=make_pair(w,v);
    }

    sort(item.begin(), item.end()); //무게 기준 오름차순 정렬

    for (int i = 1; i <= n; i++) { //각 물품에 대해, i: 물품 번호, j: 최대 배낭 무게
        for (int j = 1; j < item[i].first; j++) //우선 해당 물품을 배낭에 넣을 수 없는 경우
            dp[i][j] = dp[i - 1][j]; //그 전 물품에 대한 현재 무게의 최댓값 저장
        for (int j = item[i].first; j <= k; j++) //해당 물품을 배낭에 넣는게 가능한 경우
            dp[i][j] = max(dp[i - 1][j - item[i].first] + item[i].second, dp[i - 1][j]); //배낭에 넣는 경우와 안 넣는 경우 중 최댓값 저장
    }
    
    cout<<dp[n][k];
}

//이 물건을 넣느냐 안 넣느냐
//dp[1][j]: j무게일 때, 물건1을 넣었을 때, 안 넣었을 때 중 큰 수가 저장된다.