
**extract-xiso**

All credits remain with origional author: <in@fishtank.com>


This is a modernized code base of extract-xiso using C++17 and 64 bit data types
where needed to fix some crash issues with using the -c switch with certain extracted xiso images.


**Note:** This build is Windows specific, the cross platform directives have been stripped out and MSVC modern path handling added, The conversion was done using Codex with specific instructions which were achieved and reflected below.  It is supplied as a Visual Studio 2022 solution.  The solution properties should work with VS2026 as long as you don't change it from c++17.  I have not tested it on anything newer than VS2022



**List of changes**

Reworked AVL code using std::map
Added std::filesystem  
Added RAII file-descriptor ownership via unique_fd  
Added explicit int64_t Xbox offsets and image-bound checks.  
Replaced getopt parsing with a std::string_view C++17 parser.  
Preserved 32-bit on-disc file-size fields required by XISO  
Removed all Non windows compiler, and endian conditional branches.  
Replaced compatibility aliases with native Windows CRT calls.  
Simplified CMake to a Windows C++17 target.  
Converted win32/asprintf.c to an unconditional Windows implementation.  
Changed the banner target to win64.  
Removed obsolete #if 0 blocks.  
Fixed a Win64-unsafe integer-to-pointer callback cast.  
Retained only non-platform #if DEBUG guards.  




