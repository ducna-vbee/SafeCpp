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
#include <cstring>
#include <string>
#include <string_view>

/** Inclusion(s) of project's C++ header file(s).**/
#include "SafeContextBase.h"
#include "SafeContextException.h"
#include "SafeString.h"

/** Inclusion(s) of the standard C++ namespace(s).**/
using namespace std;


/** Main code.**/

namespace Safe
{
	template<typename GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter>::SafeStringBuilder::SafeStringBuilder() : SafeContextBase()
	{
		this->composedData = basic_string<GenericTypeOfCharacter>();
	};
	template<typename GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter>::SafeStringBuilder::SafeStringBuilder(const basic_string<GenericTypeOfCharacter>& primitiveString) : SafeContextBase()
	{
		this->composedData = basic_string<GenericTypeOfCharacter>(primitiveString);
	};
	template<typename GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter>::SafeStringBuilder::SafeStringBuilder(const SafeString<GenericTypeOfCharacter>& string) : SafeContextBase()
	{
		this->composedData = basic_string<GenericTypeOfCharacter>(string.obtainPrimitiveString());
	};
	template<typename GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter>::SafeStringBuilder::SafeStringBuilder(const SafeStringBuilder& other) : SafeContextBase(static_cast<const SafeContextBase&>(other))
	{
		this->composedData = basic_string<GenericTypeOfCharacter>(other.composedData);
	};
	template<typename GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter>::SafeStringBuilder::SafeStringBuilder(basic_string<GenericTypeOfCharacter>&& primitiveString) : SafeContextBase()
	{
		this->composedData = static_cast<basic_string<GenericTypeOfCharacter>&&>(primitiveString);
	};
	template<typename GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter>::SafeStringBuilder::SafeStringBuilder(SafeStringBuilder&& other) noexcept : SafeContextBase(static_cast<SafeContextBase&&>(other))
	{
		this->composedData = static_cast<basic_string<GenericTypeOfCharacter>&&>(other.composedData);
	};
	template<typename GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter>::SafeStringBuilder::~SafeStringBuilder() noexcept(false) = default;


	template<typename GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter>::SafeString() : SafeContextBase()
	{
		this->length = 0;
		this->composedDataPointer = nullptr;
	};
	template<typename GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter>::SafeString(const GenericTypeOfCharacter* const characterPointer)
	{
		this->length = basic_string_view<GenericTypeOfCharacter>(characterPointer).length();
		this->composedDataPointer = new GenericTypeOfCharacter[this->length];
		std::memcpy(this->composedDataPointer,characterPointer,this->length);
	};
	template<typename GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter>::SafeString(const GenericTypeOfCharacter* const characterPointer,const size_t& length) : SafeContextBase()
	{
		this->length = length;
		this->composedDataPointer = new GenericTypeOfCharacter[this->length];
		std::memcpy(this->composedDataPointer,characterPointer,this->length);
	};
	template<typename GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter>::SafeString(const basic_string<GenericTypeOfCharacter>& primitiveString) : SafeContextBase()
	{
		this->length = primitiveString.length();
		this->composedDataPointer = new GenericTypeOfCharacter[this->length];
		std::memcpy(this->composedDataPointer,primitiveString.data(),this->length);
	};
	template<typename GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter>::SafeString(const SafeString<GenericTypeOfCharacter>& other) : SafeContextBase(static_cast<const SafeContextBase&>(other))
	{
		this->length = other.length;
		this->composedDataPointer = other.composedDataPointer;
	};
	template<typename GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter>::SafeString(basic_string<GenericTypeOfCharacter>&& primitiveString) : SafeContextBase()
	{
		this->length = primitiveString.length();
		this->composedDataPointer = primitiveString.data();
	};
	template<typename GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter>::SafeString(SafeString<GenericTypeOfCharacter>&& other) noexcept : SafeContextBase(static_cast<SafeContextBase&&>(other))
	{
		this->length = other.length;
		this->composedDataPointer = static_cast<GenericTypeOfCharacter*&&>(other.composedDataPointer);
		other.length = 0;
		other.composedDataPointer = nullptr;
	};
	template<typename GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter>::~SafeString() noexcept(false)
	{
		delete[] this->composedDataPointer;
	};


	template<typename GenericTypeOfCharacter> void SafeString<GenericTypeOfCharacter>::throwOutOfBoundException(const size_t& index) noexcept(false)
	{
		throw SafeContextException("Argument `index` is out of bound: `" + to_string(index) + "`!");
	};

	template<typename GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter>::SafeStringBuilder& SafeString<GenericTypeOfCharacter>::SafeStringBuilder::operator=(const SafeStringBuilder& other)
	{
		if (this != &other)
		{
			SafeContextBase::operator=(static_cast<const SafeContextBase&>(other));
			this->composedData = basic_string<GenericTypeOfCharacter>(other.composedData);
		}

		return *this;
	};

	template<typename GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter>::SafeStringBuilder& SafeString<GenericTypeOfCharacter>::SafeStringBuilder::operator=(SafeStringBuilder&& other) noexcept
	{
		if (this != &static_cast<const SafeStringBuilder&>(other))
		{
			SafeContextBase::operator=(static_cast<SafeContextBase&&>(other));
			this->composedData = static_cast<basic_string<GenericTypeOfCharacter>&&>(other.composedData);
		}

		return *this;
	};

	template<typename GenericTypeOfCharacter> bool SafeString<GenericTypeOfCharacter>::SafeStringBuilder::operator==(const SafeStringBuilder& other) const noexcept
	{
		return (this->composedData == other.composedData);
	};

	template<typename GenericTypeOfCharacter> GenericTypeOfCharacter& SafeString<GenericTypeOfCharacter>::SafeStringBuilder::operator[](const size_t& index)
	{
		if (index < (this->composedData).length())
		{
			return (this->composedData).operator[](index);
		}
		else
		{
			SafeString<GenericTypeOfCharacter>::throwOutOfBoundException(index);
		}
	};

	template<typename GenericTypeOfCharacter> size_t SafeString<GenericTypeOfCharacter>::SafeStringBuilder::getLength() const noexcept
	{
		return (this->composedData).length();
	};

	template<typename GenericTypeOfCharacter> void SafeString<GenericTypeOfCharacter>::SafeStringBuilder::append(const GenericTypeOfCharacter* const primitiveDataPointer)
	{
		(this->composedData).append(primitiveDataPointer);
	};

	template<typename GenericTypeOfCharacter> void SafeString<GenericTypeOfCharacter>::SafeStringBuilder::append(const basic_string<GenericTypeOfCharacter>& primitiveData)
	{
		(this->composedData).append(primitiveData);
	};

	template<typename GenericTypeOfCharacter> void SafeString<GenericTypeOfCharacter>::SafeStringBuilder::append(const GenericTypeOfCharacter character)
	{
		(this->composedData).push_back(character);
	};

	template<typename GenericTypeOfCharacter> void SafeString<GenericTypeOfCharacter>::SafeStringBuilder::insert(const size_t& index,const basic_string<GenericTypeOfCharacter>& data)
	{
		(this->composedData).insert(index,data);
	};

	template<typename GenericTypeOfCharacter> void SafeString<GenericTypeOfCharacter>::SafeStringBuilder::insert(const size_t& index,const GenericTypeOfCharacter character)
	{
		(this->composedData).insert((this->composedData).begin() + index,character);
	};

	template<typename GenericTypeOfCharacter> void SafeString<GenericTypeOfCharacter>::SafeStringBuilder::insert(const std::size_t& index,const GenericTypeOfCharacter* const dataPointer)
	{
		(this->composedData).insert(index,dataPointer);
	};

	template<typename GenericTypeOfCharacter> void SafeString<GenericTypeOfCharacter>::SafeStringBuilder::remove(const size_t& index,const size_t& count)
	{
		(this->composedData).erase(index,count);
	};

	template<typename GenericTypeOfCharacter> void SafeString<GenericTypeOfCharacter>::SafeStringBuilder::remove(const GenericTypeOfCharacter* const dataPointer)
	{
		(this->composedData).erase((this->composedData).find(dataPointer),basic_string_view<GenericTypeOfCharacter>(dataPointer).length());
	};

	template<typename GenericTypeOfCharacter> void SafeString<GenericTypeOfCharacter>::SafeStringBuilder::remove(const basic_string<GenericTypeOfCharacter>& data)
	{
		(this->composedData).erase((this->composedData).find(data),data.length());
	};

	template<typename GenericTypeOfCharacter> void SafeString<GenericTypeOfCharacter>::SafeStringBuilder::remove(const SafeString<GenericTypeOfCharacter>& data)
	{
		(this->composedData).erase((this->composedData).find(*(data.composedDataPointer)),data.getLength());
	};

	template<typename GenericTypeOfCharacter> void SafeString<GenericTypeOfCharacter>::SafeStringBuilder::replace(const size_t& position,const size_t& count,const basic_string<GenericTypeOfCharacter>& data)
	{
		if ((position + count) <= (this->composedData).length())
		{
			(this->composedData).replace(position,count,data);
		}
		else
		{
			throw SafeContextException("Arguments `position`: " + to_string(position) + " and `count`: `" + to_string(count) + "` are out of bound as the length of the current instance of `SafeStringView` is `" + to_string((this->composedData).length()) + "`!");
		}
	};

	template<typename GenericTypeOfCharacter> void SafeString<GenericTypeOfCharacter>::SafeStringBuilder::clear() noexcept
	{
		(this->composedData).clear();
	};

	template<typename GenericTypeOfCharacter> void SafeString<GenericTypeOfCharacter>::SafeStringBuilder::reserve(const size_t& cardinality)
	{
		(this->composedData).reserve(cardinality);
	};

	template<typename GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter>::SafeStringBuilder::toString() noexcept
	{
		return *(::new SafeString(static_cast<basic_string<GenericTypeOfCharacter>&&>(this->composedData)));
	};

	template<typename GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter>& SafeString<GenericTypeOfCharacter>::operator=(const SafeString<GenericTypeOfCharacter>& other)
	{
		if (this != &static_cast<const SafeString<GenericTypeOfCharacter>&>(other))
		{
			SafeContextBase::operator=(static_cast<const SafeString<GenericTypeOfCharacter>&>(other));
			this->length = other.length;
			this->composedDataPointer = other.composedDataPointer;
		}

		return *this;
	};

	template<typename GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter>& SafeString<GenericTypeOfCharacter>::operator=(SafeString<GenericTypeOfCharacter>&& other) noexcept
	{
		if (this != &static_cast<const SafeString<GenericTypeOfCharacter>&>(other))
		{
			SafeContextBase::operator=(static_cast<SafeString<GenericTypeOfCharacter>&&>(other));
			this->length = static_cast<size_t&&>(other.length);
			this->composedDataPointer = static_cast<GenericTypeOfCharacter*&&>(other.composedDataPointer);
			other.length = 0;
			other.composedDataPointer = nullptr;
		}

		return *this;
	};

	template<typename GenericTypeOfCharacter> bool SafeString<GenericTypeOfCharacter>::operator==(const basic_string<GenericTypeOfCharacter>& data) const noexcept
	{
		return (basic_string_view(this->composedDataPointer,this->length) == data);
	};

	template<typename GenericTypeOfCharacter> bool SafeString<GenericTypeOfCharacter>::operator==(const basic_string_view<GenericTypeOfCharacter>& dataView) const noexcept
	{
		return (basic_string_view(this->composedDataPointer,this->length) == dataView);
	};

	template<typename GenericTypeOfCharacter> bool SafeString<GenericTypeOfCharacter>::operator==(const SafeString<GenericTypeOfCharacter>& other) const noexcept
	{
		return (basic_string_view(this->composedDataPointer,this->length) == basic_string_view(other.composedDataPointer,other.length));
	};

	template<typename GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter>& SafeString<GenericTypeOfCharacter>::operator+(const SafeString<GenericTypeOfCharacter>& other)
	{
		SafeString<GenericTypeOfCharacter>* resultPointer = ::new SafeString<GenericTypeOfCharacter>();
		resultPointer->composedDataPointer = new GenericTypeOfCharacter[this->length + other.length];

		if ((this->composedDataPointer != nullptr) && (this->length > 0))
		{
			std::memcpy(resultPointer->composedDataPointer,this->composedDataPointer,this->length);
		}

		if ((other.composedDataPointer != nullptr) && (other.length > 0))
		{
			std::memcpy(resultPointer->composedDataPointer + this->length,other.composedDataPointer,other.length);
		}

		return *resultPointer;
	};

	template<typename GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter>& SafeString<GenericTypeOfCharacter>::operator-(const SafeString<GenericTypeOfCharacter>& other)
	{
		if (this->contains(other) == true)
		{
			basic_string<GenericTypeOfCharacter> composedResult = basic_string<GenericTypeOfCharacter>(this->composedDataPointer);
			composedResult.erase(composedResult.find(basic_string_view<GenericTypeOfCharacter>(other.composedDataPointer,other.length)),other.length);

			return *(::new SafeString(composedResult));
		}
		else
		{
			throw SafeContextException("Can't subtract the substring provided by argument `other` from the current instance of `SafeString` as the latter one doesn't contain the former one!");
		}
	};

	template<typename GenericTypeOfCharacter> const GenericTypeOfCharacter SafeString<GenericTypeOfCharacter>::operator[](const size_t& index) const
	{
		if ((this-> composedDataPointer != nullptr) && (index < this->length))
		{
			return (this->composedDataPointer)[index];
		}
		else
		{
			SafeString<GenericTypeOfCharacter>::throwOutOfBoundException(index);
		}
	};

	template<typename GenericTypeOfCharacter> size_t SafeString<GenericTypeOfCharacter>::getLength() const noexcept
	{
		return this->length;
	};

	template<typename GenericTypeOfCharacter> GenericTypeOfCharacter SafeString<GenericTypeOfCharacter>::at(const size_t& index) const
	{
		return this->operator[](index);
	};

	template<typename GenericTypeOfCharacter> bool SafeString<GenericTypeOfCharacter>::contains(const SafeString<GenericTypeOfCharacter>& other) const
	{
		return (basic_string_view<GenericTypeOfCharacter>(this->composedDataPointer,this->length).find(basic_string_view<GenericTypeOfCharacter>(other.composedDataPointer,other.length)) != basic_string<GenericTypeOfCharacter>::npos);
	};

	template<typename GenericTypeOfCharacter> bool SafeString<GenericTypeOfCharacter>::compareSubstring(const size_t& startingIndex,const size_t& length,const std::basic_string<GenericTypeOfCharacter>& data) const
	{
		return (basic_string_view<GenericTypeOfCharacter>(this->composedDataPointer,this->length).substr(startingIndex,length) == data);
	};

	template<typename GenericTypeOfCharacter> bool SafeString<GenericTypeOfCharacter>::compareSubstring(const size_t& startingIndex,const size_t& length,const std::basic_string_view<GenericTypeOfCharacter>& dataView) const
	{
		return (basic_string_view<GenericTypeOfCharacter>(this->composedDataPointer,this->length).substr(startingIndex,length) == dataView);
	};

	template<typename GenericTypeOfCharacter> bool SafeString<GenericTypeOfCharacter>::compareSubstring(const size_t& startingIndex,const size_t& length,const SafeString<GenericTypeOfCharacter>& other) const
	{
		return (basic_string_view<GenericTypeOfCharacter>(this->composedDataPointer,this->length).substr(startingIndex,length) == other);
	};

	template<typename GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter>::substr(const size_t& startingIndex,const size_t& count) const
	{
		if ((startingIndex + count) <= this->length)
		{
			return *(::new SafeString(basic_string(this->composedDataPointer,this->length).substr(startingIndex,count)));
		}
		else
		{
			throw SafeContextException("Arguments `startingIndex`: " + to_string(startingIndex) + " and `count`: `" + to_string(count)  + "` are out of bound as the length of the current instance of `SafeString` is `" + to_string(this->length) + "`!");
		}
	};

	template<typename GenericTypeOfCharacter> size_t SafeString<GenericTypeOfCharacter>::getFirstIndexOfCharacter(const GenericTypeOfCharacter character) const noexcept
	{
		return basic_string_view<GenericTypeOfCharacter>(this->composedDataPointer,this->length).find_first_of(character);
	};

	template<typename GenericTypeOfCharacter> size_t SafeString<GenericTypeOfCharacter>::getLastIndexOfCharacter(const GenericTypeOfCharacter character) const noexcept
	{
		return basic_string_view<GenericTypeOfCharacter>(this->composedDataPointer,this->length).find_last_of(character);
	};

	template<typename GenericTypeOfCharacter> size_t SafeString<GenericTypeOfCharacter>::findFirst(const SafeString<GenericTypeOfCharacter>& other) const noexcept
	{
		return basic_string_view<GenericTypeOfCharacter>(this->composedDataPointer,this->length).find(basic_string_view<GenericTypeOfCharacter>(other.composedDataPointer,other.length));
	};

	template<typename GenericTypeOfCharacter> size_t SafeString<GenericTypeOfCharacter>::findLast(const SafeString<GenericTypeOfCharacter>& other) const noexcept
	{
		return basic_string_view<GenericTypeOfCharacter>(this->composedDataPointer,this->length).rfind(basic_string_view<GenericTypeOfCharacter>(other.composedDataPointer,other.length));
	};

	template<typename GenericTypeOfCharacter> basic_string<GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter>::obtainPrimitiveString() const
	{
		return basic_string<GenericTypeOfCharacter>(this->composedDataPointer,this->length);
	};

	template<typename GenericTypeOfCharacter> basic_string_view<GenericTypeOfCharacter> SafeString<GenericTypeOfCharacter>::obtainPrimitiveStringView() const noexcept
	{
		return basic_string_view<GenericTypeOfCharacter>(this->composedDataPointer,this->length);
	};


	template class CPP_SAFE_LIBRARY_TRADE SafeString<char>;
	template class CPP_SAFE_LIBRARY_TRADE SafeString<signed char>;
	template class CPP_SAFE_LIBRARY_TRADE SafeString<unsigned char>;
	template class CPP_SAFE_LIBRARY_TRADE SafeString<wchar_t>;
	template class CPP_SAFE_LIBRARY_TRADE SafeString<char8_t>;
	template class CPP_SAFE_LIBRARY_TRADE SafeString<char16_t>;
	template class CPP_SAFE_LIBRARY_TRADE SafeString<char32_t>;
};
