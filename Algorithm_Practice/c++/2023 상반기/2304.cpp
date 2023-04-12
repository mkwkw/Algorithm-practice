#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

//����!
int main(){
    vector<pair<int,int>> pilars; //��ġ, ����
    stack<pair<int, int>> st1; //��ġ, ����
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

    sort(pilars.begin(), pilars.end()); //��ġ ������� ����

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

    //������ top�� ���ؼ�
    //������ ���� Ŀ���� �͸� ����, �������� ���� �۾����� �͸� ����
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
    
    answer += maxHeight; //maxHeight ��� �ϳ��� ������ ���Ǳ� ������ ���� �ϳ� ��������Ѵ�.

    cout<<answer;
}