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
      Next(NULL)
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
  FHead(NULL)
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
