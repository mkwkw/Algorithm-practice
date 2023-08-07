#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//정렬
//정렬 기준 custom
bool comp(const pair<int,int> &a, const pair<int,int> &b){
    if(a.second==b.second){
        return a.first<b.first;
    }

    return a.second<b.second;    
}

int main(){
    int n;
    vector<pair<int, int>> pos;

    cin>>n;

    pos.assign(n, {0,0});

    for(int i=0; i<n; i++){
        int x, y;
        cin>>x>>y;
        pos[i] = {x,y};
    }

    sort(pos.begin(), pos.end(), comp);

    for(int i=0; i<n; i++){
        cout<<pos[i].first<<' '<<pos[i].second<<'\n';
    }
}