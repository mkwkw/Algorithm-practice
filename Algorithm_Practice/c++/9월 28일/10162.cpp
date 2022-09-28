#include <iostream>

using namespace std;

int main(){
    int time;
    int button[3] = {300, 60, 10};
    int push[3];

    cin>>time;

    if(time%10>0){
        cout<<"-1";
        return 0;
    }

    for(int i=0; i<3; i++){
        push[i] = time/button[i];
        time %= button[i];
    }

    for(int i=0; i<3; i++){
        cout<<push[i]<<' ';
    }
}