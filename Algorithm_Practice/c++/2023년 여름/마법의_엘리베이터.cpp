#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

//수학, 구현
//더하는 게 나은가, 빼는 게 나은가
//1~4: 빼는 게 나음
//6~9: 더하는 게 나음 - 앞의 자릿수에 1씩 더해져야함. - 숫자로 변환한다음 10^해당자릿수 더하고 그다음 다시 string으로 바꾸기
//5: 가장 key point - 앞의 자릿수에 따라 더하는 게 나을수도 있고, 빼는 게 나을수도 있다.
//  앞의 자릿수가 5이상이면 더하는 게 낫고, 앞의 자릿수가 5보다 작으면 내리는 게 낫다.
int solution(int storey) {
    
    int answer = 0;
    string numStr = to_string(storey);
    int lastIndex = numStr.length()-1;
    for(int i=lastIndex; i>=0; i--){
        //cout<<numStr<<'\n';
        int num = numStr[i]-'0';
        if(num==0){
            continue;
        }
        else if(0<num && num<=4){ //빼는 게 좋음
            answer += num;
            numStr[i]='0';
        }
        else if(6<=num && num<=9){ //더하는 게 좋음
            answer += 10-num;
            numStr[i]='0';
            numStr = to_string(stoi(numStr)+(int)pow(10,numStr.length()-i));
            
            lastIndex = numStr.length()-1;
            i=lastIndex;
        }
        else{ //5인 경우 - 빼는 게 좋을 수도, 더하는 게 좋을 수도 - 하나 더 높은 자릿수가 5이상인가
            if(i==0){ //가장 큰 자릿수인 경우
                answer += 5;
            }
            else{ //가장 큰 자릿수가 아닌 경우 - i-1번째 자리수가 5이상인가 - 이상이면 올리는 게 낫고, 미만이면 내리는 게 낫다.
                int num = numStr[i-1]-'0';
                if(num>=5){
                    answer += 5;
                    numStr[i]='0';
                    numStr = to_string(stoi(numStr)+(int)pow(10,numStr.length()-i));
                    //cout<<numStr<<'\n';
                    lastIndex = numStr.length()-1;
                    i=lastIndex;
                }
                else{
                    answer += 5;
                    numStr[i]='0';
                }
                
            }
        }
    
        
    }
    return answer;
}