import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
//본 시험에서는 solution 코드와 별도로 필요한 함수만 작성합니다.
public class Main {
    
    public static void counting(int [] ar, String word){
 
        //word마다 각 알파벳 개수 세기
        for(int i=0; i<word.length(); i++)
            ar[word.charAt(i)-'A']++;
        
    }
    public static int solution(int n, String [] words) {//단어의 총 개수와 단어의 배열이 인자로 주어집니다.  
        int answer=0;
        int [] freq_firstword = new int[26]; //기준 단어의 알파벳
        int [] freq_other = new int[26]; //비교할 단어의 알파벳
        int diff; //두 단어간의 알파벳 차이        
        int length = words[0].length(); //첫 번째 단어의 길이
 
        counting(freq_firstword, words[0]);
        
        for(int i=1; i<n; i++){
            diff=0;
            Arrays.fill(freq_other, 0);
            counting(freq_other, words[i]); //다른 단어 알파벳 개수 세기

            //두 단어간의 알파벳 차이 계산
            for(int k=0; k<26; k++)
                diff += Math.abs(freq_other[k]-freq_firstword[k]);
            
            //비슷한 단어의 조건을 코드로 표현
            if(diff == 0 || diff ==1 || diff ==2 &&(words[i].length() == length)) answer++;
        
        }        
        return answer;
    }
            
    // 입출력을 위한 메인 함수
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        String [] words = new String[n];
        int answer;
        
        for (int i=0; i<n; i++) words[i] = br.readLine();
        
        answer = solution(n, words);
        System.out.println(answer);
    }
}