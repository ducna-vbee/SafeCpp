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
