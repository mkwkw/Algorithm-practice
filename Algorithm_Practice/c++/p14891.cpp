#include <iostream>
#include <deque>

using namespace std;

//하나의 톱니바퀴를 돌림으로써 발생하는 연쇄작용은 어떻게 구현할 것인가?
//같은 극인지 판단하고 돌리는 함수 필요할 듯
void roll1(deque<char> v[], int gear, int direction){ //시계 방향, 반시계 방향으로 도는 함수
    if(direction==1) { //시계방향
        char p = v[gear].back();
        v[gear].pop_back();
        v[gear].push_front(p);
    }
    else{ //반시계방향
        char p = v[gear].front();
        v[gear].pop_front();
        v[gear].push_back(p);
    }
}

void roll2(deque<char> v[], int gear, int direction){

    if(gear==0){ //첫 번째 톱니바퀴 돌림
        if(v[0][2]!=v[1][6]) { //첫 번째 톱니바퀴 & 두 번째 톱니바퀴
            if(v[1][2]!=v[2][6]){
                if(v[2][2]!=v[3][6]) {
                    roll1(v, 3, direction * (-1));
                }
                roll1(v, 2, direction);
            }
            roll1(v, 1, direction * (-1));
        }

//        if(v[0][2]!=v[1][6] && v[1][2]!=v[2][6] && v[2][2]!=v[3][6]){ //첫 번째 톱니바퀴 & 두 번째 톱니바퀴 & 세 번째 톱니바퀴 & 네 번째 톱니바퀴
//            roll1(v, 1, direction*(-1));
//            roll1(v, 2, direction);
//            roll1(v, 3, direction * (-1));
//            if(v[0][2]!=v[1][6] && v[1][2]!=v[2][6]) { //첫 번째 톱니바퀴 & 두 번째 톱니바퀴 & 세 번째 톱니바퀴
//                roll1(v, 1, direction*(-1));
//                roll1(v, 2, direction);
//                if(v[0][2]!=v[1][6]) { //첫 번째 톱니바퀴 & 두 번째 톱니바퀴
//                    roll1(v, 1, direction * (-1));
//                }
//            }
//        }
    }

    else if(gear==1){ // 두 번째 톱니바퀴 돌림

        if(v[0][2]!=v[1][6] && v[1][2]!=v[2][6]) { //첫 번째 톱니바퀴 & 세 번째 톱니바퀴

            if(v[2][2]!=v[3][6]) {//세 번째 톱니바퀴 & 네 번째 톱니바퀴
                roll1(v, 3, direction);
            }
            roll1(v, 0, direction * (-1));
            roll1(v, 2, direction*(-1));
        }

        else if(v[0][2]!=v[1][6]){ //첫 번째만
            roll1(v, 0, direction * (-1));
        }

        else if(v[1][2]!=v[2][6]){ //세 번째

            if(v[2][2]!=v[3][6]) {//세 번째 톱니바퀴 & 네 번째 톱니바퀴
                roll1(v, 3, direction);
            }
            roll1(v, 2, direction*(-1));
        }
    }

    else if(gear==2){//세 번째 톱니바퀴

        if(v[1][2]!=v[2][6] && v[2][2]!=v[3][6]) { //두 번째 톱니바퀴 & 네 번째 톱니바퀴

            if(v[0][2]!=v[1][6]) {//첫 번째 톱니바퀴 & 두 번째 톱니바퀴
                roll1(v, 0, direction);
            }
            roll1(v, 1, direction * (-1));
            roll1(v, 3, direction*(-1));
        }

        //네 번째만
        else if(v[2][2]!=v[3][6]) {
            roll1(v, 3, direction * (-1));
        }


        else if(v[2][6]!=v[1][2]){ //세 번째 톱니바퀴

            if(v[0][2]!=v[1][6]) { //첫 번째 톱니바퀴 & 두 번째 톱니바퀴
                roll1(v, 0, direction);
            }
            roll1(v, 1, direction*(-1));
        }

    }
    else{ //네 번째 톱니바퀴

        if(v[3][6]!=v[2][2]){ //네 번째 톱니바퀴 & 세 번째 톱니바퀴
            if(v[2][6]!=v[1][2]) { //세 번째 톱니바퀴 & 두 번째 톱니바퀴
                if(v[1][6]!=v[0][2]) { //두 번째 톱니바퀴 & 첫 번째 톱니바퀴
                    roll1(v, 0, direction * (-1));
                }
                roll1(v, 1 , direction);
            }
            roll1(v, 2, direction*(-1));
        }
    }
}

int counting(deque<char>d1, deque<char>d2, deque<char>d3, deque<char>d4){
    int result=0;
    if(d1[0]=='1')
        result += 1;
    if(d2[0]=='1')
        result += 2;
    if(d3[0]=='1')
        result += 4;
    if(d4[0]=='1')
        result += 8;
    return result;
}

void roll(deque<char> v[], int gear, int direction){
    roll2(v, gear, direction); //연쇄작용
    roll1(v,gear,direction); //일단 입력된 톱니바퀴 돌림
}



int main(){
    int n;
    int answer;
    deque<char> arr[4];

    for(int i=0; i<4; i++){
        string num;
        cin>>num;
        for(int j=0; j<8; j++){
            arr[i].push_back(num[j]);
        }
    }

    cin>>n;

    for(int k=0; k<n; k++){
        int g, d;
        cin>>g>>d;
        roll(arr,g-1,d);
//        for(int i=0; i<4; i++){
//          for(int j=0; j<8; j++){
//                cout<<arr[i][j];
//            }
//            cout<<'\n';
//
//        }
//        cout<<'\n';
    }

    answer = counting(arr[0], arr[1], arr[2], arr[3]);
    cout<<answer;
}