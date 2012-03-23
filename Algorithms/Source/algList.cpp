#include "algPrecompile.h"
#include "algList.h"
//

void tstList(void )
{
  list<int > list;
  //
  list.Add(5);
  list.Add(6);
  list.Add(5);
  list.Add(-5);
  list.Add(2);
  list.Add(1);
  list.Add(1);
  list.Add(6);
  list.Add(2);
  list.Add(5);
  list.Add(2);
  list.Add(1);
  //list.Add(-9);
  //list.Add(0);
  //list.Add(3);
  //list.Add(5);
  //
  list.MergeSort();
  list.Reversed();
}