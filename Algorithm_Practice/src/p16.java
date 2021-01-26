//���� 2343
//��Ÿ����
import java.io.*;
public class p16 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		//�Է�
		String arr[] = br.readLine().split(" ");
		int n = Integer.parseInt(arr[0]);
		int m = Integer.parseInt(arr[1]);
		
		String arr1[] = br.readLine().split(" ");
		int size[] = new int [n];
		
		int sum = 0; //�հ�
		int max = 0; //���� ū ��
		for(int i=0; i<n; i++) {
			size[i] = Integer.parseInt(arr1[i]);
			if(max<size[i])
				max = size[i];
			sum += size[i];
		}
		
		
		int left = max; 
		int right = sum;
		int mid = 0;
		
		while(left<=right) {
			int bcount = 0; //��緹�� ����
			int bsize = 0; //�ϳ��� ��緹�� ũ��
			
			mid = (left+right)/2;
			
			for(int i=0; i<n; i++) {
				if(bsize + size[i] > mid) { //ũ�Ⱑ ������ ��緹�� ũ�⸦ ������ ��緹�� ������ �ϳ� ������Ű�� ��緹�� ũ��� 0���� ����
					bsize = 0;
					bcount++;
				}
				bsize += size[i]; //ũ�Ⱑ ������ ��緹�� ũ�⸦ �� ������ ��緹�� ũ�⿡ �߰�
				
			}
			
			if(bsize != 0) { 
				
				bcount++;
			}
			
			if(bcount <= m ) //��緹���� ������ m������ ���
				right = mid-1; //ũ�Ⱑ �۾����� �Ѵ�.
			else
				left = mid+1; //ũ�Ⱑ Ŀ���� �Ѵ�.
		}
		
		System.out.println(left);
		

	}

}
