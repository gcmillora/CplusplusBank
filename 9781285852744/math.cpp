#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 255
#include<ctype.h>
#include<iostream>

using namespace std;
struct Node{
	char input[MAX];
	struct Node *next;
};
struct list{
	int len;
	struct Node *head;
};
struct queue{
	int len;
	struct Node *head;
	struct Node *tail;
};
struct Node *createNode(){
	struct Node *temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->next=NULL;
	return temp;
};
struct list *createList(){
	struct list *temp;
	temp = (struct list *)malloc(sizeof(struct list));
	temp->head=NULL;
	temp->len=0;
};
struct queue *createQueue(){
	struct queue *temp;
	temp = (struct queue *)malloc(sizeof(struct queue));
	temp->head=NULL;
	temp->tail = NULL;
	temp->len =0;
};

int toString(char a[]){
	int ctr, sign, adjust,number;
	if(a[0]=='-') adjust =1;
	else adjust = 0;
	number = 0;
	for(ctr=adjust;a[ctr]!='\0';ctr++){
		number = number*10+a[ctr]-'0';
	}
	if(a[0]=='-'){
		number = number*-1;
	}
	return number;
}
int evalOperator(char inside,char outside){
	if((inside=='*'||inside=='/')&&(outside=='+'||outside=='-')){
		return 1;
	}
	else if((inside=='+'||inside=='-')&&(outside=='*'||outside=='/')){
		return 0;
	}
	else if((inside=='*'||inside=='/')&&(outside=='*'||outside=='/')){
		return 2;
	}
	else if((inside=='+'||inside=='-')&&(outside=='+'||outside=='-')){
		return 2;
	}
}


void push(struct list *stack, char val[]){
	struct Node *newnode;
	newnode = createNode();
	strcpy(newnode->input,val);
	
	if (stack->head == NULL) {	
		stack->head = newnode;	
		stack->len = 1;		
		
	}
	else{newnode->next = stack->head;
	stack->head = newnode;
	stack->len +=1;		
	}
}
int pop(struct list *stack){
	struct Node *tmpnode;
	int val;
	tmpnode = stack->head;
	val = toString(tmpnode->input);
	char op = tmpnode->input[0];
	char neg_check = tmpnode->input[1];
	stack->head = stack->head->next;
	stack->len -=1;
	free(tmpnode);

	if(isdigit(neg_check)) return val;
	if((op=='+'||op=='-'||op=='/'||op=='*'))return(op);
	return (val);
}

void enqueue(struct queue *queue, char *val)	{
	struct Node *newnode;
	if (queue == NULL) return (0);
	newnode = createNode();
	strcpy(newnode->input,val);
	if (queue->head == NULL) {	
		queue->head = newnode;	
		queue->tail = newnode;
		queue->len = 1;			
	}
	else{
	queue->tail->next = newnode;
	queue->tail = newnode;
	queue->len +=1;	
	}
	
}
int dequeue(struct queue *queue){
	struct Node *tmpnode;
	int val;
	tmpnode = queue->head;
	val = toString(tmpnode->input);
	queue->head = queue->head->next;
	queue->len -=1;	
	char op = tmpnode->input[0];
	char neg_check = tmpnode->input[1];
	if(queue->head==NULL)
		queue->tail=NULL;
	
	if(isdigit(neg_check)) return val;
	
	if((op=='+'||op=='-'||op=='/'||op=='*'))return(op);
	return (val);
}

void print_queue(struct queue *queue){
	struct Node *node;
	if(queue==NULL) return;
	else node = queue->head;
	if(node==NULL) {
		printf("\nQueue is empty.\n");	
		return;
	}
	printf("\nPrinting queue: ");
	do {
		printf("%s|", node->input);
		node = node->next;
	} while (node != NULL);
}
void print_stack(struct list *stack){
	struct Node *node;
	if(stack==NULL) return;
	else node = stack->head;
	if(node==NULL) {
		printf("\nStack is empty.\n");	
		return;
	}
	printf("\nPrinting stack: ");
	do {
		printf("%s", node->input);
		node = node->next;
	} while (node != NULL);
}

void evaluate(struct list *stack, struct queue *queue){
	while(queue->head!=NULL){
	if(stack->head==NULL){
		printf("\n\n\n------Stack is currently empty!------\n");
		char op[MAX];
		int cnv = dequeue(queue);
		sprintf(op,"%d",cnv);
		push(stack,op);
	}
	else if(queue->head->input[0]=='+'||queue->head->input[0]=='*'||queue->head->input[0]=='/'||queue->head->input[0]=='-'){
			char op[MAX];
			op[0]=dequeue(queue);	
			int num2 = pop(stack);
			int num1 = pop(stack);
			int result;
			switch(op[0]){
				case '+':
					result=num1+num2;
					break;
				case '-':
					result=num1-num2;
					break;
				case '*':
					result=num1*num2;
					break;
				case '/':
					result=num1/num2;
					break;
			}
			char res_stk[MAX];
			sprintf(res_stk,"%d",result);
			push(stack,res_stk);
			
		}
	else{
		char op[MAX];
		int cnv = dequeue(queue);
		sprintf(op,"%d",cnv);
		push(stack,op);
	}
	}
if(queue->head==NULL){
	printf("\n\n-------Queue is now empty!-------\n\n Evaluated Result: %d",pop(stack));
}
else printf("An error occured, queue is not empty!");
}

int main(){
	printf("--------FUNCTIONS SUCCESSFULLY INITIALIZED!--------\n\n");
	printf("Enter expression: ");
	char pstfx[MAX];
	int ctr=0,ctr2=0;
	gets(pstfx);
	struct list *stack;
	struct queue *queue;
	stack = createList();
	queue = createQueue();
	while(pstfx[ctr]!='\0'){
		char number[MAX];
		char op[MAX];
		ctr2=0;
		while(isdigit(pstfx[ctr])){
			number[ctr2]=pstfx[ctr];
			ctr2++;
			ctr++;
		}
		enqueue(queue,number);
		memset(&number[0], 0, sizeof(number));
		if(pstfx[ctr]=='*'||pstfx[ctr]=='/'||pstfx[ctr]=='+'||pstfx[ctr]=='-'){
			op[0] = pstfx[ctr];
			if(stack->head==NULL) {
				push(stack,op);
				printf("\n-------STACK IS EMPTY, PUTTING FIRST OPERATOR!-------\n");
			}else{
				int test = evalOperator(stack->head->input[0],op[0]);
				if(test==1){
					while(stack->head!=NULL){
							char op_enq[MAX];
							op_enq[0]=pop(stack);
							enqueue(queue,op_enq);
					}
					push(stack,op);
					}
				
				else if(test==2){
					char op_enq[MAX];
					op_enq[0]=pop(stack);
					cout<<op_enq[0]<<endl;
					enqueue(queue,op_enq);
					push(stack,op);
				}
				else{
					push(stack,op);
				}
			}
			ctr++;
		}
	}
	while(stack->len!=0){
		char last_op[MAX];
		last_op[0]=pop(stack);
		enqueue(queue,last_op);
	}
	print_queue(queue);
	evaluate(stack,queue);
return 0;
}



