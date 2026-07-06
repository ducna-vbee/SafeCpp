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
#include <string>
#include <string_view>

/** Inclusion(s) of project's C++ header file(s).**/
#include "SafeContextBase.h"


/** Main code.**/

/// <summary>
///		C++ namespace: `Safe`.
/// </summary>
namespace Safe
{
	/// <summary>
	///		C++ class template: `SafeString`.
	/// </summary>
	/// <typeparam name="GenericTypeOfCharacter"></typeparam>
	template<typename GenericTypeOfCharacter> class SafeString final : public SafeContextBase
	{
	public:
		/// <summary>
		///		C++ class: `SafeStringBuilder`.
		/// </summary>
		class SafeStringBuilder final : public SafeContextBase
		{
		private:
			std::basic_string<GenericTypeOfCharacter> composedData;

		public:
			/// <summary>
			///		Constructor of `SafeStringBuilder`.
			/// </summary>
			explicit SafeStringBuilder();

			/// <summary>
			///		Constructor of `SafeStringBuilder`.
			/// </summary>
			/// <param name="primitiveString"></param>
			explicit SafeStringBuilder(const std::basic_string<GenericTypeOfCharacter>& primitiveString);

			/// <summary>
			///		Constructor of `SafeStringBuilder`.
			/// </summary>
			/// <param name="string"></param>
			explicit SafeStringBuilder(const SafeString<GenericTypeOfCharacter>& string);

			/// <summary>
			///		Copy constructor of `SafeStringBuilder`.
			/// </summary>
			/// <param name="other"></param>
			SafeStringBuilder(const SafeStringBuilder& other);

			/// <summary>
			///		Move constructor of `SafeStringBuilder`.
			/// </summary>
			/// <param name="primitiveString"></param>
			explicit SafeStringBuilder(std::basic_string<GenericTypeOfCharacter>&& primitiveString);

			/// <summary>
			///		Move constructor of `SafeStringBuilder`.
			/// </summary>
			/// <param name="other"></param>
			SafeStringBuilder(SafeStringBuilder&& other) noexcept;

			/// <summary>
			///		Destructor of `SafeStringBuilder`.
			/// </summary>
			virtual ~SafeStringBuilder() noexcept(false);

			/// <summary>
			///		dynamic
			///		operator=
			/// </summary>
			/// <param name="other"></param>
			/// <returns>SafeStringBuilder&amp;</returns>
			SafeStringBuilder& operator=(const SafeStringBuilder& other);

			/// <summary>
			///		dynamic
			///		noexcept
			///		operator=
			/// </summary>
			/// <param name="other"></param>
			/// <returns>SafeStringBuilder&amp;</returns>
			SafeStringBuilder& operator=(SafeStringBuilder&& other) noexcept;

			/// <summary>
			///		dynamic
			///		noexcept
			///		operator==
			/// </summary>
			/// <param name="other"></param>
			/// <returns>bool</returns>
			bool operator==(const SafeStringBuilder& other) const noexcept;

			/// <summary>
			///		dynamic
			///		operator[]
			/// </summary>
			/// <param name="index"></param>
			/// <returns>GenericTypeOfCharacter&amp;</returns>
			GenericTypeOfCharacter& operator[](const std::size_t& index);

			/// <summary>
			///		dynamic
			///		noexcept
			/// </summary>
			/// <returns>size_t</returns>
			std::size_t getLength() const noexcept;

			/// <summary>
			///		dynamic
			/// </summary>
			/// <param name="primitiveDataPointer"></param>
			/// <returns>void</returns>
			void append(const GenericTypeOfCharacter* const primitiveDataPointer);

			/// <summary>
			///		dynamic
			/// </summary>
			/// <param name="primitiveData"></param>
			/// <returns>void</returns>
			void append(const std::basic_string<GenericTypeOfCharacter>& primitiveData);

			/// <summary>
			///		dynamic
			/// </summary>
			/// <param name="character"></param>
			/// <returns>void</returns>
			void append(const GenericTypeOfCharacter character);

			/// <summary>
			///		dynamic
			/// </summary>
			/// <param name="index"></param>
			/// <param name="character"></param>
			/// <returns>void</returns>
			void insert(const std::size_t& index,const GenericTypeOfCharacter character);

			/// <summary>
			///		dynamic
			/// </summary>
			/// <param name="index"></param>
			/// <param name="dataPointer"></param>
			/// <returns>void</returns>
			void insert(const std::size_t& index,const GenericTypeOfCharacter* const dataPointer);

			/// <summary>
			///		dynamic
			/// </summary>
			/// <param name="index"></param>
			/// <param name="data"></param>
			/// <returns>void</returns>
			void insert(const std::size_t& index,const std::basic_string<GenericTypeOfCharacter>& data);

			/// <summary>
			///		dynamic
			/// </summary>
			/// <param name="index"></param>
			/// <param name="count"></param>
			/// <returns>void</returns>
			void remove(const std::size_t& index,const std::size_t& count);

			/// <summary>
			///		dynamic
			/// </summary>
			/// <param name="dataPointer"></param>
			/// <returns>void</returns>
			void remove(const GenericTypeOfCharacter* const dataPointer);

			/// <summary>
			///		dynamic
			/// </summary>
			/// <param name="data"></param>
			/// <returns>void</returns>
			void remove(const std::basic_string<GenericTypeOfCharacter>& data);

			/// <summary>
			///		dynamic
			/// </summary>
			/// <param name="data"></param>
			/// <returns>void</returns>
			void remove(const SafeString<GenericTypeOfCharacter>& data);

			/// <summary>
			///		dynamic
			/// </summary>
			/// <param name="position"></param>
			/// <param name="count"></param>
			/// <param name="data"></param>
			/// <returns>void</returns>
			void replace(const std::size_t& position,const std::size_t& count,const std::basic_string<GenericTypeOfCharacter>& data);

			/// <summary>
			///		dynamic
			///		noexcept
			/// </summary>
			/// <returns>void</returns>
			void clear() noexcept;

			/// <summary>
			///		dynamic
			/// </summary>
			/// <param name="cardinality"></param>
			/// <returns>void</returns>
			void reserve(const std::size_t& cardinality);

			/// <summary>
			///		dynamic
			///		noexcept
			/// </summary>
			/// <returns>SafeString&lt;GenericTypeOfCharacter&gt;</returns>
			SafeString<GenericTypeOfCharacter> toString() noexcept;
		};

	private:
		GenericTypeOfCharacter* composedDataPointer;
		std::size_t length;


		/// <summary>
		///		static
		/// </summary>
		/// <param name="index"></param>
		/// <returns>void</returns>
		/// <exception cref="SafeContextException"/>
		[[noreturn]] static void throwOutOfBoundException(const std::size_t& index) noexcept(false);

	public:
		/// <summary>
		///		Constructor of `SafeString`.
		/// </summary>
		explicit SafeString();

		/// <summary>
		///		Constructor of `SafeString`.
		/// </summary>
		/// <param name="characterPointer"></param>
		SafeString(const GenericTypeOfCharacter* const characterPointer);

		/// <summary>
		///		Constructor of `SafeString`.
		/// </summary>
		/// <param name="characterPointer"></param>
		/// <param name="length"></param>
		SafeString(const GenericTypeOfCharacter* const characterPointer,const std::size_t& length);

		/// <summary>
		///		Constructor of `SafeString`.
		/// </summary>
		/// <param name="primitiveString"></param>
		SafeString(const std::basic_string<GenericTypeOfCharacter>& primitiveString);

		/// <summary>
		///		Copy constructor of `SafeString`.
		/// </summary>
		/// <param name="other"></param>
		SafeString(const SafeString<GenericTypeOfCharacter>& other);

		/// <summary>
		///		Move constructor of `SafeString`.
		/// </summary>
		/// <param name="primitiveString"></param>
		SafeString(std::basic_string<GenericTypeOfCharacter>&& primitiveString);

		/// <summary>
		///		Move constructor of `SafeString`.
		/// </summary>
		/// <param name="other"></param>
		SafeString(SafeString<GenericTypeOfCharacter>&& other) noexcept;

		/// <summary>
		///		Destructor of `SafeString`.
		/// </summary>
		virtual ~SafeString() noexcept(false);

		/// <summary>
		///		dynamic
		///		operator=
		/// </summary>
		/// <param name="other"></param>
		/// <returns>SafeString&lt;GenericTypeOfCharacter&gt;&amp;</returns>
		SafeString<GenericTypeOfCharacter>& operator=(const SafeString<GenericTypeOfCharacter>& other);

		/// <summary>
		///		dynamic
		///		noexcept
		///		operator=
		/// </summary>
		/// <param name="other"></param>
		/// <returns>SafeString&lt;GenericTypeOfCharacter&gt;&amp;</returns>
		SafeString<GenericTypeOfCharacter>& operator=(SafeString<GenericTypeOfCharacter>&& other) noexcept;

		/// <summary>
		///		dynamic
		///		noexcept
		///		operator==
		/// </summary>
		/// <param name="data"></param>
		/// <returns>bool</returns>
		bool operator==(const std::basic_string<GenericTypeOfCharacter>& data) const noexcept;

		/// <summary>
		///		dynamic
		///		noexcept
		///		operator==
		/// </summary>
		/// <param name="dataView"></param>
		/// <returns>bool</returns>
		bool operator==(const std::basic_string_view<GenericTypeOfCharacter>& dataView) const noexcept;

		/// <summary>
		///		dynamic
		///		noexcept
		///		operator==
		/// </summary>
		/// <param name="other"></param>
		/// <returns>bool</returns>
		bool operator==(const SafeString<GenericTypeOfCharacter>& other) const noexcept;

		/// <summary>
		///		dynamic
		///		operator+
		/// </summary>
		/// <param name="other"></param>
		/// <returns>SafeString&lt;GenericTypeOfCharacter&gt;</returns>
		SafeString<GenericTypeOfCharacter>& operator+(const SafeString<GenericTypeOfCharacter>& other);

		/// <summary>
		///		dynamic
		///		operator-
		/// </summary>
		/// <param name="other"></param>
		/// <returns>SafeString&lt;GenericTypeOfCharacter&gt;</returns>
		/// <exception cref="SafeContextException"/>
		SafeString<GenericTypeOfCharacter>& operator-(const SafeString<GenericTypeOfCharacter>& other);

		/// <summary>
		///		dynamic
		///		operator[]
		/// </summary>
		/// <param name="index"></param>
		/// <returns>GenericTypeOfCharacter</returns>
		/// <exception cref="SafeContextException"/>
		const GenericTypeOfCharacter operator[](const std::size_t& index) const;

		/// <summary>
		///		dynamic
		/// </summary>
		/// <returns>size_t</returns>
		std::size_t getLength() const noexcept;

		/// <summary>
		///		dynamic
		/// </summary>
		/// <param name="index"></param>
		/// <returns>GenericTypeOfCharacter</returns>
		GenericTypeOfCharacter at(const std::size_t& index) const;

		/// <summary>
		///		dynamic
		/// </summary>
		/// <param name="other"></param>
		/// <returns>bool</returns>
		bool contains(const SafeString<GenericTypeOfCharacter>& other) const;

		/// <summary>
		///		dynamic
		/// </summary>
		/// <param name="startingIndex"></param>
		/// <param name="length"></param>
		/// <param name="data"></param>
		/// <returns>bool</returns>
		bool compareSubstring(const std::size_t& startingIndex,const std::size_t& length,const std::basic_string<GenericTypeOfCharacter>& data) const;

		/// <summary>
		///		dynamic
		/// </summary>
		/// <param name="startingIndex"></param>
		/// <param name="length"></param>
		/// <param name="dataView"></param>
		/// <returns>bool</returns>
		bool compareSubstring(const std::size_t& startingIndex,const std::size_t& length,const std::basic_string_view<GenericTypeOfCharacter>& dataView) const;

		/// <summary>
		///		dynamic
		/// </summary>
		/// <param name="startingIndex"></param>
		/// <param name="length"></param>
		/// <param name="other"></param>
		/// <returns>bool</returns>
		bool compareSubstring(const std::size_t& startingIndex,const std::size_t& length,const SafeString<GenericTypeOfCharacter>& other) const;

		/// <summary>
		///		dynamic
		/// </summary>
		/// <param name="startingIndex"></param>
		/// <param name="count"></param>
		/// <returns>SafeString&lt;GenericTypeOfCharacter&gt;</returns>
		/// <exception cref="SafeContextException"/>
		SafeString<GenericTypeOfCharacter> substr(const std::size_t& startingIndex,const std::size_t& count) const;

		/// <summary>
		///		dynamic
		///		noexcept
		/// </summary>
		/// <param name="character"></param>
		/// <returns>size_t</returns>
		std::size_t getFirstIndexOfCharacter(const GenericTypeOfCharacter character) const noexcept;

		/// <summary>
		///		dynamic
		///		noexcept
		/// </summary>
		/// <param name="character"></param>
		/// <returns>size_t</returns>
		std::size_t getLastIndexOfCharacter(const GenericTypeOfCharacter character) const noexcept;

		/// <summary>
		///		dynamic
		///		noexcept
		/// </summary>
		/// <param name="other"></param>
		/// <returns>size_t</returns>
		std::size_t findFirst(const SafeString<GenericTypeOfCharacter>& other) const noexcept;

		/// <summary>
		///		dynamic
		///		noexcept
		/// </summary>
		/// <param name="other"></param>
		/// <returns>size_t</returns>
		std::size_t findLast(const SafeString<GenericTypeOfCharacter>& other) const noexcept;

		/// <summary>
		///		dynamic
		/// </summary>
		/// <returns>basic_string&lt;GenericTypeOfCharacter&gt;</returns>
		std::basic_string<GenericTypeOfCharacter> obtainPrimitiveString() const;

		/// <summary>
		///		dynamic
		/// </summary>
		/// <returns>basic_string_view&lt;GenericTypeOfCharacter&gt;</returns>
		std::basic_string_view<GenericTypeOfCharacter> obtainPrimitiveStringView() const noexcept;
	};

	///	<summary>
	/// 	C++ type name alias: `SafeStringBuilder`.
	/// </summary>
	///	<typeparam name="GenericTypeOfCharacter"></typeparam>
	template<typename GenericTypeOfCharacter> using SafeStringBuilder = SafeString<GenericTypeOfCharacter>::SafeStringBuilder;
};
