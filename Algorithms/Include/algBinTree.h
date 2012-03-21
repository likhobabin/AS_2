#ifndef __ALGTREE_H__
#define __ALGTREE_H__

template<class TNodeType> class binTree;
template<class TData > struct node;
//

template<class TData> class binTree
{
public:
  template<class TData> struct node
  {
    node* Left;
    node* Right;
    TData Val;
    //
    node(void ):
      Left(0x0),
      Right(0x0),
      Val( )
    {
    }
    //

    node(TData __Val):
      Left(0x0),
      Right(0x0),
      Val(__Val)
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
  
  binTree(void ):
  FRoot(0x0)
  {
  }
  //

  void Add(TData __InVal)
  {
    if(0x0 == FRoot)
      FRoot = new TNode(__InVal);
    else
    {
      TNode* temp = FRoot;
      //
      while(temp)
      {
        if(__InVal == temp->Val)
          return;
        //
        if(__InVal > temp->Val)
        {
          if(0x0 == temp->Right)
          {
            temp->Right = new TNode(__InVal);
            break;
          }
          else
            temp = temp->Right;
        }
        else
        {
          if(0x0 == temp->Left)
          {
            temp->Left = new TNode(__InVal);
            break;
          }
          else
            temp = temp->Left;
        }
      }
    }
  }
  //
  void TraverseMaxMin(void )
  {
    if(0x0 != FRoot)
      doTraverseMaxMin(FRoot);
  }
  //

  void Remove(TData __Val)
  {
    TNode* foundNode=NULL;
    TNode* parentNode=NULL;
    //
    if(Search(__Val, FRoot, foundNode, parentNode))
    {
      if(0x0 != foundNode->Right && 0x0 != foundNode->Left)
      {
        TNode* bindNode=NULL;
        //
        bindNode = theLeftBindNode(foundNode->Right);
        bindNode->Left = foundNode->Left;
        //
        if(__Val < parentNode->Val)
          parentNode->Left = foundNode->Right;
        else
          parentNode->Right = foundNode->Right;
      }
      else
        if(0x0 == foundNode->Right && 0x0 != foundNode->Left)
        {
          if(__Val < parentNode->Val)
            parentNode->Left = foundNode->Left;
          else
            parentNode->Right = foundNode->Left;
        }
        else
          if(0x0 != foundNode->Right &&  0x0 == foundNode->Left)
          {          
            if(__Val < parentNode->Val)
              parentNode->Left = foundNode->Right;
            else
              parentNode->Right = foundNode->Right;
          }
          else
            if(0x0 == foundNode->Right &&  0x0 == foundNode->Left)
            {          
              if(__Val < parentNode->Val)
                parentNode->Left = NULL;
              else
                parentNode->Right = NULL;
            }
      //
      delete foundNode;
      foundNode=0x0;
    }
  }
  void Destroy(void )
  {
    if(0x0 != FRoot)
      doDestroy(FRoot);
  }
  //

  ~binTree(void )
  {
    Destroy();
  }

private:
  TNode* FRoot;
  //

  void doDestroy(TNode* __InNode)
  { 
    if(__InNode->Right)
      doDestroy(__InNode->Right);
    //
    if(__InNode->Left)
      doDestroy(__InNode->Left);
    //
    delete __InNode;
    __InNode=0x0;
  }

  void doTraverseMaxMin(TNode* __InNode)
  {
    if(__InNode->Right)
      doTraverseMaxMin(__InNode->Right);
    //
    std::cout<<__InNode->Val<<"\n";
    //
    if(__InNode->Left)
      doTraverseMaxMin(__InNode->Left);
  }
  //

  bool Search(TData __InVal, TNode* __InNode, TNode*& __OutNode, TNode*& __ParentOfOutNode)
  {
    static bool bFound=false;
    //
    if(__InVal > __InNode->Val && __InNode->Right)
    {
      __ParentOfOutNode = __InNode;
      Search(__InVal, __InNode->Right, __OutNode, __ParentOfOutNode);
    }
    else
      if(__InVal < __InNode->Val && __InNode->Left)
      {
        __ParentOfOutNode = __InNode;
        Search(__InVal, __InNode->Left, __OutNode, __ParentOfOutNode);
      }
      else
      {
        __OutNode = __InNode;
        return(bFound=true);
      }
   //
   return(bFound);
  }
  //
  TNode* theLeftBindNode(TNode* __InNode)
  {
    static TNode* bindNode=NULL;
    //
    bindNode = __InNode;
    if(__InNode->Left)
      theLeftBindNode(__InNode->Left);
    //
    return(bindNode);
  }
};

#endif