/// <summary>
///		Legal & Licensing Information
/// </summary>
/// <remarks>
///		Required Notice: Copyright © 2026, Nguyễn Anh Đức (workofduc@gmail.com). All Rights Reserved. [cite: 6, 7]
///		This software is licensed under the PolyForm Noncommercial License 1.0.0. [cite: 1]
/// 
///		PERMITTED USE:
///		Any noncommercial purpose is a permitted purpose. [cite: 9]
///		Personal use for research, hobby projects, or personal study is permitted. [cite: 9]
/// 
///		DISTRIBUTION:
///		Redistribution is permitted only under the terms of the PolyForm Noncommercial License. [cite: 3, 4, 5]
/// 
///		COMMERCIAL USE:
///		Commercial use is NOT permitted under these terms. 
///		To obtain a commercial license, please contact me via email: workofduc@gmail.com [cite: 23]
/// </remarks>

#pragma once

/** Inclusion(s) of C++ standard library header file(s).**/
#include <exception>
#include <functional>
#include <memory>
#include <string>
#include <vector>

/** Inclusion(s) of project's C++ header file(s).**/
#include "SafeNamespace.h"


/** Main code.**/

#define safe : public Safe::SafeContextBase

#if defined(WINDOWS) && defined(_MSC_VER)
#pragma unmanaged
#define WINDOWS_VISUAL_CPP
#endif

#if (defined(CPP_SAFE_DYNAMICALLY_LINKED_LIBRARY_EXPORT) || defined(CPP_SAFE_DYNAMICALLY_LINKED_LIBRARY_IMPORT)) && defined(WINDOWS_VISUAL_CPP)

class CPP_SAFE_LIBRARY_TRADE std::exception;
struct CPP_SAFE_LIBRARY_TRADE std::_Container_base12;
template class CPP_SAFE_LIBRARY_TRADE std::allocator<char>;
template struct CPP_SAFE_LIBRARY_TRADE std::char_traits<char>;
template struct CPP_SAFE_LIBRARY_TRADE std::_Simple_types<char>;
template struct CPP_SAFE_LIBRARY_TRADE std::_String_iter_types<char,unsigned long long int,ptrdiff_t,char*,const char>;
template union CPP_SAFE_LIBRARY_TRADE std::_String_val<std::_Simple_types<char>>::_Bxty;
template class CPP_SAFE_LIBRARY_TRADE std::_String_val<std::_Simple_types<char>>;
template class CPP_SAFE_LIBRARY_TRADE std::_Compressed_pair<std::allocator<char>,std::_String_val<std::_Simple_types<char>>,true>;
template class CPP_SAFE_LIBRARY_TRADE std::basic_string<char>;
template class CPP_SAFE_LIBRARY_TRADE std::basic_string<char,std::char_traits<char>,std::allocator<char>>;
template class CPP_SAFE_LIBRARY_TRADE std::allocator<unsigned char>;
template struct CPP_SAFE_LIBRARY_TRADE std::char_traits<unsigned char>;
template struct CPP_SAFE_LIBRARY_TRADE std::_Simple_types<unsigned char>;
template struct CPP_SAFE_LIBRARY_TRADE std::_String_iter_types<unsigned char,unsigned long long int,ptrdiff_t,unsigned char*,const unsigned char>;
template union CPP_SAFE_LIBRARY_TRADE std::_String_val<std::_Simple_types<unsigned char>>::_Bxty;
template class CPP_SAFE_LIBRARY_TRADE std::_String_val<std::_Simple_types<unsigned char>>;
template class CPP_SAFE_LIBRARY_TRADE std::_Compressed_pair<std::allocator<unsigned char>,std::_String_val<std::_Simple_types<unsigned char>>,true>;
template class CPP_SAFE_LIBRARY_TRADE std::basic_string<unsigned char>;
template class CPP_SAFE_LIBRARY_TRADE std::basic_string<unsigned char,std::char_traits<unsigned char>,std::allocator<unsigned char>>;
template class CPP_SAFE_LIBRARY_TRADE std::allocator<signed char>;
template struct CPP_SAFE_LIBRARY_TRADE std::char_traits<signed char>;
template struct CPP_SAFE_LIBRARY_TRADE std::_Simple_types<signed char>;
template struct CPP_SAFE_LIBRARY_TRADE std::_String_iter_types<signed char,unsigned long long int,ptrdiff_t,signed char*,const signed char>;
template union CPP_SAFE_LIBRARY_TRADE std::_String_val<std::_Simple_types<signed char>>::_Bxty;
template class CPP_SAFE_LIBRARY_TRADE std::_String_val<std::_Simple_types<signed char>>;
template class CPP_SAFE_LIBRARY_TRADE std::_Compressed_pair<std::allocator<signed char>,std::_String_val<std::_Simple_types<signed char>>,true>;
template class CPP_SAFE_LIBRARY_TRADE std::basic_string<signed char>;
template class CPP_SAFE_LIBRARY_TRADE std::basic_string<signed char,std::char_traits<signed char>,std::allocator<signed char>>;
template class CPP_SAFE_LIBRARY_TRADE std::allocator<char8_t>;
template struct CPP_SAFE_LIBRARY_TRADE std::char_traits<char8_t>;
template struct CPP_SAFE_LIBRARY_TRADE std::_Simple_types<char8_t>;
template struct CPP_SAFE_LIBRARY_TRADE std::_String_iter_types<char8_t,unsigned long long int,ptrdiff_t,char8_t*,const char8_t>;
template union CPP_SAFE_LIBRARY_TRADE std::_String_val<std::_Simple_types<char8_t>>::_Bxty;
template class CPP_SAFE_LIBRARY_TRADE std::_String_val<std::_Simple_types<char8_t>>;
template class CPP_SAFE_LIBRARY_TRADE std::_Compressed_pair<std::allocator<char8_t>,std::_String_val<std::_Simple_types<char8_t>>,true>;
template class CPP_SAFE_LIBRARY_TRADE std::basic_string<char8_t>;
template class CPP_SAFE_LIBRARY_TRADE std::basic_string<char8_t,std::char_traits<char8_t>,std::allocator<char8_t>>;
template class CPP_SAFE_LIBRARY_TRADE std::allocator<char16_t>;
template struct CPP_SAFE_LIBRARY_TRADE std::char_traits<char16_t>;
template struct CPP_SAFE_LIBRARY_TRADE std::_Simple_types<char16_t>;
template struct CPP_SAFE_LIBRARY_TRADE std::_String_iter_types<char16_t,unsigned long long int,ptrdiff_t,char16_t*,const char16_t>;
template union CPP_SAFE_LIBRARY_TRADE std::_String_val<std::_Simple_types<char16_t>>::_Bxty;
template class CPP_SAFE_LIBRARY_TRADE std::_String_val<std::_Simple_types<char16_t>>;
template class CPP_SAFE_LIBRARY_TRADE std::_Compressed_pair<std::allocator<char16_t>,std::_String_val<std::_Simple_types<char16_t>>,true>;
template class CPP_SAFE_LIBRARY_TRADE std::basic_string<char16_t>;
template class CPP_SAFE_LIBRARY_TRADE std::basic_string<char16_t,std::char_traits<char16_t>,std::allocator<char16_t>>;
template class CPP_SAFE_LIBRARY_TRADE std::allocator<char32_t>;
template struct CPP_SAFE_LIBRARY_TRADE std::char_traits<char32_t>;
template struct CPP_SAFE_LIBRARY_TRADE std::_Simple_types<char32_t>;
template struct CPP_SAFE_LIBRARY_TRADE std::_String_iter_types<char32_t,unsigned long long int,ptrdiff_t,char32_t*,const char32_t>;
template union CPP_SAFE_LIBRARY_TRADE std::_String_val<std::_Simple_types<char32_t>>::_Bxty;
template class CPP_SAFE_LIBRARY_TRADE std::_String_val<std::_Simple_types<char32_t>>;
template class CPP_SAFE_LIBRARY_TRADE std::_Compressed_pair<std::allocator<char32_t>,std::_String_val<std::_Simple_types<char32_t>>,true>;
template class CPP_SAFE_LIBRARY_TRADE std::basic_string<char32_t>;
template class CPP_SAFE_LIBRARY_TRADE std::basic_string<char32_t,std::char_traits<char32_t>,std::allocator<char32_t>>;
template class CPP_SAFE_LIBRARY_TRADE std::allocator<wchar_t>;
template struct CPP_SAFE_LIBRARY_TRADE std::char_traits<wchar_t>;
template struct CPP_SAFE_LIBRARY_TRADE std::_Simple_types<wchar_t>;
template struct CPP_SAFE_LIBRARY_TRADE std::_String_iter_types<wchar_t,unsigned long long int,ptrdiff_t,wchar_t*,const wchar_t>;
template union CPP_SAFE_LIBRARY_TRADE std::_String_val<std::_Simple_types<wchar_t>>::_Bxty;
template class CPP_SAFE_LIBRARY_TRADE std::_String_val<std::_Simple_types<wchar_t>>;
template class CPP_SAFE_LIBRARY_TRADE std::_Compressed_pair<std::allocator<wchar_t>,std::_String_val<std::_Simple_types<wchar_t>>,true>;
template class CPP_SAFE_LIBRARY_TRADE std::basic_string<wchar_t>;
template class CPP_SAFE_LIBRARY_TRADE std::basic_string<wchar_t,std::char_traits<wchar_t>,std::allocator<wchar_t>>;
template class CPP_SAFE_LIBRARY_TRADE std::allocator<void*>;
template struct CPP_SAFE_LIBRARY_TRADE std::_Simple_types<void*>;
template class CPP_SAFE_LIBRARY_TRADE std::_Vector_val<std::_Simple_types<void*>>;
template class CPP_SAFE_LIBRARY_TRADE std::_Compressed_pair<std::allocator<void*>,std::_Vector_val<std::_Simple_types<void*>>,true>;
template class CPP_SAFE_LIBRARY_TRADE std::vector<void*,std::allocator<void*>>;
template class CPP_SAFE_LIBRARY_TRADE std::allocator<const void*>;
template struct CPP_SAFE_LIBRARY_TRADE std::_Simple_types<const void*>;
template class CPP_SAFE_LIBRARY_TRADE std::_Vector_val<std::_Simple_types<const void*>>;
template class CPP_SAFE_LIBRARY_TRADE std::_Compressed_pair<std::allocator<const void*>,std::_Vector_val<std::_Simple_types<const void*>>,true>;
template class CPP_SAFE_LIBRARY_TRADE std::vector<const void*,std::allocator<const void*>>;
template class CPP_SAFE_LIBRARY_TRADE std::function<void()>;

#endif