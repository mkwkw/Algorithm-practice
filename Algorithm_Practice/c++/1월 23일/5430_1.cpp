//��-AC - ����ϰ� ���� �� ���� ���� with �׸�
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

//������ - ������ push_front()
//�� �տ� �� ����� - pop_front()

//��¦ ���� - t �Է� �ް� ����ϱ� ���ŷο� -> t�Է� ���� �ʰ� �ϳ��� ���̽��� �����ϵ���

//����ϴ� ���� �����
string print_deq(deque<int> &dq, int front){   
    if(dq.empty()){
        return "[]";
    }

    string res = "[";
    while(!dq.empty()){

        if(front==0){ //�ùٸ� ����
            res += to_string(dq.front());
            dq.pop_front();
        }
        else{ //������ ����
            
            res += to_string(dq.back());
            dq.pop_back();
        }

        res += ",";
    }

    res[res.length()-1] = ']';
    return res;
}

//str���� ���ڸ� �����ϱ� (isdigit�Լ� �̿�)
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
        //'['������ �׳� �Ѿ�� ��.
    }

    return res;
}


string solution(string cmd, int n, string str){
    
    deque<int> dq;
    string ans; //����
    bool is_error=false; //error�� ��� true, �ƴϸ� false

    dq = extract_num(str); //str���� ���ڸ� �����Ͽ� ���� �ֱ�        

    int front = 0; //���� �� �� ���� ����Ŵ
    int back = dq.size()-1; //���� �� �� ���� ����Ŵ
    
    for(int k=0; k<cmd.length(); k++){
                        
        if(cmd[k]=='R'){ //��ɾ� R
            swap(front, back); 
        }
        else{ //��ɾ� D
            if(n==0){ //���� ���ڰ� ���µ� D������ ����
                is_error = true;
                break;
            }
            else if(dq.empty()){ //���� ���ڰ� ���µ� D������ ����
                is_error = true;
                break;
            }
            else{
                if(front == 0){ //������ ����
                    dq.pop_front();
                    back = dq.size()-1;
                }
                else{ //������ ����
                    dq.pop_back();
                    front = dq.size()-1;
                }      
            }
        }
    }

    if(!is_error){ //error�� �ƴ϶��
        ans = print_deq(dq, front);
        return ans;
    }
    else{ //error ��Ȳ�̶��
        return "error\n";
    } 
}

int main(){
    int n; //���� �迭�� ũ��
    string answer, cmd, str; //����, ��ɾ�, �־����� �迭
    cin>>cmd>>n>>str;
    answer = solution(cmd, n, str);
    
    cout<<answer;
}