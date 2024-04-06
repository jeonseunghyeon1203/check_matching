#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct{
element data[MAX_STACK_SIZE];
int top;
}StackType;

void init_stack(StackType *s)
{
    s->top=-1;
}

int is_empty(StackType *s)
{
    return (s->top==-1);
}

int is_full(StackType *s)
{
    return (s->top==(MAX_STACK_SIZE - 1));
}

void push(StackType *s,element item)
{
    if(is_full(s)){
        fprintf(stderr,"���� ��ȭ ����\n");
        return;
    }
    else s->data[++(s->top)]=item;
}

element pop(StackType *s)
{
   if(is_empty(s)){
        fprintf(stderr,"���� ���� ����\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

element peek(StackType *s)
{
   if(is_empty(s)){
        fprintf(stderr,"���� ���� ����\n");
        exit(1);
    }
    else return s->data[(s->top)];
}

int check_matching(const char *in)
{
    StackType s;
    char ch,open_ch;    //ch�Է¹��� ���� �ϳ��� Ȯ���ϱ� ���� ����, open ch�ݴ� ��ȣ�� �������� ���ÿ��� �������� ���� ��ȣ
    int i,n=strlen(in);
    init_stack(&s);

    for(i=0;i<n;i++){
        ch=in[i];
        switch(ch){         //��ȣ�� �˻�
    case '(':case'[':case'{':   //���� ��ȣ���
        push(&s,ch);         //���ÿ� ����
        break;
    case ')': case']':case'}':     //�ݴ� ��ȣ���
        if(is_empty(&s)) return 0;    //������ ����ִ��� �˻�
        else {
            open_ch=pop(&s);   //������ ���� �����ִ� ��ȣ�� ������ �ݴ°�ȣ�� �´��� ��
            if((open_ch=='('&&ch !=')')||(open_ch=='['&&ch !=']')||(open_ch=='{'&&ch !='}')){
                return 0;
            }
            break;
        }
        }
    }
    if(!is_empty(&s))return 0;  //���ڿ��� ���ٸ� 0
    return 1;  //�� �̿ܿ��� ��ȣ�˻� ���� 1
}

int main()
{
    char p[MAX_STACK_SIZE];
    printf("�����Է� :");
    scanf("%[^\n]s",p);
    if(check_matching(p)==1)
        printf("%s ��ȣ�˻缺�� \n",p);
    else
        printf("%s ��ȣ�˻���� \n",p);
    return 0;
}
