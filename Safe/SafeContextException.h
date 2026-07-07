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

/** Inclusion(s) of C++ standard library header file(s).**/
#include <exception>
#include <string>

/** Inclusion(s) of project's C++ header file(s).**/
#include "SafeContextBase.h"
#include "SafeNamespace.h"
#include "SafeTrade.h"


/** Main code.**/

/// <summary>
///		C++ namespace: `Safe`.
/// </summary>
namespace Safe
{
	/// <summary>
	///		C++ class: `SafeContextException`.
	/// </summary>
	class SafeContextException final : public std::exception,public SafeContextBase
	{
	private:
		std::string message;

	public:
		/// <summary>
		///		Constructor of `SafeContextException`.
		/// </summary>
		explicit SafeContextException();

		/// <summary>
		///		Constructor of `SafeContextException`.
		/// </summary>
		/// <param name="message"></param>
		explicit SafeContextException(const std::string& message);

		/// <summary>
		///		Copy constructor of `SafeContextException`.
		/// </summary>
		/// <param name="other"></param>
		SafeContextException(const SafeContextException& other);

		/// <summary>
		///		Move constructor of `SafeContextException`.
		/// </summary>
		/// <param name="message"></param>
		explicit SafeContextException(std::string&& message);

		/// <summary>
		///		Move constructor of `SafeContextException`.
		/// </summary>
		/// <param name="other"></param>
		SafeContextException(SafeContextException&& other) noexcept(false);

		/// <summary>
		///		Destructor of `SafeContextException`.
		/// </summary>
		virtual ~SafeContextException() noexcept override;

		/// <summary>
		///		dynamic
		///		operator=
		/// </summary>
		/// <param name="other"></param>
		/// <returns>SafeContextException&amp;</returns>
		SafeContextException& operator=(const SafeContextException& other);

		/// <summary>
		///		dynamic
		///		noexcept
		///		operator=
		/// </summary>
		/// <param name="other"></param>
		/// <returns>SafeContextException&amp;</returns>
		SafeContextException& operator=(SafeContextException&& other) noexcept;

		/// <summary>
		///		dynamic
		///		noexcept
		///		operator==
		/// </summary>
		/// <param name="other"></param>
		/// <returns>bool</returns>
		bool operator==(const SafeContextException& other) const noexcept;

		/// <summary>
		///		dynamic
		///		noexcept
		///		override
		/// </summary>
		/// <returns>char*</returns>
		const char* what() const noexcept override;

		/// <summary>
		///		dynamic
		/// </summary>
		/// <returns>string</returns>
		std::string getMessage() const;

		/// <summary>
		///		dynamic
		/// </summary>
		/// <param name="message"></param>
		/// <returns>void</returns>
		void setMessage(const std::string& message);

		/// <summary>
		///		dynamic
		///		noexcept
		/// </summary>
		/// <param name="message"></param>
		/// <returns>void</returns>
		void setMessage(std::string&& message) noexcept;
	};
};
