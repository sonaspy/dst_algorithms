#ifndef _BACKWARD_IOSTREAM_H
#define _BACKWARD_IOSTREAM_H 1

#include <iostream>

using std::ios;
using std::iostream;
using std::istream;
using std::ostream;
using std::streambuf;

using std::cerr;
using std::cin;
using std::clog;
using std::cout;
#ifdef _GLIBCXX_USE_WCHAR_T
using std::wcerr;
using std::wcin;
using std::wclog;
using std::wcout;
#endif

using std::endl;
using std::ends;
using std::flush;
using std::ws;

#endif