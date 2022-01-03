#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data; // data ���� ����
	struct node* next; // ���� ��ġ�� ����Ű�� ������
}Node; // Node�� ����Ʈ�� ���� ���
typedef struct list
{
	Node* head; // head ��ġ�� ���� ó�� ��ġ�� ����Ų��
	Node* tail; // tail ��ġ�� ���� ������ ��ġ�� ����Ų��
	int count; // ����� ���� Ȯ���� ���� ����
}List; // List ���� ����� �پ������� ���� �⺻���� ����

void listinit(List* plist) // list �ʱ�ȭ�� ���� �Լ�
{
	plist->head=NULL;  
	plist->tail=NULL; 
	plist->count=0;
}// �ش� ����Ʈ�� �ʱ���� ����

void appendNode(List* plist,int data)// ��� �߰� �Լ�
{
	Node* newnode=(Node*)malloc(sizeof(Node)); // �����޸��Ҵ��� ���� ���ο� ��� ����
	newnode->data=data;// ������ �߰�
	newnode->next=NULL;

	if(plist->head==NULL)// list�� ����� ��尡 �ƹ��͵� ���ٸ�
	{
		plist->head=newnode; // �ش� ��尡 head�� �ǰ� �ȴ�
	}
	else // ��尡 ����Ǿ��� ����Ʈ���
	{
		plist->tail->next=newnode; // ���ο� ��带 ����Ʈ�� �������� �߰�
	}
	plist->tail=newnode; // tail�� ��ġ ����
	plist->count++;
}

Node* search(List* plist,int location)// ���ϴ� ��ġ�� Ž���ϴ� �Լ�
{
	Node* cur=plist->head; // Ž���� ���� cur ����� ������ġ�� head
	
	while(cur!=NULL) // ����Ʈ�� ������ Ž���ϱ� ���� �ݺ� ���ǹ�
	{
		if(cur->data==location) // ���ϴ� ��ġ�� ã�����
			return cur;

		cur=cur->next;// cur�� ��ġ�� ���������� ����
	}
	return NULL;
}
int deleteNode(List* plist,int location) // ���� �Լ�
{
	Node* cur=plist->head;
	Node* before=plist->head; // ����Ʈ�� ���������� �ΰ��� ��带 Ȱ���ؾ���
	
	if(plist->head==NULL)
		return 0; // ��尡 �Ѱ��� ���� ��� �����۾��� ���
	
	while(cur!=NULL)
	{
		if(cur->data==location)
			break;
		before=cur; // before�� �̵� ���� cur��ġ�� �����ϰ� ����
		cur=cur->next;
	}// Ž���� ������ ���� ����

	if(cur==plist->head) // �����Ϸ��� ��尡 head�� ���
	{
		plist->head=cur->next; // head�� ��ġ ����
	}
	else{
		before->next=cur->next;
	} // �⺻ ������ ���� ��ġ ���� 
	if(cur==plist->tail) // �����Ϸ��� ��尡 tail�� ���
		plist->tail=before; // tail�� ��ġ ����
	free(cur);
	plist->count--;
	return 1;
}
void insert(List* plist,int data,int location)
{
	Node* newnode= (Node*)malloc(sizeof(Node)); // ���ο� ��� ����
	Node* cur=search(plist,location); // ������ �̷���� ��ġ�� search�Լ��� ���� ȣ��
	newnode->data=data;
	
	newnode->next=cur->next;
	cur->next=newnode; // ��� ������ ���� �⺻ �˰���

	plist->count++;
}
void print(List* plist)
{
	Node* cur=plist->head;
	while(cur!=NULL)
	{
		printf("%d ",cur->data);
		cur=cur->next;
	}printf("\n");
}
int main(void)
{
	Node* cur;
	List list;
	listinit(&list);
	appendNode(&list,1);
	appendNode(&list,3);
	appendNode(&list,4);
	appendNode(&list,5);
	print(&list);
	printf("count of node:%d\n",list.count);
	cur=search(&list,3);
	printf("after search :%d\n",cur->data);

	insert(&list,2,1);
	print(&list);
	
	deleteNode(&list,1);
	print(&list);

	deleteNode(&list,4);
	print(&list);

	deleteNode(&list,5);
	print(&list);
	return 0;
}