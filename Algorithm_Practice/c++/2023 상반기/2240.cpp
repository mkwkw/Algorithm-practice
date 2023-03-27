#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t, w, answer=0, pos=1;
    vector<int> tree;
    //vector<vector<pair<int,int>>> dp;
    vector<vector<vector<int>>> dp;

    cin>>t>>w;

    tree.assign(t+1, 0);

    //dp 배열로 3차원벡터 이용해야함
    //dp[이동 횟수][자두의 위치][시간] = 받은자두의 개수
    dp.assign(31, vector<vector<int>>(2, vector<int>(1001, 0)));

    for(int i=1; i<=t; i++){
        cin>>tree[i];
    }

    //현재 떨어진 자두의 위치 기준 - max(내가 움직였을 때, 움직이지 않았을 때), 2가지 경우
    
    
    for (int j = 0; j <= w; j++)
	{
		for (int i = 1; i <= t; i++)
		{
			if (j == 0)
			{	//처음 시작시 자두는 1번 나무 아래 위치해있다.
				dp[j][0][i] = dp[j][0][i - 1] + (tree[i] == 1);
			}
			else
			{
				//첫 시작 이후는, 위치 움직임or안움직임, 받음or못받음을 확인하며 체크한다.
				dp[j][0][i] = max(dp[j][0][i - 1] + (tree[i] == 1), dp[j - 1][1][i - 1] + (tree[i] == 1));
				dp[j][1][i] = max(dp[j][1][i - 1] + (tree[i] == 2), dp[j - 1][0][i - 1] + (tree[i] == 2));
				// dp[이동횟수][자두의 위치][흐른 시간] = 
				// (이동하지않고 시간만 1초 흐름 + i번째 입력과 현재 위치가 같은가?), 
				// (이동했고, 1초 흐름 + i번째 입력과 현재 위치가 같은가?) 중 큰 값
			}
		}
	}

    for(int i=0; i<2; i++){
        for(int j=0; j<=w; j++){
            answer = max(answer, dp[j][i][t]);
        }
    }


    //틀린 풀이
    //dp[0]: {0번까지의 이동횟수, 0번까지의 자두 개수}
    /**
     * if(tree[i]!=pos){
            move++;
            pos = tree[i];
        }

        if(move>w){
            break;
        }
    */

    // for(int i=0; i<t; i++){
    //     cin>>tree[i];
    // }

    // for(int i=0; i<t; i++){
    //     int move = 0;
    //     int cnt = 1;
    //     vector<pair<int, int>> p;
    //     if(tree[i]!=pos){
    //         move++;
    //         //pos = tree[i];
    //     }
        
    //     p.push_back({move, cnt});
    //     dp.push_back(p);

    // }

    // for(int i=1; i<t; i++){
    //     for(int k=0; k<i-1; k++){
    //         for(int j=0; j<dp[k].size(); j++){
    //             int prevMoveCnt = dp[k][j].first;
    //             int prevPlumCnt = dp[k][j].second;

    //             if(tree[i]!=tree[k]){
    //                 dp[i].push_back({prevMoveCnt+1, prevPlumCnt+1});
    //                 if(prevMoveCnt+1>w){
    //                     break;
    //                 } 
    //             }
    //             else{
    //                 dp[i].push_back({prevMoveCnt, prevPlumCnt+1});
    //                 if(prevMoveCnt>w){
    //                     break;
    //                 } 
    //             }
    //             answer = max(answer, prevPlumCnt+1);
    //         }
    //     }
    // }

    /*
    for(int i=0; i<t; i++){
        for(int j=0; j<dp[i].size(); j++){
        cout<<"i: "<<i<<'\n';
        cout<<dp[i][j].first<<' '<<dp[i][j].second<<'\n';
           
        }
        cout<<'\n';
    }
    */
    
    

    cout<<answer;

}