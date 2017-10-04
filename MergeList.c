#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;
List Read();
void Print(List L);
List Merge(List L1, List L2);
int main()
{
    List L1, L2,L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}
List Read()
{
    int n;
    List L0;
    L0 = (List)malloc(sizeof(struct Node));
    L0->Next = NULL;
    scanf("%d", &n);
    if (n)
    {
        List r = L0;
        List temp0;
        int i;
        for (i = 0; i<n; i++) {
            temp0 = (List)malloc(sizeof(struct Node));
            scanf("%d", &(temp0->Data));
            r->Next = temp0;
            r = temp0;
        }
        r->Next = NULL;
    }
    return L0;
}
void Print(List L)
{
    if (L->Next)
    {
        List tempp;
        tempp = L;
        while (tempp->Next)
        {
            tempp = tempp->Next;
            printf("%d ", tempp->Data);
        }
        printf("\n");
    }
    else
    {
        printf("NULL\n");
    }
}
List Merge( List L1, List L2 )
{
  List P;
  List Rear,sb1,sb2;
  PtrToNode t;
  P=(List)malloc(sizeof(struct Node));
  //P->Next=NULL;
  Rear=P;
  sb1=L1;
  sb2=L2;
  L1=L1->Next;
  L2=L2->Next;

  /*if(L1 == NULL)
  {
      return L2;
  }
  else if(L2 == NULL)
  {
      return L1;
  }*/
  while(L1 != NULL && L2 != NULL)
  {
    //PtrToNode t;

    if(L1->Data == L2->Data)
    {
      Rear->Next=(List)malloc(sizeof(struct Node));
      Rear->Next->Data=L1->Data;
      Rear->Next->Next=NULL;
      Rear=Rear->Next;
      Rear->Next=(List)malloc(sizeof(struct Node));
      Rear->Next->Data=L2->Data;
      Rear->Next->Next=NULL;
      Rear=Rear->Next;
      L1=L1->Next;
      L2=L2->Next;
    }
    else if(L1->Data < L2->Data)
    {
      Rear->Next=(List)malloc(sizeof(struct Node));
      Rear->Next->Data=L1->Data;
      Rear->Next->Next=NULL;
      Rear=Rear->Next;
      L1=L1->Next;
    }
    else if(L1->Data > L2->Data)
    {
      Rear->Next=(List)malloc(sizeof(struct Node));
      Rear->Next->Data=L2->Data;
      Rear->Next->Next=NULL;
      Rear=Rear->Next;
      L2=L2->Next;
    }
  }
  while(L1)
  {
    Rear->Next=(List)malloc(sizeof(struct Node));
    Rear->Next->Data=L1->Data;
    Rear->Next->Next=NULL;
    Rear=Rear->Next;
    L1=L1->Next;
  }
  while(L2)
  {
    Rear->Next=(List)malloc(sizeof(struct Node));
    Rear->Next->Data=L2->Data;
    Rear->Next->Next=NULL;
    Rear=Rear->Next;
    L2=L2->Next;
  }
  //t=P;
  //P=P->Next;
  //free(t);
  sb1->Next=NULL;
  sb2->Next=NULL;
  return P;
}
