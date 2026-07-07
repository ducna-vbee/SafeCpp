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
#include <atomic>
#include <deque>
#include <mutex>
#include <typeinfo>
#include <utility>
#include <vector>

/** Inclusion(s) of project's C++ header file(s).**/
#include "SafeContextBase.h"
#include "SafeContextException.h"

/** Inclusion(s) of the standard C++ namespace(s).**/
using namespace std;


/** Main code.**/

namespace Safe
{
	/// <summary>
	///		C++ class: `SafeMemoryManager`.
	/// </summary>
	class SafeContextBase::SafeMemoryManager final
	{
	private:
		static atomic<bool> Classification;
		static recursive_mutex ClassificationGuard;
		static mutex ShutdownGuard;


		deque<SafeContextBase*> trackedInstancePointerQueue;
		deque<pair<SafeContextBase*,size_t>> trackedArrayPointerMetadataQueue;
		deque<pair<SafeContextBase*,size_t>> trackedChunkPointerMetadataQueue;
		vector<SafeContextBase*> recycledInstancePointers;
		mutex memoryTrackerSynchronizationGuard;
		mutex memoryRecyclerSynchronizationGuard;


		/// <summary>
		///		dynamic
		///		noexcept
		/// </summary>
		/// <returns>void</returns>
		void shutdown() noexcept;

	public:
		static SafeMemoryManager StaticMemoryManager;


		vector<const SafeContextBase*> defaultConstantInstancePointers;


		/// <summary>
		///		Constructor of `SafeMemoryManager`.
		/// </summary>
		explicit SafeMemoryManager() noexcept;

		/// <summary>
		///		Copy constructor of `SafeMemoryManager`.
		/// </summary>
		inline SafeMemoryManager(const SafeMemoryManager&) = delete;

		/// <summary>
		///		Move constructor of `SafeMemoryManager`.
		/// </summary>
		inline SafeMemoryManager(SafeMemoryManager&&) noexcept = delete;

		/// <summary>
		///		Destructor of `SafeMemoryManager`.
		/// </summary>
		~SafeMemoryManager() noexcept;

		/// <summary>
		///		static
		///		noexcept
		/// </summary>
		/// <returns>bool</returns>
		static bool getClassification() noexcept;

		/// <summary>
		///		static
		///		noexcept
		/// </summary>
		/// <param name="classification"></param>
		/// <returns>void</returns>
		static void setClassification(const bool& classification) noexcept;

		/// <summary>
		///		static
		/// </summary>
		/// <param name="chunkBufferElementPointers"></param>
		/// <param name="cardinality"></param>
		/// <param name="constantPointerMasks"></param>
		/// <param name="variablePointerMasks"></param>
		/// <param name="constructionInvoker"></param>
		/// <returns>void</returns>
		static void helpInitializeChunk(vector<SafeContextBase*>& chunkBufferElementPointers,const size_t& cardinality,const vector<const void*>& constantPointerMasks,const vector<void*>& variablePointerMasks,const SafeConstructionInvoker& constructionInvoker);

		/// <summary>
		///		static
		/// </summary>
		/// <param name="chunkBufferElementPointers"></param>
		/// <param name="cardinality"></param>
		/// <param name="constantPointerMasks"></param>
		/// <param name="variablePointerMasks"></param>
		/// <returns>void</returns>
		static void helpDestroyChunk(const vector<SafeContextBase*>& chunkBufferElementPointers,const size_t& cardinality,vector<const void*>& constantPointerMasks,vector<void*>& variablePointerMasks);

		/// <summary>
		///		static
		/// </summary>
		/// <param name="chunkBufferElementPointers"></param>
		/// <param name="cardinality"></param>
		/// <param name="constantPointerMasks"></param>
		/// <param name="variablePointerMasks"></param>
		/// <param name="constantProxyInstancePointer"></param>
		/// <param name="variableProxyInstancePointer"></param>
		/// <returns>void</returns>
		static void helpDisposeChunk(const vector<SafeContextBase*>& chunkBufferElementPointers,const size_t& cardinality,vector<const void*>& constantPointerMasks,vector<void*>& variablePointerMasks,const void* const constantProxyInstancePointer,void* const variableProxyInstancePointer);

		/// <summary>
		///		static
		/// </summary>
		/// <param name="instancePointer"></param>
		/// <param name="constructionInvoker"></param>
		/// <returns>void</returns>
		static void reconstructSafely(SafeContextBase* const instancePointer,const SafeConstructionInvoker& constructionInvoker);

		/// <summary>
		///		dynamic
		/// </summary>
		/// <param name="instancePointer"></param>
		/// <returns>void</returns>
		void emplaceInstance(SafeContextBase* const instancePointer);

		/// <summary>
		///		dynamic
		/// </summary>
		/// <param name="arrayPointer"></param>
		/// <returns>void</returns>
		void emplaceArray(SafeContextBase* const arrayPointer,const size_t& arraySize);

		/// <summary>
		///		dynamic
		/// </summary>
		/// <param name="chunkPointer"></param>
		/// <returns>void</returns>
		void emplaceChunk(SafeContextBase* const chunkPointer,const size_t& chunkSize);

		/// <summary>
		///		dynamic
		///		noexcept
		/// </summary>
		/// <param name="instancePointer"></param>
		/// <returns>void</returns>
		void displaceInstance(SafeContextBase* const instancePointer) noexcept;

		/// <summary>
		///		dynamic
		///		noexcept
		/// </summary>
		/// <param name="arrayPointer"></param>
		/// <returns>void</returns>
		void displaceArray(SafeContextBase* const arrayPointer) noexcept;

		/// <summary>
		///		dynamic
		/// </summary>
		/// <param name="chunkPointer"></param>
		/// <returns>void</returns>
		void displaceChunk(SafeContextBase* const chunkPointer);

		/// <summary>
		///		dynamic
		/// </summary>
		/// <param name="instanceReference"></param>
		/// <returns>void</returns>
		void recycle(SafeContextBase& instanceReference);

		/// <summary>
		///		dynamic
		/// </summary>
		/// <param name="instancePointer"></param>
		/// <returns>void</returns>
		void recycle(SafeContextBase* const instancePointer);

		/// <summary>
		///		dynamic
		/// </summary>
		/// <param name="typeInformation"></param>
		/// <returns>SafeContextBase*</returns>
		SafeContextBase* upcycle(const type_info& typeInformation);

		/// <summary>
		///		dynamic
		/// </summary>
		/// <param name="typeInformation"></param>
		/// <returns>SafeContextBase*</returns>
		const SafeContextBase* referToDefaultConstantInstance(const type_info& typeInformation);

		/// <summary>
		///		dynamic
		/// </summary>
		/// <param name="defaultedInstancePointer"></param>
		/// <returns>void</returns>
		void supplementDefaultPolymorphicInstance(const SafeContextBase* defaultedInstancePointer);

		/// <summary>
		///		dynamic
		/// </summary>
		/// <param name="pointerInDangerZone"></param>
		/// <returns>void</returns>
		void forceShutdown(const SafeContextBase* pointerInDangerZone);
	};

	SafeContextBase::SafeMemoryManager::SafeMemoryManager() noexcept : memoryTrackerSynchronizationGuard(),memoryRecyclerSynchronizationGuard()
	{
		this->trackedInstancePointerQueue = deque<SafeContextBase*>();
		this->trackedArrayPointerMetadataQueue = deque<pair<SafeContextBase*,size_t>>();
		this->trackedChunkPointerMetadataQueue = deque<pair<SafeContextBase*,size_t>>();
		this->recycledInstancePointers = vector<SafeContextBase*>();
		this->defaultConstantInstancePointers = vector<const SafeContextBase*>();
	};
	SafeContextBase::SafeMemoryManager::~SafeMemoryManager() noexcept
	{
		this->shutdown();
	};

	SafeContextBase::SafeContextBase()
	{
		this->life = true;

		if (SafeContextBase::SafeMemoryManager::getClassification() == true)
		{
			SafeMemoryManager::StaticMemoryManager.emplaceInstance(this);
		}
	};
	SafeContextBase::SafeContextBase(const bool& classification)
	{
		this->life = true;

		if (classification == true)
		{
			SafeMemoryManager::StaticMemoryManager.emplaceInstance(this);
		}
	};
	SafeContextBase::SafeContextBase(const SafeContextBase& other) noexcept(false)
	{
		this->life = true;

		if (SafeContextBase::SafeMemoryManager::getClassification() == true)
		{
			SafeMemoryManager::StaticMemoryManager.emplaceInstance(this);
		}
	};
	SafeContextBase::SafeContextBase(SafeContextBase&& other) noexcept(false)
	{
		this->life = true;

		if (SafeContextBase::SafeMemoryManager::getClassification() == true)
		{
			SafeMemoryManager::StaticMemoryManager.emplaceInstance(this);
		}
	};
	SafeContextBase::~SafeContextBase() noexcept(false)
	{
		if (SafeContextBase::SafeMemoryManager::getClassification() == true)
		{
			SafeMemoryManager::StaticMemoryManager.displaceInstance(this);

			if (this->life == false)
			{
				SafeMemoryManager::StaticMemoryManager.forceShutdown(this);

				throw SafeContextException("The destructor of `SafeContextBase` is invoked manually on a polymorphic instance of type `SafeContextBase` which isn't managed or tracked!");
			}
			else
			{
				this->life = false;
			}
		}
	};


	atomic<bool> SafeContextBase::SafeMemoryManager::Classification{true};
	recursive_mutex SafeContextBase::SafeMemoryManager::ClassificationGuard = recursive_mutex();
	mutex SafeContextBase::SafeMemoryManager::ShutdownGuard = mutex();
	SafeContextBase::SafeMemoryManager SafeContextBase::SafeMemoryManager::StaticMemoryManager = SafeContextBase::SafeMemoryManager();


	void SafeContextBase::SafeMemoryManager::shutdown() noexcept
	{
		size_t i = 0;
		lock_guard<mutex> shutdownLock(ShutdownGuard);

		while (true)
		{
			SafeContextBase* currentInstancePointer = nullptr;

			if (currentInstancePointer == nullptr)
			{
				lock_guard<mutex> trackerLock(this->memoryTrackerSynchronizationGuard);

				if ((this->trackedInstancePointerQueue).empty() == true)
				{
					break;
				}
				else
				{
					currentInstancePointer = (this->trackedInstancePointerQueue).front();
					(this->trackedInstancePointerQueue).pop_front();
				}
			}

			delete currentInstancePointer;
		}

		SafeMemoryManager::setClassification(false);

		while (true)
		{
			pair<SafeContextBase*,size_t> currentArrayPointerMetadata = make_pair<SafeContextBase*&&,size_t&&>(nullptr,0);

			if (currentArrayPointerMetadata.first == nullptr)
			{
				lock_guard<mutex> trackerLock(this->memoryTrackerSynchronizationGuard);

				if ((this->trackedArrayPointerMetadataQueue).empty() == true)
				{
					break;
				}
				else
				{
					currentArrayPointerMetadata = (this->trackedArrayPointerMetadataQueue).front();
					(this->trackedArrayPointerMetadataQueue).pop_front();
				}
			}

			for (i = 0;i < currentArrayPointerMetadata.second;i++)
			{
				((currentArrayPointerMetadata.first)[i]).~SafeContextBase();
			}

			delete[] currentArrayPointerMetadata.first;
		}

		while (true)
		{
			pair<SafeContextBase*,size_t> currentChunkPointerMetadata = make_pair<SafeContextBase*&&,size_t&&>(nullptr,0);

			if (currentChunkPointerMetadata.first == nullptr)
			{
				lock_guard<mutex> trackerLock(this->memoryTrackerSynchronizationGuard);

				if (this->trackedChunkPointerMetadataQueue.empty() == true)
				{
					break;
				}
				else
				{
					currentChunkPointerMetadata = (this->trackedChunkPointerMetadataQueue).front();
					(this->trackedChunkPointerMetadataQueue).pop_front();
				}
			}

			for (i = 0;i < currentChunkPointerMetadata.second;i++)
			{
				((currentChunkPointerMetadata.first)[i]).~SafeContextBase();
			}

			delete currentChunkPointerMetadata.first;
		}

		SafeMemoryManager::setClassification(true);
	};

	bool SafeContextBase::SafeMemoryManager::getClassification() noexcept
	{
		lock_guard<recursive_mutex> classificationLock(ClassificationGuard);

		return Classification.load();
	};

	void SafeContextBase::SafeMemoryManager::setClassification(const bool& classification) noexcept
	{
		lock_guard<recursive_mutex> classificationLock(ClassificationGuard);

		SafeMemoryManager::Classification.store(classification);
	};

	void SafeContextBase::SafeMemoryManager::helpInitializeChunk(vector<SafeContextBase*>& chunkBufferElementPointers,const size_t& cardinality,const vector<const void*>& constantPointerMasks,const vector<void*>& variablePointerMasks,const SafeConstructionInvoker& constructionInvoker)
	{
		lock_guard<recursive_mutex> classificationLock(ClassificationGuard);
		SafeMemoryManager::Classification.store(false);
		size_t i = 0;

		for (i = 0;i < cardinality;i++)
		{
			constructionInvoker(chunkBufferElementPointers[i]);
		}

		SafeMemoryManager::Classification.store(true);
	};

	void SafeContextBase::SafeMemoryManager::helpDestroyChunk(const vector<SafeContextBase*>& chunkBufferElementPointers,const size_t& cardinality,vector<const void*>& constantPointerMasks,vector<void*>& variablePointerMasks)
	{
		lock_guard<recursive_mutex> classificationLock(ClassificationGuard);
		size_t i = 0;

		for (i = 0;i < cardinality;i++)
		{
			(chunkBufferElementPointers[i])->~SafeContextBase();
			constantPointerMasks[i] = nullptr;
			variablePointerMasks[i] = nullptr;
		}
	};

	void SafeContextBase::SafeMemoryManager::helpDisposeChunk(const vector<SafeContextBase*>& chunkBufferElementPointers,const size_t& cardinality,vector<const void*>& constantPointerMasks,vector<void*>& variablePointerMasks,const void* const constantProxyInstancePointer,void* const variableProxyInstancePointer)
	{
		lock_guard<recursive_mutex> classificationLock(ClassificationGuard);
		SafeMemoryManager::Classification.store(false);
		size_t i = 0;

		for (i = 0;i < cardinality;i++)
		{
			(chunkBufferElementPointers[i])->~SafeContextBase();
			constantPointerMasks[i] = static_cast<const void*>(constantProxyInstancePointer);
			variablePointerMasks[i] = static_cast<void*>(variableProxyInstancePointer);
		}

		SafeMemoryManager::Classification.store(true);
	};

	void SafeContextBase::SafeMemoryManager::reconstructSafely(SafeContextBase* const instancePointer,const SafeConstructionInvoker& constructionInvoker)
	{
		lock_guard<recursive_mutex> classificationLock(ClassificationGuard);
		SafeMemoryManager::Classification.store(false);
		static_cast<SafeContextBase*>(instancePointer)->~SafeContextBase();
		constructionInvoker(instancePointer);
		SafeMemoryManager::Classification.store(true);
	};

	void SafeContextBase::SafeMemoryManager::emplaceInstance(SafeContextBase* const instancePointer)
	{
		lock_guard<mutex> trackerLock(this->memoryTrackerSynchronizationGuard);
		(this->trackedInstancePointerQueue).push_back(instancePointer);
	};

	void SafeContextBase::SafeMemoryManager::emplaceArray(SafeContextBase* const arrayPointer,const size_t& arraySize)
	{
		lock_guard<mutex> trackerLock(this->memoryTrackerSynchronizationGuard);
		(this->trackedArrayPointerMetadataQueue).push_back(make_pair<SafeContextBase* const&,const size_t&>(arrayPointer,arraySize));
	};

	void SafeContextBase::SafeMemoryManager::emplaceChunk(SafeContextBase* const chunkPointer,const size_t& chunkSize)
	{
		lock_guard<mutex> trackerLock(this->memoryTrackerSynchronizationGuard);
		(this->trackedChunkPointerMetadataQueue).push_back(make_pair<SafeContextBase* const&,const size_t&>(chunkPointer,chunkSize));
	};

	void SafeContextBase::SafeMemoryManager::displaceInstance(SafeContextBase* const instancePointer) noexcept
	{
		lock_guard<mutex> trackerLock(this->memoryTrackerSynchronizationGuard);
		lock_guard<mutex> recyclerLock(this->memoryRecyclerSynchronizationGuard);
		size_t i = 0;
		size_t numberOfTrackedInstances = (this->trackedInstancePointerQueue).size();

		for (i = 0;i < numberOfTrackedInstances;i++)
		{
			if ((this->trackedInstancePointerQueue)[i] == instancePointer)
			{
				(this->trackedInstancePointerQueue).erase((this->trackedInstancePointerQueue).begin() + i);
				break;
			}
		}

		i = 0;

		while (i < (this->recycledInstancePointers).size())
		{
			if ((this->recycledInstancePointers)[i] == instancePointer)
			{
				(this->recycledInstancePointers).erase((this->recycledInstancePointers).begin() + i);
			}
			else
			{
				i++;
			}
		}
	};

	void SafeContextBase::SafeMemoryManager::displaceArray(SafeContextBase* const arrayPointer) noexcept
	{
		lock_guard<mutex> trackerLock(this->memoryTrackerSynchronizationGuard);
		size_t i = 0;
		size_t numberOfTrackedArrays = (this->trackedArrayPointerMetadataQueue).size();

		for (i = 0;i < numberOfTrackedArrays;i++)
		{
			if (((this->trackedArrayPointerMetadataQueue)[i]).first == arrayPointer)
			{
				(this->trackedArrayPointerMetadataQueue).erase((this->trackedArrayPointerMetadataQueue).begin() + i);
				break;
			}
		}
	};

	void SafeContextBase::SafeMemoryManager::displaceChunk(SafeContextBase* const chunkPointer)
	{
		lock_guard<mutex> trackerLock(this->memoryTrackerSynchronizationGuard);
		size_t i = 0;
		size_t numberOfTrackedChunks = (this->trackedChunkPointerMetadataQueue).size();

		for (i = 0;i < numberOfTrackedChunks;i++)
		{
			if (((this->trackedChunkPointerMetadataQueue)[i]).first == chunkPointer)
			{
				size_t j = 0;

				for (j = 0;j < ((this->trackedChunkPointerMetadataQueue)[i]).second;j++)
				{
					((((this->trackedChunkPointerMetadataQueue)[i]).first)[j]).~SafeContextBase();
				}

				(this->trackedChunkPointerMetadataQueue).erase((this->trackedChunkPointerMetadataQueue).begin() + i);
				break;
			}
		}
	};

	void SafeContextBase::SafeMemoryManager::recycle(SafeContextBase& instanceReference)
	{
		lock_guard<mutex> recyclerLock(this->memoryRecyclerSynchronizationGuard);
		(this->recycledInstancePointers).push_back(&instanceReference);
	};

	void SafeContextBase::SafeMemoryManager::recycle(SafeContextBase* const instancePointer)
	{
		lock_guard<mutex> recyclerLock(this->memoryRecyclerSynchronizationGuard);
		(this->recycledInstancePointers).push_back(instancePointer);
	};

	SafeContextBase* SafeContextBase::SafeMemoryManager::upcycle(const type_info& typeInformation)
	{
		lock_guard<mutex> recyclerLock(this->memoryRecyclerSynchronizationGuard);
		size_t i = 0;
		size_t numberOfRecycledPointers = (this->recycledInstancePointers).size();
		SafeContextBase* result = nullptr;

		for (i = 0;i < numberOfRecycledPointers;i++)
		{
			if (((this->recycledInstancePointers)[i])->getTypeInfo() == typeInformation)
			{
				result = (this->recycledInstancePointers)[i];
				(this->recycledInstancePointers).erase((this->recycledInstancePointers).begin() + i);
				break;
			}
		}

		return result;
	};

	const SafeContextBase* SafeContextBase::SafeMemoryManager::referToDefaultConstantInstance(const type_info& typeInformation)
	{
		lock_guard<mutex> recyclerLock(this->memoryRecyclerSynchronizationGuard);
		size_t i = 0;
		size_t numberOfDefaultConstantInstances = (this->defaultConstantInstancePointers).size();
		const SafeContextBase* result = nullptr;

		for (i = 0;i < numberOfDefaultConstantInstances;i++)
		{
			if (((this->defaultConstantInstancePointers)[i])->getTypeInfo() == typeInformation)
			{
				result = (this->defaultConstantInstancePointers)[i];
				break;
			}
		}

		return result;
	};

	void SafeContextBase::SafeMemoryManager::supplementDefaultPolymorphicInstance(const SafeContextBase* defaultedInstancePointer)
	{
		lock_guard<mutex> recyclerLock(this->memoryRecyclerSynchronizationGuard);
		(this->defaultConstantInstancePointers).push_back(defaultedInstancePointer);
	};

	void SafeContextBase::SafeMemoryManager::forceShutdown(const SafeContextBase* pointerInDangerZone)
	{
		size_t i = 0;
		lock_guard<mutex> shutdownLock(ShutdownGuard);

		while (true)
		{
			SafeContextBase* currentInstancePointer = nullptr;

			if (currentInstancePointer == nullptr)
			{
				lock_guard<mutex> trackerLock(this->memoryTrackerSynchronizationGuard);

				if ((this->trackedInstancePointerQueue).empty() == true)
				{
					break;
				}
				else
				{
					currentInstancePointer = (this->trackedInstancePointerQueue).front();

					if (currentInstancePointer != pointerInDangerZone)
					{
						(this->trackedInstancePointerQueue).pop_front();
					}
				}
			}

			delete currentInstancePointer;
		}

		SafeMemoryManager::setClassification(false);

		while (true)
		{
			pair<SafeContextBase*,size_t> currentArrayPointerMetadata = make_pair<SafeContextBase*&&,size_t&&>(nullptr,0);

			if (currentArrayPointerMetadata.first == nullptr)
			{
				lock_guard<mutex> trackerLock(this->memoryTrackerSynchronizationGuard);

				if ((this->trackedArrayPointerMetadataQueue).empty() == true)
				{
					break;
				}
				else
				{
					currentArrayPointerMetadata = (this->trackedArrayPointerMetadataQueue).front();

					if (currentArrayPointerMetadata.first != pointerInDangerZone)
					{
						(this->trackedArrayPointerMetadataQueue).pop_front();
					}
				}
			}

			for (i = 0;i < currentArrayPointerMetadata.second;i++)
			{
				((currentArrayPointerMetadata.first)[i]).~SafeContextBase();
			}

			delete[] currentArrayPointerMetadata.first;
		}

		while (true)
		{
			pair<SafeContextBase*,size_t> currentChunkPointerMetadata = make_pair<SafeContextBase*&&,size_t&&>(nullptr,0);

			if (currentChunkPointerMetadata.first == nullptr)
			{
				lock_guard<mutex> trackerLock(this->memoryTrackerSynchronizationGuard);

				if (this->trackedChunkPointerMetadataQueue.empty() == true)
				{
					break;
				}
				else
				{
					currentChunkPointerMetadata = (this->trackedChunkPointerMetadataQueue).front();
					
					if (currentChunkPointerMetadata.first != pointerInDangerZone)
					{
						(this->trackedChunkPointerMetadataQueue).pop_front();
					}
				}
			}

			for (i = 0;i < currentChunkPointerMetadata.second;i++)
			{
				((currentChunkPointerMetadata.first)[i]).~SafeContextBase();
			}

			delete currentChunkPointerMetadata.first;
		}

		SafeMemoryManager::setClassification(true);
	};

	void* SafeContextBase::operator new(size_t memorySize)
	{
		return ::operator new(memorySize);
	};

	void* SafeContextBase::operator new[](size_t memoryArraySize)
	{
		SafeContextBase* memoryArrayPointer = static_cast<SafeContextBase*>(::operator new[](sizeof(SafeContextBase) * memoryArraySize));
		size_t i = 0;

		for (i = 0;i < memoryArraySize;i++)
		{
			::new (&(memoryArrayPointer[i])) SafeContextBase(false);
		}

		SafeContextBase::SafeMemoryManager::StaticMemoryManager.emplaceArray(memoryArrayPointer,memoryArraySize);

		return memoryArrayPointer;
	};

	void SafeContextBase::operator delete(void* const memoryPointer) noexcept
	{
		::operator delete(memoryPointer);
	};

	void SafeContextBase::operator delete[](void* const memoryArrayPointer) noexcept
	{
		::operator delete[](memoryArrayPointer);
	};

	SafeContextBase* SafeContextBase::operator&() noexcept
	{
		return this;
	};

	SafeContextBase& SafeContextBase::operator=(const SafeContextBase& other) noexcept
	{
		return *this;
	};

	SafeContextBase& SafeContextBase::operator=(SafeContextBase&& other) noexcept
	{
		return *this;
	};

	bool SafeContextBase::operator==(const SafeContextBase& other) const noexcept
	{
		return (this == &other);
	};

	SafeContextBase& SafeContextBase::constructInstanceOnMemoryHeap()
	{
		return *(new SafeContextBase());
	};

	SafeContextBase* SafeContextBase::allocateArrayOnMemoryHeap(const size_t& arraySize)
	{
		return new SafeContextBase[arraySize];
	};

	SafeContextBase* SafeContextBase::allocateChunkOnMemoryHeap(const size_t& chunkCardinality)
	{
		SafeContextBase* memoryChunkPointer = static_cast<SafeContextBase*>(::operator new(sizeof(SafeContextBase) * chunkCardinality));
		size_t i = 0;

		for (i = 0;i < chunkCardinality;i++)
		{
			::new (&(memoryChunkPointer[i])) SafeContextBase(false);
		}

		SafeMemoryManager::StaticMemoryManager.emplaceChunk(memoryChunkPointer,chunkCardinality);

		return memoryChunkPointer;
	};

	void SafeContextBase::destructInstanceOnMemoryHeap(SafeContextBase* const instancePointer) noexcept
	{
		SafeMemoryManager::setClassification(false);
		SafeMemoryManager::StaticMemoryManager.displaceInstance(instancePointer);
		::delete instancePointer;
		SafeMemoryManager::setClassification(true);
	};

	void SafeContextBase::deallocateArrayOnMemoryHeap(SafeContextBase* const arrayPointer) noexcept
	{
		SafeMemoryManager::setClassification(false);
		SafeMemoryManager::StaticMemoryManager.displaceArray(arrayPointer);
		::delete[] arrayPointer;
		SafeMemoryManager::setClassification(true);
	};

	void SafeContextBase::deallocateChunkOnMemoryHeap(SafeContextBase* const chunkPointer) noexcept
	{
		SafeMemoryManager::setClassification(false);
		SafeMemoryManager::StaticMemoryManager.displaceChunk(chunkPointer);
		::delete chunkPointer;
		SafeMemoryManager::setClassification(true);
	};

	const SafeContextBase* SafeContextBase::referToDefaultConstantInstance(const type_info& typeInformation)
	{
		return SafeMemoryManager::StaticMemoryManager.referToDefaultConstantInstance(typeInformation);
	};

	void SafeContextBase::supplementDefaultPolymorphicInstance(const SafeContextBase* defaultedInstancePointer)
	{
		SafeMemoryManager::StaticMemoryManager.supplementDefaultPolymorphicInstance(defaultedInstancePointer);
	};

	void SafeContextBase::reconstructSafely(SafeContextBase* const instancePointer,const SafeConstructionInvoker& constructionInvoker)
	{
		SafeMemoryManager::reconstructSafely(instancePointer,constructionInvoker);
	};

	void SafeContextBase::helpInitializeChunk(vector<SafeContextBase*>& chunkBufferElementPointers,const size_t& cardinality,const vector<const void*>& constantPointerMasks,const vector<void*>& variablePointerMasks,const SafeConstructionInvoker& constructionInvoker)
	{
		SafeMemoryManager::helpInitializeChunk(chunkBufferElementPointers,cardinality,constantPointerMasks,variablePointerMasks,constructionInvoker);
	};

	void SafeContextBase::destroyDerivedChunkOnMemoryHeap(const std::vector<SafeContextBase*>& chunkBufferElementPointers,const std::size_t& cardinality,std::vector<const void*>& constantPointerMasks,std::vector<void*>& variablePointerMasks)
	{
		SafeMemoryManager::helpDestroyChunk(chunkBufferElementPointers,cardinality,constantPointerMasks,variablePointerMasks);
	};

	void SafeContextBase::helpDisposeChunk(const vector<SafeContextBase*>& chunkBufferElementPointers,const size_t& cardinality,vector<const void*>& constantPointerMasks,vector<void*>& variablePointerMasks,const void* const constantProxyInstancePointer,void* const variableProxyInstancePointer)
	{
		SafeMemoryManager::helpDisposeChunk(chunkBufferElementPointers,cardinality,constantPointerMasks,variablePointerMasks,constantProxyInstancePointer,variableProxyInstancePointer);
	};

	SafeContextBase* SafeContextBase::upcycle(const type_info& typeInformation)
	{
		return SafeMemoryManager::StaticMemoryManager.upcycle(typeInformation);
	};

	void SafeContextBase::finalize(SafeContextBase*& pointer) noexcept
	{
		pointer = nullptr;
	};

	void SafeContextBase::recycle(SafeContextBase& instanceReference)
	{
		SafeMemoryManager::StaticMemoryManager.recycle(instanceReference);
	};

	void SafeContextBase::recycle(SafeContextBase* const instancePointer)
	{
		SafeMemoryManager::StaticMemoryManager.recycle(instancePointer);
	};

	size_t SafeContextBase::getMemorySize() const noexcept
	{
		return sizeof(*this);
	};

	const type_info& SafeContextBase::getTypeInfo() const noexcept
	{
		return typeid(*this);
	};

	size_t SafeContextBase::getHashCode() const noexcept
	{
		return typeid(*this).hash_code();
	};
};