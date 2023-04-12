#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

//스택!
int main(){
    vector<pair<int,int>> pilars; //위치, 높이
    stack<pair<int, int>> st1; //위치, 높이
    stack<pair<int, int>> st2;
    vector<int> roof;
    int n, maxHeight = 0, maxHeightPos1 = 0, maxHeightPos2 = 0, maxHeightIdx = 0, maxHeightCnt = 0, startIdx = 0, endIdx = 0, answer = 0;
    cin>>n;

    pilars.assign(n, {0,0});
    roof.assign(1002, 0);

    for(int i=0; i<n; i++){
        cin>>pilars[i].first>>pilars[i].second;
        maxHeight = max(maxHeight, pilars[i].second);
    }

    sort(pilars.begin(), pilars.end()); //위치 순서대로 정렬

    for(int i=0; i<n; i++){
        if(pilars[i].second==maxHeight){
            maxHeightPos1 = pilars[i].first;
            break;
        }
    }

    for(int i=n-1; i>=0; i--){
        if(pilars[i].second==maxHeight){
            maxHeightPos2 = pilars[i].first;
            break;
        }
    }

    //스택의 top과 비교해서
    //왼쪽은 점점 커지는 것만 들어가게, 오른쪽은 점점 작아지는 것만 들어가게
    st1.push({pilars[0].first, pilars[0].second});
    st2.push({pilars[n-1].first, pilars[n-1].second});

    for(int i=1; i<n; i++){
        if(pilars[i].second>=st1.top().second){
            st1.push({pilars[i].first, pilars[i].second});
        }
    }
    for(int i=n-1; i>=0; i--){
        if(pilars[i].second>st2.top().second){
            st2.push({pilars[i].first, pilars[i].second});
        }
    }

    int prevPos = st1.top().first;
    st1.pop();

    while(!st1.empty()){
        //cout<<"st1: "<<(prevPos-st1.top().first)*st1.top().second<<'\n';
        answer += (prevPos-st1.top().first)*st1.top().second;
        prevPos = st1.top().first;
        st1.pop();
        
    }

    if(!st2.empty()){
        prevPos = st2.top().first;
        st2.pop();
    }
    while(!st2.empty()){
        //cout<<"st2: "<<(st2.top().first-prevPos)*st2.top().second<<'\n';
        answer += (st2.top().first-prevPos)*st2.top().second;
        prevPos = st2.top().first;
        st2.pop();
    }
    
    answer += maxHeight; //maxHeight 기둥 하나가 빠져서 계산되기 때문에 따로 하나 더해줘야한다.

    cout<<answer;
}