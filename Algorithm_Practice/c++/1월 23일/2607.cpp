//하-비슷한 단어 - 첫 번째 단어 저장, 비교할 단어들 입력받고 판단하는 함수 따로 나누기, solution 함수 하나로 정리하기  
#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> alphabet; //비교 기준 알파벳 저장할 배열 (문자의 등장 횟수)

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


    //첫번째 단어와 비교할 단어 입력 받고 판단
    for(int i=0; i<n-1; i++){
        cnt=0;
        for(int t=0; t<26; t++){
            //newAlphabet[t].second=0; //초기화
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

    string str; //비교 기준
    cin>>str;

    alphabet.assign(26,0);

    //for(int i=0; i<26; i++){
        //char a = 'A'+i;
        //alphabet.push_back(make_pair(a,0));
    //}

    answer = similar(n,str);
    cout<<answer;
   
}