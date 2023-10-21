#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//dfs, 방문배열
vector<bool> visited;
int dfs(int cardNum, vector<int> cards, int cnt){
    
    if(!visited[cards[cardNum]]){
        //cout<<cards[cardNum]<<'\n';
        visited[cards[cardNum]]=true;
        
        return dfs(cards[cardNum], cards, cnt+1);
    }
    else{
        return cnt;
    }
    
}
int solution(vector<int> cards) {
    int answer = 0;
    vector<int> setSize;
    vector<int> cards1;
    cards1.assign(cards.size()+1, 0);
    for(int i=1; i<=cards.size(); i++){
        cards1[i] = cards[i-1];
    }
        
    visited.assign(cards.size()+1, false);

    for(int i=1; i<cards1.size(); i++){
        
        //집합 찾기
        if(!visited[cards1[i]]){
            visited[cards1[i]] = true;
            setSize.push_back(dfs(cards1[i],cards1,1));
        }
        
    }
    
    // for(int i=0; i<setSize.size(); i++){
    //     cout<<setSize[i]<<' ';
    // }
    
    if(setSize[0]==cards.size()){
        answer = 0;
    }
    else{
        sort(setSize.begin(), setSize.end(), greater<>());
        answer = setSize[0]*setSize[1];
    }
    
    return answer;
}