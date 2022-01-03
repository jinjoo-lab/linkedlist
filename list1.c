#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data; // data 저장 공간
	struct node* next; // 다음 위치를 가리키는 포인터
}Node; // Node는 리스트의 구성 요소
typedef struct list
{
	Node* head; // head 위치를 통해 처음 위치를 가리킨다
	Node* tail; // tail 위치를 통해 마지막 위치를 가리킨다
	int count; // 노드의 개수 확인을 위한 변수
}List; // List 선언 방법은 다양하지만 가장 기본적인 형태

void listinit(List* plist) // list 초기화를 위한 함수
{
	plist->head=NULL;  
	plist->tail=NULL; 
	plist->count=0;
}// 해당 리스트의 초기상태 설정

void appendNode(List* plist,int data)// 노드 추가 함수
{
	Node* newnode=(Node*)malloc(sizeof(Node)); // 동적메모리할당을 통해 새로운 노드 생성
	newnode->data=data;// 데이터 추가
	newnode->next=NULL;

	if(plist->head==NULL)// list에 저장된 노드가 아무것도 없다면
	{
		plist->head=newnode; // 해당 노드가 head가 되게 된다
	}
	else // 노드가 저장되어진 리스트라면
	{
		plist->tail->next=newnode; // 새로운 노드를 리스트의 마지막에 추가
	}
	plist->tail=newnode; // tail의 위치 조정
	plist->count++;
}

Node* search(List* plist,int location)// 원하는 위치를 탐색하는 함수
{
	Node* cur=plist->head; // 탐색을 위한 cur 노드의 시작위치는 head
	
	while(cur!=NULL) // 리스트의 끝까지 탐색하기 위한 반복 조건문
	{
		if(cur->data==location) // 원하는 위치를 찾은경우
			return cur;

		cur=cur->next;// cur의 위치를 순차적으로 조정
	}
	return NULL;
}
int deleteNode(List* plist,int location) // 삭제 함수
{
	Node* cur=plist->head;
	Node* before=plist->head; // 리스트의 삭제에서는 두개의 노드를 활용해야함
	
	if(plist->head==NULL)
		return 0; // 노드가 한개도 없는 경우 삭제작업은 취소
	
	while(cur!=NULL)
	{
		if(cur->data==location)
			break;
		before=cur; // before은 이동 전의 cur위치와 동일하게 변경
		cur=cur->next;
	}// 탐색을 삭제를 위해 변형

	if(cur==plist->head) // 삭제하려는 노드가 head일 경우
	{
		plist->head=cur->next; // head의 위치 조정
	}
	else{
		before->next=cur->next;
	} // 기본 삭제를 위한 위치 조정 
	if(cur==plist->tail) // 삭제하려는 노드가 tail일 경우
		plist->tail=before; // tail의 위치 조정
	free(cur);
	plist->count--;
	return 1;
}
void insert(List* plist,int data,int location)
{
	Node* newnode= (Node*)malloc(sizeof(Node)); // 새로운 노드 생성
	Node* cur=search(plist,location); // 삽입이 이루어질 위치를 search함수를 통해 호출
	newnode->data=data;
	
	newnode->next=cur->next;
	cur->next=newnode; // 노드 삽입을 위한 기본 알고리즘

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