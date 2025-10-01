#include <iostream>
// To use System::Console::WriteLine, you must use C++/CLI (.NET) and include the proper header.
// For native C++, System::Console is not available. You can only use std::cout.
// If you want to use C++/CLI, change the file extension to .cpp and compile with /clr.
// Example for C++/CLI:
int main() {
   std::cout << "Hello world from native c++ multi platform OS Linux also.\n";
   /*
   #ifdef is a conditional compile cl -D .NET C++/CLI/CX (C++ Common Language Infrastructure) (C++ Component eXtensions) specifics:
   the _MANAGED macro is specifically defined by the Microsoft Visual C++ compiler (MSVC) when compiling code with the /clr option, which enables C++/CLI/CX extensions.
   C++/CLI/CX allows interoperability between native C++ code and managed .NET code.
   */
   #ifdef _MANAGED
      System::Console::WriteLine("Hello world from .NET C++/CLI and C++/CX.");
   #endif
}