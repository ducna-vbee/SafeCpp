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

/** Inclusion(s) of C++ standard library header file(s).**/
#include <string>
#include <utility>

/** Inclusion(s) of project's C++ header file(s).**/
#include "SafeContextException.h"
#include "SafeContextBase.h"

/** Inclusion(s) of the standard C++ namespace(s).**/
using namespace std;


/** Main code.**/

namespace Safe
{
	SafeContextException::SafeContextException() : SafeContextBase()
	{
		this->message = "Exception thrown!";
	};
	SafeContextException::SafeContextException(const std::string& message) : SafeContextBase()
	{
		this->message = string(message);
	};
	SafeContextException::SafeContextException(const SafeContextException& other) : SafeContextBase(static_cast<const SafeContextBase&>(other))
	{
		this->message = string(other.message);
	};
	SafeContextException::SafeContextException(std::string&& message) : SafeContextBase()
	{
		this->message = move(message);
	};
	SafeContextException::SafeContextException(SafeContextException&& other) noexcept(false) : SafeContextBase(static_cast<SafeContextBase&&>(other))
	{
		this->message = move(other.message);
	};
	SafeContextException::~SafeContextException() noexcept = default;


	SafeContextException& SafeContextException::operator=(const SafeContextException& other)
	{
		SafeContextBase::operator=(static_cast<const SafeContextBase&>(other));
		this->message = string(other.message);

		return *this;
	};

	SafeContextException& SafeContextException::operator=(SafeContextException&& other) noexcept
	{
		SafeContextBase::operator=(static_cast<SafeContextBase&&>(other));
		this->message = move(other.message);

		return *this;
	};

	bool SafeContextException::operator==(const SafeContextException& other) const noexcept
	{
		return (this->message == other.message);
	};

	const char* SafeContextException::what() const noexcept
	{
		return (this->message).data();
	};

	string SafeContextException::getMessage() const
	{
		return string(this->message);
	};

	void SafeContextException::setMessage(const string& message)
	{
		this->message = string(message);
	};

	void SafeContextException::setMessage(string&& message) noexcept
	{
		this->message = move(message);
	};
};
