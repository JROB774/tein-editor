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

#define cstd_malloc( t_,      sz_) (t_*)malloc ((sz_)      *sizeof(t_))
#define cstd_realloc(t_, pt_, sz_) (t_*)realloc((pt_),(sz_)*sizeof(t_))
#define cstd_calloc( t_,      sz_) (t_*)calloc ((sz_),      sizeof(t_))
#define cstd_free(       pt_)             free ((pt_))

// Casting macros to easily search for and locate any casting in the code.

#define SCAST(t_, x_) (static_cast     <(t_)>(x_))
#define DCAST(t_, x_) (dynamic_cast    <(t_)>(x_))
#define RCAST(t_, x_) (reinterpret_cast<(t_)>(x_))
#define CCAST(t_, x_) (const_cast      <(t_)>(x_))

#define CAST( t_, x_) ((t_)(x_))

// Custom assert implementation that is toggled via the DEBUG_BUILD define.

#if defined(DEBUG_BUILD)
#include <cassert>
#define ASSERT(e_) assert(e_)
#else
#define ASSERT(e_) ((void)0)
#endif

// The static_assert feature was not implemented until C++17 so if that is not
// available we implement a similar behaviour using a negative index error.
// Unfortunately, this more hacky version will not have a custom error message.

#if defined(COMPILER_SUPPORTS_STDCPP17)
#define STATIC_ASSERT(e_, ...) static_assert(e_, __VA_ARGS__)
#else
#define STATIC_ASSERT(e_, ...) typedef char STATIC_ASSERT__[(e_)?1:-1];
#endif

// Useful method for easily getting the size of a statically allocated array.
//
// We don't use the lambda version in release builds because we will not need
// the static assert. So instead we just do the size-of calculation directly.

#if defined(DEBUG_BUILD)
#define STATIC_ARRAY_COUNT(array_)                              \
[] () constexpr -> size_t                                       \
{                                                               \
STATIC_ASSERT(std::is_array<decltype(array_)>::value,           \
  "STATIC_ARRAY_COUNT requires a statically allocated array!"); \
return (sizeof(array_) / sizeof((array_)[0]));                  \
}()
#else
#define STATIC_ARRAY_COUNT(array_) (sizeof(array_) / sizeof((array_)[0]))
#endif

// Allows for code to be deferred to the end of scope for later execution.
// An example of the syntax for using the custom defer macro utility is:
//
// defer { /* Code to defer! */ };
//
// This allows for a clear and easy method of executing tasks during scope
// exit -- often including freeing memory, other resources, and whatever.

#define DEFER_CONCAT1(a_, b_) a_##b_
#define DEFER_CONCAT2(a_, b_) DEFER_CONCAT1(a_, b_)

#define defer \
const auto& DEFER_CONCAT2(defer, __LINE__) = utility::Defer_Help() + [&]()

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
FORCEINLINE bool operator== (const Vec2_Base<T>& a_, const Vec2_Base<T>& b_);
template<typename T>
FORCEINLINE bool operator!= (const Vec2_Base<T>& a_, const Vec2_Base<T>& b_);

template<typename T>
FORCEINLINE bool operator== (const Vec3_Base<T>& a_, const Vec3_Base<T>& b_);
template<typename T>
FORCEINLINE bool operator!= (const Vec3_Base<T>& a_, const Vec3_Base<T>& b_);

template<typename T>
FORCEINLINE bool operator== (const Vec4_Base<T>& a_, const Vec4_Base<T>& b_);
template<typename T>
FORCEINLINE bool operator!= (const Vec4_Base<T>& a_, const Vec4_Base<T>& b_);

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

    FORCEINLINE void     push   (const T& val_);
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

STDDEF int show_alert (const char* title_, const char* msg_, int type_,
                       int buttons_, std::string window_=std::string());

// Retrieve specific paths on the system that are of importance to the program.

STDDEF std::string get_executable_path ();

// Functions for opening various types of operating system dialog windows.

enum Dialog_Type { DIALOG_TYPE_LVL, DIALOG_TYPE_CSV, DIALOG_TYPE_LVL_AND_CSV, DIALOG_TYPE_GPAK, DIALOG_TYPE_EXE };

STDDEF std::vector<std::string> open_dialog (Dialog_Type type_, bool multiselect_=true);
STDDEF std::string              save_dialog (Dialog_Type type_);
STDDEF std::vector<std::string> path_dialog (                   bool multiselect_=true);

// Various file system operations for operating on and manipulating files/dirs.

FILDEF size_t          get_size_of_file        (const char* file_name_);
FILDEF size_t          get_size_of_file        (FILE* file_);

FILDEF bool            does_file_exist         (const char* file_name_);
FILDEF bool            does_path_exist         (const char* path_);

STDDEF void            list_path_content       (const char* path_, std::vector<std::string>& content_);
STDDEF void            list_path_content_r     (const char* path_, std::vector<std::string>& content_);

STDDEF void            list_path_files         (const char* path_, std::vector<std::string>& files_);
STDDEF void            list_path_files_r       (const char* path_, std::vector<std::string>& files_);

FILDEF bool            create_path             (const char* path_);

FILDEF bool            is_path_absolute        (const char* path_);

FILDEF bool            is_file                 (const char* file_name_);
FILDEF bool            is_path                 (const char* path_);

FILDEF u64             last_file_write_time    (const char* file_name_);

FILDEF std::string     make_path_absolute      (const char* path_);
FILDEF std::string     fix_path_slashes        (const char* path_);

STDDEF char*           read_entire_file        (const char* file_name_);
STDDEF std::string     read_entire_file_str    (const char* file_name_);
STDDEF std::vector<u8> read_binary_file        (const char* file_name_);

FILDEF std::string     strip_file_path         (const char* file_name_);
FILDEF std::string     strip_file_ext          (const char* file_name_);
FILDEF std::string     strip_file_path_and_ext (const char* file_name_);
FILDEF std::string     strip_file_name         (const char* file_name_);

// Miscellaneous utility functions that don't really have anywhere else to go.

FILDEF void         tokenize_string (const std::string& str_, const char* delims_, std::vector<std::string>& tokens_);

INLDEF std::string  format_string   (const char* format_, ...);
INLDEF std::string  format_string_v (const char* format_, va_list args_);

FILDEF int          get_line_count  (const char* str_);

FILDEF Vec2         get_mouse_pos   ();

INLDEF std::string  format_time     (const char* format_);

FILDEF unsigned int get_thread_id   ();

FILDEF bool         point_in_bounds_xyxy (Vec2 p_, float x1_, float y1_, float x2_, float y2_);
FILDEF bool         point_in_bounds_xyxy (Vec2 p_, Quad q_);
FILDEF bool         point_in_bounds_xywh (Vec2 p_, float x_,  float y_,  float w_,  float h_);
FILDEF bool         point_in_bounds_xywh (Vec2 p_, Quad q_);

FILDEF bool         insensitive_compare  (const std::string& a_, const std::string& b_);

FILDEF bool         string_replace       (std::string& str_, const std::string& from_, const std::string& to_);

FILDEF void         play_error_sound   ();
FILDEF void         play_warning_sound ();

FILDEF void         run_executable (const char* exe_);
FILDEF void         load_webpage   (const char* url_);
