//��-����� �ܾ� - ù ��° �ܾ� ����, ���� �ܾ�� �Է¹ް� �Ǵ��ϴ� �Լ� ���� ������, solution �Լ� �ϳ��� �����ϱ�  
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> alphabet; //�� ���� ���ĺ� ������ �迭 (������ ���� Ƚ��)

int similar(int n, string str){
    vector<int> newAlphabet;
    int cnt=0;
    int answer=0;

    for(int t=0; t<26; t++){
        //char a = 'A'+t;
        newAlphabet.push_back(0);
    }

    for(int i=0; i<str.length(); i++){
        //alphabet[str[i]-65].second++;
        alphabet[str[i]-65]++;
        //for(int j=0; j<26; j++)
        //    cout<<alphabet[j].second<< ' ';
    }


    //ù��° �ܾ�� ���� �ܾ� �Է� �ް� �Ǵ�
    for(int i=0; i<n-1; i++){
        cnt=0;
        for(int t=0; t<26; t++){
            //newAlphabet[t].second=0; //�ʱ�ȭ
            newAlphabet[t]=0;
        }

        string s;
        cin>>s;
        for(int j=0; j<s.length(); j++){
            //newAlphabet[s[j]-65].second++;
            newAlphabet[s[j]-65]++;
        }

        for(int p=0; p<26; p++){
            //cnt += newAlphabet[p].second - alphabet[p].second;
            cnt += abs(newAlphabet[p]-alphabet[p]);
        }
        //cout<<"cnt: "<<cnt<<'\n';
        
        if(cnt==0 || cnt==1 || (cnt==2&&s.length()==str.length())){
            answer++;
        }
       
    }
    return answer;
}

int main(){
    int n;
    int answer;

    cin>>n;

    string str; //�� ����
    cin>>str;

    alphabet.assign(26,0);

    //for(int i=0; i<26; i++){
        //char a = 'A'+i;
        //alphabet.push_back(make_pair(a,0));
    //}

    answer = similar(n,str);
    cout<<answer;
   
}