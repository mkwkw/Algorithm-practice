#include <iostream>
#include <deque>
#include <queue>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//뒤집기 - 덱에서 push_front()
//맨 앞에 거 지우기 - pop_front()

//string print_deq(deque<int> &dq, int front){
string print_deq(deque<int> &dq, bool is_reversed){    
    if(dq.empty()){
        return "[]";
    }

    string res = "[";
    while(!dq.empty()){

        //if(front==0){ //올바른 순서
        if(!is_reversed){
            res += to_string(dq.front());
            dq.pop_front();
        }
        else{ //뒤집힌 순서
            
            res += to_string(dq.back());
            dq.pop_back();
        }

        res += ",";
    }

    res[res.length()-1] = ']';
    return res;
}

deque<int> extract_num(string str){
    deque<int> res;
    string tmp="";

    for(int i=0; i<str.length(); i++){
        if(isdigit(str[i])){
            tmp += str[i];
        }
        else if(tmp!="" && (str[i]==',' || str[i]==']')){
            res.push_back(stoi(tmp));
            tmp="";
        }
        //'['나오면 그냥 넘어가면 됨.
    }

    return res;
}


int main(){
    
    int t; //전체 테스트 개수

    cin>>t;
    
    for(int i=0; i<t; i++){
        deque<int> dq;
        string cmd, str, ans; //명령어: ex. RDD, 정수 배열(string으로 입력 받음),정답
        int n; //정수 배열의 크기
        bool is_reversed = false, is_error=false; //error인 경우 true, 아니면 false

        cin>>cmd>>n>>str;

        dq = extract_num(str); //str에서 숫자를 추출하여 덱에 넣기        
    
        for(int k=0; k<cmd.length(); k++){
                        
            if(cmd[k]=='R'){ //명령어 R
                is_reversed = !is_reversed; //bool 성질 이용
            }
            else{ //명령어 D
                if(n==0){
                    is_error = true;
                    break;
                }
                else if(dq.empty()){
                    is_error = true;
                    break;
                }
                else{

                    if (is_reversed){ //뒤집힌 배열이면 맨 뒤 데이터 삭제
                        dq.pop_back();
                    }
                    else{ //올바른 순서의 배열이면 맨 앞 데이터 삭제
                        dq.pop_front();
                    }

                }
                
            }
        }

        if(!is_error){
            //ans = print_deq(dq, front);
            ans = print_deq(dq, is_reversed);
            cout<<ans<<'\n';
        }
        else{
            cout<<"error\n";
        }        

    }
}