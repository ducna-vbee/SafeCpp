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
#include <utility>

/** Inclusion(s) of project's C++ header file(s).**/
#include "SafeContextBase.h"
#include "SafeEvent.h"

/** Inclusion(s) of the standard C++ namespace(s).**/
using namespace std;


/** Main code.**/

namespace Safe
{
	SafeEvent::SafeEvent() : SafeContextBase()
	{
		this->cancellation = false;
		this->occurrence = []() -> void
		{

		};
	};
	SafeEvent::SafeEvent(const SafeEventOccurrence& occurrence) : SafeContextBase()
	{
		this->cancellation = false;
		this->occurrence = occurrence;
	};
	SafeEvent::SafeEvent(const SafeEvent& other) : SafeContextBase(static_cast<const SafeContextBase&>(other))
	{
		this->cancellation = false;
		this->occurrence = other.occurrence;
	};
	SafeEvent::SafeEvent(SafeEventOccurrence&& occurrence) : SafeContextBase()
	{
		this->cancellation = false;
		this->occurrence = move(occurrence);
	};
	SafeEvent::SafeEvent(SafeEvent&& other) noexcept(false) : SafeContextBase(static_cast<SafeContextBase&&>(other))
	{
		this->cancellation = move(other.cancellation);
		this->occurrence = move(other.occurrence);
	};
	SafeEvent::~SafeEvent() noexcept(false) = default;


	SafeEvent& SafeEvent::operator=(const SafeEvent& other)
	{
		if (this != &other)
		{
			SafeContextBase::operator=(static_cast<const SafeContextBase&>(other));
			this->cancellation = false;
			this->occurrence = other.occurrence;
		}

		return *this;
	};

	SafeEvent& SafeEvent::operator=(SafeEvent&& other) noexcept(false)
	{
		if (this != &static_cast<const SafeEvent&>(other))
		{
			SafeContextBase::operator=(static_cast<SafeContextBase&&>(other));
			this->cancellation = move(other.cancellation);
			this->occurrence = move(other.occurrence);
		}

		return *this;
	};

	bool SafeEvent::getCancellation() const noexcept
	{
		return this->cancellation;
	};

	void SafeEvent::setCancellation(const bool& cancellation) noexcept
	{
		this->cancellation = cancellation;
	};

	void SafeEvent::setCancellation(bool&& cancellation) noexcept
	{
		this->cancellation = move(cancellation);
	};

	SafeEvent::SafeEventOccurrence SafeEvent::getOccurrence() const
	{
		return this->occurrence;
	};

	void SafeEvent::setOccurrence(const SafeEventOccurrence& occurrence)
	{
		this->occurrence = occurrence;
	};

	void SafeEvent::setOccurrence(SafeEventOccurrence&& occurrence) noexcept
	{
		this->occurrence = move(occurrence);
	};

	void SafeEvent::broadcast()
	{
		this->cancellation = false;

		while (true)
		{
			(this->occurrence)();

			if (this->cancellation == true)
			{
				break;
			}
		}
	};

	void SafeEvent::cancel() noexcept
	{
		this->cancellation = true;
	};

	void SafeEvent::raise() noexcept
	{
		if (this->cancellation == true)
		{
			this->broadcast();
		}
	};

	void SafeEvent::abrogate() noexcept
	{
		if (this->cancellation == false)
		{
			this->cancel();
		}
	};
};
