#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

//stack - pair<int,int> - 인덱스, 가격
//st.top().second인 가격보다 prices[i]가 같거나 높으면 stack에 저장
//st.top().second인 가격보다 prices[i]가 낮으면 st.top().second 값이 prices[i]보다 같거나 작을 때까지 pop
//pop할 때, st.top().first와 i 차이 비교하고 answer 배열에 저장
//마지막에 stack에 남아있는 pair는 prices.size()-1과 차이 비교하고 answer 배열에 저장 
vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<pair<int,int>> priceSt; //인덱스, 가격
    
    answer.assign(prices.size(), 0);
    
    for(int i=0; i<prices.size(); i++){
        if(priceSt.empty() || (!priceSt.empty()&&priceSt.top().second<=prices[i])){
            priceSt.push({i, prices[i]});
        }
        else{
            while(!priceSt.empty()&&(priceSt.top().second>prices[i])){
                answer[priceSt.top().first] = i-priceSt.top().first;
                priceSt.pop();
            }
            priceSt.push({i, prices[i]});
        }
        
        
    }
    
    while(!priceSt.empty()){
        int idx = priceSt.top().first;
        answer[idx] = prices.size()-1-idx;
        priceSt.pop();
    }
    
    return answer;
}