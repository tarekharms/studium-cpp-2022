// Author: Carsten Link
//  println.hpp




#ifndef println_hpp
#define println_hpp

/*
 based on: http://stackoverflow.com/questions/16084379/system-out-println-function-syntax-in-c/16085135#16085135
 initial Author: http://stackoverflow.com/users/264338/mkaes
 */

#include <iostream>
#include <iomanip>
#include <sstream>
//using namespace std;




//namespace {


//template<typename T>


// from: https://stackoverflow.com/questions/16605967/set-precision-of-stdto-string-when-converting-floating-point-values
template <typename T>
//std::string to_string_with_precision(const T a_value, const int n = 18)
std::string to_string_with_precision(const T & a_value)
{
  std::ostringstream out;
  if (   a_value  > 999999.9
      || a_value  < -999999.9
      || (a_value < 0.001 && a_value > 0.0)
      || (a_value >-0.001 && a_value < 0.0)
      ) {
    out << std::scientific;
  }else{
    out << std::defaultfloat;
  }
  out
  // << std::setprecision(n)
  // << std::setprecision(std::numeric_limits< double >::max_digits10 + 1)
  //<< std::setw(24)
  //<< std::defaultfloat
  //<< std::scientific
  //<< std::fixed
  << a_value  ;
  return out.str();
}


#ifdef H_PRETTY_PRINT
//see: http://louisdx.github.io/cxx-prettyprint/
//see: https://github.com/louisdx/cxx-prettyprint
//see: https://devblogs.microsoft.com/oldnewthing/20190619-00/?p=102599

template <typename T>
//inline std::string as_string(T  t){
inline
typename std::enable_if<!::pretty_print::is_container<T>::value, std::string>::type
as_string(T  t){
  using namespace std;
  return to_string_with_precision(t);
  //return to_string(t);
}

template <typename T>
inline
typename std::enable_if<::pretty_print::is_container<T>::value, std::string>::type
as_string(T  t){
  /*std::ostringstream out;
  out << t;
  return out.str();*/
  std::string result;
  result += "[ ";
  for ( typename T::value_type e : t) {
    result += as_string(e);
    result += ", ";
  }
  result += " ]";
  return result;
}
#else

template <typename T>
inline std::string as_string(T  t){
  using namespace std;
  //return to_string_with_precision(t);
  return to_string(t);
}

#endif


template <>
inline std::string as_string<unsigned int>(unsigned int i){
  return std::string("\033[4m") + to_string_with_precision(i) + std::string("\033[0m");
}

template <>
inline std::string as_string<signed long long int>(signed long long int i){
  std::string retval = std::string("\033[4m");
  if(i>=0){
    retval += '+';
  }
  retval += to_string_with_precision(i) + std::string("\033[0m");
  return  retval ;
}

template <>
inline std::string as_string<signed int>(signed int i){
  std::string retval = std::string("\033[4m");
  if(i>=0){
    retval += '+';
  }
  retval += to_string_with_precision(i) + std::string("\033[0m");
  return  retval ;
}


template <>
inline std::string as_string<bool>(bool b){
  return std::string("\033[4m") + std::string(b?"true":"false") + std::string("\033[0m");
}


template <>
inline std::string as_string<char>(char c){
  return std::string("\033[3m") + std::string(1,c) + std::string("\033[0m"); // 1m,3m are great
}

template <>
inline std::string as_string<unsigned char>(unsigned char c){
  return as_string(static_cast<unsigned int>(c));
}

template <>
inline std::string as_string<signed char>(signed char c){
  return as_string(static_cast<signed int>(c));
}

template <>
inline std::string as_string<double>(double d){
  return std::string("\033[4m") + to_string_with_precision(d) + std::string("\033[0m");
}

template <>
inline std::string as_string<const char *>(const char * s){
  return std::string(s);
}

template <>
inline std::string as_string<char *>(char * s){
  return std::string(s);
}

template <>
inline std::string as_string<std::string>(std::string s){
  return s;
}
//}


inline void println()
{
  std::cout << std::endl;
}

template <typename T>
inline void println(T t)
{
  std::cout << as_string(t) << std::endl;
}

template <typename T, typename ...U>
inline void println(T t, U ...u)
{
  std::cout << as_string(t);
  println(u...);
}

template <typename T>
inline void print(T t)
{
  std::cout << as_string(t);
}

template <typename T, typename ...U>
inline void print(T t, U ...u)
{
  std::cout << as_string(t);
  print(u...);
}



#endif /* println_hpp */
