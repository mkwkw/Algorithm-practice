#include <iostream>
#include <vector>

using namespace std;

int main(){
    string s, s1;
    int n, rCnt = 0, bCnt = 0, rCnt1 = 0, rCnt2 = 0, bCnt1 = 0, bCnt2 = 0, answer = 1000000000;

    cin>>n>>s;

    //���� ������ ������ �״�� ����
    //�������� �����̷��� �Ķ� ���� �߰��� �־����
    //�Ķ����� �����̷��� ���� ���� �߰��� �־����
    
    //1. ������ ���� ���������� ������ ����
    bool bflag = false; //�߰��� �Ķ����� �־�� �ű�
    for(int i=n-1; i>=0; i--){
        if(s[i]=='B'){
            bflag = true;
        }

        if(bflag && s[i]=='R'){
            rCnt1++;
        }
    }

    //2. ������ ���� �������� ������ ����
    bflag = false; //�߰��� �Ķ����� �־�� �ű�
    for(int i=0; i<n; i++){
        if(s[i]=='B'){
            bflag = true;
        }

        if(bflag && s[i]=='R'){
            rCnt2++;
        }
    }

    
    //3. �Ķ��� ���� ���������� ������ ����
    bool rflag = false; //�߰��� �������� �־�� �ű�
    for(int i=n-1; i>=0; i--){
        if(s[i]=='R'){
            rflag = true;
        }

        if(rflag && s[i]=='B'){
            bCnt1++;
        }
    }

    //4. ������ ���� �������� ������ ����
    rflag = false; //�߰��� �Ķ����� �־�� �ű�
    for(int i=0; i<n; i++){
        if(s[i]=='R'){
            rflag = true;
        }

        if(rflag && s[i]=='B'){
            bCnt2++;
        }
    }
    
    answer = min(answer, rCnt1);
    answer = min(answer, rCnt2);
    answer = min(answer, bCnt1);
    answer = min(answer, bCnt2);

    cout<<answer;

    //15�� - swap �̿�
    // for(int i=0; i<n; i++){
    //     if(s[i]=='R'){
    //         rCnt++;
    //     }
    //     else{
    //         bCnt++;
    //     }
    // }

    // //R�� �������� ����
    // s1 = s;
    // for(int i=0; i<n; i++){
    //     if(i==rCnt+1){
    //         break;
    //     }
    //     if(s1[i]=='B'){
    //         for(int j=i+1; j<n; j++){
    //             if(s1[j]=='R'){
                    
    //                 int temp = s1[j];
    //                 s1[j] = s1[i];
    //                 s1[i] = temp;
    //                 bCnt1++;
    //                 break;
                    
    //             }
    //         }
    //     }

    // }

    // //cout<<s1<<' '<<bCnt1<<'\n';

    // //R�� ���������� ����
    // s1 = s;
    // for(int i=n-1; i>=0; i--){
        
    //     if(i==n-1-rCnt){
    //         break;
    //     }
        
    //     if(s1[i]=='B'){
    //         for(int j=i-1; j>=0; j--){
    //             if(s1[j]=='R'){
    //                 swap(s1[i], s1[j]);
    //                 bCnt2++;
    //                 break;
    //             }
    //         }
    //     }
    // }

    // //R�� �������� ����
    // s1 = s;
    // for(int i=0; i<n; i++){
    //     if(i==rCnt+1){
    //         break;
    //     }
    //     if(s1[i]=='R'){
    //         for(int j=i+1; j<n; j++){
    //             if(s1[j]=='B'){
                    
    //                 int temp = s1[j];
    //                 s1[j] = s1[i];
    //                 s1[i] = temp;
    //                 rCnt1++;
    //                 break;
                    
    //             }
    //         }
    //     }

    // }

    // //cout<<s1<<' '<<bCnt1<<'\n';

    // //R�� ���������� ����
    // s1 = s;
    // for(int i=n-1; i>=0; i--){
        
    //     if(i==n-1-rCnt){
    //         break;
    //     }
        
    //     if(s1[i]=='R'){
    //         for(int j=i-1; j>=0; j--){
    //             if(s1[j]=='B'){
    //                 swap(s1[i], s1[j]);
    //                 rCnt2++;
    //                 break;
    //             }
    //         }
    //     }
    // }

    // //cout<<s1<<' '<<bCnt2<<'\n';
    
}