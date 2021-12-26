#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    int n = phone_book.size();
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=0; i<n-1; i++){
        int m = phone_book[i].length();
    
        if(phone_book[i]==phone_book[i+1].substr(0,m)){
            answer=false;
            return answer;
        }
        
    }
   
    return answer;
}

/*1. 중복이 없다. && 정렬을 해서 풀어야될 것 같다. -> set을 이용하면 되려나?
하지만 set은 인덱스로 순회를 하지 못한다. 풀이의 감이 안잡힌다.
2. 3중 for문 정확성은 통과지만 역시나 효율성 마지막 케이스 2개 시간초과로 실패
검색
2-1. 마지막 for문에서 접두어에 해당하는 것을 인덱스로 하나하나 비교했는데
substr메소드로 하는 것이 더 좋아보임. -> 바꿈. 그래도 시간초과
2-2. string을 sort로 정렬하면 사전순으로 정렬된다는 것을 깨닫게 됨. 원래 알고 있었으나 숫자라서 당연히 숫자 크기 순으로 정렬된다고 생각했던 것 같음.
예를 들어, ["119", "97674223", "1195524421"]을 sort하면
119 1195524421 97674223  이렇게 정렬됨.
즉, i번째 원소와 i+1번째 원소만 비교하면 되는 것임.
결론: for문 하나로 끝났다. substr과 sort의 특성을 다시 깨달음.
*/