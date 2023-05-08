#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    vector<int> dp, children;
    int n, lisLength = 0;

    cin>>n;

    dp.assign(n, 1); //현재 인덱스까지 가장 긴 길이의 수열 길이
    children.assign(n, 0);

    for(int i=0; i<n; i++){
        cin>>children[i];
    }

    for(int i=1; i<n; i++){
        int maxCnt = 0;
        for(int j=0; j<i; j++){
            if(children[j]<children[i] && dp[j]+1>dp[i]){
                dp[i] = dp[j]+1;
            }
        }
    }

    for(int i=0; i<n; i++){
        lisLength = max(lisLength, dp[i]);
    }

    cout<<n-lisLength;
}

//가장 긴 길이 수열 구하고 직접 옮기는 것 구현 -> 시간 초과 - 그냥 n-가장 긴 길이의 증가하는 수열 길이 해도 됨.
/*
//아이들이 오름차순으로 서있는가
bool verify(vector<int> &children){
    bool flag = true;

    for(int i=0; i<children.size()-1; i++){
        if(children[i]+1!=children[i+1]){
            flag = false;
            break;
        }
    }

    return flag;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //vector<int> dp; //현재 인덱스까지 가장 긴 길이의 증가하는 수열 길이
    int n, answer = 0;
    vector<int> children;

    cin>>n;

    children.assign(n, 0);
    
    for(int i=0; i<n; i++){
        cin>>children[i];
    }

    while(!verify(children)){
        vector<vector<pair<char, int>>> dpLis(n); //가장 긴 길이의 증가하는 수열의 아이들 번호, 인덱스
        int maxCnt = 0, maxIdx = 0, insertPos = 0;
        dpLis[0].push_back({children[0], 0});

        for(int i=1; i<n; i++){
            int maxLisCnt = 0; //children[i]보다 앞에 있는 작은 것들의 수
            for(int j=0; j<i; j++){
                if(children[j]<children[i]){
                    if(maxLisCnt<dpLis[j].size()){
                        maxLisCnt = dpLis[j].size();
                        dpLis[i] = dpLis[j];
                    }
                }
            }
            //dp[i] += maxLisCnt;
            dpLis[i].push_back({children[i], i});
        }

        for(int i=0; i<n; i++){
            if(maxCnt < dpLis[i].size()){
                maxCnt = dpLis[i].size();
                maxIdx = i;
            }
        }

        //cout<<"children length: "<<children.size()<<" dpLis size: "<<dpLis.size()<<'\n';
        
        for(int i=0; i<children.size(); i++){
            bool flag = false; //현재 lis에 chlidren[i]가 있는가
            for(int j=0; j<dpLis[maxIdx].size(); j++){
                
                if(children[i]==dpLis[maxIdx][j].first){
                    flag = true;
                    break;
                }
                else{
                    if(children[i]<dpLis[maxIdx][0].first){
                        insertPos = 0;
                        break;
                    }
                    if(dpLis[maxIdx][j].first<children[i]){
                        insertPos = dpLis[maxIdx][j].second+1;
                    }
                }
            }

            if(!flag){
                children.insert(children.begin()+insertPos, children[i]);
                if(insertPos<i){
                    children.erase(children.begin()+i+1);
                }
                else{
                    children.erase(children.begin()+i);
                }
                
                //cout<<"insertPos: "<<insertPos<<' '<<children[i]<<'\n';
                //cout<<"erasePos: "<<i<<' '<<children[i]<<'\n';
                //for(int i=0; i<n; i++){
                //    cout<<children[i]<<' ';
                //}
                //cout<<'\n';
                answer++;
                break;
            }
            
        }
    }

    cout<<answer;

}
*/