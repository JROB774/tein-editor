/*******************************************************************************
 * Utility for loading OpenGL functionality for the desired GL version.
 * Available Under Public Domain or MIT License (See EOF)
 * Authored By Joshua Robertson
 *
*******************************************************************************/

#ifndef GLL_H__ /*////////////////////////////////////////////////////////////*/
#define GLL_H__

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

#define GLL_INITPROC(name_, return_, ...)                \
typedef return_ (APIENTRYP GLL_GL_##name_)(__VA_ARGS__); \
GLAPI GLL_GL_##name_ GLL_##name_;                        \
GLL_GL_##name_ GLL_##name_ = NULL

#define GLL_LOADPROC(name_, proc_loader_)                \
GLL_##name_ = (GLL_GL_##name_)((proc_loader_)(#name_))

/* -------------------------------------------------------------------------- */

#include "GL/KHR/khrplatform.h"
#include "GL/GL.h"

/* -------------------------------------------------------------------------- */

#define GLL_LOAD_CORE_PROFILE 0x01
#define GLL_LOAD_COMP_PROFILE 0x02

typedef int GLL_bool;

#define GLL_FALSE 0
#define GLL_TRUE  1

typedef void* (*GLL_proc_loader)(const char* name_);

GLL_STDDEF GLL_bool GLL_load_gl_procs (int major_, int minor_, int profile_, GLL_proc_loader proc_loader_);
GLL_INLDEF GLL_bool GLL_is_proc_valid (void* proc_);

/* -------------------------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

/* -------------------------------------------------------------------------- */

#endif /* GLL_H__ ////////////////////////////////////////////////////////////*/

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

GLL_STDDEF GLL_bool GLL_load_gl_procs (int major_, int minor_, int profile_, GLL_proc_loader proc_loader_)
{
    GLL_ASSERT(proc_loader_);

    // Preload functions that we use internally for specific processes.
    GLL_LOADPROC(glGetIntegerv, proc_loader_);
    GLL_LOADPROC(glGetString,   proc_loader_);
    GLL_LOADPROC(glGetStringi,  proc_loader_);

    // Determining the OpenGL version uses a different method based on
    // which method is available (we prefer GetInteger over GetString).
    int (*get_gl_version)(void) = NULL;

    if      (GLL_is_proc_valid(glGetIntegerv)) get_gl_version = GLL__get_ver__new;
    else if (GLL_is_proc_valid(glGetString))   get_gl_version = GLL__get_ver__old;
    else                                       return GL_FALSE;

    // Determine if user wants to load core or compatibility procs.
    GLL_bool load_comp = (profile_ == GLL_LOAD_COMP_PROFILE);

    // Only load the OpenGL functions that we have access to. This
    // will either be the desired set of OpenGL functions or less.
    int desired = (major_ * 100) + (minor_ * 10);
    int current = get_gl_version();

    // Ensures we only load what we want, not what we have access to.
    if (desired < current) current = desired;

    if (current >= 100) GLL__load_gl_version_100(proc_loader_, load_comp);
    if (current >= 110) GLL__load_gl_version_110(proc_loader_, load_comp);
    if (current >= 120) GLL__load_gl_version_120(proc_loader_, load_comp);
    if (current >= 130) GLL__load_gl_version_130(proc_loader_, load_comp);
    if (current >= 140) GLL__load_gl_version_140(proc_loader_, load_comp);
    if (current >= 150) GLL__load_gl_version_150(proc_loader_, load_comp);
    if (current >= 200) GLL__load_gl_version_200(proc_loader_, load_comp);
    if (current >= 210) GLL__load_gl_version_210(proc_loader_, load_comp);
    if (current >= 300) GLL__load_gl_version_300(proc_loader_, load_comp);
    if (current >= 310) GLL__load_gl_version_310(proc_loader_, load_comp);
    if (current >= 320) GLL__load_gl_version_320(proc_loader_, load_comp);
    if (current >= 330) GLL__load_gl_version_330(proc_loader_, load_comp);
    if (current >= 400) GLL__load_gl_version_400(proc_loader_, load_comp);
    if (current >= 410) GLL__load_gl_version_410(proc_loader_, load_comp);
    if (current >= 420) GLL__load_gl_version_420(proc_loader_, load_comp);
    if (current >= 430) GLL__load_gl_version_430(proc_loader_, load_comp);
    if (current >= 440) GLL__load_gl_version_440(proc_loader_, load_comp);
    if (current >= 450) GLL__load_gl_version_450(proc_loader_, load_comp);
    if (current >= 460) GLL__load_gl_version_460(proc_loader_, load_comp);

    return GL_TRUE;
}

GLL_INLDEF GLL_bool GLL_is_proc_valid (void* proc_)
{
    // Certain GL proc loaders (e.g. Windows) may return non-null values
    // to represent failure -- depening on the implementation. So it is
    // preferred that this function be used to check if a proc is valid.
    //
    // https://www.khronos.org/opengl/wiki/Load_OpenGL_Functions#Windows

    return !((proc_ == (void*)0x0) || (proc_ == (void*)0x1) ||
             (proc_ == (void*)0x2) || (proc_ == (void*)0x3) ||
             (proc_ == (void*) -1));
}

/* -------------------------------------------------------------------------- */

static GLL_INLINE void GLL__load_gl_version_100 (GLL_proc_loader proc_loader_, GLL_bool load_comp_)
{
    GLL_LOADPROC(glCullFace,                                    proc_loader_);
    GLL_LOADPROC(glFrontFace,                                   proc_loader_);
    GLL_LOADPROC(glHint,                                        proc_loader_);
    GLL_LOADPROC(glLineWidth,                                   proc_loader_);
    GLL_LOADPROC(glPointSize,                                   proc_loader_);
    GLL_LOADPROC(glPolygonMode,                                 proc_loader_);
    GLL_LOADPROC(glScissor,                                     proc_loader_);
    GLL_LOADPROC(glTexParameterf,                               proc_loader_);
    GLL_LOADPROC(glTexParameterfv,                              proc_loader_);
    GLL_LOADPROC(glTexParameteri,                               proc_loader_);
    GLL_LOADPROC(glTexParameteriv,                              proc_loader_);
    GLL_LOADPROC(glTexImage1D,                                  proc_loader_);
    GLL_LOADPROC(glTexImage2D,                                  proc_loader_);
    GLL_LOADPROC(glDrawBuffer,                                  proc_loader_);
    GLL_LOADPROC(glClear,                                       proc_loader_);
    GLL_LOADPROC(glClearColor,                                  proc_loader_);
    GLL_LOADPROC(glClearStencil,                                proc_loader_);
    GLL_LOADPROC(glClearDepth,                                  proc_loader_);
    GLL_LOADPROC(glStencilMask,                                 proc_loader_);
    GLL_LOADPROC(glColorMask,                                   proc_loader_);
    GLL_LOADPROC(glDepthMask,                                   proc_loader_);
    GLL_LOADPROC(glDisable,                                     proc_loader_);
    GLL_LOADPROC(glEnable,                                      proc_loader_);
    GLL_LOADPROC(glFinish,                                      proc_loader_);
    GLL_LOADPROC(glFlush,                                       proc_loader_);
    GLL_LOADPROC(glBlendFunc,                                   proc_loader_);
    GLL_LOADPROC(glLogicOp,                                     proc_loader_);
    GLL_LOADPROC(glStencilFunc,                                 proc_loader_);
    GLL_LOADPROC(glStencilOp,                                   proc_loader_);
    GLL_LOADPROC(glDepthFunc,                                   proc_loader_);
    GLL_LOADPROC(glPixelStoref,                                 proc_loader_);
    GLL_LOADPROC(glPixelStorei,                                 proc_loader_);
    GLL_LOADPROC(glReadBuffer,                                  proc_loader_);
    GLL_LOADPROC(glReadPixels,                                  proc_loader_);
    GLL_LOADPROC(glGetBooleanv,                                 proc_loader_);
    GLL_LOADPROC(glGetDoublev,                                  proc_loader_);
    GLL_LOADPROC(glGetError,                                    proc_loader_);
    GLL_LOADPROC(glGetFloatv,                                   proc_loader_);
    GLL_LOADPROC(glGetIntegerv,                                 proc_loader_);
    GLL_LOADPROC(glGetString,                                   proc_loader_);
    GLL_LOADPROC(glGetTexImage,                                 proc_loader_);
    GLL_LOADPROC(glGetTexParameterfv,                           proc_loader_);
    GLL_LOADPROC(glGetTexParameteriv,                           proc_loader_);
    GLL_LOADPROC(glGetTexLevelParameterfv,                      proc_loader_);
    GLL_LOADPROC(glGetTexLevelParameteriv,                      proc_loader_);
    GLL_LOADPROC(glIsEnabled,                                   proc_loader_);
    GLL_LOADPROC(glDepthRange,                                  proc_loader_);
    GLL_LOADPROC(glViewport,                                    proc_loader_);
    GLL_LOADPROC(glNewList,                                     proc_loader_);

    if (!load_comp_) return;

    GLL_LOADPROC(glEndList,                                     proc_loader_);
    GLL_LOADPROC(glCallList,                                    proc_loader_);
    GLL_LOADPROC(glCallLists,                                   proc_loader_);
    GLL_LOADPROC(glDeleteLists,                                 proc_loader_);
    GLL_LOADPROC(glGenLists,                                    proc_loader_);
    GLL_LOADPROC(glListBase,                                    proc_loader_);
    GLL_LOADPROC(glBegin,                                       proc_loader_);
    GLL_LOADPROC(glBitmap,                                      proc_loader_);
    GLL_LOADPROC(glColor3b,                                     proc_loader_);
    GLL_LOADPROC(glColor3bv,                                    proc_loader_);
    GLL_LOADPROC(glColor3d,                                     proc_loader_);
    GLL_LOADPROC(glColor3dv,                                    proc_loader_);
    GLL_LOADPROC(glColor3f,                                     proc_loader_);
    GLL_LOADPROC(glColor3fv,                                    proc_loader_);
    GLL_LOADPROC(glColor3i,                                     proc_loader_);
    GLL_LOADPROC(glColor3iv,                                    proc_loader_);
    GLL_LOADPROC(glColor3s,                                     proc_loader_);
    GLL_LOADPROC(glColor3sv,                                    proc_loader_);
    GLL_LOADPROC(glColor3ub,                                    proc_loader_);
    GLL_LOADPROC(glColor3ubv,                                   proc_loader_);
    GLL_LOADPROC(glColor3ui,                                    proc_loader_);
    GLL_LOADPROC(glColor3uiv,                                   proc_loader_);
    GLL_LOADPROC(glColor3us,                                    proc_loader_);
    GLL_LOADPROC(glColor3usv,                                   proc_loader_);
    GLL_LOADPROC(glColor4b,                                     proc_loader_);
    GLL_LOADPROC(glColor4bv,                                    proc_loader_);
    GLL_LOADPROC(glColor4d,                                     proc_loader_);
    GLL_LOADPROC(glColor4dv,                                    proc_loader_);
    GLL_LOADPROC(glColor4f,                                     proc_loader_);
    GLL_LOADPROC(glColor4fv,                                    proc_loader_);
    GLL_LOADPROC(glColor4i,                                     proc_loader_);
    GLL_LOADPROC(glColor4iv,                                    proc_loader_);
    GLL_LOADPROC(glColor4s,                                     proc_loader_);
    GLL_LOADPROC(glColor4sv,                                    proc_loader_);
    GLL_LOADPROC(glColor4ub,                                    proc_loader_);
    GLL_LOADPROC(glColor4ubv,                                   proc_loader_);
    GLL_LOADPROC(glColor4ui,                                    proc_loader_);
    GLL_LOADPROC(glColor4uiv,                                   proc_loader_);
    GLL_LOADPROC(glColor4us,                                    proc_loader_);
    GLL_LOADPROC(glColor4usv,                                   proc_loader_);
    GLL_LOADPROC(glEdgeFlag,                                    proc_loader_);
    GLL_LOADPROC(glEdgeFlagv,                                   proc_loader_);
    GLL_LOADPROC(glEnd,                                         proc_loader_);
    GLL_LOADPROC(glIndexd,                                      proc_loader_);
    GLL_LOADPROC(glIndexdv,                                     proc_loader_);
    GLL_LOADPROC(glIndexf,                                      proc_loader_);
    GLL_LOADPROC(glIndexfv,                                     proc_loader_);
    GLL_LOADPROC(glIndexi,                                      proc_loader_);
    GLL_LOADPROC(glIndexiv,                                     proc_loader_);
    GLL_LOADPROC(glIndexs,                                      proc_loader_);
    GLL_LOADPROC(glIndexsv,                                     proc_loader_);
    GLL_LOADPROC(glNormal3b,                                    proc_loader_);
    GLL_LOADPROC(glNormal3bv,                                   proc_loader_);
    GLL_LOADPROC(glNormal3d,                                    proc_loader_);
    GLL_LOADPROC(glNormal3dv,                                   proc_loader_);
    GLL_LOADPROC(glNormal3f,                                    proc_loader_);
    GLL_LOADPROC(glNormal3fv,                                   proc_loader_);
    GLL_LOADPROC(glNormal3i,                                    proc_loader_);
    GLL_LOADPROC(glNormal3uv,                                   proc_loader_);
    GLL_LOADPROC(glNormal3s,                                    proc_loader_);
    GLL_LOADPROC(glNormal3sv,                                   proc_loader_);
    GLL_LOADPROC(glRasterPos2d,                                 proc_loader_);
    GLL_LOADPROC(glRasterPos2dv,                                proc_loader_);
    GLL_LOADPROC(glRasterPos2f,                                 proc_loader_);
    GLL_LOADPROC(glRasterPos2fv,                                proc_loader_);
    GLL_LOADPROC(glRasterPos2i,                                 proc_loader_);
    GLL_LOADPROC(glRasterPos2iv,                                proc_loader_);
    GLL_LOADPROC(glRasterPos2s,                                 proc_loader_);
    GLL_LOADPROC(glRasterPos2sv,                                proc_loader_);
    GLL_LOADPROC(glRasterPos3d,                                 proc_loader_);
    GLL_LOADPROC(glRasterPos3dv,                                proc_loader_);
    GLL_LOADPROC(glRasterPos3f,                                 proc_loader_);
    GLL_LOADPROC(glRasterPos3fv,                                proc_loader_);
    GLL_LOADPROC(glRasterPos3i,                                 proc_loader_);
    GLL_LOADPROC(glRasterPos3iv,                                proc_loader_);
    GLL_LOADPROC(glRasterPos3s,                                 proc_loader_);
    GLL_LOADPROC(glRasterPos3sv,                                proc_loader_);
    GLL_LOADPROC(glRasterPos4d,                                 proc_loader_);
    GLL_LOADPROC(glRasterPos4dv,                                proc_loader_);
    GLL_LOADPROC(glRasterPos4f,                                 proc_loader_);
    GLL_LOADPROC(glRasterPos4fv,                                proc_loader_);
    GLL_LOADPROC(glRasterPos4i,                                 proc_loader_);
    GLL_LOADPROC(glRasterPos4iv,                                proc_loader_);
    GLL_LOADPROC(glRasterPos4s,                                 proc_loader_);
    GLL_LOADPROC(glRasterPos4sv,                                proc_loader_);
    GLL_LOADPROC(glRectd,                                       proc_loader_);
    GLL_LOADPROC(glRectdv,                                      proc_loader_);
    GLL_LOADPROC(glRectf,                                       proc_loader_);
    GLL_LOADPROC(glRectfv,                                      proc_loader_);
    GLL_LOADPROC(glRecti,                                       proc_loader_);
    GLL_LOADPROC(glRectiv,                                      proc_loader_);
    GLL_LOADPROC(glRects,                                       proc_loader_);
    GLL_LOADPROC(glRectsv,                                      proc_loader_);
    GLL_LOADPROC(glTexCoord1d,                                  proc_loader_);
    GLL_LOADPROC(glTexCoord1dv,                                 proc_loader_);
    GLL_LOADPROC(glTexCoord1f,                                  proc_loader_);
    GLL_LOADPROC(glTexCoord1fv,                                 proc_loader_);
    GLL_LOADPROC(glTexCoord1i,                                  proc_loader_);
    GLL_LOADPROC(glTexCoord1iv,                                 proc_loader_);
    GLL_LOADPROC(glTexCoord1s,                                  proc_loader_);
    GLL_LOADPROC(glTexCoord1sv,                                 proc_loader_);
    GLL_LOADPROC(glTexCoord2d,                                  proc_loader_);
    GLL_LOADPROC(glTexCoord2dv,                                 proc_loader_);
    GLL_LOADPROC(glTexCoord2f,                                  proc_loader_);
    GLL_LOADPROC(glTexCoord2fv,                                 proc_loader_);
    GLL_LOADPROC(glTexCoord2i,                                  proc_loader_);
    GLL_LOADPROC(glTexCoord2iv,                                 proc_loader_);
    GLL_LOADPROC(glTexCoord2s,                                  proc_loader_);
    GLL_LOADPROC(glTexCoord2sv,                                 proc_loader_);
    GLL_LOADPROC(glTexCoord3d,                                  proc_loader_);
    GLL_LOADPROC(glTexCoord3dv,                                 proc_loader_);
    GLL_LOADPROC(glTexCoord3f,                                  proc_loader_);
    GLL_LOADPROC(glTexCoord3fv,                                 proc_loader_);
    GLL_LOADPROC(glTexCoord3i,                                  proc_loader_);
    GLL_LOADPROC(glTexCoord3iv,                                 proc_loader_);
    GLL_LOADPROC(glTexCoord3s,                                  proc_loader_);
    GLL_LOADPROC(glTexCoord3sv,                                 proc_loader_);
    GLL_LOADPROC(glTexCoord4d,                                  proc_loader_);
    GLL_LOADPROC(glTexCoord4dv,                                 proc_loader_);
    GLL_LOADPROC(glTexCoord4f,                                  proc_loader_);
    GLL_LOADPROC(glTexCoord4fv,                                 proc_loader_);
    GLL_LOADPROC(glTexCoord4i,                                  proc_loader_);
    GLL_LOADPROC(glTexCoord4iv,                                 proc_loader_);
    GLL_LOADPROC(glTexCoord4s,                                  proc_loader_);
    GLL_LOADPROC(glTexCoord4sv,                                 proc_loader_);
    GLL_LOADPROC(glVertex2d,                                    proc_loader_);
    GLL_LOADPROC(glVertex2dv,                                   proc_loader_);
    GLL_LOADPROC(glVertex2f,                                    proc_loader_);
    GLL_LOADPROC(glVertex2fv,                                   proc_loader_);
    GLL_LOADPROC(glVertex2i,                                    proc_loader_);
    GLL_LOADPROC(glVertex2iv,                                   proc_loader_);
    GLL_LOADPROC(glVertex2s,                                    proc_loader_);
    GLL_LOADPROC(glVertex2sv,                                   proc_loader_);
    GLL_LOADPROC(glVertex3d,                                    proc_loader_);
    GLL_LOADPROC(glVertex3dv,                                   proc_loader_);
    GLL_LOADPROC(glVertex3f,                                    proc_loader_);
    GLL_LOADPROC(glVertex3fv,                                   proc_loader_);
    GLL_LOADPROC(glVertex3i,                                    proc_loader_);
    GLL_LOADPROC(glVertex3iv,                                   proc_loader_);
    GLL_LOADPROC(glVertex3s,                                    proc_loader_);
    GLL_LOADPROC(glVertex3sv,                                   proc_loader_);
    GLL_LOADPROC(glVertex4d,                                    proc_loader_);
    GLL_LOADPROC(glVertex4dv,                                   proc_loader_);
    GLL_LOADPROC(glVertex4f,                                    proc_loader_);
    GLL_LOADPROC(glVertex4fv,                                   proc_loader_);
    GLL_LOADPROC(glVertex4i,                                    proc_loader_);
    GLL_LOADPROC(glVertex4iv,                                   proc_loader_);
    GLL_LOADPROC(glVertex4s,                                    proc_loader_);
    GLL_LOADPROC(glVertex4sv,                                   proc_loader_);
    GLL_LOADPROC(glClipPlane,                                   proc_loader_);
    GLL_LOADPROC(glColorMaterial,                               proc_loader_);
    GLL_LOADPROC(glFogf,                                        proc_loader_);
    GLL_LOADPROC(glFogfv,                                       proc_loader_);
    GLL_LOADPROC(glFogi,                                        proc_loader_);
    GLL_LOADPROC(glFogiv,                                       proc_loader_);
    GLL_LOADPROC(glLightf,                                      proc_loader_);
    GLL_LOADPROC(glLightfv,                                     proc_loader_);
    GLL_LOADPROC(glLighti,                                      proc_loader_);
    GLL_LOADPROC(glLightiv,                                     proc_loader_);
    GLL_LOADPROC(glLightModelf,                                 proc_loader_);
    GLL_LOADPROC(glLightModelfv,                                proc_loader_);
    GLL_LOADPROC(glLightModeli,                                 proc_loader_);
    GLL_LOADPROC(glLightModeliv,                                proc_loader_);
    GLL_LOADPROC(glLineStipple,                                 proc_loader_);
    GLL_LOADPROC(glMaterialf,                                   proc_loader_);
    GLL_LOADPROC(glMaterialfv,                                  proc_loader_);
    GLL_LOADPROC(glMateriali,                                   proc_loader_);
    GLL_LOADPROC(glMaterialiv,                                  proc_loader_);
    GLL_LOADPROC(glPolygonStipple,                              proc_loader_);
    GLL_LOADPROC(glShadeModel,                                  proc_loader_);
    GLL_LOADPROC(glTexEnvf,                                     proc_loader_);
    GLL_LOADPROC(glTexEnvfv,                                    proc_loader_);
    GLL_LOADPROC(glTexEnvi,                                     proc_loader_);
    GLL_LOADPROC(glTexEnviv,                                    proc_loader_);
    GLL_LOADPROC(glTexGend,                                     proc_loader_);
    GLL_LOADPROC(glTexGendv,                                    proc_loader_);
    GLL_LOADPROC(glTexGenf,                                     proc_loader_);
    GLL_LOADPROC(glTexGenfv,                                    proc_loader_);
    GLL_LOADPROC(glTexGeni,                                     proc_loader_);
    GLL_LOADPROC(glTexGeniv,                                    proc_loader_);
    GLL_LOADPROC(glFeedbackBuffer,                              proc_loader_);
    GLL_LOADPROC(glSelectBuffer,                                proc_loader_);
    GLL_LOADPROC(glRenderMode,                                  proc_loader_);
    GLL_LOADPROC(glInitNames,                                   proc_loader_);
    GLL_LOADPROC(glLoadName,                                    proc_loader_);
    GLL_LOADPROC(glPassThrough,                                 proc_loader_);
    GLL_LOADPROC(glPopName,                                     proc_loader_);
    GLL_LOADPROC(glPushName,                                    proc_loader_);
    GLL_LOADPROC(glClearAccum,                                  proc_loader_);
    GLL_LOADPROC(glClearIndex,                                  proc_loader_);
    GLL_LOADPROC(glIndexMask,                                   proc_loader_);
    GLL_LOADPROC(glAccum,                                       proc_loader_);
    GLL_LOADPROC(glPopAttrib,                                   proc_loader_);
    GLL_LOADPROC(glPushAttrib,                                  proc_loader_);
    GLL_LOADPROC(glMap1d,                                       proc_loader_);
    GLL_LOADPROC(glMap1f,                                       proc_loader_);
    GLL_LOADPROC(glMap2d,                                       proc_loader_);
    GLL_LOADPROC(glMap2f,                                       proc_loader_);
    GLL_LOADPROC(glMapGrid1d,                                   proc_loader_);
    GLL_LOADPROC(glMapGrid1f,                                   proc_loader_);
    GLL_LOADPROC(glMapGrid2d,                                   proc_loader_);
    GLL_LOADPROC(glMapGrid2f,                                   proc_loader_);
    GLL_LOADPROC(glEvalCoord1d,                                 proc_loader_);
    GLL_LOADPROC(glEvalCoord1dv,                                proc_loader_);
    GLL_LOADPROC(glEvalCoord1f,                                 proc_loader_);
    GLL_LOADPROC(glEvalCoord1fv,                                proc_loader_);
    GLL_LOADPROC(glEvalCoord2d,                                 proc_loader_);
    GLL_LOADPROC(glEvalCoord2dv,                                proc_loader_);
    GLL_LOADPROC(glEvalCoord2f,                                 proc_loader_);
    GLL_LOADPROC(glEvalCoord2fv,                                proc_loader_);
    GLL_LOADPROC(glEvalMesh1,                                   proc_loader_);
    GLL_LOADPROC(glEvalPoint1,                                  proc_loader_);
    GLL_LOADPROC(glEvalMesh2,                                   proc_loader_);
    GLL_LOADPROC(glEvalPoint2,                                  proc_loader_);
    GLL_LOADPROC(glAlphaFunc,                                   proc_loader_);
    GLL_LOADPROC(glPixelZoom,                                   proc_loader_);
    GLL_LOADPROC(glPixelTransferf,                              proc_loader_);
    GLL_LOADPROC(glPixelTransferi,                              proc_loader_);
    GLL_LOADPROC(glPixelMapfv,                                  proc_loader_);
    GLL_LOADPROC(glPixelMapuiv,                                 proc_loader_);
    GLL_LOADPROC(glPixelMapusv,                                 proc_loader_);
    GLL_LOADPROC(glCopyPixels,                                  proc_loader_);
    GLL_LOADPROC(glDrawPixels,                                  proc_loader_);
    GLL_LOADPROC(glGetClipPlane,                                proc_loader_);
    GLL_LOADPROC(glGetLightfv,                                  proc_loader_);
    GLL_LOADPROC(glGetLightiv,                                  proc_loader_);
    GLL_LOADPROC(glGetMapdv,                                    proc_loader_);
    GLL_LOADPROC(glGetMapfv,                                    proc_loader_);
    GLL_LOADPROC(glGetMapiv,                                    proc_loader_);
    GLL_LOADPROC(glGetMaterialfv,                               proc_loader_);
    GLL_LOADPROC(glGetMaterialiv,                               proc_loader_);
    GLL_LOADPROC(glGetPixelMapfv,                               proc_loader_);
    GLL_LOADPROC(glGetPixelMapuiv,                              proc_loader_);
    GLL_LOADPROC(glGetPixelMapusv,                              proc_loader_);
    GLL_LOADPROC(glGetPolygonStipple,                           proc_loader_);
    GLL_LOADPROC(glGetTexEnvfv,                                 proc_loader_);
    GLL_LOADPROC(glGetTexEnviv,                                 proc_loader_);
    GLL_LOADPROC(glGetTexGendv,                                 proc_loader_);
    GLL_LOADPROC(glGetTexGenfv,                                 proc_loader_);
    GLL_LOADPROC(glGetTexGeniv,                                 proc_loader_);
    GLL_LOADPROC(glIsList,                                      proc_loader_);
    GLL_LOADPROC(glFrustum,                                     proc_loader_);
    GLL_LOADPROC(glLoadIdentity,                                proc_loader_);
    GLL_LOADPROC(glLoadMatrixf,                                 proc_loader_);
    GLL_LOADPROC(glLoadMatrixd,                                 proc_loader_);
    GLL_LOADPROC(glMatrixMode,                                  proc_loader_);
    GLL_LOADPROC(glMultMatrixf,                                 proc_loader_);
    GLL_LOADPROC(glMultMatrixd,                                 proc_loader_);
    GLL_LOADPROC(glOrtho,                                       proc_loader_);
    GLL_LOADPROC(glPopMatrix,                                   proc_loader_);
    GLL_LOADPROC(glPushMatrix,                                  proc_loader_);
    GLL_LOADPROC(glRotated,                                     proc_loader_);
    GLL_LOADPROC(glRotatef,                                     proc_loader_);
    GLL_LOADPROC(glScaled,                                      proc_loader_);
    GLL_LOADPROC(glScalef,                                      proc_loader_);
    GLL_LOADPROC(glTranslated,                                  proc_loader_);
    GLL_LOADPROC(glTranslatef,                                  proc_loader_);
}

static GLL_INLINE void GLL__load_gl_version_110 (GLL_proc_loader proc_loader_, GLL_bool load_comp_)
{
    GLL_LOADPROC(glDrawArrays,                                  proc_loader_);
    GLL_LOADPROC(glDrawElements,                                proc_loader_);
    GLL_LOADPROC(glGetPointerv,                                 proc_loader_);
    GLL_LOADPROC(glPolygonOffset,                               proc_loader_);
    GLL_LOADPROC(glCopyTexImage1D,                              proc_loader_);
    GLL_LOADPROC(glCopyTexImage2D,                              proc_loader_);
    GLL_LOADPROC(glCopyTexSubImage1D,                           proc_loader_);
    GLL_LOADPROC(glCopyTexSubImage2D,                           proc_loader_);
    GLL_LOADPROC(glTexSubImage1D,                               proc_loader_);
    GLL_LOADPROC(glTexSubImage2D,                               proc_loader_);
    GLL_LOADPROC(glBindTexture,                                 proc_loader_);
    GLL_LOADPROC(glDeleteTextures,                              proc_loader_);
    GLL_LOADPROC(glGenTextures,                                 proc_loader_);
    GLL_LOADPROC(glIsTexture,                                   proc_loader_);

    if (!load_comp_) return;

    GLL_LOADPROC(glArrayElement,                                proc_loader_);
    GLL_LOADPROC(glColorPointer,                                proc_loader_);
    GLL_LOADPROC(glDisableClientState,                          proc_loader_);
    GLL_LOADPROC(glEdgeFlagPointer,                             proc_loader_);
    GLL_LOADPROC(glEnableClientState,                           proc_loader_);
    GLL_LOADPROC(glIndexPointer,                                proc_loader_);
    GLL_LOADPROC(glInterleavedArrays,                           proc_loader_);
    GLL_LOADPROC(glNormalPointer,                               proc_loader_);
    GLL_LOADPROC(glTexCoordPointer,                             proc_loader_);
    GLL_LOADPROC(glVertexPointer,                               proc_loader_);
    GLL_LOADPROC(glAreTexturesResident,                         proc_loader_);
    GLL_LOADPROC(glPrioritizeTextures,                          proc_loader_);
    GLL_LOADPROC(glIndexub,                                     proc_loader_);
    GLL_LOADPROC(glIndexubv,                                    proc_loader_);
    GLL_LOADPROC(glPopClientAttrib,                             proc_loader_);
    GLL_LOADPROC(glPushClientAttrib,                            proc_loader_);
}

static GLL_INLINE void GLL__load_gl_version_120 (GLL_proc_loader proc_loader_, GLL_bool load_comp_)
{
    GLL_LOADPROC(glDrawRangeElements,                           proc_loader_);
    GLL_LOADPROC(glTexImage3D,                                  proc_loader_);
    GLL_LOADPROC(glTexSubImage3D,                               proc_loader_);
    GLL_LOADPROC(glCopyTexSubImage3D,                           proc_loader_);
}

static GLL_INLINE void GLL__load_gl_version_130 (GLL_proc_loader proc_loader_, GLL_bool load_comp_)
{
    GLL_LOADPROC(glActiveTexture,                               proc_loader_);
    GLL_LOADPROC(glSampleCoverage,                              proc_loader_);
    GLL_LOADPROC(glCompressedTexImage3D,                        proc_loader_);
    GLL_LOADPROC(glCompressedTexImage2D,                        proc_loader_);
    GLL_LOADPROC(glCompressedTexImage1D,                        proc_loader_);
    GLL_LOADPROC(glCompressedTexSubImage3D,                     proc_loader_);
    GLL_LOADPROC(glCompressedTexSubImage2D,                     proc_loader_);
    GLL_LOADPROC(glCompressedTexSubImage1D,                     proc_loader_);
    GLL_LOADPROC(glGetCompressedTexImage,                       proc_loader_);

    if (!load_comp_) return;

    GLL_LOADPROC(glClientActiveTexture,                         proc_loader_);
    GLL_LOADPROC(glMultiTexCoord1d,                             proc_loader_);
    GLL_LOADPROC(glMultiTexCoord1dv,                            proc_loader_);
    GLL_LOADPROC(glMultiTexCoord1f,                             proc_loader_);
    GLL_LOADPROC(glMultiTexCoord1fv,                            proc_loader_);
    GLL_LOADPROC(glMultiTexCoord1i,                             proc_loader_);
    GLL_LOADPROC(glMultiTexCoord1iv,                            proc_loader_);
    GLL_LOADPROC(glMultiTexCoord1s,                             proc_loader_);
    GLL_LOADPROC(glMultiTexCoord1sv,                            proc_loader_);
    GLL_LOADPROC(glMultiTexCoord2d,                             proc_loader_);
    GLL_LOADPROC(glMultiTexCoord2dv,                            proc_loader_);
    GLL_LOADPROC(glMultiTexCoord2f,                             proc_loader_);
    GLL_LOADPROC(glMultiTexCoord2fv,                            proc_loader_);
    GLL_LOADPROC(glMultiTexCoord2i,                             proc_loader_);
    GLL_LOADPROC(glMultiTexCoord2iv,                            proc_loader_);
    GLL_LOADPROC(glMultiTexCoord2s,                             proc_loader_);
    GLL_LOADPROC(glMultiTexCoord2sv,                            proc_loader_);
    GLL_LOADPROC(glMultiTexCoord3d,                             proc_loader_);
    GLL_LOADPROC(glMultiTexCoord3dv,                            proc_loader_);
    GLL_LOADPROC(glMultiTexCoord3f,                             proc_loader_);
    GLL_LOADPROC(glMultiTexCoord3fv,                            proc_loader_);
    GLL_LOADPROC(glMultiTexCoord3i,                             proc_loader_);
    GLL_LOADPROC(glMultiTexCoord3iv,                            proc_loader_);
    GLL_LOADPROC(glMultiTexCoord3s,                             proc_loader_);
    GLL_LOADPROC(glMultiTexCoord3sv,                            proc_loader_);
    GLL_LOADPROC(glMultiTexCoord4d,                             proc_loader_);
    GLL_LOADPROC(glMultiTexCoord4dv,                            proc_loader_);
    GLL_LOADPROC(glMultiTexCoord4f,                             proc_loader_);
    GLL_LOADPROC(glMultiTexCoord4fv,                            proc_loader_);
    GLL_LOADPROC(glMultiTexCoord4i,                             proc_loader_);
    GLL_LOADPROC(glMultiTexCoord4iv,                            proc_loader_);
    GLL_LOADPROC(glMultiTexCoord4s,                             proc_loader_);
    GLL_LOADPROC(glMultiTexCoord4sv,                            proc_loader_);
    GLL_LOADPROC(glLoadTransposeMatrixf,                        proc_loader_);
    GLL_LOADPROC(glLoadTransposeMatrixd,                        proc_loader_);
    GLL_LOADPROC(glMultTransposeMatrixf,                        proc_loader_);
    GLL_LOADPROC(glMultTransposeMatrixd,                        proc_loader_);
}

static GLL_INLINE void GLL__load_gl_version_140 (GLL_proc_loader proc_loader_, GLL_bool load_comp_)
{
    GLL_LOADPROC(glBlendFuncSeparate,                           proc_loader_);
    GLL_LOADPROC(glMultiDrawArrays,                             proc_loader_);
    GLL_LOADPROC(glMultiDrawElements,                           proc_loader_);
    GLL_LOADPROC(glPointParameterf,                             proc_loader_);
    GLL_LOADPROC(glPointParameterfv,                            proc_loader_);
    GLL_LOADPROC(glPointParameteri,                             proc_loader_);
    GLL_LOADPROC(glPointParameteriv,                            proc_loader_);
    GLL_LOADPROC(glBlendColor,                                  proc_loader_);
    GLL_LOADPROC(glBlendEquation,                               proc_loader_);

    if (!load_comp_) return;

    GLL_LOADPROC(glFogCoordf,                                   proc_loader_);
    GLL_LOADPROC(glFogCoordfv,                                  proc_loader_);
    GLL_LOADPROC(glFogCoordd,                                   proc_loader_);
    GLL_LOADPROC(glFogCoorddv,                                  proc_loader_);
    GLL_LOADPROC(glFogCoordPointer,                             proc_loader_);
    GLL_LOADPROC(glSecondaryColor3b,                            proc_loader_);
    GLL_LOADPROC(glSecondaryColor3bv,                           proc_loader_);
    GLL_LOADPROC(glSecondaryColor3d,                            proc_loader_);
    GLL_LOADPROC(glSecondaryColor3dv,                           proc_loader_);
    GLL_LOADPROC(glSecondaryColor3f,                            proc_loader_);
    GLL_LOADPROC(glSecondaryColor3fv,                           proc_loader_);
    GLL_LOADPROC(glSecondaryColor3i,                            proc_loader_);
    GLL_LOADPROC(glSecondaryColor3iv,                           proc_loader_);
    GLL_LOADPROC(glSecondaryColor3s,                            proc_loader_);
    GLL_LOADPROC(glSecondaryColor3sv,                           proc_loader_);
    GLL_LOADPROC(glSecondaryColor3ub,                           proc_loader_);
    GLL_LOADPROC(glSecondaryColor3ubv,                          proc_loader_);
    GLL_LOADPROC(glSecondaryColor3ui,                           proc_loader_);
    GLL_LOADPROC(glSecondaryColor3uiv,                          proc_loader_);
    GLL_LOADPROC(glSecondaryColor3us,                           proc_loader_);
    GLL_LOADPROC(glSecondaryColor3usv,                          proc_loader_);
    GLL_LOADPROC(glSecondaryColorPointer,                       proc_loader_);
    GLL_LOADPROC(glWindowPos2d,                                 proc_loader_);
    GLL_LOADPROC(glWindowPos2dv,                                proc_loader_);
    GLL_LOADPROC(glWindowPos2f,                                 proc_loader_);
    GLL_LOADPROC(glWindowPos2fv,                                proc_loader_);
    GLL_LOADPROC(glWindowPos2i,                                 proc_loader_);
    GLL_LOADPROC(glWindowPos2iv,                                proc_loader_);
    GLL_LOADPROC(glWindowPos2s,                                 proc_loader_);
    GLL_LOADPROC(glWindowPos2sv,                                proc_loader_);
    GLL_LOADPROC(glWindowPos3d,                                 proc_loader_);
    GLL_LOADPROC(glWindowPos3dv,                                proc_loader_);
    GLL_LOADPROC(glWindowPos3f,                                 proc_loader_);
    GLL_LOADPROC(glWindowPos3fv,                                proc_loader_);
    GLL_LOADPROC(glWindowPos3i,                                 proc_loader_);
    GLL_LOADPROC(glWindowPos3iv,                                proc_loader_);
    GLL_LOADPROC(glWindowPos3s,                                 proc_loader_);
    GLL_LOADPROC(glWindowPos3sv,                                proc_loader_);
}

static GLL_INLINE void GLL__load_gl_version_150 (GLL_proc_loader proc_loader_, GLL_bool load_comp_)
{
    GLL_LOADPROC(glGenQueries,                                  proc_loader_);
    GLL_LOADPROC(glDeleteQueries,                               proc_loader_);
    GLL_LOADPROC(glIsQuery,                                     proc_loader_);
    GLL_LOADPROC(glBeginQuery,                                  proc_loader_);
    GLL_LOADPROC(glEndQuery,                                    proc_loader_);
    GLL_LOADPROC(glGetQueryiv,                                  proc_loader_);
    GLL_LOADPROC(glGetQueryObjectiv,                            proc_loader_);
    GLL_LOADPROC(glGetQueryObjectuiv,                           proc_loader_);
    GLL_LOADPROC(glBindBuffer,                                  proc_loader_);
    GLL_LOADPROC(glDeleteBuffers,                               proc_loader_);
    GLL_LOADPROC(glGenBuffers,                                  proc_loader_);
    GLL_LOADPROC(glIsBuffer,                                    proc_loader_);
    GLL_LOADPROC(glBufferData,                                  proc_loader_);
    GLL_LOADPROC(glBufferSubData,                               proc_loader_);
    GLL_LOADPROC(glGetBufferSubData,                            proc_loader_);
    GLL_LOADPROC(glMapBuffer,                                   proc_loader_);
    GLL_LOADPROC(glUnmapBuffer,                                 proc_loader_);
    GLL_LOADPROC(glGetBufferParameteriv,                        proc_loader_);
    GLL_LOADPROC(glGetBufferPointerv,                           proc_loader_);
}

static GLL_INLINE void GLL__load_gl_version_200 (GLL_proc_loader proc_loader_, GLL_bool load_comp_)
{
    GLL_LOADPROC(glBlendEquationSeparate,                       proc_loader_);
    GLL_LOADPROC(glDrawBuffers,                                 proc_loader_);
    GLL_LOADPROC(glStencilOpSeparate,                           proc_loader_);
    GLL_LOADPROC(glStencilFuncSeparate,                         proc_loader_);
    GLL_LOADPROC(glStencilMaskSeparate,                         proc_loader_);
    GLL_LOADPROC(glAttachShader,                                proc_loader_);
    GLL_LOADPROC(glBindAttribLocation,                          proc_loader_);
    GLL_LOADPROC(glCompileShader,                               proc_loader_);
    GLL_LOADPROC(glCreateProgram,                               proc_loader_);
    GLL_LOADPROC(glCreateShader,                                proc_loader_);
    GLL_LOADPROC(glDeleteProgram,                               proc_loader_);
    GLL_LOADPROC(glDeleteShader,                                proc_loader_);
    GLL_LOADPROC(glDetachShader,                                proc_loader_);
    GLL_LOADPROC(glDisableVertexAttribArray,                    proc_loader_);
    GLL_LOADPROC(glEnableVertexAttribArray,                     proc_loader_);
    GLL_LOADPROC(glGetActiveAttrib,                             proc_loader_);
    GLL_LOADPROC(glGetActiveUniform,                            proc_loader_);
    GLL_LOADPROC(glGetAttachedShaders,                          proc_loader_);
    GLL_LOADPROC(glGetAttribLocation,                           proc_loader_);
    GLL_LOADPROC(glGetProgramiv,                                proc_loader_);
    GLL_LOADPROC(glGetProgramInfoLog,                           proc_loader_);
    GLL_LOADPROC(glGetShaderiv,                                 proc_loader_);
    GLL_LOADPROC(glGetShaderInfoLog,                            proc_loader_);
    GLL_LOADPROC(glGetShaderSource,                             proc_loader_);
    GLL_LOADPROC(glGetUniformLocation,                          proc_loader_);
    GLL_LOADPROC(glGetUniformfv,                                proc_loader_);
    GLL_LOADPROC(glGetUniformiv,                                proc_loader_);
    GLL_LOADPROC(glGetVertexAttribdv,                           proc_loader_);
    GLL_LOADPROC(glGetVertexAttribfv,                           proc_loader_);
    GLL_LOADPROC(glGetVertexAttribiv,                           proc_loader_);
    GLL_LOADPROC(glGetVertexAttribPointerv,                     proc_loader_);
    GLL_LOADPROC(glIsProgram,                                   proc_loader_);
    GLL_LOADPROC(glIsShader,                                    proc_loader_);
    GLL_LOADPROC(glLinkProgram,                                 proc_loader_);
    GLL_LOADPROC(glShaderSource,                                proc_loader_);
    GLL_LOADPROC(glUseProgram,                                  proc_loader_);
    GLL_LOADPROC(glUniform1f,                                   proc_loader_);
    GLL_LOADPROC(glUniform2f,                                   proc_loader_);
    GLL_LOADPROC(glUniform3f,                                   proc_loader_);
    GLL_LOADPROC(glUniform4f,                                   proc_loader_);
    GLL_LOADPROC(glUniform1i,                                   proc_loader_);
    GLL_LOADPROC(glUniform2i,                                   proc_loader_);
    GLL_LOADPROC(glUniform3i,                                   proc_loader_);
    GLL_LOADPROC(glUniform4i,                                   proc_loader_);
    GLL_LOADPROC(glUniform1fv,                                  proc_loader_);
    GLL_LOADPROC(glUniform2fv,                                  proc_loader_);
    GLL_LOADPROC(glUniform3fv,                                  proc_loader_);
    GLL_LOADPROC(glUniform4fv,                                  proc_loader_);
    GLL_LOADPROC(glUniform1iv,                                  proc_loader_);
    GLL_LOADPROC(glUniform2iv,                                  proc_loader_);
    GLL_LOADPROC(glUniform3iv,                                  proc_loader_);
    GLL_LOADPROC(glUniform4iv,                                  proc_loader_);
    GLL_LOADPROC(glUniformMatrix2fv,                            proc_loader_);
    GLL_LOADPROC(glUniformMatrix3fv,                            proc_loader_);
    GLL_LOADPROC(glUniformMatrix4fv,                            proc_loader_);
    GLL_LOADPROC(glValidateProgram,                             proc_loader_);
    GLL_LOADPROC(glVertexAttrib1d,                              proc_loader_);
    GLL_LOADPROC(glVertexAttrib1dv,                             proc_loader_);
    GLL_LOADPROC(glVertexAttrib1f,                              proc_loader_);
    GLL_LOADPROC(glVertexAttrib1fv,                             proc_loader_);
    GLL_LOADPROC(glVertexAttrib1s,                              proc_loader_);
    GLL_LOADPROC(glVertexAttrib1sv,                             proc_loader_);
    GLL_LOADPROC(glVertexAttrib2d,                              proc_loader_);
    GLL_LOADPROC(glVertexAttrib2dv,                             proc_loader_);
    GLL_LOADPROC(glVertexAttrib2f,                              proc_loader_);
    GLL_LOADPROC(glVertexAttrib2fv,                             proc_loader_);
    GLL_LOADPROC(glVertexAttrib2s,                              proc_loader_);
    GLL_LOADPROC(glVertexAttrib2sv,                             proc_loader_);
    GLL_LOADPROC(glVertexAttrib3d,                              proc_loader_);
    GLL_LOADPROC(glVertexAttrib3dv,                             proc_loader_);
    GLL_LOADPROC(glVertexAttrib3f,                              proc_loader_);
    GLL_LOADPROC(glVertexAttrib3fv,                             proc_loader_);
    GLL_LOADPROC(glVertexAttrib3s,                              proc_loader_);
    GLL_LOADPROC(glVertexAttrib3sv,                             proc_loader_);
    GLL_LOADPROC(glVertexAttrib4Nbv,                            proc_loader_);
    GLL_LOADPROC(glVertexAttrib4Niv,                            proc_loader_);
    GLL_LOADPROC(glVertexAttrib4Nsv,                            proc_loader_);
    GLL_LOADPROC(glVertexAttrib4Nub,                            proc_loader_);
    GLL_LOADPROC(glVertexAttrib4Nubv,                           proc_loader_);
    GLL_LOADPROC(glVertexAttrib4Nuiv,                           proc_loader_);
    GLL_LOADPROC(glVertexAttrib4Nusv,                           proc_loader_);
    GLL_LOADPROC(glVertexAttrib4bv,                             proc_loader_);
    GLL_LOADPROC(glVertexAttrib4d,                              proc_loader_);
    GLL_LOADPROC(glVertexAttrib4dv,                             proc_loader_);
    GLL_LOADPROC(glVertexAttrib4f,                              proc_loader_);
    GLL_LOADPROC(glVertexAttrib4fv,                             proc_loader_);
    GLL_LOADPROC(glVertexAttrib4iv,                             proc_loader_);
    GLL_LOADPROC(glVertexAttrib4s,                              proc_loader_);
    GLL_LOADPROC(glVertexAttrib4sv,                             proc_loader_);
    GLL_LOADPROC(glVertexAttrib4ubv,                            proc_loader_);
    GLL_LOADPROC(glVertexAttrib4uiv,                            proc_loader_);
    GLL_LOADPROC(glVertexAttrib4usv,                            proc_loader_);
    GLL_LOADPROC(glVertexAttribPointer,                         proc_loader_);
}

static GLL_INLINE void GLL__load_gl_version_210 (GLL_proc_loader proc_loader_, GLL_bool load_comp_)
{
    GLL_LOADPROC(glUniformMatrix2x3fv,                          proc_loader_);
    GLL_LOADPROC(glUniformMatrix3x2fv,                          proc_loader_);
    GLL_LOADPROC(glUniformMatrix2x4fv,                          proc_loader_);
    GLL_LOADPROC(glUniformMatrix4x2fv,                          proc_loader_);
    GLL_LOADPROC(glUniformMatrix3x4fv,                          proc_loader_);
    GLL_LOADPROC(glUniformMatrix4x3fv,                          proc_loader_);
}

static GLL_INLINE void GLL__load_gl_version_300 (GLL_proc_loader proc_loader_, GLL_bool load_comp_)
{
    GLL_LOADPROC(glColorMaski,                                  proc_loader_);
    GLL_LOADPROC(glGetBooleani_v,                               proc_loader_);
    GLL_LOADPROC(glGetIntegeri_v,                               proc_loader_);
    GLL_LOADPROC(glEnablei,                                     proc_loader_);
    GLL_LOADPROC(glDisablei,                                    proc_loader_);
    GLL_LOADPROC(glIsEnabledi,                                  proc_loader_);
    GLL_LOADPROC(glBeginTransformFeedback,                      proc_loader_);
    GLL_LOADPROC(glEndTransformFeedback,                        proc_loader_);
    GLL_LOADPROC(glBindBufferRange,                             proc_loader_);
    GLL_LOADPROC(glBindBufferBase,                              proc_loader_);
    GLL_LOADPROC(glTransformFeedbackVaryings,                   proc_loader_);
    GLL_LOADPROC(glGetTransformFeedbackVarying,                 proc_loader_);
    GLL_LOADPROC(glClampColor,                                  proc_loader_);
    GLL_LOADPROC(glBeginConditionalRender,                      proc_loader_);
    GLL_LOADPROC(glEndConditionalRender,                        proc_loader_);
    GLL_LOADPROC(glVertexAttribIPointer,                        proc_loader_);
    GLL_LOADPROC(glGetVertexAttribIiv,                          proc_loader_);
    GLL_LOADPROC(glGetVertexAttribIuiv,                         proc_loader_);
    GLL_LOADPROC(glVertexAttribI1i,                             proc_loader_);
    GLL_LOADPROC(glVertexAttribI2i,                             proc_loader_);
    GLL_LOADPROC(glVertexAttribI3i,                             proc_loader_);
    GLL_LOADPROC(glVertexAttribI4i,                             proc_loader_);
    GLL_LOADPROC(glVertexAttribI1ui,                            proc_loader_);
    GLL_LOADPROC(glVertexAttribI2ui,                            proc_loader_);
    GLL_LOADPROC(glVertexAttribI3ui,                            proc_loader_);
    GLL_LOADPROC(glVertexAttribI4ui,                            proc_loader_);
    GLL_LOADPROC(glVertexAttribI1iv,                            proc_loader_);
    GLL_LOADPROC(glVertexAttribI2iv,                            proc_loader_);
    GLL_LOADPROC(glVertexAttribI3iv,                            proc_loader_);
    GLL_LOADPROC(glVertexAttribI4iv,                            proc_loader_);
    GLL_LOADPROC(glVertexAttribI1uiv,                           proc_loader_);
    GLL_LOADPROC(glVertexAttribI2uiv,                           proc_loader_);
    GLL_LOADPROC(glVertexAttribI3uiv,                           proc_loader_);
    GLL_LOADPROC(glVertexAttribI4uiv,                           proc_loader_);
    GLL_LOADPROC(glVertexAttribI4bv,                            proc_loader_);
    GLL_LOADPROC(glVertexAttribI4sv,                            proc_loader_);
    GLL_LOADPROC(glVertexAttribI4ubv,                           proc_loader_);
    GLL_LOADPROC(glVertexAttribI4usv,                           proc_loader_);
    GLL_LOADPROC(glGetUniformuiv,                               proc_loader_);
    GLL_LOADPROC(glBindFragDataLocation,                        proc_loader_);
    GLL_LOADPROC(glGetFragDataLocation,                         proc_loader_);
    GLL_LOADPROC(glUniform1ui,                                  proc_loader_);
    GLL_LOADPROC(glUniform2ui,                                  proc_loader_);
    GLL_LOADPROC(glUniform3ui,                                  proc_loader_);
    GLL_LOADPROC(glUniform4ui,                                  proc_loader_);
    GLL_LOADPROC(glUniform1uiv,                                 proc_loader_);
    GLL_LOADPROC(glUniform2uiv,                                 proc_loader_);
    GLL_LOADPROC(glUniform3uiv,                                 proc_loader_);
    GLL_LOADPROC(glUniform4uiv,                                 proc_loader_);
    GLL_LOADPROC(glTexParameterIiv,                             proc_loader_);
    GLL_LOADPROC(glTexParameterIuiv,                            proc_loader_);
    GLL_LOADPROC(glGetTexParameterIiv,                          proc_loader_);
    GLL_LOADPROC(glGetTexParameterIuiv,                         proc_loader_);
    GLL_LOADPROC(glClearBufferiv,                               proc_loader_);
    GLL_LOADPROC(glClearBufferuiv,                              proc_loader_);
    GLL_LOADPROC(glClearBufferfv,                               proc_loader_);
    GLL_LOADPROC(glClearBufferfi,                               proc_loader_);
    GLL_LOADPROC(glGetStringi,                                  proc_loader_);
    GLL_LOADPROC(glIsRenderbuffer,                              proc_loader_);
    GLL_LOADPROC(glBindRenderbuffer,                            proc_loader_);
    GLL_LOADPROC(glDeleteRenderbuffers,                         proc_loader_);
    GLL_LOADPROC(glGenRenderbuffers,                            proc_loader_);
    GLL_LOADPROC(glRenderbufferStorage,                         proc_loader_);
    GLL_LOADPROC(glGetRenderbufferParameteriv,                  proc_loader_);
    GLL_LOADPROC(glIsFramebuffer,                               proc_loader_);
    GLL_LOADPROC(glBindFramebuffer,                             proc_loader_);
    GLL_LOADPROC(glDeleteFramebuffers,                          proc_loader_);
    GLL_LOADPROC(glGenFramebuffers,                             proc_loader_);
    GLL_LOADPROC(glCheckFramebufferStatus,                      proc_loader_);
    GLL_LOADPROC(glFramebufferTexture1D,                        proc_loader_);
    GLL_LOADPROC(glFramebufferTexture2D,                        proc_loader_);
    GLL_LOADPROC(glFramebufferTexture3D,                        proc_loader_);
    GLL_LOADPROC(glFramebufferRenderbuffer,                     proc_loader_);
    GLL_LOADPROC(glGetFramebufferAttachmentParameteriv,         proc_loader_);
    GLL_LOADPROC(glGenerateMipmap,                              proc_loader_);
    GLL_LOADPROC(glBlitFramebuffer,                             proc_loader_);
    GLL_LOADPROC(glRenderbufferStorageMultisample,              proc_loader_);
    GLL_LOADPROC(glFramebufferTextureLayer,                     proc_loader_);
    GLL_LOADPROC(glMapBufferRange,                              proc_loader_);
    GLL_LOADPROC(glFlushMappedBufferRange,                      proc_loader_);
    GLL_LOADPROC(glBindVertexArray,                             proc_loader_);
    GLL_LOADPROC(glDeleteVertexArrays,                          proc_loader_);
    GLL_LOADPROC(glGenVertexArrays,                             proc_loader_);
    GLL_LOADPROC(glIsVertexArray,                               proc_loader_);
}

static GLL_INLINE void GLL__load_gl_version_310 (GLL_proc_loader proc_loader_, GLL_bool load_comp_)
{
    GLL_LOADPROC(glDrawArraysInstanced,                         proc_loader_);
    GLL_LOADPROC(glDrawElementsInstanced,                       proc_loader_);
    GLL_LOADPROC(glTexBuffer,                                   proc_loader_);
    GLL_LOADPROC(glPrimitiveRestartIndex,                       proc_loader_);
    GLL_LOADPROC(glCopyBufferSubData,                           proc_loader_);
    GLL_LOADPROC(glGetUniformIndices,                           proc_loader_);
    GLL_LOADPROC(glGetActiveUniformsiv,                         proc_loader_);
    GLL_LOADPROC(glGetActiveUniformName,                        proc_loader_);
    GLL_LOADPROC(glGetUniformBlockIndex,                        proc_loader_);
    GLL_LOADPROC(glGetActiveUniformBlockiv,                     proc_loader_);
    GLL_LOADPROC(glGetActiveUniformBlockName,                   proc_loader_);
    GLL_LOADPROC(glUniformBlockBinding,                         proc_loader_);
}

static GLL_INLINE void GLL__load_gl_version_320 (GLL_proc_loader proc_loader_, GLL_bool load_comp_)
{
    GLL_LOADPROC(glDrawElementsBaseVertex,                      proc_loader_);
    GLL_LOADPROC(glDrawRangeElementsBaseVertex,                 proc_loader_);
    GLL_LOADPROC(glDrawElementsInstancedBaseVertex,             proc_loader_);
    GLL_LOADPROC(glMultiDrawElementsBaseVertex,                 proc_loader_);
    GLL_LOADPROC(glProvokingVertex,                             proc_loader_);
    GLL_LOADPROC(glFenceSync,                                   proc_loader_);
    GLL_LOADPROC(glIsSync,                                      proc_loader_);
    GLL_LOADPROC(glDeleteSync,                                  proc_loader_);
    GLL_LOADPROC(glClientWaitSync,                              proc_loader_);
    GLL_LOADPROC(glWaitSync,                                    proc_loader_);
    GLL_LOADPROC(glGetInteger64v,                               proc_loader_);
    GLL_LOADPROC(glGetSynciv,                                   proc_loader_);
    GLL_LOADPROC(glGetInteger64i_v,                             proc_loader_);
    GLL_LOADPROC(glGetBufferParameteri64v,                      proc_loader_);
    GLL_LOADPROC(glFramebufferTexture,                          proc_loader_);
    GLL_LOADPROC(glTexImage2DMultisample,                       proc_loader_);
    GLL_LOADPROC(glTexImage3DMultisample,                       proc_loader_);
    GLL_LOADPROC(glGetMultisamplefv,                            proc_loader_);
    GLL_LOADPROC(glSampleMaski,                                 proc_loader_);
}

static GLL_INLINE void GLL__load_gl_version_330 (GLL_proc_loader proc_loader_, GLL_bool load_comp_)
{
    GLL_LOADPROC(glBindFragDataLocationIndexed,                 proc_loader_);
    GLL_LOADPROC(glGetFragDataIndex,                            proc_loader_);
    GLL_LOADPROC(glGenSamplers,                                 proc_loader_);
    GLL_LOADPROC(glDeleteSamplers,                              proc_loader_);
    GLL_LOADPROC(glIsSampler,                                   proc_loader_);
    GLL_LOADPROC(glBindSampler,                                 proc_loader_);
    GLL_LOADPROC(glSamplerParameteri,                           proc_loader_);
    GLL_LOADPROC(glSamplerParameteriv,                          proc_loader_);
    GLL_LOADPROC(glSamplerParameterf,                           proc_loader_);
    GLL_LOADPROC(glSamplerParameterfv,                          proc_loader_);
    GLL_LOADPROC(glSamplerParameterIiv,                         proc_loader_);
    GLL_LOADPROC(glSamplerParameterIuiv,                        proc_loader_);
    GLL_LOADPROC(glGetSamplerParameteriv,                       proc_loader_);
    GLL_LOADPROC(glGetSamplerParameterIiv,                      proc_loader_);
    GLL_LOADPROC(glGetSamplerParameterfv,                       proc_loader_);
    GLL_LOADPROC(glGetSamplerParameterIuiv,                     proc_loader_);
    GLL_LOADPROC(glQueryCounter,                                proc_loader_);
    GLL_LOADPROC(glGetQueryObjecti64v,                          proc_loader_);
    GLL_LOADPROC(glGetQueryObjectui64v,                         proc_loader_);
    GLL_LOADPROC(glVertexAttribDivisor,                         proc_loader_);
    GLL_LOADPROC(glVertexAttribP1ui,                            proc_loader_);
    GLL_LOADPROC(glVertexAttribP1uiv,                           proc_loader_);
    GLL_LOADPROC(glVertexAttribP2ui,                            proc_loader_);
    GLL_LOADPROC(glVertexAttribP2uiv,                           proc_loader_);
    GLL_LOADPROC(glVertexAttribP3ui,                            proc_loader_);
    GLL_LOADPROC(glVertexAttribP3uiv,                           proc_loader_);
    GLL_LOADPROC(glVertexAttribP4ui,                            proc_loader_);
    GLL_LOADPROC(glVertexAttribP4uiv,                           proc_loader_);

    if (!load_comp_) return;

    GLL_LOADPROC(glVertexP2ui,                                  proc_loader_);
    GLL_LOADPROC(glVertexP2uiv,                                 proc_loader_);
    GLL_LOADPROC(glVertexP3ui,                                  proc_loader_);
    GLL_LOADPROC(glVertexP3uiv,                                 proc_loader_);
    GLL_LOADPROC(glVertexP4ui,                                  proc_loader_);
    GLL_LOADPROC(glVertexP4uiv,                                 proc_loader_);
    GLL_LOADPROC(glTexCoordP1ui,                                proc_loader_);
    GLL_LOADPROC(glTexCoordP1uiv,                               proc_loader_);
    GLL_LOADPROC(glTexCoordP2ui,                                proc_loader_);
    GLL_LOADPROC(glTexCoordP2uiv,                               proc_loader_);
    GLL_LOADPROC(glTexCoordP3ui,                                proc_loader_);
    GLL_LOADPROC(glTexCoordP3uiv,                               proc_loader_);
    GLL_LOADPROC(glTexCoordP4ui,                                proc_loader_);
    GLL_LOADPROC(glTexCoordP4uiv,                               proc_loader_);
    GLL_LOADPROC(glMultiTexCoordP1ui,                           proc_loader_);
    GLL_LOADPROC(glMultiTexCoordP1uiv,                          proc_loader_);
    GLL_LOADPROC(glMultiTexCoordP2ui,                           proc_loader_);
    GLL_LOADPROC(glMultiTexCoordP2uiv,                          proc_loader_);
    GLL_LOADPROC(glMultiTexCoordP3ui,                           proc_loader_);
    GLL_LOADPROC(glMultiTexCoordP3uiv,                          proc_loader_);
    GLL_LOADPROC(glMultiTexCoordP4ui,                           proc_loader_);
    GLL_LOADPROC(glMultiTexCoordP4uiv,                          proc_loader_);
    GLL_LOADPROC(glNormalP3ui,                                  proc_loader_);
    GLL_LOADPROC(glNormalP3uiv,                                 proc_loader_);
    GLL_LOADPROC(glColorP3ui,                                   proc_loader_);
    GLL_LOADPROC(glColorP3uiv,                                  proc_loader_);
    GLL_LOADPROC(glColorP4ui,                                   proc_loader_);
    GLL_LOADPROC(glColorP4uiv,                                  proc_loader_);
    GLL_LOADPROC(glSecondaryColorP3ui,                          proc_loader_);
    GLL_LOADPROC(glSecondaryColorP3uiv,                         proc_loader_);
}

static GLL_INLINE void GLL__load_gl_version_400 (GLL_proc_loader proc_loader_, GLL_bool load_comp_)
{
    GLL_LOADPROC(glMinSampleShading,                            proc_loader_);
    GLL_LOADPROC(glBlendEquationi,                              proc_loader_);
    GLL_LOADPROC(glBlendEquationSeparatei,                      proc_loader_);
    GLL_LOADPROC(glBlendFunci,                                  proc_loader_);
    GLL_LOADPROC(glBlendFuncSeparatei,                          proc_loader_);
    GLL_LOADPROC(glDrawArraysIndirect,                          proc_loader_);
    GLL_LOADPROC(glDrawElementsIndirect,                        proc_loader_);
    GLL_LOADPROC(glUniform1d,                                   proc_loader_);
    GLL_LOADPROC(glUniform2d,                                   proc_loader_);
    GLL_LOADPROC(glUniform3d,                                   proc_loader_);
    GLL_LOADPROC(glUniform4d,                                   proc_loader_);
    GLL_LOADPROC(glUniform1dv,                                  proc_loader_);
    GLL_LOADPROC(glUniform2dv,                                  proc_loader_);
    GLL_LOADPROC(glUniform3dv,                                  proc_loader_);
    GLL_LOADPROC(glUniform4dv,                                  proc_loader_);
    GLL_LOADPROC(glUniformMatrix2dv,                            proc_loader_);
    GLL_LOADPROC(glUniformMatrix3dv,                            proc_loader_);
    GLL_LOADPROC(glUniformMatrix4dv,                            proc_loader_);
    GLL_LOADPROC(glUniformMatrix2x3dv,                          proc_loader_);
    GLL_LOADPROC(glUniformMatrix2x4dv,                          proc_loader_);
    GLL_LOADPROC(glUniformMatrix3x2dv,                          proc_loader_);
    GLL_LOADPROC(glUniformMatrix3x4dv,                          proc_loader_);
    GLL_LOADPROC(glUniformMatrix4x2dv,                          proc_loader_);
    GLL_LOADPROC(glUniformMatrix4x3dv,                          proc_loader_);
    GLL_LOADPROC(glGetUniformdv,                                proc_loader_);
    GLL_LOADPROC(glGetSubroutineUniformLocation,                proc_loader_);
    GLL_LOADPROC(glGetSubroutineIndex,                          proc_loader_);
    GLL_LOADPROC(glGetActiveSubroutineUniformiv,                proc_loader_);
    GLL_LOADPROC(glGetActiveSubroutineUniformName,              proc_loader_);
    GLL_LOADPROC(glGetActiveSubroutineName,                     proc_loader_);
    GLL_LOADPROC(glUniformSubroutinesuiv,                       proc_loader_);
    GLL_LOADPROC(glGetUniformSubroutineuiv,                     proc_loader_);
    GLL_LOADPROC(glGetProgramStageiv,                           proc_loader_);
    GLL_LOADPROC(glPatchParameteri,                             proc_loader_);
    GLL_LOADPROC(glPatchParameterfv,                            proc_loader_);
    GLL_LOADPROC(glBindTransformFeedback,                       proc_loader_);
    GLL_LOADPROC(glDeleteTransformFeedbacks,                    proc_loader_);
    GLL_LOADPROC(glGenTransformFeedbacks,                       proc_loader_);
    GLL_LOADPROC(glIsTransformFeedback,                         proc_loader_);
    GLL_LOADPROC(glPauseTransformFeedback,                      proc_loader_);
    GLL_LOADPROC(glResumeTransformFeedback,                     proc_loader_);
    GLL_LOADPROC(glDrawTransformFeedback,                       proc_loader_);
    GLL_LOADPROC(glDrawTransformFeedbackStream,                 proc_loader_);
    GLL_LOADPROC(glBeginQueryIndexed,                           proc_loader_);
    GLL_LOADPROC(glEndQueryIndexed,                             proc_loader_);
    GLL_LOADPROC(glGetQueryIndexediv,                           proc_loader_);
}

static GLL_INLINE void GLL__load_gl_version_410 (GLL_proc_loader proc_loader_, GLL_bool load_comp_)
{
    GLL_LOADPROC(glReleaseShaderCompiler,                       proc_loader_);
    GLL_LOADPROC(glShaderBinary,                                proc_loader_);
    GLL_LOADPROC(glGetShaderPrecisionFormat,                    proc_loader_);
    GLL_LOADPROC(glDepthRangef,                                 proc_loader_);
    GLL_LOADPROC(glClearDepthf,                                 proc_loader_);
    GLL_LOADPROC(glGetProgramBinary,                            proc_loader_);
    GLL_LOADPROC(glProgramBinary,                               proc_loader_);
    GLL_LOADPROC(glProgramParameteri,                           proc_loader_);
    GLL_LOADPROC(glUseProgramStages,                            proc_loader_);
    GLL_LOADPROC(glActiveShaderProgram,                         proc_loader_);
    GLL_LOADPROC(glCreateShaderProgramv,                        proc_loader_);
    GLL_LOADPROC(glBindProgramPipeline,                         proc_loader_);
    GLL_LOADPROC(glDeleteProgramPipelines,                      proc_loader_);
    GLL_LOADPROC(glGenProgramPipelines,                         proc_loader_);
    GLL_LOADPROC(glIsProgramPipeline,                           proc_loader_);
    GLL_LOADPROC(glGetProgramPipelineiv,                        proc_loader_);
    GLL_LOADPROC(glProgramUniform1i,                            proc_loader_);
    GLL_LOADPROC(glProgramUniform1iv,                           proc_loader_);
    GLL_LOADPROC(glProgramUniform1f,                            proc_loader_);
    GLL_LOADPROC(glProgramUniform1fv,                           proc_loader_);
    GLL_LOADPROC(glProgramUniform1d,                            proc_loader_);
    GLL_LOADPROC(glProgramUniform1dv,                           proc_loader_);
    GLL_LOADPROC(glProgramUniform1ui,                           proc_loader_);
    GLL_LOADPROC(glProgramUniform1uiv,                          proc_loader_);
    GLL_LOADPROC(glProgramUniform2i,                            proc_loader_);
    GLL_LOADPROC(glProgramUniform2iv,                           proc_loader_);
    GLL_LOADPROC(glProgramUniform2f,                            proc_loader_);
    GLL_LOADPROC(glProgramUniform2fv,                           proc_loader_);
    GLL_LOADPROC(glProgramUniform2d,                            proc_loader_);
    GLL_LOADPROC(glProgramUniform2dv,                           proc_loader_);
    GLL_LOADPROC(glProgramUniform2ui,                           proc_loader_);
    GLL_LOADPROC(glProgramUniform2uiv,                          proc_loader_);
    GLL_LOADPROC(glProgramUniform3i,                            proc_loader_);
    GLL_LOADPROC(glProgramUniform3iv,                           proc_loader_);
    GLL_LOADPROC(glProgramUniform3f,                            proc_loader_);
    GLL_LOADPROC(glProgramUniform3fv,                           proc_loader_);
    GLL_LOADPROC(glProgramUniform3d,                            proc_loader_);
    GLL_LOADPROC(glProgramUniform3dv,                           proc_loader_);
    GLL_LOADPROC(glProgramUniform3ui,                           proc_loader_);
    GLL_LOADPROC(glProgramUniform3uiv,                          proc_loader_);
    GLL_LOADPROC(glProgramUniform4i,                            proc_loader_);
    GLL_LOADPROC(glProgramUniform4iv,                           proc_loader_);
    GLL_LOADPROC(glProgramUniform4f,                            proc_loader_);
    GLL_LOADPROC(glProgramUniform4fv,                           proc_loader_);
    GLL_LOADPROC(glProgramUniform4d,                            proc_loader_);
    GLL_LOADPROC(glProgramUniform4dv,                           proc_loader_);
    GLL_LOADPROC(glProgramUniform4ui,                           proc_loader_);
    GLL_LOADPROC(glProgramUniform4uiv,                          proc_loader_);
    GLL_LOADPROC(glProgramUniformMatrix2fv,                     proc_loader_);
    GLL_LOADPROC(glProgramUniformMatrix3fv,                     proc_loader_);
    GLL_LOADPROC(glProgramUniformMatrix4fv,                     proc_loader_);
    GLL_LOADPROC(glProgramUniformMatrix2dv,                     proc_loader_);
    GLL_LOADPROC(glProgramUniformMatrix3dv,                     proc_loader_);
    GLL_LOADPROC(glProgramUniformMatrix4dv,                     proc_loader_);
    GLL_LOADPROC(glProgramUniformMatrix2x3fv,                   proc_loader_);
    GLL_LOADPROC(glProgramUniformMatrix3x2fv,                   proc_loader_);
    GLL_LOADPROC(glProgramUniformMatrix2x4fv,                   proc_loader_);
    GLL_LOADPROC(glProgramUniformMatrix4x2fv,                   proc_loader_);
    GLL_LOADPROC(glProgramUniformMatrix3x4fv,                   proc_loader_);
    GLL_LOADPROC(glProgramUniformMatrix4x3fv,                   proc_loader_);
    GLL_LOADPROC(glProgramUniformMatrix2x3dv,                   proc_loader_);
    GLL_LOADPROC(glProgramUniformMatrix3x2dv,                   proc_loader_);
    GLL_LOADPROC(glProgramUniformMatrix2x4dv,                   proc_loader_);
    GLL_LOADPROC(glProgramUniformMatrix4x2dv,                   proc_loader_);
    GLL_LOADPROC(glProgramUniformMatrix3x4dv,                   proc_loader_);
    GLL_LOADPROC(glProgramUniformMatrix4x3dv,                   proc_loader_);
    GLL_LOADPROC(glValidateProgramPipeline,                     proc_loader_);
    GLL_LOADPROC(glGetProgramPipelineInfoLog,                   proc_loader_);
    GLL_LOADPROC(glVertexAttribL1d,                             proc_loader_);
    GLL_LOADPROC(glVertexAttribL2d,                             proc_loader_);
    GLL_LOADPROC(glVertexAttribL3d,                             proc_loader_);
    GLL_LOADPROC(glVertexAttribL4d,                             proc_loader_);
    GLL_LOADPROC(glVertexAttribL1dv,                            proc_loader_);
    GLL_LOADPROC(glVertexAttribL2dv,                            proc_loader_);
    GLL_LOADPROC(glVertexAttribL3dv,                            proc_loader_);
    GLL_LOADPROC(glVertexAttribL4dv,                            proc_loader_);
    GLL_LOADPROC(glVertexAttribLPointer,                        proc_loader_);
    GLL_LOADPROC(glGetVertexAttribLdv,                          proc_loader_);
    GLL_LOADPROC(glViewportArrayv,                              proc_loader_);
    GLL_LOADPROC(glViewportIndexedf,                            proc_loader_);
    GLL_LOADPROC(glViewportIndexedfv,                           proc_loader_);
    GLL_LOADPROC(glScissorArrayv,                               proc_loader_);
    GLL_LOADPROC(glScissorIndexed,                              proc_loader_);
    GLL_LOADPROC(glScissorIndexedv,                             proc_loader_);
    GLL_LOADPROC(glDepthRangeArrayv,                            proc_loader_);
    GLL_LOADPROC(glDepthRangeIndexed,                           proc_loader_);
    GLL_LOADPROC(glGetFloati_v,                                 proc_loader_);
    GLL_LOADPROC(glGetDoublei_v,                                proc_loader_);
}

static GLL_INLINE void GLL__load_gl_version_420 (GLL_proc_loader proc_loader_, GLL_bool load_comp_)
{
    GLL_LOADPROC(glDrawArraysInstancedBaseInstance,             proc_loader_);
    GLL_LOADPROC(glDrawElementsInstancedBaseInstance,           proc_loader_);
    GLL_LOADPROC(glDrawElementsInstancedBaseVertexBaseInstance, proc_loader_);
    GLL_LOADPROC(glGetInternalformativ,                         proc_loader_);
    GLL_LOADPROC(glGetActiveAtomicCounterBufferiv,              proc_loader_);
    GLL_LOADPROC(glBindImageTexture,                            proc_loader_);
    GLL_LOADPROC(glMemoryBarrier,                               proc_loader_);
    GLL_LOADPROC(glTexStorage1D,                                proc_loader_);
    GLL_LOADPROC(glTexStorage2D,                                proc_loader_);
    GLL_LOADPROC(glTexStorage3D,                                proc_loader_);
    GLL_LOADPROC(glDrawTransformFeedbackInstanced,              proc_loader_);
    GLL_LOADPROC(glDrawTransformFeedbackStreamInstanced,        proc_loader_);
}

static GLL_INLINE void GLL__load_gl_version_430 (GLL_proc_loader proc_loader_, GLL_bool load_comp_)
{
    GLL_LOADPROC(glClearBufferData,                             proc_loader_);
    GLL_LOADPROC(glClearBufferSubData,                          proc_loader_);
    GLL_LOADPROC(glDispatchCompute,                             proc_loader_);
    GLL_LOADPROC(glDispatchComputeIndirect,                     proc_loader_);
    GLL_LOADPROC(glCopyImageSubData,                            proc_loader_);
    GLL_LOADPROC(glFramebufferParameteri,                       proc_loader_);
    GLL_LOADPROC(glGetFramebufferParameteriv,                   proc_loader_);
    GLL_LOADPROC(glGetInternalformati64v,                       proc_loader_);
    GLL_LOADPROC(glInvalidateTexSubImage,                       proc_loader_);
    GLL_LOADPROC(glInvalidateTexImage,                          proc_loader_);
    GLL_LOADPROC(glInvalidateBufferSubData,                     proc_loader_);
    GLL_LOADPROC(glInvalidateBufferData,                        proc_loader_);
    GLL_LOADPROC(glInvalidateFramebuffer,                       proc_loader_);
    GLL_LOADPROC(glInvalidateSubFramebuffer,                    proc_loader_);
    GLL_LOADPROC(glMultiDrawArraysIndirect,                     proc_loader_);
    GLL_LOADPROC(glMultiDrawElementsIndirect,                   proc_loader_);
    GLL_LOADPROC(glGetProgramInterfaceiv,                       proc_loader_);
    GLL_LOADPROC(glGetProgramResourceIndex,                     proc_loader_);
    GLL_LOADPROC(glGetProgramResourceName,                      proc_loader_);
    GLL_LOADPROC(glGetProgramResourceiv,                        proc_loader_);
    GLL_LOADPROC(glGetProgramResourceLocation,                  proc_loader_);
    GLL_LOADPROC(glGetProgramResourceLocationIndex,             proc_loader_);
    GLL_LOADPROC(glShaderStorageBlockBinding,                   proc_loader_);
    GLL_LOADPROC(glTexBufferRange,                              proc_loader_);
    GLL_LOADPROC(glTexStorage2DMultisample,                     proc_loader_);
    GLL_LOADPROC(glTexStorage3DMultisample,                     proc_loader_);
    GLL_LOADPROC(glTextureView,                                 proc_loader_);
    GLL_LOADPROC(glBindVertexBuffer,                            proc_loader_);
    GLL_LOADPROC(glVertexAttribFormat,                          proc_loader_);
    GLL_LOADPROC(glVertexAttribIFormat,                         proc_loader_);
    GLL_LOADPROC(glVertexAttribLFormat,                         proc_loader_);
    GLL_LOADPROC(glVertexAttribBinding,                         proc_loader_);
    GLL_LOADPROC(glVertexBindingDivisor,                        proc_loader_);
    GLL_LOADPROC(glDebugMessageControl,                         proc_loader_);
    GLL_LOADPROC(glDebugMessageInsert,                          proc_loader_);
    GLL_LOADPROC(glDebugMessageCallback,                        proc_loader_);
    GLL_LOADPROC(glGetDebugMessageLog,                          proc_loader_);
    GLL_LOADPROC(glPushDebugGroup,                              proc_loader_);
    GLL_LOADPROC(glPopDebugGroup,                               proc_loader_);
    GLL_LOADPROC(glObjectLabel,                                 proc_loader_);
    GLL_LOADPROC(glGetObjectLabel,                              proc_loader_);
    GLL_LOADPROC(glObjectPtrLabel,                              proc_loader_);
    GLL_LOADPROC(glGetObjectPtrLabel,                           proc_loader_);
}

static GLL_INLINE void GLL__load_gl_version_440 (GLL_proc_loader proc_loader_, GLL_bool load_comp_)
{
    GLL_LOADPROC(glBufferStorage,                               proc_loader_);
    GLL_LOADPROC(glClearTexImage,                               proc_loader_);
    GLL_LOADPROC(glClearTexSubImage,                            proc_loader_);
    GLL_LOADPROC(glBindBuffersBase,                             proc_loader_);
    GLL_LOADPROC(glBindBuffersRange,                            proc_loader_);
    GLL_LOADPROC(glBindTextures,                                proc_loader_);
    GLL_LOADPROC(glBindSamplers,                                proc_loader_);
    GLL_LOADPROC(glBindImageTextures,                           proc_loader_);
    GLL_LOADPROC(glBindVertexBuffers,                           proc_loader_);
}

static GLL_INLINE void GLL__load_gl_version_450 (GLL_proc_loader proc_loader_, GLL_bool load_comp_)
{
    GLL_LOADPROC(glClipControl,                                 proc_loader_);
    GLL_LOADPROC(glCreateTransformFeedbacks,                    proc_loader_);
    GLL_LOADPROC(glTransformFeedbackBufferBase,                 proc_loader_);
    GLL_LOADPROC(glTransformFeedbackBufferRange,                proc_loader_);
    GLL_LOADPROC(glGetTransformFeedbackiv,                      proc_loader_);
    GLL_LOADPROC(glGetTransformFeedbacki_v,                     proc_loader_);
    GLL_LOADPROC(glGetTransformFeedbacki64_v,                   proc_loader_);
    GLL_LOADPROC(glCreateBuffers,                               proc_loader_);
    GLL_LOADPROC(glNamedBufferStorage,                          proc_loader_);
    GLL_LOADPROC(glNamedBufferData,                             proc_loader_);
    GLL_LOADPROC(glNamedBufferSubData,                          proc_loader_);
    GLL_LOADPROC(glCopyNamedBufferSubData,                      proc_loader_);
    GLL_LOADPROC(glClearNamedBufferData,                        proc_loader_);
    GLL_LOADPROC(glClearNamedBufferSubData,                     proc_loader_);
    GLL_LOADPROC(glMapNamedBuffer,                              proc_loader_);
    GLL_LOADPROC(glMapNamedBufferRange,                         proc_loader_);
    GLL_LOADPROC(glUnmapNamedBuffer,                            proc_loader_);
    GLL_LOADPROC(glFlushMappedNamedBufferRange,                 proc_loader_);
    GLL_LOADPROC(glGetNamedBufferParameteriv,                   proc_loader_);
    GLL_LOADPROC(glGetNamedBufferParameteri64v,                 proc_loader_);
    GLL_LOADPROC(glGetNamedBufferPointerv,                      proc_loader_);
    GLL_LOADPROC(glGetNamedBufferSubData,                       proc_loader_);
    GLL_LOADPROC(glCreateFramebuffers,                          proc_loader_);
    GLL_LOADPROC(glNamedFramebufferRenderbuffer,                proc_loader_);
    GLL_LOADPROC(glNamedFramebufferParameteri,                  proc_loader_);
    GLL_LOADPROC(glNamedFramebufferTexture,                     proc_loader_);
    GLL_LOADPROC(glNamedFramebufferTextureLayer,                proc_loader_);
    GLL_LOADPROC(glNamedFramebufferDrawBuffer,                  proc_loader_);
    GLL_LOADPROC(glNamedFramebufferDrawBuffers,                 proc_loader_);
    GLL_LOADPROC(glNamedFramebufferReadBuffer,                  proc_loader_);
    GLL_LOADPROC(glInvalidateNamedFramebufferData,              proc_loader_);
    GLL_LOADPROC(glInvalidateNamedFramebufferSubData,           proc_loader_);
    GLL_LOADPROC(glClearNamedFramebufferiv,                     proc_loader_);
    GLL_LOADPROC(glClearNamedFramebufferuiv,                    proc_loader_);
    GLL_LOADPROC(glClearNamedFramebufferfv,                     proc_loader_);
    GLL_LOADPROC(glClearNamedFramebufferfi,                     proc_loader_);
    GLL_LOADPROC(glBlitNamedFramebuffer,                        proc_loader_);
    GLL_LOADPROC(glCheckNamedFramebufferStatus,                 proc_loader_);
    GLL_LOADPROC(glGetNamedFramebufferParameteriv,              proc_loader_);
    GLL_LOADPROC(glGetNamedFramebufferAttachmentParameteriv,    proc_loader_);
    GLL_LOADPROC(glCreateRenderbuffers,                         proc_loader_);
    GLL_LOADPROC(glNamedRenderbufferStorage,                    proc_loader_);
    GLL_LOADPROC(glNamedRenderbufferStorageMultisample,         proc_loader_);
    GLL_LOADPROC(glGetNamedRenderbufferParameteriv,             proc_loader_);
    GLL_LOADPROC(glCreateTextures,                              proc_loader_);
    GLL_LOADPROC(glTextureBuffer,                               proc_loader_);
    GLL_LOADPROC(glTextureBufferRange,                          proc_loader_);
    GLL_LOADPROC(glTextureStorage1D,                            proc_loader_);
    GLL_LOADPROC(glTextureStorage2D,                            proc_loader_);
    GLL_LOADPROC(glTextureStorage3D,                            proc_loader_);
    GLL_LOADPROC(glTextureStorage2DMultisample,                 proc_loader_);
    GLL_LOADPROC(glTextureStorage3DMultisample,                 proc_loader_);
    GLL_LOADPROC(glTextureSubImage1D,                           proc_loader_);
    GLL_LOADPROC(glTextureSubImage2D,                           proc_loader_);
    GLL_LOADPROC(glTextureSubImage3D,                           proc_loader_);
    GLL_LOADPROC(glCompressedTextureSubImage1D,                 proc_loader_);
    GLL_LOADPROC(glCompressedTextureSubImage2D,                 proc_loader_);
    GLL_LOADPROC(glCompressedTextureSubImage3D,                 proc_loader_);
    GLL_LOADPROC(glCopyTextureSubImage1D,                       proc_loader_);
    GLL_LOADPROC(glCopyTextureSubImage2D,                       proc_loader_);
    GLL_LOADPROC(glCopyTextureSubImage3D,                       proc_loader_);
    GLL_LOADPROC(glTextureParameterf,                           proc_loader_);
    GLL_LOADPROC(glTextureParameterfv,                          proc_loader_);
    GLL_LOADPROC(glTextureParameteri,                           proc_loader_);
    GLL_LOADPROC(glTextureParameterIiv,                         proc_loader_);
    GLL_LOADPROC(glTextureParameterIuiv,                        proc_loader_);
    GLL_LOADPROC(glTextureParameteriv,                          proc_loader_);
    GLL_LOADPROC(glGenerateTextureMipmap,                       proc_loader_);
    GLL_LOADPROC(glBindTextureUnit,                             proc_loader_);
    GLL_LOADPROC(glGetTextureImage,                             proc_loader_);
    GLL_LOADPROC(glGetCompressedTextureImage,                   proc_loader_);
    GLL_LOADPROC(glGetTextureLevelParameterfv,                  proc_loader_);
    GLL_LOADPROC(glGetTextureLevelParameteriv,                  proc_loader_);
    GLL_LOADPROC(glGetTextureParameterfv,                       proc_loader_);
    GLL_LOADPROC(glGetTextureParameterIiv,                      proc_loader_);
    GLL_LOADPROC(glGetTextureParameterIuiv,                     proc_loader_);
    GLL_LOADPROC(glGetTextureParameteriv,                       proc_loader_);
    GLL_LOADPROC(glCreateVertexArrays,                          proc_loader_);
    GLL_LOADPROC(glDisableVertexArrayAttrib,                    proc_loader_);
    GLL_LOADPROC(glEnableVertexArrayAttrib,                     proc_loader_);
    GLL_LOADPROC(glVertexArrayElementBuffer,                    proc_loader_);
    GLL_LOADPROC(glVertexArrayVertexBuffer,                     proc_loader_);
    GLL_LOADPROC(glVertexArrayVertexBuffers,                    proc_loader_);
    GLL_LOADPROC(glVertexArrayAttribBinding,                    proc_loader_);
    GLL_LOADPROC(glVertexArrayAttribFormat,                     proc_loader_);
    GLL_LOADPROC(glVertexArrayAttribIFormat,                    proc_loader_);
    GLL_LOADPROC(glVertexArrayAttribLFormat,                    proc_loader_);
    GLL_LOADPROC(glVertexArrayBindingDivisor,                   proc_loader_);
    GLL_LOADPROC(glGetVertexArrayiv,                            proc_loader_);
    GLL_LOADPROC(glGetVertexArrayIndexediv,                     proc_loader_);
    GLL_LOADPROC(glGetVertexArrayIndexed64iv,                   proc_loader_);
    GLL_LOADPROC(glCreateSamplers,                              proc_loader_);
    GLL_LOADPROC(glCreateProgramPipelines,                      proc_loader_);
    GLL_LOADPROC(glCreateQueries,                               proc_loader_);
    GLL_LOADPROC(glGetQueryBufferObjecti64v,                    proc_loader_);
    GLL_LOADPROC(glGetQueryBufferObjectiv,                      proc_loader_);
    GLL_LOADPROC(glGetQueryBufferObjectui64v,                   proc_loader_);
    GLL_LOADPROC(glGetQueryBufferObjectuiv,                     proc_loader_);
    GLL_LOADPROC(glMemoryBarrierByRegion,                       proc_loader_);
    GLL_LOADPROC(glGetTextureSubImage,                          proc_loader_);
    GLL_LOADPROC(glGetCompressedTextureSubImage,                proc_loader_);
    GLL_LOADPROC(glGetGraphicsResetStatus,                      proc_loader_);
    GLL_LOADPROC(glGetnCompressedTexImage,                      proc_loader_);
    GLL_LOADPROC(glGetnTexImage,                                proc_loader_);
    GLL_LOADPROC(glGetnUniformdv,                               proc_loader_);
    GLL_LOADPROC(glGetnUniformfv,                               proc_loader_);
    GLL_LOADPROC(glGetnUniformiv,                               proc_loader_);
    GLL_LOADPROC(glGetnUniformuiv,                              proc_loader_);
    GLL_LOADPROC(glReadnPixels,                                 proc_loader_);
    GLL_LOADPROC(glTextureBarrier,                              proc_loader_);

    if (!load_comp_) return;

    GLL_LOADPROC(glGetnMapdv,                                   proc_loader_);
    GLL_LOADPROC(glGetnMapfv,                                   proc_loader_);
    GLL_LOADPROC(glGetnMapiv,                                   proc_loader_);
    GLL_LOADPROC(glGetnPixelMapfv,                              proc_loader_);
    GLL_LOADPROC(glGetnPixelMapuiv,                             proc_loader_);
    GLL_LOADPROC(glGetnPixelMapusv,                             proc_loader_);
    GLL_LOADPROC(glGetnPolygonStipple,                          proc_loader_);
    GLL_LOADPROC(glGetnColorTable,                              proc_loader_);
    GLL_LOADPROC(glGetnConvolutionFilter,                       proc_loader_);
    GLL_LOADPROC(glGetnSeparableFilter,                         proc_loader_);
    GLL_LOADPROC(glGetnHistogram,                               proc_loader_);
    GLL_LOADPROC(glGetnMinmax,                                  proc_loader_);
}

static GLL_INLINE void GLL__load_gl_version_460 (GLL_proc_loader proc_loader_, GLL_bool load_comp_)
{
    GLL_LOADPROC(glMultiDrawArraysIndirectCount,                proc_loader_);
    GLL_LOADPROC(glMultiDrawElementsIndirectCount,              proc_loader_);
    GLL_LOADPROC(glPolygonOffsetClamp,                          proc_loader_);
    GLL_LOADPROC(glSpecializeShader,                            proc_loader_);
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
 * v1.0.1  [15-11-2019]  Updated internal code formatting/style.
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
