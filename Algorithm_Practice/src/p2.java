//���� 2580
//������
//��Ʈ��ŷ
//3 �̿� 3�� ������� �� �� �� ������
//���� ���� 3*3�ڽ� ��� visit���� ���� ���� ã��

import java.io.*;

public class p2 {

	private static int arr[][];	
	private static boolean arr1[];//���� �湮 ����
	private static boolean arr2[];//���� �湮 ����
	private static boolean arr3[];//3*3�ڽ� �湮 ����
	private static int answer;
	

	private static int func(int arr[][], int a, int b) {
		for(int i=0; i<9; i++) {
			arr1[i] = false;
			arr2[i] = false;
			arr3[i] = false;
		}
		
		//����
		for(int i=0; i<9; i++) {
			for(int j=1; j<=9; j++) {
				if(arr[a][i]==j )
					arr1[j-1]=true;
				else
					continue;
			}
		}
		
		//����
		for(int i=0; i<9; i++) {
			for(int j=1; j<=9; j++) {
				if(arr[i][b]==j)
					arr2[j-1]=true;
				else
					continue;
			}
		}
		
		//3*3�ڽ�
		for(int i=(b/3)*3; i<(b/3)*3+3; i++) {
			for(int k=(a/3)*3; k<(a/3)*3; k++) {
				for(int j=1; j<=9; j++) {
					if(arr[i][k]==j)
						arr3[j-1]=true;
					else
						continue;
				}
			}
		}
		
		for(int i=0; i<9; i++) {
			/*if(arr1[i]==false)
				System.out.print("���� false "+(i+1)+" ");
			if(arr2[i]==false)
				System.out.print("���� false "+(i+1)+" ");
			if(arr3[i]==false)
				System.out.print("3*3 false "+(i+1));
			System.out.println();*/
			
			if(arr1[i]==false && arr2[i]==false && arr3[i]==false) {
				answer = i+1;
				arr1[i]=true;
				arr2[i]=true;
				arr3[i]=true;
			}
		}
		return answer;
	}
	
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		arr = new int[9][9];
		arr1 = new boolean[9];
		arr2 = new boolean[9];
		arr3 = new boolean[9];
		
		
 		for(int i=0; i<9; i++) {
			String n [] = br.readLine().split(" ");
			for(int j=0; j<9; j++) {
				arr[i][j] = Integer.parseInt(n[j]);
			}
		}
	
 		for(int i=0; i<9; i++) {
 			for(int j=0; j<9; j++) {
 				if(arr[i][j]==0)
 					arr[i][j]=func(arr,i,j);
 			}
 		}
		
		for(int i=0; i<9; i++) {
			for(int j=0; j<9; j++) {
				System.out.print(arr[i][j]+" ");
			}
			System.out.println();
		}
		br.close();
	}

}
