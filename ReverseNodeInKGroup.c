#include<stdio.h>
#include<stdlib.h>
struct ListNode{
	int data;
	struct ListNode *next;
};
struct ListNode *head=NULL,*p,*q,*r;

int ReadNumberOfNode();
int ReadInput();
int ReadNumberOfrevers();
void AddNodeEnd(int value);
int length(struct ListNode *head);
struct ListNode *reverseKGroup(int k,struct ListNode *head);
void display(struct ListNode *head);

int main(){
	int nbrNode,input,s;
	nbrNode=ReadNumberOfNode();
	for(int i=0;i<nbrNode;i++){
		input=ReadInput();
		AddNodeEnd(input);
	}
	s=ReadNumberOfrevers();
    display(reverseKGroup(s,head));
}

int ReadNumberOfrevers()
{int number1;
  printf("enter number of reverse: ");
  scanf("%d",&number1);
  return number1;
}

int ReadNumberOfNode()
{int number2;
  printf("enter the number of node: ");
  scanf("%d",&number2);
  return number2;
}

int ReadInput()
{int number3;
  printf("enter number: ");
  scanf("%d",&number3);
  return number3;
}

void AddNodeEnd(int value)
{q=head;
  p=(struct ListNode*)malloc(sizeof(struct ListNode));
  p->data=value;
  if(head==NULL)
  {
    p->next=NULL;
    head=p;
  }else
  {
    while(q->next!=NULL){
    	q=q->next;
	}
	q->next=p;
	p->next=NULL;
  }
}


int length(struct ListNode *head){
	if(head==NULL){
             printf("The list is empty");
	     return -1;                 
	}else{
             p=head;int count=0;
	     while(p!=NULL){
	     count++;
			p=p->next;
		}
		return count;
	}
}

void display(struct ListNode *head){
	p=head;
	while(p!=NULL){
		printf("%d\n",p->data);
		p=p->next;
	}
}

struct ListNode *reverseKGroup(int k,struct ListNode *head){
	if(head==NULL){
		printf("the list is empty");
		return NULL;
	}else{
		if(k==1){
			return head;
		}else{
			int bol=0,d=k,f,h,count=0,c=0,w=k;
			p=head;
			while(bol!=1){
			    f=d;count=0;q=head;
			    while(count!=k/2){q=head;
			    	for(int i=1;i<f;i++){
					q=q->next;
				    }
				    h=p->data;
				    p->data=q->data;
				    q->data=h;
				    p=p->next;
				    f=f-1;
				    count++;
				}
				if(length(head)-w<k){
					bol=1;
				}p=head;
				for(int i=1;i<=d;i++){
					p=p->next;
				}d+=k;w+=k;
			}
			return head;
		}
	}
}
