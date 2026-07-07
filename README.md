# Safe
**Safe** is a runtime library that defines a safe context for C++.
It tracks every heap-allocated instance of types that inherit from `Safe::SafeContextBase` and offers recycling/repurpose mechanisms, using only C++ standard library.

## 📥 Download & Installation
Download the library package for your platform.
Extract the package to your project directory and specify the paths to the library's header files. Link to the library files (`.sll`,`.dll`, `.a` or `.so`) by adding to the dependency inputs. If you want to use the dynamic library, copy the library file(s) to the folder(s) of the output executable(s).


> [!NOTE]
On Windows, in order to avoid the confusion between the `.lib` files that go with `.dll` in dynamic libraries, `Safe` will use `.sll` as the file extension for static libraries. Linking to the static libraries with `.sll` extension is fine like linking to `.lib` files in other projects. All library packages are thoroughly scanned with ESET Smart Security Premium on a Windows 10 environment prior to release to ensure they are free of malicious code.


## 📖 Reference & Guide
Navigate to [Reference](Safe/Reference.md) to view API reference and [Guide](Safe/Guide.md) to view guide.


## 💡 Examples
```c++
class Example : public Safe::SafeContextBase //or `class Example safe`
{
public:
	Example()
	{
		
	};
	Example(const Example& other) noexcept
	{
		
	};
	Example(Example&& other) noexcept
	{
		
	};
	~Example() override = default;


	Example& operator=(const Example& other) noexcept
	{
		return *this;
	};

	Example& operator=(Example&& other) noexcept
	{
		return *this;
	};
};

int main()
{
	Example* pointer = ::new Example();
	Example* anotherPointer = ::new Example();
	Example* pointerAlias = pointer;
	Safe::SafeContextBase::recycle(dynamic_cast<Safe::SafeContextBase*>(pointer)); // `pointer` is no longer meaningful after recycling.
	Example& repurposedReference = Safe::SafeContextBase::repurpose<Example>();
	// No need to deallocate via `pointer`, `anotherPointer` or `pointerAlias` anymore. Doing so will lead to program termination or even compilation error(s).

	return 0;
};
```

## ✍️ Authors
	Duc Nguyen (https://www.github.com/QuantumBoy1010/)


## 🛠️ Feedback & Error reports

This project is a result of ongoing research. If you encounter any issues, find a bug in the headers, or have suggestions for performance improvements, your feedback is highly valued!

* **GitHub Issues:** Please use the [Issues](https://github.com/QuantumBoy1010/Safe/issues) tab to report technical errors or bugs.
* **Email:** For detailed feedback or private inquiries, feel free to reach out to me directly at **workofduc@gmail.com**.
* **Feature Requests:** If you have a specific use case that the current runtime doesn't cover, I'd love to hear about it.
 

## 💖 Support the Project

If you find this runtime library useful for your research or hobby projects, consider supporting my work. Your sponsorship helps me dedicate more time to optimizing memory management research, fixing errors and keeping the engine up to date.

* **[Sponsor on GitHub](https://github.com/sponsors/duc18020319)**


## ⚖️ Legal & Licensing Information

Required Notice: Copyright©2026, Nguyễn Anh Đức (workofduc@gmail.com)

`Safe--Cpp` is dual-licensed to accommodate both open-source development and proprietary commercial use:

* **Open-Source Track (GPLv3):** This project is licensed under the **GNU General Public License v3**. It is 100% free and open for personal study, academic research, and open-source projects. In accordance with the GPLv3, any software that integrates this library under this track must also have its full source code made public.
* **Commercial Track:** For commercial entities wishing to embed `Safe--Cpp` into proprietary, closed-source software, a separate commercial license is required. This grants you the legal right to use the library without being bound by the GPLv3 copyleft requirements.

For commercial licensing inquiries, pricing, or to obtain a proprietary license agreement, please contact: **workofduc@gmail.com**.
