#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int t, n;

    cin>>t;

    for(int i=0; i<t; i++){      
        vector<queue<int>> teams(201); //������ ������ ť�� �����س��� �뵵
        vector<int> ranking;
        vector<int> newRanking;
        int minSum = 4000;
        int minTeamNum = 0;
        int minTeamFive = 1000;

        cin>>n;

        ranking.assign(n, 0);
        
        for(int j=0; j<n; j++){
            cin>>ranking[j];
            teams[ranking[j]].push(j);
        }

        //���� �ο��� 6���� ���� ���� �������� �����Ѵ�.
        //������ �ٽ� �Űܾ��Ѵ�.
        
        for(int j=0; j<201; j++){
            for(int k=0; k<n; k++){
                if(teams[j].size()<6){
                    if(ranking[k]==j){
                        ranking[k]=0;
                    } 
                }
            }

            while(!teams[j].empty()){
                teams[j].pop();
            }
        }

        for(int j=0; j<n; j++){
            if(ranking[j]!=0){
                newRanking.push_back(ranking[j]);
            }
        }

        for(int j=0; j<newRanking.size(); j++){
            teams[newRanking[j]].push(j);
        }

        for(int j=0; j<201; j++){
            int tempSum = 0;
            if(!teams[j].empty()){

                //���� 4�� ���� ��
                for(int k=0; k<4; k++){
                    tempSum += teams[j].front();
                    teams[j].pop();
                }
                //��� �� �ٲ�� ���
                if(minSum>tempSum){
                    minSum = tempSum;
                    minTeamNum = j;
                    minTeamFive = teams[j].front();
                }
                else if(minSum==tempSum){
                    if(minTeamFive>teams[j].front()){
                        minSum = tempSum;
                        minTeamNum = j;
                        minTeamFive = teams[j].front();
                    }
                }

            }
        }

        cout<<minTeamNum<<'\n';
    }
}