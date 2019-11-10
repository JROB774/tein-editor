#pragma once

// We don't care about external library warnings as we can't fix them.
#if   defined(COMPILER_MSVC)
#pragma warning(push, 0)
#elif defined(COMPILER_GCC)
#pragma GCC system_header
#elif defined(COMPILER_CLANG)
#pragma clang system_header
#endif

#define GLL_IMPLEMENTATION
#define GLL_STATIC

#if defined(DEBUG_BUILD)
#define GLL_DEBUG_BUILD
#endif

#include "GLL/GLL.h"

#include "GLM/glm.hpp"
#include "GLM/gtc/matrix_transform.hpp"
#include "GLM/gtc/type_ptr.hpp"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#define STB_RECT_PACK_IMPLEMENTATION

#define STB_IMAGE_WRITE_STATIC
#define STB_IMAGE_STATIC
#define STBRP_STATIC

#include "STB/stb_image_write.h"
#include "STB/stb_image.h"
#include "STB/stb_rect_pack.h"

#include "FT2/ft2build.h"
#include FT_FREETYPE_H

// This is only needed in console/debug based builds of the application.
// If it is enabled in a release build then the compiler will complain.
#if defined(DEBUG_BUILD)
#define SDL_MAIN_HANDLED
#endif

#include "SDL2/SDL.h"
#include "SDL2/SDL_syswm.h"

#define CURL_STATICLIB
#include "CURL/curl.h"

#include "JSON/json.hpp"

#include "GON/gon.h"
#include "GON/gon.cpp"

#if defined(COMPILER_MSVC)
#pragma warning(pop)
#endif
