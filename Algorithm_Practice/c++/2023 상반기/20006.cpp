#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    vector<pair<int, set<pair<string, int>>>> rooms;    
    int p, m, level;
    string nickname;

    cin>>p>>m;

    for(int i=0; i<p; i++){
        cin>>level>>nickname;

        set<pair<string, int>> players;
        
        bool flag = false; //빈 방에 들어갔는지 여부 - true 빈 방 들어감, false 빈 방 못 들어감 - 방 새로 만들어야함
        for(int j=0; j<rooms.size(); j++){
            if((rooms[j].first-10<=level && level<=rooms[j].first+10) && rooms[j].second.size()<m){
                rooms[j].second.insert({nickname, level});
                flag = true;
                break; //여러 방에 들어가는 것 방지
            }
        }

        if(!flag){
            players.clear();
            players.insert({nickname, level});
        
            rooms.push_back({level, players});
        }

    }

    for(int i=0; i<rooms.size(); i++){
        if(rooms[i].second.size()==m){
            cout<<"Started!\n";

            for(auto player : rooms[i].second){
                cout<<player.second<<' '<<player.first<<'\n';
            }
        }
        else{
            cout<<"Waiting!\n";

            for(auto player : rooms[i].second){
                cout<<player.second<<' '<<player.first<<'\n';
            }
        }
    }

}