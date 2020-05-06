/*******************************************************************************
 * Modified version of GL headers providing the WGL extension functionality.
 * Copyright (c) 2013-2018 The Khronos Group Inc.
 *
*******************************************************************************/

#ifndef WGL_H__ /*////////////////////////////////////////////////////////////*/
#define WGL_H__

#ifdef COMPILER_HAS_PRAGMA_ONCE
#pragma once
#endif

/*////////////////////////////////////////////////////////////////////////////*/

/* -------------------------------------------------------------------------- */

EXTERN_C_START /***************************************************************/

/* -------------------------------------------------------------------------- */

DECLARE_HANDLE(HPBUFFERARB);
DECLARE_HANDLE(HPBUFFEREXT);
DECLARE_HANDLE(HPGPUNV);
DECLARE_HANDLE(HGPUNV);
DECLARE_HANDLE(HVIDEOOUTPUTDEVICENV);
DECLARE_HANDLE(HVIDEOINPUTDEVICENV);
DECLARE_HANDLE(HPVIDEODEV);

struct _GPU_DEVICE
{
    DWORD cb;
    CHAR  DeviceName   [ 32];
    CHAR  DeviceString [128];
    DWORD Flags;
    RECT  rcVirtualScreen;
};

typedef struct _GPU_DEVICE   GPU_DEVICE;
typedef struct _GPU_DEVICE* PGPU_DEVICE;

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_ARB_buffer_region

#ifndef WGL_ARB_buffer_region
#define WGL_ARB_buffer_region 1

#define WGL_FRONT_COLOR_BUFFER_BIT_ARB    0x00000001
#define WGL_BACK_COLOR_BUFFER_BIT_ARB     0x00000002
#define WGL_DEPTH_BUFFER_BIT_ARB          0x00000004
#define WGL_STENCIL_BUFFER_BIT_ARB        0x00000008

OPENGL_INIT_PROC(wglCreateBufferRegionARB,  HANDLE, HDC hDC, int iLayerPlane, UINT uType);
OPENGL_INIT_PROC(wglDeleteBufferRegionARB,  VOID,   HANDLE hRegion);
OPENGL_INIT_PROC(wglSaveBufferRegionARB,    BOOL,   HANDLE hRegion, int x, int y, int width, int height);
OPENGL_INIT_PROC(wglRestoreBufferRegionARB, BOOL,   HANDLE hRegion, int x, int y, int width, int height, int xSrc, int ySrc);

#define wglCreateBufferRegionARB  OGL__wglCreateBufferRegionARB
#define wglDeleteBufferRegionARB  OGL__wglDeleteBufferRegionARB
#define wglSaveBufferRegionARB    OGL__wglSaveBufferRegionARB
#define wglRestoreBufferRegionARB OGL__wglRestoreBufferRegionARB

#endif // WGL_ARB_buffer_region

#endif // OPENGL_INCLUDE_WGL_ARB_buffer_region

/* -------------------------------------------------------------------------- */

#ifndef WGL_ARB_context_flush_control
#define WGL_ARB_context_flush_control 1

#define WGL_CONTEXT_RELEASE_BEHAVIOR_ARB          0x2097
#define WGL_CONTEXT_RELEASE_BEHAVIOR_NONE_ARB     0
#define WGL_CONTEXT_RELEASE_BEHAVIOR_FLUSH_ARB    0x2098

#endif // WGL_ARB_context_flush_control

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_ARB_create_context

#ifndef WGL_ARB_create_context
#define WGL_ARB_create_context 1

#define WGL_CONTEXT_DEBUG_BIT_ARB                 0x00000001
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB    0x00000002
#define WGL_CONTEXT_MAJOR_VERSION_ARB             0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB             0x2092
#define WGL_CONTEXT_LAYER_PLANE_ARB               0x2093
#define WGL_CONTEXT_FLAGS_ARB                     0x2094
#define ERROR_INVALID_VERSION_ARB                 0x2095

OPENGL_INIT_PROC(wglCreateContextAttribsARB, HGLRC, HDC hDC, HGLRC hShareContext, const int *attribList);
#define wglCreateContextAttribsARB OGL__wglCreateContextAttribsARB

#endif // WGL_ARB_create_context

#endif // OPENGL_INCLUDE_WGL_ARB_create_context

/* -------------------------------------------------------------------------- */

#ifndef WGL_ARB_create_context_no_error
#define WGL_ARB_create_context_no_error 1

#define WGL_CONTEXT_OPENGL_NO_ERROR_ARB    0x31B3

#endif // WGL_ARB_create_context_no_error

/* -------------------------------------------------------------------------- */

#ifndef WGL_ARB_create_context_profile
#define WGL_ARB_create_context_profile 1

#define WGL_CONTEXT_PROFILE_MASK_ARB                 0x9126
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB             0x00000001
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB    0x00000002
#define ERROR_INVALID_PROFILE_ARB                    0x2096

#endif // WGL_ARB_create_context_profile

/* -------------------------------------------------------------------------- */

#ifndef WGL_ARB_create_context_robustness
#define WGL_ARB_create_context_robustness 1

#define WGL_CONTEXT_ROBUST_ACCESS_BIT_ARB              0x00000004
#define WGL_LOSE_CONTEXT_ON_RESET_ARB                  0x8252
#define WGL_CONTEXT_RESET_NOTIFICATION_STRATEGY_ARB    0x8256
#define WGL_NO_RESET_NOTIFICATION_ARB                  0x8261

#endif // WGL_ARB_create_context_robustness

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_ARB_extensions_string

#ifndef WGL_ARB_extensions_string
#define WGL_ARB_extensions_string 1

OPENGL_INIT_PROC(wglGetExtensionsStringARB, const char*, HDC hdc);
#define wglGetExtensionsStringARB OGL__wglGetExtensionsStringARB

#endif // WGL_ARB_extensions_string

#endif // OPENGL_INCLUDE_WGL_ARB_extensions_string

/* -------------------------------------------------------------------------- */

#ifndef WGL_ARB_framebuffer_sRGB
#define WGL_ARB_framebuffer_sRGB 1

#define WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB    0x20A9

#endif // WGL_ARB_framebuffer_sRGB

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_ARB_make_current_read

#ifndef WGL_ARB_make_current_read
#define WGL_ARB_make_current_read 1

#define ERROR_INVALID_PIXEL_TYPE_ARB              0x2043
#define ERROR_INCOMPATIBLE_DEVICE_CONTEXTS_ARB    0x2054

OPENGL_INIT_PROC(wglMakeContextCurrentARB, BOOL, HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
OPENGL_INIT_PROC(wglGetCurrentReadDCARB,   HDC,  void);

#define wglMakeContextCurrentARB OGL__wglMakeContextCurrentARB
#define wglGetCurrentReadDCARB   OGL__wglGetCurrentReadDCARB

#endif // WGL_ARB_make_current_read

#endif // OPENGL_INCLUDE_WGL_ARB_make_current_read

/* -------------------------------------------------------------------------- */

#ifndef WGL_ARB_multisample
#define WGL_ARB_multisample 1

#define WGL_SAMPLE_BUFFERS_ARB    0x2041
#define WGL_SAMPLES_ARB           0x2042

#endif // WGL_ARB_multisample

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_ARB_pbuffer

#ifndef WGL_ARB_pbuffer
#define WGL_ARB_pbuffer 1

#define WGL_DRAW_TO_PBUFFER_ARB       0x202D
#define WGL_MAX_PBUFFER_PIXELS_ARB    0x202E
#define WGL_MAX_PBUFFER_WIDTH_ARB     0x202F
#define WGL_MAX_PBUFFER_HEIGHT_ARB    0x2030
#define WGL_PBUFFER_LARGEST_ARB       0x2033
#define WGL_PBUFFER_WIDTH_ARB         0x2034
#define WGL_PBUFFER_HEIGHT_ARB        0x2035
#define WGL_PBUFFER_LOST_ARB          0x2036

OPENGL_INIT_PROC(wglCreatePbufferARB,    HPBUFFERARB, HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
OPENGL_INIT_PROC(wglGetPbufferDCARB,     HDC,         HPBUFFERARB hPbuffer);
OPENGL_INIT_PROC(wglReleasePbufferDCARB, int,         HPBUFFERARB hPbuffer, HDC hDC);
OPENGL_INIT_PROC(wglDestroyPbufferARB,   BOOL,        HPBUFFERARB hPbuffer);
OPENGL_INIT_PROC(wglQueryPbufferARB,     BOOL,        HPBUFFERARB hPbuffer, int iAttribute, int *piValue);

#define wglCreatePbufferARB    OGL__wglCreatePbufferARB
#define wglGetPbufferDCARB     OGL__wglGetPbufferDCARB
#define wglReleasePbufferDCARB OGL__wglReleasePbufferDCARB
#define wglDestroyPbufferARB   OGL__wglDestroyPbufferARB
#define wglQueryPbufferARB     OGL__wglQueryPbufferARB

#endif // WGL_ARB_pbuffer

#endif // OPENGL_INCLUDE_WGL_ARB_pbuffer

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_ARB_pixel_format

#ifndef WGL_ARB_pixel_format
#define WGL_ARB_pixel_format 1

#define WGL_NUMBER_PIXEL_FORMATS_ARB       0x2000
#define WGL_DRAW_TO_WINDOW_ARB             0x2001
#define WGL_DRAW_TO_BITMAP_ARB             0x2002
#define WGL_ACCELERATION_ARB               0x2003
#define WGL_NEED_PALETTE_ARB               0x2004
#define WGL_NEED_SYSTEM_PALETTE_ARB        0x2005
#define WGL_SWAP_LAYER_BUFFERS_ARB         0x2006
#define WGL_SWAP_METHOD_ARB                0x2007
#define WGL_NUMBER_OVERLAYS_ARB            0x2008
#define WGL_NUMBER_UNDERLAYS_ARB           0x2009
#define WGL_TRANSPARENT_ARB                0x200A
#define WGL_TRANSPARENT_RED_VALUE_ARB      0x2037
#define WGL_TRANSPARENT_GREEN_VALUE_ARB    0x2038
#define WGL_TRANSPARENT_BLUE_VALUE_ARB     0x2039
#define WGL_TRANSPARENT_ALPHA_VALUE_ARB    0x203A
#define WGL_TRANSPARENT_INDEX_VALUE_ARB    0x203B
#define WGL_SHARE_DEPTH_ARB                0x200C
#define WGL_SHARE_STENCIL_ARB              0x200D
#define WGL_SHARE_ACCUM_ARB                0x200E
#define WGL_SUPPORT_GDI_ARB                0x200F
#define WGL_SUPPORT_OPENGL_ARB             0x2010
#define WGL_DOUBLE_BUFFER_ARB              0x2011
#define WGL_STEREO_ARB                     0x2012
#define WGL_PIXEL_TYPE_ARB                 0x2013
#define WGL_COLOR_BITS_ARB                 0x2014
#define WGL_RED_BITS_ARB                   0x2015
#define WGL_RED_SHIFT_ARB                  0x2016
#define WGL_GREEN_BITS_ARB                 0x2017
#define WGL_GREEN_SHIFT_ARB                0x2018
#define WGL_BLUE_BITS_ARB                  0x2019
#define WGL_BLUE_SHIFT_ARB                 0x201A
#define WGL_ALPHA_BITS_ARB                 0x201B
#define WGL_ALPHA_SHIFT_ARB                0x201C
#define WGL_ACCUM_BITS_ARB                 0x201D
#define WGL_ACCUM_RED_BITS_ARB             0x201E
#define WGL_ACCUM_GREEN_BITS_ARB           0x201F
#define WGL_ACCUM_BLUE_BITS_ARB            0x2020
#define WGL_ACCUM_ALPHA_BITS_ARB           0x2021
#define WGL_DEPTH_BITS_ARB                 0x2022
#define WGL_STENCIL_BITS_ARB               0x2023
#define WGL_AUX_BUFFERS_ARB                0x2024
#define WGL_NO_ACCELERATION_ARB            0x2025
#define WGL_GENERIC_ACCELERATION_ARB       0x2026
#define WGL_FULL_ACCELERATION_ARB          0x2027
#define WGL_SWAP_EXCHANGE_ARB              0x2028
#define WGL_SWAP_COPY_ARB                  0x2029
#define WGL_SWAP_UNDEFINED_ARB             0x202A
#define WGL_TYPE_RGBA_ARB                  0x202B
#define WGL_TYPE_COLORINDEX_ARB            0x202C

OPENGL_INIT_PROC(wglGetPixelFormatAttribivARB, BOOL, HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, int *piValues);
OPENGL_INIT_PROC(wglGetPixelFormatAttribfvARB, BOOL, HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, const int *piAttributes, FLOAT *pfValues);
OPENGL_INIT_PROC(wglChoosePixelFormatARB,      BOOL, HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);

#define wglGetPixelFormatAttribivARB OGL__wglGetPixelFormatAttribivARB
#define wglGetPixelFormatAttribfvARB OGL__wglGetPixelFormatAttribfvARB
#define wglChoosePixelFormatARB      OGL__wglChoosePixelFormatARB

#endif // WGL_ARB_pixel_format

#endif // OPENGL_INCLUDE_WGL_ARB_pixel_format

/* -------------------------------------------------------------------------- */

#ifndef WGL_ARB_pixel_format_float
#define WGL_ARB_pixel_format_float 1

#define WGL_TYPE_RGBA_FLOAT_ARB    0x21A0

#endif // WGL_ARB_pixel_format_float

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_ARB_render_texture

#ifndef WGL_ARB_render_texture
#define WGL_ARB_render_texture 1

#define WGL_BIND_TO_TEXTURE_RGB_ARB            0x2070
#define WGL_BIND_TO_TEXTURE_RGBA_ARB           0x2071
#define WGL_TEXTURE_FORMAT_ARB                 0x2072
#define WGL_TEXTURE_TARGET_ARB                 0x2073
#define WGL_MIPMAP_TEXTURE_ARB                 0x2074
#define WGL_TEXTURE_RGB_ARB                    0x2075
#define WGL_TEXTURE_RGBA_ARB                   0x2076
#define WGL_NO_TEXTURE_ARB                     0x2077
#define WGL_TEXTURE_CUBE_MAP_ARB               0x2078
#define WGL_TEXTURE_1D_ARB                     0x2079
#define WGL_TEXTURE_2D_ARB                     0x207A
#define WGL_MIPMAP_LEVEL_ARB                   0x207B
#define WGL_CUBE_MAP_FACE_ARB                  0x207C
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB    0x207D
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB    0x207E
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB    0x207F
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB    0x2080
#define WGL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB    0x2081
#define WGL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB    0x2082
#define WGL_FRONT_LEFT_ARB                     0x2083
#define WGL_FRONT_RIGHT_ARB                    0x2084
#define WGL_BACK_LEFT_ARB                      0x2085
#define WGL_BACK_RIGHT_ARB                     0x2086
#define WGL_AUX0_ARB                           0x2087
#define WGL_AUX1_ARB                           0x2088
#define WGL_AUX2_ARB                           0x2089
#define WGL_AUX3_ARB                           0x208A
#define WGL_AUX4_ARB                           0x208B
#define WGL_AUX5_ARB                           0x208C
#define WGL_AUX6_ARB                           0x208D
#define WGL_AUX7_ARB                           0x208E
#define WGL_AUX8_ARB                           0x208F
#define WGL_AUX9_ARB                           0x2090

OPENGL_INIT_PROC(wglBindTexImageARB,     BOOL, HPBUFFERARB hPbuffer, int iBuffer);
OPENGL_INIT_PROC(wglReleaseTexImageARB,  BOOL, HPBUFFERARB hPbuffer, int iBuffer);
OPENGL_INIT_PROC(wglSetPbufferAttribARB, BOOL, HPBUFFERARB hPbuffer, const int *piAttribList);

#define wglBindTexImageARB     OGL__wglBindTexImageARB
#define wglReleaseTexImageARB  OGL__wglReleaseTexImageARB
#define wglSetPbufferAttribARB OGL__wglSetPbufferAttribARB

#endif // WGL_ARB_render_texture

#endif // OPENGL_INCLUDE_WGL_ARB_render_texture

/* -------------------------------------------------------------------------- */

#ifndef WGL_ARB_robustness_application_isolation
#define WGL_ARB_robustness_application_isolation 1

#define WGL_CONTEXT_RESET_ISOLATION_BIT_ARB    0x00000008

#endif // WGL_ARB_robustness_application_isolation

/* -------------------------------------------------------------------------- */

#ifndef WGL_ARB_robustness_share_group_isolation
#define WGL_ARB_robustness_share_group_isolation 1

#endif // WGL_ARB_robustness_share_group_isolation

/* -------------------------------------------------------------------------- */

#ifndef WGL_3DFX_multisample
#define WGL_3DFX_multisample 1

#define WGL_SAMPLE_BUFFERS_3DFX    0x2060
#define WGL_SAMPLES_3DFX           0x2061

#endif // WGL_3DFX_multisample

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_3DL_stereo_control

#ifndef WGL_3DL_stereo_control
#define WGL_3DL_stereo_control 1

#define WGL_STEREO_EMITTER_ENABLE_3DL     0x2055
#define WGL_STEREO_EMITTER_DISABLE_3DL    0x2056
#define WGL_STEREO_POLARITY_NORMAL_3DL    0x2057
#define WGL_STEREO_POLARITY_INVERT_3DL    0x2058

OPENGL_INIT_PROC(wglSetStereoEmitterState3DL, BOOL, HDC hDC, UINT uState);
#define wglSetStereoEmitterState3DL OGL__wglSetStereoEmitterState3DL

#endif // WGL_3DL_stereo_control

#endif // OPENGL_INCLUDE_WGL_3DL_stereo_control

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_AMD_gpu_association

#ifndef WGL_AMD_gpu_association
#define WGL_AMD_gpu_association 1

#define WGL_GPU_VENDOR_AMD                   0x1F00
#define WGL_GPU_RENDERER_STRING_AMD          0x1F01
#define WGL_GPU_OPENGL_VERSION_STRING_AMD    0x1F02
#define WGL_GPU_FASTEST_TARGET_GPUS_AMD      0x21A2
#define WGL_GPU_RAM_AMD                      0x21A3
#define WGL_GPU_CLOCK_AMD                    0x21A4
#define WGL_GPU_NUM_PIPES_AMD                0x21A5
#define WGL_GPU_NUM_SIMD_AMD                 0x21A6
#define WGL_GPU_NUM_RB_AMD                   0x21A7
#define WGL_GPU_NUM_SPI_AMD                  0x21A8

OPENGL_INIT_PROC(wglGetGPUIDsAMD,                      UINT,  UINT maxCount, UINT *ids);
OPENGL_INIT_PROC(wglGetGPUInfoAMD,                     INT,   UINT id, INT property, GLenum dataType, UINT size, void *data);
OPENGL_INIT_PROC(wglGetContextGPUIDAMD,                UINT,  HGLRC hglrc);
OPENGL_INIT_PROC(wglCreateAssociatedContextAMD,        HGLRC, UINT id);
OPENGL_INIT_PROC(wglCreateAssociatedContextAttribsAMD, HGLRC, UINT id, HGLRC hShareContext, const int *attribList);
OPENGL_INIT_PROC(wglDeleteAssociatedContextAMD,        BOOL,  HGLRC hglrc);
OPENGL_INIT_PROC(wglMakeAssociatedContextCurrentAMD,   BOOL,  HGLRC hglrc);
OPENGL_INIT_PROC(wglGetCurrentAssociatedContextAMD,    HGLRC, void);
OPENGL_INIT_PROC(wglBlitContextFramebufferAMD,         VOID,  HGLRC dstCtx, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);

#define wglGetGPUIDsAMD                      OGL__wglGetGPUIDsAMD
#define wglGetGPUInfoAMD                     OGL__wglGetGPUInfoAMD
#define wglGetContextGPUIDAMD                OGL__wglGetContextGPUIDAMD
#define wglCreateAssociatedContextAMD        OGL__wglCreateAssociatedContextAMD
#define wglCreateAssociatedContextAttribsAMD OGL__wglCreateAssociatedContextAttribsAMD
#define wglDeleteAssociatedContextAMD        OGL__wglDeleteAssociatedContextAMD
#define wglMakeAssociatedContextCurrentAMD   OGL__wglMakeAssociatedContextCurrentAMD
#define wglGetCurrentAssociatedContextAMD    OGL__wglGetCurrentAssociatedContextAMD
#define wglBlitContextFramebufferAMD         OGL__wglBlitContextFramebufferAMD

#endif // WGL_AMD_gpu_association

#endif // OPENGL_INCLUDE_WGL_AMD_gpu_association

/* -------------------------------------------------------------------------- */

#ifndef WGL_ATI_pixel_format_float
#define WGL_ATI_pixel_format_float 1

#define WGL_TYPE_RGBA_FLOAT_ATI    0x21A0

#endif // WGL_ATI_pixel_format_float

/* -------------------------------------------------------------------------- */

#ifndef WGL_ATI_render_texture_rectangle
#define WGL_ATI_render_texture_rectangle 1

#define WGL_TEXTURE_RECTANGLE_ATI    0x21A5

#endif // WGL_ATI_render_texture_rectangle

/* -------------------------------------------------------------------------- */

#ifndef WGL_EXT_colorspace
#define WGL_EXT_colorspace 1

#define WGL_COLORSPACE_EXT           0x309D
#define WGL_COLORSPACE_SRGB_EXT      0x3089
#define WGL_COLORSPACE_LINEAR_EXT    0x308A

#endif // WGL_EXT_colorspace

/* -------------------------------------------------------------------------- */

#ifndef WGL_EXT_create_context_es2_profile
#define WGL_EXT_create_context_es2_profile 1

#define WGL_CONTEXT_ES2_PROFILE_BIT_EXT    0x00000004

#endif // WGL_EXT_create_context_es2_profile

/* -------------------------------------------------------------------------- */

#ifndef WGL_EXT_create_context_es_profile
#define WGL_EXT_create_context_es_profile 1

#define WGL_CONTEXT_ES_PROFILE_BIT_EXT    0x00000004

#endif // WGL_EXT_create_context_es_profile

/* -------------------------------------------------------------------------- */

#ifndef WGL_EXT_depth_float
#define WGL_EXT_depth_float 1

#define WGL_DEPTH_FLOAT_EXT    0x2040

#endif // WGL_EXT_depth_float

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_EXT_display_color_table

#ifndef WGL_EXT_display_color_table
#define WGL_EXT_display_color_table 1

OPENGL_INIT_PROC(wglCreateDisplayColorTableEXT,  GLboolean, GLushort id);
OPENGL_INIT_PROC(wglLoadDisplayColorTableEXT,    GLboolean, const GLushort *table, GLuint length);
OPENGL_INIT_PROC(wglBindDisplayColorTableEXT,    GLboolean, GLushort id);
OPENGL_INIT_PROC(wglDestroyDisplayColorTableEXT, VOID,      GLushort id);

#define wglCreateDisplayColorTableEXT  OGL__wglCreateDisplayColorTableEXT
#define wglLoadDisplayColorTableEXT    OGL__wglLoadDisplayColorTableEXT
#define wglBindDisplayColorTableEXT    OGL__wglBindDisplayColorTableEXT
#define wglDestroyDisplayColorTableEXT OGL__wglDestroyDisplayColorTableEXT

#endif // WGL_EXT_display_color_table

#endif // OPENGL_INCLUDE_WGL_EXT_display_color_table

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_EXT_extensions_string

#ifndef WGL_EXT_extensions_string
#define WGL_EXT_extensions_string 1

OPENGL_INIT_PROC(wglGetExtensionsStringEXT, const char*, void);
#define wglGetExtensionsStringEXT OGL__wglGetExtensionsStringEXT

#endif // WGL_EXT_extensions_string

#endif // OPENGL_INCLUDE_WGL_EXT_extensions_string

/* -------------------------------------------------------------------------- */

#ifndef WGL_EXT_framebuffer_sRGB
#define WGL_EXT_framebuffer_sRGB 1

#define WGL_FRAMEBUFFER_SRGB_CAPABLE_EXT    0x20A9

#endif // WGL_EXT_framebuffer_sRGB

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_EXT_make_current_read

#ifndef WGL_EXT_make_current_read
#define WGL_EXT_make_current_read 1

#define ERROR_INVALID_PIXEL_TYPE_EXT    0x2043

OPENGL_INIT_PROC(wglMakeContextCurrentEXT, BOOL, HDC hDrawDC, HDC hReadDC, HGLRC hglrc);
OPENGL_INIT_PROC(wglGetCurrentReadDCEXT,   HDC,  void);

#define wglMakeContextCurrentEXT OGL__wglMakeContextCurrentEXT
#define wglGetCurrentReadDCEXT   OGL__wglGetCurrentReadDCEXT

#endif // WGL_EXT_make_current_read

#endif // OPENGL_INCLUDE_WGL_EXT_make_current_read

/* -------------------------------------------------------------------------- */

#ifndef WGL_EXT_multisample
#define WGL_EXT_multisample 1

#define WGL_SAMPLE_BUFFERS_EXT    0x2041
#define WGL_SAMPLES_EXT           0x2042

#endif // WGL_EXT_multisample

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_EXT_pbuffer

#ifndef WGL_EXT_pbuffer
#define WGL_EXT_pbuffer 1

#define WGL_DRAW_TO_PBUFFER_EXT           0x202D
#define WGL_MAX_PBUFFER_PIXELS_EXT        0x202E
#define WGL_MAX_PBUFFER_WIDTH_EXT         0x202F
#define WGL_MAX_PBUFFER_HEIGHT_EXT        0x2030
#define WGL_OPTIMAL_PBUFFER_WIDTH_EXT     0x2031
#define WGL_OPTIMAL_PBUFFER_HEIGHT_EXT    0x2032
#define WGL_PBUFFER_LARGEST_EXT           0x2033
#define WGL_PBUFFER_WIDTH_EXT             0x2034
#define WGL_PBUFFER_HEIGHT_EXT            0x2035

OPENGL_INIT_PROC(wglCreatePbufferEXT,    HPBUFFEREXT, HDC hDC, int iPixelFormat, int iWidth, int iHeight, const int *piAttribList);
OPENGL_INIT_PROC(wglGetPbufferDCEXT,     HDC,         HPBUFFEREXT hPbuffer);
OPENGL_INIT_PROC(wglReleasePbufferDCEXT, int,         HPBUFFEREXT hPbuffer, HDC hDC);
OPENGL_INIT_PROC(wglDestroyPbufferEXT,   BOOL,        HPBUFFEREXT hPbuffer);
OPENGL_INIT_PROC(wglQueryPbufferEXT,     BOOL,        HPBUFFEREXT hPbuffer, int iAttribute, int *piValue);

#define wglCreatePbufferEXT    OGL__wglCreatePbufferEXT
#define wglGetPbufferDCEXT     OGL__wglGetPbufferDCEXT
#define wglReleasePbufferDCEXT OGL__wglReleasePbufferDCEXT
#define wglDestroyPbufferEXT   OGL__wglDestroyPbufferEXT
#define wglQueryPbufferEXT     OGL__wglQueryPbufferEXT

#endif // WGL_EXT_pbuffer

#endif // OPENGL_INCLUDE_WGL_EXT_pbuffer

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_EXT_pixel_format

#ifndef WGL_EXT_pixel_format
#define WGL_EXT_pixel_format 1

#define WGL_NUMBER_PIXEL_FORMATS_EXT    0x2000
#define WGL_DRAW_TO_WINDOW_EXT          0x2001
#define WGL_DRAW_TO_BITMAP_EXT          0x2002
#define WGL_ACCELERATION_EXT            0x2003
#define WGL_NEED_PALETTE_EXT            0x2004
#define WGL_NEED_SYSTEM_PALETTE_EXT     0x2005
#define WGL_SWAP_LAYER_BUFFERS_EXT      0x2006
#define WGL_SWAP_METHOD_EXT             0x2007
#define WGL_NUMBER_OVERLAYS_EXT         0x2008
#define WGL_NUMBER_UNDERLAYS_EXT        0x2009
#define WGL_TRANSPARENT_EXT             0x200A
#define WGL_TRANSPARENT_VALUE_EXT       0x200B
#define WGL_SHARE_DEPTH_EXT             0x200C
#define WGL_SHARE_STENCIL_EXT           0x200D
#define WGL_SHARE_ACCUM_EXT             0x200E
#define WGL_SUPPORT_GDI_EXT             0x200F
#define WGL_SUPPORT_OPENGL_EXT          0x2010
#define WGL_DOUBLE_BUFFER_EXT           0x2011
#define WGL_STEREO_EXT                  0x2012
#define WGL_PIXEL_TYPE_EXT              0x2013
#define WGL_COLOR_BITS_EXT              0x2014
#define WGL_RED_BITS_EXT                0x2015
#define WGL_RED_SHIFT_EXT               0x2016
#define WGL_GREEN_BITS_EXT              0x2017
#define WGL_GREEN_SHIFT_EXT             0x2018
#define WGL_BLUE_BITS_EXT               0x2019
#define WGL_BLUE_SHIFT_EXT              0x201A
#define WGL_ALPHA_BITS_EXT              0x201B
#define WGL_ALPHA_SHIFT_EXT             0x201C
#define WGL_ACCUM_BITS_EXT              0x201D
#define WGL_ACCUM_RED_BITS_EXT          0x201E
#define WGL_ACCUM_GREEN_BITS_EXT        0x201F
#define WGL_ACCUM_BLUE_BITS_EXT         0x2020
#define WGL_ACCUM_ALPHA_BITS_EXT        0x2021
#define WGL_DEPTH_BITS_EXT              0x2022
#define WGL_STENCIL_BITS_EXT            0x2023
#define WGL_AUX_BUFFERS_EXT             0x2024
#define WGL_NO_ACCELERATION_EXT         0x2025
#define WGL_GENERIC_ACCELERATION_EXT    0x2026
#define WGL_FULL_ACCELERATION_EXT       0x2027
#define WGL_SWAP_EXCHANGE_EXT           0x2028
#define WGL_SWAP_COPY_EXT               0x2029
#define WGL_SWAP_UNDEFINED_EXT          0x202A
#define WGL_TYPE_RGBA_EXT               0x202B
#define WGL_TYPE_COLORINDEX_EXT         0x202C

OPENGL_INIT_PROC(wglGetPixelFormatAttribivEXT, BOOL, HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, int *piValues);
OPENGL_INIT_PROC(wglGetPixelFormatAttribfvEXT, BOOL, HDC hdc, int iPixelFormat, int iLayerPlane, UINT nAttributes, int *piAttributes, FLOAT *pfValues);
OPENGL_INIT_PROC(wglChoosePixelFormatEXT,      BOOL, HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList, UINT nMaxFormats, int *piFormats, UINT *nNumFormats);

#define wglGetPixelFormatAttribivEXT OGL__wglGetPixelFormatAttribivEXT
#define wglGetPixelFormatAttribfvEXT OGL__wglGetPixelFormatAttribfvEXT
#define wglChoosePixelFormatEXT      OGL__wglChoosePixelFormatEXT

#endif // WGL_EXT_pixel_format

#endif // OPENGL_INCLUDE_WGL_EXT_pixel_format

/* -------------------------------------------------------------------------- */

#ifndef WGL_EXT_pixel_format_packed_float
#define WGL_EXT_pixel_format_packed_float 1

#define WGL_TYPE_RGBA_UNSIGNED_FLOAT_EXT    0x20A8

#endif // WGL_EXT_pixel_format_packed_float

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_EXT_swap_control

#ifndef WGL_EXT_swap_control
#define WGL_EXT_swap_control 1

OPENGL_INIT_PROC(wglSwapIntervalEXT,    BOOL, int interval);
OPENGL_INIT_PROC(wglGetSwapIntervalEXT, int,  void);

#define wglSwapIntervalEXT    OGL__wglSwapIntervalEXT
#define wglGetSwapIntervalEXT OGL__wglGetSwapIntervalEXT

#endif // WGL_EXT_swap_control

#endif // OPENGL_INCLUDE_WGL_EXT_swap_control

/* -------------------------------------------------------------------------- */

#ifndef WGL_EXT_swap_control_tear
#define WGL_EXT_swap_control_tear 1

#endif // WGL_EXT_swap_control_tear

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_I3D_digital_video_control

#ifndef WGL_I3D_digital_video_control
#define WGL_I3D_digital_video_control 1

#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_FRAMEBUFFER_I3D    0x2050
#define WGL_DIGITAL_VIDEO_CURSOR_ALPHA_VALUE_I3D          0x2051
#define WGL_DIGITAL_VIDEO_CURSOR_INCLUDED_I3D             0x2052
#define WGL_DIGITAL_VIDEO_GAMMA_CORRECTED_I3D             0x2053

OPENGL_INIT_PROC(wglGetDigitalVideoParametersI3D, BOOL, HDC hDC, int iAttribute, int *piValue);
OPENGL_INIT_PROC(wglSetDigitalVideoParametersI3D, BOOL, HDC hDC, int iAttribute, const int *piValue);

#define wglGetDigitalVideoParametersI3D OGL__wglGetDigitalVideoParametersI3D
#define wglSetDigitalVideoParametersI3D OGL__wglSetDigitalVideoParametersI3D

#endif // WGL_I3D_digital_video_control

#endif // OPENGL_INCLUDE_WGL_I3D_digital_video_control

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_I3D_gamma

#ifndef WGL_I3D_gamma
#define WGL_I3D_gamma 1

#define WGL_GAMMA_TABLE_SIZE_I3D         0x204E
#define WGL_GAMMA_EXCLUDE_DESKTOP_I3D    0x204F

OPENGL_INIT_PROC(wglGetGammaTableParametersI3D, BOOL, HDC hDC, int iAttribute, int *piValue);
OPENGL_INIT_PROC(wglSetGammaTableParametersI3D, BOOL, HDC hDC, int iAttribute, const int *piValue);
OPENGL_INIT_PROC(wglGetGammaTableI3D,           BOOL, HDC hDC, int iEntries, USHORT *puRed, USHORT *puGreen, USHORT *puBlue);
OPENGL_INIT_PROC(wglSetGammaTableI3D,           BOOL, HDC hDC, int iEntries, const USHORT *puRed, const USHORT *puGreen, const USHORT *puBlue);

#define wglGetGammaTableParametersI3D OGL__wglGetGammaTableParametersI3D
#define wglSetGammaTableParametersI3D OGL__wglSetGammaTableParametersI3D
#define wglGetGammaTableI3D           OGL__wglGetGammaTableI3D
#define wglSetGammaTableI3D           OGL__wglSetGammaTableI3D

#endif // WGL_I3D_gamma

#endif // OPENGL_INCLUDE_WGL_I3D_gamma

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_I3D_genlock

#ifndef WGL_I3D_genlock
#define WGL_I3D_genlock 1

#define WGL_GENLOCK_SOURCE_MULTIVIEW_I3D         0x2044
#define WGL_GENLOCK_SOURCE_EXTERNAL_SYNC_I3D     0x2045
#define WGL_GENLOCK_SOURCE_EXTERNAL_FIELD_I3D    0x2046
#define WGL_GENLOCK_SOURCE_EXTERNAL_TTL_I3D      0x2047
#define WGL_GENLOCK_SOURCE_DIGITAL_SYNC_I3D      0x2048
#define WGL_GENLOCK_SOURCE_DIGITAL_FIELD_I3D     0x2049
#define WGL_GENLOCK_SOURCE_EDGE_FALLING_I3D      0x204A
#define WGL_GENLOCK_SOURCE_EDGE_RISING_I3D       0x204B
#define WGL_GENLOCK_SOURCE_EDGE_BOTH_I3D         0x204C

OPENGL_INIT_PROC(wglEnableGenlockI3D,              BOOL, HDC hDC);
OPENGL_INIT_PROC(wglDisableGenlockI3D,             BOOL, HDC hDC);
OPENGL_INIT_PROC(wglIsEnabledGenlockI3D,           BOOL, HDC hDC, BOOL *pFlag);
OPENGL_INIT_PROC(wglGenlockSourceI3D,              BOOL, HDC hDC, UINT uSource);
OPENGL_INIT_PROC(wglGetGenlockSourceI3D,           BOOL, HDC hDC, UINT *uSource);
OPENGL_INIT_PROC(wglGenlockSourceEdgeI3D,          BOOL, HDC hDC, UINT uEdge);
OPENGL_INIT_PROC(wglGetGenlockSourceEdgeI3D,       BOOL, HDC hDC, UINT *uEdge);
OPENGL_INIT_PROC(wglGenlockSampleRateI3D,          BOOL, HDC hDC, UINT uRate);
OPENGL_INIT_PROC(wglGetGenlockSampleRateI3D,       BOOL, HDC hDC, UINT *uRate);
OPENGL_INIT_PROC(wglGenlockSourceDelayI3D,         BOOL, HDC hDC, UINT uDelay);
OPENGL_INIT_PROC(wglGetGenlockSourceDelayI3D,      BOOL, HDC hDC, UINT *uDelay);
OPENGL_INIT_PROC(wglQueryGenlockMaxSourceDelayI3D, BOOL, HDC hDC, UINT *uMaxLineDelay, UINT *uMaxPixelDelay);

#define wglEnableGenlockI3D              OGL__wglEnableGenlockI3D
#define wglDisableGenlockI3D             OGL__wglDisableGenlockI3D
#define wglIsEnabledGenlockI3D           OGL__wglIsEnabledGenlockI3D
#define wglGenlockSourceI3D              OGL__wglGenlockSourceI3D
#define wglGetGenlockSourceI3D           OGL__wglGetGenlockSourceI3D
#define wglGenlockSourceEdgeI3D          OGL__wglGenlockSourceEdgeI3D
#define wglGetGenlockSourceEdgeI3D       OGL__wglGetGenlockSourceEdgeI3D
#define wglGenlockSampleRateI3D          OGL__wglGenlockSampleRateI3D
#define wglGetGenlockSampleRateI3D       OGL__wglGetGenlockSampleRateI3D
#define wglGenlockSourceDelayI3D         OGL__wglGenlockSourceDelayI3D
#define wglGetGenlockSourceDelayI3D      OGL__wglGetGenlockSourceDelayI3D
#define wglQueryGenlockMaxSourceDelayI3D OGL__wglQueryGenlockMaxSourceDelayI3D

#endif // WGL_I3D_genlock

#endif // OPENGL_INCLUDE_WGL_I3D_genlock

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_I3D_image_buffer

#ifndef WGL_I3D_image_buffer
#define WGL_I3D_image_buffer 1

#define WGL_IMAGE_BUFFER_MIN_ACCESS_I3D    0x00000001
#define WGL_IMAGE_BUFFER_LOCK_I3D          0x00000002

OPENGL_INIT_PROC(wglCreateImageBufferI3D,          LPVOID, HDC hDC, DWORD dwSize, UINT uFlags);
OPENGL_INIT_PROC(wglDestroyImageBufferI3D,         BOOL,   HDC hDC, LPVOID pAddress);
OPENGL_INIT_PROC(wglAssociateImageBufferEventsI3D, BOOL,   HDC hDC, const HANDLE *pEvent, const LPVOID *pAddress, const DWORD *pSize, UINT count);
OPENGL_INIT_PROC(wglReleaseImageBufferEventsI3D,   BOOL,   HDC hDC, const LPVOID *pAddress, UINT count);

#define wglCreateImageBufferI3D          OGL__wglCreateImageBufferI3D
#define wglDestroyImageBufferI3D         OGL__wglDestroyImageBufferI3D
#define wglAssociateImageBufferEventsI3D OGL__wglAssociateImageBufferEventsI3D
#define wglReleaseImageBufferEventsI3D   OGL__wglReleaseImageBufferEventsI3D

#endif // WGL_I3D_image_buffer

#endif // OPENGL_INCLUDE_WGL_I3D_image_buffer

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_I3D_swap_frame_lock

#ifndef WGL_I3D_swap_frame_lock
#define WGL_I3D_swap_frame_lock 1

OPENGL_INIT_PROC(wglEnableFrameLockI3D,      BOOL, void);
OPENGL_INIT_PROC(wglDisableFrameLockI3D,     BOOL, void);
OPENGL_INIT_PROC(wglIsEnabledFrameLockI3D,   BOOL, BOOL *pFlag);
OPENGL_INIT_PROC(wglQueryFrameLockMasterI3D, BOOL, BOOL *pFlag);

#define wglEnableFrameLockI3D      OGL__wglEnableFrameLockI3D
#define wglDisableFrameLockI3D     OGL__wglDisableFrameLockI3D
#define wglIsEnabledFrameLockI3D   OGL__wglIsEnabledFrameLockI3D
#define wglQueryFrameLockMasterI3D OGL__wglQueryFrameLockMasterI3D

#endif // WGL_I3D_swap_frame_lock

#endif // OPENGL_INCLUDE_WGL_I3D_swap_frame_lock

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_I3D_swap_frame_usage

#ifndef WGL_I3D_swap_frame_usage
#define WGL_I3D_swap_frame_usage 1

OPENGL_INIT_PROC(wglGetFrameUsageI3D,      BOOL, float *pUsage);
OPENGL_INIT_PROC(wglBeginFrameTrackingI3D, BOOL, void);
OPENGL_INIT_PROC(wglEndFrameTrackingI3D,   BOOL, void);
OPENGL_INIT_PROC(wglQueryFrameTrackingI3D, BOOL, DWORD *pFrameCount, DWORD *pMissedFrames, float *pLastMissedUsage);

#define wglGetFrameUsageI3D      OGL__wglGetFrameUsageI3D
#define wglBeginFrameTrackingI3D OGL__wglBeginFrameTrackingI3D
#define wglEndFrameTrackingI3D   OGL__wglEndFrameTrackingI3D
#define wglQueryFrameTrackingI3D OGL__wglQueryFrameTrackingI3D

#endif // WGL_I3D_swap_frame_usage

#endif // OPENGL_INCLUDE_WGL_I3D_swap_frame_usage

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_NV_DX_interop

#ifndef WGL_NV_DX_interop
#define WGL_NV_DX_interop 1

#define WGL_ACCESS_READ_ONLY_NV        0x00000000
#define WGL_ACCESS_READ_WRITE_NV       0x00000001
#define WGL_ACCESS_WRITE_DISCARD_NV    0x00000002

OPENGL_INIT_PROC(wglDXSetResourceShareHandleNV, BOOL,   void *dxObject, HANDLE shareHandle);
OPENGL_INIT_PROC(wglDXOpenDeviceNV,             HANDLE, void *dxDevice);
OPENGL_INIT_PROC(wglDXCloseDeviceNV,            BOOL,   HANDLE hDevice);
OPENGL_INIT_PROC(wglDXRegisterObjectNV,         HANDLE, HANDLE hDevice, void *dxObject, GLuint name, GLenum type, GLenum access);
OPENGL_INIT_PROC(wglDXUnregisterObjectNV,       BOOL,   HANDLE hDevice, HANDLE hObject);
OPENGL_INIT_PROC(wglDXObjectAccessNV,           BOOL,   HANDLE hObject, GLenum access);
OPENGL_INIT_PROC(wglDXLockObjectsNV,            BOOL,   HANDLE hDevice, GLint count, HANDLE *hObjects);
OPENGL_INIT_PROC(wglDXUnlockObjectsNV,          BOOL,   HANDLE hDevice, GLint count, HANDLE *hObjects);

#define wglDXSetResourceShareHandleNV OGL__wglDXSetResourceShareHandleNV
#define wglDXOpenDeviceNV             OGL__wglDXOpenDeviceNV
#define wglDXCloseDeviceNV            OGL__wglDXCloseDeviceNV
#define wglDXRegisterObjectNV         OGL__wglDXRegisterObjectNV
#define wglDXUnregisterObjectNV       OGL__wglDXUnregisterObjectNV
#define wglDXObjectAccessNV           OGL__wglDXObjectAccessNV
#define wglDXLockObjectsNV            OGL__wglDXLockObjectsNV
#define wglDXUnlockObjectsNV          OGL__wglDXUnlockObjectsNV

#endif // WGL_NV_DX_interop

#endif // OPENGL_INCLUDE_WGL_NV_DX_interop

/* -------------------------------------------------------------------------- */

#ifndef WGL_NV_DX_interop2
#define WGL_NV_DX_interop2 1

#endif // WGL_NV_DX_interop2

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_NV_copy_image

#ifndef WGL_NV_copy_image
#define WGL_NV_copy_image 1

OPENGL_INIT_PROC(wglCopyImageSubDataNV, BOOL, HGLRC hSrcRC, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, HGLRC hDstRC, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
#define wglCopyImageSubDataNV OGL__wglCopyImageSubDataNV

#endif // WGL_NV_copy_image

#endif // OPENGL_INCLUDE_WGL_NV_copy_image

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_NV_delay_before_swap

#ifndef WGL_NV_delay_before_swap
#define WGL_NV_delay_before_swap 1

OPENGL_INIT_PROC(wglDelayBeforeSwapNV, BOOL, HDC hDC, GLfloat seconds);
#define wglDelayBeforeSwapNV OGL__wglDelayBeforeSwapNV

#endif // WGL_NV_delay_before_swap

#endif // OPENGL_INCLUDE_WGL_NV_delay_before_swap

/* -------------------------------------------------------------------------- */

#ifndef WGL_NV_float_buffer
#define WGL_NV_float_buffer 1

#define WGL_FLOAT_COMPONENTS_NV                        0x20B0
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_R_NV       0x20B1
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RG_NV      0x20B2
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGB_NV     0x20B3
#define WGL_BIND_TO_TEXTURE_RECTANGLE_FLOAT_RGBA_NV    0x20B4
#define WGL_TEXTURE_FLOAT_R_NV                         0x20B5
#define WGL_TEXTURE_FLOAT_RG_NV                        0x20B6
#define WGL_TEXTURE_FLOAT_RGB_NV                       0x20B7
#define WGL_TEXTURE_FLOAT_RGBA_NV                      0x20B8

#endif // WGL_NV_float_buffer

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_NV_gpu_affinity

#ifndef WGL_NV_gpu_affinity
#define WGL_NV_gpu_affinity 1

#define ERROR_INCOMPATIBLE_AFFINITY_MASKS_NV    0x20D0
#define ERROR_MISSING_AFFINITY_MASK_NV          0x20D1

OPENGL_INIT_PROC(wglEnumGpusNV,               BOOL, UINT iGpuIndex, HGPUNV *phGpu);
OPENGL_INIT_PROC(wglEnumGpuDevicesNV,         BOOL, HGPUNV hGpu, UINT iDeviceIndex, PGPU_DEVICE lpGpuDevice);
OPENGL_INIT_PROC(wglCreateAffinityDCNV,       HDC,  const HGPUNV *phGpuList);
OPENGL_INIT_PROC(wglEnumGpusFromAffinityDCNV, BOOL, HDC hAffinityDC, UINT iGpuIndex, HGPUNV *hGpu);
OPENGL_INIT_PROC(wglDeleteDCNV,               BOOL, HDC hdc);

#define wglEnumGpusNV               OGL__wglEnumGpusNV
#define wglEnumGpuDevicesNV         OGL__wglEnumGpuDevicesNV
#define wglCreateAffinityDCNV       OGL__wglCreateAffinityDCNV
#define wglEnumGpusFromAffinityDCNV OGL__wglEnumGpusFromAffinityDCNV
#define wglDeleteDCNV               OGL__wglDeleteDCNV

#endif // WGL_NV_gpu_affinity

#endif // OPENGL_INCLUDE_WGL_NV_gpu_affinity

/* -------------------------------------------------------------------------- */

#ifndef WGL_NV_multigpu_context
#define WGL_NV_multigpu_context 1

#define WGL_CONTEXT_MULTIGPU_ATTRIB_NV                         0x20AA
#define WGL_CONTEXT_MULTIGPU_ATTRIB_SINGLE_NV                  0x20AB
#define WGL_CONTEXT_MULTIGPU_ATTRIB_AFR_NV                     0x20AC
#define WGL_CONTEXT_MULTIGPU_ATTRIB_MULTICAST_NV               0x20AD
#define WGL_CONTEXT_MULTIGPU_ATTRIB_MULTI_DISPLAY_MULTICAST_NV 0x20AE

#endif // WGL_NV_multigpu_context

/* -------------------------------------------------------------------------- */

#ifndef WGL_NV_multisample_coverage
#define WGL_NV_multisample_coverage 1

#define WGL_COVERAGE_SAMPLES_NV    0x2042
#define WGL_COLOR_SAMPLES_NV       0x20B9

#endif // WGL_NV_multisample_coverage

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_NV_present_video

#ifndef WGL_NV_present_video
#define WGL_NV_present_video 1

#define WGL_NUM_VIDEO_SLOTS_NV    0x20F0

OPENGL_INIT_PROC(wglEnumerateVideoDevicesNV, int,  HDC hDc, HVIDEOOUTPUTDEVICENV *phDeviceList);
OPENGL_INIT_PROC(wglBindVideoDeviceNV,       BOOL, HDC hDc, unsigned int uVideoSlot, HVIDEOOUTPUTDEVICENV hVideoDevice, const int *piAttribList);
OPENGL_INIT_PROC(wglQueryCurrentContextNV,   BOOL, int iAttribute, int *piValue);

#define wglEnumerateVideoDevicesNV OGL__wglEnumerateVideoDevicesNV
#define wglBindVideoDeviceNV       OGL__wglBindVideoDeviceNV
#define wglQueryCurrentContextNV   OGL__wglQueryCurrentContextNV

#endif // WGL_NV_present_video

#endif // OPENGL_INCLUDE_WGL_NV_present_video

/* -------------------------------------------------------------------------- */

#ifndef WGL_NV_render_depth_texture
#define WGL_NV_render_depth_texture 1

#define WGL_BIND_TO_TEXTURE_DEPTH_NV              0x20A3
#define WGL_BIND_TO_TEXTURE_RECTANGLE_DEPTH_NV    0x20A4
#define WGL_DEPTH_TEXTURE_FORMAT_NV               0x20A5
#define WGL_TEXTURE_DEPTH_COMPONENT_NV            0x20A6
#define WGL_DEPTH_COMPONENT_NV                    0x20A7

#endif // WGL_NV_render_depth_texture

/* -------------------------------------------------------------------------- */

#ifndef WGL_NV_render_texture_rectangle
#define WGL_NV_render_texture_rectangle 1

#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGB_NV     0x20A0
#define WGL_BIND_TO_TEXTURE_RECTANGLE_RGBA_NV    0x20A1
#define WGL_TEXTURE_RECTANGLE_NV                 0x20A2

#endif // WGL_NV_render_texture_rectangle

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_NV_swap_group

#ifndef WGL_NV_swap_group
#define WGL_NV_swap_group 1

OPENGL_INIT_PROC(wglJoinSwapGroupNV,      BOOL, HDC hDC, GLuint group);
OPENGL_INIT_PROC(wglBindSwapBarrierNV,    BOOL, GLuint group, GLuint barrier);
OPENGL_INIT_PROC(wglQuerySwapGroupNV,     BOOL, HDC hDC, GLuint *group, GLuint *barrier);
OPENGL_INIT_PROC(wglQueryMaxSwapGroupsNV, BOOL, HDC hDC, GLuint *maxGroups, GLuint *maxBarriers);
OPENGL_INIT_PROC(wglQueryFrameCountNV,    BOOL, HDC hDC, GLuint *count);
OPENGL_INIT_PROC(wglResetFrameCountNV,    BOOL, HDC hDC);

#define wglJoinSwapGroupNV      OGL__wglJoinSwapGroupNV
#define wglBindSwapBarrierNV    OGL__wglBindSwapBarrierNV
#define wglQuerySwapGroupNV     OGL__wglQuerySwapGroupNV
#define wglQueryMaxSwapGroupsNV OGL__wglQueryMaxSwapGroupsNV
#define wglQueryFrameCountNV    OGL__wglQueryFrameCountNV
#define wglResetFrameCountNV    OGL__wglResetFrameCountNV

#endif // WGL_NV_swap_group

#endif // OPENGL_INCLUDE_WGL_NV_swap_group

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_NV_video_capture

#ifndef WGL_NV_video_capture
#define WGL_NV_video_capture 1

#define WGL_UNIQUE_ID_NV                  0x20CE
#define WGL_NUM_VIDEO_CAPTURE_SLOTS_NV    0x20CF

OPENGL_INIT_PROC(wglBindVideoCaptureDeviceNV,       BOOL, UINT uVideoSlot, HVIDEOINPUTDEVICENV hDevice);
OPENGL_INIT_PROC(wglEnumerateVideoCaptureDevicesNV, UINT, HDC hDc, HVIDEOINPUTDEVICENV *phDeviceList);
OPENGL_INIT_PROC(wglLockVideoCaptureDeviceNV,       BOOL, HDC hDc, HVIDEOINPUTDEVICENV hDevice);
OPENGL_INIT_PROC(wglQueryVideoCaptureDeviceNV,      BOOL, HDC hDc, HVIDEOINPUTDEVICENV hDevice, int iAttribute, int *piValue);
OPENGL_INIT_PROC(wglReleaseVideoCaptureDeviceNV,    BOOL, HDC hDc, HVIDEOINPUTDEVICENV hDevice);

#define wglBindVideoCaptureDeviceNV       OGL__wglBindVideoCaptureDeviceNV
#define wglEnumerateVideoCaptureDevicesNV OGL__wglEnumerateVideoCaptureDevicesNV
#define wglLockVideoCaptureDeviceNV       OGL__wglLockVideoCaptureDeviceNV
#define wglQueryVideoCaptureDeviceNV      OGL__wglQueryVideoCaptureDeviceNV
#define wglReleaseVideoCaptureDeviceNV    OGL__wglReleaseVideoCaptureDeviceNV

#endif // WGL_NV_video_capture

#endif // OPENGL_INCLUDE_WGL_NV_video_capture

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_NV_video_output

#ifndef WGL_NV_video_output
#define WGL_NV_video_output 1

#define WGL_BIND_TO_VIDEO_RGB_NV              0x20C0
#define WGL_BIND_TO_VIDEO_RGBA_NV             0x20C1
#define WGL_BIND_TO_VIDEO_RGB_AND_DEPTH_NV    0x20C2
#define WGL_VIDEO_OUT_COLOR_NV                0x20C3
#define WGL_VIDEO_OUT_ALPHA_NV                0x20C4
#define WGL_VIDEO_OUT_DEPTH_NV                0x20C5
#define WGL_VIDEO_OUT_COLOR_AND_ALPHA_NV      0x20C6
#define WGL_VIDEO_OUT_COLOR_AND_DEPTH_NV      0x20C7
#define WGL_VIDEO_OUT_FRAME                   0x20C8
#define WGL_VIDEO_OUT_FIELD_1                 0x20C9
#define WGL_VIDEO_OUT_FIELD_2                 0x20CA
#define WGL_VIDEO_OUT_STACKED_FIELDS_1_2      0x20CB
#define WGL_VIDEO_OUT_STACKED_FIELDS_2_1      0x20CC

OPENGL_INIT_PROC(wglGetVideoDeviceNV,     BOOL, HDC hDC, int numDevices, HPVIDEODEV *hVideoDevice);
OPENGL_INIT_PROC(wglReleaseVideoDeviceNV, BOOL, HPVIDEODEV hVideoDevice);
OPENGL_INIT_PROC(wglBindVideoImageNV,     BOOL, HPVIDEODEV hVideoDevice, HPBUFFERARB hPbuffer, int iVideoBuffer);
OPENGL_INIT_PROC(wglReleaseVideoImageNV,  BOOL, HPBUFFERARB hPbuffer, int iVideoBuffer);
OPENGL_INIT_PROC(wglSendPbufferToVideoNV, BOOL, HPBUFFERARB hPbuffer, int iBufferType, unsigned long *pulCounterPbuffer, BOOL bBlock);
OPENGL_INIT_PROC(wglGetVideoInfoNV,       BOOL, HPVIDEODEV hpVideoDevice, unsigned long *pulCounterOutputPbuffer, unsigned long *pulCounterOutputVideo);

#define wglGetVideoDeviceNV     OGL__wglGetVideoDeviceNV
#define wglReleaseVideoDeviceNV OGL__wglReleaseVideoDeviceNV
#define wglBindVideoImageNV     OGL__wglBindVideoImageNV
#define wglReleaseVideoImageNV  OGL__wglReleaseVideoImageNV
#define wglSendPbufferToVideoNV OGL__wglSendPbufferToVideoNV
#define wglGetVideoInfoNV       OGL__wglGetVideoInfoNV

#endif // WGL_NV_video_output

#endif // OPENGL_INCLUDE_WGL_NV_video_output

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_WGL_OML_sync_control

#ifndef WGL_OML_sync_control
#define WGL_OML_sync_control 1

OPENGL_INIT_PROC(wglGetSyncValuesOML,       BOOL,  HDC hdc, INT64 *ust, INT64 *msc, INT64 *sbc);
OPENGL_INIT_PROC(wglGetMscRateOML,          BOOL,  HDC hdc, INT32 *numerator, INT32 *denominator);
OPENGL_INIT_PROC(wglSwapBuffersMscOML,      INT64, HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder);
OPENGL_INIT_PROC(wglSwapLayerBuffersMscOML, INT64, HDC hdc, INT fuPlanes, INT64 target_msc, INT64 divisor, INT64 remainder);
OPENGL_INIT_PROC(wglWaitForMscOML,          BOOL,  HDC hdc, INT64 target_msc, INT64 divisor, INT64 remainder, INT64 *ust, INT64 *msc, INT64 *sbc);
OPENGL_INIT_PROC(wglWaitForSbcOML,          BOOL,  HDC hdc, INT64 target_sbc, INT64 *ust, INT64 *msc, INT64 *sbc);

#define wglGetSyncValuesOML       OGL__wglGetSyncValuesOML
#define wglGetMscRateOML          OGL__wglGetMscRateOML
#define wglSwapBuffersMscOML      OGL__wglSwapBuffersMscOML
#define wglSwapLayerBuffersMscOML OGL__wglSwapLayerBuffersMscOML
#define wglWaitForMscOML          OGL__wglWaitForMscOML
#define wglWaitForSbcOML          OGL__wglWaitForSbcOML

#endif // WGL_OML_sync_control

#endif // OPENGL_INCLUDE_WGL_OML_sync_control

/* -------------------------------------------------------------------------- */

EXTERN_C_END /*****************************************************************/

/* -------------------------------------------------------------------------- */

/*////////////////////////////////////////////////////////////////////////////*/

#endif /* WGL_H__ ////////////////////////////////////////////////////////////*/

/*******************************************************************************
 * Copyright (c) 2013-2018 The Khronos Group Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and/or associated documentation files (the "Materials"), to
 * deal in the Materials without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Materials, and to permit persons to whom the Materials
 * are furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Materials.
 *
 * THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE MATERIALS OR THE USE OR OTHER
 * DEALINGS IN THE MATERIALS.
 *
*******************************************************************************/
