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

    //dp �迭�� 3�������� �̿��ؾ���
    //dp[�̵� Ƚ��][�ڵ��� ��ġ][�ð�] = �����ڵ��� ����
    dp.assign(31, vector<vector<int>>(2, vector<int>(1001, 0)));

    for(int i=1; i<=t; i++){
        cin>>tree[i];
    }

    //���� ������ �ڵ��� ��ġ ���� - max(���� �������� ��, �������� �ʾ��� ��), 2���� ���
    
    
    for (int j = 0; j <= w; j++)
	{
		for (int i = 1; i <= t; i++)
		{
			if (j == 0)
			{	//ó�� ���۽� �ڵδ� 1�� ���� �Ʒ� ��ġ���ִ�.
				dp[j][0][i] = dp[j][0][i - 1] + (tree[i] == 1);
			}
			else
			{
				//ù ���� ���Ĵ�, ��ġ ������or�ȿ�����, ����or�������� Ȯ���ϸ� üũ�Ѵ�.
				dp[j][0][i] = max(dp[j][0][i - 1] + (tree[i] == 1), dp[j - 1][1][i - 1] + (tree[i] == 1));
				dp[j][1][i] = max(dp[j][1][i - 1] + (tree[i] == 2), dp[j - 1][0][i - 1] + (tree[i] == 2));
				// dp[�̵�Ƚ��][�ڵ��� ��ġ][�帥 �ð�] = 
				// (�̵������ʰ� �ð��� 1�� �帧 + i��° �Է°� ���� ��ġ�� ������?), 
				// (�̵��߰�, 1�� �帧 + i��° �Է°� ���� ��ġ�� ������?) �� ū ��
			}
		}
	}

    for(int i=0; i<2; i++){
        for(int j=0; j<=w; j++){
            answer = max(answer, dp[j][i][t]);
        }
    }


    //Ʋ�� Ǯ��
    //dp[0]: {0�������� �̵�Ƚ��, 0�������� �ڵ� ����}
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