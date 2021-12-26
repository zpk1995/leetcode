#include <stdio.h>
#include <stdlib.h>
struct ListNode {
      int val;
      struct ListNode *next;
};

/*链表初始化*/

struct ListNode *ListNodeInit()
{
	struct ListNode *p,*q;
	struct ListNode *head = NULL;
	int i = 0;	
	int data = 0;
	head = (struct ListNode *)malloc(sizeof(struct ListNode));
	while(1)
	{
		printf("plese input data,date = -1 end\n");
		scanf("%d",&data);
		if(data == -1)
			break;
		p = (struct ListNode *)malloc(sizeof(struct ListNode));
		p->val = data;
		if(i++ == 0)
			head->next = p;	
		else
			q->next = p;
		
		q = p;		
	}
	return head;
}

/*链表长度*/

int ListLength(struct ListNode *head)
{
	struct ListNode *Node = head->next;
	int length = 0;
	if(NULL == head && NULL == head->next){
		printf("list is empty\n");
		return 0;
	}
	while(NULL != Node){
		length++;
		Node = Node->next;
	}
	printf("the length of list is %d\n",length);
	return length;
}

void ListNodePrintf(struct ListNode *head)
{
	struct ListNode *PrintNode = head->next;
	int i = 0;
	if(head == NULL && head->next == NULL){
		printf("list is empty\n");
		return;
	}
	while(NULL != PrintNode){
		printf("%d",PrintNode->val);
		if(NULL != PrintNode->next)
			printf("->");
		PrintNode = PrintNode->next;
	}

	printf("\n");
}

struct ListNode *reverseList(struct ListNode *head){
    struct ListNode *p = NULL;
    struct ListNode *q = NULL;
    struct ListNode * temp_q = NULL;
    if(head->next == NULL && head ==NULL)
        return head;
    p = head->next;
    q = p->next;
    p->next = NULL;
    while(q != NULL)
    {
        temp_q = q->next;
        q->next = p;
        p = q;
        q = temp_q;
    }
    head->next = p;
    return head;
}

int main(void)
{
	struct ListNode *List = NULL;
	List = ListNodeInit();
	ListLength(List);
	if(NULL == List){
		printf("Init List error\n");
		return -1;
	}
	ListNodePrintf(List);
	reverseList(List);
	ListNodePrintf(List);
		
	return 0;
}
