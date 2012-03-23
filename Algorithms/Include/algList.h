#ifndef __ALGLIST_H__
#define __ALGLIST_H__
//
void tstList(void );
//

template<class TData > class list
{
public:
  template<class TData > struct node
  {
    TData Data;
    node* Next;
    //
    node(TData __Data):
    Data(__Data),
      Next(0x0)
    {
    }
    //

    ~node(void )
    {
    }
    //
  };
  //
  typedef node<TData > TNode;
  //
  list(void ):
  FHead(0x0)
  {
  }
  //

  void Add(TData __InVal)
  {
    if(0x0 == FHead)
      FHead = new TNode(__InVal);
    else
    {
      TNode* traverse = FHead;
      //
      while(traverse->Next)
      {
        traverse = traverse->Next;
      }
      //
      traverse->Next = new TNode(__InVal);
    }
  }
  //

  unsigned int Quantity(void )
  {
    TNode* count=FHead;
    unsigned int quantity=0x0;
    //
    while(count)
    {
      count=count->Next;
      quantity++;
    }
    //
    return(quantity);
  }
  //

  void MergeSort()
  {
    TNode *p=0x0, *q=0x0, *i_input=0x0, *tail=0x0, *head=FHead;
    unsigned int k=1;
    unsigned int pSize=0;
    unsigned int qSize=0;
    unsigned int quant = Quantity();
    int out=0;
    //
    while(1)
    {
      p = head;
      q = p;
      head = 0x0;
      tail=0x0;
      out=0;
      //
      while(p)
      {
        out++;
        TNode* prev=0x0;
        for(unsigned int i=0; k>i && q; i++)
        {
          prev=q;
          if((q = q->Next))
            pSize++;
        }
        //
        if(!q)
          q=prev;
        //
        qSize = k;
        //
        if(quant <= (qSize+pSize))
          out=0;
        //
        while((pSize>0) || (q && qSize>0))
        {
          if(pSize==0 && q)
          {
            i_input = q; q=q->Next; qSize--;
          }
          else
            if(qSize==0 || !q)
            {
              i_input=p; p=p->Next; pSize--;
            }
            else
              if(p->Data <= q->Data)
              {
                i_input=p; p=p->Next; pSize--;
              }
              else
              {
                i_input=q; q=q->Next; qSize--;
              }
          //
          if(0x0 != tail)
          {
            tail->Next = i_input;
          }
          else
          {
            head = i_input;
          }
          //
          tail = i_input;
          tail->Next=0x0;
        }//[1]
        p=q;
      }//[2]
      //
      if(out <= 1)
        break;
      //
      k*=2;
    }//[3]
    FHead = head;
  }
  //

  void Reversed(void )
  {
    TNode* prev = FHead;
    TNode* curr = prev->Next;
    prev->Next = 0x0;
    //
    while(curr)
    {
      TNode* temp = curr->Next;
      curr->Next = prev;
      prev = curr;
      curr = temp;
    }
    //
    FHead = prev;
  }
  //

  void Destroy(void )
  {
    if(0x0 != FHead)
      doDestroy(FHead);
  }
  //

  ~list(void )
  {
    Destroy();
  }
  //

private:
  TNode* FHead;
  //

  void doDestroy(TNode*& __InNode)
  {
    if(__InNode->Next)
      doDestroy(__InNode->Next);
    //
    delete __InNode;
    __InNode = 0x0;
  }
  //
};
//
#endif//__ALGLIST_H__
