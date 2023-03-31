#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int answer = 0;
    vector<pair<char, int>> card(5);
    vector<int> color; //R, G, B, Y ī�� ����
    vector<int> cnt; //0 ���� 1~9 ī�� ���� 

    color.assign(4, 0);
    cnt.assign(10, 0);

    for(int i=0; i<5; i++){
        cin>>card[i].first>>card[i].second;
        switch(card[i].first){
            case 'R':
                color[0]++;
                break;
            case 'G':
                color[1]++;
                break;
            case 'B':
                color[2]++;
                break;
            case 'Y':
                color[3]++;
                break;
        }
        switch(card[i].second){
            case 1:
                cnt[1]++;
                break;
            case 2:
                cnt[2]++;
                break;
            case 3:
                cnt[3]++;
                break;
            case 4:
                cnt[4]++;
                break;
            case 5:
                cnt[5]++;
                break;
            case 6:
                cnt[6]++;
                break;
            case 7:
                cnt[7]++;
                break;
            case 8:
                cnt[8]++;
                break;
            case 9:
                cnt[9]++;
                break;
        }
    }
    
    //����
    sort(card.begin(), card.end());

    // for(int i=0; i<4; i++){
    //     cout<<color[i]<<' ';
    // }
    // cout<<'\n';
    // for(int i=1; i<10; i++){
    //     cout<<cnt[i]<<' ';
    // }

    //ù ��° ��Ģ
    bool flag1 = true;
    int temp = 0;
    for(int i=0; i<4; i++){
        if(card[i].first!=card[i+1].first || card[i].second+1 != card[i+1].second){
            flag1 = false;
            break;
        }
    }

    if(flag1){
        answer = max(answer, 900 + card[4].second);
    }

    //�� ��° ��Ģ
    for(int i=1; i<10; i++){
        if(cnt[i]==4){
            answer = max(answer, 800+i);
            break;
        }
    }

    //�� ��° ��Ģ
    int two1 = 0; //2���� ī�� ����
    int two2 = 0;
    int three = 0; //3���� ī�� ����
    for(int i=1; i<10; i++){
        if(cnt[i]==2){
            if(two1==0){
                two1 = i;
            }
            else{
                two2 = i;
            }
        }
        else if(cnt[i]==3){
            three = i;
        }
    }

    //�ϰ� ��° ��Ģ
    if(two1>0 && two2>0){
        answer = max(answer, two2*10+two1+300);
    }

    if(three>0){
        //���� ��° ��Ģ
        answer = max(answer, three+400);
        
        if(two1>0){
            answer = max(answer, three*10+two1+700);
        }
    }

    if(two1>0){
        answer = max(answer, two1+200);
    }
    
    //�� ��° ��Ģ
    for(int i=0; i<4; i++){
        if(color[i]==5){
            for(int i=9; i>=1; i--){
                if(cnt[i]>0){
                    answer = max(answer, i+600);
                    break;
                }
            }
            break;
        }
    }

    //�ټ� ��° ��Ģ
    for(int i=0; i<=5; i++){
        if(cnt[i]==1 && cnt[i+1]==1 && cnt[i+2]==1 && cnt[i+3]==1 && cnt[i+4]==1){
            answer = max(answer, 500+i+4);
            break;
        }
    }

    //��ȩ ��° ��Ģ
    if(answer==0){
        for(int i=9; i>=1; i--){
            if(cnt[i]>0){
                answer = max(answer, i+100);
                break;
            }
        }
    }    

    cout<<answer;

}