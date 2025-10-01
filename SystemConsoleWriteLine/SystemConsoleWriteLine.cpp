/*
to use System::Console::WriteLine, you must use .NET C++/CLI/CX (C++ Common Language Infrastructure) (C++ Component eXtensions).
for native C++, System::Console is not available. You can only use std::cout.
if you want to use C++/CLI/CX, change the file extension to .cpp and compile with /clr.
*/
/*#pragma unmanaged*/
#include <iostream>
using namespace std;

#ifdef _MANAGED
   #pragma managed(push, off)
   #pragma managed(pop)
   using namespace System; /*for.NET C++ / CLI / CX Console::WriteLine*/
#endif

int main() {
	string string = "";
   std::string string2 = "";

   if (string == "") {
      cout << "string" << endl;
	}

	std::cout << "Hello world from native c++ multi platform OS Linux also.\n";
   /*
   #ifdef is a conditional compile cl -D .NET C++/CLI/CXspecifics:
   the _MANAGED macro is specifically defined by the Microsoft Visual C++ compiler (MSVC) when compiling code with the /clr option, which enables C++/CLI/CX extensions.
   C++/CLI/CX allows interoperability between native C++ code and managed .NET code.
   */
   #ifdef _MANAGED
      using namespace System; /*for .NET C++ / CLI / CX Console::WriteLine*/

      string = ".NET C++/CLI/CX";

      /*
		String a; no default constructor exists for class "System::String"
                'System::String': cannot use this type here without a top-level '^'
      handle declarator ^
      pointer *
      reference &
      */
      String ^ b; /*fix the dot with String ^ b = nullptr;*/
		String ^ a = nullptr;
      a = ".NET C++/CLI/CX"; /*String ^ can be directly assigned from a string literal*/
		
      /*
      System::String ^ String = ""; is a syntactic sugar provided by C++/CLI for creating an empty System::String ^ from a string literal.
      The compiler handles the gcnew and constructor call implicitly.
      System::String ^ String = gcnew System::String("");) is the explicit way to create an empty System::String ^ using the gcnew operator and a constructor call.
      */
      String ^ c = "from .NET C++/CLI/CX"; /*String ^ can be directly assigned from a string literal*/
      /*String::Empty is a static property that returns an empty string. It is equivalent to gcnew String("") but more efficient.*/
      String ^ d = String::Empty;
      /*
      gcnew is an operator for allocating memory, just like the new operator, except you don't need to delete anything created with it; it's garbage collected.
      You use gcnew for creating .Net managed types, and new for creating unmanaged types.

      'System::String': cannot use 'new' on the reference type; use 'gcnew' instead
      'initializing': cannot convert from 'System::String *' to 'System::String ^'
		System::String ^ String = new System::String("");
      */
		System::String ^ String = gcnew System::String(".NET C++/CLI/CX"); /* conversion from char* to System::String^ */
      /*conversion from std::string to System::String^*/
      System::String ^ dotnetString2 = gcnew System::String(string2.c_str());
      /*object handling : System::Console::WriteLine can directly handle .NET objects (like System::String^)*/

      System::Console::WriteLine("Hello world from .NET C++/CLI and C++/CX.");
   #endif
}