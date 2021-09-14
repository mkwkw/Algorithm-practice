#include <iostream>
#include <deque>

using namespace std;

void making(deque<int> d){
    int num;
    for(int i=0; i<8; i++){
        cin>>num;
        dq.push_back(num);
    }
}

//하나의 톱니바퀴를 돌림으로써 발생하는 연쇄작용은 어떻게 구현할 것인가?
void roll1(deque<int> dq[], int gear, int direction){ //시계 방향, 반시계 방향으로 돌았을 때
    if(direction==1) {
        int p = dq[gear-1].pop_back();
        dq[gear-1].push_front(p);
//        if(gear==2||gear==3){
//            if(dq[gear-1][2]==dq[gear][6]){
//                int p = dq[gear].pop_front();
//                dq[gear].push_back(p);
//            }
//            else if(dq[gear-2][2]==dq[gear-1][6]){
//                int p = dq[gear-2].pop_front();
//                dq[gear-2].push_back(p);
//            }
//
//        }
    }
    else{
        int p = dq[gear-1].pop_front();
        dq[gear-1].push_back(p);
    }
}

void roll2(deque<int> dq[], int gear, int direction){

}



int counting(deque<int>d1, deque<int>d2, deque<int>d3, deque<int>d4){
    int result=0;
    if(d1[0]==1)
        result += 1;
    if(d2[0]==1)
        result += 2;
    if(d3[0]==1)
        result += 4;
    if(d4[0]==1)
        result += 8;
    return result;
}

int main(){
    deque<int> dq[4];

    dq[0]=deque<int> dq1(8);
    dq[1]=deque<int> dq2(8);
    dq[2]=deque<int> dq3(8);
    dq[3]=deque<int> dq4(8);

    making(dq1);
    making(dq2);
    making(dq3);
    making(dq4);

    int n;
    int answer;

    cin>>n;

    for(int i=0; i<n; i++){
        int g, d;
        cin>>g>>d;
        roll(g,d);
    }

    counting(dq1, dq2, dq3, dq4);

}