#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//문자열 정렬
//접두어 판별
//["123", "8", "1234"]을 정렬하면
//["123", "1234", "8"]이다.
//즉, 길이순서대로 정렬되는 것이 아니다.
//따라서 앞의 문자열과 길이 및 substr을 비교하면 된다.
bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=1; i<phone_book.size(); i++){
        if(phone_book[i-1].length()<=phone_book[i].length() 
           && phone_book[i-1]==phone_book[i].substr(0,phone_book[i-1].length())
          ){
            answer = false;
            break;
        }
    }
    
    return answer;
}