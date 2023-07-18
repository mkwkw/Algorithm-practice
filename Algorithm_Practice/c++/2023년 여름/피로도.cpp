#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//가능한 최소 피로도의 던전 중, ((k-소모 피로도)>=최소 필요 피로도)인 던전 개수가 최대인 것 찾기  
bool comp(const pair<int,int> &a, const pair<int,int> &b){
    
    if(a.first==b.first){
        return a.second<b.second;
    }
    
    return a.first>b.first;
}

//k이하의 최소 필요도를 갖는 던전 중에 (k-소모 필요도) 했을 때 가능한 경우 조사하기
vector<pair<int,int>> findDungeon(int k, vector<pair<int,int>> &p){
    vector<pair<int,int>> result;
    
    for(int i=0; i<p.size(); i++){
        if(k>=p[i].first){
            result.push_back({p[i].first, p[i].second});        
        }
    }
    
    return result;
}

int solution(int k, vector<vector<int>> dungeons) {
    vector<pair<int,int>> exhaust, temp;
    vector<bool> visited;
    int answer = 0;
    
    for(int i=0; i<dungeons.size(); i++){
        exhaust.push_back({dungeons[i][0], dungeons[i][1]});
    }
    
    visited.assign(exhaust.size(), false);
    
    sort(exhaust.begin(), exhaust.end(), comp);
    
    for(int l=0; l<exhaust.size(); l++){ //총 for문 도는 횟수 
        temp = findDungeon(k, exhaust);
        /*
        cout<<"k: "<<k<<" temp size: "<<temp.size()<<'\n';
        for(int j=0; j<temp.size(); j++){
            cout<<temp[j].first<<' '<<temp[j].second<<'\n';
        }*/
        int maxCnt = 0, maxIdx = -1;
        for(int i=0; i<temp.size(); i++){
            vector<pair<int,int>> t;
            t = findDungeon(k-temp[i].second, temp);
            if(t.size()>maxCnt){
                if(!visited[i+(exhaust.size()-temp.size())]){
                    maxCnt = t.size();
                    maxIdx = i+(exhaust.size()-temp.size());
                }
            }
        }
        //cout<<"maxIdx: "<<maxIdx<<'\n';
        if(maxIdx==-1){
            if(temp.size()>0 && k>=temp[0].first){
                answer++;
            }
            break;
        }
        
        k -= exhaust[maxIdx].second;
        visited[maxIdx] = true;
        answer++;
        exhaust[maxIdx].first = 1001;
    }
    return answer;
}