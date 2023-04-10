#include <iostream>
#include <set> //Áßº¹X

using namespace std;

int main(){
    set<string> players;
    int n;
    char game;

    cin>>n>>game;

    for(int i=0; i<n; i++){
        string player;
        cin>>player;
        players.insert(player);
    }

    switch(game){
        case 'Y':
            cout<<players.size();
            break;
        case 'F':
            cout<<players.size()/2;
            break;
        case 'O':
            cout<<players.size()/3;
            break;
    }
    
}