#include<stdio.h>
#include<stdlib.h>

#define FALSE 0
#define TRUE 1

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;

//建立单链表
LinkList createLinkList(LinkList L,int n){
	LNode *p,*q;
	q=L;
	int i;
	printf("请输入创建链表的值:\n");
	for(i=0;i<n;i++){
		p=(LinkList)malloc(sizeof(LNode));
		scanf("%d",&p->data);
//----------以下是后插-------------------
//		p->next=L->next;
//		L->next=p;
//----------以下是前插-------------------
		q->next=p;
		p->next=NULL;
		q=p;
	}
	q->next=NULL;
	printf("链表创建成功!\n");
	return L;
}

//输出单链表
int printLinkList(LinkList L){
	LNode *p=L;
	if(!L){
		printf("该链表不存在\n");
		return FALSE;
	}
	if(L->next==NULL){
		printf("该链表为空表\n");
		return FALSE;
	}
	while(p->next!=NULL){
		p=p->next;
		printf("%d ",p->data);
	}
	printf("\n");
	return TRUE;
}
//按位查找
int getElemByPos(LinkList L,int pos,int n){
	LNode *p=L;
	int count=0;
	if(!p){
		return FALSE;
	}
	if(pos<0||pos>n){
		return FALSE;
	}
	while(p->next!=NULL){
		p=p->next;
		count++;
		if(count==pos){
			printf("你要查找的第%d位数字为%d\n",pos,p->data);
			return TRUE;
		}
	}
}

int getElemByValue(LinkList L,int value){
	LNode *p;
	int pos=0;
	if(!p){
		return FALSE;
	}
	for(p=L;p->next!=NULL;p=p->next,pos++){
		if(value==p->data){
			printf("你要查找的数字%d在第%d位\n",value,pos);
		}
	}
	return TRUE;
}

int getLength(LinkList L){
	LNode *p=L;
	int length=0;
	if(p==NULL){
		return FALSE;
	}
	while(p->next!=NULL){
		p=p->next;
		length++;
	}
	return length;
}

int listInsert(LinkList &L,int pos,int value){
	LNode *p=L;
	LNode *s;
	if(pos<0||pos>getLength(L)){
		printf("pos值不合法!\n");
		return FALSE;
	}
	s=(LinkList)malloc(sizeof(LNode));
	int len=getLength(L);
	int i;
	for(i=1;p->next!=NULL;i++){
		if(i==pos){
			s->data=value;
			s->next=p->next;
			p->next=s;
			len++;
			break;
		}
		p=p->next;
	}
	return TRUE;
}

int listDelete(LinkList L,int pos,int *value){
	LNode *p=L;
	LNode *q;
	int j;
	if(pos>getLength(L)||pos<=0){
		printf("NOT FOUND NUM\n");
		return FALSE;
	}
	for(j=1;j<pos;j++){
		p=p->next;
	}
	q=p->next;
	*value=q->data;
	p->next=q->next;
	free(q);
	return TRUE;
}

int listUpdate(LinkList L,int location,int value){
	int j;
	LNode *p=L;
	if(location<0||location>getLength(L)){
		printf("位置不合法\n");
		return FALSE;
	}
	for(j=1;j<=location;j++){
		p=p->next;
	}
	p->data=value;
	printf("修改成功\n");
	return TRUE;
}
//销毁链表
int destroyList(LinkList &L){
	LNode *p;
	while(L!=NULL){
		p=L;
		L=L->next;
		free(p);
	}
	printf("链表销毁完成\n");
	return TRUE;
}

void showOprationID(){
	printf("****************************************\n");
	printf("*%*s单链表操作序号%*s*\n",12,"",12,"");
	printf("*%*s1建表;2遍历输出;3按位查找;%*s*\n",6,"",6,"");
	printf("*%*s4按值查找;5获取单链表长度;6插入元素;%*s*\n",1,"",1,"");
	printf("*%*s7更新元素;8删除元素;9销毁链表;%*s*\n",4,"",4,"");
	printf("*%*s0退出;%*s*\n",16,"",16,"");
	printf("****************************************\n");
	printf("请输入操作序号:\n");
}


int main(){
	LNode *L;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	int op;
	showOprationID();
	scanf("%d",&op);
	while(op!=0){
		if(op==1){
			printf("1建表:\n");
			int len;
			printf("请输入创建链表的长度:\n");
			scanf("%d",&len);
			createLinkList(L,len);
		}
		if(op==2){
			printf("2遍历输出:\n");
			printf("链表输出如下：\n");
			printLinkList(L);
		}
		if(op==3){
			printf("3按位查找:\n");
			int i;
			printf("请输入需要查找的位置:\n");
			scanf("%d",&i);
			getElemByPos(L,i,getLength(L));
		}
		if(op==4){
			printf("4按值查找:\n");
			int value;
			scanf("%d",&value);
			getElemByValue(L,value);
		}
		if(op==5){
			printf("5获取单链表长度:\n");
			printf("%d\n",getLength(L));
		}
		if(op==6){
			printf("6插入元素:\n");
			int i;
			int e;
			printf("请输入插入位置：\n");
			scanf("%d",&i);
			printf("请输入插入数字:\n");
			scanf("%d",&e);
			listInsert(L,i,e);
		}
		if(op==7){
			printf("7更新元素:\n");
			int loc;
			int target;
			printf("请输入你需要更新的位置;\n");
			scanf("%d",&loc);
			printf("请输入你想改变的元素值:\n");
			scanf("%d",&target);
			listUpdate(L,loc,target);
		}
		if(op==8){
			printf("8删除元素:\n");
			int h,n;
			printf("请输入需要删除元素的序号:\n");
			scanf("%d",&h);
			if(listDelete(L,h,&n)){
				printf("删除的元素为：%d\n",n);
			}
		}
		if(op==9){
			printf("9销毁链表:\n");
			destroyList(L);
		}
		printf("操作 %d 结束!\n",op);
		showOprationID();
		scanf("%d",&op);
	}
    printf("退出！");
	return 0;
}

