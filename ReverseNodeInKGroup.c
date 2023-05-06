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
void AddNodeEnd(int y);
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
{int l;
  printf("enter number of reverse: ");
  scanf("%d",&l);
  return l;
}

int ReadNumberOfNode()
{int b;
  printf("enter the number of node: ");
  scanf("%d",&b);
  return b;
}

int ReadInput()
{int y;
  printf("enter number: ");
  scanf("%d",&y);
  return y;
}

void AddNodeEnd(int y)
{q=head;
  p=(struct ListNode*)malloc(sizeof(struct ListNode));
  p->data=y;
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
		p=head;int c=0;
		while(p!=NULL){
			c++;
			p=p->next;
		}
		return c;
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
		}else{int bol=0,d=k,f,h,count=0,c=0,w=k;q=head;p=head;
			while(bol!=1){f=d;count=0;int count1=0;q=head;
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
