import java.util.*;
import java.io.*;


public class p16173{

    static boolean verify(int n, int r, int c){
        if(r<0 || c<0 || r>=n || c>=n){
            return false;
        }
        return true;
    }
    
    static class Pos{
        private int r;
        private int c;

        public Pos(int r, int c){
            this.r = r;
            this.c = c;
        }
    }
    
    static int[] dr = {0, 1};
    static int[] dc = {1, 0};
    public static void main(String[] args) throws IOException{

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        int[][] board = new int[n][n];
        boolean[][] visited = new boolean[n][n];

        for(int i=0; i<n; i++){
            String[] num = br.readLine().split(" ");
            
            for(int j=0; j<n; j++){
                board[i][j] = Integer.parseInt(num[j]);
            }
        }

        //Queue<Pos> pos = new LinkedList<Pos>();
        Queue<int[]> pos = new LinkedList<>();
        visited[0][0] = true;
        for(int i=0; i<2; i++){
            int nextR = dr[i]*board[0][0];
            int nextC = dc[i]*board[0][0];

            if(verify(n, nextR, nextC)){
                //pos.offer(new Pos(nextR, nextC));
                pos.offer(new int[]{nextR, nextC});
            }   
        }
        
        while(!pos.isEmpty()){
            
            if(pos.peek()[0]==n-1 && pos.peek()[1]==n-1){
                System.out.print("HaruHaru");
                return;
            }

            for(int i=0; i<2; i++){
                int r = pos.peek()[0];
                int c = pos.peek()[1];
                int nextR = r+dr[i]*board[r][c];
                int nextC = c+dc[i]*board[r][c];

                if(verify(n, nextR, nextC) && !visited[nextR][nextC]){
                    pos.offer(new int[]{nextR, nextC});
                }   
            }

            pos.poll();
        }

        System.out.print("Hing");
    }
}