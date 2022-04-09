#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(){
    deque<char> wheel;
    //vector<char> wheel;
    int n, k, idx=0, move;
    char top, alpha;
    bool flag = true;
    cin>>n>>k;

    //기본적으로 deque을 ?로 n개 채우기
    for(int i=0; i<n; i++){
        wheel.push_back('?');
    }

    for(int i=0; i<k; i++){
        cin>>move>>alpha;

        //move-1개 앞에서 빼고 뒤에서 넣기 
        for(int j=0; j<move-1; j++){
            top = wheel.front();
            wheel.pop_front();
            wheel.push_back(top);
        }

        //wheel의 맨 앞 원소가 무엇인지에 따라 동작 결정
        top = wheel.front();
        
        if(top=='?' || top==alpha){
            wheel.pop_front();
            wheel.push_back(alpha);
        }
        else{
            flag=false;
            break;
        }

    }

    if(!flag){
        cout<<"!";
        return 0;
    }

    //시계방향으로 출력해야하므로 deque의 뒤에서부터 출력
    while(!wheel.empty()){
        top = wheel.back();
        cout<<top;
        wheel.pop_back();
    }
    

}