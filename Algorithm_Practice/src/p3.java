//백준 2580 
//백트래킹 
//참고: https://st-lab.tistory.com/119
import java.io.*;
public class p3 {
	private static int arr[][];	
	private static boolean arr1[];//가로 방문 여부
	private static boolean arr2[];//세로 방문 여부
	private static boolean arr3[];//3*3박스 방문 여부
	private static int answer;
	
	//같은 행, 같은 열, 3*3박스에 중복되는 수가 있는지 검사
	private static boolean func(int arr[][], int a, int b, int value) {
		
		//가로
		for(int i=0; i<9; i++) {
			if(arr[a][i] == value)
				return false;
		}
		
		//세로
		for(int i=0; i<9; i++) {
			if(arr[i][b]==value)
				return false;
		}
		
		//3*3박스
		for(int i=(b/3)*3; i<(b/3)*3+3; i++) {
			for(int k=(a/3)*3; k<(a/3)*3; k++) {
				if(arr[i][k] == value)
					return false;
			}
		}
		
		
		return true; //중복된 것이 없다.
	}
	
	//0자리에 알맞은 숫자 넣기
	private static void sudoku(int row, int col) {
		
		// 해당 행이 다 채워졌을 경우 다음 행의 첫 번째 열부터 시작
				if (col == 9) {
					sudoku(row + 1, 0);
					return;
				}
		 
				// 행과 열이 모두 채워졌을 경우 출력 후 종료
				if (row == 9) {
					StringBuilder sb = new StringBuilder();
					for (int i = 0; i < 9; i++) {
						for (int j = 0; j < 9; j++) {
							sb.append(arr[i][j]).append(" ");
						}
						sb.append("\n");
					}
					System.out.println(sb);
					// 출력 뒤 시스템을 종료한다.
					System.exit(0);
				}
		 
				// 만약 해당 위치가 0 이라면 1부터 9까지 중 가능한 수 탐색
				if (arr[row][col] == 0) {
					for (int i = 1; i <= 9; i++) {
						// i 값이 중복되지 않는지 검사
						if (func(arr, row, col, i)) { //중복되지 않으면
							arr[row][col] = i; //숫자 할당
							sudoku(row, col + 1); //다음 열로 넘어감
						}
					}
					
				}
		 
				sudoku(row, col + 1);
	}
	
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		arr = new int[9][9];
		arr1 = new boolean[9];
		arr2 = new boolean[9];
		arr3 = new boolean[9];
		
		//스도쿠 입력
 		for(int i=0; i<9; i++) {
			String n [] = br.readLine().split(" ");
			for(int j=0; j<9; j++) {
				arr[i][j] = Integer.parseInt(n[j]);
			}
		}
 		
 		sudoku(0,0);
 		
		br.close();
	}

}
