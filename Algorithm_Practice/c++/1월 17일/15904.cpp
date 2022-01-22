#include <iostream>
#include <queue>

using namespace std;

bool find_UCPC(queue<char> &q){ 
    bool f1 = false, f2 = false, f3 = false, check = false;
    while(!q.empty()){
        if(q.front()=='U'){
            f1 = true;
            break;
        }
        q.pop();
    }

    if(f1){
        while(!q.empty()){
            if(q.front()=='C'){
                f2 = true;
                break;
            }
            q.pop();
        }
    }

    if(f2){
        while(!q.empty()){
            if(q.front()=='P'){
                f3 = true;
                break;
            }
            q.pop();
        }
    }

    if(f3){
        while(!q.empty()){
            if(q.front()=='C'){
                check = true;
                break;
            }
            q.pop();
        }
    }

    return check;
}

int main(){
    string str;
    bool answer;
    queue<char> q;
    getline(cin, str);

    for(int i=0; i<str.length(); i++){
        q.push(str[i]);
    }

    answer = find_UCPC(q);

    if(answer){
        cout<<"I love UCPC";
    }
    else {
        cout<<"I hate UCPC";
    }
}

//한 줄로 입력 받기 (string의 getline()이용 - getline(cin, str));
//그리디 - U찾은 다음, C찾고, 그 다음 P찾고, 그 다음 C찾아야함. 각 flag를 두고 조건문 이용
//순서대로 편리하게 탐색하기 위해 queue를 사용하였음.  