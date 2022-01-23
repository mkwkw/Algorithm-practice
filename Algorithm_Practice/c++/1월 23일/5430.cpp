//��-AC - ���� Ǯ�� ���ļ� �� ��Ĵ�� Ǯ��� - string ����, isdigit()���� �� ��
#include <iostream>
#include <deque>
#include <string>

using namespace std;

//[ �Ǵ� , �Ǵ� ]�� ���� ������ tmp�� ���ڸ� �ٿ��� result ���Ϳ� ��´�. 
deque<int> refactoring(string str) {
    deque<int> result;
    string tmp; //���ڸ� ���� �ӽ� ���ڿ�
    for (int i = 0; i < str.size(); i++) {
        if (isdigit(str[i])) //���ڶ�� ���ڿ��� �߰�
            tmp += str[i];
        else if (!tmp.empty() && (str[i] == ',' || str[i] == ']')) { //���ڿ��� ������� ���� ��, ��ǥ �Ǵ� �ݴ� ��ȣ�� ������ ���ڷ� �ٲ��ֱ�
            result.push_back(stoi(tmp));
            tmp = ""; //���ڿ� �ʱ�ȭ
        }
    }
    return result;
}

//�ƿ� string���� ���� ����
string toStr(deque<int> dq, bool is_reversed) {
    if (dq.empty()) //���� ����ִ� ���
        return "[]";

    string result = "[";
    while (!dq.empty()) {
        if (is_reversed) { //���������� �ڿ�������
            result += to_string(dq.back());
            dq.pop_back();
        } else { //�ùٸ� ������ �տ�������
            result += to_string(dq.front());
            dq.pop_front();
        }
        result += ",";
    }
    result[result.size() - 1] = ']'; //������ ��ǥ�� �ݴ� ��ȣ�� �ٲ��ֱ�
    return result;
}

/**
 * �Լ� R���� ������ �迭�� ������ �ʿ䰡 ���ٴ°� �ٽ�
 * ����ִ� �迭�� �����ϴ� ��츦 ����
 */
int main() {
    int t, n;
    string p, str;

    cin >> t;
    while (t--) {
        //�Է�
        bool is_reversed = false, is_error = false;
        cin >> p >> n >> str;

        //����
        deque<int> dq = refactoring(str); //���ڿ����� ���ڸ� ���ؼ� ���� �ֱ�
        for (int i = 0; i < p.size(); i++) {
            if (p[i] == 'R') { //�Լ� R : is_reversed ������ �ݴ�� �ٲ��ֱ�
                is_reversed = !is_reversed;
                continue;
            }
            //�Լ� D
            if (dq.empty()) { //�迭�� ��������� error
                is_error = true;
                break;
            }
            if (is_reversed) //������ �迭�̸� �� �� ������ ����
                dq.pop_back();
            else //�ùٸ� ������ �迭�̸� �� �� ������ ����
                dq.pop_front();
        }

        //���
        if (is_error)
            cout << "error\n";
        else //���ڸ� �ٽ� ���ڿ��� ��Ƽ� �����ϱ�
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

//������ - ������ push_front()
//�� �տ� �� ����� - pop_front()
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
        string arr; //���� �迭
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