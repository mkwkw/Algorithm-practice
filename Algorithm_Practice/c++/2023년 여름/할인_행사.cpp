#include <string>
#include <vector>
#include <map>

using namespace std;

//map 사용 - key: want에 있는 menu 이름, value: want에 있는 menu 개수
//discount배열에서 각 인덱스에서 뒤에 10개/끝까지 돌면서 map에 있는 메뉴가 있다면 map의 value--
//순회를 마치고 나서 만약, map의 value가 1이상인 것이 있다면 할인받지 못한 메뉴가 있다는 뜻
//따라서, map의 value가 모두 0이하인 경우만 answer에 해당하는 경우이다.
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> wantAndNumber, temp;
    
    for(int i=0; i<want.size(); i++){
        wantAndNumber[want[i]] = number[i];
    }
    
    for(int i=0; i<discount.size(); i++){
        temp = wantAndNumber;
        bool flag = true; //temp의 값이 모두 0이하인 경우 true, 아니면 false
        if(i+9<discount.size()){ //i부터 10개 품목 순회
            for(int j=0; j<10; j++){
                if(temp.find(discount[i+j])!=temp.end()){
                    temp[discount[i+j]]--;
                }
            }

        }
        else{ //i부터 뒤에 남은 품목 순회
            for(int j=i; j<discount.size(); j++){
                if(temp.find(discount[j])!=temp.end()){
                    temp[discount[j]]--;
                }
            }
            
        }
        for(auto m : temp){
            if(m.second>0){
                flag = false;
                break;
            }
        }
        
        if(flag){
            answer++;
        }
    }
    return answer;
}