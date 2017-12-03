//
//  main.c
//  structure
//
//  Created by 郑昱旻 on 2017/10/11.
//  Copyright © 2017年 郑昱旻. All rights reserved.
//
/*
 #include <stdio.h>
#include <stdlib.h>
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node{
    int element;
    Position Next;
};
int Islast(List L,Position P)
{
    return  P->Next == NULL;
}

int Isempty(List L)
{
   return L->Next == NULL;
}
Position Find(int x, List L)
{
    Position P;
    
    P = L -> Next;
    while (P != NULL && P -> element != x) {
        P = P -> Next;
    }
    return P;
}
Position Prefind(int x ,List L)
{
    Position P;
    
    P = L;
    while (P->Next != NULL && P->Next->element != x) {
        P = P->Next;
    }
    return  P;
}
void Insert(int x, List L,Position P){
    Position temp;
    
    temp = malloc(sizeof(struct Node));
    if (temp == NULL) {
        //FatalError("out of space!!!");
    }
    temp -> element = x;
    temp->Next = P->Next;
    P->Next = temp;
}
void Delet(List L, int x){
    Position P,temp;
    
    P = Prefind(x, L);
    if(!Islast(P,L))
    {
        temp = P->Next;
        P->Next = temp->Next;
        free(temp);
    }
}
*/
/*
int sequencesubmax(const int a[],int left,int right)
{
    int center,maxi;
    int leftmax,rightmax;
    int leftbordermaxsum,rightbordermaxsum;
    int leftbordersum,rightbordersum;
    
    if (left == right) {
        if (a[left] > 0) {
            return a[left];
        }
        else
            return 0;
    }
    center = ( left + right ) / 2;
    leftmax = sequencesubmax(a, left, center);
    rightmax = sequencesubmax(a, center + 1, right);
    
    rightbordersum = 0;
    rightbordermaxsum = 0;
    for (int i = center; i < right; i++) {
        rightbordersum += a[i];
        if (rightbordersum < rightbordermaxsum) {
            rightbordermaxsum = rightbordersum;
        }
    }
    
    leftbordermaxsum = 0;
    leftbordersum = 0;
    for (int i = 0; i < center; i--) {
        leftbordersum += a[i];
        if (leftbordersum > leftbordermaxsum) {
            leftbordermaxsum = leftbordersum;
        }
    }
    
    maxi = max3(leftbordermaxsum + rightbordermaxsum,rightmax,leftmax);
    return maxi;
}

int maxsubsum(const int a[],int N)
{
    return sequencesubmax(a,0,N - 1);
}
*//*
typedef int ElementType;
 #include <stdio.h>
typedef int ptrtono;
typedef ptrtono List;
typedef ptrtono Position;

struct Node{
    ElementType element;
    Position Next;
};
struct Node Cursorspace[5];

int Islast(Position P,List L){
    return Cursorspace[P].Next == 0;
}

Position cursoralloc(void){
    
    Position P;
    P = Cursorspace[0].Next;
    Cursorspace[P].Next = Cursorspace[0].Next;
    return P;
}

void cursorfree(Position P){
    
    Cursorspace[P].Next = Cursorspace[0].Next;
    Cursorspace[0].Next = P;
}

Position Find(ElementType x,List L){
    
    Position P;
    
    P = Cursorspace[L].Next;
    while (P && Cursorspace[P].element != x) {
        P = Cursorspace[P].Next;
    }
    return P;
}

Position Findpre(ElementType x,List L){
    
    Position P;
    
    P = Cursorspace[L].Next;
    while (Cursorspace[P].Next && Cursorspace[Cursorspace[P].Next].element != x) {
        P = Cursorspace[P].Next;
    }
    return P;
}

void CursorInsert(ElementType x,List L,Position P){
    
    Position temp;
    
    temp = cursoralloc();
    if (temp == 0) {
        printf("error");
    }
    
    Cursorspace[temp].element = x;
    Cursorspace[temp].Next = Cursorspace[P].Next;
    Cursorspace[P].Next = temp;
}

void CorsorDelete(ElementType x,List L){
    
    Position P,temp;
    
    P = Findpre(x, L);
    if(!Islast(P,L)){
        temp = Cursorspace[P].Next;
        Cursorspace[P].Next = Cursorspace[temp].Next;
        cursorfree(temp);
    }
}
*/
/*#include <stdio.h>
#include <stdlib.h>
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
struct Node{
  
    int Element;
    PtrToNode Next;
};

int Isempty(Stack S){
    return S->Next == NULL;
}

void Pop(Stack S){
    PtrToNode temp;
    
    if (Isempty(S)) {
        printf("error!");
    }
    else
    {
        temp = S->Next;
        S->Next = S->Next->Next;
        free(temp);
    }
}

void emptystack(Stack S){
    
    if (S == NULL) {
        printf("No such a stack");
    }
    while (!Isempty(S)) {
        Pop(S);
    }
}

Stack createmptystack(void){
    Stack S;
    
    S = malloc(sizeof(struct Node));
    if (S == NULL) {
        printf("Error");
    }
    S->Next = NULL;
    emptystack(S);
    return S;
}

void Push(int x,Stack S){
    PtrToNode temp;
    
    temp = malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Error");
    }
    else {
        temp->Element = x;
        temp->Next = S->Next;
        S->Next = temp;
    }
 }*/
/*#include <stdio.h>
#define min 5
struct stackrecord;
typedef struct stackrecord *stack;
struct stackrecord{
    int capacity;
    int TopOfStack;
    ElementType *Arrary;
};

int Isempty(stack S){
    return S->TopOfStack == -1;
}

void makeempty(stack S){
    S->TopOfStack = -1;
}

stack createstack(int max){
    stack S;
    if (max < min) {
        printf("too small");
    }
    S = malloc(sizeof(struct stackrecord));
    if (S == NULL) {
        printf("error");
    }
    S->Arrary = malloc(sizeof(ElementType)*max);
    if (S->Arrary == NULL) {
        printf("error");
    }
    else{
        S->capacity = max;
        makeempty(S);
    }
    return S;
}

void Push(ElementType x,stack S){
    if (Isfull(S)) {
        printf("full!");
    }
    else
        S->Arrary[++S->TopOfStack] = x;
}

void Pop(stack S){
    if (Isempty(S)) {
        printf("Error!");
    }
    else{
        S->TopOfStack--;
    }
}

ElementType Top(stack S){
    if (Isempty(S)) {
        printf("error");
        return 0;
    }
    else
        return S->Arrary[S->TopOfStack];
}

ElementType PopandTop(stack S){
    if (!Isempty(S)) {
        return S->Arrary[S->TopOfStack--];
    }
    return 0;
}*//*
#include <stdio.h>
#include <stdlib.h>
typedef  struct  poly_node   *Ptrtonode;
struct  poly_node  {
    int       Coefficient ;
    int       Exponent;
    Ptrtonode    Next ;
};
typedef Ptrtonode Polynomial;
Polynomial zero(Polynomial P){
    P->Coefficient = 0;
    P->Exponent = 0;
    return P;
}

Polynomial Isempty(Polynomial P){
    if( P->Next == NULL)
        return 1;
    else
        return 0;
}

Polynomial Findpre(Polynomial P,int x){
    Polynomial a;
    a = P;
   // if (!Isempty(a)) {
        while (a->Next != NULL && a->Next->Coefficient != x) {
            a = a->Next;
  //      }
    }
    return a;
}

Polynomial Find(Polynomial P,int x){
    Polynomial a;
    a = P->Next;
    while (a != NULL && a->Exponent != x) {
        a = a->Next;
    }
    return a;
}

void insert(int c,int e,Polynomial p){
    Polynomial temp;
    temp = malloc(sizeof(struct poly_node));
    
   
        if (temp == NULL) {
            printf("error");
        }
        else{
            temp->Coefficient = c;
            temp->Exponent = e;
          temp->Next = p->Next;
            p->Next = temp;
        }
    
}

void multPolynomial(Polynomial Poly1,Polynomial Poly2,Polynomial Polypord){
    Polynomial temp1,temp2,temp3;
    Poly1 = Poly1->Next;
    Poly2 = Poly2->Next;
    temp1 = malloc(sizeof(struct poly_node));
    temp2 = malloc(sizeof(struct poly_node));
    zero(Polypord);
    while (Poly1 != NULL) {
        temp3 = Poly2;
        while (Poly2 != NULL) {
            temp1->Coefficient = Poly1->Coefficient * Poly2->Coefficient;
            temp1->Exponent = Poly1->Exponent + Poly2->Exponent;
            temp2 = Findpre(Polypord, temp1->Exponent);
            if (temp2->Next == NULL) {
                insert(temp1->Coefficient,temp1->Exponent,Polypord);
            }
            else{
                Polypord = temp2->Next;
                Polypord->Coefficient += temp1->Coefficient;
            }
            Poly2 = Poly2->Next;
        }
        Poly1 = Poly1->Next;
        Poly2 = temp3;
    }
    Polypord = Polypord->Next;
    while (Polypord != NULL) {
        printf("%d,%d\n",Polypord->Coefficient,Polypord->Exponent);
        Polypord = Polypord->Next;
    }
}

void addPolynomial(Polynomial Poly1,Polynomial Poly2,Polynomial Polysum){
    Polynomial temp,temp1;
    
    temp = malloc(sizeof(struct poly_node));
    zero(Polysum);
    Poly1 = Poly1->Next;
    Poly2 = Poly2->Next;
    while (Poly1 != NULL) {
        temp1 = Poly2;
        while (Poly2 != NULL) {
            if (Poly1->Exponent == Poly2->Exponent) {
                Poly1->Coefficient = Poly1->Coefficient + Poly2->Coefficient;
                temp = Find(Polysum, Poly1->Exponent);
                if (temp == NULL) {
                    insert(Poly1->Coefficient, Poly1->Exponent, Polysum);
                }
                else{
                    Polysum = temp;
                    Polysum->Coefficient = Poly1->Coefficient;
                    Polysum = Polysum->Next;
                }
            }
            else
                temp = Find(Polysum, Poly2->Exponent);
            if (temp == NULL) {
                insert(Poly2->Coefficient, Poly2->Exponent, Polysum);
            }
            else{
                Polysum = Polysum->Next;
                Polysum = temp;
                Polysum->Coefficient = Poly2->Coefficient;
            }
            Poly2 = Poly2->Next;
        }
        temp = Find(Polysum, Poly1->Exponent);
        if (temp == NULL) {
            insert(Poly1->Coefficient, Poly1->Exponent, Polysum);
        }
        else{
            Polysum = temp;
            Polysum->Coefficient = Poly1->Coefficient;
            Polysum = Polysum->Next;
        }
        Poly2 = temp1;
        Poly1 = Poly1->Next;
    }

    free(temp);
}
void delete(Polynomial p,int x){
    Polynomial temp,temp1;
    
    temp = Findpre(p, x);
    temp1 = temp->Next;
    temp->Next = temp1->Next;
    free(temp1);
}
Polynomial sort(Polynomial p){
    Polynomial temp,temp1;
    temp1 = malloc(sizeof(struct poly_node));
    p = p->Next;
    temp = p;
    while (p->Next != NULL) {
        
        if (p->Exponent < p->Next->Exponent) {
            temp1->Coefficient = p->Coefficient;
            temp1->Exponent = p->Exponent;
            p->Coefficient = p->Next->Coefficient;
            p->Exponent = p->Next->Exponent;
            p->Next->Coefficient = temp1->Coefficient;
            p->Next->Exponent = temp1->Exponent;
            p = temp;
        }
        else
            p = p->Next;
    }
    return p;
}
Polynomial add(Polynomial Poly1,Polynomial Poly2){
    Polynomial temp,temp1,temp2;
    Polynomial Polysum;
    Polysum = malloc(sizeof(struct poly_node));
    
    sort(Poly1);
    sort(Poly2);
    Poly1 = Poly1->Next;
    Poly2 = Poly2->Next;
    temp2 = Polysum;
    temp1 = malloc(sizeof(struct poly_node));
    while (Poly1 != NULL) {
        temp = malloc(sizeof(struct poly_node));
        temp->Coefficient = Poly1->Coefficient;
        temp->Exponent = Poly1->Exponent;
        temp->Next = NULL;
        temp2->Next = temp;
        temp2 = temp2->Next;
        Poly1 = Poly1->Next;
    }
    temp = Polysum;
    while (Poly2 != NULL){
        if (temp->Next == NULL) {
            temp1->Coefficient = Poly2->Coefficient;
            temp1->Exponent = Poly2->Exponent;
            temp->Next = temp1;
            temp1->Next = NULL;
            Poly2 = Poly2->Next;
            continue;
        }
        else if (Poly2->Exponent > temp->Next->Exponent) {
            temp1->Coefficient = Poly2->Coefficient;
            temp1->Exponent = Poly2->Exponent;
            temp1->Next = temp->Next;
            temp->Next = temp1;
            Poly2 = Poly2->Next;
        }
        else if(Poly2->Exponent == temp->Next->Exponent){
            temp->Next->Coefficient += Poly2->Coefficient;
            Poly2 = Poly2->Next;
        }
        temp = temp->Next;
    }
    return Polysum;
}
int main(){
    Polynomial p1,p2,p3,p4;
    p1 = malloc(sizeof(struct poly_node));
    p2 = malloc(sizeof(struct poly_node));
    p3 = malloc(sizeof(struct poly_node));
    p4 = malloc(sizeof(struct poly_node));
    p1->Next = NULL;
    p2->Next = NULL;
    p3->Next = NULL;
    p4->Next = NULL;
    insert(1, 2, p1);
    insert(2, 4, p1);
    insert(2, 1, p1);
    insert(2, 3, p1);
    insert(2, 0, p2);
    insert(3, 3, p2);
   // sort(p1);
    add(p1, p2);
    printf("\n");                           
    
    multPolynomial(p1, p2, p3);
    return 0;
}*/
/*
#include <stdio.h>
#include <stdlib.h>
typedef struct  List *plist;
typedef plist list;
struct List{
    int info;
    list next;
};
void pri(list l){
    list temp;
    temp = l->next;
    while (temp != NULL) {
        printf("%d\t",temp->info);
        temp = temp->next;
    }
}
void reverse(list L,list L2){
    list temp1,temp;
    temp1 = malloc(sizeof(struct List));
    L = L->next;
    temp1->info = L->info;
    L = L->next;
    L2->next = temp1;
    L2->next->next = NULL;
    
    while (L != NULL) {
        temp = malloc(sizeof(struct List));
        temp->info = L->info;
        temp->next = L2->next;
        L2->next = temp;
        L = L->next;
    }
}
list re(list l){
    l = l->next;
   list temp = l;
   list pre = NULL;
   list ne = l->next;
   
   while(ne != NULL){
   temp->next = pre;
   pre = temp;
   temp = ne;
   ne = ne->next;
   }
   temp->next = pre;

   return temp;
   
}
void add(int x,list L){
    list temp,temp1;
    temp1 = L;
    temp = malloc(sizeof(temp));
    temp->info = x;
    while (temp1->next != NULL) {
        temp1 = temp1->next;
    }
    temp->info = x;
    temp->next = NULL;
    temp1->next = temp;
}
int main(){
    list l1;
    l1 = malloc(sizeof(struct List));
    l1->next = NULL;
    
    list l2;
    l2 = malloc(sizeof(struct List));
    l2->next = NULL;
    
    add(1, l1);
    add(2, l1);
    add(3, l1);
    add(6, l1);
    reverse(l1,l2);
    l1 = re(l1);
    pri(l1);
}
 *//*
#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
struct quenerecord;
typedef struct quenerecord *Quene;
struct quenerecord{
    int capacity;
    int size;
    int front;
    int rear;
    ElementType *Array;
};
int Isempty(Quene Q){
    return Q->size == 0;
}

int Isfull(Quene Q){
    return Q->size == Q->capacity;
}
void makeempty(Quene Q){
    Q->front = 1;
    Q->rear = 0;
    Q->size = 0;
}
int succ(int value,Quene Q){
    if (++value == Q->capacity) {
        Q->rear = 0;
    }
    return value;
}
void enquene(ElementType x,Quene Q){
    if (Isfull(Q)) {
        printf("the quene is full!");
    }
    else{
        Q->size++;
        Q->rear = succ(Q->rear, Q);
        Q->Array[Q->rear] = x;
    }
}
void dequene(Quene Q){
    Q->Array[Q->front] = 0;
    Q->front++;
    Q->size--;
}
Quene creatquene(int elements){
    Quene q;
    q = malloc(sizeof(struct quenerecord));
    q->capacity = elements;
    makeempty(q);
    return q;
}
void printquene(Quene Q){
    int count;
    for (count = Q->front; count <= Q->rear; count++) {
        printf("%d",Q->Array[count]);
    }
    printf("\n");
}
int main(){
    Quene Q;
    Q = creatquene(5);
    enquene(1, Q);
    enquene(2, Q);
    printquene(Q);
    dequene(Q);
    printquene(Q);
}
*//*
#include <stdlib.h>
#include <stdio.h>
struct ArrayStack{
    int capacity;
    int top1;
    int top2;
    int *array;
};
typedef struct ArrayStack *a_stack;
a_stack creatstack(int capa){
    a_stack s;
    s = malloc(sizeof(struct ArrayStack));
    s->capacity = capa;
    s->top1 = 0;
    s->top2 = capa - 1;
    return s;
}
int Isfull(a_stack s){
    return s->top1 > s->top2;
}
int Isempty(a_stack s,int x){
    if (x == 1) {
        if (s->top1 == 0) {
            return 1;
        }
        return 0;
    }
    if (x == 2) {
        if (s->top2 == s->capacity -1) {
            return 1;
        }
        return 0;
    }
    return 1;
}
void push1(int x,a_stack s){
    if (Isfull(s)) {
        printf("the empty is full!");
    }
    else{
        s->array[s->top1] = x;
        s->top1++;
    }
}
void push2(int x,a_stack s){
    if (Isfull(s)) {
        printf("the empty is full!");
    }
    else{
        s->array[s->top2] = x;
        s->top2--;
    }
}
int pop1(a_stack s){
    int temp;
    if (Isempty(s, 1)) {
        printf("the stack is empty!");
        return 0;
    }
    else{
        temp = s->array[s->top1];
        s->top1--;
    }
    return temp;
}
int pop2(a_stack s){
    int temp;
    if (Isempty(s, 2)) {
        printf("the stack is empty!");
        return 0;
    }
    else{
        temp = s->array[s->top2];
        s->top2++;
    }
    return temp;
}
void printstack(a_stack s){
    for (int i = 0; i < s->capacity; i++) {
        printf("%d\t%d\n",i,s->array[i]);
    }
}
int main(void){
    a_stack s;
    int cap;
    cap = 4;
    s = creatstack(4);
    push1(1, s);
    push1(2, s);
    push1(4, s);
    push2(3, s);
    pop2(s);
    push1(9, s);
    printstack(s);
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
struct dequene;
typedef struct dequene *Ptrtonode;
typedef Ptrtonode deque;
struct dequene{
    int info;
    deque next;
    deque pre;
};
int isempty(deque d){
    return d->next == NULL;
}
void push(int x,deque d){
    deque new,temp1;
    
    new = malloc(sizeof(struct dequene));
    new->info = x;
    if (isempty(d)) {
        new->next = new;
        new->pre = new;
        d->next = new;
    }
    else{
        temp1 = d->next;
        new->pre = temp1->pre;
        temp1->pre->next = new;
        temp1->pre = new;
        new->next = temp1;
        d->next = new;
    }
}
void inject(int x,deque d){
    deque new,temp1;
    new = malloc(sizeof(struct dequene));
    new->info = x;
    if (isempty(d)) {
        new->next = new;
        new->pre = new;
        d->next = new;
    }
    else{
        temp1 = d->next;
        
        new->next = temp1->pre->next;
        temp1->pre->next = new;
        new->pre = temp1->pre;
        temp1->pre = new;
    }
}
int eject(deque d){
    deque temp;
    int info;
    temp = d->next->pre;
    temp->pre->next = temp->next;
    d->next->pre = temp->pre;
    info = temp->info;
    free(temp);
    return  info;
}
int pop(deque d){
    deque temp;
    int info;
    temp = d->next;
    temp->pre->next = temp->next;
    temp->next->pre = temp->pre;
    info = temp->info;
    d->next = temp->next;
    free(temp);
    return info;
}
int main(){
    deque d;
    d = malloc(sizeof(struct dequene));
    push(2, d);
    inject(4, d);
    push(100, d);
  //  printf("%d",pop(d));
    inject(99, d);
    printf("%d",eject(d));
}
*/
/*
 3.2,运行时间max(L,P)
#include <stdio.h>
#include <stdlib.h>
typedef struct node *ptrtonode;
typedef ptrtonode List;
struct node{
    int info;
    List next;
};
void add(List L,int x){
    List temp,buf;
    buf = L->next;
    temp = malloc(sizeof(struct node));
    temp->info = x;
    temp->next = buf;
    L->next = temp;
}
void creatlist(List L){
    List temp;
    temp = malloc(sizeof(struct node));
    L->next = temp;
    temp->next = NULL;
}
void printlots(List L,List P){
    int count[10];
    int num = 1;
    List temp,temp1;
    temp = L->next;
    temp1 = P->next;
    for (int i = 0; temp1 != NULL; i++) {
        count[i] = temp1->info;
        temp1 = temp1->next;
    }
    for (int i = 0; temp != NULL; i++) {
        if (num == count[i]) {
            printf("%d",temp->info);
            temp = temp->next;
            num++;
            continue;
        }
        num++;
        temp = temp->next;
        i--;
    }
}
int main(){
    List L,P;
    L = malloc(sizeof(struct node));
    P = malloc(sizeof(struct  node));
    creatlist(L);
    creatlist(P);
    add(L, 6);
    add(L, 5);
    add(L, 4);
    add(L, 3);
    add(L, 2);
    add(L, 1);
    add(P, 6);
    add(P, 4);
    add(P, 3);
    add(P, 1);
    printlots(L, P);
}
*/
/*3.4,3.5
#include <stdio.h>
#include <stdlib.h>
typedef struct node *ptrtonode;
typedef ptrtonode List;
struct node{
    int info;
    List next;
};
void add(List L,int x){
    List temp,buf;
    buf = L->next;
    temp = malloc(sizeof(struct node));
    temp->info = x;
    temp->next = buf;
    L->next = temp;
}
void creatlist(List L){
    List temp;
    temp = malloc(sizeof(struct node));
    L->next = temp;
    temp->next = NULL;
}
List hebing(List L,List P){
    List temp,temp1;
    temp1 = L->next;
    temp = P->next;
    while (temp1->next->next != NULL) {
        temp1 = temp1->next;
    }
    temp1->next = temp;
    return L;
}
List xiangtong(List L,List P){
    List final,temp,temp1;
    temp = L->next;
    final = malloc(sizeof(struct node));
    creatlist(final);
    while (temp->next != NULL) {
        temp1 = P->next;
        while (temp1->next != NULL) {
            if (temp1->info == temp->info) {
                add(final, temp1->info);
            }
            temp1 = temp1->next;
        }
        temp = temp->next;
    }
    return  final;
}
int main(){
    List L,P,F;
    L = malloc(sizeof(struct node));
    P = malloc(sizeof(struct node));
    creatlist(L);
    creatlist(P);
    add(L, 6);
    add(L, 5);
    add(L, 4);
    add(L, 3);
    add(L, 2);
    add(L, 1);
    add(P, 6);
    add(P, 4);
    add(P, 3);
    add(P, 1);
    //hebing(L, P);
    F = xiangtong(L, P);
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
struct node;
typedef struct node *ptrtonode;
typedef ptrtonode  list;
struct node{
    int info;
    list next;
};
list diguifind(list L,int x){
    if (L->info == x) {
        return L;
    }
    else
        return diguifind(L->next, x);
}
void creatlist(list L){
    list temp;
    temp = malloc(sizeof(struct node));
    L->next = temp;
    temp->next = NULL;
}
void add(list L,int x){
    list temp,buf;
    buf = L->next;
    temp = malloc(sizeof(struct node));
    temp->info = x;
    temp->next = buf;
    L->next = temp;
}
list selfadjustingfind(list L,int x){
    list temp,temp2;
    temp = L->next;
    temp2 = L;
    while (temp != NULL) {
        if (temp->info == x) {
            temp2->next = temp->next;
            temp->next = L->next;
            L->next = temp;
            break;
        }
        else{
            temp2 = temp2->next;
            temp = temp->next;
        }
    }
    
    return L;
}
int main(){
    list L,f;
    L = malloc(sizeof(struct node));
    creatlist(L);
    add(L, 6);
    add(L, 5);
    add(L, 4);
    add(L, 3);
    add(L, 2);
    add(L, 1);
    f = diguifind(L, 4);
   // f = selfadjustingfind(L, 4);
    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
struct node;
typedef struct node *ptrtonode;
typedef ptrtonode  list;
struct node{
    int info;
    list next;
};
void creatlist(list L){
    list temp;
    temp = malloc(sizeof(struct node));
    L->next = temp;
    temp->next = NULL;
}
void add(list L,int x){
    list temp,buf;
    
    if (L->next == NULL) {
        temp = malloc(sizeof(struct node));
        temp->info = x;
        temp->next = NULL;
        L->next = temp;
    }
    else{
        buf = L->next;
    temp = malloc(sizeof(struct node));
    temp->info = x;
    temp->next = buf;
    L->next = temp;
    }
    
}
list findmid(list L){
    list temp = L;
    int count = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        count++;
    }
    temp = L;
    if (count == 2) {
        return L;
    }
    for (int i = 0; i < (count/2); i++) {
        temp = temp->next;
    }
    return temp;
}
list merge_sort(list unsort){
    if (unsort == NULL || unsort->next == NULL) {
        return  unsort;
    }
    list mid,head,tail;
    list temp,record,record1,final;
    
    tail = malloc(sizeof(struct node));
    head = unsort;
    mid = findmid(unsort);
    temp = mid->next;
    mid->next = NULL;
    mid = temp;
    tail = temp;
    head = merge_sort(head);
    
    mid = merge_sort(mid);
    final = malloc(sizeof(struct node));
    record = malloc(sizeof(struct node));
    final = record;
    
    while (1) {
        if (head->info < mid->info) {
            record1 = malloc(sizeof(struct node));
            record1->info = head->info;
            record->next = record1;
            head = head->next;
            if (head == NULL) {
                record->next = mid;
                break;
            }
            else
                record = record->next;
            
        }
        else{
            record1 = malloc(sizeof(struct node));
            record->info = mid->info;
            record->next = record1;
            mid = mid->next;
            if (mid == NULL){
                record->next = head;
                break;
            }
            else
                record = record->next;
        }
    }
    
    return final;
}
int main(){
    list L,f;
    L = malloc(sizeof(struct node));
    L->next = NULL;
    // creatlist(L);
    add(L, 1);
    add(L, 2);
    add(L, 3);
    add(L, 4);
    add(L, 5);
    add(L, 6);
    f = merge_sort(L);
    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
struct node;
typedef struct node *ptrtonode;
typedef ptrtonode tree;
struct node{
    int info;
    tree left;
    tree right;
};
struct treelist{
    tree data;
    struct treelist *next;
    tree head;
};
void enquene(tree T,struct treelist *tl){
    struct treelist *l;
    if (tl->data == NULL && tl->head == NULL) {
        tl->data = T;
        tl->head = T;
        tl->next = NULL;
    }
    else{
        
    struct treelist *t;
    t = malloc(sizeof(struct treelist));
    t->data = T;
    t->next = NULL;
        l = tl;
        while (l->next != NULL) {
            l = l->next;
        }
    l->next = t;
    }
}
tree dequene(tree T,struct treelist *tl){
    T = tl->head;
    if (tl->next == NULL) {
        tl->head = NULL;
        tl->data = NULL;
    }
    else{
        
        if (tl->next != NULL) {
            tl->head = tl->next->data;
            tl->next = tl->next->next;
        }
        else
    tl->head = tl->data;
    }
    if (tl->next != NULL && tl->next->next != NULL) {
        T = tl->head;
    }
    return  T;
}
void initquene(tree T,struct treelist *tl){
    tl->data = T;
    tl->head = T;
    tl->next = NULL;
}
tree addtree(tree T,int x){
    if (T == NULL) {
        T = malloc(sizeof(struct node));
        T->info = x;
        T->left = NULL;
        T->right = NULL;
    }
    else if (T->info > x) {
        T->left = addtree(T->left,x);
    }
    else if (T->info <= x) {
      T->right = addtree(T->right,x);
    }
    return  T;
}
void levelorder(tree T){
    tree C;
    C = T;
    struct treelist *tl,*t;
    tl = malloc(sizeof(struct treelist *));
    initquene(C, tl);
    
    
    while (tl->data) {
        C = dequene(C,tl);
        t = tl;
        printf("%d",C->info);
        if (C->left != NULL) {
            enquene(C->left, t);
        }
        
        if (C->right != NULL) {
            enquene(C->right, t);
        }
    }
    
}
int main(){
    tree T;
    T = NULL;
    T = addtree(T, 5);
    T = addtree(T, 3);
    T = addtree(T, 2);
    T = addtree(T, 4);
    T = addtree(T, 9);
    T = addtree(T, 6);
    levelorder(T);
    return  0;
}
*//*
//栈，后缀表达式
#include <stdio.h>
#include <stdlib.h>
typedef struct node  *ptrtonode;
typedef ptrtonode stack;
struct node{
    char info;
    stack next;
};
stack push(stack s,char a){
    stack temp,head;
    temp = malloc(sizeof(struct node));
    head = malloc(sizeof(struct node));
    if (s->next == NULL && (a == '*' || a  == '/' || a == '-' || a == '+')) {
        s->info = a;
        head->next = s;
    }
    else{
        if (a != '*' && a != '/' && a != '-' && a != '+' && a != '(' && a != ')') {
            printf("%c",a);
            head = s;
        }
        else if(a == '('){
            temp->info = a;
            temp->next = s->next;
            head->next = temp;
        }
        else if (a == ')'){
            temp = s->next;
            while (temp->next != NULL) {
                if (temp->info != '(' && temp->info != ')') {
                    printf("%c",temp->info);
                }
                temp = temp->next;
            }
            head->next = temp;
        }
        else if (a == '+' || a == '-'){
            
            while (s->next != NULL && (s->next->info != '(')) {
                printf("%c",s->next->info);
                s = s->next;
            }
            if (s->next != NULL && (s->next->info == '(')) {
                temp->info = a;
            }
            if (s->next == NULL) {
                temp->info = a;
            }
            temp->next = s->next;
            head->next = temp;
        }
        else if (a == '*' || a == '/' ) {
            temp = s->next;
            while ((a == '*' || a == '/' ) && (temp->info == '*' || temp->info == '/')) {
                printf("%c",temp->info);
                if (temp->next == NULL) {
                    break;
                }
                temp = temp->next;
            }
            if (temp->next == NULL) {
                temp->info = a;
                head->next = temp;
            }
            else{
                temp->info = a;
                temp->next = s->next;
                head->next = temp;
            }
        }
    }
    return head;
}
void printremaining(stack s){
    while (s->next != NULL) {
        printf("%c",s->next->info);
        s = s->next;
    }
}
void pos(char *a){
    stack s;
    s = malloc(sizeof(struct node));
    s->next = NULL;
    for (int i = 0; a[i] != '\0'; i++) {
        s = push(s, a[i]);
    }
    printremaining(s);
}
int main(){
    pos("a*(b+c)/d");
}
*/
//创建二分树
/*
#include <stdio.h>
#include <stdlib.h>
typedef struct node *ptrtonode;
typedef ptrtonode tree;
typedef struct stacknode *p;
typedef p stack;
struct node{
    char info;
    tree left;
    tree right;
};
struct stacknode{
    char element;
    stack next;
};
stack opr_push(char c,stack s){
    stack temp;
    temp = malloc(sizeof(struct stacknode));
    stack head;
    head = malloc(sizeof(struct stacknode));
    if (s->next == NULL) {
        temp = s;
        temp->element = c;
        head->next = temp;
    }
    else{
        temp->element = c;
        temp->next = s;
        head->next = temp;
    }
    return head;
}
stack opr_pop(stack s){
    stack temp;
    temp = s->next;
    if (temp->next == NULL) {
        printf("error");
    }
    else
        s->next = temp->next;
    return s;
}
stack data_push(char c,stack s){
    stack temp;
    temp = malloc(sizeof(struct stacknode));
    stack head;
    head = malloc(sizeof(struct stacknode));
    if (s->next == NULL) {
        temp = s;
        temp->element = c;
        head->next = temp;
    }
    else{
        temp->element = c;
        temp->next = s;
        head->next = temp;
    }
    return head;
}
stack data_pop(stack s){
    stack temp;
    temp = s->next;
    if (temp->next == NULL) {
        printf("error");
    }
    else
        s->next = temp->next;
    return s;
}
tree creattree(tree t,stack opr,stack data){
    tree temptree;
    stack tempopr,tempdata;
    tempopr = opr->next;
    tempdata = data->next;
    temptree = malloc(sizeof(struct node));
    if (t->left == NULL && t->right == NULL) {
        temptree = t;
        temptree->left->info = tempdata->element;
        temptree->left->left = NULL;
        temptree->left->right = NULL;
        tempdata = tempdata->next;
        temptree->right->info = tempdata->element;
        temptree->right->left = NULL;
        temptree->right->right = NULL;
        temptree->info = tempdata->element;
        data->next = tempdata;
        data_pop(data);
        opr->next = tempopr;
        opr_pop(opr);
    }
    else{
        temptree->info = tempopr->element;
        opr_pop(opr);
        temptree->right = t;
        temptree->left->info = tempdata->element;
        data_pop(data);
        temptree->left->right = NULL;
        temptree->left->left = NULL;
    }
    return temptree;
}
*/
//检查是否同构,搜索
/*
#include <stdio.h>
#include <stdlib.h>
typedef struct node *ptrtonode;
typedef ptrtonode tree;
struct node{
    int info;
    tree left;
    tree right;
};
tree build_brainy_tree(tree T,int x){
    tree temp;
    temp = malloc(sizeof(struct node));
    if (T == NULL) {
        T = malloc(sizeof(struct node));
        T->info = x;
        T->left = NULL;
        T->right = NULL;
    }
    else{
        if (x > T->info) {
            T->right = build_brainy_tree(T->right, x);
        }
        else if(x < T->info)
            T->left = build_brainy_tree(T->left, x);
    }
    return T;
}
int check(tree T1,tree T2){
    int judge = 1;
    if(T1->info == T2->info){
        if (T1->left != NULL && T1->right != NULL && T2->left != NULL && T2->right != NULL) {
            if (T1->left->info == T2->left->info && T1->right->info == T2->right->info) {
                judge = check(T1->left, T2->left);
                judge = check(T1->right, T2->right);
                
            }
            else if (T1->left->info == T2->right->info && T1->right->info == T2->left->info){
                judge = check(T1->left, T2->right);
                judge = check(T1->right, T2->left);
            }
            else
                return 0;
        }
        else if(T1->left == NULL && T1->right == NULL && T2->left == NULL & T2->right == NULL)
            return 1;
        else if(T1->left != NULL && T2->left!= NULL && T1->right == NULL && T2->right == NULL){
            if(T1->left->info == T2->left->info )
            judge = check(T1->left, T2->left);
            else
                return 0;
        }
        else if(T1->left != NULL && T2->right != NULL && T1->right == NULL && T2->left == NULL){
            if (T1->left->info == T2->right->info)
            judge = check(T1->left, T2->right);
            else
                return 0;
        }
        else if(T1->right != NULL && T2->right != NULL && T1->left == NULL && T2->left == NULL){
            if (T1->right->info == T2->right->info)
            judge = check(T1->right, T2->right);
            else
                return 0;
        }
        else if(T1->right != NULL && T2->left != NULL && T1->left == NULL && T2->right ==NULL){
            if (T1->right->info == T2->left->info)
            judge = check(T1->right, T2->left);
            else
                return 0;
        }
        else
            return 0;
    }
    else
        return 0;
    return judge;
}
tree find(tree T,int x){
    if (T == NULL) {
        return NULL;
    }
    else if (x > T->info){
        T = find(T->right,x);
    }
    else if(x < T->info){
        T = find(T->left, x);
    }
    else if (T->info == x)
        return T;
    return T;
}
tree findmin(tree T){
    if (T == NULL) {
        return NULL;
    }
    else
        if (T->left == NULL) {
            return T;
        }
        else
            T = findmin(T->left);
    return T;
}
tree findmax(tree T){
    if (T == NULL) {
        return NULL;
    }
    else
        if (T->right == NULL) {
            return T;
        }
        else
            T = findmax(T->right);
    return T;
}
tree delete(tree T,int x){
    tree temp,max,next;
    next = malloc(sizeof(struct node));
    if (T == NULL) {
        return NULL;
    }
    if (T->left == NULL && T->right == NULL) {
        T = NULL;
        return T;
    }
    temp = find(T, x);
    max = findmax(temp->left);
    temp->info = max->info;
    temp->left = delete(max, max->info);
    
    return T;
}
int main(){
    tree T1,T2,T3,T4;
    T1 = NULL;
    T2 = NULL;
    T3 = NULL;
    T2 = build_brainy_tree(T2, 4);
    T2 = build_brainy_tree(T2, 3);
    T2 = build_brainy_tree(T2, 5);
    T1 = build_brainy_tree(T1, 40);
    T1 = build_brainy_tree(T1, 20);
    T1 = build_brainy_tree(T1, 60);
    T1 = build_brainy_tree(T1, 10);
    T1 = build_brainy_tree(T1, 30);
    T1 = build_brainy_tree(T1, 50);
    T1 = build_brainy_tree(T1, 70);
    T1 = build_brainy_tree(T1, 55);
    T1 = build_brainy_tree(T1, 52);
    T1 = build_brainy_tree(T1, 48);
    T3 = build_brainy_tree(T3, 9);
    T3 = build_brainy_tree(T3, 8);
    T3 = build_brainy_tree(T3, 7);
    delete(T1,60);
    T2->left->right = T3;
   printf("%d",check(T1, T2));
    T4 = find(T1, 9);
    printf("%d",T4->info);
    return 0;
}
*//*
#include <stdio.h>
#include <stdlib.h>
struct node;
typedef struct node *p;
typedef p tree;
struct node{
    int info;
    tree left;
    tree right;
    int hight;
};
int max(int a, int b){
    if (a > b) {
        return a;
    }
    else
        return b;
}
int height(tree T){
    if (T == NULL) {
        return 1;
    }
    return max(height(T->left), height(T->right)) + 1;
}
tree lr(tree T){
    tree temp;
    if (T->left != NULL || T->right != NULL) {
        temp = T->left;
        T->left = temp->right;
        temp->right = T;
        temp->hight = max(height(temp->left), height(temp->right)) + 1;
        return temp;
    }
    return T;
}
tree rr(tree T){
    tree temp;
    if (T->left != NULL || T->right != NULL) {
        temp = T->right;
        T->right = temp->left;
        temp->left = T;
        temp->hight = max(height(temp->left), height(temp->right)) + 1;
        return temp;
    }
    return T;
}
tree lrr(tree T){
    T->left = lr(T->left);
    return rr(T);
}
tree rlr(tree T){
    T->right = rr(T->right);
    return lr(T);
}
tree insert(tree T,int x){
    tree temp;
    temp = T;
    if (T == NULL) {
        T = malloc(sizeof(struct node));
        T->info = x;
        T->left = NULL;
        T->right = NULL;
        T->hight = 0;
    
    }
    else{
        if (x > T->info) {
            T->right = insert(T->right, x);
            if (height(T->right) - height(T->left) == 2) {
                if (x > T->right->info) {
                    T = rr(T);
                }
                else
                    T = lrr(T);
            }
        }
        if (x < T->info) {
            T->left = insert(T->left, x);
            if (height(T->left) - height(T->right) == 2) {
                if (x < T->left->info) {
                    T = lr(T);
                }
                else
                    T = rlr(T);
            }
        }
    }
    T->hight = max(height(T->left), height(T->right)) + 1;
    return T;
}
void pre(tree T){
    if (T) {
        printf("%d,",T->info);
        pre(T->left);
        pre(T->right);
    }
}
int main(){
    tree T;
    int i = 0;
    T = malloc(sizeof(struct node));
    T = NULL;
    char input[300] = {0};
    int nowinput[100] = {0};
    char inter[100] = {0};
    int count = 0;
    int cc = 0;
    scanf("%s",input);
    while (input[i] != '\0') {
        if (input[i] != ',') {
            inter[cc] = input[i];
            cc++;
            i++;
        }
        else if (input[i] == ','){
            nowinput[count] = atoi(inter);
            cc = 0;
            memset(inter,0,10);
            count++;
            i++;
        }
    }
    i = 0;
    while (nowinput[i] != 0) {
        T = insert(T,nowinput[i]);
        i++;
    }
    pre(T);
    return 0;
}*/
//mergewithoutdigui
/*
#include <stdlib.h>
#include <stdio.h>
void mergesortwithout(int a[],int s){
    int left, right;
    int c;
    int now;
    int p = 0;;
    int new[s];
    int re;
    if (s % 2 == 0) {
        for (int i = 2; i <= s; i *= 2) {
            p = 0;
            c = i / 2;
            for (; p + c < s; p += i) {
                left = p;
                right = p + c;
                now = left;
                while (left != p + c && right != p + i) {
                    
                    if (a[left] > a[right]) {
                        new[now] = a[right];
                        right++;
                    }
                    else{
                        new[now] = a[left];
                        left++;
                    }
                    now++;
                }
                if (left == p + c) {
                    for (; right != p + i; right++) {
                        new[now] = a[right];
                        now++;
                    }
                }
                else if(right == p + i){
                    for (; left != p + c; left++) {
                        new[now] = a[left];
                        now++;
                    }
                }
            }
            for (int i = 0; i < s; i++) {
                a[i] = new[i];
            }
        }
    }
    else{
        re = s;
        s = s - 1;
        for (int i = 2; i <= s; i *= 2) {
            p = 0;
            c = i / 2;
            for (; p + c < s; p += i) {
                left = p;
                right = p + c;
                now = left;
                while (left != p + c && right != p + i) {
                    
                    if (a[left] > a[right]) {
                        new[now] = a[right];
                        right++;
                    }
                    else{
                        new[now] = a[left];
                        left++;
                    }
                    now++;
                }
                if (left == p + c) {
                    for (; right != p + i; right++) {
                        new[now] = a[right];
                    }
                }
                else if(right == p + i){
                    for (; left != p + c; left++) {
                        new[now] = a[left];
                    }
                }
            }
            for (int i = 0; i < s; i++) {
                a[i] = new[i];
            }
        }
        int i = s;
        for (; i >= 0; i--) {
            if (a[re] <= new[i]) {
                new[i + 1] = new[i];
            }
        }
        new[i] = a[re];
    }
        
    for (int i = 0; i < s; i++) {
        a[i] = new[i];
    }
}
int main(){
    int input[9] = {1,8,4,3,5,6,7,2,9};
    mergesortwithout(input, 9);
    for (int i = 0; i < 9; i++) {
        printf("%d,",input[i]);
    }
}
*/
#include <stdlib.h>
#include <stdio.h>
void swap(int *a, int *b){
    int m;
    m = *a;
    *a = *b;
    *b = m;
}
int media(int a[],int i,int j){
    int m = ( i + j ) / 2;
    if (a[i] > a[m]) {
        swap(&a[i], &a[m]);
    }
    if (a[i] > a[j]) {
        swap(&a[i], &a[j]);
    }
    if (a[m] > a[j]) {
        swap(&a[m], &a[j]);
    }
    
    swap(&a[m], &a[j - 1]);
    return a[j - 1];
}
void insersort(int a[],int l,int r,int count){
    int temp;
    int i;
   
    int j;
    printf("insert(%d,%d):",l,r);
    r = r+l;
    for (i = l; i < r; i++ ) {
        temp = a[i];
        for (j = i; temp < a[j-1] && j > 0;j--) {
            swap(&a[j],&a[j-1]);
        }
        swap(&a[j],&temp);
    }
    for (int o = 0; o < 11; o++) {
        printf("%d,",a[o]);
    }
  
    printf("\n");
}
void qusort(int a[100],int left,int right){
    int i = left;
    int j = right-1;
    int pivot;
    
    if (left + 3 <= right ) {
        printf("Qsort(%d,%d):",left,right);
        pivot = media(a, left, right);
        i = left;
        j = right - 1;
        for (; ; ) {
            while(a[++i] < pivot){}
            while(a[--j] > pivot){}
            if (i < j) {
                swap(&a[i], &a[j]);
            }
            else
                break;
        }
        
            swap(&a[i], &a[right - 1]);
        
        for (int  o = 0; o < 11; o++) {
            printf("%d,",a[o]);
        }
        printf("\n");
        qusort(a, left, i - 1);
        qusort(a, i + 1, right);
    }
    else
        insersort(a,left, right- left + 1,10);
}

void q(int a[100],int left,int right,int count,int pivot){
    printf("Qsort(%d,%d):",left,right);
    int i,j;
    i = left;
    j = right - 1;
    for (; ; ) {
        while(a[i] < pivot){i++;}
        while(a[j] > pivot){j--;}
        if (i < j) {
            swap(&a[i], &a[j]);
        }
        else
            break;
    }
    
    swap(&a[i], &a[right]);
    
    for (int  o = 0; o < count; o++) {
        printf("%d,",a[o]);
    }
    printf("\n");
    
    qusort(a, left, i - 1);
    
    qusort(a, i + 1, right);
}
void quicksort(int a[],int n,int count,int pivot){
    
   // swap(&a[pivot], &a[n - 1]);
    
    qusort(a,0,n-1);
}
int main(){
    int seq[11] = {3,1,4,1,5,9,2,6,5,3,5};
    int index;
        scanf("%d",&index);
    quicksort(seq, 11, 11,index);
}

/*
#include <stdio.h>
void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int median(int a[],int left,int right){
    int m = ( left + right ) / 2;
    if (a[left] >  a[m]) {
        swap(&a[left], &a[m]);
    }
    if (a[left] > a[right]) {
        swap(&a[left], &a[right]);
    }
    if (a[m] > a[right]) {
        swap(&a[m], &a[right]);
    }
    swap(&a[right - 1], &a[m]);

    return a[right - 1];
}

void insort(int a[],int left,int b){
    int i = left;
    int j;
    int temp;
    b = b + left;
    for (i = left; i < b; i++) {
        temp = a[i];
        for (j = i; a[j - 1] > temp && j > 0; j--) {
            swap(&a[j - 1], &a[j]);
        }
        swap(&temp, &a[j]);
    }
}
void qusort(int a[],int left, int right){
    int i,j;
    int pivot;
    if (left + 3 <= right) {
        pivot = median(a, left, right);
        i = left;
        j = right - 1;
        while (1) {
            while(a[++i] < pivot);
            while(a[--j] > pivot);
            if (i < j) {
                swap(&a[i], &a[j]);
            }
            else
                break;
        }
        swap(&a[i], &a[right - 1]);
        for (int i = 0; i < 10; i++) {
            printf("%d,",a[i]);
        }
        printf("\n");
        qusort(a , left, i - 1);

        qusort(a, i + 1, right);

    }
    else
        insort(a, left, right-left + 1);
    for (int i = 0; i < 10; i++) {
        printf("%d,",a[i]);
    }
     printf("\n");
}
int main(){
    int seq[10] = {49,38,65,97,76,13,27,50,2,8};
    qusort(seq, 0, 9);
   
}*/
