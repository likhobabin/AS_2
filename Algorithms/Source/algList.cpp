#include "algPrecompile.h"
#include "algShared.h"
#include "algList.h"
//

void tstList(void )
{
  list<int > list;
  //
  list.Add(3);
  list.Add(2);
  list.Add(1);
  list.Add(-5);
  list.Add(2);
  list.Add(1);
  list.Add(1);
  list.Add(6);
  list.Add(2);
  list.Add(5);
  list.Add(2);
  list.Add(1);
  //
  list.MergeSort<leftLessOrEqualRight<int> >();
  list.Reversed();
}