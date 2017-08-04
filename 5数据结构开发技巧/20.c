/****************************************
技巧11：从链表中删除节点（没很好的运行）
****************************************/
/*
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct student
{
  int num;
  struct student *next;
}LNode,*LinkList;
struct student *create(int n)
{
  int i;
  struct student *head,*p1,*p2;
  int a;
  head=NULL;
  printf ("the record:\n");
  for (i=n; i>0; --i)
    {
      p1=(struct student*)malloc(sizeof(struct student));
      scanf("%d",&a);
      p1->num=a;
      if (head=NULL)
	{
	  head=p1;
	  p2=p1;
	}
      else
	{
	  p2->next=p1;
	  p2=p1;
	}
    }
  p2->next=NULL;
  return head;
};
struct student *delnode(struct student *head,int i)
{
  int j=0;
  struct student *p,*r;
  p=head;
  while(p&&j<i-1)           //找到要删除的位置
    {
      p=p->next;
      ++j;
    }
  if(!p->next||j>i-1)
    exit(1);
  r=p->next;
  p->next=r->next;           //删除节点
  free(r);
};
main()
{
  int n,i;
  struct student *q;
  printf ("input the count of the nodes you want to creat:\n");
  scanf("%d",&n);
  q=create(n);
  i=2;
  delnode(q,i);
  printf ("the third record is deleted!\nthe result is:\n");
  while(q)
    {
      printf ("%d ",q->num);
      q=q->next;
    }
  return 0;
}
*/
/****************************************
技巧12：合并两个链表
****************************************/
/*
#include <stdio.h>
#include <malloc.h>
typedef struct student
{
  int num;
  struct student *next;
}LNode,*LinkList;
LinkList create(void)
{
  LinkList head;
  LNode *p1,*p2;
  char a;
  head=NULL;
  a=getchar();
  while(a!='\n')
    {
      p1=(LNode*)malloc(sizeof(LNode));
      p1->num=a;
      if(head==NULL)
	head=p1;
      else
	p2->next=p1;
      p2=p1;
      a=getchar();
    }
  p2->next=NULL;
  return head;
}
LinkList coalition(LinkList L1,LinkList L2)
{
  LNode *temp;
  if(L1==NULL)
    return L2;
  else
    {
      if (L2 !=NULL)
	{
	  for(temp=L1;temp->next != NULL;temp=temp->next);
	  temp->next=L2;
	}
    }
  return L1;
}
int main(int argc, char *argv[])
{
  LinkList L1,L2,L3;
  printf ("please input two linklist:\n");
  printf ("the first linklist:\n");
  L1=create();
  printf ("the second linklist:\n");
  L2=create();
  coalition(L1,L2);
  printf ("the resultant linklist is:\n");
  while(L1)
    {
      printf ("%c",L1->num);
      L1=L1->next;
    }
  return 0;
}
*/
/****************************************
技巧13：应用栈实现进制转换
****************************************/
/*
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct DataType
{
  DataType *base;
  DataType *top;
  int stacksize;
}SeqStack;
void Initial(SeqStack *s)
{
  //构造一个空栈
  s->base=(DataType *)malloc(stacksize *sizeof(DataType));
  if(!s->base)
    exit(-1);
  s->top=s->base;
  s->stacksize=stacksize;
}
//判栈空
int IsEmpty(SeqStack *s)
{
  return s->top==s->base;
}
//判栈满
int IsFull(SeqStack *s)
{
  return s->top - s->base==stacksize-1;
}
//进栈
void Push(SeqStack *S,DataType x)
{
  if (IsFull(S))
    {
      printf ("栈上溢\n"); //上溢，退出运行
      exit(1);
    }
  *S->top++ = x;    //栈顶指针加1后将x入栈
}
//出栈
DataType Pop(SeqStack *S)
{
  if (IsEmpty(S))
    {
      printf ("栈为空\n");  //下溢，退出运行
      exit(1);
    }
  return *--S->top; //栈顶元素返回后将栈顶指针减1
}
//取栈顶元素
DataType Top(SeqStack *S)
{
  if (IsEmpty(S))
    {
      printf ("栈为空\n");   //下溢，退出运行
      exit(1);
    }
  return *(S->top-1);
}
void conversion(int N,int B)
{          //假设N是非负的十进制整数，输出等值的B进制数
  int i;
  SeqStack *S;
  Initial(S);
  while(N)
    {      //从右向左产生B进制的各位数字，并将其进栈
      Push(S,N%B);     //将bi进栈0<=i<=j
      N=N/B;
    }
  while(!IsEmpty(S))
    {
      i=Pop(S);        //栈非空时退栈输出
      printf ("%d\n",i);
    }
}
void main()
{
  int n,d;
  printf ("Input the integer you want to transform:\n");
  scanf("%d",&n);
  printf ("Input the integer of the system:\n");
  scanf("%d",&d);
  printf ("result:\n");
  conversion(n,d);
}
*/
/****************************************
技巧14:创建循环队列FIFO
****************************************/
/*
#include <stdio.h>
#include <stdlib.h>
#define maxsize 50
#define TRUE 1
#define FAILE 0

typedef int datatype;
typedef struct {
	datatype data[maxsize];//为了判别空或满队，data[0]不用于存数据
	int front;
	int rear;
}sequeue;

void reset(sequeue *sq)
{
	sq->front = 0;
	sq->rear = 0;
}

 *当头尾指针相等时，队列为空
 *当"(rear+1)%maxsize == front"时，队列为满

int is_empty(sequeue *sq)//队列为空时返回1，不为空时返回0
{
	if(sq->front == sq->rear)
		return 1;
	else
		return 0;
}

int is_full(sequeue *sq)//队列为满时返回1，不为满时返回0
{
	if((sq->rear+1)%maxsize == sq->front)
		return 1;
	else
		return 0;
}

//获得循环队列的头节点，同时队列保持不变
datatype get_front(sequeue *sq)
{
	if(is_empty(sq)){
		printf("sequeue is NULL!\n");
		return 0;
	}
	else
		return(sq->data[(sq->front+1)%maxsize]);
}

//入队
datatype in_sequeue(sequeue *sq,datatype x) //将x插入到循环队列中
{
	if(is_full(sq)){
		printf("sequeue is full\n");
		return 1; //队列已满，返回1
	}
	else{
		sq->rear = (sq->rear+1)%maxsize;//队尾指针加1
		sq->data[sq->rear] = x;//将x插入到队尾
		return 0;//入队成功，函数返回0
	}
}

//出队
datatype out_sequeue(sequeue *sq) //函数返回队顶元素
{
	if(is_empty(sq)){
		printf("sequeue is null\n");
		return 0; //队列已空，返回NULL
	}
	else{
		sq->front = (sq->front+1)%maxsize;//队首指针加1
		return(sq->data[sq->front]);//出队成功，函数返回队首元素
	}
}

int main(int argc,char *argv[])
{
	int i,j,x;
	char c;
	sequeue *q;
	q = (sequeue *)malloc(sizeof(sequeue));
	while(TRUE)
	{
		printf("\n\t请选择\t");
		printf("\n\tA:建字符队列\t");
		printf("\n\tB:取队列节点\t");
		printf("\n\tC:入队\t");
		printf("\n\tD:出队\t");
		printf("\n\tE:结束\t\n");
		c = getchar();
		//fflush(stdin);
		setbuf(stdin, NULL);
		switch(c){
			case 'A':
			        reset(q);
				printf("\n循环队列初始化完毕!\n");
				break;
			case 'B':
				printf("取出的元素为:%d\n",get_front(q));
				break;
			case 'C':
				printf("\n请输入入队的数据:");
				scanf("%d",&x);
				setbuf(stdin, NULL);
				in_sequeue(q,x);
				printf("\n当前循环队列的数据为:");
				i = q->front;
				while(i!=q->rear){
					i = (i+1)%maxsize;
					printf("%5d",q->data[i]);
				}
				break;
			case 'D':
				printf("\n出队元素为:%d",out_sequeue(q));
				printf("\n当前循环队列的数据为:");
				i = q->front;
				while(i!=q->rear){
					i = (i+1)%maxsize;
					printf("%5d",q->data[i]);
				}
				break;
			case 'E':
				return 0;
		}
	}
}
*/
/****************************************
技巧15:创建链表队列FIFO
****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#define TRUE 1
#define FAILE 0

typedef int datatype;

typedef struct link_list{
	datatype data;
	struct link_list *next;
}link_list;

typedef struct {
	link_list *front;
	link_list *rear;
}link_queue;

//初始化一个链表队列
void reset_link_queue(link_queue *lq)
{
	lq->front = (link_list *)malloc(sizeof(link_list));//分配头结点空间
	lq->front->next = NULL;//头节点指针域置空
	lq->rear = lq->front;//尾指针指向头节点
}

//当头尾指针相等时，队列为空
int is_empty(link_queue *lq)
{
	if(lq->front == lq->rear)
		return 1;//队列为空时返回1
	else
		return 0;//不为空时返回0
}


//获得循环队列的头节点，同时队列保持不变
datatype get_front(link_queue *lq)
{
	if(is_empty(lq)){
		printf("link queue is NULL!\n");
		return 0;
	}
	else
		return(lq->front->next->data);
}

//入队
datatype in_link_queue(link_queue *lq,datatype x) //将x插入到队尾
{
		lq->rear->next = (link_list *)malloc(sizeof(link_list));//分配空间给新节点，并插到队尾
		lq->rear = lq->rear->next;//尾指针指向新插入节点
		lq->rear->data = x;//给新节点数据域赋值
		lq->rear->next = NULL;//新节点指针域赋值
		return 0;//入队成功，函数返回0
}

//出队
datatype out_link_queue(link_queue *lq) //函数返回队顶元素
{
	link_list *s;
	if(is_empty(lq)){
		printf("the link queue is empty!");//队空，函数返回0
		return 0;
	}
	s = lq->front;//头结点赋给s
	lq->front = s->next;//头结点指向原队头节点
	free(s);//释放原头结点
	return(lq->front->data);//出队成功，函数返回原队头节点的数据域
	
}

int main(int argc,char *argv[])
{
	int i,j,x;
	char c;
	link_list *s;
	link_queue *lq;
	lq = (link_queue *)malloc(sizeof(link_queue));
	while(TRUE)
	{
		printf("\n\t请选择\t");
		printf("\n\tA:建字符队列\t");
		printf("\n\tB:取队列节点\t");
		printf("\n\tC:入队\t");
		printf("\n\tD:出队\t");
		printf("\n\tE:结束\t\n");
//		initscr();
//		c = getch();
//		endwin();
		c = getchar();
		scanf("%*[^\n]%*c");
		switch(c){
			case 'A':
			        reset_link_queue(lq);
				printf("\n循环队列初始化完毕!\n");
				break;
			case 'B':
				printf("取出的元素为:%d\n",get_front(lq));
				break;
			case 'C':
				printf("\n请输入入队的数据:");
				scanf("%d",&x);
				setbuf(stdin, NULL);
				in_link_queue(lq,x);
				printf("\n当前链表队列的数据为:");
				s = lq->front->next;
				while(s!=NULL){
					printf("%5d",s->data);
					s = s->next;
				}
				break;
			case 'D':
				printf("\n出队元素为:%d",out_link_queue(lq));
				printf("\n当前循环队列的数据为:");
				s = lq->front->next;
				while(s!=NULL){
					printf("%5d",s->data);
					s = s->next;
				}
				break;
			case 'E':
				return 0;
			case '\n':
				printf("here is a huiche!");
				break;

		}
	}
}
