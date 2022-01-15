#include <iostream>
#include <stack>

using namespace std;

string mirror(string word){
    stack<char> words;
    string res="";
    for(int i=0; i<word.length(); i++){
        //cout<<"word[i]: "<<word[i]<<'\n';
        if(word[i]!='b' && word[i]!='d' && word[i]!='p' && word[i]!='q' && word[i]!='i' && word[i]!='o'&& word[i]!='v' && word[i]!='w' && word[i]!='x'){
            return "INVALID";
        }

        else{
            words.push(word[i]);
        }
    }

    while(!words.empty()){
        char alph = words.top();

        if(alph == 'b'){
            res += 'd';
        }

        else if(alph == 'd'){
            res += 'b';
        }

        else if(alph == 'p'){
            res += 'q';
        }

        else if(alph == 'q'){
            res += 'p';
        }

        else{
            res += alph;
        }

        words.pop();
    }

    return res;
}

int main(){
    while(true){
        string word, answer;
        cin>>word;
        
        if(word=="#"){
            break;
        }

        answer = mirror(word);
        cout<<answer<<'\n';
    }


}

//단순 구현 문제
//조건 빠뜨리지 않기!