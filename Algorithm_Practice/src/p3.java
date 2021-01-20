//���� 2580 
//��Ʈ��ŷ 
//����: https://st-lab.tistory.com/119
import java.io.*;
public class p3 {
	private static int arr[][];	
	private static boolean arr1[];//���� �湮 ����
	private static boolean arr2[];//���� �湮 ����
	private static boolean arr3[];//3*3�ڽ� �湮 ����
	private static int answer;
	
	//���� ��, ���� ��, 3*3�ڽ��� �ߺ��Ǵ� ���� �ִ��� �˻�
	private static boolean func(int arr[][], int a, int b, int value) {
		
		//����
		for(int i=0; i<9; i++) {
			if(arr[a][i] == value)
				return false;
		}
		
		//����
		for(int i=0; i<9; i++) {
			if(arr[i][b]==value)
				return false;
		}
		
		//3*3�ڽ�
		for(int i=(b/3)*3; i<(b/3)*3+3; i++) {
			for(int k=(a/3)*3; k<(a/3)*3; k++) {
				if(arr[i][k] == value)
					return false;
			}
		}
		
		
		return true; //�ߺ��� ���� ����.
	}
	
	//0�ڸ��� �˸��� ���� �ֱ�
	private static void sudoku(int row, int col) {
		
		// �ش� ���� �� ä������ ��� ���� ���� ù ��° ������ ����
				if (col == 9) {
					sudoku(row + 1, 0);
					return;
				}
		 
				// ��� ���� ��� ä������ ��� ��� �� ����
				if (row == 9) {
					StringBuilder sb = new StringBuilder();
					for (int i = 0; i < 9; i++) {
						for (int j = 0; j < 9; j++) {
							sb.append(arr[i][j]).append(" ");
						}
						sb.append("\n");
					}
					System.out.println(sb);
					// ��� �� �ý����� �����Ѵ�.
					System.exit(0);
				}
		 
				// ���� �ش� ��ġ�� 0 �̶�� 1���� 9���� �� ������ �� Ž��
				if (arr[row][col] == 0) {
					for (int i = 1; i <= 9; i++) {
						// i ���� �ߺ����� �ʴ��� �˻�
						if (func(arr, row, col, i)) { //�ߺ����� ������
							arr[row][col] = i; //���� �Ҵ�
							sudoku(row, col + 1); //���� ���� �Ѿ
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
		
		//������ �Է�
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
