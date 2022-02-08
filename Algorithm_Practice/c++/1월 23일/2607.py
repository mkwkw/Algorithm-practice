import sys
#본 시험에서는 solution 코드와 별도로 필요한 함수만 작성합니다.

#word마다 각 알파벳 개수 세기 (하나의 char을 인자로 받고 아스키코드로 변환하는 ord함수를 이용)
def counting(ar, word) :
    for w in word : 
        i=ord(w) - ord('A')
        ar[i] += 1
 
def solution(n, words): #단어의 총 개수와 단어의 배열이 인자로 주어집니다.  
#들여쓰기에 주의하면서 필요한 코드를 작성하세요
    answer =0
    diff =0 #두 단어간의 알파벳 차이     
    freq_firstword=[0] *26 
    length = len(words[0]) #첫 번째 단어 길이
 
    counting(freq_firstword, words[0]) #첫 번째 단어 알파벳 개수 세기
   
    for i in range(1,n) :
        diff =0
        freq_other=[0] * 26        
        counting(freq_other, words[i]) #다른 단어 알파벳 개수 세기
    
        #두 단어간의 알파벳 차이 계산
        for freq1, freq2 in zip(freq_other, freq_firstword) :
           diff += abs(freq1-freq2)            
        
        #비슷한 단어의 조건을 코드로 표현
        if (diff==0 or diff ==1 or (diff==2  and (len(words[i]) == length))) :  answer +=1
 
    return answer
 
if __name__ == "__main__":
    input = sys.stdin.readline
    n = int(input())
    words = [input().rstrip() for _ in range(n)]
    answer = solution(n, words)
    print(answer)