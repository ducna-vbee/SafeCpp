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
#include <string>
#include <type_traits>
#include <vector>

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
	///		C++ class template: `SafeMemoryChunk`.
	/// </summary>
	/// <typeparam name="GenericTypeOfSafeContextDerivative"></typeparam>
	template<typename GenericTypeOfSafeContextDerivative> requires std::equality_comparable<GenericTypeOfSafeContextDerivative> class SafeContextBase::SafeMemoryChunk final : public SafeContextBase
	{
	private:
		GenericTypeOfSafeContextDerivative* composedBufferPointer;
		std::size_t cardinality;
		std::vector<const void*> constantPointerMasks;
		std::vector<void*> variablePointerMasks;

	public:
		static_assert((std::is_base_of<SafeContextBase,GenericTypeOfSafeContextDerivative>::value == true),"`GenericTypeOfSafeContextDerivative` must be a type inherited from `SafeContextBase`!");
		static_assert((std::is_pointer<GenericTypeOfSafeContextDerivative>::value == false),"`GenericTypeOfSafeContextDerivative` can't be a pointer type!");
		static_assert((std::is_default_constructible<GenericTypeOfSafeContextDerivative>::value == true),"`GenericTypeOfSafeContextDerivative` must be a type having a default constructor!");
		static_assert((std::is_copy_constructible<GenericTypeOfSafeContextDerivative>::value == true),"`GenericTypeOfSafeContextDerivative` must be a type having a copy constructor!");
		static_assert((std::is_move_constructible<GenericTypeOfSafeContextDerivative>::value == true),"`GenericTypeOfSafeContextDerivative` must be a type having a move constructor!");
		static_assert((std::is_copy_assignable<GenericTypeOfSafeContextDerivative>::value == true),"`GenericTypeOfSafeContextDerivative` must be a type having a copy assignment operator!");
		static_assert((std::is_move_assignable<GenericTypeOfSafeContextDerivative>::value == true),"`GenericTypeOfSafeContextDerivative` must be a type having a move assignment operator!");


		/// <summary>
		///		Constructor of `SafeMemoryChunk`.
		/// </summary>
		inline constexpr explicit SafeMemoryChunk() : SafeContextBase()
		{
			this->cardinality = 10;
			this->constantPointerMasks = std::vector<const void*>();
			this->variablePointerMasks = std::vector<void*>();
			std::vector<SafeContextBase*> chunkBufferElementPointers = std::vector<SafeContextBase*>();
			GenericTypeOfSafeContextDerivative* chunkPointer = static_cast<GenericTypeOfSafeContextDerivative*>(::operator new(sizeof(GenericTypeOfSafeContextDerivative) * this->cardinality));
			std::size_t i = 0;

			for (i = 0;i < this->cardinality;i++)
			{
				(this->constantPointerMasks).push_back(static_cast<const void*>(chunkPointer + i));
				(this->variablePointerMasks).push_back(static_cast<void*>(chunkPointer + i));
				chunkBufferElementPointers.push_back(static_cast<SafeContextBase*>(chunkPointer + i));
			}

			this->composedBufferPointer = chunkPointer;
			SafeContextBase::helpInitializeChunk(chunkBufferElementPointers,this->cardinality,this->constantPointerMasks,this->variablePointerMasks,[](SafeContextBase* const instancePointer) -> void
			{
				::new(instancePointer) GenericTypeOfSafeContextDerivative();
			});
		};

		/// <summary>
		///		Constructor of `SafeMemoryChunk`.
		/// </summary>
		/// <param name="cardinality"></param>
		inline explicit SafeMemoryChunk(const std::size_t& cardinality) : SafeContextBase()
		{
			this->cardinality = cardinality;
			this->constantPointerMasks = std::vector<const void*>();
			this->variablePointerMasks = std::vector<void*>();
			std::vector<SafeContextBase*> chunkBufferElementPointers = std::vector<SafeContextBase*>();
			GenericTypeOfSafeContextDerivative* chunkPointer = static_cast<GenericTypeOfSafeContextDerivative*>(::operator new(sizeof(GenericTypeOfSafeContextDerivative) * this->cardinality));
			std::size_t i = 0;

			for (i = 0;i < cardinality;i++)
			{
				(this->constantPointerMasks).push_back(static_cast<const void*>(chunkPointer + i));
				(this->variablePointerMasks).push_back(static_cast<void*>(chunkPointer + i));
				chunkBufferElementPointers.push_back(static_cast<SafeContextBase*>(chunkPointer + i));
			}

			this->composedBufferPointer = chunkPointer;
			SafeContextBase::helpInitializeChunk(chunkBufferElementPointers,this->cardinality,this->constantPointerMasks,this->variablePointerMasks,[](SafeContextBase* const instancePointer) -> void
			{
				::new(instancePointer) GenericTypeOfSafeContextDerivative();
			});
		};

	private:
		/// <summary>
		///		Copy constructor of `SafeMemoryChunk`.
		/// </summary>
		inline SafeMemoryChunk(const SafeMemoryChunk<GenericTypeOfSafeContextDerivative>&) = delete;

		/// <summary>
		///		Move constructor of `SafeMemoryChunk`.
		/// </summary>
		inline SafeMemoryChunk(SafeMemoryChunk<GenericTypeOfSafeContextDerivative>&&) = delete;

	public:
		/// <summary>
		///		Destructor of `SafeMemoryChunk`.
		/// </summary>
		inline virtual ~SafeMemoryChunk() noexcept(false) override
		{
			if (this->composedBufferPointer != nullptr)
			{
				std::size_t i = 0;
				std::vector<SafeContextBase*> chunkBufferElementPointers = std::vector<SafeContextBase*>();

				for (i = 0;i < this->cardinality;i++)
				{
					chunkBufferElementPointers.push_back(&((this->composedBufferPointer)[i]));
				}

				SafeContextBase::destroyDerivedChunkOnMemoryHeap(chunkBufferElementPointers,this->cardinality,this->constantPointerMasks,this->variablePointerMasks);
				::operator delete(this->composedBufferPointer);
				this->composedBufferPointer = nullptr;
			}
		};

	private:
		/// <summary>
		///		dynamic
		///		inline
		///		operator=
		/// </summary>
		/// <returns>SafeMemoryChunk&lt;GenericTypeOfSafeContextDerivative&gt;&amp;</returns>
		inline SafeMemoryChunk<GenericTypeOfSafeContextDerivative>& operator=(const SafeMemoryChunk<GenericTypeOfSafeContextDerivative>&) = delete;

		/// <summary>
		///		dynamic
		///		inline
		///		operator=
		/// </summary>
		/// <returns>SafeMemoryChunk&lt;GenericTypeOfSafeContextDerivative&gt;&amp;</returns>
		inline SafeMemoryChunk<GenericTypeOfSafeContextDerivative>& operator=(SafeMemoryChunk<GenericTypeOfSafeContextDerivative>&&) = delete;

	public:
		/// <summary>
		///		dynamic
		///		inline
		///		operator[]
		/// </summary>
		/// <param name="index"></param>
		/// <returns>GenericTypeOfSafeContextDerivative&amp;</returns>
		/// <exception cref="SafeContextException"/>
		inline const GenericTypeOfSafeContextDerivative& operator[](const std::size_t& index) const
		{
			if (index >= this->cardinality)
			{
				throw SafeContextException("Argument `index` is out of bound: `" + std::to_string(index) + "` while the cardinality is `" + std::to_string(this->cardinality) + "`!");
			}
			else
			{
				return *(static_cast<const GenericTypeOfSafeContextDerivative*>((this->constantPointerMasks)[index]));
			}
		};

		/// <summary>
		///		dynamic
		///		inline
		///		operator[]
		/// </summary>
		/// <param name="index"></param>
		/// <returns>GenericTypeOfSafeContextDerivative&amp;</returns>
		/// <exception cref="SafeContextException"/>
		inline GenericTypeOfSafeContextDerivative& operator[](const std::size_t& index)
		{
			if (index >= this->cardinality)
			{
				throw SafeContextException("Argument `index` is out of bound: `" + std::to_string(index) + "` while the cardinality is `" + std::to_string(this->cardinality) + "`!");
			}
			else
			{
				return *(static_cast<GenericTypeOfSafeContextDerivative*>((this->variablePointerMasks)[index]));
			}
		};

		/// <summary>
		///		dynamic
		///     inline
		///		noexcept
		/// </summary>
		/// <returns>size_t</returns>
		inline std::size_t getCardinality() const noexcept
		{
			return this->cardinality;
		};

		/// <summary>
		///		dynamic
		///     inline
		/// </summary>
		/// <returns>bool</returns>
		inline bool contains(const GenericTypeOfSafeContextDerivative& element) const
		{
			if (this->composedBufferPointer == nullptr)
			{
				return false;
			}
			else
			{
				std::size_t i = 0;

				for (i = 0;i < this->cardinality;i++)
				{
					if ((this->composedBufferPointer)[i] == element)
					{
						return true;
					}
				}

				return false;
			}
		};

		/// <summary>
		///		dynamic
		///		inline
		/// </summary>
		/// <returns>void</returns>
		inline void dispose()
		{
			const GenericTypeOfSafeContextDerivative* constantProxyInstancePointer = static_cast<const GenericTypeOfSafeContextDerivative*>(SafeContextBase::referToDefaultConstantInstance(typeid(GenericTypeOfSafeContextDerivative)));
			GenericTypeOfSafeContextDerivative* variableProxyInstancePointer = ::new GenericTypeOfSafeContextDerivative();

			if (constantProxyInstancePointer == nullptr)
			{
				constantProxyInstancePointer = SafeContextBase::supplementDefaultInstanceOfDerivedType<GenericTypeOfSafeContextDerivative>();
			}

			std::size_t i = 0;
			std::vector<SafeContextBase*> chunkBufferElementPointers = std::vector<SafeContextBase*>();

			for (i = 0;i < this->cardinality;i++)
			{
				chunkBufferElementPointers.push_back(&((this->composedBufferPointer)[i]));
			}

			SafeContextBase::helpDisposeChunk(chunkBufferElementPointers,this->cardinality,this->constantPointerMasks,this->variablePointerMasks,constantProxyInstancePointer,variableProxyInstancePointer);
			::operator delete(this->composedBufferPointer);
			this->composedBufferPointer = nullptr;
		};
	};

	/// <summary>
	///		C++ type name alias: `SafeMemoryChunk`.
	/// </summary>
	/// <typeparam name="GenericTypeOfSafeContextDerivative"></typeparam>
	template<typename GenericTypeOfSafeContextDerivative> using SafeMemoryChunk = SafeContextBase::SafeMemoryChunk<GenericTypeOfSafeContextDerivative>;
};
