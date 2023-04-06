#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

int main(){
    vector<int> order;
    map<int, int> cnt; //전기용품 이름, 등장 횟수
    vector<queue<int>> pos(101); //[i]의 큐: 제품i의 위치들
    //queue<int> multiTap; //멀티탭 구멍
    set<int> multiTap;
    int n, k, answer=0;

    cin>>n>>k;

    order.assign(k, 0);
    
    for(int i=0; i<k; i++){
        cin>>order[i];
        
        // if(cnt.find(order[i])!=cnt.end()){
        //     cnt[order[i]]++;
        // }
        // else{
        //     cnt[order[i]]=1;
        // }

        pos[order[i]].push(i);
        
    }

    for(int i=0; i<6; i++){
        while(!pos[i].empty()){
            cout<<pos[i].front()<<' ';
            pos[i].pop();
        }
        cout<<'\n';
    }

    //처음에 멀티탭 구멍 다 채우기
    int idx=0;
    while(idx<k && (((multiTap.find(order[idx])!=multiTap.end()) && multiTap.size()<=n) || ((multiTap.find(order[idx])==multiTap.end()) && multiTap.size()<n))){
        multiTap.insert(order[idx]);
        //cnt[order[idx]]--;
        pos[order[idx]].pop();
        //cout<<"order["<<idx<<"]: "<<order[idx]<<'\n';
        idx++;
        //cout<<"i: "<<idx<<" multiTap size: "<<multiTap.size()<<" order["<<idx<<"]: "<<order[idx]<<'\n';
    }

    //처음에 다 끝내면
    if(idx==k-1){
        cout<<0;
        return 0;
    }

    //n==1 && 뒤에 남으면
    if(n==1 && idx<k-1){
        answer = k-1;
        cout<<answer;
        return 0;
    }

    //n>1 && 뒤에 남으면
    for(int i=idx; i<k; i++){

        //뒤에 있는 수 중에 셋에 해당하는 수가 없다면
        if(multiTap.find(order[i])==multiTap.end()){ //뒤에 남은 것 중에 셋에 해당하는 수가 없는 경우
            int minCnt = 100;
            int minName = 0;

            int farDist = 0;
            int farName = 0;
            //멀티탭에 있는 제품 중에 남은 등장 횟수가 가장 작은 것 찾기
            // for(auto s:multiTap){
            //     if(minCnt>cnt[s]){
            //         minCnt = cnt[s];
            //         minName = s; 
            //     }
            // }

            //멀티탭에 있는 제품 중에 다음 수까지의 거리가 가장 먼 것 찾기
            //남은 등장 횟수가 없으면 먼저 지우기
            for(auto s:multiTap){
                if(pos[s].empty()){
                    farName = s;
                    break;
                }
                
                //cout<<"s: "<<s<<' '<<pos[s].front()<<' '<<i<<' '<<pos[s].front() - i<<'\n';
                if(pos[s].front() - i >= farDist){
                    farDist = pos[s].front() - i;
                    farName = s;
                }

            }


            //cout<<"out: "<<farName<<'\n';
            //multiTap.erase(minName);
            multiTap.erase(farName);
            //cout<<multiTap.size()<<'\n';
            answer++;
            multiTap.insert(order[i]);

            // for(auto s: multiTap){
            //     cout<<s<<' ';
            // }
            // cout<<'\n';

            //cnt[order[i]]--;
            pos[order[i]].pop();
            //cout<<multiTap.size()<<'\n';
        }
        else{ //뒤에 남은 것 중에 셋에 해당하는 수가 있는 경우
            //cnt[order[i]]--;
            pos[order[i]].pop();
        }
        
    }

    cout<<answer;

}