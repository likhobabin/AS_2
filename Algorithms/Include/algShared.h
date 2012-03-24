#ifndef __ALGSHARED__
#define __ALGSHARED__
//

#include <functional>
//

template<class TComp> struct leftLessOrEqualRight : public std::binary_function<TComp, TComp, bool>
{
  bool operator()(const TComp& __Left, const TComp& __Right)
  {
    return(__Left <= __Right);
  }
};
//

template<class TComp> struct leftMoreOrEqualRight : public std::binary_function<TComp, TComp, bool>
{
  bool operator()(const TComp& __Left, const TComp& __Right)
  {
    return(__Left >= __Right);
  }
};
//

#endif//__ALGSHARED__