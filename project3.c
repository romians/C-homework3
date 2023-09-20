#include <stdio.h>
#include <stdlib.h>
typedef struct teenode {
	int data;
	struct treenode* left, * right;
} treenode;

// 4.00*5.00
treenode n1 = { 4.00, NULL, NULL };
treenode n2 = { 5.00, NULL, NULL };
treenode n3 = { (float)'*', &n1, &n2 };

// 3.00 + (4.00*5.00)
treenode n4 = { 3.00, NULL, NULL };
treenode n5 = { (float)'+',&n4, &n3 };

// 2.00 + (3.00 + (4.00*5.00))
treenode n6 = { 2.00, NULL, NULL };
treenode n7 = { (float)'+', &n6,&n5 };

// 6.00/7.00
treenode n8 = { 6.00, NULL, NULL };
treenode n9 = { 7.00, NULL, NULL };
treenode n10 = { (float)'/',&n8, &n9 };

// (2.00 + (3.00 + (4.00*5.00))) - (6.00/7.00)
treenode n11 = { (float)'-', &n7, &n10 };

// (2.00 + (3.00 + (4.00*5.00))) - (6.00/7.00) + 9
treenode n12 = { 9.00, NULL, NULL };
treenode n13 = { (float)'+', &n11, &n12 };

treenode* root = &n13;

//수식 트리 계산 함수
float evaluate(treenode* root)
{
	if (root == NULL)	return 0;
	if (root->left == NULL && root->right == NULL)return root->data;
	else {
		float op1 = evaluate(root->left);
		float op2 = evaluate(root->right);

		switch (root->data) {
		case '+':	printf("%.2f + %.2f = %.2f\n", op1, op2, op1 + op2);  return op1 + op2;
		case '-':	printf("%.2f - %.2f = %.2f\n", op1, op2, op1 - op2);  return op1 - op2;
		case '*':	printf("%.2f * %.2f = %.2f\n", op1, op2, op1 * op2); return op1 * op2;
		case '/':	printf("%.2f / %.2f = %.2f\n", op1, op2, op1 / op2); return op1 / op2;
		}
	}
	return 0;
}

//노드 개수 계산 함수
int get_node_count(treenode* node) {
	int count = 0;
	if (node != NULL)
		count = 1 + get_node_count(node->left) +
		get_node_count(node->right);
	return count;

}

int main(void)
{
	printf("수식의 값은 %.2f입니다. \n", evaluate(root));
	printf("\n총 노드의 수는 %d개입니다. ", get_node_count(root));
	return 0;
}