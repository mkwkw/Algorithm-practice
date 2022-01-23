//상-AC - 이전 풀이 고쳐서 내 방식대로 풀어보기 - string 리턴, isdigit()쓰면 될 듯
#include <iostream>
#include <deque>
#include <string>

using namespace std;

//[ 또는 , 또는 ]가 나올 때까지 tmp에 숫자를 붙여서 result 벡터에 담는다. 
deque<int> refactoring(string str) {
    deque<int> result;
    string tmp; //숫자를 담을 임시 문자열
    for (int i = 0; i < str.size(); i++) {
        if (isdigit(str[i])) //숫자라면 문자열에 추가
            tmp += str[i];
        else if (!tmp.empty() && (str[i] == ',' || str[i] == ']')) { //문자열이 비어있지 않을 때, 쉼표 또는 닫는 괄호를 만나면 숫자로 바꿔주기
            result.push_back(stoi(tmp));
            tmp = ""; //문자열 초기화
        }
    }
    return result;
}

//아예 string으로 만들어서 리턴
string toStr(deque<int> dq, bool is_reversed) {
    if (dq.empty()) //덱이 비어있는 경우
        return "[]";

    string result = "[";
    while (!dq.empty()) {
        if (is_reversed) { //뒤집혔으면 뒤에서부터
            result += to_string(dq.back());
            dq.pop_back();
        } else { //올바른 순서면 앞에서부터
            result += to_string(dq.front());
            dq.pop_front();
        }
        result += ",";
    }
    result[result.size() - 1] = ']'; //마지막 쉼표를 닫는 괄호로 바꿔주기
    return result;
}

/**
 * 함수 R에서 실제로 배열을 뒤집을 필요가 없다는게 핵심
 * 비어있는 배열을 리턴하는 경우를 주의
 */
int main() {
    int t, n;
    string p, str;

    cin >> t;
    while (t--) {
        //입력
        bool is_reversed = false, is_error = false;
        cin >> p >> n >> str;

        //연산
        deque<int> dq = refactoring(str); //문자열에서 숫자를 구해서 덱에 넣기
        for (int i = 0; i < p.size(); i++) {
            if (p[i] == 'R') { //함수 R : is_reversed 변수만 반대로 바꿔주기
                is_reversed = !is_reversed;
                continue;
            }
            //함수 D
            if (dq.empty()) { //배열이 비어있으면 error
                is_error = true;
                break;
            }
            if (is_reversed) //뒤집힌 배열이면 맨 뒤 데이터 삭제
                dq.pop_back();
            else //올바른 순서의 배열이면 맨 앞 데이터 삭제
                dq.pop_front();
        }

        //출력
        if (is_error)
            cout << "error\n";
        else //숫자를 다시 문자열에 담아서 리턴하기
            cout << toStr(dq, is_reversed) << '\n';
    }
}

/*
#include <iostream>
#include <deque>
#include <queue>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

//뒤집기 - 덱에서 push_front()
//맨 앞에 거 지우기 - pop_front()
deque<string> deq;
vector<string> v;
queue<string> q;
void print_deq(int front){
    cout<<"[";
    if(deq.empty()){
        cout<<"]\n";
    }
    else if(front==0){

            for(int k=0; k<deq.size()-1; k++){
                cout<<deq[k]<<',';
                //deq.pop_front();
            }
            cout<<deq[deq.size()-1]<<"]"<<'\n';
        }
        else{
            for(int k=front; k>0; k--){
                cout<<deq[k]<<',';
                //deq.pop_front();
            }
            cout<<deq[0]<<"]"<<'\n';
    }


}


int main(){
    
    int t;

    cin>>t;
    
    for(int i=0; i<t; i++){
        
        string cmd; //ex. RDD
        int n;
        string arr; //정수 배열
        string num;
        cin>>cmd;
        cin>>n;
        cin>>arr;

        int prev = 0;
        int cur = 0;

        arr.erase(0,1);
        arr.erase(arr.length()-1, arr.length());

        //cout<<"arr: "<<arr;
        
        cur = arr.find(',');
        while(cur != string::npos){
            string substring = arr.substr(prev, cur - prev);
            deq.push_back(substring);
            prev= cur+1;
            cur = arr.find(',',prev);
        }
        deq.push_back(arr.substr(prev, cur-prev));

        int front = 0;
        int back = deq.size()-1;
    
        for(int k=0; k<cmd.length(); k++){
                        
            if(cmd[k]=='R'){
                //reversing();
                swap(front, back);
            }
            else{
                if(deq.empty() || n==0){
                    cout<<"error\n";
                    break;
                }
                //erasing();
                else{
                    if(front == 0){
                        deq.pop_front();
                        back = deq.size()-1;
                    }
                    else{
                        deq.pop_back();
                        front = deq.size()-1;
                    }
                }
                
            }
        }

        if(!(n==0)){print_deq(front);}

        deq.clear();

    }
}
*/