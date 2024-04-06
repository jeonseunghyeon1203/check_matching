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
        fprintf(stderr,"스택 포화 에러\n");
        return;
    }
    else s->data[++(s->top)]=item;
}

element pop(StackType *s)
{
   if(is_empty(s)){
        fprintf(stderr,"스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

element peek(StackType *s)
{
   if(is_empty(s)){
        fprintf(stderr,"스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)];
}

int check_matching(const char *in)
{
    StackType s;
    char ch,open_ch;    //ch입력받은 값을 하나씩 확인하기 위한 변수, open ch닫는 괄호를 만났을때 스택에서 꺼내오는 여는 괄호
    int i,n=strlen(in);
    init_stack(&s);

    for(i=0;i<n;i++){
        ch=in[i];
        switch(ch){         //괄호를 검사
    case '(':case'[':case'{':   //여는 괄호라면
        push(&s,ch);         //스택에 저장
        break;
    case ')': case']':case'}':     //닫는 괄호라면
        if(is_empty(&s)) return 0;    //스택이 비어있는지 검사
        else {
            open_ch=pop(&s);   //스택의 제일 위에있는 괄호를 꺼내어 닫는괄호와 맞는지 비교
            if((open_ch=='('&&ch !=')')||(open_ch=='['&&ch !=']')||(open_ch=='{'&&ch !='}')){
                return 0;
            }
            break;
        }
        }
    }
    if(!is_empty(&s))return 0;  //문자열이 없다면 0
    return 1;  //이 이외에는 괄호검사 성공 1
}

int main()
{
    char p[MAX_STACK_SIZE];
    printf("수식입력 :");
    scanf("%[^\n]s",p);
    if(check_matching(p)==1)
        printf("%s 괄호검사성공 \n",p);
    else
        printf("%s 괄호검사실패 \n",p);
    return 0;
}
