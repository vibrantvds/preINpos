#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include<math.h>


struct node* verIn(char e[]);
int precedence(char);
int verpaba(char *);
void Inpo(char k[]);
void loading();
void PIP();
void CompressS(char*);
void Intro();
void Exit();
void Valid();
int identifyPIP(char*);
void check(char*);
struct node;
void Initialise(struct node**);
int pushLeaf (char, int);
int pushParentPre (char, int);
int pushParentPost (char, int);
int pop(int);
void check(char*);
int calpha(char);
int cnum(char);
int coper(char);
struct node* verPre(char*);
struct node* verPost(char*);
struct node* verIn(char *);
void PreMenu(int);
void PostMenu(int);
void InMenu(int);
void postorder(struct node*);
void inorder(struct node*);
void preorder(struct node*);


char e[100], ex[100];
int top=1, menu;
struct node *curr=NULL;
struct node *p[40];


struct node{
	char info;
	struct node *left;
	struct node *right;
};

void Initialise(struct node *p[]){
	int i;
	for(i=0; i<40; ++i){
		p[i]=NULL;
	}
	
}

void Valid(){
	int loading=236;
	printf("\tChecking Validity  ");
	printf("%c ", loading);
	Sleep(700);
	printf("%c ", loading);
	Sleep(700);
	printf("%c ", loading);
	Sleep(700);
	printf("%c ", loading);
	Sleep(700);
}

void Exit(){
	system("cls");
	system("COLOR 0E");
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t      THANK YOU FOR CHOOSING\n\n");
	PIP();
	Sleep(1200);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	exit(0);
}

void loading(){
int i, loading = 236;
	system("COLOR 0E");
	printf("\n\n\t\t\t\t\t\t    WELCOME TO\n\n");
	PIP();
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\t      ");
	for(i=1;i<=7;++i){
		printf("%c ", loading);
		Sleep(500);
		printf("%c ", loading);
		Sleep(500);
		printf("%c", loading);
		Sleep(500);
		//system("cls");
		printf("\b\b\b\b       \b\b\b\b\b\b\b");
	}
	Sleep(500);
}

int precedence(char symbol){
 if(symbol == '^')
 {
  return(3);
 }
 else if(symbol == '*' || symbol == '/')
 {
  return(2);
 }
 else if(symbol == '+' || symbol == '-')
 {
  return(1);
 }
 else return 0;
}

int verpaba(char a[])
{	int i,top1=-1,s[50];
	for (i=0;a[i]!='\0';i++)
	{
		if (a[i]=='[' || a[i]=='{' || a[i]=='(')
		{
			top1++;
			s[top1]=a[i];
		}
		else if ((a[i]==']' && s[top1]=='[') || (a[i]=='}' && s[top1]=='{') || (a[i]==')' && s[top1]=='('))
		{
			top1--;
		}
		else
		{
			continue;
		}
	}
	if (top1==-1)
	{
		//("Parenthesis Balanced");
		return 1;
	}
	else
	{
		//("Parenthesis Unbalanced");
		return 0;
	}
}

void Inpo(char k[])
{
	
	char ix[100]="", stack[100], px[100];
	int top2=-1;
	char item,x;
	strcat(ix,"(");
	strcat(ix,k);
	strcat(ix,")");
	int i=0,j=0;
	item=ix[i];
	while(item != '\0')
	{	
		if (item == '(')
    	{
			stack[++top2]=item;
    	}
		else if(item=='^' || item=='*' || item=='/' || item=='+' || item=='-')
		{
				while(precedence(item)<=precedence(stack[top2]))
				{
					px[j++]=stack[top2--];
				}
				stack[++top2]=item;
		}
		else if (calpha(item)==1 || cnum(item)==1)
		{
			px[j++]=item;
		}
		else if(item == ')')
    	{
    		x =stack[top2];
    		while(x != '(')
    		{
    			px[j++] = x;
    			x = stack[--top2];
    		}
    		top2--;
   		}
   		item=ix[++i];
	}
		px[j]='\0';
		curr=verPost(px);
}

void PIP(){
	char s1=48, s2=201, s3=206, s4=200, s5=187, s6=188, s7=216, s8=181, s9=198;//for ASCII characters
	printf("\n\t\t\t\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c", s2, s3, s3, s3, s3, s3, s3, s3, s3, s3, s3, s5);
	printf("\n\t\t\t\t\t\t   %c preINpos %c", s7, s7);
	printf("\n\t\t\t\t\t\t   %c%c%c%c%c%c%c%c%c%c%c%c", s4, s3, s3, s3, s3, s3, s3, s3, s3, s3, s3, s6);
	printf("\n\t\t\t\t\t    %c| A powerful converter |%c", s8, s9);
}

void Intro(){
	system("cls");
	system("COLOR E0");//Color combinations: 0E E0 FC A9 9A 
	PIP();
	printf("\n\n\tEnter an expression:  ");
	gets(e);
	CompressS(e);
	
}

void CompressS(char *e){
	char *pch;
	pch=strtok(e, " ");
	while(pch != NULL){
		strcat(ex, pch);
		pch=strtok(NULL, " ");
	}
	int i=0;
	while(ex[i]){
		ex[i]=tolower(ex[i]);
		i++;	
	}
}

int identifyPIP(char e[]){
	int end = strlen(e)-1;
	if(e[0]=='+' || e[0]=='-' || e[0]=='*' || e[0]=='/' || e[0]=='^')
	 return 1;
	else if(e[end]=='+' || e[end]=='-' || e[end]=='*' || e[end]=='/' || e[end]=='^')
	 return 2;
	else 
	 return 3;
	
}

void check(char e[]){
	if(identifyPIP(e)==1){
		Valid();
		printf("\n\tPrefix Expression!\n");
		curr=verPre(e);
		PreMenu(menu);
	}
	else if(identifyPIP(e)==2){
		Valid();
		printf("\n\tPostfix Expression!\n");
		curr=verPost(e);
		PostMenu(menu);
	}
	else{
		Valid();
		printf("\n\tInfix Expression!\n");
		curr=verIn(e);
		InMenu(menu);
	}
}

int calpha(char a){
	if ((int)a>=97 && (int)a<=122)
		return 1;
	else 
		return 0;
}

int cnum(char a){
	if ((int)a>=48 && (int)a<=57)
		return 1;
	else 
		return 0;
}

int coper(char a){
	if (a=='+' || a=='-' || a=='*' || a=='/' || a=='^')
		return 1;
	else 
		return 0;
}

struct node* verPre(char e[]){
	top=1;
	int i, num=0, alpha=0, o=0;
	Initialise(p);
	for(i=strlen(e)-1;i>=0;i--){
		if (calpha(e[i])==1){
			alpha++;
			top=pushLeaf(e[i],top);
		}
		else if(cnum(e[i])==1){
			num++;
			top=pushLeaf(e[i],top);
		}
		else{
			o++;
			top=pushParentPre(e[i],top);
		}	
	}	
	if(top != 2 || (top == 2 && (p[top]->left == NULL || p[top]->right == NULL ) ) ){
		printf("\n\n\tThe Entered Expression Is Not Eligible For Conversion/Evaluation");
		getch();
		Exit();		
		return NULL;
	}
	else{
		if(strlen(e)-o==num){
			printf("\n\t Valid Expression.\n\tEligible for both Conversion and Evaluation.\n");
			menu = 1;
		}
		else{
			printf("\n\t Valid Expression.\n\tEligible for Conversion only.\n");
			menu = 0;
		}
		return p[2];
	}
}

struct node* verPost(char e[]){
	top=1;
	
	int i,num=0, alpha=0, o=0;
	Initialise(p);
	for(i=0;i<strlen(e);i++){
		if (calpha(e[i])==1){
			alpha++;
			top=pushLeaf(e[i],top);
		}
		else if(cnum(e[i])==1){
			num++;
			top=pushLeaf(e[i],top);
		}
		else{
			o++;
			top=pushParentPost(e[i],top);
		}	
	}	
	if(top != 2 || (top == 2 && (p[top]->left == NULL || p[top]->right == NULL ) ) ){
		printf("\n\n\tThe Entered Expression Is Not Eligible For Conversion/Evaluation");
		getch();
		Exit();	
		return NULL;
	}
	else{
		if(strlen(e)-o==num){
			printf("\n\t Valid Expression.\n\tEligible for both Conversion and Evaluation.\n");
			menu = 1;
		}
		else{
			printf("\n\t Valid Expression.\n\tEligible for Conversion only.\n");
			menu = 0;
		}
		return p[2];
	}
}

struct node* verIn(char e[]){
	top=1;
	if(verpaba(ex)==1){
		Inpo(ex);
	}	
	else{
		printf("\n\tThe Infix Expression is Parenthesis unbalanced.");
		return NULL;
	}
	
}

int pushLeaf (char t, int top){
	if (top==39)
		printf("\n\tOverflow\n");
	else{
		curr=(struct node*)malloc(sizeof(struct node));
		curr->info=t;
		curr->left=curr->right=NULL;
		p[++top]=curr;
	}
	return top;		
}

int pushParentPost (char t, int top){
	if (top==39)
		printf("\n\tOverflow\n");
	else{
		curr=(struct node*)malloc(sizeof(struct node));
		curr->info=t;
		curr->right=p[top];
		top=pop(top);
		curr->left=p[top];
		top=pop(top);
		p[++top]=curr;
	}
	return top;		
}

int pushParentPre (char t, int top){
	if (top==39)
		printf("\n\tOverflow\n");
	else{
		curr=(struct node*)malloc(sizeof(struct node));
		curr->info=t;
		curr->left=p[top];
		top=pop(top);
		curr->right=p[top];
		top=pop(top);
		p[++top]=curr;
	}
	return top;		
}

int pop(int top){
	if (top==-1)
		printf("\n\tunderflow\n");
	else{
		p[top--]==NULL;
	}
}

void PreMenu(int m){
	int i;
	printf("\n\t\t  1. Infix Conversion");
	printf("\n\t\t  2. Postfix Conversion");
	printf("\n\t\t  3. Exit");
	printf("\n\t  Enter choice: ");
	scanf("%d", &i);
	if(i==1){
		printf("\n\t  The Infix Conversion yeilds:\n\t");
		inorder(curr);
		PreMenu(menu);
	}
	else if(i==2){
		printf("\n\t  The Postfix Conversion yeilds:\n\t");
		postorder(curr);
		PreMenu(menu);
	}
	else if(i==3){
		Exit();
	}
	else if(i==74592){
		exit(0);
	}
	else{
		printf("\n\tEnter carefully!!");
		PreMenu(menu);
	}
}

void PostMenu(int m){
	int i;
	printf("\n\t\t  1. Infix Conversion");
	printf("\n\t\t  2. Prefix Conversion");
	printf("\n\t\t  3. Exit");
	printf("\n\t  Enter choice: ");
	scanf("%d", &i);
	if(i==1){
		printf("\n\t  The Infix Conversion yeilds:\n\t");
		inorder(curr);
		PostMenu(menu);
	}
	else if(i==2){
		printf("\n\t  The Prefix Conversion yeilds:\n\t");
		preorder(curr);
		PostMenu(menu);
	}
	else if(i==3){
		Exit();
	}
	else if(i==74592){
		exit(0);
	}
	else{
		printf("\n\tEnter carefully!!");
		PostMenu(menu);
	}
}

void InMenu(int m){
	int i;
	printf("\n\t\t  1. Postfix Conversion");
	printf("\n\t\t  2. Prefix Conversion");
	printf("\n\t\t  3. Exit");
	printf("\n\t\t Enter choice: ");
	scanf("%d", &i);
	if(i==1){
		printf("\n\t  The Postfix Conversion yeilds:\n\t");
		postorder(curr);
		InMenu(menu);
	}
	else if(i==2){
		printf("\n\t  The Prefix Conversion yeilds:\n\t");
		preorder(curr);
		InMenu(menu);
	}
	else if(i==3){
		Exit();
	}
	else if(i==74592){
		exit(0);
	}
	else{
		printf("\n\tEnter carefully!!");
		InMenu(menu);
	}
}

void postorder(struct node* root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%c",root->info);
	}
}

void inorder(struct node* root){
	if(root!=NULL){
		inorder(root->left);
		printf("%c",root->info);
		inorder(root->right);
		}
}

void preorder(struct node* root){
	if(root!=NULL){
		printf("%c",root->info);
		preorder(root->left);
		preorder(root->right);
	}
}

void main(){
	loading();
	Intro();
	check(ex);
	getch();
	Exit();
}
