/// <summary>
///		Legal & Licensing Information
/// </summary>
/// <remarks>
///		Required Notice: Copyright©2026, Nguyễn Anh Đức (workofduc@gmail.com). All Rights Reserved.
///
///		DUAL-LICENSING MODEL:
///		This software is dual-licensed to accommodate both open-source development and proprietary commercial use.
///
///		OPEN-SOURCE TRACK (GPLv3):
///		This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
///
///		COMMERCIAL TRACK:
///		For commercial entities wishing to embed this software into proprietary, closed-source software, a separate commercial license is required. This grants the legal right to use the library without being bound by the GPLv3 copyleft requirements.
///
///		CONTACT:
///		For commercial licensing inquiries, pricing, or to obtain a proprietary license agreement, please contact: workofduc@gmail.com
/// </remarks>

#pragma once


/** Main code.**/

#if defined(_WIN32) || defined(_WIN64)
#define WINDOWS
#elif defined(__APPLE__) || defined(__linux__) || defined(__unix__)
#define UNIX
#else
#define OTHER_OS
#endif

#ifdef WINDOWS
#ifdef CPP_SAFE_DYNAMICALLY_LINKED_LIBRARY_EXPORT
#define CPP_SAFE_LIBRARY_TRADE __declspec(dllexport)
#else
#ifdef CPP_SAFE_DYNAMICALLY_LINKED_LIBRARY_IMPORT
#define CPP_SAFE_LIBRARY_TRADE __declspec(dllimport)
#else
#ifdef CPP_SAFE_STATICALLY_LINKED_LIBRARY_EXPORT
#define CPP_SAFE_LIBRARY_TRADE
#else
#ifdef CPP_SAFE_STATICALLY_LINKED_LIBRARY_IMPORT
#define CPP_SAFE_LIBRARY_TRADE
#endif
#endif
#endif
#endif
#else
#define CPP_SAFE_LIBRARY_TRADE
#endif


/// <summary>
///		C++ namespace: `Safe`.
/// </summary>
namespace Safe
{
	class CPP_SAFE_LIBRARY_TRADE SafeContextBase;
	class CPP_SAFE_LIBRARY_TRADE SafeContextException;
	class CPP_SAFE_LIBRARY_TRADE SafeEvent;
};