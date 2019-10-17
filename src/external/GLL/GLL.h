/*******************************************************************************
 * Utility for loading OpenGL functionality for the desired GL version.
 * Available Under Public Domain or MIT License (See EOF)
 * Authored By Joshua Robertson
 *
*******************************************************************************/

#ifndef __GLL_H__ /*//////////////////////////////////////////////////////////*/
#define __GLL_H__

/* -------------------------------------------------------------------------- */

#include <stddef.h>

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#include <windows.h>
#endif

/* -------------------------------------------------------------------------- */

#ifdef __cplusplus
extern "C" {
#endif

/* -------------------------------------------------------------------------- */

// We provide our own GL and KHR Platform headers but if someone wants to use
// another header implementation instead then that is perfectly acceptable.

#ifndef GLL_INCLUDE_KHR_H
#define GLL_INCLUDE_KHR_H "GL/KHR/khrplatform.h"
#endif
#ifndef GLL_INCLUDE_GL_H
#define GLL_INCLUDE_GL_H  "GL/GL.h"
#endif

// We will use the C-style assert but if someone wants to override and use a
// custom assert implementation instead then that is perfectly acceptable.

#ifndef GLL_ASSERT
#ifndef GLL_DEBUG_BUILD
#define GLL_ASSERT(_e) ((void)0)
#else
#include <assert.h>
#define GLL_ASSERT(_e) assert(_e)
#endif
#endif

#if defined(__cplusplus)
#define GLL_INLINE inline
#else
#if   defined(__GNUC__)
#define GLL_INLINE __inline__
#elif defined(_MSC_VER)    || defined(__BORLANDC__) || \
      defined(__DMC__)     || defined(__SC__)       || \
      defined(__WATCOMC__) || defined(__LCC__)      || \
      defined(__DECC)      || defined(__CC_ARM)
#define GLL_INLINE __inline
#ifndef __inline__
#define __inline__ __inline
#endif
#else
#define GLL_INLINE inline
#ifndef __inline__
#define __inline__ inline
#endif
#endif
#endif

#ifndef GLL_STATIC
#define GLL_STDDEF static
#define GLL_INLDEF GLL_STDDEF GLL_INLINE
#else
#define GLL_STDDEF extern
#define GLL_INLDEF GLL_STDDEF GLL_INLINE
#endif

#define GLL_INITPROC(_name, _return, ...)                \
typedef _return (APIENTRYP GLL_GL_##_name)(__VA_ARGS__); \
GLAPI GLL_GL_##_name GLL_##_name;                        \
GLL_GL_##_name GLL_##_name = NULL

#define GLL_LOADPROC(_name, _proc_loader)                \
GLL_##_name = (GLL_GL_##_name)((_proc_loader)(#_name))

/* -------------------------------------------------------------------------- */

#include GLL_INCLUDE_KHR_H
#include GLL_INCLUDE_GL_H

/* -------------------------------------------------------------------------- */

#define GLL_LOAD_CORE_PROFILE 0x01
#define GLL_LOAD_COMP_PROFILE 0x02

typedef int GLL_bool;

#define GLL_FALSE 0
#define GLL_TRUE  1

typedef void* (*GLL_proc_loader)(const char* _name);

GLL_STDDEF GLL_bool GLL_load_gl_procs (int _major, int _minor, int _profile, GLL_proc_loader _proc_loader);
GLL_INLDEF GLL_bool GLL_is_proc_valid (void* _proc);

/* -------------------------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

/* -------------------------------------------------------------------------- */

#endif /* __GLL_H__ //////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/
/*////////////////////////////// IMPLEMENTATION //////////////////////////////*/
/*////////////////////////////////////////////////////////////////////////////*/

#ifdef GLL_IMPLEMENTATION /*//////////////////////////////////////////////////*/

/* -------------------------------------------------------------------------- */

#include <string.h>
#include <stdio.h>

/* -------------------------------------------------------------------------- */

static GLL_INLINE void GLL__load_gl_version_100 (GLL_proc_loader, GLL_bool);
static GLL_INLINE void GLL__load_gl_version_110 (GLL_proc_loader, GLL_bool);
static GLL_INLINE void GLL__load_gl_version_120 (GLL_proc_loader, GLL_bool);
static GLL_INLINE void GLL__load_gl_version_130 (GLL_proc_loader, GLL_bool);
static GLL_INLINE void GLL__load_gl_version_140 (GLL_proc_loader, GLL_bool);
static GLL_INLINE void GLL__load_gl_version_150 (GLL_proc_loader, GLL_bool);
static GLL_INLINE void GLL__load_gl_version_200 (GLL_proc_loader, GLL_bool);
static GLL_INLINE void GLL__load_gl_version_210 (GLL_proc_loader, GLL_bool);
static GLL_INLINE void GLL__load_gl_version_300 (GLL_proc_loader, GLL_bool);
static GLL_INLINE void GLL__load_gl_version_310 (GLL_proc_loader, GLL_bool);
static GLL_INLINE void GLL__load_gl_version_320 (GLL_proc_loader, GLL_bool);
static GLL_INLINE void GLL__load_gl_version_330 (GLL_proc_loader, GLL_bool);
static GLL_INLINE void GLL__load_gl_version_400 (GLL_proc_loader, GLL_bool);
static GLL_INLINE void GLL__load_gl_version_410 (GLL_proc_loader, GLL_bool);
static GLL_INLINE void GLL__load_gl_version_420 (GLL_proc_loader, GLL_bool);
static GLL_INLINE void GLL__load_gl_version_430 (GLL_proc_loader, GLL_bool);
static GLL_INLINE void GLL__load_gl_version_440 (GLL_proc_loader, GLL_bool);
static GLL_INLINE void GLL__load_gl_version_450 (GLL_proc_loader, GLL_bool);
static GLL_INLINE void GLL__load_gl_version_460 (GLL_proc_loader, GLL_bool);

/* -------------------------------------------------------------------------- */

static GLL_INLINE int GLL__get_ver__old (void)
{
    const char* prefix[] = { "OpenGL ES-CM ", "OpenGL ES-CL ", "OpenGL ES " };
    const char* version = (const char*)glGetString(GL_VERSION);

    for (int i=0; i<(sizeof(prefix)/sizeof((prefix)[0])); ++i) {
        int length = strlen(prefix[i]);
        if (strncmp(version, prefix[i], length) == 0) {
            version += length;
            break;
        }
    }

    int major, minor;
    sscanf(version, "%d.%d", &major, &minor);

    return (major * 100) + (minor * 10);
}
static GLL_INLINE int GLL__get_ver__new (void)
{
    GLint major, minor;

    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);

    return (major * 100) + (minor * 10);
}

/* -------------------------------------------------------------------------- */

GLL_STDDEF GLL_bool GLL_load_gl_procs (int _major, int _minor, int _profile, GLL_proc_loader _proc_loader)
{
    GLL_ASSERT(_proc_loader);

    // Preload functions that we use internally for specific processes.
    GLL_LOADPROC(glGetIntegerv, _proc_loader);
    GLL_LOADPROC(glGetString,   _proc_loader);
    GLL_LOADPROC(glGetStringi,  _proc_loader);

    // Determining the OpenGL version uses a different method based on
    // which method is available (we prefer GetInteger over GetString).
    int (*get_gl_version)(void) = NULL;

    if      (GLL_is_proc_valid(glGetIntegerv)) { get_gl_version = GLL__get_ver__new; }
    else if (GLL_is_proc_valid(glGetString))   { get_gl_version = GLL__get_ver__old; }
    else                                       { return GL_FALSE;                    }

    // Determine if user wants to load core or compatibility procs.
    GLL_bool load_comp = (_profile == GLL_LOAD_COMP_PROFILE);

    // Only load the OpenGL functions that we have access to. This
    // will either be the desired set of OpenGL functions or less.
    int desired = (_major * 100) + (_minor * 10);
    int current = get_gl_version();

    // Ensures we only load what we want, not what we have access to.
    if (desired < current) { current = desired; }

    if (current >= 100) { GLL__load_gl_version_100(_proc_loader, load_comp); }
    if (current >= 110) { GLL__load_gl_version_110(_proc_loader, load_comp); }
    if (current >= 120) { GLL__load_gl_version_120(_proc_loader, load_comp); }
    if (current >= 130) { GLL__load_gl_version_130(_proc_loader, load_comp); }
    if (current >= 140) { GLL__load_gl_version_140(_proc_loader, load_comp); }
    if (current >= 150) { GLL__load_gl_version_150(_proc_loader, load_comp); }
    if (current >= 200) { GLL__load_gl_version_200(_proc_loader, load_comp); }
    if (current >= 210) { GLL__load_gl_version_210(_proc_loader, load_comp); }
    if (current >= 300) { GLL__load_gl_version_300(_proc_loader, load_comp); }
    if (current >= 310) { GLL__load_gl_version_310(_proc_loader, load_comp); }
    if (current >= 320) { GLL__load_gl_version_320(_proc_loader, load_comp); }
    if (current >= 330) { GLL__load_gl_version_330(_proc_loader, load_comp); }
    if (current >= 400) { GLL__load_gl_version_400(_proc_loader, load_comp); }
    if (current >= 410) { GLL__load_gl_version_410(_proc_loader, load_comp); }
    if (current >= 420) { GLL__load_gl_version_420(_proc_loader, load_comp); }
    if (current >= 430) { GLL__load_gl_version_430(_proc_loader, load_comp); }
    if (current >= 440) { GLL__load_gl_version_440(_proc_loader, load_comp); }
    if (current >= 450) { GLL__load_gl_version_450(_proc_loader, load_comp); }
    if (current >= 460) { GLL__load_gl_version_460(_proc_loader, load_comp); }

    return GL_TRUE;
}

GLL_INLDEF GLL_bool GLL_is_proc_valid (void* _proc)
{
    // Certain GL proc loaders (e.g. Windows) may return non-null values
    // to represent failure -- depening on the implementation. So it is
    // preferred that this function be used to check if a proc is valid.
    //
    // https://www.khronos.org/opengl/wiki/Load_OpenGL_Functions#Windows

    return !((_proc == (void*)0x0) || (_proc == (void*)0x1) ||
             (_proc == (void*)0x2) || (_proc == (void*)0x3) ||
             (_proc == (void*) -1));
}

/* -------------------------------------------------------------------------- */

static GLL_INLINE void GLL__load_gl_version_100 (GLL_proc_loader _proc_loader, GLL_bool _load_comp)
{
    GLL_LOADPROC(glCullFace,                                    _proc_loader);
    GLL_LOADPROC(glFrontFace,                                   _proc_loader);
    GLL_LOADPROC(glHint,                                        _proc_loader);
    GLL_LOADPROC(glLineWidth,                                   _proc_loader);
    GLL_LOADPROC(glPointSize,                                   _proc_loader);
    GLL_LOADPROC(glPolygonMode,                                 _proc_loader);
    GLL_LOADPROC(glScissor,                                     _proc_loader);
    GLL_LOADPROC(glTexParameterf,                               _proc_loader);
    GLL_LOADPROC(glTexParameterfv,                              _proc_loader);
    GLL_LOADPROC(glTexParameteri,                               _proc_loader);
    GLL_LOADPROC(glTexParameteriv,                              _proc_loader);
    GLL_LOADPROC(glTexImage1D,                                  _proc_loader);
    GLL_LOADPROC(glTexImage2D,                                  _proc_loader);
    GLL_LOADPROC(glDrawBuffer,                                  _proc_loader);
    GLL_LOADPROC(glClear,                                       _proc_loader);
    GLL_LOADPROC(glClearColor,                                  _proc_loader);
    GLL_LOADPROC(glClearStencil,                                _proc_loader);
    GLL_LOADPROC(glClearDepth,                                  _proc_loader);
    GLL_LOADPROC(glStencilMask,                                 _proc_loader);
    GLL_LOADPROC(glColorMask,                                   _proc_loader);
    GLL_LOADPROC(glDepthMask,                                   _proc_loader);
    GLL_LOADPROC(glDisable,                                     _proc_loader);
    GLL_LOADPROC(glEnable,                                      _proc_loader);
    GLL_LOADPROC(glFinish,                                      _proc_loader);
    GLL_LOADPROC(glFlush,                                       _proc_loader);
    GLL_LOADPROC(glBlendFunc,                                   _proc_loader);
    GLL_LOADPROC(glLogicOp,                                     _proc_loader);
    GLL_LOADPROC(glStencilFunc,                                 _proc_loader);
    GLL_LOADPROC(glStencilOp,                                   _proc_loader);
    GLL_LOADPROC(glDepthFunc,                                   _proc_loader);
    GLL_LOADPROC(glPixelStoref,                                 _proc_loader);
    GLL_LOADPROC(glPixelStorei,                                 _proc_loader);
    GLL_LOADPROC(glReadBuffer,                                  _proc_loader);
    GLL_LOADPROC(glReadPixels,                                  _proc_loader);
    GLL_LOADPROC(glGetBooleanv,                                 _proc_loader);
    GLL_LOADPROC(glGetDoublev,                                  _proc_loader);
    GLL_LOADPROC(glGetError,                                    _proc_loader);
    GLL_LOADPROC(glGetFloatv,                                   _proc_loader);
    GLL_LOADPROC(glGetIntegerv,                                 _proc_loader);
    GLL_LOADPROC(glGetString,                                   _proc_loader);
    GLL_LOADPROC(glGetTexImage,                                 _proc_loader);
    GLL_LOADPROC(glGetTexParameterfv,                           _proc_loader);
    GLL_LOADPROC(glGetTexParameteriv,                           _proc_loader);
    GLL_LOADPROC(glGetTexLevelParameterfv,                      _proc_loader);
    GLL_LOADPROC(glGetTexLevelParameteriv,                      _proc_loader);
    GLL_LOADPROC(glIsEnabled,                                   _proc_loader);
    GLL_LOADPROC(glDepthRange,                                  _proc_loader);
    GLL_LOADPROC(glViewport,                                    _proc_loader);
    GLL_LOADPROC(glNewList,                                     _proc_loader);

    if (!_load_comp) { return; }

    GLL_LOADPROC(glEndList,                                     _proc_loader);
    GLL_LOADPROC(glCallList,                                    _proc_loader);
    GLL_LOADPROC(glCallLists,                                   _proc_loader);
    GLL_LOADPROC(glDeleteLists,                                 _proc_loader);
    GLL_LOADPROC(glGenLists,                                    _proc_loader);
    GLL_LOADPROC(glListBase,                                    _proc_loader);
    GLL_LOADPROC(glBegin,                                       _proc_loader);
    GLL_LOADPROC(glBitmap,                                      _proc_loader);
    GLL_LOADPROC(glColor3b,                                     _proc_loader);
    GLL_LOADPROC(glColor3bv,                                    _proc_loader);
    GLL_LOADPROC(glColor3d,                                     _proc_loader);
    GLL_LOADPROC(glColor3dv,                                    _proc_loader);
    GLL_LOADPROC(glColor3f,                                     _proc_loader);
    GLL_LOADPROC(glColor3fv,                                    _proc_loader);
    GLL_LOADPROC(glColor3i,                                     _proc_loader);
    GLL_LOADPROC(glColor3iv,                                    _proc_loader);
    GLL_LOADPROC(glColor3s,                                     _proc_loader);
    GLL_LOADPROC(glColor3sv,                                    _proc_loader);
    GLL_LOADPROC(glColor3ub,                                    _proc_loader);
    GLL_LOADPROC(glColor3ubv,                                   _proc_loader);
    GLL_LOADPROC(glColor3ui,                                    _proc_loader);
    GLL_LOADPROC(glColor3uiv,                                   _proc_loader);
    GLL_LOADPROC(glColor3us,                                    _proc_loader);
    GLL_LOADPROC(glColor3usv,                                   _proc_loader);
    GLL_LOADPROC(glColor4b,                                     _proc_loader);
    GLL_LOADPROC(glColor4bv,                                    _proc_loader);
    GLL_LOADPROC(glColor4d,                                     _proc_loader);
    GLL_LOADPROC(glColor4dv,                                    _proc_loader);
    GLL_LOADPROC(glColor4f,                                     _proc_loader);
    GLL_LOADPROC(glColor4fv,                                    _proc_loader);
    GLL_LOADPROC(glColor4i,                                     _proc_loader);
    GLL_LOADPROC(glColor4iv,                                    _proc_loader);
    GLL_LOADPROC(glColor4s,                                     _proc_loader);
    GLL_LOADPROC(glColor4sv,                                    _proc_loader);
    GLL_LOADPROC(glColor4ub,                                    _proc_loader);
    GLL_LOADPROC(glColor4ubv,                                   _proc_loader);
    GLL_LOADPROC(glColor4ui,                                    _proc_loader);
    GLL_LOADPROC(glColor4uiv,                                   _proc_loader);
    GLL_LOADPROC(glColor4us,                                    _proc_loader);
    GLL_LOADPROC(glColor4usv,                                   _proc_loader);
    GLL_LOADPROC(glEdgeFlag,                                    _proc_loader);
    GLL_LOADPROC(glEdgeFlagv,                                   _proc_loader);
    GLL_LOADPROC(glEnd,                                         _proc_loader);
    GLL_LOADPROC(glIndexd,                                      _proc_loader);
    GLL_LOADPROC(glIndexdv,                                     _proc_loader);
    GLL_LOADPROC(glIndexf,                                      _proc_loader);
    GLL_LOADPROC(glIndexfv,                                     _proc_loader);
    GLL_LOADPROC(glIndexi,                                      _proc_loader);
    GLL_LOADPROC(glIndexiv,                                     _proc_loader);
    GLL_LOADPROC(glIndexs,                                      _proc_loader);
    GLL_LOADPROC(glIndexsv,                                     _proc_loader);
    GLL_LOADPROC(glNormal3b,                                    _proc_loader);
    GLL_LOADPROC(glNormal3bv,                                   _proc_loader);
    GLL_LOADPROC(glNormal3d,                                    _proc_loader);
    GLL_LOADPROC(glNormal3dv,                                   _proc_loader);
    GLL_LOADPROC(glNormal3f,                                    _proc_loader);
    GLL_LOADPROC(glNormal3fv,                                   _proc_loader);
    GLL_LOADPROC(glNormal3i,                                    _proc_loader);
    GLL_LOADPROC(glNormal3uv,                                   _proc_loader);
    GLL_LOADPROC(glNormal3s,                                    _proc_loader);
    GLL_LOADPROC(glNormal3sv,                                   _proc_loader);
    GLL_LOADPROC(glRasterPos2d,                                 _proc_loader);
    GLL_LOADPROC(glRasterPos2dv,                                _proc_loader);
    GLL_LOADPROC(glRasterPos2f,                                 _proc_loader);
    GLL_LOADPROC(glRasterPos2fv,                                _proc_loader);
    GLL_LOADPROC(glRasterPos2i,                                 _proc_loader);
    GLL_LOADPROC(glRasterPos2iv,                                _proc_loader);
    GLL_LOADPROC(glRasterPos2s,                                 _proc_loader);
    GLL_LOADPROC(glRasterPos2sv,                                _proc_loader);
    GLL_LOADPROC(glRasterPos3d,                                 _proc_loader);
    GLL_LOADPROC(glRasterPos3dv,                                _proc_loader);
    GLL_LOADPROC(glRasterPos3f,                                 _proc_loader);
    GLL_LOADPROC(glRasterPos3fv,                                _proc_loader);
    GLL_LOADPROC(glRasterPos3i,                                 _proc_loader);
    GLL_LOADPROC(glRasterPos3iv,                                _proc_loader);
    GLL_LOADPROC(glRasterPos3s,                                 _proc_loader);
    GLL_LOADPROC(glRasterPos3sv,                                _proc_loader);
    GLL_LOADPROC(glRasterPos4d,                                 _proc_loader);
    GLL_LOADPROC(glRasterPos4dv,                                _proc_loader);
    GLL_LOADPROC(glRasterPos4f,                                 _proc_loader);
    GLL_LOADPROC(glRasterPos4fv,                                _proc_loader);
    GLL_LOADPROC(glRasterPos4i,                                 _proc_loader);
    GLL_LOADPROC(glRasterPos4iv,                                _proc_loader);
    GLL_LOADPROC(glRasterPos4s,                                 _proc_loader);
    GLL_LOADPROC(glRasterPos4sv,                                _proc_loader);
    GLL_LOADPROC(glRectd,                                       _proc_loader);
    GLL_LOADPROC(glRectdv,                                      _proc_loader);
    GLL_LOADPROC(glRectf,                                       _proc_loader);
    GLL_LOADPROC(glRectfv,                                      _proc_loader);
    GLL_LOADPROC(glRecti,                                       _proc_loader);
    GLL_LOADPROC(glRectiv,                                      _proc_loader);
    GLL_LOADPROC(glRects,                                       _proc_loader);
    GLL_LOADPROC(glRectsv,                                      _proc_loader);
    GLL_LOADPROC(glTexCoord1d,                                  _proc_loader);
    GLL_LOADPROC(glTexCoord1dv,                                 _proc_loader);
    GLL_LOADPROC(glTexCoord1f,                                  _proc_loader);
    GLL_LOADPROC(glTexCoord1fv,                                 _proc_loader);
    GLL_LOADPROC(glTexCoord1i,                                  _proc_loader);
    GLL_LOADPROC(glTexCoord1iv,                                 _proc_loader);
    GLL_LOADPROC(glTexCoord1s,                                  _proc_loader);
    GLL_LOADPROC(glTexCoord1sv,                                 _proc_loader);
    GLL_LOADPROC(glTexCoord2d,                                  _proc_loader);
    GLL_LOADPROC(glTexCoord2dv,                                 _proc_loader);
    GLL_LOADPROC(glTexCoord2f,                                  _proc_loader);
    GLL_LOADPROC(glTexCoord2fv,                                 _proc_loader);
    GLL_LOADPROC(glTexCoord2i,                                  _proc_loader);
    GLL_LOADPROC(glTexCoord2iv,                                 _proc_loader);
    GLL_LOADPROC(glTexCoord2s,                                  _proc_loader);
    GLL_LOADPROC(glTexCoord2sv,                                 _proc_loader);
    GLL_LOADPROC(glTexCoord3d,                                  _proc_loader);
    GLL_LOADPROC(glTexCoord3dv,                                 _proc_loader);
    GLL_LOADPROC(glTexCoord3f,                                  _proc_loader);
    GLL_LOADPROC(glTexCoord3fv,                                 _proc_loader);
    GLL_LOADPROC(glTexCoord3i,                                  _proc_loader);
    GLL_LOADPROC(glTexCoord3iv,                                 _proc_loader);
    GLL_LOADPROC(glTexCoord3s,                                  _proc_loader);
    GLL_LOADPROC(glTexCoord3sv,                                 _proc_loader);
    GLL_LOADPROC(glTexCoord4d,                                  _proc_loader);
    GLL_LOADPROC(glTexCoord4dv,                                 _proc_loader);
    GLL_LOADPROC(glTexCoord4f,                                  _proc_loader);
    GLL_LOADPROC(glTexCoord4fv,                                 _proc_loader);
    GLL_LOADPROC(glTexCoord4i,                                  _proc_loader);
    GLL_LOADPROC(glTexCoord4iv,                                 _proc_loader);
    GLL_LOADPROC(glTexCoord4s,                                  _proc_loader);
    GLL_LOADPROC(glTexCoord4sv,                                 _proc_loader);
    GLL_LOADPROC(glVertex2d,                                    _proc_loader);
    GLL_LOADPROC(glVertex2dv,                                   _proc_loader);
    GLL_LOADPROC(glVertex2f,                                    _proc_loader);
    GLL_LOADPROC(glVertex2fv,                                   _proc_loader);
    GLL_LOADPROC(glVertex2i,                                    _proc_loader);
    GLL_LOADPROC(glVertex2iv,                                   _proc_loader);
    GLL_LOADPROC(glVertex2s,                                    _proc_loader);
    GLL_LOADPROC(glVertex2sv,                                   _proc_loader);
    GLL_LOADPROC(glVertex3d,                                    _proc_loader);
    GLL_LOADPROC(glVertex3dv,                                   _proc_loader);
    GLL_LOADPROC(glVertex3f,                                    _proc_loader);
    GLL_LOADPROC(glVertex3fv,                                   _proc_loader);
    GLL_LOADPROC(glVertex3i,                                    _proc_loader);
    GLL_LOADPROC(glVertex3iv,                                   _proc_loader);
    GLL_LOADPROC(glVertex3s,                                    _proc_loader);
    GLL_LOADPROC(glVertex3sv,                                   _proc_loader);
    GLL_LOADPROC(glVertex4d,                                    _proc_loader);
    GLL_LOADPROC(glVertex4dv,                                   _proc_loader);
    GLL_LOADPROC(glVertex4f,                                    _proc_loader);
    GLL_LOADPROC(glVertex4fv,                                   _proc_loader);
    GLL_LOADPROC(glVertex4i,                                    _proc_loader);
    GLL_LOADPROC(glVertex4iv,                                   _proc_loader);
    GLL_LOADPROC(glVertex4s,                                    _proc_loader);
    GLL_LOADPROC(glVertex4sv,                                   _proc_loader);
    GLL_LOADPROC(glClipPlane,                                   _proc_loader);
    GLL_LOADPROC(glColorMaterial,                               _proc_loader);
    GLL_LOADPROC(glFogf,                                        _proc_loader);
    GLL_LOADPROC(glFogfv,                                       _proc_loader);
    GLL_LOADPROC(glFogi,                                        _proc_loader);
    GLL_LOADPROC(glFogiv,                                       _proc_loader);
    GLL_LOADPROC(glLightf,                                      _proc_loader);
    GLL_LOADPROC(glLightfv,                                     _proc_loader);
    GLL_LOADPROC(glLighti,                                      _proc_loader);
    GLL_LOADPROC(glLightiv,                                     _proc_loader);
    GLL_LOADPROC(glLightModelf,                                 _proc_loader);
    GLL_LOADPROC(glLightModelfv,                                _proc_loader);
    GLL_LOADPROC(glLightModeli,                                 _proc_loader);
    GLL_LOADPROC(glLightModeliv,                                _proc_loader);
    GLL_LOADPROC(glLineStipple,                                 _proc_loader);
    GLL_LOADPROC(glMaterialf,                                   _proc_loader);
    GLL_LOADPROC(glMaterialfv,                                  _proc_loader);
    GLL_LOADPROC(glMateriali,                                   _proc_loader);
    GLL_LOADPROC(glMaterialiv,                                  _proc_loader);
    GLL_LOADPROC(glPolygonStipple,                              _proc_loader);
    GLL_LOADPROC(glShadeModel,                                  _proc_loader);
    GLL_LOADPROC(glTexEnvf,                                     _proc_loader);
    GLL_LOADPROC(glTexEnvfv,                                    _proc_loader);
    GLL_LOADPROC(glTexEnvi,                                     _proc_loader);
    GLL_LOADPROC(glTexEnviv,                                    _proc_loader);
    GLL_LOADPROC(glTexGend,                                     _proc_loader);
    GLL_LOADPROC(glTexGendv,                                    _proc_loader);
    GLL_LOADPROC(glTexGenf,                                     _proc_loader);
    GLL_LOADPROC(glTexGenfv,                                    _proc_loader);
    GLL_LOADPROC(glTexGeni,                                     _proc_loader);
    GLL_LOADPROC(glTexGeniv,                                    _proc_loader);
    GLL_LOADPROC(glFeedbackBuffer,                              _proc_loader);
    GLL_LOADPROC(glSelectBuffer,                                _proc_loader);
    GLL_LOADPROC(glRenderMode,                                  _proc_loader);
    GLL_LOADPROC(glInitNames,                                   _proc_loader);
    GLL_LOADPROC(glLoadName,                                    _proc_loader);
    GLL_LOADPROC(glPassThrough,                                 _proc_loader);
    GLL_LOADPROC(glPopName,                                     _proc_loader);
    GLL_LOADPROC(glPushName,                                    _proc_loader);
    GLL_LOADPROC(glClearAccum,                                  _proc_loader);
    GLL_LOADPROC(glClearIndex,                                  _proc_loader);
    GLL_LOADPROC(glIndexMask,                                   _proc_loader);
    GLL_LOADPROC(glAccum,                                       _proc_loader);
    GLL_LOADPROC(glPopAttrib,                                   _proc_loader);
    GLL_LOADPROC(glPushAttrib,                                  _proc_loader);
    GLL_LOADPROC(glMap1d,                                       _proc_loader);
    GLL_LOADPROC(glMap1f,                                       _proc_loader);
    GLL_LOADPROC(glMap2d,                                       _proc_loader);
    GLL_LOADPROC(glMap2f,                                       _proc_loader);
    GLL_LOADPROC(glMapGrid1d,                                   _proc_loader);
    GLL_LOADPROC(glMapGrid1f,                                   _proc_loader);
    GLL_LOADPROC(glMapGrid2d,                                   _proc_loader);
    GLL_LOADPROC(glMapGrid2f,                                   _proc_loader);
    GLL_LOADPROC(glEvalCoord1d,                                 _proc_loader);
    GLL_LOADPROC(glEvalCoord1dv,                                _proc_loader);
    GLL_LOADPROC(glEvalCoord1f,                                 _proc_loader);
    GLL_LOADPROC(glEvalCoord1fv,                                _proc_loader);
    GLL_LOADPROC(glEvalCoord2d,                                 _proc_loader);
    GLL_LOADPROC(glEvalCoord2dv,                                _proc_loader);
    GLL_LOADPROC(glEvalCoord2f,                                 _proc_loader);
    GLL_LOADPROC(glEvalCoord2fv,                                _proc_loader);
    GLL_LOADPROC(glEvalMesh1,                                   _proc_loader);
    GLL_LOADPROC(glEvalPoint1,                                  _proc_loader);
    GLL_LOADPROC(glEvalMesh2,                                   _proc_loader);
    GLL_LOADPROC(glEvalPoint2,                                  _proc_loader);
    GLL_LOADPROC(glAlphaFunc,                                   _proc_loader);
    GLL_LOADPROC(glPixelZoom,                                   _proc_loader);
    GLL_LOADPROC(glPixelTransferf,                              _proc_loader);
    GLL_LOADPROC(glPixelTransferi,                              _proc_loader);
    GLL_LOADPROC(glPixelMapfv,                                  _proc_loader);
    GLL_LOADPROC(glPixelMapuiv,                                 _proc_loader);
    GLL_LOADPROC(glPixelMapusv,                                 _proc_loader);
    GLL_LOADPROC(glCopyPixels,                                  _proc_loader);
    GLL_LOADPROC(glDrawPixels,                                  _proc_loader);
    GLL_LOADPROC(glGetClipPlane,                                _proc_loader);
    GLL_LOADPROC(glGetLightfv,                                  _proc_loader);
    GLL_LOADPROC(glGetLightiv,                                  _proc_loader);
    GLL_LOADPROC(glGetMapdv,                                    _proc_loader);
    GLL_LOADPROC(glGetMapfv,                                    _proc_loader);
    GLL_LOADPROC(glGetMapiv,                                    _proc_loader);
    GLL_LOADPROC(glGetMaterialfv,                               _proc_loader);
    GLL_LOADPROC(glGetMaterialiv,                               _proc_loader);
    GLL_LOADPROC(glGetPixelMapfv,                               _proc_loader);
    GLL_LOADPROC(glGetPixelMapuiv,                              _proc_loader);
    GLL_LOADPROC(glGetPixelMapusv,                              _proc_loader);
    GLL_LOADPROC(glGetPolygonStipple,                           _proc_loader);
    GLL_LOADPROC(glGetTexEnvfv,                                 _proc_loader);
    GLL_LOADPROC(glGetTexEnviv,                                 _proc_loader);
    GLL_LOADPROC(glGetTexGendv,                                 _proc_loader);
    GLL_LOADPROC(glGetTexGenfv,                                 _proc_loader);
    GLL_LOADPROC(glGetTexGeniv,                                 _proc_loader);
    GLL_LOADPROC(glIsList,                                      _proc_loader);
    GLL_LOADPROC(glFrustum,                                     _proc_loader);
    GLL_LOADPROC(glLoadIdentity,                                _proc_loader);
    GLL_LOADPROC(glLoadMatrixf,                                 _proc_loader);
    GLL_LOADPROC(glLoadMatrixd,                                 _proc_loader);
    GLL_LOADPROC(glMatrixMode,                                  _proc_loader);
    GLL_LOADPROC(glMultMatrixf,                                 _proc_loader);
    GLL_LOADPROC(glMultMatrixd,                                 _proc_loader);
    GLL_LOADPROC(glOrtho,                                       _proc_loader);
    GLL_LOADPROC(glPopMatrix,                                   _proc_loader);
    GLL_LOADPROC(glPushMatrix,                                  _proc_loader);
    GLL_LOADPROC(glRotated,                                     _proc_loader);
    GLL_LOADPROC(glRotatef,                                     _proc_loader);
    GLL_LOADPROC(glScaled,                                      _proc_loader);
    GLL_LOADPROC(glScalef,                                      _proc_loader);
    GLL_LOADPROC(glTranslated,                                  _proc_loader);
    GLL_LOADPROC(glTranslatef,                                  _proc_loader);
}

static GLL_INLINE void GLL__load_gl_version_110 (GLL_proc_loader _proc_loader, GLL_bool _load_comp)
{
    GLL_LOADPROC(glDrawArrays,                                  _proc_loader);
    GLL_LOADPROC(glDrawElements,                                _proc_loader);
    GLL_LOADPROC(glGetPointerv,                                 _proc_loader);
    GLL_LOADPROC(glPolygonOffset,                               _proc_loader);
    GLL_LOADPROC(glCopyTexImage1D,                              _proc_loader);
    GLL_LOADPROC(glCopyTexImage2D,                              _proc_loader);
    GLL_LOADPROC(glCopyTexSubImage1D,                           _proc_loader);
    GLL_LOADPROC(glCopyTexSubImage2D,                           _proc_loader);
    GLL_LOADPROC(glTexSubImage1D,                               _proc_loader);
    GLL_LOADPROC(glTexSubImage2D,                               _proc_loader);
    GLL_LOADPROC(glBindTexture,                                 _proc_loader);
    GLL_LOADPROC(glDeleteTextures,                              _proc_loader);
    GLL_LOADPROC(glGenTextures,                                 _proc_loader);
    GLL_LOADPROC(glIsTexture,                                   _proc_loader);

    if (!_load_comp) { return; }

    GLL_LOADPROC(glArrayElement,                                _proc_loader);
    GLL_LOADPROC(glColorPointer,                                _proc_loader);
    GLL_LOADPROC(glDisableClientState,                          _proc_loader);
    GLL_LOADPROC(glEdgeFlagPointer,                             _proc_loader);
    GLL_LOADPROC(glEnableClientState,                           _proc_loader);
    GLL_LOADPROC(glIndexPointer,                                _proc_loader);
    GLL_LOADPROC(glInterleavedArrays,                           _proc_loader);
    GLL_LOADPROC(glNormalPointer,                               _proc_loader);
    GLL_LOADPROC(glTexCoordPointer,                             _proc_loader);
    GLL_LOADPROC(glVertexPointer,                               _proc_loader);
    GLL_LOADPROC(glAreTexturesResident,                         _proc_loader);
    GLL_LOADPROC(glPrioritizeTextures,                          _proc_loader);
    GLL_LOADPROC(glIndexub,                                     _proc_loader);
    GLL_LOADPROC(glIndexubv,                                    _proc_loader);
    GLL_LOADPROC(glPopClientAttrib,                             _proc_loader);
    GLL_LOADPROC(glPushClientAttrib,                            _proc_loader);
}

static GLL_INLINE void GLL__load_gl_version_120 (GLL_proc_loader _proc_loader, GLL_bool _load_comp)
{
    GLL_LOADPROC(glDrawRangeElements,                           _proc_loader);
    GLL_LOADPROC(glTexImage3D,                                  _proc_loader);
    GLL_LOADPROC(glTexSubImage3D,                               _proc_loader);
    GLL_LOADPROC(glCopyTexSubImage3D,                           _proc_loader);
}

static GLL_INLINE void GLL__load_gl_version_130 (GLL_proc_loader _proc_loader, GLL_bool _load_comp)
{
    GLL_LOADPROC(glActiveTexture,                               _proc_loader);
    GLL_LOADPROC(glSampleCoverage,                              _proc_loader);
    GLL_LOADPROC(glCompressedTexImage3D,                        _proc_loader);
    GLL_LOADPROC(glCompressedTexImage2D,                        _proc_loader);
    GLL_LOADPROC(glCompressedTexImage1D,                        _proc_loader);
    GLL_LOADPROC(glCompressedTexSubImage3D,                     _proc_loader);
    GLL_LOADPROC(glCompressedTexSubImage2D,                     _proc_loader);
    GLL_LOADPROC(glCompressedTexSubImage1D,                     _proc_loader);
    GLL_LOADPROC(glGetCompressedTexImage,                       _proc_loader);

    if (!_load_comp) { return; }

    GLL_LOADPROC(glClientActiveTexture,                         _proc_loader);
    GLL_LOADPROC(glMultiTexCoord1d,                             _proc_loader);
    GLL_LOADPROC(glMultiTexCoord1dv,                            _proc_loader);
    GLL_LOADPROC(glMultiTexCoord1f,                             _proc_loader);
    GLL_LOADPROC(glMultiTexCoord1fv,                            _proc_loader);
    GLL_LOADPROC(glMultiTexCoord1i,                             _proc_loader);
    GLL_LOADPROC(glMultiTexCoord1iv,                            _proc_loader);
    GLL_LOADPROC(glMultiTexCoord1s,                             _proc_loader);
    GLL_LOADPROC(glMultiTexCoord1sv,                            _proc_loader);
    GLL_LOADPROC(glMultiTexCoord2d,                             _proc_loader);
    GLL_LOADPROC(glMultiTexCoord2dv,                            _proc_loader);
    GLL_LOADPROC(glMultiTexCoord2f,                             _proc_loader);
    GLL_LOADPROC(glMultiTexCoord2fv,                            _proc_loader);
    GLL_LOADPROC(glMultiTexCoord2i,                             _proc_loader);
    GLL_LOADPROC(glMultiTexCoord2iv,                            _proc_loader);
    GLL_LOADPROC(glMultiTexCoord2s,                             _proc_loader);
    GLL_LOADPROC(glMultiTexCoord2sv,                            _proc_loader);
    GLL_LOADPROC(glMultiTexCoord3d,                             _proc_loader);
    GLL_LOADPROC(glMultiTexCoord3dv,                            _proc_loader);
    GLL_LOADPROC(glMultiTexCoord3f,                             _proc_loader);
    GLL_LOADPROC(glMultiTexCoord3fv,                            _proc_loader);
    GLL_LOADPROC(glMultiTexCoord3i,                             _proc_loader);
    GLL_LOADPROC(glMultiTexCoord3iv,                            _proc_loader);
    GLL_LOADPROC(glMultiTexCoord3s,                             _proc_loader);
    GLL_LOADPROC(glMultiTexCoord3sv,                            _proc_loader);
    GLL_LOADPROC(glMultiTexCoord4d,                             _proc_loader);
    GLL_LOADPROC(glMultiTexCoord4dv,                            _proc_loader);
    GLL_LOADPROC(glMultiTexCoord4f,                             _proc_loader);
    GLL_LOADPROC(glMultiTexCoord4fv,                            _proc_loader);
    GLL_LOADPROC(glMultiTexCoord4i,                             _proc_loader);
    GLL_LOADPROC(glMultiTexCoord4iv,                            _proc_loader);
    GLL_LOADPROC(glMultiTexCoord4s,                             _proc_loader);
    GLL_LOADPROC(glMultiTexCoord4sv,                            _proc_loader);
    GLL_LOADPROC(glLoadTransposeMatrixf,                        _proc_loader);
    GLL_LOADPROC(glLoadTransposeMatrixd,                        _proc_loader);
    GLL_LOADPROC(glMultTransposeMatrixf,                        _proc_loader);
    GLL_LOADPROC(glMultTransposeMatrixd,                        _proc_loader);
}

static GLL_INLINE void GLL__load_gl_version_140 (GLL_proc_loader _proc_loader, GLL_bool _load_comp)
{
    GLL_LOADPROC(glBlendFuncSeparate,                           _proc_loader);
    GLL_LOADPROC(glMultiDrawArrays,                             _proc_loader);
    GLL_LOADPROC(glMultiDrawElements,                           _proc_loader);
    GLL_LOADPROC(glPointParameterf,                             _proc_loader);
    GLL_LOADPROC(glPointParameterfv,                            _proc_loader);
    GLL_LOADPROC(glPointParameteri,                             _proc_loader);
    GLL_LOADPROC(glPointParameteriv,                            _proc_loader);
    GLL_LOADPROC(glBlendColor,                                  _proc_loader);
    GLL_LOADPROC(glBlendEquation,                               _proc_loader);

    if (!_load_comp) { return; }

    GLL_LOADPROC(glFogCoordf,                                   _proc_loader);
    GLL_LOADPROC(glFogCoordfv,                                  _proc_loader);
    GLL_LOADPROC(glFogCoordd,                                   _proc_loader);
    GLL_LOADPROC(glFogCoorddv,                                  _proc_loader);
    GLL_LOADPROC(glFogCoordPointer,                             _proc_loader);
    GLL_LOADPROC(glSecondaryColor3b,                            _proc_loader);
    GLL_LOADPROC(glSecondaryColor3bv,                           _proc_loader);
    GLL_LOADPROC(glSecondaryColor3d,                            _proc_loader);
    GLL_LOADPROC(glSecondaryColor3dv,                           _proc_loader);
    GLL_LOADPROC(glSecondaryColor3f,                            _proc_loader);
    GLL_LOADPROC(glSecondaryColor3fv,                           _proc_loader);
    GLL_LOADPROC(glSecondaryColor3i,                            _proc_loader);
    GLL_LOADPROC(glSecondaryColor3iv,                           _proc_loader);
    GLL_LOADPROC(glSecondaryColor3s,                            _proc_loader);
    GLL_LOADPROC(glSecondaryColor3sv,                           _proc_loader);
    GLL_LOADPROC(glSecondaryColor3ub,                           _proc_loader);
    GLL_LOADPROC(glSecondaryColor3ubv,                          _proc_loader);
    GLL_LOADPROC(glSecondaryColor3ui,                           _proc_loader);
    GLL_LOADPROC(glSecondaryColor3uiv,                          _proc_loader);
    GLL_LOADPROC(glSecondaryColor3us,                           _proc_loader);
    GLL_LOADPROC(glSecondaryColor3usv,                          _proc_loader);
    GLL_LOADPROC(glSecondaryColorPointer,                       _proc_loader);
    GLL_LOADPROC(glWindowPos2d,                                 _proc_loader);
    GLL_LOADPROC(glWindowPos2dv,                                _proc_loader);
    GLL_LOADPROC(glWindowPos2f,                                 _proc_loader);
    GLL_LOADPROC(glWindowPos2fv,                                _proc_loader);
    GLL_LOADPROC(glWindowPos2i,                                 _proc_loader);
    GLL_LOADPROC(glWindowPos2iv,                                _proc_loader);
    GLL_LOADPROC(glWindowPos2s,                                 _proc_loader);
    GLL_LOADPROC(glWindowPos2sv,                                _proc_loader);
    GLL_LOADPROC(glWindowPos3d,                                 _proc_loader);
    GLL_LOADPROC(glWindowPos3dv,                                _proc_loader);
    GLL_LOADPROC(glWindowPos3f,                                 _proc_loader);
    GLL_LOADPROC(glWindowPos3fv,                                _proc_loader);
    GLL_LOADPROC(glWindowPos3i,                                 _proc_loader);
    GLL_LOADPROC(glWindowPos3iv,                                _proc_loader);
    GLL_LOADPROC(glWindowPos3s,                                 _proc_loader);
    GLL_LOADPROC(glWindowPos3sv,                                _proc_loader);
}

static GLL_INLINE void GLL__load_gl_version_150 (GLL_proc_loader _proc_loader, GLL_bool _load_comp)
{
    GLL_LOADPROC(glGenQueries,                                  _proc_loader);
    GLL_LOADPROC(glDeleteQueries,                               _proc_loader);
    GLL_LOADPROC(glIsQuery,                                     _proc_loader);
    GLL_LOADPROC(glBeginQuery,                                  _proc_loader);
    GLL_LOADPROC(glEndQuery,                                    _proc_loader);
    GLL_LOADPROC(glGetQueryiv,                                  _proc_loader);
    GLL_LOADPROC(glGetQueryObjectiv,                            _proc_loader);
    GLL_LOADPROC(glGetQueryObjectuiv,                           _proc_loader);
    GLL_LOADPROC(glBindBuffer,                                  _proc_loader);
    GLL_LOADPROC(glDeleteBuffers,                               _proc_loader);
    GLL_LOADPROC(glGenBuffers,                                  _proc_loader);
    GLL_LOADPROC(glIsBuffer,                                    _proc_loader);
    GLL_LOADPROC(glBufferData,                                  _proc_loader);
    GLL_LOADPROC(glBufferSubData,                               _proc_loader);
    GLL_LOADPROC(glGetBufferSubData,                            _proc_loader);
    GLL_LOADPROC(glMapBuffer,                                   _proc_loader);
    GLL_LOADPROC(glUnmapBuffer,                                 _proc_loader);
    GLL_LOADPROC(glGetBufferParameteriv,                        _proc_loader);
    GLL_LOADPROC(glGetBufferPointerv,                           _proc_loader);
}

static GLL_INLINE void GLL__load_gl_version_200 (GLL_proc_loader _proc_loader, GLL_bool _load_comp)
{
    GLL_LOADPROC(glBlendEquationSeparate,                       _proc_loader);
    GLL_LOADPROC(glDrawBuffers,                                 _proc_loader);
    GLL_LOADPROC(glStencilOpSeparate,                           _proc_loader);
    GLL_LOADPROC(glStencilFuncSeparate,                         _proc_loader);
    GLL_LOADPROC(glStencilMaskSeparate,                         _proc_loader);
    GLL_LOADPROC(glAttachShader,                                _proc_loader);
    GLL_LOADPROC(glBindAttribLocation,                          _proc_loader);
    GLL_LOADPROC(glCompileShader,                               _proc_loader);
    GLL_LOADPROC(glCreateProgram,                               _proc_loader);
    GLL_LOADPROC(glCreateShader,                                _proc_loader);
    GLL_LOADPROC(glDeleteProgram,                               _proc_loader);
    GLL_LOADPROC(glDeleteShader,                                _proc_loader);
    GLL_LOADPROC(glDetachShader,                                _proc_loader);
    GLL_LOADPROC(glDisableVertexAttribArray,                    _proc_loader);
    GLL_LOADPROC(glEnableVertexAttribArray,                     _proc_loader);
    GLL_LOADPROC(glGetActiveAttrib,                             _proc_loader);
    GLL_LOADPROC(glGetActiveUniform,                            _proc_loader);
    GLL_LOADPROC(glGetAttachedShaders,                          _proc_loader);
    GLL_LOADPROC(glGetAttribLocation,                           _proc_loader);
    GLL_LOADPROC(glGetProgramiv,                                _proc_loader);
    GLL_LOADPROC(glGetProgramInfoLog,                           _proc_loader);
    GLL_LOADPROC(glGetShaderiv,                                 _proc_loader);
    GLL_LOADPROC(glGetShaderInfoLog,                            _proc_loader);
    GLL_LOADPROC(glGetShaderSource,                             _proc_loader);
    GLL_LOADPROC(glGetUniformLocation,                          _proc_loader);
    GLL_LOADPROC(glGetUniformfv,                                _proc_loader);
    GLL_LOADPROC(glGetUniformiv,                                _proc_loader);
    GLL_LOADPROC(glGetVertexAttribdv,                           _proc_loader);
    GLL_LOADPROC(glGetVertexAttribfv,                           _proc_loader);
    GLL_LOADPROC(glGetVertexAttribiv,                           _proc_loader);
    GLL_LOADPROC(glGetVertexAttribPointerv,                     _proc_loader);
    GLL_LOADPROC(glIsProgram,                                   _proc_loader);
    GLL_LOADPROC(glIsShader,                                    _proc_loader);
    GLL_LOADPROC(glLinkProgram,                                 _proc_loader);
    GLL_LOADPROC(glShaderSource,                                _proc_loader);
    GLL_LOADPROC(glUseProgram,                                  _proc_loader);
    GLL_LOADPROC(glUniform1f,                                   _proc_loader);
    GLL_LOADPROC(glUniform2f,                                   _proc_loader);
    GLL_LOADPROC(glUniform3f,                                   _proc_loader);
    GLL_LOADPROC(glUniform4f,                                   _proc_loader);
    GLL_LOADPROC(glUniform1i,                                   _proc_loader);
    GLL_LOADPROC(glUniform2i,                                   _proc_loader);
    GLL_LOADPROC(glUniform3i,                                   _proc_loader);
    GLL_LOADPROC(glUniform4i,                                   _proc_loader);
    GLL_LOADPROC(glUniform1fv,                                  _proc_loader);
    GLL_LOADPROC(glUniform2fv,                                  _proc_loader);
    GLL_LOADPROC(glUniform3fv,                                  _proc_loader);
    GLL_LOADPROC(glUniform4fv,                                  _proc_loader);
    GLL_LOADPROC(glUniform1iv,                                  _proc_loader);
    GLL_LOADPROC(glUniform2iv,                                  _proc_loader);
    GLL_LOADPROC(glUniform3iv,                                  _proc_loader);
    GLL_LOADPROC(glUniform4iv,                                  _proc_loader);
    GLL_LOADPROC(glUniformMatrix2fv,                            _proc_loader);
    GLL_LOADPROC(glUniformMatrix3fv,                            _proc_loader);
    GLL_LOADPROC(glUniformMatrix4fv,                            _proc_loader);
    GLL_LOADPROC(glValidateProgram,                             _proc_loader);
    GLL_LOADPROC(glVertexAttrib1d,                              _proc_loader);
    GLL_LOADPROC(glVertexAttrib1dv,                             _proc_loader);
    GLL_LOADPROC(glVertexAttrib1f,                              _proc_loader);
    GLL_LOADPROC(glVertexAttrib1fv,                             _proc_loader);
    GLL_LOADPROC(glVertexAttrib1s,                              _proc_loader);
    GLL_LOADPROC(glVertexAttrib1sv,                             _proc_loader);
    GLL_LOADPROC(glVertexAttrib2d,                              _proc_loader);
    GLL_LOADPROC(glVertexAttrib2dv,                             _proc_loader);
    GLL_LOADPROC(glVertexAttrib2f,                              _proc_loader);
    GLL_LOADPROC(glVertexAttrib2fv,                             _proc_loader);
    GLL_LOADPROC(glVertexAttrib2s,                              _proc_loader);
    GLL_LOADPROC(glVertexAttrib2sv,                             _proc_loader);
    GLL_LOADPROC(glVertexAttrib3d,                              _proc_loader);
    GLL_LOADPROC(glVertexAttrib3dv,                             _proc_loader);
    GLL_LOADPROC(glVertexAttrib3f,                              _proc_loader);
    GLL_LOADPROC(glVertexAttrib3fv,                             _proc_loader);
    GLL_LOADPROC(glVertexAttrib3s,                              _proc_loader);
    GLL_LOADPROC(glVertexAttrib3sv,                             _proc_loader);
    GLL_LOADPROC(glVertexAttrib4Nbv,                            _proc_loader);
    GLL_LOADPROC(glVertexAttrib4Niv,                            _proc_loader);
    GLL_LOADPROC(glVertexAttrib4Nsv,                            _proc_loader);
    GLL_LOADPROC(glVertexAttrib4Nub,                            _proc_loader);
    GLL_LOADPROC(glVertexAttrib4Nubv,                           _proc_loader);
    GLL_LOADPROC(glVertexAttrib4Nuiv,                           _proc_loader);
    GLL_LOADPROC(glVertexAttrib4Nusv,                           _proc_loader);
    GLL_LOADPROC(glVertexAttrib4bv,                             _proc_loader);
    GLL_LOADPROC(glVertexAttrib4d,                              _proc_loader);
    GLL_LOADPROC(glVertexAttrib4dv,                             _proc_loader);
    GLL_LOADPROC(glVertexAttrib4f,                              _proc_loader);
    GLL_LOADPROC(glVertexAttrib4fv,                             _proc_loader);
    GLL_LOADPROC(glVertexAttrib4iv,                             _proc_loader);
    GLL_LOADPROC(glVertexAttrib4s,                              _proc_loader);
    GLL_LOADPROC(glVertexAttrib4sv,                             _proc_loader);
    GLL_LOADPROC(glVertexAttrib4ubv,                            _proc_loader);
    GLL_LOADPROC(glVertexAttrib4uiv,                            _proc_loader);
    GLL_LOADPROC(glVertexAttrib4usv,                            _proc_loader);
    GLL_LOADPROC(glVertexAttribPointer,                         _proc_loader);
}

static GLL_INLINE void GLL__load_gl_version_210 (GLL_proc_loader _proc_loader, GLL_bool _load_comp)
{
    GLL_LOADPROC(glUniformMatrix2x3fv,                          _proc_loader);
    GLL_LOADPROC(glUniformMatrix3x2fv,                          _proc_loader);
    GLL_LOADPROC(glUniformMatrix2x4fv,                          _proc_loader);
    GLL_LOADPROC(glUniformMatrix4x2fv,                          _proc_loader);
    GLL_LOADPROC(glUniformMatrix3x4fv,                          _proc_loader);
    GLL_LOADPROC(glUniformMatrix4x3fv,                          _proc_loader);
}

static GLL_INLINE void GLL__load_gl_version_300 (GLL_proc_loader _proc_loader, GLL_bool _load_comp)
{
    GLL_LOADPROC(glColorMaski,                                  _proc_loader);
    GLL_LOADPROC(glGetBooleani_v,                               _proc_loader);
    GLL_LOADPROC(glGetIntegeri_v,                               _proc_loader);
    GLL_LOADPROC(glEnablei,                                     _proc_loader);
    GLL_LOADPROC(glDisablei,                                    _proc_loader);
    GLL_LOADPROC(glIsEnabledi,                                  _proc_loader);
    GLL_LOADPROC(glBeginTransformFeedback,                      _proc_loader);
    GLL_LOADPROC(glEndTransformFeedback,                        _proc_loader);
    GLL_LOADPROC(glBindBufferRange,                             _proc_loader);
    GLL_LOADPROC(glBindBufferBase,                              _proc_loader);
    GLL_LOADPROC(glTransformFeedbackVaryings,                   _proc_loader);
    GLL_LOADPROC(glGetTransformFeedbackVarying,                 _proc_loader);
    GLL_LOADPROC(glClampColor,                                  _proc_loader);
    GLL_LOADPROC(glBeginConditionalRender,                      _proc_loader);
    GLL_LOADPROC(glEndConditionalRender,                        _proc_loader);
    GLL_LOADPROC(glVertexAttribIPointer,                        _proc_loader);
    GLL_LOADPROC(glGetVertexAttribIiv,                          _proc_loader);
    GLL_LOADPROC(glGetVertexAttribIuiv,                         _proc_loader);
    GLL_LOADPROC(glVertexAttribI1i,                             _proc_loader);
    GLL_LOADPROC(glVertexAttribI2i,                             _proc_loader);
    GLL_LOADPROC(glVertexAttribI3i,                             _proc_loader);
    GLL_LOADPROC(glVertexAttribI4i,                             _proc_loader);
    GLL_LOADPROC(glVertexAttribI1ui,                            _proc_loader);
    GLL_LOADPROC(glVertexAttribI2ui,                            _proc_loader);
    GLL_LOADPROC(glVertexAttribI3ui,                            _proc_loader);
    GLL_LOADPROC(glVertexAttribI4ui,                            _proc_loader);
    GLL_LOADPROC(glVertexAttribI1iv,                            _proc_loader);
    GLL_LOADPROC(glVertexAttribI2iv,                            _proc_loader);
    GLL_LOADPROC(glVertexAttribI3iv,                            _proc_loader);
    GLL_LOADPROC(glVertexAttribI4iv,                            _proc_loader);
    GLL_LOADPROC(glVertexAttribI1uiv,                           _proc_loader);
    GLL_LOADPROC(glVertexAttribI2uiv,                           _proc_loader);
    GLL_LOADPROC(glVertexAttribI3uiv,                           _proc_loader);
    GLL_LOADPROC(glVertexAttribI4uiv,                           _proc_loader);
    GLL_LOADPROC(glVertexAttribI4bv,                            _proc_loader);
    GLL_LOADPROC(glVertexAttribI4sv,                            _proc_loader);
    GLL_LOADPROC(glVertexAttribI4ubv,                           _proc_loader);
    GLL_LOADPROC(glVertexAttribI4usv,                           _proc_loader);
    GLL_LOADPROC(glGetUniformuiv,                               _proc_loader);
    GLL_LOADPROC(glBindFragDataLocation,                        _proc_loader);
    GLL_LOADPROC(glGetFragDataLocation,                         _proc_loader);
    GLL_LOADPROC(glUniform1ui,                                  _proc_loader);
    GLL_LOADPROC(glUniform2ui,                                  _proc_loader);
    GLL_LOADPROC(glUniform3ui,                                  _proc_loader);
    GLL_LOADPROC(glUniform4ui,                                  _proc_loader);
    GLL_LOADPROC(glUniform1uiv,                                 _proc_loader);
    GLL_LOADPROC(glUniform2uiv,                                 _proc_loader);
    GLL_LOADPROC(glUniform3uiv,                                 _proc_loader);
    GLL_LOADPROC(glUniform4uiv,                                 _proc_loader);
    GLL_LOADPROC(glTexParameterIiv,                             _proc_loader);
    GLL_LOADPROC(glTexParameterIuiv,                            _proc_loader);
    GLL_LOADPROC(glGetTexParameterIiv,                          _proc_loader);
    GLL_LOADPROC(glGetTexParameterIuiv,                         _proc_loader);
    GLL_LOADPROC(glClearBufferiv,                               _proc_loader);
    GLL_LOADPROC(glClearBufferuiv,                              _proc_loader);
    GLL_LOADPROC(glClearBufferfv,                               _proc_loader);
    GLL_LOADPROC(glClearBufferfi,                               _proc_loader);
    GLL_LOADPROC(glGetStringi,                                  _proc_loader);
    GLL_LOADPROC(glIsRenderbuffer,                              _proc_loader);
    GLL_LOADPROC(glBindRenderbuffer,                            _proc_loader);
    GLL_LOADPROC(glDeleteRenderbuffers,                         _proc_loader);
    GLL_LOADPROC(glGenRenderbuffers,                            _proc_loader);
    GLL_LOADPROC(glRenderbufferStorage,                         _proc_loader);
    GLL_LOADPROC(glGetRenderbufferParameteriv,                  _proc_loader);
    GLL_LOADPROC(glIsFramebuffer,                               _proc_loader);
    GLL_LOADPROC(glBindFramebuffer,                             _proc_loader);
    GLL_LOADPROC(glDeleteFramebuffers,                          _proc_loader);
    GLL_LOADPROC(glGenFramebuffers,                             _proc_loader);
    GLL_LOADPROC(glCheckFramebufferStatus,                      _proc_loader);
    GLL_LOADPROC(glFramebufferTexture1D,                        _proc_loader);
    GLL_LOADPROC(glFramebufferTexture2D,                        _proc_loader);
    GLL_LOADPROC(glFramebufferTexture3D,                        _proc_loader);
    GLL_LOADPROC(glFramebufferRenderbuffer,                     _proc_loader);
    GLL_LOADPROC(glGetFramebufferAttachmentParameteriv,         _proc_loader);
    GLL_LOADPROC(glGenerateMipmap,                              _proc_loader);
    GLL_LOADPROC(glBlitFramebuffer,                             _proc_loader);
    GLL_LOADPROC(glRenderbufferStorageMultisample,              _proc_loader);
    GLL_LOADPROC(glFramebufferTextureLayer,                     _proc_loader);
    GLL_LOADPROC(glMapBufferRange,                              _proc_loader);
    GLL_LOADPROC(glFlushMappedBufferRange,                      _proc_loader);
    GLL_LOADPROC(glBindVertexArray,                             _proc_loader);
    GLL_LOADPROC(glDeleteVertexArrays,                          _proc_loader);
    GLL_LOADPROC(glGenVertexArrays,                             _proc_loader);
    GLL_LOADPROC(glIsVertexArray,                               _proc_loader);
}

static GLL_INLINE void GLL__load_gl_version_310 (GLL_proc_loader _proc_loader, GLL_bool _load_comp)
{
    GLL_LOADPROC(glDrawArraysInstanced,                         _proc_loader);
    GLL_LOADPROC(glDrawElementsInstanced,                       _proc_loader);
    GLL_LOADPROC(glTexBuffer,                                   _proc_loader);
    GLL_LOADPROC(glPrimitiveRestartIndex,                       _proc_loader);
    GLL_LOADPROC(glCopyBufferSubData,                           _proc_loader);
    GLL_LOADPROC(glGetUniformIndices,                           _proc_loader);
    GLL_LOADPROC(glGetActiveUniformsiv,                         _proc_loader);
    GLL_LOADPROC(glGetActiveUniformName,                        _proc_loader);
    GLL_LOADPROC(glGetUniformBlockIndex,                        _proc_loader);
    GLL_LOADPROC(glGetActiveUniformBlockiv,                     _proc_loader);
    GLL_LOADPROC(glGetActiveUniformBlockName,                   _proc_loader);
    GLL_LOADPROC(glUniformBlockBinding,                         _proc_loader);
}

static GLL_INLINE void GLL__load_gl_version_320 (GLL_proc_loader _proc_loader, GLL_bool _load_comp)
{
    GLL_LOADPROC(glDrawElementsBaseVertex,                      _proc_loader);
    GLL_LOADPROC(glDrawRangeElementsBaseVertex,                 _proc_loader);
    GLL_LOADPROC(glDrawElementsInstancedBaseVertex,             _proc_loader);
    GLL_LOADPROC(glMultiDrawElementsBaseVertex,                 _proc_loader);
    GLL_LOADPROC(glProvokingVertex,                             _proc_loader);
    GLL_LOADPROC(glFenceSync,                                   _proc_loader);
    GLL_LOADPROC(glIsSync,                                      _proc_loader);
    GLL_LOADPROC(glDeleteSync,                                  _proc_loader);
    GLL_LOADPROC(glClientWaitSync,                              _proc_loader);
    GLL_LOADPROC(glWaitSync,                                    _proc_loader);
    GLL_LOADPROC(glGetInteger64v,                               _proc_loader);
    GLL_LOADPROC(glGetSynciv,                                   _proc_loader);
    GLL_LOADPROC(glGetInteger64i_v,                             _proc_loader);
    GLL_LOADPROC(glGetBufferParameteri64v,                      _proc_loader);
    GLL_LOADPROC(glFramebufferTexture,                          _proc_loader);
    GLL_LOADPROC(glTexImage2DMultisample,                       _proc_loader);
    GLL_LOADPROC(glTexImage3DMultisample,                       _proc_loader);
    GLL_LOADPROC(glGetMultisamplefv,                            _proc_loader);
    GLL_LOADPROC(glSampleMaski,                                 _proc_loader);
}

static GLL_INLINE void GLL__load_gl_version_330 (GLL_proc_loader _proc_loader, GLL_bool _load_comp)
{
    GLL_LOADPROC(glBindFragDataLocationIndexed,                 _proc_loader);
    GLL_LOADPROC(glGetFragDataIndex,                            _proc_loader);
    GLL_LOADPROC(glGenSamplers,                                 _proc_loader);
    GLL_LOADPROC(glDeleteSamplers,                              _proc_loader);
    GLL_LOADPROC(glIsSampler,                                   _proc_loader);
    GLL_LOADPROC(glBindSampler,                                 _proc_loader);
    GLL_LOADPROC(glSamplerParameteri,                           _proc_loader);
    GLL_LOADPROC(glSamplerParameteriv,                          _proc_loader);
    GLL_LOADPROC(glSamplerParameterf,                           _proc_loader);
    GLL_LOADPROC(glSamplerParameterfv,                          _proc_loader);
    GLL_LOADPROC(glSamplerParameterIiv,                         _proc_loader);
    GLL_LOADPROC(glSamplerParameterIuiv,                        _proc_loader);
    GLL_LOADPROC(glGetSamplerParameteriv,                       _proc_loader);
    GLL_LOADPROC(glGetSamplerParameterIiv,                      _proc_loader);
    GLL_LOADPROC(glGetSamplerParameterfv,                       _proc_loader);
    GLL_LOADPROC(glGetSamplerParameterIuiv,                     _proc_loader);
    GLL_LOADPROC(glQueryCounter,                                _proc_loader);
    GLL_LOADPROC(glGetQueryObjecti64v,                          _proc_loader);
    GLL_LOADPROC(glGetQueryObjectui64v,                         _proc_loader);
    GLL_LOADPROC(glVertexAttribDivisor,                         _proc_loader);
    GLL_LOADPROC(glVertexAttribP1ui,                            _proc_loader);
    GLL_LOADPROC(glVertexAttribP1uiv,                           _proc_loader);
    GLL_LOADPROC(glVertexAttribP2ui,                            _proc_loader);
    GLL_LOADPROC(glVertexAttribP2uiv,                           _proc_loader);
    GLL_LOADPROC(glVertexAttribP3ui,                            _proc_loader);
    GLL_LOADPROC(glVertexAttribP3uiv,                           _proc_loader);
    GLL_LOADPROC(glVertexAttribP4ui,                            _proc_loader);
    GLL_LOADPROC(glVertexAttribP4uiv,                           _proc_loader);

    if (!_load_comp) { return; }

    GLL_LOADPROC(glVertexP2ui,                                  _proc_loader);
    GLL_LOADPROC(glVertexP2uiv,                                 _proc_loader);
    GLL_LOADPROC(glVertexP3ui,                                  _proc_loader);
    GLL_LOADPROC(glVertexP3uiv,                                 _proc_loader);
    GLL_LOADPROC(glVertexP4ui,                                  _proc_loader);
    GLL_LOADPROC(glVertexP4uiv,                                 _proc_loader);
    GLL_LOADPROC(glTexCoordP1ui,                                _proc_loader);
    GLL_LOADPROC(glTexCoordP1uiv,                               _proc_loader);
    GLL_LOADPROC(glTexCoordP2ui,                                _proc_loader);
    GLL_LOADPROC(glTexCoordP2uiv,                               _proc_loader);
    GLL_LOADPROC(glTexCoordP3ui,                                _proc_loader);
    GLL_LOADPROC(glTexCoordP3uiv,                               _proc_loader);
    GLL_LOADPROC(glTexCoordP4ui,                                _proc_loader);
    GLL_LOADPROC(glTexCoordP4uiv,                               _proc_loader);
    GLL_LOADPROC(glMultiTexCoordP1ui,                           _proc_loader);
    GLL_LOADPROC(glMultiTexCoordP1uiv,                          _proc_loader);
    GLL_LOADPROC(glMultiTexCoordP2ui,                           _proc_loader);
    GLL_LOADPROC(glMultiTexCoordP2uiv,                          _proc_loader);
    GLL_LOADPROC(glMultiTexCoordP3ui,                           _proc_loader);
    GLL_LOADPROC(glMultiTexCoordP3uiv,                          _proc_loader);
    GLL_LOADPROC(glMultiTexCoordP4ui,                           _proc_loader);
    GLL_LOADPROC(glMultiTexCoordP4uiv,                          _proc_loader);
    GLL_LOADPROC(glNormalP3ui,                                  _proc_loader);
    GLL_LOADPROC(glNormalP3uiv,                                 _proc_loader);
    GLL_LOADPROC(glColorP3ui,                                   _proc_loader);
    GLL_LOADPROC(glColorP3uiv,                                  _proc_loader);
    GLL_LOADPROC(glColorP4ui,                                   _proc_loader);
    GLL_LOADPROC(glColorP4uiv,                                  _proc_loader);
    GLL_LOADPROC(glSecondaryColorP3ui,                          _proc_loader);
    GLL_LOADPROC(glSecondaryColorP3uiv,                         _proc_loader);
}

static GLL_INLINE void GLL__load_gl_version_400 (GLL_proc_loader _proc_loader, GLL_bool _load_comp)
{
    GLL_LOADPROC(glMinSampleShading,                            _proc_loader);
    GLL_LOADPROC(glBlendEquationi,                              _proc_loader);
    GLL_LOADPROC(glBlendEquationSeparatei,                      _proc_loader);
    GLL_LOADPROC(glBlendFunci,                                  _proc_loader);
    GLL_LOADPROC(glBlendFuncSeparatei,                          _proc_loader);
    GLL_LOADPROC(glDrawArraysIndirect,                          _proc_loader);
    GLL_LOADPROC(glDrawElementsIndirect,                        _proc_loader);
    GLL_LOADPROC(glUniform1d,                                   _proc_loader);
    GLL_LOADPROC(glUniform2d,                                   _proc_loader);
    GLL_LOADPROC(glUniform3d,                                   _proc_loader);
    GLL_LOADPROC(glUniform4d,                                   _proc_loader);
    GLL_LOADPROC(glUniform1dv,                                  _proc_loader);
    GLL_LOADPROC(glUniform2dv,                                  _proc_loader);
    GLL_LOADPROC(glUniform3dv,                                  _proc_loader);
    GLL_LOADPROC(glUniform4dv,                                  _proc_loader);
    GLL_LOADPROC(glUniformMatrix2dv,                            _proc_loader);
    GLL_LOADPROC(glUniformMatrix3dv,                            _proc_loader);
    GLL_LOADPROC(glUniformMatrix4dv,                            _proc_loader);
    GLL_LOADPROC(glUniformMatrix2x3dv,                          _proc_loader);
    GLL_LOADPROC(glUniformMatrix2x4dv,                          _proc_loader);
    GLL_LOADPROC(glUniformMatrix3x2dv,                          _proc_loader);
    GLL_LOADPROC(glUniformMatrix3x4dv,                          _proc_loader);
    GLL_LOADPROC(glUniformMatrix4x2dv,                          _proc_loader);
    GLL_LOADPROC(glUniformMatrix4x3dv,                          _proc_loader);
    GLL_LOADPROC(glGetUniformdv,                                _proc_loader);
    GLL_LOADPROC(glGetSubroutineUniformLocation,                _proc_loader);
    GLL_LOADPROC(glGetSubroutineIndex,                          _proc_loader);
    GLL_LOADPROC(glGetActiveSubroutineUniformiv,                _proc_loader);
    GLL_LOADPROC(glGetActiveSubroutineUniformName,              _proc_loader);
    GLL_LOADPROC(glGetActiveSubroutineName,                     _proc_loader);
    GLL_LOADPROC(glUniformSubroutinesuiv,                       _proc_loader);
    GLL_LOADPROC(glGetUniformSubroutineuiv,                     _proc_loader);
    GLL_LOADPROC(glGetProgramStageiv,                           _proc_loader);
    GLL_LOADPROC(glPatchParameteri,                             _proc_loader);
    GLL_LOADPROC(glPatchParameterfv,                            _proc_loader);
    GLL_LOADPROC(glBindTransformFeedback,                       _proc_loader);
    GLL_LOADPROC(glDeleteTransformFeedbacks,                    _proc_loader);
    GLL_LOADPROC(glGenTransformFeedbacks,                       _proc_loader);
    GLL_LOADPROC(glIsTransformFeedback,                         _proc_loader);
    GLL_LOADPROC(glPauseTransformFeedback,                      _proc_loader);
    GLL_LOADPROC(glResumeTransformFeedback,                     _proc_loader);
    GLL_LOADPROC(glDrawTransformFeedback,                       _proc_loader);
    GLL_LOADPROC(glDrawTransformFeedbackStream,                 _proc_loader);
    GLL_LOADPROC(glBeginQueryIndexed,                           _proc_loader);
    GLL_LOADPROC(glEndQueryIndexed,                             _proc_loader);
    GLL_LOADPROC(glGetQueryIndexediv,                           _proc_loader);
}

static GLL_INLINE void GLL__load_gl_version_410 (GLL_proc_loader _proc_loader, GLL_bool _load_comp)
{
    GLL_LOADPROC(glReleaseShaderCompiler,                       _proc_loader);
    GLL_LOADPROC(glShaderBinary,                                _proc_loader);
    GLL_LOADPROC(glGetShaderPrecisionFormat,                    _proc_loader);
    GLL_LOADPROC(glDepthRangef,                                 _proc_loader);
    GLL_LOADPROC(glClearDepthf,                                 _proc_loader);
    GLL_LOADPROC(glGetProgramBinary,                            _proc_loader);
    GLL_LOADPROC(glProgramBinary,                               _proc_loader);
    GLL_LOADPROC(glProgramParameteri,                           _proc_loader);
    GLL_LOADPROC(glUseProgramStages,                            _proc_loader);
    GLL_LOADPROC(glActiveShaderProgram,                         _proc_loader);
    GLL_LOADPROC(glCreateShaderProgramv,                        _proc_loader);
    GLL_LOADPROC(glBindProgramPipeline,                         _proc_loader);
    GLL_LOADPROC(glDeleteProgramPipelines,                      _proc_loader);
    GLL_LOADPROC(glGenProgramPipelines,                         _proc_loader);
    GLL_LOADPROC(glIsProgramPipeline,                           _proc_loader);
    GLL_LOADPROC(glGetProgramPipelineiv,                        _proc_loader);
    GLL_LOADPROC(glProgramUniform1i,                            _proc_loader);
    GLL_LOADPROC(glProgramUniform1iv,                           _proc_loader);
    GLL_LOADPROC(glProgramUniform1f,                            _proc_loader);
    GLL_LOADPROC(glProgramUniform1fv,                           _proc_loader);
    GLL_LOADPROC(glProgramUniform1d,                            _proc_loader);
    GLL_LOADPROC(glProgramUniform1dv,                           _proc_loader);
    GLL_LOADPROC(glProgramUniform1ui,                           _proc_loader);
    GLL_LOADPROC(glProgramUniform1uiv,                          _proc_loader);
    GLL_LOADPROC(glProgramUniform2i,                            _proc_loader);
    GLL_LOADPROC(glProgramUniform2iv,                           _proc_loader);
    GLL_LOADPROC(glProgramUniform2f,                            _proc_loader);
    GLL_LOADPROC(glProgramUniform2fv,                           _proc_loader);
    GLL_LOADPROC(glProgramUniform2d,                            _proc_loader);
    GLL_LOADPROC(glProgramUniform2dv,                           _proc_loader);
    GLL_LOADPROC(glProgramUniform2ui,                           _proc_loader);
    GLL_LOADPROC(glProgramUniform2uiv,                          _proc_loader);
    GLL_LOADPROC(glProgramUniform3i,                            _proc_loader);
    GLL_LOADPROC(glProgramUniform3iv,                           _proc_loader);
    GLL_LOADPROC(glProgramUniform3f,                            _proc_loader);
    GLL_LOADPROC(glProgramUniform3fv,                           _proc_loader);
    GLL_LOADPROC(glProgramUniform3d,                            _proc_loader);
    GLL_LOADPROC(glProgramUniform3dv,                           _proc_loader);
    GLL_LOADPROC(glProgramUniform3ui,                           _proc_loader);
    GLL_LOADPROC(glProgramUniform3uiv,                          _proc_loader);
    GLL_LOADPROC(glProgramUniform4i,                            _proc_loader);
    GLL_LOADPROC(glProgramUniform4iv,                           _proc_loader);
    GLL_LOADPROC(glProgramUniform4f,                            _proc_loader);
    GLL_LOADPROC(glProgramUniform4fv,                           _proc_loader);
    GLL_LOADPROC(glProgramUniform4d,                            _proc_loader);
    GLL_LOADPROC(glProgramUniform4dv,                           _proc_loader);
    GLL_LOADPROC(glProgramUniform4ui,                           _proc_loader);
    GLL_LOADPROC(glProgramUniform4uiv,                          _proc_loader);
    GLL_LOADPROC(glProgramUniformMatrix2fv,                     _proc_loader);
    GLL_LOADPROC(glProgramUniformMatrix3fv,                     _proc_loader);
    GLL_LOADPROC(glProgramUniformMatrix4fv,                     _proc_loader);
    GLL_LOADPROC(glProgramUniformMatrix2dv,                     _proc_loader);
    GLL_LOADPROC(glProgramUniformMatrix3dv,                     _proc_loader);
    GLL_LOADPROC(glProgramUniformMatrix4dv,                     _proc_loader);
    GLL_LOADPROC(glProgramUniformMatrix2x3fv,                   _proc_loader);
    GLL_LOADPROC(glProgramUniformMatrix3x2fv,                   _proc_loader);
    GLL_LOADPROC(glProgramUniformMatrix2x4fv,                   _proc_loader);
    GLL_LOADPROC(glProgramUniformMatrix4x2fv,                   _proc_loader);
    GLL_LOADPROC(glProgramUniformMatrix3x4fv,                   _proc_loader);
    GLL_LOADPROC(glProgramUniformMatrix4x3fv,                   _proc_loader);
    GLL_LOADPROC(glProgramUniformMatrix2x3dv,                   _proc_loader);
    GLL_LOADPROC(glProgramUniformMatrix3x2dv,                   _proc_loader);
    GLL_LOADPROC(glProgramUniformMatrix2x4dv,                   _proc_loader);
    GLL_LOADPROC(glProgramUniformMatrix4x2dv,                   _proc_loader);
    GLL_LOADPROC(glProgramUniformMatrix3x4dv,                   _proc_loader);
    GLL_LOADPROC(glProgramUniformMatrix4x3dv,                   _proc_loader);
    GLL_LOADPROC(glValidateProgramPipeline,                     _proc_loader);
    GLL_LOADPROC(glGetProgramPipelineInfoLog,                   _proc_loader);
    GLL_LOADPROC(glVertexAttribL1d,                             _proc_loader);
    GLL_LOADPROC(glVertexAttribL2d,                             _proc_loader);
    GLL_LOADPROC(glVertexAttribL3d,                             _proc_loader);
    GLL_LOADPROC(glVertexAttribL4d,                             _proc_loader);
    GLL_LOADPROC(glVertexAttribL1dv,                            _proc_loader);
    GLL_LOADPROC(glVertexAttribL2dv,                            _proc_loader);
    GLL_LOADPROC(glVertexAttribL3dv,                            _proc_loader);
    GLL_LOADPROC(glVertexAttribL4dv,                            _proc_loader);
    GLL_LOADPROC(glVertexAttribLPointer,                        _proc_loader);
    GLL_LOADPROC(glGetVertexAttribLdv,                          _proc_loader);
    GLL_LOADPROC(glViewportArrayv,                              _proc_loader);
    GLL_LOADPROC(glViewportIndexedf,                            _proc_loader);
    GLL_LOADPROC(glViewportIndexedfv,                           _proc_loader);
    GLL_LOADPROC(glScissorArrayv,                               _proc_loader);
    GLL_LOADPROC(glScissorIndexed,                              _proc_loader);
    GLL_LOADPROC(glScissorIndexedv,                             _proc_loader);
    GLL_LOADPROC(glDepthRangeArrayv,                            _proc_loader);
    GLL_LOADPROC(glDepthRangeIndexed,                           _proc_loader);
    GLL_LOADPROC(glGetFloati_v,                                 _proc_loader);
    GLL_LOADPROC(glGetDoublei_v,                                _proc_loader);
}

static GLL_INLINE void GLL__load_gl_version_420 (GLL_proc_loader _proc_loader, GLL_bool _load_comp)
{
    GLL_LOADPROC(glDrawArraysInstancedBaseInstance,             _proc_loader);
    GLL_LOADPROC(glDrawElementsInstancedBaseInstance,           _proc_loader);
    GLL_LOADPROC(glDrawElementsInstancedBaseVertexBaseInstance, _proc_loader);
    GLL_LOADPROC(glGetInternalformativ,                         _proc_loader);
    GLL_LOADPROC(glGetActiveAtomicCounterBufferiv,              _proc_loader);
    GLL_LOADPROC(glBindImageTexture,                            _proc_loader);
    GLL_LOADPROC(glMemoryBarrier,                               _proc_loader);
    GLL_LOADPROC(glTexStorage1D,                                _proc_loader);
    GLL_LOADPROC(glTexStorage2D,                                _proc_loader);
    GLL_LOADPROC(glTexStorage3D,                                _proc_loader);
    GLL_LOADPROC(glDrawTransformFeedbackInstanced,              _proc_loader);
    GLL_LOADPROC(glDrawTransformFeedbackStreamInstanced,        _proc_loader);
}

static GLL_INLINE void GLL__load_gl_version_430 (GLL_proc_loader _proc_loader, GLL_bool _load_comp)
{
    GLL_LOADPROC(glClearBufferData,                             _proc_loader);
    GLL_LOADPROC(glClearBufferSubData,                          _proc_loader);
    GLL_LOADPROC(glDispatchCompute,                             _proc_loader);
    GLL_LOADPROC(glDispatchComputeIndirect,                     _proc_loader);
    GLL_LOADPROC(glCopyImageSubData,                            _proc_loader);
    GLL_LOADPROC(glFramebufferParameteri,                       _proc_loader);
    GLL_LOADPROC(glGetFramebufferParameteriv,                   _proc_loader);
    GLL_LOADPROC(glGetInternalformati64v,                       _proc_loader);
    GLL_LOADPROC(glInvalidateTexSubImage,                       _proc_loader);
    GLL_LOADPROC(glInvalidateTexImage,                          _proc_loader);
    GLL_LOADPROC(glInvalidateBufferSubData,                     _proc_loader);
    GLL_LOADPROC(glInvalidateBufferData,                        _proc_loader);
    GLL_LOADPROC(glInvalidateFramebuffer,                       _proc_loader);
    GLL_LOADPROC(glInvalidateSubFramebuffer,                    _proc_loader);
    GLL_LOADPROC(glMultiDrawArraysIndirect,                     _proc_loader);
    GLL_LOADPROC(glMultiDrawElementsIndirect,                   _proc_loader);
    GLL_LOADPROC(glGetProgramInterfaceiv,                       _proc_loader);
    GLL_LOADPROC(glGetProgramResourceIndex,                     _proc_loader);
    GLL_LOADPROC(glGetProgramResourceName,                      _proc_loader);
    GLL_LOADPROC(glGetProgramResourceiv,                        _proc_loader);
    GLL_LOADPROC(glGetProgramResourceLocation,                  _proc_loader);
    GLL_LOADPROC(glGetProgramResourceLocationIndex,             _proc_loader);
    GLL_LOADPROC(glShaderStorageBlockBinding,                   _proc_loader);
    GLL_LOADPROC(glTexBufferRange,                              _proc_loader);
    GLL_LOADPROC(glTexStorage2DMultisample,                     _proc_loader);
    GLL_LOADPROC(glTexStorage3DMultisample,                     _proc_loader);
    GLL_LOADPROC(glTextureView,                                 _proc_loader);
    GLL_LOADPROC(glBindVertexBuffer,                            _proc_loader);
    GLL_LOADPROC(glVertexAttribFormat,                          _proc_loader);
    GLL_LOADPROC(glVertexAttribIFormat,                         _proc_loader);
    GLL_LOADPROC(glVertexAttribLFormat,                         _proc_loader);
    GLL_LOADPROC(glVertexAttribBinding,                         _proc_loader);
    GLL_LOADPROC(glVertexBindingDivisor,                        _proc_loader);
    GLL_LOADPROC(glDebugMessageControl,                         _proc_loader);
    GLL_LOADPROC(glDebugMessageInsert,                          _proc_loader);
    GLL_LOADPROC(glDebugMessageCallback,                        _proc_loader);
    GLL_LOADPROC(glGetDebugMessageLog,                          _proc_loader);
    GLL_LOADPROC(glPushDebugGroup,                              _proc_loader);
    GLL_LOADPROC(glPopDebugGroup,                               _proc_loader);
    GLL_LOADPROC(glObjectLabel,                                 _proc_loader);
    GLL_LOADPROC(glGetObjectLabel,                              _proc_loader);
    GLL_LOADPROC(glObjectPtrLabel,                              _proc_loader);
    GLL_LOADPROC(glGetObjectPtrLabel,                           _proc_loader);
}

static GLL_INLINE void GLL__load_gl_version_440 (GLL_proc_loader _proc_loader, GLL_bool _load_comp)
{
    GLL_LOADPROC(glBufferStorage,                               _proc_loader);
    GLL_LOADPROC(glClearTexImage,                               _proc_loader);
    GLL_LOADPROC(glClearTexSubImage,                            _proc_loader);
    GLL_LOADPROC(glBindBuffersBase,                             _proc_loader);
    GLL_LOADPROC(glBindBuffersRange,                            _proc_loader);
    GLL_LOADPROC(glBindTextures,                                _proc_loader);
    GLL_LOADPROC(glBindSamplers,                                _proc_loader);
    GLL_LOADPROC(glBindImageTextures,                           _proc_loader);
    GLL_LOADPROC(glBindVertexBuffers,                           _proc_loader);
}

static GLL_INLINE void GLL__load_gl_version_450 (GLL_proc_loader _proc_loader, GLL_bool _load_comp)
{
    GLL_LOADPROC(glClipControl,                                 _proc_loader);
    GLL_LOADPROC(glCreateTransformFeedbacks,                    _proc_loader);
    GLL_LOADPROC(glTransformFeedbackBufferBase,                 _proc_loader);
    GLL_LOADPROC(glTransformFeedbackBufferRange,                _proc_loader);
    GLL_LOADPROC(glGetTransformFeedbackiv,                      _proc_loader);
    GLL_LOADPROC(glGetTransformFeedbacki_v,                     _proc_loader);
    GLL_LOADPROC(glGetTransformFeedbacki64_v,                   _proc_loader);
    GLL_LOADPROC(glCreateBuffers,                               _proc_loader);
    GLL_LOADPROC(glNamedBufferStorage,                          _proc_loader);
    GLL_LOADPROC(glNamedBufferData,                             _proc_loader);
    GLL_LOADPROC(glNamedBufferSubData,                          _proc_loader);
    GLL_LOADPROC(glCopyNamedBufferSubData,                      _proc_loader);
    GLL_LOADPROC(glClearNamedBufferData,                        _proc_loader);
    GLL_LOADPROC(glClearNamedBufferSubData,                     _proc_loader);
    GLL_LOADPROC(glMapNamedBuffer,                              _proc_loader);
    GLL_LOADPROC(glMapNamedBufferRange,                         _proc_loader);
    GLL_LOADPROC(glUnmapNamedBuffer,                            _proc_loader);
    GLL_LOADPROC(glFlushMappedNamedBufferRange,                 _proc_loader);
    GLL_LOADPROC(glGetNamedBufferParameteriv,                   _proc_loader);
    GLL_LOADPROC(glGetNamedBufferParameteri64v,                 _proc_loader);
    GLL_LOADPROC(glGetNamedBufferPointerv,                      _proc_loader);
    GLL_LOADPROC(glGetNamedBufferSubData,                       _proc_loader);
    GLL_LOADPROC(glCreateFramebuffers,                          _proc_loader);
    GLL_LOADPROC(glNamedFramebufferRenderbuffer,                _proc_loader);
    GLL_LOADPROC(glNamedFramebufferParameteri,                  _proc_loader);
    GLL_LOADPROC(glNamedFramebufferTexture,                     _proc_loader);
    GLL_LOADPROC(glNamedFramebufferTextureLayer,                _proc_loader);
    GLL_LOADPROC(glNamedFramebufferDrawBuffer,                  _proc_loader);
    GLL_LOADPROC(glNamedFramebufferDrawBuffers,                 _proc_loader);
    GLL_LOADPROC(glNamedFramebufferReadBuffer,                  _proc_loader);
    GLL_LOADPROC(glInvalidateNamedFramebufferData,              _proc_loader);
    GLL_LOADPROC(glInvalidateNamedFramebufferSubData,           _proc_loader);
    GLL_LOADPROC(glClearNamedFramebufferiv,                     _proc_loader);
    GLL_LOADPROC(glClearNamedFramebufferuiv,                    _proc_loader);
    GLL_LOADPROC(glClearNamedFramebufferfv,                     _proc_loader);
    GLL_LOADPROC(glClearNamedFramebufferfi,                     _proc_loader);
    GLL_LOADPROC(glBlitNamedFramebuffer,                        _proc_loader);
    GLL_LOADPROC(glCheckNamedFramebufferStatus,                 _proc_loader);
    GLL_LOADPROC(glGetNamedFramebufferParameteriv,              _proc_loader);
    GLL_LOADPROC(glGetNamedFramebufferAttachmentParameteriv,    _proc_loader);
    GLL_LOADPROC(glCreateRenderbuffers,                         _proc_loader);
    GLL_LOADPROC(glNamedRenderbufferStorage,                    _proc_loader);
    GLL_LOADPROC(glNamedRenderbufferStorageMultisample,         _proc_loader);
    GLL_LOADPROC(glGetNamedRenderbufferParameteriv,             _proc_loader);
    GLL_LOADPROC(glCreateTextures,                              _proc_loader);
    GLL_LOADPROC(glTextureBuffer,                               _proc_loader);
    GLL_LOADPROC(glTextureBufferRange,                          _proc_loader);
    GLL_LOADPROC(glTextureStorage1D,                            _proc_loader);
    GLL_LOADPROC(glTextureStorage2D,                            _proc_loader);
    GLL_LOADPROC(glTextureStorage3D,                            _proc_loader);
    GLL_LOADPROC(glTextureStorage2DMultisample,                 _proc_loader);
    GLL_LOADPROC(glTextureStorage3DMultisample,                 _proc_loader);
    GLL_LOADPROC(glTextureSubImage1D,                           _proc_loader);
    GLL_LOADPROC(glTextureSubImage2D,                           _proc_loader);
    GLL_LOADPROC(glTextureSubImage3D,                           _proc_loader);
    GLL_LOADPROC(glCompressedTextureSubImage1D,                 _proc_loader);
    GLL_LOADPROC(glCompressedTextureSubImage2D,                 _proc_loader);
    GLL_LOADPROC(glCompressedTextureSubImage3D,                 _proc_loader);
    GLL_LOADPROC(glCopyTextureSubImage1D,                       _proc_loader);
    GLL_LOADPROC(glCopyTextureSubImage2D,                       _proc_loader);
    GLL_LOADPROC(glCopyTextureSubImage3D,                       _proc_loader);
    GLL_LOADPROC(glTextureParameterf,                           _proc_loader);
    GLL_LOADPROC(glTextureParameterfv,                          _proc_loader);
    GLL_LOADPROC(glTextureParameteri,                           _proc_loader);
    GLL_LOADPROC(glTextureParameterIiv,                         _proc_loader);
    GLL_LOADPROC(glTextureParameterIuiv,                        _proc_loader);
    GLL_LOADPROC(glTextureParameteriv,                          _proc_loader);
    GLL_LOADPROC(glGenerateTextureMipmap,                       _proc_loader);
    GLL_LOADPROC(glBindTextureUnit,                             _proc_loader);
    GLL_LOADPROC(glGetTextureImage,                             _proc_loader);
    GLL_LOADPROC(glGetCompressedTextureImage,                   _proc_loader);
    GLL_LOADPROC(glGetTextureLevelParameterfv,                  _proc_loader);
    GLL_LOADPROC(glGetTextureLevelParameteriv,                  _proc_loader);
    GLL_LOADPROC(glGetTextureParameterfv,                       _proc_loader);
    GLL_LOADPROC(glGetTextureParameterIiv,                      _proc_loader);
    GLL_LOADPROC(glGetTextureParameterIuiv,                     _proc_loader);
    GLL_LOADPROC(glGetTextureParameteriv,                       _proc_loader);
    GLL_LOADPROC(glCreateVertexArrays,                          _proc_loader);
    GLL_LOADPROC(glDisableVertexArrayAttrib,                    _proc_loader);
    GLL_LOADPROC(glEnableVertexArrayAttrib,                     _proc_loader);
    GLL_LOADPROC(glVertexArrayElementBuffer,                    _proc_loader);
    GLL_LOADPROC(glVertexArrayVertexBuffer,                     _proc_loader);
    GLL_LOADPROC(glVertexArrayVertexBuffers,                    _proc_loader);
    GLL_LOADPROC(glVertexArrayAttribBinding,                    _proc_loader);
    GLL_LOADPROC(glVertexArrayAttribFormat,                     _proc_loader);
    GLL_LOADPROC(glVertexArrayAttribIFormat,                    _proc_loader);
    GLL_LOADPROC(glVertexArrayAttribLFormat,                    _proc_loader);
    GLL_LOADPROC(glVertexArrayBindingDivisor,                   _proc_loader);
    GLL_LOADPROC(glGetVertexArrayiv,                            _proc_loader);
    GLL_LOADPROC(glGetVertexArrayIndexediv,                     _proc_loader);
    GLL_LOADPROC(glGetVertexArrayIndexed64iv,                   _proc_loader);
    GLL_LOADPROC(glCreateSamplers,                              _proc_loader);
    GLL_LOADPROC(glCreateProgramPipelines,                      _proc_loader);
    GLL_LOADPROC(glCreateQueries,                               _proc_loader);
    GLL_LOADPROC(glGetQueryBufferObjecti64v,                    _proc_loader);
    GLL_LOADPROC(glGetQueryBufferObjectiv,                      _proc_loader);
    GLL_LOADPROC(glGetQueryBufferObjectui64v,                   _proc_loader);
    GLL_LOADPROC(glGetQueryBufferObjectuiv,                     _proc_loader);
    GLL_LOADPROC(glMemoryBarrierByRegion,                       _proc_loader);
    GLL_LOADPROC(glGetTextureSubImage,                          _proc_loader);
    GLL_LOADPROC(glGetCompressedTextureSubImage,                _proc_loader);
    GLL_LOADPROC(glGetGraphicsResetStatus,                      _proc_loader);
    GLL_LOADPROC(glGetnCompressedTexImage,                      _proc_loader);
    GLL_LOADPROC(glGetnTexImage,                                _proc_loader);
    GLL_LOADPROC(glGetnUniformdv,                               _proc_loader);
    GLL_LOADPROC(glGetnUniformfv,                               _proc_loader);
    GLL_LOADPROC(glGetnUniformiv,                               _proc_loader);
    GLL_LOADPROC(glGetnUniformuiv,                              _proc_loader);
    GLL_LOADPROC(glReadnPixels,                                 _proc_loader);
    GLL_LOADPROC(glTextureBarrier,                              _proc_loader);

    if (!_load_comp) { return; }

    GLL_LOADPROC(glGetnMapdv,                                   _proc_loader);
    GLL_LOADPROC(glGetnMapfv,                                   _proc_loader);
    GLL_LOADPROC(glGetnMapiv,                                   _proc_loader);
    GLL_LOADPROC(glGetnPixelMapfv,                              _proc_loader);
    GLL_LOADPROC(glGetnPixelMapuiv,                             _proc_loader);
    GLL_LOADPROC(glGetnPixelMapusv,                             _proc_loader);
    GLL_LOADPROC(glGetnPolygonStipple,                          _proc_loader);
    GLL_LOADPROC(glGetnColorTable,                              _proc_loader);
    GLL_LOADPROC(glGetnConvolutionFilter,                       _proc_loader);
    GLL_LOADPROC(glGetnSeparableFilter,                         _proc_loader);
    GLL_LOADPROC(glGetnHistogram,                               _proc_loader);
    GLL_LOADPROC(glGetnMinmax,                                  _proc_loader);
}

static GLL_INLINE void GLL__load_gl_version_460 (GLL_proc_loader _proc_loader, GLL_bool _load_comp)
{
    GLL_LOADPROC(glMultiDrawArraysIndirectCount,                _proc_loader);
    GLL_LOADPROC(glMultiDrawElementsIndirectCount,              _proc_loader);
    GLL_LOADPROC(glPolygonOffsetClamp,                          _proc_loader);
    GLL_LOADPROC(glSpecializeShader,                            _proc_loader);
}

/* -------------------------------------------------------------------------- */

#endif /* GLL_IMPLEMENTATION /////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/
/*////////////////////////////////////////////////////////////////////////////*/
/*////////////////////////////////////////////////////////////////////////////*/

/*******************************************************************************
 *
 * REVISION HISTORY:
 *
 * v1.0.0  [31-07-2019]  Initial release.
 *
*******************************************************************************/

/*////////////////////////////////////////////////////////////////////////////*/
/*////////////////////////////////////////////////////////////////////////////*/
/*////////////////////////////////////////////////////////////////////////////*/

/*******************************************************************************
 *
 * THIS SOFTWARE IS AVAILABLE UNDER 2 LICENSES -- CHOOSE WHICHEVER YOU PREFER.
 *
 *******************************************************************************
 *
 * ALTERNATIVE A - MIT License
 *
 * Copyright (c) 2019 Joshua Robertson
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 *******************************************************************************
 *
 * ALTERNATIVE B - Public Domain
 *
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * For more information, please refer to <http://unlicense.org/>
 *
*******************************************************************************/
