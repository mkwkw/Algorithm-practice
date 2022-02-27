#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<pair<int, int>> item; //����, ��ġ
    vector<vector<int>> dp; //�ε��� i�� ��=���԰� i�� ��, �ִ� ��ġ ����
    int n, k, w, v, answer=0;
    cin>>n>>k;

    item.assign(n+1, {0,0});
    dp.assign(n+1,vector<int>(k+1,0));

    for(int i=1; i<=n; i++){
        cin>>w>>v;
        item[i]=make_pair(w,v);
    }

    sort(item.begin(), item.end()); //���� ���� �������� ����

    for (int i = 1; i <= n; i++) { //�� ��ǰ�� ����, i: ��ǰ ��ȣ, j: �ִ� �賶 ����
        for (int j = 1; j < item[i].first; j++) //�켱 �ش� ��ǰ�� �賶�� ���� �� ���� ���
            dp[i][j] = dp[i - 1][j]; //�� �� ��ǰ�� ���� ���� ������ �ִ� ����
        for (int j = item[i].first; j <= k; j++) //�ش� ��ǰ�� �賶�� �ִ°� ������ ���
            dp[i][j] = max(dp[i - 1][j - item[i].first] + item[i].second, dp[i - 1][j]); //�賶�� �ִ� ���� �� �ִ� ��� �� �ִ� ����
    }
    
    cout<<dp[n][k];
}

//�� ������ �ִ��� �� �ִ���
//dp[1][j]: j������ ��, ����1�� �־��� ��, �� �־��� �� �� ū ���� ����ȴ�.