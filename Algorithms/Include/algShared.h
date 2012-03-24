#ifndef __ALGSHARED__
#define __ALGSHARED__
//

#include <functional>
//

template<class TData> struct leftLessOrEqualRight : public std::binary_function<TData, TData, bool>
{
  bool operator()(const TData& __Left, const TData& __Right)
  {
    return(__Left <= __Right);
  }
};
//

template<class TData> struct leftMoreOrEqualRight : public std::binary_function<TData, TData, bool>
{
  bool operator()(const TData& __Left, const TData& __Right)
  {
    return(__Left >= __Right);
  }
};
//

#endif//__ALGSHARED__