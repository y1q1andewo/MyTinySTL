// 防止重复包含
#ifndef MYTINYSTL_TYPE_TRAITS_H_
#define MYTINYSTL_TYPE_TRAITS_H_

// 这个头文件用于提取类型信息

// 标准库，它提供了许多类型特征(trait)和类型变换(transform)的工具，能够帮助程序员在编写模板代码时对类型进行更准确的判断和转换。
// 该头文件中包含的模板类和模板函数都基于编译期静态分析，它们在编译时计算并产生结果，而不是在运行时。这些类型特征和类型变换的工具可用于泛型编程中，可以实现更加通用的代码。
#include <type_traits>

// 使用命名空间防止冲突
namespace mystl
{

// helper struct

template <class T, T v>
struct m_integral_constant
{
  static constexpr T value = v;
};

template <bool b>
using m_bool_constant = m_integral_constant<bool, b>;

typedef m_bool_constant<true>  m_true_type;
typedef m_bool_constant<false> m_false_type;

/*****************************************************************************************/
// type traits

// is_pair

// --- forward declaration begin
template <class T1, class T2>
struct pair;
// --- forward declaration end

template <class T>
struct is_pair : mystl::m_false_type {};

template <class T1, class T2>
struct is_pair<mystl::pair<T1, T2>> : mystl::m_true_type {};

} // namespace mystl

#endif // !MYTINYSTL_TYPE_TRAITS_H_

