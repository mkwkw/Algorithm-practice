//상-AC - 깔끔하게 정리 및 설명 쓰기 with 그림
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

//뒤집기 - 덱에서 push_front()
//맨 앞에 거 지우기 - pop_front()

//살짝 변형 - t 입력 받고 출력하기 번거로움 -> t입력 받지 않고 하나의 케이스씩 동작하도록

//출력하는 형태 만들기
string print_deq(deque<int> &dq, int front){   
    if(dq.empty()){
        return "[]";
    }

    string res = "[";
    while(!dq.empty()){

        if(front==0){ //올바른 순서
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

//str에서 숫자만 추출하기
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


string solution(){
    
    deque<int> dq;
    string cmd, str, ans; //명령어: ex. RDD, 정수 배열(string으로 입력 받음),정답
    int n; //정수 배열의 크기
    bool is_error=false; //error인 경우 true, 아니면 false

    cin>>cmd>>n>>str;

    dq = extract_num(str); //str에서 숫자를 추출하여 덱에 넣기        

    int front = 0; //덱의 맨 앞 원소 가리킴
    int back = dq.size()-1; //덱의 맨 뒤 원소 가리킴
    
    for(int k=0; k<cmd.length(); k++){
                        
        if(cmd[k]=='R'){ //명령어 R
            swap(front, back); 
        }
        else{ //명령어 D
            if(n==0){ //덱에 숫자가 없는데 D들어오면 에러
                is_error = true;
                break;
            }
            else if(dq.empty()){ //덱에 숫자가 없는데 D들어오면 에러
                is_error = true;
                break;
            }
            else{
                if(front == 0){ //정방향 상태
                    dq.pop_front();
                    back = dq.size()-1;
                }
                else{ //역방향 상태
                    dq.pop_back();
                    front = dq.size()-1;
                }      
            }
        }
    }

    if(!is_error){ //error가 아니라면
        ans = print_deq(dq, front);
        return ans;
    }
    else{ //error 상황이라면
        return "error\n";
    } 
}

int main(){
    
    string answer;

    answer = solution();
    
    cout<<answer;
}