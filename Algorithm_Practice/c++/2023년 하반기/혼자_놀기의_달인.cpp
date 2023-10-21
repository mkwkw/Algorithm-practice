#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int cnt, minNum = 100;
void dfs(int cardNum, vector<int> cards, vector<int> heads, vector<int> temp){
    cout<<heads[cards[cardNum]]<<' '<<cards[cardNum]<<'\n';
    if(heads[cards[cardNum]] == cards[cardNum]){
        cnt++;
        minNum = min(minNum, cards[cardNum]);
        heads[cardNum] = minNum;
        temp.push_back(cards[cardNum]);
        cout<<cards[cardNum]<<'\n';
        dfs(cards[cardNum], cards, heads, temp);
    }
    else{
        for(int i=0; i<temp.size(); i++){
            heads[temp[i]] = minNum;
        }
        return;
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
    
    vector<int> heads;
    heads.assign(cards.size()+1, 0);
    
    for(int i=1; i<=cards.size(); i++){
        heads[i] = i;
    }
    
    for(int i=1; i<cards1.size(); i++){
        
        //집합 찾기
        cout<<heads[cards1[i]]<<' '<<cards1[i]<<'\n';
        if(heads[cards1[i]]==cards1[i]){
            cnt = 1;
            minNum = cards1[i];
            dfs(cards1[i],cards1, heads,{cards1[i]});
            setSize.push_back(cnt);
        }
        
    }
    
    for(int i=0; i<setSize.size(); i++){
        cout<<setSize[i]<<' ';
    }
    
    if(setSize.size()==1){
        answer = 0;
    }
    else{
        sort(setSize.begin(), setSize.end(), greater<>());
        answer = setSize[0]*setSize[1];
    }
    
    return answer;
}