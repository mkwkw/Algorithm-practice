#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//큐
int main(){
    queue<int> card;
    int n;

    cin>>n;

    for(int i=1; i<=n; i++){
        card.push(i);
    }

    if(card.size()==1){
        cout<<card.front();
        return 0;
    }

    while(card.size()>1){
        card.pop();
        
        if(card.size()==1){
            break;
        }

        int f = card.front();
        card.pop();
        card.push(f);
    }

    cout<<card.front();
    
}