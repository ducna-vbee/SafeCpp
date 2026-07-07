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
#include <functional>

/** Inclusion(s) of project's C++ header file(s).**/
#include "SafeContextBase.h"
#include "SafeContextException.h"


/** Main code.**/

/// <summary>
///		C++ namespace: `Safe`.
/// </summary>
namespace Safe
{
	/// <summary>
	///		C++ class template: `SafeFunction`.
	/// </summary>
	/// <typeparam name="GenericType"></typeparam>
	template<typename GenericType> class SafeFunction;

	/// <summary>
	///		C++ class template: `SafeFunction`.
	/// </summary>
	/// <typeparam name="GenericTypeOfReturn"></typeparam>
	/// <typeparam name="...GenericTypesOfArguments"></typeparam>
	template<typename GenericTypeOfReturn,typename ...GenericTypesOfArguments> class SafeFunction<GenericTypeOfReturn(GenericTypesOfArguments...)> final : public SafeContextBase
	{
	private:
		std::function<GenericTypeOfReturn(GenericTypesOfArguments...)> composedData;


		/// <summary>
		///		dynamic
		///     inline
		///		noexcept
		/// </summary>
		/// <returns>bool</returns>
		inline bool checkInvocability() const noexcept
		{
			return (this->composedData).operator bool();
		};

	public:
		/// <summary>
		///		Constructor of `SafeFunction`.
		/// </summary>
		inline explicit SafeFunction() : SafeContextBase()
		{
			this->composedData = std::function<GenericTypeOfReturn(GenericTypesOfArguments...)>();
		};

		/// <summary>
		///		Constructor of `SafeFunction`.
		/// </summary>
		/// <typeparam name="GenericTypeOfFunction"></typeparam>
		/// <param name="functionallyInvocable"></param>
		template<class GenericTypeOfFunction> inline SafeFunction(const GenericTypeOfFunction& functionallyInvocable) : SafeContextBase()
		{
			this->composedData = functionallyInvocable;
		};

		/// <summary>
		///		Constructor of `SafeFunction`.
		/// </summary>
		/// <param name="function"></param>
		inline SafeFunction(const std::function<GenericTypeOfReturn(GenericTypesOfArguments...)>& function) : SafeContextBase()
		{
			this->composedData = function;
		};

		/// <summary>
		///		Copy constructor of `SafeFunction`.
		/// </summary>
		/// <param name="other"></param>
		inline SafeFunction(const SafeFunction<GenericTypeOfReturn(GenericTypesOfArguments...)>& other) : SafeContextBase(static_cast<const SafeContextBase&>(other))
		{
			this->composedData = other.composedData;
		};

		/// <summary>
		///		Move constructor of `SafeFunction`.
		/// </summary>
		/// <typeparam name="GenericTypeOfFunction"></typeparam>
		/// <param name="functionallyInvocable"></param>
		template<class GenericTypeOfFunction> inline SafeFunction(GenericTypeOfFunction&& functionallyInvocable) : SafeContextBase()
		{
			this->composedData = static_cast<GenericTypeOfFunction&&>(functionallyInvocable);
		};

		/// <summary>
		///		Move constructor of `SafeFunction`.
		/// </summary>
		/// <param name="function"></param>
		inline SafeFunction(std::function<GenericTypeOfReturn(GenericTypesOfArguments...)>&& function) : SafeContextBase()
		{
			this->composedData = static_cast<std::function<GenericTypeOfReturn(GenericTypesOfArguments...)>&&>(function);
		};

		/// <summary>
		///		Move constructor of `SafeFunction`.
		/// </summary>
		/// <param name="other"></param>
		inline SafeFunction(SafeFunction<GenericTypeOfReturn(GenericTypesOfArguments...)>&& other) noexcept(false) : SafeContextBase(static_cast<SafeContextBase&&>(other))
		{
			this->composedData = static_cast<std::function<GenericTypeOfReturn(GenericTypesOfArguments...)>&&>(other.composedData);
		};

		/// <summary>
		///		Destructor of `SafeFunction`.
		/// </summary>
		inline virtual ~SafeFunction() noexcept(false) override = default;

		/// <summary>
		///		dynamic
		///		inline
		///		operator=
		/// </summary>
		/// <param name="other"></param>
		/// <returns>SafeFunction&lt;GenericTypeOfReturn,GenericTypesOfArguments...&gt;&amp;</returns>
		inline SafeFunction<GenericTypeOfReturn(GenericTypesOfArguments...)>& operator=(const SafeFunction<GenericTypeOfReturn(GenericTypesOfArguments...)>& other)
		{
			if (this != &other)
			{
				SafeContextBase::operator=(static_cast<const SafeContextBase&>(other));
				this->composedData = other.composedData;
			}

			return *this;
		};

		/// <summary>
		///		dynamic
		///		inline
		///		noexcept(false)
		///		operator=
		/// </summary>
		/// <param name="other"></param>
		/// <returns>SafeFunction&lt;GenericTypeOfReturn,GenericTypesOfArguments...&gt;&amp;</returns>
		inline SafeFunction<GenericTypeOfReturn(GenericTypesOfArguments...)>& operator=(SafeFunction<GenericTypeOfReturn(GenericTypesOfArguments...)>&& other) noexcept(false)
		{
			if (this != &static_cast<const SafeFunction<GenericTypeOfReturn(GenericTypesOfArguments...)>&>(other))
			{
				SafeContextBase::operator=(static_cast<SafeContextBase&&>(other));
				this->composedData = static_cast<std::function<GenericTypeOfReturn(GenericTypesOfArguments...)>&&>(other.composedData);
			}

			return *this;
		};

		/// <summary>
		///		dynamic
		///		inline
		///		operator()
		/// </summary>
		/// <param name="arguments"></param>
		/// <returns>GenericTypeOfReturn</returns>
		/// <exception cref="SafeContextException"/>
		inline GenericTypeOfReturn operator()(GenericTypesOfArguments... arguments) const
		{
			if (this->checkInvocability() == true)
			{
				return (this->composedData)(arguments...);
			}
			else
			{
				throw SafeContextException("The current instance of `SafeFunction` is not invocable!");
			}
		};

		/// <summary>
		///		dynamic
		///     inline
		///		noexcept
		/// </summary>
		/// <returns>bool</returns>
		inline bool isInvocable() const noexcept
		{
			return ((this->composedData).operator bool() == true);
		};
	};
};
