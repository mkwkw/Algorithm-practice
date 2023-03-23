#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<vector<int>> board;
    vector<vector<int>> sameColLength;
    vector<vector<int>> sameRowLength;
    int n, l, answer = 0;

    cin>>n>>l;

    board.assign(n, vector<int>(n, 0));
    sameColLength.assign(n, vector<int>(n, 0));
    sameRowLength.assign(n, vector<int>(n, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
        }
    }

    
    for(int i=0; i<n; i++){
        bool flag = true, flag1 = true, flag2 = true;
        int prev1 = 0, next1 = 0, prev2 = 0, next2 = 0;
        
        prev1 = board[i][0];
        prev2 = board[0][i];

        for(int j=1; j<n; j++){
            
            next1 = board[i][j];
            next2 = board[j][i];
            cout<<"pos: "<<i<<' '<<j<<'\n';
            cout<<"prev1: "<<prev1<<" next1: "<<next1<<'\n';

            //�ϳ��� ��

            //������ ĭ ���� �� 2�̻��̸� ���� ��ġ �Ұ�
            if(abs(prev1-next1)>1){
                flag1 = false;
                break;
            }

            //���� ��ȭ�� ������ ��
            if(prev1 != next1){
                //flag = false;

                if(prev1<next1){ //���ʿ� L�� �̻��� ���̰� prev1�� ĭ�� �ִ°� 
                    int sameHeight = 0;
                    for(int k=j-1; k>=0; k--){
                        if(board[i][k]==prev1){
                            sameHeight++;
                        }
                        else{
                            break;
                        }

                        if(sameHeight==l){
                            break;
                        }
                    }

                    if(sameHeight!=l){
                        flag1 = false;
                        break;
                    }
                    cout<<"left l: "<<sameHeight<<'\n';
                }
                else{ //�����ʿ� L�� �̻��� ���̰� next1�� ĭ�� �ִ°�
                    int sameHeight = 1;
                    for(int k=j+1; k<n; k++){
                        if(board[i][k]==next1){
                            sameHeight++;
                        }
                        else{
                            break;
                        }

                        if(sameHeight==l){
                            break;
                        }
                    }

                    if(sameHeight!=l){
                        flag1 = false;
                        break;
                    }
                    cout<<"right l: "<<sameHeight<<'\n';

                }
            }

            

            //�ϳ��� ��
            if(abs(prev2-next2)>1){
                flag2 = false;
                break;
            }

            //���� ��ȭ�� ������ ��
            if(prev2 != next2){
                //flag = false;

                if(prev2<next2){ //���� L�� �̻��� ���̰� prev2�� ĭ�� �ִ°� 
                    int sameHeight = 0;
                    for(int k=j-1; k>=0; k--){
                        if(board[k][i]==prev2){
                            sameHeight++;
                        }
                        else{
                            break;
                        }

                        if(sameHeight==l){
                            break;
                        }
                    }

                    if(sameHeight!=l){
                        flag2 = false;
                        break;
                    }
                    cout<<"up l: "<<sameHeight<<'\n';
                }
                else{ //�Ʒ��ʿ� L�� �̻��� ���̰� next2�� ĭ�� �ִ°�
                    int sameHeight = 1;
                    for(int k=j+1; k<n; k++){
                        if(board[k][i]==next2){
                            sameHeight++;
                        }
                        else{
                            break;
                        }

                        if(sameHeight==l){
                            break;
                        }
                    }

                    if(sameHeight!=l){
                        flag = false;
                        break;
                    }
                    cout<<"down l: "<<sameHeight<<'\n';

                }
            }

            

            prev1 = board[i][j];
            prev2 = board[j][i];
        }

        if(flag1){
            answer++;
            cout<<"row: "<<i<<' '<<answer<<'\n';
        }

        if(flag2){
            answer++;
            cout<<"col: "<<i<<' '<<answer<<'\n';
        }
        //if(flag && flag1 && flag2){
        //    answer++;
        //}
        //else{
        //    if(flag1 && flag2){
        //        answer++;
        //    }
        //}

        //cout<<"ans: "<<answer<<'\n';
    }
    

    cout<<answer;

}