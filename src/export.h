#ifndef EXPORT_H
#define EXPORT_H

#ifdef LIBRARY_EXPORT
#define SHARED __declspec(dllexport)
#else
#define SHARED __declspec(dllimport)
#endif

#if __cplusplus >= 201703L
#define CXX17
#endif

#endif // EXPORT_H
