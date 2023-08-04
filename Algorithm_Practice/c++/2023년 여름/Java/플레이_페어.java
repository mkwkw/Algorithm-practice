import java.util.*;
import java.io.*;

//문자열 - StringBuilder 이용 - charAt, setCharAt
//int -> char : (char)(i+'A') (대문자)
//메소드 안에 내부 클래스 선언
public class Main
{

    public static void main(String args[]) throws IOException
    {
        class Pos{
            private int row;
            private int col;

            public Pos(int row, int col){
                this.row = row;
                this.col = col;
            }
        }

        List<Character> boardInRow = new ArrayList<Character>();
        char[][] board = new char[5][5];
        boolean[] visited = new boolean[26]; //기본값 false
        Map<Character, Pos> pos = new HashMap<Character, Pos>();
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder msg = new StringBuilder(br.readLine());
        String key = br.readLine();

        //1단계 - 키로 암호화에 사용할 판 만들기
        for(int i=0; i<key.length(); i++){
            if(!visited[key.charAt(i)-'A']){
                boardInRow.add(key.charAt(i));
                visited[key.charAt(i)-'A'] = true;
            }
        }

        
        for(int i=0; i<26; i++){
            if(i!=9&&!visited[i]){
                boardInRow.add((char)(i+'A'));
            }
        }

        for(int i=0; i<25; i++){
            board[i/5][i%5] = boardInRow.get(i);
            pos.put(boardInRow.get(i), new Pos(i/5, i%5));
        }

        //2단계 메시지 쪼개기
        int idx = 0;
        int msgLength = msg.length();
        while(idx<msgLength){
            char ch1 = msg.charAt(idx);

            if(idx+1<msgLength){
                char ch2 = msg.charAt(idx+1);

                if(ch1==ch2){
                    if(ch1=='X'){
                        msg.insert(idx+1, 'Q');
                    }
                    else{
                        msg.insert(idx+1, 'X');
                    }
                    msgLength += 1;
                }
            }

            idx += 2;
        }

        if(msg.length()%2==1){
            msg.append('X');
        }

        //System.out.println(msg.toString());

        //3단계 암호화하기
        //해당 글자가 몇 행 몇 열인가
        for(int i=0; i<msg.length(); i+=2){
            //System.out.println(msg.toString());
            Character ch1 = msg.charAt(i);
            Character ch2 = msg.charAt(i+1);

            int ch1Row = pos.get(ch1).row;
            int ch1Col = pos.get(ch1).col;

            int ch2Row = pos.get(ch2).row;
            int ch2Col = pos.get(ch2).col;

            if(ch1Row==ch2Row){
                ch1Col += 1;
                ch2Col += 1;

                //System.out.println(ch1Col+" "+ch2Col);

                if(ch1Col==5){
                    ch1Col = 0;
                }
                if(ch2Col==5){
                    ch2Col = 0;
                }

                msg.setCharAt(i, board[ch1Row][ch1Col]);
                msg.setCharAt(i+1, board[ch2Row][ch2Col]);
            }
            else if(ch1Col==ch2Col){
                ch1Row += 1;
                ch2Row += 1;

                if(ch1Row==5){
                    ch1Row = 0;
                }
                if(ch2Row==5){
                    ch2Row = 0;
                }

                msg.setCharAt(i, board[ch1Row][ch1Col]);
                msg.setCharAt(i+1, board[ch2Row][ch2Col]);
            }
            else{
                int temp = ch2Col;
                ch2Col = ch1Col;
                ch1Col = temp;

                msg.setCharAt(i, board[ch1Row][ch1Col]);
                msg.setCharAt(i+1, board[ch2Row][ch2Col]);
            }

        }

        System.out.print(msg.toString());
        
    }
}