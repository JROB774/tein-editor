#pragma once

// We provide more descriptive definitions of the static keyword to make the
// intent and context surrounding the keyword's usage more clear when reading.

#define GLOBAL     static
#define PERSISTENT static
#define INTERNAL   static
#define SHARED     static

// Forceinline isn't standard and if not available we just use inline instead.

#if   defined(COMPILER_GCC) && (COMPILER_VERSION_MAJOR >= 4)
#define FORCEINLINE __attribute__((always_inline)) static __inline__
#elif defined(COMPILER_MSVC)
#define FORCEINLINE __forceinline
#else
#define FORCEINLINE inline
#endif

// All of the functions in our project should use one of these definitions.
//
// By default we use static functions as we only have one compilation unit so
// by making all functions statically linked we can speed up our build times.

#define STDDEF INTERNAL
#define INLDEF INTERNAL inline
#define FILDEF INTERNAL FORCEINLINE

// Custom defines of C memory allocation functions that handle the cast to
// our desired pointer type, as C++ doesn't support auto cast from a void*.

#define cstd_malloc( _t,      _sz) (_t*)malloc ((_sz)      *sizeof(_t))
#define cstd_realloc(_t, _pt, _sz) (_t*)realloc((_pt),(_sz)*sizeof(_t))
#define cstd_calloc( _t,      _sz) (_t*)calloc ((_sz),      sizeof(_t))
#define cstd_free(       _pt)             free ((_pt))

// Casting macros to easily search for and locate any casting in the code.

#define SCAST(_t, _x) (static_cast     <(_t)>(_x))
#define DCAST(_t, _x) (dynamic_cast    <(_t)>(_x))
#define RCAST(_t, _x) (reinterpret_cast<(_t)>(_x))
#define CCAST(_t, _x) (const_cast      <(_t)>(_x))

#define CAST( _t, _x) ((_t)(_x))

// Simple macros for determining the minimum and maximum of two values.

#define MIN(_a, _b) (((_a) < (_b)) ? (_a) : (_b))
#define MAX(_a, _b) (((_a) < (_b)) ? (_b) : (_a))

// Custom assert implementation that is toggled via the DEBUG_BUILD define.

#if defined(DEBUG_BUILD)
#include <cassert>
#define ASSERT(_e) assert(_e)
#else
#define ASSERT(_e) ((void)0)
#endif

// The static_assert feature was not implemented until C++17 so if that is not
// available we implement a similar behaviour using a negative index error.
// Unfortunately, this more hacky version will not have a custom error message.

#if defined(COMPILER_SUPPORTS_STDCPP17)
#define STATIC_ASSERT(_e, ...) static_assert(_e, __VA_ARGS__)
#else
#define STATIC_ASSERT(_e, ...) typedef char STATIC_ASSERT__[(_e)?1:-1];
#endif

// Useful method for easily getting the size of a statically allocated array.
//
// We don't use the lambda version in release builds because we will not need
// the static assert. So instead we just do the size-of calculation directly.

#if defined(DEBUG_BUILD)
#define STATIC_ARRAY_COUNT(_array)                              \
[] () constexpr -> size_t                                       \
{                                                               \
STATIC_ASSERT(std::is_array<decltype(_array)>::value,           \
  "STATIC_ARRAY_COUNT requires a statically allocated array!"); \
return (sizeof(_array) / sizeof((_array)[0]));                  \
}()
#else
#define STATIC_ARRAY_COUNT(_array) (sizeof(_array) / sizeof((_array)[0]))
#endif

// Allows for code to be deferred to the end of scope for later execution.
// An example of the syntax for using the custom defer macro utility is:
//
// defer { /* Code to defer! */ };
//
// This allows for a clear and easy method of executing tasks during scope
// exit -- often including freeing memory, other resources, and whatever.

#define DEFER_CONCAT1(_a, _b) _a##_b
#define DEFER_CONCAT2(_a, _b) DEFER_CONCAT1(_a, _b)

#define defer \
const auto& DEFER_CONCAT2(defer, __LINE__) = Defer_Help() + [&]()

// Do not use this directly and instead use the defer macro!
template<typename T>
struct Defer
{
    T lambda;

             Defer   (T _lambda): lambda(_lambda) { /* Nothing! */ }
            ~Defer   ()                           {    lambda();   }

             Defer   (const Defer& _defer) = delete;
    Defer& operator= (const Defer& _defer) = delete;
};
struct Defer_Help
{
    template<typename T>
    Defer<T> operator+ (T _type) { return _type; }
};

// Short-hand fixed-width integral types that are faster to frequently type.

typedef uint8_t   u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t    s8;
typedef int16_t  s16;
typedef int32_t  s32;
typedef int64_t  s64;

// Lightweight multi-component vector structures that can be accessed using
// either the XYZW, RGBA, or STPQ component names based on the vector's use.

template<typename T>
struct Vec2_Base
{
    STATIC_ASSERT(std::is_arithmetic<T>::value, "Vec2 needs arithmetic type!");

    union { T x, r, s; };
    union { T y, g, t; };
};

template<typename T>
struct Vec3_Base
{
    STATIC_ASSERT(std::is_arithmetic<T>::value, "Vec3 needs arithmetic type!");

    union { T x, r, s; };
    union { T y, g, t; };
    union { T z, b, p; };
};

template<typename T>
struct Vec4_Base
{
    STATIC_ASSERT(std::is_arithmetic<T>::value, "Vec4 needs arithmetic type!");

    union { T x, r, s; };
    union { T y, g, t; };
    union { T z, b, p; };
    union { T w, a, q; };
};

// Simple comparison operators for the various multi-dimensional vector types.

template<typename T>
FORCEINLINE bool operator== (const Vec2_Base<T>& _a, const Vec2_Base<T>& _b);
template<typename T>
FORCEINLINE bool operator!= (const Vec2_Base<T>& _a, const Vec2_Base<T>& _b);

template<typename T>
FORCEINLINE bool operator== (const Vec3_Base<T>& _a, const Vec3_Base<T>& _b);
template<typename T>
FORCEINLINE bool operator!= (const Vec3_Base<T>& _a, const Vec3_Base<T>& _b);

template<typename T>
FORCEINLINE bool operator== (const Vec4_Base<T>& _a, const Vec4_Base<T>& _b);
template<typename T>
FORCEINLINE bool operator!= (const Vec4_Base<T>& _a, const Vec4_Base<T>& _b);

// Short-hand type defintions for various types of multi-dimensional vector.

typedef Vec2_Base<int>          Vec2i;
typedef Vec2_Base<unsigned int> Vec2u;
typedef Vec2_Base<float>        Vec2f;
typedef Vec2_Base<double>       Vec2d;
typedef Vec2_Base<long double>  Vec2l;
typedef Vec2_Base<bool>         Vec2b;

typedef Vec3_Base<int>          Vec3i;
typedef Vec3_Base<unsigned int> Vec3u;
typedef Vec3_Base<float>        Vec3f;
typedef Vec3_Base<double>       Vec3d;
typedef Vec3_Base<long double>  Vec3l;
typedef Vec3_Base<bool>         Vec3b;

typedef Vec4_Base<int>          Vec4i;
typedef Vec4_Base<unsigned int> Vec4u;
typedef Vec4_Base<float>        Vec4f;
typedef Vec4_Base<double>       Vec4d;
typedef Vec4_Base<long double>  Vec4l;
typedef Vec4_Base<bool>         Vec4b;

// The default type used for vectors is float so we also have these defaults.

typedef Vec2_Base<float>        Vec2;
typedef Vec3_Base<float>        Vec3;
typedef Vec4_Base<float>        Vec4;

// Some basic primitive shape-based data structures for easily passing data.

struct Point { float x,  y;          };
struct Line  { float x1, y1, x2, y2; };

struct Quad
{
    union { float x, l, x1, left;   };
    union { float y, t, y1, top;    };
    union { float w, r, x2, right;  };
    union { float h, b, y2, bottom; };
};

// Simple and easy to use statically-allocated generic stack container type.

template<typename T, size_t N>
struct Stack
{
    SHARED constexpr size_t CAPACITY = N;

    T      data[N] = {};
    size_t count   = 0;

    FORCEINLINE void     push   (const T& _val);
    FORCEINLINE T        pop    ();
    // Get the current top element but do not pop it.
    FORCEINLINE T&       peek   ();
    FORCEINLINE const T& peek   () const;
};

// Platform-independent system for displaying alert messages/boxes to user.
// Currently we only have a Windows version implemented but can be expanded.

#if defined(PLATFORM_WINNT)
// We just map these alert constants directly to the Win32 API equivalents.
GLOBAL constexpr int ALERT_BUTTON_OK            = MB_OK;
GLOBAL constexpr int ALERT_BUTTON_OK_CANCEL     = MB_OKCANCEL;
GLOBAL constexpr int ALERT_BUTTON_YES_NO        = MB_YESNO;
GLOBAL constexpr int ALERT_BUTTON_YES_NO_CANCEL = MB_YESNOCANCEL;
GLOBAL constexpr int ALERT_TYPE_INFO            = MB_ICONINFORMATION;
GLOBAL constexpr int ALERT_TYPE_WARNING         = MB_ICONWARNING;
GLOBAL constexpr int ALERT_TYPE_ERROR           = MB_ICONERROR;
GLOBAL constexpr int ALERT_RESULT_NULL          = NULL;
GLOBAL constexpr int ALERT_RESULT_OK            = IDOK;
GLOBAL constexpr int ALERT_RESULT_YES           = IDYES;
GLOBAL constexpr int ALERT_RESULT_NO            = IDNO;
GLOBAL constexpr int ALERT_RESULT_CANCEL        = IDCANCEL;
#endif // PLATFORM_WINNT

// This functions needs to know what a window struct is in order to be used.
struct Window;

STDDEF int show_alert (const char* _title, const char* _msg, int _type,
                       int _buttons, std::string _window=std::string());

// Retrieve specific paths on the system that are of importance to the program.

STDDEF std::string get_executable_path ();

// Functions for opening various types of operating system dialog windows.

enum Dialog_Type { DIALOG_TYPE_LVL, DIALOG_TYPE_CSV, DIALOG_TYPE_LVL_AND_CSV, DIALOG_TYPE_GPAK, DIALOG_TYPE_EXE };

STDDEF std::vector<std::string> open_dialog (Dialog_Type _type, bool _multiselect=true);
STDDEF std::string              save_dialog (Dialog_Type _type);
STDDEF std::vector<std::string> path_dialog (                   bool _multiselect=true);

// Various file system operations for operating on and manipulating files/dirs.

FILDEF size_t          get_size_of_file        (const char* _file_name);
FILDEF size_t          get_size_of_file        (FILE* _file);

FILDEF bool            does_file_exist         (const char* _file_name);
FILDEF bool            does_path_exist         (const char* _path);

STDDEF void            list_path_content       (const char* _path, std::vector<std::string>& _content);
STDDEF void            list_path_content_r     (const char* _path, std::vector<std::string>& _content);

STDDEF void            list_path_files         (const char* _path, std::vector<std::string>& _files);
STDDEF void            list_path_files_r       (const char* _path, std::vector<std::string>& _files);

FILDEF bool            create_path             (const char* _path);

FILDEF bool            is_path_absolute        (const char* _path);

FILDEF bool            is_file                 (const char* _file_name);
FILDEF bool            is_path                 (const char* _path);

FILDEF u64             last_file_write_time    (const char* _file_name);

FILDEF std::string     make_path_absolute      (const char* _path);
FILDEF std::string     fix_path_slashes        (const char* _path);

STDDEF char*           read_entire_file        (const char* _file_name);
STDDEF std::string     read_entire_file_str    (const char* _file_name);
STDDEF std::vector<u8> read_binary_file        (const char* _file_name);

FILDEF std::string     strip_file_path         (const char* _file_name);
FILDEF std::string     strip_file_ext          (const char* _file_name);
FILDEF std::string     strip_file_path_and_ext (const char* _file_name);
FILDEF std::string     strip_file_name         (const char* _file_name);

// Miscellaneous utility functions that don't really have anywhere else to go.

FILDEF void         tokenize_string (const std::string& _str, const char* _delims, std::vector<std::string>& _tokens);

INLDEF std::string  format_string   (const char* _format, ...);
INLDEF std::string  format_string_v (const char* _format, va_list _args);

FILDEF int          get_line_count  (const char* _str);

FILDEF Vec2         get_mouse_pos   ();

INLDEF std::string  format_time     (const char* _format);

FILDEF unsigned int get_thread_id   ();

FILDEF bool         point_in_bounds_xyxy (Vec2 _p, float _x1, float _y1, float _x2, float _y2);
FILDEF bool         point_in_bounds_xyxy (Vec2 _p, Quad _q);
FILDEF bool         point_in_bounds_xywh (Vec2 _p, float _x,  float _y,  float _w,  float _h);
FILDEF bool         point_in_bounds_xywh (Vec2 _p, Quad _q);

FILDEF bool         insensitive_compare  (const std::string& _a, const std::string& _b);

FILDEF bool         string_replace       (std::string& _str, const std::string& _from, const std::string& _to);

FILDEF void         play_error_sound   ();
FILDEF void         play_warning_sound ();

FILDEF void         run_executable (const char* _exe);
FILDEF void         load_webpage   (const char* _url);
