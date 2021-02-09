//2263
//Ʈ���� ��ȸ

import java.io.*;
public class p31 {
	
	public static int inorder[], postorder[], index[]; //inorder �Է� ��, postorder �Է� ��, �� ������ inorder�迭������ �ε��� �� ���� 
	
	//preorder���ϱ� ����-inorder���� �ε��� ��, �� �ε��� ��, postorder���� �ε��� ��, �� �ε��� ��
	public static void preorder(int inorderStart, int inorderEnd, int postorderStart, int postorderEnd) {
		
		//����
		if(inorderStart>inorderEnd || postorderStart>postorderEnd) {
			return;
		}
		
		//postorder�� ������ ���Ұ� �� (����)Ʈ���� root�̴�.
		int root = postorder[postorderEnd];
		System.out.print(root+" ");
		
		//���� subtree (inorder������ root��� ���� ����, postorder������ ó������ �߰�����)
		preorder(inorderStart, index[root]-1, postorderStart, postorderStart+(index[root]- inorderStart)-1 );
		//������ subtree (inorder������ root��� ���� ������, postorder������ �߰����� ������(root��� ����))
		preorder(index[root]+1, inorderEnd, postorderStart+(index[root]-inorderStart), postorderEnd-1);
	}
	

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		inorder = new int [n+1];
		postorder = new int [n+1];
		index = new int [n+1];
		
		//inorder �迭
		String brr[] = br.readLine().split(" ");
		for(int i=0; i<n; i++) {
			inorder[i] = Integer.parseInt(brr[i]);
		}
		//postorder �迭
		String brr1[] = br.readLine().split(" ");
		for(int i=0; i<n; i++) {
			postorder[i]= Integer.parseInt(brr1[i]);
		}
		
		//inorder �迭������ ������ "�ε��� ����"
		for(int i=0; i<n; i++) {
			index[inorder[i]] = i;
		}
		
		preorder(0, n-1, 0, n-1); //preorder���ϱ� 
	}

}
