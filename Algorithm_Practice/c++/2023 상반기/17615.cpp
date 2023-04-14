#include <iostream>
#include <vector>

using namespace std;

int main(){
    string s, s1;
    int n, rCnt = 0, bCnt = 0, rCnt1 = 0, rCnt2 = 0, bCnt1 = 0, bCnt2 = 0, answer = 1000000000;

    cin>>n>>s;

    //공을 모으는 과정을 그대로 구현
    //빨간색을 움직이려면 파란 공이 중간에 있어야함
    //파란색을 움직이려면 빨간 공이 중간에 있어야함
    
    //1. 빨간색 공을 오른쪽으로 모으는 과정
    bool bflag = false; //중간에 파란색이 있어야 옮김
    for(int i=n-1; i>=0; i--){
        if(s[i]=='B'){
            bflag = true;
        }

        if(bflag && s[i]=='R'){
            rCnt1++;
        }
    }

    //2. 빨간색 공을 왼쪽으로 모으는 과정
    bflag = false; //중간에 파란색이 있어야 옮김
    for(int i=0; i<n; i++){
        if(s[i]=='B'){
            bflag = true;
        }

        if(bflag && s[i]=='R'){
            rCnt2++;
        }
    }

    
    //3. 파란색 공을 오른쪽으로 모으는 과정
    bool rflag = false; //중간에 빨간색이 있어야 옮김
    for(int i=n-1; i>=0; i--){
        if(s[i]=='R'){
            rflag = true;
        }

        if(rflag && s[i]=='B'){
            bCnt1++;
        }
    }

    //4. 빨간색 공을 왼쪽으로 모으는 과정
    rflag = false; //중간에 파란색이 있어야 옮김
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

    //15점 - swap 이용
    // for(int i=0; i<n; i++){
    //     if(s[i]=='R'){
    //         rCnt++;
    //     }
    //     else{
    //         bCnt++;
    //     }
    // }

    // //R을 왼쪽으로 몰기
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

    // //R을 오른쪽으로 몰기
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

    // //R을 왼쪽으로 몰기
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

    // //R을 오른쪽으로 몰기
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