/*******************************************************************************
 * Modified version of GL headers providing GL functionality and extensions.
 * Copyright (c) 2013-2018 The Khronos Group Inc.
 *
*******************************************************************************/

#ifndef GL_H__ /*/////////////////////////////////////////////////////////////*/
#define GL_H__

#ifdef COMPILER_HAS_PRAGMA_ONCE
#pragma once
#endif

/*////////////////////////////////////////////////////////////////////////////*/

/* -------------------------------------------------------------------------- */

EXTERN_C_START /***************************************************************/

/* -------------------------------------------------------------------------- */

typedef void             GLvoid;
typedef unsigned int     GLenum;
typedef khronos_float_t  GLfloat;
typedef int              GLint;
typedef int              GLsizei;
typedef unsigned int     GLbitfield;
typedef double           GLdouble;
typedef unsigned int     GLuint;
typedef unsigned char    GLboolean;
typedef khronos_uint8_t  GLubyte;
typedef khronos_float_t  GLclampf;
typedef double           GLclampd;
typedef khronos_ssize_t  GLsizeiptr;
typedef khronos_intptr_t GLintptr;
typedef char             GLchar;
typedef khronos_int16_t  GLshort;
typedef khronos_int8_t   GLbyte;
typedef khronos_uint16_t GLushort;
typedef khronos_uint16_t GLhalf;
typedef struct __GLsync* GLsync;
typedef khronos_uint64_t GLuint64;
typedef khronos_int64_t  GLint64;

typedef khronos_uint64_t GLuint64EXT;
typedef khronos_uint16_t GLhalfARB;
typedef khronos_ssize_t  GLsizeiptrARB;
typedef khronos_intptr_t GLintptrARB;
typedef khronos_int32_t  GLfixed;
typedef khronos_int64_t  GLint64EXT;
typedef char             GLcharARB;
typedef void*            GLeglImageOES;
typedef void*            GLeglClientBufferEXT;
typedef unsigned short   GLhalfNV;
typedef GLintptr         GLvdpauSurfaceNV;

struct _cl_context;
struct _cl_event;

typedef void (APIENTRYP GLDEBUGPROCARB)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);
typedef void (APIENTRYP GLDEBUGPROCAMD)(GLuint id, GLenum category, GLenum severity, GLsizei length, const GLchar *message, void *userParam);
typedef void (APIENTRYP GLVULKANPROCNV)(void);

#ifdef __APPLE__
typedef void* GLhandleARB;
#else
typedef unsigned int GLhandleARB;
#endif

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_LOAD_GL_VERSION_1_0

#ifndef GL_VERSION_1_0
#define GL_VERSION_1_0 1

#define GL_DEPTH_BUFFER_BIT                 0x00000100
#define GL_STENCIL_BUFFER_BIT               0x00000400
#define GL_COLOR_BUFFER_BIT                 0x00004000
#define GL_FALSE                            0
#define GL_TRUE                             1
#define GL_POINTS                           0x0000
#define GL_LINES                            0x0001
#define GL_LINE_LOOP                        0x0002
#define GL_LINE_STRIP                       0x0003
#define GL_TRIANGLES                        0x0004
#define GL_TRIANGLE_STRIP                   0x0005
#define GL_TRIANGLE_FAN                     0x0006
#define GL_QUADS                            0x0007
#define GL_NEVER                            0x0200
#define GL_LESS                             0x0201
#define GL_EQUAL                            0x0202
#define GL_LEQUAL                           0x0203
#define GL_GREATER                          0x0204
#define GL_NOTEQUAL                         0x0205
#define GL_GEQUAL                           0x0206
#define GL_ALWAYS                           0x0207
#define GL_ZERO                             0
#define GL_ONE                              1
#define GL_SRC_COLOR                        0x0300
#define GL_ONE_MINUS_SRC_COLOR              0x0301
#define GL_SRC_ALPHA                        0x0302
#define GL_ONE_MINUS_SRC_ALPHA              0x0303
#define GL_DST_ALPHA                        0x0304
#define GL_ONE_MINUS_DST_ALPHA              0x0305
#define GL_DST_COLOR                        0x0306
#define GL_ONE_MINUS_DST_COLOR              0x0307
#define GL_SRC_ALPHA_SATURATE               0x0308
#define GL_NONE                             0
#define GL_FRONT_LEFT                       0x0400
#define GL_FRONT_RIGHT                      0x0401
#define GL_BACK_LEFT                        0x0402
#define GL_BACK_RIGHT                       0x0403
#define GL_FRONT                            0x0404
#define GL_BACK                             0x0405
#define GL_LEFT                             0x0406
#define GL_RIGHT                            0x0407
#define GL_FRONT_AND_BACK                   0x0408
#define GL_NO_ERROR                         0
#define GL_INVALID_ENUM                     0x0500
#define GL_INVALID_VALUE                    0x0501
#define GL_INVALID_OPERATION                0x0502
#define GL_OUT_OF_MEMORY                    0x0505
#define GL_CW                               0x0900
#define GL_CCW                              0x0901
#define GL_POINT_SIZE                       0x0B11
#define GL_POINT_SIZE_RANGE                 0x0B12
#define GL_POINT_SIZE_GRANULARITY           0x0B13
#define GL_LINE_SMOOTH                      0x0B20
#define GL_LINE_WIDTH                       0x0B21
#define GL_LINE_WIDTH_RANGE                 0x0B22
#define GL_LINE_WIDTH_GRANULARITY           0x0B23
#define GL_POLYGON_MODE                     0x0B40
#define GL_POLYGON_SMOOTH                   0x0B41
#define GL_CULL_FACE                        0x0B44
#define GL_CULL_FACE_MODE                   0x0B45
#define GL_FRONT_FACE                       0x0B46
#define GL_DEPTH_RANGE                      0x0B70
#define GL_DEPTH_TEST                       0x0B71
#define GL_DEPTH_WRITEMASK                  0x0B72
#define GL_DEPTH_CLEAR_VALUE                0x0B73
#define GL_DEPTH_FUNC                       0x0B74
#define GL_STENCIL_TEST                     0x0B90
#define GL_STENCIL_CLEAR_VALUE              0x0B91
#define GL_STENCIL_FUNC                     0x0B92
#define GL_STENCIL_VALUE_MASK               0x0B93
#define GL_STENCIL_FAIL                     0x0B94
#define GL_STENCIL_PASS_DEPTH_FAIL          0x0B95
#define GL_STENCIL_PASS_DEPTH_PASS          0x0B96
#define GL_STENCIL_REF                      0x0B97
#define GL_STENCIL_WRITEMASK                0x0B98
#define GL_VIEWPORT                         0x0BA2
#define GL_DITHER                           0x0BD0
#define GL_BLEND_DST                        0x0BE0
#define GL_BLEND_SRC                        0x0BE1
#define GL_BLEND                            0x0BE2
#define GL_LOGIC_OP_MODE                    0x0BF0
#define GL_DRAW_BUFFER                      0x0C01
#define GL_READ_BUFFER                      0x0C02
#define GL_SCISSOR_BOX                      0x0C10
#define GL_SCISSOR_TEST                     0x0C11
#define GL_COLOR_CLEAR_VALUE                0x0C22
#define GL_COLOR_WRITEMASK                  0x0C23
#define GL_DOUBLEBUFFER                     0x0C32
#define GL_STEREO                           0x0C33
#define GL_LINE_SMOOTH_HINT                 0x0C52
#define GL_POLYGON_SMOOTH_HINT              0x0C53
#define GL_UNPACK_SWAP_BYTES                0x0CF0
#define GL_UNPACK_LSB_FIRST                 0x0CF1
#define GL_UNPACK_ROW_LENGTH                0x0CF2
#define GL_UNPACK_SKIP_ROWS                 0x0CF3
#define GL_UNPACK_SKIP_PIXELS               0x0CF4
#define GL_UNPACK_ALIGNMENT                 0x0CF5
#define GL_PACK_SWAP_BYTES                  0x0D00
#define GL_PACK_LSB_FIRST                   0x0D01
#define GL_PACK_ROW_LENGTH                  0x0D02
#define GL_PACK_SKIP_ROWS                   0x0D03
#define GL_PACK_SKIP_PIXELS                 0x0D04
#define GL_PACK_ALIGNMENT                   0x0D05
#define GL_MAX_TEXTURE_SIZE                 0x0D33
#define GL_MAX_VIEWPORT_DIMS                0x0D3A
#define GL_SUBPIXEL_BITS                    0x0D50
#define GL_TEXTURE_1D                       0x0DE0
#define GL_TEXTURE_2D                       0x0DE1
#define GL_TEXTURE_WIDTH                    0x1000
#define GL_TEXTURE_HEIGHT                   0x1001
#define GL_TEXTURE_BORDER_COLOR             0x1004
#define GL_DONT_CARE                        0x1100
#define GL_FASTEST                          0x1101
#define GL_NICEST                           0x1102
#define GL_BYTE                             0x1400
#define GL_UNSIGNED_BYTE                    0x1401
#define GL_SHORT                            0x1402
#define GL_UNSIGNED_SHORT                   0x1403
#define GL_INT                              0x1404
#define GL_UNSIGNED_INT                     0x1405
#define GL_FLOAT                            0x1406
#define GL_STACK_OVERFLOW                   0x0503
#define GL_STACK_UNDERFLOW                  0x0504
#define GL_CLEAR                            0x1500
#define GL_AND                              0x1501
#define GL_AND_REVERSE                      0x1502
#define GL_COPY                             0x1503
#define GL_AND_INVERTED                     0x1504
#define GL_NOOP                             0x1505
#define GL_XOR                              0x1506
#define GL_OR                               0x1507
#define GL_NOR                              0x1508
#define GL_EQUIV                            0x1509
#define GL_INVERT                           0x150A
#define GL_OR_REVERSE                       0x150B
#define GL_COPY_INVERTED                    0x150C
#define GL_OR_INVERTED                      0x150D
#define GL_NAND                             0x150E
#define GL_SET                              0x150F
#define GL_TEXTURE                          0x1702
#define GL_COLOR                            0x1800
#define GL_DEPTH                            0x1801
#define GL_STENCIL                          0x1802
#define GL_STENCIL_INDEX                    0x1901
#define GL_DEPTH_COMPONENT                  0x1902
#define GL_RED                              0x1903
#define GL_GREEN                            0x1904
#define GL_BLUE                             0x1905
#define GL_ALPHA                            0x1906
#define GL_RGB                              0x1907
#define GL_RGBA                             0x1908
#define GL_POINT                            0x1B00
#define GL_LINE                             0x1B01
#define GL_FILL                             0x1B02
#define GL_KEEP                             0x1E00
#define GL_REPLACE                          0x1E01
#define GL_INCR                             0x1E02
#define GL_DECR                             0x1E03
#define GL_VENDOR                           0x1F00
#define GL_RENDERER                         0x1F01
#define GL_VERSION                          0x1F02
#define GL_EXTENSIONS                       0x1F03
#define GL_NEAREST                          0x2600
#define GL_LINEAR                           0x2601
#define GL_NEAREST_MIPMAP_NEAREST           0x2700
#define GL_LINEAR_MIPMAP_NEAREST            0x2701
#define GL_NEAREST_MIPMAP_LINEAR            0x2702
#define GL_LINEAR_MIPMAP_LINEAR             0x2703
#define GL_TEXTURE_MAG_FILTER               0x2800
#define GL_TEXTURE_MIN_FILTER               0x2801
#define GL_TEXTURE_WRAP_S                   0x2802
#define GL_TEXTURE_WRAP_T                   0x2803
#define GL_REPEAT                           0x2901
#define GL_CURRENT_BIT                      0x00000001
#define GL_POINT_BIT                        0x00000002
#define GL_LINE_BIT                         0x00000004
#define GL_POLYGON_BIT                      0x00000008
#define GL_POLYGON_STIPPLE_BIT              0x00000010
#define GL_PIXEL_MODE_BIT                   0x00000020
#define GL_LIGHTING_BIT                     0x00000040
#define GL_FOG_BIT                          0x00000080
#define GL_ACCUM_BUFFER_BIT                 0x00000200
#define GL_VIEWPORT_BIT                     0x00000800
#define GL_TRANSFORM_BIT                    0x00001000
#define GL_ENABLE_BIT                       0x00002000
#define GL_HINT_BIT                         0x00008000
#define GL_EVAL_BIT                         0x00010000
#define GL_LIST_BIT                         0x00020000
#define GL_TEXTURE_BIT                      0x00040000
#define GL_SCISSOR_BIT                      0x00080000
#define GL_ALL_ATTRIB_BITS                  0xFFFFFFFF
#define GL_QUAD_STRIP                       0x0008
#define GL_POLYGON                          0x0009
#define GL_ACCUM                            0x0100
#define GL_LOAD                             0x0101
#define GL_RETURN                           0x0102
#define GL_MULT                             0x0103
#define GL_ADD                              0x0104
#define GL_AUX0                             0x0409
#define GL_AUX1                             0x040A
#define GL_AUX2                             0x040B
#define GL_AUX3                             0x040C
#define GL_2D                               0x0600
#define GL_3D                               0x0601
#define GL_3D_COLOR                         0x0602
#define GL_3D_COLOR_TEXTURE                 0x0603
#define GL_4D_COLOR_TEXTURE                 0x0604
#define GL_PASS_THROUGH_TOKEN               0x0700
#define GL_POINT_TOKEN                      0x0701
#define GL_LINE_TOKEN                       0x0702
#define GL_POLYGON_TOKEN                    0x0703
#define GL_BITMAP_TOKEN                     0x0704
#define GL_DRAW_PIXEL_TOKEN                 0x0705
#define GL_COPY_PIXEL_TOKEN                 0x0706
#define GL_LINE_RESET_TOKEN                 0x0707
#define GL_EXP                              0x0800
#define GL_EXP2                             0x0801
#define GL_COEFF                            0x0A00
#define GL_ORDER                            0x0A01
#define GL_DOMAIN                           0x0A02
#define GL_PIXEL_MAP_I_TO_I                 0x0C70
#define GL_PIXEL_MAP_S_TO_S                 0x0C71
#define GL_PIXEL_MAP_I_TO_R                 0x0C72
#define GL_PIXEL_MAP_I_TO_G                 0x0C73
#define GL_PIXEL_MAP_I_TO_B                 0x0C74
#define GL_PIXEL_MAP_I_TO_A                 0x0C75
#define GL_PIXEL_MAP_R_TO_R                 0x0C76
#define GL_PIXEL_MAP_G_TO_G                 0x0C77
#define GL_PIXEL_MAP_B_TO_B                 0x0C78
#define GL_PIXEL_MAP_A_TO_A                 0x0C79
#define GL_CURRENT_COLOR                    0x0B00
#define GL_CURRENT_INDEX                    0x0B01
#define GL_CURRENT_NORMAL                   0x0B02
#define GL_CURRENT_TEXTURE_COORDS           0x0B03
#define GL_CURRENT_RASTER_COLOR             0x0B04
#define GL_CURRENT_RASTER_INDEX             0x0B05
#define GL_CURRENT_RASTER_TEXTURE_COORDS    0x0B06
#define GL_CURRENT_RASTER_POSITION          0x0B07
#define GL_CURRENT_RASTER_POSITION_VALID    0x0B08
#define GL_CURRENT_RASTER_DISTANCE          0x0B09
#define GL_POINT_SMOOTH                     0x0B10
#define GL_LINE_STIPPLE                     0x0B24
#define GL_LINE_STIPPLE_PATTERN             0x0B25
#define GL_LINE_STIPPLE_REPEAT              0x0B26
#define GL_LIST_MODE                        0x0B30
#define GL_MAX_LIST_NESTING                 0x0B31
#define GL_LIST_BASE                        0x0B32
#define GL_LIST_INDEX                       0x0B33
#define GL_POLYGON_STIPPLE                  0x0B42
#define GL_EDGE_FLAG                        0x0B43
#define GL_LIGHTING                         0x0B50
#define GL_LIGHT_MODEL_LOCAL_VIEWER         0x0B51
#define GL_LIGHT_MODEL_TWO_SIDE             0x0B52
#define GL_LIGHT_MODEL_AMBIENT              0x0B53
#define GL_SHADE_MODEL                      0x0B54
#define GL_COLOR_MATERIAL_FACE              0x0B55
#define GL_COLOR_MATERIAL_PARAMETER         0x0B56
#define GL_COLOR_MATERIAL                   0x0B57
#define GL_FOG                              0x0B60
#define GL_FOG_INDEX                        0x0B61
#define GL_FOG_DENSITY                      0x0B62
#define GL_FOG_START                        0x0B63
#define GL_FOG_END                          0x0B64
#define GL_FOG_MODE                         0x0B65
#define GL_FOG_COLOR                        0x0B66
#define GL_ACCUM_CLEAR_VALUE                0x0B80
#define GL_MATRIX_MODE                      0x0BA0
#define GL_NORMALIZE                        0x0BA1
#define GL_MODELVIEW_STACK_DEPTH            0x0BA3
#define GL_PROJECTION_STACK_DEPTH           0x0BA4
#define GL_TEXTURE_STACK_DEPTH              0x0BA5
#define GL_MODELVIEW_MATRIX                 0x0BA6
#define GL_PROJECTION_MATRIX                0x0BA7
#define GL_TEXTURE_MATRIX                   0x0BA8
#define GL_ATTRIB_STACK_DEPTH               0x0BB0
#define GL_ALPHA_TEST                       0x0BC0
#define GL_ALPHA_TEST_FUNC                  0x0BC1
#define GL_ALPHA_TEST_REF                   0x0BC2
#define GL_LOGIC_OP                         0x0BF1
#define GL_AUX_BUFFERS                      0x0C00
#define GL_INDEX_CLEAR_VALUE                0x0C20
#define GL_INDEX_WRITEMASK                  0x0C21
#define GL_INDEX_MODE                       0x0C30
#define GL_RGBA_MODE                        0x0C31
#define GL_RENDER_MODE                      0x0C40
#define GL_PERSPECTIVE_CORRECTION_HINT      0x0C50
#define GL_POINT_SMOOTH_HINT                0x0C51
#define GL_FOG_HINT                         0x0C54
#define GL_TEXTURE_GEN_S                    0x0C60
#define GL_TEXTURE_GEN_T                    0x0C61
#define GL_TEXTURE_GEN_R                    0x0C62
#define GL_TEXTURE_GEN_Q                    0x0C63
#define GL_PIXEL_MAP_I_TO_I_SIZE            0x0CB0
#define GL_PIXEL_MAP_S_TO_S_SIZE            0x0CB1
#define GL_PIXEL_MAP_I_TO_R_SIZE            0x0CB2
#define GL_PIXEL_MAP_I_TO_G_SIZE            0x0CB3
#define GL_PIXEL_MAP_I_TO_B_SIZE            0x0CB4
#define GL_PIXEL_MAP_I_TO_A_SIZE            0x0CB5
#define GL_PIXEL_MAP_R_TO_R_SIZE            0x0CB6
#define GL_PIXEL_MAP_G_TO_G_SIZE            0x0CB7
#define GL_PIXEL_MAP_B_TO_B_SIZE            0x0CB8
#define GL_PIXEL_MAP_A_TO_A_SIZE            0x0CB9
#define GL_MAP_COLOR                        0x0D10
#define GL_MAP_STENCIL                      0x0D11
#define GL_INDEX_SHIFT                      0x0D12
#define GL_INDEX_OFFSET                     0x0D13
#define GL_RED_SCALE                        0x0D14
#define GL_RED_BIAS                         0x0D15
#define GL_ZOOM_X                           0x0D16
#define GL_ZOOM_Y                           0x0D17
#define GL_GREEN_SCALE                      0x0D18
#define GL_GREEN_BIAS                       0x0D19
#define GL_BLUE_SCALE                       0x0D1A
#define GL_BLUE_BIAS                        0x0D1B
#define GL_ALPHA_SCALE                      0x0D1C
#define GL_ALPHA_BIAS                       0x0D1D
#define GL_DEPTH_SCALE                      0x0D1E
#define GL_DEPTH_BIAS                       0x0D1F
#define GL_MAX_EVAL_ORDER                   0x0D30
#define GL_MAX_LIGHTS                       0x0D31
#define GL_MAX_CLIP_PLANES                  0x0D32
#define GL_MAX_PIXEL_MAP_TABLE              0x0D34
#define GL_MAX_ATTRIB_STACK_DEPTH           0x0D35
#define GL_MAX_MODELVIEW_STACK_DEPTH        0x0D36
#define GL_MAX_NAME_STACK_DEPTH             0x0D37
#define GL_MAX_PROJECTION_STACK_DEPTH       0x0D38
#define GL_MAX_TEXTURE_STACK_DEPTH          0x0D39
#define GL_INDEX_BITS                       0x0D51
#define GL_RED_BITS                         0x0D52
#define GL_GREEN_BITS                       0x0D53
#define GL_BLUE_BITS                        0x0D54
#define GL_ALPHA_BITS                       0x0D55
#define GL_DEPTH_BITS                       0x0D56
#define GL_STENCIL_BITS                     0x0D57
#define GL_ACCUM_RED_BITS                   0x0D58
#define GL_ACCUM_GREEN_BITS                 0x0D59
#define GL_ACCUM_BLUE_BITS                  0x0D5A
#define GL_ACCUM_ALPHA_BITS                 0x0D5B
#define GL_NAME_STACK_DEPTH                 0x0D70
#define GL_AUTO_NORMAL                      0x0D80
#define GL_MAP1_COLOR_4                     0x0D90
#define GL_MAP1_INDEX                       0x0D91
#define GL_MAP1_NORMAL                      0x0D92
#define GL_MAP1_TEXTURE_COORD_1             0x0D93
#define GL_MAP1_TEXTURE_COORD_2             0x0D94
#define GL_MAP1_TEXTURE_COORD_3             0x0D95
#define GL_MAP1_TEXTURE_COORD_4             0x0D96
#define GL_MAP1_VERTEX_3                    0x0D97
#define GL_MAP1_VERTEX_4                    0x0D98
#define GL_MAP2_COLOR_4                     0x0DB0
#define GL_MAP2_INDEX                       0x0DB1
#define GL_MAP2_NORMAL                      0x0DB2
#define GL_MAP2_TEXTURE_COORD_1             0x0DB3
#define GL_MAP2_TEXTURE_COORD_2             0x0DB4
#define GL_MAP2_TEXTURE_COORD_3             0x0DB5
#define GL_MAP2_TEXTURE_COORD_4             0x0DB6
#define GL_MAP2_VERTEX_3                    0x0DB7
#define GL_MAP2_VERTEX_4                    0x0DB8
#define GL_MAP1_GRID_DOMAIN                 0x0DD0
#define GL_MAP1_GRID_SEGMENTS               0x0DD1
#define GL_MAP2_GRID_DOMAIN                 0x0DD2
#define GL_MAP2_GRID_SEGMENTS               0x0DD3
#define GL_TEXTURE_COMPONENTS               0x1003
#define GL_TEXTURE_BORDER                   0x1005
#define GL_AMBIENT                          0x1200
#define GL_DIFFUSE                          0x1201
#define GL_SPECULAR                         0x1202
#define GL_POSITION                         0x1203
#define GL_SPOT_DIRECTION                   0x1204
#define GL_SPOT_EXPONENT                    0x1205
#define GL_SPOT_CUTOFF                      0x1206
#define GL_CONSTANT_ATTENUATION             0x1207
#define GL_LINEAR_ATTENUATION               0x1208
#define GL_QUADRATIC_ATTENUATION            0x1209
#define GL_COMPILE                          0x1300
#define GL_COMPILE_AND_EXECUTE              0x1301
#define GL_2_BYTES                          0x1407
#define GL_3_BYTES                          0x1408
#define GL_4_BYTES                          0x1409
#define GL_EMISSION                         0x1600
#define GL_SHININESS                        0x1601
#define GL_AMBIENT_AND_DIFFUSE              0x1602
#define GL_COLOR_INDEXES                    0x1603
#define GL_MODELVIEW                        0x1700
#define GL_PROJECTION                       0x1701
#define GL_COLOR_INDEX                      0x1900
#define GL_LUMINANCE                        0x1909
#define GL_LUMINANCE_ALPHA                  0x190A
#define GL_BITMAP                           0x1A00
#define GL_RENDER                           0x1C00
#define GL_FEEDBACK                         0x1C01
#define GL_SELECT                           0x1C02
#define GL_FLAT                             0x1D00
#define GL_SMOOTH                           0x1D01
#define GL_S                                0x2000
#define GL_T                                0x2001
#define GL_R                                0x2002
#define GL_Q                                0x2003
#define GL_MODULATE                         0x2100
#define GL_DECAL                            0x2101
#define GL_TEXTURE_ENV_MODE                 0x2200
#define GL_TEXTURE_ENV_COLOR                0x2201
#define GL_TEXTURE_ENV                      0x2300
#define GL_EYE_LINEAR                       0x2400
#define GL_OBJECT_LINEAR                    0x2401
#define GL_SPHERE_MAP                       0x2402
#define GL_TEXTURE_GEN_MODE                 0x2500
#define GL_OBJECT_PLANE                     0x2501
#define GL_EYE_PLANE                        0x2502
#define GL_CLAMP                            0x2900
#define GL_CLIP_PLANE0                      0x3000
#define GL_CLIP_PLANE1                      0x3001
#define GL_CLIP_PLANE2                      0x3002
#define GL_CLIP_PLANE3                      0x3003
#define GL_CLIP_PLANE4                      0x3004
#define GL_CLIP_PLANE5                      0x3005
#define GL_LIGHT0                           0x4000
#define GL_LIGHT1                           0x4001
#define GL_LIGHT2                           0x4002
#define GL_LIGHT3                           0x4003
#define GL_LIGHT4                           0x4004
#define GL_LIGHT5                           0x4005
#define GL_LIGHT6                           0x4006
#define GL_LIGHT7                           0x4007

OPENGL_INIT_PROC(glCullFace,               void,           GLenum mode);
OPENGL_INIT_PROC(glFrontFace,              void,           GLenum mode);
OPENGL_INIT_PROC(glHint,                   void,           GLenum target, GLenum mode);
OPENGL_INIT_PROC(glLineWidth,              void,           GLfloat width);
OPENGL_INIT_PROC(glPointSize,              void,           GLfloat size);
OPENGL_INIT_PROC(glPolygonMode,            void,           GLenum face, GLenum mode);
OPENGL_INIT_PROC(glScissor,                void,           GLint x, GLint y, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glTexParameterf,          void,           GLenum target, GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glTexParameterfv,         void,           GLenum target, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glTexParameteri,          void,           GLenum target, GLenum pname, GLint param);
OPENGL_INIT_PROC(glTexParameteriv,         void,           GLenum target, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glTexImage1D,             void,           GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
OPENGL_INIT_PROC(glTexImage2D,             void,           GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
OPENGL_INIT_PROC(glDrawBuffer,             void,           GLenum buf);
OPENGL_INIT_PROC(glClear,                  void,           GLbitfield mask);
OPENGL_INIT_PROC(glClearColor,             void,           GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
OPENGL_INIT_PROC(glClearStencil,           void,           GLint s);
OPENGL_INIT_PROC(glClearDepth,             void,           GLdouble depth);
OPENGL_INIT_PROC(glStencilMask,            void,           GLuint mask);
OPENGL_INIT_PROC(glColorMask,              void,           GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
OPENGL_INIT_PROC(glDepthMask,              void,           GLboolean flag);
OPENGL_INIT_PROC(glDisable,                void,           GLenum cap);
OPENGL_INIT_PROC(glEnable,                 void,           GLenum cap);
OPENGL_INIT_PROC(glFinish,                 void,           void);
OPENGL_INIT_PROC(glFlush,                  void,           void);
OPENGL_INIT_PROC(glBlendFunc,              void,           GLenum sfactor, GLenum dfactor);
OPENGL_INIT_PROC(glLogicOp,                void,           GLenum opcode);
OPENGL_INIT_PROC(glStencilFunc,            void,           GLenum func, GLint ref, GLuint mask);
OPENGL_INIT_PROC(glStencilOp,              void,           GLenum fail, GLenum zfail, GLenum zpass);
OPENGL_INIT_PROC(glDepthFunc,              void,           GLenum func);
OPENGL_INIT_PROC(glPixelStoref,            void,           GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glPixelStorei,            void,           GLenum pname, GLint param);
OPENGL_INIT_PROC(glReadBuffer,             void,           GLenum src);
OPENGL_INIT_PROC(glReadPixels,             void,           GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
OPENGL_INIT_PROC(glGetBooleanv,            void,           GLenum pname, GLboolean *data);
OPENGL_INIT_PROC(glGetDoublev,             void,           GLenum pname, GLdouble *data);
OPENGL_INIT_PROC(glGetError,               GLenum,         void);
OPENGL_INIT_PROC(glGetFloatv,              void,           GLenum pname, GLfloat *data);
OPENGL_INIT_PROC(glGetIntegerv,            void,           GLenum pname, GLint *data);
OPENGL_INIT_PROC(glGetString,              const GLubyte*, GLenum name);
OPENGL_INIT_PROC(glGetTexImage,            void,           GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
OPENGL_INIT_PROC(glGetTexParameterfv,      void,           GLenum target, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetTexParameteriv,      void,           GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetTexLevelParameterfv, void,           GLenum target, GLint level, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetTexLevelParameteriv, void,           GLenum target, GLint level, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glIsEnabled,              GLboolean,      GLenum cap);
OPENGL_INIT_PROC(glDepthRange,             void,           GLdouble n, GLdouble f);
OPENGL_INIT_PROC(glViewport,               void,           GLint x, GLint y, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glNewList,                void,           GLuint list, GLenum mode);
#ifdef OPENGL_USE_COMPATIBILITY_PROFILE
OPENGL_INIT_PROC(glEndList,                void,           void);
OPENGL_INIT_PROC(glCallList,               void,           GLuint list);
OPENGL_INIT_PROC(glCallLists,              void,           GLsizei n, GLenum type, const void *lists);
OPENGL_INIT_PROC(glDeleteLists,            void,           GLuint list, GLsizei range);
OPENGL_INIT_PROC(glGenLists,               GLuint,         GLsizei range);
OPENGL_INIT_PROC(glListBase,               void,           GLuint base);
OPENGL_INIT_PROC(glBegin,                  void,           GLenum mode);
OPENGL_INIT_PROC(glBitmap,                 void,           GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
OPENGL_INIT_PROC(glColor3b,                void,           GLbyte red, GLbyte green, GLbyte blue);
OPENGL_INIT_PROC(glColor3bv,               void,           const GLbyte *v);
OPENGL_INIT_PROC(glColor3d,                void,           GLdouble red, GLdouble green, GLdouble blue);
OPENGL_INIT_PROC(glColor3dv,               void,           const GLdouble *v);
OPENGL_INIT_PROC(glColor3f,                void,           GLfloat red, GLfloat green, GLfloat blue);
OPENGL_INIT_PROC(glColor3fv,               void,           const GLfloat *v);
OPENGL_INIT_PROC(glColor3i,                void,           GLint red, GLint green, GLint blue);
OPENGL_INIT_PROC(glColor3iv,               void,           const GLint *v);
OPENGL_INIT_PROC(glColor3s,                void,           GLshort red, GLshort green, GLshort blue);
OPENGL_INIT_PROC(glColor3sv,               void,           const GLshort *v);
OPENGL_INIT_PROC(glColor3ub,               void,           GLubyte red, GLubyte green, GLubyte blue);
OPENGL_INIT_PROC(glColor3ubv,              void,           const GLubyte *v);
OPENGL_INIT_PROC(glColor3ui,               void,           GLuint red, GLuint green, GLuint blue);
OPENGL_INIT_PROC(glColor3uiv,              void,           const GLuint *v);
OPENGL_INIT_PROC(glColor3us,               void,           GLushort red, GLushort green, GLushort blue);
OPENGL_INIT_PROC(glColor3usv,              void,           const GLushort *v);
OPENGL_INIT_PROC(glColor4b,                void,           GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
OPENGL_INIT_PROC(glColor4bv,               void,           const GLbyte *v);
OPENGL_INIT_PROC(glColor4d,                void,           GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
OPENGL_INIT_PROC(glColor4dv,               void,           const GLdouble *v);
OPENGL_INIT_PROC(glColor4f,                void,           GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
OPENGL_INIT_PROC(glColor4fv,               void,           const GLfloat *v);
OPENGL_INIT_PROC(glColor4i,                void,           GLint red, GLint green, GLint blue, GLint alpha);
OPENGL_INIT_PROC(glColor4iv,               void,           const GLint *v);
OPENGL_INIT_PROC(glColor4s,                void,           GLshort red, GLshort green, GLshort blue, GLshort alpha);
OPENGL_INIT_PROC(glColor4sv,               void,           const GLshort *v);
OPENGL_INIT_PROC(glColor4ub,               void,           GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
OPENGL_INIT_PROC(glColor4ubv,              void,           const GLubyte *v);
OPENGL_INIT_PROC(glColor4ui,               void,           GLuint red, GLuint green, GLuint blue, GLuint alpha);
OPENGL_INIT_PROC(glColor4uiv,              void,           const GLuint *v);
OPENGL_INIT_PROC(glColor4us,               void,           GLushort red, GLushort green, GLushort blue, GLushort alpha);
OPENGL_INIT_PROC(glColor4usv,              void,           const GLushort *v);
OPENGL_INIT_PROC(glEdgeFlag,               void,           GLboolean flag);
OPENGL_INIT_PROC(glEdgeFlagv,              void,           const GLboolean *flag);
OPENGL_INIT_PROC(glEnd,                    void,           void);
OPENGL_INIT_PROC(glIndexd,                 void,           GLdouble c);
OPENGL_INIT_PROC(glIndexdv,                void,           const GLdouble *c);
OPENGL_INIT_PROC(glIndexf,                 void,           GLfloat c);
OPENGL_INIT_PROC(glIndexfv,                void,           const GLfloat *c);
OPENGL_INIT_PROC(glIndexi,                 void,           GLint c);
OPENGL_INIT_PROC(glIndexiv,                void,           const GLint *c);
OPENGL_INIT_PROC(glIndexs,                 void,           GLshort c);
OPENGL_INIT_PROC(glIndexsv,                void,           const GLshort *c);
OPENGL_INIT_PROC(glNormal3b,               void,           GLbyte nx, GLbyte ny, GLbyte nz);
OPENGL_INIT_PROC(glNormal3bv,              void,           const GLbyte *v);
OPENGL_INIT_PROC(glNormal3d,               void,           GLdouble nx, GLdouble ny, GLdouble nz);
OPENGL_INIT_PROC(glNormal3dv,              void,           const GLdouble *v);
OPENGL_INIT_PROC(glNormal3f,               void,           GLfloat nx, GLfloat ny, GLfloat nz);
OPENGL_INIT_PROC(glNormal3fv,              void,           const GLfloat *v);
OPENGL_INIT_PROC(glNormal3i,               void,           GLint nx, GLint ny, GLint nz);
OPENGL_INIT_PROC(glNormal3uv,              void,           const GLint *v);
OPENGL_INIT_PROC(glNormal3s,               void,           GLshort nx, GLshort ny, GLshort nz);
OPENGL_INIT_PROC(glNormal3sv,              void,           const GLshort *v);
OPENGL_INIT_PROC(glRasterPos2d,            void,           GLdouble x, GLdouble y);
OPENGL_INIT_PROC(glRasterPos2dv,           void,           const GLdouble *v);
OPENGL_INIT_PROC(glRasterPos2f,            void,           GLfloat x, GLfloat y);
OPENGL_INIT_PROC(glRasterPos2fv,           void,           const GLfloat *v);
OPENGL_INIT_PROC(glRasterPos2i,            void,           GLint x, GLint y);
OPENGL_INIT_PROC(glRasterPos2iv,           void,           const GLint *v);
OPENGL_INIT_PROC(glRasterPos2s,            void,           GLshort x, GLshort y);
OPENGL_INIT_PROC(glRasterPos2sv,           void,           const GLshort *v);
OPENGL_INIT_PROC(glRasterPos3d,            void,           GLdouble x, GLdouble y, GLdouble z);
OPENGL_INIT_PROC(glRasterPos3dv,           void,           const GLdouble *v);
OPENGL_INIT_PROC(glRasterPos3f,            void,           GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glRasterPos3fv,           void,           const GLfloat *v);
OPENGL_INIT_PROC(glRasterPos3i,            void,           GLint x, GLint y, GLint z);
OPENGL_INIT_PROC(glRasterPos3iv,           void,           const GLint *v);
OPENGL_INIT_PROC(glRasterPos3s,            void,           GLshort x, GLshort y, GLshort z);
OPENGL_INIT_PROC(glRasterPos3sv,           void,           const GLshort *v);
OPENGL_INIT_PROC(glRasterPos4d,            void,           GLdouble x, GLdouble y, GLdouble z, GLdouble w);
OPENGL_INIT_PROC(glRasterPos4dv,           void,           const GLdouble *v);
OPENGL_INIT_PROC(glRasterPos4f,            void,           GLfloat x, GLfloat y, GLfloat z, GLfloat w);
OPENGL_INIT_PROC(glRasterPos4fv,           void,           const GLfloat *v);
OPENGL_INIT_PROC(glRasterPos4i,            void,           GLint x, GLint y, GLint z, GLint w);
OPENGL_INIT_PROC(glRasterPos4iv,           void,           const GLint *v);
OPENGL_INIT_PROC(glRasterPos4s,            void,           GLshort x, GLshort y, GLshort z, GLshort w);
OPENGL_INIT_PROC(glRasterPos4sv,           void,           const GLshort *v);
OPENGL_INIT_PROC(glRectd,                  void,           GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
OPENGL_INIT_PROC(glRectdv,                 void,           const GLdouble *v1, const GLdouble *v2);
OPENGL_INIT_PROC(glRectf,                  void,           GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
OPENGL_INIT_PROC(glRectfv,                 void,           const GLfloat *v1, const GLfloat *v2);
OPENGL_INIT_PROC(glRecti,                  void,           GLint x1, GLint y1, GLint x2, GLint y2);
OPENGL_INIT_PROC(glRectiv,                 void,           const GLint *v1, const GLint *v2);
OPENGL_INIT_PROC(glRects,                  void,           GLshort x1, GLshort y1, GLshort x2, GLshort y2);
OPENGL_INIT_PROC(glRectsv,                 void,           const GLshort *v1, const GLshort *v2);
OPENGL_INIT_PROC(glTexCoord1d,             void,           GLdouble s);
OPENGL_INIT_PROC(glTexCoord1dv,            void,           const GLdouble *v);
OPENGL_INIT_PROC(glTexCoord1f,             void,           GLfloat s);
OPENGL_INIT_PROC(glTexCoord1fv,            void,           const GLfloat *v);
OPENGL_INIT_PROC(glTexCoord1i,             void,           GLint s);
OPENGL_INIT_PROC(glTexCoord1iv,            void,           const GLint *v);
OPENGL_INIT_PROC(glTexCoord1s,             void,           GLshort s);
OPENGL_INIT_PROC(glTexCoord1sv,            void,           const GLshort *v);
OPENGL_INIT_PROC(glTexCoord2d,             void,           GLdouble s, GLdouble t);
OPENGL_INIT_PROC(glTexCoord2dv,            void,           const GLdouble *v);
OPENGL_INIT_PROC(glTexCoord2f,             void,           GLfloat s, GLfloat t);
OPENGL_INIT_PROC(glTexCoord2fv,            void,           const GLfloat *v);
OPENGL_INIT_PROC(glTexCoord2i,             void,           GLint s, GLint t);
OPENGL_INIT_PROC(glTexCoord2iv,            void,           const GLint *v);
OPENGL_INIT_PROC(glTexCoord2s,             void,           GLshort s, GLshort t);
OPENGL_INIT_PROC(glTexCoord2sv,            void,           const GLshort *v);
OPENGL_INIT_PROC(glTexCoord3d,             void,           GLdouble s, GLdouble t, GLdouble r);
OPENGL_INIT_PROC(glTexCoord3dv,            void,           const GLdouble *v);
OPENGL_INIT_PROC(glTexCoord3f,             void,           GLfloat s, GLfloat t, GLfloat r);
OPENGL_INIT_PROC(glTexCoord3fv,            void,           const GLfloat *v);
OPENGL_INIT_PROC(glTexCoord3i,             void,           GLint s, GLint t, GLint r);
OPENGL_INIT_PROC(glTexCoord3iv,            void,           const GLint *v);
OPENGL_INIT_PROC(glTexCoord3s,             void,           GLshort s, GLshort t, GLshort r);
OPENGL_INIT_PROC(glTexCoord3sv,            void,           const GLshort *v);
OPENGL_INIT_PROC(glTexCoord4d,             void,           GLdouble s, GLdouble t, GLdouble r, GLdouble q);
OPENGL_INIT_PROC(glTexCoord4dv,            void,           const GLdouble *v);
OPENGL_INIT_PROC(glTexCoord4f,             void,           GLfloat s, GLfloat t, GLfloat r, GLfloat q);
OPENGL_INIT_PROC(glTexCoord4fv,            void,           const GLfloat *v);
OPENGL_INIT_PROC(glTexCoord4i,             void,           GLint s, GLint t, GLint r, GLint q);
OPENGL_INIT_PROC(glTexCoord4iv,            void,           const GLint *v);
OPENGL_INIT_PROC(glTexCoord4s,             void,           GLshort s, GLshort t, GLshort r, GLshort q);
OPENGL_INIT_PROC(glTexCoord4sv,            void,           const GLshort *v);
OPENGL_INIT_PROC(glVertex2d,               void,           GLdouble x, GLdouble y);
OPENGL_INIT_PROC(glVertex2dv,              void,           const GLdouble *v);
OPENGL_INIT_PROC(glVertex2f,               void,           GLfloat x, GLfloat y);
OPENGL_INIT_PROC(glVertex2fv,              void,           const GLfloat *v);
OPENGL_INIT_PROC(glVertex2i,               void,           GLint x, GLint y);
OPENGL_INIT_PROC(glVertex2iv,              void,           const GLint *v);
OPENGL_INIT_PROC(glVertex2s,               void,           GLshort x, GLshort y);
OPENGL_INIT_PROC(glVertex2sv,              void,           const GLshort *v);
OPENGL_INIT_PROC(glVertex3d,               void,           GLdouble x, GLdouble y, GLdouble z);
OPENGL_INIT_PROC(glVertex3dv,              void,           const GLdouble *v);
OPENGL_INIT_PROC(glVertex3f,               void,           GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glVertex3fv,              void,           const GLfloat *v);
OPENGL_INIT_PROC(glVertex3i,               void,           GLint x, GLint y, GLint z);
OPENGL_INIT_PROC(glVertex3iv,              void,           const GLint *v);
OPENGL_INIT_PROC(glVertex3s,               void,           GLshort x, GLshort y, GLshort z);
OPENGL_INIT_PROC(glVertex3sv,              void,           const GLshort *v);
OPENGL_INIT_PROC(glVertex4d,               void,           GLdouble x, GLdouble y, GLdouble z, GLdouble w);
OPENGL_INIT_PROC(glVertex4dv,              void,           const GLdouble *v);
OPENGL_INIT_PROC(glVertex4f,               void,           GLfloat x, GLfloat y, GLfloat z, GLfloat w);
OPENGL_INIT_PROC(glVertex4fv,              void,           const GLfloat *v);
OPENGL_INIT_PROC(glVertex4i,               void,           GLint x, GLint y, GLint z, GLint w);
OPENGL_INIT_PROC(glVertex4iv,              void,           const GLint *v);
OPENGL_INIT_PROC(glVertex4s,               void,           GLshort x, GLshort y, GLshort z, GLshort w);
OPENGL_INIT_PROC(glVertex4sv,              void,           const GLshort *v);
OPENGL_INIT_PROC(glClipPlane,              void,           GLenum plane, const GLdouble *equation);
OPENGL_INIT_PROC(glColorMaterial,          void,           GLenum face, GLenum mode);
OPENGL_INIT_PROC(glFogf,                   void,           GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glFogfv,                  void,           GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glFogi,                   void,           GLenum pname, GLint param);
OPENGL_INIT_PROC(glFogiv,                  void,           GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glLightf,                 void,           GLenum light, GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glLightfv,                void,           GLenum light, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glLighti,                 void,           GLenum light, GLenum pname, GLint param);
OPENGL_INIT_PROC(glLightiv,                void,           GLenum light, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glLightModelf,            void,           GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glLightModelfv,           void,           GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glLightModeli,            void,           GLenum pname, GLint param);
OPENGL_INIT_PROC(glLightModeliv,           void,           GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glLineStipple,            void,           GLint factor, GLushort pattern);
OPENGL_INIT_PROC(glMaterialf,              void,           GLenum face, GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glMaterialfv,             void,           GLenum face, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glMateriali,              void,           GLenum face, GLenum pname, GLint param);
OPENGL_INIT_PROC(glMaterialiv,             void,           GLenum face, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glPolygonStipple,         void,           const GLubyte *mask);
OPENGL_INIT_PROC(glShadeModel,             void,           GLenum mode);
OPENGL_INIT_PROC(glTexEnvf,                void,           GLenum target, GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glTexEnvfv,               void,           GLenum target, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glTexEnvi,                void,           GLenum target, GLenum pname, GLint param);
OPENGL_INIT_PROC(glTexEnviv,               void,           GLenum target, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glTexGend,                void,           GLenum coord, GLenum pname, GLdouble param);
OPENGL_INIT_PROC(glTexGendv,               void,           GLenum coord, GLenum pname, const GLdouble *params);
OPENGL_INIT_PROC(glTexGenf,                void,           GLenum coord, GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glTexGenfv,               void,           GLenum coord, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glTexGeni,                void,           GLenum coord, GLenum pname, GLint param);
OPENGL_INIT_PROC(glTexGeniv,               void,           GLenum coord, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glFeedbackBuffer,         void,           GLsizei size, GLenum type, GLfloat *buffer);
OPENGL_INIT_PROC(glSelectBuffer,           void,           GLsizei size, GLuint *buffer);
OPENGL_INIT_PROC(glRenderMode,             GLint,          GLenum mode);
OPENGL_INIT_PROC(glInitNames,              void,           void);
OPENGL_INIT_PROC(glLoadName,               void,           GLuint name);
OPENGL_INIT_PROC(glPassThrough,            void,           GLfloat token);
OPENGL_INIT_PROC(glPopName,                void,           void);
OPENGL_INIT_PROC(glPushName,               void,           GLuint name);
OPENGL_INIT_PROC(glClearAccum,             void,           GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
OPENGL_INIT_PROC(glClearIndex,             void,           GLfloat c);
OPENGL_INIT_PROC(glIndexMask,              void,           GLuint mask);
OPENGL_INIT_PROC(glAccum,                  void,           GLenum op, GLfloat value);
OPENGL_INIT_PROC(glPopAttrib,              void,           void);
OPENGL_INIT_PROC(glPushAttrib,             void,           GLbitfield mask);
OPENGL_INIT_PROC(glMap1d,                  void,           GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
OPENGL_INIT_PROC(glMap1f,                  void,           GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
OPENGL_INIT_PROC(glMap2d,                  void,           GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
OPENGL_INIT_PROC(glMap2f,                  void,           GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
OPENGL_INIT_PROC(glMapGrid1d,              void,           GLint un, GLdouble u1, GLdouble u2);
OPENGL_INIT_PROC(glMapGrid1f,              void,           GLint un, GLfloat u1, GLfloat u2);
OPENGL_INIT_PROC(glMapGrid2d,              void,           GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
OPENGL_INIT_PROC(glMapGrid2f,              void,           GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
OPENGL_INIT_PROC(glEvalCoord1d,            void,           GLdouble u);
OPENGL_INIT_PROC(glEvalCoord1dv,           void,           const GLdouble *u);
OPENGL_INIT_PROC(glEvalCoord1f,            void,           GLfloat u);
OPENGL_INIT_PROC(glEvalCoord1fv,           void,           const GLfloat *u);
OPENGL_INIT_PROC(glEvalCoord2d,            void,           GLdouble u, GLdouble v);
OPENGL_INIT_PROC(glEvalCoord2dv,           void,           const GLdouble *u);
OPENGL_INIT_PROC(glEvalCoord2f,            void,           GLfloat u, GLfloat v);
OPENGL_INIT_PROC(glEvalCoord2fv,           void,           const GLfloat *u);
OPENGL_INIT_PROC(glEvalMesh1,              void,           GLenum mode, GLint i1, GLint i2);
OPENGL_INIT_PROC(glEvalPoint1,             void,           GLint i);
OPENGL_INIT_PROC(glEvalMesh2,              void,           GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
OPENGL_INIT_PROC(glEvalPoint2,             void,           GLint i, GLint j);
OPENGL_INIT_PROC(glAlphaFunc,              void,           GLenum func, GLfloat ref);
OPENGL_INIT_PROC(glPixelZoom,              void,           GLfloat xfactor, GLfloat yfactor);
OPENGL_INIT_PROC(glPixelTransferf,         void,           GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glPixelTransferi,         void,           GLenum pname, GLint param);
OPENGL_INIT_PROC(glPixelMapfv,             void,           GLenum map, GLsizei mapsize, const GLfloat *values);
OPENGL_INIT_PROC(glPixelMapuiv,            void,           GLenum map, GLsizei mapsize, const GLuint *values);
OPENGL_INIT_PROC(glPixelMapusv,            void,           GLenum map, GLsizei mapsize, const GLushort *values);
OPENGL_INIT_PROC(glCopyPixels,             void,           GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
OPENGL_INIT_PROC(glDrawPixels,             void,           GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
OPENGL_INIT_PROC(glGetClipPlane,           void,           GLenum plane, GLdouble *equation);
OPENGL_INIT_PROC(glGetLightfv,             void,           GLenum light, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetLightiv,             void,           GLenum light, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetMapdv,               void,           GLenum target, GLenum query, GLdouble *v);
OPENGL_INIT_PROC(glGetMapfv,               void,           GLenum target, GLenum query, GLfloat *v);
OPENGL_INIT_PROC(glGetMapiv,               void,           GLenum target, GLenum query, GLint *v);
OPENGL_INIT_PROC(glGetMaterialfv,          void,           GLenum face, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetMaterialiv,          void,           GLenum face, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetPixelMapfv,          void,           GLenum map, GLfloat *values);
OPENGL_INIT_PROC(glGetPixelMapuiv,         void,           GLenum map, GLuint *values);
OPENGL_INIT_PROC(glGetPixelMapusv,         void,           GLenum map, GLushort *values);
OPENGL_INIT_PROC(glGetPolygonStipple,      void,           GLubyte *mask);
OPENGL_INIT_PROC(glGetTexEnvfv,            void,           GLenum target, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetTexEnviv,            void,           GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetTexGendv,            void,           GLenum coord, GLenum pname, GLdouble *params);
OPENGL_INIT_PROC(glGetTexGenfv,            void,           GLenum coord, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetTexGeniv,            void,           GLenum coord, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glIsList,                 GLboolean,      GLuint list);
OPENGL_INIT_PROC(glFrustum,                void,           GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
OPENGL_INIT_PROC(glLoadIdentity,           void,           void);
OPENGL_INIT_PROC(glLoadMatrixf,            void,           const GLfloat *m);
OPENGL_INIT_PROC(glLoadMatrixd,            void,           const GLdouble *m);
OPENGL_INIT_PROC(glMatrixMode,             void,           GLenum mode);
OPENGL_INIT_PROC(glMultMatrixf,            void,           const GLfloat *m);
OPENGL_INIT_PROC(glMultMatrixd,            void,           const GLdouble *m);
OPENGL_INIT_PROC(glOrtho,                  void,           GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
OPENGL_INIT_PROC(glPopMatrix,              void,           void);
OPENGL_INIT_PROC(glPushMatrix,             void,           void);
OPENGL_INIT_PROC(glRotated,                void,           GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
OPENGL_INIT_PROC(glRotatef,                void,           GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glScaled,                 void,           GLdouble x, GLdouble y, GLdouble z);
OPENGL_INIT_PROC(glScalef,                 void,           GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glTranslated,             void,           GLdouble x, GLdouble y, GLdouble z);
OPENGL_INIT_PROC(glTranslatef,             void,           GLfloat x, GLfloat y, GLfloat z);
#endif // OPENGL_USE_COMPATIBILITY_PROFILE

#define glCullFace               OGL__glCullFace
#define glFrontFace              OGL__glFrontFace
#define glHint                   OGL__glHint
#define glLineWidth              OGL__glLineWidth
#define glPointSize              OGL__glPointSize
#define glPolygonMode            OGL__glPolygonMode
#define glScissor                OGL__glScissor
#define glTexParameterf          OGL__glTexParameterf
#define glTexParameterfv         OGL__glTexParameterfv
#define glTexParameteri          OGL__glTexParameteri
#define glTexParameteriv         OGL__glTexParameteriv
#define glTexImage1D             OGL__glTexImage1D
#define glTexImage2D             OGL__glTexImage2D
#define glDrawBuffer             OGL__glDrawBuffer
#define glClear                  OGL__glClear
#define glClearColor             OGL__glClearColor
#define glClearStencil           OGL__glClearStencil
#define glClearDepth             OGL__glClearDepth
#define glStencilMask            OGL__glStencilMask
#define glColorMask              OGL__glColorMask
#define glDepthMask              OGL__glDepthMask
#define glDisable                OGL__glDisable
#define glEnable                 OGL__glEnable
#define glFinish                 OGL__glFinish
#define glFlush                  OGL__glFlush
#define glBlendFunc              OGL__glBlendFunc
#define glLogicOp                OGL__glLogicOp
#define glStencilFunc            OGL__glStencilFunc
#define glStencilOp              OGL__glStencilOp
#define glDepthFunc              OGL__glDepthFunc
#define glPixelStoref            OGL__glPixelStoref
#define glPixelStorei            OGL__glPixelStorei
#define glReadBuffer             OGL__glReadBuffer
#define glReadPixels             OGL__glReadPixels
#define glGetBooleanv            OGL__glGetBooleanv
#define glGetDoublev             OGL__glGetDoublev
#define glGetError               OGL__glGetError
#define glGetFloatv              OGL__glGetFloatv
#define glGetIntegerv            OGL__glGetIntegerv
#define glGetString              OGL__glGetString
#define glGetTexImage            OGL__glGetTexImage
#define glGetTexParameterfv      OGL__glGetTexParameterfv
#define glGetTexParameteriv      OGL__glGetTexParameteriv
#define glGetTexLevelParameterfv OGL__glGetTexLevelParameterfv
#define glGetTexLevelParameteriv OGL__glGetTexLevelParameteriv
#define glIsEnabled              OGL__glIsEnabled
#define glDepthRange             OGL__glDepthRange
#define glViewport               OGL__glViewport
#define glNewList                OGL__glNewList
#ifdef OPENGL_USE_COMPATIBILITY_PROFILE
#define glEndList                OGL__glEndList
#define glCallList               OGL__glCallList
#define glCallLists              OGL__glCallLists
#define glDeleteLists            OGL__glDeleteLists
#define glGenLists               OGL__glGenLists
#define glListBase               OGL__glListBase
#define glBegin                  OGL__glBegin
#define glBitmap                 OGL__glBitmap
#define glColor3b                OGL__glColor3b
#define glColor3bv               OGL__glColor3bv
#define glColor3d                OGL__glColor3d
#define glColor3dv               OGL__glColor3dv
#define glColor3f                OGL__glColor3f
#define glColor3fv               OGL__glColor3fv
#define glColor3i                OGL__glColor3i
#define glColor3iv               OGL__glColor3iv
#define glColor3s                OGL__glColor3s
#define glColor3sv               OGL__glColor3sv
#define glColor3ub               OGL__glColor3ub
#define glColor3ubv              OGL__glColor3ubv
#define glColor3ui               OGL__glColor3ui
#define glColor3uiv              OGL__glColor3uiv
#define glColor3us               OGL__glColor3us
#define glColor3usv              OGL__glColor3usv
#define glColor4b                OGL__glColor4b
#define glColor4bv               OGL__glColor4bv
#define glColor4d                OGL__glColor4d
#define glColor4dv               OGL__glColor4dv
#define glColor4f                OGL__glColor4f
#define glColor4fv               OGL__glColor4fv
#define glColor4i                OGL__glColor4i
#define glColor4iv               OGL__glColor4iv
#define glColor4s                OGL__glColor4s
#define glColor4sv               OGL__glColor4sv
#define glColor4ub               OGL__glColor4ub
#define glColor4ubv              OGL__glColor4ubv
#define glColor4ui               OGL__glColor4ui
#define glColor4uiv              OGL__glColor4uiv
#define glColor4us               OGL__glColor4us
#define glColor4usv              OGL__glColor4usv
#define glEdgeFlag               OGL__glEdgeFlag
#define glEdgeFlagv              OGL__glEdgeFlagv
#define glEnd                    OGL__glEnd
#define glIndexd                 OGL__glIndexd
#define glIndexdv                OGL__glIndexdv
#define glIndexf                 OGL__glIndexf
#define glIndexfv                OGL__glIndexfv
#define glIndexi                 OGL__glIndexi
#define glIndexiv                OGL__glIndexiv
#define glIndexs                 OGL__glIndexs
#define glIndexsv                OGL__glIndexsv
#define glNormal3b               OGL__glNormal3b
#define glNormal3bv              OGL__glNormal3bv
#define glNormal3d               OGL__glNormal3d
#define glNormal3dv              OGL__glNormal3dv
#define glNormal3f               OGL__glNormal3f
#define glNormal3fv              OGL__glNormal3fv
#define glNormal3i               OGL__glNormal3i
#define glNormal3uv              OGL__glNormal3uv
#define glNormal3s               OGL__glNormal3s
#define glNormal3sv              OGL__glNormal3sv
#define glRasterPos2d            OGL__glRasterPos2d
#define glRasterPos2dv           OGL__glRasterPos2dv
#define glRasterPos2f            OGL__glRasterPos2f
#define glRasterPos2fv           OGL__glRasterPos2fv
#define glRasterPos2i            OGL__glRasterPos2i
#define glRasterPos2iv           OGL__glRasterPos2iv
#define glRasterPos2s            OGL__glRasterPos2s
#define glRasterPos2sv           OGL__glRasterPos2sv
#define glRasterPos3d            OGL__glRasterPos3d
#define glRasterPos3dv           OGL__glRasterPos3dv
#define glRasterPos3f            OGL__glRasterPos3f
#define glRasterPos3fv           OGL__glRasterPos3fv
#define glRasterPos3i            OGL__glRasterPos3i
#define glRasterPos3iv           OGL__glRasterPos3iv
#define glRasterPos3s            OGL__glRasterPos3s
#define glRasterPos3sv           OGL__glRasterPos3sv
#define glRasterPos4d            OGL__glRasterPos4d
#define glRasterPos4dv           OGL__glRasterPos4dv
#define glRasterPos4f            OGL__glRasterPos4f
#define glRasterPos4fv           OGL__glRasterPos4fv
#define glRasterPos4i            OGL__glRasterPos4i
#define glRasterPos4iv           OGL__glRasterPos4iv
#define glRasterPos4s            OGL__glRasterPos4s
#define glRasterPos4sv           OGL__glRasterPos4sv
#define glRectd                  OGL__glRectd
#define glRectdv                 OGL__glRectdv
#define glRectf                  OGL__glRectf
#define glRectfv                 OGL__glRectfv
#define glRecti                  OGL__glRecti
#define glRectiv                 OGL__glRectiv
#define glRects                  OGL__glRects
#define glRectsv                 OGL__glRectsv
#define glTexCoord1d             OGL__glTexCoord1d
#define glTexCoord1dv            OGL__glTexCoord1dv
#define glTexCoord1f             OGL__glTexCoord1f
#define glTexCoord1fv            OGL__glTexCoord1fv
#define glTexCoord1i             OGL__glTexCoord1i
#define glTexCoord1iv            OGL__glTexCoord1iv
#define glTexCoord1s             OGL__glTexCoord1s
#define glTexCoord1sv            OGL__glTexCoord1sv
#define glTexCoord2d             OGL__glTexCoord2d
#define glTexCoord2dv            OGL__glTexCoord2dv
#define glTexCoord2f             OGL__glTexCoord2f
#define glTexCoord2fv            OGL__glTexCoord2fv
#define glTexCoord2i             OGL__glTexCoord2i
#define glTexCoord2iv            OGL__glTexCoord2iv
#define glTexCoord2s             OGL__glTexCoord2s
#define glTexCoord2sv            OGL__glTexCoord2sv
#define glTexCoord3d             OGL__glTexCoord3d
#define glTexCoord3dv            OGL__glTexCoord3dv
#define glTexCoord3f             OGL__glTexCoord3f
#define glTexCoord3fv            OGL__glTexCoord3fv
#define glTexCoord3i             OGL__glTexCoord3i
#define glTexCoord3iv            OGL__glTexCoord3iv
#define glTexCoord3s             OGL__glTexCoord3s
#define glTexCoord3sv            OGL__glTexCoord3sv
#define glTexCoord4d             OGL__glTexCoord4d
#define glTexCoord4dv            OGL__glTexCoord4dv
#define glTexCoord4f             OGL__glTexCoord4f
#define glTexCoord4fv            OGL__glTexCoord4fv
#define glTexCoord4i             OGL__glTexCoord4i
#define glTexCoord4iv            OGL__glTexCoord4iv
#define glTexCoord4s             OGL__glTexCoord4s
#define glTexCoord4sv            OGL__glTexCoord4sv
#define glVertex2d               OGL__glVertex2d
#define glVertex2dv              OGL__glVertex2dv
#define glVertex2f               OGL__glVertex2f
#define glVertex2fv              OGL__glVertex2fv
#define glVertex2i               OGL__glVertex2i
#define glVertex2iv              OGL__glVertex2iv
#define glVertex2s               OGL__glVertex2s
#define glVertex2sv              OGL__glVertex2sv
#define glVertex3d               OGL__glVertex3d
#define glVertex3dv              OGL__glVertex3dv
#define glVertex3f               OGL__glVertex3f
#define glVertex3fv              OGL__glVertex3fv
#define glVertex3i               OGL__glVertex3i
#define glVertex3iv              OGL__glVertex3iv
#define glVertex3s               OGL__glVertex3s
#define glVertex3sv              OGL__glVertex3sv
#define glVertex4d               OGL__glVertex4d
#define glVertex4dv              OGL__glVertex4dv
#define glVertex4f               OGL__glVertex4f
#define glVertex4fv              OGL__glVertex4fv
#define glVertex4i               OGL__glVertex4i
#define glVertex4iv              OGL__glVertex4iv
#define glVertex4s               OGL__glVertex4s
#define glVertex4sv              OGL__glVertex4sv
#define glClipPlane              OGL__glClipPlane
#define glColorMaterial          OGL__glColorMaterial
#define glFogf                   OGL__glFogf
#define glFogfv                  OGL__glFogfv
#define glFogi                   OGL__glFogi
#define glFogiv                  OGL__glFogiv
#define glLightf                 OGL__glLightf
#define glLightfv                OGL__glLightfv
#define glLighti                 OGL__glLighti
#define glLightiv                OGL__glLightiv
#define glLightModelf            OGL__glLightModelf
#define glLightModelfv           OGL__glLightModelfv
#define glLightModeli            OGL__glLightModeli
#define glLightModeliv           OGL__glLightModeliv
#define glLineStipple            OGL__glLineStipple
#define glMaterialf              OGL__glMaterialf
#define glMaterialfv             OGL__glMaterialfv
#define glMateriali              OGL__glMateriali
#define glMaterialiv             OGL__glMaterialiv
#define glPolygonStipple         OGL__glPolygonStipple
#define glShadeModel             OGL__glShadeModel
#define glTexEnvf                OGL__glTexEnvf
#define glTexEnvfv               OGL__glTexEnvfv
#define glTexEnvi                OGL__glTexEnvi
#define glTexEnviv               OGL__glTexEnviv
#define glTexGend                OGL__glTexGend
#define glTexGendv               OGL__glTexGendv
#define glTexGenf                OGL__glTexGenf
#define glTexGenfv               OGL__glTexGenfv
#define glTexGeni                OGL__glTexGeni
#define glTexGeniv               OGL__glTexGeniv
#define glFeedbackBuffer         OGL__glFeedbackBuffer
#define glSelectBuffer           OGL__glSelectBuffer
#define glRenderMode             OGL__glRenderMode
#define glInitNames              OGL__glInitNames
#define glLoadName               OGL__glLoadName
#define glPassThrough            OGL__glPassThrough
#define glPopName                OGL__glPopName
#define glPushName               OGL__glPushName
#define glClearAccum             OGL__glClearAccum
#define glClearIndex             OGL__glClearIndex
#define glIndexMask              OGL__glIndexMask
#define glAccum                  OGL__glAccum
#define glPopAttrib              OGL__glPopAttrib
#define glPushAttrib             OGL__glPushAttrib
#define glMap1d                  OGL__glMap1d
#define glMap1f                  OGL__glMap1f
#define glMap2d                  OGL__glMap2d
#define glMap2f                  OGL__glMap2f
#define glMapGrid1d              OGL__glMapGrid1d
#define glMapGrid1f              OGL__glMapGrid1f
#define glMapGrid2d              OGL__glMapGrid2d
#define glMapGrid2f              OGL__glMapGrid2f
#define glEvalCoord1d            OGL__glEvalCoord1d
#define glEvalCoord1dv           OGL__glEvalCoord1dv
#define glEvalCoord1f            OGL__glEvalCoord1f
#define glEvalCoord1fv           OGL__glEvalCoord1fv
#define glEvalCoord2d            OGL__glEvalCoord2d
#define glEvalCoord2dv           OGL__glEvalCoord2dv
#define glEvalCoord2f            OGL__glEvalCoord2f
#define glEvalCoord2fv           OGL__glEvalCoord2fv
#define glEvalMesh1              OGL__glEvalMesh1
#define glEvalPoint1             OGL__glEvalPoint1
#define glEvalMesh2              OGL__glEvalMesh2
#define glEvalPoint2             OGL__glEvalPoint2
#define glAlphaFunc              OGL__glAlphaFunc
#define glPixelZoom              OGL__glPixelZoom
#define glPixelTransferf         OGL__glPixelTransferf
#define glPixelTransferi         OGL__glPixelTransferi
#define glPixelMapfv             OGL__glPixelMapfv
#define glPixelMapuiv            OGL__glPixelMapuiv
#define glPixelMapusv            OGL__glPixelMapusv
#define glCopyPixels             OGL__glCopyPixels
#define glDrawPixels             OGL__glDrawPixels
#define glGetClipPlane           OGL__glGetClipPlane
#define glGetLightfv             OGL__glGetLightfv
#define glGetLightiv             OGL__glGetLightiv
#define glGetMapdv               OGL__glGetMapdv
#define glGetMapfv               OGL__glGetMapfv
#define glGetMapiv               OGL__glGetMapiv
#define glGetMaterialfv          OGL__glGetMaterialfv
#define glGetMaterialiv          OGL__glGetMaterialiv
#define glGetPixelMapfv          OGL__glGetPixelMapfv
#define glGetPixelMapuiv         OGL__glGetPixelMapuiv
#define glGetPixelMapusv         OGL__glGetPixelMapusv
#define glGetPolygonStipple      OGL__glGetPolygonStipple
#define glGetTexEnvfv            OGL__glGetTexEnvfv
#define glGetTexEnviv            OGL__glGetTexEnviv
#define glGetTexGendv            OGL__glGetTexGendv
#define glGetTexGenfv            OGL__glGetTexGenfv
#define glGetTexGeniv            OGL__glGetTexGeniv
#define glIsList                 OGL__glIsList
#define glFrustum                OGL__glFrustum
#define glLoadIdentity           OGL__glLoadIdentity
#define glLoadMatrixf            OGL__glLoadMatrixf
#define glLoadMatrixd            OGL__glLoadMatrixd
#define glMatrixMode             OGL__glMatrixMode
#define glMultMatrixf            OGL__glMultMatrixf
#define glMultMatrixd            OGL__glMultMatrixd
#define glOrtho                  OGL__glOrtho
#define glPopMatrix              OGL__glPopMatrix
#define glPushMatrix             OGL__glPushMatrix
#define glRotated                OGL__glRotated
#define glRotatef                OGL__glRotatef
#define glScaled                 OGL__glScaled
#define glScalef                 OGL__glScalef
#define glTranslated             OGL__glTranslated
#define glTranslatef             OGL__glTranslatef
#endif // OPENGL_USE_COMPATIBILITY_PROFILE

#endif // GL_VERSION_1_0

#endif // OPENGL_LOAD_GL_VERSION_1_0

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_LOAD_GL_VERSION_1_1

#ifndef GL_VERSION_1_1
#define GL_VERSION_1_1 1

#define GL_COLOR_LOGIC_OP                   0x0BF2
#define GL_POLYGON_OFFSET_UNITS             0x2A00
#define GL_POLYGON_OFFSET_POINT             0x2A01
#define GL_POLYGON_OFFSET_LINE              0x2A02
#define GL_POLYGON_OFFSET_FILL              0x8037
#define GL_POLYGON_OFFSET_FACTOR            0x8038
#define GL_TEXTURE_BINDING_1D               0x8068
#define GL_TEXTURE_BINDING_2D               0x8069
#define GL_TEXTURE_INTERNAL_FORMAT          0x1003
#define GL_TEXTURE_RED_SIZE                 0x805C
#define GL_TEXTURE_GREEN_SIZE               0x805D
#define GL_TEXTURE_BLUE_SIZE                0x805E
#define GL_TEXTURE_ALPHA_SIZE               0x805F
#define GL_DOUBLE                           0x140A
#define GL_PROXY_TEXTURE_1D                 0x8063
#define GL_PROXY_TEXTURE_2D                 0x8064
#define GL_R3_G3_B2                         0x2A10
#define GL_RGB4                             0x804F
#define GL_RGB5                             0x8050
#define GL_RGB8                             0x8051
#define GL_RGB10                            0x8052
#define GL_RGB12                            0x8053
#define GL_RGB16                            0x8054
#define GL_RGBA2                            0x8055
#define GL_RGBA4                            0x8056
#define GL_RGB5_A1                          0x8057
#define GL_RGBA8                            0x8058
#define GL_RGB10_A2                         0x8059
#define GL_RGBA12                           0x805A
#define GL_RGBA16                           0x805B
#define GL_VERTEX_ARRAY                     0x8074
#define GL_CLIENT_PIXEL_STORE_BIT           0x00000001
#define GL_CLIENT_VERTEX_ARRAY_BIT          0x00000002
#define GL_CLIENT_ALL_ATTRIB_BITS           0xFFFFFFFF
#define GL_VERTEX_ARRAY_POINTER             0x808E
#define GL_NORMAL_ARRAY_POINTER             0x808F
#define GL_COLOR_ARRAY_POINTER              0x8090
#define GL_INDEX_ARRAY_POINTER              0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER      0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER          0x8093
#define GL_FEEDBACK_BUFFER_POINTER          0x0DF0
#define GL_SELECTION_BUFFER_POINTER         0x0DF3
#define GL_CLIENT_ATTRIB_STACK_DEPTH        0x0BB1
#define GL_INDEX_LOGIC_OP                   0x0BF1
#define GL_MAX_CLIENT_ATTRIB_STACK_DEPTH    0x0D3B
#define GL_FEEDBACK_BUFFER_SIZE             0x0DF1
#define GL_FEEDBACK_BUFFER_TYPE             0x0DF2
#define GL_SELECTION_BUFFER_SIZE            0x0DF4
#define GL_NORMAL_ARRAY                     0x8075
#define GL_COLOR_ARRAY                      0x8076
#define GL_INDEX_ARRAY                      0x8077
#define GL_TEXTURE_COORD_ARRAY              0x8078
#define GL_EDGE_FLAG_ARRAY                  0x8079
#define GL_VERTEX_ARRAY_SIZE                0x807A
#define GL_VERTEX_ARRAY_TYPE                0x807B
#define GL_VERTEX_ARRAY_STRIDE              0x807C
#define GL_NORMAL_ARRAY_TYPE                0x807E
#define GL_NORMAL_ARRAY_STRIDE              0x807F
#define GL_COLOR_ARRAY_SIZE                 0x8081
#define GL_COLOR_ARRAY_TYPE                 0x8082
#define GL_COLOR_ARRAY_STRIDE               0x8083
#define GL_INDEX_ARRAY_TYPE                 0x8085
#define GL_INDEX_ARRAY_STRIDE               0x8086
#define GL_TEXTURE_COORD_ARRAY_SIZE         0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE         0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE       0x808A
#define GL_EDGE_FLAG_ARRAY_STRIDE           0x808C
#define GL_TEXTURE_LUMINANCE_SIZE           0x8060
#define GL_TEXTURE_INTENSITY_SIZE           0x8061
#define GL_TEXTURE_PRIORITY                 0x8066
#define GL_TEXTURE_RESIDENT                 0x8067
#define GL_ALPHA4                           0x803B
#define GL_ALPHA8                           0x803C
#define GL_ALPHA12                          0x803D
#define GL_ALPHA16                          0x803E
#define GL_LUMINANCE4                       0x803F
#define GL_LUMINANCE8                       0x8040
#define GL_LUMINANCE12                      0x8041
#define GL_LUMINANCE16                      0x8042
#define GL_LUMINANCE4_ALPHA4                0x8043
#define GL_LUMINANCE6_ALPHA2                0x8044
#define GL_LUMINANCE8_ALPHA8                0x8045
#define GL_LUMINANCE12_ALPHA4               0x8046
#define GL_LUMINANCE12_ALPHA12              0x8047
#define GL_LUMINANCE16_ALPHA16              0x8048
#define GL_INTENSITY                        0x8049
#define GL_INTENSITY4                       0x804A
#define GL_INTENSITY8                       0x804B
#define GL_INTENSITY12                      0x804C
#define GL_INTENSITY16                      0x804D
#define GL_V2F                              0x2A20
#define GL_V3F                              0x2A21
#define GL_C4UB_V2F                         0x2A22
#define GL_C4UB_V3F                         0x2A23
#define GL_C3F_V3F                          0x2A24
#define GL_N3F_V3F                          0x2A25
#define GL_C4F_N3F_V3F                      0x2A26
#define GL_T2F_V3F                          0x2A27
#define GL_T4F_V4F                          0x2A28
#define GL_T2F_C4UB_V3F                     0x2A29
#define GL_T2F_C3F_V3F                      0x2A2A
#define GL_T2F_N3F_V3F                      0x2A2B
#define GL_T2F_C4F_N3F_V3F                  0x2A2C
#define GL_T4F_C4F_N3F_V4F                  0x2A2D

OPENGL_INIT_PROC(glDrawArrays,          void,      GLenum mode, GLint first, GLsizei count);
OPENGL_INIT_PROC(glDrawElements,        void,      GLenum mode, GLsizei count, GLenum type, const void *indices);
OPENGL_INIT_PROC(glGetPointerv,         void,      GLenum pname, void **params);
OPENGL_INIT_PROC(glPolygonOffset,       void,      GLfloat factor, GLfloat units);
OPENGL_INIT_PROC(glCopyTexImage1D,      void,      GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
OPENGL_INIT_PROC(glCopyTexImage2D,      void,      GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
OPENGL_INIT_PROC(glCopyTexSubImage1D,   void,      GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
OPENGL_INIT_PROC(glCopyTexSubImage2D,   void,      GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glTexSubImage1D,       void,      GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
OPENGL_INIT_PROC(glTexSubImage2D,       void,      GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
OPENGL_INIT_PROC(glBindTexture,         void,      GLenum target, GLuint texture);
OPENGL_INIT_PROC(glDeleteTextures,      void,      GLsizei n, const GLuint *textures);
OPENGL_INIT_PROC(glGenTextures,         void,      GLsizei n, GLuint *textures);
OPENGL_INIT_PROC(glIsTexture,           GLboolean, GLuint texture);
#ifdef OPENGL_USE_COMPATIBILITY_PROFILE
OPENGL_INIT_PROC(glArrayElement,        void,      GLint i);
OPENGL_INIT_PROC(glColorPointer,        void,      GLint size, GLenum type, GLsizei stride, const void *pointer);
OPENGL_INIT_PROC(glDisableClientState,  void,      GLenum array);
OPENGL_INIT_PROC(glEdgeFlagPointer,     void,      GLsizei stride, const void *pointer);
OPENGL_INIT_PROC(glEnableClientState,   void,      GLenum array);
OPENGL_INIT_PROC(glIndexPointer,        void,      GLenum type, GLsizei stride, const void *pointer);
OPENGL_INIT_PROC(glInterleavedArrays,   void,      GLenum format, GLsizei stride, const void *pointer);
OPENGL_INIT_PROC(glNormalPointer,       void,      GLenum type, GLsizei stride, const void *pointer);
OPENGL_INIT_PROC(glTexCoordPointer,     void,      GLint size, GLenum type, GLsizei stride, const void *pointer);
OPENGL_INIT_PROC(glVertexPointer,       void,      GLint size, GLenum type, GLsizei stride, const void *pointer);
OPENGL_INIT_PROC(glAreTexturesResident, GLboolean, GLsizei n, const GLuint *textures, GLboolean *residences);
OPENGL_INIT_PROC(glPrioritizeTextures,  void,      GLsizei n, const GLuint *textures, const GLfloat *priorities);
OPENGL_INIT_PROC(glIndexub,             void,      GLubyte c);
OPENGL_INIT_PROC(glIndexubv,            void,      const GLubyte *c);
OPENGL_INIT_PROC(glPopClientAttrib,     void,      void);
OPENGL_INIT_PROC(glPushClientAttrib,    void,      GLbitfield mask);
#endif // OPENGL_USE_COMPATIBILITY_PROFILE

#define glDrawArrays          OGL__glDrawArrays
#define glDrawElements        OGL__glDrawElements
#define glGetPointerv         OGL__glGetPointerv
#define glPolygonOffset       OGL__glPolygonOffset
#define glCopyTexImage1D      OGL__glCopyTexImage1D
#define glCopyTexImage2D      OGL__glCopyTexImage2D
#define glCopyTexSubImage1D   OGL__glCopyTexSubImage1D
#define glCopyTexSubImage2D   OGL__glCopyTexSubImage2D
#define glTexSubImage1D       OGL__glTexSubImage1D
#define glTexSubImage2D       OGL__glTexSubImage2D
#define glBindTexture         OGL__glBindTexture
#define glDeleteTextures      OGL__glDeleteTextures
#define glGenTextures         OGL__glGenTextures
#define glIsTexture           OGL__glIsTexture
#ifdef OPENGL_USE_COMPATIBILITY_PROFILE
#define glArrayElement        OGL__glArrayElement
#define glColorPointer        OGL__glColorPointer
#define glDisableClientState  OGL__glDisableClientState
#define glEdgeFlagPointer     OGL__glEdgeFlagPointer
#define glEnableClientState   OGL__glEnableClientState
#define glIndexPointer        OGL__glIndexPointer
#define glInterleavedArrays   OGL__glInterleavedArrays
#define glNormalPointer       OGL__glNormalPointer
#define glTexCoordPointer     OGL__glTexCoordPointer
#define glVertexPointer       OGL__glVertexPointer
#define glAreTexturesResident OGL__glAreTexturesResident
#define glPrioritizeTextures  OGL__glPrioritizeTextures
#define glIndexub             OGL__glIndexub
#define glIndexubv            OGL__glIndexubv
#define glPopClientAttrib     OGL__glPopClientAttrib
#define glPushClientAttrib    OGL__glPushClientAttrib
#endif // OPENGL_USE_COMPATIBILITY_PROFILE

#endif // GL_VERSION_1_1

#endif // OPENGL_LOAD_GL_VERSION_1_1

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_LOAD_GL_VERSION_1_2

#ifndef GL_VERSION_1_2
#define GL_VERSION_1_2 1

#define GL_UNSIGNED_BYTE_3_3_2              0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4           0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1           0x8034
#define GL_UNSIGNED_INT_8_8_8_8             0x8035
#define GL_UNSIGNED_INT_10_10_10_2          0x8036
#define GL_TEXTURE_BINDING_3D               0x806A
#define GL_PACK_SKIP_IMAGES                 0x806B
#define GL_PACK_IMAGE_HEIGHT                0x806C
#define GL_UNPACK_SKIP_IMAGES               0x806D
#define GL_UNPACK_IMAGE_HEIGHT              0x806E
#define GL_TEXTURE_3D                       0x806F
#define GL_PROXY_TEXTURE_3D                 0x8070
#define GL_TEXTURE_DEPTH                    0x8071
#define GL_TEXTURE_WRAP_R                   0x8072
#define GL_MAX_3D_TEXTURE_SIZE              0x8073
#define GL_UNSIGNED_BYTE_2_3_3_REV          0x8362
#define GL_UNSIGNED_SHORT_5_6_5             0x8363
#define GL_UNSIGNED_SHORT_5_6_5_REV         0x8364
#define GL_UNSIGNED_SHORT_4_4_4_4_REV       0x8365
#define GL_UNSIGNED_SHORT_1_5_5_5_REV       0x8366
#define GL_UNSIGNED_INT_8_8_8_8_REV         0x8367
#define GL_UNSIGNED_INT_2_10_10_10_REV      0x8368
#define GL_BGR                              0x80E0
#define GL_BGRA                             0x80E1
#define GL_MAX_ELEMENTS_VERTICES            0x80E8
#define GL_MAX_ELEMENTS_INDICES             0x80E9
#define GL_CLAMP_TO_EDGE                    0x812F
#define GL_TEXTURE_MIN_LOD                  0x813A
#define GL_TEXTURE_MAX_LOD                  0x813B
#define GL_TEXTURE_BASE_LEVEL               0x813C
#define GL_TEXTURE_MAX_LEVEL                0x813D
#define GL_SMOOTH_POINT_SIZE_RANGE          0x0B12
#define GL_SMOOTH_POINT_SIZE_GRANULARITY    0x0B13
#define GL_SMOOTH_LINE_WIDTH_RANGE          0x0B22
#define GL_SMOOTH_LINE_WIDTH_GRANULARITY    0x0B23
#define GL_ALIASED_LINE_WIDTH_RANGE         0x846E
#define GL_RESCALE_NORMAL                   0x803A
#define GL_LIGHT_MODEL_COLOR_CONTROL        0x81F8
#define GL_SINGLE_COLOR                     0x81F9
#define GL_SEPARATE_SPECULAR_COLOR          0x81FA
#define GL_ALIASED_POINT_SIZE_RANGE         0x846D

OPENGL_INIT_PROC(glDrawRangeElements, void, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
OPENGL_INIT_PROC(glTexImage3D,        void, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
OPENGL_INIT_PROC(glTexSubImage3D,     void, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
OPENGL_INIT_PROC(glCopyTexSubImage3D, void, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);

#define glDrawRangeElements OGL__glDrawRangeElements
#define glTexImage3D        OGL__glTexImage3D
#define glTexSubImage3D     OGL__glTexSubImage3D
#define glCopyTexSubImage3D OGL__glCopyTexSubImage3D

#endif // GL_VERSION_1_2

#endif // OPENGL_LOAD_GL_VERSION_1_2

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_LOAD_GL_VERSION_1_3

#ifndef GL_VERSION_1_3
#define GL_VERSION_1_3 1

#define GL_TEXTURE0                          0x84C0
#define GL_TEXTURE1                          0x84C1
#define GL_TEXTURE2                          0x84C2
#define GL_TEXTURE3                          0x84C3
#define GL_TEXTURE4                          0x84C4
#define GL_TEXTURE5                          0x84C5
#define GL_TEXTURE6                          0x84C6
#define GL_TEXTURE7                          0x84C7
#define GL_TEXTURE8                          0x84C8
#define GL_TEXTURE9                          0x84C9
#define GL_TEXTURE10                         0x84CA
#define GL_TEXTURE11                         0x84CB
#define GL_TEXTURE12                         0x84CC
#define GL_TEXTURE13                         0x84CD
#define GL_TEXTURE14                         0x84CE
#define GL_TEXTURE15                         0x84CF
#define GL_TEXTURE16                         0x84D0
#define GL_TEXTURE17                         0x84D1
#define GL_TEXTURE18                         0x84D2
#define GL_TEXTURE19                         0x84D3
#define GL_TEXTURE20                         0x84D4
#define GL_TEXTURE21                         0x84D5
#define GL_TEXTURE22                         0x84D6
#define GL_TEXTURE23                         0x84D7
#define GL_TEXTURE24                         0x84D8
#define GL_TEXTURE25                         0x84D9
#define GL_TEXTURE26                         0x84DA
#define GL_TEXTURE27                         0x84DB
#define GL_TEXTURE28                         0x84DC
#define GL_TEXTURE29                         0x84DD
#define GL_TEXTURE30                         0x84DE
#define GL_TEXTURE31                         0x84DF
#define GL_ACTIVE_TEXTURE                    0x84E0
#define GL_MULTISAMPLE                       0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE          0x809E
#define GL_SAMPLE_ALPHA_TO_ONE               0x809F
#define GL_SAMPLE_COVERAGE                   0x80A0
#define GL_SAMPLE_BUFFERS                    0x80A8
#define GL_SAMPLES                           0x80A9
#define GL_SAMPLE_COVERAGE_VALUE             0x80AA
#define GL_SAMPLE_COVERAGE_INVERT            0x80AB
#define GL_TEXTURE_CUBE_MAP                  0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP          0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X       0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X       0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y       0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y       0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z       0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z       0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP            0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE         0x851C
#define GL_COMPRESSED_RGB                    0x84ED
#define GL_COMPRESSED_RGBA                   0x84EE
#define GL_TEXTURE_COMPRESSION_HINT          0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE     0x86A0
#define GL_TEXTURE_COMPRESSED                0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS    0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS        0x86A3
#define GL_CLAMP_TO_BORDER                   0x812D
#define GL_CLIENT_ACTIVE_TEXTURE             0x84E1
#define GL_MAX_TEXTURE_UNITS                 0x84E2
#define GL_TRANSPOSE_MODELVIEW_MATRIX        0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX       0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX          0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX            0x84E6
#define GL_MULTISAMPLE_BIT                   0x20000000
#define GL_NORMAL_MAP                        0x8511
#define GL_REFLECTION_MAP                    0x8512
#define GL_COMPRESSED_ALPHA                  0x84E9
#define GL_COMPRESSED_LUMINANCE              0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA        0x84EB
#define GL_COMPRESSED_INTENSITY              0x84EC
#define GL_COMBINE                           0x8570
#define GL_COMBINE_RGB                       0x8571
#define GL_COMBINE_ALPHA                     0x8572
#define GL_SOURCE0_RGB                       0x8580
#define GL_SOURCE1_RGB                       0x8581
#define GL_SOURCE2_RGB                       0x8582
#define GL_SOURCE0_ALPHA                     0x8588
#define GL_SOURCE1_ALPHA                     0x8589
#define GL_SOURCE2_ALPHA                     0x858A
#define GL_OPERAND0_RGB                      0x8590
#define GL_OPERAND1_RGB                      0x8591
#define GL_OPERAND2_RGB                      0x8592
#define GL_OPERAND0_ALPHA                    0x8598
#define GL_OPERAND1_ALPHA                    0x8599
#define GL_OPERAND2_ALPHA                    0x859A
#define GL_RGB_SCALE                         0x8573
#define GL_ADD_SIGNED                        0x8574
#define GL_INTERPOLATE                       0x8575
#define GL_SUBTRACT                          0x84E7
#define GL_CONSTANT                          0x8576
#define GL_PRIMARY_COLOR                     0x8577
#define GL_PREVIOUS                          0x8578
#define GL_DOT3_RGB                          0x86AE
#define GL_DOT3_RGBA                         0x86AF

OPENGL_INIT_PROC(glActiveTexture,           void, GLenum texture);
OPENGL_INIT_PROC(glSampleCoverage,          void, GLfloat value, GLboolean invert);
OPENGL_INIT_PROC(glCompressedTexImage3D,    void, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
OPENGL_INIT_PROC(glCompressedTexImage2D,    void, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
OPENGL_INIT_PROC(glCompressedTexImage1D,    void, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
OPENGL_INIT_PROC(glCompressedTexSubImage3D, void, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
OPENGL_INIT_PROC(glCompressedTexSubImage2D, void, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
OPENGL_INIT_PROC(glCompressedTexSubImage1D, void, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
OPENGL_INIT_PROC(glGetCompressedTexImage,   void, GLenum target, GLint level, void *img);
#ifdef OPENGL_USE_COMPATIBILITY_PROFILE
OPENGL_INIT_PROC(glClientActiveTexture,     void, GLenum texture);
OPENGL_INIT_PROC(glMultiTexCoord1d,         void, GLenum target, GLdouble s);
OPENGL_INIT_PROC(glMultiTexCoord1dv,        void, GLenum target, const GLdouble *v);
OPENGL_INIT_PROC(glMultiTexCoord1f,         void, GLenum target, GLfloat s);
OPENGL_INIT_PROC(glMultiTexCoord1fv,        void, GLenum target, const GLfloat *v);
OPENGL_INIT_PROC(glMultiTexCoord1i,         void, GLenum target, GLint s);
OPENGL_INIT_PROC(glMultiTexCoord1iv,        void, GLenum target, const GLint *v);
OPENGL_INIT_PROC(glMultiTexCoord1s,         void, GLenum target, GLshort s);
OPENGL_INIT_PROC(glMultiTexCoord1sv,        void, GLenum target, const GLshort *v);
OPENGL_INIT_PROC(glMultiTexCoord2d,         void, GLenum target, GLdouble s, GLdouble t);
OPENGL_INIT_PROC(glMultiTexCoord2dv,        void, GLenum target, const GLdouble *v);
OPENGL_INIT_PROC(glMultiTexCoord2f,         void, GLenum target, GLfloat s, GLfloat t);
OPENGL_INIT_PROC(glMultiTexCoord2fv,        void, GLenum target, const GLfloat *v);
OPENGL_INIT_PROC(glMultiTexCoord2i,         void, GLenum target, GLint s, GLint t);
OPENGL_INIT_PROC(glMultiTexCoord2iv,        void, GLenum target, const GLint *v);
OPENGL_INIT_PROC(glMultiTexCoord2s,         void, GLenum target, GLshort s, GLshort t);
OPENGL_INIT_PROC(glMultiTexCoord2sv,        void, GLenum target, const GLshort *v);
OPENGL_INIT_PROC(glMultiTexCoord3d,         void, GLenum target, GLdouble s, GLdouble t, GLdouble r);
OPENGL_INIT_PROC(glMultiTexCoord3dv,        void, GLenum target, const GLdouble *v);
OPENGL_INIT_PROC(glMultiTexCoord3f,         void, GLenum target, GLfloat s, GLfloat t, GLfloat r);
OPENGL_INIT_PROC(glMultiTexCoord3fv,        void, GLenum target, const GLfloat *v);
OPENGL_INIT_PROC(glMultiTexCoord3i,         void, GLenum target, GLint s, GLint t, GLint r);
OPENGL_INIT_PROC(glMultiTexCoord3iv,        void, GLenum target, const GLint *v);
OPENGL_INIT_PROC(glMultiTexCoord3s,         void, GLenum target, GLshort s, GLshort t, GLshort r);
OPENGL_INIT_PROC(glMultiTexCoord3sv,        void, GLenum target, const GLshort *v);
OPENGL_INIT_PROC(glMultiTexCoord4d,         void, GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
OPENGL_INIT_PROC(glMultiTexCoord4dv,        void, GLenum target, const GLdouble *v);
OPENGL_INIT_PROC(glMultiTexCoord4f,         void, GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
OPENGL_INIT_PROC(glMultiTexCoord4fv,        void, GLenum target, const GLfloat *v);
OPENGL_INIT_PROC(glMultiTexCoord4i,         void, GLenum target, GLint s, GLint t, GLint r, GLint q);
OPENGL_INIT_PROC(glMultiTexCoord4iv,        void, GLenum target, const GLint *v);
OPENGL_INIT_PROC(glMultiTexCoord4s,         void, GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
OPENGL_INIT_PROC(glMultiTexCoord4sv,        void, GLenum target, const GLshort *v);
OPENGL_INIT_PROC(glLoadTransposeMatrixf,    void, const GLfloat *m);
OPENGL_INIT_PROC(glLoadTransposeMatrixd,    void, const GLdouble *m);
OPENGL_INIT_PROC(glMultTransposeMatrixf,    void, const GLfloat *m);
OPENGL_INIT_PROC(glMultTransposeMatrixd,    void, const GLdouble *m);
#endif // OPENGL_USE_COMPATIBILITY_PROFILE

#define glActiveTexture           OGL__glActiveTexture
#define glSampleCoverage          OGL__glSampleCoverage
#define glCompressedTexImage3D    OGL__glCompressedTexImage3D
#define glCompressedTexImage2D    OGL__glCompressedTexImage2D
#define glCompressedTexImage1D    OGL__glCompressedTexImage1D
#define glCompressedTexSubImage3D OGL__glCompressedTexSubImage3D
#define glCompressedTexSubImage2D OGL__glCompressedTexSubImage2D
#define glCompressedTexSubImage1D OGL__glCompressedTexSubImage1D
#define glGetCompressedTexImage   OGL__glGetCompressedTexImage
#ifdef OPENGL_USE_COMPATIBILITY_PROFILE
#define glClientActiveTexture     OGL__glClientActiveTexture
#define glMultiTexCoord1d         OGL__glMultiTexCoord1d
#define glMultiTexCoord1dv        OGL__glMultiTexCoord1dv
#define glMultiTexCoord1f         OGL__glMultiTexCoord1f
#define glMultiTexCoord1fv        OGL__glMultiTexCoord1fv
#define glMultiTexCoord1i         OGL__glMultiTexCoord1i
#define glMultiTexCoord1iv        OGL__glMultiTexCoord1iv
#define glMultiTexCoord1s         OGL__glMultiTexCoord1s
#define glMultiTexCoord1sv        OGL__glMultiTexCoord1sv
#define glMultiTexCoord2d         OGL__glMultiTexCoord2d
#define glMultiTexCoord2dv        OGL__glMultiTexCoord2dv
#define glMultiTexCoord2f         OGL__glMultiTexCoord2f
#define glMultiTexCoord2fv        OGL__glMultiTexCoord2fv
#define glMultiTexCoord2i         OGL__glMultiTexCoord2i
#define glMultiTexCoord2iv        OGL__glMultiTexCoord2iv
#define glMultiTexCoord2s         OGL__glMultiTexCoord2s
#define glMultiTexCoord2sv        OGL__glMultiTexCoord2sv
#define glMultiTexCoord3d         OGL__glMultiTexCoord3d
#define glMultiTexCoord3dv        OGL__glMultiTexCoord3dv
#define glMultiTexCoord3f         OGL__glMultiTexCoord3f
#define glMultiTexCoord3fv        OGL__glMultiTexCoord3fv
#define glMultiTexCoord3i         OGL__glMultiTexCoord3i
#define glMultiTexCoord3iv        OGL__glMultiTexCoord3iv
#define glMultiTexCoord3s         OGL__glMultiTexCoord3s
#define glMultiTexCoord3sv        OGL__glMultiTexCoord3sv
#define glMultiTexCoord4d         OGL__glMultiTexCoord4d
#define glMultiTexCoord4dv        OGL__glMultiTexCoord4dv
#define glMultiTexCoord4f         OGL__glMultiTexCoord4f
#define glMultiTexCoord4fv        OGL__glMultiTexCoord4fv
#define glMultiTexCoord4i         OGL__glMultiTexCoord4i
#define glMultiTexCoord4iv        OGL__glMultiTexCoord4iv
#define glMultiTexCoord4s         OGL__glMultiTexCoord4s
#define glMultiTexCoord4sv        OGL__glMultiTexCoord4sv
#define glLoadTransposeMatrixf    OGL__glLoadTransposeMatrixf
#define glLoadTransposeMatrixd    OGL__glLoadTransposeMatrixd
#define glMultTransposeMatrixf    OGL__glMultTransposeMatrixf
#define glMultTransposeMatrixd    OGL__glMultTransposeMatrixd
#endif // OPENGL_USE_COMPATIBILITY_PROFILE

#endif // GL_VERSION_1_3

#endif // OPENGL_LOAD_GL_VERSION_1_3

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_LOAD_GL_VERSION_1_4

#ifndef GL_VERSION_1_4
#define GL_VERSION_1_4 1

#define GL_BLEND_DST_RGB                    0x80C8
#define GL_BLEND_SRC_RGB                    0x80C9
#define GL_BLEND_DST_ALPHA                  0x80CA
#define GL_BLEND_SRC_ALPHA                  0x80CB
#define GL_POINT_FADE_THRESHOLD_SIZE        0x8128
#define GL_DEPTH_COMPONENT16                0x81A5
#define GL_DEPTH_COMPONENT24                0x81A6
#define GL_DEPTH_COMPONENT32                0x81A7
#define GL_MIRRORED_REPEAT                  0x8370
#define GL_MAX_TEXTURE_LOD_BIAS             0x84FD
#define GL_TEXTURE_LOD_BIAS                 0x8501
#define GL_INCR_WRAP                        0x8507
#define GL_DECR_WRAP                        0x8508
#define GL_TEXTURE_DEPTH_SIZE               0x884A
#define GL_TEXTURE_COMPARE_MODE             0x884C
#define GL_TEXTURE_COMPARE_FUNC             0x884D
#define GL_BLEND_COLOR                      0x8005
#define GL_BLEND_EQUATION                   0x8009
#define GL_CONSTANT_COLOR                   0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR         0x8002
#define GL_CONSTANT_ALPHA                   0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA         0x8004
#define GL_FUNC_ADD                         0x8006
#define GL_FUNC_REVERSE_SUBTRACT            0x800B
#define GL_FUNC_SUBTRACT                    0x800A
#define GL_MIN                              0x8007
#define GL_MAX                              0x8008
#define GL_POINT_SIZE_MIN                   0x8126
#define GL_POINT_SIZE_MAX                   0x8127
#define GL_POINT_DISTANCE_ATTENUATION       0x8129
#define GL_GENERATE_MIPMAP                  0x8191
#define GL_GENERATE_MIPMAP_HINT             0x8192
#define GL_FOG_COORDINATE_SOURCE            0x8450
#define GL_FOG_COORDINATE                   0x8451
#define GL_FRAGMENT_DEPTH                   0x8452
#define GL_CURRENT_FOG_COORDINATE           0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE        0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE      0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER     0x8456
#define GL_FOG_COORDINATE_ARRAY             0x8457
#define GL_COLOR_SUM                        0x8458
#define GL_CURRENT_SECONDARY_COLOR          0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE       0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE       0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE     0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER    0x845D
#define GL_SECONDARY_COLOR_ARRAY            0x845E
#define GL_TEXTURE_FILTER_CONTROL           0x8500
#define GL_DEPTH_TEXTURE_MODE               0x884B
#define GL_COMPARE_R_TO_TEXTURE             0x884E

OPENGL_INIT_PROC(glBlendFuncSeparate,     void, GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
OPENGL_INIT_PROC(glMultiDrawArrays,       void, GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
OPENGL_INIT_PROC(glMultiDrawElements,     void, GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
OPENGL_INIT_PROC(glPointParameterf,       void, GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glPointParameterfv,      void, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glPointParameteri,       void, GLenum pname, GLint param);
OPENGL_INIT_PROC(glPointParameteriv,      void, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glBlendColor,            void, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
OPENGL_INIT_PROC(glBlendEquation,         void, GLenum mode);
#ifdef OPENGL_USE_COMPATIBILITY_PROFILE
OPENGL_INIT_PROC(glFogCoordf,             void, GLfloat coord);
OPENGL_INIT_PROC(glFogCoordfv,            void, const GLfloat *coord);
OPENGL_INIT_PROC(glFogCoordd,             void, GLdouble coord);
OPENGL_INIT_PROC(glFogCoorddv,            void, const GLdouble *coord);
OPENGL_INIT_PROC(glFogCoordPointer,       void, GLenum type, GLsizei stride, const void *pointer);
OPENGL_INIT_PROC(glSecondaryColor3b,      void, GLbyte red, GLbyte green, GLbyte blue);
OPENGL_INIT_PROC(glSecondaryColor3bv,     void, const GLbyte *v);
OPENGL_INIT_PROC(glSecondaryColor3d,      void, GLdouble red, GLdouble green, GLdouble blue);
OPENGL_INIT_PROC(glSecondaryColor3dv,     void, const GLdouble *v);
OPENGL_INIT_PROC(glSecondaryColor3f,      void, GLfloat red, GLfloat green, GLfloat blue);
OPENGL_INIT_PROC(glSecondaryColor3fv,     void, const GLfloat *v);
OPENGL_INIT_PROC(glSecondaryColor3i,      void, GLint red, GLint green, GLint blue);
OPENGL_INIT_PROC(glSecondaryColor3iv,     void, const GLint *v);
OPENGL_INIT_PROC(glSecondaryColor3s,      void, GLshort red, GLshort green, GLshort blue);
OPENGL_INIT_PROC(glSecondaryColor3sv,     void, const GLshort *v);
OPENGL_INIT_PROC(glSecondaryColor3ub,     void, GLubyte red, GLubyte green, GLubyte blue);
OPENGL_INIT_PROC(glSecondaryColor3ubv,    void, const GLubyte *v);
OPENGL_INIT_PROC(glSecondaryColor3ui,     void, GLuint red, GLuint green, GLuint blue);
OPENGL_INIT_PROC(glSecondaryColor3uiv,    void, const GLuint *v);
OPENGL_INIT_PROC(glSecondaryColor3us,     void, GLushort red, GLushort green, GLushort blue);
OPENGL_INIT_PROC(glSecondaryColor3usv,    void, const GLushort *v);
OPENGL_INIT_PROC(glSecondaryColorPointer, void, GLint size, GLenum type, GLsizei stride, const void *pointer);
OPENGL_INIT_PROC(glWindowPos2d,           void, GLdouble x, GLdouble y);
OPENGL_INIT_PROC(glWindowPos2dv,          void, const GLdouble *v);
OPENGL_INIT_PROC(glWindowPos2f,           void, GLfloat x, GLfloat y);
OPENGL_INIT_PROC(glWindowPos2fv,          void, const GLfloat *v);
OPENGL_INIT_PROC(glWindowPos2i,           void, GLint x, GLint y);
OPENGL_INIT_PROC(glWindowPos2iv,          void, const GLint *v);
OPENGL_INIT_PROC(glWindowPos2s,           void, GLshort x, GLshort y);
OPENGL_INIT_PROC(glWindowPos2sv,          void, const GLshort *v);
OPENGL_INIT_PROC(glWindowPos3d,           void, GLdouble x, GLdouble y, GLdouble z);
OPENGL_INIT_PROC(glWindowPos3dv,          void, const GLdouble *v);
OPENGL_INIT_PROC(glWindowPos3f,           void, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glWindowPos3fv,          void, const GLfloat *v);
OPENGL_INIT_PROC(glWindowPos3i,           void, GLint x, GLint y, GLint z);
OPENGL_INIT_PROC(glWindowPos3iv,          void, const GLint *v);
OPENGL_INIT_PROC(glWindowPos3s,           void, GLshort x, GLshort y, GLshort z);
OPENGL_INIT_PROC(glWindowPos3sv,          void, const GLshort *v);
#endif // OPENGL_USE_COMPATIBILITY_PROFILE

#define glBlendFuncSeparate     OGL__glBlendFuncSeparate
#define glMultiDrawArrays       OGL__glMultiDrawArrays
#define glMultiDrawElements     OGL__glMultiDrawElements
#define glPointParameterf       OGL__glPointParameterf
#define glPointParameterfv      OGL__glPointParameterfv
#define glPointParameteri       OGL__glPointParameteri
#define glPointParameteriv      OGL__glPointParameteriv
#define glBlendColor            OGL__glBlendColor
#define glBlendEquation         OGL__glBlendEquation
#ifdef OPENGL_USE_COMPATIBILITY_PROFILE
#define glFogCoordf             OGL__glFogCoordf
#define glFogCoordfv            OGL__glFogCoordfv
#define glFogCoordd             OGL__glFogCoordd
#define glFogCoorddv            OGL__glFogCoorddv
#define glFogCoordPointer       OGL__glFogCoordPointer
#define glSecondaryColor3b      OGL__glSecondaryColor3b
#define glSecondaryColor3bv     OGL__glSecondaryColor3bv
#define glSecondaryColor3d      OGL__glSecondaryColor3d
#define glSecondaryColor3dv     OGL__glSecondaryColor3dv
#define glSecondaryColor3f      OGL__glSecondaryColor3f
#define glSecondaryColor3fv     OGL__glSecondaryColor3fv
#define glSecondaryColor3i      OGL__glSecondaryColor3i
#define glSecondaryColor3iv     OGL__glSecondaryColor3iv
#define glSecondaryColor3s      OGL__glSecondaryColor3s
#define glSecondaryColor3sv     OGL__glSecondaryColor3sv
#define glSecondaryColor3ub     OGL__glSecondaryColor3ub
#define glSecondaryColor3ubv    OGL__glSecondaryColor3ubv
#define glSecondaryColor3ui     OGL__glSecondaryColor3ui
#define glSecondaryColor3uiv    OGL__glSecondaryColor3uiv
#define glSecondaryColor3us     OGL__glSecondaryColor3us
#define glSecondaryColor3usv    OGL__glSecondaryColor3usv
#define glSecondaryColorPointer OGL__glSecondaryColorPointer
#define glWindowPos2d           OGL__glWindowPos2d
#define glWindowPos2dv          OGL__glWindowPos2dv
#define glWindowPos2f           OGL__glWindowPos2f
#define glWindowPos2fv          OGL__glWindowPos2fv
#define glWindowPos2i           OGL__glWindowPos2i
#define glWindowPos2iv          OGL__glWindowPos2iv
#define glWindowPos2s           OGL__glWindowPos2s
#define glWindowPos2sv          OGL__glWindowPos2sv
#define glWindowPos3d           OGL__glWindowPos3d
#define glWindowPos3dv          OGL__glWindowPos3dv
#define glWindowPos3f           OGL__glWindowPos3f
#define glWindowPos3fv          OGL__glWindowPos3fv
#define glWindowPos3i           OGL__glWindowPos3i
#define glWindowPos3iv          OGL__glWindowPos3iv
#define glWindowPos3s           OGL__glWindowPos3s
#define glWindowPos3sv          OGL__glWindowPos3sv
#endif // OPENGL_USE_COMPATIBILITY_PROFILE

#endif // GL_VERSION_1_4

#endif // OPENGL_LOAD_GL_VERSION_1_4

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_LOAD_GL_VERSION_1_5

#ifndef GL_VERSION_1_5
#define GL_VERSION_1_5 1

#define GL_BUFFER_SIZE                             0x8764
#define GL_BUFFER_USAGE                            0x8765
#define GL_QUERY_COUNTER_BITS                      0x8864
#define GL_CURRENT_QUERY                           0x8865
#define GL_QUERY_RESULT                            0x8866
#define GL_QUERY_RESULT_AVAILABLE                  0x8867
#define GL_ARRAY_BUFFER                            0x8892
#define GL_ELEMENT_ARRAY_BUFFER                    0x8893
#define GL_ARRAY_BUFFER_BINDING                    0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING            0x8895
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING      0x889F
#define GL_READ_ONLY                               0x88B8
#define GL_WRITE_ONLY                              0x88B9
#define GL_READ_WRITE                              0x88BA
#define GL_BUFFER_ACCESS                           0x88BB
#define GL_BUFFER_MAPPED                           0x88BC
#define GL_BUFFER_MAP_POINTER                      0x88BD
#define GL_STREAM_DRAW                             0x88E0
#define GL_STREAM_READ                             0x88E1
#define GL_STREAM_COPY                             0x88E2
#define GL_STATIC_DRAW                             0x88E4
#define GL_STATIC_READ                             0x88E5
#define GL_STATIC_COPY                             0x88E6
#define GL_DYNAMIC_DRAW                            0x88E8
#define GL_DYNAMIC_READ                            0x88E9
#define GL_DYNAMIC_COPY                            0x88EA
#define GL_SAMPLES_PASSED                          0x8914
#define GL_SRC1_ALPHA                              0x8589
#define GL_VERTEX_ARRAY_BUFFER_BINDING             0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING             0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING              0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING              0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING      0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING          0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING    0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING     0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING             0x889E
#define GL_FOG_COORD_SRC                           0x8450
#define GL_FOG_COORD                               0x8451
#define GL_CURRENT_FOG_COORD                       0x8453
#define GL_FOG_COORD_ARRAY_TYPE                    0x8454
#define GL_FOG_COORD_ARRAY_STRIDE                  0x8455
#define GL_FOG_COORD_ARRAY_POINTER                 0x8456
#define GL_FOG_COORD_ARRAY                         0x8457
#define GL_FOG_COORD_ARRAY_BUFFER_BINDING          0x889D
#define GL_SRC0_RGB                                0x8580
#define GL_SRC1_RGB                                0x8581
#define GL_SRC2_RGB                                0x8582
#define GL_SRC0_ALPHA                              0x8588
#define GL_SRC2_ALPHA                              0x858A

OPENGL_INIT_PROC(glGenQueries,           void,      GLsizei n, GLuint *ids);
OPENGL_INIT_PROC(glDeleteQueries,        void,      GLsizei n, const GLuint *ids);
OPENGL_INIT_PROC(glIsQuery,              GLboolean, GLuint id);
OPENGL_INIT_PROC(glBeginQuery,           void,      GLenum target, GLuint id);
OPENGL_INIT_PROC(glEndQuery,             void,      GLenum target);
OPENGL_INIT_PROC(glGetQueryiv,           void,      GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetQueryObjectiv,     void,      GLuint id, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetQueryObjectuiv,    void,      GLuint id, GLenum pname, GLuint *params);
OPENGL_INIT_PROC(glBindBuffer,           void,      GLenum target, GLuint buffer);
OPENGL_INIT_PROC(glDeleteBuffers,        void,      GLsizei n, const GLuint *buffers);
OPENGL_INIT_PROC(glGenBuffers,           void,      GLsizei n, GLuint *buffers);
OPENGL_INIT_PROC(glIsBuffer,             GLboolean, GLuint buffer);
OPENGL_INIT_PROC(glBufferData,           void,      GLenum target, GLsizeiptr size, const void *data, GLenum usage);
OPENGL_INIT_PROC(glBufferSubData,        void,      GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
OPENGL_INIT_PROC(glGetBufferSubData,     void,      GLenum target, GLintptr offset, GLsizeiptr size, void *data);
OPENGL_INIT_PROC(glMapBuffer,            void*,     GLenum target, GLenum access);
OPENGL_INIT_PROC(glUnmapBuffer,          GLboolean, GLenum target);
OPENGL_INIT_PROC(glGetBufferParameteriv, void,      GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetBufferPointerv,    void,      GLenum target, GLenum pname, void **params);

#define glGenQueries           OGL__glGenQueries
#define glDeleteQueries        OGL__glDeleteQueries
#define glIsQuery              OGL__glIsQuery
#define glBeginQuery           OGL__glBeginQuery
#define glEndQuery             OGL__glEndQuery
#define glGetQueryiv           OGL__glGetQueryiv
#define glGetQueryObjectiv     OGL__glGetQueryObjectiv
#define glGetQueryObjectuiv    OGL__glGetQueryObjectuiv
#define glBindBuffer           OGL__glBindBuffer
#define glDeleteBuffers        OGL__glDeleteBuffers
#define glGenBuffers           OGL__glGenBuffers
#define glIsBuffer             OGL__glIsBuffer
#define glBufferData           OGL__glBufferData
#define glBufferSubData        OGL__glBufferSubData
#define glGetBufferSubData     OGL__glGetBufferSubData
#define glMapBuffer            OGL__glMapBuffer
#define glUnmapBuffer          OGL__glUnmapBuffer
#define glGetBufferParameteriv OGL__glGetBufferParameteriv
#define glGetBufferPointerv    OGL__glGetBufferPointerv

#endif // GL_VERSION_1_5

#endif // OPENGL_LOAD_GL_VERSION_1_5

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_LOAD_GL_VERSION_2_0

#ifndef GL_VERSION_2_0
#define GL_VERSION_2_0 1

#define GL_BLEND_EQUATION_RGB                  0x8009
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED         0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE            0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE          0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE            0x8625
#define GL_CURRENT_VERTEX_ATTRIB               0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE           0x8642
#define GL_VERTEX_ATTRIB_ARRAY_POINTER         0x8645
#define GL_STENCIL_BACK_FUNC                   0x8800
#define GL_STENCIL_BACK_FAIL                   0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL        0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS        0x8803
#define GL_MAX_DRAW_BUFFERS                    0x8824
#define GL_DRAW_BUFFER0                        0x8825
#define GL_DRAW_BUFFER1                        0x8826
#define GL_DRAW_BUFFER2                        0x8827
#define GL_DRAW_BUFFER3                        0x8828
#define GL_DRAW_BUFFER4                        0x8829
#define GL_DRAW_BUFFER5                        0x882A
#define GL_DRAW_BUFFER6                        0x882B
#define GL_DRAW_BUFFER7                        0x882C
#define GL_DRAW_BUFFER8                        0x882D
#define GL_DRAW_BUFFER9                        0x882E
#define GL_DRAW_BUFFER10                       0x882F
#define GL_DRAW_BUFFER11                       0x8830
#define GL_DRAW_BUFFER12                       0x8831
#define GL_DRAW_BUFFER13                       0x8832
#define GL_DRAW_BUFFER14                       0x8833
#define GL_DRAW_BUFFER15                       0x8834
#define GL_BLEND_EQUATION_ALPHA                0x883D
#define GL_MAX_VERTEX_ATTRIBS                  0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED      0x886A
#define GL_MAX_TEXTURE_IMAGE_UNITS             0x8872
#define GL_FRAGMENT_SHADER                     0x8B30
#define GL_VERTEX_SHADER                       0x8B31
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS     0x8B49
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS       0x8B4A
#define GL_MAX_VARYING_FLOATS                  0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS      0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS    0x8B4D
#define GL_SHADER_TYPE                         0x8B4F
#define GL_FLOAT_VEC2                          0x8B50
#define GL_FLOAT_VEC3                          0x8B51
#define GL_FLOAT_VEC4                          0x8B52
#define GL_INT_VEC2                            0x8B53
#define GL_INT_VEC3                            0x8B54
#define GL_INT_VEC4                            0x8B55
#define GL_BOOL                                0x8B56
#define GL_BOOL_VEC2                           0x8B57
#define GL_BOOL_VEC3                           0x8B58
#define GL_BOOL_VEC4                           0x8B59
#define GL_FLOAT_MAT2                          0x8B5A
#define GL_FLOAT_MAT3                          0x8B5B
#define GL_FLOAT_MAT4                          0x8B5C
#define GL_SAMPLER_1D                          0x8B5D
#define GL_SAMPLER_2D                          0x8B5E
#define GL_SAMPLER_3D                          0x8B5F
#define GL_SAMPLER_CUBE                        0x8B60
#define GL_SAMPLER_1D_SHADOW                   0x8B61
#define GL_SAMPLER_2D_SHADOW                   0x8B62
#define GL_DELETE_STATUS                       0x8B80
#define GL_COMPILE_STATUS                      0x8B81
#define GL_LINK_STATUS                         0x8B82
#define GL_VALIDATE_STATUS                     0x8B83
#define GL_INFO_LOG_LENGTH                     0x8B84
#define GL_ATTACHED_SHADERS                    0x8B85
#define GL_ACTIVE_UNIFORMS                     0x8B86
#define GL_ACTIVE_UNIFORM_MAX_LENGTH           0x8B87
#define GL_SHADER_SOURCE_LENGTH                0x8B88
#define GL_ACTIVE_ATTRIBUTES                   0x8B89
#define GL_ACTIVE_ATTRIBUTE_MAX_LENGTH         0x8B8A
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT     0x8B8B
#define GL_SHADING_LANGUAGE_VERSION            0x8B8C
#define GL_CURRENT_PROGRAM                     0x8B8D
#define GL_POINT_SPRITE_COORD_ORIGIN           0x8CA0
#define GL_LOWER_LEFT                          0x8CA1
#define GL_UPPER_LEFT                          0x8CA2
#define GL_STENCIL_BACK_REF                    0x8CA3
#define GL_STENCIL_BACK_VALUE_MASK             0x8CA4
#define GL_STENCIL_BACK_WRITEMASK              0x8CA5
#define GL_VERTEX_PROGRAM_TWO_SIDE             0x8643
#define GL_POINT_SPRITE                        0x8861
#define GL_COORD_REPLACE                       0x8862
#define GL_MAX_TEXTURE_COORDS                  0x8871

OPENGL_INIT_PROC(glBlendEquationSeparate,    void,      GLenum modeRGB, GLenum modeAlpha);
OPENGL_INIT_PROC(glDrawBuffers,              void,      GLsizei n, const GLenum *bufs);
OPENGL_INIT_PROC(glStencilOpSeparate,        void,      GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
OPENGL_INIT_PROC(glStencilFuncSeparate,      void,      GLenum face, GLenum func, GLint ref, GLuint mask);
OPENGL_INIT_PROC(glStencilMaskSeparate,      void,      GLenum face, GLuint mask);
OPENGL_INIT_PROC(glAttachShader,             void,      GLuint program, GLuint shader);
OPENGL_INIT_PROC(glBindAttribLocation,       void,      GLuint program, GLuint index, const GLchar *name);
OPENGL_INIT_PROC(glCompileShader,            void,      GLuint shader);
OPENGL_INIT_PROC(glCreateProgram,            GLuint,    void);
OPENGL_INIT_PROC(glCreateShader,             GLuint,    GLenum type);
OPENGL_INIT_PROC(glDeleteProgram,            void,      GLuint program);
OPENGL_INIT_PROC(glDeleteShader,             void,      GLuint shader);
OPENGL_INIT_PROC(glDetachShader,             void,      GLuint program, GLuint shader);
OPENGL_INIT_PROC(glDisableVertexAttribArray, void,      GLuint index);
OPENGL_INIT_PROC(glEnableVertexAttribArray,  void,      GLuint index);
OPENGL_INIT_PROC(glGetActiveAttrib,          void,      GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
OPENGL_INIT_PROC(glGetActiveUniform,         void,      GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
OPENGL_INIT_PROC(glGetAttachedShaders,       void,      GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
OPENGL_INIT_PROC(glGetAttribLocation,        GLint,     GLuint program, const GLchar *name);
OPENGL_INIT_PROC(glGetProgramiv,             void,      GLuint program, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetProgramInfoLog,        void,      GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
OPENGL_INIT_PROC(glGetShaderiv,              void,      GLuint shader, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetShaderInfoLog,         void,      GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
OPENGL_INIT_PROC(glGetShaderSource,          void,      GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
OPENGL_INIT_PROC(glGetUniformLocation,       GLint,     GLuint program, const GLchar *name);
OPENGL_INIT_PROC(glGetUniformfv,             void,      GLuint program, GLint location, GLfloat *params);
OPENGL_INIT_PROC(glGetUniformiv,             void,      GLuint program, GLint location, GLint *params);
OPENGL_INIT_PROC(glGetVertexAttribdv,        void,      GLuint index, GLenum pname, GLdouble *params);
OPENGL_INIT_PROC(glGetVertexAttribfv,        void,      GLuint index, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetVertexAttribiv,        void,      GLuint index, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetVertexAttribPointerv,  void,      GLuint index, GLenum pname, void **pointer);
OPENGL_INIT_PROC(glIsProgram,                GLboolean, GLuint program);
OPENGL_INIT_PROC(glIsShader,                 GLboolean, GLuint shader);
OPENGL_INIT_PROC(glLinkProgram,              void,      GLuint program);
OPENGL_INIT_PROC(glShaderSource,             void,      GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
OPENGL_INIT_PROC(glUseProgram,               void,      GLuint program);
OPENGL_INIT_PROC(glUniform1f,                void,      GLint location, GLfloat v0);
OPENGL_INIT_PROC(glUniform2f,                void,      GLint location, GLfloat v0, GLfloat v1);
OPENGL_INIT_PROC(glUniform3f,                void,      GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
OPENGL_INIT_PROC(glUniform4f,                void,      GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
OPENGL_INIT_PROC(glUniform1i,                void,      GLint location, GLint v0);
OPENGL_INIT_PROC(glUniform2i,                void,      GLint location, GLint v0, GLint v1);
OPENGL_INIT_PROC(glUniform3i,                void,      GLint location, GLint v0, GLint v1, GLint v2);
OPENGL_INIT_PROC(glUniform4i,                void,      GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
OPENGL_INIT_PROC(glUniform1fv,               void,      GLint location, GLsizei count, const GLfloat *value);
OPENGL_INIT_PROC(glUniform2fv,               void,      GLint location, GLsizei count, const GLfloat *value);
OPENGL_INIT_PROC(glUniform3fv,               void,      GLint location, GLsizei count, const GLfloat *value);
OPENGL_INIT_PROC(glUniform4fv,               void,      GLint location, GLsizei count, const GLfloat *value);
OPENGL_INIT_PROC(glUniform1iv,               void,      GLint location, GLsizei count, const GLint *value);
OPENGL_INIT_PROC(glUniform2iv,               void,      GLint location, GLsizei count, const GLint *value);
OPENGL_INIT_PROC(glUniform3iv,               void,      GLint location, GLsizei count, const GLint *value);
OPENGL_INIT_PROC(glUniform4iv,               void,      GLint location, GLsizei count, const GLint *value);
OPENGL_INIT_PROC(glUniformMatrix2fv,         void,      GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glUniformMatrix3fv,         void,      GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glUniformMatrix4fv,         void,      GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glValidateProgram,          void,      GLuint program);
OPENGL_INIT_PROC(glVertexAttrib1d,           void,      GLuint index, GLdouble x);
OPENGL_INIT_PROC(glVertexAttrib1dv,          void,      GLuint index, const GLdouble *v);
OPENGL_INIT_PROC(glVertexAttrib1f,           void,      GLuint index, GLfloat x);
OPENGL_INIT_PROC(glVertexAttrib1fv,          void,      GLuint index, const GLfloat *v);
OPENGL_INIT_PROC(glVertexAttrib1s,           void,      GLuint index, GLshort x);
OPENGL_INIT_PROC(glVertexAttrib1sv,          void,      GLuint index, const GLshort *v);
OPENGL_INIT_PROC(glVertexAttrib2d,           void,      GLuint index, GLdouble x, GLdouble y);
OPENGL_INIT_PROC(glVertexAttrib2dv,          void,      GLuint index, const GLdouble *v);
OPENGL_INIT_PROC(glVertexAttrib2f,           void,      GLuint index, GLfloat x, GLfloat y);
OPENGL_INIT_PROC(glVertexAttrib2fv,          void,      GLuint index, const GLfloat *v);
OPENGL_INIT_PROC(glVertexAttrib2s,           void,      GLuint index, GLshort x, GLshort y);
OPENGL_INIT_PROC(glVertexAttrib2sv,          void,      GLuint index, const GLshort *v);
OPENGL_INIT_PROC(glVertexAttrib3d,           void,      GLuint index, GLdouble x, GLdouble y, GLdouble z);
OPENGL_INIT_PROC(glVertexAttrib3dv,          void,      GLuint index, const GLdouble *v);
OPENGL_INIT_PROC(glVertexAttrib3f,           void,      GLuint index, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glVertexAttrib3fv,          void,      GLuint index, const GLfloat *v);
OPENGL_INIT_PROC(glVertexAttrib3s,           void,      GLuint index, GLshort x, GLshort y, GLshort z);
OPENGL_INIT_PROC(glVertexAttrib3sv,          void,      GLuint index, const GLshort *v);
OPENGL_INIT_PROC(glVertexAttrib4Nbv,         void,      GLuint index, const GLbyte *v);
OPENGL_INIT_PROC(glVertexAttrib4Niv,         void,      GLuint index, const GLint *v);
OPENGL_INIT_PROC(glVertexAttrib4Nsv,         void,      GLuint index, const GLshort *v);
OPENGL_INIT_PROC(glVertexAttrib4Nub,         void,      GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
OPENGL_INIT_PROC(glVertexAttrib4Nubv,        void,      GLuint index, const GLubyte *v);
OPENGL_INIT_PROC(glVertexAttrib4Nuiv,        void,      GLuint index, const GLuint *v);
OPENGL_INIT_PROC(glVertexAttrib4Nusv,        void,      GLuint index, const GLushort *v);
OPENGL_INIT_PROC(glVertexAttrib4bv,          void,      GLuint index, const GLbyte *v);
OPENGL_INIT_PROC(glVertexAttrib4d,           void,      GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
OPENGL_INIT_PROC(glVertexAttrib4dv,          void,      GLuint index, const GLdouble *v);
OPENGL_INIT_PROC(glVertexAttrib4f,           void,      GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
OPENGL_INIT_PROC(glVertexAttrib4fv,          void,      GLuint index, const GLfloat *v);
OPENGL_INIT_PROC(glVertexAttrib4iv,          void,      GLuint index, const GLint *v);
OPENGL_INIT_PROC(glVertexAttrib4s,           void,      GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
OPENGL_INIT_PROC(glVertexAttrib4sv,          void,      GLuint index, const GLshort *v);
OPENGL_INIT_PROC(glVertexAttrib4ubv,         void,      GLuint index, const GLubyte *v);
OPENGL_INIT_PROC(glVertexAttrib4uiv,         void,      GLuint index, const GLuint *v);
OPENGL_INIT_PROC(glVertexAttrib4usv,         void,      GLuint index, const GLushort *v);
OPENGL_INIT_PROC(glVertexAttribPointer,      void,      GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);

#define glBlendEquationSeparate    OGL__glBlendEquationSeparate
#define glDrawBuffers              OGL__glDrawBuffers
#define glStencilOpSeparate        OGL__glStencilOpSeparate
#define glStencilFuncSeparate      OGL__glStencilFuncSeparate
#define glStencilMaskSeparate      OGL__glStencilMaskSeparate
#define glAttachShader             OGL__glAttachShader
#define glBindAttribLocation       OGL__glBindAttribLocation
#define glCompileShader            OGL__glCompileShader
#define glCreateProgram            OGL__glCreateProgram
#define glCreateShader             OGL__glCreateShader
#define glDeleteProgram            OGL__glDeleteProgram
#define glDeleteShader             OGL__glDeleteShader
#define glDetachShader             OGL__glDetachShader
#define glDisableVertexAttribArray OGL__glDisableVertexAttribArray
#define glEnableVertexAttribArray  OGL__glEnableVertexAttribArray
#define glGetActiveAttrib          OGL__glGetActiveAttrib
#define glGetActiveUniform         OGL__glGetActiveUniform
#define glGetAttachedShaders       OGL__glGetAttachedShaders
#define glGetAttribLocation        OGL__glGetAttribLocation
#define glGetProgramiv             OGL__glGetProgramiv
#define glGetProgramInfoLog        OGL__glGetProgramInfoLog
#define glGetShaderiv              OGL__glGetShaderiv
#define glGetShaderInfoLog         OGL__glGetShaderInfoLog
#define glGetShaderSource          OGL__glGetShaderSource
#define glGetUniformLocation       OGL__glGetUniformLocation
#define glGetUniformfv             OGL__glGetUniformfv
#define glGetUniformiv             OGL__glGetUniformiv
#define glGetVertexAttribdv        OGL__glGetVertexAttribdv
#define glGetVertexAttribfv        OGL__glGetVertexAttribfv
#define glGetVertexAttribiv        OGL__glGetVertexAttribiv
#define glGetVertexAttribPointerv  OGL__glGetVertexAttribPointerv
#define glIsProgram                OGL__glIsProgram
#define glIsShader                 OGL__glIsShader
#define glLinkProgram              OGL__glLinkProgram
#define glShaderSource             OGL__glShaderSource
#define glUseProgram               OGL__glUseProgram
#define glUniform1f                OGL__glUniform1f
#define glUniform2f                OGL__glUniform2f
#define glUniform3f                OGL__glUniform3f
#define glUniform4f                OGL__glUniform4f
#define glUniform1i                OGL__glUniform1i
#define glUniform2i                OGL__glUniform2i
#define glUniform3i                OGL__glUniform3i
#define glUniform4i                OGL__glUniform4i
#define glUniform1fv               OGL__glUniform1fv
#define glUniform2fv               OGL__glUniform2fv
#define glUniform3fv               OGL__glUniform3fv
#define glUniform4fv               OGL__glUniform4fv
#define glUniform1iv               OGL__glUniform1iv
#define glUniform2iv               OGL__glUniform2iv
#define glUniform3iv               OGL__glUniform3iv
#define glUniform4iv               OGL__glUniform4iv
#define glUniformMatrix2fv         OGL__glUniformMatrix2fv
#define glUniformMatrix3fv         OGL__glUniformMatrix3fv
#define glUniformMatrix4fv         OGL__glUniformMatrix4fv
#define glValidateProgram          OGL__glValidateProgram
#define glVertexAttrib1d           OGL__glVertexAttrib1d
#define glVertexAttrib1dv          OGL__glVertexAttrib1dv
#define glVertexAttrib1f           OGL__glVertexAttrib1f
#define glVertexAttrib1fv          OGL__glVertexAttrib1fv
#define glVertexAttrib1s           OGL__glVertexAttrib1s
#define glVertexAttrib1sv          OGL__glVertexAttrib1sv
#define glVertexAttrib2d           OGL__glVertexAttrib2d
#define glVertexAttrib2dv          OGL__glVertexAttrib2dv
#define glVertexAttrib2f           OGL__glVertexAttrib2f
#define glVertexAttrib2fv          OGL__glVertexAttrib2fv
#define glVertexAttrib2s           OGL__glVertexAttrib2s
#define glVertexAttrib2sv          OGL__glVertexAttrib2sv
#define glVertexAttrib3d           OGL__glVertexAttrib3d
#define glVertexAttrib3dv          OGL__glVertexAttrib3dv
#define glVertexAttrib3f           OGL__glVertexAttrib3f
#define glVertexAttrib3fv          OGL__glVertexAttrib3fv
#define glVertexAttrib3s           OGL__glVertexAttrib3s
#define glVertexAttrib3sv          OGL__glVertexAttrib3sv
#define glVertexAttrib4Nbv         OGL__glVertexAttrib4Nbv
#define glVertexAttrib4Niv         OGL__glVertexAttrib4Niv
#define glVertexAttrib4Nsv         OGL__glVertexAttrib4Nsv
#define glVertexAttrib4Nub         OGL__glVertexAttrib4Nub
#define glVertexAttrib4Nubv        OGL__glVertexAttrib4Nubv
#define glVertexAttrib4Nuiv        OGL__glVertexAttrib4Nuiv
#define glVertexAttrib4Nusv        OGL__glVertexAttrib4Nusv
#define glVertexAttrib4bv          OGL__glVertexAttrib4bv
#define glVertexAttrib4d           OGL__glVertexAttrib4d
#define glVertexAttrib4dv          OGL__glVertexAttrib4dv
#define glVertexAttrib4f           OGL__glVertexAttrib4f
#define glVertexAttrib4fv          OGL__glVertexAttrib4fv
#define glVertexAttrib4iv          OGL__glVertexAttrib4iv
#define glVertexAttrib4s           OGL__glVertexAttrib4s
#define glVertexAttrib4sv          OGL__glVertexAttrib4sv
#define glVertexAttrib4ubv         OGL__glVertexAttrib4ubv
#define glVertexAttrib4uiv         OGL__glVertexAttrib4uiv
#define glVertexAttrib4usv         OGL__glVertexAttrib4usv
#define glVertexAttribPointer      OGL__glVertexAttribPointer

#endif // GL_VERSION_2_0

#endif // OPENGL_LOAD_GL_VERSION_2_0

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_LOAD_GL_VERSION_2_1

#ifndef GL_VERSION_2_1
#define GL_VERSION_2_1 1

#define GL_PIXEL_PACK_BUFFER                 0x88EB
#define GL_PIXEL_UNPACK_BUFFER               0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING         0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING       0x88EF
#define GL_FLOAT_MAT2x3                      0x8B65
#define GL_FLOAT_MAT2x4                      0x8B66
#define GL_FLOAT_MAT3x2                      0x8B67
#define GL_FLOAT_MAT3x4                      0x8B68
#define GL_FLOAT_MAT4x2                      0x8B69
#define GL_FLOAT_MAT4x3                      0x8B6A
#define GL_SRGB                              0x8C40
#define GL_SRGB8                             0x8C41
#define GL_SRGB_ALPHA                        0x8C42
#define GL_SRGB8_ALPHA8                      0x8C43
#define GL_COMPRESSED_SRGB                   0x8C48
#define GL_COMPRESSED_SRGB_ALPHA             0x8C49
#define GL_CURRENT_RASTER_SECONDARY_COLOR    0x845F
#define GL_SLUMINANCE_ALPHA                  0x8C44
#define GL_SLUMINANCE8_ALPHA8                0x8C45
#define GL_SLUMINANCE                        0x8C46
#define GL_SLUMINANCE8                       0x8C47
#define GL_COMPRESSED_SLUMINANCE             0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA       0x8C4B

OPENGL_INIT_PROC(glUniformMatrix2x3fv, void, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glUniformMatrix3x2fv, void, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glUniformMatrix2x4fv, void, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glUniformMatrix4x2fv, void, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glUniformMatrix3x4fv, void, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glUniformMatrix4x3fv, void, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);

#define glUniformMatrix2x3fv OGL__glUniformMatrix2x3fv
#define glUniformMatrix3x2fv OGL__glUniformMatrix3x2fv
#define glUniformMatrix2x4fv OGL__glUniformMatrix2x4fv
#define glUniformMatrix4x2fv OGL__glUniformMatrix4x2fv
#define glUniformMatrix3x4fv OGL__glUniformMatrix3x4fv
#define glUniformMatrix4x3fv OGL__glUniformMatrix4x3fv

#endif // GL_VERSION_2_1

#endif // OPENGL_LOAD_GL_VERSION_2_1

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_LOAD_GL_VERSION_3_0

#ifndef GL_VERSION_3_0
#define GL_VERSION_3_0 1

#define GL_COMPARE_REF_TO_TEXTURE                           0x884E
#define GL_CLIP_DISTANCE0                                   0x3000
#define GL_CLIP_DISTANCE1                                   0x3001
#define GL_CLIP_DISTANCE2                                   0x3002
#define GL_CLIP_DISTANCE3                                   0x3003
#define GL_CLIP_DISTANCE4                                   0x3004
#define GL_CLIP_DISTANCE5                                   0x3005
#define GL_CLIP_DISTANCE6                                   0x3006
#define GL_CLIP_DISTANCE7                                   0x3007
#define GL_MAX_CLIP_DISTANCES                               0x0D32
#define GL_MAJOR_VERSION                                    0x821B
#define GL_MINOR_VERSION                                    0x821C
#define GL_NUM_EXTENSIONS                                   0x821D
#define GL_CONTEXT_FLAGS                                    0x821E
#define GL_COMPRESSED_RED                                   0x8225
#define GL_COMPRESSED_RG                                    0x8226
#define GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT              0x00000001
#define GL_RGBA32F                                          0x8814
#define GL_RGB32F                                           0x8815
#define GL_RGBA16F                                          0x881A
#define GL_RGB16F                                           0x881B
#define GL_VERTEX_ATTRIB_ARRAY_INTEGER                      0x88FD
#define GL_MAX_ARRAY_TEXTURE_LAYERS                         0x88FF
#define GL_MIN_PROGRAM_TEXEL_OFFSET                         0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET                         0x8905
#define GL_CLAMP_READ_COLOR                                 0x891C
#define GL_FIXED_ONLY                                       0x891D
#define GL_MAX_VARYING_COMPONENTS                           0x8B4B
#define GL_TEXTURE_1D_ARRAY                                 0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY                           0x8C19
#define GL_TEXTURE_2D_ARRAY                                 0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY                           0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY                         0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY                         0x8C1D
#define GL_R11F_G11F_B10F                                   0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV                     0x8C3B
#define GL_RGB9_E5                                          0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV                         0x8C3E
#define GL_TEXTURE_SHARED_SIZE                              0x8C3F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH            0x8C76
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE                   0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS       0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS                      0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START                  0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE                   0x8C85
#define GL_PRIMITIVES_GENERATED                             0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN            0x8C88
#define GL_RASTERIZER_DISCARD                               0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS    0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS          0x8C8B
#define GL_INTERLEAVED_ATTRIBS                              0x8C8C
#define GL_SEPARATE_ATTRIBS                                 0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER                        0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING                0x8C8F
#define GL_RGBA32UI                                         0x8D70
#define GL_RGB32UI                                          0x8D71
#define GL_RGBA16UI                                         0x8D76
#define GL_RGB16UI                                          0x8D77
#define GL_RGBA8UI                                          0x8D7C
#define GL_RGB8UI                                           0x8D7D
#define GL_RGBA32I                                          0x8D82
#define GL_RGB32I                                           0x8D83
#define GL_RGBA16I                                          0x8D88
#define GL_RGB16I                                           0x8D89
#define GL_RGBA8I                                           0x8D8E
#define GL_RGB8I                                            0x8D8F
#define GL_RED_INTEGER                                      0x8D94
#define GL_GREEN_INTEGER                                    0x8D95
#define GL_BLUE_INTEGER                                     0x8D96
#define GL_RGB_INTEGER                                      0x8D98
#define GL_RGBA_INTEGER                                     0x8D99
#define GL_BGR_INTEGER                                      0x8D9A
#define GL_BGRA_INTEGER                                     0x8D9B
#define GL_SAMPLER_1D_ARRAY                                 0x8DC0
#define GL_SAMPLER_2D_ARRAY                                 0x8DC1
#define GL_SAMPLER_1D_ARRAY_SHADOW                          0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW                          0x8DC4
#define GL_SAMPLER_CUBE_SHADOW                              0x8DC5
#define GL_UNSIGNED_INT_VEC2                                0x8DC6
#define GL_UNSIGNED_INT_VEC3                                0x8DC7
#define GL_UNSIGNED_INT_VEC4                                0x8DC8
#define GL_INT_SAMPLER_1D                                   0x8DC9
#define GL_INT_SAMPLER_2D                                   0x8DCA
#define GL_INT_SAMPLER_3D                                   0x8DCB
#define GL_INT_SAMPLER_CUBE                                 0x8DCC
#define GL_INT_SAMPLER_1D_ARRAY                             0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY                             0x8DCF
#define GL_UNSIGNED_INT_SAMPLER_1D                          0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D                          0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D                          0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE                        0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY                    0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY                    0x8DD7
#define GL_QUERY_WAIT                                       0x8E13
#define GL_QUERY_NO_WAIT                                    0x8E14
#define GL_QUERY_BY_REGION_WAIT                             0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT                          0x8E16
#define GL_BUFFER_ACCESS_FLAGS                              0x911F
#define GL_BUFFER_MAP_LENGTH                                0x9120
#define GL_BUFFER_MAP_OFFSET                                0x9121
#define GL_DEPTH_COMPONENT32F                               0x8CAC
#define GL_DEPTH32F_STENCIL8                                0x8CAD
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV                   0x8DAD
#define GL_INVALID_FRAMEBUFFER_OPERATION                    0x0506
#define GL_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING            0x8210
#define GL_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE            0x8211
#define GL_FRAMEBUFFER_ATTACHMENT_RED_SIZE                  0x8212
#define GL_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE                0x8213
#define GL_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE                 0x8214
#define GL_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE                0x8215
#define GL_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE                0x8216
#define GL_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE              0x8217
#define GL_FRAMEBUFFER_DEFAULT                              0x8218
#define GL_FRAMEBUFFER_UNDEFINED                            0x8219
#define GL_DEPTH_STENCIL_ATTACHMENT                         0x821A
#define GL_MAX_RENDERBUFFER_SIZE                            0x84E8
#define GL_DEPTH_STENCIL                                    0x84F9
#define GL_UNSIGNED_INT_24_8                                0x84FA
#define GL_DEPTH24_STENCIL8                                 0x88F0
#define GL_TEXTURE_STENCIL_SIZE                             0x88F1
#define GL_TEXTURE_RED_TYPE                                 0x8C10
#define GL_TEXTURE_GREEN_TYPE                               0x8C11
#define GL_TEXTURE_BLUE_TYPE                                0x8C12
#define GL_TEXTURE_ALPHA_TYPE                               0x8C13
#define GL_TEXTURE_DEPTH_TYPE                               0x8C16
#define GL_UNSIGNED_NORMALIZED                              0x8C17
#define GL_FRAMEBUFFER_BINDING                              0x8CA6
#define GL_DRAW_FRAMEBUFFER_BINDING                         0x8CA6
#define GL_RENDERBUFFER_BINDING                             0x8CA7
#define GL_READ_FRAMEBUFFER                                 0x8CA8
#define GL_DRAW_FRAMEBUFFER                                 0x8CA9
#define GL_READ_FRAMEBUFFER_BINDING                         0x8CAA
#define GL_RENDERBUFFER_SAMPLES                             0x8CAB
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE               0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME               0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL             0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE     0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER             0x8CD4
#define GL_FRAMEBUFFER_COMPLETE                             0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT                0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT        0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER               0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER               0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED                          0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS                            0x8CDF
#define GL_COLOR_ATTACHMENT0                                0x8CE0
#define GL_COLOR_ATTACHMENT1                                0x8CE1
#define GL_COLOR_ATTACHMENT2                                0x8CE2
#define GL_COLOR_ATTACHMENT3                                0x8CE3
#define GL_COLOR_ATTACHMENT4                                0x8CE4
#define GL_COLOR_ATTACHMENT5                                0x8CE5
#define GL_COLOR_ATTACHMENT6                                0x8CE6
#define GL_COLOR_ATTACHMENT7                                0x8CE7
#define GL_COLOR_ATTACHMENT8                                0x8CE8
#define GL_COLOR_ATTACHMENT9                                0x8CE9
#define GL_COLOR_ATTACHMENT10                               0x8CEA
#define GL_COLOR_ATTACHMENT11                               0x8CEB
#define GL_COLOR_ATTACHMENT12                               0x8CEC
#define GL_COLOR_ATTACHMENT13                               0x8CED
#define GL_COLOR_ATTACHMENT14                               0x8CEE
#define GL_COLOR_ATTACHMENT15                               0x8CEF
#define GL_COLOR_ATTACHMENT16                               0x8CF0
#define GL_COLOR_ATTACHMENT17                               0x8CF1
#define GL_COLOR_ATTACHMENT18                               0x8CF2
#define GL_COLOR_ATTACHMENT19                               0x8CF3
#define GL_COLOR_ATTACHMENT20                               0x8CF4
#define GL_COLOR_ATTACHMENT21                               0x8CF5
#define GL_COLOR_ATTACHMENT22                               0x8CF6
#define GL_COLOR_ATTACHMENT23                               0x8CF7
#define GL_COLOR_ATTACHMENT24                               0x8CF8
#define GL_COLOR_ATTACHMENT25                               0x8CF9
#define GL_COLOR_ATTACHMENT26                               0x8CFA
#define GL_COLOR_ATTACHMENT27                               0x8CFB
#define GL_COLOR_ATTACHMENT28                               0x8CFC
#define GL_COLOR_ATTACHMENT29                               0x8CFD
#define GL_COLOR_ATTACHMENT30                               0x8CFE
#define GL_COLOR_ATTACHMENT31                               0x8CFF
#define GL_DEPTH_ATTACHMENT                                 0x8D00
#define GL_STENCIL_ATTACHMENT                               0x8D20
#define GL_FRAMEBUFFER                                      0x8D40
#define GL_RENDERBUFFER                                     0x8D41
#define GL_RENDERBUFFER_WIDTH                               0x8D42
#define GL_RENDERBUFFER_HEIGHT                              0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT                     0x8D44
#define GL_STENCIL_INDEX1                                   0x8D46
#define GL_STENCIL_INDEX4                                   0x8D47
#define GL_STENCIL_INDEX8                                   0x8D48
#define GL_STENCIL_INDEX16                                  0x8D49
#define GL_RENDERBUFFER_RED_SIZE                            0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE                          0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE                           0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE                          0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE                          0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE                        0x8D55
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE               0x8D56
#define GL_MAX_SAMPLES                                      0x8D57
#define GL_FRAMEBUFFER_SRGB                                 0x8DB9
#define GL_HALF_FLOAT                                       0x140B
#define GL_MAP_READ_BIT                                     0x0001
#define GL_MAP_WRITE_BIT                                    0x0002
#define GL_MAP_INVALIDATE_RANGE_BIT                         0x0004
#define GL_MAP_INVALIDATE_BUFFER_BIT                        0x0008
#define GL_MAP_FLUSH_EXPLICIT_BIT                           0x0010
#define GL_MAP_UNSYNCHRONIZED_BIT                           0x0020
#define GL_COMPRESSED_RED_RGTC1                             0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1                      0x8DBC
#define GL_COMPRESSED_RG_RGTC2                              0x8DBD
#define GL_COMPRESSED_SIGNED_RG_RGTC2                       0x8DBE
#define GL_RG                                               0x8227
#define GL_RG_INTEGER                                       0x8228
#define GL_R8                                               0x8229
#define GL_R16                                              0x822A
#define GL_RG8                                              0x822B
#define GL_RG16                                             0x822C
#define GL_R16F                                             0x822D
#define GL_R32F                                             0x822E
#define GL_RG16F                                            0x822F
#define GL_RG32F                                            0x8230
#define GL_R8I                                              0x8231
#define GL_R8UI                                             0x8232
#define GL_R16I                                             0x8233
#define GL_R16UI                                            0x8234
#define GL_R32I                                             0x8235
#define GL_R32UI                                            0x8236
#define GL_RG8I                                             0x8237
#define GL_RG8UI                                            0x8238
#define GL_RG16I                                            0x8239
#define GL_RG16UI                                           0x823A
#define GL_RG32I                                            0x823B
#define GL_RG32UI                                           0x823C
#define GL_VERTEX_ARRAY_BINDING                             0x85B5
#define GL_INDEX                                            0x8222
#define GL_TEXTURE_LUMINANCE_TYPE                           0x8C14
#define GL_TEXTURE_INTENSITY_TYPE                           0x8C15
#define GL_CLAMP_VERTEX_COLOR                               0x891A
#define GL_CLAMP_FRAGMENT_COLOR                             0x891B
#define GL_ALPHA_INTEGER                                    0x8D97

OPENGL_INIT_PROC(glColorMaski,                          void,           GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
OPENGL_INIT_PROC(glGetBooleani_v,                       void,           GLenum target, GLuint index, GLboolean *data);
OPENGL_INIT_PROC(glGetIntegeri_v,                       void,           GLenum target, GLuint index, GLint *data);
OPENGL_INIT_PROC(glEnablei,                             void,           GLenum target, GLuint index);
OPENGL_INIT_PROC(glDisablei,                            void,           GLenum target, GLuint index);
OPENGL_INIT_PROC(glIsEnabledi,                          GLboolean,      GLenum target, GLuint index);
OPENGL_INIT_PROC(glBeginTransformFeedback,              void,           GLenum primitiveMode);
OPENGL_INIT_PROC(glEndTransformFeedback,                void,           void);
OPENGL_INIT_PROC(glBindBufferRange,                     void,           GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
OPENGL_INIT_PROC(glBindBufferBase,                      void,           GLenum target, GLuint index, GLuint buffer);
OPENGL_INIT_PROC(glTransformFeedbackVaryings,           void,           GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
OPENGL_INIT_PROC(glGetTransformFeedbackVarying,         void,           GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
OPENGL_INIT_PROC(glClampColor,                          void,           GLenum target, GLenum clamp);
OPENGL_INIT_PROC(glBeginConditionalRender,              void,           GLuint id, GLenum mode);
OPENGL_INIT_PROC(glEndConditionalRender,                void,           void);
OPENGL_INIT_PROC(glVertexAttribIPointer,                void,           GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
OPENGL_INIT_PROC(glGetVertexAttribIiv,                  void,           GLuint index, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetVertexAttribIuiv,                 void,           GLuint index, GLenum pname, GLuint *params);
OPENGL_INIT_PROC(glVertexAttribI1i,                     void,           GLuint index, GLint x);
OPENGL_INIT_PROC(glVertexAttribI2i,                     void,           GLuint index, GLint x, GLint y);
OPENGL_INIT_PROC(glVertexAttribI3i,                     void,           GLuint index, GLint x, GLint y, GLint z);
OPENGL_INIT_PROC(glVertexAttribI4i,                     void,           GLuint index, GLint x, GLint y, GLint z, GLint w);
OPENGL_INIT_PROC(glVertexAttribI1ui,                    void,           GLuint index, GLuint x);
OPENGL_INIT_PROC(glVertexAttribI2ui,                    void,           GLuint index, GLuint x, GLuint y);
OPENGL_INIT_PROC(glVertexAttribI3ui,                    void,           GLuint index, GLuint x, GLuint y, GLuint z);
OPENGL_INIT_PROC(glVertexAttribI4ui,                    void,           GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
OPENGL_INIT_PROC(glVertexAttribI1iv,                    void,           GLuint index, const GLint *v);
OPENGL_INIT_PROC(glVertexAttribI2iv,                    void,           GLuint index, const GLint *v);
OPENGL_INIT_PROC(glVertexAttribI3iv,                    void,           GLuint index, const GLint *v);
OPENGL_INIT_PROC(glVertexAttribI4iv,                    void,           GLuint index, const GLint *v);
OPENGL_INIT_PROC(glVertexAttribI1uiv,                   void,           GLuint index, const GLuint *v);
OPENGL_INIT_PROC(glVertexAttribI2uiv,                   void,           GLuint index, const GLuint *v);
OPENGL_INIT_PROC(glVertexAttribI3uiv,                   void,           GLuint index, const GLuint *v);
OPENGL_INIT_PROC(glVertexAttribI4uiv,                   void,           GLuint index, const GLuint *v);
OPENGL_INIT_PROC(glVertexAttribI4bv,                    void,           GLuint index, const GLbyte *v);
OPENGL_INIT_PROC(glVertexAttribI4sv,                    void,           GLuint index, const GLshort *v);
OPENGL_INIT_PROC(glVertexAttribI4ubv,                   void,           GLuint index, const GLubyte *v);
OPENGL_INIT_PROC(glVertexAttribI4usv,                   void,           GLuint index, const GLushort *v);
OPENGL_INIT_PROC(glGetUniformuiv,                       void,           GLuint program, GLint location, GLuint *params);
OPENGL_INIT_PROC(glBindFragDataLocation,                void,           GLuint program, GLuint color, const GLchar *name);
OPENGL_INIT_PROC(glGetFragDataLocation,                 GLint,          GLuint program, const GLchar *name);
OPENGL_INIT_PROC(glUniform1ui,                          void,           GLint location, GLuint v0);
OPENGL_INIT_PROC(glUniform2ui,                          void,           GLint location, GLuint v0, GLuint v1);
OPENGL_INIT_PROC(glUniform3ui,                          void,           GLint location, GLuint v0, GLuint v1, GLuint v2);
OPENGL_INIT_PROC(glUniform4ui,                          void,           GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
OPENGL_INIT_PROC(glUniform1uiv,                         void,           GLint location, GLsizei count, const GLuint *value);
OPENGL_INIT_PROC(glUniform2uiv,                         void,           GLint location, GLsizei count, const GLuint *value);
OPENGL_INIT_PROC(glUniform3uiv,                         void,           GLint location, GLsizei count, const GLuint *value);
OPENGL_INIT_PROC(glUniform4uiv,                         void,           GLint location, GLsizei count, const GLuint *value);
OPENGL_INIT_PROC(glTexParameterIiv,                     void,           GLenum target, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glTexParameterIuiv,                    void,           GLenum target, GLenum pname, const GLuint *params);
OPENGL_INIT_PROC(glGetTexParameterIiv,                  void,           GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetTexParameterIuiv,                 void,           GLenum target, GLenum pname, GLuint *params);
OPENGL_INIT_PROC(glClearBufferiv,                       void,           GLenum buffer, GLint drawbuffer, const GLint *value);
OPENGL_INIT_PROC(glClearBufferuiv,                      void,           GLenum buffer, GLint drawbuffer, const GLuint *value);
OPENGL_INIT_PROC(glClearBufferfv,                       void,           GLenum buffer, GLint drawbuffer, const GLfloat *value);
OPENGL_INIT_PROC(glClearBufferfi,                       void,           GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
OPENGL_INIT_PROC(glGetStringi,                          const GLubyte*, GLenum name, GLuint index);
OPENGL_INIT_PROC(glIsRenderbuffer,                      GLboolean,      GLuint renderbuffer);
OPENGL_INIT_PROC(glBindRenderbuffer,                    void,           GLenum target, GLuint renderbuffer);
OPENGL_INIT_PROC(glDeleteRenderbuffers,                 void,           GLsizei n, const GLuint *renderbuffers);
OPENGL_INIT_PROC(glGenRenderbuffers,                    void,           GLsizei n, GLuint *renderbuffers);
OPENGL_INIT_PROC(glRenderbufferStorage,                 void,           GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glGetRenderbufferParameteriv,          void,           GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glIsFramebuffer,                       GLboolean,      GLuint framebuffer);
OPENGL_INIT_PROC(glBindFramebuffer,                     void,           GLenum target, GLuint framebuffer);
OPENGL_INIT_PROC(glDeleteFramebuffers,                  void,           GLsizei n, const GLuint *framebuffers);
OPENGL_INIT_PROC(glGenFramebuffers,                     void,           GLsizei n, GLuint *framebuffers);
OPENGL_INIT_PROC(glCheckFramebufferStatus,              GLenum,         GLenum target);
OPENGL_INIT_PROC(glFramebufferTexture1D,                void,           GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
OPENGL_INIT_PROC(glFramebufferTexture2D,                void,           GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
OPENGL_INIT_PROC(glFramebufferTexture3D,                void,           GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
OPENGL_INIT_PROC(glFramebufferRenderbuffer,             void,           GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
OPENGL_INIT_PROC(glGetFramebufferAttachmentParameteriv, void,           GLenum target, GLenum attachment, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGenerateMipmap,                      void,           GLenum target);
OPENGL_INIT_PROC(glBlitFramebuffer,                     void,           GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
OPENGL_INIT_PROC(glRenderbufferStorageMultisample,      void,           GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glFramebufferTextureLayer,             void,           GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
OPENGL_INIT_PROC(glMapBufferRange,                      void*,          GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
OPENGL_INIT_PROC(glFlushMappedBufferRange,              void,           GLenum target, GLintptr offset, GLsizeiptr length);
OPENGL_INIT_PROC(glBindVertexArray,                     void,           GLuint array);
OPENGL_INIT_PROC(glDeleteVertexArrays,                  void,           GLsizei n, const GLuint *arrays);
OPENGL_INIT_PROC(glGenVertexArrays,                     void,           GLsizei n, GLuint *arrays);
OPENGL_INIT_PROC(glIsVertexArray,                       GLboolean,      GLuint array);

#define glColorMaski                          OGL__glColorMaski
#define glGetBooleani_v                       OGL__glGetBooleani_v
#define glGetIntegeri_v                       OGL__glGetIntegeri_v
#define glEnablei                             OGL__glEnablei
#define glDisablei                            OGL__glDisablei
#define glIsEnabledi                          OGL__glIsEnabledi
#define glBeginTransformFeedback              OGL__glBeginTransformFeedback
#define glEndTransformFeedback                OGL__glEndTransformFeedback
#define glBindBufferRange                     OGL__glBindBufferRange
#define glBindBufferBase                      OGL__glBindBufferBase
#define glTransformFeedbackVaryings           OGL__glTransformFeedbackVaryings
#define glGetTransformFeedbackVarying         OGL__glGetTransformFeedbackVarying
#define glClampColor                          OGL__glClampColor
#define glBeginConditionalRender              OGL__glBeginConditionalRender
#define glEndConditionalRender                OGL__glEndConditionalRender
#define glVertexAttribIPointer                OGL__glVertexAttribIPointer
#define glGetVertexAttribIiv                  OGL__glGetVertexAttribIiv
#define glGetVertexAttribIuiv                 OGL__glGetVertexAttribIuiv
#define glVertexAttribI1i                     OGL__glVertexAttribI1i
#define glVertexAttribI2i                     OGL__glVertexAttribI2i
#define glVertexAttribI3i                     OGL__glVertexAttribI3i
#define glVertexAttribI4i                     OGL__glVertexAttribI4i
#define glVertexAttribI1ui                    OGL__glVertexAttribI1ui
#define glVertexAttribI2ui                    OGL__glVertexAttribI2ui
#define glVertexAttribI3ui                    OGL__glVertexAttribI3ui
#define glVertexAttribI4ui                    OGL__glVertexAttribI4ui
#define glVertexAttribI1iv                    OGL__glVertexAttribI1iv
#define glVertexAttribI2iv                    OGL__glVertexAttribI2iv
#define glVertexAttribI3iv                    OGL__glVertexAttribI3iv
#define glVertexAttribI4iv                    OGL__glVertexAttribI4iv
#define glVertexAttribI1uiv                   OGL__glVertexAttribI1uiv
#define glVertexAttribI2uiv                   OGL__glVertexAttribI2uiv
#define glVertexAttribI3uiv                   OGL__glVertexAttribI3uiv
#define glVertexAttribI4uiv                   OGL__glVertexAttribI4uiv
#define glVertexAttribI4bv                    OGL__glVertexAttribI4bv
#define glVertexAttribI4sv                    OGL__glVertexAttribI4sv
#define glVertexAttribI4ubv                   OGL__glVertexAttribI4ubv
#define glVertexAttribI4usv                   OGL__glVertexAttribI4usv
#define glGetUniformuiv                       OGL__glGetUniformuiv
#define glBindFragDataLocation                OGL__glBindFragDataLocation
#define glGetFragDataLocation                 OGL__glGetFragDataLocation
#define glUniform1ui                          OGL__glUniform1ui
#define glUniform2ui                          OGL__glUniform2ui
#define glUniform3ui                          OGL__glUniform3ui
#define glUniform4ui                          OGL__glUniform4ui
#define glUniform1uiv                         OGL__glUniform1uiv
#define glUniform2uiv                         OGL__glUniform2uiv
#define glUniform3uiv                         OGL__glUniform3uiv
#define glUniform4uiv                         OGL__glUniform4uiv
#define glTexParameterIiv                     OGL__glTexParameterIiv
#define glTexParameterIuiv                    OGL__glTexParameterIuiv
#define glGetTexParameterIiv                  OGL__glGetTexParameterIiv
#define glGetTexParameterIuiv                 OGL__glGetTexParameterIuiv
#define glClearBufferiv                       OGL__glClearBufferiv
#define glClearBufferuiv                      OGL__glClearBufferuiv
#define glClearBufferfv                       OGL__glClearBufferfv
#define glClearBufferfi                       OGL__glClearBufferfi
#define glGetStringi                          OGL__glGetStringi
#define glIsRenderbuffer                      OGL__glIsRenderbuffer
#define glBindRenderbuffer                    OGL__glBindRenderbuffer
#define glDeleteRenderbuffers                 OGL__glDeleteRenderbuffers
#define glGenRenderbuffers                    OGL__glGenRenderbuffers
#define glRenderbufferStorage                 OGL__glRenderbufferStorage
#define glGetRenderbufferParameteriv          OGL__glGetRenderbufferParameteriv
#define glIsFramebuffer                       OGL__glIsFramebuffer
#define glBindFramebuffer                     OGL__glBindFramebuffer
#define glDeleteFramebuffers                  OGL__glDeleteFramebuffers
#define glGenFramebuffers                     OGL__glGenFramebuffers
#define glCheckFramebufferStatus              OGL__glCheckFramebufferStatus
#define glFramebufferTexture1D                OGL__glFramebufferTexture1D
#define glFramebufferTexture2D                OGL__glFramebufferTexture2D
#define glFramebufferTexture3D                OGL__glFramebufferTexture3D
#define glFramebufferRenderbuffer             OGL__glFramebufferRenderbuffer
#define glGetFramebufferAttachmentParameteriv OGL__glGetFramebufferAttachmentParameteriv
#define glGenerateMipmap                      OGL__glGenerateMipmap
#define glBlitFramebuffer                     OGL__glBlitFramebuffer
#define glRenderbufferStorageMultisample      OGL__glRenderbufferStorageMultisample
#define glFramebufferTextureLayer             OGL__glFramebufferTextureLayer
#define glMapBufferRange                      OGL__glMapBufferRange
#define glFlushMappedBufferRange              OGL__glFlushMappedBufferRange
#define glBindVertexArray                     OGL__glBindVertexArray
#define glDeleteVertexArrays                  OGL__glDeleteVertexArrays
#define glGenVertexArrays                     OGL__glGenVertexArrays
#define glIsVertexArray                       OGL__glIsVertexArray

#endif // GL_VERSION_3_0

#endif // OPENGL_LOAD_GL_VERSION_3_0

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_LOAD_GL_VERSION_3_1

#ifndef GL_VERSION_3_1
#define GL_VERSION_3_1 1

#define GL_SAMPLER_2D_RECT                                0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW                         0x8B64
#define GL_SAMPLER_BUFFER                                 0x8DC2
#define GL_INT_SAMPLER_2D_RECT                            0x8DCD
#define GL_INT_SAMPLER_BUFFER                             0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT                   0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_BUFFER                    0x8DD8
#define GL_TEXTURE_BUFFER                                 0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE                        0x8C2B
#define GL_TEXTURE_BINDING_BUFFER                         0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING              0x8C2D
#define GL_TEXTURE_RECTANGLE                              0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE                      0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE                        0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE                     0x84F8
#define GL_R8_SNORM                                       0x8F94
#define GL_RG8_SNORM                                      0x8F95
#define GL_RGB8_SNORM                                     0x8F96
#define GL_RGBA8_SNORM                                    0x8F97
#define GL_R16_SNORM                                      0x8F98
#define GL_RG16_SNORM                                     0x8F99
#define GL_RGB16_SNORM                                    0x8F9A
#define GL_RGBA16_SNORM                                   0x8F9B
#define GL_SIGNED_NORMALIZED                              0x8F9C
#define GL_PRIMITIVE_RESTART                              0x8F9D
#define GL_PRIMITIVE_RESTART_INDEX                        0x8F9E
#define GL_COPY_READ_BUFFER                               0x8F36
#define GL_COPY_WRITE_BUFFER                              0x8F37
#define GL_UNIFORM_BUFFER                                 0x8A11
#define GL_UNIFORM_BUFFER_BINDING                         0x8A28
#define GL_UNIFORM_BUFFER_START                           0x8A29
#define GL_UNIFORM_BUFFER_SIZE                            0x8A2A
#define GL_MAX_VERTEX_UNIFORM_BLOCKS                      0x8A2B
#define GL_MAX_GEOMETRY_UNIFORM_BLOCKS                    0x8A2C
#define GL_MAX_FRAGMENT_UNIFORM_BLOCKS                    0x8A2D
#define GL_MAX_COMBINED_UNIFORM_BLOCKS                    0x8A2E
#define GL_MAX_UNIFORM_BUFFER_BINDINGS                    0x8A2F
#define GL_MAX_UNIFORM_BLOCK_SIZE                         0x8A30
#define GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS         0x8A31
#define GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS       0x8A32
#define GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS       0x8A33
#define GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT                0x8A34
#define GL_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH           0x8A35
#define GL_ACTIVE_UNIFORM_BLOCKS                          0x8A36
#define GL_UNIFORM_TYPE                                   0x8A37
#define GL_UNIFORM_SIZE                                   0x8A38
#define GL_UNIFORM_NAME_LENGTH                            0x8A39
#define GL_UNIFORM_BLOCK_INDEX                            0x8A3A
#define GL_UNIFORM_OFFSET                                 0x8A3B
#define GL_UNIFORM_ARRAY_STRIDE                           0x8A3C
#define GL_UNIFORM_MATRIX_STRIDE                          0x8A3D
#define GL_UNIFORM_IS_ROW_MAJOR                           0x8A3E
#define GL_UNIFORM_BLOCK_BINDING                          0x8A3F
#define GL_UNIFORM_BLOCK_DATA_SIZE                        0x8A40
#define GL_UNIFORM_BLOCK_NAME_LENGTH                      0x8A41
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORMS                  0x8A42
#define GL_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES           0x8A43
#define GL_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER      0x8A44
#define GL_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER    0x8A45
#define GL_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER    0x8A46
#define GL_INVALID_INDEX                                  0xFFFFFFFFu

OPENGL_INIT_PROC(glDrawArraysInstanced,       void,   GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
OPENGL_INIT_PROC(glDrawElementsInstanced,     void,   GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
OPENGL_INIT_PROC(glTexBuffer,                 void,   GLenum target, GLenum internalformat, GLuint buffer);
OPENGL_INIT_PROC(glPrimitiveRestartIndex,     void,   GLuint index);
OPENGL_INIT_PROC(glCopyBufferSubData,         void,   GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
OPENGL_INIT_PROC(glGetUniformIndices,         void,   GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
OPENGL_INIT_PROC(glGetActiveUniformsiv,       void,   GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetActiveUniformName,      void,   GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
OPENGL_INIT_PROC(glGetUniformBlockIndex,      GLuint, GLuint program, const GLchar *uniformBlockName);
OPENGL_INIT_PROC(glGetActiveUniformBlockiv,   void,   GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetActiveUniformBlockName, void,   GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
OPENGL_INIT_PROC(glUniformBlockBinding,       void,   GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);

#define glDrawArraysInstanced       OGL__glDrawArraysInstanced
#define glDrawElementsInstanced     OGL__glDrawElementsInstanced
#define glTexBuffer                 OGL__glTexBuffer
#define glPrimitiveRestartIndex     OGL__glPrimitiveRestartIndex
#define glCopyBufferSubData         OGL__glCopyBufferSubData
#define glGetUniformIndices         OGL__glGetUniformIndices
#define glGetActiveUniformsiv       OGL__glGetActiveUniformsiv
#define glGetActiveUniformName      OGL__glGetActiveUniformName
#define glGetUniformBlockIndex      OGL__glGetUniformBlockIndex
#define glGetActiveUniformBlockiv   OGL__glGetActiveUniformBlockiv
#define glGetActiveUniformBlockName OGL__glGetActiveUniformBlockName
#define glUniformBlockBinding       OGL__glUniformBlockBinding

#endif // GL_VERSION_3_1

#endif // OPENGL_LOAD_GL_VERSION_3_1

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_LOAD_GL_VERSION_3_2

#ifndef GL_VERSION_3_2
#define GL_VERSION_3_2 1

#define GL_CONTEXT_CORE_PROFILE_BIT                     0x00000001
#define GL_CONTEXT_COMPATIBILITY_PROFILE_BIT            0x00000002
#define GL_LINES_ADJACENCY                              0x000A
#define GL_LINE_STRIP_ADJACENCY                         0x000B
#define GL_TRIANGLES_ADJACENCY                          0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY                     0x000D
#define GL_PROGRAM_POINT_SIZE                           0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS             0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED               0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS         0x8DA8
#define GL_GEOMETRY_SHADER                              0x8DD9
#define GL_GEOMETRY_VERTICES_OUT                        0x8916
#define GL_GEOMETRY_INPUT_TYPE                          0x8917
#define GL_GEOMETRY_OUTPUT_TYPE                         0x8918
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS              0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES                 0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS         0x8DE1
#define GL_MAX_VERTEX_OUTPUT_COMPONENTS                 0x9122
#define GL_MAX_GEOMETRY_INPUT_COMPONENTS                0x9123
#define GL_MAX_GEOMETRY_OUTPUT_COMPONENTS               0x9124
#define GL_MAX_FRAGMENT_INPUT_COMPONENTS                0x9125
#define GL_CONTEXT_PROFILE_MASK                         0x9126
#define GL_DEPTH_CLAMP                                  0x864F
#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION     0x8E4C
#define GL_FIRST_VERTEX_CONVENTION                      0x8E4D
#define GL_LAST_VERTEX_CONVENTION                       0x8E4E
#define GL_PROVOKING_VERTEX                             0x8E4F
#define GL_TEXTURE_CUBE_MAP_SEAMLESS                    0x884F
#define GL_MAX_SERVER_WAIT_TIMEOUT                      0x9111
#define GL_OBJECT_TYPE                                  0x9112
#define GL_SYNC_CONDITION                               0x9113
#define GL_SYNC_STATUS                                  0x9114
#define GL_SYNC_FLAGS                                   0x9115
#define GL_SYNC_FENCE                                   0x9116
#define GL_SYNC_GPU_COMMANDS_COMPLETE                   0x9117
#define GL_UNSIGNALED                                   0x9118
#define GL_SIGNALED                                     0x9119
#define GL_ALREADY_SIGNALED                             0x911A
#define GL_TIMEOUT_EXPIRED                              0x911B
#define GL_CONDITION_SATISFIED                          0x911C
#define GL_WAIT_FAILED                                  0x911D
#define GL_TIMEOUT_IGNORED                              0xFFFFFFFFFFFFFFFFull
#define GL_SYNC_FLUSH_COMMANDS_BIT                      0x00000001
#define GL_SAMPLE_POSITION                              0x8E50
#define GL_SAMPLE_MASK                                  0x8E51
#define GL_SAMPLE_MASK_VALUE                            0x8E52
#define GL_MAX_SAMPLE_MASK_WORDS                        0x8E59
#define GL_TEXTURE_2D_MULTISAMPLE                       0x9100
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE                 0x9101
#define GL_TEXTURE_2D_MULTISAMPLE_ARRAY                 0x9102
#define GL_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY           0x9103
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE               0x9104
#define GL_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY         0x9105
#define GL_TEXTURE_SAMPLES                              0x9106
#define GL_TEXTURE_FIXED_SAMPLE_LOCATIONS               0x9107
#define GL_SAMPLER_2D_MULTISAMPLE                       0x9108
#define GL_INT_SAMPLER_2D_MULTISAMPLE                   0x9109
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE          0x910A
#define GL_SAMPLER_2D_MULTISAMPLE_ARRAY                 0x910B
#define GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY             0x910C
#define GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY    0x910D
#define GL_MAX_COLOR_TEXTURE_SAMPLES                    0x910E
#define GL_MAX_DEPTH_TEXTURE_SAMPLES                    0x910F
#define GL_MAX_INTEGER_SAMPLES                          0x9110

OPENGL_INIT_PROC(glDrawElementsBaseVertex,          void,      GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
OPENGL_INIT_PROC(glDrawRangeElementsBaseVertex,     void,      GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
OPENGL_INIT_PROC(glDrawElementsInstancedBaseVertex, void,      GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
OPENGL_INIT_PROC(glMultiDrawElementsBaseVertex,     void,      GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
OPENGL_INIT_PROC(glProvokingVertex,                 void,      GLenum mode);
OPENGL_INIT_PROC(glFenceSync,                       GLsync,    GLenum condition, GLbitfield flags);
OPENGL_INIT_PROC(glIsSync,                          GLboolean, GLsync sync);
OPENGL_INIT_PROC(glDeleteSync,                      void,      GLsync sync);
OPENGL_INIT_PROC(glClientWaitSync,                  GLenum,    GLsync sync, GLbitfield flags, GLuint64 timeout);
OPENGL_INIT_PROC(glWaitSync,                        void,      GLsync sync, GLbitfield flags, GLuint64 timeout);
OPENGL_INIT_PROC(glGetInteger64v,                   void,      GLenum pname, GLint64 *data);
OPENGL_INIT_PROC(glGetSynciv,                       void,      GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
OPENGL_INIT_PROC(glGetInteger64i_v,                 void,      GLenum target, GLuint index, GLint64 *data);
OPENGL_INIT_PROC(glGetBufferParameteri64v,          void,      GLenum target, GLenum pname, GLint64 *params);
OPENGL_INIT_PROC(glFramebufferTexture,              void,      GLenum target, GLenum attachment, GLuint texture, GLint level);
OPENGL_INIT_PROC(glTexImage2DMultisample,           void,      GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
OPENGL_INIT_PROC(glTexImage3DMultisample,           void,      GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
OPENGL_INIT_PROC(glGetMultisamplefv,                void,      GLenum pname, GLuint index, GLfloat *val);
OPENGL_INIT_PROC(glSampleMaski,                     void,      GLuint maskNumber, GLbitfield mask);

#define glDrawElementsBaseVertex          OGL__glDrawElementsBaseVertex
#define glDrawRangeElementsBaseVertex     OGL__glDrawRangeElementsBaseVertex
#define glDrawElementsInstancedBaseVertex OGL__glDrawElementsInstancedBaseVertex
#define glMultiDrawElementsBaseVertex     OGL__glMultiDrawElementsBaseVertex
#define glProvokingVertex                 OGL__glProvokingVertex
#define glFenceSync                       OGL__glFenceSync
#define glIsSync                          OGL__glIsSync
#define glDeleteSync                      OGL__glDeleteSync
#define glClientWaitSync                  OGL__glClientWaitSync
#define glWaitSync                        OGL__glWaitSync
#define glGetInteger64v                   OGL__glGetInteger64v
#define glGetSynciv                       OGL__glGetSynciv
#define glGetInteger64i_v                 OGL__glGetInteger64i_v
#define glGetBufferParameteri64v          OGL__glGetBufferParameteri64v
#define glFramebufferTexture              OGL__glFramebufferTexture
#define glTexImage2DMultisample           OGL__glTexImage2DMultisample
#define glTexImage3DMultisample           OGL__glTexImage3DMultisample
#define glGetMultisamplefv                OGL__glGetMultisamplefv
#define glSampleMaski                     OGL__glSampleMaski

#endif // GL_VERSION_3_2

#endif // OPENGL_LOAD_GL_VERSION_3_2

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_LOAD_GL_VERSION_3_3

#ifndef GL_VERSION_3_3
#define GL_VERSION_3_3 1

#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR     0x88FE
#define GL_SRC1_COLOR                      0x88F9
#define GL_ONE_MINUS_SRC1_COLOR            0x88FA
#define GL_ONE_MINUS_SRC1_ALPHA            0x88FB
#define GL_MAX_DUAL_SOURCE_DRAW_BUFFERS    0x88FC
#define GL_ANY_SAMPLES_PASSED              0x8C2F
#define GL_SAMPLER_BINDING                 0x8919
#define GL_RGB10_A2UI                      0x906F
#define GL_TEXTURE_SWIZZLE_R               0x8E42
#define GL_TEXTURE_SWIZZLE_G               0x8E43
#define GL_TEXTURE_SWIZZLE_B               0x8E44
#define GL_TEXTURE_SWIZZLE_A               0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA            0x8E46
#define GL_TIME_ELAPSED                    0x88BF
#define GL_TIMESTAMP                       0x8E28
#define GL_INT_2_10_10_10_REV              0x8D9F

OPENGL_INIT_PROC(glBindFragDataLocationIndexed, void,      GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
OPENGL_INIT_PROC(glGetFragDataIndex,            GLint,     GLuint program, const GLchar *name);
OPENGL_INIT_PROC(glGenSamplers,                 void,      GLsizei count, GLuint *samplers);
OPENGL_INIT_PROC(glDeleteSamplers,              void,      GLsizei count, const GLuint *samplers);
OPENGL_INIT_PROC(glIsSampler,                   GLboolean, GLuint sampler);
OPENGL_INIT_PROC(glBindSampler,                 void,      GLuint unit, GLuint sampler);
OPENGL_INIT_PROC(glSamplerParameteri,           void,      GLuint sampler, GLenum pname, GLint param);
OPENGL_INIT_PROC(glSamplerParameteriv,          void,      GLuint sampler, GLenum pname, const GLint *param);
OPENGL_INIT_PROC(glSamplerParameterf,           void,      GLuint sampler, GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glSamplerParameterfv,          void,      GLuint sampler, GLenum pname, const GLfloat *param);
OPENGL_INIT_PROC(glSamplerParameterIiv,         void,      GLuint sampler, GLenum pname, const GLint *param);
OPENGL_INIT_PROC(glSamplerParameterIuiv,        void,      GLuint sampler, GLenum pname, const GLuint *param);
OPENGL_INIT_PROC(glGetSamplerParameteriv,       void,      GLuint sampler, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetSamplerParameterIiv,      void,      GLuint sampler, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetSamplerParameterfv,       void,      GLuint sampler, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetSamplerParameterIuiv,     void,      GLuint sampler, GLenum pname, GLuint *params);
OPENGL_INIT_PROC(glQueryCounter,                void,      GLuint id, GLenum target);
OPENGL_INIT_PROC(glGetQueryObjecti64v,          void,      GLuint id, GLenum pname, GLint64 *params);
OPENGL_INIT_PROC(glGetQueryObjectui64v,         void,      GLuint id, GLenum pname, GLuint64 *params);
OPENGL_INIT_PROC(glVertexAttribDivisor,         void,      GLuint index, GLuint divisor);
OPENGL_INIT_PROC(glVertexAttribP1ui,            void,      GLuint index, GLenum type, GLboolean normalized, GLuint value);
OPENGL_INIT_PROC(glVertexAttribP1uiv,           void,      GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
OPENGL_INIT_PROC(glVertexAttribP2ui,            void,      GLuint index, GLenum type, GLboolean normalized, GLuint value);
OPENGL_INIT_PROC(glVertexAttribP2uiv,           void,      GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
OPENGL_INIT_PROC(glVertexAttribP3ui,            void,      GLuint index, GLenum type, GLboolean normalized, GLuint value);
OPENGL_INIT_PROC(glVertexAttribP3uiv,           void,      GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
OPENGL_INIT_PROC(glVertexAttribP4ui,            void,      GLuint index, GLenum type, GLboolean normalized, GLuint value);
OPENGL_INIT_PROC(glVertexAttribP4uiv,           void,      GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
#ifdef OPENGL_USE_COMPATIBILITY_PROFILE
OPENGL_INIT_PROC(glVertexP2ui,                  void,      GLenum type, GLuint value);
OPENGL_INIT_PROC(glVertexP2uiv,                 void,      GLenum type, const GLuint *value);
OPENGL_INIT_PROC(glVertexP3ui,                  void,      GLenum type, GLuint value);
OPENGL_INIT_PROC(glVertexP3uiv,                 void,      GLenum type, const GLuint *value);
OPENGL_INIT_PROC(glVertexP4ui,                  void,      GLenum type, GLuint value);
OPENGL_INIT_PROC(glVertexP4uiv,                 void,      GLenum type, const GLuint *value);
OPENGL_INIT_PROC(glTexCoordP1ui,                void,      GLenum type, GLuint coords);
OPENGL_INIT_PROC(glTexCoordP1uiv,               void,      GLenum type, const GLuint *coords);
OPENGL_INIT_PROC(glTexCoordP2ui,                void,      GLenum type, GLuint coords);
OPENGL_INIT_PROC(glTexCoordP2uiv,               void,      GLenum type, const GLuint *coords);
OPENGL_INIT_PROC(glTexCoordP3ui,                void,      GLenum type, GLuint coords);
OPENGL_INIT_PROC(glTexCoordP3uiv,               void,      GLenum type, const GLuint *coords);
OPENGL_INIT_PROC(glTexCoordP4ui,                void,      GLenum type, GLuint coords);
OPENGL_INIT_PROC(glTexCoordP4uiv,               void,      GLenum type, const GLuint *coords);
OPENGL_INIT_PROC(glMultiTexCoordP1ui,           void,      GLenum texture, GLenum type, GLuint coords);
OPENGL_INIT_PROC(glMultiTexCoordP1uiv,          void,      GLenum texture, GLenum type, const GLuint *coords);
OPENGL_INIT_PROC(glMultiTexCoordP2ui,           void,      GLenum texture, GLenum type, GLuint coords);
OPENGL_INIT_PROC(glMultiTexCoordP2uiv,          void,      GLenum texture, GLenum type, const GLuint *coords);
OPENGL_INIT_PROC(glMultiTexCoordP3ui,           void,      GLenum texture, GLenum type, GLuint coords);
OPENGL_INIT_PROC(glMultiTexCoordP3uiv,          void,      GLenum texture, GLenum type, const GLuint *coords);
OPENGL_INIT_PROC(glMultiTexCoordP4ui,           void,      GLenum texture, GLenum type, GLuint coords);
OPENGL_INIT_PROC(glMultiTexCoordP4uiv,          void,      GLenum texture, GLenum type, const GLuint *coords);
OPENGL_INIT_PROC(glNormalP3ui,                  void,      GLenum type, GLuint coords);
OPENGL_INIT_PROC(glNormalP3uiv,                 void,      GLenum type, const GLuint *coords);
OPENGL_INIT_PROC(glColorP3ui,                   void,      GLenum type, GLuint color);
OPENGL_INIT_PROC(glColorP3uiv,                  void,      GLenum type, const GLuint *color);
OPENGL_INIT_PROC(glColorP4ui,                   void,      GLenum type, GLuint color);
OPENGL_INIT_PROC(glColorP4uiv,                  void,      GLenum type, const GLuint *color);
OPENGL_INIT_PROC(glSecondaryColorP3ui,          void,      GLenum type, GLuint color);
OPENGL_INIT_PROC(glSecondaryColorP3uiv,         void,      GLenum type, const GLuint *color);
#endif // OPENGL_USE_COMPATIBILITY_PROFILE

#define glBindFragDataLocationIndexed OGL__glBindFragDataLocationIndexed
#define glGetFragDataIndex            OGL__glGetFragDataIndex
#define glGenSamplers                 OGL__glGenSamplers
#define glDeleteSamplers              OGL__glDeleteSamplers
#define glIsSampler                   OGL__glIsSampler
#define glBindSampler                 OGL__glBindSampler
#define glSamplerParameteri           OGL__glSamplerParameteri
#define glSamplerParameteriv          OGL__glSamplerParameteriv
#define glSamplerParameterf           OGL__glSamplerParameterf
#define glSamplerParameterfv          OGL__glSamplerParameterfv
#define glSamplerParameterIiv         OGL__glSamplerParameterIiv
#define glSamplerParameterIuiv        OGL__glSamplerParameterIuiv
#define glGetSamplerParameteriv       OGL__glGetSamplerParameteriv
#define glGetSamplerParameterIiv      OGL__glGetSamplerParameterIiv
#define glGetSamplerParameterfv       OGL__glGetSamplerParameterfv
#define glGetSamplerParameterIuiv     OGL__glGetSamplerParameterIuiv
#define glQueryCounter                OGL__glQueryCounter
#define glGetQueryObjecti64v          OGL__glGetQueryObjecti64v
#define glGetQueryObjectui64v         OGL__glGetQueryObjectui64v
#define glVertexAttribDivisor         OGL__glVertexAttribDivisor
#define glVertexAttribP1ui            OGL__glVertexAttribP1ui
#define glVertexAttribP1uiv           OGL__glVertexAttribP1uiv
#define glVertexAttribP2ui            OGL__glVertexAttribP2ui
#define glVertexAttribP2uiv           OGL__glVertexAttribP2uiv
#define glVertexAttribP3ui            OGL__glVertexAttribP3ui
#define glVertexAttribP3uiv           OGL__glVertexAttribP3uiv
#define glVertexAttribP4ui            OGL__glVertexAttribP4ui
#define glVertexAttribP4uiv           OGL__glVertexAttribP4uiv
#ifdef OPENGL_USE_COMPATIBILITY_PROFILE
#define glVertexP2ui                  OGL__glVertexP2ui
#define glVertexP2uiv                 OGL__glVertexP2uiv
#define glVertexP3ui                  OGL__glVertexP3ui
#define glVertexP3uiv                 OGL__glVertexP3uiv
#define glVertexP4ui                  OGL__glVertexP4ui
#define glVertexP4uiv                 OGL__glVertexP4uiv
#define glTexCoordP1ui                OGL__glTexCoordP1ui
#define glTexCoordP1uiv               OGL__glTexCoordP1uiv
#define glTexCoordP2ui                OGL__glTexCoordP2ui
#define glTexCoordP2uiv               OGL__glTexCoordP2uiv
#define glTexCoordP3ui                OGL__glTexCoordP3ui
#define glTexCoordP3uiv               OGL__glTexCoordP3uiv
#define glTexCoordP4ui                OGL__glTexCoordP4ui
#define glTexCoordP4uiv               OGL__glTexCoordP4uiv
#define glMultiTexCoordP1ui           OGL__glMultiTexCoordP1ui
#define glMultiTexCoordP1uiv          OGL__glMultiTexCoordP1uiv
#define glMultiTexCoordP2ui           OGL__glMultiTexCoordP2ui
#define glMultiTexCoordP2uiv          OGL__glMultiTexCoordP2uiv
#define glMultiTexCoordP3ui           OGL__glMultiTexCoordP3ui
#define glMultiTexCoordP3uiv          OGL__glMultiTexCoordP3uiv
#define glMultiTexCoordP4ui           OGL__glMultiTexCoordP4ui
#define glMultiTexCoordP4uiv          OGL__glMultiTexCoordP4uiv
#define glNormalP3ui                  OGL__glNormalP3ui
#define glNormalP3uiv                 OGL__glNormalP3uiv
#define glColorP3ui                   OGL__glColorP3ui
#define glColorP3uiv                  OGL__glColorP3uiv
#define glColorP4ui                   OGL__glColorP4ui
#define glColorP4uiv                  OGL__glColorP4uiv
#define glSecondaryColorP3ui          OGL__glSecondaryColorP3ui
#define glSecondaryColorP3uiv         OGL__glSecondaryColorP3uiv
#endif // OPENGL_USE_COMPATIBILITY_PROFILE

#endif // GL_VERSION_3_3

#endif // OPENGL_LOAD_GL_VERSION_3_3

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_LOAD_GL_VERSION_4_0

#ifndef GL_VERSION_4_0
#define GL_VERSION_4_0 1

#define GL_SAMPLE_SHADING                                        0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE                              0x8C37
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET                     0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET                     0x8E5F
#define GL_TEXTURE_CUBE_MAP_ARRAY                                0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY                        0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY                          0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY                                0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW                         0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY                            0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY                   0x900F
#define GL_DRAW_INDIRECT_BUFFER                                  0x8F3F
#define GL_DRAW_INDIRECT_BUFFER_BINDING                          0x8F43
#define GL_GEOMETRY_SHADER_INVOCATIONS                           0x887F
#define GL_MAX_GEOMETRY_SHADER_INVOCATIONS                       0x8E5A
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET                     0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET                     0x8E5C
#define GL_FRAGMENT_INTERPOLATION_OFFSET_BITS                    0x8E5D
#define GL_MAX_VERTEX_STREAMS                                    0x8E71
#define GL_DOUBLE_VEC2                                           0x8FFC
#define GL_DOUBLE_VEC3                                           0x8FFD
#define GL_DOUBLE_VEC4                                           0x8FFE
#define GL_DOUBLE_MAT2                                           0x8F46
#define GL_DOUBLE_MAT3                                           0x8F47
#define GL_DOUBLE_MAT4                                           0x8F48
#define GL_DOUBLE_MAT2x3                                         0x8F49
#define GL_DOUBLE_MAT2x4                                         0x8F4A
#define GL_DOUBLE_MAT3x2                                         0x8F4B
#define GL_DOUBLE_MAT3x4                                         0x8F4C
#define GL_DOUBLE_MAT4x2                                         0x8F4D
#define GL_DOUBLE_MAT4x3                                         0x8F4E
#define GL_ACTIVE_SUBROUTINES                                    0x8DE5
#define GL_ACTIVE_SUBROUTINE_UNIFORMS                            0x8DE6
#define GL_ACTIVE_SUBROUTINE_UNIFORM_LOCATIONS                   0x8E47
#define GL_ACTIVE_SUBROUTINE_MAX_LENGTH                          0x8E48
#define GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH                  0x8E49
#define GL_MAX_SUBROUTINES                                       0x8DE7
#define GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS                      0x8DE8
#define GL_NUM_COMPATIBLE_SUBROUTINES                            0x8E4A
#define GL_COMPATIBLE_SUBROUTINES                                0x8E4B
#define GL_PATCHES                                               0x000E
#define GL_PATCH_VERTICES                                        0x8E72
#define GL_PATCH_DEFAULT_INNER_LEVEL                             0x8E73
#define GL_PATCH_DEFAULT_OUTER_LEVEL                             0x8E74
#define GL_TESS_CONTROL_OUTPUT_VERTICES                          0x8E75
#define GL_TESS_GEN_MODE                                         0x8E76
#define GL_TESS_GEN_SPACING                                      0x8E77
#define GL_TESS_GEN_VERTEX_ORDER                                 0x8E78
#define GL_TESS_GEN_POINT_MODE                                   0x8E79
#define GL_ISOLINES                                              0x8E7A
#define GL_FRACTIONAL_ODD                                        0x8E7B
#define GL_FRACTIONAL_EVEN                                       0x8E7C
#define GL_MAX_PATCH_VERTICES                                    0x8E7D
#define GL_MAX_TESS_GEN_LEVEL                                    0x8E7E
#define GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS                   0x8E7F
#define GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS                0x8E80
#define GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS                  0x8E81
#define GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS               0x8E82
#define GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS                    0x8E83
#define GL_MAX_TESS_PATCH_COMPONENTS                             0x8E84
#define GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS              0x8E85
#define GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS                 0x8E86
#define GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS                       0x8E89
#define GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS                    0x8E8A
#define GL_MAX_TESS_CONTROL_INPUT_COMPONENTS                     0x886C
#define GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS                  0x886D
#define GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS          0x8E1E
#define GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS       0x8E1F
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_CONTROL_SHADER       0x84F0
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TESS_EVALUATION_SHADER    0x84F1
#define GL_TESS_EVALUATION_SHADER                                0x8E87
#define GL_TESS_CONTROL_SHADER                                   0x8E88
#define GL_TRANSFORM_FEEDBACK                                    0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED                      0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE                      0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING                            0x8E25
#define GL_MAX_TRANSFORM_FEEDBACK_BUFFERS                        0x8E70

OPENGL_INIT_PROC(glMinSampleShading,               void,      GLfloat value);
OPENGL_INIT_PROC(glBlendEquationi,                 void,      GLuint buf, GLenum mode);
OPENGL_INIT_PROC(glBlendEquationSeparatei,         void,      GLuint buf, GLenum modeRGB, GLenum modeAlpha);
OPENGL_INIT_PROC(glBlendFunci,                     void,      GLuint buf, GLenum src, GLenum dst);
OPENGL_INIT_PROC(glBlendFuncSeparatei,             void,      GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
OPENGL_INIT_PROC(glDrawArraysIndirect,             void,      GLenum mode, const void *indirect);
OPENGL_INIT_PROC(glDrawElementsIndirect,           void,      GLenum mode, GLenum type, const void *indirect);
OPENGL_INIT_PROC(glUniform1d,                      void,      GLint location, GLdouble x);
OPENGL_INIT_PROC(glUniform2d,                      void,      GLint location, GLdouble x, GLdouble y);
OPENGL_INIT_PROC(glUniform3d,                      void,      GLint location, GLdouble x, GLdouble y, GLdouble z);
OPENGL_INIT_PROC(glUniform4d,                      void,      GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
OPENGL_INIT_PROC(glUniform1dv,                     void,      GLint location, GLsizei count, const GLdouble *value);
OPENGL_INIT_PROC(glUniform2dv,                     void,      GLint location, GLsizei count, const GLdouble *value);
OPENGL_INIT_PROC(glUniform3dv,                     void,      GLint location, GLsizei count, const GLdouble *value);
OPENGL_INIT_PROC(glUniform4dv,                     void,      GLint location, GLsizei count, const GLdouble *value);
OPENGL_INIT_PROC(glUniformMatrix2dv,               void,      GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glUniformMatrix3dv,               void,      GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glUniformMatrix4dv,               void,      GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glUniformMatrix2x3dv,             void,      GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glUniformMatrix2x4dv,             void,      GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glUniformMatrix3x2dv,             void,      GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glUniformMatrix3x4dv,             void,      GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glUniformMatrix4x2dv,             void,      GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glUniformMatrix4x3dv,             void,      GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glGetUniformdv,                   void,      GLuint program, GLint location, GLdouble *params);
OPENGL_INIT_PROC(glGetSubroutineUniformLocation,   GLint,     GLuint program, GLenum shadertype, const GLchar *name);
OPENGL_INIT_PROC(glGetSubroutineIndex,             GLuint,    GLuint program, GLenum shadertype, const GLchar *name);
OPENGL_INIT_PROC(glGetActiveSubroutineUniformiv,   void,      GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
OPENGL_INIT_PROC(glGetActiveSubroutineUniformName, void,      GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
OPENGL_INIT_PROC(glGetActiveSubroutineName,        void,      GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
OPENGL_INIT_PROC(glUniformSubroutinesuiv,          void,      GLenum shadertype, GLsizei count, const GLuint *indices);
OPENGL_INIT_PROC(glGetUniformSubroutineuiv,        void,      GLenum shadertype, GLint location, GLuint *params);
OPENGL_INIT_PROC(glGetProgramStageiv,              void,      GLuint program, GLenum shadertype, GLenum pname, GLint *values);
OPENGL_INIT_PROC(glPatchParameteri,                void,      GLenum pname, GLint value);
OPENGL_INIT_PROC(glPatchParameterfv,               void,      GLenum pname, const GLfloat *values);
OPENGL_INIT_PROC(glBindTransformFeedback,          void,      GLenum target, GLuint id);
OPENGL_INIT_PROC(glDeleteTransformFeedbacks,       void,      GLsizei n, const GLuint *ids);
OPENGL_INIT_PROC(glGenTransformFeedbacks,          void,      GLsizei n, GLuint *ids);
OPENGL_INIT_PROC(glIsTransformFeedback,            GLboolean, GLuint id);
OPENGL_INIT_PROC(glPauseTransformFeedback,         void,      void);
OPENGL_INIT_PROC(glResumeTransformFeedback,        void,      void);
OPENGL_INIT_PROC(glDrawTransformFeedback,          void,      GLenum mode, GLuint id);
OPENGL_INIT_PROC(glDrawTransformFeedbackStream,    void,      GLenum mode, GLuint id, GLuint stream);
OPENGL_INIT_PROC(glBeginQueryIndexed,              void,      GLenum target, GLuint index, GLuint id);
OPENGL_INIT_PROC(glEndQueryIndexed,                void,      GLenum target, GLuint index);
OPENGL_INIT_PROC(glGetQueryIndexediv,              void,      GLenum target, GLuint index, GLenum pname, GLint *params);

#define glMinSampleShading               OGL__glMinSampleShading
#define glBlendEquationi                 OGL__glBlendEquationi
#define glBlendEquationSeparatei         OGL__glBlendEquationSeparatei
#define glBlendFunci                     OGL__glBlendFunci
#define glBlendFuncSeparatei             OGL__glBlendFuncSeparatei
#define glDrawArraysIndirect             OGL__glDrawArraysIndirect
#define glDrawElementsIndirect           OGL__glDrawElementsIndirect
#define glUniform1d                      OGL__glUniform1d
#define glUniform2d                      OGL__glUniform2d
#define glUniform3d                      OGL__glUniform3d
#define glUniform4d                      OGL__glUniform4d
#define glUniform1dv                     OGL__glUniform1dv
#define glUniform2dv                     OGL__glUniform2dv
#define glUniform3dv                     OGL__glUniform3dv
#define glUniform4dv                     OGL__glUniform4dv
#define glUniformMatrix2dv               OGL__glUniformMatrix2dv
#define glUniformMatrix3dv               OGL__glUniformMatrix3dv
#define glUniformMatrix4dv               OGL__glUniformMatrix4dv
#define glUniformMatrix2x3dv             OGL__glUniformMatrix2x3dv
#define glUniformMatrix2x4dv             OGL__glUniformMatrix2x4dv
#define glUniformMatrix3x2dv             OGL__glUniformMatrix3x2dv
#define glUniformMatrix3x4dv             OGL__glUniformMatrix3x4dv
#define glUniformMatrix4x2dv             OGL__glUniformMatrix4x2dv
#define glUniformMatrix4x3dv             OGL__glUniformMatrix4x3dv
#define glGetUniformdv                   OGL__glGetUniformdv
#define glGetSubroutineUniformLocation   OGL__glGetSubroutineUniformLocation
#define glGetSubroutineIndex             OGL__glGetSubroutineIndex
#define glGetActiveSubroutineUniformiv   OGL__glGetActiveSubroutineUniformiv
#define glGetActiveSubroutineUniformName OGL__glGetActiveSubroutineUniformName
#define glGetActiveSubroutineName        OGL__glGetActiveSubroutineName
#define glUniformSubroutinesuiv          OGL__glUniformSubroutinesuiv
#define glGetUniformSubroutineuiv        OGL__glGetUniformSubroutineuiv
#define glGetProgramStageiv              OGL__glGetProgramStageiv
#define glPatchParameteri                OGL__glPatchParameteri
#define glPatchParameterfv               OGL__glPatchParameterfv
#define glBindTransformFeedback          OGL__glBindTransformFeedback
#define glDeleteTransformFeedbacks       OGL__glDeleteTransformFeedbacks
#define glGenTransformFeedbacks          OGL__glGenTransformFeedbacks
#define glIsTransformFeedback            OGL__glIsTransformFeedback
#define glPauseTransformFeedback         OGL__glPauseTransformFeedback
#define glResumeTransformFeedback        OGL__glResumeTransformFeedback
#define glDrawTransformFeedback          OGL__glDrawTransformFeedback
#define glDrawTransformFeedbackStream    OGL__glDrawTransformFeedbackStream
#define glBeginQueryIndexed              OGL__glBeginQueryIndexed
#define glEndQueryIndexed                OGL__glEndQueryIndexed
#define glGetQueryIndexediv              OGL__glGetQueryIndexediv

#endif // GL_VERSION_4_0

#endif // OPENGL_LOAD_GL_VERSION_4_0

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_LOAD_GL_VERSION_4_1

#ifndef GL_VERSION_4_1
#define GL_VERSION_4_1 1

#define GL_FIXED                               0x140C
#define GL_IMPLEMENTATION_COLOR_READ_TYPE      0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT    0x8B9B
#define GL_LOW_FLOAT                           0x8DF0
#define GL_MEDIUM_FLOAT                        0x8DF1
#define GL_HIGH_FLOAT                          0x8DF2
#define GL_LOW_INT                             0x8DF3
#define GL_MEDIUM_INT                          0x8DF4
#define GL_HIGH_INT                            0x8DF5
#define GL_SHADER_COMPILER                     0x8DFA
#define GL_SHADER_BINARY_FORMATS               0x8DF8
#define GL_NUM_SHADER_BINARY_FORMATS           0x8DF9
#define GL_MAX_VERTEX_UNIFORM_VECTORS          0x8DFB
#define GL_MAX_VARYING_VECTORS                 0x8DFC
#define GL_MAX_FRAGMENT_UNIFORM_VECTORS        0x8DFD
#define GL_RGB565                              0x8D62
#define GL_PROGRAM_BINARY_RETRIEVABLE_HINT     0x8257
#define GL_PROGRAM_BINARY_LENGTH               0x8741
#define GL_NUM_PROGRAM_BINARY_FORMATS          0x87FE
#define GL_PROGRAM_BINARY_FORMATS              0x87FF
#define GL_VERTEX_SHADER_BIT                   0x00000001
#define GL_FRAGMENT_SHADER_BIT                 0x00000002
#define GL_GEOMETRY_SHADER_BIT                 0x00000004
#define GL_TESS_CONTROL_SHADER_BIT             0x00000008
#define GL_TESS_EVALUATION_SHADER_BIT          0x00000010
#define GL_ALL_SHADER_BITS                     0xFFFFFFFF
#define GL_PROGRAM_SEPARABLE                   0x8258
#define GL_ACTIVE_PROGRAM                      0x8259
#define GL_PROGRAM_PIPELINE_BINDING            0x825A
#define GL_MAX_VIEWPORTS                       0x825B
#define GL_VIEWPORT_SUBPIXEL_BITS              0x825C
#define GL_VIEWPORT_BOUNDS_RANGE               0x825D
#define GL_LAYER_PROVOKING_VERTEX              0x825E
#define GL_VIEWPORT_INDEX_PROVOKING_VERTEX     0x825F
#define GL_UNDEFINED_VERTEX                    0x8260

OPENGL_INIT_PROC(glReleaseShaderCompiler,     void,      void);
OPENGL_INIT_PROC(glShaderBinary,              void,      GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length);
OPENGL_INIT_PROC(glGetShaderPrecisionFormat,  void,      GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
OPENGL_INIT_PROC(glDepthRangef,               void,      GLfloat n, GLfloat f);
OPENGL_INIT_PROC(glClearDepthf,               void,      GLfloat d);
OPENGL_INIT_PROC(glGetProgramBinary,          void,      GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
OPENGL_INIT_PROC(glProgramBinary,             void,      GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
OPENGL_INIT_PROC(glProgramParameteri,         void,      GLuint program, GLenum pname, GLint value);
OPENGL_INIT_PROC(glUseProgramStages,          void,      GLuint pipeline, GLbitfield stages, GLuint program);
OPENGL_INIT_PROC(glActiveShaderProgram,       void,      GLuint pipeline, GLuint program);
OPENGL_INIT_PROC(glCreateShaderProgramv,      GLuint,    GLenum type, GLsizei count, const GLchar *const*strings);
OPENGL_INIT_PROC(glBindProgramPipeline,       void,      GLuint pipeline);
OPENGL_INIT_PROC(glDeleteProgramPipelines,    void,      GLsizei n, const GLuint *pipelines);
OPENGL_INIT_PROC(glGenProgramPipelines,       void,      GLsizei n, GLuint *pipelines);
OPENGL_INIT_PROC(glIsProgramPipeline,         GLboolean, GLuint pipeline);
OPENGL_INIT_PROC(glGetProgramPipelineiv,      void,      GLuint pipeline, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glProgramUniform1i,          void,      GLuint program, GLint location, GLint v0);
OPENGL_INIT_PROC(glProgramUniform1iv,         void,      GLuint program, GLint location, GLsizei count, const GLint *value);
OPENGL_INIT_PROC(glProgramUniform1f,          void,      GLuint program, GLint location, GLfloat v0);
OPENGL_INIT_PROC(glProgramUniform1fv,         void,      GLuint program, GLint location, GLsizei count, const GLfloat *value);
OPENGL_INIT_PROC(glProgramUniform1d,          void,      GLuint program, GLint location, GLdouble v0);
OPENGL_INIT_PROC(glProgramUniform1dv,         void,      GLuint program, GLint location, GLsizei count, const GLdouble *value);
OPENGL_INIT_PROC(glProgramUniform1ui,         void,      GLuint program, GLint location, GLuint v0);
OPENGL_INIT_PROC(glProgramUniform1uiv,        void,      GLuint program, GLint location, GLsizei count, const GLuint *value);
OPENGL_INIT_PROC(glProgramUniform2i,          void,      GLuint program, GLint location, GLint v0, GLint v1);
OPENGL_INIT_PROC(glProgramUniform2iv,         void,      GLuint program, GLint location, GLsizei count, const GLint *value);
OPENGL_INIT_PROC(glProgramUniform2f,          void,      GLuint program, GLint location, GLfloat v0, GLfloat v1);
OPENGL_INIT_PROC(glProgramUniform2fv,         void,      GLuint program, GLint location, GLsizei count, const GLfloat *value);
OPENGL_INIT_PROC(glProgramUniform2d,          void,      GLuint program, GLint location, GLdouble v0, GLdouble v1);
OPENGL_INIT_PROC(glProgramUniform2dv,         void,      GLuint program, GLint location, GLsizei count, const GLdouble *value);
OPENGL_INIT_PROC(glProgramUniform2ui,         void,      GLuint program, GLint location, GLuint v0, GLuint v1);
OPENGL_INIT_PROC(glProgramUniform2uiv,        void,      GLuint program, GLint location, GLsizei count, const GLuint *value);
OPENGL_INIT_PROC(glProgramUniform3i,          void,      GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
OPENGL_INIT_PROC(glProgramUniform3iv,         void,      GLuint program, GLint location, GLsizei count, const GLint *value);
OPENGL_INIT_PROC(glProgramUniform3f,          void,      GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
OPENGL_INIT_PROC(glProgramUniform3fv,         void,      GLuint program, GLint location, GLsizei count, const GLfloat *value);
OPENGL_INIT_PROC(glProgramUniform3d,          void,      GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
OPENGL_INIT_PROC(glProgramUniform3dv,         void,      GLuint program, GLint location, GLsizei count, const GLdouble *value);
OPENGL_INIT_PROC(glProgramUniform3ui,         void,      GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
OPENGL_INIT_PROC(glProgramUniform3uiv,        void,      GLuint program, GLint location, GLsizei count, const GLuint *value);
OPENGL_INIT_PROC(glProgramUniform4i,          void,      GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
OPENGL_INIT_PROC(glProgramUniform4iv,         void,      GLuint program, GLint location, GLsizei count, const GLint *value);
OPENGL_INIT_PROC(glProgramUniform4f,          void,      GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
OPENGL_INIT_PROC(glProgramUniform4fv,         void,      GLuint program, GLint location, GLsizei count, const GLfloat *value);
OPENGL_INIT_PROC(glProgramUniform4d,          void,      GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
OPENGL_INIT_PROC(glProgramUniform4dv,         void,      GLuint program, GLint location, GLsizei count, const GLdouble *value);
OPENGL_INIT_PROC(glProgramUniform4ui,         void,      GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
OPENGL_INIT_PROC(glProgramUniform4uiv,        void,      GLuint program, GLint location, GLsizei count, const GLuint *value);
OPENGL_INIT_PROC(glProgramUniformMatrix2fv,   void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glProgramUniformMatrix3fv,   void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glProgramUniformMatrix4fv,   void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glProgramUniformMatrix2dv,   void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glProgramUniformMatrix3dv,   void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glProgramUniformMatrix4dv,   void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glProgramUniformMatrix2x3fv, void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glProgramUniformMatrix3x2fv, void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glProgramUniformMatrix2x4fv, void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glProgramUniformMatrix4x2fv, void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glProgramUniformMatrix3x4fv, void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glProgramUniformMatrix4x3fv, void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glProgramUniformMatrix2x3dv, void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glProgramUniformMatrix3x2dv, void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glProgramUniformMatrix2x4dv, void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glProgramUniformMatrix4x2dv, void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glProgramUniformMatrix3x4dv, void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glProgramUniformMatrix4x3dv, void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glValidateProgramPipeline,   void,      GLuint pipeline);
OPENGL_INIT_PROC(glGetProgramPipelineInfoLog, void,      GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
OPENGL_INIT_PROC(glVertexAttribL1d,           void,      GLuint index, GLdouble x);
OPENGL_INIT_PROC(glVertexAttribL2d,           void,      GLuint index, GLdouble x, GLdouble y);
OPENGL_INIT_PROC(glVertexAttribL3d,           void,      GLuint index, GLdouble x, GLdouble y, GLdouble z);
OPENGL_INIT_PROC(glVertexAttribL4d,           void,      GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
OPENGL_INIT_PROC(glVertexAttribL1dv,          void,      GLuint index, const GLdouble *v);
OPENGL_INIT_PROC(glVertexAttribL2dv,          void,      GLuint index, const GLdouble *v);
OPENGL_INIT_PROC(glVertexAttribL3dv,          void,      GLuint index, const GLdouble *v);
OPENGL_INIT_PROC(glVertexAttribL4dv,          void,      GLuint index, const GLdouble *v);
OPENGL_INIT_PROC(glVertexAttribLPointer,      void,      GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
OPENGL_INIT_PROC(glGetVertexAttribLdv,        void,      GLuint index, GLenum pname, GLdouble *params);
OPENGL_INIT_PROC(glViewportArrayv,            void,      GLuint first, GLsizei count, const GLfloat *v);
OPENGL_INIT_PROC(glViewportIndexedf,          void,      GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
OPENGL_INIT_PROC(glViewportIndexedfv,         void,      GLuint index, const GLfloat *v);
OPENGL_INIT_PROC(glScissorArrayv,             void,      GLuint first, GLsizei count, const GLint *v);
OPENGL_INIT_PROC(glScissorIndexed,            void,      GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glScissorIndexedv,           void,      GLuint index, const GLint *v);
OPENGL_INIT_PROC(glDepthRangeArrayv,          void,      GLuint first, GLsizei count, const GLdouble *v);
OPENGL_INIT_PROC(glDepthRangeIndexed,         void,      GLuint index, GLdouble n, GLdouble f);
OPENGL_INIT_PROC(glGetFloati_v,               void,      GLenum target, GLuint index, GLfloat *data);
OPENGL_INIT_PROC(glGetDoublei_v,              void,      GLenum target, GLuint index, GLdouble *data);

#define glReleaseShaderCompiler     OGL__glReleaseShaderCompiler
#define glShaderBinary              OGL__glShaderBinary
#define glGetShaderPrecisionFormat  OGL__glGetShaderPrecisionFormat
#define glDepthRangef               OGL__glDepthRangef
#define glClearDepthf               OGL__glClearDepthf
#define glGetProgramBinary          OGL__glGetProgramBinary
#define glProgramBinary             OGL__glProgramBinary
#define glProgramParameteri         OGL__glProgramParameteri
#define glUseProgramStages          OGL__glUseProgramStages
#define glActiveShaderProgram       OGL__glActiveShaderProgram
#define glCreateShaderProgramv      OGL__glCreateShaderProgramv
#define glBindProgramPipeline       OGL__glBindProgramPipeline
#define glDeleteProgramPipelines    OGL__glDeleteProgramPipelines
#define glGenProgramPipelines       OGL__glGenProgramPipelines
#define glIsProgramPipeline         OGL__glIsProgramPipeline
#define glGetProgramPipelineiv      OGL__glGetProgramPipelineiv
#define glProgramUniform1i          OGL__glProgramUniform1i
#define glProgramUniform1iv         OGL__glProgramUniform1iv
#define glProgramUniform1f          OGL__glProgramUniform1f
#define glProgramUniform1fv         OGL__glProgramUniform1fv
#define glProgramUniform1d          OGL__glProgramUniform1d
#define glProgramUniform1dv         OGL__glProgramUniform1dv
#define glProgramUniform1ui         OGL__glProgramUniform1ui
#define glProgramUniform1uiv        OGL__glProgramUniform1uiv
#define glProgramUniform2i          OGL__glProgramUniform2i
#define glProgramUniform2iv         OGL__glProgramUniform2iv
#define glProgramUniform2f          OGL__glProgramUniform2f
#define glProgramUniform2fv         OGL__glProgramUniform2fv
#define glProgramUniform2d          OGL__glProgramUniform2d
#define glProgramUniform2dv         OGL__glProgramUniform2dv
#define glProgramUniform2ui         OGL__glProgramUniform2ui
#define glProgramUniform2uiv        OGL__glProgramUniform2uiv
#define glProgramUniform3i          OGL__glProgramUniform3i
#define glProgramUniform3iv         OGL__glProgramUniform3iv
#define glProgramUniform3f          OGL__glProgramUniform3f
#define glProgramUniform3fv         OGL__glProgramUniform3fv
#define glProgramUniform3d          OGL__glProgramUniform3d
#define glProgramUniform3dv         OGL__glProgramUniform3dv
#define glProgramUniform3ui         OGL__glProgramUniform3ui
#define glProgramUniform3uiv        OGL__glProgramUniform3uiv
#define glProgramUniform4i          OGL__glProgramUniform4i
#define glProgramUniform4iv         OGL__glProgramUniform4iv
#define glProgramUniform4f          OGL__glProgramUniform4f
#define glProgramUniform4fv         OGL__glProgramUniform4fv
#define glProgramUniform4d          OGL__glProgramUniform4d
#define glProgramUniform4dv         OGL__glProgramUniform4dv
#define glProgramUniform4ui         OGL__glProgramUniform4ui
#define glProgramUniform4uiv        OGL__glProgramUniform4uiv
#define glProgramUniformMatrix2fv   OGL__glProgramUniformMatrix2fv
#define glProgramUniformMatrix3fv   OGL__glProgramUniformMatrix3fv
#define glProgramUniformMatrix4fv   OGL__glProgramUniformMatrix4fv
#define glProgramUniformMatrix2dv   OGL__glProgramUniformMatrix2dv
#define glProgramUniformMatrix3dv   OGL__glProgramUniformMatrix3dv
#define glProgramUniformMatrix4dv   OGL__glProgramUniformMatrix4dv
#define glProgramUniformMatrix2x3fv OGL__glProgramUniformMatrix2x3fv
#define glProgramUniformMatrix3x2fv OGL__glProgramUniformMatrix3x2fv
#define glProgramUniformMatrix2x4fv OGL__glProgramUniformMatrix2x4fv
#define glProgramUniformMatrix4x2fv OGL__glProgramUniformMatrix4x2fv
#define glProgramUniformMatrix3x4fv OGL__glProgramUniformMatrix3x4fv
#define glProgramUniformMatrix4x3fv OGL__glProgramUniformMatrix4x3fv
#define glProgramUniformMatrix2x3dv OGL__glProgramUniformMatrix2x3dv
#define glProgramUniformMatrix3x2dv OGL__glProgramUniformMatrix3x2dv
#define glProgramUniformMatrix2x4dv OGL__glProgramUniformMatrix2x4dv
#define glProgramUniformMatrix4x2dv OGL__glProgramUniformMatrix4x2dv
#define glProgramUniformMatrix3x4dv OGL__glProgramUniformMatrix3x4dv
#define glProgramUniformMatrix4x3dv OGL__glProgramUniformMatrix4x3dv
#define glValidateProgramPipeline   OGL__glValidateProgramPipeline
#define glGetProgramPipelineInfoLog OGL__glGetProgramPipelineInfoLog
#define glVertexAttribL1d           OGL__glVertexAttribL1d
#define glVertexAttribL2d           OGL__glVertexAttribL2d
#define glVertexAttribL3d           OGL__glVertexAttribL3d
#define glVertexAttribL4d           OGL__glVertexAttribL4d
#define glVertexAttribL1dv          OGL__glVertexAttribL1dv
#define glVertexAttribL2dv          OGL__glVertexAttribL2dv
#define glVertexAttribL3dv          OGL__glVertexAttribL3dv
#define glVertexAttribL4dv          OGL__glVertexAttribL4dv
#define glVertexAttribLPointer      OGL__glVertexAttribLPointer
#define glGetVertexAttribLdv        OGL__glGetVertexAttribLdv
#define glViewportArrayv            OGL__glViewportArrayv
#define glViewportIndexedf          OGL__glViewportIndexedf
#define glViewportIndexedfv         OGL__glViewportIndexedfv
#define glScissorArrayv             OGL__glScissorArrayv
#define glScissorIndexed            OGL__glScissorIndexed
#define glScissorIndexedv           OGL__glScissorIndexedv
#define glDepthRangeArrayv          OGL__glDepthRangeArrayv
#define glDepthRangeIndexed         OGL__glDepthRangeIndexed
#define glGetFloati_v               OGL__glGetFloati_v
#define glGetDoublei_v              OGL__glGetDoublei_v

#endif // GL_VERSION_4_1

#endif // OPENGL_LOAD_GL_VERSION_4_1

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_LOAD_GL_VERSION_4_2

#ifndef GL_VERSION_4_2
#define GL_VERSION_4_2 1

#define GL_COPY_READ_BUFFER_BINDING                                      0x8F36
#define GL_COPY_WRITE_BUFFER_BINDING                                     0x8F37
#define GL_TRANSFORM_FEEDBACK_ACTIVE                                     0x8E24
#define GL_TRANSFORM_FEEDBACK_PAUSED                                     0x8E23
#define GL_UNPACK_COMPRESSED_BLOCK_WIDTH                                 0x9127
#define GL_UNPACK_COMPRESSED_BLOCK_HEIGHT                                0x9128
#define GL_UNPACK_COMPRESSED_BLOCK_DEPTH                                 0x9129
#define GL_UNPACK_COMPRESSED_BLOCK_SIZE                                  0x912A
#define GL_PACK_COMPRESSED_BLOCK_WIDTH                                   0x912B
#define GL_PACK_COMPRESSED_BLOCK_HEIGHT                                  0x912C
#define GL_PACK_COMPRESSED_BLOCK_DEPTH                                   0x912D
#define GL_PACK_COMPRESSED_BLOCK_SIZE                                    0x912E
#define GL_NUM_SAMPLE_COUNTS                                             0x9380
#define GL_MIN_MAP_BUFFER_ALIGNMENT                                      0x90BC
#define GL_ATOMIC_COUNTER_BUFFER                                         0x92C0
#define GL_ATOMIC_COUNTER_BUFFER_BINDING                                 0x92C1
#define GL_ATOMIC_COUNTER_BUFFER_START                                   0x92C2
#define GL_ATOMIC_COUNTER_BUFFER_SIZE                                    0x92C3
#define GL_ATOMIC_COUNTER_BUFFER_DATA_SIZE                               0x92C4
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTERS                  0x92C5
#define GL_ATOMIC_COUNTER_BUFFER_ACTIVE_ATOMIC_COUNTER_INDICES           0x92C6
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_VERTEX_SHADER             0x92C7
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_CONTROL_SHADER       0x92C8
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TESS_EVALUATION_SHADER    0x92C9
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_GEOMETRY_SHADER           0x92CA
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_FRAGMENT_SHADER           0x92CB
#define GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS                             0x92CC
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS                       0x92CD
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS                    0x92CE
#define GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS                           0x92CF
#define GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS                           0x92D0
#define GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS                           0x92D1
#define GL_MAX_VERTEX_ATOMIC_COUNTERS                                    0x92D2
#define GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS                              0x92D3
#define GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS                           0x92D4
#define GL_MAX_GEOMETRY_ATOMIC_COUNTERS                                  0x92D5
#define GL_MAX_FRAGMENT_ATOMIC_COUNTERS                                  0x92D6
#define GL_MAX_COMBINED_ATOMIC_COUNTERS                                  0x92D7
#define GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE                                0x92D8
#define GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS                            0x92DC
#define GL_ACTIVE_ATOMIC_COUNTER_BUFFERS                                 0x92D9
#define GL_UNIFORM_ATOMIC_COUNTER_BUFFER_INDEX                           0x92DA
#define GL_UNSIGNED_INT_ATOMIC_COUNTER                                   0x92DB
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT                               0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT                                     0x00000002
#define GL_UNIFORM_BARRIER_BIT                                           0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT                                     0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT                               0x00000020
#define GL_COMMAND_BARRIER_BIT                                           0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT                                      0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT                                    0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT                                     0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT                                       0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT                                0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT                                    0x00001000
#define GL_ALL_BARRIER_BITS                                              0xFFFFFFFF
#define GL_MAX_IMAGE_UNITS                                               0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS                 0x8F39
#define GL_IMAGE_BINDING_NAME                                            0x8F3A
#define GL_IMAGE_BINDING_LEVEL                                           0x8F3B
#define GL_IMAGE_BINDING_LAYERED                                         0x8F3C
#define GL_IMAGE_BINDING_LAYER                                           0x8F3D
#define GL_IMAGE_BINDING_ACCESS                                          0x8F3E
#define GL_IMAGE_1D                                                      0x904C
#define GL_IMAGE_2D                                                      0x904D
#define GL_IMAGE_3D                                                      0x904E
#define GL_IMAGE_2D_RECT                                                 0x904F
#define GL_IMAGE_CUBE                                                    0x9050
#define GL_IMAGE_BUFFER                                                  0x9051
#define GL_IMAGE_1D_ARRAY                                                0x9052
#define GL_IMAGE_2D_ARRAY                                                0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY                                          0x9054
#define GL_IMAGE_2D_MULTISAMPLE                                          0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY                                    0x9056
#define GL_INT_IMAGE_1D                                                  0x9057
#define GL_INT_IMAGE_2D                                                  0x9058
#define GL_INT_IMAGE_3D                                                  0x9059
#define GL_INT_IMAGE_2D_RECT                                             0x905A
#define GL_INT_IMAGE_CUBE                                                0x905B
#define GL_INT_IMAGE_BUFFER                                              0x905C
#define GL_INT_IMAGE_1D_ARRAY                                            0x905D
#define GL_INT_IMAGE_2D_ARRAY                                            0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY                                      0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE                                      0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY                                0x9061
#define GL_UNSIGNED_INT_IMAGE_1D                                         0x9062
#define GL_UNSIGNED_INT_IMAGE_2D                                         0x9063
#define GL_UNSIGNED_INT_IMAGE_3D                                         0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT                                    0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE                                       0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER                                     0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY                                   0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY                                   0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY                             0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE                             0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY                       0x906C
#define GL_MAX_IMAGE_SAMPLES                                             0x906D
#define GL_IMAGE_BINDING_FORMAT                                          0x906E
#define GL_IMAGE_FORMAT_COMPATIBILITY_TYPE                               0x90C7
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_SIZE                            0x90C8
#define GL_IMAGE_FORMAT_COMPATIBILITY_BY_CLASS                           0x90C9
#define GL_MAX_VERTEX_IMAGE_UNIFORMS                                     0x90CA
#define GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS                               0x90CB
#define GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS                            0x90CC
#define GL_MAX_GEOMETRY_IMAGE_UNIFORMS                                   0x90CD
#define GL_MAX_FRAGMENT_IMAGE_UNIFORMS                                   0x90CE
#define GL_MAX_COMBINED_IMAGE_UNIFORMS                                   0x90CF
#define GL_COMPRESSED_RGBA_BPTC_UNORM                                    0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM                              0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT                              0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT                            0x8E8F
#define GL_TEXTURE_IMMUTABLE_FORMAT                                      0x912F

OPENGL_INIT_PROC(glDrawArraysInstancedBaseInstance,             void, GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
OPENGL_INIT_PROC(glDrawElementsInstancedBaseInstance,           void, GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
OPENGL_INIT_PROC(glDrawElementsInstancedBaseVertexBaseInstance, void, GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
OPENGL_INIT_PROC(glGetInternalformativ,                         void, GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);
OPENGL_INIT_PROC(glGetActiveAtomicCounterBufferiv,              void, GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glBindImageTexture,                            void, GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
OPENGL_INIT_PROC(glMemoryBarrier,                               void, GLbitfield barriers);
OPENGL_INIT_PROC(glTexStorage1D,                                void, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
OPENGL_INIT_PROC(glTexStorage2D,                                void, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glTexStorage3D,                                void, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
OPENGL_INIT_PROC(glDrawTransformFeedbackInstanced,              void, GLenum mode, GLuint id, GLsizei instancecount);
OPENGL_INIT_PROC(glDrawTransformFeedbackStreamInstanced,        void, GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);

#define glDrawArraysInstancedBaseInstance             OGL__glDrawArraysInstancedBaseInstance
#define glDrawElementsInstancedBaseInstance           OGL__glDrawElementsInstancedBaseInstance
#define glDrawElementsInstancedBaseVertexBaseInstance OGL__glDrawElementsInstancedBaseVertexBaseInstance
#define glGetInternalformativ                         OGL__glGetInternalformativ
#define glGetActiveAtomicCounterBufferiv              OGL__glGetActiveAtomicCounterBufferiv
#define glBindImageTexture                            OGL__glBindImageTexture
#define glMemoryBarrier                               OGL__glMemoryBarrier
#define glTexStorage1D                                OGL__glTexStorage1D
#define glTexStorage2D                                OGL__glTexStorage2D
#define glTexStorage3D                                OGL__glTexStorage3D
#define glDrawTransformFeedbackInstanced              OGL__glDrawTransformFeedbackInstanced
#define glDrawTransformFeedbackStreamInstanced        OGL__glDrawTransformFeedbackStreamInstanced

#endif // GL_VERSION_4_2

#endif // OPENGL_LOAD_GL_VERSION_4_2

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_LOAD_GL_VERSION_4_3

#ifndef GL_VERSION_4_3
#define GL_VERSION_4_3 1

typedef void (APIENTRY* GLDEBUGPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);

#define GL_NUM_SHADING_LANGUAGE_VERSIONS                         0x82E9
#define GL_VERTEX_ATTRIB_ARRAY_LONG                              0x874E
#define GL_COMPRESSED_RGB8_ETC2                                  0x9274
#define GL_COMPRESSED_SRGB8_ETC2                                 0x9275
#define GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2              0x9276
#define GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2             0x9277
#define GL_COMPRESSED_RGBA8_ETC2_EAC                             0x9278
#define GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC                      0x9279
#define GL_COMPRESSED_R11_EAC                                    0x9270
#define GL_COMPRESSED_SIGNED_R11_EAC                             0x9271
#define GL_COMPRESSED_RG11_EAC                                   0x9272
#define GL_COMPRESSED_SIGNED_RG11_EAC                            0x9273
#define GL_PRIMITIVE_RESTART_FIXED_INDEX                         0x8D69
#define GL_ANY_SAMPLES_PASSED_CONSERVATIVE                       0x8D6A
#define GL_MAX_ELEMENT_INDEX                                     0x8D6B
#define GL_COMPUTE_SHADER                                        0x91B9
#define GL_MAX_COMPUTE_UNIFORM_BLOCKS                            0x91BB
#define GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS                       0x91BC
#define GL_MAX_COMPUTE_IMAGE_UNIFORMS                            0x91BD
#define GL_MAX_COMPUTE_SHARED_MEMORY_SIZE                        0x8262
#define GL_MAX_COMPUTE_UNIFORM_COMPONENTS                        0x8263
#define GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS                    0x8264
#define GL_MAX_COMPUTE_ATOMIC_COUNTERS                           0x8265
#define GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS               0x8266
#define GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS                    0x90EB
#define GL_MAX_COMPUTE_WORK_GROUP_COUNT                          0x91BE
#define GL_MAX_COMPUTE_WORK_GROUP_SIZE                           0x91BF
#define GL_COMPUTE_WORK_GROUP_SIZE                               0x8267
#define GL_UNIFORM_BLOCK_REFERENCED_BY_COMPUTE_SHADER            0x90EC
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_COMPUTE_SHADER    0x90ED
#define GL_DISPATCH_INDIRECT_BUFFER                              0x90EE
#define GL_DISPATCH_INDIRECT_BUFFER_BINDING                      0x90EF
#define GL_COMPUTE_SHADER_BIT                                    0x00000020
#define GL_DEBUG_OUTPUT_SYNCHRONOUS                              0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH                      0x8243
#define GL_DEBUG_CALLBACK_FUNCTION                               0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM                             0x8245
#define GL_DEBUG_SOURCE_API                                      0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM                            0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER                          0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY                              0x8249
#define GL_DEBUG_SOURCE_APPLICATION                              0x824A
#define GL_DEBUG_SOURCE_OTHER                                    0x824B
#define GL_DEBUG_TYPE_ERROR                                      0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR                        0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR                         0x824E
#define GL_DEBUG_TYPE_PORTABILITY                                0x824F
#define GL_DEBUG_TYPE_PERFORMANCE                                0x8250
#define GL_DEBUG_TYPE_OTHER                                      0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH                              0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES                             0x9144
#define GL_DEBUG_LOGGED_MESSAGES                                 0x9145
#define GL_DEBUG_SEVERITY_HIGH                                   0x9146
#define GL_DEBUG_SEVERITY_MEDIUM                                 0x9147
#define GL_DEBUG_SEVERITY_LOW                                    0x9148
#define GL_DEBUG_TYPE_MARKER                                     0x8268
#define GL_DEBUG_TYPE_PUSH_GROUP                                 0x8269
#define GL_DEBUG_TYPE_POP_GROUP                                  0x826A
#define GL_DEBUG_SEVERITY_NOTIFICATION                           0x826B
#define GL_MAX_DEBUG_GROUP_STACK_DEPTH                           0x826C
#define GL_DEBUG_GROUP_STACK_DEPTH                               0x826D
#define GL_BUFFER                                                0x82E0
#define GL_SHADER                                                0x82E1
#define GL_PROGRAM                                               0x82E2
#define GL_QUERY                                                 0x82E3
#define GL_PROGRAM_PIPELINE                                      0x82E4
#define GL_SAMPLER                                               0x82E6
#define GL_MAX_LABEL_LENGTH                                      0x82E8
#define GL_DEBUG_OUTPUT                                          0x92E0
#define GL_CONTEXT_FLAG_DEBUG_BIT                                0x00000002
#define GL_MAX_UNIFORM_LOCATIONS                                 0x826E
#define GL_FRAMEBUFFER_DEFAULT_WIDTH                             0x9310
#define GL_FRAMEBUFFER_DEFAULT_HEIGHT                            0x9311
#define GL_FRAMEBUFFER_DEFAULT_LAYERS                            0x9312
#define GL_FRAMEBUFFER_DEFAULT_SAMPLES                           0x9313
#define GL_FRAMEBUFFER_DEFAULT_FIXED_SAMPLE_LOCATIONS            0x9314
#define GL_MAX_FRAMEBUFFER_WIDTH                                 0x9315
#define GL_MAX_FRAMEBUFFER_HEIGHT                                0x9316
#define GL_MAX_FRAMEBUFFER_LAYERS                                0x9317
#define GL_MAX_FRAMEBUFFER_SAMPLES                               0x9318
#define GL_INTERNALFORMAT_SUPPORTED                              0x826F
#define GL_INTERNALFORMAT_PREFERRED                              0x8270
#define GL_INTERNALFORMAT_RED_SIZE                               0x8271
#define GL_INTERNALFORMAT_GREEN_SIZE                             0x8272
#define GL_INTERNALFORMAT_BLUE_SIZE                              0x8273
#define GL_INTERNALFORMAT_ALPHA_SIZE                             0x8274
#define GL_INTERNALFORMAT_DEPTH_SIZE                             0x8275
#define GL_INTERNALFORMAT_STENCIL_SIZE                           0x8276
#define GL_INTERNALFORMAT_SHARED_SIZE                            0x8277
#define GL_INTERNALFORMAT_RED_TYPE                               0x8278
#define GL_INTERNALFORMAT_GREEN_TYPE                             0x8279
#define GL_INTERNALFORMAT_BLUE_TYPE                              0x827A
#define GL_INTERNALFORMAT_ALPHA_TYPE                             0x827B
#define GL_INTERNALFORMAT_DEPTH_TYPE                             0x827C
#define GL_INTERNALFORMAT_STENCIL_TYPE                           0x827D
#define GL_MAX_WIDTH                                             0x827E
#define GL_MAX_HEIGHT                                            0x827F
#define GL_MAX_DEPTH                                             0x8280
#define GL_MAX_LAYERS                                            0x8281
#define GL_MAX_COMBINED_DIMENSIONS                               0x8282
#define GL_COLOR_COMPONENTS                                      0x8283
#define GL_DEPTH_COMPONENTS                                      0x8284
#define GL_STENCIL_COMPONENTS                                    0x8285
#define GL_COLOR_RENDERABLE                                      0x8286
#define GL_DEPTH_RENDERABLE                                      0x8287
#define GL_STENCIL_RENDERABLE                                    0x8288
#define GL_FRAMEBUFFER_RENDERABLE                                0x8289
#define GL_FRAMEBUFFER_RENDERABLE_LAYERED                        0x828A
#define GL_FRAMEBUFFER_BLEND                                     0x828B
#define GL_READ_PIXELS                                           0x828C
#define GL_READ_PIXELS_FORMAT                                    0x828D
#define GL_READ_PIXELS_TYPE                                      0x828E
#define GL_TEXTURE_IMAGE_FORMAT                                  0x828F
#define GL_TEXTURE_IMAGE_TYPE                                    0x8290
#define GL_GET_TEXTURE_IMAGE_FORMAT                              0x8291
#define GL_GET_TEXTURE_IMAGE_TYPE                                0x8292
#define GL_MIPMAP                                                0x8293
#define GL_MANUAL_GENERATE_MIPMAP                                0x8294
#define GL_AUTO_GENERATE_MIPMAP                                  0x8295
#define GL_COLOR_ENCODING                                        0x8296
#define GL_SRGB_READ                                             0x8297
#define GL_SRGB_WRITE                                            0x8298
#define GL_FILTER                                                0x829A
#define GL_VERTEX_TEXTURE                                        0x829B
#define GL_TESS_CONTROL_TEXTURE                                  0x829C
#define GL_TESS_EVALUATION_TEXTURE                               0x829D
#define GL_GEOMETRY_TEXTURE                                      0x829E
#define GL_FRAGMENT_TEXTURE                                      0x829F
#define GL_COMPUTE_TEXTURE                                       0x82A0
#define GL_TEXTURE_SHADOW                                        0x82A1
#define GL_TEXTURE_GATHER                                        0x82A2
#define GL_TEXTURE_GATHER_SHADOW                                 0x82A3
#define GL_SHADER_IMAGE_LOAD                                     0x82A4
#define GL_SHADER_IMAGE_STORE                                    0x82A5
#define GL_SHADER_IMAGE_ATOMIC                                   0x82A6
#define GL_IMAGE_TEXEL_SIZE                                      0x82A7
#define GL_IMAGE_COMPATIBILITY_CLASS                             0x82A8
#define GL_IMAGE_PIXEL_FORMAT                                    0x82A9
#define GL_IMAGE_PIXEL_TYPE                                      0x82AA
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_TEST                   0x82AC
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_TEST                 0x82AD
#define GL_SIMULTANEOUS_TEXTURE_AND_DEPTH_WRITE                  0x82AE
#define GL_SIMULTANEOUS_TEXTURE_AND_STENCIL_WRITE                0x82AF
#define GL_TEXTURE_COMPRESSED_BLOCK_WIDTH                        0x82B1
#define GL_TEXTURE_COMPRESSED_BLOCK_HEIGHT                       0x82B2
#define GL_TEXTURE_COMPRESSED_BLOCK_SIZE                         0x82B3
#define GL_CLEAR_BUFFER                                          0x82B4
#define GL_TEXTURE_VIEW                                          0x82B5
#define GL_VIEW_COMPATIBILITY_CLASS                              0x82B6
#define GL_FULL_SUPPORT                                          0x82B7
#define GL_CAVEAT_SUPPORT                                        0x82B8
#define GL_IMAGE_CLASS_4_X_32                                    0x82B9
#define GL_IMAGE_CLASS_2_X_32                                    0x82BA
#define GL_IMAGE_CLASS_1_X_32                                    0x82BB
#define GL_IMAGE_CLASS_4_X_16                                    0x82BC
#define GL_IMAGE_CLASS_2_X_16                                    0x82BD
#define GL_IMAGE_CLASS_1_X_16                                    0x82BE
#define GL_IMAGE_CLASS_4_X_8                                     0x82BF
#define GL_IMAGE_CLASS_2_X_8                                     0x82C0
#define GL_IMAGE_CLASS_1_X_8                                     0x82C1
#define GL_IMAGE_CLASS_11_11_10                                  0x82C2
#define GL_IMAGE_CLASS_10_10_10_2                                0x82C3
#define GL_VIEW_CLASS_128_BITS                                   0x82C4
#define GL_VIEW_CLASS_96_BITS                                    0x82C5
#define GL_VIEW_CLASS_64_BITS                                    0x82C6
#define GL_VIEW_CLASS_48_BITS                                    0x82C7
#define GL_VIEW_CLASS_32_BITS                                    0x82C8
#define GL_VIEW_CLASS_24_BITS                                    0x82C9
#define GL_VIEW_CLASS_16_BITS                                    0x82CA
#define GL_VIEW_CLASS_8_BITS                                     0x82CB
#define GL_VIEW_CLASS_S3TC_DXT1_RGB                              0x82CC
#define GL_VIEW_CLASS_S3TC_DXT1_RGBA                             0x82CD
#define GL_VIEW_CLASS_S3TC_DXT3_RGBA                             0x82CE
#define GL_VIEW_CLASS_S3TC_DXT5_RGBA                             0x82CF
#define GL_VIEW_CLASS_RGTC1_RED                                  0x82D0
#define GL_VIEW_CLASS_RGTC2_RG                                   0x82D1
#define GL_VIEW_CLASS_BPTC_UNORM                                 0x82D2
#define GL_VIEW_CLASS_BPTC_FLOAT                                 0x82D3
#define GL_UNIFORM                                               0x92E1
#define GL_UNIFORM_BLOCK                                         0x92E2
#define GL_PROGRAM_INPUT                                         0x92E3
#define GL_PROGRAM_OUTPUT                                        0x92E4
#define GL_BUFFER_VARIABLE                                       0x92E5
#define GL_SHADER_STORAGE_BLOCK                                  0x92E6
#define GL_VERTEX_SUBROUTINE                                     0x92E8
#define GL_TESS_CONTROL_SUBROUTINE                               0x92E9
#define GL_TESS_EVALUATION_SUBROUTINE                            0x92EA
#define GL_GEOMETRY_SUBROUTINE                                   0x92EB
#define GL_FRAGMENT_SUBROUTINE                                   0x92EC
#define GL_COMPUTE_SUBROUTINE                                    0x92ED
#define GL_VERTEX_SUBROUTINE_UNIFORM                             0x92EE
#define GL_TESS_CONTROL_SUBROUTINE_UNIFORM                       0x92EF
#define GL_TESS_EVALUATION_SUBROUTINE_UNIFORM                    0x92F0
#define GL_GEOMETRY_SUBROUTINE_UNIFORM                           0x92F1
#define GL_FRAGMENT_SUBROUTINE_UNIFORM                           0x92F2
#define GL_COMPUTE_SUBROUTINE_UNIFORM                            0x92F3
#define GL_TRANSFORM_FEEDBACK_VARYING                            0x92F4
#define GL_ACTIVE_RESOURCES                                      0x92F5
#define GL_MAX_NAME_LENGTH                                       0x92F6
#define GL_MAX_NUM_ACTIVE_VARIABLES                              0x92F7
#define GL_MAX_NUM_COMPATIBLE_SUBROUTINES                        0x92F8
#define GL_NAME_LENGTH                                           0x92F9
#define GL_TYPE                                                  0x92FA
#define GL_ARRAY_SIZE                                            0x92FB
#define GL_OFFSET                                                0x92FC
#define GL_BLOCK_INDEX                                           0x92FD
#define GL_ARRAY_STRIDE                                          0x92FE
#define GL_MATRIX_STRIDE                                         0x92FF
#define GL_IS_ROW_MAJOR                                          0x9300
#define GL_ATOMIC_COUNTER_BUFFER_INDEX                           0x9301
#define GL_BUFFER_BINDING                                        0x9302
#define GL_BUFFER_DATA_SIZE                                      0x9303
#define GL_NUM_ACTIVE_VARIABLES                                  0x9304
#define GL_ACTIVE_VARIABLES                                      0x9305
#define GL_REFERENCED_BY_VERTEX_SHADER                           0x9306
#define GL_REFERENCED_BY_TESS_CONTROL_SHADER                     0x9307
#define GL_REFERENCED_BY_TESS_EVALUATION_SHADER                  0x9308
#define GL_REFERENCED_BY_GEOMETRY_SHADER                         0x9309
#define GL_REFERENCED_BY_FRAGMENT_SHADER                         0x930A
#define GL_REFERENCED_BY_COMPUTE_SHADER                          0x930B
#define GL_TOP_LEVEL_ARRAY_SIZE                                  0x930C
#define GL_TOP_LEVEL_ARRAY_STRIDE                                0x930D
#define GL_LOCATION                                              0x930E
#define GL_LOCATION_INDEX                                        0x930F
#define GL_IS_PER_PATCH                                          0x92E7
#define GL_SHADER_STORAGE_BUFFER                                 0x90D2
#define GL_SHADER_STORAGE_BUFFER_BINDING                         0x90D3
#define GL_SHADER_STORAGE_BUFFER_START                           0x90D4
#define GL_SHADER_STORAGE_BUFFER_SIZE                            0x90D5
#define GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS                      0x90D6
#define GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS                    0x90D7
#define GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS                0x90D8
#define GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS             0x90D9
#define GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS                    0x90DA
#define GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS                     0x90DB
#define GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS                    0x90DC
#define GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS                    0x90DD
#define GL_MAX_SHADER_STORAGE_BLOCK_SIZE                         0x90DE
#define GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT                0x90DF
#define GL_SHADER_STORAGE_BARRIER_BIT                            0x00002000
#define GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES                  0x8F39
#define GL_DEPTH_STENCIL_TEXTURE_MODE                            0x90EA
#define GL_TEXTURE_BUFFER_OFFSET                                 0x919D
#define GL_TEXTURE_BUFFER_SIZE                                   0x919E
#define GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT                       0x919F
#define GL_TEXTURE_VIEW_MIN_LEVEL                                0x82DB
#define GL_TEXTURE_VIEW_NUM_LEVELS                               0x82DC
#define GL_TEXTURE_VIEW_MIN_LAYER                                0x82DD
#define GL_TEXTURE_VIEW_NUM_LAYERS                               0x82DE
#define GL_TEXTURE_IMMUTABLE_LEVELS                              0x82DF
#define GL_VERTEX_ATTRIB_BINDING                                 0x82D4
#define GL_VERTEX_ATTRIB_RELATIVE_OFFSET                         0x82D5
#define GL_VERTEX_BINDING_DIVISOR                                0x82D6
#define GL_VERTEX_BINDING_OFFSET                                 0x82D7
#define GL_VERTEX_BINDING_STRIDE                                 0x82D8
#define GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET                     0x82D9
#define GL_MAX_VERTEX_ATTRIB_BINDINGS                            0x82DA
#define GL_VERTEX_BINDING_BUFFER                                 0x8F4F
#define GL_DISPLAY_LIST                                          0x82E7

OPENGL_INIT_PROC(glClearBufferData,                 void,   GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
OPENGL_INIT_PROC(glClearBufferSubData,              void,   GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
OPENGL_INIT_PROC(glDispatchCompute,                 void,   GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
OPENGL_INIT_PROC(glDispatchComputeIndirect,         void,   GLintptr indirect);
OPENGL_INIT_PROC(glCopyImageSubData,                void,   GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
OPENGL_INIT_PROC(glFramebufferParameteri,           void,   GLenum target, GLenum pname, GLint param);
OPENGL_INIT_PROC(glGetFramebufferParameteriv,       void,   GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetInternalformati64v,           void,   GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params);
OPENGL_INIT_PROC(glInvalidateTexSubImage,           void,   GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
OPENGL_INIT_PROC(glInvalidateTexImage,              void,   GLuint texture, GLint level);
OPENGL_INIT_PROC(glInvalidateBufferSubData,         void,   GLuint buffer, GLintptr offset, GLsizeiptr length);
OPENGL_INIT_PROC(glInvalidateBufferData,            void,   GLuint buffer);
OPENGL_INIT_PROC(glInvalidateFramebuffer,           void,   GLenum target, GLsizei numAttachments, const GLenum *attachments);
OPENGL_INIT_PROC(glInvalidateSubFramebuffer,        void,   GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glMultiDrawArraysIndirect,         void,   GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
OPENGL_INIT_PROC(glMultiDrawElementsIndirect,       void,   GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
OPENGL_INIT_PROC(glGetProgramInterfaceiv,           void,   GLuint program, GLenum programInterface, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetProgramResourceIndex,         GLuint, GLuint program, GLenum programInterface, const GLchar *name);
OPENGL_INIT_PROC(glGetProgramResourceName,          void,   GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
OPENGL_INIT_PROC(glGetProgramResourceiv,            void,   GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params);
OPENGL_INIT_PROC(glGetProgramResourceLocation,      GLint,  GLuint program, GLenum programInterface, const GLchar *name);
OPENGL_INIT_PROC(glGetProgramResourceLocationIndex, GLint,  GLuint program, GLenum programInterface, const GLchar *name);
OPENGL_INIT_PROC(glShaderStorageBlockBinding,       void,   GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
OPENGL_INIT_PROC(glTexBufferRange,                  void,   GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
OPENGL_INIT_PROC(glTexStorage2DMultisample,         void,   GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
OPENGL_INIT_PROC(glTexStorage3DMultisample,         void,   GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
OPENGL_INIT_PROC(glTextureView,                     void,   GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
OPENGL_INIT_PROC(glBindVertexBuffer,                void,   GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
OPENGL_INIT_PROC(glVertexAttribFormat,              void,   GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
OPENGL_INIT_PROC(glVertexAttribIFormat,             void,   GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
OPENGL_INIT_PROC(glVertexAttribLFormat,             void,   GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
OPENGL_INIT_PROC(glVertexAttribBinding,             void,   GLuint attribindex, GLuint bindingindex);
OPENGL_INIT_PROC(glVertexBindingDivisor,            void,   GLuint bindingindex, GLuint divisor);
OPENGL_INIT_PROC(glDebugMessageControl,             void,   GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
OPENGL_INIT_PROC(glDebugMessageInsert,              void,   GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
OPENGL_INIT_PROC(glDebugMessageCallback,            void,   GLDEBUGPROC callback, const void *userParam);
OPENGL_INIT_PROC(glGetDebugMessageLog,              GLuint, GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
OPENGL_INIT_PROC(glPushDebugGroup,                  void,   GLenum source, GLuint id, GLsizei length, const GLchar *message);
OPENGL_INIT_PROC(glPopDebugGroup,                   void,   void);
OPENGL_INIT_PROC(glObjectLabel,                     void,   GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
OPENGL_INIT_PROC(glGetObjectLabel,                  void,   GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
OPENGL_INIT_PROC(glObjectPtrLabel,                  void,   const void *ptr, GLsizei length, const GLchar *label);
OPENGL_INIT_PROC(glGetObjectPtrLabel,               void,   const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);

#define glClearBufferData                 OGL__glClearBufferData
#define glClearBufferSubData              OGL__glClearBufferSubData
#define glDispatchCompute                 OGL__glDispatchCompute
#define glDispatchComputeIndirect         OGL__glDispatchComputeIndirect
#define glCopyImageSubData                OGL__glCopyImageSubData
#define glFramebufferParameteri           OGL__glFramebufferParameteri
#define glGetFramebufferParameteriv       OGL__glGetFramebufferParameteriv
#define glGetInternalformati64v           OGL__glGetInternalformati64v
#define glInvalidateTexSubImage           OGL__glInvalidateTexSubImage
#define glInvalidateTexImage              OGL__glInvalidateTexImage
#define glInvalidateBufferSubData         OGL__glInvalidateBufferSubData
#define glInvalidateBufferData            OGL__glInvalidateBufferData
#define glInvalidateFramebuffer           OGL__glInvalidateFramebuffer
#define glInvalidateSubFramebuffer        OGL__glInvalidateSubFramebuffer
#define glMultiDrawArraysIndirect         OGL__glMultiDrawArraysIndirect
#define glMultiDrawElementsIndirect       OGL__glMultiDrawElementsIndirect
#define glGetProgramInterfaceiv           OGL__glGetProgramInterfaceiv
#define glGetProgramResourceIndex         OGL__glGetProgramResourceIndex
#define glGetProgramResourceName          OGL__glGetProgramResourceName
#define glGetProgramResourceiv            OGL__glGetProgramResourceiv
#define glGetProgramResourceLocation      OGL__glGetProgramResourceLocation
#define glGetProgramResourceLocationIndex OGL__glGetProgramResourceLocationIndex
#define glShaderStorageBlockBinding       OGL__glShaderStorageBlockBinding
#define glTexBufferRange                  OGL__glTexBufferRange
#define glTexStorage2DMultisample         OGL__glTexStorage2DMultisample
#define glTexStorage3DMultisample         OGL__glTexStorage3DMultisample
#define glTextureView                     OGL__glTextureView
#define glBindVertexBuffer                OGL__glBindVertexBuffer
#define glVertexAttribFormat              OGL__glVertexAttribFormat
#define glVertexAttribIFormat             OGL__glVertexAttribIFormat
#define glVertexAttribLFormat             OGL__glVertexAttribLFormat
#define glVertexAttribBinding             OGL__glVertexAttribBinding
#define glVertexBindingDivisor            OGL__glVertexBindingDivisor
#define glDebugMessageControl             OGL__glDebugMessageControl
#define glDebugMessageInsert              OGL__glDebugMessageInsert
#define glDebugMessageCallback            OGL__glDebugMessageCallback
#define glGetDebugMessageLog              OGL__glGetDebugMessageLog
#define glPushDebugGroup                  OGL__glPushDebugGroup
#define glPopDebugGroup                   OGL__glPopDebugGroup
#define glObjectLabel                     OGL__glObjectLabel
#define glGetObjectLabel                  OGL__glGetObjectLabel
#define glObjectPtrLabel                  OGL__glObjectPtrLabel
#define glGetObjectPtrLabel               OGL__glGetObjectPtrLabel

#endif // GL_VERSION_4_3

#endif // OPENGL_LOAD_GL_VERSION_4_3

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_LOAD_GL_VERSION_4_4

#ifndef GL_VERSION_4_4
#define GL_VERSION_4_4 1

#define GL_MAX_VERTEX_ATTRIB_STRIDE                   0x82E5
#define GL_PRIMITIVE_RESTART_FOR_PATCHES_SUPPORTED    0x8221
#define GL_TEXTURE_BUFFER_BINDING                     0x8C2A
#define GL_MAP_PERSISTENT_BIT                         0x0040
#define GL_MAP_COHERENT_BIT                           0x0080
#define GL_DYNAMIC_STORAGE_BIT                        0x0100
#define GL_CLIENT_STORAGE_BIT                         0x0200
#define GL_CLIENT_MAPPED_BUFFER_BARRIER_BIT           0x00004000
#define GL_BUFFER_IMMUTABLE_STORAGE                   0x821F
#define GL_BUFFER_STORAGE_FLAGS                       0x8220
#define GL_CLEAR_TEXTURE                              0x9365
#define GL_LOCATION_COMPONENT                         0x934A
#define GL_TRANSFORM_FEEDBACK_BUFFER_INDEX            0x934B
#define GL_TRANSFORM_FEEDBACK_BUFFER_STRIDE           0x934C
#define GL_QUERY_BUFFER                               0x9192
#define GL_QUERY_BUFFER_BARRIER_BIT                   0x00008000
#define GL_QUERY_BUFFER_BINDING                       0x9193
#define GL_QUERY_RESULT_NO_WAIT                       0x9194
#define GL_MIRROR_CLAMP_TO_EDGE                       0x8743

OPENGL_INIT_PROC(glBufferStorage,     void, GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
OPENGL_INIT_PROC(glClearTexImage,     void, GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
OPENGL_INIT_PROC(glClearTexSubImage,  void, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
OPENGL_INIT_PROC(glBindBuffersBase,   void, GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
OPENGL_INIT_PROC(glBindBuffersRange,  void, GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
OPENGL_INIT_PROC(glBindTextures,      void, GLuint first, GLsizei count, const GLuint *textures);
OPENGL_INIT_PROC(glBindSamplers,      void, GLuint first, GLsizei count, const GLuint *samplers);
OPENGL_INIT_PROC(glBindImageTextures, void, GLuint first, GLsizei count, const GLuint *textures);
OPENGL_INIT_PROC(glBindVertexBuffers, void, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);

#define glBufferStorage     OGL__glBufferStorage
#define glClearTexImage     OGL__glClearTexImage
#define glClearTexSubImage  OGL__glClearTexSubImage
#define glBindBuffersBase   OGL__glBindBuffersBase
#define glBindBuffersRange  OGL__glBindBuffersRange
#define glBindTextures      OGL__glBindTextures
#define glBindSamplers      OGL__glBindSamplers
#define glBindImageTextures OGL__glBindImageTextures
#define glBindVertexBuffers OGL__glBindVertexBuffers

#endif // GL_VERSION_4_4

#endif // OPENGL_LOAD_GL_VERSION_4_4

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_LOAD_GL_VERSION_4_5

#ifndef GL_VERSION_4_5
#define GL_VERSION_4_5 1

#define GL_CONTEXT_LOST                            0x0507
#define GL_NEGATIVE_ONE_TO_ONE                     0x935E
#define GL_ZERO_TO_ONE                             0x935F
#define GL_CLIP_ORIGIN                             0x935C
#define GL_CLIP_DEPTH_MODE                         0x935D
#define GL_QUERY_WAIT_INVERTED                     0x8E17
#define GL_QUERY_NO_WAIT_INVERTED                  0x8E18
#define GL_QUERY_BY_REGION_WAIT_INVERTED           0x8E19
#define GL_QUERY_BY_REGION_NO_WAIT_INVERTED        0x8E1A
#define GL_MAX_CULL_DISTANCES                      0x82F9
#define GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES    0x82FA
#define GL_TEXTURE_TARGET                          0x1006
#define GL_QUERY_TARGET                            0x82EA
#define GL_GUILTY_CONTEXT_RESET                    0x8253
#define GL_INNOCENT_CONTEXT_RESET                  0x8254
#define GL_UNKNOWN_CONTEXT_RESET                   0x8255
#define GL_RESET_NOTIFICATION_STRATEGY             0x8256
#define GL_LOSE_CONTEXT_ON_RESET                   0x8252
#define GL_NO_RESET_NOTIFICATION                   0x8261
#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT          0x00000004
#define GL_CONTEXT_RELEASE_BEHAVIOR                0x82FB
#define GL_CONTEXT_RELEASE_BEHAVIOR_FLUSH          0x82FC

OPENGL_INIT_PROC(glClipControl,                              void,      GLenum origin, GLenum depth);
OPENGL_INIT_PROC(glCreateTransformFeedbacks,                 void,      GLsizei n, GLuint *ids);
OPENGL_INIT_PROC(glTransformFeedbackBufferBase,              void,      GLuint xfb, GLuint index, GLuint buffer);
OPENGL_INIT_PROC(glTransformFeedbackBufferRange,             void,      GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
OPENGL_INIT_PROC(glGetTransformFeedbackiv,                   void,      GLuint xfb, GLenum pname, GLint *param);
OPENGL_INIT_PROC(glGetTransformFeedbacki_v,                  void,      GLuint xfb, GLenum pname, GLuint index, GLint *param);
OPENGL_INIT_PROC(glGetTransformFeedbacki64_v,                void,      GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
OPENGL_INIT_PROC(glCreateBuffers,                            void,      GLsizei n, GLuint *buffers);
OPENGL_INIT_PROC(glNamedBufferStorage,                       void,      GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
OPENGL_INIT_PROC(glNamedBufferData,                          void,      GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
OPENGL_INIT_PROC(glNamedBufferSubData,                       void,      GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
OPENGL_INIT_PROC(glCopyNamedBufferSubData,                   void,      GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
OPENGL_INIT_PROC(glClearNamedBufferData,                     void,      GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
OPENGL_INIT_PROC(glClearNamedBufferSubData,                  void,      GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
OPENGL_INIT_PROC(glMapNamedBuffer,                           void*,     GLuint buffer, GLenum access);
OPENGL_INIT_PROC(glMapNamedBufferRange,                      void*,     GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
OPENGL_INIT_PROC(glUnmapNamedBuffer,                         GLboolean, GLuint buffer);
OPENGL_INIT_PROC(glFlushMappedNamedBufferRange,              void,      GLuint buffer, GLintptr offset, GLsizeiptr length);
OPENGL_INIT_PROC(glGetNamedBufferParameteriv,                void,      GLuint buffer, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetNamedBufferParameteri64v,              void,      GLuint buffer, GLenum pname, GLint64 *params);
OPENGL_INIT_PROC(glGetNamedBufferPointerv,                   void,      GLuint buffer, GLenum pname, void **params);
OPENGL_INIT_PROC(glGetNamedBufferSubData,                    void,      GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
OPENGL_INIT_PROC(glCreateFramebuffers,                       void,      GLsizei n, GLuint *framebuffers);
OPENGL_INIT_PROC(glNamedFramebufferRenderbuffer,             void,      GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
OPENGL_INIT_PROC(glNamedFramebufferParameteri,               void,      GLuint framebuffer, GLenum pname, GLint param);
OPENGL_INIT_PROC(glNamedFramebufferTexture,                  void,      GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
OPENGL_INIT_PROC(glNamedFramebufferTextureLayer,             void,      GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
OPENGL_INIT_PROC(glNamedFramebufferDrawBuffer,               void,      GLuint framebuffer, GLenum buf);
OPENGL_INIT_PROC(glNamedFramebufferDrawBuffers,              void,      GLuint framebuffer, GLsizei n, const GLenum *bufs);
OPENGL_INIT_PROC(glNamedFramebufferReadBuffer,               void,      GLuint framebuffer, GLenum src);
OPENGL_INIT_PROC(glInvalidateNamedFramebufferData,           void,      GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
OPENGL_INIT_PROC(glInvalidateNamedFramebufferSubData,        void,      GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glClearNamedFramebufferiv,                  void,      GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
OPENGL_INIT_PROC(glClearNamedFramebufferuiv,                 void,      GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
OPENGL_INIT_PROC(glClearNamedFramebufferfv,                  void,      GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
OPENGL_INIT_PROC(glClearNamedFramebufferfi,                  void,      GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
OPENGL_INIT_PROC(glBlitNamedFramebuffer,                     void,      GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
OPENGL_INIT_PROC(glCheckNamedFramebufferStatus,              GLenum,    GLuint framebuffer, GLenum target);
OPENGL_INIT_PROC(glGetNamedFramebufferParameteriv,           void,      GLuint framebuffer, GLenum pname, GLint *param);
OPENGL_INIT_PROC(glGetNamedFramebufferAttachmentParameteriv, void,      GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glCreateRenderbuffers,                      void,      GLsizei n, GLuint *renderbuffers);
OPENGL_INIT_PROC(glNamedRenderbufferStorage,                 void,      GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glNamedRenderbufferStorageMultisample,      void,      GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glGetNamedRenderbufferParameteriv,          void,      GLuint renderbuffer, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glCreateTextures,                           void,      GLenum target, GLsizei n, GLuint *textures);
OPENGL_INIT_PROC(glTextureBuffer,                            void,      GLuint texture, GLenum internalformat, GLuint buffer);
OPENGL_INIT_PROC(glTextureBufferRange,                       void,      GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
OPENGL_INIT_PROC(glTextureStorage1D,                         void,      GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
OPENGL_INIT_PROC(glTextureStorage2D,                         void,      GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glTextureStorage3D,                         void,      GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
OPENGL_INIT_PROC(glTextureStorage2DMultisample,              void,      GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
OPENGL_INIT_PROC(glTextureStorage3DMultisample,              void,      GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
OPENGL_INIT_PROC(glTextureSubImage1D,                        void,      GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
OPENGL_INIT_PROC(glTextureSubImage2D,                        void,      GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
OPENGL_INIT_PROC(glTextureSubImage3D,                        void,      GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
OPENGL_INIT_PROC(glCompressedTextureSubImage1D,              void,      GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
OPENGL_INIT_PROC(glCompressedTextureSubImage2D,              void,      GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
OPENGL_INIT_PROC(glCompressedTextureSubImage3D,              void,      GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
OPENGL_INIT_PROC(glCopyTextureSubImage1D,                    void,      GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
OPENGL_INIT_PROC(glCopyTextureSubImage2D,                    void,      GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glCopyTextureSubImage3D,                    void,      GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glTextureParameterf,                        void,      GLuint texture, GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glTextureParameterfv,                       void,      GLuint texture, GLenum pname, const GLfloat *param);
OPENGL_INIT_PROC(glTextureParameteri,                        void,      GLuint texture, GLenum pname, GLint param);
OPENGL_INIT_PROC(glTextureParameterIiv,                      void,      GLuint texture, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glTextureParameterIuiv,                     void,      GLuint texture, GLenum pname, const GLuint *params);
OPENGL_INIT_PROC(glTextureParameteriv,                       void,      GLuint texture, GLenum pname, const GLint *param);
OPENGL_INIT_PROC(glGenerateTextureMipmap,                    void,      GLuint texture);
OPENGL_INIT_PROC(glBindTextureUnit,                          void,      GLuint unit, GLuint texture);
OPENGL_INIT_PROC(glGetTextureImage,                          void,      GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
OPENGL_INIT_PROC(glGetCompressedTextureImage,                void,      GLuint texture, GLint level, GLsizei bufSize, void *pixels);
OPENGL_INIT_PROC(glGetTextureLevelParameterfv,               void,      GLuint texture, GLint level, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetTextureLevelParameteriv,               void,      GLuint texture, GLint level, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetTextureParameterfv,                    void,      GLuint texture, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetTextureParameterIiv,                   void,      GLuint texture, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetTextureParameterIuiv,                  void,      GLuint texture, GLenum pname, GLuint *params);
OPENGL_INIT_PROC(glGetTextureParameteriv,                    void,      GLuint texture, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glCreateVertexArrays,                       void,      GLsizei n, GLuint *arrays);
OPENGL_INIT_PROC(glDisableVertexArrayAttrib,                 void,      GLuint vaobj, GLuint index);
OPENGL_INIT_PROC(glEnableVertexArrayAttrib,                  void,      GLuint vaobj, GLuint index);
OPENGL_INIT_PROC(glVertexArrayElementBuffer,                 void,      GLuint vaobj, GLuint buffer);
OPENGL_INIT_PROC(glVertexArrayVertexBuffer,                  void,      GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
OPENGL_INIT_PROC(glVertexArrayVertexBuffers,                 void,      GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
OPENGL_INIT_PROC(glVertexArrayAttribBinding,                 void,      GLuint vaobj, GLuint attribindex, GLuint bindingindex);
OPENGL_INIT_PROC(glVertexArrayAttribFormat,                  void,      GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
OPENGL_INIT_PROC(glVertexArrayAttribIFormat,                 void,      GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
OPENGL_INIT_PROC(glVertexArrayAttribLFormat,                 void,      GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
OPENGL_INIT_PROC(glVertexArrayBindingDivisor,                void,      GLuint vaobj, GLuint bindingindex, GLuint divisor);
OPENGL_INIT_PROC(glGetVertexArrayiv,                         void,      GLuint vaobj, GLenum pname, GLint *param);
OPENGL_INIT_PROC(glGetVertexArrayIndexediv,                  void,      GLuint vaobj, GLuint index, GLenum pname, GLint *param);
OPENGL_INIT_PROC(glGetVertexArrayIndexed64iv,                void,      GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
OPENGL_INIT_PROC(glCreateSamplers,                           void,      GLsizei n, GLuint *samplers);
OPENGL_INIT_PROC(glCreateProgramPipelines,                   void,      GLsizei n, GLuint *pipelines);
OPENGL_INIT_PROC(glCreateQueries,                            void,      GLenum target, GLsizei n, GLuint *ids);
OPENGL_INIT_PROC(glGetQueryBufferObjecti64v,                 void,      GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
OPENGL_INIT_PROC(glGetQueryBufferObjectiv,                   void,      GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
OPENGL_INIT_PROC(glGetQueryBufferObjectui64v,                void,      GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
OPENGL_INIT_PROC(glGetQueryBufferObjectuiv,                  void,      GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
OPENGL_INIT_PROC(glMemoryBarrierByRegion,                    void,      GLbitfield barriers);
OPENGL_INIT_PROC(glGetTextureSubImage,                       void,      GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
OPENGL_INIT_PROC(glGetCompressedTextureSubImage,             void,      GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
OPENGL_INIT_PROC(glGetGraphicsResetStatus,                   GLenum,    void);
OPENGL_INIT_PROC(glGetnCompressedTexImage,                   void,      GLenum target, GLint lod, GLsizei bufSize, void *pixels);
OPENGL_INIT_PROC(glGetnTexImage,                             void,      GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
OPENGL_INIT_PROC(glGetnUniformdv,                            void,      GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
OPENGL_INIT_PROC(glGetnUniformfv,                            void,      GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
OPENGL_INIT_PROC(glGetnUniformiv,                            void,      GLuint program, GLint location, GLsizei bufSize, GLint *params);
OPENGL_INIT_PROC(glGetnUniformuiv,                           void,      GLuint program, GLint location, GLsizei bufSize, GLuint *params);
OPENGL_INIT_PROC(glReadnPixels,                              void,      GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
OPENGL_INIT_PROC(glTextureBarrier,                           void,      void);
#ifdef OPENGL_USE_COMPATIBILITY_PROFILE
OPENGL_INIT_PROC(glGetnMapdv,                                void,      GLenum target, GLenum query, GLsizei bufSize, GLdouble *v);
OPENGL_INIT_PROC(glGetnMapfv,                                void,      GLenum target, GLenum query, GLsizei bufSize, GLfloat *v);
OPENGL_INIT_PROC(glGetnMapiv,                                void,      GLenum target, GLenum query, GLsizei bufSize, GLint *v);
OPENGL_INIT_PROC(glGetnPixelMapfv,                           void,      GLenum map, GLsizei bufSize, GLfloat *values);
OPENGL_INIT_PROC(glGetnPixelMapuiv,                          void,      GLenum map, GLsizei bufSize, GLuint *values);
OPENGL_INIT_PROC(glGetnPixelMapusv,                          void,      GLenum map, GLsizei bufSize, GLushort *values);
OPENGL_INIT_PROC(glGetnPolygonStipple,                       void,      GLsizei bufSize, GLubyte *pattern);
OPENGL_INIT_PROC(glGetnColorTable,                           void,      GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *table);
OPENGL_INIT_PROC(glGetnConvolutionFilter,                    void,      GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *image);
OPENGL_INIT_PROC(glGetnSeparableFilter,                      void,      GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void *row, GLsizei columnBufSize, void *column, void *span);
OPENGL_INIT_PROC(glGetnHistogram,                            void,      GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);
OPENGL_INIT_PROC(glGetnMinmax,                               void,      GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);
#endif // OPENGL_USE_COMPATIBILITY_PROFILE

#define glClipControl                              OGL__glClipControl
#define glCreateTransformFeedbacks                 OGL__glCreateTransformFeedbacks
#define glTransformFeedbackBufferBase              OGL__glTransformFeedbackBufferBase
#define glTransformFeedbackBufferRange             OGL__glTransformFeedbackBufferRange
#define glGetTransformFeedbackiv                   OGL__glGetTransformFeedbackiv
#define glGetTransformFeedbacki_v                  OGL__glGetTransformFeedbacki_v
#define glGetTransformFeedbacki64_v                OGL__glGetTransformFeedbacki64_v
#define glCreateBuffers                            OGL__glCreateBuffers
#define glNamedBufferStorage                       OGL__glNamedBufferStorage
#define glNamedBufferData                          OGL__glNamedBufferData
#define glNamedBufferSubData                       OGL__glNamedBufferSubData
#define glCopyNamedBufferSubData                   OGL__glCopyNamedBufferSubData
#define glClearNamedBufferData                     OGL__glClearNamedBufferData
#define glClearNamedBufferSubData                  OGL__glClearNamedBufferSubData
#define glMapNamedBuffer                           OGL__glMapNamedBuffer
#define glMapNamedBufferRange                      OGL__glMapNamedBufferRange
#define glUnmapNamedBuffer                         OGL__glUnmapNamedBuffer
#define glFlushMappedNamedBufferRange              OGL__glFlushMappedNamedBufferRange
#define glGetNamedBufferParameteriv                OGL__glGetNamedBufferParameteriv
#define glGetNamedBufferParameteri64v              OGL__glGetNamedBufferParameteri64v
#define glGetNamedBufferPointerv                   OGL__glGetNamedBufferPointerv
#define glGetNamedBufferSubData                    OGL__glGetNamedBufferSubData
#define glCreateFramebuffers                       OGL__glCreateFramebuffers
#define glNamedFramebufferRenderbuffer             OGL__glNamedFramebufferRenderbuffer
#define glNamedFramebufferParameteri               OGL__glNamedFramebufferParameteri
#define glNamedFramebufferTexture                  OGL__glNamedFramebufferTexture
#define glNamedFramebufferTextureLayer             OGL__glNamedFramebufferTextureLayer
#define glNamedFramebufferDrawBuffer               OGL__glNamedFramebufferDrawBuffer
#define glNamedFramebufferDrawBuffers              OGL__glNamedFramebufferDrawBuffers
#define glNamedFramebufferReadBuffer               OGL__glNamedFramebufferReadBuffer
#define glInvalidateNamedFramebufferData           OGL__glInvalidateNamedFramebufferData
#define glInvalidateNamedFramebufferSubData        OGL__glInvalidateNamedFramebufferSubData
#define glClearNamedFramebufferiv                  OGL__glClearNamedFramebufferiv
#define glClearNamedFramebufferuiv                 OGL__glClearNamedFramebufferuiv
#define glClearNamedFramebufferfv                  OGL__glClearNamedFramebufferfv
#define glClearNamedFramebufferfi                  OGL__glClearNamedFramebufferfi
#define glBlitNamedFramebuffer                     OGL__glBlitNamedFramebuffer
#define glCheckNamedFramebufferStatus              OGL__glCheckNamedFramebufferStatus
#define glGetNamedFramebufferParameteriv           OGL__glGetNamedFramebufferParameteriv
#define glGetNamedFramebufferAttachmentParameteriv OGL__glGetNamedFramebufferAttachmentParameteriv
#define glCreateRenderbuffers                      OGL__glCreateRenderbuffers
#define glNamedRenderbufferStorage                 OGL__glNamedRenderbufferStorage
#define glNamedRenderbufferStorageMultisample      OGL__glNamedRenderbufferStorageMultisample
#define glGetNamedRenderbufferParameteriv          OGL__glGetNamedRenderbufferParameteriv
#define glCreateTextures                           OGL__glCreateTextures
#define glTextureBuffer                            OGL__glTextureBuffer
#define glTextureBufferRange                       OGL__glTextureBufferRange
#define glTextureStorage1D                         OGL__glTextureStorage1D
#define glTextureStorage2D                         OGL__glTextureStorage2D
#define glTextureStorage3D                         OGL__glTextureStorage3D
#define glTextureStorage2DMultisample              OGL__glTextureStorage2DMultisample
#define glTextureStorage3DMultisample              OGL__glTextureStorage3DMultisample
#define glTextureSubImage1D                        OGL__glTextureSubImage1D
#define glTextureSubImage2D                        OGL__glTextureSubImage2D
#define glTextureSubImage3D                        OGL__glTextureSubImage3D
#define glCompressedTextureSubImage1D              OGL__glCompressedTextureSubImage1D
#define glCompressedTextureSubImage2D              OGL__glCompressedTextureSubImage2D
#define glCompressedTextureSubImage3D              OGL__glCompressedTextureSubImage3D
#define glCopyTextureSubImage1D                    OGL__glCopyTextureSubImage1D
#define glCopyTextureSubImage2D                    OGL__glCopyTextureSubImage2D
#define glCopyTextureSubImage3D                    OGL__glCopyTextureSubImage3D
#define glTextureParameterf                        OGL__glTextureParameterf
#define glTextureParameterfv                       OGL__glTextureParameterfv
#define glTextureParameteri                        OGL__glTextureParameteri
#define glTextureParameterIiv                      OGL__glTextureParameterIiv
#define glTextureParameterIuiv                     OGL__glTextureParameterIuiv
#define glTextureParameteriv                       OGL__glTextureParameteriv
#define glGenerateTextureMipmap                    OGL__glGenerateTextureMipmap
#define glBindTextureUnit                          OGL__glBindTextureUnit
#define glGetTextureImage                          OGL__glGetTextureImage
#define glGetCompressedTextureImage                OGL__glGetCompressedTextureImage
#define glGetTextureLevelParameterfv               OGL__glGetTextureLevelParameterfv
#define glGetTextureLevelParameteriv               OGL__glGetTextureLevelParameteriv
#define glGetTextureParameterfv                    OGL__glGetTextureParameterfv
#define glGetTextureParameterIiv                   OGL__glGetTextureParameterIiv
#define glGetTextureParameterIuiv                  OGL__glGetTextureParameterIuiv
#define glGetTextureParameteriv                    OGL__glGetTextureParameteriv
#define glCreateVertexArrays                       OGL__glCreateVertexArrays
#define glDisableVertexArrayAttrib                 OGL__glDisableVertexArrayAttrib
#define glEnableVertexArrayAttrib                  OGL__glEnableVertexArrayAttrib
#define glVertexArrayElementBuffer                 OGL__glVertexArrayElementBuffer
#define glVertexArrayVertexBuffer                  OGL__glVertexArrayVertexBuffer
#define glVertexArrayVertexBuffers                 OGL__glVertexArrayVertexBuffers
#define glVertexArrayAttribBinding                 OGL__glVertexArrayAttribBinding
#define glVertexArrayAttribFormat                  OGL__glVertexArrayAttribFormat
#define glVertexArrayAttribIFormat                 OGL__glVertexArrayAttribIFormat
#define glVertexArrayAttribLFormat                 OGL__glVertexArrayAttribLFormat
#define glVertexArrayBindingDivisor                OGL__glVertexArrayBindingDivisor
#define glGetVertexArrayiv                         OGL__glGetVertexArrayiv
#define glGetVertexArrayIndexediv                  OGL__glGetVertexArrayIndexediv
#define glGetVertexArrayIndexed64iv                OGL__glGetVertexArrayIndexed64iv
#define glCreateSamplers                           OGL__glCreateSamplers
#define glCreateProgramPipelines                   OGL__glCreateProgramPipelines
#define glCreateQueries                            OGL__glCreateQueries
#define glGetQueryBufferObjecti64v                 OGL__glGetQueryBufferObjecti64v
#define glGetQueryBufferObjectiv                   OGL__glGetQueryBufferObjectiv
#define glGetQueryBufferObjectui64v                OGL__glGetQueryBufferObjectui64v
#define glGetQueryBufferObjectuiv                  OGL__glGetQueryBufferObjectuiv
#define glMemoryBarrierByRegion                    OGL__glMemoryBarrierByRegion
#define glGetTextureSubImage                       OGL__glGetTextureSubImage
#define glGetCompressedTextureSubImage             OGL__glGetCompressedTextureSubImage
#define glGetGraphicsResetStatus                   OGL__glGetGraphicsResetStatus
#define glGetnCompressedTexImage                   OGL__glGetnCompressedTexImage
#define glGetnTexImage                             OGL__glGetnTexImage
#define glGetnUniformdv                            OGL__glGetnUniformdv
#define glGetnUniformfv                            OGL__glGetnUniformfv
#define glGetnUniformiv                            OGL__glGetnUniformiv
#define glGetnUniformuiv                           OGL__glGetnUniformuiv
#define glReadnPixels                              OGL__glReadnPixels
#define glTextureBarrier                           OGL__glTextureBarrier
#ifdef OPENGL_USE_COMPATIBILITY_PROFILE
#define glGetnMapdv                                OGL__glGetnMapdv
#define glGetnMapfv                                OGL__glGetnMapfv
#define glGetnMapiv                                OGL__glGetnMapiv
#define glGetnPixelMapfv                           OGL__glGetnPixelMapfv
#define glGetnPixelMapuiv                          OGL__glGetnPixelMapuiv
#define glGetnPixelMapusv                          OGL__glGetnPixelMapusv
#define glGetnPolygonStipple                       OGL__glGetnPolygonStipple
#define glGetnColorTable                           OGL__glGetnColorTable
#define glGetnConvolutionFilter                    OGL__glGetnConvolutionFilter
#define glGetnSeparableFilter                      OGL__glGetnSeparableFilter
#define glGetnHistogram                            OGL__glGetnHistogram
#define glGetnMinmax                               OGL__glGetnMinmax
#endif // OPENGL_USE_COMPATIBILITY_PROFILE

#endif // GL_VERSION_4_5

#endif // OPENGL_LOAD_GL_VERSION_4_5

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_LOAD_GL_VERSION_4_6

#ifndef GL_VERSION_4_6
#define GL_VERSION_4_6 1

#define GL_SHADER_BINARY_FORMAT_SPIR_V           0x9551
#define GL_SPIR_V_BINARY                         0x9552
#define GL_PARAMETER_BUFFER                      0x80EE
#define GL_PARAMETER_BUFFER_BINDING              0x80EF
#define GL_CONTEXT_FLAG_NO_ERROR_BIT             0x00000008
#define GL_VERTICES_SUBMITTED                    0x82EE
#define GL_PRIMITIVES_SUBMITTED                  0x82EF
#define GL_VERTEX_SHADER_INVOCATIONS             0x82F0
#define GL_TESS_CONTROL_SHADER_PATCHES           0x82F1
#define GL_TESS_EVALUATION_SHADER_INVOCATIONS    0x82F2
#define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED    0x82F3
#define GL_FRAGMENT_SHADER_INVOCATIONS           0x82F4
#define GL_COMPUTE_SHADER_INVOCATIONS            0x82F5
#define GL_CLIPPING_INPUT_PRIMITIVES             0x82F6
#define GL_CLIPPING_OUTPUT_PRIMITIVES            0x82F7
#define GL_POLYGON_OFFSET_CLAMP                  0x8E1B
#define GL_SPIR_V_EXTENSIONS                     0x9553
#define GL_NUM_SPIR_V_EXTENSIONS                 0x9554
#define GL_TEXTURE_MAX_ANISOTROPY                0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY            0x84FF
#define GL_TRANSFORM_FEEDBACK_OVERFLOW           0x82EC
#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW    0x82ED

OPENGL_INIT_PROC(glMultiDrawArraysIndirectCount,   void, GLenum mode, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
OPENGL_INIT_PROC(glMultiDrawElementsIndirectCount, void, GLenum mode, GLenum type, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
OPENGL_INIT_PROC(glPolygonOffsetClamp,             void, GLfloat factor, GLfloat units, GLfloat clamp);
OPENGL_INIT_PROC(glSpecializeShader,               void, GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue);

#define glMultiDrawArraysIndirectCount   OGL__glMultiDrawArraysIndirectCount
#define glMultiDrawElementsIndirectCount OGL__glMultiDrawElementsIndirectCount
#define glPolygonOffsetClamp             OGL__glPolygonOffsetClamp
#define glSpecializeShader               OGL__glSpecializeShader

#endif // GL_VERSION_4_6

#endif // OPENGL_LOAD_GL_VERSION_4_6

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_ES2_compatibility
#define GL_ARB_ES2_compatibility 1

#endif // GL_ARB_ES2_compatibility

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_ES3_1_compatibility
#define GL_ARB_ES3_1_compatibility 1

#endif // GL_ARB_ES3_1_compatibility

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_ES3_2_compatibility

#ifndef GL_ARB_ES3_2_compatibility
#define GL_ARB_ES3_2_compatibility 1

#define GL_PRIMITIVE_BOUNDING_BOX_ARB                0x92BE
#define GL_MULTISAMPLE_LINE_WIDTH_RANGE_ARB          0x9381
#define GL_MULTISAMPLE_LINE_WIDTH_GRANULARITY_ARB    0x9382

OPENGL_INIT_PROC(glPrimitiveBoundingBoxARB, void, GLfloat minX, GLfloat minY, GLfloat minZ, GLfloat minW, GLfloat maxX, GLfloat maxY, GLfloat maxZ, GLfloat maxW);
#define glPrimitiveBoundingBoxARB OGL__glPrimitiveBoundingBoxARB

#endif // GL_ARB_ES3_2_compatibility

#endif // OPENGL_INCLUDE_GL_ARB_ES3_2_compatibility

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_ES3_compatibility
#define GL_ARB_ES3_compatibility 1

#endif // GL_ARB_ES3_compatibility

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_arrays_of_arrays
#define GL_ARB_arrays_of_arrays 1

#endif // GL_ARB_arrays_of_arrays

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_base_instance
#define GL_ARB_base_instance 1

#endif // GL_ARB_base_instance

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_bindless_texture

#ifndef GL_ARB_bindless_texture
#define GL_ARB_bindless_texture 1

#define GL_UNSIGNED_INT64_ARB    0x140F

OPENGL_INIT_PROC(glGetTextureHandleARB,             GLuint64,  GLuint texture);
OPENGL_INIT_PROC(glGetTextureSamplerHandleARB,      GLuint64,  GLuint texture, GLuint sampler);
OPENGL_INIT_PROC(glMakeTextureHandleResidentARB,    void,      GLuint64 handle);
OPENGL_INIT_PROC(glMakeTextureHandleNonResidentARB, void,      GLuint64 handle);
OPENGL_INIT_PROC(glGetImageHandleARB,               GLuint64,  GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
OPENGL_INIT_PROC(glMakeImageHandleResidentARB,      void,      GLuint64 handle, GLenum access);
OPENGL_INIT_PROC(glMakeImageHandleNonResidentARB,   void,      GLuint64 handle);
OPENGL_INIT_PROC(glUniformHandleui64ARB,            void,      GLint location, GLuint64 value);
OPENGL_INIT_PROC(glUniformHandleui64vARB,           void,      GLint location, GLsizei count, const GLuint64 *value);
OPENGL_INIT_PROC(glProgramUniformHandleui64ARB,     void,      GLuint program, GLint location, GLuint64 value);
OPENGL_INIT_PROC(glProgramUniformHandleui64vARB,    void,      GLuint program, GLint location, GLsizei count, const GLuint64 *values);
OPENGL_INIT_PROC(glIsTextureHandleResidentARB,      GLboolean, GLuint64 handle);
OPENGL_INIT_PROC(glIsImageHandleResidentARB,        GLboolean, GLuint64 handle);
OPENGL_INIT_PROC(glVertexAttribL1ui64ARB,           void,      GLuint index, GLuint64EXT x);
OPENGL_INIT_PROC(glVertexAttribL1ui64vARB,          void,      GLuint index, const GLuint64EXT *v);
OPENGL_INIT_PROC(glGetVertexAttribLui64vARB,        void,      GLuint index, GLenum pname, GLuint64EXT *params);

#define glGetTextureHandleARB             OGL__glGetTextureHandleARB
#define glGetTextureSamplerHandleARB      OGL__glGetTextureSamplerHandleARB
#define glMakeTextureHandleResidentARB    OGL__glMakeTextureHandleResidentARB
#define glMakeTextureHandleNonResidentARB OGL__glMakeTextureHandleNonResidentARB
#define glGetImageHandleARB               OGL__glGetImageHandleARB
#define glMakeImageHandleResidentARB      OGL__glMakeImageHandleResidentARB
#define glMakeImageHandleNonResidentARB   OGL__glMakeImageHandleNonResidentARB
#define glUniformHandleui64ARB            OGL__glUniformHandleui64ARB
#define glUniformHandleui64vARB           OGL__glUniformHandleui64vARB
#define glProgramUniformHandleui64ARB     OGL__glProgramUniformHandleui64ARB
#define glProgramUniformHandleui64vARB    OGL__glProgramUniformHandleui64vARB
#define glIsTextureHandleResidentARB      OGL__glIsTextureHandleResidentARB
#define glIsImageHandleResidentARB        OGL__glIsImageHandleResidentARB
#define glVertexAttribL1ui64ARB           OGL__glVertexAttribL1ui64ARB
#define glVertexAttribL1ui64vARB          OGL__glVertexAttribL1ui64vARB
#define glGetVertexAttribLui64vARB        OGL__glGetVertexAttribLui64vARB

#endif // GL_ARB_bindless_texture

#endif // OPENGL_INCLUDE_GL_ARB_bindless_texture

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_blend_func_extended
#define GL_ARB_blend_func_extended 1

#endif // GL_ARB_blend_func_extended

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_buffer_storage
#define GL_ARB_buffer_storage 1

#endif // GL_ARB_buffer_storage

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_cl_event

#ifndef GL_ARB_cl_event
#define GL_ARB_cl_event 1

#define GL_SYNC_CL_EVENT_ARB             0x8240
#define GL_SYNC_CL_EVENT_COMPLETE_ARB    0x8241

OPENGL_INIT_PROC(glCreateSyncFromCLeventARB, GLsync, struct _cl_context *context, struct _cl_event *event, GLbitfield flags);
#define glCreateSyncFromCLeventARB OGL__glCreateSyncFromCLeventARB

#endif // GL_ARB_cl_event

#endif // OPENGL_INCLUDE_GL_ARB_cl_event

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_clear_buffer_object
#define GL_ARB_clear_buffer_object 1

#endif // GL_ARB_clear_buffer_object

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_clear_texture
#define GL_ARB_clear_texture 1

#endif // GL_ARB_clear_texture

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_clip_control
#define GL_ARB_clip_control 1

#endif // GL_ARB_clip_control

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_color_buffer_float

#ifndef GL_ARB_color_buffer_float
#define GL_ARB_color_buffer_float 1

#define GL_RGBA_FLOAT_MODE_ARB         0x8820
#define GL_CLAMP_VERTEX_COLOR_ARB      0x891A
#define GL_CLAMP_FRAGMENT_COLOR_ARB    0x891B
#define GL_CLAMP_READ_COLOR_ARB        0x891C
#define GL_FIXED_ONLY_ARB              0x891D

OPENGL_INIT_PROC(glClampColorARB, void, GLenum target, GLenum clamp);
#define glClampColorARB OGL__glClampColorARB

#endif // GL_ARB_color_buffer_float

#endif // OPENGL_INCLUDE_GL_ARB_color_buffer_float

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_compatibility
#define GL_ARB_compatibility 1

#endif // GL_ARB_compatibility

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_compressed_texture_pixel_storage
#define GL_ARB_compressed_texture_pixel_storage 1

#endif // GL_ARB_compressed_texture_pixel_storage

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_compute_shader
#define GL_ARB_compute_shader 1

#endif // GL_ARB_compute_shader

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_compute_variable_group_size

#ifndef GL_ARB_compute_variable_group_size
#define GL_ARB_compute_variable_group_size 1

#define GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB    0x9344
#define GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB       0x90EB
#define GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB           0x9345
#define GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB              0x91BF

OPENGL_INIT_PROC(glDispatchComputeGroupSizeARB, void, GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z, GLuint group_size_x, GLuint group_size_y, GLuint group_size_z);
#define glDispatchComputeGroupSizeARB OGL__glDispatchComputeGroupSizeARB

#endif // GL_ARB_compute_variable_group_size

#endif // OPENGL_INCLUDE_GL_ARB_compute_variable_group_size

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_conditional_render_inverted
#define GL_ARB_conditional_render_inverted 1

#endif // GL_ARB_conditional_render_inverted

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_conservative_depth
#define GL_ARB_conservative_depth 1

#endif // GL_ARB_conservative_depth

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_copy_buffer
#define GL_ARB_copy_buffer 1

#endif // GL_ARB_copy_buffer

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_copy_image
#define GL_ARB_copy_image 1

#endif // GL_ARB_copy_image

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_cull_distance
#define GL_ARB_cull_distance 1

#endif // GL_ARB_cull_distance

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_debug_output

#ifndef GL_ARB_debug_output
#define GL_ARB_debug_output 1

#define GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB            0x8242
#define GL_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_ARB    0x8243
#define GL_DEBUG_CALLBACK_FUNCTION_ARB             0x8244
#define GL_DEBUG_CALLBACK_USER_PARAM_ARB           0x8245
#define GL_DEBUG_SOURCE_API_ARB                    0x8246
#define GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB          0x8247
#define GL_DEBUG_SOURCE_SHADER_COMPILER_ARB        0x8248
#define GL_DEBUG_SOURCE_THIRD_PARTY_ARB            0x8249
#define GL_DEBUG_SOURCE_APPLICATION_ARB            0x824A
#define GL_DEBUG_SOURCE_OTHER_ARB                  0x824B
#define GL_DEBUG_TYPE_ERROR_ARB                    0x824C
#define GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB      0x824D
#define GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB       0x824E
#define GL_DEBUG_TYPE_PORTABILITY_ARB              0x824F
#define GL_DEBUG_TYPE_PERFORMANCE_ARB              0x8250
#define GL_DEBUG_TYPE_OTHER_ARB                    0x8251
#define GL_MAX_DEBUG_MESSAGE_LENGTH_ARB            0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES_ARB           0x9144
#define GL_DEBUG_LOGGED_MESSAGES_ARB               0x9145
#define GL_DEBUG_SEVERITY_HIGH_ARB                 0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_ARB               0x9147
#define GL_DEBUG_SEVERITY_LOW_ARB                  0x9148

OPENGL_INIT_PROC(glDebugMessageControlARB,  void,   GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
OPENGL_INIT_PROC(glDebugMessageInsertARB,   void,   GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
OPENGL_INIT_PROC(glDebugMessageCallbackARB, void,   GLDEBUGPROCARB callback, const void *userParam);
OPENGL_INIT_PROC(glGetDebugMessageLogARB,   GLuint, GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);

#define glDebugMessageControlARB  OGL__glDebugMessageControlARB
#define glDebugMessageInsertARB   OGL__glDebugMessageInsertARB
#define glDebugMessageCallbackARB OGL__glDebugMessageCallbackARB
#define glGetDebugMessageLogARB   OGL__glGetDebugMessageLogARB

#endif // GL_ARB_debug_output

#endif // OPENGL_INCLUDE_GL_ARB_debug_output

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_depth_buffer_float
#define GL_ARB_depth_buffer_float 1

#endif // GL_ARB_depth_buffer_float

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_depth_clamp
#define GL_ARB_depth_clamp 1

#endif // GL_ARB_depth_clamp

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_depth_texture
#define GL_ARB_depth_texture 1

#define GL_DEPTH_COMPONENT16_ARB     0x81A5
#define GL_DEPTH_COMPONENT24_ARB     0x81A6
#define GL_DEPTH_COMPONENT32_ARB     0x81A7
#define GL_TEXTURE_DEPTH_SIZE_ARB    0x884A
#define GL_DEPTH_TEXTURE_MODE_ARB    0x884B

#endif // GL_ARB_depth_texture

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_derivative_control
#define GL_ARB_derivative_control 1

#endif // GL_ARB_derivative_control

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_direct_state_access
#define GL_ARB_direct_state_access 1

#endif // GL_ARB_direct_state_access

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_draw_buffers

#ifndef GL_ARB_draw_buffers
#define GL_ARB_draw_buffers 1

#define GL_MAX_DRAW_BUFFERS_ARB    0x8824
#define GL_DRAW_BUFFER0_ARB        0x8825
#define GL_DRAW_BUFFER1_ARB        0x8826
#define GL_DRAW_BUFFER2_ARB        0x8827
#define GL_DRAW_BUFFER3_ARB        0x8828
#define GL_DRAW_BUFFER4_ARB        0x8829
#define GL_DRAW_BUFFER5_ARB        0x882A
#define GL_DRAW_BUFFER6_ARB        0x882B
#define GL_DRAW_BUFFER7_ARB        0x882C
#define GL_DRAW_BUFFER8_ARB        0x882D
#define GL_DRAW_BUFFER9_ARB        0x882E
#define GL_DRAW_BUFFER10_ARB       0x882F
#define GL_DRAW_BUFFER11_ARB       0x8830
#define GL_DRAW_BUFFER12_ARB       0x8831
#define GL_DRAW_BUFFER13_ARB       0x8832
#define GL_DRAW_BUFFER14_ARB       0x8833
#define GL_DRAW_BUFFER15_ARB       0x8834

OPENGL_INIT_PROC(glDrawBuffersARB, void, GLsizei n, const GLenum *bufs);
#define glDrawBuffersARB OGL__glDrawBuffersARB

#endif // GL_ARB_draw_buffers

#endif // OPENGL_INCLUDE_GL_ARB_draw_buffers

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_draw_buffers_blend

#ifndef GL_ARB_draw_buffers_blend
#define GL_ARB_draw_buffers_blend 1

OPENGL_INIT_PROC(glBlendEquationiARB,         void, GLuint buf, GLenum mode);
OPENGL_INIT_PROC(glBlendEquationSeparateiARB, void, GLuint buf, GLenum modeRGB, GLenum modeAlpha);
OPENGL_INIT_PROC(glBlendFunciARB,             void, GLuint buf, GLenum src, GLenum dst);
OPENGL_INIT_PROC(glBlendFuncSeparateiARB,     void, GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);

#define glBlendEquationiARB         OGL__glBlendEquationiARB
#define glBlendEquationSeparateiARB OGL__glBlendEquationSeparateiARB
#define glBlendFunciARB             OGL__glBlendFunciARB
#define glBlendFuncSeparateiARB     OGL__glBlendFuncSeparateiARB

#endif // GL_ARB_draw_buffers_blend

#endif // OPENGL_INCLUDE_GL_ARB_draw_buffers_blend

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_draw_elements_base_vertex
#define GL_ARB_draw_elements_base_vertex 1

#endif // GL_ARB_draw_elements_base_vertex

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_draw_indirect
#define GL_ARB_draw_indirect 1

#endif // GL_ARB_draw_indirect

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_draw_instanced

#ifndef GL_ARB_draw_instanced
#define GL_ARB_draw_instanced 1

OPENGL_INIT_PROC(glDrawArraysInstancedARB,   void, GLenum mode, GLint first, GLsizei count, GLsizei primcount);
OPENGL_INIT_PROC(glDrawElementsInstancedARB, void, GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount);

#define glDrawArraysInstancedARB   OGL__glDrawArraysInstancedARB
#define glDrawElementsInstancedARB OGL__glDrawElementsInstancedARB

#endif // GL_ARB_draw_instanced

#endif // OPENGL_INCLUDE_GL_ARB_draw_instanced

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_enhanced_layouts
#define GL_ARB_enhanced_layouts 1

#endif // GL_ARB_enhanced_layouts

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_explicit_attrib_location
#define GL_ARB_explicit_attrib_location 1

#endif // GL_ARB_explicit_attrib_location

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_explicit_uniform_location
#define GL_ARB_explicit_uniform_location 1

#endif // GL_ARB_explicit_uniform_location

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_fragment_coord_conventions
#define GL_ARB_fragment_coord_conventions 1

#endif // GL_ARB_fragment_coord_conventions

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_fragment_layer_viewport
#define GL_ARB_fragment_layer_viewport 1

#endif // GL_ARB_fragment_layer_viewport

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_fragment_program

#ifndef GL_ARB_fragment_program
#define GL_ARB_fragment_program 1

#define GL_FRAGMENT_PROGRAM_ARB                       0x8804
#define GL_PROGRAM_FORMAT_ASCII_ARB                   0x8875
#define GL_PROGRAM_LENGTH_ARB                         0x8627
#define GL_PROGRAM_FORMAT_ARB                         0x8876
#define GL_PROGRAM_BINDING_ARB                        0x8677
#define GL_PROGRAM_INSTRUCTIONS_ARB                   0x88A0
#define GL_MAX_PROGRAM_INSTRUCTIONS_ARB               0x88A1
#define GL_PROGRAM_NATIVE_INSTRUCTIONS_ARB            0x88A2
#define GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB        0x88A3
#define GL_PROGRAM_TEMPORARIES_ARB                    0x88A4
#define GL_MAX_PROGRAM_TEMPORARIES_ARB                0x88A5
#define GL_PROGRAM_NATIVE_TEMPORARIES_ARB             0x88A6
#define GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB         0x88A7
#define GL_PROGRAM_PARAMETERS_ARB                     0x88A8
#define GL_MAX_PROGRAM_PARAMETERS_ARB                 0x88A9
#define GL_PROGRAM_NATIVE_PARAMETERS_ARB              0x88AA
#define GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB          0x88AB
#define GL_PROGRAM_ATTRIBS_ARB                        0x88AC
#define GL_MAX_PROGRAM_ATTRIBS_ARB                    0x88AD
#define GL_PROGRAM_NATIVE_ATTRIBS_ARB                 0x88AE
#define GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB             0x88AF
#define GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB           0x88B4
#define GL_MAX_PROGRAM_ENV_PARAMETERS_ARB             0x88B5
#define GL_PROGRAM_UNDER_NATIVE_LIMITS_ARB            0x88B6
#define GL_PROGRAM_ALU_INSTRUCTIONS_ARB               0x8805
#define GL_PROGRAM_TEX_INSTRUCTIONS_ARB               0x8806
#define GL_PROGRAM_TEX_INDIRECTIONS_ARB               0x8807
#define GL_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB        0x8808
#define GL_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB        0x8809
#define GL_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB        0x880A
#define GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB           0x880B
#define GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB           0x880C
#define GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB           0x880D
#define GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB    0x880E
#define GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB    0x880F
#define GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB    0x8810
#define GL_PROGRAM_STRING_ARB                         0x8628
#define GL_PROGRAM_ERROR_POSITION_ARB                 0x864B
#define GL_CURRENT_MATRIX_ARB                         0x8641
#define GL_TRANSPOSE_CURRENT_MATRIX_ARB               0x88B7
#define GL_CURRENT_MATRIX_STACK_DEPTH_ARB             0x8640
#define GL_MAX_PROGRAM_MATRICES_ARB                   0x862F
#define GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB         0x862E
#define GL_MAX_TEXTURE_COORDS_ARB                     0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_ARB                0x8872
#define GL_PROGRAM_ERROR_STRING_ARB                   0x8874
#define GL_MATRIX0_ARB                                0x88C0
#define GL_MATRIX1_ARB                                0x88C1
#define GL_MATRIX2_ARB                                0x88C2
#define GL_MATRIX3_ARB                                0x88C3
#define GL_MATRIX4_ARB                                0x88C4
#define GL_MATRIX5_ARB                                0x88C5
#define GL_MATRIX6_ARB                                0x88C6
#define GL_MATRIX7_ARB                                0x88C7
#define GL_MATRIX8_ARB                                0x88C8
#define GL_MATRIX9_ARB                                0x88C9
#define GL_MATRIX10_ARB                               0x88CA
#define GL_MATRIX11_ARB                               0x88CB
#define GL_MATRIX12_ARB                               0x88CC
#define GL_MATRIX13_ARB                               0x88CD
#define GL_MATRIX14_ARB                               0x88CE
#define GL_MATRIX15_ARB                               0x88CF
#define GL_MATRIX16_ARB                               0x88D0
#define GL_MATRIX17_ARB                               0x88D1
#define GL_MATRIX18_ARB                               0x88D2
#define GL_MATRIX19_ARB                               0x88D3
#define GL_MATRIX20_ARB                               0x88D4
#define GL_MATRIX21_ARB                               0x88D5
#define GL_MATRIX22_ARB                               0x88D6
#define GL_MATRIX23_ARB                               0x88D7
#define GL_MATRIX24_ARB                               0x88D8
#define GL_MATRIX25_ARB                               0x88D9
#define GL_MATRIX26_ARB                               0x88DA
#define GL_MATRIX27_ARB                               0x88DB
#define GL_MATRIX28_ARB                               0x88DC
#define GL_MATRIX29_ARB                               0x88DD
#define GL_MATRIX30_ARB                               0x88DE
#define GL_MATRIX31_ARB                               0x88DF

OPENGL_INIT_PROC(glProgramStringARB,              void,      GLenum target, GLenum format, GLsizei len, const void *string);
OPENGL_INIT_PROC(glBindProgramARB,                void,      GLenum target, GLuint program);
OPENGL_INIT_PROC(glDeleteProgramsARB,             void,      GLsizei n, const GLuint *programs);
OPENGL_INIT_PROC(glGenProgramsARB,                void,      GLsizei n, GLuint *programs);
OPENGL_INIT_PROC(glProgramEnvParameter4dARB,      void,      GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
OPENGL_INIT_PROC(glProgramEnvParameter4dvARB,     void,      GLenum target, GLuint index, const GLdouble *params);
OPENGL_INIT_PROC(glProgramEnvParameter4fARB,      void,      GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
OPENGL_INIT_PROC(glProgramEnvParameter4fvARB,     void,      GLenum target, GLuint index, const GLfloat *params);
OPENGL_INIT_PROC(glProgramLocalParameter4dARB,    void,      GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
OPENGL_INIT_PROC(glProgramLocalParameter4dvARB,   void,      GLenum target, GLuint index, const GLdouble *params);
OPENGL_INIT_PROC(glProgramLocalParameter4fARB,    void,      GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
OPENGL_INIT_PROC(glProgramLocalParameter4fvARB,   void,      GLenum target, GLuint index, const GLfloat *params);
OPENGL_INIT_PROC(glGetProgramEnvParameterdvARB,   void,      GLenum target, GLuint index, GLdouble *params);
OPENGL_INIT_PROC(glGetProgramEnvParameterfvARB,   void,      GLenum target, GLuint index, GLfloat *params);
OPENGL_INIT_PROC(glGetProgramLocalParameterdvARB, void,      GLenum target, GLuint index, GLdouble *params);
OPENGL_INIT_PROC(glGetProgramLocalParameterfvARB, void,      GLenum target, GLuint index, GLfloat *params);
OPENGL_INIT_PROC(glGetProgramivARB,               void,      GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetProgramStringARB,           void,      GLenum target, GLenum pname, void *string);
OPENGL_INIT_PROC(glIsProgramARB,                  GLboolean, GLuint program);

#define glProgramStringARB              OGL__glProgramStringARB
#define glBindProgramARB                OGL__glBindProgramARB
#define glDeleteProgramsARB             OGL__glDeleteProgramsARB
#define glGenProgramsARB                OGL__glGenProgramsARB
#define glProgramEnvParameter4dARB      OGL__glProgramEnvParameter4dARB
#define glProgramEnvParameter4dvARB     OGL__glProgramEnvParameter4dvARB
#define glProgramEnvParameter4fARB      OGL__glProgramEnvParameter4fARB
#define glProgramEnvParameter4fvARB     OGL__glProgramEnvParameter4fvARB
#define glProgramLocalParameter4dARB    OGL__glProgramLocalParameter4dARB
#define glProgramLocalParameter4dvARB   OGL__glProgramLocalParameter4dvARB
#define glProgramLocalParameter4fARB    OGL__glProgramLocalParameter4fARB
#define glProgramLocalParameter4fvARB   OGL__glProgramLocalParameter4fvARB
#define glGetProgramEnvParameterdvARB   OGL__glGetProgramEnvParameterdvARB
#define glGetProgramEnvParameterfvARB   OGL__glGetProgramEnvParameterfvARB
#define glGetProgramLocalParameterdvARB OGL__glGetProgramLocalParameterdvARB
#define glGetProgramLocalParameterfvARB OGL__glGetProgramLocalParameterfvARB
#define glGetProgramivARB               OGL__glGetProgramivARB
#define glGetProgramStringARB           OGL__glGetProgramStringARB
#define glIsProgramARB                  OGL__glIsProgramARB

#endif // GL_ARB_fragment_program

#endif // OPENGL_INCLUDE_GL_ARB_fragment_program

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_fragment_program_shadow
#define GL_ARB_fragment_program_shadow 1

#endif // GL_ARB_fragment_program_shadow

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_fragment_shader
#define GL_ARB_fragment_shader 1

#define GL_FRAGMENT_SHADER_ARB                    0x8B30
#define GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB    0x8B49
#define GL_FRAGMENT_SHADER_DERIVATIVE_HINT_ARB    0x8B8B

#endif // GL_ARB_fragment_shader

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_fragment_shader_interlock
#define GL_ARB_fragment_shader_interlock 1

#endif // GL_ARB_fragment_shader_interlock

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_framebuffer_no_attachments
#define GL_ARB_framebuffer_no_attachments 1

#endif // GL_ARB_framebuffer_no_attachments

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_framebuffer_object
#define GL_ARB_framebuffer_object 1

#endif // GL_ARB_framebuffer_object

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_framebuffer_sRGB
#define GL_ARB_framebuffer_sRGB 1

#endif // GL_ARB_framebuffer_sRGB

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_geometry_shader4

#ifndef GL_ARB_geometry_shader4
#define GL_ARB_geometry_shader4 1

#define GL_LINES_ADJACENCY_ARB                         0x000A
#define GL_LINE_STRIP_ADJACENCY_ARB                    0x000B
#define GL_TRIANGLES_ADJACENCY_ARB                     0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY_ARB                0x000D
#define GL_PROGRAM_POINT_SIZE_ARB                      0x8642
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB        0x8C29
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_ARB          0x8DA7
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_ARB    0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_ARB      0x8DA9
#define GL_GEOMETRY_SHADER_ARB                         0x8DD9
#define GL_GEOMETRY_VERTICES_OUT_ARB                   0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_ARB                     0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_ARB                    0x8DDC
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB         0x8DDD
#define GL_MAX_VERTEX_VARYING_COMPONENTS_ARB           0x8DDE
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB         0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB            0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB    0x8DE1

OPENGL_INIT_PROC(glProgramParameteriARB,       void, GLuint program, GLenum pname, GLint value);
OPENGL_INIT_PROC(glFramebufferTextureARB,      void, GLenum target, GLenum attachment, GLuint texture, GLint level);
OPENGL_INIT_PROC(glFramebufferTextureLayerARB, void, GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
OPENGL_INIT_PROC(glFramebufferTextureFaceARB,  void, GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);

#define glProgramParameteriARB       OGL__glProgramParameteriARB
#define glFramebufferTextureARB      OGL__glFramebufferTextureARB
#define glFramebufferTextureLayerARB OGL__glFramebufferTextureLayerARB
#define glFramebufferTextureFaceARB  OGL__glFramebufferTextureFaceARB

#endif // GL_ARB_geometry_shader4

#endif // OPENGL_INCLUDE_GL_ARB_geometry_shader4

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_get_program_binary
#define GL_ARB_get_program_binary 1

#endif // GL_ARB_get_program_binary

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_get_texture_sub_image
#define GL_ARB_get_texture_sub_image 1

#endif // GL_ARB_get_texture_sub_image

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_gl_spirv

#ifndef GL_ARB_gl_spirv
#define GL_ARB_gl_spirv 1

#define GL_SHADER_BINARY_FORMAT_SPIR_V_ARB    0x9551
#define GL_SPIR_V_BINARY_ARB                  0x9552

OPENGL_INIT_PROC(glSpecializeShaderARB, void, GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue);
#define glSpecializeShaderARB OGL__glSpecializeShaderARB

#endif // GL_ARB_gl_spirv

#endif // OPENGL_INCLUDE_GL_ARB_gl_spirv

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_gpu_shader5
#define GL_ARB_gpu_shader5 1

#endif // GL_ARB_gpu_shader5

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_gpu_shader_fp64
#define GL_ARB_gpu_shader_fp64 1

#endif // GL_ARB_gpu_shader_fp64

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_gpu_shader_int64

#ifndef GL_ARB_gpu_shader_int64
#define GL_ARB_gpu_shader_int64 1

#define GL_INT64_ARB                  0x140E
#define GL_INT64_VEC2_ARB             0x8FE9
#define GL_INT64_VEC3_ARB             0x8FEA
#define GL_INT64_VEC4_ARB             0x8FEB
#define GL_UNSIGNED_INT64_VEC2_ARB    0x8FF5
#define GL_UNSIGNED_INT64_VEC3_ARB    0x8FF6
#define GL_UNSIGNED_INT64_VEC4_ARB    0x8FF7

OPENGL_INIT_PROC(glUniform1i64ARB,          void, GLint location, GLint64 x);
OPENGL_INIT_PROC(glUniform2i64ARB,          void, GLint location, GLint64 x, GLint64 y);
OPENGL_INIT_PROC(glUniform3i64ARB,          void, GLint location, GLint64 x, GLint64 y, GLint64 z);
OPENGL_INIT_PROC(glUniform4i64ARB,          void, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
OPENGL_INIT_PROC(glUniform1i64vARB,         void, GLint location, GLsizei count, const GLint64 *value);
OPENGL_INIT_PROC(glUniform2i64vARB,         void, GLint location, GLsizei count, const GLint64 *value);
OPENGL_INIT_PROC(glUniform3i64vARB,         void, GLint location, GLsizei count, const GLint64 *value);
OPENGL_INIT_PROC(glUniform4i64vARB,         void, GLint location, GLsizei count, const GLint64 *value);
OPENGL_INIT_PROC(glUniform1ui64ARB,         void, GLint location, GLuint64 x);
OPENGL_INIT_PROC(glUniform2ui64ARB,         void, GLint location, GLuint64 x, GLuint64 y);
OPENGL_INIT_PROC(glUniform3ui64ARB,         void, GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
OPENGL_INIT_PROC(glUniform4ui64ARB,         void, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
OPENGL_INIT_PROC(glUniform1ui64vARB,        void, GLint location, GLsizei count, const GLuint64 *value);
OPENGL_INIT_PROC(glUniform2ui64vARB,        void, GLint location, GLsizei count, const GLuint64 *value);
OPENGL_INIT_PROC(glUniform3ui64vARB,        void, GLint location, GLsizei count, const GLuint64 *value);
OPENGL_INIT_PROC(glUniform4ui64vARB,        void, GLint location, GLsizei count, const GLuint64 *value);
OPENGL_INIT_PROC(glGetUniformi64vARB,       void, GLuint program, GLint location, GLint64 *params);
OPENGL_INIT_PROC(glGetUniformui64vARB,      void, GLuint program, GLint location, GLuint64 *params);
OPENGL_INIT_PROC(glGetnUniformi64vARB,      void, GLuint program, GLint location, GLsizei bufSize, GLint64 *params);
OPENGL_INIT_PROC(glGetnUniformui64vARB,     void, GLuint program, GLint location, GLsizei bufSize, GLuint64 *params);
OPENGL_INIT_PROC(glProgramUniform1i64ARB,   void, GLuint program, GLint location, GLint64 x);
OPENGL_INIT_PROC(glProgramUniform2i64ARB,   void, GLuint program, GLint location, GLint64 x, GLint64 y);
OPENGL_INIT_PROC(glProgramUniform3i64ARB,   void, GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z);
OPENGL_INIT_PROC(glProgramUniform4i64ARB,   void, GLuint program, GLint location, GLint64 x, GLint64 y, GLint64 z, GLint64 w);
OPENGL_INIT_PROC(glProgramUniform1i64vARB,  void, GLuint program, GLint location, GLsizei count, const GLint64 *value);
OPENGL_INIT_PROC(glProgramUniform2i64vARB,  void, GLuint program, GLint location, GLsizei count, const GLint64 *value);
OPENGL_INIT_PROC(glProgramUniform3i64vARB,  void, GLuint program, GLint location, GLsizei count, const GLint64 *value);
OPENGL_INIT_PROC(glProgramUniform4i64vARB,  void, GLuint program, GLint location, GLsizei count, const GLint64 *value);
OPENGL_INIT_PROC(glProgramUniform1ui64ARB,  void, GLuint program, GLint location, GLuint64 x);
OPENGL_INIT_PROC(glProgramUniform2ui64ARB,  void, GLuint program, GLint location, GLuint64 x, GLuint64 y);
OPENGL_INIT_PROC(glProgramUniform3ui64ARB,  void, GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z);
OPENGL_INIT_PROC(glProgramUniform4ui64ARB,  void, GLuint program, GLint location, GLuint64 x, GLuint64 y, GLuint64 z, GLuint64 w);
OPENGL_INIT_PROC(glProgramUniform1ui64vARB, void, GLuint program, GLint location, GLsizei count, const GLuint64 *value);
OPENGL_INIT_PROC(glProgramUniform2ui64vARB, void, GLuint program, GLint location, GLsizei count, const GLuint64 *value);
OPENGL_INIT_PROC(glProgramUniform3ui64vARB, void, GLuint program, GLint location, GLsizei count, const GLuint64 *value);
OPENGL_INIT_PROC(glProgramUniform4ui64vARB, void, GLuint program, GLint location, GLsizei count, const GLuint64 *value);

#define glUniform1i64ARB          OGL__glUniform1i64ARB
#define glUniform2i64ARB          OGL__glUniform2i64ARB
#define glUniform3i64ARB          OGL__glUniform3i64ARB
#define glUniform4i64ARB          OGL__glUniform4i64ARB
#define glUniform1i64vARB         OGL__glUniform1i64vARB
#define glUniform2i64vARB         OGL__glUniform2i64vARB
#define glUniform3i64vARB         OGL__glUniform3i64vARB
#define glUniform4i64vARB         OGL__glUniform4i64vARB
#define glUniform1ui64ARB         OGL__glUniform1ui64ARB
#define glUniform2ui64ARB         OGL__glUniform2ui64ARB
#define glUniform3ui64ARB         OGL__glUniform3ui64ARB
#define glUniform4ui64ARB         OGL__glUniform4ui64ARB
#define glUniform1ui64vARB        OGL__glUniform1ui64vARB
#define glUniform2ui64vARB        OGL__glUniform2ui64vARB
#define glUniform3ui64vARB        OGL__glUniform3ui64vARB
#define glUniform4ui64vARB        OGL__glUniform4ui64vARB
#define glGetUniformi64vARB       OGL__glGetUniformi64vARB
#define glGetUniformui64vARB      OGL__glGetUniformui64vARB
#define glGetnUniformi64vARB      OGL__glGetnUniformi64vARB
#define glGetnUniformui64vARB     OGL__glGetnUniformui64vARB
#define glProgramUniform1i64ARB   OGL__glProgramUniform1i64ARB
#define glProgramUniform2i64ARB   OGL__glProgramUniform2i64ARB
#define glProgramUniform3i64ARB   OGL__glProgramUniform3i64ARB
#define glProgramUniform4i64ARB   OGL__glProgramUniform4i64ARB
#define glProgramUniform1i64vARB  OGL__glProgramUniform1i64vARB
#define glProgramUniform2i64vARB  OGL__glProgramUniform2i64vARB
#define glProgramUniform3i64vARB  OGL__glProgramUniform3i64vARB
#define glProgramUniform4i64vARB  OGL__glProgramUniform4i64vARB
#define glProgramUniform1ui64ARB  OGL__glProgramUniform1ui64ARB
#define glProgramUniform2ui64ARB  OGL__glProgramUniform2ui64ARB
#define glProgramUniform3ui64ARB  OGL__glProgramUniform3ui64ARB
#define glProgramUniform4ui64ARB  OGL__glProgramUniform4ui64ARB
#define glProgramUniform1ui64vARB OGL__glProgramUniform1ui64vARB
#define glProgramUniform2ui64vARB OGL__glProgramUniform2ui64vARB
#define glProgramUniform3ui64vARB OGL__glProgramUniform3ui64vARB
#define glProgramUniform4ui64vARB OGL__glProgramUniform4ui64vARB

#endif // GL_ARB_gpu_shader_int64

#endif // OPENGL_INCLUDE_GL_ARB_gpu_shader_int64

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_half_float_pixel
#define GL_ARB_half_float_pixel 1

#define GL_HALF_FLOAT_ARB    0x140B

#endif // GL_ARB_half_float_pixel

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_half_float_vertex
#define GL_ARB_half_float_vertex 1

#endif // GL_ARB_half_float_vertex

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_imaging

#ifndef GL_ARB_imaging
#define GL_ARB_imaging 1

#define GL_CONVOLUTION_1D                         0x8010
#define GL_CONVOLUTION_2D                         0x8011
#define GL_SEPARABLE_2D                           0x8012
#define GL_CONVOLUTION_BORDER_MODE                0x8013
#define GL_CONVOLUTION_FILTER_SCALE               0x8014
#define GL_CONVOLUTION_FILTER_BIAS                0x8015
#define GL_REDUCE                                 0x8016
#define GL_CONVOLUTION_FORMAT                     0x8017
#define GL_CONVOLUTION_WIDTH                      0x8018
#define GL_CONVOLUTION_HEIGHT                     0x8019
#define GL_MAX_CONVOLUTION_WIDTH                  0x801A
#define GL_MAX_CONVOLUTION_HEIGHT                 0x801B
#define GL_POST_CONVOLUTION_RED_SCALE             0x801C
#define GL_POST_CONVOLUTION_GREEN_SCALE           0x801D
#define GL_POST_CONVOLUTION_BLUE_SCALE            0x801E
#define GL_POST_CONVOLUTION_ALPHA_SCALE           0x801F
#define GL_POST_CONVOLUTION_RED_BIAS              0x8020
#define GL_POST_CONVOLUTION_GREEN_BIAS            0x8021
#define GL_POST_CONVOLUTION_BLUE_BIAS             0x8022
#define GL_POST_CONVOLUTION_ALPHA_BIAS            0x8023
#define GL_HISTOGRAM                              0x8024
#define GL_PROXY_HISTOGRAM                        0x8025
#define GL_HISTOGRAM_WIDTH                        0x8026
#define GL_HISTOGRAM_FORMAT                       0x8027
#define GL_HISTOGRAM_RED_SIZE                     0x8028
#define GL_HISTOGRAM_GREEN_SIZE                   0x8029
#define GL_HISTOGRAM_BLUE_SIZE                    0x802A
#define GL_HISTOGRAM_ALPHA_SIZE                   0x802B
#define GL_HISTOGRAM_LUMINANCE_SIZE               0x802C
#define GL_HISTOGRAM_SINK                         0x802D
#define GL_MINMAX                                 0x802E
#define GL_MINMAX_FORMAT                          0x802F
#define GL_MINMAX_SINK                            0x8030
#define GL_TABLE_TOO_LARGE                        0x8031
#define GL_COLOR_MATRIX                           0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH               0x80B2
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH           0x80B3
#define GL_POST_COLOR_MATRIX_RED_SCALE            0x80B4
#define GL_POST_COLOR_MATRIX_GREEN_SCALE          0x80B5
#define GL_POST_COLOR_MATRIX_BLUE_SCALE           0x80B6
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE          0x80B7
#define GL_POST_COLOR_MATRIX_RED_BIAS             0x80B8
#define GL_POST_COLOR_MATRIX_GREEN_BIAS           0x80B9
#define GL_POST_COLOR_MATRIX_BLUE_BIAS            0x80BA
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS           0x80BB
#define GL_COLOR_TABLE                            0x80D0
#define GL_POST_CONVOLUTION_COLOR_TABLE           0x80D1
#define GL_POST_COLOR_MATRIX_COLOR_TABLE          0x80D2
#define GL_PROXY_COLOR_TABLE                      0x80D3
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE     0x80D4
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE    0x80D5
#define GL_COLOR_TABLE_SCALE                      0x80D6
#define GL_COLOR_TABLE_BIAS                       0x80D7
#define GL_COLOR_TABLE_FORMAT                     0x80D8
#define GL_COLOR_TABLE_WIDTH                      0x80D9
#define GL_COLOR_TABLE_RED_SIZE                   0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE                 0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE                  0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE                 0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE             0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE             0x80DF
#define GL_CONSTANT_BORDER                        0x8151
#define GL_REPLICATE_BORDER                       0x8153
#define GL_CONVOLUTION_BORDER_COLOR               0x8154

OPENGL_INIT_PROC(glColorTable,                void, GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *table);
OPENGL_INIT_PROC(glColorTableParameterfv,     void, GLenum target, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glColorTableParameteriv,     void, GLenum target, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glCopyColorTable,            void, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
OPENGL_INIT_PROC(glGetColorTable,             void, GLenum target, GLenum format, GLenum type, void *table);
OPENGL_INIT_PROC(glGetColorTableParameterfv,  void, GLenum target, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetColorTableParameteriv,  void, GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glColorSubTable,             void, GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void *data);
OPENGL_INIT_PROC(glCopyColorSubTable,         void, GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);
OPENGL_INIT_PROC(glConvolutionFilter1D,       void, GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *image);
OPENGL_INIT_PROC(glConvolutionFilter2D,       void, GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *image);
OPENGL_INIT_PROC(glConvolutionParameterf,     void, GLenum target, GLenum pname, GLfloat params);
OPENGL_INIT_PROC(glConvolutionParameterfv,    void, GLenum target, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glConvolutionParameteri,     void, GLenum target, GLenum pname, GLint params);
OPENGL_INIT_PROC(glConvolutionParameteriv,    void, GLenum target, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glCopyConvolutionFilter1D,   void, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
OPENGL_INIT_PROC(glCopyConvolutionFilter2D,   void, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glGetConvolutionFilter,      void, GLenum target, GLenum format, GLenum type, void *image);
OPENGL_INIT_PROC(glGetConvolutionParameterfv, void, GLenum target, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetConvolutionParameteriv, void, GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetSeparableFilter,        void, GLenum target, GLenum format, GLenum type, void *row, void *column, void *span);
OPENGL_INIT_PROC(glSeparableFilter2D,         void, GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *row, const void *column);
OPENGL_INIT_PROC(glGetHistogram,              void, GLenum target, GLboolean reset, GLenum format, GLenum type, void *values);
OPENGL_INIT_PROC(glGetHistogramParameterfv,   void, GLenum target, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetHistogramParameteriv,   void, GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetMinmax,                 void, GLenum target, GLboolean reset, GLenum format, GLenum type, void *values);
OPENGL_INIT_PROC(glGetMinmaxParameterfv,      void, GLenum target, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetMinmaxParameteriv,      void, GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glHistogram,                 void, GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
OPENGL_INIT_PROC(glMinmax,                    void, GLenum target, GLenum internalformat, GLboolean sink);
OPENGL_INIT_PROC(glResetHistogram,            void, GLenum target);
OPENGL_INIT_PROC(glResetMinmax,               void, GLenum target);

#define glColorTable                OGL__glColorTable
#define glColorTableParameterfv     OGL__glColorTableParameterfv
#define glColorTableParameteriv     OGL__glColorTableParameteriv
#define glCopyColorTable            OGL__glCopyColorTable
#define glGetColorTable             OGL__glGetColorTable
#define glGetColorTableParameterfv  OGL__glGetColorTableParameterfv
#define glGetColorTableParameteriv  OGL__glGetColorTableParameteriv
#define glColorSubTable             OGL__glColorSubTable
#define glCopyColorSubTable         OGL__glCopyColorSubTable
#define glConvolutionFilter1D       OGL__glConvolutionFilter1D
#define glConvolutionFilter2D       OGL__glConvolutionFilter2D
#define glConvolutionParameterf     OGL__glConvolutionParameterf
#define glConvolutionParameterfv    OGL__glConvolutionParameterfv
#define glConvolutionParameteri     OGL__glConvolutionParameteri
#define glConvolutionParameteriv    OGL__glConvolutionParameteriv
#define glCopyConvolutionFilter1D   OGL__glCopyConvolutionFilter1D
#define glCopyConvolutionFilter2D   OGL__glCopyConvolutionFilter2D
#define glGetConvolutionFilter      OGL__glGetConvolutionFilter
#define glGetConvolutionParameterfv OGL__glGetConvolutionParameterfv
#define glGetConvolutionParameteriv OGL__glGetConvolutionParameteriv
#define glGetSeparableFilter        OGL__glGetSeparableFilter
#define glSeparableFilter2D         OGL__glSeparableFilter2D
#define glGetHistogram              OGL__glGetHistogram
#define glGetHistogramParameterfv   OGL__glGetHistogramParameterfv
#define glGetHistogramParameteriv   OGL__glGetHistogramParameteriv
#define glGetMinmax                 OGL__glGetMinmax
#define glGetMinmaxParameterfv      OGL__glGetMinmaxParameterfv
#define glGetMinmaxParameteriv      OGL__glGetMinmaxParameteriv
#define glHistogram                 OGL__glHistogram
#define glMinmax                    OGL__glMinmax
#define glResetHistogram            OGL__glResetHistogram
#define glResetMinmax               OGL__glResetMinmax

#endif // GL_ARB_imaging

#endif // OPENGL_INCLUDE_GL_ARB_imaging

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_indirect_parameters

#ifndef GL_ARB_indirect_parameters
#define GL_ARB_indirect_parameters 1

#define GL_PARAMETER_BUFFER_ARB            0x80EE
#define GL_PARAMETER_BUFFER_BINDING_ARB    0x80EF

OPENGL_INIT_PROC(glMultiDrawArraysIndirectCountARB,   void, GLenum mode, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
OPENGL_INIT_PROC(glMultiDrawElementsIndirectCountARB, void, GLenum mode, GLenum type, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);

#define glMultiDrawArraysIndirectCountARB   OGL__glMultiDrawArraysIndirectCountARB
#define glMultiDrawElementsIndirectCountARB OGL__glMultiDrawElementsIndirectCountARB

#endif // GL_ARB_indirect_parameters

#endif // OPENGL_INCLUDE_GL_ARB_indirect_parameters

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_instanced_arrays

#ifndef GL_ARB_instanced_arrays
#define GL_ARB_instanced_arrays 1

#define GL_VERTEX_ATTRIB_ARRAY_DIVISOR_ARB    0x88FE

OPENGL_INIT_PROC(glVertexAttribDivisorARB, void, GLuint index, GLuint divisor);
#define glVertexAttribDivisorARB OGL__glVertexAttribDivisorARB

#endif // GL_ARB_instanced_arrays

#endif // OPENGL_INCLUDE_GL_ARB_instanced_arrays

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_internalformat_query
#define GL_ARB_internalformat_query 1

#endif // GL_ARB_internalformat_query

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_internalformat_query2
#define GL_ARB_internalformat_query2 1

#define GL_SRGB_DECODE_ARB               0x8299
#define GL_VIEW_CLASS_EAC_R11            0x9383
#define GL_VIEW_CLASS_EAC_RG11           0x9384
#define GL_VIEW_CLASS_ETC2_RGB           0x9385
#define GL_VIEW_CLASS_ETC2_RGBA          0x9386
#define GL_VIEW_CLASS_ETC2_EAC_RGBA      0x9387
#define GL_VIEW_CLASS_ASTC_4x4_RGBA      0x9388
#define GL_VIEW_CLASS_ASTC_5x4_RGBA      0x9389
#define GL_VIEW_CLASS_ASTC_5x5_RGBA      0x938A
#define GL_VIEW_CLASS_ASTC_6x5_RGBA      0x938B
#define GL_VIEW_CLASS_ASTC_6x6_RGBA      0x938C
#define GL_VIEW_CLASS_ASTC_8x5_RGBA      0x938D
#define GL_VIEW_CLASS_ASTC_8x6_RGBA      0x938E
#define GL_VIEW_CLASS_ASTC_8x8_RGBA      0x938F
#define GL_VIEW_CLASS_ASTC_10x5_RGBA     0x9390
#define GL_VIEW_CLASS_ASTC_10x6_RGBA     0x9391
#define GL_VIEW_CLASS_ASTC_10x8_RGBA     0x9392
#define GL_VIEW_CLASS_ASTC_10x10_RGBA    0x9393
#define GL_VIEW_CLASS_ASTC_12x10_RGBA    0x9394
#define GL_VIEW_CLASS_ASTC_12x12_RGBA    0x9395

#endif // GL_ARB_internalformat_query2

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_invalidate_subdata
#define GL_ARB_invalidate_subdata 1

#endif // GL_ARB_invalidate_subdata

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_map_buffer_alignment
#define GL_ARB_map_buffer_alignment 1

#endif // GL_ARB_map_buffer_alignment

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_map_buffer_range
#define GL_ARB_map_buffer_range 1

#endif // GL_ARB_map_buffer_range

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_matrix_palette

#ifndef GL_ARB_matrix_palette
#define GL_ARB_matrix_palette 1

#define GL_MATRIX_PALETTE_ARB                    0x8840
#define GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB    0x8841
#define GL_MAX_PALETTE_MATRICES_ARB              0x8842
#define GL_CURRENT_PALETTE_MATRIX_ARB            0x8843
#define GL_MATRIX_INDEX_ARRAY_ARB                0x8844
#define GL_CURRENT_MATRIX_INDEX_ARB              0x8845
#define GL_MATRIX_INDEX_ARRAY_SIZE_ARB           0x8846
#define GL_MATRIX_INDEX_ARRAY_TYPE_ARB           0x8847
#define GL_MATRIX_INDEX_ARRAY_STRIDE_ARB         0x8848
#define GL_MATRIX_INDEX_ARRAY_POINTER_ARB        0x8849

OPENGL_INIT_PROC(glCurrentPaletteMatrixARB, void, GLint index);
OPENGL_INIT_PROC(glMatrixIndexubvARB,       void, GLint size, const GLubyte *indices);
OPENGL_INIT_PROC(glMatrixIndexusvARB,       void, GLint size, const GLushort *indices);
OPENGL_INIT_PROC(glMatrixIndexuivARB,       void, GLint size, const GLuint *indices);
OPENGL_INIT_PROC(glMatrixIndexPointerARB,   void, GLint size, GLenum type, GLsizei stride, const void *pointer);

#define glCurrentPaletteMatrixARB OGL__glCurrentPaletteMatrixARB
#define glMatrixIndexubvARB       OGL__glMatrixIndexubvARB
#define glMatrixIndexusvARB       OGL__glMatrixIndexusvARB
#define glMatrixIndexuivARB       OGL__glMatrixIndexuivARB
#define glMatrixIndexPointerARB   OGL__glMatrixIndexPointerARB

#endif // GL_ARB_matrix_palette

#endif // OPENGL_INCLUDE_GL_ARB_matrix_palette

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_multi_bind
#define GL_ARB_multi_bind 1

#endif // GL_ARB_multi_bind

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_multi_draw_indirect
#define GL_ARB_multi_draw_indirect 1

#endif // GL_ARB_multi_draw_indirect

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_multisample

#ifndef GL_ARB_multisample
#define GL_ARB_multisample 1

#define GL_MULTISAMPLE_ARB                 0x809D
#define GL_SAMPLE_ALPHA_TO_COVERAGE_ARB    0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_ARB         0x809F
#define GL_SAMPLE_COVERAGE_ARB             0x80A0
#define GL_SAMPLE_BUFFERS_ARB              0x80A8
#define GL_SAMPLES_ARB                     0x80A9
#define GL_SAMPLE_COVERAGE_VALUE_ARB       0x80AA
#define GL_SAMPLE_COVERAGE_INVERT_ARB      0x80AB
#define GL_MULTISAMPLE_BIT_ARB             0x20000000

OPENGL_INIT_PROC(glSampleCoverageARB, void, GLfloat value, GLboolean invert);
#define glSampleCoverageARB OGL__glSampleCoverageARB

#endif // GL_ARB_multisample

#endif // OPENGL_INCLUDE_GL_ARB_multisample

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_multitexture

#ifndef GL_ARB_multitexture
#define GL_ARB_multitexture 1

#define GL_TEXTURE0_ARB                 0x84C0
#define GL_TEXTURE1_ARB                 0x84C1
#define GL_TEXTURE2_ARB                 0x84C2
#define GL_TEXTURE3_ARB                 0x84C3
#define GL_TEXTURE4_ARB                 0x84C4
#define GL_TEXTURE5_ARB                 0x84C5
#define GL_TEXTURE6_ARB                 0x84C6
#define GL_TEXTURE7_ARB                 0x84C7
#define GL_TEXTURE8_ARB                 0x84C8
#define GL_TEXTURE9_ARB                 0x84C9
#define GL_TEXTURE10_ARB                0x84CA
#define GL_TEXTURE11_ARB                0x84CB
#define GL_TEXTURE12_ARB                0x84CC
#define GL_TEXTURE13_ARB                0x84CD
#define GL_TEXTURE14_ARB                0x84CE
#define GL_TEXTURE15_ARB                0x84CF
#define GL_TEXTURE16_ARB                0x84D0
#define GL_TEXTURE17_ARB                0x84D1
#define GL_TEXTURE18_ARB                0x84D2
#define GL_TEXTURE19_ARB                0x84D3
#define GL_TEXTURE20_ARB                0x84D4
#define GL_TEXTURE21_ARB                0x84D5
#define GL_TEXTURE22_ARB                0x84D6
#define GL_TEXTURE23_ARB                0x84D7
#define GL_TEXTURE24_ARB                0x84D8
#define GL_TEXTURE25_ARB                0x84D9
#define GL_TEXTURE26_ARB                0x84DA
#define GL_TEXTURE27_ARB                0x84DB
#define GL_TEXTURE28_ARB                0x84DC
#define GL_TEXTURE29_ARB                0x84DD
#define GL_TEXTURE30_ARB                0x84DE
#define GL_TEXTURE31_ARB                0x84DF
#define GL_ACTIVE_TEXTURE_ARB           0x84E0
#define GL_CLIENT_ACTIVE_TEXTURE_ARB    0x84E1
#define GL_MAX_TEXTURE_UNITS_ARB        0x84E2

OPENGL_INIT_PROC(glActiveTextureARB,       void, GLenum texture);
OPENGL_INIT_PROC(glClientActiveTextureARB, void, GLenum texture);
OPENGL_INIT_PROC(glMultiTexCoord1dARB,     void, GLenum target, GLdouble s);
OPENGL_INIT_PROC(glMultiTexCoord1dvARB,    void, GLenum target, const GLdouble *v);
OPENGL_INIT_PROC(glMultiTexCoord1fARB,     void, GLenum target, GLfloat s);
OPENGL_INIT_PROC(glMultiTexCoord1fvARB,    void, GLenum target, const GLfloat *v);
OPENGL_INIT_PROC(glMultiTexCoord1iARB,     void, GLenum target, GLint s);
OPENGL_INIT_PROC(glMultiTexCoord1ivARB,    void, GLenum target, const GLint *v);
OPENGL_INIT_PROC(glMultiTexCoord1sARB,     void, GLenum target, GLshort s);
OPENGL_INIT_PROC(glMultiTexCoord1svARB,    void, GLenum target, const GLshort *v);
OPENGL_INIT_PROC(glMultiTexCoord2dARB,     void, GLenum target, GLdouble s, GLdouble t);
OPENGL_INIT_PROC(glMultiTexCoord2dvARB,    void, GLenum target, const GLdouble *v);
OPENGL_INIT_PROC(glMultiTexCoord2fARB,     void, GLenum target, GLfloat s, GLfloat t);
OPENGL_INIT_PROC(glMultiTexCoord2fvARB,    void, GLenum target, const GLfloat *v);
OPENGL_INIT_PROC(glMultiTexCoord2iARB,     void, GLenum target, GLint s, GLint t);
OPENGL_INIT_PROC(glMultiTexCoord2ivARB,    void, GLenum target, const GLint *v);
OPENGL_INIT_PROC(glMultiTexCoord2sARB,     void, GLenum target, GLshort s, GLshort t);
OPENGL_INIT_PROC(glMultiTexCoord2svARB,    void, GLenum target, const GLshort *v);
OPENGL_INIT_PROC(glMultiTexCoord3dARB,     void, GLenum target, GLdouble s, GLdouble t, GLdouble r);
OPENGL_INIT_PROC(glMultiTexCoord3dvARB,    void, GLenum target, const GLdouble *v);
OPENGL_INIT_PROC(glMultiTexCoord3fARB,     void, GLenum target, GLfloat s, GLfloat t, GLfloat r);
OPENGL_INIT_PROC(glMultiTexCoord3fvARB,    void, GLenum target, const GLfloat *v);
OPENGL_INIT_PROC(glMultiTexCoord3iARB,     void, GLenum target, GLint s, GLint t, GLint r);
OPENGL_INIT_PROC(glMultiTexCoord3ivARB,    void, GLenum target, const GLint *v);
OPENGL_INIT_PROC(glMultiTexCoord3sARB,     void, GLenum target, GLshort s, GLshort t, GLshort r);
OPENGL_INIT_PROC(glMultiTexCoord3svARB,    void, GLenum target, const GLshort *v);
OPENGL_INIT_PROC(glMultiTexCoord4dARB,     void, GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
OPENGL_INIT_PROC(glMultiTexCoord4dvARB,    void, GLenum target, const GLdouble *v);
OPENGL_INIT_PROC(glMultiTexCoord4fARB,     void, GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
OPENGL_INIT_PROC(glMultiTexCoord4fvARB,    void, GLenum target, const GLfloat *v);
OPENGL_INIT_PROC(glMultiTexCoord4iARB,     void, GLenum target, GLint s, GLint t, GLint r, GLint q);
OPENGL_INIT_PROC(glMultiTexCoord4ivARB,    void, GLenum target, const GLint *v);
OPENGL_INIT_PROC(glMultiTexCoord4sARB,     void, GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
OPENGL_INIT_PROC(glMultiTexCoord4svARB,    void, GLenum target, const GLshort *v);

#define glActiveTextureARB       OGL__glActiveTextureARB
#define glClientActiveTextureARB OGL__glClientActiveTextureARB
#define glMultiTexCoord1dARB     OGL__glMultiTexCoord1dARB
#define glMultiTexCoord1dvARB    OGL__glMultiTexCoord1dvARB
#define glMultiTexCoord1fARB     OGL__glMultiTexCoord1fARB
#define glMultiTexCoord1fvARB    OGL__glMultiTexCoord1fvARB
#define glMultiTexCoord1iARB     OGL__glMultiTexCoord1iARB
#define glMultiTexCoord1ivARB    OGL__glMultiTexCoord1ivARB
#define glMultiTexCoord1sARB     OGL__glMultiTexCoord1sARB
#define glMultiTexCoord1svARB    OGL__glMultiTexCoord1svARB
#define glMultiTexCoord2dARB     OGL__glMultiTexCoord2dARB
#define glMultiTexCoord2dvARB    OGL__glMultiTexCoord2dvARB
#define glMultiTexCoord2fARB     OGL__glMultiTexCoord2fARB
#define glMultiTexCoord2fvARB    OGL__glMultiTexCoord2fvARB
#define glMultiTexCoord2iARB     OGL__glMultiTexCoord2iARB
#define glMultiTexCoord2ivARB    OGL__glMultiTexCoord2ivARB
#define glMultiTexCoord2sARB     OGL__glMultiTexCoord2sARB
#define glMultiTexCoord2svARB    OGL__glMultiTexCoord2svARB
#define glMultiTexCoord3dARB     OGL__glMultiTexCoord3dARB
#define glMultiTexCoord3dvARB    OGL__glMultiTexCoord3dvARB
#define glMultiTexCoord3fARB     OGL__glMultiTexCoord3fARB
#define glMultiTexCoord3fvARB    OGL__glMultiTexCoord3fvARB
#define glMultiTexCoord3iARB     OGL__glMultiTexCoord3iARB
#define glMultiTexCoord3ivARB    OGL__glMultiTexCoord3ivARB
#define glMultiTexCoord3sARB     OGL__glMultiTexCoord3sARB
#define glMultiTexCoord3svARB    OGL__glMultiTexCoord3svARB
#define glMultiTexCoord4dARB     OGL__glMultiTexCoord4dARB
#define glMultiTexCoord4dvARB    OGL__glMultiTexCoord4dvARB
#define glMultiTexCoord4fARB     OGL__glMultiTexCoord4fARB
#define glMultiTexCoord4fvARB    OGL__glMultiTexCoord4fvARB
#define glMultiTexCoord4iARB     OGL__glMultiTexCoord4iARB
#define glMultiTexCoord4ivARB    OGL__glMultiTexCoord4ivARB
#define glMultiTexCoord4sARB     OGL__glMultiTexCoord4sARB
#define glMultiTexCoord4svARB    OGL__glMultiTexCoord4svARB

#endif // GL_ARB_multitexture

#endif // OPENGL_INCLUDE_GL_ARB_multitexture

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_occlusion_query

#ifndef GL_ARB_occlusion_query
#define GL_ARB_occlusion_query 1

#define GL_QUERY_COUNTER_BITS_ARB        0x8864
#define GL_CURRENT_QUERY_ARB             0x8865
#define GL_QUERY_RESULT_ARB              0x8866
#define GL_QUERY_RESULT_AVAILABLE_ARB    0x8867
#define GL_SAMPLES_PASSED_ARB            0x8914

OPENGL_INIT_PROC(glGenQueriesARB,        void,      GLsizei n, GLuint *ids);
OPENGL_INIT_PROC(glDeleteQueriesARB,     void,      GLsizei n, const GLuint *ids);
OPENGL_INIT_PROC(glIsQueryARB,           GLboolean, GLuint id);
OPENGL_INIT_PROC(glBeginQueryARB,        void,      GLenum target, GLuint id);
OPENGL_INIT_PROC(glEndQueryARB,          void,      GLenum target);
OPENGL_INIT_PROC(glGetQueryivARB,        void,      GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetQueryObjectivARB,  void,      GLuint id, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetQueryObjectuivARB, void,      GLuint id, GLenum pname, GLuint *params);

#define glGenQueriesARB        OGL__glGenQueriesARB
#define glDeleteQueriesARB     OGL__glDeleteQueriesARB
#define glIsQueryARB           OGL__glIsQueryARB
#define glBeginQueryARB        OGL__glBeginQueryARB
#define glEndQueryARB          OGL__glEndQueryARB
#define glGetQueryivARB        OGL__glGetQueryivARB
#define glGetQueryObjectivARB  OGL__glGetQueryObjectivARB
#define glGetQueryObjectuivARB OGL__glGetQueryObjectuivARB

#endif // GL_ARB_occlusion_query

#endif // OPENGL_INCLUDE_GL_ARB_occlusion_query

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_occlusion_query2
#define GL_ARB_occlusion_query2 1

#endif // GL_ARB_occlusion_query2

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_parallel_shader_compile

#ifndef GL_ARB_parallel_shader_compile
#define GL_ARB_parallel_shader_compile 1

#define GL_MAX_SHADER_COMPILER_THREADS_ARB    0x91B0
#define GL_COMPLETION_STATUS_ARB              0x91B1

OPENGL_INIT_PROC(glMaxShaderCompilerThreadsARB, void, GLuint count);
#define glMaxShaderCompilerThreadsARB OGL__glMaxShaderCompilerThreadsARB

#endif // GL_ARB_parallel_shader_compile

#endif // OPENGL_INCLUDE_GL_ARB_parallel_shader_compile

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_pipeline_statistics_query
#define GL_ARB_pipeline_statistics_query 1

#define GL_VERTICES_SUBMITTED_ARB                    0x82EE
#define GL_PRIMITIVES_SUBMITTED_ARB                  0x82EF
#define GL_VERTEX_SHADER_INVOCATIONS_ARB             0x82F0
#define GL_TESS_CONTROL_SHADER_PATCHES_ARB           0x82F1
#define GL_TESS_EVALUATION_SHADER_INVOCATIONS_ARB    0x82F2
#define GL_GEOMETRY_SHADER_PRIMITIVES_EMITTED_ARB    0x82F3
#define GL_FRAGMENT_SHADER_INVOCATIONS_ARB           0x82F4
#define GL_COMPUTE_SHADER_INVOCATIONS_ARB            0x82F5
#define GL_CLIPPING_INPUT_PRIMITIVES_ARB             0x82F6
#define GL_CLIPPING_OUTPUT_PRIMITIVES_ARB            0x82F7

#endif // GL_ARB_pipeline_statistics_query

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_pixel_buffer_object
#define GL_ARB_pixel_buffer_object 1

#define GL_PIXEL_PACK_BUFFER_ARB              0x88EB
#define GL_PIXEL_UNPACK_BUFFER_ARB            0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_ARB      0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_ARB    0x88EF

#endif // GL_ARB_pixel_buffer_object

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_point_parameters

#ifndef GL_ARB_point_parameters
#define GL_ARB_point_parameters 1

#define GL_POINT_SIZE_MIN_ARB                0x8126
#define GL_POINT_SIZE_MAX_ARB                0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_ARB     0x8128
#define GL_POINT_DISTANCE_ATTENUATION_ARB    0x8129

OPENGL_INIT_PROC(glPointParameterfARB,  void, GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glPointParameterfvARB, void, GLenum pname, const GLfloat *params);

#define glPointParameterfARB  OGL__glPointParameterfARB
#define glPointParameterfvARB OGL__glPointParameterfvARB

#endif // GL_ARB_point_parameters

#endif // OPENGL_INCLUDE_GL_ARB_point_parameters

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_point_sprite
#define GL_ARB_point_sprite 1

#define GL_POINT_SPRITE_ARB     0x8861
#define GL_COORD_REPLACE_ARB    0x8862

#endif // GL_ARB_point_sprite

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_polygon_offset_clamp
#define GL_ARB_polygon_offset_clamp 1

#endif // GL_ARB_polygon_offset_clamp

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_post_depth_coverage
#define GL_ARB_post_depth_coverage 1

#endif // GL_ARB_post_depth_coverage

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_program_interface_query
#define GL_ARB_program_interface_query 1

#endif // GL_ARB_program_interface_query

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_provoking_vertex
#define GL_ARB_provoking_vertex 1

#endif // GL_ARB_provoking_vertex

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_query_buffer_object
#define GL_ARB_query_buffer_object 1

#endif // GL_ARB_query_buffer_object

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_robust_buffer_access_behavior
#define GL_ARB_robust_buffer_access_behavior 1

#endif // GL_ARB_robust_buffer_access_behavior

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_robustness

#ifndef GL_ARB_robustness
#define GL_ARB_robustness 1

#define GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT_ARB    0x00000004
#define GL_LOSE_CONTEXT_ON_RESET_ARB             0x8252
#define GL_GUILTY_CONTEXT_RESET_ARB              0x8253
#define GL_INNOCENT_CONTEXT_RESET_ARB            0x8254
#define GL_UNKNOWN_CONTEXT_RESET_ARB             0x8255
#define GL_RESET_NOTIFICATION_STRATEGY_ARB       0x8256
#define GL_NO_RESET_NOTIFICATION_ARB             0x8261

OPENGL_INIT_PROC(glGetGraphicsResetStatusARB, GLenum, void);
OPENGL_INIT_PROC(glGetnTexImageARB,           void,   GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *img);
OPENGL_INIT_PROC(glReadnPixelsARB,            void,   GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
OPENGL_INIT_PROC(glGetnCompressedTexImageARB, void,   GLenum target, GLint lod, GLsizei bufSize, void *img);
OPENGL_INIT_PROC(glGetnUniformfvARB,          void,   GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
OPENGL_INIT_PROC(glGetnUniformivARB,          void,   GLuint program, GLint location, GLsizei bufSize, GLint *params);
OPENGL_INIT_PROC(glGetnUniformuivARB,         void,   GLuint program, GLint location, GLsizei bufSize, GLuint *params);
OPENGL_INIT_PROC(glGetnUniformdvARB,          void,   GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
OPENGL_INIT_PROC(glGetnMapdvARB,              void,   GLenum target, GLenum query, GLsizei bufSize, GLdouble *v);
OPENGL_INIT_PROC(glGetnMapfvARB,              void,   GLenum target, GLenum query, GLsizei bufSize, GLfloat *v);
OPENGL_INIT_PROC(glGetnMapivARB,              void,   GLenum target, GLenum query, GLsizei bufSize, GLint *v);
OPENGL_INIT_PROC(glGetnPixelMapfvARB,         void,   GLenum map, GLsizei bufSize, GLfloat *values);
OPENGL_INIT_PROC(glGetnPixelMapuivARB,        void,   GLenum map, GLsizei bufSize, GLuint *values);
OPENGL_INIT_PROC(glGetnPixelMapusvARB,        void,   GLenum map, GLsizei bufSize, GLushort *values);
OPENGL_INIT_PROC(glGetnPolygonStippleARB,     void,   GLsizei bufSize, GLubyte *pattern);
OPENGL_INIT_PROC(glGetnColorTableARB,         void,   GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *table);
OPENGL_INIT_PROC(glGetnConvolutionFilterARB,  void,   GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *image);
OPENGL_INIT_PROC(glGetnSeparableFilterARB,    void,   GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void *row, GLsizei columnBufSize, void *column, void *span);
OPENGL_INIT_PROC(glGetnHistogramARB,          void,   GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);
OPENGL_INIT_PROC(glGetnMinmaxARB,             void,   GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);

#define glGetGraphicsResetStatusARB OGL__glGetGraphicsResetStatusARB
#define glGetnTexImageARB           OGL__glGetnTexImageARB
#define glReadnPixelsARB            OGL__glReadnPixelsARB
#define glGetnCompressedTexImageARB OGL__glGetnCompressedTexImageARB
#define glGetnUniformfvARB          OGL__glGetnUniformfvARB
#define glGetnUniformivARB          OGL__glGetnUniformivARB
#define glGetnUniformuivARB         OGL__glGetnUniformuivARB
#define glGetnUniformdvARB          OGL__glGetnUniformdvARB
#define glGetnMapdvARB              OGL__glGetnMapdvARB
#define glGetnMapfvARB              OGL__glGetnMapfvARB
#define glGetnMapivARB              OGL__glGetnMapivARB
#define glGetnPixelMapfvARB         OGL__glGetnPixelMapfvARB
#define glGetnPixelMapuivARB        OGL__glGetnPixelMapuivARB
#define glGetnPixelMapusvARB        OGL__glGetnPixelMapusvARB
#define glGetnPolygonStippleARB     OGL__glGetnPolygonStippleARB
#define glGetnColorTableARB         OGL__glGetnColorTableARB
#define glGetnConvolutionFilterARB  OGL__glGetnConvolutionFilterARB
#define glGetnSeparableFilterARB    OGL__glGetnSeparableFilterARB
#define glGetnHistogramARB          OGL__glGetnHistogramARB
#define glGetnMinmaxARB             OGL__glGetnMinmaxARB

#endif // GL_ARB_robustness

#endif // OPENGL_INCLUDE_GL_ARB_robustness

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_robustness_isolation
#define GL_ARB_robustness_isolation 1

#endif // GL_ARB_robustness_isolation

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_sample_locations

#ifndef GL_ARB_sample_locations
#define GL_ARB_sample_locations 1

#define GL_SAMPLE_LOCATION_SUBPIXEL_BITS_ARB                0x933D
#define GL_SAMPLE_LOCATION_PIXEL_GRID_WIDTH_ARB             0x933E
#define GL_SAMPLE_LOCATION_PIXEL_GRID_HEIGHT_ARB            0x933F
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_TABLE_SIZE_ARB      0x9340
#define GL_SAMPLE_LOCATION_ARB                              0x8E50
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_ARB                 0x9341
#define GL_FRAMEBUFFER_PROGRAMMABLE_SAMPLE_LOCATIONS_ARB    0x9342
#define GL_FRAMEBUFFER_SAMPLE_LOCATION_PIXEL_GRID_ARB       0x9343

OPENGL_INIT_PROC(glFramebufferSampleLocationsfvARB,      void, GLenum target, GLuint start, GLsizei count, const GLfloat *v);
OPENGL_INIT_PROC(glNamedFramebufferSampleLocationsfvARB, void, GLuint framebuffer, GLuint start, GLsizei count, const GLfloat *v);
OPENGL_INIT_PROC(glEvaluateDepthValuesARB,               void, void);

#define glFramebufferSampleLocationsfvARB      OGL__glFramebufferSampleLocationsfvARB
#define glNamedFramebufferSampleLocationsfvARB OGL__glNamedFramebufferSampleLocationsfvARB
#define glEvaluateDepthValuesARB               OGL__glEvaluateDepthValuesARB

#endif // GL_ARB_sample_locations

#endif // OPENGL_INCLUDE_GL_ARB_sample_locations

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_sample_shading

#ifndef GL_ARB_sample_shading
#define GL_ARB_sample_shading 1

#define GL_SAMPLE_SHADING_ARB              0x8C36
#define GL_MIN_SAMPLE_SHADING_VALUE_ARB    0x8C37

OPENGL_INIT_PROC(glMinSampleShadingARB, void, GLfloat value);
#define glMinSampleShadingARB OGL__glMinSampleShadingARB

#endif // GL_ARB_sample_shading

#endif // OPENGL_INCLUDE_GL_ARB_sample_shading

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_sampler_objects
#define GL_ARB_sampler_objects 1

#endif // GL_ARB_sampler_objects

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_seamless_cube_map
#define GL_ARB_seamless_cube_map 1

#endif // GL_ARB_seamless_cube_map

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_seamless_cubemap_per_texture
#define GL_ARB_seamless_cubemap_per_texture 1

#endif // GL_ARB_seamless_cubemap_per_texture

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_separate_shader_objects
#define GL_ARB_separate_shader_objects 1

#endif // GL_ARB_separate_shader_objects

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_shader_atomic_counter_ops
#define GL_ARB_shader_atomic_counter_ops 1

#endif // GL_ARB_shader_atomic_counter_ops

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_shader_atomic_counters
#define GL_ARB_shader_atomic_counters 1

#endif // GL_ARB_shader_atomic_counters

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_shader_ballot
#define GL_ARB_shader_ballot 1

#endif // GL_ARB_shader_ballot

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_shader_bit_encoding
#define GL_ARB_shader_bit_encoding 1

#endif // GL_ARB_shader_bit_encoding

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_shader_clock
#define GL_ARB_shader_clock 1

#endif // GL_ARB_shader_clock

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_shader_draw_parameters
#define GL_ARB_shader_draw_parameters 1

#endif // GL_ARB_shader_draw_parameters

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_shader_group_vote
#define GL_ARB_shader_group_vote 1

#endif // GL_ARB_shader_group_vote

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_shader_image_load_store
#define GL_ARB_shader_image_load_store 1

#endif // GL_ARB_shader_image_load_store

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_shader_image_size
#define GL_ARB_shader_image_size 1

#endif // GL_ARB_shader_image_size

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_shader_objects

#ifndef GL_ARB_shader_objects
#define GL_ARB_shader_objects 1

#define GL_PROGRAM_OBJECT_ARB                      0x8B40
#define GL_SHADER_OBJECT_ARB                       0x8B48
#define GL_OBJECT_TYPE_ARB                         0x8B4E
#define GL_OBJECT_SUBTYPE_ARB                      0x8B4F
#define GL_FLOAT_VEC2_ARB                          0x8B50
#define GL_FLOAT_VEC3_ARB                          0x8B51
#define GL_FLOAT_VEC4_ARB                          0x8B52
#define GL_INT_VEC2_ARB                            0x8B53
#define GL_INT_VEC3_ARB                            0x8B54
#define GL_INT_VEC4_ARB                            0x8B55
#define GL_BOOL_ARB                                0x8B56
#define GL_BOOL_VEC2_ARB                           0x8B57
#define GL_BOOL_VEC3_ARB                           0x8B58
#define GL_BOOL_VEC4_ARB                           0x8B59
#define GL_FLOAT_MAT2_ARB                          0x8B5A
#define GL_FLOAT_MAT3_ARB                          0x8B5B
#define GL_FLOAT_MAT4_ARB                          0x8B5C
#define GL_SAMPLER_1D_ARB                          0x8B5D
#define GL_SAMPLER_2D_ARB                          0x8B5E
#define GL_SAMPLER_3D_ARB                          0x8B5F
#define GL_SAMPLER_CUBE_ARB                        0x8B60
#define GL_SAMPLER_1D_SHADOW_ARB                   0x8B61
#define GL_SAMPLER_2D_SHADOW_ARB                   0x8B62
#define GL_SAMPLER_2D_RECT_ARB                     0x8B63
#define GL_SAMPLER_2D_RECT_SHADOW_ARB              0x8B64
#define GL_OBJECT_DELETE_STATUS_ARB                0x8B80
#define GL_OBJECT_COMPILE_STATUS_ARB               0x8B81
#define GL_OBJECT_LINK_STATUS_ARB                  0x8B82
#define GL_OBJECT_VALIDATE_STATUS_ARB              0x8B83
#define GL_OBJECT_INFO_LOG_LENGTH_ARB              0x8B84
#define GL_OBJECT_ATTACHED_OBJECTS_ARB             0x8B85
#define GL_OBJECT_ACTIVE_UNIFORMS_ARB              0x8B86
#define GL_OBJECT_ACTIVE_UNIFORM_MAX_LENGTH_ARB    0x8B87
#define GL_OBJECT_SHADER_SOURCE_LENGTH_ARB         0x8B88

OPENGL_INIT_PROC(glDeleteObjectARB,         void,        GLhandleARB obj);
OPENGL_INIT_PROC(glGetHandleARB,            GLhandleARB, GLenum pname);
OPENGL_INIT_PROC(glDetachObjectARB,         void,        GLhandleARB containerObj, GLhandleARB attachedObj);
OPENGL_INIT_PROC(glCreateShaderObjectARB,   GLhandleARB, GLenum shaderType);
OPENGL_INIT_PROC(glShaderSourceARB,         void,        GLhandleARB shaderObj, GLsizei count, const GLcharARB **string, const GLint *length);
OPENGL_INIT_PROC(glCompileShaderARB,        void,        GLhandleARB shaderObj);
OPENGL_INIT_PROC(glCreateProgramObjectARB,  GLhandleARB, void);
OPENGL_INIT_PROC(glAttachObjectARB,         void,        GLhandleARB containerObj, GLhandleARB obj);
OPENGL_INIT_PROC(glLinkProgramARB,          void,        GLhandleARB programObj);
OPENGL_INIT_PROC(glUseProgramObjectARB,     void,        GLhandleARB programObj);
OPENGL_INIT_PROC(glValidateProgramARB,      void,        GLhandleARB programObj);
OPENGL_INIT_PROC(glUniform1fARB,            void,        GLint location, GLfloat v0);
OPENGL_INIT_PROC(glUniform2fARB,            void,        GLint location, GLfloat v0, GLfloat v1);
OPENGL_INIT_PROC(glUniform3fARB,            void,        GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
OPENGL_INIT_PROC(glUniform4fARB,            void,        GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
OPENGL_INIT_PROC(glUniform1iARB,            void,        GLint location, GLint v0);
OPENGL_INIT_PROC(glUniform2iARB,            void,        GLint location, GLint v0, GLint v1);
OPENGL_INIT_PROC(glUniform3iARB,            void,        GLint location, GLint v0, GLint v1, GLint v2);
OPENGL_INIT_PROC(glUniform4iARB,            void,        GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
OPENGL_INIT_PROC(glUniform1fvARB,           void,        GLint location, GLsizei count, const GLfloat *value);
OPENGL_INIT_PROC(glUniform2fvARB,           void,        GLint location, GLsizei count, const GLfloat *value);
OPENGL_INIT_PROC(glUniform3fvARB,           void,        GLint location, GLsizei count, const GLfloat *value);
OPENGL_INIT_PROC(glUniform4fvARB,           void,        GLint location, GLsizei count, const GLfloat *value);
OPENGL_INIT_PROC(glUniform1ivARB,           void,        GLint location, GLsizei count, const GLint *value);
OPENGL_INIT_PROC(glUniform2ivARB,           void,        GLint location, GLsizei count, const GLint *value);
OPENGL_INIT_PROC(glUniform3ivARB,           void,        GLint location, GLsizei count, const GLint *value);
OPENGL_INIT_PROC(glUniform4ivARB,           void,        GLint location, GLsizei count, const GLint *value);
OPENGL_INIT_PROC(glUniformMatrix2fvARB,     void,        GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glUniformMatrix3fvARB,     void,        GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glUniformMatrix4fvARB,     void,        GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glGetObjectParameterfvARB, void,        GLhandleARB obj, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetObjectParameterivARB, void,        GLhandleARB obj, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetInfoLogARB,           void,        GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *infoLog);
OPENGL_INIT_PROC(glGetAttachedObjectsARB,   void,        GLhandleARB containerObj, GLsizei maxCount, GLsizei *count, GLhandleARB *obj);
OPENGL_INIT_PROC(glGetUniformLocationARB,   GLint,       GLhandleARB programObj, const GLcharARB *name);
OPENGL_INIT_PROC(glGetActiveUniformARB,     void,        GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name);
OPENGL_INIT_PROC(glGetUniformfvARB,         void,        GLhandleARB programObj, GLint location, GLfloat *params);
OPENGL_INIT_PROC(glGetUniformivARB,         void,        GLhandleARB programObj, GLint location, GLint *params);
OPENGL_INIT_PROC(glGetShaderSourceARB,      void,        GLhandleARB obj, GLsizei maxLength, GLsizei *length, GLcharARB *source);

#define glDeleteObjectARB         OGL__glDeleteObjectARB
#define glGetHandleARB            OGL__glGetHandleARB
#define glDetachObjectARB         OGL__glDetachObjectARB
#define glCreateShaderObjectARB   OGL__glCreateShaderObjectARB
#define glShaderSourceARB         OGL__glShaderSourceARB
#define glCompileShaderARB        OGL__glCompileShaderARB
#define glCreateProgramObjectARB  OGL__glCreateProgramObjectARB
#define glAttachObjectARB         OGL__glAttachObjectARB
#define glLinkProgramARB          OGL__glLinkProgramARB
#define glUseProgramObjectARB     OGL__glUseProgramObjectARB
#define glValidateProgramARB      OGL__glValidateProgramARB
#define glUniform1fARB            OGL__glUniform1fARB
#define glUniform2fARB            OGL__glUniform2fARB
#define glUniform3fARB            OGL__glUniform3fARB
#define glUniform4fARB            OGL__glUniform4fARB
#define glUniform1iARB            OGL__glUniform1iARB
#define glUniform2iARB            OGL__glUniform2iARB
#define glUniform3iARB            OGL__glUniform3iARB
#define glUniform4iARB            OGL__glUniform4iARB
#define glUniform1fvARB           OGL__glUniform1fvARB
#define glUniform2fvARB           OGL__glUniform2fvARB
#define glUniform3fvARB           OGL__glUniform3fvARB
#define glUniform4fvARB           OGL__glUniform4fvARB
#define glUniform1ivARB           OGL__glUniform1ivARB
#define glUniform2ivARB           OGL__glUniform2ivARB
#define glUniform3ivARB           OGL__glUniform3ivARB
#define glUniform4ivARB           OGL__glUniform4ivARB
#define glUniformMatrix2fvARB     OGL__glUniformMatrix2fvARB
#define glUniformMatrix3fvARB     OGL__glUniformMatrix3fvARB
#define glUniformMatrix4fvARB     OGL__glUniformMatrix4fvARB
#define glGetObjectParameterfvARB OGL__glGetObjectParameterfvARB
#define glGetObjectParameterivARB OGL__glGetObjectParameterivARB
#define glGetInfoLogARB           OGL__glGetInfoLogARB
#define glGetAttachedObjectsARB   OGL__glGetAttachedObjectsARB
#define glGetUniformLocationARB   OGL__glGetUniformLocationARB
#define glGetActiveUniformARB     OGL__glGetActiveUniformARB
#define glGetUniformfvARB         OGL__glGetUniformfvARB
#define glGetUniformivARB         OGL__glGetUniformivARB
#define glGetShaderSourceARB      OGL__glGetShaderSourceARB

#endif // GL_ARB_shader_objects

#endif // OPENGL_INCLUDE_GL_ARB_shader_objects

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_shader_precision
#define GL_ARB_shader_precision 1

#endif // GL_ARB_shader_precision

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_shader_stencil_export
#define GL_ARB_shader_stencil_export 1

#endif // GL_ARB_shader_stencil_export

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_shader_storage_buffer_object
#define GL_ARB_shader_storage_buffer_object 1

#endif // GL_ARB_shader_storage_buffer_object

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_shader_subroutine
#define GL_ARB_shader_subroutine 1

#endif // GL_ARB_shader_subroutine

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_shader_texture_image_samples
#define GL_ARB_shader_texture_image_samples 1

#endif // GL_ARB_shader_texture_image_samples

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_shader_texture_lod
#define GL_ARB_shader_texture_lod 1

#endif // GL_ARB_shader_texture_lod

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_shader_viewport_layer_array
#define GL_ARB_shader_viewport_layer_array 1

#endif // GL_ARB_shader_viewport_layer_array

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_shading_language_100
#define GL_ARB_shading_language_100 1

#define GL_SHADING_LANGUAGE_VERSION_ARB    0x8B8C

#endif // GL_ARB_shading_language_100

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_shading_language_420pack
#define GL_ARB_shading_language_420pack 1

#endif // GL_ARB_shading_language_420pack

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_shading_language_include

#ifndef GL_ARB_shading_language_include
#define GL_ARB_shading_language_include 1

#define GL_SHADER_INCLUDE_ARB         0x8DAE
#define GL_NAMED_STRING_LENGTH_ARB    0x8DE9
#define GL_NAMED_STRING_TYPE_ARB      0x8DEA

OPENGL_INIT_PROC(glNamedStringARB,          void,      GLenum type, GLint namelen, const GLchar *name, GLint stringlen, const GLchar *string);
OPENGL_INIT_PROC(glDeleteNamedStringARB,    void,      GLint namelen, const GLchar *name);
OPENGL_INIT_PROC(glCompileShaderIncludeARB, void,      GLuint shader, GLsizei count, const GLchar *const*path, const GLint *length);
OPENGL_INIT_PROC(glIsNamedStringARB,        GLboolean, GLint namelen, const GLchar *name);
OPENGL_INIT_PROC(glGetNamedStringARB,       void,      GLint namelen, const GLchar *name, GLsizei bufSize, GLint *stringlen, GLchar *string);
OPENGL_INIT_PROC(glGetNamedStringivARB,     void,      GLint namelen, const GLchar *name, GLenum pname, GLint *params);

#define glNamedStringARB          OGL__glNamedStringARB
#define glDeleteNamedStringARB    OGL__glDeleteNamedStringARB
#define glCompileShaderIncludeARB OGL__glCompileShaderIncludeARB
#define glIsNamedStringARB        OGL__glIsNamedStringARB
#define glGetNamedStringARB       OGL__glGetNamedStringARB
#define glGetNamedStringivARB     OGL__glGetNamedStringivARB

#endif // GL_ARB_shading_language_include

#endif // OPENGL_INCLUDE_GL_ARB_shading_language_include

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_shading_language_packing
#define GL_ARB_shading_language_packing 1

#endif // GL_ARB_shading_language_packing

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_shadow
#define GL_ARB_shadow 1

#define GL_TEXTURE_COMPARE_MODE_ARB    0x884C
#define GL_TEXTURE_COMPARE_FUNC_ARB    0x884D
#define GL_COMPARE_R_TO_TEXTURE_ARB    0x884E

#endif // GL_ARB_shadow

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_shadow_ambient
#define GL_ARB_shadow_ambient 1

#define GL_TEXTURE_COMPARE_FAIL_VALUE_ARB    0x80BF

#endif // GL_ARB_shadow_ambient

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_sparse_buffer

#ifndef GL_ARB_sparse_buffer
#define GL_ARB_sparse_buffer 1

#define GL_SPARSE_STORAGE_BIT_ARB         0x0400
#define GL_SPARSE_BUFFER_PAGE_SIZE_ARB    0x82F8

OPENGL_INIT_PROC(glBufferPageCommitmentARB,      void, GLenum target, GLintptr offset, GLsizeiptr size, GLboolean commit);
OPENGL_INIT_PROC(glNamedBufferPageCommitmentEXT, void, GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);
OPENGL_INIT_PROC(glNamedBufferPageCommitmentARB, void, GLuint buffer, GLintptr offset, GLsizeiptr size, GLboolean commit);

#define glBufferPageCommitmentARB      OGL__glBufferPageCommitmentARB
#define glNamedBufferPageCommitmentEXT OGL__glNamedBufferPageCommitmentEXT
#define glNamedBufferPageCommitmentARB OGL__glNamedBufferPageCommitmentARB

#endif // GL_ARB_sparse_buffer

#endif // OPENGL_INCLUDE_GL_ARB_sparse_buffer

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_sparse_texture

#ifndef GL_ARB_sparse_texture
#define GL_ARB_sparse_texture 1

#define GL_TEXTURE_SPARSE_ARB                            0x91A6
#define GL_VIRTUAL_PAGE_SIZE_INDEX_ARB                   0x91A7
#define GL_NUM_SPARSE_LEVELS_ARB                         0x91AA
#define GL_NUM_VIRTUAL_PAGE_SIZES_ARB                    0x91A8
#define GL_VIRTUAL_PAGE_SIZE_X_ARB                       0x9195
#define GL_VIRTUAL_PAGE_SIZE_Y_ARB                       0x9196
#define GL_VIRTUAL_PAGE_SIZE_Z_ARB                       0x9197
#define GL_MAX_SPARSE_TEXTURE_SIZE_ARB                   0x9198
#define GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB                0x9199
#define GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB           0x919A
#define GL_SPARSE_TEXTURE_FULL_ARRAY_CUBE_MIPMAPS_ARB    0x91A9

OPENGL_INIT_PROC(glTexPageCommitmentARB, void, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
#define glTexPageCommitmentARB OGL__glTexPageCommitmentARB

#endif // GL_ARB_sparse_texture

#endif // OPENGL_INCLUDE_GL_ARB_sparse_texture

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_sparse_texture2
#define GL_ARB_sparse_texture2 1

#endif // GL_ARB_sparse_texture2

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_sparse_texture_clamp
#define GL_ARB_sparse_texture_clamp 1

#endif // GL_ARB_sparse_texture_clamp

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_spirv_extensions
#define GL_ARB_spirv_extensions 1

#endif // GL_ARB_spirv_extensions

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_stencil_texturing
#define GL_ARB_stencil_texturing 1

#endif // GL_ARB_stencil_texturing

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_sync
#define GL_ARB_sync 1

#endif // GL_ARB_sync

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_tessellation_shader
#define GL_ARB_tessellation_shader 1

#endif // GL_ARB_tessellation_shader

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_barrier
#define GL_ARB_texture_barrier 1

#endif // GL_ARB_texture_barrier

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_border_clamp
#define GL_ARB_texture_border_clamp 1

#define GL_CLAMP_TO_BORDER_ARB    0x812D

#endif // GL_ARB_texture_border_clamp

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_texture_buffer_object

#ifndef GL_ARB_texture_buffer_object
#define GL_ARB_texture_buffer_object 1

#define GL_TEXTURE_BUFFER_ARB                       0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE_ARB              0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_ARB               0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_ARB    0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT_ARB                0x8C2E

OPENGL_INIT_PROC(glTexBufferARB, void, GLenum target, GLenum internalformat, GLuint buffer);
#define glTexBufferARB OGL__glTexBufferARB

#endif // GL_ARB_texture_buffer_object

#endif // OPENGL_INCLUDE_GL_ARB_texture_buffer_object

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_buffer_object_rgb32
#define GL_ARB_texture_buffer_object_rgb32 1

#endif // GL_ARB_texture_buffer_object_rgb32

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_buffer_range
#define GL_ARB_texture_buffer_range 1

#endif // GL_ARB_texture_buffer_range

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_texture_compression

#ifndef GL_ARB_texture_compression
#define GL_ARB_texture_compression 1

#define GL_COMPRESSED_ALPHA_ARB                  0x84E9
#define GL_COMPRESSED_LUMINANCE_ARB              0x84EA
#define GL_COMPRESSED_LUMINANCE_ALPHA_ARB        0x84EB
#define GL_COMPRESSED_INTENSITY_ARB              0x84EC
#define GL_COMPRESSED_RGB_ARB                    0x84ED
#define GL_COMPRESSED_RGBA_ARB                   0x84EE
#define GL_TEXTURE_COMPRESSION_HINT_ARB          0x84EF
#define GL_TEXTURE_COMPRESSED_IMAGE_SIZE_ARB     0x86A0
#define GL_TEXTURE_COMPRESSED_ARB                0x86A1
#define GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB    0x86A2
#define GL_COMPRESSED_TEXTURE_FORMATS_ARB        0x86A3

OPENGL_INIT_PROC(glCompressedTexImage3DARB,    void, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
OPENGL_INIT_PROC(glCompressedTexImage2DARB,    void, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
OPENGL_INIT_PROC(glCompressedTexImage1DARB,    void, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
OPENGL_INIT_PROC(glCompressedTexSubImage3DARB, void, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
OPENGL_INIT_PROC(glCompressedTexSubImage2DARB, void, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
OPENGL_INIT_PROC(glCompressedTexSubImage1DARB, void, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
OPENGL_INIT_PROC(glGetCompressedTexImageARB,   void, GLenum target, GLint level, void *img);

#define glCompressedTexImage3DARB    OGL__glCompressedTexImage3DARB
#define glCompressedTexImage2DARB    OGL__glCompressedTexImage2DARB
#define glCompressedTexImage1DARB    OGL__glCompressedTexImage1DARB
#define glCompressedTexSubImage3DARB OGL__glCompressedTexSubImage3DARB
#define glCompressedTexSubImage2DARB OGL__glCompressedTexSubImage2DARB
#define glCompressedTexSubImage1DARB OGL__glCompressedTexSubImage1DARB
#define glGetCompressedTexImageARB   OGL__glGetCompressedTexImageARB

#endif // GL_ARB_texture_compression

#endif // OPENGL_INCLUDE_GL_ARB_texture_compression

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_compression_bptc
#define GL_ARB_texture_compression_bptc 1

#define GL_COMPRESSED_RGBA_BPTC_UNORM_ARB            0x8E8C
#define GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM_ARB      0x8E8D
#define GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT_ARB      0x8E8E
#define GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT_ARB    0x8E8F

#endif // GL_ARB_texture_compression_bptc

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_compression_rgtc
#define GL_ARB_texture_compression_rgtc 1

#endif // GL_ARB_texture_compression_rgtc

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_cube_map
#define GL_ARB_texture_cube_map 1

#define GL_NORMAL_MAP_ARB                     0x8511
#define GL_REFLECTION_MAP_ARB                 0x8512
#define GL_TEXTURE_CUBE_MAP_ARB               0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_ARB       0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_ARB    0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_ARB    0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_ARB    0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_ARB    0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_ARB    0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_ARB    0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARB         0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB      0x851C

#endif // GL_ARB_texture_cube_map

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_cube_map_array
#define GL_ARB_texture_cube_map_array 1

#define GL_TEXTURE_CUBE_MAP_ARRAY_ARB                 0x9009
#define GL_TEXTURE_BINDING_CUBE_MAP_ARRAY_ARB         0x900A
#define GL_PROXY_TEXTURE_CUBE_MAP_ARRAY_ARB           0x900B
#define GL_SAMPLER_CUBE_MAP_ARRAY_ARB                 0x900C
#define GL_SAMPLER_CUBE_MAP_ARRAY_SHADOW_ARB          0x900D
#define GL_INT_SAMPLER_CUBE_MAP_ARRAY_ARB             0x900E
#define GL_UNSIGNED_INT_SAMPLER_CUBE_MAP_ARRAY_ARB    0x900F

#endif // GL_ARB_texture_cube_map_array

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_env_add
#define GL_ARB_texture_env_add 1

#endif // GL_ARB_texture_env_add

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_env_combine
#define GL_ARB_texture_env_combine 1

#define GL_COMBINE_ARB           0x8570
#define GL_COMBINE_RGB_ARB       0x8571
#define GL_COMBINE_ALPHA_ARB     0x8572
#define GL_SOURCE0_RGB_ARB       0x8580
#define GL_SOURCE1_RGB_ARB       0x8581
#define GL_SOURCE2_RGB_ARB       0x8582
#define GL_SOURCE0_ALPHA_ARB     0x8588
#define GL_SOURCE1_ALPHA_ARB     0x8589
#define GL_SOURCE2_ALPHA_ARB     0x858A
#define GL_OPERAND0_RGB_ARB      0x8590
#define GL_OPERAND1_RGB_ARB      0x8591
#define GL_OPERAND2_RGB_ARB      0x8592
#define GL_OPERAND0_ALPHA_ARB    0x8598
#define GL_OPERAND1_ALPHA_ARB    0x8599
#define GL_OPERAND2_ALPHA_ARB    0x859A
#define GL_RGB_SCALE_ARB         0x8573
#define GL_ADD_SIGNED_ARB        0x8574
#define GL_INTERPOLATE_ARB       0x8575
#define GL_SUBTRACT_ARB          0x84E7
#define GL_CONSTANT_ARB          0x8576
#define GL_PRIMARY_COLOR_ARB     0x8577
#define GL_PREVIOUS_ARB          0x8578

#endif // GL_ARB_texture_env_combine

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_env_crossbar
#define GL_ARB_texture_env_crossbar 1

#endif // GL_ARB_texture_env_crossbar

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_env_dot3
#define GL_ARB_texture_env_dot3 1

#define GL_DOT3_RGB_ARB     0x86AE
#define GL_DOT3_RGBA_ARB    0x86AF

#endif // GL_ARB_texture_env_dot3

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_filter_anisotropic
#define GL_ARB_texture_filter_anisotropic 1

#endif // GL_ARB_texture_filter_anisotropic

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_filter_minmax
#define GL_ARB_texture_filter_minmax 1

#define GL_TEXTURE_REDUCTION_MODE_ARB    0x9366
#define GL_WEIGHTED_AVERAGE_ARB          0x9367

#endif // GL_ARB_texture_filter_minmax

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_float
#define GL_ARB_texture_float 1

#define GL_TEXTURE_RED_TYPE_ARB          0x8C10
#define GL_TEXTURE_GREEN_TYPE_ARB        0x8C11
#define GL_TEXTURE_BLUE_TYPE_ARB         0x8C12
#define GL_TEXTURE_ALPHA_TYPE_ARB        0x8C13
#define GL_TEXTURE_LUMINANCE_TYPE_ARB    0x8C14
#define GL_TEXTURE_INTENSITY_TYPE_ARB    0x8C15
#define GL_TEXTURE_DEPTH_TYPE_ARB        0x8C16
#define GL_UNSIGNED_NORMALIZED_ARB       0x8C17
#define GL_RGBA32F_ARB                   0x8814
#define GL_RGB32F_ARB                    0x8815
#define GL_ALPHA32F_ARB                  0x8816
#define GL_INTENSITY32F_ARB              0x8817
#define GL_LUMINANCE32F_ARB              0x8818
#define GL_LUMINANCE_ALPHA32F_ARB        0x8819
#define GL_RGBA16F_ARB                   0x881A
#define GL_RGB16F_ARB                    0x881B
#define GL_ALPHA16F_ARB                  0x881C
#define GL_INTENSITY16F_ARB              0x881D
#define GL_LUMINANCE16F_ARB              0x881E
#define GL_LUMINANCE_ALPHA16F_ARB        0x881F

#endif // GL_ARB_texture_float

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_gather
#define GL_ARB_texture_gather 1

#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_ARB        0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB        0x8E5F
#define GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB    0x8F9F

#endif // GL_ARB_texture_gather

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_mirror_clamp_to_edge
#define GL_ARB_texture_mirror_clamp_to_edge 1

#endif // GL_ARB_texture_mirror_clamp_to_edge

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_mirrored_repeat
#define GL_ARB_texture_mirrored_repeat 1

#define GL_MIRRORED_REPEAT_ARB    0x8370

#endif // GL_ARB_texture_mirrored_repeat

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_multisample
#define GL_ARB_texture_multisample 1

#endif // GL_ARB_texture_multisample

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_non_power_of_two
#define GL_ARB_texture_non_power_of_two 1

#endif // GL_ARB_texture_non_power_of_two

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_query_levels
#define GL_ARB_texture_query_levels 1

#endif // GL_ARB_texture_query_levels

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_query_lod
#define GL_ARB_texture_query_lod 1

#endif // GL_ARB_texture_query_lod

/* -------------------------------------------------------------------------- */
#ifndef GL_ARB_texture_rectangle
#define GL_ARB_texture_rectangle 1

#define GL_TEXTURE_RECTANGLE_ARB             0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_ARB     0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE_ARB       0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB    0x84F8

#endif // GL_ARB_texture_rectangle

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_rg
#define GL_ARB_texture_rg 1

#endif // GL_ARB_texture_rg

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_rgb10_a2ui
#define GL_ARB_texture_rgb10_a2ui 1

#endif // GL_ARB_texture_rgb10_a2ui

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_stencil8
#define GL_ARB_texture_stencil8 1

#endif // GL_ARB_texture_stencil8

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_storage
#define GL_ARB_texture_storage 1

#endif // GL_ARB_texture_storage

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_storage_multisample
#define GL_ARB_texture_storage_multisample 1

#endif // GL_ARB_texture_storage_multisample

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_swizzle
#define GL_ARB_texture_swizzle 1

#endif // GL_ARB_texture_swizzle

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_texture_view
#define GL_ARB_texture_view 1

#endif // GL_ARB_texture_view

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_timer_query
#define GL_ARB_timer_query 1

#endif // GL_ARB_timer_query

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_transform_feedback2
#define GL_ARB_transform_feedback2 1

#endif // GL_ARB_transform_feedback2

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_transform_feedback3
#define GL_ARB_transform_feedback3 1

#endif // GL_ARB_transform_feedback3

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_transform_feedback_instanced
#define GL_ARB_transform_feedback_instanced 1

#endif // GL_ARB_transform_feedback_instanced

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_transform_feedback_overflow_query
#define GL_ARB_transform_feedback_overflow_query 1

#define GL_TRANSFORM_FEEDBACK_OVERFLOW_ARB           0x82EC
#define GL_TRANSFORM_FEEDBACK_STREAM_OVERFLOW_ARB    0x82ED

#endif // GL_ARB_transform_feedback_overflow_query

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_transpose_matrix

#ifndef GL_ARB_transpose_matrix
#define GL_ARB_transpose_matrix 1

#define GL_TRANSPOSE_MODELVIEW_MATRIX_ARB     0x84E3
#define GL_TRANSPOSE_PROJECTION_MATRIX_ARB    0x84E4
#define GL_TRANSPOSE_TEXTURE_MATRIX_ARB       0x84E5
#define GL_TRANSPOSE_COLOR_MATRIX_ARB         0x84E6

OPENGL_INIT_PROC(glLoadTransposeMatrixfARB, void, const GLfloat *m);
OPENGL_INIT_PROC(glLoadTransposeMatrixdARB, void, const GLdouble *m);
OPENGL_INIT_PROC(glMultTransposeMatrixfARB, void, const GLfloat *m);
OPENGL_INIT_PROC(glMultTransposeMatrixdARB, void, const GLdouble *m);

#define glLoadTransposeMatrixfARB OGL__glLoadTransposeMatrixfARB
#define glLoadTransposeMatrixdARB OGL__glLoadTransposeMatrixdARB
#define glMultTransposeMatrixfARB OGL__glMultTransposeMatrixfARB
#define glMultTransposeMatrixdARB OGL__glMultTransposeMatrixdARB

#endif // GL_ARB_transpose_matrix

#endif // OPENGL_INCLUDE_GL_ARB_transpose_matrix

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_uniform_buffer_object
#define GL_ARB_uniform_buffer_object 1

#endif // GL_ARB_uniform_buffer_object

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_vertex_array_bgra
#define GL_ARB_vertex_array_bgra 1

#endif // GL_ARB_vertex_array_bgra

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_vertex_array_object
#define GL_ARB_vertex_array_object 1

#endif // GL_ARB_vertex_array_object

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_vertex_attrib_64bit
#define GL_ARB_vertex_attrib_64bit 1

#endif // GL_ARB_vertex_attrib_64bit

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_vertex_attrib_binding
#define GL_ARB_vertex_attrib_binding 1

#endif // GL_ARB_vertex_attrib_binding

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_vertex_blend

#ifndef GL_ARB_vertex_blend
#define GL_ARB_vertex_blend 1

#define GL_MAX_VERTEX_UNITS_ARB        0x86A4
#define GL_ACTIVE_VERTEX_UNITS_ARB     0x86A5
#define GL_WEIGHT_SUM_UNITY_ARB        0x86A6
#define GL_VERTEX_BLEND_ARB            0x86A7
#define GL_CURRENT_WEIGHT_ARB          0x86A8
#define GL_WEIGHT_ARRAY_TYPE_ARB       0x86A9
#define GL_WEIGHT_ARRAY_STRIDE_ARB     0x86AA
#define GL_WEIGHT_ARRAY_SIZE_ARB       0x86AB
#define GL_WEIGHT_ARRAY_POINTER_ARB    0x86AC
#define GL_WEIGHT_ARRAY_ARB            0x86AD
#define GL_MODELVIEW0_ARB              0x1700
#define GL_MODELVIEW1_ARB              0x850A
#define GL_MODELVIEW2_ARB              0x8722
#define GL_MODELVIEW3_ARB              0x8723
#define GL_MODELVIEW4_ARB              0x8724
#define GL_MODELVIEW5_ARB              0x8725
#define GL_MODELVIEW6_ARB              0x8726
#define GL_MODELVIEW7_ARB              0x8727
#define GL_MODELVIEW8_ARB              0x8728
#define GL_MODELVIEW9_ARB              0x8729
#define GL_MODELVIEW10_ARB             0x872A
#define GL_MODELVIEW11_ARB             0x872B
#define GL_MODELVIEW12_ARB             0x872C
#define GL_MODELVIEW13_ARB             0x872D
#define GL_MODELVIEW14_ARB             0x872E
#define GL_MODELVIEW15_ARB             0x872F
#define GL_MODELVIEW16_ARB             0x8730
#define GL_MODELVIEW17_ARB             0x8731
#define GL_MODELVIEW18_ARB             0x8732
#define GL_MODELVIEW19_ARB             0x8733
#define GL_MODELVIEW20_ARB             0x8734
#define GL_MODELVIEW21_ARB             0x8735
#define GL_MODELVIEW22_ARB             0x8736
#define GL_MODELVIEW23_ARB             0x8737
#define GL_MODELVIEW24_ARB             0x8738
#define GL_MODELVIEW25_ARB             0x8739
#define GL_MODELVIEW26_ARB             0x873A
#define GL_MODELVIEW27_ARB             0x873B
#define GL_MODELVIEW28_ARB             0x873C
#define GL_MODELVIEW29_ARB             0x873D
#define GL_MODELVIEW30_ARB             0x873E
#define GL_MODELVIEW31_ARB             0x873F

OPENGL_INIT_PROC(glWeightbvARB,      void, GLint size, const GLbyte *weights);
OPENGL_INIT_PROC(glWeightsvARB,      void, GLint size, const GLshort *weights);
OPENGL_INIT_PROC(glWeightivARB,      void, GLint size, const GLint *weights);
OPENGL_INIT_PROC(glWeightfvARB,      void, GLint size, const GLfloat *weights);
OPENGL_INIT_PROC(glWeightdvARB,      void, GLint size, const GLdouble *weights);
OPENGL_INIT_PROC(glWeightubvARB,     void, GLint size, const GLubyte *weights);
OPENGL_INIT_PROC(glWeightusvARB,     void, GLint size, const GLushort *weights);
OPENGL_INIT_PROC(glWeightuivARB,     void, GLint size, const GLuint *weights);
OPENGL_INIT_PROC(glWeightPointerARB, void, GLint size, GLenum type, GLsizei stride, const void *pointer);
OPENGL_INIT_PROC(glVertexBlendARB,   void, GLint count);

#define glWeightbvARB      OGL__glWeightbvARB
#define glWeightsvARB      OGL__glWeightsvARB
#define glWeightivARB      OGL__glWeightivARB
#define glWeightfvARB      OGL__glWeightfvARB
#define glWeightdvARB      OGL__glWeightdvARB
#define glWeightubvARB     OGL__glWeightubvARB
#define glWeightusvARB     OGL__glWeightusvARB
#define glWeightuivARB     OGL__glWeightuivARB
#define glWeightPointerARB OGL__glWeightPointerARB
#define glVertexBlendARB   OGL__glVertexBlendARB

#endif // GL_ARB_vertex_blend

#endif // OPENGL_INCLUDE_GL_ARB_vertex_blend

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_vertex_buffer_object

#ifndef GL_ARB_vertex_buffer_object
#define GL_ARB_vertex_buffer_object 1

#define GL_BUFFER_SIZE_ARB                             0x8764
#define GL_BUFFER_USAGE_ARB                            0x8765
#define GL_ARRAY_BUFFER_ARB                            0x8892
#define GL_ELEMENT_ARRAY_BUFFER_ARB                    0x8893
#define GL_ARRAY_BUFFER_BINDING_ARB                    0x8894
#define GL_ELEMENT_ARRAY_BUFFER_BINDING_ARB            0x8895
#define GL_VERTEX_ARRAY_BUFFER_BINDING_ARB             0x8896
#define GL_NORMAL_ARRAY_BUFFER_BINDING_ARB             0x8897
#define GL_COLOR_ARRAY_BUFFER_BINDING_ARB              0x8898
#define GL_INDEX_ARRAY_BUFFER_BINDING_ARB              0x8899
#define GL_TEXTURE_COORD_ARRAY_BUFFER_BINDING_ARB      0x889A
#define GL_EDGE_FLAG_ARRAY_BUFFER_BINDING_ARB          0x889B
#define GL_SECONDARY_COLOR_ARRAY_BUFFER_BINDING_ARB    0x889C
#define GL_FOG_COORDINATE_ARRAY_BUFFER_BINDING_ARB     0x889D
#define GL_WEIGHT_ARRAY_BUFFER_BINDING_ARB             0x889E
#define GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING_ARB      0x889F
#define GL_READ_ONLY_ARB                               0x88B8
#define GL_WRITE_ONLY_ARB                              0x88B9
#define GL_READ_WRITE_ARB                              0x88BA
#define GL_BUFFER_ACCESS_ARB                           0x88BB
#define GL_BUFFER_MAPPED_ARB                           0x88BC
#define GL_BUFFER_MAP_POINTER_ARB                      0x88BD
#define GL_STREAM_DRAW_ARB                             0x88E0
#define GL_STREAM_READ_ARB                             0x88E1
#define GL_STREAM_COPY_ARB                             0x88E2
#define GL_STATIC_DRAW_ARB                             0x88E4
#define GL_STATIC_READ_ARB                             0x88E5
#define GL_STATIC_COPY_ARB                             0x88E6
#define GL_DYNAMIC_DRAW_ARB                            0x88E8
#define GL_DYNAMIC_READ_ARB                            0x88E9
#define GL_DYNAMIC_COPY_ARB                            0x88EA

OPENGL_INIT_PROC(glBindBufferARB,           void,      GLenum target, GLuint buffer);
OPENGL_INIT_PROC(glDeleteBuffersARB,        void,      GLsizei n, const GLuint *buffers);
OPENGL_INIT_PROC(glGenBuffersARB,           void,      GLsizei n, GLuint *buffers);
OPENGL_INIT_PROC(glIsBufferARB,             GLboolean, GLuint buffer);
OPENGL_INIT_PROC(glBufferDataARB,           void,      GLenum target, GLsizeiptrARB size, const void *data, GLenum usage);
OPENGL_INIT_PROC(glBufferSubDataARB,        void,      GLenum target, GLintptrARB offset, GLsizeiptrARB size, const void *data);
OPENGL_INIT_PROC(glGetBufferSubDataARB,     void,      GLenum target, GLintptrARB offset, GLsizeiptrARB size, void *data);
OPENGL_INIT_PROC(glMapBufferARB,            void*,     GLenum target, GLenum access);
OPENGL_INIT_PROC(glUnmapBufferARB,          GLboolean, GLenum target);
OPENGL_INIT_PROC(glGetBufferParameterivARB, void,      GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetBufferPointervARB,    void,      GLenum target, GLenum pname, void **params);

#define glBindBufferARB           OGL__glBindBufferARB
#define glDeleteBuffersARB        OGL__glDeleteBuffersARB
#define glGenBuffersARB           OGL__glGenBuffersARB
#define glIsBufferARB             OGL__glIsBufferARB
#define glBufferDataARB           OGL__glBufferDataARB
#define glBufferSubDataARB        OGL__glBufferSubDataARB
#define glGetBufferSubDataARB     OGL__glGetBufferSubDataARB
#define glMapBufferARB            OGL__glMapBufferARB
#define glUnmapBufferARB          OGL__glUnmapBufferARB
#define glGetBufferParameterivARB OGL__glGetBufferParameterivARB
#define glGetBufferPointervARB    OGL__glGetBufferPointervARB

#endif // GL_ARB_vertex_buffer_object

#endif // OPENGL_INCLUDE_GL_ARB_vertex_buffer_object

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_vertex_program

#ifndef GL_ARB_vertex_program
#define GL_ARB_vertex_program 1

#define GL_COLOR_SUM_ARB                               0x8458
#define GL_VERTEX_PROGRAM_ARB                          0x8620
#define GL_VERTEX_ATTRIB_ARRAY_ENABLED_ARB             0x8622
#define GL_VERTEX_ATTRIB_ARRAY_SIZE_ARB                0x8623
#define GL_VERTEX_ATTRIB_ARRAY_STRIDE_ARB              0x8624
#define GL_VERTEX_ATTRIB_ARRAY_TYPE_ARB                0x8625
#define GL_CURRENT_VERTEX_ATTRIB_ARB                   0x8626
#define GL_VERTEX_PROGRAM_POINT_SIZE_ARB               0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_ARB                 0x8643
#define GL_VERTEX_ATTRIB_ARRAY_POINTER_ARB             0x8645
#define GL_MAX_VERTEX_ATTRIBS_ARB                      0x8869
#define GL_VERTEX_ATTRIB_ARRAY_NORMALIZED_ARB          0x886A
#define GL_PROGRAM_ADDRESS_REGISTERS_ARB               0x88B0
#define GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB           0x88B1
#define GL_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB        0x88B2
#define GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB    0x88B3

OPENGL_INIT_PROC(glVertexAttrib1dARB,           void, GLuint index, GLdouble x);
OPENGL_INIT_PROC(glVertexAttrib1dvARB,          void, GLuint index, const GLdouble *v);
OPENGL_INIT_PROC(glVertexAttrib1fARB,           void, GLuint index, GLfloat x);
OPENGL_INIT_PROC(glVertexAttrib1fvARB,          void, GLuint index, const GLfloat *v);
OPENGL_INIT_PROC(glVertexAttrib1sARB,           void, GLuint index, GLshort x);
OPENGL_INIT_PROC(glVertexAttrib1svARB,          void, GLuint index, const GLshort *v);
OPENGL_INIT_PROC(glVertexAttrib2dARB,           void, GLuint index, GLdouble x, GLdouble y);
OPENGL_INIT_PROC(glVertexAttrib2dvARB,          void, GLuint index, const GLdouble *v);
OPENGL_INIT_PROC(glVertexAttrib2fARB,           void, GLuint index, GLfloat x, GLfloat y);
OPENGL_INIT_PROC(glVertexAttrib2fvARB,          void, GLuint index, const GLfloat *v);
OPENGL_INIT_PROC(glVertexAttrib2sARB,           void, GLuint index, GLshort x, GLshort y);
OPENGL_INIT_PROC(glVertexAttrib2svARB,          void, GLuint index, const GLshort *v);
OPENGL_INIT_PROC(glVertexAttrib3dARB,           void, GLuint index, GLdouble x, GLdouble y, GLdouble z);
OPENGL_INIT_PROC(glVertexAttrib3dvARB,          void, GLuint index, const GLdouble *v);
OPENGL_INIT_PROC(glVertexAttrib3fARB,           void, GLuint index, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glVertexAttrib3fvARB,          void, GLuint index, const GLfloat *v);
OPENGL_INIT_PROC(glVertexAttrib3sARB,           void, GLuint index, GLshort x, GLshort y, GLshort z);
OPENGL_INIT_PROC(glVertexAttrib3svARB,          void, GLuint index, const GLshort *v);
OPENGL_INIT_PROC(glVertexAttrib4NbvARB,         void, GLuint index, const GLbyte *v);
OPENGL_INIT_PROC(glVertexAttrib4NivARB,         void, GLuint index, const GLint *v);
OPENGL_INIT_PROC(glVertexAttrib4NsvARB,         void, GLuint index, const GLshort *v);
OPENGL_INIT_PROC(glVertexAttrib4NubARB,         void, GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
OPENGL_INIT_PROC(glVertexAttrib4NubvARB,        void, GLuint index, const GLubyte *v);
OPENGL_INIT_PROC(glVertexAttrib4NuivARB,        void, GLuint index, const GLuint *v);
OPENGL_INIT_PROC(glVertexAttrib4NusvARB,        void, GLuint index, const GLushort *v);
OPENGL_INIT_PROC(glVertexAttrib4bvARB,          void, GLuint index, const GLbyte *v);
OPENGL_INIT_PROC(glVertexAttrib4dARB,           void, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
OPENGL_INIT_PROC(glVertexAttrib4dvARB,          void, GLuint index, const GLdouble *v);
OPENGL_INIT_PROC(glVertexAttrib4fARB,           void, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
OPENGL_INIT_PROC(glVertexAttrib4fvARB,          void, GLuint index, const GLfloat *v);
OPENGL_INIT_PROC(glVertexAttrib4ivARB,          void, GLuint index, const GLint *v);
OPENGL_INIT_PROC(glVertexAttrib4sARB,           void, GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
OPENGL_INIT_PROC(glVertexAttrib4svARB,          void, GLuint index, const GLshort *v);
OPENGL_INIT_PROC(glVertexAttrib4ubvARB,         void, GLuint index, const GLubyte *v);
OPENGL_INIT_PROC(glVertexAttrib4uivARB,         void, GLuint index, const GLuint *v);
OPENGL_INIT_PROC(glVertexAttrib4usvARB,         void, GLuint index, const GLushort *v);
OPENGL_INIT_PROC(glVertexAttribPointerARB,      void, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);
OPENGL_INIT_PROC(glEnableVertexAttribArrayARB,  void, GLuint index);
OPENGL_INIT_PROC(glDisableVertexAttribArrayARB, void, GLuint index);
OPENGL_INIT_PROC(glGetVertexAttribdvARB,        void, GLuint index, GLenum pname, GLdouble *params);
OPENGL_INIT_PROC(glGetVertexAttribfvARB,        void, GLuint index, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetVertexAttribivARB,        void, GLuint index, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetVertexAttribPointervARB,  void, GLuint index, GLenum pname, void **pointer);

#define glVertexAttrib1dARB           OGL__glVertexAttrib1dARB
#define glVertexAttrib1dvARB          OGL__glVertexAttrib1dvARB
#define glVertexAttrib1fARB           OGL__glVertexAttrib1fARB
#define glVertexAttrib1fvARB          OGL__glVertexAttrib1fvARB
#define glVertexAttrib1sARB           OGL__glVertexAttrib1sARB
#define glVertexAttrib1svARB          OGL__glVertexAttrib1svARB
#define glVertexAttrib2dARB           OGL__glVertexAttrib2dARB
#define glVertexAttrib2dvARB          OGL__glVertexAttrib2dvARB
#define glVertexAttrib2fARB           OGL__glVertexAttrib2fARB
#define glVertexAttrib2fvARB          OGL__glVertexAttrib2fvARB
#define glVertexAttrib2sARB           OGL__glVertexAttrib2sARB
#define glVertexAttrib2svARB          OGL__glVertexAttrib2svARB
#define glVertexAttrib3dARB           OGL__glVertexAttrib3dARB
#define glVertexAttrib3dvARB          OGL__glVertexAttrib3dvARB
#define glVertexAttrib3fARB           OGL__glVertexAttrib3fARB
#define glVertexAttrib3fvARB          OGL__glVertexAttrib3fvARB
#define glVertexAttrib3sARB           OGL__glVertexAttrib3sARB
#define glVertexAttrib3svARB          OGL__glVertexAttrib3svARB
#define glVertexAttrib4NbvARB         OGL__glVertexAttrib4NbvARB
#define glVertexAttrib4NivARB         OGL__glVertexAttrib4NivARB
#define glVertexAttrib4NsvARB         OGL__glVertexAttrib4NsvARB
#define glVertexAttrib4NubARB         OGL__glVertexAttrib4NubARB
#define glVertexAttrib4NubvARB        OGL__glVertexAttrib4NubvARB
#define glVertexAttrib4NuivARB        OGL__glVertexAttrib4NuivARB
#define glVertexAttrib4NusvARB        OGL__glVertexAttrib4NusvARB
#define glVertexAttrib4bvARB          OGL__glVertexAttrib4bvARB
#define glVertexAttrib4dARB           OGL__glVertexAttrib4dARB
#define glVertexAttrib4dvARB          OGL__glVertexAttrib4dvARB
#define glVertexAttrib4fARB           OGL__glVertexAttrib4fARB
#define glVertexAttrib4fvARB          OGL__glVertexAttrib4fvARB
#define glVertexAttrib4ivARB          OGL__glVertexAttrib4ivARB
#define glVertexAttrib4sARB           OGL__glVertexAttrib4sARB
#define glVertexAttrib4svARB          OGL__glVertexAttrib4svARB
#define glVertexAttrib4ubvARB         OGL__glVertexAttrib4ubvARB
#define glVertexAttrib4uivARB         OGL__glVertexAttrib4uivARB
#define glVertexAttrib4usvARB         OGL__glVertexAttrib4usvARB
#define glVertexAttribPointerARB      OGL__glVertexAttribPointerARB
#define glEnableVertexAttribArrayARB  OGL__glEnableVertexAttribArrayARB
#define glDisableVertexAttribArrayARB OGL__glDisableVertexAttribArrayARB
#define glGetVertexAttribdvARB        OGL__glGetVertexAttribdvARB
#define glGetVertexAttribfvARB        OGL__glGetVertexAttribfvARB
#define glGetVertexAttribivARB        OGL__glGetVertexAttribivARB
#define glGetVertexAttribPointervARB  OGL__glGetVertexAttribPointervARB

#endif // GL_ARB_vertex_program

#endif // OPENGL_INCLUDE_GL_ARB_vertex_program

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_vertex_shader

#ifndef GL_ARB_vertex_shader
#define GL_ARB_vertex_shader 1

#define GL_VERTEX_SHADER_ARB                         0x8B31
#define GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB         0x8B4A
#define GL_MAX_VARYING_FLOATS_ARB                    0x8B4B
#define GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB        0x8B4C
#define GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB      0x8B4D
#define GL_OBJECT_ACTIVE_ATTRIBUTES_ARB              0x8B89
#define GL_OBJECT_ACTIVE_ATTRIBUTE_MAX_LENGTH_ARB    0x8B8A

OPENGL_INIT_PROC(glBindAttribLocationARB, void,  GLhandleARB programObj, GLuint index, const GLcharARB *name);
OPENGL_INIT_PROC(glGetActiveAttribARB,    void,  GLhandleARB programObj, GLuint index, GLsizei maxLength, GLsizei *length, GLint *size, GLenum *type, GLcharARB *name);
OPENGL_INIT_PROC(glGetAttribLocationARB,  GLint, GLhandleARB programObj, const GLcharARB *name);

#define glBindAttribLocationARB OGL__glBindAttribLocationARB
#define glGetActiveAttribARB    OGL__glGetActiveAttribARB
#define glGetAttribLocationARB  OGL__glGetAttribLocationARB

#endif // GL_ARB_vertex_shader

#endif // OPENGL_INCLUDE_GL_ARB_vertex_shader

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_vertex_type_10f_11f_11f_rev
#define GL_ARB_vertex_type_10f_11f_11f_rev 1

#endif // GL_ARB_vertex_type_10f_11f_11f_rev

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_vertex_type_2_10_10_10_rev
#define GL_ARB_vertex_type_2_10_10_10_rev 1

#endif // GL_ARB_vertex_type_2_10_10_10_rev

/* -------------------------------------------------------------------------- */

#ifndef GL_ARB_viewport_array
#define GL_ARB_viewport_array 1

#endif // GL_ARB_viewport_array

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ARB_window_pos

#ifndef GL_ARB_window_pos
#define GL_ARB_window_pos 1

OPENGL_INIT_PROC(glWindowPos2dARB,  void, GLdouble x, GLdouble y);
OPENGL_INIT_PROC(glWindowPos2dvARB, void, const GLdouble *v);
OPENGL_INIT_PROC(glWindowPos2fARB,  void, GLfloat x, GLfloat y);
OPENGL_INIT_PROC(glWindowPos2fvARB, void, const GLfloat *v);
OPENGL_INIT_PROC(glWindowPos2iARB,  void, GLint x, GLint y);
OPENGL_INIT_PROC(glWindowPos2ivARB, void, const GLint *v);
OPENGL_INIT_PROC(glWindowPos2sARB,  void, GLshort x, GLshort y);
OPENGL_INIT_PROC(glWindowPos2svARB, void, const GLshort *v);
OPENGL_INIT_PROC(glWindowPos3dARB,  void, GLdouble x, GLdouble y, GLdouble z);
OPENGL_INIT_PROC(glWindowPos3dvARB, void, const GLdouble *v);
OPENGL_INIT_PROC(glWindowPos3fARB,  void, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glWindowPos3fvARB, void, const GLfloat *v);
OPENGL_INIT_PROC(glWindowPos3iARB,  void, GLint x, GLint y, GLint z);
OPENGL_INIT_PROC(glWindowPos3ivARB, void, const GLint *v);
OPENGL_INIT_PROC(glWindowPos3sARB,  void, GLshort x, GLshort y, GLshort z);
OPENGL_INIT_PROC(glWindowPos3svARB, void, const GLshort *v);

#define glWindowPos2dARB  OGL__glWindowPos2dARB
#define glWindowPos2dvARB OGL__glWindowPos2dvARB
#define glWindowPos2fARB  OGL__glWindowPos2fARB
#define glWindowPos2fvARB OGL__glWindowPos2fvARB
#define glWindowPos2iARB  OGL__glWindowPos2iARB
#define glWindowPos2ivARB OGL__glWindowPos2ivARB
#define glWindowPos2sARB  OGL__glWindowPos2sARB
#define glWindowPos2svARB OGL__glWindowPos2svARB
#define glWindowPos3dARB  OGL__glWindowPos3dARB
#define glWindowPos3dvARB OGL__glWindowPos3dvARB
#define glWindowPos3fARB  OGL__glWindowPos3fARB
#define glWindowPos3fvARB OGL__glWindowPos3fvARB
#define glWindowPos3iARB  OGL__glWindowPos3iARB
#define glWindowPos3ivARB OGL__glWindowPos3ivARB
#define glWindowPos3sARB  OGL__glWindowPos3sARB
#define glWindowPos3svARB OGL__glWindowPos3svARB

#endif // GL_ARB_window_pos

#endif // OPENGL_INCLUDE_GL_ARB_window_pos

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_KHR_blend_equation_advanced

#ifndef GL_KHR_blend_equation_advanced
#define GL_KHR_blend_equation_advanced 1

#define GL_MULTIPLY_KHR          0x9294
#define GL_SCREEN_KHR            0x9295
#define GL_OVERLAY_KHR           0x9296
#define GL_DARKEN_KHR            0x9297
#define GL_LIGHTEN_KHR           0x9298
#define GL_COLORDODGE_KHR        0x9299
#define GL_COLORBURN_KHR         0x929A
#define GL_HARDLIGHT_KHR         0x929B
#define GL_SOFTLIGHT_KHR         0x929C
#define GL_DIFFERENCE_KHR        0x929E
#define GL_EXCLUSION_KHR         0x92A0
#define GL_HSL_HUE_KHR           0x92AD
#define GL_HSL_SATURATION_KHR    0x92AE
#define GL_HSL_COLOR_KHR         0x92AF
#define GL_HSL_LUMINOSITY_KHR    0x92B0

OPENGL_INIT_PROC(glBlendBarrierKHR, void, void);
#define glBlendBarrierKHR OGL__glBlendBarrierKHR

#endif // GL_KHR_blend_equation_advanced

#endif // OPENGL_INCLUDE_GL_KHR_blend_equation_advanced

/* -------------------------------------------------------------------------- */

#ifndef GL_KHR_blend_equation_advanced_coherent
#define GL_KHR_blend_equation_advanced_coherent 1

#define GL_BLEND_ADVANCED_COHERENT_KHR    0x9285

#endif // GL_KHR_blend_equation_advanced_coherent

/* -------------------------------------------------------------------------- */

#ifndef GL_KHR_context_flush_control
#define GL_KHR_context_flush_control 1

#endif // GL_KHR_context_flush_control

/* -------------------------------------------------------------------------- */

#ifndef GL_KHR_debug
#define GL_KHR_debug 1

#endif // GL_KHR_debug

/* -------------------------------------------------------------------------- */

#ifndef GL_KHR_no_error
#define GL_KHR_no_error 1

#define GL_CONTEXT_FLAG_NO_ERROR_BIT_KHR    0x00000008

#endif // GL_KHR_no_error

/* -------------------------------------------------------------------------- */

#ifndef GL_KHR_parallel_shader_compile
#define GL_KHR_parallel_shader_compile 1

#define GL_MAX_SHADER_COMPILER_THREADS_KHR    0x91B0
#define GL_COMPLETION_STATUS_KHR              0x91B1

#endif // GL_KHR_parallel_shader_compile

/* -------------------------------------------------------------------------- */

#ifndef GL_KHR_robust_buffer_access_behavior
#define GL_KHR_robust_buffer_access_behavior 1

#endif // GL_KHR_robust_buffer_access_behavior

/* -------------------------------------------------------------------------- */

#ifndef GL_KHR_robustness
#define GL_KHR_robustness 1
#define GL_CONTEXT_ROBUST_ACCESS    0x90F3

#endif // GL_KHR_robustness

/* -------------------------------------------------------------------------- */

#ifndef GL_KHR_shader_subgroup
#define GL_KHR_shader_subgroup 1

#define GL_SUBGROUP_SIZE_KHR                            0x9532
#define GL_SUBGROUP_SUPPORTED_STAGES_KHR                0x9533
#define GL_SUBGROUP_SUPPORTED_FEATURES_KHR              0x9534
#define GL_SUBGROUP_QUAD_ALL_STAGES_KHR                 0x9535
#define GL_SUBGROUP_FEATURE_BASIC_BIT_KHR               0x00000001
#define GL_SUBGROUP_FEATURE_VOTE_BIT_KHR                0x00000002
#define GL_SUBGROUP_FEATURE_ARITHMETIC_BIT_KHR          0x00000004
#define GL_SUBGROUP_FEATURE_BALLOT_BIT_KHR              0x00000008
#define GL_SUBGROUP_FEATURE_SHUFFLE_BIT_KHR             0x00000010
#define GL_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT_KHR    0x00000020
#define GL_SUBGROUP_FEATURE_CLUSTERED_BIT_KHR           0x00000040
#define GL_SUBGROUP_FEATURE_QUAD_BIT_KHR                0x00000080

#endif // GL_KHR_shader_subgroup

/* -------------------------------------------------------------------------- */

#ifndef GL_KHR_texture_compression_astc_hdr
#define GL_KHR_texture_compression_astc_hdr 1

#define GL_COMPRESSED_RGBA_ASTC_4x4_KHR              0x93B0
#define GL_COMPRESSED_RGBA_ASTC_5x4_KHR              0x93B1
#define GL_COMPRESSED_RGBA_ASTC_5x5_KHR              0x93B2
#define GL_COMPRESSED_RGBA_ASTC_6x5_KHR              0x93B3
#define GL_COMPRESSED_RGBA_ASTC_6x6_KHR              0x93B4
#define GL_COMPRESSED_RGBA_ASTC_8x5_KHR              0x93B5
#define GL_COMPRESSED_RGBA_ASTC_8x6_KHR              0x93B6
#define GL_COMPRESSED_RGBA_ASTC_8x8_KHR              0x93B7
#define GL_COMPRESSED_RGBA_ASTC_10x5_KHR             0x93B8
#define GL_COMPRESSED_RGBA_ASTC_10x6_KHR             0x93B9
#define GL_COMPRESSED_RGBA_ASTC_10x8_KHR             0x93BA
#define GL_COMPRESSED_RGBA_ASTC_10x10_KHR            0x93BB
#define GL_COMPRESSED_RGBA_ASTC_12x10_KHR            0x93BC
#define GL_COMPRESSED_RGBA_ASTC_12x12_KHR            0x93BD
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_4x4_KHR      0x93D0
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x4_KHR      0x93D1
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_5x5_KHR      0x93D2
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x5_KHR      0x93D3
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_6x6_KHR      0x93D4
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x5_KHR      0x93D5
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x6_KHR      0x93D6
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_8x8_KHR      0x93D7
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x5_KHR     0x93D8
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x6_KHR     0x93D9
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x8_KHR     0x93DA
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_10x10_KHR    0x93DB
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x10_KHR    0x93DC
#define GL_COMPRESSED_SRGB8_ALPHA8_ASTC_12x12_KHR    0x93DD

#endif // GL_KHR_texture_compression_astc_hdr

/* -------------------------------------------------------------------------- */

#ifndef GL_KHR_texture_compression_astc_ldr
#define GL_KHR_texture_compression_astc_ldr 1

#endif // GL_KHR_texture_compression_astc_ldr

/* -------------------------------------------------------------------------- */

#ifndef GL_KHR_texture_compression_astc_sliced_3d
#define GL_KHR_texture_compression_astc_sliced_3d 1

#endif // GL_KHR_texture_compression_astc_sliced_3d

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_OES_byte_coordinates

#ifndef GL_OES_byte_coordinates
#define GL_OES_byte_coordinates 1

OPENGL_INIT_PROC(glMultiTexCoord1bOES,  void, GLenum texture, GLbyte s);
OPENGL_INIT_PROC(glMultiTexCoord1bvOES, void, GLenum texture, const GLbyte *coords);
OPENGL_INIT_PROC(glMultiTexCoord2bOES,  void, GLenum texture, GLbyte s, GLbyte t);
OPENGL_INIT_PROC(glMultiTexCoord2bvOES, void, GLenum texture, const GLbyte *coords);
OPENGL_INIT_PROC(glMultiTexCoord3bOES,  void, GLenum texture, GLbyte s, GLbyte t, GLbyte r);
OPENGL_INIT_PROC(glMultiTexCoord3bvOES, void, GLenum texture, const GLbyte *coords);
OPENGL_INIT_PROC(glMultiTexCoord4bOES,  void, GLenum texture, GLbyte s, GLbyte t, GLbyte r, GLbyte q);
OPENGL_INIT_PROC(glMultiTexCoord4bvOES, void, GLenum texture, const GLbyte *coords);
OPENGL_INIT_PROC(glTexCoord1bOES,       void, GLbyte s);
OPENGL_INIT_PROC(glTexCoord1bvOES,      void, const GLbyte *coords);
OPENGL_INIT_PROC(glTexCoord2bOES,       void, GLbyte s, GLbyte t);
OPENGL_INIT_PROC(glTexCoord2bvOES,      void, const GLbyte *coords);
OPENGL_INIT_PROC(glTexCoord3bOES,       void, GLbyte s, GLbyte t, GLbyte r);
OPENGL_INIT_PROC(glTexCoord3bvOES,      void, const GLbyte *coords);
OPENGL_INIT_PROC(glTexCoord4bOES,       void, GLbyte s, GLbyte t, GLbyte r, GLbyte q);
OPENGL_INIT_PROC(glTexCoord4bvOES,      void, const GLbyte *coords);
OPENGL_INIT_PROC(glVertex2bOES,         void, GLbyte x, GLbyte y);
OPENGL_INIT_PROC(glVertex2bvOES,        void, const GLbyte *coords);
OPENGL_INIT_PROC(glVertex3bOES,         void, GLbyte x, GLbyte y, GLbyte z);
OPENGL_INIT_PROC(glVertex3bvOES,        void, const GLbyte *coords);
OPENGL_INIT_PROC(glVertex4bOES,         void, GLbyte x, GLbyte y, GLbyte z, GLbyte w);
OPENGL_INIT_PROC(glVertex4bvOES,        void, const GLbyte *coords);

#define glMultiTexCoord1bOES  OGL__glMultiTexCoord1bOES
#define glMultiTexCoord1bvOES OGL__glMultiTexCoord1bvOES
#define glMultiTexCoord2bOES  OGL__glMultiTexCoord2bOES
#define glMultiTexCoord2bvOES OGL__glMultiTexCoord2bvOES
#define glMultiTexCoord3bOES  OGL__glMultiTexCoord3bOES
#define glMultiTexCoord3bvOES OGL__glMultiTexCoord3bvOES
#define glMultiTexCoord4bOES  OGL__glMultiTexCoord4bOES
#define glMultiTexCoord4bvOES OGL__glMultiTexCoord4bvOES
#define glTexCoord1bOES       OGL__glTexCoord1bOES
#define glTexCoord1bvOES      OGL__glTexCoord1bvOES
#define glTexCoord2bOES       OGL__glTexCoord2bOES
#define glTexCoord2bvOES      OGL__glTexCoord2bvOES
#define glTexCoord3bOES       OGL__glTexCoord3bOES
#define glTexCoord3bvOES      OGL__glTexCoord3bvOES
#define glTexCoord4bOES       OGL__glTexCoord4bOES
#define glTexCoord4bvOES      OGL__glTexCoord4bvOES
#define glVertex2bOES         OGL__glVertex2bOES
#define glVertex2bvOES        OGL__glVertex2bvOES
#define glVertex3bOES         OGL__glVertex3bOES
#define glVertex3bvOES        OGL__glVertex3bvOES
#define glVertex4bOES         OGL__glVertex4bOES
#define glVertex4bvOES        OGL__glVertex4bvOES

#endif // GL_OES_byte_coordinates

#endif // OPENGL_INCLUDE_GL_OES_byte_coordinates

/* -------------------------------------------------------------------------- */

#ifndef GL_OES_compressed_paletted_texture
#define GL_OES_compressed_paletted_texture 1

#define GL_PALETTE4_RGB8_OES        0x8B90
#define GL_PALETTE4_RGBA8_OES       0x8B91
#define GL_PALETTE4_R5_G6_B5_OES    0x8B92
#define GL_PALETTE4_RGBA4_OES       0x8B93
#define GL_PALETTE4_RGB5_A1_OES     0x8B94
#define GL_PALETTE8_RGB8_OES        0x8B95
#define GL_PALETTE8_RGBA8_OES       0x8B96
#define GL_PALETTE8_R5_G6_B5_OES    0x8B97
#define GL_PALETTE8_RGBA4_OES       0x8B98
#define GL_PALETTE8_RGB5_A1_OES     0x8B99

#endif // GL_OES_compressed_paletted_texture

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_OES_fixed_point

#ifndef GL_OES_fixed_point
#define GL_OES_fixed_point 1

#define GL_FIXED_OES    0x140C

OPENGL_INIT_PROC(glAlphaFuncxOES,                void, GLenum func, GLfixed ref);
OPENGL_INIT_PROC(glClearColorxOES,               void, GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
OPENGL_INIT_PROC(glClearDepthxOES,               void, GLfixed depth);
OPENGL_INIT_PROC(glClipPlanexOES,                void, GLenum plane, const GLfixed *equation);
OPENGL_INIT_PROC(glColor4xOES,                   void, GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
OPENGL_INIT_PROC(glDepthRangexOES,               void, GLfixed n, GLfixed f);
OPENGL_INIT_PROC(glFogxOES,                      void, GLenum pname, GLfixed param);
OPENGL_INIT_PROC(glFogxvOES,                     void, GLenum pname, const GLfixed *param);
OPENGL_INIT_PROC(glFrustumxOES,                  void, GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f);
OPENGL_INIT_PROC(glGetClipPlanexOES,             void, GLenum plane, GLfixed *equation);
OPENGL_INIT_PROC(glGetFixedvOES,                 void, GLenum pname, GLfixed *params);
OPENGL_INIT_PROC(glGetTexEnvxvOES,               void, GLenum target, GLenum pname, GLfixed *params);
OPENGL_INIT_PROC(glGetTexParameterxvOES,         void, GLenum target, GLenum pname, GLfixed *params);
OPENGL_INIT_PROC(glLightModelxOES,               void, GLenum pname, GLfixed param);
OPENGL_INIT_PROC(glLightModelxvOES,              void, GLenum pname, const GLfixed *param);
OPENGL_INIT_PROC(glLightxOES,                    void, GLenum light, GLenum pname, GLfixed param);
OPENGL_INIT_PROC(glLightxvOES,                   void, GLenum light, GLenum pname, const GLfixed *params);
OPENGL_INIT_PROC(glLineWidthxOES,                void, GLfixed width);
OPENGL_INIT_PROC(glLoadMatrixxOES,               void, const GLfixed *m);
OPENGL_INIT_PROC(glMaterialxOES,                 void, GLenum face, GLenum pname, GLfixed param);
OPENGL_INIT_PROC(glMaterialxvOES,                void, GLenum face, GLenum pname, const GLfixed *param);
OPENGL_INIT_PROC(glMultMatrixxOES,               void, const GLfixed *m);
OPENGL_INIT_PROC(glMultiTexCoord4xOES,           void, GLenum texture, GLfixed s, GLfixed t, GLfixed r, GLfixed q);
OPENGL_INIT_PROC(glNormal3xOES,                  void, GLfixed nx, GLfixed ny, GLfixed nz);
OPENGL_INIT_PROC(glOrthoxOES,                    void, GLfixed l, GLfixed r, GLfixed b, GLfixed t, GLfixed n, GLfixed f);
OPENGL_INIT_PROC(glPointParameterxvOES,          void, GLenum pname, const GLfixed *params);
OPENGL_INIT_PROC(glPointSizexOES,                void, GLfixed size);
OPENGL_INIT_PROC(glPolygonOffsetxOES,            void, GLfixed factor, GLfixed units);
OPENGL_INIT_PROC(glRotatexOES,                   void, GLfixed angle, GLfixed x, GLfixed y, GLfixed z);
OPENGL_INIT_PROC(glScalexOES,                    void, GLfixed x, GLfixed y, GLfixed z);
OPENGL_INIT_PROC(glTexEnvxOES,                   void, GLenum target, GLenum pname, GLfixed param);
OPENGL_INIT_PROC(glTexEnvxvOES,                  void, GLenum target, GLenum pname, const GLfixed *params);
OPENGL_INIT_PROC(glTexParameterxOES,             void, GLenum target, GLenum pname, GLfixed param);
OPENGL_INIT_PROC(glTexParameterxvOES,            void, GLenum target, GLenum pname, const GLfixed *params);
OPENGL_INIT_PROC(glTranslatexOES,                void, GLfixed x, GLfixed y, GLfixed z);
OPENGL_INIT_PROC(glAccumxOES,                    void, GLenum op, GLfixed value);
OPENGL_INIT_PROC(glBitmapxOES,                   void, GLsizei width, GLsizei height, GLfixed xorig, GLfixed yorig, GLfixed xmove, GLfixed ymove, const GLubyte *bitmap);
OPENGL_INIT_PROC(glBlendColorxOES,               void, GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
OPENGL_INIT_PROC(glClearAccumxOES,               void, GLfixed red, GLfixed green, GLfixed blue, GLfixed alpha);
OPENGL_INIT_PROC(glColor3xOES,                   void, GLfixed red, GLfixed green, GLfixed blue);
OPENGL_INIT_PROC(glColor3xvOES,                  void, const GLfixed *components);
OPENGL_INIT_PROC(glColor4xvOES,                  void, const GLfixed *components);
OPENGL_INIT_PROC(glConvolutionParameterxOES,     void, GLenum target, GLenum pname, GLfixed param);
OPENGL_INIT_PROC(glConvolutionParameterxvOES,    void, GLenum target, GLenum pname, const GLfixed *params);
OPENGL_INIT_PROC(glEvalCoord1xOES,               void, GLfixed u);
OPENGL_INIT_PROC(glEvalCoord1xvOES,              void, const GLfixed *coords);
OPENGL_INIT_PROC(glEvalCoord2xOES,               void, GLfixed u, GLfixed v);
OPENGL_INIT_PROC(glEvalCoord2xvOES,              void, const GLfixed *coords);
OPENGL_INIT_PROC(glFeedbackBufferxOES,           void, GLsizei n, GLenum type, const GLfixed *buffer);
OPENGL_INIT_PROC(glGetConvolutionParameterxvOES, void, GLenum target, GLenum pname, GLfixed *params);
OPENGL_INIT_PROC(glGetHistogramParameterxvOES,   void, GLenum target, GLenum pname, GLfixed *params);
OPENGL_INIT_PROC(glGetLightxOES,                 void, GLenum light, GLenum pname, GLfixed *params);
OPENGL_INIT_PROC(glGetMapxvOES,                  void, GLenum target, GLenum query, GLfixed *v);
OPENGL_INIT_PROC(glGetMaterialxOES,              void, GLenum face, GLenum pname, GLfixed param);
OPENGL_INIT_PROC(glGetPixelMapxv,                void, GLenum map, GLint size, GLfixed *values);
OPENGL_INIT_PROC(glGetTexGenxvOES,               void, GLenum coord, GLenum pname, GLfixed *params);
OPENGL_INIT_PROC(glGetTexLevelParameterxvOES,    void, GLenum target, GLint level, GLenum pname, GLfixed *params);
OPENGL_INIT_PROC(glIndexxOES,                    void, GLfixed component);
OPENGL_INIT_PROC(glIndexxvOES,                   void, const GLfixed *component);
OPENGL_INIT_PROC(glLoadTransposeMatrixxOES,      void, const GLfixed *m);
OPENGL_INIT_PROC(glMap1xOES,                     void, GLenum target, GLfixed u1, GLfixed u2, GLint stride, GLint order, GLfixed points);
OPENGL_INIT_PROC(glMap2xOES,                     void, GLenum target, GLfixed u1, GLfixed u2, GLint ustride, GLint uorder, GLfixed v1, GLfixed v2, GLint vstride, GLint vorder, GLfixed points);
OPENGL_INIT_PROC(glMapGrid1xOES,                 void, GLint n, GLfixed u1, GLfixed u2);
OPENGL_INIT_PROC(glMapGrid2xOES,                 void, GLint n, GLfixed u1, GLfixed u2, GLfixed v1, GLfixed v2);
OPENGL_INIT_PROC(glMultTransposeMatrixxOES,      void, const GLfixed *m);
OPENGL_INIT_PROC(glMultiTexCoord1xOES,           void, GLenum texture, GLfixed s);
OPENGL_INIT_PROC(glMultiTexCoord1xvOES,          void, GLenum texture, const GLfixed *coords);
OPENGL_INIT_PROC(glMultiTexCoord2xOES,           void, GLenum texture, GLfixed s, GLfixed t);
OPENGL_INIT_PROC(glMultiTexCoord2xvOES,          void, GLenum texture, const GLfixed *coords);
OPENGL_INIT_PROC(glMultiTexCoord3xOES,           void, GLenum texture, GLfixed s, GLfixed t, GLfixed r);
OPENGL_INIT_PROC(glMultiTexCoord3xvOES,          void, GLenum texture, const GLfixed *coords);
OPENGL_INIT_PROC(glMultiTexCoord4xvOES,          void, GLenum texture, const GLfixed *coords);
OPENGL_INIT_PROC(glNormal3xvOES,                 void, const GLfixed *coords);
OPENGL_INIT_PROC(glPassThroughxOES,              void, GLfixed token);
OPENGL_INIT_PROC(glPixelMapx,                    void, GLenum map, GLint size, const GLfixed *values);
OPENGL_INIT_PROC(glPixelStorex,                  void, GLenum pname, GLfixed param);
OPENGL_INIT_PROC(glPixelTransferxOES,            void, GLenum pname, GLfixed param);
OPENGL_INIT_PROC(glPixelZoomxOES,                void, GLfixed xfactor, GLfixed yfactor);
OPENGL_INIT_PROC(glPrioritizeTexturesxOES,       void, GLsizei n, const GLuint *textures, const GLfixed *priorities);
OPENGL_INIT_PROC(glRasterPos2xOES,               void, GLfixed x, GLfixed y);
OPENGL_INIT_PROC(glRasterPos2xvOES,              void, const GLfixed *coords);
OPENGL_INIT_PROC(glRasterPos3xOES,               void, GLfixed x, GLfixed y, GLfixed z);
OPENGL_INIT_PROC(glRasterPos3xvOES,              void, const GLfixed *coords);
OPENGL_INIT_PROC(glRasterPos4xOES,               void, GLfixed x, GLfixed y, GLfixed z, GLfixed w);
OPENGL_INIT_PROC(glRasterPos4xvOES,              void, const GLfixed *coords);
OPENGL_INIT_PROC(glRectxOES,                     void, GLfixed x1, GLfixed y1, GLfixed x2, GLfixed y2);
OPENGL_INIT_PROC(glRectxvOES,                    void, const GLfixed *v1, const GLfixed *v2);
OPENGL_INIT_PROC(glTexCoord1xOES,                void, GLfixed s);
OPENGL_INIT_PROC(glTexCoord1xvOES,               void, const GLfixed *coords);
OPENGL_INIT_PROC(glTexCoord2xOES,                void, GLfixed s, GLfixed t);
OPENGL_INIT_PROC(glTexCoord2xvOES,               void, const GLfixed *coords);
OPENGL_INIT_PROC(glTexCoord3xOES,                void, GLfixed s, GLfixed t, GLfixed r);
OPENGL_INIT_PROC(glTexCoord3xvOES,               void, const GLfixed *coords);
OPENGL_INIT_PROC(glTexCoord4xOES,                void, GLfixed s, GLfixed t, GLfixed r, GLfixed q);
OPENGL_INIT_PROC(glTexCoord4xvOES,               void, const GLfixed *coords);
OPENGL_INIT_PROC(glTexGenxOES,                   void, GLenum coord, GLenum pname, GLfixed param);
OPENGL_INIT_PROC(glTexGenxvOES,                  void, GLenum coord, GLenum pname, const GLfixed *params);
OPENGL_INIT_PROC(glVertex2xOES,                  void, GLfixed x);
OPENGL_INIT_PROC(glVertex2xvOES,                 void, const GLfixed *coords);
OPENGL_INIT_PROC(glVertex3xOES,                  void, GLfixed x, GLfixed y);
OPENGL_INIT_PROC(glVertex3xvOES,                 void, const GLfixed *coords);
OPENGL_INIT_PROC(glVertex4xOES,                  void, GLfixed x, GLfixed y, GLfixed z);
OPENGL_INIT_PROC(glVertex4xvOES,                 void, const GLfixed *coords);

#define glAlphaFuncxOES                OGL__glAlphaFuncxOES
#define glClearColorxOES               OGL__glClearColorxOES
#define glClearDepthxOES               OGL__glClearDepthxOES
#define glClipPlanexOES                OGL__glClipPlanexOES
#define glColor4xOES                   OGL__glColor4xOES
#define glDepthRangexOES               OGL__glDepthRangexOES
#define glFogxOES                      OGL__glFogxOES
#define glFogxvOES                     OGL__glFogxvOES
#define glFrustumxOES                  OGL__glFrustumxOES
#define glGetClipPlanexOES             OGL__glGetClipPlanexOES
#define glGetFixedvOES                 OGL__glGetFixedvOES
#define glGetTexEnvxvOES               OGL__glGetTexEnvxvOES
#define glGetTexParameterxvOES         OGL__glGetTexParameterxvOES
#define glLightModelxOES               OGL__glLightModelxOES
#define glLightModelxvOES              OGL__glLightModelxvOES
#define glLightxOES                    OGL__glLightxOES
#define glLightxvOES                   OGL__glLightxvOES
#define glLineWidthxOES                OGL__glLineWidthxOES
#define glLoadMatrixxOES               OGL__glLoadMatrixxOES
#define glMaterialxOES                 OGL__glMaterialxOES
#define glMaterialxvOES                OGL__glMaterialxvOES
#define glMultMatrixxOES               OGL__glMultMatrixxOES
#define glMultiTexCoord4xOES           OGL__glMultiTexCoord4xOES
#define glNormal3xOES                  OGL__glNormal3xOES
#define glOrthoxOES                    OGL__glOrthoxOES
#define glPointParameterxvOES          OGL__glPointParameterxvOES
#define glPointSizexOES                OGL__glPointSizexOES
#define glPolygonOffsetxOES            OGL__glPolygonOffsetxOES
#define glRotatexOES                   OGL__glRotatexOES
#define glScalexOES                    OGL__glScalexOES
#define glTexEnvxOES                   OGL__glTexEnvxOES
#define glTexEnvxvOES                  OGL__glTexEnvxvOES
#define glTexParameterxOES             OGL__glTexParameterxOES
#define glTexParameterxvOES            OGL__glTexParameterxvOES
#define glTranslatexOES                OGL__glTranslatexOES
#define glAccumxOES                    OGL__glAccumxOES
#define glBitmapxOES                   OGL__glBitmapxOES
#define glBlendColorxOES               OGL__glBlendColorxOES
#define glClearAccumxOES               OGL__glClearAccumxOES
#define glColor3xOES                   OGL__glColor3xOES
#define glColor3xvOES                  OGL__glColor3xvOES
#define glColor4xvOES                  OGL__glColor4xvOES
#define glConvolutionParameterxOES     OGL__glConvolutionParameterxOES
#define glConvolutionParameterxvOES    OGL__glConvolutionParameterxvOES
#define glEvalCoord1xOES               OGL__glEvalCoord1xOES
#define glEvalCoord1xvOES              OGL__glEvalCoord1xvOES
#define glEvalCoord2xOES               OGL__glEvalCoord2xOES
#define glEvalCoord2xvOES              OGL__glEvalCoord2xvOES
#define glFeedbackBufferxOES           OGL__glFeedbackBufferxOES
#define glGetConvolutionParameterxvOES OGL__glGetConvolutionParameterxvOES
#define glGetHistogramParameterxvOES   OGL__glGetHistogramParameterxvOES
#define glGetLightxOES                 OGL__glGetLightxOES
#define glGetMapxvOES                  OGL__glGetMapxvOES
#define glGetMaterialxOES              OGL__glGetMaterialxOES
#define glGetPixelMapxv                OGL__glGetPixelMapxv
#define glGetTexGenxvOES               OGL__glGetTexGenxvOES
#define glGetTexLevelParameterxvOES    OGL__glGetTexLevelParameterxvOES
#define glIndexxOES                    OGL__glIndexxOES
#define glIndexxvOES                   OGL__glIndexxvOES
#define glLoadTransposeMatrixxOES      OGL__glLoadTransposeMatrixxOES
#define glMap1xOES                     OGL__glMap1xOES
#define glMap2xOES                     OGL__glMap2xOES
#define glMapGrid1xOES                 OGL__glMapGrid1xOES
#define glMapGrid2xOES                 OGL__glMapGrid2xOES
#define glMultTransposeMatrixxOES      OGL__glMultTransposeMatrixxOES
#define glMultiTexCoord1xOES           OGL__glMultiTexCoord1xOES
#define glMultiTexCoord1xvOES          OGL__glMultiTexCoord1xvOES
#define glMultiTexCoord2xOES           OGL__glMultiTexCoord2xOES
#define glMultiTexCoord2xvOES          OGL__glMultiTexCoord2xvOES
#define glMultiTexCoord3xOES           OGL__glMultiTexCoord3xOES
#define glMultiTexCoord3xvOES          OGL__glMultiTexCoord3xvOES
#define glMultiTexCoord4xvOES          OGL__glMultiTexCoord4xvOES
#define glNormal3xvOES                 OGL__glNormal3xvOES
#define glPassThroughxOES              OGL__glPassThroughxOES
#define glPixelMapx                    OGL__glPixelMapx
#define glPixelStorex                  OGL__glPixelStorex
#define glPixelTransferxOES            OGL__glPixelTransferxOES
#define glPixelZoomxOES                OGL__glPixelZoomxOES
#define glPrioritizeTexturesxOES       OGL__glPrioritizeTexturesxOES
#define glRasterPos2xOES               OGL__glRasterPos2xOES
#define glRasterPos2xvOES              OGL__glRasterPos2xvOES
#define glRasterPos3xOES               OGL__glRasterPos3xOES
#define glRasterPos3xvOES              OGL__glRasterPos3xvOES
#define glRasterPos4xOES               OGL__glRasterPos4xOES
#define glRasterPos4xvOES              OGL__glRasterPos4xvOES
#define glRectxOES                     OGL__glRectxOES
#define glRectxvOES                    OGL__glRectxvOES
#define glTexCoord1xOES                OGL__glTexCoord1xOES
#define glTexCoord1xvOES               OGL__glTexCoord1xvOES
#define glTexCoord2xOES                OGL__glTexCoord2xOES
#define glTexCoord2xvOES               OGL__glTexCoord2xvOES
#define glTexCoord3xOES                OGL__glTexCoord3xOES
#define glTexCoord3xvOES               OGL__glTexCoord3xvOES
#define glTexCoord4xOES                OGL__glTexCoord4xOES
#define glTexCoord4xvOES               OGL__glTexCoord4xvOES
#define glTexGenxOES                   OGL__glTexGenxOES
#define glTexGenxvOES                  OGL__glTexGenxvOES
#define glVertex2xOES                  OGL__glVertex2xOES
#define glVertex2xvOES                 OGL__glVertex2xvOES
#define glVertex3xOES                  OGL__glVertex3xOES
#define glVertex3xvOES                 OGL__glVertex3xvOES
#define glVertex4xOES                  OGL__glVertex4xOES
#define glVertex4xvOES                 OGL__glVertex4xvOES

#endif // GL_OES_fixed_point

#endif // OPENGL_INCLUDE_GL_OES_fixed_point

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_OES_query_matrix

#ifndef GL_OES_query_matrix
#define GL_OES_query_matrix 1

OPENGL_INIT_PROC(glQueryMatrixxOES, GLbitfield, GLfixed *mantissa, GLint *exponent);
#define glQueryMatrixxOES OGL__glQueryMatrixxOES

#endif // GL_OES_query_matrix

#endif // OPENGL_INCLUDE_GL_OES_query_matrix

/* -------------------------------------------------------------------------- */

#ifndef GL_OES_read_format
#define GL_OES_read_format 1

#define GL_IMPLEMENTATION_COLOR_READ_TYPE_OES      0x8B9A
#define GL_IMPLEMENTATION_COLOR_READ_FORMAT_OES    0x8B9B

#endif // GL_OES_read_format

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_OES_single_precision

#ifndef GL_OES_single_precision
#define GL_OES_single_precision 1

OPENGL_INIT_PROC(glClearDepthfOES,   void, GLclampf depth);
OPENGL_INIT_PROC(glClipPlanefOES,    void, GLenum plane, const GLfloat *equation);
OPENGL_INIT_PROC(glDepthRangefOES,   void, GLclampf n, GLclampf f);
OPENGL_INIT_PROC(glFrustumfOES,      void, GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);
OPENGL_INIT_PROC(glGetClipPlanefOES, void, GLenum plane, GLfloat *equation);
OPENGL_INIT_PROC(glOrthofOES,        void, GLfloat l, GLfloat r, GLfloat b, GLfloat t, GLfloat n, GLfloat f);

#define glClearDepthfOES   OGL__glClearDepthfOES
#define glClipPlanefOES    OGL__glClipPlanefOES
#define glDepthRangefOES   OGL__glDepthRangefOES
#define glFrustumfOES      OGL__glFrustumfOES
#define glGetClipPlanefOES OGL__glGetClipPlanefOES
#define glOrthofOES        OGL__glOrthofOES

#endif // GL_OES_single_precision

#endif // OPENGL_INCLUDE_GL_OES_single_precision

/* -------------------------------------------------------------------------- */

#ifndef GL_3DFX_multisample
#define GL_3DFX_multisample 1

#define GL_MULTISAMPLE_3DFX        0x86B2
#define GL_SAMPLE_BUFFERS_3DFX     0x86B3
#define GL_SAMPLES_3DFX            0x86B4
#define GL_MULTISAMPLE_BIT_3DFX    0x20000000

#endif // GL_3DFX_multisample

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_3DFX_tbuffer

#ifndef GL_3DFX_tbuffer
#define GL_3DFX_tbuffer 1

OPENGL_INIT_PROC(glTbufferMask3DFX, void, GLuint mask);
#define glTbufferMask3DFX OGL__glTbufferMask3DFX

#endif // GL_3DFX_tbuffer

#endif // OPENGL_INCLUDE_GL_3DFX_tbuffer

/* -------------------------------------------------------------------------- */

#ifndef GL_3DFX_texture_compression_FXT1
#define GL_3DFX_texture_compression_FXT1 1

#define GL_COMPRESSED_RGB_FXT1_3DFX     0x86B0
#define GL_COMPRESSED_RGBA_FXT1_3DFX    0x86B1

#endif // GL_3DFX_texture_compression_FXT1

/* -------------------------------------------------------------------------- */

#ifndef GL_AMD_blend_minmax_factor
#define GL_AMD_blend_minmax_factor 1

#define GL_FACTOR_MIN_AMD    0x901C
#define GL_FACTOR_MAX_AMD    0x901D

#endif // GL_AMD_blend_minmax_factor

/* -------------------------------------------------------------------------- */

#ifndef GL_AMD_conservative_depth
#define GL_AMD_conservative_depth 1

#endif // GL_AMD_conservative_depth

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_AMD_debug_output

#ifndef GL_AMD_debug_output
#define GL_AMD_debug_output 1

#define GL_MAX_DEBUG_MESSAGE_LENGTH_AMD             0x9143
#define GL_MAX_DEBUG_LOGGED_MESSAGES_AMD            0x9144
#define GL_DEBUG_LOGGED_MESSAGES_AMD                0x9145
#define GL_DEBUG_SEVERITY_HIGH_AMD                  0x9146
#define GL_DEBUG_SEVERITY_MEDIUM_AMD                0x9147
#define GL_DEBUG_SEVERITY_LOW_AMD                   0x9148
#define GL_DEBUG_CATEGORY_API_ERROR_AMD             0x9149
#define GL_DEBUG_CATEGORY_WINDOW_SYSTEM_AMD         0x914A
#define GL_DEBUG_CATEGORY_DEPRECATION_AMD           0x914B
#define GL_DEBUG_CATEGORY_UNDEFINED_BEHAVIOR_AMD    0x914C
#define GL_DEBUG_CATEGORY_PERFORMANCE_AMD           0x914D
#define GL_DEBUG_CATEGORY_SHADER_COMPILER_AMD       0x914E
#define GL_DEBUG_CATEGORY_APPLICATION_AMD           0x914F
#define GL_DEBUG_CATEGORY_OTHER_AMD                 0x9150

OPENGL_INIT_PROC(glDebugMessageEnableAMD,   void,   GLenum category, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
OPENGL_INIT_PROC(glDebugMessageInsertAMD,   void,   GLenum category, GLenum severity, GLuint id, GLsizei length, const GLchar *buf);
OPENGL_INIT_PROC(glDebugMessageCallbackAMD, void,   GLDEBUGPROCAMD callback, void *userParam);
OPENGL_INIT_PROC(glGetDebugMessageLogAMD,   GLuint, GLuint count, GLsizei bufsize, GLenum *categories, GLuint *severities, GLuint *ids, GLsizei *lengths, GLchar *message);

#define glDebugMessageEnableAMD   OGL__glDebugMessageEnableAMD
#define glDebugMessageInsertAMD   OGL__glDebugMessageInsertAMD
#define glDebugMessageCallbackAMD OGL__glDebugMessageCallbackAMD
#define glGetDebugMessageLogAMD   OGL__glGetDebugMessageLogAMD

#endif // GL_AMD_debug_output

#endif // OPENGL_INCLUDE_GL_AMD_debug_output

/* -------------------------------------------------------------------------- */

#ifndef GL_AMD_depth_clamp_separate
#define GL_AMD_depth_clamp_separate 1

#define GL_DEPTH_CLAMP_NEAR_AMD    0x901E
#define GL_DEPTH_CLAMP_FAR_AMD     0x901F

#endif // GL_AMD_depth_clamp_separate

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_AMD_draw_buffers_blend

#ifndef GL_AMD_draw_buffers_blend
#define GL_AMD_draw_buffers_blend 1

OPENGL_INIT_PROC(glBlendFuncIndexedAMD,             void, GLuint buf, GLenum src, GLenum dst);
OPENGL_INIT_PROC(glBlendFuncSeparateIndexedAMD,     void, GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
OPENGL_INIT_PROC(glBlendEquationIndexedAMD,         void, GLuint buf, GLenum mode);
OPENGL_INIT_PROC(glBlendEquationSeparateIndexedAMD, void, GLuint buf, GLenum modeRGB, GLenum modeAlpha);

#define glBlendFuncIndexedAMD             OGL__glBlendFuncIndexedAMD
#define glBlendFuncSeparateIndexedAMD     OGL__glBlendFuncSeparateIndexedAMD
#define glBlendEquationIndexedAMD         OGL__glBlendEquationIndexedAMD
#define glBlendEquationSeparateIndexedAMD OGL__glBlendEquationSeparateIndexedAMD

#endif // GL_AMD_draw_buffers_blend

#endif // OPENGL_INCLUDE_GL_AMD_draw_buffers_blend

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_AMD_framebuffer_multisample_advanced

#ifndef GL_AMD_framebuffer_multisample_advanced
#define GL_AMD_framebuffer_multisample_advanced 1

#define GL_RENDERBUFFER_STORAGE_SAMPLES_AMD             0x91B2
#define GL_MAX_COLOR_FRAMEBUFFER_SAMPLES_AMD            0x91B3
#define GL_MAX_COLOR_FRAMEBUFFER_STORAGE_SAMPLES_AMD    0x91B4
#define GL_MAX_DEPTH_STENCIL_FRAMEBUFFER_SAMPLES_AMD    0x91B5
#define GL_NUM_SUPPORTED_MULTISAMPLE_MODES_AMD          0x91B6
#define GL_SUPPORTED_MULTISAMPLE_MODES_AMD              0x91B7

OPENGL_INIT_PROC(glRenderbufferStorageMultisampleAdvancedAMD,      void, GLenum target, GLsizei samples, GLsizei storageSamples, GLenum internalformat, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glNamedRenderbufferStorageMultisampleAdvancedAMD, void, GLuint renderbuffer, GLsizei samples, GLsizei storageSamples, GLenum internalformat, GLsizei width, GLsizei height);

#define glRenderbufferStorageMultisampleAdvancedAMD      OGL__glRenderbufferStorageMultisampleAdvancedAMD
#define glNamedRenderbufferStorageMultisampleAdvancedAMD OGL__glNamedRenderbufferStorageMultisampleAdvancedAMD

#endif // GL_AMD_framebuffer_multisample_advanced

#endif // OPENGL_INCLUDE_GL_AMD_framebuffer_multisample_advanced

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_AMD_framebuffer_sample_positions

#ifndef GL_AMD_framebuffer_sample_positions
#define GL_AMD_framebuffer_sample_positions 1

#define GL_SUBSAMPLE_DISTANCE_AMD             0x883F
#define GL_PIXELS_PER_SAMPLE_PATTERN_X_AMD    0x91AE
#define GL_PIXELS_PER_SAMPLE_PATTERN_Y_AMD    0x91AF
#define GL_ALL_PIXELS_AMD                     0xFFFFFFFF

OPENGL_INIT_PROC(glFramebufferSamplePositionsfvAMD,      void, GLenum target, GLuint numsamples, GLuint pixelindex, const GLfloat *values);
OPENGL_INIT_PROC(glNamedFramebufferSamplePositionsfvAMD, void, GLuint framebuffer, GLuint numsamples, GLuint pixelindex, const GLfloat *values);
OPENGL_INIT_PROC(glGetFramebufferParameterfvAMD,         void, GLenum target, GLenum pname, GLuint numsamples, GLuint pixelindex, GLsizei size, GLfloat *values);
OPENGL_INIT_PROC(glGetNamedFramebufferParameterfvAMD,    void, GLuint framebuffer, GLenum pname, GLuint numsamples, GLuint pixelindex, GLsizei size, GLfloat *values);

#define glFramebufferSamplePositionsfvAMD      OGL__glFramebufferSamplePositionsfvAMD
#define glNamedFramebufferSamplePositionsfvAMD OGL__glNamedFramebufferSamplePositionsfvAMD
#define glGetFramebufferParameterfvAMD         OGL__glGetFramebufferParameterfvAMD
#define glGetNamedFramebufferParameterfvAMD    OGL__glGetNamedFramebufferParameterfvAMD

#endif // GL_AMD_framebuffer_sample_positions

#endif // OPENGL_INCLUDE_GL_AMD_framebuffer_sample_positions

/* -------------------------------------------------------------------------- */

#ifndef GL_AMD_gcn_shader
#define GL_AMD_gcn_shader 1

#endif // GL_AMD_gcn_shader

/* -------------------------------------------------------------------------- */

#ifndef GL_AMD_gpu_shader_half_float
#define GL_AMD_gpu_shader_half_float 1

#define GL_FLOAT16_NV            0x8FF8
#define GL_FLOAT16_VEC2_NV       0x8FF9
#define GL_FLOAT16_VEC3_NV       0x8FFA
#define GL_FLOAT16_VEC4_NV       0x8FFB
#define GL_FLOAT16_MAT2_AMD      0x91C5
#define GL_FLOAT16_MAT3_AMD      0x91C6
#define GL_FLOAT16_MAT4_AMD      0x91C7
#define GL_FLOAT16_MAT2x3_AMD    0x91C8
#define GL_FLOAT16_MAT2x4_AMD    0x91C9
#define GL_FLOAT16_MAT3x2_AMD    0x91CA
#define GL_FLOAT16_MAT3x4_AMD    0x91CB
#define GL_FLOAT16_MAT4x2_AMD    0x91CC
#define GL_FLOAT16_MAT4x3_AMD    0x91CD

#endif // GL_AMD_gpu_shader_half_float

/* -------------------------------------------------------------------------- */

#ifndef GL_AMD_gpu_shader_int16
#define GL_AMD_gpu_shader_int16 1

#endif // GL_AMD_gpu_shader_int16

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_AMD_gpu_shader_int64

#ifndef GL_AMD_gpu_shader_int64
#define GL_AMD_gpu_shader_int64 1

#define GL_INT64_NV                  0x140E
#define GL_UNSIGNED_INT64_NV         0x140F
#define GL_INT8_NV                   0x8FE0
#define GL_INT8_VEC2_NV              0x8FE1
#define GL_INT8_VEC3_NV              0x8FE2
#define GL_INT8_VEC4_NV              0x8FE3
#define GL_INT16_NV                  0x8FE4
#define GL_INT16_VEC2_NV             0x8FE5
#define GL_INT16_VEC3_NV             0x8FE6
#define GL_INT16_VEC4_NV             0x8FE7
#define GL_INT64_VEC2_NV             0x8FE9
#define GL_INT64_VEC3_NV             0x8FEA
#define GL_INT64_VEC4_NV             0x8FEB
#define GL_UNSIGNED_INT8_NV          0x8FEC
#define GL_UNSIGNED_INT8_VEC2_NV     0x8FED
#define GL_UNSIGNED_INT8_VEC3_NV     0x8FEE
#define GL_UNSIGNED_INT8_VEC4_NV     0x8FEF
#define GL_UNSIGNED_INT16_NV         0x8FF0
#define GL_UNSIGNED_INT16_VEC2_NV    0x8FF1
#define GL_UNSIGNED_INT16_VEC3_NV    0x8FF2
#define GL_UNSIGNED_INT16_VEC4_NV    0x8FF3
#define GL_UNSIGNED_INT64_VEC2_NV    0x8FF5
#define GL_UNSIGNED_INT64_VEC3_NV    0x8FF6
#define GL_UNSIGNED_INT64_VEC4_NV    0x8FF7

OPENGL_INIT_PROC(glUniform1i64NV,          void, GLint location, GLint64EXT x);
OPENGL_INIT_PROC(glUniform2i64NV,          void, GLint location, GLint64EXT x, GLint64EXT y);
OPENGL_INIT_PROC(glUniform3i64NV,          void, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
OPENGL_INIT_PROC(glUniform4i64NV,          void, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
OPENGL_INIT_PROC(glUniform1i64vNV,         void, GLint location, GLsizei count, const GLint64EXT *value);
OPENGL_INIT_PROC(glUniform2i64vNV,         void, GLint location, GLsizei count, const GLint64EXT *value);
OPENGL_INIT_PROC(glUniform3i64vNV,         void, GLint location, GLsizei count, const GLint64EXT *value);
OPENGL_INIT_PROC(glUniform4i64vNV,         void, GLint location, GLsizei count, const GLint64EXT *value);
OPENGL_INIT_PROC(glUniform1ui64NV,         void, GLint location, GLuint64EXT x);
OPENGL_INIT_PROC(glUniform2ui64NV,         void, GLint location, GLuint64EXT x, GLuint64EXT y);
OPENGL_INIT_PROC(glUniform3ui64NV,         void, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
OPENGL_INIT_PROC(glUniform4ui64NV,         void, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
OPENGL_INIT_PROC(glUniform1ui64vNV,        void, GLint location, GLsizei count, const GLuint64EXT *value);
OPENGL_INIT_PROC(glUniform2ui64vNV,        void, GLint location, GLsizei count, const GLuint64EXT *value);
OPENGL_INIT_PROC(glUniform3ui64vNV,        void, GLint location, GLsizei count, const GLuint64EXT *value);
OPENGL_INIT_PROC(glUniform4ui64vNV,        void, GLint location, GLsizei count, const GLuint64EXT *value);
OPENGL_INIT_PROC(glGetUniformi64vNV,       void, GLuint program, GLint location, GLint64EXT *params);
OPENGL_INIT_PROC(glGetUniformui64vNV,      void, GLuint program, GLint location, GLuint64EXT *params);
OPENGL_INIT_PROC(glProgramUniform1i64NV,   void, GLuint program, GLint location, GLint64EXT x);
OPENGL_INIT_PROC(glProgramUniform2i64NV,   void, GLuint program, GLint location, GLint64EXT x, GLint64EXT y);
OPENGL_INIT_PROC(glProgramUniform3i64NV,   void, GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z);
OPENGL_INIT_PROC(glProgramUniform4i64NV,   void, GLuint program, GLint location, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
OPENGL_INIT_PROC(glProgramUniform1i64vNV,  void, GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
OPENGL_INIT_PROC(glProgramUniform2i64vNV,  void, GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
OPENGL_INIT_PROC(glProgramUniform3i64vNV,  void, GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
OPENGL_INIT_PROC(glProgramUniform4i64vNV,  void, GLuint program, GLint location, GLsizei count, const GLint64EXT *value);
OPENGL_INIT_PROC(glProgramUniform1ui64NV,  void, GLuint program, GLint location, GLuint64EXT x);
OPENGL_INIT_PROC(glProgramUniform2ui64NV,  void, GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y);
OPENGL_INIT_PROC(glProgramUniform3ui64NV,  void, GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
OPENGL_INIT_PROC(glProgramUniform4ui64NV,  void, GLuint program, GLint location, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
OPENGL_INIT_PROC(glProgramUniform1ui64vNV, void, GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
OPENGL_INIT_PROC(glProgramUniform2ui64vNV, void, GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
OPENGL_INIT_PROC(glProgramUniform3ui64vNV, void, GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);
OPENGL_INIT_PROC(glProgramUniform4ui64vNV, void, GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);

#define glUniform1i64NV          OGL__glUniform1i64NV
#define glUniform2i64NV          OGL__glUniform2i64NV
#define glUniform3i64NV          OGL__glUniform3i64NV
#define glUniform4i64NV          OGL__glUniform4i64NV
#define glUniform1i64vNV         OGL__glUniform1i64vNV
#define glUniform2i64vNV         OGL__glUniform2i64vNV
#define glUniform3i64vNV         OGL__glUniform3i64vNV
#define glUniform4i64vNV         OGL__glUniform4i64vNV
#define glUniform1ui64NV         OGL__glUniform1ui64NV
#define glUniform2ui64NV         OGL__glUniform2ui64NV
#define glUniform3ui64NV         OGL__glUniform3ui64NV
#define glUniform4ui64NV         OGL__glUniform4ui64NV
#define glUniform1ui64vNV        OGL__glUniform1ui64vNV
#define glUniform2ui64vNV        OGL__glUniform2ui64vNV
#define glUniform3ui64vNV        OGL__glUniform3ui64vNV
#define glUniform4ui64vNV        OGL__glUniform4ui64vNV
#define glGetUniformi64vNV       OGL__glGetUniformi64vNV
#define glGetUniformui64vNV      OGL__glGetUniformui64vNV
#define glProgramUniform1i64NV   OGL__glProgramUniform1i64NV
#define glProgramUniform2i64NV   OGL__glProgramUniform2i64NV
#define glProgramUniform3i64NV   OGL__glProgramUniform3i64NV
#define glProgramUniform4i64NV   OGL__glProgramUniform4i64NV
#define glProgramUniform1i64vNV  OGL__glProgramUniform1i64vNV
#define glProgramUniform2i64vNV  OGL__glProgramUniform2i64vNV
#define glProgramUniform3i64vNV  OGL__glProgramUniform3i64vNV
#define glProgramUniform4i64vNV  OGL__glProgramUniform4i64vNV
#define glProgramUniform1ui64NV  OGL__glProgramUniform1ui64NV
#define glProgramUniform2ui64NV  OGL__glProgramUniform2ui64NV
#define glProgramUniform3ui64NV  OGL__glProgramUniform3ui64NV
#define glProgramUniform4ui64NV  OGL__glProgramUniform4ui64NV
#define glProgramUniform1ui64vNV OGL__glProgramUniform1ui64vNV
#define glProgramUniform2ui64vNV OGL__glProgramUniform2ui64vNV
#define glProgramUniform3ui64vNV OGL__glProgramUniform3ui64vNV
#define glProgramUniform4ui64vNV OGL__glProgramUniform4ui64vNV

#endif // GL_AMD_gpu_shader_int64

#endif // OPENGL_INCLUDE_GL_AMD_gpu_shader_int64

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_AMD_interleaved_elements

#ifndef GL_AMD_interleaved_elements
#define GL_AMD_interleaved_elements 1

#define GL_VERTEX_ELEMENT_SWIZZLE_AMD    0x91A4
#define GL_VERTEX_ID_SWIZZLE_AMD         0x91A5

OPENGL_INIT_PROC(glVertexAttribParameteriAMD, void, GLuint index, GLenum pname, GLint param);
#define glVertexAttribParameteriAMD OGL__glVertexAttribParameteriAMD

#endif // GL_AMD_interleaved_elements

#endif // OPENGL_INCLUDE_GL_AMD_interleaved_elements

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_AMD_multi_draw_indirect

#ifndef GL_AMD_multi_draw_indirect
#define GL_AMD_multi_draw_indirect 1

OPENGL_INIT_PROC(glMultiDrawArraysIndirectAMD,   void, GLenum mode, const void *indirect, GLsizei primcount, GLsizei stride);
OPENGL_INIT_PROC(glMultiDrawElementsIndirectAMD, void, GLenum mode, GLenum type, const void *indirect, GLsizei primcount, GLsizei stride);

#define glMultiDrawArraysIndirectAMD   OGL__glMultiDrawArraysIndirectAMD
#define glMultiDrawElementsIndirectAMD OGL__glMultiDrawElementsIndirectAMD

#endif // GL_AMD_multi_draw_indirect

#endif // OPENGL_INCLUDE_GL_AMD_multi_draw_indirect

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_AMD_name_gen_delete

#ifndef GL_AMD_name_gen_delete
#define GL_AMD_name_gen_delete 1

#define GL_DATA_BUFFER_AMD            0x9151
#define GL_PERFORMANCE_MONITOR_AMD    0x9152
#define GL_QUERY_OBJECT_AMD           0x9153
#define GL_VERTEX_ARRAY_OBJECT_AMD    0x9154
#define GL_SAMPLER_OBJECT_AMD         0x9155

OPENGL_INIT_PROC(glGenNamesAMD,    void,      GLenum identifier, GLuint num, GLuint *names);
OPENGL_INIT_PROC(glDeleteNamesAMD, void,      GLenum identifier, GLuint num, const GLuint *names);
OPENGL_INIT_PROC(glIsNameAMD,      GLboolean, GLenum identifier, GLuint name);

#define glGenNamesAMD    OGL__glGenNamesAMD
#define glDeleteNamesAMD OGL__glDeleteNamesAMD
#define glIsNameAMD      OGL__glIsNameAMD

#endif // GL_AMD_name_gen_delete

#endif // OPENGL_INCLUDE_GL_AMD_name_gen_delete

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_AMD_occlusion_query_event

#ifndef GL_AMD_occlusion_query_event
#define GL_AMD_occlusion_query_event 1

#define GL_OCCLUSION_QUERY_EVENT_MASK_AMD        0x874F
#define GL_QUERY_DEPTH_PASS_EVENT_BIT_AMD        0x00000001
#define GL_QUERY_DEPTH_FAIL_EVENT_BIT_AMD        0x00000002
#define GL_QUERY_STENCIL_FAIL_EVENT_BIT_AMD      0x00000004
#define GL_QUERY_DEPTH_BOUNDS_FAIL_EVENT_BIT_AMD 0x00000008
#define GL_QUERY_ALL_EVENT_BITS_AMD              0xFFFFFFFF

OPENGL_INIT_PROC(glQueryObjectParameteruiAMD, void, GLenum target, GLuint id, GLenum pname, GLuint param);
#define glQueryObjectParameteruiAMD OGL__glQueryObjectParameteruiAMD

#endif // GL_AMD_occlusion_query_event

#endif // OPENGL_INCLUDE_GL_AMD_occlusion_query_event

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_AMD_performance_monitor

#ifndef GL_AMD_performance_monitor
#define GL_AMD_performance_monitor 1

#define GL_COUNTER_TYPE_AMD                0x8BC0
#define GL_COUNTER_RANGE_AMD               0x8BC1
#define GL_UNSIGNED_INT64_AMD              0x8BC2
#define GL_PERCENTAGE_AMD                  0x8BC3
#define GL_PERFMON_RESULT_AVAILABLE_AMD    0x8BC4
#define GL_PERFMON_RESULT_SIZE_AMD         0x8BC5
#define GL_PERFMON_RESULT_AMD              0x8BC6

OPENGL_INIT_PROC(glGetPerfMonitorGroupsAMD,        void, GLint *numGroups, GLsizei groupsSize, GLuint *groups);
OPENGL_INIT_PROC(glGetPerfMonitorCountersAMD,      void, GLuint group, GLint *numCounters, GLint *maxActiveCounters, GLsizei counterSize, GLuint *counters);
OPENGL_INIT_PROC(glGetPerfMonitorGroupStringAMD,   void, GLuint group, GLsizei bufSize, GLsizei *length, GLchar *groupString);
OPENGL_INIT_PROC(glGetPerfMonitorCounterStringAMD, void, GLuint group, GLuint counter, GLsizei bufSize, GLsizei *length, GLchar *counterString);
OPENGL_INIT_PROC(glGetPerfMonitorCounterInfoAMD,   void, GLuint group, GLuint counter, GLenum pname, void *data);
OPENGL_INIT_PROC(glGenPerfMonitorsAMD,             void, GLsizei n, GLuint *monitors);
OPENGL_INIT_PROC(glDeletePerfMonitorsAMD,          void, GLsizei n, GLuint *monitors);
OPENGL_INIT_PROC(glSelectPerfMonitorCountersAMD,   void, GLuint monitor, GLboolean enable, GLuint group, GLint numCounters, GLuint *counterList);
OPENGL_INIT_PROC(glBeginPerfMonitorAMD,            void, GLuint monitor);
OPENGL_INIT_PROC(glEndPerfMonitorAMD,              void, GLuint monitor);
OPENGL_INIT_PROC(glGetPerfMonitorCounterDataAMD,   void, GLuint monitor, GLenum pname, GLsizei dataSize, GLuint *data, GLint *bytesWritten);

#define glGetPerfMonitorGroupsAMD        OGL__glGetPerfMonitorGroupsAMD
#define glGetPerfMonitorCountersAMD      OGL__glGetPerfMonitorCountersAMD
#define glGetPerfMonitorGroupStringAMD   OGL__glGetPerfMonitorGroupStringAMD
#define glGetPerfMonitorCounterStringAMD OGL__glGetPerfMonitorCounterStringAMD
#define glGetPerfMonitorCounterInfoAMD   OGL__glGetPerfMonitorCounterInfoAMD
#define glGenPerfMonitorsAMD             OGL__glGenPerfMonitorsAMD
#define glDeletePerfMonitorsAMD          OGL__glDeletePerfMonitorsAMD
#define glSelectPerfMonitorCountersAMD   OGL__glSelectPerfMonitorCountersAMD
#define glBeginPerfMonitorAMD            OGL__glBeginPerfMonitorAMD
#define glEndPerfMonitorAMD              OGL__glEndPerfMonitorAMD
#define glGetPerfMonitorCounterDataAMD   OGL__glGetPerfMonitorCounterDataAMD

#endif // GL_AMD_performance_monitor

#endif // OPENGL_INCLUDE_GL_AMD_performance_monitor

/* -------------------------------------------------------------------------- */

#ifndef GL_AMD_pinned_memory
#define GL_AMD_pinned_memory 1

#define GL_EXTERNAL_VIRTUAL_MEMORY_BUFFER_AMD    0x9160

#endif // GL_AMD_pinned_memory

/* -------------------------------------------------------------------------- */

#ifndef GL_AMD_query_buffer_object
#define GL_AMD_query_buffer_object 1

#define GL_QUERY_BUFFER_AMD            0x9192
#define GL_QUERY_BUFFER_BINDING_AMD    0x9193
#define GL_QUERY_RESULT_NO_WAIT_AMD    0x9194

#endif // GL_AMD_query_buffer_object

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_AMD_sample_positions

#ifndef GL_AMD_sample_positions
#define GL_AMD_sample_positions 1

OPENGL_INIT_PROC(glSetMultisamplefvAMD, void, GLenum pname, GLuint index, const GLfloat *val);
#define glSetMultisamplefvAMD OGL__glSetMultisamplefvAMD

#endif // GL_AMD_sample_positions

#endif // OPENGL_INCLUDE_GL_AMD_sample_positions

/* -------------------------------------------------------------------------- */

#ifndef GL_AMD_seamless_cubemap_per_texture
#define GL_AMD_seamless_cubemap_per_texture 1

#endif // GL_AMD_seamless_cubemap_per_texture

/* -------------------------------------------------------------------------- */

#ifndef GL_AMD_shader_atomic_counter_ops
#define GL_AMD_shader_atomic_counter_ops 1

#endif // GL_AMD_shader_atomic_counter_ops

/* -------------------------------------------------------------------------- */

#ifndef GL_AMD_shader_ballot
#define GL_AMD_shader_ballot 1

#endif // GL_AMD_shader_ballot

/* -------------------------------------------------------------------------- */

#ifndef GL_AMD_shader_explicit_vertex_parameter
#define GL_AMD_shader_explicit_vertex_parameter 1

#endif // GL_AMD_shader_explicit_vertex_parameter

/* -------------------------------------------------------------------------- */

#ifndef GL_AMD_shader_gpu_shader_half_float_fetch
#define GL_AMD_shader_gpu_shader_half_float_fetch 1

#endif // GL_AMD_shader_gpu_shader_half_float_fetch

/* -------------------------------------------------------------------------- */

#ifndef GL_AMD_shader_image_load_store_lod
#define GL_AMD_shader_image_load_store_lod 1

#endif // GL_AMD_shader_image_load_store_lod

/* -------------------------------------------------------------------------- */

#ifndef GL_AMD_shader_stencil_export
#define GL_AMD_shader_stencil_export 1

#endif // GL_AMD_shader_stencil_export

/* -------------------------------------------------------------------------- */

#ifndef GL_AMD_shader_trinary_minmax
#define GL_AMD_shader_trinary_minmax 1

#endif // GL_AMD_shader_trinary_minmax

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_AMD_sparse_texture

#ifndef GL_AMD_sparse_texture
#define GL_AMD_sparse_texture 1

#define GL_VIRTUAL_PAGE_SIZE_X_AMD            0x9195
#define GL_VIRTUAL_PAGE_SIZE_Y_AMD            0x9196
#define GL_VIRTUAL_PAGE_SIZE_Z_AMD            0x9197
#define GL_MAX_SPARSE_TEXTURE_SIZE_AMD        0x9198
#define GL_MAX_SPARSE_3D_TEXTURE_SIZE_AMD     0x9199
#define GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS    0x919A
#define GL_MIN_SPARSE_LEVEL_AMD               0x919B
#define GL_MIN_LOD_WARNING_AMD                0x919C
#define GL_TEXTURE_STORAGE_SPARSE_BIT_AMD     0x00000001

OPENGL_INIT_PROC(glTexStorageSparseAMD, void, GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags);
OPENGL_INIT_PROC(glTextureStorageSparseAMD, void, GLuint texture, GLenum target, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLsizei layers, GLbitfield flags);

#define glTexStorageSparseAMD     OGL__glTexStorageSparseAMD
#define glTextureStorageSparseAMD OGL__glTextureStorageSparseAMD

#endif // GL_AMD_sparse_texture

#endif // OPENGL_INCLUDE_GL_AMD_sparse_texture

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_AMD_stencil_operation_extended

#ifndef GL_AMD_stencil_operation_extended
#define GL_AMD_stencil_operation_extended 1

#define GL_SET_AMD                      0x874A
#define GL_REPLACE_VALUE_AMD            0x874B
#define GL_STENCIL_OP_VALUE_AMD         0x874C
#define GL_STENCIL_BACK_OP_VALUE_AMD    0x874D

OPENGL_INIT_PROC(glStencilOpValueAMD, void, GLenum face, GLuint value);
#define glStencilOpValueAMD OGL__glStencilOpValueAMD

#endif // GL_AMD_stencil_operation_extended

#endif // OPENGL_INCLUDE_GL_AMD_stencil_operation_extended

/* -------------------------------------------------------------------------- */

#ifndef GL_AMD_texture_gather_bias_lod
#define GL_AMD_texture_gather_bias_lod 1

#endif // GL_AMD_texture_gather_bias_lod

/* -------------------------------------------------------------------------- */

#ifndef GL_AMD_texture_texture4
#define GL_AMD_texture_texture4 1

#endif // GL_AMD_texture_texture4

/* -------------------------------------------------------------------------- */

#ifndef GL_AMD_transform_feedback3_lines_triangles
#define GL_AMD_transform_feedback3_lines_triangles 1

#endif // GL_AMD_transform_feedback3_lines_triangles

/* -------------------------------------------------------------------------- */

#ifndef GL_AMD_transform_feedback4
#define GL_AMD_transform_feedback4 1

#define GL_STREAM_RASTERIZATION_AMD    0x91A0

#endif // GL_AMD_transform_feedback4

/* -------------------------------------------------------------------------- */

#ifndef GL_AMD_vertex_shader_layer
#define GL_AMD_vertex_shader_layer 1

#endif // GL_AMD_vertex_shader_layer

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_AMD_vertex_shader_tessellator

#ifndef GL_AMD_vertex_shader_tessellator
#define GL_AMD_vertex_shader_tessellator 1

#define GL_SAMPLER_BUFFER_AMD                 0x9001
#define GL_INT_SAMPLER_BUFFER_AMD             0x9002
#define GL_UNSIGNED_INT_SAMPLER_BUFFER_AMD    0x9003
#define GL_TESSELLATION_MODE_AMD              0x9004
#define GL_TESSELLATION_FACTOR_AMD            0x9005
#define GL_DISCRETE_AMD                       0x9006
#define GL_CONTINUOUS_AMD                     0x9007

OPENGL_INIT_PROC(glTessellationFactorAMD, void, GLfloat factor);
OPENGL_INIT_PROC(glTessellationModeAMD,   void, GLenum mode);

#define glTessellationFactorAMD OGL__glTessellationFactorAMD
#define glTessellationModeAMD   OGL__glTessellationModeAMD

#endif // GL_AMD_vertex_shader_tessellator

#endif // OPENGL_INCLUDE_GL_AMD_vertex_shader_tessellator

/* -------------------------------------------------------------------------- */

#ifndef GL_AMD_vertex_shader_viewport_index
#define GL_AMD_vertex_shader_viewport_index 1

#endif // GL_AMD_vertex_shader_viewport_index

/* -------------------------------------------------------------------------- */

#ifndef GL_APPLE_aux_depth_stencil
#define GL_APPLE_aux_depth_stencil 1

#define GL_AUX_DEPTH_STENCIL_APPLE    0x8A14

#endif // GL_APPLE_aux_depth_stencil

/* -------------------------------------------------------------------------- */

#ifndef GL_APPLE_client_storage
#define GL_APPLE_client_storage 1

#define GL_UNPACK_CLIENT_STORAGE_APPLE    0x85B2

#endif // GL_APPLE_client_storage

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_APPLE_element_array

#ifndef GL_APPLE_element_array
#define GL_APPLE_element_array 1

#define GL_ELEMENT_ARRAY_APPLE            0x8A0C
#define GL_ELEMENT_ARRAY_TYPE_APPLE       0x8A0D
#define GL_ELEMENT_ARRAY_POINTER_APPLE    0x8A0E

OPENGL_INIT_PROC(glElementPointerAPPLE,             void, GLenum type, const void *pointer);
OPENGL_INIT_PROC(glDrawElementArrayAPPLE,           void, GLenum mode, GLint first, GLsizei count);
OPENGL_INIT_PROC(glDrawRangeElementArrayAPPLE,      void, GLenum mode, GLuint start, GLuint end, GLint first, GLsizei count);
OPENGL_INIT_PROC(glMultiDrawElementArrayAPPLE,      void, GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
OPENGL_INIT_PROC(glMultiDrawRangeElementArrayAPPLE, void, GLenum mode, GLuint start, GLuint end, const GLint *first, const GLsizei *count, GLsizei primcount);

#define glElementPointerAPPLE             OGL__glElementPointerAPPLE
#define glDrawElementArrayAPPLE           OGL__glDrawElementArrayAPPLE
#define glDrawRangeElementArrayAPPLE      OGL__glDrawRangeElementArrayAPPLE
#define glMultiDrawElementArrayAPPLE      OGL__glMultiDrawElementArrayAPPLE
#define glMultiDrawRangeElementArrayAPPLE OGL__glMultiDrawRangeElementArrayAPPLE

#endif // GL_APPLE_element_array

#endif // OPENGL_INCLUDE_GL_APPLE_element_array

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_APPLE_fence

#ifndef GL_APPLE_fence
#define GL_APPLE_fence 1

#define GL_DRAW_PIXELS_APPLE    0x8A0A
#define GL_FENCE_APPLE          0x8A0B

OPENGL_INIT_PROC(glGenFencesAPPLE,    void,      GLsizei n, GLuint *fences);
OPENGL_INIT_PROC(glDeleteFencesAPPLE, void,      GLsizei n, const GLuint *fences);
OPENGL_INIT_PROC(glSetFenceAPPLE,     void,      GLuint fence);
OPENGL_INIT_PROC(glIsFenceAPPLE,      GLboolean, GLuint fence);
OPENGL_INIT_PROC(glTestFenceAPPLE,    GLboolean, GLuint fence);
OPENGL_INIT_PROC(glFinishFenceAPPLE,  void,      GLuint fence);
OPENGL_INIT_PROC(glTestObjectAPPLE,   GLboolean, GLenum object, GLuint name);
OPENGL_INIT_PROC(glFinishObjectAPPLE, void,      GLenum object, GLint name);

#define glGenFencesAPPLE    OGL__glGenFencesAPPLE
#define glDeleteFencesAPPLE OGL__glDeleteFencesAPPLE
#define glSetFenceAPPLE     OGL__glSetFenceAPPLE
#define glIsFenceAPPLE      OGL__glIsFenceAPPLE
#define glTestFenceAPPLE    OGL__glTestFenceAPPLE
#define glFinishFenceAPPLE  OGL__glFinishFenceAPPLE
#define glTestObjectAPPLE   OGL__glTestObjectAPPLE
#define glFinishObjectAPPLE OGL__glFinishObjectAPPLE

#endif // GL_APPLE_fence

#endif // OPENGL_INCLUDE_GL_APPLE_fence

/* -------------------------------------------------------------------------- */

#ifndef GL_APPLE_float_pixels
#define GL_APPLE_float_pixels 1

#define GL_HALF_APPLE                       0x140B
#define GL_RGBA_FLOAT32_APPLE               0x8814
#define GL_RGB_FLOAT32_APPLE                0x8815
#define GL_ALPHA_FLOAT32_APPLE              0x8816
#define GL_INTENSITY_FLOAT32_APPLE          0x8817
#define GL_LUMINANCE_FLOAT32_APPLE          0x8818
#define GL_LUMINANCE_ALPHA_FLOAT32_APPLE    0x8819
#define GL_RGBA_FLOAT16_APPLE               0x881A
#define GL_RGB_FLOAT16_APPLE                0x881B
#define GL_ALPHA_FLOAT16_APPLE              0x881C
#define GL_INTENSITY_FLOAT16_APPLE          0x881D
#define GL_LUMINANCE_FLOAT16_APPLE          0x881E
#define GL_LUMINANCE_ALPHA_FLOAT16_APPLE    0x881F
#define GL_COLOR_FLOAT_APPLE                0x8A0F

#endif // GL_APPLE_float_pixels

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_APPLE_flush_buffer_range

#ifndef GL_APPLE_flush_buffer_range
#define GL_APPLE_flush_buffer_range 1

#define GL_BUFFER_SERIALIZED_MODIFY_APPLE    0x8A12
#define GL_BUFFER_FLUSHING_UNMAP_APPLE       0x8A13

OPENGL_INIT_PROC(glBufferParameteriAPPLE,       void, GLenum target, GLenum pname, GLint param);
OPENGL_INIT_PROC(glFlushMappedBufferRangeAPPLE, void, GLenum target, GLintptr offset, GLsizeiptr size);

#define glBufferParameteriAPPLE       OGL__glBufferParameteriAPPLE
#define glFlushMappedBufferRangeAPPLE OGL__glFlushMappedBufferRangeAPPLE

#endif // GL_APPLE_flush_buffer_range

#endif // OPENGL_INCLUDE_GL_APPLE_flush_buffer_range

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_APPLE_object_purgeable

#ifndef GL_APPLE_object_purgeable
#define GL_APPLE_object_purgeable 1

#define GL_BUFFER_OBJECT_APPLE    0x85B3
#define GL_RELEASED_APPLE         0x8A19
#define GL_VOLATILE_APPLE         0x8A1A
#define GL_RETAINED_APPLE         0x8A1B
#define GL_UNDEFINED_APPLE        0x8A1C
#define GL_PURGEABLE_APPLE        0x8A1D

OPENGL_INIT_PROC(glObjectPurgeableAPPLE,      GLenum, GLenum objectType, GLuint name, GLenum option);
OPENGL_INIT_PROC(glObjectUnpurgeableAPPLE,    GLenum, GLenum objectType, GLuint name, GLenum option);
OPENGL_INIT_PROC(glGetObjectParameterivAPPLE, void,   GLenum objectType, GLuint name, GLenum pname, GLint *params);

#define glObjectPurgeableAPPLE      OGL__glObjectPurgeableAPPLE
#define glObjectUnpurgeableAPPLE    OGL__glObjectUnpurgeableAPPLE
#define glGetObjectParameterivAPPLE OGL__glGetObjectParameterivAPPLE

#endif // GL_APPLE_object_purgeable

#endif // OPENGL_INCLUDE_GL_APPLE_object_purgeable

/* -------------------------------------------------------------------------- */

#ifndef GL_APPLE_rgb_422
#define GL_APPLE_rgb_422 1

#define GL_RGB_422_APPLE                   0x8A1F
#define GL_UNSIGNED_SHORT_8_8_APPLE        0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_APPLE    0x85BB
#define GL_RGB_RAW_422_APPLE               0x8A51

#endif // GL_APPLE_rgb_422

/* -------------------------------------------------------------------------- */

#ifndef GL_APPLE_row_bytes
#define GL_APPLE_row_bytes 1

#define GL_PACK_ROW_BYTES_APPLE      0x8A15
#define GL_UNPACK_ROW_BYTES_APPLE    0x8A16

#endif // GL_APPLE_row_bytes

/* -------------------------------------------------------------------------- */

#ifndef GL_APPLE_specular_vector
#define GL_APPLE_specular_vector 1

#define GL_LIGHT_MODEL_SPECULAR_VECTOR_APPLE    0x85B0

#endif // GL_APPLE_specular_vector

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_APPLE_texture_range

#ifndef GL_APPLE_texture_range
#define GL_APPLE_texture_range 1

#define GL_TEXTURE_RANGE_LENGTH_APPLE     0x85B7
#define GL_TEXTURE_RANGE_POINTER_APPLE    0x85B8
#define GL_TEXTURE_STORAGE_HINT_APPLE     0x85BC
#define GL_STORAGE_PRIVATE_APPLE          0x85BD
#define GL_STORAGE_CACHED_APPLE           0x85BE
#define GL_STORAGE_SHARED_APPLE           0x85BF

OPENGL_INIT_PROC(glTextureRangeAPPLE,            void, GLenum target, GLsizei length, const void *pointer);
OPENGL_INIT_PROC(glGetTexParameterPointervAPPLE, void, GLenum target, GLenum pname, void **params);

#define glTextureRangeAPPLE            OGL__glTextureRangeAPPLE
#define glGetTexParameterPointervAPPLE OGL__glGetTexParameterPointervAPPLE

#endif // GL_APPLE_texture_range

#endif // OPENGL_INCLUDE_GL_APPLE_texture_range

/* -------------------------------------------------------------------------- */

#ifndef GL_APPLE_transform_hint
#define GL_APPLE_transform_hint 1

#define GL_TRANSFORM_HINT_APPLE    0x85B1

#endif // GL_APPLE_transform_hint

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_APPLE_vertex_array_object

#ifndef GL_APPLE_vertex_array_object
#define GL_APPLE_vertex_array_object 1

#define GL_VERTEX_ARRAY_BINDING_APPLE    0x85B5

OPENGL_INIT_PROC(glBindVertexArrayAPPLE,    void,      GLuint array);
OPENGL_INIT_PROC(glDeleteVertexArraysAPPLE, void,      GLsizei n, const GLuint *arrays);
OPENGL_INIT_PROC(glGenVertexArraysAPPLE,    void,      GLsizei n, GLuint *arrays);
OPENGL_INIT_PROC(glIsVertexArrayAPPLE,      GLboolean, GLuint array);

#define glBindVertexArrayAPPLE    OGL__glBindVertexArrayAPPLE
#define glDeleteVertexArraysAPPLE OGL__glDeleteVertexArraysAPPLE
#define glGenVertexArraysAPPLE    OGL__glGenVertexArraysAPPLE
#define glIsVertexArrayAPPLE      OGL__glIsVertexArrayAPPLE

#endif // GL_APPLE_vertex_array_object

#endif // OPENGL_INCLUDE_GL_APPLE_vertex_array_object

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_APPLE_vertex_array_range

#ifndef GL_APPLE_vertex_array_range
#define GL_APPLE_vertex_array_range 1

#define GL_VERTEX_ARRAY_RANGE_APPLE            0x851D
#define GL_VERTEX_ARRAY_RANGE_LENGTH_APPLE     0x851E
#define GL_VERTEX_ARRAY_STORAGE_HINT_APPLE     0x851F
#define GL_VERTEX_ARRAY_RANGE_POINTER_APPLE    0x8521
#define GL_STORAGE_CLIENT_APPLE                0x85B4

OPENGL_INIT_PROC(glVertexArrayRangeAPPLE,      void, GLsizei length, void *pointer);
OPENGL_INIT_PROC(glFlushVertexArrayRangeAPPLE, void, GLsizei length, void *pointer);
OPENGL_INIT_PROC(glVertexArrayParameteriAPPLE, void, GLenum pname, GLint param);

#define glVertexArrayRangeAPPLE      OGL__glVertexArrayRangeAPPLE
#define glFlushVertexArrayRangeAPPLE OGL__glFlushVertexArrayRangeAPPLE
#define glVertexArrayParameteriAPPLE OGL__glVertexArrayParameteriAPPLE

#endif // GL_APPLE_vertex_array_range

#endif // OPENGL_INCLUDE_GL_APPLE_vertex_array_range

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_APPLE_vertex_program_evaluators

#ifndef GL_APPLE_vertex_program_evaluators
#define GL_APPLE_vertex_program_evaluators 1

#define GL_VERTEX_ATTRIB_MAP1_APPLE           0x8A00
#define GL_VERTEX_ATTRIB_MAP2_APPLE           0x8A01
#define GL_VERTEX_ATTRIB_MAP1_SIZE_APPLE      0x8A02
#define GL_VERTEX_ATTRIB_MAP1_COEFF_APPLE     0x8A03
#define GL_VERTEX_ATTRIB_MAP1_ORDER_APPLE     0x8A04
#define GL_VERTEX_ATTRIB_MAP1_DOMAIN_APPLE    0x8A05
#define GL_VERTEX_ATTRIB_MAP2_SIZE_APPLE      0x8A06
#define GL_VERTEX_ATTRIB_MAP2_COEFF_APPLE     0x8A07
#define GL_VERTEX_ATTRIB_MAP2_ORDER_APPLE     0x8A08
#define GL_VERTEX_ATTRIB_MAP2_DOMAIN_APPLE    0x8A09

OPENGL_INIT_PROC(glEnableVertexAttribAPPLE,    void,      GLuint index, GLenum pname);
OPENGL_INIT_PROC(glDisableVertexAttribAPPLE,   void,      GLuint index, GLenum pname);
OPENGL_INIT_PROC(glIsVertexAttribEnabledAPPLE, GLboolean, GLuint index, GLenum pname);
OPENGL_INIT_PROC(glMapVertexAttrib1dAPPLE,     void,      GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
OPENGL_INIT_PROC(glMapVertexAttrib1fAPPLE,     void,      GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
OPENGL_INIT_PROC(glMapVertexAttrib2dAPPLE,     void,      GLuint index, GLuint size, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
OPENGL_INIT_PROC(glMapVertexAttrib2fAPPLE,     void,      GLuint index, GLuint size, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);

#define glEnableVertexAttribAPPLE    OGL__glEnableVertexAttribAPPLE
#define glDisableVertexAttribAPPLE   OGL__glDisableVertexAttribAPPLE
#define glIsVertexAttribEnabledAPPLE OGL__glIsVertexAttribEnabledAPPLE
#define glMapVertexAttrib1dAPPLE     OGL__glMapVertexAttrib1dAPPLE
#define glMapVertexAttrib1fAPPLE     OGL__glMapVertexAttrib1fAPPLE
#define glMapVertexAttrib2dAPPLE     OGL__glMapVertexAttrib2dAPPLE
#define glMapVertexAttrib2fAPPLE     OGL__glMapVertexAttrib2fAPPLE

#endif // GL_APPLE_vertex_program_evaluators

#endif // OPENGL_INCLUDE_GL_APPLE_vertex_program_evaluators

/* -------------------------------------------------------------------------- */

#ifndef GL_APPLE_ycbcr_422
#define GL_APPLE_ycbcr_422 1

#define GL_YCBCR_422_APPLE    0x85B9

#endif // GL_APPLE_ycbcr_422

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ATI_draw_buffers

#ifndef GL_ATI_draw_buffers
#define GL_ATI_draw_buffers 1

#define GL_MAX_DRAW_BUFFERS_ATI    0x8824
#define GL_DRAW_BUFFER0_ATI        0x8825
#define GL_DRAW_BUFFER1_ATI        0x8826
#define GL_DRAW_BUFFER2_ATI        0x8827
#define GL_DRAW_BUFFER3_ATI        0x8828
#define GL_DRAW_BUFFER4_ATI        0x8829
#define GL_DRAW_BUFFER5_ATI        0x882A
#define GL_DRAW_BUFFER6_ATI        0x882B
#define GL_DRAW_BUFFER7_ATI        0x882C
#define GL_DRAW_BUFFER8_ATI        0x882D
#define GL_DRAW_BUFFER9_ATI        0x882E
#define GL_DRAW_BUFFER10_ATI       0x882F
#define GL_DRAW_BUFFER11_ATI       0x8830
#define GL_DRAW_BUFFER12_ATI       0x8831
#define GL_DRAW_BUFFER13_ATI       0x8832
#define GL_DRAW_BUFFER14_ATI       0x8833
#define GL_DRAW_BUFFER15_ATI       0x8834

OPENGL_INIT_PROC(glDrawBuffersATI, void, GLsizei n, const GLenum *bufs);
#define glDrawBuffersATI OGL__glDrawBuffersATI

#endif // GL_ATI_draw_buffers

#endif // OPENGL_INCLUDE_GL_ATI_draw_buffers

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ATI_element_array

#ifndef GL_ATI_element_array
#define GL_ATI_element_array 1

#define GL_ELEMENT_ARRAY_ATI            0x8768
#define GL_ELEMENT_ARRAY_TYPE_ATI       0x8769
#define GL_ELEMENT_ARRAY_POINTER_ATI    0x876A

OPENGL_INIT_PROC(glElementPointerATI,        void, GLenum type, const void *pointer);
OPENGL_INIT_PROC(glDrawElementArrayATI,      void, GLenum mode, GLsizei count);
OPENGL_INIT_PROC(glDrawRangeElementArrayATI, void, GLenum mode, GLuint start, GLuint end, GLsizei count);

#define glElementPointerATI        OGL__glElementPointerATI
#define glDrawElementArrayATI      OGL__glDrawElementArrayATI
#define glDrawRangeElementArrayATI OGL__glDrawRangeElementArrayATI

#endif // GL_ATI_element_array

#endif // OPENGL_INCLUDE_GL_ATI_element_array

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ATI_envmap_bumpmap

#ifndef GL_ATI_envmap_bumpmap
#define GL_ATI_envmap_bumpmap 1

#define GL_BUMP_ROT_MATRIX_ATI         0x8775
#define GL_BUMP_ROT_MATRIX_SIZE_ATI    0x8776
#define GL_BUMP_NUM_TEX_UNITS_ATI      0x8777
#define GL_BUMP_TEX_UNITS_ATI          0x8778
#define GL_DUDV_ATI                    0x8779
#define GL_DU8DV8_ATI                  0x877A
#define GL_BUMP_ENVMAP_ATI             0x877B
#define GL_BUMP_TARGET_ATI             0x877C

OPENGL_INIT_PROC(glTexBumpParameterivATI,    void, GLenum pname, const GLint *param);
OPENGL_INIT_PROC(glTexBumpParameterfvATI,    void, GLenum pname, const GLfloat *param);
OPENGL_INIT_PROC(glGetTexBumpParameterivATI, void, GLenum pname, GLint *param);
OPENGL_INIT_PROC(glGetTexBumpParameterfvATI, void, GLenum pname, GLfloat *param);

#define glTexBumpParameterivATI    OGL__glTexBumpParameterivATI
#define glTexBumpParameterfvATI    OGL__glTexBumpParameterfvATI
#define glGetTexBumpParameterivATI OGL__glGetTexBumpParameterivATI
#define glGetTexBumpParameterfvATI OGL__glGetTexBumpParameterfvATI

#endif // GL_ATI_envmap_bumpmap

#endif // OPENGL_INCLUDE_GL_ATI_envmap_bumpmap

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ATI_fragment_shader

#ifndef GL_ATI_fragment_shader
#define GL_ATI_fragment_shader 1

#define GL_FRAGMENT_SHADER_ATI                      0x8920
#define GL_REG_0_ATI                                0x8921
#define GL_REG_1_ATI                                0x8922
#define GL_REG_2_ATI                                0x8923
#define GL_REG_3_ATI                                0x8924
#define GL_REG_4_ATI                                0x8925
#define GL_REG_5_ATI                                0x8926
#define GL_REG_6_ATI                                0x8927
#define GL_REG_7_ATI                                0x8928
#define GL_REG_8_ATI                                0x8929
#define GL_REG_9_ATI                                0x892A
#define GL_REG_10_ATI                               0x892B
#define GL_REG_11_ATI                               0x892C
#define GL_REG_12_ATI                               0x892D
#define GL_REG_13_ATI                               0x892E
#define GL_REG_14_ATI                               0x892F
#define GL_REG_15_ATI                               0x8930
#define GL_REG_16_ATI                               0x8931
#define GL_REG_17_ATI                               0x8932
#define GL_REG_18_ATI                               0x8933
#define GL_REG_19_ATI                               0x8934
#define GL_REG_20_ATI                               0x8935
#define GL_REG_21_ATI                               0x8936
#define GL_REG_22_ATI                               0x8937
#define GL_REG_23_ATI                               0x8938
#define GL_REG_24_ATI                               0x8939
#define GL_REG_25_ATI                               0x893A
#define GL_REG_26_ATI                               0x893B
#define GL_REG_27_ATI                               0x893C
#define GL_REG_28_ATI                               0x893D
#define GL_REG_29_ATI                               0x893E
#define GL_REG_30_ATI                               0x893F
#define GL_REG_31_ATI                               0x8940
#define GL_CON_0_ATI                                0x8941
#define GL_CON_1_ATI                                0x8942
#define GL_CON_2_ATI                                0x8943
#define GL_CON_3_ATI                                0x8944
#define GL_CON_4_ATI                                0x8945
#define GL_CON_5_ATI                                0x8946
#define GL_CON_6_ATI                                0x8947
#define GL_CON_7_ATI                                0x8948
#define GL_CON_8_ATI                                0x8949
#define GL_CON_9_ATI                                0x894A
#define GL_CON_10_ATI                               0x894B
#define GL_CON_11_ATI                               0x894C
#define GL_CON_12_ATI                               0x894D
#define GL_CON_13_ATI                               0x894E
#define GL_CON_14_ATI                               0x894F
#define GL_CON_15_ATI                               0x8950
#define GL_CON_16_ATI                               0x8951
#define GL_CON_17_ATI                               0x8952
#define GL_CON_18_ATI                               0x8953
#define GL_CON_19_ATI                               0x8954
#define GL_CON_20_ATI                               0x8955
#define GL_CON_21_ATI                               0x8956
#define GL_CON_22_ATI                               0x8957
#define GL_CON_23_ATI                               0x8958
#define GL_CON_24_ATI                               0x8959
#define GL_CON_25_ATI                               0x895A
#define GL_CON_26_ATI                               0x895B
#define GL_CON_27_ATI                               0x895C
#define GL_CON_28_ATI                               0x895D
#define GL_CON_29_ATI                               0x895E
#define GL_CON_30_ATI                               0x895F
#define GL_CON_31_ATI                               0x8960
#define GL_MOV_ATI                                  0x8961
#define GL_ADD_ATI                                  0x8963
#define GL_MUL_ATI                                  0x8964
#define GL_SUB_ATI                                  0x8965
#define GL_DOT3_ATI                                 0x8966
#define GL_DOT4_ATI                                 0x8967
#define GL_MAD_ATI                                  0x8968
#define GL_LERP_ATI                                 0x8969
#define GL_CND_ATI                                  0x896A
#define GL_CND0_ATI                                 0x896B
#define GL_DOT2_ADD_ATI                             0x896C
#define GL_SECONDARY_INTERPOLATOR_ATI               0x896D
#define GL_NUM_FRAGMENT_REGISTERS_ATI               0x896E
#define GL_NUM_FRAGMENT_CONSTANTS_ATI               0x896F
#define GL_NUM_PASSES_ATI                           0x8970
#define GL_NUM_INSTRUCTIONS_PER_PASS_ATI            0x8971
#define GL_NUM_INSTRUCTIONS_TOTAL_ATI               0x8972
#define GL_NUM_INPUT_INTERPOLATOR_COMPONENTS_ATI    0x8973
#define GL_NUM_LOOPBACK_COMPONENTS_ATI              0x8974
#define GL_COLOR_ALPHA_PAIRING_ATI                  0x8975
#define GL_SWIZZLE_STR_ATI                          0x8976
#define GL_SWIZZLE_STQ_ATI                          0x8977
#define GL_SWIZZLE_STR_DR_ATI                       0x8978
#define GL_SWIZZLE_STQ_DQ_ATI                       0x8979
#define GL_SWIZZLE_STRQ_ATI                         0x897A
#define GL_SWIZZLE_STRQ_DQ_ATI                      0x897B
#define GL_RED_BIT_ATI                              0x00000001
#define GL_GREEN_BIT_ATI                            0x00000002
#define GL_BLUE_BIT_ATI                             0x00000004
#define GL_2X_BIT_ATI                               0x00000001
#define GL_4X_BIT_ATI                               0x00000002
#define GL_8X_BIT_ATI                               0x00000004
#define GL_HALF_BIT_ATI                             0x00000008
#define GL_QUARTER_BIT_ATI                          0x00000010
#define GL_EIGHTH_BIT_ATI                           0x00000020
#define GL_SATURATE_BIT_ATI                         0x00000040
#define GL_COMP_BIT_ATI                             0x00000002
#define GL_NEGATE_BIT_ATI                           0x00000004
#define GL_BIAS_BIT_ATI                             0x00000008

OPENGL_INIT_PROC(glGenFragmentShadersATI,        GLuint, GLuint range);
OPENGL_INIT_PROC(glBindFragmentShaderATI,        void,   GLuint id);
OPENGL_INIT_PROC(glDeleteFragmentShaderATI,      void,   GLuint id);
OPENGL_INIT_PROC(glBeginFragmentShaderATI,       void,   void);
OPENGL_INIT_PROC(glEndFragmentShaderATI,         void,   void);
OPENGL_INIT_PROC(glPassTexCoordATI,              void,   GLuint dst, GLuint coord, GLenum swizzle);
OPENGL_INIT_PROC(glSampleMapATI,                 void,   GLuint dst, GLuint interp, GLenum swizzle);
OPENGL_INIT_PROC(glColorFragmentOp1ATI,          void,   GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
OPENGL_INIT_PROC(glColorFragmentOp2ATI,          void,   GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
OPENGL_INIT_PROC(glColorFragmentOp3ATI,          void,   GLenum op, GLuint dst, GLuint dstMask, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
OPENGL_INIT_PROC(glAlphaFragmentOp1ATI,          void,   GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod);
OPENGL_INIT_PROC(glAlphaFragmentOp2ATI,          void,   GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod);
OPENGL_INIT_PROC(glAlphaFragmentOp3ATI,          void,   GLenum op, GLuint dst, GLuint dstMod, GLuint arg1, GLuint arg1Rep, GLuint arg1Mod, GLuint arg2, GLuint arg2Rep, GLuint arg2Mod, GLuint arg3, GLuint arg3Rep, GLuint arg3Mod);
OPENGL_INIT_PROC(glSetFragmentShaderConstantATI, void,   GLuint dst, const GLfloat *value);

#define glGenFragmentShadersATI        OGL__glGenFragmentShadersATI
#define glBindFragmentShaderATI        OGL__glBindFragmentShaderATI
#define glDeleteFragmentShaderATI      OGL__glDeleteFragmentShaderATI
#define glBeginFragmentShaderATI       OGL__glBeginFragmentShaderATI
#define glEndFragmentShaderATI         OGL__glEndFragmentShaderATI
#define glPassTexCoordATI              OGL__glPassTexCoordATI
#define glSampleMapATI                 OGL__glSampleMapATI
#define glColorFragmentOp1ATI          OGL__glColorFragmentOp1ATI
#define glColorFragmentOp2ATI          OGL__glColorFragmentOp2ATI
#define glColorFragmentOp3ATI          OGL__glColorFragmentOp3ATI
#define glAlphaFragmentOp1ATI          OGL__glAlphaFragmentOp1ATI
#define glAlphaFragmentOp2ATI          OGL__glAlphaFragmentOp2ATI
#define glAlphaFragmentOp3ATI          OGL__glAlphaFragmentOp3ATI
#define glSetFragmentShaderConstantATI OGL__glSetFragmentShaderConstantATI

#endif // GL_ATI_fragment_shader

#endif // OPENGL_INCLUDE_GL_ATI_fragment_shader

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ATI_map_object_buffer

#ifndef GL_ATI_map_object_buffer
#define GL_ATI_map_object_buffer 1

OPENGL_INIT_PROC(glMapObjectBufferATI,   void*, GLuint buffer);
OPENGL_INIT_PROC(glUnmapObjectBufferATI, void,  GLuint buffer);

#define glMapObjectBufferATI   OGL__glMapObjectBufferATI
#define glUnmapObjectBufferATI OGL__glUnmapObjectBufferATI

#endif // GL_ATI_map_object_buffer

#endif // OPENGL_INCLUDE_GL_ATI_map_object_buffer

/* -------------------------------------------------------------------------- */

#ifndef GL_ATI_meminfo
#define GL_ATI_meminfo 1

#define GL_VBO_FREE_MEMORY_ATI             0x87FB
#define GL_TEXTURE_FREE_MEMORY_ATI         0x87FC
#define GL_RENDERBUFFER_FREE_MEMORY_ATI    0x87FD

#endif // GL_ATI_meminfo

/* -------------------------------------------------------------------------- */

#ifndef GL_ATI_pixel_format_float
#define GL_ATI_pixel_format_float 1

#define GL_RGBA_FLOAT_MODE_ATI                0x8820
#define GL_COLOR_CLEAR_UNCLAMPED_VALUE_ATI    0x8835

#endif // GL_ATI_pixel_format_float

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ATI_pn_triangles

#ifndef GL_ATI_pn_triangles
#define GL_ATI_pn_triangles 1

#define GL_PN_TRIANGLES_ATI                          0x87F0
#define GL_MAX_PN_TRIANGLES_TESSELATION_LEVEL_ATI    0x87F1
#define GL_PN_TRIANGLES_POINT_MODE_ATI               0x87F2
#define GL_PN_TRIANGLES_NORMAL_MODE_ATI              0x87F3
#define GL_PN_TRIANGLES_TESSELATION_LEVEL_ATI        0x87F4
#define GL_PN_TRIANGLES_POINT_MODE_LINEAR_ATI        0x87F5
#define GL_PN_TRIANGLES_POINT_MODE_CUBIC_ATI         0x87F6
#define GL_PN_TRIANGLES_NORMAL_MODE_LINEAR_ATI       0x87F7
#define GL_PN_TRIANGLES_NORMAL_MODE_QUADRATIC_ATI    0x87F8

OPENGL_INIT_PROC(glPNTrianglesiATI, void, GLenum pname, GLint param);
OPENGL_INIT_PROC(glPNTrianglesfATI, void, GLenum pname, GLfloat param);

#define glPNTrianglesiATI OGL__glPNTrianglesiATI
#define glPNTrianglesfATI OGL__glPNTrianglesfATI

#endif // GL_ATI_pn_triangles

#endif // OPENGL_INCLUDE_GL_ATI_pn_triangles

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ATI_separate_stencil

#ifndef GL_ATI_separate_stencil
#define GL_ATI_separate_stencil 1

#define GL_STENCIL_BACK_FUNC_ATI               0x8800
#define GL_STENCIL_BACK_FAIL_ATI               0x8801
#define GL_STENCIL_BACK_PASS_DEPTH_FAIL_ATI    0x8802
#define GL_STENCIL_BACK_PASS_DEPTH_PASS_ATI    0x8803

OPENGL_INIT_PROC(glStencilOpSeparateATI,   void, GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
OPENGL_INIT_PROC(glStencilFuncSeparateATI, void, GLenum frontfunc, GLenum backfunc, GLint ref, GLuint mask);

#define glStencilOpSeparateATI   OGL__glStencilOpSeparateATI
#define glStencilFuncSeparateATI OGL__glStencilFuncSeparateATI

#endif // GL_ATI_separate_stencil

#endif // OPENGL_INCLUDE_GL_ATI_separate_stencil

/* -------------------------------------------------------------------------- */

#ifndef GL_ATI_text_fragment_shader
#define GL_ATI_text_fragment_shader 1

#define GL_TEXT_FRAGMENT_SHADER_ATI    0x8200

#endif // GL_ATI_text_fragment_shader

/* -------------------------------------------------------------------------- */

#ifndef GL_ATI_texture_env_combine3
#define GL_ATI_texture_env_combine3 1

#define GL_MODULATE_ADD_ATI           0x8744
#define GL_MODULATE_SIGNED_ADD_ATI    0x8745
#define GL_MODULATE_SUBTRACT_ATI      0x8746

#endif // GL_ATI_texture_env_combine3

/* -------------------------------------------------------------------------- */

#ifndef GL_ATI_texture_float
#define GL_ATI_texture_float 1

#define GL_RGBA_FLOAT32_ATI               0x8814
#define GL_RGB_FLOAT32_ATI                0x8815
#define GL_ALPHA_FLOAT32_ATI              0x8816
#define GL_INTENSITY_FLOAT32_ATI          0x8817
#define GL_LUMINANCE_FLOAT32_ATI          0x8818
#define GL_LUMINANCE_ALPHA_FLOAT32_ATI    0x8819
#define GL_RGBA_FLOAT16_ATI               0x881A
#define GL_RGB_FLOAT16_ATI                0x881B
#define GL_ALPHA_FLOAT16_ATI              0x881C
#define GL_INTENSITY_FLOAT16_ATI          0x881D
#define GL_LUMINANCE_FLOAT16_ATI          0x881E
#define GL_LUMINANCE_ALPHA_FLOAT16_ATI    0x881F

#endif // GL_ATI_texture_float

/* -------------------------------------------------------------------------- */

#ifndef GL_ATI_texture_mirror_once
#define GL_ATI_texture_mirror_once 1

#define GL_MIRROR_CLAMP_ATI            0x8742
#define GL_MIRROR_CLAMP_TO_EDGE_ATI    0x8743

#endif // GL_ATI_texture_mirror_once

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ATI_vertex_array_object

#ifndef GL_ATI_vertex_array_object
#define GL_ATI_vertex_array_object 1

#define GL_STATIC_ATI                 0x8760
#define GL_DYNAMIC_ATI                0x8761
#define GL_PRESERVE_ATI               0x8762
#define GL_DISCARD_ATI                0x8763
#define GL_OBJECT_BUFFER_SIZE_ATI     0x8764
#define GL_OBJECT_BUFFER_USAGE_ATI    0x8765
#define GL_ARRAY_OBJECT_BUFFER_ATI    0x8766
#define GL_ARRAY_OBJECT_OFFSET_ATI    0x8767

OPENGL_INIT_PROC(glNewObjectBufferATI,         GLuint,    GLsizei size, const void *pointer, GLenum usage);
OPENGL_INIT_PROC(glIsObjectBufferATI,          GLboolean, GLuint buffer);
OPENGL_INIT_PROC(glUpdateObjectBufferATI,      void,      GLuint buffer, GLuint offset, GLsizei size, const void *pointer, GLenum preserve);
OPENGL_INIT_PROC(glGetObjectBufferfvATI,       void,      GLuint buffer, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetObjectBufferivATI,       void,      GLuint buffer, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glFreeObjectBufferATI,        void,      GLuint buffer);
OPENGL_INIT_PROC(glArrayObjectATI,             void,      GLenum array, GLint size, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
OPENGL_INIT_PROC(glGetArrayObjectfvATI,        void,      GLenum array, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetArrayObjectivATI,        void,      GLenum array, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glVariantArrayObjectATI,      void,      GLuint id, GLenum type, GLsizei stride, GLuint buffer, GLuint offset);
OPENGL_INIT_PROC(glGetVariantArrayObjectfvATI, void,      GLuint id, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetVariantArrayObjectivATI, void,      GLuint id, GLenum pname, GLint *params);

#define glNewObjectBufferATI         OGL__glNewObjectBufferATI
#define glIsObjectBufferATI          OGL__glIsObjectBufferATI
#define glUpdateObjectBufferATI      OGL__glUpdateObjectBufferATI
#define glGetObjectBufferfvATI       OGL__glGetObjectBufferfvATI
#define glGetObjectBufferivATI       OGL__glGetObjectBufferivATI
#define glFreeObjectBufferATI        OGL__glFreeObjectBufferATI
#define glArrayObjectATI             OGL__glArrayObjectATI
#define glGetArrayObjectfvATI        OGL__glGetArrayObjectfvATI
#define glGetArrayObjectivATI        OGL__glGetArrayObjectivATI
#define glVariantArrayObjectATI      OGL__glVariantArrayObjectATI
#define glGetVariantArrayObjectfvATI OGL__glGetVariantArrayObjectfvATI
#define glGetVariantArrayObjectivATI OGL__glGetVariantArrayObjectivATI

#endif // GL_ATI_vertex_array_object

#endif // OPENGL_INCLUDE_GL_ATI_vertex_array_object

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ATI_vertex_attrib_array_object

#ifndef GL_ATI_vertex_attrib_array_object
#define GL_ATI_vertex_attrib_array_object 1

OPENGL_INIT_PROC(glVertexAttribArrayObjectATI,      void, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLuint buffer, GLuint offset);
OPENGL_INIT_PROC(glGetVertexAttribArrayObjectfvATI, void, GLuint index, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetVertexAttribArrayObjectivATI, void, GLuint index, GLenum pname, GLint *params);

#define glVertexAttribArrayObjectATI      OGL__glVertexAttribArrayObjectATI
#define glGetVertexAttribArrayObjectfvATI OGL__glGetVertexAttribArrayObjectfvATI
#define glGetVertexAttribArrayObjectivATI OGL__glGetVertexAttribArrayObjectivATI

#endif // GL_ATI_vertex_attrib_array_object

#endif // OPENGL_INCLUDE_GL_ATI_vertex_attrib_array_object

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_ATI_vertex_streams

#ifndef GL_ATI_vertex_streams
#define GL_ATI_vertex_streams 1

#define GL_MAX_VERTEX_STREAMS_ATI    0x876B
#define GL_VERTEX_STREAM0_ATI        0x876C
#define GL_VERTEX_STREAM1_ATI        0x876D
#define GL_VERTEX_STREAM2_ATI        0x876E
#define GL_VERTEX_STREAM3_ATI        0x876F
#define GL_VERTEX_STREAM4_ATI        0x8770
#define GL_VERTEX_STREAM5_ATI        0x8771
#define GL_VERTEX_STREAM6_ATI        0x8772
#define GL_VERTEX_STREAM7_ATI        0x8773
#define GL_VERTEX_SOURCE_ATI         0x8774

OPENGL_INIT_PROC(glVertexStream1sATI,           void, GLenum stream, GLshort x);
OPENGL_INIT_PROC(glVertexStream1svATI,          void, GLenum stream, const GLshort *coords);
OPENGL_INIT_PROC(glVertexStream1iATI,           void, GLenum stream, GLint x);
OPENGL_INIT_PROC(glVertexStream1ivATI,          void, GLenum stream, const GLint *coords);
OPENGL_INIT_PROC(glVertexStream1fATI,           void, GLenum stream, GLfloat x);
OPENGL_INIT_PROC(glVertexStream1fvATI,          void, GLenum stream, const GLfloat *coords);
OPENGL_INIT_PROC(glVertexStream1dATI,           void, GLenum stream, GLdouble x);
OPENGL_INIT_PROC(glVertexStream1dvATI,          void, GLenum stream, const GLdouble *coords);
OPENGL_INIT_PROC(glVertexStream2sATI,           void, GLenum stream, GLshort x, GLshort y);
OPENGL_INIT_PROC(glVertexStream2svATI,          void, GLenum stream, const GLshort *coords);
OPENGL_INIT_PROC(glVertexStream2iATI,           void, GLenum stream, GLint x, GLint y);
OPENGL_INIT_PROC(glVertexStream2ivATI,          void, GLenum stream, const GLint *coords);
OPENGL_INIT_PROC(glVertexStream2fATI,           void, GLenum stream, GLfloat x, GLfloat y);
OPENGL_INIT_PROC(glVertexStream2fvATI,          void, GLenum stream, const GLfloat *coords);
OPENGL_INIT_PROC(glVertexStream2dATI,           void, GLenum stream, GLdouble x, GLdouble y);
OPENGL_INIT_PROC(glVertexStream2dvATI,          void, GLenum stream, const GLdouble *coords);
OPENGL_INIT_PROC(glVertexStream3sATI,           void, GLenum stream, GLshort x, GLshort y, GLshort z);
OPENGL_INIT_PROC(glVertexStream3svATI,          void, GLenum stream, const GLshort *coords);
OPENGL_INIT_PROC(glVertexStream3iATI,           void, GLenum stream, GLint x, GLint y, GLint z);
OPENGL_INIT_PROC(glVertexStream3ivATI,          void, GLenum stream, const GLint *coords);
OPENGL_INIT_PROC(glVertexStream3fATI,           void, GLenum stream, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glVertexStream3fvATI,          void, GLenum stream, const GLfloat *coords);
OPENGL_INIT_PROC(glVertexStream3dATI,           void, GLenum stream, GLdouble x, GLdouble y, GLdouble z);
OPENGL_INIT_PROC(glVertexStream3dvATI,          void, GLenum stream, const GLdouble *coords);
OPENGL_INIT_PROC(glVertexStream4sATI,           void, GLenum stream, GLshort x, GLshort y, GLshort z, GLshort w);
OPENGL_INIT_PROC(glVertexStream4svATI,          void, GLenum stream, const GLshort *coords);
OPENGL_INIT_PROC(glVertexStream4iATI,           void, GLenum stream, GLint x, GLint y, GLint z, GLint w);
OPENGL_INIT_PROC(glVertexStream4ivATI,          void, GLenum stream, const GLint *coords);
OPENGL_INIT_PROC(glVertexStream4fATI,           void, GLenum stream, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
OPENGL_INIT_PROC(glVertexStream4fvATI,          void, GLenum stream, const GLfloat *coords);
OPENGL_INIT_PROC(glVertexStream4dATI,           void, GLenum stream, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
OPENGL_INIT_PROC(glVertexStream4dvATI,          void, GLenum stream, const GLdouble *coords);
OPENGL_INIT_PROC(glNormalStream3bATI,           void, GLenum stream, GLbyte nx, GLbyte ny, GLbyte nz);
OPENGL_INIT_PROC(glNormalStream3bvATI,          void, GLenum stream, const GLbyte *coords);
OPENGL_INIT_PROC(glNormalStream3sATI,           void, GLenum stream, GLshort nx, GLshort ny, GLshort nz);
OPENGL_INIT_PROC(glNormalStream3svATI,          void, GLenum stream, const GLshort *coords);
OPENGL_INIT_PROC(glNormalStream3iATI,           void, GLenum stream, GLint nx, GLint ny, GLint nz);
OPENGL_INIT_PROC(glNormalStream3ivATI,          void, GLenum stream, const GLint *coords);
OPENGL_INIT_PROC(glNormalStream3fATI,           void, GLenum stream, GLfloat nx, GLfloat ny, GLfloat nz);
OPENGL_INIT_PROC(glNormalStream3fvATI,          void, GLenum stream, const GLfloat *coords);
OPENGL_INIT_PROC(glNormalStream3dATI,           void, GLenum stream, GLdouble nx, GLdouble ny, GLdouble nz);
OPENGL_INIT_PROC(glNormalStream3dvATI,          void, GLenum stream, const GLdouble *coords);
OPENGL_INIT_PROC(glClientActiveVertexStreamATI, void, GLenum stream);
OPENGL_INIT_PROC(glVertexBlendEnviATI,          void, GLenum pname, GLint param);
OPENGL_INIT_PROC(glVertexBlendEnvfATI,          void, GLenum pname, GLfloat param);

#define glVertexStream1sATI           OGL__glVertexStream1sATI
#define glVertexStream1svATI          OGL__glVertexStream1svATI
#define glVertexStream1iATI           OGL__glVertexStream1iATI
#define glVertexStream1ivATI          OGL__glVertexStream1ivATI
#define glVertexStream1fATI           OGL__glVertexStream1fATI
#define glVertexStream1fvATI          OGL__glVertexStream1fvATI
#define glVertexStream1dATI           OGL__glVertexStream1dATI
#define glVertexStream1dvATI          OGL__glVertexStream1dvATI
#define glVertexStream2sATI           OGL__glVertexStream2sATI
#define glVertexStream2svATI          OGL__glVertexStream2svATI
#define glVertexStream2iATI           OGL__glVertexStream2iATI
#define glVertexStream2ivATI          OGL__glVertexStream2ivATI
#define glVertexStream2fATI           OGL__glVertexStream2fATI
#define glVertexStream2fvATI          OGL__glVertexStream2fvATI
#define glVertexStream2dATI           OGL__glVertexStream2dATI
#define glVertexStream2dvATI          OGL__glVertexStream2dvATI
#define glVertexStream3sATI           OGL__glVertexStream3sATI
#define glVertexStream3svATI          OGL__glVertexStream3svATI
#define glVertexStream3iATI           OGL__glVertexStream3iATI
#define glVertexStream3ivATI          OGL__glVertexStream3ivATI
#define glVertexStream3fATI           OGL__glVertexStream3fATI
#define glVertexStream3fvATI          OGL__glVertexStream3fvATI
#define glVertexStream3dATI           OGL__glVertexStream3dATI
#define glVertexStream3dvATI          OGL__glVertexStream3dvATI
#define glVertexStream4sATI           OGL__glVertexStream4sATI
#define glVertexStream4svATI          OGL__glVertexStream4svATI
#define glVertexStream4iATI           OGL__glVertexStream4iATI
#define glVertexStream4ivATI          OGL__glVertexStream4ivATI
#define glVertexStream4fATI           OGL__glVertexStream4fATI
#define glVertexStream4fvATI          OGL__glVertexStream4fvATI
#define glVertexStream4dATI           OGL__glVertexStream4dATI
#define glVertexStream4dvATI          OGL__glVertexStream4dvATI
#define glNormalStream3bATI           OGL__glNormalStream3bATI
#define glNormalStream3bvATI          OGL__glNormalStream3bvATI
#define glNormalStream3sATI           OGL__glNormalStream3sATI
#define glNormalStream3svATI          OGL__glNormalStream3svATI
#define glNormalStream3iATI           OGL__glNormalStream3iATI
#define glNormalStream3ivATI          OGL__glNormalStream3ivATI
#define glNormalStream3fATI           OGL__glNormalStream3fATI
#define glNormalStream3fvATI          OGL__glNormalStream3fvATI
#define glNormalStream3dATI           OGL__glNormalStream3dATI
#define glNormalStream3dvATI          OGL__glNormalStream3dvATI
#define glClientActiveVertexStreamATI OGL__glClientActiveVertexStreamATI
#define glVertexBlendEnviATI          OGL__glVertexBlendEnviATI
#define glVertexBlendEnvfATI          OGL__glVertexBlendEnvfATI

#endif // GL_ATI_vertex_streams

#endif // OPENGL_INCLUDE_GL_ATI_vertex_streams

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_422_pixels
#define GL_EXT_422_pixels 1

#define GL_422_EXT                0x80CC
#define GL_422_REV_EXT            0x80CD
#define GL_422_AVERAGE_EXT        0x80CE
#define GL_422_REV_AVERAGE_EXT    0x80CF

#endif // GL_EXT_422_pixels

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_EGL_image_storage

#ifndef GL_EXT_EGL_image_storage
#define GL_EXT_EGL_image_storage 1

OPENGL_INIT_PROC(glEGLImageTargetTexStorageEXT,     void, GLenum target, GLeglImageOES image, const GLint* attrib_list);
OPENGL_INIT_PROC(glEGLImageTargetTextureStorageEXT, void, GLuint texture, GLeglImageOES image, const GLint* attrib_list);

#define glEGLImageTargetTexStorageEXT     OGL__glEGLImageTargetTexStorageEXT
#define glEGLImageTargetTextureStorageEXT OGL__glEGLImageTargetTextureStorageEXT

#endif // GL_EXT_EGL_image_storage

#endif // OPENGL_INCLUDE_GL_EXT_EGL_image_storage

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_abgr
#define GL_EXT_abgr 1

#define GL_ABGR_EXT    0x8000

#endif // GL_EXT_abgr

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_bgra
#define GL_EXT_bgra 1

#define GL_BGR_EXT     0x80E0
#define GL_BGRA_EXT    0x80E1

#endif // GL_EXT_bgra

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_bindable_uniform

#ifndef GL_EXT_bindable_uniform
#define GL_EXT_bindable_uniform 1

#define GL_MAX_VERTEX_BINDABLE_UNIFORMS_EXT      0x8DE2
#define GL_MAX_FRAGMENT_BINDABLE_UNIFORMS_EXT    0x8DE3
#define GL_MAX_GEOMETRY_BINDABLE_UNIFORMS_EXT    0x8DE4
#define GL_MAX_BINDABLE_UNIFORM_SIZE_EXT         0x8DED
#define GL_UNIFORM_BUFFER_EXT                    0x8DEE
#define GL_UNIFORM_BUFFER_BINDING_EXT            0x8DEF

OPENGL_INIT_PROC(glUniformBufferEXT,        void,     GLuint program, GLint location, GLuint buffer);
OPENGL_INIT_PROC(glGetUniformBufferSizeEXT, GLint,    GLuint program, GLint location);
OPENGL_INIT_PROC(glGetUniformOffsetEXT,     GLintptr, GLuint program, GLint location);

#define glUniformBufferEXT        OGL__glUniformBufferEXT
#define glGetUniformBufferSizeEXT OGL__glGetUniformBufferSizeEXT
#define glGetUniformOffsetEXT     OGL__glGetUniformOffsetEXT

#endif // GL_EXT_bindable_uniform

#endif // OPENGL_INCLUDE_GL_EXT_bindable_uniform

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_blend_color

#ifndef GL_EXT_blend_color
#define GL_EXT_blend_color 1

#define GL_CONSTANT_COLOR_EXT              0x8001
#define GL_ONE_MINUS_CONSTANT_COLOR_EXT    0x8002
#define GL_CONSTANT_ALPHA_EXT              0x8003
#define GL_ONE_MINUS_CONSTANT_ALPHA_EXT    0x8004
#define GL_BLEND_COLOR_EXT                 0x8005

OPENGL_INIT_PROC(glBlendColorEXT, void, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
#define glBlendColorEXT OGL__glBlendColorEXT

#endif // GL_EXT_blend_color

#endif // OPENGL_INCLUDE_GL_EXT_blend_color

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_blend_equation_separate

#ifndef GL_EXT_blend_equation_separate
#define GL_EXT_blend_equation_separate 1

#define GL_BLEND_EQUATION_RGB_EXT      0x8009
#define GL_BLEND_EQUATION_ALPHA_EXT    0x883D

OPENGL_INIT_PROC(glBlendEquationSeparateEXT, void, GLenum modeRGB, GLenum modeAlpha);
#define glBlendEquationSeparateEXT OGL__glBlendEquationSeparateEXT

#endif // GL_EXT_blend_equation_separate

#endif // OPENGL_INCLUDE_GL_EXT_blend_equation_separate

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_blend_func_separate

#ifndef GL_EXT_blend_func_separate
#define GL_EXT_blend_func_separate 1

#define GL_BLEND_DST_RGB_EXT      0x80C8
#define GL_BLEND_SRC_RGB_EXT      0x80C9
#define GL_BLEND_DST_ALPHA_EXT    0x80CA
#define GL_BLEND_SRC_ALPHA_EXT    0x80CB

OPENGL_INIT_PROC(glBlendFuncSeparateEXT, void, GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
#define glBlendFuncSeparateEXT OGL__glBlendFuncSeparateEXT

#endif // GL_EXT_blend_func_separate

#endif // OPENGL_INCLUDE_GL_EXT_blend_func_separate

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_blend_logic_op
#define GL_EXT_blend_logic_op 1

#endif // GL_EXT_blend_logic_op

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_blend_minmax

#ifndef GL_EXT_blend_minmax
#define GL_EXT_blend_minmax 1

#define GL_MIN_EXT               0x8007
#define GL_MAX_EXT               0x8008
#define GL_FUNC_ADD_EXT          0x8006
#define GL_BLEND_EQUATION_EXT    0x8009

OPENGL_INIT_PROC(glBlendEquationEXT, void, GLenum mode);
#define glBlendEquationEXT OGL__glBlendEquationEXT

#endif // GL_EXT_blend_minmax

#endif // OPENGL_INCLUDE_GL_EXT_blend_minmax

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_blend_subtract
#define GL_EXT_blend_subtract 1

#define GL_FUNC_SUBTRACT_EXT            0x800A
#define GL_FUNC_REVERSE_SUBTRACT_EXT    0x800B

#endif // GL_EXT_blend_subtract

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_clip_volume_hint
#define GL_EXT_clip_volume_hint 1

#define GL_CLIP_VOLUME_CLIPPING_HINT_EXT    0x80F0

#endif // GL_EXT_clip_volume_hint

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_cmyka
#define GL_EXT_cmyka 1

#define GL_CMYK_EXT                0x800C
#define GL_CMYKA_EXT               0x800D
#define GL_PACK_CMYK_HINT_EXT      0x800E
#define GL_UNPACK_CMYK_HINT_EXT    0x800F

#endif // GL_EXT_cmyka

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_color_subtable

#ifndef GL_EXT_color_subtable
#define GL_EXT_color_subtable 1

OPENGL_INIT_PROC(glColorSubTableEXT,     void, GLenum target, GLsizei start, GLsizei count, GLenum format, GLenum type, const void *data);
OPENGL_INIT_PROC(glCopyColorSubTableEXT, void, GLenum target, GLsizei start, GLint x, GLint y, GLsizei width);

#define glColorSubTableEXT     OGL__glColorSubTableEXT
#define glCopyColorSubTableEXT OGL__glCopyColorSubTableEXT

#endif // GL_EXT_color_subtable

#endif // OPENGL_INCLUDE_GL_EXT_color_subtable

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_compiled_vertex_array

#ifndef GL_EXT_compiled_vertex_array
#define GL_EXT_compiled_vertex_array 1

#define GL_ARRAY_ELEMENT_LOCK_FIRST_EXT    0x81A8
#define GL_ARRAY_ELEMENT_LOCK_COUNT_EXT    0x81A9

OPENGL_INIT_PROC(glLockArraysEXT,   void, GLint first, GLsizei count);
OPENGL_INIT_PROC(glUnlockArraysEXT, void, void);

#define glLockArraysEXT   OGL__glLockArraysEXT
#define glUnlockArraysEXT OGL__glUnlockArraysEXT

#endif // GL_EXT_compiled_vertex_array

#endif // OPENGL_INCLUDE_GL_EXT_compiled_vertex_array

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_convolution

#ifndef GL_EXT_convolution
#define GL_EXT_convolution 1

#define GL_CONVOLUTION_1D_EXT                  0x8010
#define GL_CONVOLUTION_2D_EXT                  0x8011
#define GL_SEPARABLE_2D_EXT                    0x8012
#define GL_CONVOLUTION_BORDER_MODE_EXT         0x8013
#define GL_CONVOLUTION_FILTER_SCALE_EXT        0x8014
#define GL_CONVOLUTION_FILTER_BIAS_EXT         0x8015
#define GL_REDUCE_EXT                          0x8016
#define GL_CONVOLUTION_FORMAT_EXT              0x8017
#define GL_CONVOLUTION_WIDTH_EXT               0x8018
#define GL_CONVOLUTION_HEIGHT_EXT              0x8019
#define GL_MAX_CONVOLUTION_WIDTH_EXT           0x801A
#define GL_MAX_CONVOLUTION_HEIGHT_EXT          0x801B
#define GL_POST_CONVOLUTION_RED_SCALE_EXT      0x801C
#define GL_POST_CONVOLUTION_GREEN_SCALE_EXT    0x801D
#define GL_POST_CONVOLUTION_BLUE_SCALE_EXT     0x801E
#define GL_POST_CONVOLUTION_ALPHA_SCALE_EXT    0x801F
#define GL_POST_CONVOLUTION_RED_BIAS_EXT       0x8020
#define GL_POST_CONVOLUTION_GREEN_BIAS_EXT     0x8021
#define GL_POST_CONVOLUTION_BLUE_BIAS_EXT      0x8022
#define GL_POST_CONVOLUTION_ALPHA_BIAS_EXT     0x8023

OPENGL_INIT_PROC(glConvolutionFilter1DEXT,       void, GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *image);
OPENGL_INIT_PROC(glConvolutionFilter2DEXT,       void, GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *image);
OPENGL_INIT_PROC(glConvolutionParameterfEXT,     void, GLenum target, GLenum pname, GLfloat params);
OPENGL_INIT_PROC(glConvolutionParameterfvEXT,    void, GLenum target, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glConvolutionParameteriEXT,     void, GLenum target, GLenum pname, GLint params);
OPENGL_INIT_PROC(glConvolutionParameterivEXT,    void, GLenum target, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glCopyConvolutionFilter1DEXT,   void, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
OPENGL_INIT_PROC(glCopyConvolutionFilter2DEXT,   void, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glGetConvolutionFilterEXT,      void, GLenum target, GLenum format, GLenum type, void *image);
OPENGL_INIT_PROC(glGetConvolutionParameterfvEXT, void, GLenum target, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetConvolutionParameterivEXT, void, GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetSeparableFilterEXT,        void, GLenum target, GLenum format, GLenum type, void *row, void *column, void *span);
OPENGL_INIT_PROC(glSeparableFilter2DEXT,         void, GLenum target, GLenum internalformat, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *row, const void *column);

#define glConvolutionFilter1DEXT       OGL__glConvolutionFilter1DEXT
#define glConvolutionFilter2DEXT       OGL__glConvolutionFilter2DEXT
#define glConvolutionParameterfEXT     OGL__glConvolutionParameterfEXT
#define glConvolutionParameterfvEXT    OGL__glConvolutionParameterfvEXT
#define glConvolutionParameteriEXT     OGL__glConvolutionParameteriEXT
#define glConvolutionParameterivEXT    OGL__glConvolutionParameterivEXT
#define glCopyConvolutionFilter1DEXT   OGL__glCopyConvolutionFilter1DEXT
#define glCopyConvolutionFilter2DEXT   OGL__glCopyConvolutionFilter2DEXT
#define glGetConvolutionFilterEXT      OGL__glGetConvolutionFilterEXT
#define glGetConvolutionParameterfvEXT OGL__glGetConvolutionParameterfvEXT
#define glGetConvolutionParameterivEXT OGL__glGetConvolutionParameterivEXT
#define glGetSeparableFilterEXT        OGL__glGetSeparableFilterEXT
#define glSeparableFilter2DEXT         OGL__glSeparableFilter2DEXT

#endif // GL_EXT_convolution

#endif // OPENGL_INCLUDE_GL_EXT_convolution

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_coordinate_frame

#ifndef GL_EXT_coordinate_frame
#define GL_EXT_coordinate_frame 1

#define GL_TANGENT_ARRAY_EXT             0x8439
#define GL_BINORMAL_ARRAY_EXT            0x843A
#define GL_CURRENT_TANGENT_EXT           0x843B
#define GL_CURRENT_BINORMAL_EXT          0x843C
#define GL_TANGENT_ARRAY_TYPE_EXT        0x843E
#define GL_TANGENT_ARRAY_STRIDE_EXT      0x843F
#define GL_BINORMAL_ARRAY_TYPE_EXT       0x8440
#define GL_BINORMAL_ARRAY_STRIDE_EXT     0x8441
#define GL_TANGENT_ARRAY_POINTER_EXT     0x8442
#define GL_BINORMAL_ARRAY_POINTER_EXT    0x8443
#define GL_MAP1_TANGENT_EXT              0x8444
#define GL_MAP2_TANGENT_EXT              0x8445
#define GL_MAP1_BINORMAL_EXT             0x8446
#define GL_MAP2_BINORMAL_EXT             0x8447

OPENGL_INIT_PROC(glTangent3bEXT,       void, GLbyte tx, GLbyte ty, GLbyte tz);
OPENGL_INIT_PROC(glTangent3bvEXT,      void, const GLbyte *v);
OPENGL_INIT_PROC(glTangent3dEXT,       void, GLdouble tx, GLdouble ty, GLdouble tz);
OPENGL_INIT_PROC(glTangent3dvEXT,      void, const GLdouble *v);
OPENGL_INIT_PROC(glTangent3fEXT,       void, GLfloat tx, GLfloat ty, GLfloat tz);
OPENGL_INIT_PROC(glTangent3fvEXT,      void, const GLfloat *v);
OPENGL_INIT_PROC(glTangent3iEXT,       void, GLint tx, GLint ty, GLint tz);
OPENGL_INIT_PROC(glTangent3ivEXT,      void, const GLint *v);
OPENGL_INIT_PROC(glTangent3sEXT,       void, GLshort tx, GLshort ty, GLshort tz);
OPENGL_INIT_PROC(glTangent3svEXT,      void, const GLshort *v);
OPENGL_INIT_PROC(glBinormal3bEXT,      void, GLbyte bx, GLbyte by, GLbyte bz);
OPENGL_INIT_PROC(glBinormal3bvEXT,     void, const GLbyte *v);
OPENGL_INIT_PROC(glBinormal3dEXT,      void, GLdouble bx, GLdouble by, GLdouble bz);
OPENGL_INIT_PROC(glBinormal3dvEXT,     void, const GLdouble *v);
OPENGL_INIT_PROC(glBinormal3fEXT,      void, GLfloat bx, GLfloat by, GLfloat bz);
OPENGL_INIT_PROC(glBinormal3fvEXT,     void, const GLfloat *v);
OPENGL_INIT_PROC(glBinormal3iEXT,      void, GLint bx, GLint by, GLint bz);
OPENGL_INIT_PROC(glBinormal3ivEXT,     void, const GLint *v);
OPENGL_INIT_PROC(glBinormal3sEXT,      void, GLshort bx, GLshort by, GLshort bz);
OPENGL_INIT_PROC(glBinormal3svEXT,     void, const GLshort *v);
OPENGL_INIT_PROC(glTangentPointerEXT,  void, GLenum type, GLsizei stride, const void *pointer);
OPENGL_INIT_PROC(glBinormalPointerEXT, void, GLenum type, GLsizei stride, const void *pointer);

#define glTangent3bEXT       OGL__glTangent3bEXT
#define glTangent3bvEXT      OGL__glTangent3bvEXT
#define glTangent3dEXT       OGL__glTangent3dEXT
#define glTangent3dvEXT      OGL__glTangent3dvEXT
#define glTangent3fEXT       OGL__glTangent3fEXT
#define glTangent3fvEXT      OGL__glTangent3fvEXT
#define glTangent3iEXT       OGL__glTangent3iEXT
#define glTangent3ivEXT      OGL__glTangent3ivEXT
#define glTangent3sEXT       OGL__glTangent3sEXT
#define glTangent3svEXT      OGL__glTangent3svEXT
#define glBinormal3bEXT      OGL__glBinormal3bEXT
#define glBinormal3bvEXT     OGL__glBinormal3bvEXT
#define glBinormal3dEXT      OGL__glBinormal3dEXT
#define glBinormal3dvEXT     OGL__glBinormal3dvEXT
#define glBinormal3fEXT      OGL__glBinormal3fEXT
#define glBinormal3fvEXT     OGL__glBinormal3fvEXT
#define glBinormal3iEXT      OGL__glBinormal3iEXT
#define glBinormal3ivEXT     OGL__glBinormal3ivEXT
#define glBinormal3sEXT      OGL__glBinormal3sEXT
#define glBinormal3svEXT     OGL__glBinormal3svEXT
#define glTangentPointerEXT  OGL__glTangentPointerEXT
#define glBinormalPointerEXT OGL__glBinormalPointerEXT

#endif // GL_EXT_coordinate_frame

#endif // OPENGL_INCLUDE_GL_EXT_coordinate_frame

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_copy_texture

#ifndef GL_EXT_copy_texture
#define GL_EXT_copy_texture 1

OPENGL_INIT_PROC(glCopyTexImage1DEXT,    void, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
OPENGL_INIT_PROC(glCopyTexImage2DEXT,    void, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
OPENGL_INIT_PROC(glCopyTexSubImage1DEXT, void, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
OPENGL_INIT_PROC(glCopyTexSubImage2DEXT, void, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glCopyTexSubImage3DEXT, void, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);

#define glCopyTexImage1DEXT    OGL__glCopyTexImage1DEXT
#define glCopyTexImage2DEXT    OGL__glCopyTexImage2DEXT
#define glCopyTexSubImage1DEXT OGL__glCopyTexSubImage1DEXT
#define glCopyTexSubImage2DEXT OGL__glCopyTexSubImage2DEXT
#define glCopyTexSubImage3DEXT OGL__glCopyTexSubImage3DEXT

#endif // GL_EXT_copy_texture

#endif // OPENGL_INCLUDE_GL_EXT_copy_texture

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_cull_vertex

#ifndef GL_EXT_cull_vertex
#define GL_EXT_cull_vertex 1

#define GL_CULL_VERTEX_EXT                    0x81AA
#define GL_CULL_VERTEX_EYE_POSITION_EXT       0x81AB
#define GL_CULL_VERTEX_OBJECT_POSITION_EXT    0x81AC

OPENGL_INIT_PROC(glCullParameterdvEXT, void, GLenum pname, GLdouble *params);
OPENGL_INIT_PROC(glCullParameterfvEXT, void, GLenum pname, GLfloat *params);

#define glCullParameterdvEXT OGL__glCullParameterdvEXT
#define glCullParameterfvEXT OGL__glCullParameterfvEXT

#endif // GL_EXT_cull_vertex

#endif // OPENGL_INCLUDE_GL_EXT_cull_vertex

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_debug_label

#ifndef GL_EXT_debug_label
#define GL_EXT_debug_label 1

#define GL_PROGRAM_PIPELINE_OBJECT_EXT    0x8A4F
#define GL_PROGRAM_OBJECT_EXT             0x8B40
#define GL_SHADER_OBJECT_EXT              0x8B48
#define GL_BUFFER_OBJECT_EXT              0x9151
#define GL_QUERY_OBJECT_EXT               0x9153
#define GL_VERTEX_ARRAY_OBJECT_EXT        0x9154

OPENGL_INIT_PROC(glLabelObjectEXT,    void, GLenum type, GLuint object, GLsizei length, const GLchar *label);
OPENGL_INIT_PROC(glGetObjectLabelEXT, void, GLenum type, GLuint object, GLsizei bufSize, GLsizei *length, GLchar *label);

#define glLabelObjectEXT    OGL__glLabelObjectEXT
#define glGetObjectLabelEXT OGL__glGetObjectLabelEXT

#endif // GL_EXT_debug_label

#endif // OPENGL_INCLUDE_GL_EXT_debug_label

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_debug_marker

#ifndef GL_EXT_debug_marker
#define GL_EXT_debug_marker 1

OPENGL_INIT_PROC(glInsertEventMarkerEXT, void, GLsizei length, const GLchar *marker);
OPENGL_INIT_PROC(glPushGroupMarkerEXT,   void, GLsizei length, const GLchar *marker);
OPENGL_INIT_PROC(glPopGroupMarkerEXT,    void, void);

#define glInsertEventMarkerEXT OGL__glInsertEventMarkerEXT
#define glPushGroupMarkerEXT   OGL__glPushGroupMarkerEXT
#define glPopGroupMarkerEXT    OGL__glPopGroupMarkerEXT

#endif // GL_EXT_debug_marker

#endif // OPENGL_INCLUDE_GL_EXT_debug_marker

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_depth_bounds_test

#ifndef GL_EXT_depth_bounds_test
#define GL_EXT_depth_bounds_test 1

#define GL_DEPTH_BOUNDS_TEST_EXT    0x8890
#define GL_DEPTH_BOUNDS_EXT         0x8891

OPENGL_INIT_PROC(glDepthBoundsEXT, void, GLclampd zmin, GLclampd zmax);
#define glDepthBoundsEXT OGL__glDepthBoundsEXT

#endif // GL_EXT_depth_bounds_test

#endif // OPENGL_INCLUDE_GL_EXT_depth_bounds_test

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_direct_state_access

#ifndef GL_EXT_direct_state_access
#define GL_EXT_direct_state_access 1

#define GL_PROGRAM_MATRIX_EXT                0x8E2D
#define GL_TRANSPOSE_PROGRAM_MATRIX_EXT      0x8E2E
#define GL_PROGRAM_MATRIX_STACK_DEPTH_EXT    0x8E2F

OPENGL_INIT_PROC(glMatrixLoadfEXT,                                 void,      GLenum mode, const GLfloat *m);
OPENGL_INIT_PROC(glMatrixLoaddEXT,                                 void,      GLenum mode, const GLdouble *m);
OPENGL_INIT_PROC(glMatrixMultfEXT,                                 void,      GLenum mode, const GLfloat *m);
OPENGL_INIT_PROC(glMatrixMultdEXT,                                 void,      GLenum mode, const GLdouble *m);
OPENGL_INIT_PROC(glMatrixLoadIdentityEXT,                          void,      GLenum mode);
OPENGL_INIT_PROC(glMatrixRotatefEXT,                               void,      GLenum mode, GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glMatrixRotatedEXT,                               void,      GLenum mode, GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
OPENGL_INIT_PROC(glMatrixScalefEXT,                                void,      GLenum mode, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glMatrixScaledEXT,                                void,      GLenum mode, GLdouble x, GLdouble y, GLdouble z);
OPENGL_INIT_PROC(glMatrixTranslatefEXT,                            void,      GLenum mode, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glMatrixTranslatedEXT,                            void,      GLenum mode, GLdouble x, GLdouble y, GLdouble z);
OPENGL_INIT_PROC(glMatrixFrustumEXT,                               void,      GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
OPENGL_INIT_PROC(glMatrixOrthoEXT,                                 void,      GLenum mode, GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
OPENGL_INIT_PROC(glMatrixPopEXT,                                   void,      GLenum mode);
OPENGL_INIT_PROC(glMatrixPushEXT,                                  void,      GLenum mode);
OPENGL_INIT_PROC(glClientAttribDefaultEXT,                         void,      GLbitfield mask);
OPENGL_INIT_PROC(glPushClientAttribDefaultEXT,                     void,      GLbitfield mask);
OPENGL_INIT_PROC(glTextureParameterfEXT,                           void,      GLuint texture, GLenum target, GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glTextureParameterfvEXT,                          void,      GLuint texture, GLenum target, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glTextureParameteriEXT,                           void,      GLuint texture, GLenum target, GLenum pname, GLint param);
OPENGL_INIT_PROC(glTextureParameterivEXT,                          void,      GLuint texture, GLenum target, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glTextureImage1DEXT,                              void,      GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
OPENGL_INIT_PROC(glTextureImage2DEXT,                              void,      GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
OPENGL_INIT_PROC(glTextureSubImage1DEXT,                           void,      GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
OPENGL_INIT_PROC(glTextureSubImage2DEXT,                           void,      GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
OPENGL_INIT_PROC(glCopyTextureImage1DEXT,                          void,      GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
OPENGL_INIT_PROC(glCopyTextureImage2DEXT,                          void,      GLuint texture, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
OPENGL_INIT_PROC(glCopyTextureSubImage1DEXT,                       void,      GLuint texture, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
OPENGL_INIT_PROC(glCopyTextureSubImage2DEXT,                       void,      GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glGetTextureImageEXT,                             void,      GLuint texture, GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
OPENGL_INIT_PROC(glGetTextureParameterfvEXT,                       void,      GLuint texture, GLenum target, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetTextureParameterivEXT,                       void,      GLuint texture, GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetTextureLevelParameterfvEXT,                  void,      GLuint texture, GLenum target, GLint level, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetTextureLevelParameterivEXT,                  void,      GLuint texture, GLenum target, GLint level, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glTextureImage3DEXT,                              void,      GLuint texture, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
OPENGL_INIT_PROC(glTextureSubImage3DEXT,                           void,      GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
OPENGL_INIT_PROC(glCopyTextureSubImage3DEXT,                       void,      GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glBindMultiTextureEXT,                            void,      GLenum texunit, GLenum target, GLuint texture);
OPENGL_INIT_PROC(glMultiTexCoordPointerEXT,                        void,      GLenum texunit, GLint size, GLenum type, GLsizei stride, const void *pointer);
OPENGL_INIT_PROC(glMultiTexEnvfEXT,                                void,      GLenum texunit, GLenum target, GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glMultiTexEnvfvEXT,                               void,      GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glMultiTexEnviEXT,                                void,      GLenum texunit, GLenum target, GLenum pname, GLint param);
OPENGL_INIT_PROC(glMultiTexEnvivEXT,                               void,      GLenum texunit, GLenum target, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glMultiTexGendEXT,                                void,      GLenum texunit, GLenum coord, GLenum pname, GLdouble param);
OPENGL_INIT_PROC(glMultiTexGendvEXT,                               void,      GLenum texunit, GLenum coord, GLenum pname, const GLdouble *params);
OPENGL_INIT_PROC(glMultiTexGenfEXT,                                void,      GLenum texunit, GLenum coord, GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glMultiTexGenfvEXT,                               void,      GLenum texunit, GLenum coord, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glMultiTexGeniEXT,                                void,      GLenum texunit, GLenum coord, GLenum pname, GLint param);
OPENGL_INIT_PROC(glMultiTexGenivEXT,                               void,      GLenum texunit, GLenum coord, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glGetMultiTexEnvfvEXT,                            void,      GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetMultiTexEnvivEXT,                            void,      GLenum texunit, GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetMultiTexGendvEXT,                            void,      GLenum texunit, GLenum coord, GLenum pname, GLdouble *params);
OPENGL_INIT_PROC(glGetMultiTexGenfvEXT,                            void,      GLenum texunit, GLenum coord, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetMultiTexGenivEXT,                            void,      GLenum texunit, GLenum coord, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glMultiTexParameteriEXT,                          void,      GLenum texunit, GLenum target, GLenum pname, GLint param);
OPENGL_INIT_PROC(glMultiTexParameterivEXT,                         void,      GLenum texunit, GLenum target, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glMultiTexParameterfEXT,                          void,      GLenum texunit, GLenum target, GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glMultiTexParameterfvEXT,                         void,      GLenum texunit, GLenum target, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glMultiTexImage1DEXT,                             void,      GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
OPENGL_INIT_PROC(glMultiTexImage2DEXT,                             void,      GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
OPENGL_INIT_PROC(glMultiTexSubImage1DEXT,                          void,      GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
OPENGL_INIT_PROC(glMultiTexSubImage2DEXT,                          void,      GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
OPENGL_INIT_PROC(glCopyMultiTexImage1DEXT,                         void,      GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
OPENGL_INIT_PROC(glCopyMultiTexImage2DEXT,                         void,      GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
OPENGL_INIT_PROC(glCopyMultiTexSubImage1DEXT,                      void,      GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
OPENGL_INIT_PROC(glCopyMultiTexSubImage2DEXT,                      void,      GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glGetMultiTexImageEXT,                            void,      GLenum texunit, GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
OPENGL_INIT_PROC(glGetMultiTexParameterfvEXT,                      void,      GLenum texunit, GLenum target, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetMultiTexParameterivEXT,                      void,      GLenum texunit, GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetMultiTexLevelParameterfvEXT,                 void,      GLenum texunit, GLenum target, GLint level, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetMultiTexLevelParameterivEXT,                 void,      GLenum texunit, GLenum target, GLint level, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glMultiTexImage3DEXT,                             void,      GLenum texunit, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
OPENGL_INIT_PROC(glMultiTexSubImage3DEXT,                          void,      GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
OPENGL_INIT_PROC(glCopyMultiTexSubImage3DEXT,                      void,      GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glEnableClientStateIndexedEXT,                    void,      GLenum array, GLuint index);
OPENGL_INIT_PROC(glDisableClientStateIndexedEXT,                   void,      GLenum array, GLuint index);
OPENGL_INIT_PROC(glGetFloatIndexedvEXT,                            void,      GLenum target, GLuint index, GLfloat *data);
OPENGL_INIT_PROC(glGetDoubleIndexedvEXT,                           void,      GLenum target, GLuint index, GLdouble *data);
OPENGL_INIT_PROC(glGetPointerIndexedvEXT,                          void,      GLenum target, GLuint index, void **data);
OPENGL_INIT_PROC(glEnableIndexedEXT,                               void,      GLenum target, GLuint index);
OPENGL_INIT_PROC(glDisableIndexedEXT,                              void,      GLenum target, GLuint index);
OPENGL_INIT_PROC(glIsEnabledIndexedEXT,                            GLboolean, GLenum target, GLuint index);
OPENGL_INIT_PROC(glGetIntegerIndexedvEXT,                          void,      GLenum target, GLuint index, GLint *data);
OPENGL_INIT_PROC(glGetBooleanIndexedvEXT,                          void,      GLenum target, GLuint index, GLboolean *data);
OPENGL_INIT_PROC(glCompressedTextureImage3DEXT,                    void,      GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *bits);
OPENGL_INIT_PROC(glCompressedTextureImage2DEXT,                    void,      GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *bits);
OPENGL_INIT_PROC(glCompressedTextureImage1DEXT,                    void,      GLuint texture, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *bits);
OPENGL_INIT_PROC(glCompressedTextureSubImage3DEXT,                 void,      GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *bits);
OPENGL_INIT_PROC(glCompressedTextureSubImage2DEXT,                 void,      GLuint texture, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *bits);
OPENGL_INIT_PROC(glCompressedTextureSubImage1DEXT,                 void,      GLuint texture, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *bits);
OPENGL_INIT_PROC(glGetCompressedTextureImageEXT,                   void,      GLuint texture, GLenum target, GLint lod, void *img);
OPENGL_INIT_PROC(glCompressedMultiTexImage3DEXT,                   void,      GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *bits);
OPENGL_INIT_PROC(glCompressedMultiTexImage2DEXT,                   void,      GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *bits);
OPENGL_INIT_PROC(glCompressedMultiTexImage1DEXT,                   void,      GLenum texunit, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *bits);
OPENGL_INIT_PROC(glCompressedMultiTexSubImage3DEXT,                void,      GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *bits);
OPENGL_INIT_PROC(glCompressedMultiTexSubImage2DEXT,                void,      GLenum texunit, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *bits);
OPENGL_INIT_PROC(glCompressedMultiTexSubImage1DEXT,                void,      GLenum texunit, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *bits);
OPENGL_INIT_PROC(glGetCompressedMultiTexImageEXT,                  void,      GLenum texunit, GLenum target, GLint lod, void *img);
OPENGL_INIT_PROC(glMatrixLoadTransposefEXT,                        void,      GLenum mode, const GLfloat *m);
OPENGL_INIT_PROC(glMatrixLoadTransposedEXT,                        void,      GLenum mode, const GLdouble *m);
OPENGL_INIT_PROC(glMatrixMultTransposefEXT,                        void,      GLenum mode, const GLfloat *m);
OPENGL_INIT_PROC(glMatrixMultTransposedEXT,                        void,      GLenum mode, const GLdouble *m);
OPENGL_INIT_PROC(glNamedBufferDataEXT,                             void,      GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
OPENGL_INIT_PROC(glNamedBufferSubDataEXT,                          void,      GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
OPENGL_INIT_PROC(glMapNamedBufferEXT,                              void*,     GLuint buffer, GLenum access);
OPENGL_INIT_PROC(glUnmapNamedBufferEXT,                            GLboolean, GLuint buffer);
OPENGL_INIT_PROC(glGetNamedBufferParameterivEXT,                   void,      GLuint buffer, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetNamedBufferPointervEXT,                      void,      GLuint buffer, GLenum pname, void **params);
OPENGL_INIT_PROC(glGetNamedBufferSubDataEXT,                       void,      GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
OPENGL_INIT_PROC(glProgramUniform1fEXT,                            void,      GLuint program, GLint location, GLfloat v0);
OPENGL_INIT_PROC(glProgramUniform2fEXT,                            void,      GLuint program, GLint location, GLfloat v0, GLfloat v1);
OPENGL_INIT_PROC(glProgramUniform3fEXT,                            void,      GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
OPENGL_INIT_PROC(glProgramUniform4fEXT,                            void,      GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
OPENGL_INIT_PROC(glProgramUniform1iEXT,                            void,      GLuint program, GLint location, GLint v0);
OPENGL_INIT_PROC(glProgramUniform2iEXT,                            void,      GLuint program, GLint location, GLint v0, GLint v1);
OPENGL_INIT_PROC(glProgramUniform3iEXT,                            void,      GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
OPENGL_INIT_PROC(glProgramUniform4iEXT,                            void,      GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
OPENGL_INIT_PROC(glProgramUniform1fvEXT,                           void,      GLuint program, GLint location, GLsizei count, const GLfloat *value);
OPENGL_INIT_PROC(glProgramUniform2fvEXT,                           void,      GLuint program, GLint location, GLsizei count, const GLfloat *value);
OPENGL_INIT_PROC(glProgramUniform3fvEXT,                           void,      GLuint program, GLint location, GLsizei count, const GLfloat *value);
OPENGL_INIT_PROC(glProgramUniform4fvEXT,                           void,      GLuint program, GLint location, GLsizei count, const GLfloat *value);
OPENGL_INIT_PROC(glProgramUniform1ivEXT,                           void,      GLuint program, GLint location, GLsizei count, const GLint *value);
OPENGL_INIT_PROC(glProgramUniform2ivEXT,                           void,      GLuint program, GLint location, GLsizei count, const GLint *value);
OPENGL_INIT_PROC(glProgramUniform3ivEXT,                           void,      GLuint program, GLint location, GLsizei count, const GLint *value);
OPENGL_INIT_PROC(glProgramUniform4ivEXT,                           void,      GLuint program, GLint location, GLsizei count, const GLint *value);
OPENGL_INIT_PROC(glProgramUniformMatrix2fvEXT,                     void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glProgramUniformMatrix3fvEXT,                     void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glProgramUniformMatrix4fvEXT,                     void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glProgramUniformMatrix2x3fvEXT,                   void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glProgramUniformMatrix3x2fvEXT,                   void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glProgramUniformMatrix2x4fvEXT,                   void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glProgramUniformMatrix4x2fvEXT,                   void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glProgramUniformMatrix3x4fvEXT,                   void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glProgramUniformMatrix4x3fvEXT,                   void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
OPENGL_INIT_PROC(glTextureBufferEXT,                               void,      GLuint texture, GLenum target, GLenum internalformat, GLuint buffer);
OPENGL_INIT_PROC(glMultiTexBufferEXT,                              void,      GLenum texunit, GLenum target, GLenum internalformat, GLuint buffer);
OPENGL_INIT_PROC(glTextureParameterIivEXT,                         void,      GLuint texture, GLenum target, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glTextureParameterIuivEXT,                        void,      GLuint texture, GLenum target, GLenum pname, const GLuint *params);
OPENGL_INIT_PROC(glGetTextureParameterIivEXT,                      void,      GLuint texture, GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetTextureParameterIuivEXT,                     void,      GLuint texture, GLenum target, GLenum pname, GLuint *params);
OPENGL_INIT_PROC(glMultiTexParameterIivEXT,                        void,      GLenum texunit, GLenum target, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glMultiTexParameterIuivEXT,                       void,      GLenum texunit, GLenum target, GLenum pname, const GLuint *params);
OPENGL_INIT_PROC(glGetMultiTexParameterIivEXT,                     void,      GLenum texunit, GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetMultiTexParameterIuivEXT,                    void,      GLenum texunit, GLenum target, GLenum pname, GLuint *params);
OPENGL_INIT_PROC(glProgramUniform1uiEXT,                           void,      GLuint program, GLint location, GLuint v0);
OPENGL_INIT_PROC(glProgramUniform2uiEXT,                           void,      GLuint program, GLint location, GLuint v0, GLuint v1);
OPENGL_INIT_PROC(glProgramUniform3uiEXT,                           void,      GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
OPENGL_INIT_PROC(glProgramUniform4uiEXT,                           void,      GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
OPENGL_INIT_PROC(glProgramUniform1uivEXT,                          void,      GLuint program, GLint location, GLsizei count, const GLuint *value);
OPENGL_INIT_PROC(glProgramUniform2uivEXT,                          void,      GLuint program, GLint location, GLsizei count, const GLuint *value);
OPENGL_INIT_PROC(glProgramUniform3uivEXT,                          void,      GLuint program, GLint location, GLsizei count, const GLuint *value);
OPENGL_INIT_PROC(glProgramUniform4uivEXT,                          void,      GLuint program, GLint location, GLsizei count, const GLuint *value);
OPENGL_INIT_PROC(glNamedProgramLocalParameters4fvEXT,              void,      GLuint program, GLenum target, GLuint index, GLsizei count, const GLfloat *params);
OPENGL_INIT_PROC(glNamedProgramLocalParameterI4iEXT,               void,      GLuint program, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
OPENGL_INIT_PROC(glNamedProgramLocalParameterI4ivEXT,              void,      GLuint program, GLenum target, GLuint index, const GLint *params);
OPENGL_INIT_PROC(glNamedProgramLocalParametersI4ivEXT,             void,      GLuint program, GLenum target, GLuint index, GLsizei count, const GLint *params);
OPENGL_INIT_PROC(glNamedProgramLocalParameterI4uiEXT,              void,      GLuint program, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
OPENGL_INIT_PROC(glNamedProgramLocalParameterI4uivEXT,             void,      GLuint program, GLenum target, GLuint index, const GLuint *params);
OPENGL_INIT_PROC(glNamedProgramLocalParametersI4uivEXT,            void,      GLuint program, GLenum target, GLuint index, GLsizei count, const GLuint *params);
OPENGL_INIT_PROC(glGetNamedProgramLocalParameterIivEXT,            void,      GLuint program, GLenum target, GLuint index, GLint *params);
OPENGL_INIT_PROC(glGetNamedProgramLocalParameterIuivEXT,           void,      GLuint program, GLenum target, GLuint index, GLuint *params);
OPENGL_INIT_PROC(glEnableClientStateiEXT,                          void,      GLenum array, GLuint index);
OPENGL_INIT_PROC(glDisableClientStateiEXT,                         void,      GLenum array, GLuint index);
OPENGL_INIT_PROC(glGetFloati_vEXT,                                 void,      GLenum pname, GLuint index, GLfloat *params);
OPENGL_INIT_PROC(glGetDoublei_vEXT,                                void,      GLenum pname, GLuint index, GLdouble *params);
OPENGL_INIT_PROC(glGetPointeri_vEXT,                               void,      GLenum pname, GLuint index, void **params);
OPENGL_INIT_PROC(glNamedProgramStringEXT,                          void,      GLuint program, GLenum target, GLenum format, GLsizei len, const void *string);
OPENGL_INIT_PROC(glNamedProgramLocalParameter4dEXT,                void,      GLuint program, GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
OPENGL_INIT_PROC(glNamedProgramLocalParameter4dvEXT,               void,      GLuint program, GLenum target, GLuint index, const GLdouble *params);
OPENGL_INIT_PROC(glNamedProgramLocalParameter4fEXT,                void,      GLuint program, GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
OPENGL_INIT_PROC(glNamedProgramLocalParameter4fvEXT,               void,      GLuint program, GLenum target, GLuint index, const GLfloat *params);
OPENGL_INIT_PROC(glGetNamedProgramLocalParameterdvEXT,             void,      GLuint program, GLenum target, GLuint index, GLdouble *params);
OPENGL_INIT_PROC(glGetNamedProgramLocalParameterfvEXT,             void,      GLuint program, GLenum target, GLuint index, GLfloat *params);
OPENGL_INIT_PROC(glGetNamedProgramivEXT,                           void,      GLuint program, GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetNamedProgramStringEXT,                       void,      GLuint program, GLenum target, GLenum pname, void *string);
OPENGL_INIT_PROC(glNamedRenderbufferStorageEXT,                    void,      GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glGetNamedRenderbufferParameterivEXT,             void,      GLuint renderbuffer, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glNamedRenderbufferStorageMultisampleEXT,         void,      GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glNamedRenderbufferStorageMultisampleCoverageEXT, void,      GLuint renderbuffer, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glCheckNamedFramebufferStatusEXT,                 GLenum,    GLuint framebuffer, GLenum target);
OPENGL_INIT_PROC(glNamedFramebufferTexture1DEXT,                   void,      GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
OPENGL_INIT_PROC(glNamedFramebufferTexture2DEXT,                   void,      GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
OPENGL_INIT_PROC(glNamedFramebufferTexture3DEXT,                   void,      GLuint framebuffer, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
OPENGL_INIT_PROC(glNamedFramebufferRenderbufferEXT,                void,      GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
OPENGL_INIT_PROC(glGetNamedFramebufferAttachmentParameterivEXT,    void,      GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGenerateTextureMipmapEXT,                       void,      GLuint texture, GLenum target);
OPENGL_INIT_PROC(glGenerateMultiTexMipmapEXT,                      void,      GLenum texunit, GLenum target);
OPENGL_INIT_PROC(glFramebufferDrawBufferEXT,                       void,      GLuint framebuffer, GLenum mode);
OPENGL_INIT_PROC(glFramebufferDrawBuffersEXT,                      void,      GLuint framebuffer, GLsizei n, const GLenum *bufs);
OPENGL_INIT_PROC(glFramebufferReadBufferEXT,                       void,      GLuint framebuffer, GLenum mode);
OPENGL_INIT_PROC(glGetFramebufferParameterivEXT,                   void,      GLuint framebuffer, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glNamedCopyBufferSubDataEXT,                      void,      GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
OPENGL_INIT_PROC(glNamedFramebufferTextureEXT,                     void,      GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
OPENGL_INIT_PROC(glNamedFramebufferTextureLayerEXT,                void,      GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
OPENGL_INIT_PROC(glNamedFramebufferTextureFaceEXT,                 void,      GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLenum face);
OPENGL_INIT_PROC(glTextureRenderbufferEXT,                         void,      GLuint texture, GLenum target, GLuint renderbuffer);
OPENGL_INIT_PROC(glMultiTexRenderbufferEXT,                        void,      GLenum texunit, GLenum target, GLuint renderbuffer);
OPENGL_INIT_PROC(glVertexArrayVertexOffsetEXT,                     void,      GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
OPENGL_INIT_PROC(glVertexArrayColorOffsetEXT,                      void,      GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
OPENGL_INIT_PROC(glVertexArrayEdgeFlagOffsetEXT,                   void,      GLuint vaobj, GLuint buffer, GLsizei stride, GLintptr offset);
OPENGL_INIT_PROC(glVertexArrayIndexOffsetEXT,                      void,      GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
OPENGL_INIT_PROC(glVertexArrayNormalOffsetEXT,                     void,      GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
OPENGL_INIT_PROC(glVertexArrayTexCoordOffsetEXT,                   void,      GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
OPENGL_INIT_PROC(glVertexArrayMultiTexCoordOffsetEXT,              void,      GLuint vaobj, GLuint buffer, GLenum texunit, GLint size, GLenum type, GLsizei stride, GLintptr offset);
OPENGL_INIT_PROC(glVertexArrayFogCoordOffsetEXT,                   void,      GLuint vaobj, GLuint buffer, GLenum type, GLsizei stride, GLintptr offset);
OPENGL_INIT_PROC(glVertexArraySecondaryColorOffsetEXT,             void,      GLuint vaobj, GLuint buffer, GLint size, GLenum type, GLsizei stride, GLintptr offset);
OPENGL_INIT_PROC(glVertexArrayVertexAttribOffsetEXT,               void,      GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, GLintptr offset);
OPENGL_INIT_PROC(glVertexArrayVertexAttribIOffsetEXT,              void,      GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
OPENGL_INIT_PROC(glEnableVertexArrayEXT,                           void,      GLuint vaobj, GLenum array);
OPENGL_INIT_PROC(glDisableVertexArrayEXT,                          void,      GLuint vaobj, GLenum array);
OPENGL_INIT_PROC(glEnableVertexArrayAttribEXT,                     void,      GLuint vaobj, GLuint index);
OPENGL_INIT_PROC(glDisableVertexArrayAttribEXT,                    void,      GLuint vaobj, GLuint index);
OPENGL_INIT_PROC(glGetVertexArrayIntegervEXT,                      void,      GLuint vaobj, GLenum pname, GLint *param);
OPENGL_INIT_PROC(glGetVertexArrayPointervEXT,                      void,      GLuint vaobj, GLenum pname, void **param);
OPENGL_INIT_PROC(glGetVertexArrayIntegeri_vEXT,                    void,      GLuint vaobj, GLuint index, GLenum pname, GLint *param);
OPENGL_INIT_PROC(glGetVertexArrayPointeri_vEXT,                    void,      GLuint vaobj, GLuint index, GLenum pname, void **param);
OPENGL_INIT_PROC(glMapNamedBufferRangeEXT,                         void*,     GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
OPENGL_INIT_PROC(glFlushMappedNamedBufferRangeEXT,                 void,      GLuint buffer, GLintptr offset, GLsizeiptr length);
OPENGL_INIT_PROC(glNamedBufferStorageEXT,                          void,      GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
OPENGL_INIT_PROC(glClearNamedBufferDataEXT,                        void,      GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
OPENGL_INIT_PROC(glClearNamedBufferSubDataEXT,                     void,      GLuint buffer, GLenum internalformat, GLsizeiptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
OPENGL_INIT_PROC(glNamedFramebufferParameteriEXT,                  void,      GLuint framebuffer, GLenum pname, GLint param);
OPENGL_INIT_PROC(glGetNamedFramebufferParameterivEXT,              void,      GLuint framebuffer, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glProgramUniform1dEXT,                            void,      GLuint program, GLint location, GLdouble x);
OPENGL_INIT_PROC(glProgramUniform2dEXT,                            void,      GLuint program, GLint location, GLdouble x, GLdouble y);
OPENGL_INIT_PROC(glProgramUniform3dEXT,                            void,      GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z);
OPENGL_INIT_PROC(glProgramUniform4dEXT,                            void,      GLuint program, GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
OPENGL_INIT_PROC(glProgramUniform1dvEXT,                           void,      GLuint program, GLint location, GLsizei count, const GLdouble *value);
OPENGL_INIT_PROC(glProgramUniform2dvEXT,                           void,      GLuint program, GLint location, GLsizei count, const GLdouble *value);
OPENGL_INIT_PROC(glProgramUniform3dvEXT,                           void,      GLuint program, GLint location, GLsizei count, const GLdouble *value);
OPENGL_INIT_PROC(glProgramUniform4dvEXT,                           void,      GLuint program, GLint location, GLsizei count, const GLdouble *value);
OPENGL_INIT_PROC(glProgramUniformMatrix2dvEXT,                     void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glProgramUniformMatrix3dvEXT,                     void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glProgramUniformMatrix4dvEXT,                     void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glProgramUniformMatrix2x3dvEXT,                   void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glProgramUniformMatrix2x4dvEXT,                   void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glProgramUniformMatrix3x2dvEXT,                   void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glProgramUniformMatrix3x4dvEXT,                   void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glProgramUniformMatrix4x2dvEXT,                   void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glProgramUniformMatrix4x3dvEXT,                   void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
OPENGL_INIT_PROC(glTextureBufferRangeEXT,                          void,      GLuint texture, GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
OPENGL_INIT_PROC(glTextureStorage1DEXT,                            void,      GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
OPENGL_INIT_PROC(glTextureStorage2DEXT,                            void,      GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glTextureStorage3DEXT,                            void,      GLuint texture, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
OPENGL_INIT_PROC(glTextureStorage2DMultisampleEXT,                 void,      GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
OPENGL_INIT_PROC(glTextureStorage3DMultisampleEXT,                 void,      GLuint texture, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
OPENGL_INIT_PROC(glVertexArrayBindVertexBufferEXT,                 void,      GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
OPENGL_INIT_PROC(glVertexArrayVertexAttribFormatEXT,               void,      GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
OPENGL_INIT_PROC(glVertexArrayVertexAttribIFormatEXT,              void,      GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
OPENGL_INIT_PROC(glVertexArrayVertexAttribLFormatEXT,              void,      GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
OPENGL_INIT_PROC(glVertexArrayVertexAttribBindingEXT,              void,      GLuint vaobj, GLuint attribindex, GLuint bindingindex);
OPENGL_INIT_PROC(glVertexArrayVertexBindingDivisorEXT,             void,      GLuint vaobj, GLuint bindingindex, GLuint divisor);
OPENGL_INIT_PROC(glVertexArrayVertexAttribLOffsetEXT,              void,      GLuint vaobj, GLuint buffer, GLuint index, GLint size, GLenum type, GLsizei stride, GLintptr offset);
OPENGL_INIT_PROC(glTexturePageCommitmentEXT,                       void,      GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLboolean commit);
OPENGL_INIT_PROC(glVertexArrayVertexAttribDivisorEXT,              void,      GLuint vaobj, GLuint index, GLuint divisor);

#define glMatrixLoadfEXT                                 OGL__glMatrixLoadfEXT
#define glMatrixLoaddEXT                                 OGL__glMatrixLoaddEXT
#define glMatrixMultfEXT                                 OGL__glMatrixMultfEXT
#define glMatrixMultdEXT                                 OGL__glMatrixMultdEXT
#define glMatrixLoadIdentityEXT                          OGL__glMatrixLoadIdentityEXT
#define glMatrixRotatefEXT                               OGL__glMatrixRotatefEXT
#define glMatrixRotatedEXT                               OGL__glMatrixRotatedEXT
#define glMatrixScalefEXT                                OGL__glMatrixScalefEXT
#define glMatrixScaledEXT                                OGL__glMatrixScaledEXT
#define glMatrixTranslatefEXT                            OGL__glMatrixTranslatefEXT
#define glMatrixTranslatedEXT                            OGL__glMatrixTranslatedEXT
#define glMatrixFrustumEXT                               OGL__glMatrixFrustumEXT
#define glMatrixOrthoEXT                                 OGL__glMatrixOrthoEXT
#define glMatrixPopEXT                                   OGL__glMatrixPopEXT
#define glMatrixPushEXT                                  OGL__glMatrixPushEXT
#define glClientAttribDefaultEXT                         OGL__glClientAttribDefaultEXT
#define glPushClientAttribDefaultEXT                     OGL__glPushClientAttribDefaultEXT
#define glTextureParameterfEXT                           OGL__glTextureParameterfEXT
#define glTextureParameterfvEXT                          OGL__glTextureParameterfvEXT
#define glTextureParameteriEXT                           OGL__glTextureParameteriEXT
#define glTextureParameterivEXT                          OGL__glTextureParameterivEXT
#define glTextureImage1DEXT                              OGL__glTextureImage1DEXT
#define glTextureImage2DEXT                              OGL__glTextureImage2DEXT
#define glTextureSubImage1DEXT                           OGL__glTextureSubImage1DEXT
#define glTextureSubImage2DEXT                           OGL__glTextureSubImage2DEXT
#define glCopyTextureImage1DEXT                          OGL__glCopyTextureImage1DEXT
#define glCopyTextureImage2DEXT                          OGL__glCopyTextureImage2DEXT
#define glCopyTextureSubImage1DEXT                       OGL__glCopyTextureSubImage1DEXT
#define glCopyTextureSubImage2DEXT                       OGL__glCopyTextureSubImage2DEXT
#define glGetTextureImageEXT                             OGL__glGetTextureImageEXT
#define glGetTextureParameterfvEXT                       OGL__glGetTextureParameterfvEXT
#define glGetTextureParameterivEXT                       OGL__glGetTextureParameterivEXT
#define glGetTextureLevelParameterfvEXT                  OGL__glGetTextureLevelParameterfvEXT
#define glGetTextureLevelParameterivEXT                  OGL__glGetTextureLevelParameterivEXT
#define glTextureImage3DEXT                              OGL__glTextureImage3DEXT
#define glTextureSubImage3DEXT                           OGL__glTextureSubImage3DEXT
#define glCopyTextureSubImage3DEXT                       OGL__glCopyTextureSubImage3DEXT
#define glBindMultiTextureEXT                            OGL__glBindMultiTextureEXT
#define glMultiTexCoordPointerEXT                        OGL__glMultiTexCoordPointerEXT
#define glMultiTexEnvfEXT                                OGL__glMultiTexEnvfEXT
#define glMultiTexEnvfvEXT                               OGL__glMultiTexEnvfvEXT
#define glMultiTexEnviEXT                                OGL__glMultiTexEnviEXT
#define glMultiTexEnvivEXT                               OGL__glMultiTexEnvivEXT
#define glMultiTexGendEXT                                OGL__glMultiTexGendEXT
#define glMultiTexGendvEXT                               OGL__glMultiTexGendvEXT
#define glMultiTexGenfEXT                                OGL__glMultiTexGenfEXT
#define glMultiTexGenfvEXT                               OGL__glMultiTexGenfvEXT
#define glMultiTexGeniEXT                                OGL__glMultiTexGeniEXT
#define glMultiTexGenivEXT                               OGL__glMultiTexGenivEXT
#define glGetMultiTexEnvfvEXT                            OGL__glGetMultiTexEnvfvEXT
#define glGetMultiTexEnvivEXT                            OGL__glGetMultiTexEnvivEXT
#define glGetMultiTexGendvEXT                            OGL__glGetMultiTexGendvEXT
#define glGetMultiTexGenfvEXT                            OGL__glGetMultiTexGenfvEXT
#define glGetMultiTexGenivEXT                            OGL__glGetMultiTexGenivEXT
#define glMultiTexParameteriEXT                          OGL__glMultiTexParameteriEXT
#define glMultiTexParameterivEXT                         OGL__glMultiTexParameterivEXT
#define glMultiTexParameterfEXT                          OGL__glMultiTexParameterfEXT
#define glMultiTexParameterfvEXT                         OGL__glMultiTexParameterfvEXT
#define glMultiTexImage1DEXT                             OGL__glMultiTexImage1DEXT
#define glMultiTexImage2DEXT                             OGL__glMultiTexImage2DEXT
#define glMultiTexSubImage1DEXT                          OGL__glMultiTexSubImage1DEXT
#define glMultiTexSubImage2DEXT                          OGL__glMultiTexSubImage2DEXT
#define glCopyMultiTexImage1DEXT                         OGL__glCopyMultiTexImage1DEXT
#define glCopyMultiTexImage2DEXT                         OGL__glCopyMultiTexImage2DEXT
#define glCopyMultiTexSubImage1DEXT                      OGL__glCopyMultiTexSubImage1DEXT
#define glCopyMultiTexSubImage2DEXT                      OGL__glCopyMultiTexSubImage2DEXT
#define glGetMultiTexImageEXT                            OGL__glGetMultiTexImageEXT
#define glGetMultiTexParameterfvEXT                      OGL__glGetMultiTexParameterfvEXT
#define glGetMultiTexParameterivEXT                      OGL__glGetMultiTexParameterivEXT
#define glGetMultiTexLevelParameterfvEXT                 OGL__glGetMultiTexLevelParameterfvEXT
#define glGetMultiTexLevelParameterivEXT                 OGL__glGetMultiTexLevelParameterivEXT
#define glMultiTexImage3DEXT                             OGL__glMultiTexImage3DEXT
#define glMultiTexSubImage3DEXT                          OGL__glMultiTexSubImage3DEXT
#define glCopyMultiTexSubImage3DEXT                      OGL__glCopyMultiTexSubImage3DEXT
#define glEnableClientStateIndexedEXT                    OGL__glEnableClientStateIndexedEXT
#define glDisableClientStateIndexedEXT                   OGL__glDisableClientStateIndexedEXT
#define glGetFloatIndexedvEXT                            OGL__glGetFloatIndexedvEXT
#define glGetDoubleIndexedvEXT                           OGL__glGetDoubleIndexedvEXT
#define glGetPointerIndexedvEXT                          OGL__glGetPointerIndexedvEXT
#define glEnableIndexedEXT                               OGL__glEnableIndexedEXT
#define glDisableIndexedEXT                              OGL__glDisableIndexedEXT
#define glIsEnabledIndexedEXT                            OGL__glIsEnabledIndexedEXT
#define glGetIntegerIndexedvEXT                          OGL__glGetIntegerIndexedvEXT
#define glGetBooleanIndexedvEXT                          OGL__glGetBooleanIndexedvEXT
#define glCompressedTextureImage3DEXT                    OGL__glCompressedTextureImage3DEXT
#define glCompressedTextureImage2DEXT                    OGL__glCompressedTextureImage2DEXT
#define glCompressedTextureImage1DEXT                    OGL__glCompressedTextureImage1DEXT
#define glCompressedTextureSubImage3DEXT                 OGL__glCompressedTextureSubImage3DEXT
#define glCompressedTextureSubImage2DEXT                 OGL__glCompressedTextureSubImage2DEXT
#define glCompressedTextureSubImage1DEXT                 OGL__glCompressedTextureSubImage1DEXT
#define glGetCompressedTextureImageEXT                   OGL__glGetCompressedTextureImageEXT
#define glCompressedMultiTexImage3DEXT                   OGL__glCompressedMultiTexImage3DEXT
#define glCompressedMultiTexImage2DEXT                   OGL__glCompressedMultiTexImage2DEXT
#define glCompressedMultiTexImage1DEXT                   OGL__glCompressedMultiTexImage1DEXT
#define glCompressedMultiTexSubImage3DEXT                OGL__glCompressedMultiTexSubImage3DEXT
#define glCompressedMultiTexSubImage2DEXT                OGL__glCompressedMultiTexSubImage2DEXT
#define glCompressedMultiTexSubImage1DEXT                OGL__glCompressedMultiTexSubImage1DEXT
#define glGetCompressedMultiTexImageEXT                  OGL__glGetCompressedMultiTexImageEXT
#define glMatrixLoadTransposefEXT                        OGL__glMatrixLoadTransposefEXT
#define glMatrixLoadTransposedEXT                        OGL__glMatrixLoadTransposedEXT
#define glMatrixMultTransposefEXT                        OGL__glMatrixMultTransposefEXT
#define glMatrixMultTransposedEXT                        OGL__glMatrixMultTransposedEXT
#define glNamedBufferDataEXT                             OGL__glNamedBufferDataEXT
#define glNamedBufferSubDataEXT                          OGL__glNamedBufferSubDataEXT
#define glMapNamedBufferEXT                              OGL__glMapNamedBufferEXT
#define glUnmapNamedBufferEXT                            OGL__glUnmapNamedBufferEXT
#define glGetNamedBufferParameterivEXT                   OGL__glGetNamedBufferParameterivEXT
#define glGetNamedBufferPointervEXT                      OGL__glGetNamedBufferPointervEXT
#define glGetNamedBufferSubDataEXT                       OGL__glGetNamedBufferSubDataEXT
#define glProgramUniform1fEXT                            OGL__glProgramUniform1fEXT
#define glProgramUniform2fEXT                            OGL__glProgramUniform2fEXT
#define glProgramUniform3fEXT                            OGL__glProgramUniform3fEXT
#define glProgramUniform4fEXT                            OGL__glProgramUniform4fEXT
#define glProgramUniform1iEXT                            OGL__glProgramUniform1iEXT
#define glProgramUniform2iEXT                            OGL__glProgramUniform2iEXT
#define glProgramUniform3iEXT                            OGL__glProgramUniform3iEXT
#define glProgramUniform4iEXT                            OGL__glProgramUniform4iEXT
#define glProgramUniform1fvEXT                           OGL__glProgramUniform1fvEXT
#define glProgramUniform2fvEXT                           OGL__glProgramUniform2fvEXT
#define glProgramUniform3fvEXT                           OGL__glProgramUniform3fvEXT
#define glProgramUniform4fvEXT                           OGL__glProgramUniform4fvEXT
#define glProgramUniform1ivEXT                           OGL__glProgramUniform1ivEXT
#define glProgramUniform2ivEXT                           OGL__glProgramUniform2ivEXT
#define glProgramUniform3ivEXT                           OGL__glProgramUniform3ivEXT
#define glProgramUniform4ivEXT                           OGL__glProgramUniform4ivEXT
#define glProgramUniformMatrix2fvEXT                     OGL__glProgramUniformMatrix2fvEXT
#define glProgramUniformMatrix3fvEXT                     OGL__glProgramUniformMatrix3fvEXT
#define glProgramUniformMatrix4fvEXT                     OGL__glProgramUniformMatrix4fvEXT
#define glProgramUniformMatrix2x3fvEXT                   OGL__glProgramUniformMatrix2x3fvEXT
#define glProgramUniformMatrix3x2fvEXT                   OGL__glProgramUniformMatrix3x2fvEXT
#define glProgramUniformMatrix2x4fvEXT                   OGL__glProgramUniformMatrix2x4fvEXT
#define glProgramUniformMatrix4x2fvEXT                   OGL__glProgramUniformMatrix4x2fvEXT
#define glProgramUniformMatrix3x4fvEXT                   OGL__glProgramUniformMatrix3x4fvEXT
#define glProgramUniformMatrix4x3fvEXT                   OGL__glProgramUniformMatrix4x3fvEXT
#define glTextureBufferEXT                               OGL__glTextureBufferEXT
#define glMultiTexBufferEXT                              OGL__glMultiTexBufferEXT
#define glTextureParameterIivEXT                         OGL__glTextureParameterIivEXT
#define glTextureParameterIuivEXT                        OGL__glTextureParameterIuivEXT
#define glGetTextureParameterIivEXT                      OGL__glGetTextureParameterIivEXT
#define glGetTextureParameterIuivEXT                     OGL__glGetTextureParameterIuivEXT
#define glMultiTexParameterIivEXT                        OGL__glMultiTexParameterIivEXT
#define glMultiTexParameterIuivEXT                       OGL__glMultiTexParameterIuivEXT
#define glGetMultiTexParameterIivEXT                     OGL__glGetMultiTexParameterIivEXT
#define glGetMultiTexParameterIuivEXT                    OGL__glGetMultiTexParameterIuivEXT
#define glProgramUniform1uiEXT                           OGL__glProgramUniform1uiEXT
#define glProgramUniform2uiEXT                           OGL__glProgramUniform2uiEXT
#define glProgramUniform3uiEXT                           OGL__glProgramUniform3uiEXT
#define glProgramUniform4uiEXT                           OGL__glProgramUniform4uiEXT
#define glProgramUniform1uivEXT                          OGL__glProgramUniform1uivEXT
#define glProgramUniform2uivEXT                          OGL__glProgramUniform2uivEXT
#define glProgramUniform3uivEXT                          OGL__glProgramUniform3uivEXT
#define glProgramUniform4uivEXT                          OGL__glProgramUniform4uivEXT
#define glNamedProgramLocalParameters4fvEXT              OGL__glNamedProgramLocalParameters4fvEXT
#define glNamedProgramLocalParameterI4iEXT               OGL__glNamedProgramLocalParameterI4iEXT
#define glNamedProgramLocalParameterI4ivEXT              OGL__glNamedProgramLocalParameterI4ivEXT
#define glNamedProgramLocalParametersI4ivEXT             OGL__glNamedProgramLocalParametersI4ivEXT
#define glNamedProgramLocalParameterI4uiEXT              OGL__glNamedProgramLocalParameterI4uiEXT
#define glNamedProgramLocalParameterI4uivEXT             OGL__glNamedProgramLocalParameterI4uivEXT
#define glNamedProgramLocalParametersI4uivEXT            OGL__glNamedProgramLocalParametersI4uivEXT
#define glGetNamedProgramLocalParameterIivEXT            OGL__glGetNamedProgramLocalParameterIivEXT
#define glGetNamedProgramLocalParameterIuivEXT           OGL__glGetNamedProgramLocalParameterIuivEXT
#define glEnableClientStateiEXT                          OGL__glEnableClientStateiEXT
#define glDisableClientStateiEXT                         OGL__glDisableClientStateiEXT
#define glGetFloati_vEXT                                 OGL__glGetFloati_vEXT
#define glGetDoublei_vEXT                                OGL__glGetDoublei_vEXT
#define glGetPointeri_vEXT                               OGL__glGetPointeri_vEXT
#define glNamedProgramStringEXT                          OGL__glNamedProgramStringEXT
#define glNamedProgramLocalParameter4dEXT                OGL__glNamedProgramLocalParameter4dEXT
#define glNamedProgramLocalParameter4dvEXT               OGL__glNamedProgramLocalParameter4dvEXT
#define glNamedProgramLocalParameter4fEXT                OGL__glNamedProgramLocalParameter4fEXT
#define glNamedProgramLocalParameter4fvEXT               OGL__glNamedProgramLocalParameter4fvEXT
#define glGetNamedProgramLocalParameterdvEXT             OGL__glGetNamedProgramLocalParameterdvEXT
#define glGetNamedProgramLocalParameterfvEXT             OGL__glGetNamedProgramLocalParameterfvEXT
#define glGetNamedProgramivEXT                           OGL__glGetNamedProgramivEXT
#define glGetNamedProgramStringEXT                       OGL__glGetNamedProgramStringEXT
#define glNamedRenderbufferStorageEXT                    OGL__glNamedRenderbufferStorageEXT
#define glGetNamedRenderbufferParameterivEXT             OGL__glGetNamedRenderbufferParameterivEXT
#define glNamedRenderbufferStorageMultisampleEXT         OGL__glNamedRenderbufferStorageMultisampleEXT
#define glNamedRenderbufferStorageMultisampleCoverageEXT OGL__glNamedRenderbufferStorageMultisampleCoverageEXT
#define glCheckNamedFramebufferStatusEXT                 OGL__glCheckNamedFramebufferStatusEXT
#define glNamedFramebufferTexture1DEXT                   OGL__glNamedFramebufferTexture1DEXT
#define glNamedFramebufferTexture2DEXT                   OGL__glNamedFramebufferTexture2DEXT
#define glNamedFramebufferTexture3DEXT                   OGL__glNamedFramebufferTexture3DEXT
#define glNamedFramebufferRenderbufferEXT                OGL__glNamedFramebufferRenderbufferEXT
#define glGetNamedFramebufferAttachmentParameterivEXT    OGL__glGetNamedFramebufferAttachmentParameterivEXT
#define glGenerateTextureMipmapEXT                       OGL__glGenerateTextureMipmapEXT
#define glGenerateMultiTexMipmapEXT                      OGL__glGenerateMultiTexMipmapEXT
#define glFramebufferDrawBufferEXT                       OGL__glFramebufferDrawBufferEXT
#define glFramebufferDrawBuffersEXT                      OGL__glFramebufferDrawBuffersEXT
#define glFramebufferReadBufferEXT                       OGL__glFramebufferReadBufferEXT
#define glGetFramebufferParameterivEXT                   OGL__glGetFramebufferParameterivEXT
#define glNamedCopyBufferSubDataEXT                      OGL__glNamedCopyBufferSubDataEXT
#define glNamedFramebufferTextureEXT                     OGL__glNamedFramebufferTextureEXT
#define glNamedFramebufferTextureLayerEXT                OGL__glNamedFramebufferTextureLayerEXT
#define glNamedFramebufferTextureFaceEXT                 OGL__glNamedFramebufferTextureFaceEXT
#define glTextureRenderbufferEXT                         OGL__glTextureRenderbufferEXT
#define glMultiTexRenderbufferEXT                        OGL__glMultiTexRenderbufferEXT
#define glVertexArrayVertexOffsetEXT                     OGL__glVertexArrayVertexOffsetEXT
#define glVertexArrayColorOffsetEXT                      OGL__glVertexArrayColorOffsetEXT
#define glVertexArrayEdgeFlagOffsetEXT                   OGL__glVertexArrayEdgeFlagOffsetEXT
#define glVertexArrayIndexOffsetEXT                      OGL__glVertexArrayIndexOffsetEXT
#define glVertexArrayNormalOffsetEXT                     OGL__glVertexArrayNormalOffsetEXT
#define glVertexArrayTexCoordOffsetEXT                   OGL__glVertexArrayTexCoordOffsetEXT
#define glVertexArrayMultiTexCoordOffsetEXT              OGL__glVertexArrayMultiTexCoordOffsetEXT
#define glVertexArrayFogCoordOffsetEXT                   OGL__glVertexArrayFogCoordOffsetEXT
#define glVertexArraySecondaryColorOffsetEXT             OGL__glVertexArraySecondaryColorOffsetEXT
#define glVertexArrayVertexAttribOffsetEXT               OGL__glVertexArrayVertexAttribOffsetEXT
#define glVertexArrayVertexAttribIOffsetEXT              OGL__glVertexArrayVertexAttribIOffsetEXT
#define glEnableVertexArrayEXT                           OGL__glEnableVertexArrayEXT
#define glDisableVertexArrayEXT                          OGL__glDisableVertexArrayEXT
#define glEnableVertexArrayAttribEXT                     OGL__glEnableVertexArrayAttribEXT
#define glDisableVertexArrayAttribEXT                    OGL__glDisableVertexArrayAttribEXT
#define glGetVertexArrayIntegervEXT                      OGL__glGetVertexArrayIntegervEXT
#define glGetVertexArrayPointervEXT                      OGL__glGetVertexArrayPointervEXT
#define glGetVertexArrayIntegeri_vEXT                    OGL__glGetVertexArrayIntegeri_vEXT
#define glGetVertexArrayPointeri_vEXT                    OGL__glGetVertexArrayPointeri_vEXT
#define glMapNamedBufferRangeEXT                         OGL__glMapNamedBufferRangeEXT
#define glFlushMappedNamedBufferRangeEXT                 OGL__glFlushMappedNamedBufferRangeEXT
#define glNamedBufferStorageEXT                          OGL__glNamedBufferStorageEXT
#define glClearNamedBufferDataEXT                        OGL__glClearNamedBufferDataEXT
#define glClearNamedBufferSubDataEXT                     OGL__glClearNamedBufferSubDataEXT
#define glNamedFramebufferParameteriEXT                  OGL__glNamedFramebufferParameteriEXT
#define glGetNamedFramebufferParameterivEXT              OGL__glGetNamedFramebufferParameterivEXT
#define glProgramUniform1dEXT                            OGL__glProgramUniform1dEXT
#define glProgramUniform2dEXT                            OGL__glProgramUniform2dEXT
#define glProgramUniform3dEXT                            OGL__glProgramUniform3dEXT
#define glProgramUniform4dEXT                            OGL__glProgramUniform4dEXT
#define glProgramUniform1dvEXT                           OGL__glProgramUniform1dvEXT
#define glProgramUniform2dvEXT                           OGL__glProgramUniform2dvEXT
#define glProgramUniform3dvEXT                           OGL__glProgramUniform3dvEXT
#define glProgramUniform4dvEXT                           OGL__glProgramUniform4dvEXT
#define glProgramUniformMatrix2dvEXT                     OGL__glProgramUniformMatrix2dvEXT
#define glProgramUniformMatrix3dvEXT                     OGL__glProgramUniformMatrix3dvEXT
#define glProgramUniformMatrix4dvEXT                     OGL__glProgramUniformMatrix4dvEXT
#define glProgramUniformMatrix2x3dvEXT                   OGL__glProgramUniformMatrix2x3dvEXT
#define glProgramUniformMatrix2x4dvEXT                   OGL__glProgramUniformMatrix2x4dvEXT
#define glProgramUniformMatrix3x2dvEXT                   OGL__glProgramUniformMatrix3x2dvEXT
#define glProgramUniformMatrix3x4dvEXT                   OGL__glProgramUniformMatrix3x4dvEXT
#define glProgramUniformMatrix4x2dvEXT                   OGL__glProgramUniformMatrix4x2dvEXT
#define glProgramUniformMatrix4x3dvEXT                   OGL__glProgramUniformMatrix4x3dvEXT
#define glTextureBufferRangeEXT                          OGL__glTextureBufferRangeEXT
#define glTextureStorage1DEXT                            OGL__glTextureStorage1DEXT
#define glTextureStorage2DEXT                            OGL__glTextureStorage2DEXT
#define glTextureStorage3DEXT                            OGL__glTextureStorage3DEXT
#define glTextureStorage2DMultisampleEXT                 OGL__glTextureStorage2DMultisampleEXT
#define glTextureStorage3DMultisampleEXT                 OGL__glTextureStorage3DMultisampleEXT
#define glVertexArrayBindVertexBufferEXT                 OGL__glVertexArrayBindVertexBufferEXT
#define glVertexArrayVertexAttribFormatEXT               OGL__glVertexArrayVertexAttribFormatEXT
#define glVertexArrayVertexAttribIFormatEXT              OGL__glVertexArrayVertexAttribIFormatEXT
#define glVertexArrayVertexAttribLFormatEXT              OGL__glVertexArrayVertexAttribLFormatEXT
#define glVertexArrayVertexAttribBindingEXT              OGL__glVertexArrayVertexAttribBindingEXT
#define glVertexArrayVertexBindingDivisorEXT             OGL__glVertexArrayVertexBindingDivisorEXT
#define glVertexArrayVertexAttribLOffsetEXT              OGL__glVertexArrayVertexAttribLOffsetEXT
#define glTexturePageCommitmentEXT                       OGL__glTexturePageCommitmentEXT
#define glVertexArrayVertexAttribDivisorEXT              OGL__glVertexArrayVertexAttribDivisorEXT

#endif // GL_EXT_direct_state_access

#endif // OPENGL_INCLUDE_GL_EXT_direct_state_access

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_draw_buffers2

#ifndef GL_EXT_draw_buffers2
#define GL_EXT_draw_buffers2 1

OPENGL_INIT_PROC(glColorMaskIndexedEXT, void, GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
#define glColorMaskIndexedEXT OGL__glColorMaskIndexedEXT

#endif // GL_EXT_draw_buffers2

#endif // OPENGL_INCLUDE_GL_EXT_draw_buffers2

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_draw_instanced

#ifndef GL_EXT_draw_instanced
#define GL_EXT_draw_instanced 1

OPENGL_INIT_PROC(glDrawArraysInstancedEXT,   void, GLenum mode, GLint start, GLsizei count, GLsizei primcount);
OPENGL_INIT_PROC(glDrawElementsInstancedEXT, void, GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei primcount);

#define glDrawArraysInstancedEXT   OGL__glDrawArraysInstancedEXT
#define glDrawElementsInstancedEXT OGL__glDrawElementsInstancedEXT

#endif // GL_EXT_draw_instanced

#endif // OPENGL_INCLUDE_GL_EXT_draw_instanced

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_draw_range_elements

#ifndef GL_EXT_draw_range_elements
#define GL_EXT_draw_range_elements 1

#define GL_MAX_ELEMENTS_VERTICES_EXT    0x80E8
#define GL_MAX_ELEMENTS_INDICES_EXT     0x80E9

OPENGL_INIT_PROC(glDrawRangeElementsEXT, void, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
#define glDrawRangeElementsEXT OGL__glDrawRangeElementsEXT

#endif // GL_EXT_draw_range_elements

#endif // OPENGL_INCLUDE_GL_EXT_draw_range_elements

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_external_buffer

#ifndef GL_EXT_external_buffer
#define GL_EXT_external_buffer 1

OPENGL_INIT_PROC(glBufferStorageExternalEXT,      void, GLenum target, GLintptr offset, GLsizeiptr size, GLeglClientBufferEXT clientBuffer, GLbitfield flags);
OPENGL_INIT_PROC(glNamedBufferStorageExternalEXT, void, GLuint buffer, GLintptr offset, GLsizeiptr size, GLeglClientBufferEXT clientBuffer, GLbitfield flags);

#define glBufferStorageExternalEXT      OGL__glBufferStorageExternalEXT
#define glNamedBufferStorageExternalEXT OGL__glNamedBufferStorageExternalEXT

#endif // GL_EXT_external_buffer

#endif // OPENGL_INCLUDE_GL_EXT_external_buffer

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_fog_coord

#ifndef GL_EXT_fog_coord
#define GL_EXT_fog_coord 1

#define GL_FOG_COORDINATE_SOURCE_EXT           0x8450
#define GL_FOG_COORDINATE_EXT                  0x8451
#define GL_FRAGMENT_DEPTH_EXT                  0x8452
#define GL_CURRENT_FOG_COORDINATE_EXT          0x8453
#define GL_FOG_COORDINATE_ARRAY_TYPE_EXT       0x8454
#define GL_FOG_COORDINATE_ARRAY_STRIDE_EXT     0x8455
#define GL_FOG_COORDINATE_ARRAY_POINTER_EXT    0x8456
#define GL_FOG_COORDINATE_ARRAY_EXT            0x8457

OPENGL_INIT_PROC(glFogCoordfEXT,       void, GLfloat coord);
OPENGL_INIT_PROC(glFogCoordfvEXT,      void, const GLfloat *coord);
OPENGL_INIT_PROC(glFogCoorddEXT,       void, GLdouble coord);
OPENGL_INIT_PROC(glFogCoorddvEXT,      void, const GLdouble *coord);
OPENGL_INIT_PROC(glFogCoordPointerEXT, void, GLenum type, GLsizei stride, const void *pointer);

#define glFogCoordfEXT       OGL__glFogCoordfEXT
#define glFogCoordfvEXT      OGL__glFogCoordfvEXT
#define glFogCoorddEXT       OGL__glFogCoorddEXT
#define glFogCoorddvEXT      OGL__glFogCoorddvEXT
#define glFogCoordPointerEXT OGL__glFogCoordPointerEXT

#endif // GL_EXT_fog_coord

#endif // OPENGL_INCLUDE_GL_EXT_fog_coord

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_framebuffer_blit

#ifndef GL_EXT_framebuffer_blit
#define GL_EXT_framebuffer_blit 1

#define GL_READ_FRAMEBUFFER_EXT            0x8CA8
#define GL_DRAW_FRAMEBUFFER_EXT            0x8CA9
#define GL_DRAW_FRAMEBUFFER_BINDING_EXT    0x8CA6
#define GL_READ_FRAMEBUFFER_BINDING_EXT    0x8CAA

OPENGL_INIT_PROC(glBlitFramebufferEXT, void, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
#define glBlitFramebufferEXT OGL__glBlitFramebufferEXT

#endif // GL_EXT_framebuffer_blit

#endif // OPENGL_INCLUDE_GL_EXT_framebuffer_blit

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_framebuffer_multisample

#ifndef GL_EXT_framebuffer_multisample
#define GL_EXT_framebuffer_multisample 1

#define GL_RENDERBUFFER_SAMPLES_EXT                  0x8CAB
#define GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE_EXT    0x8D56
#define GL_MAX_SAMPLES_EXT                           0x8D57

OPENGL_INIT_PROC(glRenderbufferStorageMultisampleEXT, void, GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
#define glRenderbufferStorageMultisampleEXT OGL__glRenderbufferStorageMultisampleEXT

#endif // GL_EXT_framebuffer_multisample

#endif // OPENGL_INCLUDE_GL_EXT_framebuffer_multisample

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_framebuffer_multisample_blit_scaled
#define GL_EXT_framebuffer_multisample_blit_scaled 1

#define GL_SCALED_RESOLVE_FASTEST_EXT    0x90BA
#define GL_SCALED_RESOLVE_NICEST_EXT     0x90BB

#endif // GL_EXT_framebuffer_multisample_blit_scaled

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_framebuffer_object

#ifndef GL_EXT_framebuffer_object
#define GL_EXT_framebuffer_object 1

#define GL_INVALID_FRAMEBUFFER_OPERATION_EXT                   0x0506
#define GL_MAX_RENDERBUFFER_SIZE_EXT                           0x84E8
#define GL_FRAMEBUFFER_BINDING_EXT                             0x8CA6
#define GL_RENDERBUFFER_BINDING_EXT                            0x8CA7
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE_EXT              0x8CD0
#define GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME_EXT              0x8CD1
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL_EXT            0x8CD2
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE_EXT    0x8CD3
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_3D_ZOFFSET_EXT       0x8CD4
#define GL_FRAMEBUFFER_COMPLETE_EXT                            0x8CD5
#define GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT_EXT               0x8CD6
#define GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT_EXT       0x8CD7
#define GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS_EXT               0x8CD9
#define GL_FRAMEBUFFER_INCOMPLETE_FORMATS_EXT                  0x8CDA
#define GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER_EXT              0x8CDB
#define GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER_EXT              0x8CDC
#define GL_FRAMEBUFFER_UNSUPPORTED_EXT                         0x8CDD
#define GL_MAX_COLOR_ATTACHMENTS_EXT                           0x8CDF
#define GL_COLOR_ATTACHMENT0_EXT                               0x8CE0
#define GL_COLOR_ATTACHMENT1_EXT                               0x8CE1
#define GL_COLOR_ATTACHMENT2_EXT                               0x8CE2
#define GL_COLOR_ATTACHMENT3_EXT                               0x8CE3
#define GL_COLOR_ATTACHMENT4_EXT                               0x8CE4
#define GL_COLOR_ATTACHMENT5_EXT                               0x8CE5
#define GL_COLOR_ATTACHMENT6_EXT                               0x8CE6
#define GL_COLOR_ATTACHMENT7_EXT                               0x8CE7
#define GL_COLOR_ATTACHMENT8_EXT                               0x8CE8
#define GL_COLOR_ATTACHMENT9_EXT                               0x8CE9
#define GL_COLOR_ATTACHMENT10_EXT                              0x8CEA
#define GL_COLOR_ATTACHMENT11_EXT                              0x8CEB
#define GL_COLOR_ATTACHMENT12_EXT                              0x8CEC
#define GL_COLOR_ATTACHMENT13_EXT                              0x8CED
#define GL_COLOR_ATTACHMENT14_EXT                              0x8CEE
#define GL_COLOR_ATTACHMENT15_EXT                              0x8CEF
#define GL_DEPTH_ATTACHMENT_EXT                                0x8D00
#define GL_STENCIL_ATTACHMENT_EXT                              0x8D20
#define GL_FRAMEBUFFER_EXT                                     0x8D40
#define GL_RENDERBUFFER_EXT                                    0x8D41
#define GL_RENDERBUFFER_WIDTH_EXT                              0x8D42
#define GL_RENDERBUFFER_HEIGHT_EXT                             0x8D43
#define GL_RENDERBUFFER_INTERNAL_FORMAT_EXT                    0x8D44
#define GL_STENCIL_INDEX1_EXT                                  0x8D46
#define GL_STENCIL_INDEX4_EXT                                  0x8D47
#define GL_STENCIL_INDEX8_EXT                                  0x8D48
#define GL_STENCIL_INDEX16_EXT                                 0x8D49
#define GL_RENDERBUFFER_RED_SIZE_EXT                           0x8D50
#define GL_RENDERBUFFER_GREEN_SIZE_EXT                         0x8D51
#define GL_RENDERBUFFER_BLUE_SIZE_EXT                          0x8D52
#define GL_RENDERBUFFER_ALPHA_SIZE_EXT                         0x8D53
#define GL_RENDERBUFFER_DEPTH_SIZE_EXT                         0x8D54
#define GL_RENDERBUFFER_STENCIL_SIZE_EXT                       0x8D55

OPENGL_INIT_PROC(glIsRenderbufferEXT,                      GLboolean, GLuint renderbuffer);
OPENGL_INIT_PROC(glBindRenderbufferEXT,                    void,      GLenum target, GLuint renderbuffer);
OPENGL_INIT_PROC(glDeleteRenderbuffersEXT,                 void,      GLsizei n, const GLuint *renderbuffers);
OPENGL_INIT_PROC(glGenRenderbuffersEXT,                    void,      GLsizei n, GLuint *renderbuffers);
OPENGL_INIT_PROC(glRenderbufferStorageEXT,                 void,      GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glGetRenderbufferParameterivEXT,          void,      GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glIsFramebufferEXT,                       GLboolean, GLuint framebuffer);
OPENGL_INIT_PROC(glBindFramebufferEXT,                     void,      GLenum target, GLuint framebuffer);
OPENGL_INIT_PROC(glDeleteFramebuffersEXT,                  void,      GLsizei n, const GLuint *framebuffers);
OPENGL_INIT_PROC(glGenFramebuffersEXT,                     void,      GLsizei n, GLuint *framebuffers);
OPENGL_INIT_PROC(glCheckFramebufferStatusEXT,              GLenum,    GLenum target);
OPENGL_INIT_PROC(glFramebufferTexture1DEXT,                void,      GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
OPENGL_INIT_PROC(glFramebufferTexture2DEXT,                void,      GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
OPENGL_INIT_PROC(glFramebufferTexture3DEXT,                void,      GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
OPENGL_INIT_PROC(glFramebufferRenderbufferEXT,             void,      GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
OPENGL_INIT_PROC(glGetFramebufferAttachmentParameterivEXT, void,      GLenum target, GLenum attachment, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGenerateMipmapEXT,                      void,      GLenum target);

#define glIsRenderbufferEXT                      OGL__glIsRenderbufferEXT
#define glBindRenderbufferEXT                    OGL__glBindRenderbufferEXT
#define glDeleteRenderbuffersEXT                 OGL__glDeleteRenderbuffersEXT
#define glGenRenderbuffersEXT                    OGL__glGenRenderbuffersEXT
#define glRenderbufferStorageEXT                 OGL__glRenderbufferStorageEXT
#define glGetRenderbufferParameterivEXT          OGL__glGetRenderbufferParameterivEXT
#define glIsFramebufferEXT                       OGL__glIsFramebufferEXT
#define glBindFramebufferEXT                     OGL__glBindFramebufferEXT
#define glDeleteFramebuffersEXT                  OGL__glDeleteFramebuffersEXT
#define glGenFramebuffersEXT                     OGL__glGenFramebuffersEXT
#define glCheckFramebufferStatusEXT              OGL__glCheckFramebufferStatusEXT
#define glFramebufferTexture1DEXT                OGL__glFramebufferTexture1DEXT
#define glFramebufferTexture2DEXT                OGL__glFramebufferTexture2DEXT
#define glFramebufferTexture3DEXT                OGL__glFramebufferTexture3DEXT
#define glFramebufferRenderbufferEXT             OGL__glFramebufferRenderbufferEXT
#define glGetFramebufferAttachmentParameterivEXT OGL__glGetFramebufferAttachmentParameterivEXT
#define glGenerateMipmapEXT                      OGL__glGenerateMipmapEXT

#endif // GL_EXT_framebuffer_object

#endif // OPENGL_INCLUDE_GL_EXT_framebuffer_object

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_framebuffer_sRGB
#define GL_EXT_framebuffer_sRGB 1

#define GL_FRAMEBUFFER_SRGB_EXT            0x8DB9
#define GL_FRAMEBUFFER_SRGB_CAPABLE_EXT    0x8DBA

#endif // GL_EXT_framebuffer_sRGB

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_geometry_shader4

#ifndef GL_EXT_geometry_shader4
#define GL_EXT_geometry_shader4 1

#define GL_GEOMETRY_SHADER_EXT                         0x8DD9
#define GL_GEOMETRY_VERTICES_OUT_EXT                   0x8DDA
#define GL_GEOMETRY_INPUT_TYPE_EXT                     0x8DDB
#define GL_GEOMETRY_OUTPUT_TYPE_EXT                    0x8DDC
#define GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT        0x8C29
#define GL_MAX_GEOMETRY_VARYING_COMPONENTS_EXT         0x8DDD
#define GL_MAX_VERTEX_VARYING_COMPONENTS_EXT           0x8DDE
#define GL_MAX_VARYING_COMPONENTS_EXT                  0x8B4B
#define GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT         0x8DDF
#define GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT            0x8DE0
#define GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT    0x8DE1
#define GL_LINES_ADJACENCY_EXT                         0x000A
#define GL_LINE_STRIP_ADJACENCY_EXT                    0x000B
#define GL_TRIANGLES_ADJACENCY_EXT                     0x000C
#define GL_TRIANGLE_STRIP_ADJACENCY_EXT                0x000D
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS_EXT    0x8DA8
#define GL_FRAMEBUFFER_INCOMPLETE_LAYER_COUNT_EXT      0x8DA9
#define GL_FRAMEBUFFER_ATTACHMENT_LAYERED_EXT          0x8DA7
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER_EXT    0x8CD4
#define GL_PROGRAM_POINT_SIZE_EXT                      0x8642

OPENGL_INIT_PROC(glProgramParameteriEXT, void, GLuint program, GLenum pname, GLint value);
#define glProgramParameteriEXT OGL__glProgramParameteriEXT

#endif // GL_EXT_geometry_shader4

#endif // OPENGL_INCLUDE_GL_EXT_geometry_shader4

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_gpu_program_parameters

#ifndef GL_EXT_gpu_program_parameters
#define GL_EXT_gpu_program_parameters 1

OPENGL_INIT_PROC(glProgramEnvParameters4fvEXT,   void, GLenum target, GLuint index, GLsizei count, const GLfloat *params);
OPENGL_INIT_PROC(glProgramLocalParameters4fvEXT, void, GLenum target, GLuint index, GLsizei count, const GLfloat *params);

#define glProgramEnvParameters4fvEXT   OGL__glProgramEnvParameters4fvEXT
#define glProgramLocalParameters4fvEXT OGL__glProgramLocalParameters4fvEXT

#endif // GL_EXT_gpu_program_parameters

#endif // OPENGL_INCLUDE_GL_EXT_gpu_program_parameters

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_gpu_shader4

#ifndef GL_EXT_gpu_shader4
#define GL_EXT_gpu_shader4 1

#define GL_VERTEX_ATTRIB_ARRAY_INTEGER_EXT      0x88FD
#define GL_SAMPLER_1D_ARRAY_EXT                 0x8DC0
#define GL_SAMPLER_2D_ARRAY_EXT                 0x8DC1
#define GL_SAMPLER_BUFFER_EXT                   0x8DC2
#define GL_SAMPLER_1D_ARRAY_SHADOW_EXT          0x8DC3
#define GL_SAMPLER_2D_ARRAY_SHADOW_EXT          0x8DC4
#define GL_SAMPLER_CUBE_SHADOW_EXT              0x8DC5
#define GL_UNSIGNED_INT_VEC2_EXT                0x8DC6
#define GL_UNSIGNED_INT_VEC3_EXT                0x8DC7
#define GL_UNSIGNED_INT_VEC4_EXT                0x8DC8
#define GL_INT_SAMPLER_1D_EXT                   0x8DC9
#define GL_INT_SAMPLER_2D_EXT                   0x8DCA
#define GL_INT_SAMPLER_3D_EXT                   0x8DCB
#define GL_INT_SAMPLER_CUBE_EXT                 0x8DCC
#define GL_INT_SAMPLER_2D_RECT_EXT              0x8DCD
#define GL_INT_SAMPLER_1D_ARRAY_EXT             0x8DCE
#define GL_INT_SAMPLER_2D_ARRAY_EXT             0x8DCF
#define GL_INT_SAMPLER_BUFFER_EXT               0x8DD0
#define GL_UNSIGNED_INT_SAMPLER_1D_EXT          0x8DD1
#define GL_UNSIGNED_INT_SAMPLER_2D_EXT          0x8DD2
#define GL_UNSIGNED_INT_SAMPLER_3D_EXT          0x8DD3
#define GL_UNSIGNED_INT_SAMPLER_CUBE_EXT        0x8DD4
#define GL_UNSIGNED_INT_SAMPLER_2D_RECT_EXT     0x8DD5
#define GL_UNSIGNED_INT_SAMPLER_1D_ARRAY_EXT    0x8DD6
#define GL_UNSIGNED_INT_SAMPLER_2D_ARRAY_EXT    0x8DD7
#define GL_UNSIGNED_INT_SAMPLER_BUFFER_EXT      0x8DD8
#define GL_MIN_PROGRAM_TEXEL_OFFSET_EXT         0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET_EXT         0x8905

OPENGL_INIT_PROC(glGetUniformuivEXT,        void,  GLuint program, GLint location, GLuint *params);
OPENGL_INIT_PROC(glBindFragDataLocationEXT, void,  GLuint program, GLuint color, const GLchar *name);
OPENGL_INIT_PROC(glGetFragDataLocationEXT,  GLint, GLuint program, const GLchar *name);
OPENGL_INIT_PROC(glUniform1uiEXT,           void,  GLint location, GLuint v0);
OPENGL_INIT_PROC(glUniform2uiEXT,           void,  GLint location, GLuint v0, GLuint v1);
OPENGL_INIT_PROC(glUniform3uiEXT,           void,  GLint location, GLuint v0, GLuint v1, GLuint v2);
OPENGL_INIT_PROC(glUniform4uiEXT,           void,  GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
OPENGL_INIT_PROC(glUniform1uivEXT,          void,  GLint location, GLsizei count, const GLuint *value);
OPENGL_INIT_PROC(glUniform2uivEXT,          void,  GLint location, GLsizei count, const GLuint *value);
OPENGL_INIT_PROC(glUniform3uivEXT,          void,  GLint location, GLsizei count, const GLuint *value);
OPENGL_INIT_PROC(glUniform4uivEXT,          void,  GLint location, GLsizei count, const GLuint *value);

#define glGetUniformuivEXT        OGL__glGetUniformuivEXT
#define glBindFragDataLocationEXT OGL__glBindFragDataLocationEXT
#define glGetFragDataLocationEXT  OGL__glGetFragDataLocationEXT
#define glUniform1uiEXT           OGL__glUniform1uiEXT
#define glUniform2uiEXT           OGL__glUniform2uiEXT
#define glUniform3uiEXT           OGL__glUniform3uiEXT
#define glUniform4uiEXT           OGL__glUniform4uiEXT
#define glUniform1uivEXT          OGL__glUniform1uivEXT
#define glUniform2uivEXT          OGL__glUniform2uivEXT
#define glUniform3uivEXT          OGL__glUniform3uivEXT
#define glUniform4uivEXT          OGL__glUniform4uivEXT

#endif // GL_EXT_gpu_shader4

#endif // OPENGL_INCLUDE_GL_EXT_gpu_shader4

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_histogram

#ifndef GL_EXT_histogram
#define GL_EXT_histogram 1

#define GL_HISTOGRAM_EXT                   0x8024
#define GL_PROXY_HISTOGRAM_EXT             0x8025
#define GL_HISTOGRAM_WIDTH_EXT             0x8026
#define GL_HISTOGRAM_FORMAT_EXT            0x8027
#define GL_HISTOGRAM_RED_SIZE_EXT          0x8028
#define GL_HISTOGRAM_GREEN_SIZE_EXT        0x8029
#define GL_HISTOGRAM_BLUE_SIZE_EXT         0x802A
#define GL_HISTOGRAM_ALPHA_SIZE_EXT        0x802B
#define GL_HISTOGRAM_LUMINANCE_SIZE_EXT    0x802C
#define GL_HISTOGRAM_SINK_EXT              0x802D
#define GL_MINMAX_EXT                      0x802E
#define GL_MINMAX_FORMAT_EXT               0x802F
#define GL_MINMAX_SINK_EXT                 0x8030
#define GL_TABLE_TOO_LARGE_EXT             0x8031

OPENGL_INIT_PROC(glGetHistogramEXT,            void, GLenum target, GLboolean reset, GLenum format, GLenum type, void *values);
OPENGL_INIT_PROC(glGetHistogramParameterfvEXT, void, GLenum target, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetHistogramParameterivEXT, void, GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetMinmaxEXT,               void, GLenum target, GLboolean reset, GLenum format, GLenum type, void *values);
OPENGL_INIT_PROC(glGetMinmaxParameterfvEXT,    void, GLenum target, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetMinmaxParameterivEXT,    void, GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glHistogramEXT,               void, GLenum target, GLsizei width, GLenum internalformat, GLboolean sink);
OPENGL_INIT_PROC(glMinmaxEXT,                  void, GLenum target, GLenum internalformat, GLboolean sink);
OPENGL_INIT_PROC(glResetHistogramEXT,          void, GLenum target);
OPENGL_INIT_PROC(glResetMinmaxEXT,             void, GLenum target);

#define glGetHistogramEXT            OGL__glGetHistogramEXT
#define glGetHistogramParameterfvEXT OGL__glGetHistogramParameterfvEXT
#define glGetHistogramParameterivEXT OGL__glGetHistogramParameterivEXT
#define glGetMinmaxEXT               OGL__glGetMinmaxEXT
#define glGetMinmaxParameterfvEXT    OGL__glGetMinmaxParameterfvEXT
#define glGetMinmaxParameterivEXT    OGL__glGetMinmaxParameterivEXT
#define glHistogramEXT               OGL__glHistogramEXT
#define glMinmaxEXT                  OGL__glMinmaxEXT
#define glResetHistogramEXT          OGL__glResetHistogramEXT
#define glResetMinmaxEXT             OGL__glResetMinmaxEXT

#endif // GL_EXT_histogram

#endif // OPENGL_INCLUDE_GL_EXT_histogram

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_index_array_formats
#define GL_EXT_index_array_formats 1

#define GL_IUI_V2F_EXT            0x81AD
#define GL_IUI_V3F_EXT            0x81AE
#define GL_IUI_N3F_V2F_EXT        0x81AF
#define GL_IUI_N3F_V3F_EXT        0x81B0
#define GL_T2F_IUI_V2F_EXT        0x81B1
#define GL_T2F_IUI_V3F_EXT        0x81B2
#define GL_T2F_IUI_N3F_V2F_EXT    0x81B3
#define GL_T2F_IUI_N3F_V3F_EXT    0x81B4

#endif // GL_EXT_index_array_formats

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_index_func

#ifndef GL_EXT_index_func
#define GL_EXT_index_func 1

#define GL_INDEX_TEST_EXT         0x81B5
#define GL_INDEX_TEST_FUNC_EXT    0x81B6
#define GL_INDEX_TEST_REF_EXT     0x81B7

OPENGL_INIT_PROC(glIndexFuncEXT, void, GLenum func, GLclampf ref);
#define glIndexFuncEXT OGL__glIndexFuncEXT

#endif // GL_EXT_index_func

#endif // OPENGL_INCLUDE_GL_EXT_index_func

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_index_material

#ifndef GL_EXT_index_material
#define GL_EXT_index_material 1

#define GL_INDEX_MATERIAL_EXT              0x81B8
#define GL_INDEX_MATERIAL_PARAMETER_EXT    0x81B9
#define GL_INDEX_MATERIAL_FACE_EXT         0x81BA

OPENGL_INIT_PROC(glIndexMaterialEXT, void, GLenum face, GLenum mode);
#define glIndexMaterialEXT OGL__glIndexMaterialEXT

#endif // GL_EXT_index_material

#endif // OPENGL_INCLUDE_GL_EXT_index_material

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_index_texture
#define GL_EXT_index_texture 1

#endif // GL_EXT_index_texture

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_light_texture

#ifndef GL_EXT_light_texture
#define GL_EXT_light_texture 1

#define GL_FRAGMENT_MATERIAL_EXT             0x8349
#define GL_FRAGMENT_NORMAL_EXT               0x834A
#define GL_FRAGMENT_COLOR_EXT                0x834C
#define GL_ATTENUATION_EXT                   0x834D
#define GL_SHADOW_ATTENUATION_EXT            0x834E
#define GL_TEXTURE_APPLICATION_MODE_EXT      0x834F
#define GL_TEXTURE_LIGHT_EXT                 0x8350
#define GL_TEXTURE_MATERIAL_FACE_EXT         0x8351
#define GL_TEXTURE_MATERIAL_PARAMETER_EXT    0x8352

OPENGL_INIT_PROC(glApplyTextureEXT,    void, GLenum mode);
OPENGL_INIT_PROC(glTextureLightEXT,    void, GLenum pname);
OPENGL_INIT_PROC(glTextureMaterialEXT, void, GLenum face, GLenum mode);

#define glApplyTextureEXT    OGL__glApplyTextureEXT
#define glTextureLightEXT    OGL__glTextureLightEXT
#define glTextureMaterialEXT OGL__glTextureMaterialEXT

#endif // GL_EXT_light_texture

#endif // OPENGL_INCLUDE_GL_EXT_light_texture

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_memory_object

#ifndef GL_EXT_memory_object
#define GL_EXT_memory_object 1

#define GL_TEXTURE_TILING_EXT             0x9580
#define GL_DEDICATED_MEMORY_OBJECT_EXT    0x9581
#define GL_PROTECTED_MEMORY_OBJECT_EXT    0x959B
#define GL_NUM_TILING_TYPES_EXT           0x9582
#define GL_TILING_TYPES_EXT               0x9583
#define GL_OPTIMAL_TILING_EXT             0x9584
#define GL_LINEAR_TILING_EXT              0x9585
#define GL_NUM_DEVICE_UUIDS_EXT           0x9596
#define GL_DEVICE_UUID_EXT                0x9597
#define GL_DRIVER_UUID_EXT                0x9598
#define GL_UUID_SIZE_EXT                  16

OPENGL_INIT_PROC(glGetUnsignedBytevEXT,               void,      GLenum pname, GLubyte *data);
OPENGL_INIT_PROC(glGetUnsignedBytei_vEXT,             void,      GLenum target, GLuint index, GLubyte *data);
OPENGL_INIT_PROC(glDeleteMemoryObjectsEXT,            void,      GLsizei n, const GLuint *memoryObjects);
OPENGL_INIT_PROC(glIsMemoryObjectEXT,                 GLboolean, GLuint memoryObject);
OPENGL_INIT_PROC(glCreateMemoryObjectsEXT,            void,      GLsizei n, GLuint *memoryObjects);
OPENGL_INIT_PROC(glMemoryObjectParameterivEXT,        void,      GLuint memoryObject, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glGetMemoryObjectParameterivEXT,     void,      GLuint memoryObject, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glTexStorageMem2DEXT,                void,      GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLuint memory, GLuint64 offset);
OPENGL_INIT_PROC(glTexStorageMem2DMultisampleEXT,     void,      GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset);
OPENGL_INIT_PROC(glTexStorageMem3DEXT,                void,      GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset);
OPENGL_INIT_PROC(glTexStorageMem3DMultisampleEXT,     void,      GLenum target, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset);
OPENGL_INIT_PROC(glBufferStorageMemEXT,               void,      GLenum target, GLsizeiptr size, GLuint memory, GLuint64 offset);
OPENGL_INIT_PROC(glTextureStorageMem2DEXT,            void,      GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLuint memory, GLuint64 offset);
OPENGL_INIT_PROC(glTextureStorageMem2DMultisampleEXT, void,      GLuint texture, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset);
OPENGL_INIT_PROC(glTextureStorageMem3DEXT,            void,      GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLuint memory, GLuint64 offset);
OPENGL_INIT_PROC(glTextureStorageMem3DMultisampleEXT, void,      GLuint texture, GLsizei samples, GLenum internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations, GLuint memory, GLuint64 offset);
OPENGL_INIT_PROC(glNamedBufferStorageMemEXT,          void,      GLuint buffer, GLsizeiptr size, GLuint memory, GLuint64 offset);
OPENGL_INIT_PROC(glTexStorageMem1DEXT,                void,      GLenum target, GLsizei levels, GLenum internalFormat, GLsizei width, GLuint memory, GLuint64 offset);
OPENGL_INIT_PROC(glTextureStorageMem1DEXT,            void,      GLuint texture, GLsizei levels, GLenum internalFormat, GLsizei width, GLuint memory, GLuint64 offset);

#define glGetUnsignedBytevEXT               OGL__glGetUnsignedBytevEXT
#define glGetUnsignedBytei_vEXT             OGL__glGetUnsignedBytei_vEXT
#define glDeleteMemoryObjectsEXT            OGL__glDeleteMemoryObjectsEXT
#define glIsMemoryObjectEXT                 OGL__glIsMemoryObjectEXT
#define glCreateMemoryObjectsEXT            OGL__glCreateMemoryObjectsEXT
#define glMemoryObjectParameterivEXT        OGL__glMemoryObjectParameterivEXT
#define glGetMemoryObjectParameterivEXT     OGL__glGetMemoryObjectParameterivEXT
#define glTexStorageMem2DEXT                OGL__glTexStorageMem2DEXT
#define glTexStorageMem2DMultisampleEXT     OGL__glTexStorageMem2DMultisampleEXT
#define glTexStorageMem3DEXT                OGL__glTexStorageMem3DEXT
#define glTexStorageMem3DMultisampleEXT     OGL__glTexStorageMem3DMultisampleEXT
#define glBufferStorageMemEXT               OGL__glBufferStorageMemEXT
#define glTextureStorageMem2DEXT            OGL__glTextureStorageMem2DEXT
#define glTextureStorageMem2DMultisampleEXT OGL__glTextureStorageMem2DMultisampleEXT
#define glTextureStorageMem3DEXT            OGL__glTextureStorageMem3DEXT
#define glTextureStorageMem3DMultisampleEXT OGL__glTextureStorageMem3DMultisampleEXT
#define glNamedBufferStorageMemEXT          OGL__glNamedBufferStorageMemEXT
#define glTexStorageMem1DEXT                OGL__glTexStorageMem1DEXT
#define glTextureStorageMem1DEXT            OGL__glTextureStorageMem1DEXT

#endif // GL_EXT_memory_object

#endif // OPENGL_INCLUDE_GL_EXT_memory_object

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_memory_object_fd

#ifndef GL_EXT_memory_object_fd
#define GL_EXT_memory_object_fd 1

#define GL_HANDLE_TYPE_OPAQUE_FD_EXT    0x9586

OPENGL_INIT_PROC(glImportMemoryFdEXT, void, GLuint memory, GLuint64 size, GLenum handleType, GLint fd);
#define glImportMemoryFdEXT OGL__glImportMemoryFdEXT

#endif // GL_EXT_memory_object_fd

#endif // OPENGL_INCLUDE_GL_EXT_memory_object_fd

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_memory_object_win32

#ifndef GL_EXT_memory_object_win32
#define GL_EXT_memory_object_win32 1

#define GL_HANDLE_TYPE_OPAQUE_WIN32_EXT        0x9587
#define GL_HANDLE_TYPE_OPAQUE_WIN32_KMT_EXT    0x9588
#define GL_DEVICE_LUID_EXT                     0x9599
#define GL_DEVICE_NODE_MASK_EXT                0x959A
#define GL_LUID_SIZE_EXT                       8
#define GL_HANDLE_TYPE_D3D12_TILEPOOL_EXT      0x9589
#define GL_HANDLE_TYPE_D3D12_RESOURCE_EXT      0x958A
#define GL_HANDLE_TYPE_D3D11_IMAGE_EXT         0x958B
#define GL_HANDLE_TYPE_D3D11_IMAGE_KMT_EXT     0x958C

OPENGL_INIT_PROC(glImportMemoryWin32HandleEXT, void, GLuint memory, GLuint64 size, GLenum handleType, void *handle);
OPENGL_INIT_PROC(glImportMemoryWin32NameEXT,   void, GLuint memory, GLuint64 size, GLenum handleType, const void *name);

#define glImportMemoryWin32HandleEXT OGL__glImportMemoryWin32HandleEXT
#define glImportMemoryWin32NameEXT   OGL__glImportMemoryWin32NameEXT

#endif // GL_EXT_memory_object_win32

#endif // OPENGL_INCLUDE_GL_EXT_memory_object_win32

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_misc_attribute
#define GL_EXT_misc_attribute 1

#endif // GL_EXT_misc_attribute

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_multi_draw_arrays

#ifndef GL_EXT_multi_draw_arrays
#define GL_EXT_multi_draw_arrays 1

OPENGL_INIT_PROC(glMultiDrawArraysEXT,   void, GLenum mode, const GLint *first, const GLsizei *count, GLsizei primcount);
OPENGL_INIT_PROC(glMultiDrawElementsEXT, void, GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei primcount);

#define glMultiDrawArraysEXT   OGL__glMultiDrawArraysEXT
#define glMultiDrawElementsEXT OGL__glMultiDrawElementsEXT

#endif // GL_EXT_multi_draw_arrays

#endif // OPENGL_INCLUDE_GL_EXT_multi_draw_arrays

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_multisample

#ifndef GL_EXT_multisample
#define GL_EXT_multisample 1

#define GL_MULTISAMPLE_EXT             0x809D
#define GL_SAMPLE_ALPHA_TO_MASK_EXT    0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_EXT     0x809F
#define GL_SAMPLE_MASK_EXT             0x80A0
#define GL_1PASS_EXT                   0x80A1
#define GL_2PASS_0_EXT                 0x80A2
#define GL_2PASS_1_EXT                 0x80A3
#define GL_4PASS_0_EXT                 0x80A4
#define GL_4PASS_1_EXT                 0x80A5
#define GL_4PASS_2_EXT                 0x80A6
#define GL_4PASS_3_EXT                 0x80A7
#define GL_SAMPLE_BUFFERS_EXT          0x80A8
#define GL_SAMPLES_EXT                 0x80A9
#define GL_SAMPLE_MASK_VALUE_EXT       0x80AA
#define GL_SAMPLE_MASK_INVERT_EXT      0x80AB
#define GL_SAMPLE_PATTERN_EXT          0x80AC
#define GL_MULTISAMPLE_BIT_EXT         0x20000000

OPENGL_INIT_PROC(glSampleMaskEXT,    void, GLclampf value, GLboolean invert);
OPENGL_INIT_PROC(glSamplePatternEXT, void, GLenum pattern);

#define glSampleMaskEXT    OGL__glSampleMaskEXT
#define glSamplePatternEXT OGL__glSamplePatternEXT

#endif // GL_EXT_multisample

#endif // OPENGL_INCLUDE_GL_EXT_multisample

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_multiview_tessellation_geometry_shader
#define GL_EXT_multiview_tessellation_geometry_shader 1

#endif // GL_EXT_multiview_tessellation_geometry_shader

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_multiview_texture_multisample
#define GL_EXT_multiview_texture_multisample 1

#endif // GL_EXT_multiview_texture_multisample

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_multiview_timer_query
#define GL_EXT_multiview_timer_query 1

#endif // GL_EXT_multiview_timer_query

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_packed_depth_stencil
#define GL_EXT_packed_depth_stencil 1

#define GL_DEPTH_STENCIL_EXT           0x84F9
#define GL_UNSIGNED_INT_24_8_EXT       0x84FA
#define GL_DEPTH24_STENCIL8_EXT        0x88F0
#define GL_TEXTURE_STENCIL_SIZE_EXT    0x88F1

#endif // GL_EXT_packed_depth_stencil

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_packed_float
#define GL_EXT_packed_float 1

#define GL_R11F_G11F_B10F_EXT                  0x8C3A
#define GL_UNSIGNED_INT_10F_11F_11F_REV_EXT    0x8C3B
#define GL_RGBA_SIGNED_COMPONENTS_EXT          0x8C3C

#endif // GL_EXT_packed_float

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_packed_pixels
#define GL_EXT_packed_pixels 1

#define GL_UNSIGNED_BYTE_3_3_2_EXT        0x8032
#define GL_UNSIGNED_SHORT_4_4_4_4_EXT     0x8033
#define GL_UNSIGNED_SHORT_5_5_5_1_EXT     0x8034
#define GL_UNSIGNED_INT_8_8_8_8_EXT       0x8035
#define GL_UNSIGNED_INT_10_10_10_2_EXT    0x8036

#endif /* GL_EXT_packed_pixels */

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_paletted_texture

#ifndef GL_EXT_paletted_texture
#define GL_EXT_paletted_texture 1

#define GL_COLOR_INDEX1_EXT          0x80E2
#define GL_COLOR_INDEX2_EXT          0x80E3
#define GL_COLOR_INDEX4_EXT          0x80E4
#define GL_COLOR_INDEX8_EXT          0x80E5
#define GL_COLOR_INDEX12_EXT         0x80E6
#define GL_COLOR_INDEX16_EXT         0x80E7
#define GL_TEXTURE_INDEX_SIZE_EXT    0x80ED

OPENGL_INIT_PROC(glColorTableEXT,               void, GLenum target, GLenum internalFormat, GLsizei width, GLenum format, GLenum type, const void *table);
OPENGL_INIT_PROC(glGetColorTableEXT,            void, GLenum target, GLenum format, GLenum type, void *data);
OPENGL_INIT_PROC(glGetColorTableParameterivEXT, void, GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetColorTableParameterfvEXT, void, GLenum target, GLenum pname, GLfloat *params);

#define glColorTableEXT               OGL__glColorTableEXT
#define glGetColorTableEXT            OGL__glGetColorTableEXT
#define glGetColorTableParameterivEXT OGL__glGetColorTableParameterivEXT
#define glGetColorTableParameterfvEXT OGL__glGetColorTableParameterfvEXT

#endif // GL_EXT_paletted_texture

#endif // OPENGL_INCLUDE_GL_EXT_paletted_texture

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_pixel_buffer_object
#define GL_EXT_pixel_buffer_object 1

#define GL_PIXEL_PACK_BUFFER_EXT              0x88EB
#define GL_PIXEL_UNPACK_BUFFER_EXT            0x88EC
#define GL_PIXEL_PACK_BUFFER_BINDING_EXT      0x88ED
#define GL_PIXEL_UNPACK_BUFFER_BINDING_EXT    0x88EF

#endif // GL_EXT_pixel_buffer_object

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_pixel_transform

#ifndef GL_EXT_pixel_transform
#define GL_EXT_pixel_transform 1

#define GL_PIXEL_TRANSFORM_2D_EXT                    0x8330
#define GL_PIXEL_MAG_FILTER_EXT                      0x8331
#define GL_PIXEL_MIN_FILTER_EXT                      0x8332
#define GL_PIXEL_CUBIC_WEIGHT_EXT                    0x8333
#define GL_CUBIC_EXT                                 0x8334
#define GL_AVERAGE_EXT                               0x8335
#define GL_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT        0x8336
#define GL_MAX_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT    0x8337
#define GL_PIXEL_TRANSFORM_2D_MATRIX_EXT             0x8338

OPENGL_INIT_PROC(glPixelTransformParameteriEXT,     void, GLenum target, GLenum pname, GLint param);
OPENGL_INIT_PROC(glPixelTransformParameterfEXT,     void, GLenum target, GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glPixelTransformParameterivEXT,    void, GLenum target, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glPixelTransformParameterfvEXT,    void, GLenum target, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glGetPixelTransformParameterivEXT, void, GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetPixelTransformParameterfvEXT, void, GLenum target, GLenum pname, GLfloat *params);

#define glPixelTransformParameteriEXT     OGL__glPixelTransformParameteriEXT
#define glPixelTransformParameterfEXT     OGL__glPixelTransformParameterfEXT
#define glPixelTransformParameterivEXT    OGL__glPixelTransformParameterivEXT
#define glPixelTransformParameterfvEXT    OGL__glPixelTransformParameterfvEXT
#define glGetPixelTransformParameterivEXT OGL__glGetPixelTransformParameterivEXT
#define glGetPixelTransformParameterfvEXT OGL__glGetPixelTransformParameterfvEXT

#endif // GL_EXT_pixel_transform

#endif // OPENGL_INCLUDE_GL_EXT_pixel_transform

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_pixel_transform_color_table
#define GL_EXT_pixel_transform_color_table 1

#endif // GL_EXT_pixel_transform_color_table

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_point_parameters

#ifndef GL_EXT_point_parameters
#define GL_EXT_point_parameters 1

#define GL_POINT_SIZE_MIN_EXT               0x8126
#define GL_POINT_SIZE_MAX_EXT               0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_EXT    0x8128
#define GL_DISTANCE_ATTENUATION_EXT         0x8129

OPENGL_INIT_PROC(glPointParameterfEXT,  void, GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glPointParameterfvEXT, void, GLenum pname, const GLfloat *params);

#define glPointParameterfEXT  OGL__glPointParameterfEXT
#define glPointParameterfvEXT OGL__glPointParameterfvEXT

#endif // GL_EXT_point_parameters

#endif // OPENGL_INCLUDE_GL_EXT_point_parameters

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_polygon_offset

#ifndef GL_EXT_polygon_offset
#define GL_EXT_polygon_offset 1

#define GL_POLYGON_OFFSET_EXT           0x8037
#define GL_POLYGON_OFFSET_FACTOR_EXT    0x8038
#define GL_POLYGON_OFFSET_BIAS_EXT      0x8039

OPENGL_INIT_PROC(glPolygonOffsetEXT, void, GLfloat factor, GLfloat bias);
#define glPolygonOffsetEXT OGL__glPolygonOffsetEXT

#endif // GL_EXT_polygon_offset

#endif // OPENGL_INCLUDE_GL_EXT_polygon_offset

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_polygon_offset_clamp

#ifndef GL_EXT_polygon_offset_clamp
#define GL_EXT_polygon_offset_clamp 1

#define GL_POLYGON_OFFSET_CLAMP_EXT    0x8E1B

OPENGL_INIT_PROC(glPolygonOffsetClampEXT, void, GLfloat factor, GLfloat units, GLfloat clamp);
#define glPolygonOffsetClampEXT OGL__glPolygonOffsetClampEXT

#endif // GL_EXT_polygon_offset_clamp

#endif // OPENGL_INCLUDE_GL_EXT_polygon_offset_clamp

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_post_depth_coverage
#define GL_EXT_post_depth_coverage 1

#endif // GL_EXT_post_depth_coverage

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_provoking_vertex

#ifndef GL_EXT_provoking_vertex
#define GL_EXT_provoking_vertex 1

#define GL_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION_EXT    0x8E4C
#define GL_FIRST_VERTEX_CONVENTION_EXT                     0x8E4D
#define GL_LAST_VERTEX_CONVENTION_EXT                      0x8E4E
#define GL_PROVOKING_VERTEX_EXT                            0x8E4F

OPENGL_INIT_PROC(glProvokingVertexEXT, void, GLenum mode);
#define glProvokingVertexEXT OGL__glProvokingVertexEXT

#endif // GL_EXT_provoking_vertex

#endif // OPENGL_INCLUDE_GL_EXT_provoking_vertex

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_raster_multisample

#ifndef GL_EXT_raster_multisample
#define GL_EXT_raster_multisample 1

#define GL_RASTER_MULTISAMPLE_EXT                   0x9327
#define GL_RASTER_SAMPLES_EXT                       0x9328
#define GL_MAX_RASTER_SAMPLES_EXT                   0x9329
#define GL_RASTER_FIXED_SAMPLE_LOCATIONS_EXT        0x932A
#define GL_MULTISAMPLE_RASTERIZATION_ALLOWED_EXT    0x932B
#define GL_EFFECTIVE_RASTER_SAMPLES_EXT             0x932C

OPENGL_INIT_PROC(glRasterSamplesEXT, void, GLuint samples, GLboolean fixedsamplelocations);
#define glRasterSamplesEXT OGL__glRasterSamplesEXT

#endif // GL_EXT_raster_multisample

#endif // OPENGL_INCLUDE_GL_EXT_raster_multisample

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_rescale_normal
#define GL_EXT_rescale_normal 1

#define GL_RESCALE_NORMAL_EXT    0x803A

#endif // GL_EXT_rescale_normal

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_secondary_color

#ifndef GL_EXT_secondary_color
#define GL_EXT_secondary_color 1

#define GL_COLOR_SUM_EXT                        0x8458
#define GL_CURRENT_SECONDARY_COLOR_EXT          0x8459
#define GL_SECONDARY_COLOR_ARRAY_SIZE_EXT       0x845A
#define GL_SECONDARY_COLOR_ARRAY_TYPE_EXT       0x845B
#define GL_SECONDARY_COLOR_ARRAY_STRIDE_EXT     0x845C
#define GL_SECONDARY_COLOR_ARRAY_POINTER_EXT    0x845D
#define GL_SECONDARY_COLOR_ARRAY_EXT            0x845E

OPENGL_INIT_PROC(glSecondaryColor3bEXT,      void, GLbyte red, GLbyte green, GLbyte blue);
OPENGL_INIT_PROC(glSecondaryColor3bvEXT,     void, const GLbyte *v);
OPENGL_INIT_PROC(glSecondaryColor3dEXT,      void, GLdouble red, GLdouble green, GLdouble blue);
OPENGL_INIT_PROC(glSecondaryColor3dvEXT,     void, const GLdouble *v);
OPENGL_INIT_PROC(glSecondaryColor3fEXT,      void, GLfloat red, GLfloat green, GLfloat blue);
OPENGL_INIT_PROC(glSecondaryColor3fvEXT,     void, const GLfloat *v);
OPENGL_INIT_PROC(glSecondaryColor3iEXT,      void, GLint red, GLint green, GLint blue);
OPENGL_INIT_PROC(glSecondaryColor3ivEXT,     void, const GLint *v);
OPENGL_INIT_PROC(glSecondaryColor3sEXT,      void, GLshort red, GLshort green, GLshort blue);
OPENGL_INIT_PROC(glSecondaryColor3svEXT,     void, const GLshort *v);
OPENGL_INIT_PROC(glSecondaryColor3ubEXT,     void, GLubyte red, GLubyte green, GLubyte blue);
OPENGL_INIT_PROC(glSecondaryColor3ubvEXT,    void, const GLubyte *v);
OPENGL_INIT_PROC(glSecondaryColor3uiEXT,     void, GLuint red, GLuint green, GLuint blue);
OPENGL_INIT_PROC(glSecondaryColor3uivEXT,    void, const GLuint *v);
OPENGL_INIT_PROC(glSecondaryColor3usEXT,     void, GLushort red, GLushort green, GLushort blue);
OPENGL_INIT_PROC(glSecondaryColor3usvEXT,    void, const GLushort *v);
OPENGL_INIT_PROC(glSecondaryColorPointerEXT, void, GLint size, GLenum type, GLsizei stride, const void *pointer);

#define glSecondaryColor3bEXT      OGL__glSecondaryColor3bEXT
#define glSecondaryColor3bvEXT     OGL__glSecondaryColor3bvEXT
#define glSecondaryColor3dEXT      OGL__glSecondaryColor3dEXT
#define glSecondaryColor3dvEXT     OGL__glSecondaryColor3dvEXT
#define glSecondaryColor3fEXT      OGL__glSecondaryColor3fEXT
#define glSecondaryColor3fvEXT     OGL__glSecondaryColor3fvEXT
#define glSecondaryColor3iEXT      OGL__glSecondaryColor3iEXT
#define glSecondaryColor3ivEXT     OGL__glSecondaryColor3ivEXT
#define glSecondaryColor3sEXT      OGL__glSecondaryColor3sEXT
#define glSecondaryColor3svEXT     OGL__glSecondaryColor3svEXT
#define glSecondaryColor3ubEXT     OGL__glSecondaryColor3ubEXT
#define glSecondaryColor3ubvEXT    OGL__glSecondaryColor3ubvEXT
#define glSecondaryColor3uiEXT     OGL__glSecondaryColor3uiEXT
#define glSecondaryColor3uivEXT    OGL__glSecondaryColor3uivEXT
#define glSecondaryColor3usEXT     OGL__glSecondaryColor3usEXT
#define glSecondaryColor3usvEXT    OGL__glSecondaryColor3usvEXT
#define glSecondaryColorPointerEXT OGL__glSecondaryColorPointerEXT

#endif // GL_EXT_secondary_color

#endif // OPENGL_INCLUDE_GL_EXT_secondary_color

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_semaphore

#ifndef GL_EXT_semaphore
#define GL_EXT_semaphore 1

#define GL_LAYOUT_GENERAL_EXT                               0x958D
#define GL_LAYOUT_COLOR_ATTACHMENT_EXT                      0x958E
#define GL_LAYOUT_DEPTH_STENCIL_ATTACHMENT_EXT              0x958F
#define GL_LAYOUT_DEPTH_STENCIL_READ_ONLY_EXT               0x9590
#define GL_LAYOUT_SHADER_READ_ONLY_EXT                      0x9591
#define GL_LAYOUT_TRANSFER_SRC_EXT                          0x9592
#define GL_LAYOUT_TRANSFER_DST_EXT                          0x9593
#define GL_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_EXT    0x9530
#define GL_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_EXT    0x9531

OPENGL_INIT_PROC(glGenSemaphoresEXT,              void,      GLsizei n, GLuint *semaphores);
OPENGL_INIT_PROC(glDeleteSemaphoresEXT,           void,      GLsizei n, const GLuint *semaphores);
OPENGL_INIT_PROC(glIsSemaphoreEXT,                GLboolean, GLuint semaphore);
OPENGL_INIT_PROC(glSemaphoreParameterui64vEXT,    void,      GLuint semaphore, GLenum pname, const GLuint64 *params);
OPENGL_INIT_PROC(glGetSemaphoreParameterui64vEXT, void,      GLuint semaphore, GLenum pname, GLuint64 *params);
OPENGL_INIT_PROC(glWaitSemaphoreEXT,              void,      GLuint semaphore, GLuint numBufferBarriers, const GLuint *buffers, GLuint numTextureBarriers, const GLuint *textures, const GLenum *srcLayouts);
OPENGL_INIT_PROC(glSignalSemaphoreEXT,            void,      GLuint semaphore, GLuint numBufferBarriers, const GLuint *buffers, GLuint numTextureBarriers, const GLuint *textures, const GLenum *dstLayouts);

#define glGenSemaphoresEXT              OGL__glGenSemaphoresEXT
#define glDeleteSemaphoresEXT           OGL__glDeleteSemaphoresEXT
#define glIsSemaphoreEXT                OGL__glIsSemaphoreEXT
#define glSemaphoreParameterui64vEXT    OGL__glSemaphoreParameterui64vEXT
#define glGetSemaphoreParameterui64vEXT OGL__glGetSemaphoreParameterui64vEXT
#define glWaitSemaphoreEXT              OGL__glWaitSemaphoreEXT
#define glSignalSemaphoreEXT            OGL__glSignalSemaphoreEXT

#endif // GL_EXT_semaphore

#endif // OPENGL_INCLUDE_GL_EXT_semaphore

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_semaphore_fd

#ifndef GL_EXT_semaphore_fd
#define GL_EXT_semaphore_fd 1

OPENGL_INIT_PROC(glImportSemaphoreFdEXT, void, GLuint semaphore, GLenum handleType, GLint fd);
#define glImportSemaphoreFdEXT OGL__glImportSemaphoreFdEXT

#endif // GL_EXT_semaphore_fd

#endif // OPENGL_INCLUDE_GL_EXT_semaphore_fd

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_semaphore_win32

#ifndef GL_EXT_semaphore_win32
#define GL_EXT_semaphore_win32 1

#define GL_HANDLE_TYPE_D3D12_FENCE_EXT    0x9594
#define GL_D3D12_FENCE_VALUE_EXT          0x9595

OPENGL_INIT_PROC(glImportSemaphoreWin32HandleEXT, void, GLuint semaphore, GLenum handleType, void *handle);
OPENGL_INIT_PROC(glImportSemaphoreWin32NameEXT,   void, GLuint semaphore, GLenum handleType, const void *name);

#define glImportSemaphoreWin32HandleEXT OGL__glImportSemaphoreWin32HandleEXT
#define glImportSemaphoreWin32NameEXT   OGL__glImportSemaphoreWin32NameEXT

#endif // GL_EXT_semaphore_win32

#endif // OPENGL_INCLUDE_GL_EXT_semaphore_win32

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_separate_shader_objects

#ifndef GL_EXT_separate_shader_objects
#define GL_EXT_separate_shader_objects 1

#define GL_ACTIVE_PROGRAM_EXT    0x8B8D

OPENGL_INIT_PROC(glUseShaderProgramEXT,    void,   GLenum type, GLuint program);
OPENGL_INIT_PROC(glActiveProgramEXT,       void,   GLuint program);
OPENGL_INIT_PROC(glCreateShaderProgramEXT, GLuint, GLenum type, const GLchar *string);

#define glUseShaderProgramEXT    OGL__glUseShaderProgramEXT
#define glActiveProgramEXT       OGL__glActiveProgramEXT
#define glCreateShaderProgramEXT OGL__glCreateShaderProgramEXT

#endif // GL_EXT_separate_shader_objects

#endif // OPENGL_INCLUDE_GL_EXT_separate_shader_objects

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_separate_specular_color
#define GL_EXT_separate_specular_color 1

#define GL_LIGHT_MODEL_COLOR_CONTROL_EXT    0x81F8
#define GL_SINGLE_COLOR_EXT                 0x81F9
#define GL_SEPARATE_SPECULAR_COLOR_EXT      0x81FA

#endif // GL_EXT_separate_specular_color

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_shader_framebuffer_fetch
#define GL_EXT_shader_framebuffer_fetch 1

#define GL_FRAGMENT_SHADER_DISCARDS_SAMPLES_EXT    0x8A52

#endif // GL_EXT_shader_framebuffer_fetch

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_shader_framebuffer_fetch_non_coherent

#ifndef GL_EXT_shader_framebuffer_fetch_non_coherent
#define GL_EXT_shader_framebuffer_fetch_non_coherent 1

OPENGL_INIT_PROC(glFramebufferFetchBarrierEXT, void, void);
#define glFramebufferFetchBarrierEXT OGL__glFramebufferFetchBarrierEXT

#endif // GL_EXT_shader_framebuffer_fetch_non_coherent

#endif // OPENGL_INCLUDE_GL_EXT_shader_framebuffer_fetch_non_coherent

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_shader_image_load_formatted
#define GL_EXT_shader_image_load_formatted 1

#endif // GL_EXT_shader_image_load_formatted

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_shader_image_load_store

#ifndef GL_EXT_shader_image_load_store
#define GL_EXT_shader_image_load_store 1

#define GL_MAX_IMAGE_UNITS_EXT                                  0x8F38
#define GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS_EXT    0x8F39
#define GL_IMAGE_BINDING_NAME_EXT                               0x8F3A
#define GL_IMAGE_BINDING_LEVEL_EXT                              0x8F3B
#define GL_IMAGE_BINDING_LAYERED_EXT                            0x8F3C
#define GL_IMAGE_BINDING_LAYER_EXT                              0x8F3D
#define GL_IMAGE_BINDING_ACCESS_EXT                             0x8F3E
#define GL_IMAGE_1D_EXT                                         0x904C
#define GL_IMAGE_2D_EXT                                         0x904D
#define GL_IMAGE_3D_EXT                                         0x904E
#define GL_IMAGE_2D_RECT_EXT                                    0x904F
#define GL_IMAGE_CUBE_EXT                                       0x9050
#define GL_IMAGE_BUFFER_EXT                                     0x9051
#define GL_IMAGE_1D_ARRAY_EXT                                   0x9052
#define GL_IMAGE_2D_ARRAY_EXT                                   0x9053
#define GL_IMAGE_CUBE_MAP_ARRAY_EXT                             0x9054
#define GL_IMAGE_2D_MULTISAMPLE_EXT                             0x9055
#define GL_IMAGE_2D_MULTISAMPLE_ARRAY_EXT                       0x9056
#define GL_INT_IMAGE_1D_EXT                                     0x9057
#define GL_INT_IMAGE_2D_EXT                                     0x9058
#define GL_INT_IMAGE_3D_EXT                                     0x9059
#define GL_INT_IMAGE_2D_RECT_EXT                                0x905A
#define GL_INT_IMAGE_CUBE_EXT                                   0x905B
#define GL_INT_IMAGE_BUFFER_EXT                                 0x905C
#define GL_INT_IMAGE_1D_ARRAY_EXT                               0x905D
#define GL_INT_IMAGE_2D_ARRAY_EXT                               0x905E
#define GL_INT_IMAGE_CUBE_MAP_ARRAY_EXT                         0x905F
#define GL_INT_IMAGE_2D_MULTISAMPLE_EXT                         0x9060
#define GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT                   0x9061
#define GL_UNSIGNED_INT_IMAGE_1D_EXT                            0x9062
#define GL_UNSIGNED_INT_IMAGE_2D_EXT                            0x9063
#define GL_UNSIGNED_INT_IMAGE_3D_EXT                            0x9064
#define GL_UNSIGNED_INT_IMAGE_2D_RECT_EXT                       0x9065
#define GL_UNSIGNED_INT_IMAGE_CUBE_EXT                          0x9066
#define GL_UNSIGNED_INT_IMAGE_BUFFER_EXT                        0x9067
#define GL_UNSIGNED_INT_IMAGE_1D_ARRAY_EXT                      0x9068
#define GL_UNSIGNED_INT_IMAGE_2D_ARRAY_EXT                      0x9069
#define GL_UNSIGNED_INT_IMAGE_CUBE_MAP_ARRAY_EXT                0x906A
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_EXT                0x906B
#define GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY_EXT          0x906C
#define GL_MAX_IMAGE_SAMPLES_EXT                                0x906D
#define GL_IMAGE_BINDING_FORMAT_EXT                             0x906E
#define GL_VERTEX_ATTRIB_ARRAY_BARRIER_BIT_EXT                  0x00000001
#define GL_ELEMENT_ARRAY_BARRIER_BIT_EXT                        0x00000002
#define GL_UNIFORM_BARRIER_BIT_EXT                              0x00000004
#define GL_TEXTURE_FETCH_BARRIER_BIT_EXT                        0x00000008
#define GL_SHADER_IMAGE_ACCESS_BARRIER_BIT_EXT                  0x00000020
#define GL_COMMAND_BARRIER_BIT_EXT                              0x00000040
#define GL_PIXEL_BUFFER_BARRIER_BIT_EXT                         0x00000080
#define GL_TEXTURE_UPDATE_BARRIER_BIT_EXT                       0x00000100
#define GL_BUFFER_UPDATE_BARRIER_BIT_EXT                        0x00000200
#define GL_FRAMEBUFFER_BARRIER_BIT_EXT                          0x00000400
#define GL_TRANSFORM_FEEDBACK_BARRIER_BIT_EXT                   0x00000800
#define GL_ATOMIC_COUNTER_BARRIER_BIT_EXT                       0x00001000
#define GL_ALL_BARRIER_BITS_EXT                                 0xFFFFFFFF

OPENGL_INIT_PROC(glBindImageTextureEXT, void, GLuint index, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLint format);
OPENGL_INIT_PROC(glMemoryBarrierEXT,    void, GLbitfield barriers);

#define glBindImageTextureEXT OGL__glBindImageTextureEXT
#define glMemoryBarrierEXT    OGL__glMemoryBarrierEXT

#endif // GL_EXT_shader_image_load_store

#endif // OPENGL_INCLUDE_GL_EXT_shader_image_load_store

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_shader_integer_mix
#define GL_EXT_shader_integer_mix 1

#endif // GL_EXT_shader_integer_mix

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_shadow_funcs
#define GL_EXT_shadow_funcs 1

#endif // GL_EXT_shadow_funcs

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_shared_texture_palette
#define GL_EXT_shared_texture_palette 1

#define GL_SHARED_TEXTURE_PALETTE_EXT    0x81FB

#endif // GL_EXT_shared_texture_palette

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_sparse_texture2
#define GL_EXT_sparse_texture2 1

#endif // GL_EXT_sparse_texture2

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_stencil_clear_tag

#ifndef GL_EXT_stencil_clear_tag
#define GL_EXT_stencil_clear_tag 1

#define GL_STENCIL_TAG_BITS_EXT           0x88F2
#define GL_STENCIL_CLEAR_TAG_VALUE_EXT    0x88F3

OPENGL_INIT_PROC(glStencilClearTagEXT, void, GLsizei stencilTagBits, GLuint stencilClearTag);
#define glStencilClearTagEXT OGL__glStencilClearTagEXT

#endif // GL_EXT_stencil_clear_tag

#endif // OPENGL_INCLUDE_GL_EXT_stencil_clear_tag

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_stencil_two_side

#ifndef GL_EXT_stencil_two_side
#define GL_EXT_stencil_two_side 1

#define GL_STENCIL_TEST_TWO_SIDE_EXT    0x8910
#define GL_ACTIVE_STENCIL_FACE_EXT      0x8911

OPENGL_INIT_PROC(glActiveStencilFaceEXT, void, GLenum face);
#define glActiveStencilFaceEXT OGL__glActiveStencilFaceEXT

#endif // GL_EXT_stencil_two_side

#endif // OPENGL_INCLUDE_GL_EXT_stencil_two_side

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_stencil_wrap
#define GL_EXT_stencil_wrap 1

#define GL_INCR_WRAP_EXT    0x8507
#define GL_DECR_WRAP_EXT    0x8508

#endif // GL_EXT_stencil_wrap

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_subtexture

#ifndef GL_EXT_subtexture
#define GL_EXT_subtexture 1

OPENGL_INIT_PROC(glTexSubImage1DEXT, void, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
OPENGL_INIT_PROC(glTexSubImage2DEXT, void, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);

#define glTexSubImage1DEXT OGL__glTexSubImage1DEXT
#define glTexSubImage2DEXT OGL__glTexSubImage2DEXT

#endif // GL_EXT_subtexture

#endif // OPENGL_INCLUDE_GL_EXT_subtexture

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_texture
#define GL_EXT_texture 1

#define GL_ALPHA4_EXT                    0x803B
#define GL_ALPHA8_EXT                    0x803C
#define GL_ALPHA12_EXT                   0x803D
#define GL_ALPHA16_EXT                   0x803E
#define GL_LUMINANCE4_EXT                0x803F
#define GL_LUMINANCE8_EXT                0x8040
#define GL_LUMINANCE12_EXT               0x8041
#define GL_LUMINANCE16_EXT               0x8042
#define GL_LUMINANCE4_ALPHA4_EXT         0x8043
#define GL_LUMINANCE6_ALPHA2_EXT         0x8044
#define GL_LUMINANCE8_ALPHA8_EXT         0x8045
#define GL_LUMINANCE12_ALPHA4_EXT        0x8046
#define GL_LUMINANCE12_ALPHA12_EXT       0x8047
#define GL_LUMINANCE16_ALPHA16_EXT       0x8048
#define GL_INTENSITY_EXT                 0x8049
#define GL_INTENSITY4_EXT                0x804A
#define GL_INTENSITY8_EXT                0x804B
#define GL_INTENSITY12_EXT               0x804C
#define GL_INTENSITY16_EXT               0x804D
#define GL_RGB2_EXT                      0x804E
#define GL_RGB4_EXT                      0x804F
#define GL_RGB5_EXT                      0x8050
#define GL_RGB8_EXT                      0x8051
#define GL_RGB10_EXT                     0x8052
#define GL_RGB12_EXT                     0x8053
#define GL_RGB16_EXT                     0x8054
#define GL_RGBA2_EXT                     0x8055
#define GL_RGBA4_EXT                     0x8056
#define GL_RGB5_A1_EXT                   0x8057
#define GL_RGBA8_EXT                     0x8058
#define GL_RGB10_A2_EXT                  0x8059
#define GL_RGBA12_EXT                    0x805A
#define GL_RGBA16_EXT                    0x805B
#define GL_TEXTURE_RED_SIZE_EXT          0x805C
#define GL_TEXTURE_GREEN_SIZE_EXT        0x805D
#define GL_TEXTURE_BLUE_SIZE_EXT         0x805E
#define GL_TEXTURE_ALPHA_SIZE_EXT        0x805F
#define GL_TEXTURE_LUMINANCE_SIZE_EXT    0x8060
#define GL_TEXTURE_INTENSITY_SIZE_EXT    0x8061
#define GL_REPLACE_EXT                   0x8062
#define GL_PROXY_TEXTURE_1D_EXT          0x8063
#define GL_PROXY_TEXTURE_2D_EXT          0x8064
#define GL_TEXTURE_TOO_LARGE_EXT         0x8065

#endif // GL_EXT_texture

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_texture3D

#ifndef GL_EXT_texture3D
#define GL_EXT_texture3D 1

#define GL_PACK_SKIP_IMAGES_EXT       0x806B
#define GL_PACK_IMAGE_HEIGHT_EXT      0x806C
#define GL_UNPACK_SKIP_IMAGES_EXT     0x806D
#define GL_UNPACK_IMAGE_HEIGHT_EXT    0x806E
#define GL_TEXTURE_3D_EXT             0x806F
#define GL_PROXY_TEXTURE_3D_EXT       0x8070
#define GL_TEXTURE_DEPTH_EXT          0x8071
#define GL_TEXTURE_WRAP_R_EXT         0x8072
#define GL_MAX_3D_TEXTURE_SIZE_EXT    0x8073

OPENGL_INIT_PROC(glTexImage3DEXT,    void, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
OPENGL_INIT_PROC(glTexSubImage3DEXT, void, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);

#define glTexImage3DEXT    OGL__glTexImage3DEXT
#define glTexSubImage3DEXT OGL__glTexSubImage3DEXT

#endif // GL_EXT_texture3D

#endif // OPENGL_INCLUDE_GL_EXT_texture3D

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_texture_array

#ifndef GL_EXT_texture_array
#define GL_EXT_texture_array 1

#define GL_TEXTURE_1D_ARRAY_EXT                0x8C18
#define GL_PROXY_TEXTURE_1D_ARRAY_EXT          0x8C19
#define GL_TEXTURE_2D_ARRAY_EXT                0x8C1A
#define GL_PROXY_TEXTURE_2D_ARRAY_EXT          0x8C1B
#define GL_TEXTURE_BINDING_1D_ARRAY_EXT        0x8C1C
#define GL_TEXTURE_BINDING_2D_ARRAY_EXT        0x8C1D
#define GL_MAX_ARRAY_TEXTURE_LAYERS_EXT        0x88FF
#define GL_COMPARE_REF_DEPTH_TO_TEXTURE_EXT    0x884E

OPENGL_INIT_PROC(glFramebufferTextureLayerEXT, void, GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
#define glFramebufferTextureLayerEXT OGL__glFramebufferTextureLayerEXT

#endif // GL_EXT_texture_array

#endif // OPENGL_INCLUDE_GL_EXT_texture_array

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_texture_buffer_object

#ifndef GL_EXT_texture_buffer_object
#define GL_EXT_texture_buffer_object 1

#define GL_TEXTURE_BUFFER_EXT                       0x8C2A
#define GL_MAX_TEXTURE_BUFFER_SIZE_EXT              0x8C2B
#define GL_TEXTURE_BINDING_BUFFER_EXT               0x8C2C
#define GL_TEXTURE_BUFFER_DATA_STORE_BINDING_EXT    0x8C2D
#define GL_TEXTURE_BUFFER_FORMAT_EXT                0x8C2E

OPENGL_INIT_PROC(glTexBufferEXT, void, GLenum target, GLenum internalformat, GLuint buffer);
#define glTexBufferEXT OGL__glTexBufferEXT

#endif // GL_EXT_texture_buffer_object

#endif // OPENGL_INCLUDE_GL_EXT_texture_buffer_object

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_texture_compression_latc
#define GL_EXT_texture_compression_latc 1

#define GL_COMPRESSED_LUMINANCE_LATC1_EXT                 0x8C70
#define GL_COMPRESSED_SIGNED_LUMINANCE_LATC1_EXT          0x8C71
#define GL_COMPRESSED_LUMINANCE_ALPHA_LATC2_EXT           0x8C72
#define GL_COMPRESSED_SIGNED_LUMINANCE_ALPHA_LATC2_EXT    0x8C73

#endif // GL_EXT_texture_compression_latc

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_texture_compression_rgtc
#define GL_EXT_texture_compression_rgtc 1

#define GL_COMPRESSED_RED_RGTC1_EXT                 0x8DBB
#define GL_COMPRESSED_SIGNED_RED_RGTC1_EXT          0x8DBC
#define GL_COMPRESSED_RED_GREEN_RGTC2_EXT           0x8DBD
#define GL_COMPRESSED_SIGNED_RED_GREEN_RGTC2_EXT    0x8DBE

#endif // GL_EXT_texture_compression_rgtc

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_texture_compression_s3tc
#define GL_EXT_texture_compression_s3tc 1

#define GL_COMPRESSED_RGB_S3TC_DXT1_EXT     0x83F0
#define GL_COMPRESSED_RGBA_S3TC_DXT1_EXT    0x83F1
#define GL_COMPRESSED_RGBA_S3TC_DXT3_EXT    0x83F2
#define GL_COMPRESSED_RGBA_S3TC_DXT5_EXT    0x83F3

#endif // GL_EXT_texture_compression_s3tc

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_texture_cube_map
#define GL_EXT_texture_cube_map 1

#define GL_NORMAL_MAP_EXT                     0x8511
#define GL_REFLECTION_MAP_EXT                 0x8512
#define GL_TEXTURE_CUBE_MAP_EXT               0x8513
#define GL_TEXTURE_BINDING_CUBE_MAP_EXT       0x8514
#define GL_TEXTURE_CUBE_MAP_POSITIVE_X_EXT    0x8515
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_X_EXT    0x8516
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Y_EXT    0x8517
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Y_EXT    0x8518
#define GL_TEXTURE_CUBE_MAP_POSITIVE_Z_EXT    0x8519
#define GL_TEXTURE_CUBE_MAP_NEGATIVE_Z_EXT    0x851A
#define GL_PROXY_TEXTURE_CUBE_MAP_EXT         0x851B
#define GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT      0x851C

#endif // GL_EXT_texture_cube_map

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_texture_env_add
#define GL_EXT_texture_env_add 1

#endif // GL_EXT_texture_env_add

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_texture_env_combine
#define GL_EXT_texture_env_combine 1

#define GL_COMBINE_EXT           0x8570
#define GL_COMBINE_RGB_EXT       0x8571
#define GL_COMBINE_ALPHA_EXT     0x8572
#define GL_RGB_SCALE_EXT         0x8573
#define GL_ADD_SIGNED_EXT        0x8574
#define GL_INTERPOLATE_EXT       0x8575
#define GL_CONSTANT_EXT          0x8576
#define GL_PRIMARY_COLOR_EXT     0x8577
#define GL_PREVIOUS_EXT          0x8578
#define GL_SOURCE0_RGB_EXT       0x8580
#define GL_SOURCE1_RGB_EXT       0x8581
#define GL_SOURCE2_RGB_EXT       0x8582
#define GL_SOURCE0_ALPHA_EXT     0x8588
#define GL_SOURCE1_ALPHA_EXT     0x8589
#define GL_SOURCE2_ALPHA_EXT     0x858A
#define GL_OPERAND0_RGB_EXT      0x8590
#define GL_OPERAND1_RGB_EXT      0x8591
#define GL_OPERAND2_RGB_EXT      0x8592
#define GL_OPERAND0_ALPHA_EXT    0x8598
#define GL_OPERAND1_ALPHA_EXT    0x8599
#define GL_OPERAND2_ALPHA_EXT    0x859A

#endif // GL_EXT_texture_env_combine

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_texture_env_dot3
#define GL_EXT_texture_env_dot3 1

#define GL_DOT3_RGB_EXT     0x8740
#define GL_DOT3_RGBA_EXT    0x8741

#endif // GL_EXT_texture_env_dot3

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_texture_filter_anisotropic
#define GL_EXT_texture_filter_anisotropic 1

#define GL_TEXTURE_MAX_ANISOTROPY_EXT        0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT    0x84FF

#endif // GL_EXT_texture_filter_anisotropic

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_texture_filter_minmax
#define GL_EXT_texture_filter_minmax 1

#define GL_TEXTURE_REDUCTION_MODE_EXT    0x9366
#define GL_WEIGHTED_AVERAGE_EXT          0x9367

#endif // GL_EXT_texture_filter_minmax

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_texture_integer

#ifndef GL_EXT_texture_integer
#define GL_EXT_texture_integer 1

#define GL_RGBA32UI_EXT                   0x8D70
#define GL_RGB32UI_EXT                    0x8D71
#define GL_ALPHA32UI_EXT                  0x8D72
#define GL_INTENSITY32UI_EXT              0x8D73
#define GL_LUMINANCE32UI_EXT              0x8D74
#define GL_LUMINANCE_ALPHA32UI_EXT        0x8D75
#define GL_RGBA16UI_EXT                   0x8D76
#define GL_RGB16UI_EXT                    0x8D77
#define GL_ALPHA16UI_EXT                  0x8D78
#define GL_INTENSITY16UI_EXT              0x8D79
#define GL_LUMINANCE16UI_EXT              0x8D7A
#define GL_LUMINANCE_ALPHA16UI_EXT        0x8D7B
#define GL_RGBA8UI_EXT                    0x8D7C
#define GL_RGB8UI_EXT                     0x8D7D
#define GL_ALPHA8UI_EXT                   0x8D7E
#define GL_INTENSITY8UI_EXT               0x8D7F
#define GL_LUMINANCE8UI_EXT               0x8D80
#define GL_LUMINANCE_ALPHA8UI_EXT         0x8D81
#define GL_RGBA32I_EXT                    0x8D82
#define GL_RGB32I_EXT                     0x8D83
#define GL_ALPHA32I_EXT                   0x8D84
#define GL_INTENSITY32I_EXT               0x8D85
#define GL_LUMINANCE32I_EXT               0x8D86
#define GL_LUMINANCE_ALPHA32I_EXT         0x8D87
#define GL_RGBA16I_EXT                    0x8D88
#define GL_RGB16I_EXT                     0x8D89
#define GL_ALPHA16I_EXT                   0x8D8A
#define GL_INTENSITY16I_EXT               0x8D8B
#define GL_LUMINANCE16I_EXT               0x8D8C
#define GL_LUMINANCE_ALPHA16I_EXT         0x8D8D
#define GL_RGBA8I_EXT                     0x8D8E
#define GL_RGB8I_EXT                      0x8D8F
#define GL_ALPHA8I_EXT                    0x8D90
#define GL_INTENSITY8I_EXT                0x8D91
#define GL_LUMINANCE8I_EXT                0x8D92
#define GL_LUMINANCE_ALPHA8I_EXT          0x8D93
#define GL_RED_INTEGER_EXT                0x8D94
#define GL_GREEN_INTEGER_EXT              0x8D95
#define GL_BLUE_INTEGER_EXT               0x8D96
#define GL_ALPHA_INTEGER_EXT              0x8D97
#define GL_RGB_INTEGER_EXT                0x8D98
#define GL_RGBA_INTEGER_EXT               0x8D99
#define GL_BGR_INTEGER_EXT                0x8D9A
#define GL_BGRA_INTEGER_EXT               0x8D9B
#define GL_LUMINANCE_INTEGER_EXT          0x8D9C
#define GL_LUMINANCE_ALPHA_INTEGER_EXT    0x8D9D
#define GL_RGBA_INTEGER_MODE_EXT          0x8D9E

OPENGL_INIT_PROC(glTexParameterIivEXT,     void, GLenum target, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glTexParameterIuivEXT,    void, GLenum target, GLenum pname, const GLuint *params);
OPENGL_INIT_PROC(glGetTexParameterIivEXT,  void, GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetTexParameterIuivEXT, void, GLenum target, GLenum pname, GLuint *params);
OPENGL_INIT_PROC(glClearColorIiEXT,        void, GLint red, GLint green, GLint blue, GLint alpha);
OPENGL_INIT_PROC(glClearColorIuiEXT,       void, GLuint red, GLuint green, GLuint blue, GLuint alpha);

#define glTexParameterIivEXT     OGL__glTexParameterIivEXT
#define glTexParameterIuivEXT    OGL__glTexParameterIuivEXT
#define glGetTexParameterIivEXT  OGL__glGetTexParameterIivEXT
#define glGetTexParameterIuivEXT OGL__glGetTexParameterIuivEXT
#define glClearColorIiEXT        OGL__glClearColorIiEXT
#define glClearColorIuiEXT       OGL__glClearColorIuiEXT

#endif // GL_EXT_texture_integer

#endif // OPENGL_INCLUDE_GL_EXT_texture_integer

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_texture_lod_bias
#define GL_EXT_texture_lod_bias 1

#define GL_MAX_TEXTURE_LOD_BIAS_EXT      0x84FD
#define GL_TEXTURE_FILTER_CONTROL_EXT    0x8500
#define GL_TEXTURE_LOD_BIAS_EXT          0x8501

#endif // GL_EXT_texture_lod_bias

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_texture_mirror_clamp
#define GL_EXT_texture_mirror_clamp 1

#define GL_MIRROR_CLAMP_EXT              0x8742
#define GL_MIRROR_CLAMP_TO_EDGE_EXT      0x8743
#define GL_MIRROR_CLAMP_TO_BORDER_EXT    0x8912

#endif // GL_EXT_texture_mirror_clamp

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_texture_object

#ifndef GL_EXT_texture_object
#define GL_EXT_texture_object 1

#define GL_TEXTURE_PRIORITY_EXT      0x8066
#define GL_TEXTURE_RESIDENT_EXT      0x8067
#define GL_TEXTURE_1D_BINDING_EXT    0x8068
#define GL_TEXTURE_2D_BINDING_EXT    0x8069
#define GL_TEXTURE_3D_BINDING_EXT    0x806A

OPENGL_INIT_PROC(glAreTexturesResidentEXT, GLboolean, GLsizei n, const GLuint *textures, GLboolean *residences);
OPENGL_INIT_PROC(glBindTextureEXT,         void,      GLenum target, GLuint texture);
OPENGL_INIT_PROC(glDeleteTexturesEXT,      void,      GLsizei n, const GLuint *textures);
OPENGL_INIT_PROC(glGenTexturesEXT,         void,      GLsizei n, GLuint *textures);
OPENGL_INIT_PROC(glIsTextureEXT,           GLboolean, GLuint texture);
OPENGL_INIT_PROC(glPrioritizeTexturesEXT,  void,      GLsizei n, const GLuint *textures, const GLclampf *priorities);

#define glAreTexturesResidentEXT OGL__glAreTexturesResidentEXT
#define glBindTextureEXT         OGL__glBindTextureEXT
#define glDeleteTexturesEXT      OGL__glDeleteTexturesEXT
#define glGenTexturesEXT         OGL__glGenTexturesEXT
#define glIsTextureEXT           OGL__glIsTextureEXT
#define glPrioritizeTexturesEXT  OGL__glPrioritizeTexturesEXT

#endif // GL_EXT_texture_object

#endif // OPENGL_INCLUDE_GL_EXT_texture_object

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_texture_perturb_normal

#ifndef GL_EXT_texture_perturb_normal
#define GL_EXT_texture_perturb_normal 1

#define GL_PERTURB_EXT           0x85AE
#define GL_TEXTURE_NORMAL_EXT    0x85AF

OPENGL_INIT_PROC(glTextureNormalEXT, void, GLenum mode);
#define glTextureNormalEXT OGL__glTextureNormalEXT

#endif // GL_EXT_texture_perturb_normal

#endif // OPENGL_INCLUDE_GL_EXT_texture_perturb_normal

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_texture_sRGB
#define GL_EXT_texture_sRGB 1

#define GL_SRGB_EXT                               0x8C40
#define GL_SRGB8_EXT                              0x8C41
#define GL_SRGB_ALPHA_EXT                         0x8C42
#define GL_SRGB8_ALPHA8_EXT                       0x8C43
#define GL_SLUMINANCE_ALPHA_EXT                   0x8C44
#define GL_SLUMINANCE8_ALPHA8_EXT                 0x8C45
#define GL_SLUMINANCE_EXT                         0x8C46
#define GL_SLUMINANCE8_EXT                        0x8C47
#define GL_COMPRESSED_SRGB_EXT                    0x8C48
#define GL_COMPRESSED_SRGB_ALPHA_EXT              0x8C49
#define GL_COMPRESSED_SLUMINANCE_EXT              0x8C4A
#define GL_COMPRESSED_SLUMINANCE_ALPHA_EXT        0x8C4B
#define GL_COMPRESSED_SRGB_S3TC_DXT1_EXT          0x8C4C
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT1_EXT    0x8C4D
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT    0x8C4E
#define GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT5_EXT    0x8C4F

#endif // GL_EXT_texture_sRGB

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_texture_sRGB_R8
#define GL_EXT_texture_sRGB_R8 1

#define GL_SR8_EXT    0x8FBD

#endif // GL_EXT_texture_sRGB_R8

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_texture_sRGB_decode
#define GL_EXT_texture_sRGB_decode 1

#define GL_TEXTURE_SRGB_DECODE_EXT    0x8A48
#define GL_DECODE_EXT                 0x8A49
#define GL_SKIP_DECODE_EXT            0x8A4A

#endif // GL_EXT_texture_sRGB_decode

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_texture_shadow_lod
#define GL_EXT_texture_shadow_lod 1

#endif // GL_EXT_texture_shadow_lod

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_texture_shared_exponent
#define GL_EXT_texture_shared_exponent 1

#define GL_RGB9_E5_EXT                     0x8C3D
#define GL_UNSIGNED_INT_5_9_9_9_REV_EXT    0x8C3E
#define GL_TEXTURE_SHARED_SIZE_EXT         0x8C3F

#endif // GL_EXT_texture_shared_exponent

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_texture_snorm
#define GL_EXT_texture_snorm 1

#define GL_ALPHA_SNORM                  0x9010
#define GL_LUMINANCE_SNORM              0x9011
#define GL_LUMINANCE_ALPHA_SNORM        0x9012
#define GL_INTENSITY_SNORM              0x9013
#define GL_ALPHA8_SNORM                 0x9014
#define GL_LUMINANCE8_SNORM             0x9015
#define GL_LUMINANCE8_ALPHA8_SNORM      0x9016
#define GL_INTENSITY8_SNORM             0x9017
#define GL_ALPHA16_SNORM                0x9018
#define GL_LUMINANCE16_SNORM            0x9019
#define GL_LUMINANCE16_ALPHA16_SNORM    0x901A
#define GL_INTENSITY16_SNORM            0x901B
#define GL_RED_SNORM                    0x8F90
#define GL_RG_SNORM                     0x8F91
#define GL_RGB_SNORM                    0x8F92
#define GL_RGBA_SNORM                   0x8F93

#endif // GL_EXT_texture_snorm

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_texture_swizzle
#define GL_EXT_texture_swizzle 1

#define GL_TEXTURE_SWIZZLE_R_EXT       0x8E42
#define GL_TEXTURE_SWIZZLE_G_EXT       0x8E43
#define GL_TEXTURE_SWIZZLE_B_EXT       0x8E44
#define GL_TEXTURE_SWIZZLE_A_EXT       0x8E45
#define GL_TEXTURE_SWIZZLE_RGBA_EXT    0x8E46

#endif // GL_EXT_texture_swizzle

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_timer_query

#ifndef GL_EXT_timer_query
#define GL_EXT_timer_query 1

#define GL_TIME_ELAPSED_EXT    0x88BF

OPENGL_INIT_PROC(glGetQueryObjecti64vEXT,  void, GLuint id, GLenum pname, GLint64 *params);
OPENGL_INIT_PROC(glGetQueryObjectui64vEXT, void, GLuint id, GLenum pname, GLuint64 *params);

#define glGetQueryObjecti64vEXT  OGL__glGetQueryObjecti64vEXT
#define glGetQueryObjectui64vEXT OGL__glGetQueryObjectui64vEXT

#endif // GL_EXT_timer_query

#endif // OPENGL_INCLUDE_GL_EXT_timer_query

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_transform_feedback

#ifndef GL_EXT_transform_feedback
#define GL_EXT_transform_feedback 1

#define GL_TRANSFORM_FEEDBACK_BUFFER_EXT                        0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_START_EXT                  0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_EXT                   0x8C85
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_EXT                0x8C8F
#define GL_INTERLEAVED_ATTRIBS_EXT                              0x8C8C
#define GL_SEPARATE_ATTRIBS_EXT                                 0x8C8D
#define GL_PRIMITIVES_GENERATED_EXT                             0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_EXT            0x8C88
#define GL_RASTERIZER_DISCARD_EXT                               0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_EXT    0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_EXT          0x8C8B
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_EXT       0x8C80
#define GL_TRANSFORM_FEEDBACK_VARYINGS_EXT                      0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE_EXT                   0x8C7F
#define GL_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH_EXT            0x8C76

OPENGL_INIT_PROC(glBeginTransformFeedbackEXT,      void, GLenum primitiveMode);
OPENGL_INIT_PROC(glEndTransformFeedbackEXT,        void, void);
OPENGL_INIT_PROC(glBindBufferRangeEXT,             void, GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
OPENGL_INIT_PROC(glBindBufferOffsetEXT,            void, GLenum target, GLuint index, GLuint buffer, GLintptr offset);
OPENGL_INIT_PROC(glBindBufferBaseEXT,              void, GLenum target, GLuint index, GLuint buffer);
OPENGL_INIT_PROC(glTransformFeedbackVaryingsEXT,   void, GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
OPENGL_INIT_PROC(glGetTransformFeedbackVaryingEXT, void, GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);

#define glBeginTransformFeedbackEXT      OGL__glBeginTransformFeedbackEXT
#define glEndTransformFeedbackEXT        OGL__glEndTransformFeedbackEXT
#define glBindBufferRangeEXT             OGL__glBindBufferRangeEXT
#define glBindBufferOffsetEXT            OGL__glBindBufferOffsetEXT
#define glBindBufferBaseEXT              OGL__glBindBufferBaseEXT
#define glTransformFeedbackVaryingsEXT   OGL__glTransformFeedbackVaryingsEXT
#define glGetTransformFeedbackVaryingEXT OGL__glGetTransformFeedbackVaryingEXT

#endif // GL_EXT_transform_feedback

#endif // OPENGL_INCLUDE_GL_EXT_transform_feedback

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_vertex_array

#ifndef GL_EXT_vertex_array
#define GL_EXT_vertex_array 1

#define GL_VERTEX_ARRAY_EXT                   0x8074
#define GL_NORMAL_ARRAY_EXT                   0x8075
#define GL_COLOR_ARRAY_EXT                    0x8076
#define GL_INDEX_ARRAY_EXT                    0x8077
#define GL_TEXTURE_COORD_ARRAY_EXT            0x8078
#define GL_EDGE_FLAG_ARRAY_EXT                0x8079
#define GL_VERTEX_ARRAY_SIZE_EXT              0x807A
#define GL_VERTEX_ARRAY_TYPE_EXT              0x807B
#define GL_VERTEX_ARRAY_STRIDE_EXT            0x807C
#define GL_VERTEX_ARRAY_COUNT_EXT             0x807D
#define GL_NORMAL_ARRAY_TYPE_EXT              0x807E
#define GL_NORMAL_ARRAY_STRIDE_EXT            0x807F
#define GL_NORMAL_ARRAY_COUNT_EXT             0x8080
#define GL_COLOR_ARRAY_SIZE_EXT               0x8081
#define GL_COLOR_ARRAY_TYPE_EXT               0x8082
#define GL_COLOR_ARRAY_STRIDE_EXT             0x8083
#define GL_COLOR_ARRAY_COUNT_EXT              0x8084
#define GL_INDEX_ARRAY_TYPE_EXT               0x8085
#define GL_INDEX_ARRAY_STRIDE_EXT             0x8086
#define GL_INDEX_ARRAY_COUNT_EXT              0x8087
#define GL_TEXTURE_COORD_ARRAY_SIZE_EXT       0x8088
#define GL_TEXTURE_COORD_ARRAY_TYPE_EXT       0x8089
#define GL_TEXTURE_COORD_ARRAY_STRIDE_EXT     0x808A
#define GL_TEXTURE_COORD_ARRAY_COUNT_EXT      0x808B
#define GL_EDGE_FLAG_ARRAY_STRIDE_EXT         0x808C
#define GL_EDGE_FLAG_ARRAY_COUNT_EXT          0x808D
#define GL_VERTEX_ARRAY_POINTER_EXT           0x808E
#define GL_NORMAL_ARRAY_POINTER_EXT           0x808F
#define GL_COLOR_ARRAY_POINTER_EXT            0x8090
#define GL_INDEX_ARRAY_POINTER_EXT            0x8091
#define GL_TEXTURE_COORD_ARRAY_POINTER_EXT    0x8092
#define GL_EDGE_FLAG_ARRAY_POINTER_EXT        0x8093

OPENGL_INIT_PROC(glArrayElementEXT,    void, GLint i);
OPENGL_INIT_PROC(glColorPointerEXT,    void, GLint size, GLenum type, GLsizei stride, GLsizei count, const void *pointer);
OPENGL_INIT_PROC(glDrawArraysEXT,      void, GLenum mode, GLint first, GLsizei count);
OPENGL_INIT_PROC(glEdgeFlagPointerEXT, void, GLsizei stride, GLsizei count, const GLboolean *pointer);
OPENGL_INIT_PROC(glGetPointervEXT,     void, GLenum pname, void **params);
OPENGL_INIT_PROC(glIndexPointerEXT,    void, GLenum type, GLsizei stride, GLsizei count, const void *pointer);
OPENGL_INIT_PROC(glNormalPointerEXT,   void, GLenum type, GLsizei stride, GLsizei count, const void *pointer);
OPENGL_INIT_PROC(glTexCoordPointerEXT, void, GLint size, GLenum type, GLsizei stride, GLsizei count, const void *pointer);
OPENGL_INIT_PROC(glVertexPointerEXT,   void, GLint size, GLenum type, GLsizei stride, GLsizei count, const void *pointer);

#define glArrayElementEXT    OGL__glArrayElementEXT
#define glColorPointerEXT    OGL__glColorPointerEXT
#define glDrawArraysEXT      OGL__glDrawArraysEXT
#define glEdgeFlagPointerEXT OGL__glEdgeFlagPointerEXT
#define glGetPointervEXT     OGL__glGetPointervEXT
#define glIndexPointerEXT    OGL__glIndexPointerEXT
#define glNormalPointerEXT   OGL__glNormalPointerEXT
#define glTexCoordPointerEXT OGL__glTexCoordPointerEXT
#define glVertexPointerEXT   OGL__glVertexPointerEXT

#endif // GL_EXT_vertex_array

#endif // OPENGL_INCLUDE_GL_EXT_vertex_array

/* -------------------------------------------------------------------------- */

#ifndef GL_EXT_vertex_array_bgra
#define GL_EXT_vertex_array_bgra 1

#endif // GL_EXT_vertex_array_bgra

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_vertex_attrib_64bit

#ifndef GL_EXT_vertex_attrib_64bit
#define GL_EXT_vertex_attrib_64bit 1

#define GL_DOUBLE_VEC2_EXT      0x8FFC
#define GL_DOUBLE_VEC3_EXT      0x8FFD
#define GL_DOUBLE_VEC4_EXT      0x8FFE
#define GL_DOUBLE_MAT2_EXT      0x8F46
#define GL_DOUBLE_MAT3_EXT      0x8F47
#define GL_DOUBLE_MAT4_EXT      0x8F48
#define GL_DOUBLE_MAT2x3_EXT    0x8F49
#define GL_DOUBLE_MAT2x4_EXT    0x8F4A
#define GL_DOUBLE_MAT3x2_EXT    0x8F4B
#define GL_DOUBLE_MAT3x4_EXT    0x8F4C
#define GL_DOUBLE_MAT4x2_EXT    0x8F4D
#define GL_DOUBLE_MAT4x3_EXT    0x8F4E

OPENGL_INIT_PROC(glVertexAttribL1dEXT,      void, GLuint index, GLdouble x);
OPENGL_INIT_PROC(glVertexAttribL2dEXT,      void, GLuint index, GLdouble x, GLdouble y);
OPENGL_INIT_PROC(glVertexAttribL3dEXT,      void, GLuint index, GLdouble x, GLdouble y, GLdouble z);
OPENGL_INIT_PROC(glVertexAttribL4dEXT,      void, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
OPENGL_INIT_PROC(glVertexAttribL1dvEXT,     void, GLuint index, const GLdouble *v);
OPENGL_INIT_PROC(glVertexAttribL2dvEXT,     void, GLuint index, const GLdouble *v);
OPENGL_INIT_PROC(glVertexAttribL3dvEXT,     void, GLuint index, const GLdouble *v);
OPENGL_INIT_PROC(glVertexAttribL4dvEXT,     void, GLuint index, const GLdouble *v);
OPENGL_INIT_PROC(glVertexAttribLPointerEXT, void, GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
OPENGL_INIT_PROC(glGetVertexAttribLdvEXT,   void, GLuint index, GLenum pname, GLdouble *params);

#define glVertexAttribL1dEXT      OGL__glVertexAttribL1dEXT
#define glVertexAttribL2dEXT      OGL__glVertexAttribL2dEXT
#define glVertexAttribL3dEXT      OGL__glVertexAttribL3dEXT
#define glVertexAttribL4dEXT      OGL__glVertexAttribL4dEXT
#define glVertexAttribL1dvEXT     OGL__glVertexAttribL1dvEXT
#define glVertexAttribL2dvEXT     OGL__glVertexAttribL2dvEXT
#define glVertexAttribL3dvEXT     OGL__glVertexAttribL3dvEXT
#define glVertexAttribL4dvEXT     OGL__glVertexAttribL4dvEXT
#define glVertexAttribLPointerEXT OGL__glVertexAttribLPointerEXT
#define glGetVertexAttribLdvEXT   OGL__glGetVertexAttribLdvEXT

#endif // GL_EXT_vertex_attrib_64bit

#endif // OPENGL_INCLUDE_GL_EXT_vertex_attrib_64bit

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_vertex_shader

#ifndef GL_EXT_vertex_shader
#define GL_EXT_vertex_shader 1

#define GL_VERTEX_SHADER_EXT                                  0x8780
#define GL_VERTEX_SHADER_BINDING_EXT                          0x8781
#define GL_OP_INDEX_EXT                                       0x8782
#define GL_OP_NEGATE_EXT                                      0x8783
#define GL_OP_DOT3_EXT                                        0x8784
#define GL_OP_DOT4_EXT                                        0x8785
#define GL_OP_MUL_EXT                                         0x8786
#define GL_OP_ADD_EXT                                         0x8787
#define GL_OP_MADD_EXT                                        0x8788
#define GL_OP_FRAC_EXT                                        0x8789
#define GL_OP_MAX_EXT                                         0x878A
#define GL_OP_MIN_EXT                                         0x878B
#define GL_OP_SET_GE_EXT                                      0x878C
#define GL_OP_SET_LT_EXT                                      0x878D
#define GL_OP_CLAMP_EXT                                       0x878E
#define GL_OP_FLOOR_EXT                                       0x878F
#define GL_OP_ROUND_EXT                                       0x8790
#define GL_OP_EXP_BASE_2_EXT                                  0x8791
#define GL_OP_LOG_BASE_2_EXT                                  0x8792
#define GL_OP_POWER_EXT                                       0x8793
#define GL_OP_RECIP_EXT                                       0x8794
#define GL_OP_RECIP_SQRT_EXT                                  0x8795
#define GL_OP_SUB_EXT                                         0x8796
#define GL_OP_CROSS_PRODUCT_EXT                               0x8797
#define GL_OP_MULTIPLY_MATRIX_EXT                             0x8798
#define GL_OP_MOV_EXT                                         0x8799
#define GL_OUTPUT_VERTEX_EXT                                  0x879A
#define GL_OUTPUT_COLOR0_EXT                                  0x879B
#define GL_OUTPUT_COLOR1_EXT                                  0x879C
#define GL_OUTPUT_TEXTURE_COORD0_EXT                          0x879D
#define GL_OUTPUT_TEXTURE_COORD1_EXT                          0x879E
#define GL_OUTPUT_TEXTURE_COORD2_EXT                          0x879F
#define GL_OUTPUT_TEXTURE_COORD3_EXT                          0x87A0
#define GL_OUTPUT_TEXTURE_COORD4_EXT                          0x87A1
#define GL_OUTPUT_TEXTURE_COORD5_EXT                          0x87A2
#define GL_OUTPUT_TEXTURE_COORD6_EXT                          0x87A3
#define GL_OUTPUT_TEXTURE_COORD7_EXT                          0x87A4
#define GL_OUTPUT_TEXTURE_COORD8_EXT                          0x87A5
#define GL_OUTPUT_TEXTURE_COORD9_EXT                          0x87A6
#define GL_OUTPUT_TEXTURE_COORD10_EXT                         0x87A7
#define GL_OUTPUT_TEXTURE_COORD11_EXT                         0x87A8
#define GL_OUTPUT_TEXTURE_COORD12_EXT                         0x87A9
#define GL_OUTPUT_TEXTURE_COORD13_EXT                         0x87AA
#define GL_OUTPUT_TEXTURE_COORD14_EXT                         0x87AB
#define GL_OUTPUT_TEXTURE_COORD15_EXT                         0x87AC
#define GL_OUTPUT_TEXTURE_COORD16_EXT                         0x87AD
#define GL_OUTPUT_TEXTURE_COORD17_EXT                         0x87AE
#define GL_OUTPUT_TEXTURE_COORD18_EXT                         0x87AF
#define GL_OUTPUT_TEXTURE_COORD19_EXT                         0x87B0
#define GL_OUTPUT_TEXTURE_COORD20_EXT                         0x87B1
#define GL_OUTPUT_TEXTURE_COORD21_EXT                         0x87B2
#define GL_OUTPUT_TEXTURE_COORD22_EXT                         0x87B3
#define GL_OUTPUT_TEXTURE_COORD23_EXT                         0x87B4
#define GL_OUTPUT_TEXTURE_COORD24_EXT                         0x87B5
#define GL_OUTPUT_TEXTURE_COORD25_EXT                         0x87B6
#define GL_OUTPUT_TEXTURE_COORD26_EXT                         0x87B7
#define GL_OUTPUT_TEXTURE_COORD27_EXT                         0x87B8
#define GL_OUTPUT_TEXTURE_COORD28_EXT                         0x87B9
#define GL_OUTPUT_TEXTURE_COORD29_EXT                         0x87BA
#define GL_OUTPUT_TEXTURE_COORD30_EXT                         0x87BB
#define GL_OUTPUT_TEXTURE_COORD31_EXT                         0x87BC
#define GL_OUTPUT_FOG_EXT                                     0x87BD
#define GL_SCALAR_EXT                                         0x87BE
#define GL_VECTOR_EXT                                         0x87BF
#define GL_MATRIX_EXT                                         0x87C0
#define GL_VARIANT_EXT                                        0x87C1
#define GL_INVARIANT_EXT                                      0x87C2
#define GL_LOCAL_CONSTANT_EXT                                 0x87C3
#define GL_LOCAL_EXT                                          0x87C4
#define GL_MAX_VERTEX_SHADER_INSTRUCTIONS_EXT                 0x87C5
#define GL_MAX_VERTEX_SHADER_VARIANTS_EXT                     0x87C6
#define GL_MAX_VERTEX_SHADER_INVARIANTS_EXT                   0x87C7
#define GL_MAX_VERTEX_SHADER_LOCAL_CONSTANTS_EXT              0x87C8
#define GL_MAX_VERTEX_SHADER_LOCALS_EXT                       0x87C9
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_INSTRUCTIONS_EXT       0x87CA
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_VARIANTS_EXT           0x87CB
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCAL_CONSTANTS_EXT    0x87CC
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_INVARIANTS_EXT         0x87CD
#define GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCALS_EXT             0x87CE
#define GL_VERTEX_SHADER_INSTRUCTIONS_EXT                     0x87CF
#define GL_VERTEX_SHADER_VARIANTS_EXT                         0x87D0
#define GL_VERTEX_SHADER_INVARIANTS_EXT                       0x87D1
#define GL_VERTEX_SHADER_LOCAL_CONSTANTS_EXT                  0x87D2
#define GL_VERTEX_SHADER_LOCALS_EXT                           0x87D3
#define GL_VERTEX_SHADER_OPTIMIZED_EXT                        0x87D4
#define GL_X_EXT                                              0x87D5
#define GL_Y_EXT                                              0x87D6
#define GL_Z_EXT                                              0x87D7
#define GL_W_EXT                                              0x87D8
#define GL_NEGATIVE_X_EXT                                     0x87D9
#define GL_NEGATIVE_Y_EXT                                     0x87DA
#define GL_NEGATIVE_Z_EXT                                     0x87DB
#define GL_NEGATIVE_W_EXT                                     0x87DC
#define GL_ZERO_EXT                                           0x87DD
#define GL_ONE_EXT                                            0x87DE
#define GL_NEGATIVE_ONE_EXT                                   0x87DF
#define GL_NORMALIZED_RANGE_EXT                               0x87E0
#define GL_FULL_RANGE_EXT                                     0x87E1
#define GL_CURRENT_VERTEX_EXT                                 0x87E2
#define GL_MVP_MATRIX_EXT                                     0x87E3
#define GL_VARIANT_VALUE_EXT                                  0x87E4
#define GL_VARIANT_DATATYPE_EXT                               0x87E5
#define GL_VARIANT_ARRAY_STRIDE_EXT                           0x87E6
#define GL_VARIANT_ARRAY_TYPE_EXT                             0x87E7
#define GL_VARIANT_ARRAY_EXT                                  0x87E8
#define GL_VARIANT_ARRAY_POINTER_EXT                          0x87E9
#define GL_INVARIANT_VALUE_EXT                                0x87EA
#define GL_INVARIANT_DATATYPE_EXT                             0x87EB
#define GL_LOCAL_CONSTANT_VALUE_EXT                           0x87EC
#define GL_LOCAL_CONSTANT_DATATYPE_EXT                        0x87ED

OPENGL_INIT_PROC(glBeginVertexShaderEXT,         void,      void);
OPENGL_INIT_PROC(glEndVertexShaderEXT,           void,      void);
OPENGL_INIT_PROC(glBindVertexShaderEXT,          void,      GLuint id);
OPENGL_INIT_PROC(glGenVertexShadersEXT,          GLuint,    GLuint range);
OPENGL_INIT_PROC(glDeleteVertexShaderEXT,        void,      GLuint id);
OPENGL_INIT_PROC(glShaderOp1EXT,                 void,      GLenum op, GLuint res, GLuint arg1);
OPENGL_INIT_PROC(glShaderOp2EXT,                 void,      GLenum op, GLuint res, GLuint arg1, GLuint arg2);
OPENGL_INIT_PROC(glShaderOp3EXT,                 void,      GLenum op, GLuint res, GLuint arg1, GLuint arg2, GLuint arg3);
OPENGL_INIT_PROC(glSwizzleEXT,                   void,      GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
OPENGL_INIT_PROC(glWriteMaskEXT,                 void,      GLuint res, GLuint in, GLenum outX, GLenum outY, GLenum outZ, GLenum outW);
OPENGL_INIT_PROC(glInsertComponentEXT,           void,      GLuint res, GLuint src, GLuint num);
OPENGL_INIT_PROC(glExtractComponentEXT,          void,     GLuint res, GLuint src, GLuint num);
OPENGL_INIT_PROC(glGenSymbolsEXT,                GLuint,    GLenum datatype, GLenum storagetype, GLenum range, GLuint components);
OPENGL_INIT_PROC(glSetInvariantEXT,              void,      GLuint id, GLenum type, const void *addr);
OPENGL_INIT_PROC(glSetLocalConstantEXT,          void,      GLuint id, GLenum type, const void *addr);
OPENGL_INIT_PROC(glVariantbvEXT,                 void,      GLuint id, const GLbyte *addr);
OPENGL_INIT_PROC(glVariantsvEXT,                 void,      GLuint id, const GLshort *addr);
OPENGL_INIT_PROC(glVariantivEXT,                 void,      GLuint id, const GLint *addr);
OPENGL_INIT_PROC(glVariantfvEXT,                 void,      GLuint id, const GLfloat *addr);
OPENGL_INIT_PROC(glVariantdvEXT,                 void,      GLuint id, const GLdouble *addr);
OPENGL_INIT_PROC(glVariantubvEXT,                void,      GLuint id, const GLubyte *addr);
OPENGL_INIT_PROC(glVariantusvEXT,                void,      GLuint id, const GLushort *addr);
OPENGL_INIT_PROC(glVariantuivEXT,                void,      GLuint id, const GLuint *addr);
OPENGL_INIT_PROC(glVariantPointerEXT,            void,      GLuint id, GLenum type, GLuint stride, const void *addr);
OPENGL_INIT_PROC(glEnableVariantClientStateEXT,  void,      GLuint id);
OPENGL_INIT_PROC(glDisableVariantClientStateEXT, void,      GLuint id);
OPENGL_INIT_PROC(glBindLightParameterEXT,        GLuint,    GLenum light, GLenum value);
OPENGL_INIT_PROC(glBindMaterialParameterEXT,     GLuint,    GLenum face, GLenum value);
OPENGL_INIT_PROC(glBindTexGenParameterEXT,       GLuint,    GLenum unit, GLenum coord, GLenum value);
OPENGL_INIT_PROC(glBindTextureUnitParameterEXT,  GLuint,    GLenum unit, GLenum value);
OPENGL_INIT_PROC(glBindParameterEXT,             GLuint,    GLenum value);
OPENGL_INIT_PROC(glIsVariantEnabledEXT,          GLboolean, GLuint id, GLenum cap);
OPENGL_INIT_PROC(glGetVariantBooleanvEXT,        void,      GLuint id, GLenum value, GLboolean *data);
OPENGL_INIT_PROC(glGetVariantIntegervEXT,        void,      GLuint id, GLenum value, GLint *data);
OPENGL_INIT_PROC(glGetVariantFloatvEXT,          void,      GLuint id, GLenum value, GLfloat *data);
OPENGL_INIT_PROC(glGetVariantPointervEXT,        void,      GLuint id, GLenum value, void **data);
OPENGL_INIT_PROC(glGetInvariantBooleanvEXT,      void,      GLuint id, GLenum value, GLboolean *data);
OPENGL_INIT_PROC(glGetInvariantIntegervEXT,      void,      GLuint id, GLenum value, GLint *data);
OPENGL_INIT_PROC(glGetInvariantFloatvEXT,        void,      GLuint id, GLenum value, GLfloat *data);
OPENGL_INIT_PROC(glGetLocalConstantBooleanvEXT,  void,      GLuint id, GLenum value, GLboolean *data);
OPENGL_INIT_PROC(glGetLocalConstantIntegervEXT,  void,      GLuint id, GLenum value, GLint *data);
OPENGL_INIT_PROC(glGetLocalConstantFloatvEXT,    void,      GLuint id, GLenum value, GLfloat *data);

#define glBeginVertexShaderEXT         OGL__glBeginVertexShaderEXT
#define glEndVertexShaderEXT           OGL__glEndVertexShaderEXT
#define glBindVertexShaderEXT          OGL__glBindVertexShaderEXT
#define glGenVertexShadersEXT          OGL__glGenVertexShadersEXT
#define glDeleteVertexShaderEXT        OGL__glDeleteVertexShaderEXT
#define glShaderOp1EXT                 OGL__glShaderOp1EXT
#define glShaderOp2EXT                 OGL__glShaderOp2EXT
#define glShaderOp3EXT                 OGL__glShaderOp3EXT
#define glSwizzleEXT                   OGL__glSwizzleEXT
#define glWriteMaskEXT                 OGL__glWriteMaskEXT
#define glInsertComponentEXT           OGL__glInsertComponentEXT
#define glExtractComponentEXT          OGL__glExtractComponentEXT
#define glGenSymbolsEXT                OGL__glGenSymbolsEXT
#define glSetInvariantEXT              OGL__glSetInvariantEXT
#define glSetLocalConstantEXT          OGL__glSetLocalConstantEXT
#define glVariantbvEXT                 OGL__glVariantbvEXT
#define glVariantsvEXT                 OGL__glVariantsvEXT
#define glVariantivEXT                 OGL__glVariantivEXT
#define glVariantfvEXT                 OGL__glVariantfvEXT
#define glVariantdvEXT                 OGL__glVariantdvEXT
#define glVariantubvEXT                OGL__glVariantubvEXT
#define glVariantusvEXT                OGL__glVariantusvEXT
#define glVariantuivEXT                OGL__glVariantuivEXT
#define glVariantPointerEXT            OGL__glVariantPointerEXT
#define glEnableVariantClientStateEXT  OGL__glEnableVariantClientStateEXT
#define glDisableVariantClientStateEXT OGL__glDisableVariantClientStateEXT
#define glBindLightParameterEXT        OGL__glBindLightParameterEXT
#define glBindMaterialParameterEXT     OGL__glBindMaterialParameterEXT
#define glBindTexGenParameterEXT       OGL__glBindTexGenParameterEXT
#define glBindTextureUnitParameterEXT  OGL__glBindTextureUnitParameterEXT
#define glBindParameterEXT             OGL__glBindParameterEXT
#define glIsVariantEnabledEXT          OGL__glIsVariantEnabledEXT
#define glGetVariantBooleanvEXT        OGL__glGetVariantBooleanvEXT
#define glGetVariantIntegervEXT        OGL__glGetVariantIntegervEXT
#define glGetVariantFloatvEXT          OGL__glGetVariantFloatvEXT
#define glGetVariantPointervEXT        OGL__glGetVariantPointervEXT
#define glGetInvariantBooleanvEXT      OGL__glGetInvariantBooleanvEXT
#define glGetInvariantIntegervEXT      OGL__glGetInvariantIntegervEXT
#define glGetInvariantFloatvEXT        OGL__glGetInvariantFloatvEXT
#define glGetLocalConstantBooleanvEXT  OGL__glGetLocalConstantBooleanvEXT
#define glGetLocalConstantIntegervEXT  OGL__glGetLocalConstantIntegervEXT
#define glGetLocalConstantFloatvEXT    OGL__glGetLocalConstantFloatvEXT

#endif // GL_EXT_vertex_shader

#endif // OPENGL_INCLUDE_GL_EXT_vertex_shader

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_vertex_weighting

#ifndef GL_EXT_vertex_weighting
#define GL_EXT_vertex_weighting 1

#define GL_MODELVIEW0_STACK_DEPTH_EXT         0x0BA3
#define GL_MODELVIEW1_STACK_DEPTH_EXT         0x8502
#define GL_MODELVIEW0_MATRIX_EXT              0x0BA6
#define GL_MODELVIEW1_MATRIX_EXT              0x8506
#define GL_VERTEX_WEIGHTING_EXT               0x8509
#define GL_MODELVIEW0_EXT                     0x1700
#define GL_MODELVIEW1_EXT                     0x850A
#define GL_CURRENT_VERTEX_WEIGHT_EXT          0x850B
#define GL_VERTEX_WEIGHT_ARRAY_EXT            0x850C
#define GL_VERTEX_WEIGHT_ARRAY_SIZE_EXT       0x850D
#define GL_VERTEX_WEIGHT_ARRAY_TYPE_EXT       0x850E
#define GL_VERTEX_WEIGHT_ARRAY_STRIDE_EXT     0x850F
#define GL_VERTEX_WEIGHT_ARRAY_POINTER_EXT    0x8510

OPENGL_INIT_PROC(glVertexWeightfEXT,       void, GLfloat weight);
OPENGL_INIT_PROC(glVertexWeightfvEXT,      void, const GLfloat *weight);
OPENGL_INIT_PROC(glVertexWeightPointerEXT, void, GLint size, GLenum type, GLsizei stride, const void *pointer);

#define glVertexWeightfEXT       OGL__glVertexWeightfEXT
#define glVertexWeightfvEXT      OGL__glVertexWeightfvEXT
#define glVertexWeightPointerEXT OGL__glVertexWeightPointerEXT

#endif // GL_EXT_vertex_weighting

#endif // OPENGL_INCLUDE_GL_EXT_vertex_weighting

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_win32_keyed_mutex

#ifndef GL_EXT_win32_keyed_mutex
#define GL_EXT_win32_keyed_mutex 1

OPENGL_INIT_PROC(glAcquireKeyedMutexWin32EXT, GLboolean, GLuint memory, GLuint64 key, GLuint timeout);
OPENGL_INIT_PROC(glReleaseKeyedMutexWin32EXT, GLboolean, GLuint memory, GLuint64 key);

#define glAcquireKeyedMutexWin32EXT OGL__glAcquireKeyedMutexWin32EXT
#define glReleaseKeyedMutexWin32EXT OGL__glReleaseKeyedMutexWin32EXT

#endif // GL_EXT_win32_keyed_mutex

#endif // OPENGL_INCLUDE_GL_EXT_win32_keyed_mutex

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_window_rectangles

#ifndef GL_EXT_window_rectangles
#define GL_EXT_window_rectangles 1

#define GL_INCLUSIVE_EXT                0x8F10
#define GL_EXCLUSIVE_EXT                0x8F11
#define GL_WINDOW_RECTANGLE_EXT         0x8F12
#define GL_WINDOW_RECTANGLE_MODE_EXT    0x8F13
#define GL_MAX_WINDOW_RECTANGLES_EXT    0x8F14
#define GL_NUM_WINDOW_RECTANGLES_EXT    0x8F15

OPENGL_INIT_PROC(glWindowRectanglesEXT, void, GLenum mode, GLsizei count, const GLint *box);
#define glWindowRectanglesEXT OGL__glWindowRectanglesEXT

#endif // GL_EXT_window_rectangles

#endif // OPENGL_INCLUDE_GL_EXT_window_rectangles

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_EXT_x11_sync_object

#ifndef GL_EXT_x11_sync_object
#define GL_EXT_x11_sync_object 1

#define GL_SYNC_X11_FENCE_EXT    0x90E1

OPENGL_INIT_PROC(glImportSyncEXT, GLsync, GLenum external_sync_type, GLintptr external_sync, GLbitfield flags);
#define glImportSyncEXT OGL__glImportSyncEXT

#endif // GL_EXT_x11_sync_object

#endif // OPENGL_INCLUDE_GL_EXT_x11_sync_object

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_GREMEDY_frame_terminator

#ifndef GL_GREMEDY_frame_terminator
#define GL_GREMEDY_frame_terminator 1

OPENGL_INIT_PROC(glFrameTerminatorGREMEDY, void, void);
#define glFrameTerminatorGREMEDY OGL__glFrameTerminatorGREMEDY

#endif // GL_GREMEDY_frame_terminator

#endif // OPENGL_INCLUDE_GL_GREMEDY_frame_terminator

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_GREMEDY_string_marker

#ifndef GL_GREMEDY_string_marker
#define GL_GREMEDY_string_marker 1

OPENGL_INIT_PROC(glStringMarkerGREMEDY, void, GLsizei len, const void *string);
#define glStringMarkerGREMEDY OGL__glStringMarkerGREMEDY

#endif // GL_GREMEDY_string_marker

#endif // OPENGL_INCLUDE_GL_GREMEDY_string_marker

/* -------------------------------------------------------------------------- */

#ifndef GL_HP_convolution_border_modes
#define GL_HP_convolution_border_modes 1

#define GL_IGNORE_BORDER_HP               0x8150
#define GL_CONSTANT_BORDER_HP             0x8151
#define GL_REPLICATE_BORDER_HP            0x8153
#define GL_CONVOLUTION_BORDER_COLOR_HP    0x8154

#endif // GL_HP_convolution_border_modes

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_HP_image_transform

#ifndef GL_HP_image_transform
#define GL_HP_image_transform 1

#define GL_IMAGE_SCALE_X_HP                             0x8155
#define GL_IMAGE_SCALE_Y_HP                             0x8156
#define GL_IMAGE_TRANSLATE_X_HP                         0x8157
#define GL_IMAGE_TRANSLATE_Y_HP                         0x8158
#define GL_IMAGE_ROTATE_ANGLE_HP                        0x8159
#define GL_IMAGE_ROTATE_ORIGIN_X_HP                     0x815A
#define GL_IMAGE_ROTATE_ORIGIN_Y_HP                     0x815B
#define GL_IMAGE_MAG_FILTER_HP                          0x815C
#define GL_IMAGE_MIN_FILTER_HP                          0x815D
#define GL_IMAGE_CUBIC_WEIGHT_HP                        0x815E
#define GL_CUBIC_HP                                     0x815F
#define GL_AVERAGE_HP                                   0x8160
#define GL_IMAGE_TRANSFORM_2D_HP                        0x8161
#define GL_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP          0x8162
#define GL_PROXY_POST_IMAGE_TRANSFORM_COLOR_TABLE_HP    0x8163

OPENGL_INIT_PROC(glImageTransformParameteriHP,     void, GLenum target, GLenum pname, GLint param);
OPENGL_INIT_PROC(glImageTransformParameterfHP,     void, GLenum target, GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glImageTransformParameterivHP,    void, GLenum target, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glImageTransformParameterfvHP,    void, GLenum target, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glGetImageTransformParameterivHP, void, GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetImageTransformParameterfvHP, void, GLenum target, GLenum pname, GLfloat *params);

#define glImageTransformParameteriHP     OGL__glImageTransformParameteriHP
#define glImageTransformParameterfHP     OGL__glImageTransformParameterfHP
#define glImageTransformParameterivHP    OGL__glImageTransformParameterivHP
#define glImageTransformParameterfvHP    OGL__glImageTransformParameterfvHP
#define glGetImageTransformParameterivHP OGL__glGetImageTransformParameterivHP
#define glGetImageTransformParameterfvHP OGL__glGetImageTransformParameterfvHP

#endif // GL_HP_image_transform

#endif // OPENGL_INCLUDE_GL_HP_image_transform

/* -------------------------------------------------------------------------- */

#ifndef GL_HP_occlusion_test
#define GL_HP_occlusion_test 1

#define GL_OCCLUSION_TEST_HP           0x8165
#define GL_OCCLUSION_TEST_RESULT_HP    0x8166

#endif // GL_HP_occlusion_test

/* -------------------------------------------------------------------------- */

#ifndef GL_HP_texture_lighting
#define GL_HP_texture_lighting 1

#define GL_TEXTURE_LIGHTING_MODE_HP    0x8167
#define GL_TEXTURE_POST_SPECULAR_HP    0x8168
#define GL_TEXTURE_PRE_SPECULAR_HP     0x8169

#endif // GL_HP_texture_lighting

/* -------------------------------------------------------------------------- */

#ifndef GL_IBM_cull_vertex
#define GL_IBM_cull_vertex 1

#define GL_CULL_VERTEX_IBM    103050

#endif // GL_IBM_cull_vertex

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_IBM_multimode_draw_arrays

#ifndef GL_IBM_multimode_draw_arrays
#define GL_IBM_multimode_draw_arrays 1

OPENGL_INIT_PROC(glMultiModeDrawArraysIBM,   void, const GLenum *mode, const GLint *first, const GLsizei *count, GLsizei primcount, GLint modestride);
OPENGL_INIT_PROC(glMultiModeDrawElementsIBM, void, const GLenum *mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei primcount, GLint modestride);

#define glMultiModeDrawArraysIBM   OGL__glMultiModeDrawArraysIBM
#define glMultiModeDrawElementsIBM OGL__glMultiModeDrawElementsIBM

#endif // GL_IBM_multimode_draw_arrays

#endif // OPENGL_INCLUDE_GL_IBM_multimode_draw_arrays

/* -------------------------------------------------------------------------- */

#ifndef GL_IBM_rasterpos_clip
#define GL_IBM_rasterpos_clip 1

#define GL_RASTER_POSITION_UNCLIPPED_IBM    0x19262

#endif // GL_IBM_rasterpos_clip

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_IBM_static_data

#ifndef GL_IBM_static_data
#define GL_IBM_static_data 1

#define GL_ALL_STATIC_DATA_IBM        103060
#define GL_STATIC_VERTEX_ARRAY_IBM    103061

OPENGL_INIT_PROC(glFlushStaticDataIBM, void, GLenum target);
#define glFlushStaticDataIBM OGL__glFlushStaticDataIBM

#endif // GL_IBM_static_data

#endif // OPENGL_INCLUDE_GL_IBM_static_data

/* -------------------------------------------------------------------------- */

#ifndef GL_IBM_texture_mirrored_repeat
#define GL_IBM_texture_mirrored_repeat 1

#define GL_MIRRORED_REPEAT_IBM    0x8370

#endif // GL_IBM_texture_mirrored_repeat

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_IBM_vertex_array_lists

#ifndef GL_IBM_vertex_array_lists
#define GL_IBM_vertex_array_lists 1

#define GL_VERTEX_ARRAY_LIST_IBM                    103070
#define GL_NORMAL_ARRAY_LIST_IBM                    103071
#define GL_COLOR_ARRAY_LIST_IBM                     103072
#define GL_INDEX_ARRAY_LIST_IBM                     103073
#define GL_TEXTURE_COORD_ARRAY_LIST_IBM             103074
#define GL_EDGE_FLAG_ARRAY_LIST_IBM                 103075
#define GL_FOG_COORDINATE_ARRAY_LIST_IBM            103076
#define GL_SECONDARY_COLOR_ARRAY_LIST_IBM           103077
#define GL_VERTEX_ARRAY_LIST_STRIDE_IBM             103080
#define GL_NORMAL_ARRAY_LIST_STRIDE_IBM             103081
#define GL_COLOR_ARRAY_LIST_STRIDE_IBM              103082
#define GL_INDEX_ARRAY_LIST_STRIDE_IBM              103083
#define GL_TEXTURE_COORD_ARRAY_LIST_STRIDE_IBM      103084
#define GL_EDGE_FLAG_ARRAY_LIST_STRIDE_IBM          103085
#define GL_FOG_COORDINATE_ARRAY_LIST_STRIDE_IBM     103086
#define GL_SECONDARY_COLOR_ARRAY_LIST_STRIDE_IBM    103087

OPENGL_INIT_PROC(glColorPointerListIBM,          void, GLint size, GLenum type, GLint stride, const void **pointer, GLint ptrstride);
OPENGL_INIT_PROC(glSecondaryColorPointerListIBM, void, GLint size, GLenum type, GLint stride, const void **pointer, GLint ptrstride);
OPENGL_INIT_PROC(glEdgeFlagPointerListIBM,       void, GLint stride, const GLboolean **pointer, GLint ptrstride);
OPENGL_INIT_PROC(glFogCoordPointerListIBM,       void, GLenum type, GLint stride, const void **pointer, GLint ptrstride);
OPENGL_INIT_PROC(glIndexPointerListIBM,          void, GLenum type, GLint stride, const void **pointer, GLint ptrstride);
OPENGL_INIT_PROC(glNormalPointerListIBM,         void, GLenum type, GLint stride, const void **pointer, GLint ptrstride);
OPENGL_INIT_PROC(glTexCoordPointerListIBM,       void, GLint size, GLenum type, GLint stride, const void **pointer, GLint ptrstride);
OPENGL_INIT_PROC(glVertexPointerListIBM,         void, GLint size, GLenum type, GLint stride, const void **pointer, GLint ptrstride);

#define glColorPointerListIBM          OGL__glColorPointerListIBM
#define glSecondaryColorPointerListIBM OGL__glSecondaryColorPointerListIBM
#define glEdgeFlagPointerListIBM       OGL__glEdgeFlagPointerListIBM
#define glFogCoordPointerListIBM       OGL__glFogCoordPointerListIBM
#define glIndexPointerListIBM          OGL__glIndexPointerListIBM
#define glNormalPointerListIBM         OGL__glNormalPointerListIBM
#define glTexCoordPointerListIBM       OGL__glTexCoordPointerListIBM
#define glVertexPointerListIBM         OGL__glVertexPointerListIBM

#endif // GL_IBM_vertex_array_lists

#endif // OPENGL_INCLUDE_GL_IBM_vertex_array_lists

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_INGR_blend_func_separate

#ifndef GL_INGR_blend_func_separate
#define GL_INGR_blend_func_separate 1

OPENGL_INIT_PROC(glBlendFuncSeparateINGR, void, GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
#define glBlendFuncSeparateINGR OGL__glBlendFuncSeparateINGR

#endif // GL_INGR_blend_func_separate

#endif // OPENGL_INCLUDE_GL_INGR_blend_func_separate

/* -------------------------------------------------------------------------- */

#ifndef GL_INGR_color_clamp
#define GL_INGR_color_clamp 1

#define GL_RED_MIN_CLAMP_INGR      0x8560
#define GL_GREEN_MIN_CLAMP_INGR    0x8561
#define GL_BLUE_MIN_CLAMP_INGR     0x8562
#define GL_ALPHA_MIN_CLAMP_INGR    0x8563
#define GL_RED_MAX_CLAMP_INGR      0x8564
#define GL_GREEN_MAX_CLAMP_INGR    0x8565
#define GL_BLUE_MAX_CLAMP_INGR     0x8566
#define GL_ALPHA_MAX_CLAMP_INGR    0x8567

#endif // GL_INGR_color_clamp

/* -------------------------------------------------------------------------- */

#ifndef GL_INGR_interlace_read
#define GL_INGR_interlace_read 1

#define GL_INTERLACE_READ_INGR    0x8568

#endif // GL_INGR_interlace_read

/* -------------------------------------------------------------------------- */

#ifndef GL_INTEL_blackhole_render
#define GL_INTEL_blackhole_render 1

#define GL_BLACKHOLE_RENDER_INTEL    0x83FC

#endif // GL_INTEL_blackhole_render

/* -------------------------------------------------------------------------- */

#ifndef GL_INTEL_conservative_rasterization
#define GL_INTEL_conservative_rasterization 1

#define GL_CONSERVATIVE_RASTERIZATION_INTEL    0x83FE

#endif // GL_INTEL_conservative_rasterization

/* -------------------------------------------------------------------------- */

#ifndef GL_INTEL_fragment_shader_ordering
#define GL_INTEL_fragment_shader_ordering 1

#endif // GL_INTEL_fragment_shader_ordering

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_INTEL_framebuffer_CMAA

#ifndef GL_INTEL_framebuffer_CMAA
#define GL_INTEL_framebuffer_CMAA 1

OPENGL_INIT_PROC(glApplyFramebufferAttachmentCMAAINTEL, void, void);
#define glApplyFramebufferAttachmentCMAAINTEL OGL__glApplyFramebufferAttachmentCMAAINTEL

#endif // GL_INTEL_framebuffer_CMAA

#endif // OPENGL_INCLUDE_GL_INTEL_framebuffer_CMAA

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_INTEL_map_texture

#ifndef GL_INTEL_map_texture
#define GL_INTEL_map_texture 1

#define GL_TEXTURE_MEMORY_LAYOUT_INTEL       0x83FF
#define GL_LAYOUT_DEFAULT_INTEL              0
#define GL_LAYOUT_LINEAR_INTEL               1
#define GL_LAYOUT_LINEAR_CPU_CACHED_INTEL    2

OPENGL_INIT_PROC(glSyncTextureINTEL,    void,  GLuint texture);
OPENGL_INIT_PROC(glUnmapTexture2DINTEL, void,  GLuint texture, GLint level);
OPENGL_INIT_PROC(glMapTexture2DINTEL,   void*, GLuint texture, GLint level, GLbitfield access, GLint *stride, GLenum *layout);

#define glSyncTextureINTEL    OGL__glSyncTextureINTEL
#define glUnmapTexture2DINTEL OGL__glUnmapTexture2DINTEL
#define glMapTexture2DINTEL   OGL__glMapTexture2DINTEL

#endif // GL_INTEL_map_texture

#endif // OPENGL_INCLUDE_GL_INTEL_map_texture

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_INTEL_parallel_arrays

#ifndef GL_INTEL_parallel_arrays
#define GL_INTEL_parallel_arrays 1

#define GL_PARALLEL_ARRAYS_INTEL                          0x83F4
#define GL_VERTEX_ARRAY_PARALLEL_POINTERS_INTEL           0x83F5
#define GL_NORMAL_ARRAY_PARALLEL_POINTERS_INTEL           0x83F6
#define GL_COLOR_ARRAY_PARALLEL_POINTERS_INTEL            0x83F7
#define GL_TEXTURE_COORD_ARRAY_PARALLEL_POINTERS_INTEL    0x83F8

OPENGL_INIT_PROC(glVertexPointervINTEL,   void, GLint size, GLenum type, const void **pointer);
OPENGL_INIT_PROC(glNormalPointervINTEL,   void, GLenum type, const void **pointer);
OPENGL_INIT_PROC(glColorPointervINTEL,    void, GLint size, GLenum type, const void **pointer);
OPENGL_INIT_PROC(glTexCoordPointervINTEL, void, GLint size, GLenum type, const void **pointer);

#define glVertexPointervINTEL   OGL__glVertexPointervINTEL
#define glNormalPointervINTEL   OGL__glNormalPointervINTEL
#define glColorPointervINTEL    OGL__glColorPointervINTEL
#define glTexCoordPointervINTEL OGL__glTexCoordPointervINTEL

#endif // GL_INTEL_parallel_arrays

#endif // OPENGL_INCLUDE_GL_INTEL_parallel_arrays

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_INTEL_performance_query

#ifndef GL_INTEL_performance_query
#define GL_INTEL_performance_query 1

#define GL_PERFQUERY_SINGLE_CONTEXT_INTEL             0x00000000
#define GL_PERFQUERY_GLOBAL_CONTEXT_INTEL             0x00000001
#define GL_PERFQUERY_WAIT_INTEL                       0x83FB
#define GL_PERFQUERY_FLUSH_INTEL                      0x83FA
#define GL_PERFQUERY_DONOT_FLUSH_INTEL                0x83F9
#define GL_PERFQUERY_COUNTER_EVENT_INTEL              0x94F0
#define GL_PERFQUERY_COUNTER_DURATION_NORM_INTEL      0x94F1
#define GL_PERFQUERY_COUNTER_DURATION_RAW_INTEL       0x94F2
#define GL_PERFQUERY_COUNTER_THROUGHPUT_INTEL         0x94F3
#define GL_PERFQUERY_COUNTER_RAW_INTEL                0x94F4
#define GL_PERFQUERY_COUNTER_TIMESTAMP_INTEL          0x94F5
#define GL_PERFQUERY_COUNTER_DATA_UINT32_INTEL        0x94F8
#define GL_PERFQUERY_COUNTER_DATA_UINT64_INTEL        0x94F9
#define GL_PERFQUERY_COUNTER_DATA_FLOAT_INTEL         0x94FA
#define GL_PERFQUERY_COUNTER_DATA_DOUBLE_INTEL        0x94FB
#define GL_PERFQUERY_COUNTER_DATA_BOOL32_INTEL        0x94FC
#define GL_PERFQUERY_QUERY_NAME_LENGTH_MAX_INTEL      0x94FD
#define GL_PERFQUERY_COUNTER_NAME_LENGTH_MAX_INTEL    0x94FE
#define GL_PERFQUERY_COUNTER_DESC_LENGTH_MAX_INTEL    0x94FF
#define GL_PERFQUERY_GPA_EXTENDED_COUNTERS_INTEL      0x9500

OPENGL_INIT_PROC(glBeginPerfQueryINTEL,       void, GLuint queryHandle);
OPENGL_INIT_PROC(glCreatePerfQueryINTEL,      void, GLuint queryId, GLuint *queryHandle);
OPENGL_INIT_PROC(glDeletePerfQueryINTEL,      void, GLuint queryHandle);
OPENGL_INIT_PROC(glEndPerfQueryINTEL,         void, GLuint queryHandle);
OPENGL_INIT_PROC(glGetFirstPerfQueryIdINTEL,  void, GLuint *queryId);
OPENGL_INIT_PROC(glGetNextPerfQueryIdINTEL,   void, GLuint queryId, GLuint *nextQueryId);
OPENGL_INIT_PROC(glGetPerfCounterInfoINTEL,   void, GLuint queryId, GLuint counterId, GLuint counterNameLength, GLchar *counterName, GLuint counterDescLength, GLchar *counterDesc, GLuint *counterOffset, GLuint *counterDataSize, GLuint *counterTypeEnum, GLuint *counterDataTypeEnum, GLuint64 *rawCounterMaxValue);
OPENGL_INIT_PROC(glGetPerfQueryDataINTEL,     void, GLuint queryHandle, GLuint flags, GLsizei dataSize, void *data, GLuint *bytesWritten);
OPENGL_INIT_PROC(glGetPerfQueryIdByNameINTEL, void, GLchar *queryName, GLuint *queryId);
OPENGL_INIT_PROC(glGetPerfQueryInfoINTEL,     void, GLuint queryId, GLuint queryNameLength, GLchar *queryName, GLuint *dataSize, GLuint *noCounters, GLuint *noInstances, GLuint *capsMask);

#define glBeginPerfQueryINTEL       OGL__glBeginPerfQueryINTEL
#define glCreatePerfQueryINTEL      OGL__glCreatePerfQueryINTEL
#define glDeletePerfQueryINTEL      OGL__glDeletePerfQueryINTEL
#define glEndPerfQueryINTEL         OGL__glEndPerfQueryINTEL
#define glGetFirstPerfQueryIdINTEL  OGL__glGetFirstPerfQueryIdINTEL
#define glGetNextPerfQueryIdINTEL   OGL__glGetNextPerfQueryIdINTEL
#define glGetPerfCounterInfoINTEL   OGL__glGetPerfCounterInfoINTEL
#define glGetPerfQueryDataINTEL     OGL__glGetPerfQueryDataINTEL
#define glGetPerfQueryIdByNameINTEL OGL__glGetPerfQueryIdByNameINTEL
#define glGetPerfQueryInfoINTEL     OGL__glGetPerfQueryInfoINTEL

#endif // GL_INTEL_performance_query

#endif // OPENGL_INCLUDE_GL_INTEL_performance_query

/* -------------------------------------------------------------------------- */

#ifndef GL_MESAX_texture_stack
#define GL_MESAX_texture_stack 1

#define GL_TEXTURE_1D_STACK_MESAX            0x8759
#define GL_TEXTURE_2D_STACK_MESAX            0x875A
#define GL_PROXY_TEXTURE_1D_STACK_MESAX      0x875B
#define GL_PROXY_TEXTURE_2D_STACK_MESAX      0x875C
#define GL_TEXTURE_1D_STACK_BINDING_MESAX    0x875D
#define GL_TEXTURE_2D_STACK_BINDING_MESAX    0x875E

#endif // GL_MESAX_texture_stack

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_MESA_framebuffer_flip_y

#ifndef GL_MESA_framebuffer_flip_y
#define GL_MESA_framebuffer_flip_y 1

#define GL_FRAMEBUFFER_FLIP_Y_MESA    0x8BBB

OPENGL_INIT_PROC(glFramebufferParameteriMESA,     void, GLenum target, GLenum pname, GLint param);
OPENGL_INIT_PROC(glGetFramebufferParameterivMESA, void, GLenum target, GLenum pname, GLint *params);

#define glFramebufferParameteriMESA     OGL__glFramebufferParameteriMESA
#define glGetFramebufferParameterivMESA OGL__glGetFramebufferParameterivMESA

#endif // GL_MESA_framebuffer_flip_y

#endif // OPENGL_INCLUDE_GL_MESA_framebuffer_flip_y

/* -------------------------------------------------------------------------- */

#ifndef GL_MESA_pack_invert
#define GL_MESA_pack_invert 1

#define GL_PACK_INVERT_MESA    0x8758

#endif // GL_MESA_pack_invert

/* -------------------------------------------------------------------------- */

#ifndef GL_MESA_program_binary_formats
#define GL_MESA_program_binary_formats 1

#define GL_PROGRAM_BINARY_FORMAT_MESA    0x875F

#endif // GL_MESA_program_binary_formats

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_MESA_resize_buffers

#ifndef GL_MESA_resize_buffers
#define GL_MESA_resize_buffers 1

OPENGL_INIT_PROC(glResizeBuffersMESA, void, void);
#define glResizeBuffersMESA OGL__glResizeBuffersMESA

#endif // GL_MESA_resize_buffers

#endif // OPENGL_INCLUDE_GL_MESA_resize_buffers

/* -------------------------------------------------------------------------- */

#ifndef GL_MESA_shader_integer_functions
#define GL_MESA_shader_integer_functions 1

#endif // GL_MESA_shader_integer_functions

/* -------------------------------------------------------------------------- */

#ifndef GL_MESA_tile_raster_order
#define GL_MESA_tile_raster_order 1

#define GL_TILE_RASTER_ORDER_FIXED_MESA           0x8BB8
#define GL_TILE_RASTER_ORDER_INCREASING_X_MESA    0x8BB9
#define GL_TILE_RASTER_ORDER_INCREASING_Y_MESA    0x8BBA

#endif // GL_MESA_tile_raster_order

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_MESA_window_pos

#ifndef GL_MESA_window_pos
#define GL_MESA_window_pos 1

OPENGL_INIT_PROC(glWindowPos2dMESA,  void, GLdouble x, GLdouble y);
OPENGL_INIT_PROC(glWindowPos2dvMESA, void, const GLdouble *v);
OPENGL_INIT_PROC(glWindowPos2fMESA,  void, GLfloat x, GLfloat y);
OPENGL_INIT_PROC(glWindowPos2fvMESA, void, const GLfloat *v);
OPENGL_INIT_PROC(glWindowPos2iMESA,  void, GLint x, GLint y);
OPENGL_INIT_PROC(glWindowPos2ivMESA, void, const GLint *v);
OPENGL_INIT_PROC(glWindowPos2sMESA,  void, GLshort x, GLshort y);
OPENGL_INIT_PROC(glWindowPos2svMESA, void, const GLshort *v);
OPENGL_INIT_PROC(glWindowPos3dMESA,  void, GLdouble x, GLdouble y, GLdouble z);
OPENGL_INIT_PROC(glWindowPos3dvMESA, void, const GLdouble *v);
OPENGL_INIT_PROC(glWindowPos3fMESA,  void, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glWindowPos3fvMESA, void, const GLfloat *v);
OPENGL_INIT_PROC(glWindowPos3iMESA,  void, GLint x, GLint y, GLint z);
OPENGL_INIT_PROC(glWindowPos3ivMESA, void, const GLint *v);
OPENGL_INIT_PROC(glWindowPos3sMESA,  void, GLshort x, GLshort y, GLshort z);
OPENGL_INIT_PROC(glWindowPos3svMESA, void, const GLshort *v);
OPENGL_INIT_PROC(glWindowPos4dMESA,  void, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
OPENGL_INIT_PROC(glWindowPos4dvMESA, void, const GLdouble *v);
OPENGL_INIT_PROC(glWindowPos4fMESA,  void, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
OPENGL_INIT_PROC(glWindowPos4fvMESA, void, const GLfloat *v);
OPENGL_INIT_PROC(glWindowPos4iMESA,  void, GLint x, GLint y, GLint z, GLint w);
OPENGL_INIT_PROC(glWindowPos4ivMESA, void, const GLint *v);
OPENGL_INIT_PROC(glWindowPos4sMESA,  void, GLshort x, GLshort y, GLshort z, GLshort w);
OPENGL_INIT_PROC(glWindowPos4svMESA, void, const GLshort *v);

#define glWindowPos2dMESA  OGL__glWindowPos2dMESA
#define glWindowPos2dvMESA OGL__glWindowPos2dvMESA
#define glWindowPos2fMESA  OGL__glWindowPos2fMESA
#define glWindowPos2fvMESA OGL__glWindowPos2fvMESA
#define glWindowPos2iMESA  OGL__glWindowPos2iMESA
#define glWindowPos2ivMESA OGL__glWindowPos2ivMESA
#define glWindowPos2sMESA  OGL__glWindowPos2sMESA
#define glWindowPos2svMESA OGL__glWindowPos2svMESA
#define glWindowPos3dMESA  OGL__glWindowPos3dMESA
#define glWindowPos3dvMESA OGL__glWindowPos3dvMESA
#define glWindowPos3fMESA  OGL__glWindowPos3fMESA
#define glWindowPos3fvMESA OGL__glWindowPos3fvMESA
#define glWindowPos3iMESA  OGL__glWindowPos3iMESA
#define glWindowPos3ivMESA OGL__glWindowPos3ivMESA
#define glWindowPos3sMESA  OGL__glWindowPos3sMESA
#define glWindowPos3svMESA OGL__glWindowPos3svMESA
#define glWindowPos4dMESA  OGL__glWindowPos4dMESA
#define glWindowPos4dvMESA OGL__glWindowPos4dvMESA
#define glWindowPos4fMESA  OGL__glWindowPos4fMESA
#define glWindowPos4fvMESA OGL__glWindowPos4fvMESA
#define glWindowPos4iMESA  OGL__glWindowPos4iMESA
#define glWindowPos4ivMESA OGL__glWindowPos4ivMESA
#define glWindowPos4sMESA  OGL__glWindowPos4sMESA
#define glWindowPos4svMESA OGL__glWindowPos4svMESA

#endif // GL_MESA_window_pos

#endif // OPENGL_INCLUDE_GL_MESA_window_pos

/* -------------------------------------------------------------------------- */

#ifndef GL_MESA_ycbcr_texture
#define GL_MESA_ycbcr_texture 1

#define GL_UNSIGNED_SHORT_8_8_MESA        0x85BA
#define GL_UNSIGNED_SHORT_8_8_REV_MESA    0x85BB
#define GL_YCBCR_MESA                     0x8757

#endif // GL_MESA_ycbcr_texture

/* -------------------------------------------------------------------------- */

#ifndef GL_NVX_blend_equation_advanced_multi_draw_buffers
#define GL_NVX_blend_equation_advanced_multi_draw_buffers 1

#endif // GL_NVX_blend_equation_advanced_multi_draw_buffers

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NVX_conditional_render

#ifndef GL_NVX_conditional_render
#define GL_NVX_conditional_render 1

OPENGL_INIT_PROC(glBeginConditionalRenderNVX, void, GLuint id);
OPENGL_INIT_PROC(glEndConditionalRenderNVX,   void, void);

#define glBeginConditionalRenderNVX OGL__glBeginConditionalRenderNVX
#define glEndConditionalRenderNVX   OGL__glEndConditionalRenderNVX

#endif // GL_NVX_conditional_render

#endif // OPENGL_INCLUDE_GL_NVX_conditional_render

/* -------------------------------------------------------------------------- */

#ifndef GL_NVX_gpu_memory_info
#define GL_NVX_gpu_memory_info 1

#define GL_GPU_MEMORY_INFO_DEDICATED_VIDMEM_NVX            0x9047
#define GL_GPU_MEMORY_INFO_TOTAL_AVAILABLE_MEMORY_NVX      0x9048
#define GL_GPU_MEMORY_INFO_CURRENT_AVAILABLE_VIDMEM_NVX    0x9049
#define GL_GPU_MEMORY_INFO_EVICTION_COUNT_NVX              0x904A
#define GL_GPU_MEMORY_INFO_EVICTED_MEMORY_NVX              0x904B

#endif // GL_NVX_gpu_memory_info

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NVX_gpu_multicast2

#ifndef GL_NVX_gpu_multicast2
#define GL_NVX_gpu_multicast2 1

#define GL_UPLOAD_GPU_MASK_NVX    0x954A

OPENGL_INIT_PROC(glUploadGpuMaskNVX,                   void,   GLbitfield mask);
OPENGL_INIT_PROC(glMulticastViewportArrayvNVX,         void,   GLuint gpu, GLuint first, GLsizei count, const GLfloat *v);
OPENGL_INIT_PROC(glMulticastViewportPositionWScaleNVX, void,   GLuint gpu, GLuint index, GLfloat xcoeff, GLfloat ycoeff);
OPENGL_INIT_PROC(glMulticastScissorArrayvNVX,          void,   GLuint gpu, GLuint first, GLsizei count, const GLint *v);
OPENGL_INIT_PROC(glAsyncCopyBufferSubDataNVX,          GLuint, GLsizei waitSemaphoreCount, const GLuint *waitSemaphoreArray, const GLuint64 *fenceValueArray, GLuint readGpu, GLbitfield writeGpuMask, GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size, GLsizei signalSemaphoreCount, const GLuint *signalSemaphoreArray, const GLuint64 *signalValueArray);
OPENGL_INIT_PROC(glAsyncCopyImageSubDataNVX,           GLuint, GLsizei waitSemaphoreCount, const GLuint *waitSemaphoreArray, const GLuint64 *waitValueArray, GLuint srcGpu, GLbitfield dstGpuMask, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth, GLsizei signalSemaphoreCount, const GLuint *signalSemaphoreArray, const GLuint64 *signalValueArray);

#define glUploadGpuMaskNVX                   OGL__glUploadGpuMaskNVX
#define glMulticastViewportArrayvNVX         OGL__glMulticastViewportArrayvNVX
#define glMulticastViewportPositionWScaleNVX OGL__glMulticastViewportPositionWScaleNVX
#define glMulticastScissorArrayvNVX          OGL__glMulticastScissorArrayvNVX
#define glAsyncCopyBufferSubDataNVX          OGL__glAsyncCopyBufferSubDataNVX
#define glAsyncCopyImageSubDataNVX           OGL__glAsyncCopyImageSubDataNVX

#endif // GL_NVX_gpu_multicast2

#endif // OPENGL_INCLUDE_GL_NVX_gpu_multicast2

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NVX_linked_gpu_multicast

#ifndef GL_NVX_linked_gpu_multicast
#define GL_NVX_linked_gpu_multicast 1

#define GL_LGPU_SEPARATE_STORAGE_BIT_NVX    0x0800
#define GL_MAX_LGPU_GPUS_NVX                0x92BA

OPENGL_INIT_PROC(glLGPUNamedBufferSubDataNVX, void, GLbitfield gpuMask, GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
OPENGL_INIT_PROC(glLGPUCopyImageSubDataNVX,   void, GLuint sourceGpu, GLbitfield destinationGpuMask, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srxY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
OPENGL_INIT_PROC(glLGPUInterlockNVX,          void, void);

#define glLGPUNamedBufferSubDataNVX OGL__glLGPUNamedBufferSubDataNVX
#define glLGPUCopyImageSubDataNVX   OGL__glLGPUCopyImageSubDataNVX
#define glLGPUInterlockNVX          OGL__glLGPUInterlockNVX

#endif // GL_NVX_linked_gpu_multicast

#endif // OPENGL_INCLUDE_GL_NVX_linked_gpu_multicast

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NVX_progress_fence

#ifndef GL_NVX_progress_fence
#define GL_NVX_progress_fence 1

OPENGL_INIT_PROC(glCreateProgressFenceNVX,     GLuint, void);
OPENGL_INIT_PROC(glSignalSemaphoreui64NVX,     void,   GLuint signalGpu, GLsizei fenceObjectCount, const GLuint *semaphoreArray, const GLuint64 *fenceValueArray);
OPENGL_INIT_PROC(glWaitSemaphoreui64NVX,       void,   GLuint waitGpu, GLsizei fenceObjectCount, const GLuint *semaphoreArray, const GLuint64 *fenceValueArray);
OPENGL_INIT_PROC(glClientWaitSemaphoreui64NVX, void,   GLsizei fenceObjectCount, const GLuint *semaphoreArray, const GLuint64 *fenceValueArray);

#define glCreateProgressFenceNVX     OGL__glCreateProgressFenceNVX
#define glSignalSemaphoreui64NVX     OGL__glSignalSemaphoreui64NVX
#define glWaitSemaphoreui64NVX       OGL__glWaitSemaphoreui64NVX
#define glClientWaitSemaphoreui64NVX OGL__glClientWaitSemaphoreui64NVX

#endif // GL_NVX_progress_fence

#endif // OPENGL_INCLUDE_GL_NVX_progress_fence

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_alpha_to_coverage_dither_control

#ifndef GL_NV_alpha_to_coverage_dither_control
#define GL_NV_alpha_to_coverage_dither_control 1

#define GL_ALPHA_TO_COVERAGE_DITHER_DEFAULT_NV    0x934D
#define GL_ALPHA_TO_COVERAGE_DITHER_ENABLE_NV     0x934E
#define GL_ALPHA_TO_COVERAGE_DITHER_DISABLE_NV    0x934F
#define GL_ALPHA_TO_COVERAGE_DITHER_MODE_NV       0x92BF

OPENGL_INIT_PROC(glAlphaToCoverageDitherControlNV, void, GLenum mode);
#define glAlphaToCoverageDitherControlNV OGL__glAlphaToCoverageDitherControlNV

#endif // GL_NV_alpha_to_coverage_dither_control

#endif // OPENGL_INCLUDE_GL_NV_alpha_to_coverage_dither_control

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_bindless_multi_draw_indirect

#ifndef GL_NV_bindless_multi_draw_indirect
#define GL_NV_bindless_multi_draw_indirect 1

OPENGL_INIT_PROC(glMultiDrawArraysIndirectBindlessNV,   void, GLenum mode, const void *indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);
OPENGL_INIT_PROC(glMultiDrawElementsIndirectBindlessNV, void, GLenum mode, GLenum type, const void *indirect, GLsizei drawCount, GLsizei stride, GLint vertexBufferCount);

#define glMultiDrawArraysIndirectBindlessNV   OGL__glMultiDrawArraysIndirectBindlessNV
#define glMultiDrawElementsIndirectBindlessNV OGL__glMultiDrawElementsIndirectBindlessNV

#endif // GL_NV_bindless_multi_draw_indirect

#endif // OPENGL_INCLUDE_GL_NV_bindless_multi_draw_indirect

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_bindless_multi_draw_indirect_count

#ifndef GL_NV_bindless_multi_draw_indirect_count
#define GL_NV_bindless_multi_draw_indirect_count 1

OPENGL_INIT_PROC(glMultiDrawArraysIndirectBindlessCountNV,   void, GLenum mode, const void *indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);
OPENGL_INIT_PROC(glMultiDrawElementsIndirectBindlessCountNV, void, GLenum mode, GLenum type, const void *indirect, GLsizei drawCount, GLsizei maxDrawCount, GLsizei stride, GLint vertexBufferCount);

#define glMultiDrawArraysIndirectBindlessCountNV   OGL__glMultiDrawArraysIndirectBindlessCountNV
#define glMultiDrawElementsIndirectBindlessCountNV OGL__glMultiDrawElementsIndirectBindlessCountNV

#endif // GL_NV_bindless_multi_draw_indirect_count

#endif // OPENGL_INCLUDE_GL_NV_bindless_multi_draw_indirect_count

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_bindless_texture

#ifndef GL_NV_bindless_texture
#define GL_NV_bindless_texture 1

OPENGL_INIT_PROC(glGetTextureHandleNV,             GLuint64,  GLuint texture);
OPENGL_INIT_PROC(glGetTextureSamplerHandleNV,      GLuint64,  GLuint texture, GLuint sampler);
OPENGL_INIT_PROC(glMakeTextureHandleResidentNV,    void,      GLuint64 handle);
OPENGL_INIT_PROC(glMakeTextureHandleNonResidentNV, void,      GLuint64 handle);
OPENGL_INIT_PROC(glGetImageHandleNV,               GLuint64,  GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum format);
OPENGL_INIT_PROC(glMakeImageHandleResidentNV,      void,      GLuint64 handle, GLenum access);
OPENGL_INIT_PROC(glMakeImageHandleNonResidentNV,   void,      GLuint64 handle);
OPENGL_INIT_PROC(glUniformHandleui64NV,            void,      GLint location, GLuint64 value);
OPENGL_INIT_PROC(glUniformHandleui64vNV,           void,      GLint location, GLsizei count, const GLuint64 *value);
OPENGL_INIT_PROC(glProgramUniformHandleui64NV,     void,      GLuint program, GLint location, GLuint64 value);
OPENGL_INIT_PROC(glProgramUniformHandleui64vNV,    void,      GLuint program, GLint location, GLsizei count, const GLuint64 *values);
OPENGL_INIT_PROC(glIsTextureHandleResidentNV,      GLboolean, GLuint64 handle);
OPENGL_INIT_PROC(glIsImageHandleResidentNV,        GLboolean, GLuint64 handle);

#define glGetTextureHandleNV             OGL__glGetTextureHandleNV
#define glGetTextureSamplerHandleNV      OGL__glGetTextureSamplerHandleNV
#define glMakeTextureHandleResidentNV    OGL__glMakeTextureHandleResidentNV
#define glMakeTextureHandleNonResidentNV OGL__glMakeTextureHandleNonResidentNV
#define glGetImageHandleNV               OGL__glGetImageHandleNV
#define glMakeImageHandleResidentNV      OGL__glMakeImageHandleResidentNV
#define glMakeImageHandleNonResidentNV   OGL__glMakeImageHandleNonResidentNV
#define glUniformHandleui64NV            OGL__glUniformHandleui64NV
#define glUniformHandleui64vNV           OGL__glUniformHandleui64vNV
#define glProgramUniformHandleui64NV     OGL__glProgramUniformHandleui64NV
#define glProgramUniformHandleui64vNV    OGL__glProgramUniformHandleui64vNV
#define glIsTextureHandleResidentNV      OGL__glIsTextureHandleResidentNV
#define glIsImageHandleResidentNV        OGL__glIsImageHandleResidentNV

#endif // GL_NV_bindless_texture

#endif // OPENGL_INCLUDE_GL_NV_bindless_texture

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_blend_equation_advanced

#ifndef GL_NV_blend_equation_advanced
#define GL_NV_blend_equation_advanced 1

#define GL_BLEND_OVERLAP_NV              0x9281
#define GL_BLEND_PREMULTIPLIED_SRC_NV    0x9280
#define GL_BLUE_NV                       0x1905
#define GL_COLORBURN_NV                  0x929A
#define GL_COLORDODGE_NV                 0x9299
#define GL_CONJOINT_NV                   0x9284
#define GL_CONTRAST_NV                   0x92A1
#define GL_DARKEN_NV                     0x9297
#define GL_DIFFERENCE_NV                 0x929E
#define GL_DISJOINT_NV                   0x9283
#define GL_DST_ATOP_NV                   0x928F
#define GL_DST_IN_NV                     0x928B
#define GL_DST_NV                        0x9287
#define GL_DST_OUT_NV                    0x928D
#define GL_DST_OVER_NV                   0x9289
#define GL_EXCLUSION_NV                  0x92A0
#define GL_GREEN_NV                      0x1904
#define GL_HARDLIGHT_NV                  0x929B
#define GL_HARDMIX_NV                    0x92A9
#define GL_HSL_COLOR_NV                  0x92AF
#define GL_HSL_HUE_NV                    0x92AD
#define GL_HSL_LUMINOSITY_NV             0x92B0
#define GL_HSL_SATURATION_NV             0x92AE
#define GL_INVERT_OVG_NV                 0x92B4
#define GL_INVERT_RGB_NV                 0x92A3
#define GL_LIGHTEN_NV                    0x9298
#define GL_LINEARBURN_NV                 0x92A5
#define GL_LINEARDODGE_NV                0x92A4
#define GL_LINEARLIGHT_NV                0x92A7
#define GL_MINUS_CLAMPED_NV              0x92B3
#define GL_MINUS_NV                      0x929F
#define GL_MULTIPLY_NV                   0x9294
#define GL_OVERLAY_NV                    0x9296
#define GL_PINLIGHT_NV                   0x92A8
#define GL_PLUS_CLAMPED_ALPHA_NV         0x92B2
#define GL_PLUS_CLAMPED_NV               0x92B1
#define GL_PLUS_DARKER_NV                0x9292
#define GL_PLUS_NV                       0x9291
#define GL_RED_NV                        0x1903
#define GL_SCREEN_NV                     0x9295
#define GL_SOFTLIGHT_NV                  0x929C
#define GL_SRC_ATOP_NV                   0x928E
#define GL_SRC_IN_NV                     0x928A
#define GL_SRC_NV                        0x9286
#define GL_SRC_OUT_NV                    0x928C
#define GL_SRC_OVER_NV                   0x9288
#define GL_UNCORRELATED_NV               0x9282
#define GL_VIVIDLIGHT_NV                 0x92A6
#define GL_XOR_NV                        0x1506

OPENGL_INIT_PROC(glBlendParameteriNV, void, GLenum pname, GLint value);
OPENGL_INIT_PROC(glBlendBarrierNV,    void, void);

#define glBlendParameteriNV OGL__glBlendParameteriNV
#define glBlendBarrierNV    OGL__glBlendBarrierNV

#endif // GL_NV_blend_equation_advanced

#endif // OPENGL_INCLUDE_GL_NV_blend_equation_advanced

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_blend_equation_advanced_coherent
#define GL_NV_blend_equation_advanced_coherent 1

#define GL_BLEND_ADVANCED_COHERENT_NV    0x9285

#endif // GL_NV_blend_equation_advanced_coherent

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_blend_minmax_factor
#define GL_NV_blend_minmax_factor 1

#endif // GL_NV_blend_minmax_factor

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_blend_square
#define GL_NV_blend_square 1

#endif // GL_NV_blend_square

/* -------------------------------------------------------------------------- */

#ifdef OPNEGL_INCLUDE_GL_NV_clip_space_w_scaling

#ifndef GL_NV_clip_space_w_scaling
#define GL_NV_clip_space_w_scaling 1

#define GL_VIEWPORT_POSITION_W_SCALE_NV            0x937C
#define GL_VIEWPORT_POSITION_W_SCALE_X_COEFF_NV    0x937D
#define GL_VIEWPORT_POSITION_W_SCALE_Y_COEFF_NV    0x937E

OPENGL_INIT_PROC(glViewportPositionWScaleNV, void, GLuint index, GLfloat xcoeff, GLfloat ycoeff);
#define glViewportPositionWScaleNV OGL__glViewportPositionWScaleNV

#endif // GL_NV_clip_space_w_scaling

#endif // OPNEGL_INCLUDE_GL_NV_clip_space_w_scaling

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_command_list

#ifndef GL_NV_command_list
#define GL_NV_command_list 1

#define GL_TERMINATE_SEQUENCE_COMMAND_NV         0x0000
#define GL_NOP_COMMAND_NV                        0x0001
#define GL_DRAW_ELEMENTS_COMMAND_NV              0x0002
#define GL_DRAW_ARRAYS_COMMAND_NV                0x0003
#define GL_DRAW_ELEMENTS_STRIP_COMMAND_NV        0x0004
#define GL_DRAW_ARRAYS_STRIP_COMMAND_NV          0x0005
#define GL_DRAW_ELEMENTS_INSTANCED_COMMAND_NV    0x0006
#define GL_DRAW_ARRAYS_INSTANCED_COMMAND_NV      0x0007
#define GL_ELEMENT_ADDRESS_COMMAND_NV            0x0008
#define GL_ATTRIBUTE_ADDRESS_COMMAND_NV          0x0009
#define GL_UNIFORM_ADDRESS_COMMAND_NV            0x000A
#define GL_BLEND_COLOR_COMMAND_NV                0x000B
#define GL_STENCIL_REF_COMMAND_NV                0x000C
#define GL_LINE_WIDTH_COMMAND_NV                 0x000D
#define GL_POLYGON_OFFSET_COMMAND_NV             0x000E
#define GL_ALPHA_REF_COMMAND_NV                  0x000F
#define GL_VIEWPORT_COMMAND_NV                   0x0010
#define GL_SCISSOR_COMMAND_NV                    0x0011
#define GL_FRONT_FACE_COMMAND_NV                 0x0012

OPENGL_INIT_PROC(glCreateStatesNV,                 void,      GLsizei n, GLuint *states);
OPENGL_INIT_PROC(glDeleteStatesNV,                 void,      GLsizei n, const GLuint *states);
OPENGL_INIT_PROC(glIsStateNV,                      GLboolean, GLuint state);
OPENGL_INIT_PROC(glStateCaptureNV,                 void,      GLuint state, GLenum mode);
OPENGL_INIT_PROC(glGetCommandHeaderNV,             GLuint,    GLenum tokenID, GLuint size);
OPENGL_INIT_PROC(glGetStageIndexNV,                GLushort,  GLenum shadertype);
OPENGL_INIT_PROC(glDrawCommandsNV,                 void,      GLenum primitiveMode, GLuint buffer, const GLintptr *indirects, const GLsizei *sizes, GLuint count);
OPENGL_INIT_PROC(glDrawCommandsAddressNV,          void,      GLenum primitiveMode, const GLuint64 *indirects, const GLsizei *sizes, GLuint count);
OPENGL_INIT_PROC(glDrawCommandsStatesNV,           void,      GLuint buffer, const GLintptr *indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count);
OPENGL_INIT_PROC(glDrawCommandsStatesAddressNV,    void,      const GLuint64 *indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count);
OPENGL_INIT_PROC(glCreateCommandListsNV,           void,      GLsizei n, GLuint *lists);
OPENGL_INIT_PROC(glDeleteCommandListsNV,           void,      GLsizei n, const GLuint *lists);
OPENGL_INIT_PROC(glIsCommandListNV,                GLboolean, GLuint list);
OPENGL_INIT_PROC(glListDrawCommandsStatesClientNV, void,      GLuint list, GLuint segment, const void **indirects, const GLsizei *sizes, const GLuint *states, const GLuint *fbos, GLuint count);
OPENGL_INIT_PROC(glCommandListSegmentsNV,          void,      GLuint list, GLuint segments);
OPENGL_INIT_PROC(glCompileCommandListNV,           void,      GLuint list);
OPENGL_INIT_PROC(glCallCommandListNV,              void,      GLuint list);

#define glCreateStatesNV                 OGL__glCreateStatesNV
#define glDeleteStatesNV                 OGL__glDeleteStatesNV
#define glIsStateNV                      OGL__glIsStateNV
#define glStateCaptureNV                 OGL__glStateCaptureNV
#define glGetCommandHeaderNV             OGL__glGetCommandHeaderNV
#define glGetStageIndexNV                OGL__glGetStageIndexNV
#define glDrawCommandsNV                 OGL__glDrawCommandsNV
#define glDrawCommandsAddressNV          OGL__glDrawCommandsAddressNV
#define glDrawCommandsStatesNV           OGL__glDrawCommandsStatesNV
#define glDrawCommandsStatesAddressNV    OGL__glDrawCommandsStatesAddressNV
#define glCreateCommandListsNV           OGL__glCreateCommandListsNV
#define glDeleteCommandListsNV           OGL__glDeleteCommandListsNV
#define glIsCommandListNV                OGL__glIsCommandListNV
#define glListDrawCommandsStatesClientNV OGL__glListDrawCommandsStatesClientNV
#define glCommandListSegmentsNV          OGL__glCommandListSegmentsNV
#define glCompileCommandListNV           OGL__glCompileCommandListNV
#define glCallCommandListNV              OGL__glCallCommandListNV

#endif // GL_NV_command_list

#endif // OPENGL_INCLUDE_GL_NV_command_list

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_compute_program5
#define GL_NV_compute_program5 1

#define GL_COMPUTE_PROGRAM_NV                     0x90FB
#define GL_COMPUTE_PROGRAM_PARAMETER_BUFFER_NV    0x90FC

#endif // GL_NV_compute_program5

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_compute_shader_derivatives
#define GL_NV_compute_shader_derivatives 1

#endif // GL_NV_compute_shader_derivatives

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_conditional_render

#ifndef GL_NV_conditional_render
#define GL_NV_conditional_render 1

#define GL_QUERY_WAIT_NV                 0x8E13
#define GL_QUERY_NO_WAIT_NV              0x8E14
#define GL_QUERY_BY_REGION_WAIT_NV       0x8E15
#define GL_QUERY_BY_REGION_NO_WAIT_NV    0x8E16

OPENGL_INIT_PROC(glBeginConditionalRenderNV, void, GLuint id, GLenum mode);
OPENGL_INIT_PROC(glEndConditionalRenderNV,   void, void);

#define glBeginConditionalRenderNV OGL__glBeginConditionalRenderNV
#define glEndConditionalRenderNV   OGL__glEndConditionalRenderNV

#endif // GL_NV_conditional_render

#endif // OPENGL_INCLUDE_GL_NV_conditional_render

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_conservative_raster

#ifndef GL_NV_conservative_raster
#define GL_NV_conservative_raster 1

#define GL_CONSERVATIVE_RASTERIZATION_NV          0x9346
#define GL_SUBPIXEL_PRECISION_BIAS_X_BITS_NV      0x9347
#define GL_SUBPIXEL_PRECISION_BIAS_Y_BITS_NV      0x9348
#define GL_MAX_SUBPIXEL_PRECISION_BIAS_BITS_NV    0x9349

OPENGL_INIT_PROC(glSubpixelPrecisionBiasNV, void, GLuint xbits, GLuint ybits);
#define glSubpixelPrecisionBiasNV OGL__glSubpixelPrecisionBiasNV

#endif // GL_NV_conservative_raster

#endif // OPENGL_INCLUDE_GL_NV_conservative_raster

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_conservative_raster_dilate

#ifndef GL_NV_conservative_raster_dilate
#define GL_NV_conservative_raster_dilate 1

#define GL_CONSERVATIVE_RASTER_DILATE_NV                0x9379
#define GL_CONSERVATIVE_RASTER_DILATE_RANGE_NV          0x937A
#define GL_CONSERVATIVE_RASTER_DILATE_GRANULARITY_NV    0x937B

OPENGL_INIT_PROC(glConservativeRasterParameterfNV, void, GLenum pname, GLfloat value);
#define glConservativeRasterParameterfNV OGL__glConservativeRasterParameterfNV

#endif // GL_NV_conservative_raster_dilate

#endif // OPENGL_INCLUDE_GL_NV_conservative_raster_dilate

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_conservative_raster_pre_snap
#define GL_NV_conservative_raster_pre_snap 1

#define GL_CONSERVATIVE_RASTER_MODE_PRE_SNAP_NV    0x9550

#endif // GL_NV_conservative_raster_pre_snap

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_conservative_raster_pre_snap_triangles

#ifndef GL_NV_conservative_raster_pre_snap_triangles
#define GL_NV_conservative_raster_pre_snap_triangles 1

#define GL_CONSERVATIVE_RASTER_MODE_NV                       0x954D
#define GL_CONSERVATIVE_RASTER_MODE_POST_SNAP_NV             0x954E
#define GL_CONSERVATIVE_RASTER_MODE_PRE_SNAP_TRIANGLES_NV    0x954F

OPENGL_INIT_PROC(glConservativeRasterParameteriNV, void, GLenum pname, GLint param);
#define glConservativeRasterParameteriNV OGL__glConservativeRasterParameteriNV

#endif // GL_NV_conservative_raster_pre_snap_triangles

#endif // OPENGL_INCLUDE_GL_NV_conservative_raster_pre_snap_triangles

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_conservative_raster_underestimation
#define GL_NV_conservative_raster_underestimation 1

#endif // GL_NV_conservative_raster_underestimation

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_copy_depth_to_color
#define GL_NV_copy_depth_to_color 1

#define GL_DEPTH_STENCIL_TO_RGBA_NV    0x886E
#define GL_DEPTH_STENCIL_TO_BGRA_NV    0x886F

#endif // GL_NV_copy_depth_to_color

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_copy_image

#ifndef GL_NV_copy_image
#define GL_NV_copy_image 1

OPENGL_INIT_PROC(glCopyImageSubDataNV, void, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei width, GLsizei height, GLsizei depth);
#define glCopyImageSubDataNV OGL__glCopyImageSubDataNV

#endif // GL_NV_copy_image

#endif // OPENGL_INCLUDE_GL_NV_copy_image

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_deep_texture3D
#define GL_NV_deep_texture3D 1

#define GL_MAX_DEEP_3D_TEXTURE_WIDTH_HEIGHT_NV    0x90D0
#define GL_MAX_DEEP_3D_TEXTURE_DEPTH_NV           0x90D1

#endif // GL_NV_deep_texture3D

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_depth_buffer_float

#ifndef GL_NV_depth_buffer_float
#define GL_NV_depth_buffer_float 1

#define GL_DEPTH_COMPONENT32F_NV                0x8DAB
#define GL_DEPTH32F_STENCIL8_NV                 0x8DAC
#define GL_FLOAT_32_UNSIGNED_INT_24_8_REV_NV    0x8DAD
#define GL_DEPTH_BUFFER_FLOAT_MODE_NV           0x8DAF

OPENGL_INIT_PROC(glDepthRangedNV,  void, GLdouble zNear, GLdouble zFar);
OPENGL_INIT_PROC(glClearDepthdNV,  void, GLdouble depth);
OPENGL_INIT_PROC(glDepthBoundsdNV, void, GLdouble zmin, GLdouble zmax);

#define glDepthRangedNV  OGL__glDepthRangedNV
#define glClearDepthdNV  OGL__glClearDepthdNV
#define glDepthBoundsdNV OGL__glDepthBoundsdNV

#endif // GL_NV_depth_buffer_float

#endif // OPENGL_INCLUDE_GL_NV_depth_buffer_float

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_depth_clamp
#define GL_NV_depth_clamp 1

#define GL_DEPTH_CLAMP_NV    0x864F

#endif // GL_NV_depth_clamp

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_draw_texture

#ifndef GL_NV_draw_texture
#define GL_NV_draw_texture 1

OPENGL_INIT_PROC(glDrawTextureNV, void, GLuint texture, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1);
#define glDrawTextureNV OGL__glDrawTextureNV

#endif // GL_NV_draw_texture

#endif // OPENGL_INCLUDE_GL_NV_draw_texture

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_draw_vulkan_image

#ifndef GL_NV_draw_vulkan_image
#define GL_NV_draw_vulkan_image 1

OPENGL_INIT_PROC(glDrawVkImageNV,       void,           GLuint64 vkImage, GLuint sampler, GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1, GLfloat z, GLfloat s0, GLfloat t0, GLfloat s1, GLfloat t1);
OPENGL_INIT_PROC(glGetVkProcAddrNV,     GLVULKANPROCNV, const GLchar *name);
OPENGL_INIT_PROC(glWaitVkSemaphoreNV,   void,           GLuint64 vkSemaphore);
OPENGL_INIT_PROC(glSignalVkSemaphoreNV, void,           GLuint64 vkSemaphore);
OPENGL_INIT_PROC(glSignalVkFenceNV,     void,           GLuint64 vkFence);

#define glDrawVkImageNV       OGL__glDrawVkImageNV
#define glGetVkProcAddrNV     OGL__glGetVkProcAddrNV
#define glWaitVkSemaphoreNV   OGL__glWaitVkSemaphoreNV
#define glSignalVkSemaphoreNV OGL__glSignalVkSemaphoreNV
#define glSignalVkFenceNV     OGL__glSignalVkFenceNV

#endif // GL_NV_draw_vulkan_image

#endif // OPENGL_INCLUDE_GL_NV_draw_vulkan_image

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_evaluators

#ifndef GL_NV_evaluators
#define GL_NV_evaluators 1

#define GL_EVAL_2D_NV                         0x86C0
#define GL_EVAL_TRIANGULAR_2D_NV              0x86C1
#define GL_MAP_TESSELLATION_NV                0x86C2
#define GL_MAP_ATTRIB_U_ORDER_NV              0x86C3
#define GL_MAP_ATTRIB_V_ORDER_NV              0x86C4
#define GL_EVAL_FRACTIONAL_TESSELLATION_NV    0x86C5
#define GL_EVAL_VERTEX_ATTRIB0_NV             0x86C6
#define GL_EVAL_VERTEX_ATTRIB1_NV             0x86C7
#define GL_EVAL_VERTEX_ATTRIB2_NV             0x86C8
#define GL_EVAL_VERTEX_ATTRIB3_NV             0x86C9
#define GL_EVAL_VERTEX_ATTRIB4_NV             0x86CA
#define GL_EVAL_VERTEX_ATTRIB5_NV             0x86CB
#define GL_EVAL_VERTEX_ATTRIB6_NV             0x86CC
#define GL_EVAL_VERTEX_ATTRIB7_NV             0x86CD
#define GL_EVAL_VERTEX_ATTRIB8_NV             0x86CE
#define GL_EVAL_VERTEX_ATTRIB9_NV             0x86CF
#define GL_EVAL_VERTEX_ATTRIB10_NV            0x86D0
#define GL_EVAL_VERTEX_ATTRIB11_NV            0x86D1
#define GL_EVAL_VERTEX_ATTRIB12_NV            0x86D2
#define GL_EVAL_VERTEX_ATTRIB13_NV            0x86D3
#define GL_EVAL_VERTEX_ATTRIB14_NV            0x86D4
#define GL_EVAL_VERTEX_ATTRIB15_NV            0x86D5
#define GL_MAX_MAP_TESSELLATION_NV            0x86D6
#define GL_MAX_RATIONAL_EVAL_ORDER_NV         0x86D7

OPENGL_INIT_PROC(glMapControlPointsNV,        void, GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLint uorder, GLint vorder, GLboolean packed, const void *points);
OPENGL_INIT_PROC(glMapParameterivNV,          void, GLenum target, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glMapParameterfvNV,          void, GLenum target, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glGetMapControlPointsNV,     void, GLenum target, GLuint index, GLenum type, GLsizei ustride, GLsizei vstride, GLboolean packed, void *points);
OPENGL_INIT_PROC(glGetMapParameterivNV,       void, GLenum target, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetMapParameterfvNV,       void, GLenum target, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetMapAttribParameterivNV, void, GLenum target, GLuint index, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetMapAttribParameterfvNV, void, GLenum target, GLuint index, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glEvalMapsNV,                void, GLenum target, GLenum mode);

#define glMapControlPointsNV        OGL__glMapControlPointsNV
#define glMapParameterivNV          OGL__glMapParameterivNV
#define glMapParameterfvNV          OGL__glMapParameterfvNV
#define glGetMapControlPointsNV     OGL__glGetMapControlPointsNV
#define glGetMapParameterivNV       OGL__glGetMapParameterivNV
#define glGetMapParameterfvNV       OGL__glGetMapParameterfvNV
#define glGetMapAttribParameterivNV OGL__glGetMapAttribParameterivNV
#define glGetMapAttribParameterfvNV OGL__glGetMapAttribParameterfvNV
#define glEvalMapsNV                OGL__glEvalMapsNV

#endif // GL_NV_evaluators

#endif // OPENGL_INCLUDE_GL_NV_evaluators

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_explicit_multisample

#ifndef GL_NV_explicit_multisample
#define GL_NV_explicit_multisample 1

#define GL_SAMPLE_POSITION_NV                            0x8E50
#define GL_SAMPLE_MASK_NV                                0x8E51
#define GL_SAMPLE_MASK_VALUE_NV                          0x8E52
#define GL_TEXTURE_BINDING_RENDERBUFFER_NV               0x8E53
#define GL_TEXTURE_RENDERBUFFER_DATA_STORE_BINDING_NV    0x8E54
#define GL_TEXTURE_RENDERBUFFER_NV                       0x8E55
#define GL_SAMPLER_RENDERBUFFER_NV                       0x8E56
#define GL_INT_SAMPLER_RENDERBUFFER_NV                   0x8E57
#define GL_UNSIGNED_INT_SAMPLER_RENDERBUFFER_NV          0x8E58
#define GL_MAX_SAMPLE_MASK_WORDS_NV                      0x8E59

OPENGL_INIT_PROC(glGetMultisamplefvNV,  void, GLenum pname, GLuint index, GLfloat *val);
OPENGL_INIT_PROC(glSampleMaskIndexedNV, void, GLuint index, GLbitfield mask);
OPENGL_INIT_PROC(glTexRenderbufferNV,   void, GLenum target, GLuint renderbuffer);

#define glGetMultisamplefvNV  OGL__glGetMultisamplefvNV
#define glSampleMaskIndexedNV OGL__glSampleMaskIndexedNV
#define glTexRenderbufferNV   OGL__glTexRenderbufferNV

#endif // GL_NV_explicit_multisample

#endif // OPENGL_INCLUDE_GL_NV_explicit_multisample

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_fence

#ifndef GL_NV_fence
#define GL_NV_fence 1

#define GL_ALL_COMPLETED_NV      0x84F2
#define GL_FENCE_STATUS_NV       0x84F3
#define GL_FENCE_CONDITION_NV    0x84F4

OPENGL_INIT_PROC(glDeleteFencesNV, void,      GLsizei n, const GLuint *fences);
OPENGL_INIT_PROC(glGenFencesNV,    void,      GLsizei n, GLuint *fences);
OPENGL_INIT_PROC(glIsFenceNV,      GLboolean, GLuint fence);
OPENGL_INIT_PROC(glTestFenceNV,    GLboolean, GLuint fence);
OPENGL_INIT_PROC(glGetFenceivNV,   void,      GLuint fence, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glFinishFenceNV,  void,      GLuint fence);
OPENGL_INIT_PROC(glSetFenceNV,     void,      GLuint fence, GLenum condition);

#define glDeleteFencesNV OGL__glDeleteFencesNV
#define glGenFencesNV    OGL__glGenFencesNV
#define glIsFenceNV      OGL__glIsFenceNV
#define glTestFenceNV    OGL__glTestFenceNV
#define glGetFenceivNV   OGL__glGetFenceivNV
#define glFinishFenceNV  OGL__glFinishFenceNV
#define glSetFenceNV     OGL__glSetFenceNV

#endif // GL_NV_fence

#endif // OPENGL_INCLUDE_GL_NV_fence

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_fill_rectangle
#define GL_NV_fill_rectangle 1

#define GL_FILL_RECTANGLE_NV    0x933C

#endif // GL_NV_fill_rectangle

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_float_buffer
#define GL_NV_float_buffer 1

#define GL_FLOAT_R_NV                     0x8880
#define GL_FLOAT_RG_NV                    0x8881
#define GL_FLOAT_RGB_NV                   0x8882
#define GL_FLOAT_RGBA_NV                  0x8883
#define GL_FLOAT_R16_NV                   0x8884
#define GL_FLOAT_R32_NV                   0x8885
#define GL_FLOAT_RG16_NV                  0x8886
#define GL_FLOAT_RG32_NV                  0x8887
#define GL_FLOAT_RGB16_NV                 0x8888
#define GL_FLOAT_RGB32_NV                 0x8889
#define GL_FLOAT_RGBA16_NV                0x888A
#define GL_FLOAT_RGBA32_NV                0x888B
#define GL_TEXTURE_FLOAT_COMPONENTS_NV    0x888C
#define GL_FLOAT_CLEAR_COLOR_VALUE_NV     0x888D
#define GL_FLOAT_RGBA_MODE_NV             0x888E

#endif // GL_NV_float_buffer

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_fog_distance
#define GL_NV_fog_distance 1

#define GL_FOG_DISTANCE_MODE_NV     0x855A
#define GL_EYE_RADIAL_NV            0x855B
#define GL_EYE_PLANE_ABSOLUTE_NV    0x855C

#endif // GL_NV_fog_distance

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_fragment_coverage_to_color

#ifndef GL_NV_fragment_coverage_to_color
#define GL_NV_fragment_coverage_to_color 1

#define GL_FRAGMENT_COVERAGE_TO_COLOR_NV    0x92DD
#define GL_FRAGMENT_COVERAGE_COLOR_NV       0x92DE

OPENGL_INIT_PROC(glFragmentCoverageColorNV, void, GLuint color);
#define glFragmentCoverageColorNV OGL__glFragmentCoverageColorNV

#endif // GL_NV_fragment_coverage_to_color

#endif // OPENGL_INCLUDE_GL_NV_fragment_coverage_to_color

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_fragment_program

#ifndef GL_NV_fragment_program
#define GL_NV_fragment_program 1

#define GL_MAX_FRAGMENT_PROGRAM_LOCAL_PARAMETERS_NV    0x8868
#define GL_FRAGMENT_PROGRAM_NV                         0x8870
#define GL_MAX_TEXTURE_COORDS_NV                       0x8871
#define GL_MAX_TEXTURE_IMAGE_UNITS_NV                  0x8872
#define GL_FRAGMENT_PROGRAM_BINDING_NV                 0x8873
#define GL_PROGRAM_ERROR_STRING_NV                     0x8874

OPENGL_INIT_PROC(glProgramNamedParameter4fNV,    void, GLuint id, GLsizei len, const GLubyte *name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
OPENGL_INIT_PROC(glProgramNamedParameter4fvNV,   void, GLuint id, GLsizei len, const GLubyte *name, const GLfloat *v);
OPENGL_INIT_PROC(glProgramNamedParameter4dNV,    void, GLuint id, GLsizei len, const GLubyte *name, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
OPENGL_INIT_PROC(glProgramNamedParameter4dvNV,   void, GLuint id, GLsizei len, const GLubyte *name, const GLdouble *v);
OPENGL_INIT_PROC(glGetProgramNamedParameterfvNV, void, GLuint id, GLsizei len, const GLubyte *name, GLfloat *params);
OPENGL_INIT_PROC(glGetProgramNamedParameterdvNV, void, GLuint id, GLsizei len, const GLubyte *name, GLdouble *params);

#define glProgramNamedParameter4fNV    OGL__glProgramNamedParameter4fNV
#define glProgramNamedParameter4fvNV   OGL__glProgramNamedParameter4fvNV
#define glProgramNamedParameter4dNV    OGL__glProgramNamedParameter4dNV
#define glProgramNamedParameter4dvNV   OGL__glProgramNamedParameter4dvNV
#define glGetProgramNamedParameterfvNV OGL__glGetProgramNamedParameterfvNV
#define glGetProgramNamedParameterdvNV OGL__glGetProgramNamedParameterdvNV

#endif // GL_NV_fragment_program

#endif // OPENGL_INCLUDE_GL_NV_fragment_program

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_fragment_program2
#define GL_NV_fragment_program2 1

#define GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV    0x88F4
#define GL_MAX_PROGRAM_CALL_DEPTH_NV           0x88F5
#define GL_MAX_PROGRAM_IF_DEPTH_NV             0x88F6
#define GL_MAX_PROGRAM_LOOP_DEPTH_NV           0x88F7
#define GL_MAX_PROGRAM_LOOP_COUNT_NV           0x88F8

#endif // GL_NV_fragment_program2

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_fragment_program4
#define GL_NV_fragment_program4 1

#endif // GL_NV_fragment_program4

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_fragment_program_option
#define GL_NV_fragment_program_option 1

#endif // GL_NV_fragment_program_option

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_fragment_shader_barycentric
#define GL_NV_fragment_shader_barycentric 1

#endif // GL_NV_fragment_shader_barycentric

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_fragment_shader_interlock
#define GL_NV_fragment_shader_interlock 1

#endif // GL_NV_fragment_shader_interlock

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_framebuffer_mixed_samples

#ifndef GL_NV_framebuffer_mixed_samples
#define GL_NV_framebuffer_mixed_samples 1

#define GL_COVERAGE_MODULATION_TABLE_NV          0x9331
#define GL_COLOR_SAMPLES_NV                      0x8E20
#define GL_DEPTH_SAMPLES_NV                      0x932D
#define GL_STENCIL_SAMPLES_NV                    0x932E
#define GL_MIXED_DEPTH_SAMPLES_SUPPORTED_NV      0x932F
#define GL_MIXED_STENCIL_SAMPLES_SUPPORTED_NV    0x9330
#define GL_COVERAGE_MODULATION_NV                0x9332
#define GL_COVERAGE_MODULATION_TABLE_SIZE_NV     0x9333

OPENGL_INIT_PROC(glCoverageModulationTableNV,    void, GLsizei n, const GLfloat *v);
OPENGL_INIT_PROC(glGetCoverageModulationTableNV, void, GLsizei bufsize, GLfloat *v);
OPENGL_INIT_PROC(glCoverageModulationNV,         void, GLenum components);

#define glCoverageModulationTableNV    OGL__glCoverageModulationTableNV
#define glGetCoverageModulationTableNV OGL__glGetCoverageModulationTableNV
#define glCoverageModulationNV         OGL__glCoverageModulationNV

#endif // GL_NV_framebuffer_mixed_samples

#endif // OPENGL_INCLUDE_GL_NV_framebuffer_mixed_samples

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_framebuffer_multisample_coverage

#ifndef GL_NV_framebuffer_multisample_coverage
#define GL_NV_framebuffer_multisample_coverage 1

#define GL_RENDERBUFFER_COVERAGE_SAMPLES_NV     0x8CAB
#define GL_RENDERBUFFER_COLOR_SAMPLES_NV        0x8E10
#define GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV    0x8E11
#define GL_MULTISAMPLE_COVERAGE_MODES_NV        0x8E12

OPENGL_INIT_PROC(glRenderbufferStorageMultisampleCoverageNV, void, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLenum internalformat, GLsizei width, GLsizei height);
#define glRenderbufferStorageMultisampleCoverageNV OGL__glRenderbufferStorageMultisampleCoverageNV

#endif // GL_NV_framebuffer_multisample_coverage

#endif // OPENGL_INCLUDE_GL_NV_framebuffer_multisample_coverage

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_geometry_program4

#ifndef GL_NV_geometry_program4
#define GL_NV_geometry_program4 1

#define GL_GEOMETRY_PROGRAM_NV                       0x8C26
#define GL_MAX_PROGRAM_OUTPUT_VERTICES_NV            0x8C27
#define GL_MAX_PROGRAM_TOTAL_OUTPUT_COMPONENTS_NV    0x8C28

OPENGL_INIT_PROC(glProgramVertexLimitNV,      void, GLenum target, GLint limit);
OPENGL_INIT_PROC(glFramebufferTextureEXT,     void, GLenum target, GLenum attachment, GLuint texture, GLint level);
OPENGL_INIT_PROC(glFramebufferTextureFaceEXT, void, GLenum target, GLenum attachment, GLuint texture, GLint level, GLenum face);

#define glProgramVertexLimitNV      OGL__glProgramVertexLimitNV
#define glFramebufferTextureEXT     OGL__glFramebufferTextureEXT
#define glFramebufferTextureFaceEXT OGL__glFramebufferTextureFaceEXT

#endif // GL_NV_geometry_program4

#endif // OPENGL_INCLUDE_GL_NV_geometry_program4

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_geometry_shader4
#define GL_NV_geometry_shader4 1

#endif // GL_NV_geometry_shader4

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_geometry_shader_passthrough
#define GL_NV_geometry_shader_passthrough 1

#endif // GL_NV_geometry_shader_passthrough

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_gpu_multicast

#ifndef GL_NV_gpu_multicast
#define GL_NV_gpu_multicast 1

#define GL_PER_GPU_STORAGE_BIT_NV                       0x0800
#define GL_MULTICAST_GPUS_NV                            0x92BA
#define GL_RENDER_GPU_MASK_NV                           0x9558
#define GL_PER_GPU_STORAGE_NV                           0x9548
#define GL_MULTICAST_PROGRAMMABLE_SAMPLE_LOCATION_NV    0x9549

OPENGL_INIT_PROC(glRenderGpuMaskNV,                         void, GLbitfield mask);
OPENGL_INIT_PROC(glMulticastBufferSubDataNV,                void, GLbitfield gpuMask, GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
OPENGL_INIT_PROC(glMulticastCopyBufferSubDataNV,            void, GLuint readGpu, GLbitfield writeGpuMask, GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
OPENGL_INIT_PROC(glMulticastCopyImageSubDataNV,             void, GLuint srcGpu, GLbitfield dstGpuMask, GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
OPENGL_INIT_PROC(glMulticastBlitFramebufferNV,              void, GLuint srcGpu, GLuint dstGpu, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
OPENGL_INIT_PROC(glMulticastFramebufferSampleLocationsfvNV, void, GLuint gpu, GLuint framebuffer, GLuint start, GLsizei count, const GLfloat *v);
OPENGL_INIT_PROC(glMulticastBarrierNV,                      void, void);
OPENGL_INIT_PROC(glMulticastWaitSyncNV,                     void, GLuint signalGpu, GLbitfield waitGpuMask);
OPENGL_INIT_PROC(glMulticastGetQueryObjectivNV,             void, GLuint gpu, GLuint id, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glMulticastGetQueryObjectuivNV,            void, GLuint gpu, GLuint id, GLenum pname, GLuint *params);
OPENGL_INIT_PROC(glMulticastGetQueryObjecti64vNV,           void, GLuint gpu, GLuint id, GLenum pname, GLint64 *params);
OPENGL_INIT_PROC(glMulticastGetQueryObjectui64vNV,          void, GLuint gpu, GLuint id, GLenum pname, GLuint64 *params);

#define glRenderGpuMaskNV                         OGL__glRenderGpuMaskNV
#define glMulticastBufferSubDataNV                OGL__glMulticastBufferSubDataNV
#define glMulticastCopyBufferSubDataNV            OGL__glMulticastCopyBufferSubDataNV
#define glMulticastCopyImageSubDataNV             OGL__glMulticastCopyImageSubDataNV
#define glMulticastBlitFramebufferNV              OGL__glMulticastBlitFramebufferNV
#define glMulticastFramebufferSampleLocationsfvNV OGL__glMulticastFramebufferSampleLocationsfvNV
#define glMulticastBarrierNV                      OGL__glMulticastBarrierNV
#define glMulticastWaitSyncNV                     OGL__glMulticastWaitSyncNV
#define glMulticastGetQueryObjectivNV             OGL__glMulticastGetQueryObjectivNV
#define glMulticastGetQueryObjectuivNV            OGL__glMulticastGetQueryObjectuivNV
#define glMulticastGetQueryObjecti64vNV           OGL__glMulticastGetQueryObjecti64vNV
#define glMulticastGetQueryObjectui64vNV          OGL__glMulticastGetQueryObjectui64vNV

#endif // GL_NV_gpu_multicast

#endif // OPENGL_INCLUDE_GL_NV_gpu_multicast

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_gpu_program4

#ifndef GL_NV_gpu_program4
#define GL_NV_gpu_program4 1

#define GL_MIN_PROGRAM_TEXEL_OFFSET_NV         0x8904
#define GL_MAX_PROGRAM_TEXEL_OFFSET_NV         0x8905
#define GL_PROGRAM_ATTRIB_COMPONENTS_NV        0x8906
#define GL_PROGRAM_RESULT_COMPONENTS_NV        0x8907
#define GL_MAX_PROGRAM_ATTRIB_COMPONENTS_NV    0x8908
#define GL_MAX_PROGRAM_RESULT_COMPONENTS_NV    0x8909
#define GL_MAX_PROGRAM_GENERIC_ATTRIBS_NV      0x8DA5
#define GL_MAX_PROGRAM_GENERIC_RESULTS_NV      0x8DA6

OPENGL_INIT_PROC(glProgramLocalParameterI4iNV,     void, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
OPENGL_INIT_PROC(glProgramLocalParameterI4ivNV,    void, GLenum target, GLuint index, const GLint *params);
OPENGL_INIT_PROC(glProgramLocalParametersI4ivNV,   void, GLenum target, GLuint index, GLsizei count, const GLint *params);
OPENGL_INIT_PROC(glProgramLocalParameterI4uiNV,    void, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
OPENGL_INIT_PROC(glProgramLocalParameterI4uivNV,   void, GLenum target, GLuint index, const GLuint *params);
OPENGL_INIT_PROC(glProgramLocalParametersI4uivNV,  void, GLenum target, GLuint index, GLsizei count, const GLuint *params);
OPENGL_INIT_PROC(glProgramEnvParameterI4iNV,       void, GLenum target, GLuint index, GLint x, GLint y, GLint z, GLint w);
OPENGL_INIT_PROC(glProgramEnvParameterI4ivNV,      void, GLenum target, GLuint index, const GLint *params);
OPENGL_INIT_PROC(glProgramEnvParametersI4ivNV,     void, GLenum target, GLuint index, GLsizei count, const GLint *params);
OPENGL_INIT_PROC(glProgramEnvParameterI4uiNV,      void, GLenum target, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
OPENGL_INIT_PROC(glProgramEnvParameterI4uivNV,     void, GLenum target, GLuint index, const GLuint *params);
OPENGL_INIT_PROC(glProgramEnvParametersI4uivNV,    void, GLenum target, GLuint index, GLsizei count, const GLuint *params);
OPENGL_INIT_PROC(glGetProgramLocalParameterIivNV,  void, GLenum target, GLuint index, GLint *params);
OPENGL_INIT_PROC(glGetProgramLocalParameterIuivNV, void, GLenum target, GLuint index, GLuint *params);
OPENGL_INIT_PROC(glGetProgramEnvParameterIivNV,    void, GLenum target, GLuint index, GLint *params);
OPENGL_INIT_PROC(glGetProgramEnvParameterIuivNV,   void, GLenum target, GLuint index, GLuint *params);

#define glProgramLocalParameterI4iNV     OGL__glProgramLocalParameterI4iNV
#define glProgramLocalParameterI4ivNV    OGL__glProgramLocalParameterI4ivNV
#define glProgramLocalParametersI4ivNV   OGL__glProgramLocalParametersI4ivNV
#define glProgramLocalParameterI4uiNV    OGL__glProgramLocalParameterI4uiNV
#define glProgramLocalParameterI4uivNV   OGL__glProgramLocalParameterI4uivNV
#define glProgramLocalParametersI4uivNV  OGL__glProgramLocalParametersI4uivNV
#define glProgramEnvParameterI4iNV       OGL__glProgramEnvParameterI4iNV
#define glProgramEnvParameterI4ivNV      OGL__glProgramEnvParameterI4ivNV
#define glProgramEnvParametersI4ivNV     OGL__glProgramEnvParametersI4ivNV
#define glProgramEnvParameterI4uiNV      OGL__glProgramEnvParameterI4uiNV
#define glProgramEnvParameterI4uivNV     OGL__glProgramEnvParameterI4uivNV
#define glProgramEnvParametersI4uivNV    OGL__glProgramEnvParametersI4uivNV
#define glGetProgramLocalParameterIivNV  OGL__glGetProgramLocalParameterIivNV
#define glGetProgramLocalParameterIuivNV OGL__glGetProgramLocalParameterIuivNV
#define glGetProgramEnvParameterIivNV    OGL__glGetProgramEnvParameterIivNV
#define glGetProgramEnvParameterIuivNV   OGL__glGetProgramEnvParameterIuivNV

#endif // GL_NV_gpu_program4

#endif // OPENGL_INCLUDE_GL_NV_gpu_program4

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_gpu_program5

#ifndef GL_NV_gpu_program5
#define GL_NV_gpu_program5 1

#define GL_MAX_GEOMETRY_PROGRAM_INVOCATIONS_NV              0x8E5A
#define GL_MIN_FRAGMENT_INTERPOLATION_OFFSET_NV             0x8E5B
#define GL_MAX_FRAGMENT_INTERPOLATION_OFFSET_NV             0x8E5C
#define GL_FRAGMENT_PROGRAM_INTERPOLATION_OFFSET_BITS_NV    0x8E5D
#define GL_MIN_PROGRAM_TEXTURE_GATHER_OFFSET_NV             0x8E5E
#define GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_NV             0x8E5F
#define GL_MAX_PROGRAM_SUBROUTINE_PARAMETERS_NV             0x8F44
#define GL_MAX_PROGRAM_SUBROUTINE_NUM_NV                    0x8F45

OPENGL_INIT_PROC(glProgramSubroutineParametersuivNV,   void, GLenum target, GLsizei count, const GLuint *params);
OPENGL_INIT_PROC(glGetProgramSubroutineParameteruivNV, void, GLenum target, GLuint index, GLuint *param);

#define glProgramSubroutineParametersuivNV   OGL__glProgramSubroutineParametersuivNV
#define glGetProgramSubroutineParameteruivNV OGL__glGetProgramSubroutineParameteruivNV

#endif // GL_NV_gpu_program5

#endif // OPENGL_INCLUDE_GL_NV_gpu_program5

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_gpu_program5_mem_extended
#define GL_NV_gpu_program5_mem_extended 1

#endif // GL_NV_gpu_program5_mem_extended

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_gpu_shader5
#define GL_NV_gpu_shader5 1

#endif // GL_NV_gpu_shader5

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_half_float

#ifndef GL_NV_half_float
#define GL_NV_half_float 1

#define GL_HALF_FLOAT_NV    0x140B

OPENGL_INIT_PROC(glVertex2hNV,          void, GLhalfNV x, GLhalfNV y);
OPENGL_INIT_PROC(glVertex2hvNV,         void, const GLhalfNV *v);
OPENGL_INIT_PROC(glVertex3hNV,          void, GLhalfNV x, GLhalfNV y, GLhalfNV z);
OPENGL_INIT_PROC(glVertex3hvNV,         void, const GLhalfNV *v);
OPENGL_INIT_PROC(glVertex4hNV,          void, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
OPENGL_INIT_PROC(glVertex4hvNV,         void, const GLhalfNV *v);
OPENGL_INIT_PROC(glNormal3hNV,          void, GLhalfNV nx, GLhalfNV ny, GLhalfNV nz);
OPENGL_INIT_PROC(glNormal3hvNV,         void, const GLhalfNV *v);
OPENGL_INIT_PROC(glColor3hNV,           void, GLhalfNV red, GLhalfNV green, GLhalfNV blue);
OPENGL_INIT_PROC(glColor3hvNV,          void, const GLhalfNV *v);
OPENGL_INIT_PROC(glColor4hNV,           void, GLhalfNV red, GLhalfNV green, GLhalfNV blue, GLhalfNV alpha);
OPENGL_INIT_PROC(glColor4hvNV,          void, const GLhalfNV *v);
OPENGL_INIT_PROC(glTexCoord1hNV,        void, GLhalfNV s);
OPENGL_INIT_PROC(glTexCoord1hvNV,       void, const GLhalfNV *v);
OPENGL_INIT_PROC(glTexCoord2hNV,        void, GLhalfNV s, GLhalfNV t);
OPENGL_INIT_PROC(glTexCoord2hvNV,       void, const GLhalfNV *v);
OPENGL_INIT_PROC(glTexCoord3hNV,        void, GLhalfNV s, GLhalfNV t, GLhalfNV r);
OPENGL_INIT_PROC(glTexCoord3hvNV,       void, const GLhalfNV *v);
OPENGL_INIT_PROC(glTexCoord4hNV,        void, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
OPENGL_INIT_PROC(glTexCoord4hvNV,       void, const GLhalfNV *v);
OPENGL_INIT_PROC(glMultiTexCoord1hNV,   void, GLenum target, GLhalfNV s);
OPENGL_INIT_PROC(glMultiTexCoord1hvNV,  void, GLenum target, const GLhalfNV *v);
OPENGL_INIT_PROC(glMultiTexCoord2hNV,   void, GLenum target, GLhalfNV s, GLhalfNV t);
OPENGL_INIT_PROC(glMultiTexCoord2hvNV,  void, GLenum target, const GLhalfNV *v);
OPENGL_INIT_PROC(glMultiTexCoord3hNV,   void, GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r);
OPENGL_INIT_PROC(glMultiTexCoord3hvNV,  void, GLenum target, const GLhalfNV *v);
OPENGL_INIT_PROC(glMultiTexCoord4hNV,   void, GLenum target, GLhalfNV s, GLhalfNV t, GLhalfNV r, GLhalfNV q);
OPENGL_INIT_PROC(glMultiTexCoord4hvNV,  void, GLenum target, const GLhalfNV *v);
OPENGL_INIT_PROC(glFogCoordhNV,         void, GLhalfNV fog);
OPENGL_INIT_PROC(glFogCoordhvNV,        void, const GLhalfNV *fog);
OPENGL_INIT_PROC(glSecondaryColor3hNV,  void, GLhalfNV red, GLhalfNV green, GLhalfNV blue);
OPENGL_INIT_PROC(glSecondaryColor3hvNV, void, const GLhalfNV *v);
OPENGL_INIT_PROC(glVertexWeighthNV,     void, GLhalfNV weight);
OPENGL_INIT_PROC(glVertexWeighthvNV,    void, const GLhalfNV *weight);
OPENGL_INIT_PROC(glVertexAttrib1hNV,    void, GLuint index, GLhalfNV x);
OPENGL_INIT_PROC(glVertexAttrib1hvNV,   void, GLuint index, const GLhalfNV *v);
OPENGL_INIT_PROC(glVertexAttrib2hNV,    void, GLuint index, GLhalfNV x, GLhalfNV y);
OPENGL_INIT_PROC(glVertexAttrib2hvNV,   void, GLuint index, const GLhalfNV *v);
OPENGL_INIT_PROC(glVertexAttrib3hNV,    void, GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z);
OPENGL_INIT_PROC(glVertexAttrib3hvNV,   void, GLuint index, const GLhalfNV *v);
OPENGL_INIT_PROC(glVertexAttrib4hNV,    void, GLuint index, GLhalfNV x, GLhalfNV y, GLhalfNV z, GLhalfNV w);
OPENGL_INIT_PROC(glVertexAttrib4hvNV,   void, GLuint index, const GLhalfNV *v);
OPENGL_INIT_PROC(glVertexAttribs1hvNV,  void, GLuint index, GLsizei n, const GLhalfNV *v);
OPENGL_INIT_PROC(glVertexAttribs2hvNV,  void, GLuint index, GLsizei n, const GLhalfNV *v);
OPENGL_INIT_PROC(glVertexAttribs3hvNV,  void, GLuint index, GLsizei n, const GLhalfNV *v);
OPENGL_INIT_PROC(glVertexAttribs4hvNV,  void, GLuint index, GLsizei n, const GLhalfNV *v);

#define glVertex2hNV          OGL__glVertex2hNV
#define glVertex2hvNV         OGL__glVertex2hvNV
#define glVertex3hNV          OGL__glVertex3hNV
#define glVertex3hvNV         OGL__glVertex3hvNV
#define glVertex4hNV          OGL__glVertex4hNV
#define glVertex4hvNV         OGL__glVertex4hvNV
#define glNormal3hNV          OGL__glNormal3hNV
#define glNormal3hvNV         OGL__glNormal3hvNV
#define glColor3hNV           OGL__glColor3hNV
#define glColor3hvNV          OGL__glColor3hvNV
#define glColor4hNV           OGL__glColor4hNV
#define glColor4hvNV          OGL__glColor4hvNV
#define glTexCoord1hNV        OGL__glTexCoord1hNV
#define glTexCoord1hvNV       OGL__glTexCoord1hvNV
#define glTexCoord2hNV        OGL__glTexCoord2hNV
#define glTexCoord2hvNV       OGL__glTexCoord2hvNV
#define glTexCoord3hNV        OGL__glTexCoord3hNV
#define glTexCoord3hvNV       OGL__glTexCoord3hvNV
#define glTexCoord4hNV        OGL__glTexCoord4hNV
#define glTexCoord4hvNV       OGL__glTexCoord4hvNV
#define glMultiTexCoord1hNV   OGL__glMultiTexCoord1hNV
#define glMultiTexCoord1hvNV  OGL__glMultiTexCoord1hvNV
#define glMultiTexCoord2hNV   OGL__glMultiTexCoord2hNV
#define glMultiTexCoord2hvNV  OGL__glMultiTexCoord2hvNV
#define glMultiTexCoord3hNV   OGL__glMultiTexCoord3hNV
#define glMultiTexCoord3hvNV  OGL__glMultiTexCoord3hvNV
#define glMultiTexCoord4hNV   OGL__glMultiTexCoord4hNV
#define glMultiTexCoord4hvNV  OGL__glMultiTexCoord4hvNV
#define glFogCoordhNV         OGL__glFogCoordhNV
#define glFogCoordhvNV        OGL__glFogCoordhvNV
#define glSecondaryColor3hNV  OGL__glSecondaryColor3hNV
#define glSecondaryColor3hvNV OGL__glSecondaryColor3hvNV
#define glVertexWeighthNV     OGL__glVertexWeighthNV
#define glVertexWeighthvNV    OGL__glVertexWeighthvNV
#define glVertexAttrib1hNV    OGL__glVertexAttrib1hNV
#define glVertexAttrib1hvNV   OGL__glVertexAttrib1hvNV
#define glVertexAttrib2hNV    OGL__glVertexAttrib2hNV
#define glVertexAttrib2hvNV   OGL__glVertexAttrib2hvNV
#define glVertexAttrib3hNV    OGL__glVertexAttrib3hNV
#define glVertexAttrib3hvNV   OGL__glVertexAttrib3hvNV
#define glVertexAttrib4hNV    OGL__glVertexAttrib4hNV
#define glVertexAttrib4hvNV   OGL__glVertexAttrib4hvNV
#define glVertexAttribs1hvNV  OGL__glVertexAttribs1hvNV
#define glVertexAttribs2hvNV  OGL__glVertexAttribs2hvNV
#define glVertexAttribs3hvNV  OGL__glVertexAttribs3hvNV
#define glVertexAttribs4hvNV  OGL__glVertexAttribs4hvNV

#endif // GL_NV_half_float

#endif // OPENGL_INCLUDE_GL_NV_half_float

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_internalformat_sample_query
#define GL_NV_internalformat_sample_query 1

#define GL_MULTISAMPLES_NV           0x9371
#define GL_SUPERSAMPLE_SCALE_X_NV    0x9372
#define GL_SUPERSAMPLE_SCALE_Y_NV    0x9373
#define GL_CONFORMANT_NV             0x9374

#endif // GL_NV_internalformat_sample_query

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_light_max_exponent
#define GL_NV_light_max_exponent 1

#define GL_MAX_SHININESS_NV        0x8504
#define GL_MAX_SPOT_EXPONENT_NV    0x8505

#endif // GL_NV_light_max_exponent

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_memory_attachment

#ifndef GL_NV_memory_attachment
#define GL_NV_memory_attachment 1

#define GL_ATTACHED_MEMORY_OBJECT_NV         0x95A4
#define GL_ATTACHED_MEMORY_OFFSET_NV         0x95A5
#define GL_MEMORY_ATTACHABLE_ALIGNMENT_NV    0x95A6
#define GL_MEMORY_ATTACHABLE_SIZE_NV         0x95A7
#define GL_MEMORY_ATTACHABLE_NV              0x95A8
#define GL_DETACHED_MEMORY_INCARNATION_NV    0x95A9
#define GL_DETACHED_TEXTURES_NV              0x95AA
#define GL_DETACHED_BUFFERS_NV               0x95AB
#define GL_MAX_DETACHED_TEXTURES_NV          0x95AC
#define GL_MAX_DETACHED_BUFFERS_NV           0x95AD

OPENGL_INIT_PROC(glGetMemoryObjectDetachedResourcesuivNV, void, GLuint memory, GLenum pname, GLint first, GLsizei count, GLuint *params);
OPENGL_INIT_PROC(glResetMemoryObjectParameterNV,          void, GLuint memory, GLenum pname);
OPENGL_INIT_PROC(glTexAttachMemoryNV,                     void, GLenum target, GLuint memory, GLuint64 offset);
OPENGL_INIT_PROC(glBufferAttachMemoryNV,                  void, GLenum target, GLuint memory, GLuint64 offset);
OPENGL_INIT_PROC(glTextureAttachMemoryNV,                 void, GLuint texture, GLuint memory, GLuint64 offset);
OPENGL_INIT_PROC(glNamedBufferAttachMemoryNV,             void, GLuint buffer, GLuint memory, GLuint64 offset);

#define glGetMemoryObjectDetachedResourcesuivNV OGL__glGetMemoryObjectDetachedResourcesuivNV
#define glResetMemoryObjectParameterNV          OGL__glResetMemoryObjectParameterNV
#define glTexAttachMemoryNV                     OGL__glTexAttachMemoryNV
#define glBufferAttachMemoryNV                  OGL__glBufferAttachMemoryNV
#define glTextureAttachMemoryNV                 OGL__glTextureAttachMemoryNV
#define glNamedBufferAttachMemoryNV             OGL__glNamedBufferAttachMemoryNV

#endif // GL_NV_memory_attachment

#endif // OPENGL_INCLUDE_GL_NV_memory_attachment

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_mesh_shader

#ifndef GL_NV_mesh_shader
#define GL_NV_mesh_shader 1

#define GL_MESH_SHADER_NV                                        0x9559
#define GL_TASK_SHADER_NV                                        0x955A
#define GL_MAX_MESH_UNIFORM_BLOCKS_NV                            0x8E60
#define GL_MAX_MESH_TEXTURE_IMAGE_UNITS_NV                       0x8E61
#define GL_MAX_MESH_IMAGE_UNIFORMS_NV                            0x8E62
#define GL_MAX_MESH_UNIFORM_COMPONENTS_NV                        0x8E63
#define GL_MAX_MESH_ATOMIC_COUNTER_BUFFERS_NV                    0x8E64
#define GL_MAX_MESH_ATOMIC_COUNTERS_NV                           0x8E65
#define GL_MAX_MESH_SHADER_STORAGE_BLOCKS_NV                     0x8E66
#define GL_MAX_COMBINED_MESH_UNIFORM_COMPONENTS_NV               0x8E67
#define GL_MAX_TASK_UNIFORM_BLOCKS_NV                            0x8E68
#define GL_MAX_TASK_TEXTURE_IMAGE_UNITS_NV                       0x8E69
#define GL_MAX_TASK_IMAGE_UNIFORMS_NV                            0x8E6A
#define GL_MAX_TASK_UNIFORM_COMPONENTS_NV                        0x8E6B
#define GL_MAX_TASK_ATOMIC_COUNTER_BUFFERS_NV                    0x8E6C
#define GL_MAX_TASK_ATOMIC_COUNTERS_NV                           0x8E6D
#define GL_MAX_TASK_SHADER_STORAGE_BLOCKS_NV                     0x8E6E
#define GL_MAX_COMBINED_TASK_UNIFORM_COMPONENTS_NV               0x8E6F
#define GL_MAX_MESH_WORK_GROUP_INVOCATIONS_NV                    0x95A2
#define GL_MAX_TASK_WORK_GROUP_INVOCATIONS_NV                    0x95A3
#define GL_MAX_MESH_TOTAL_MEMORY_SIZE_NV                         0x9536
#define GL_MAX_TASK_TOTAL_MEMORY_SIZE_NV                         0x9537
#define GL_MAX_MESH_OUTPUT_VERTICES_NV                           0x9538
#define GL_MAX_MESH_OUTPUT_PRIMITIVES_NV                         0x9539
#define GL_MAX_TASK_OUTPUT_COUNT_NV                              0x953A
#define GL_MAX_DRAW_MESH_TASKS_COUNT_NV                          0x953D
#define GL_MAX_MESH_VIEWS_NV                                     0x9557
#define GL_MESH_OUTPUT_PER_VERTEX_GRANULARITY_NV                 0x92DF
#define GL_MESH_OUTPUT_PER_PRIMITIVE_GRANULARITY_NV              0x9543
#define GL_MAX_MESH_WORK_GROUP_SIZE_NV                           0x953B
#define GL_MAX_TASK_WORK_GROUP_SIZE_NV                           0x953C
#define GL_MESH_WORK_GROUP_SIZE_NV                               0x953E
#define GL_TASK_WORK_GROUP_SIZE_NV                               0x953F
#define GL_MESH_VERTICES_OUT_NV                                  0x9579
#define GL_MESH_PRIMITIVES_OUT_NV                                0x957A
#define GL_MESH_OUTPUT_TYPE_NV                                   0x957B
#define GL_UNIFORM_BLOCK_REFERENCED_BY_MESH_SHADER_NV            0x959C
#define GL_UNIFORM_BLOCK_REFERENCED_BY_TASK_SHADER_NV            0x959D
#define GL_REFERENCED_BY_MESH_SHADER_NV                          0x95A0
#define GL_REFERENCED_BY_TASK_SHADER_NV                          0x95A1
#define GL_MESH_SHADER_BIT_NV                                    0x00000040
#define GL_TASK_SHADER_BIT_NV                                    0x00000080
#define GL_MESH_SUBROUTINE_NV                                    0x957C
#define GL_TASK_SUBROUTINE_NV                                    0x957D
#define GL_MESH_SUBROUTINE_UNIFORM_NV                            0x957E
#define GL_TASK_SUBROUTINE_UNIFORM_NV                            0x957F
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_MESH_SHADER_NV    0x959E
#define GL_ATOMIC_COUNTER_BUFFER_REFERENCED_BY_TASK_SHADER_NV    0x959F

OPENGL_INIT_PROC(glDrawMeshTasksNV,                   void, GLuint first, GLuint count);
OPENGL_INIT_PROC(glDrawMeshTasksIndirectNV,           void, GLintptr indirect);
OPENGL_INIT_PROC(glMultiDrawMeshTasksIndirectNV,      void, GLintptr indirect, GLsizei drawcount, GLsizei stride);
OPENGL_INIT_PROC(glMultiDrawMeshTasksIndirectCountNV, void, GLintptr indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);

#define glDrawMeshTasksNV                   OGL__glDrawMeshTasksNV
#define glDrawMeshTasksIndirectNV           OGL__glDrawMeshTasksIndirectNV
#define glMultiDrawMeshTasksIndirectNV      OGL__glMultiDrawMeshTasksIndirectNV
#define glMultiDrawMeshTasksIndirectCountNV OGL__glMultiDrawMeshTasksIndirectCountNV

#endif // GL_NV_mesh_shader

#endif // OPENGL_INCLUDE_GL_NV_mesh_shader

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_multisample_coverage
#define GL_NV_multisample_coverage 1

#endif // GL_NV_multisample_coverage

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_multisample_filter_hint
#define GL_NV_multisample_filter_hint 1

#define GL_MULTISAMPLE_FILTER_HINT_NV    0x8534

#endif // GL_NV_multisample_filter_hint

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_occlusion_query

#ifndef GL_NV_occlusion_query
#define GL_NV_occlusion_query 1

#define GL_PIXEL_COUNTER_BITS_NV            0x8864
#define GL_CURRENT_OCCLUSION_QUERY_ID_NV    0x8865
#define GL_PIXEL_COUNT_NV                   0x8866
#define GL_PIXEL_COUNT_AVAILABLE_NV         0x8867

OPENGL_INIT_PROC(glGenOcclusionQueriesNV,    void,      GLsizei n, GLuint *ids);
OPENGL_INIT_PROC(glDeleteOcclusionQueriesNV, void,      GLsizei n, const GLuint *ids);
OPENGL_INIT_PROC(glIsOcclusionQueryNV,       GLboolean, GLuint id);
OPENGL_INIT_PROC(glBeginOcclusionQueryNV,    void,      GLuint id);
OPENGL_INIT_PROC(glEndOcclusionQueryNV,      void,      void);
OPENGL_INIT_PROC(glGetOcclusionQueryivNV,    void,      GLuint id, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetOcclusionQueryuivNV,   void,      GLuint id, GLenum pname, GLuint *params);

#define glGenOcclusionQueriesNV    OGL__glGenOcclusionQueriesNV
#define glDeleteOcclusionQueriesNV OGL__glDeleteOcclusionQueriesNV
#define glIsOcclusionQueryNV       OGL__glIsOcclusionQueryNV
#define glBeginOcclusionQueryNV    OGL__glBeginOcclusionQueryNV
#define glEndOcclusionQueryNV      OGL__glEndOcclusionQueryNV
#define glGetOcclusionQueryivNV    OGL__glGetOcclusionQueryivNV
#define glGetOcclusionQueryuivNV   OGL__glGetOcclusionQueryuivNV

#endif // GL_NV_occlusion_query

#endif // OPENGL_INCLUDE_GL_NV_occlusion_query

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_packed_depth_stencil
#define GL_NV_packed_depth_stencil 1

#define GL_DEPTH_STENCIL_NV        0x84F9
#define GL_UNSIGNED_INT_24_8_NV    0x84FA

#endif // GL_NV_packed_depth_stencil

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_parameter_buffer_object

#ifndef GL_NV_parameter_buffer_object
#define GL_NV_parameter_buffer_object 1

#define GL_MAX_PROGRAM_PARAMETER_BUFFER_BINDINGS_NV    0x8DA0
#define GL_MAX_PROGRAM_PARAMETER_BUFFER_SIZE_NV        0x8DA1
#define GL_VERTEX_PROGRAM_PARAMETER_BUFFER_NV          0x8DA2
#define GL_GEOMETRY_PROGRAM_PARAMETER_BUFFER_NV        0x8DA3
#define GL_FRAGMENT_PROGRAM_PARAMETER_BUFFER_NV        0x8DA4

OPENGL_INIT_PROC(glProgramBufferParametersfvNV,   void, GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLfloat *params);
OPENGL_INIT_PROC(glProgramBufferParametersIivNV,  void, GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLint *params);
OPENGL_INIT_PROC(glProgramBufferParametersIuivNV, void, GLenum target, GLuint bindingIndex, GLuint wordIndex, GLsizei count, const GLuint *params);

#define glProgramBufferParametersfvNV   OGL__glProgramBufferParametersfvNV
#define glProgramBufferParametersIivNV  OGL__glProgramBufferParametersIivNV
#define glProgramBufferParametersIuivNV OGL__glProgramBufferParametersIuivNV

#endif // GL_NV_parameter_buffer_object

#endif // OPENGL_INCLUDE_GL_NV_parameter_buffer_object

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_parameter_buffer_object2
#define GL_NV_parameter_buffer_object2 1

#endif // GL_NV_parameter_buffer_object2

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_path_rendering

#ifndef GL_NV_path_rendering
#define GL_NV_path_rendering 1

#define GL_PATH_FORMAT_SVG_NV                         0x9070
#define GL_PATH_FORMAT_PS_NV                          0x9071
#define GL_STANDARD_FONT_NAME_NV                      0x9072
#define GL_SYSTEM_FONT_NAME_NV                        0x9073
#define GL_FILE_NAME_NV                               0x9074
#define GL_PATH_STROKE_WIDTH_NV                       0x9075
#define GL_PATH_END_CAPS_NV                           0x9076
#define GL_PATH_INITIAL_END_CAP_NV                    0x9077
#define GL_PATH_TERMINAL_END_CAP_NV                   0x9078
#define GL_PATH_JOIN_STYLE_NV                         0x9079
#define GL_PATH_MITER_LIMIT_NV                        0x907A
#define GL_PATH_DASH_CAPS_NV                          0x907B
#define GL_PATH_INITIAL_DASH_CAP_NV                   0x907C
#define GL_PATH_TERMINAL_DASH_CAP_NV                  0x907D
#define GL_PATH_DASH_OFFSET_NV                        0x907E
#define GL_PATH_CLIENT_LENGTH_NV                      0x907F
#define GL_PATH_FILL_MODE_NV                          0x9080
#define GL_PATH_FILL_MASK_NV                          0x9081
#define GL_PATH_FILL_COVER_MODE_NV                    0x9082
#define GL_PATH_STROKE_COVER_MODE_NV                  0x9083
#define GL_PATH_STROKE_MASK_NV                        0x9084
#define GL_COUNT_UP_NV                                0x9088
#define GL_COUNT_DOWN_NV                              0x9089
#define GL_PATH_OBJECT_BOUNDING_BOX_NV                0x908A
#define GL_CONVEX_HULL_NV                             0x908B
#define GL_BOUNDING_BOX_NV                            0x908D
#define GL_TRANSLATE_X_NV                             0x908E
#define GL_TRANSLATE_Y_NV                             0x908F
#define GL_TRANSLATE_2D_NV                            0x9090
#define GL_TRANSLATE_3D_NV                            0x9091
#define GL_AFFINE_2D_NV                               0x9092
#define GL_AFFINE_3D_NV                               0x9094
#define GL_TRANSPOSE_AFFINE_2D_NV                     0x9096
#define GL_TRANSPOSE_AFFINE_3D_NV                     0x9098
#define GL_UTF8_NV                                    0x909A
#define GL_UTF16_NV                                   0x909B
#define GL_BOUNDING_BOX_OF_BOUNDING_BOXES_NV          0x909C
#define GL_PATH_COMMAND_COUNT_NV                      0x909D
#define GL_PATH_COORD_COUNT_NV                        0x909E
#define GL_PATH_DASH_ARRAY_COUNT_NV                   0x909F
#define GL_PATH_COMPUTED_LENGTH_NV                    0x90A0
#define GL_PATH_FILL_BOUNDING_BOX_NV                  0x90A1
#define GL_PATH_STROKE_BOUNDING_BOX_NV                0x90A2
#define GL_SQUARE_NV                                  0x90A3
#define GL_ROUND_NV                                   0x90A4
#define GL_TRIANGULAR_NV                              0x90A5
#define GL_BEVEL_NV                                   0x90A6
#define GL_MITER_REVERT_NV                            0x90A7
#define GL_MITER_TRUNCATE_NV                          0x90A8
#define GL_SKIP_MISSING_GLYPH_NV                      0x90A9
#define GL_USE_MISSING_GLYPH_NV                       0x90AA
#define GL_PATH_ERROR_POSITION_NV                     0x90AB
#define GL_ACCUM_ADJACENT_PAIRS_NV                    0x90AD
#define GL_ADJACENT_PAIRS_NV                          0x90AE
#define GL_FIRST_TO_REST_NV                           0x90AF
#define GL_PATH_GEN_MODE_NV                           0x90B0
#define GL_PATH_GEN_COEFF_NV                          0x90B1
#define GL_PATH_GEN_COMPONENTS_NV                     0x90B3
#define GL_PATH_STENCIL_FUNC_NV                       0x90B7
#define GL_PATH_STENCIL_REF_NV                        0x90B8
#define GL_PATH_STENCIL_VALUE_MASK_NV                 0x90B9
#define GL_PATH_STENCIL_DEPTH_OFFSET_FACTOR_NV        0x90BD
#define GL_PATH_STENCIL_DEPTH_OFFSET_UNITS_NV         0x90BE
#define GL_PATH_COVER_DEPTH_FUNC_NV                   0x90BF
#define GL_PATH_DASH_OFFSET_RESET_NV                  0x90B4
#define GL_MOVE_TO_RESETS_NV                          0x90B5
#define GL_MOVE_TO_CONTINUES_NV                       0x90B6
#define GL_CLOSE_PATH_NV                              0x00
#define GL_MOVE_TO_NV                                 0x02
#define GL_RELATIVE_MOVE_TO_NV                        0x03
#define GL_LINE_TO_NV                                 0x04
#define GL_RELATIVE_LINE_TO_NV                        0x05
#define GL_HORIZONTAL_LINE_TO_NV                      0x06
#define GL_RELATIVE_HORIZONTAL_LINE_TO_NV             0x07
#define GL_VERTICAL_LINE_TO_NV                        0x08
#define GL_RELATIVE_VERTICAL_LINE_TO_NV               0x09
#define GL_QUADRATIC_CURVE_TO_NV                      0x0A
#define GL_RELATIVE_QUADRATIC_CURVE_TO_NV             0x0B
#define GL_CUBIC_CURVE_TO_NV                          0x0C
#define GL_RELATIVE_CUBIC_CURVE_TO_NV                 0x0D
#define GL_SMOOTH_QUADRATIC_CURVE_TO_NV               0x0E
#define GL_RELATIVE_SMOOTH_QUADRATIC_CURVE_TO_NV      0x0F
#define GL_SMOOTH_CUBIC_CURVE_TO_NV                   0x10
#define GL_RELATIVE_SMOOTH_CUBIC_CURVE_TO_NV          0x11
#define GL_SMALL_CCW_ARC_TO_NV                        0x12
#define GL_RELATIVE_SMALL_CCW_ARC_TO_NV               0x13
#define GL_SMALL_CW_ARC_TO_NV                         0x14
#define GL_RELATIVE_SMALL_CW_ARC_TO_NV                0x15
#define GL_LARGE_CCW_ARC_TO_NV                        0x16
#define GL_RELATIVE_LARGE_CCW_ARC_TO_NV               0x17
#define GL_LARGE_CW_ARC_TO_NV                         0x18
#define GL_RELATIVE_LARGE_CW_ARC_TO_NV                0x19
#define GL_RESTART_PATH_NV                            0xF0
#define GL_DUP_FIRST_CUBIC_CURVE_TO_NV                0xF2
#define GL_DUP_LAST_CUBIC_CURVE_TO_NV                 0xF4
#define GL_RECT_NV                                    0xF6
#define GL_CIRCULAR_CCW_ARC_TO_NV                     0xF8
#define GL_CIRCULAR_CW_ARC_TO_NV                      0xFA
#define GL_CIRCULAR_TANGENT_ARC_TO_NV                 0xFC
#define GL_ARC_TO_NV                                  0xFE
#define GL_RELATIVE_ARC_TO_NV                         0xFF
#define GL_BOLD_BIT_NV                                0x01
#define GL_ITALIC_BIT_NV                              0x02
#define GL_GLYPH_WIDTH_BIT_NV                         0x01
#define GL_GLYPH_HEIGHT_BIT_NV                        0x02
#define GL_GLYPH_HORIZONTAL_BEARING_X_BIT_NV          0x04
#define GL_GLYPH_HORIZONTAL_BEARING_Y_BIT_NV          0x08
#define GL_GLYPH_HORIZONTAL_BEARING_ADVANCE_BIT_NV    0x10
#define GL_GLYPH_VERTICAL_BEARING_X_BIT_NV            0x20
#define GL_GLYPH_VERTICAL_BEARING_Y_BIT_NV            0x40
#define GL_GLYPH_VERTICAL_BEARING_ADVANCE_BIT_NV      0x80
#define GL_GLYPH_HAS_KERNING_BIT_NV                   0x100
#define GL_FONT_X_MIN_BOUNDS_BIT_NV                   0x00010000
#define GL_FONT_Y_MIN_BOUNDS_BIT_NV                   0x00020000
#define GL_FONT_X_MAX_BOUNDS_BIT_NV                   0x00040000
#define GL_FONT_Y_MAX_BOUNDS_BIT_NV                   0x00080000
#define GL_FONT_UNITS_PER_EM_BIT_NV                   0x00100000
#define GL_FONT_ASCENDER_BIT_NV                       0x00200000
#define GL_FONT_DESCENDER_BIT_NV                      0x00400000
#define GL_FONT_HEIGHT_BIT_NV                         0x00800000
#define GL_FONT_MAX_ADVANCE_WIDTH_BIT_NV              0x01000000
#define GL_FONT_MAX_ADVANCE_HEIGHT_BIT_NV             0x02000000
#define GL_FONT_UNDERLINE_POSITION_BIT_NV             0x04000000
#define GL_FONT_UNDERLINE_THICKNESS_BIT_NV            0x08000000
#define GL_FONT_HAS_KERNING_BIT_NV                    0x10000000
#define GL_ROUNDED_RECT_NV                            0xE8
#define GL_RELATIVE_ROUNDED_RECT_NV                   0xE9
#define GL_ROUNDED_RECT2_NV                           0xEA
#define GL_RELATIVE_ROUNDED_RECT2_NV                  0xEB
#define GL_ROUNDED_RECT4_NV                           0xEC
#define GL_RELATIVE_ROUNDED_RECT4_NV                  0xED
#define GL_ROUNDED_RECT8_NV                           0xEE
#define GL_RELATIVE_ROUNDED_RECT8_NV                  0xEF
#define GL_RELATIVE_RECT_NV                           0xF7
#define GL_FONT_GLYPHS_AVAILABLE_NV                   0x9368
#define GL_FONT_TARGET_UNAVAILABLE_NV                 0x9369
#define GL_FONT_UNAVAILABLE_NV                        0x936A
#define GL_FONT_UNINTELLIGIBLE_NV                     0x936B
#define GL_CONIC_CURVE_TO_NV                          0x1A
#define GL_RELATIVE_CONIC_CURVE_TO_NV                 0x1B
#define GL_FONT_NUM_GLYPH_INDICES_BIT_NV              0x20000000
#define GL_STANDARD_FONT_FORMAT_NV                    0x936C
#define GL_2_BYTES_NV                                 0x1407
#define GL_3_BYTES_NV                                 0x1408
#define GL_4_BYTES_NV                                 0x1409
#define GL_EYE_LINEAR_NV                              0x2400
#define GL_OBJECT_LINEAR_NV                           0x2401
#define GL_CONSTANT_NV                                0x8576
#define GL_PATH_FOG_GEN_MODE_NV                       0x90AC
#define GL_PRIMARY_COLOR_NV                           0x852C
#define GL_SECONDARY_COLOR_NV                         0x852D
#define GL_PATH_GEN_COLOR_FORMAT_NV                   0x90B2
#define GL_PATH_PROJECTION_NV                         0x1701
#define GL_PATH_MODELVIEW_NV                          0x1700
#define GL_PATH_MODELVIEW_STACK_DEPTH_NV              0x0BA3
#define GL_PATH_MODELVIEW_MATRIX_NV                   0x0BA6
#define GL_PATH_MAX_MODELVIEW_STACK_DEPTH_NV          0x0D36
#define GL_PATH_TRANSPOSE_MODELVIEW_MATRIX_NV         0x84E3
#define GL_PATH_PROJECTION_STACK_DEPTH_NV             0x0BA4
#define GL_PATH_PROJECTION_MATRIX_NV                  0x0BA7
#define GL_PATH_MAX_PROJECTION_STACK_DEPTH_NV         0x0D38
#define GL_PATH_TRANSPOSE_PROJECTION_MATRIX_NV        0x84E4
#define GL_FRAGMENT_INPUT_NV                          0x936D

OPENGL_INIT_PROC(glGenPathsNV,                            GLuint,    GLsizei range);
OPENGL_INIT_PROC(glDeletePathsNV,                         void,      GLuint path, GLsizei range);
OPENGL_INIT_PROC(glIsPathNV,                              GLboolean, GLuint path);
OPENGL_INIT_PROC(glPathCommandsNV,                        void,      GLuint path, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords);
OPENGL_INIT_PROC(glPathCoordsNV,                          void,      GLuint path, GLsizei numCoords, GLenum coordType, const void *coords);
OPENGL_INIT_PROC(glPathSubCommandsNV,                     void,      GLuint path, GLsizei commandStart, GLsizei commandsToDelete, GLsizei numCommands, const GLubyte *commands, GLsizei numCoords, GLenum coordType, const void *coords);
OPENGL_INIT_PROC(glPathSubCoordsNV,                       void,      GLuint path, GLsizei coordStart, GLsizei numCoords, GLenum coordType, const void *coords);
OPENGL_INIT_PROC(glPathStringNV,                          void,      GLuint path, GLenum format, GLsizei length, const void *pathString);
OPENGL_INIT_PROC(glPathGlyphsNV,                          void,      GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLsizei numGlyphs, GLenum type, const void *charcodes, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
OPENGL_INIT_PROC(glPathGlyphRangeNV,                      void,      GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyph, GLsizei numGlyphs, GLenum handleMissingGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
OPENGL_INIT_PROC(glWeightPathsNV,                         void,      GLuint resultPath, GLsizei numPaths, const GLuint *paths, const GLfloat *weights);
OPENGL_INIT_PROC(glCopyPathNV,                            void,      GLuint resultPath, GLuint srcPath);
OPENGL_INIT_PROC(glInterpolatePathsNV,                    void,      GLuint resultPath, GLuint pathA, GLuint pathB, GLfloat weight);
OPENGL_INIT_PROC(glTransformPathNV,                       void,      GLuint resultPath, GLuint srcPath, GLenum transformType, const GLfloat *transformValues);
OPENGL_INIT_PROC(glPathParameterivNV,                     void,      GLuint path, GLenum pname, const GLint *value);
OPENGL_INIT_PROC(glPathParameteriNV,                      void,      GLuint path, GLenum pname, GLint value);
OPENGL_INIT_PROC(glPathParameterfvNV,                     void,      GLuint path, GLenum pname, const GLfloat *value);
OPENGL_INIT_PROC(glPathParameterfNV,                      void,      GLuint path, GLenum pname, GLfloat value);
OPENGL_INIT_PROC(glPathDashArrayNV,                       void,      GLuint path, GLsizei dashCount, const GLfloat *dashArray);
OPENGL_INIT_PROC(glPathStencilFuncNV,                     void,      GLenum func, GLint ref, GLuint mask);
OPENGL_INIT_PROC(glPathStencilDepthOffsetNV,              void,      GLfloat factor, GLfloat units);
OPENGL_INIT_PROC(glStencilFillPathNV,                     void,      GLuint path, GLenum fillMode, GLuint mask);
OPENGL_INIT_PROC(glStencilStrokePathNV,                   void,      GLuint path, GLint reference, GLuint mask);
OPENGL_INIT_PROC(glStencilFillPathInstancedNV,            void,      GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum transformType, const GLfloat *transformValues);
OPENGL_INIT_PROC(glStencilStrokePathInstancedNV,          void,      GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum transformType, const GLfloat *transformValues);
OPENGL_INIT_PROC(glPathCoverDepthFuncNV,                  void,      GLenum func);
OPENGL_INIT_PROC(glCoverFillPathNV,                       void,      GLuint path, GLenum coverMode);
OPENGL_INIT_PROC(glCoverStrokePathNV,                     void,      GLuint path, GLenum coverMode);
OPENGL_INIT_PROC(glCoverFillPathInstancedNV,              void,      GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
OPENGL_INIT_PROC(glCoverStrokePathInstancedNV,            void,      GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
OPENGL_INIT_PROC(glGetPathParameterivNV,                  void,      GLuint path, GLenum pname, GLint *value);
OPENGL_INIT_PROC(glGetPathParameterfvNV,                  void,      GLuint path, GLenum pname, GLfloat *value);
OPENGL_INIT_PROC(glGetPathCommandsNV,                     void,      GLuint path, GLubyte *commands);
OPENGL_INIT_PROC(glGetPathCoordsNV,                       void,      GLuint path, GLfloat *coords);
OPENGL_INIT_PROC(glGetPathDashArrayNV,                    void,      GLuint path, GLfloat *dashArray);
OPENGL_INIT_PROC(glGetPathMetricsNV,                      void,      GLbitfield metricQueryMask, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLsizei stride, GLfloat *metrics);
OPENGL_INIT_PROC(glGetPathMetricRangeNV,                  void,      GLbitfield metricQueryMask, GLuint firstPathName, GLsizei numPaths, GLsizei stride, GLfloat *metrics);
OPENGL_INIT_PROC(glGetPathSpacingNV,                      void,      GLenum pathListMode, GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLfloat advanceScale, GLfloat kerningScale, GLenum transformType, GLfloat *returnedSpacing);
OPENGL_INIT_PROC(glIsPointInFillPathNV,                   GLboolean, GLuint path, GLuint mask, GLfloat x, GLfloat y);
OPENGL_INIT_PROC(glIsPointInStrokePathNV,                 GLboolean, GLuint path, GLfloat x, GLfloat y);
OPENGL_INIT_PROC(glGetPathLengthNV,                       GLfloat,   GLuint path, GLsizei startSegment, GLsizei numSegments);
OPENGL_INIT_PROC(glPointAlongPathNV,                      GLboolean, GLuint path, GLsizei startSegment, GLsizei numSegments, GLfloat distance, GLfloat *x, GLfloat *y, GLfloat *tangentX, GLfloat *tangentY);
OPENGL_INIT_PROC(glMatrixLoad3x2fNV,                      void,      GLenum matrixMode, const GLfloat *m);
OPENGL_INIT_PROC(glMatrixLoad3x3fNV,                      void,      GLenum matrixMode, const GLfloat *m);
OPENGL_INIT_PROC(glMatrixLoadTranspose3x3fNV,             void,      GLenum matrixMode, const GLfloat *m);
OPENGL_INIT_PROC(glMatrixMult3x2fNV,                      void,      GLenum matrixMode, const GLfloat *m);
OPENGL_INIT_PROC(glMatrixMult3x3fNV,                      void,      GLenum matrixMode, const GLfloat *m);
OPENGL_INIT_PROC(glMatrixMultTranspose3x3fNV,             void,      GLenum matrixMode, const GLfloat *m);
OPENGL_INIT_PROC(glStencilThenCoverFillPathNV,            void,      GLuint path, GLenum fillMode, GLuint mask, GLenum coverMode);
OPENGL_INIT_PROC(glStencilThenCoverStrokePathNV,          void,      GLuint path, GLint reference, GLuint mask, GLenum coverMode);
OPENGL_INIT_PROC(glStencilThenCoverFillPathInstancedNV,   void,      GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLenum fillMode, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
OPENGL_INIT_PROC(glStencilThenCoverStrokePathInstancedNV, void,      GLsizei numPaths, GLenum pathNameType, const void *paths, GLuint pathBase, GLint reference, GLuint mask, GLenum coverMode, GLenum transformType, const GLfloat *transformValues);
OPENGL_INIT_PROC(glPathGlyphIndexRangeNV,                 GLenum,    GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint pathParameterTemplate, GLfloat emScale, GLuint baseAndCount[2]);
OPENGL_INIT_PROC(glPathGlyphIndexArrayNV,                 GLenum,    GLuint firstPathName, GLenum fontTarget, const void *fontName, GLbitfield fontStyle, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
OPENGL_INIT_PROC(glPathMemoryGlyphIndexArrayNV,           GLenum,    GLuint firstPathName, GLenum fontTarget, GLsizeiptr fontSize, const void *fontData, GLsizei faceIndex, GLuint firstGlyphIndex, GLsizei numGlyphs, GLuint pathParameterTemplate, GLfloat emScale);
OPENGL_INIT_PROC(glProgramPathFragmentInputGenNV,         void,      GLuint program, GLint location, GLenum genMode, GLint components, const GLfloat *coeffs);
OPENGL_INIT_PROC(glGetProgramResourcefvNV,                void,      GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLfloat *params);
OPENGL_INIT_PROC(glPathColorGenNV,                        void,      GLenum color, GLenum genMode, GLenum colorFormat, const GLfloat *coeffs);
OPENGL_INIT_PROC(glPathTexGenNV,                          void,      GLenum texCoordSet, GLenum genMode, GLint components, const GLfloat *coeffs);
OPENGL_INIT_PROC(glPathFogGenNV,                          void,      GLenum genMode);
OPENGL_INIT_PROC(glGetPathColorGenivNV,                   void,      GLenum color, GLenum pname, GLint *value);
OPENGL_INIT_PROC(glGetPathColorGenfvNV,                   void,      GLenum color, GLenum pname, GLfloat *value);
OPENGL_INIT_PROC(glGetPathTexGenivNV,                     void,      GLenum texCoordSet, GLenum pname, GLint *value);
OPENGL_INIT_PROC(glGetPathTexGenfvNV,                     void,      GLenum texCoordSet, GLenum pname, GLfloat *value);

#define glGenPathsNV                            OGL__glGenPathsNV
#define glDeletePathsNV                         OGL__glDeletePathsNV
#define glIsPathNV                              OGL__glIsPathNV
#define glPathCommandsNV                        OGL__glPathCommandsNV
#define glPathCoordsNV                          OGL__glPathCoordsNV
#define glPathSubCommandsNV                     OGL__glPathSubCommandsNV
#define glPathSubCoordsNV                       OGL__glPathSubCoordsNV
#define glPathStringNV                          OGL__glPathStringNV
#define glPathGlyphsNV                          OGL__glPathGlyphsNV
#define glPathGlyphRangeNV                      OGL__glPathGlyphRangeNV
#define glWeightPathsNV                         OGL__glWeightPathsNV
#define glCopyPathNV                            OGL__glCopyPathNV
#define glInterpolatePathsNV                    OGL__glInterpolatePathsNV
#define glTransformPathNV                       OGL__glTransformPathNV
#define glPathParameterivNV                     OGL__glPathParameterivNV
#define glPathParameteriNV                      OGL__glPathParameteriNV
#define glPathParameterfvNV                     OGL__glPathParameterfvNV
#define glPathParameterfNV                      OGL__glPathParameterfNV
#define glPathDashArrayNV                       OGL__glPathDashArrayNV
#define glPathStencilFuncNV                     OGL__glPathStencilFuncNV
#define glPathStencilDepthOffsetNV              OGL__glPathStencilDepthOffsetNV
#define glStencilFillPathNV                     OGL__glStencilFillPathNV
#define glStencilStrokePathNV                   OGL__glStencilStrokePathNV
#define glStencilFillPathInstancedNV            OGL__glStencilFillPathInstancedNV
#define glStencilStrokePathInstancedNV          OGL__glStencilStrokePathInstancedNV
#define glPathCoverDepthFuncNV                  OGL__glPathCoverDepthFuncNV
#define glCoverFillPathNV                       OGL__glCoverFillPathNV
#define glCoverStrokePathNV                     OGL__glCoverStrokePathNV
#define glCoverFillPathInstancedNV              OGL__glCoverFillPathInstancedNV
#define glCoverStrokePathInstancedNV            OGL__glCoverStrokePathInstancedNV
#define glGetPathParameterivNV                  OGL__glGetPathParameterivNV
#define glGetPathParameterfvNV                  OGL__glGetPathParameterfvNV
#define glGetPathCommandsNV                     OGL__glGetPathCommandsNV
#define glGetPathCoordsNV                       OGL__glGetPathCoordsNV
#define glGetPathDashArrayNV                    OGL__glGetPathDashArrayNV
#define glGetPathMetricsNV                      OGL__glGetPathMetricsNV
#define glGetPathMetricRangeNV                  OGL__glGetPathMetricRangeNV
#define glGetPathSpacingNV                      OGL__glGetPathSpacingNV
#define glIsPointInFillPathNV                   OGL__glIsPointInFillPathNV
#define glIsPointInStrokePathNV                 OGL__glIsPointInStrokePathNV
#define glGetPathLengthNV                       OGL__glGetPathLengthNV
#define glPointAlongPathNV                      OGL__glPointAlongPathNV
#define glMatrixLoad3x2fNV                      OGL__glMatrixLoad3x2fNV
#define glMatrixLoad3x3fNV                      OGL__glMatrixLoad3x3fNV
#define glMatrixLoadTranspose3x3fNV             OGL__glMatrixLoadTranspose3x3fNV
#define glMatrixMult3x2fNV                      OGL__glMatrixMult3x2fNV
#define glMatrixMult3x3fNV                      OGL__glMatrixMult3x3fNV
#define glMatrixMultTranspose3x3fNV             OGL__glMatrixMultTranspose3x3fNV
#define glStencilThenCoverFillPathNV            OGL__glStencilThenCoverFillPathNV
#define glStencilThenCoverStrokePathNV          OGL__glStencilThenCoverStrokePathNV
#define glStencilThenCoverFillPathInstancedNV   OGL__glStencilThenCoverFillPathInstancedNV
#define glStencilThenCoverStrokePathInstancedNV OGL__glStencilThenCoverStrokePathInstancedNV
#define glPathGlyphIndexRangeNV                 OGL__glPathGlyphIndexRangeNV
#define glPathGlyphIndexArrayNV                 OGL__glPathGlyphIndexArrayNV
#define glPathMemoryGlyphIndexArrayNV           OGL__glPathMemoryGlyphIndexArrayNV
#define glProgramPathFragmentInputGenNV         OGL__glProgramPathFragmentInputGenNV
#define glGetProgramResourcefvNV                OGL__glGetProgramResourcefvNV
#define glPathColorGenNV                        OGL__glPathColorGenNV
#define glPathTexGenNV                          OGL__glPathTexGenNV
#define glPathFogGenNV                          OGL__glPathFogGenNV
#define glGetPathColorGenivNV                   OGL__glGetPathColorGenivNV
#define glGetPathColorGenfvNV                   OGL__glGetPathColorGenfvNV
#define glGetPathTexGenivNV                     OGL__glGetPathTexGenivNV
#define glGetPathTexGenfvNV                     OGL__glGetPathTexGenfvNV

#endif // GL_NV_path_rendering

#endif // OPENGL_INCLUDE_GL_NV_path_rendering

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_path_rendering_shared_edge
#define GL_NV_path_rendering_shared_edge 1

#define GL_SHARED_EDGE_NV    0xC0

#endif // GL_NV_path_rendering_shared_edge

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_pixel_data_range

#ifndef GL_NV_pixel_data_range
#define GL_NV_pixel_data_range 1

#define GL_WRITE_PIXEL_DATA_RANGE_NV            0x8878
#define GL_READ_PIXEL_DATA_RANGE_NV             0x8879
#define GL_WRITE_PIXEL_DATA_RANGE_LENGTH_NV     0x887A
#define GL_READ_PIXEL_DATA_RANGE_LENGTH_NV      0x887B
#define GL_WRITE_PIXEL_DATA_RANGE_POINTER_NV    0x887C
#define GL_READ_PIXEL_DATA_RANGE_POINTER_NV     0x887D

OPENGL_INIT_PROC(glPixelDataRangeNV,      void, GLenum target, GLsizei length, const void *pointer);
OPENGL_INIT_PROC(glFlushPixelDataRangeNV, void, GLenum target);

#define glPixelDataRangeNV      OGL__glPixelDataRangeNV
#define glFlushPixelDataRangeNV OGL__glFlushPixelDataRangeNV

#endif // GL_NV_pixel_data_range

#endif // OPENGL_INCLUDE_GL_NV_pixel_data_range

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_point_sprite

#ifndef GL_NV_point_sprite
#define GL_NV_point_sprite 1

#define GL_POINT_SPRITE_NV           0x8861
#define GL_COORD_REPLACE_NV          0x8862
#define GL_POINT_SPRITE_R_MODE_NV    0x8863

OPENGL_INIT_PROC(glPointParameteriNV,  void, GLenum pname, GLint param);
OPENGL_INIT_PROC(glPointParameterivNV, void, GLenum pname, const GLint *params);

#define glPointParameteriNV  OGL__glPointParameteriNV
#define glPointParameterivNV OGL__glPointParameterivNV

#endif // GL_NV_point_sprite

#endif // OPENGL_INCLUDE_GL_NV_point_sprite

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_present_video

#ifndef GL_NV_present_video
#define GL_NV_present_video 1

#define GL_FRAME_NV               0x8E26
#define GL_FIELDS_NV              0x8E27
#define GL_CURRENT_TIME_NV        0x8E28
#define GL_NUM_FILL_STREAMS_NV    0x8E29
#define GL_PRESENT_TIME_NV        0x8E2A
#define GL_PRESENT_DURATION_NV    0x8E2B

OPENGL_INIT_PROC(glPresentFrameKeyedNV,    void, GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLuint key0, GLenum target1, GLuint fill1, GLuint key1);
OPENGL_INIT_PROC(glPresentFrameDualFillNV, void, GLuint video_slot, GLuint64EXT minPresentTime, GLuint beginPresentTimeId, GLuint presentDurationId, GLenum type, GLenum target0, GLuint fill0, GLenum target1, GLuint fill1, GLenum target2, GLuint fill2, GLenum target3, GLuint fill3);
OPENGL_INIT_PROC(glGetVideoivNV,           void, GLuint video_slot, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetVideouivNV,          void, GLuint video_slot, GLenum pname, GLuint *params);
OPENGL_INIT_PROC(glGetVideoi64vNV,         void, GLuint video_slot, GLenum pname, GLint64EXT *params);
OPENGL_INIT_PROC(glGetVideoui64vNV,        void, GLuint video_slot, GLenum pname, GLuint64EXT *params);

#define glPresentFrameKeyedNV    OGL__glPresentFrameKeyedNV
#define glPresentFrameDualFillNV OGL__glPresentFrameDualFillNV
#define glGetVideoivNV           OGL__glGetVideoivNV
#define glGetVideouivNV          OGL__glGetVideouivNV
#define glGetVideoi64vNV         OGL__glGetVideoi64vNV
#define glGetVideoui64vNV        OGL__glGetVideoui64vNV

#endif // GL_NV_present_video

#endif // OPENGL_INCLUDE_GL_NV_present_video

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_primitive_restart

#ifndef GL_NV_primitive_restart
#define GL_NV_primitive_restart 1

#define GL_PRIMITIVE_RESTART_NV          0x8558
#define GL_PRIMITIVE_RESTART_INDEX_NV    0x8559

OPENGL_INIT_PROC(glPrimitiveRestartNV,      void, void);
OPENGL_INIT_PROC(glPrimitiveRestartIndexNV, void, GLuint index);

#define glPrimitiveRestartNV      OGL__glPrimitiveRestartNV
#define glPrimitiveRestartIndexNV OGL__glPrimitiveRestartIndexNV

#endif // GL_NV_primitive_restart

#endif // OPENGL_INCLUDE_GL_NV_primitive_restart

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_query_resource

#ifndef GL_NV_query_resource
#define GL_NV_query_resource 1

#define GL_QUERY_RESOURCE_TYPE_VIDMEM_ALLOC_NV    0x9540
#define GL_QUERY_RESOURCE_MEMTYPE_VIDMEM_NV       0x9542
#define GL_QUERY_RESOURCE_SYS_RESERVED_NV         0x9544
#define GL_QUERY_RESOURCE_TEXTURE_NV              0x9545
#define GL_QUERY_RESOURCE_RENDERBUFFER_NV         0x9546
#define GL_QUERY_RESOURCE_BUFFEROBJECT_NV         0x9547

OPENGL_INIT_PROC(glQueryResourceNV, GLint, GLenum queryType, GLint tagId, GLuint bufSize, GLint *buffer);
#define glQueryResourceNV OGL__glQueryResourceNV

#endif // GL_NV_query_resource

#endif // OPENGL_INCLUDE_GL_NV_query_resource

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_query_resource_tag

#ifndef GL_NV_query_resource_tag
#define GL_NV_query_resource_tag 1

OPENGL_INIT_PROC(glGenQueryResourceTagNV,    void, GLsizei n, GLint *tagIds);
OPENGL_INIT_PROC(glDeleteQueryResourceTagNV, void, GLsizei n, const GLint *tagIds);
OPENGL_INIT_PROC(glQueryResourceTagNV,       void, GLint tagId, const GLchar *tagString);

#define glGenQueryResourceTagNV    OGL__glGenQueryResourceTagNV
#define glDeleteQueryResourceTagNV OGL__glDeleteQueryResourceTagNV
#define glQueryResourceTagNV       OGL__glQueryResourceTagNV

#endif // GL_NV_query_resource_tag

#endif // OPENGL_INCLUDE_GL_NV_query_resource_tag

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_register_combiners

#ifndef GL_NV_register_combiners
#define GL_NV_register_combiners 1

#define GL_REGISTER_COMBINERS_NV             0x8522
#define GL_VARIABLE_A_NV                     0x8523
#define GL_VARIABLE_B_NV                     0x8524
#define GL_VARIABLE_C_NV                     0x8525
#define GL_VARIABLE_D_NV                     0x8526
#define GL_VARIABLE_E_NV                     0x8527
#define GL_VARIABLE_F_NV                     0x8528
#define GL_VARIABLE_G_NV                     0x8529
#define GL_CONSTANT_COLOR0_NV                0x852A
#define GL_CONSTANT_COLOR1_NV                0x852B
#define GL_SPARE0_NV                         0x852E
#define GL_SPARE1_NV                         0x852F
#define GL_DISCARD_NV                        0x8530
#define GL_E_TIMES_F_NV                      0x8531
#define GL_SPARE0_PLUS_SECONDARY_COLOR_NV    0x8532
#define GL_UNSIGNED_IDENTITY_NV              0x8536
#define GL_UNSIGNED_INVERT_NV                0x8537
#define GL_EXPAND_NORMAL_NV                  0x8538
#define GL_EXPAND_NEGATE_NV                  0x8539
#define GL_HALF_BIAS_NORMAL_NV               0x853A
#define GL_HALF_BIAS_NEGATE_NV               0x853B
#define GL_SIGNED_IDENTITY_NV                0x853C
#define GL_SIGNED_NEGATE_NV                  0x853D
#define GL_SCALE_BY_TWO_NV                   0x853E
#define GL_SCALE_BY_FOUR_NV                  0x853F
#define GL_SCALE_BY_ONE_HALF_NV              0x8540
#define GL_BIAS_BY_NEGATIVE_ONE_HALF_NV      0x8541
#define GL_COMBINER_INPUT_NV                 0x8542
#define GL_COMBINER_MAPPING_NV               0x8543
#define GL_COMBINER_COMPONENT_USAGE_NV       0x8544
#define GL_COMBINER_AB_DOT_PRODUCT_NV        0x8545
#define GL_COMBINER_CD_DOT_PRODUCT_NV        0x8546
#define GL_COMBINER_MUX_SUM_NV               0x8547
#define GL_COMBINER_SCALE_NV                 0x8548
#define GL_COMBINER_BIAS_NV                  0x8549
#define GL_COMBINER_AB_OUTPUT_NV             0x854A
#define GL_COMBINER_CD_OUTPUT_NV             0x854B
#define GL_COMBINER_SUM_OUTPUT_NV            0x854C
#define GL_MAX_GENERAL_COMBINERS_NV          0x854D
#define GL_NUM_GENERAL_COMBINERS_NV          0x854E
#define GL_COLOR_SUM_CLAMP_NV                0x854F
#define GL_COMBINER0_NV                      0x8550
#define GL_COMBINER1_NV                      0x8551
#define GL_COMBINER2_NV                      0x8552
#define GL_COMBINER3_NV                      0x8553
#define GL_COMBINER4_NV                      0x8554
#define GL_COMBINER5_NV                      0x8555
#define GL_COMBINER6_NV                      0x8556
#define GL_COMBINER7_NV                      0x8557

OPENGL_INIT_PROC(glCombinerParameterfvNV,              void, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glCombinerParameterfNV,               void, GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glCombinerParameterivNV,              void, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glCombinerParameteriNV,               void, GLenum pname, GLint param);
OPENGL_INIT_PROC(glCombinerInputNV,                    void, GLenum stage, GLenum portion, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
OPENGL_INIT_PROC(glCombinerOutputNV,                   void, GLenum stage, GLenum portion, GLenum abOutput, GLenum cdOutput, GLenum sumOutput, GLenum scale, GLenum bias, GLboolean abDotProduct, GLboolean cdDotProduct, GLboolean muxSum);
OPENGL_INIT_PROC(glFinalCombinerInputNV,               void, GLenum variable, GLenum input, GLenum mapping, GLenum componentUsage);
OPENGL_INIT_PROC(glGetCombinerInputParameterfvNV,      void, GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetCombinerInputParameterivNV,      void, GLenum stage, GLenum portion, GLenum variable, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetCombinerOutputParameterfvNV,     void, GLenum stage, GLenum portion, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetCombinerOutputParameterivNV,     void, GLenum stage, GLenum portion, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetFinalCombinerInputParameterfvNV, void, GLenum variable, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetFinalCombinerInputParameterivNV, void, GLenum variable, GLenum pname, GLint *params);

#define glCombinerParameterfvNV              OGL__glCombinerParameterfvNV
#define glCombinerParameterfNV               OGL__glCombinerParameterfNV
#define glCombinerParameterivNV              OGL__glCombinerParameterivNV
#define glCombinerParameteriNV               OGL__glCombinerParameteriNV
#define glCombinerInputNV                    OGL__glCombinerInputNV
#define glCombinerOutputNV                   OGL__glCombinerOutputNV
#define glFinalCombinerInputNV               OGL__glFinalCombinerInputNV
#define glGetCombinerInputParameterfvNV      OGL__glGetCombinerInputParameterfvNV
#define glGetCombinerInputParameterivNV      OGL__glGetCombinerInputParameterivNV
#define glGetCombinerOutputParameterfvNV     OGL__glGetCombinerOutputParameterfvNV
#define glGetCombinerOutputParameterivNV     OGL__glGetCombinerOutputParameterivNV
#define glGetFinalCombinerInputParameterfvNV OGL__glGetFinalCombinerInputParameterfvNV
#define glGetFinalCombinerInputParameterivNV OGL__glGetFinalCombinerInputParameterivNV

#endif // GL_NV_register_combiners

#endif // OPENGL_INCLUDE_GL_NV_register_combiners

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_register_combiners2

#ifndef GL_NV_register_combiners2
#define GL_NV_register_combiners2 1

#define GL_PER_STAGE_CONSTANTS_NV    0x8535

OPENGL_INIT_PROC(glCombinerStageParameterfvNV,    void, GLenum stage, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glGetCombinerStageParameterfvNV, void, GLenum stage, GLenum pname, GLfloat *params);

#define glCombinerStageParameterfvNV    OGL__glCombinerStageParameterfvNV
#define glGetCombinerStageParameterfvNV OGL__glGetCombinerStageParameterfvNV

#endif // GL_NV_register_combiners2

#endif // OPENGL_INCLUDE_GL_NV_register_combiners2

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_representative_fragment_test
#define GL_NV_representative_fragment_test 1

#define GL_REPRESENTATIVE_FRAGMENT_TEST_NV    0x937F

#endif // GL_NV_representative_fragment_test

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_robustness_video_memory_purge
#define GL_NV_robustness_video_memory_purge 1

#define GL_PURGED_CONTEXT_RESET_NV    0x92BB

#endif // GL_NV_robustness_video_memory_purge

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_sample_locations

#ifndef GL_NV_sample_locations
#define GL_NV_sample_locations 1

#define GL_SAMPLE_LOCATION_SUBPIXEL_BITS_NV                0x933D
#define GL_SAMPLE_LOCATION_PIXEL_GRID_WIDTH_NV             0x933E
#define GL_SAMPLE_LOCATION_PIXEL_GRID_HEIGHT_NV            0x933F
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_TABLE_SIZE_NV      0x9340
#define GL_SAMPLE_LOCATION_NV                              0x8E50
#define GL_PROGRAMMABLE_SAMPLE_LOCATION_NV                 0x9341
#define GL_FRAMEBUFFER_PROGRAMMABLE_SAMPLE_LOCATIONS_NV    0x9342
#define GL_FRAMEBUFFER_SAMPLE_LOCATION_PIXEL_GRID_NV       0x9343

OPENGL_INIT_PROC(glFramebufferSampleLocationsfvNV,      void, GLenum target, GLuint start, GLsizei count, const GLfloat *v);
OPENGL_INIT_PROC(glNamedFramebufferSampleLocationsfvNV, void, GLuint framebuffer, GLuint start, GLsizei count, const GLfloat *v);
OPENGL_INIT_PROC(glResolveDepthValuesNV,                void, void);

#define glFramebufferSampleLocationsfvNV      OGL__glFramebufferSampleLocationsfvNV
#define glNamedFramebufferSampleLocationsfvNV OGL__glNamedFramebufferSampleLocationsfvNV
#define glResolveDepthValuesNV                OGL__glResolveDepthValuesNV

#endif // GL_NV_sample_locations

#endif // OPENGL_INCLUDE_GL_NV_sample_locations

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_sample_mask_override_coverage
#define GL_NV_sample_mask_override_coverage 1

#endif // GL_NV_sample_mask_override_coverage

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_scissor_exclusive

#ifndef GL_NV_scissor_exclusive
#define GL_NV_scissor_exclusive 1

#define GL_SCISSOR_TEST_EXCLUSIVE_NV    0x9555
#define GL_SCISSOR_BOX_EXCLUSIVE_NV     0x9556

OPENGL_INIT_PROC(glScissorExclusiveNV,       void, GLint x, GLint y, GLsizei width, GLsizei height);
OPENGL_INIT_PROC(glScissorExclusiveArrayvNV, void, GLuint first, GLsizei count, const GLint *v);

#define glScissorExclusiveNV       OGL__glScissorExclusiveNV
#define glScissorExclusiveArrayvNV OGL__glScissorExclusiveArrayvNV

#endif // GL_NV_scissor_exclusive

#endif // OPENGL_INCLUDE_GL_NV_scissor_exclusive

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_shader_atomic_counters
#define GL_NV_shader_atomic_counters 1

#endif // GL_NV_shader_atomic_counters

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_shader_atomic_float
#define GL_NV_shader_atomic_float 1

#endif // GL_NV_shader_atomic_float

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_shader_atomic_float64
#define GL_NV_shader_atomic_float64 1

#endif // GL_NV_shader_atomic_float64

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_shader_atomic_fp16_vector
#define GL_NV_shader_atomic_fp16_vector 1

#endif // GL_NV_shader_atomic_fp16_vector

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_shader_atomic_int64
#define GL_NV_shader_atomic_int64 1

#endif // GL_NV_shader_atomic_int64

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_shader_buffer_load

#ifndef GL_NV_shader_buffer_load
#define GL_NV_shader_buffer_load 1

#define GL_BUFFER_GPU_ADDRESS_NV           0x8F1D
#define GL_GPU_ADDRESS_NV                  0x8F34
#define GL_MAX_SHADER_BUFFER_ADDRESS_NV    0x8F35

OPENGL_INIT_PROC(glMakeBufferResidentNV,           void,      GLenum target, GLenum access);
OPENGL_INIT_PROC(glMakeBufferNonResidentNV,        void,      GLenum target);
OPENGL_INIT_PROC(glIsBufferResidentNV,             GLboolean, GLenum target);
OPENGL_INIT_PROC(glMakeNamedBufferResidentNV,      void,      GLuint buffer, GLenum access);
OPENGL_INIT_PROC(glMakeNamedBufferNonResidentNV,   void,      GLuint buffer);
OPENGL_INIT_PROC(glIsNamedBufferResidentNV,        GLboolean, GLuint buffer);
OPENGL_INIT_PROC(glGetBufferParameterui64vNV,      void,      GLenum target, GLenum pname, GLuint64EXT *params);
OPENGL_INIT_PROC(glGetNamedBufferParameterui64vNV, void,      GLuint buffer, GLenum pname, GLuint64EXT *params);
OPENGL_INIT_PROC(glGetIntegerui64vNV,              void,      GLenum value, GLuint64EXT *result);
OPENGL_INIT_PROC(glUniformui64NV,                  void,      GLint location, GLuint64EXT value);
OPENGL_INIT_PROC(glUniformui64vNV,                 void,      GLint location, GLsizei count, const GLuint64EXT *value);
OPENGL_INIT_PROC(glProgramUniformui64NV,           void,      GLuint program, GLint location, GLuint64EXT value);
OPENGL_INIT_PROC(glProgramUniformui64vNV,          void,      GLuint program, GLint location, GLsizei count, const GLuint64EXT *value);

#define glMakeBufferResidentNV           OGL__glMakeBufferResidentNV
#define glMakeBufferNonResidentNV        OGL__glMakeBufferNonResidentNV
#define glIsBufferResidentNV             OGL__glIsBufferResidentNV
#define glMakeNamedBufferResidentNV      OGL__glMakeNamedBufferResidentNV
#define glMakeNamedBufferNonResidentNV   OGL__glMakeNamedBufferNonResidentNV
#define glIsNamedBufferResidentNV        OGL__glIsNamedBufferResidentNV
#define glGetBufferParameterui64vNV      OGL__glGetBufferParameterui64vNV
#define glGetNamedBufferParameterui64vNV OGL__glGetNamedBufferParameterui64vNV
#define glGetIntegerui64vNV              OGL__glGetIntegerui64vNV
#define glUniformui64NV                  OGL__glUniformui64NV
#define glUniformui64vNV                 OGL__glUniformui64vNV
#define glProgramUniformui64NV           OGL__glProgramUniformui64NV
#define glProgramUniformui64vNV          OGL__glProgramUniformui64vNV

#endif // GL_NV_shader_buffer_load

#endif // OPENGL_INCLUDE_GL_NV_shader_buffer_load

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_shader_buffer_store
#define GL_NV_shader_buffer_store 1

#define GL_SHADER_GLOBAL_ACCESS_BARRIER_BIT_NV    0x00000010

#endif // GL_NV_shader_buffer_store

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_shader_storage_buffer_object
#define GL_NV_shader_storage_buffer_object 1

#endif // GL_NV_shader_storage_buffer_object

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_shader_subgroup_partitioned
#define GL_NV_shader_subgroup_partitioned 1

#define GL_SUBGROUP_FEATURE_PARTITIONED_BIT_NV    0x00000100

#endif // GL_NV_shader_subgroup_partitioned

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_shader_texture_footprint
#define GL_NV_shader_texture_footprint 1

#endif // GL_NV_shader_texture_footprint

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_shader_thread_group
#define GL_NV_shader_thread_group 1

#define GL_WARP_SIZE_NV       0x9339
#define GL_WARPS_PER_SM_NV    0x933A
#define GL_SM_COUNT_NV        0x933B

#endif // GL_NV_shader_thread_group

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_shader_thread_shuffle
#define GL_NV_shader_thread_shuffle 1

#endif // GL_NV_shader_thread_shuffle

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_shading_rate_image

#ifndef GL_NV_shading_rate_image
#define GL_NV_shading_rate_image 1

#define GL_SHADING_RATE_IMAGE_NV                          0x9563
#define GL_SHADING_RATE_NO_INVOCATIONS_NV                 0x9564
#define GL_SHADING_RATE_1_INVOCATION_PER_PIXEL_NV         0x9565
#define GL_SHADING_RATE_1_INVOCATION_PER_1X2_PIXELS_NV    0x9566
#define GL_SHADING_RATE_1_INVOCATION_PER_2X1_PIXELS_NV    0x9567
#define GL_SHADING_RATE_1_INVOCATION_PER_2X2_PIXELS_NV    0x9568
#define GL_SHADING_RATE_1_INVOCATION_PER_2X4_PIXELS_NV    0x9569
#define GL_SHADING_RATE_1_INVOCATION_PER_4X2_PIXELS_NV    0x956A
#define GL_SHADING_RATE_1_INVOCATION_PER_4X4_PIXELS_NV    0x956B
#define GL_SHADING_RATE_2_INVOCATIONS_PER_PIXEL_NV        0x956C
#define GL_SHADING_RATE_4_INVOCATIONS_PER_PIXEL_NV        0x956D
#define GL_SHADING_RATE_8_INVOCATIONS_PER_PIXEL_NV        0x956E
#define GL_SHADING_RATE_16_INVOCATIONS_PER_PIXEL_NV       0x956F
#define GL_SHADING_RATE_IMAGE_BINDING_NV                  0x955B
#define GL_SHADING_RATE_IMAGE_TEXEL_WIDTH_NV              0x955C
#define GL_SHADING_RATE_IMAGE_TEXEL_HEIGHT_NV             0x955D
#define GL_SHADING_RATE_IMAGE_PALETTE_SIZE_NV             0x955E
#define GL_MAX_COARSE_FRAGMENT_SAMPLES_NV                 0x955F
#define GL_SHADING_RATE_SAMPLE_ORDER_DEFAULT_NV           0x95AE
#define GL_SHADING_RATE_SAMPLE_ORDER_PIXEL_MAJOR_NV       0x95AF
#define GL_SHADING_RATE_SAMPLE_ORDER_SAMPLE_MAJOR_NV      0x95B0

OPENGL_INIT_PROC(glBindShadingRateImageNV,           void, GLuint texture);
OPENGL_INIT_PROC(glGetShadingRateImagePaletteNV,     void, GLuint viewport, GLuint entry, GLenum *rate);
OPENGL_INIT_PROC(glGetShadingRateSampleLocationivNV, void, GLenum rate, GLuint samples, GLuint index, GLint *location);
OPENGL_INIT_PROC(glShadingRateImageBarrierNV,        void, GLboolean synchronize);
OPENGL_INIT_PROC(glShadingRateImagePaletteNV,        void, GLuint viewport, GLuint first, GLsizei count, const GLenum *rates);
OPENGL_INIT_PROC(glShadingRateSampleOrderNV,         void, GLenum order);
OPENGL_INIT_PROC(glShadingRateSampleOrderCustomNV,   void, GLenum rate, GLuint samples, const GLint *locations);

#define glBindShadingRateImageNV           OGL__glBindShadingRateImageNV
#define glGetShadingRateImagePaletteNV     OGL__glGetShadingRateImagePaletteNV
#define glGetShadingRateSampleLocationivNV OGL__glGetShadingRateSampleLocationivNV
#define glShadingRateImageBarrierNV        OGL__glShadingRateImageBarrierNV
#define glShadingRateImagePaletteNV        OGL__glShadingRateImagePaletteNV
#define glShadingRateSampleOrderNV         OGL__glShadingRateSampleOrderNV
#define glShadingRateSampleOrderCustomNV   OGL__glShadingRateSampleOrderCustomNV

#endif // GL_NV_shading_rate_image

#endif // OPENGL_INCLUDE_GL_NV_shading_rate_image

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_stereo_view_rendering
#define GL_NV_stereo_view_rendering 1

#endif // GL_NV_stereo_view_rendering

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_tessellation_program5
#define GL_NV_tessellation_program5 1

#define GL_MAX_PROGRAM_PATCH_ATTRIBS_NV                   0x86D8
#define GL_TESS_CONTROL_PROGRAM_NV                        0x891E
#define GL_TESS_EVALUATION_PROGRAM_NV                     0x891F
#define GL_TESS_CONTROL_PROGRAM_PARAMETER_BUFFER_NV       0x8C74
#define GL_TESS_EVALUATION_PROGRAM_PARAMETER_BUFFER_NV    0x8C75

#endif // GL_NV_tessellation_program5

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_texgen_emboss
#define GL_NV_texgen_emboss 1

#define GL_EMBOSS_LIGHT_NV       0x855D
#define GL_EMBOSS_CONSTANT_NV    0x855E
#define GL_EMBOSS_MAP_NV         0x855F

#endif // GL_NV_texgen_emboss

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_texgen_reflection
#define GL_NV_texgen_reflection 1

#define GL_NORMAL_MAP_NV        0x8511
#define GL_REFLECTION_MAP_NV    0x8512

#endif // GL_NV_texgen_reflection

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_texture_barrier

#ifndef GL_NV_texture_barrier
#define GL_NV_texture_barrier 1

OPENGL_INIT_PROC(glTextureBarrierNV, void, void);
#define glTextureBarrierNV OGL__glTextureBarrierNV

#endif // GL_NV_texture_barrier

#endif // OPENGL_INCLUDE_GL_NV_texture_barrier

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_texture_compression_vtc
#define GL_NV_texture_compression_vtc 1

#endif // GL_NV_texture_compression_vtc

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_texture_env_combine4
#define GL_NV_texture_env_combine4 1

#define GL_COMBINE4_NV          0x8503
#define GL_SOURCE3_RGB_NV       0x8583
#define GL_SOURCE3_ALPHA_NV     0x858B
#define GL_OPERAND3_RGB_NV      0x8593
#define GL_OPERAND3_ALPHA_NV    0x859B

#endif // GL_NV_texture_env_combine4

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_texture_expand_normal
#define GL_NV_texture_expand_normal 1

#define GL_TEXTURE_UNSIGNED_REMAP_MODE_NV    0x888F

#endif // GL_NV_texture_expand_normal

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_texture_multisample

#ifndef GL_NV_texture_multisample
#define GL_NV_texture_multisample 1

#define GL_TEXTURE_COVERAGE_SAMPLES_NV    0x9045
#define GL_TEXTURE_COLOR_SAMPLES_NV       0x9046

OPENGL_INIT_PROC(glTexImage2DMultisampleCoverageNV,     void, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
OPENGL_INIT_PROC(glTexImage3DMultisampleCoverageNV,     void, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
OPENGL_INIT_PROC(glTextureImage2DMultisampleNV,         void, GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
OPENGL_INIT_PROC(glTextureImage3DMultisampleNV,         void, GLuint texture, GLenum target, GLsizei samples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);
OPENGL_INIT_PROC(glTextureImage2DMultisampleCoverageNV, void, GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLboolean fixedSampleLocations);
OPENGL_INIT_PROC(glTextureImage3DMultisampleCoverageNV, void, GLuint texture, GLenum target, GLsizei coverageSamples, GLsizei colorSamples, GLint internalFormat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedSampleLocations);

#define glTexImage2DMultisampleCoverageNV     OGL__glTexImage2DMultisampleCoverageNV
#define glTexImage3DMultisampleCoverageNV     OGL__glTexImage3DMultisampleCoverageNV
#define glTextureImage2DMultisampleNV         OGL__glTextureImage2DMultisampleNV
#define glTextureImage3DMultisampleNV         OGL__glTextureImage3DMultisampleNV
#define glTextureImage2DMultisampleCoverageNV OGL__glTextureImage2DMultisampleCoverageNV
#define glTextureImage3DMultisampleCoverageNV OGL__glTextureImage3DMultisampleCoverageNV

#endif // GL_NV_texture_multisample

#endif // OPENGL_INCLUDE_GL_NV_texture_multisample

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_texture_rectangle
#define GL_NV_texture_rectangle 1

#define GL_TEXTURE_RECTANGLE_NV             0x84F5
#define GL_TEXTURE_BINDING_RECTANGLE_NV     0x84F6
#define GL_PROXY_TEXTURE_RECTANGLE_NV       0x84F7
#define GL_MAX_RECTANGLE_TEXTURE_SIZE_NV    0x84F8

#endif // GL_NV_texture_rectangle

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_texture_rectangle_compressed
#define GL_NV_texture_rectangle_compressed 1

#endif // GL_NV_texture_rectangle_compressed

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_texture_shader
#define GL_NV_texture_shader 1

#define GL_OFFSET_TEXTURE_RECTANGLE_NV                  0x864C
#define GL_OFFSET_TEXTURE_RECTANGLE_SCALE_NV            0x864D
#define GL_DOT_PRODUCT_TEXTURE_RECTANGLE_NV             0x864E
#define GL_RGBA_UNSIGNED_DOT_PRODUCT_MAPPING_NV         0x86D9
#define GL_UNSIGNED_INT_S8_S8_8_8_NV                    0x86DA
#define GL_UNSIGNED_INT_8_8_S8_S8_REV_NV                0x86DB
#define GL_DSDT_MAG_INTENSITY_NV                        0x86DC
#define GL_SHADER_CONSISTENT_NV                         0x86DD
#define GL_TEXTURE_SHADER_NV                            0x86DE
#define GL_SHADER_OPERATION_NV                          0x86DF
#define GL_CULL_MODES_NV                                0x86E0
#define GL_OFFSET_TEXTURE_MATRIX_NV                     0x86E1
#define GL_OFFSET_TEXTURE_SCALE_NV                      0x86E2
#define GL_OFFSET_TEXTURE_BIAS_NV                       0x86E3
#define GL_OFFSET_TEXTURE_2D_MATRIX_NV                  0x86E1
#define GL_OFFSET_TEXTURE_2D_SCALE_NV                   0x86E2
#define GL_OFFSET_TEXTURE_2D_BIAS_NV                    0x86E3
#define GL_PREVIOUS_TEXTURE_INPUT_NV                    0x86E4
#define GL_CONST_EYE_NV                                 0x86E5
#define GL_PASS_THROUGH_NV                              0x86E6
#define GL_CULL_FRAGMENT_NV                             0x86E7
#define GL_OFFSET_TEXTURE_2D_NV                         0x86E8
#define GL_DEPENDENT_AR_TEXTURE_2D_NV                   0x86E9
#define GL_DEPENDENT_GB_TEXTURE_2D_NV                   0x86EA
#define GL_DOT_PRODUCT_NV                               0x86EC
#define GL_DOT_PRODUCT_DEPTH_REPLACE_NV                 0x86ED
#define GL_DOT_PRODUCT_TEXTURE_2D_NV                    0x86EE
#define GL_DOT_PRODUCT_TEXTURE_CUBE_MAP_NV              0x86F0
#define GL_DOT_PRODUCT_DIFFUSE_CUBE_MAP_NV              0x86F1
#define GL_DOT_PRODUCT_REFLECT_CUBE_MAP_NV              0x86F2
#define GL_DOT_PRODUCT_CONST_EYE_REFLECT_CUBE_MAP_NV    0x86F3
#define GL_HILO_NV                                      0x86F4
#define GL_DSDT_NV                                      0x86F5
#define GL_DSDT_MAG_NV                                  0x86F6
#define GL_DSDT_MAG_VIB_NV                              0x86F7
#define GL_HILO16_NV                                    0x86F8
#define GL_SIGNED_HILO_NV                               0x86F9
#define GL_SIGNED_HILO16_NV                             0x86FA
#define GL_SIGNED_RGBA_NV                               0x86FB
#define GL_SIGNED_RGBA8_NV                              0x86FC
#define GL_SIGNED_RGB_NV                                0x86FE
#define GL_SIGNED_RGB8_NV                               0x86FF
#define GL_SIGNED_LUMINANCE_NV                          0x8701
#define GL_SIGNED_LUMINANCE8_NV                         0x8702
#define GL_SIGNED_LUMINANCE_ALPHA_NV                    0x8703
#define GL_SIGNED_LUMINANCE8_ALPHA8_NV                  0x8704
#define GL_SIGNED_ALPHA_NV                              0x8705
#define GL_SIGNED_ALPHA8_NV                             0x8706
#define GL_SIGNED_INTENSITY_NV                          0x8707
#define GL_SIGNED_INTENSITY8_NV                         0x8708
#define GL_DSDT8_NV                                     0x8709
#define GL_DSDT8_MAG8_NV                                0x870A
#define GL_DSDT8_MAG8_INTENSITY8_NV                     0x870B
#define GL_SIGNED_RGB_UNSIGNED_ALPHA_NV                 0x870C
#define GL_SIGNED_RGB8_UNSIGNED_ALPHA8_NV               0x870D
#define GL_HI_SCALE_NV                                  0x870E
#define GL_LO_SCALE_NV                                  0x870F
#define GL_DS_SCALE_NV                                  0x8710
#define GL_DT_SCALE_NV                                  0x8711
#define GL_MAGNITUDE_SCALE_NV                           0x8712
#define GL_VIBRANCE_SCALE_NV                            0x8713
#define GL_HI_BIAS_NV                                   0x8714
#define GL_LO_BIAS_NV                                   0x8715
#define GL_DS_BIAS_NV                                   0x8716
#define GL_DT_BIAS_NV                                   0x8717
#define GL_MAGNITUDE_BIAS_NV                            0x8718
#define GL_VIBRANCE_BIAS_NV                             0x8719
#define GL_TEXTURE_BORDER_VALUES_NV                     0x871A
#define GL_TEXTURE_HI_SIZE_NV                           0x871B
#define GL_TEXTURE_LO_SIZE_NV                           0x871C
#define GL_TEXTURE_DS_SIZE_NV                           0x871D
#define GL_TEXTURE_DT_SIZE_NV                           0x871E
#define GL_TEXTURE_MAG_SIZE_NV                          0x871F

#endif // GL_NV_texture_shader

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_texture_shader2
#define GL_NV_texture_shader2 1

#define GL_DOT_PRODUCT_TEXTURE_3D_NV    0x86EF

#endif // GL_NV_texture_shader2

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_texture_shader3
#define GL_NV_texture_shader3 1

#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_NV                 0x8850
#define GL_OFFSET_PROJECTIVE_TEXTURE_2D_SCALE_NV           0x8851
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_NV          0x8852
#define GL_OFFSET_PROJECTIVE_TEXTURE_RECTANGLE_SCALE_NV    0x8853
#define GL_OFFSET_HILO_TEXTURE_2D_NV                       0x8854
#define GL_OFFSET_HILO_TEXTURE_RECTANGLE_NV                0x8855
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_2D_NV            0x8856
#define GL_OFFSET_HILO_PROJECTIVE_TEXTURE_RECTANGLE_NV     0x8857
#define GL_DEPENDENT_HILO_TEXTURE_2D_NV                    0x8858
#define GL_DEPENDENT_RGB_TEXTURE_3D_NV                     0x8859
#define GL_DEPENDENT_RGB_TEXTURE_CUBE_MAP_NV               0x885A
#define GL_DOT_PRODUCT_PASS_THROUGH_NV                     0x885B
#define GL_DOT_PRODUCT_TEXTURE_1D_NV                       0x885C
#define GL_DOT_PRODUCT_AFFINE_DEPTH_REPLACE_NV             0x885D
#define GL_HILO8_NV                                        0x885E
#define GL_SIGNED_HILO8_NV                                 0x885F
#define GL_FORCE_BLUE_TO_ONE_NV                            0x8860

#endif // GL_NV_texture_shader3

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_transform_feedback

#ifndef GL_NV_transform_feedback
#define GL_NV_transform_feedback 1

#define GL_BACK_PRIMARY_COLOR_NV                               0x8C77
#define GL_BACK_SECONDARY_COLOR_NV                             0x8C78
#define GL_TEXTURE_COORD_NV                                    0x8C79
#define GL_CLIP_DISTANCE_NV                                    0x8C7A
#define GL_VERTEX_ID_NV                                        0x8C7B
#define GL_PRIMITIVE_ID_NV                                     0x8C7C
#define GL_GENERIC_ATTRIB_NV                                   0x8C7D
#define GL_TRANSFORM_FEEDBACK_ATTRIBS_NV                       0x8C7E
#define GL_TRANSFORM_FEEDBACK_BUFFER_MODE_NV                   0x8C7F
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_NV       0x8C80
#define GL_ACTIVE_VARYINGS_NV                                  0x8C81
#define GL_ACTIVE_VARYING_MAX_LENGTH_NV                        0x8C82
#define GL_TRANSFORM_FEEDBACK_VARYINGS_NV                      0x8C83
#define GL_TRANSFORM_FEEDBACK_BUFFER_START_NV                  0x8C84
#define GL_TRANSFORM_FEEDBACK_BUFFER_SIZE_NV                   0x8C85
#define GL_TRANSFORM_FEEDBACK_RECORD_NV                        0x8C86
#define GL_PRIMITIVES_GENERATED_NV                             0x8C87
#define GL_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN_NV            0x8C88
#define GL_RASTERIZER_DISCARD_NV                               0x8C89
#define GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_NV    0x8C8A
#define GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_NV          0x8C8B
#define GL_INTERLEAVED_ATTRIBS_NV                              0x8C8C
#define GL_SEPARATE_ATTRIBS_NV                                 0x8C8D
#define GL_TRANSFORM_FEEDBACK_BUFFER_NV                        0x8C8E
#define GL_TRANSFORM_FEEDBACK_BUFFER_BINDING_NV                0x8C8F
#define GL_LAYER_NV                                            0x8DAA
#define GL_NEXT_BUFFER_NV                                      -2
#define GL_SKIP_COMPONENTS4_NV                                 -3
#define GL_SKIP_COMPONENTS3_NV                                 -4
#define GL_SKIP_COMPONENTS2_NV                                 -5
#define GL_SKIP_COMPONENTS1_NV                                 -6

OPENGL_INIT_PROC(glBeginTransformFeedbackNV,         void,  GLenum primitiveMode);
OPENGL_INIT_PROC(glEndTransformFeedbackNV,           void,  void);
OPENGL_INIT_PROC(glTransformFeedbackAttribsNV,       void,  GLsizei count, const GLint *attribs, GLenum bufferMode);
OPENGL_INIT_PROC(glBindBufferRangeNV,                void,  GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
OPENGL_INIT_PROC(glBindBufferOffsetNV,               void,  GLenum target, GLuint index, GLuint buffer, GLintptr offset);
OPENGL_INIT_PROC(glBindBufferBaseNV,                 void,  GLenum target, GLuint index, GLuint buffer);
OPENGL_INIT_PROC(glTransformFeedbackVaryingsNV,      void,  GLuint program, GLsizei count, const GLint *locations, GLenum bufferMode);
OPENGL_INIT_PROC(glActiveVaryingNV,                  void,  GLuint program, const GLchar *name);
OPENGL_INIT_PROC(glGetVaryingLocationNV,             GLint, GLuint program, const GLchar *name);
OPENGL_INIT_PROC(glGetActiveVaryingNV,               void,  GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
OPENGL_INIT_PROC(glGetTransformFeedbackVaryingNV,    void,  GLuint program, GLuint index, GLint *location);
OPENGL_INIT_PROC(glTransformFeedbackStreamAttribsNV, void,  GLsizei count, const GLint *attribs, GLsizei nbuffers, const GLint *bufstreams, GLenum bufferMode);

#define glBeginTransformFeedbackNV         OGL__glBeginTransformFeedbackNV
#define glEndTransformFeedbackNV           OGL__glEndTransformFeedbackNV
#define glTransformFeedbackAttribsNV       OGL__glTransformFeedbackAttribsNV
#define glBindBufferRangeNV                OGL__glBindBufferRangeNV
#define glBindBufferOffsetNV               OGL__glBindBufferOffsetNV
#define glBindBufferBaseNV                 OGL__glBindBufferBaseNV
#define glTransformFeedbackVaryingsNV      OGL__glTransformFeedbackVaryingsNV
#define glActiveVaryingNV                  OGL__glActiveVaryingNV
#define glGetVaryingLocationNV             OGL__glGetVaryingLocationNV
#define glGetActiveVaryingNV               OGL__glGetActiveVaryingNV
#define glGetTransformFeedbackVaryingNV    OGL__glGetTransformFeedbackVaryingNV
#define glTransformFeedbackStreamAttribsNV OGL__glTransformFeedbackStreamAttribsNV

#endif // GL_NV_transform_feedback

#endif // OPENGL_INCLUDE_GL_NV_transform_feedback

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_transform_feedback2

#ifndef GL_NV_transform_feedback2
#define GL_NV_transform_feedback2 1

#define GL_TRANSFORM_FEEDBACK_NV                  0x8E22
#define GL_TRANSFORM_FEEDBACK_BUFFER_PAUSED_NV    0x8E23
#define GL_TRANSFORM_FEEDBACK_BUFFER_ACTIVE_NV    0x8E24
#define GL_TRANSFORM_FEEDBACK_BINDING_NV          0x8E25

OPENGL_INIT_PROC(glBindTransformFeedbackNV,    void,      GLenum target, GLuint id);
OPENGL_INIT_PROC(glDeleteTransformFeedbacksNV, void,      GLsizei n, const GLuint *ids);
OPENGL_INIT_PROC(glGenTransformFeedbacksNV,    void,      GLsizei n, GLuint *ids);
OPENGL_INIT_PROC(glIsTransformFeedbackNV,      GLboolean, GLuint id);
OPENGL_INIT_PROC(glPauseTransformFeedbackNV,   void,      void);
OPENGL_INIT_PROC(glResumeTransformFeedbackNV,  void,      void);
OPENGL_INIT_PROC(glDrawTransformFeedbackNV,    void,      GLenum mode, GLuint id);

#define glBindTransformFeedbackNV    OGL__glBindTransformFeedbackNV
#define glDeleteTransformFeedbacksNV OGL__glDeleteTransformFeedbacksNV
#define glGenTransformFeedbacksNV    OGL__glGenTransformFeedbacksNV
#define glIsTransformFeedbackNV      OGL__glIsTransformFeedbackNV
#define glPauseTransformFeedbackNV   OGL__glPauseTransformFeedbackNV
#define glResumeTransformFeedbackNV  OGL__glResumeTransformFeedbackNV
#define glDrawTransformFeedbackNV    OGL__glDrawTransformFeedbackNV

#endif // GL_NV_transform_feedback2

#endif // OPENGL_INCLUDE_GL_NV_transform_feedback2

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_uniform_buffer_unified_memory
#define GL_NV_uniform_buffer_unified_memory 1

#define GL_UNIFORM_BUFFER_UNIFIED_NV    0x936E
#define GL_UNIFORM_BUFFER_ADDRESS_NV    0x936F
#define GL_UNIFORM_BUFFER_LENGTH_NV     0x9370

#endif // GL_NV_uniform_buffer_unified_memory

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_vdpau_interop

#ifndef GL_NV_vdpau_interop
#define GL_NV_vdpau_interop 1

#define GL_SURFACE_STATE_NV         0x86EB
#define GL_SURFACE_REGISTERED_NV    0x86FD
#define GL_SURFACE_MAPPED_NV        0x8700
#define GL_WRITE_DISCARD_NV         0x88BE

OPENGL_INIT_PROC(glVDPAUInitNV,                  void,             const void *vdpDevice, const void *getProcAddress);
OPENGL_INIT_PROC(glVDPAUFiniNV,                  void,             void);
OPENGL_INIT_PROC(glVDPAURegisterVideoSurfaceNV,  GLvdpauSurfaceNV, const void *vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint *textureNames);
OPENGL_INIT_PROC(glVDPAURegisterOutputSurfaceNV, GLvdpauSurfaceNV, const void *vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint *textureNames);
OPENGL_INIT_PROC(glVDPAUIsSurfaceNV,             GLboolean,        GLvdpauSurfaceNV surface);
OPENGL_INIT_PROC(glVDPAUUnregisterSurfaceNV,     void,             GLvdpauSurfaceNV surface);
OPENGL_INIT_PROC(glVDPAUGetSurfaceivNV,          void,             GLvdpauSurfaceNV surface, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
OPENGL_INIT_PROC(glVDPAUSurfaceAccessNV,         void,             GLvdpauSurfaceNV surface, GLenum access);
OPENGL_INIT_PROC(glVDPAUMapSurfacesNV,           void,             GLsizei numSurfaces, const GLvdpauSurfaceNV *surfaces);
OPENGL_INIT_PROC(glVDPAUUnmapSurfacesNV,         void,             GLsizei numSurface, const GLvdpauSurfaceNV *surfaces);

#define glVDPAUInitNV                  OGL__glVDPAUInitNV
#define glVDPAUFiniNV                  OGL__glVDPAUFiniNV
#define glVDPAURegisterVideoSurfaceNV  OGL__glVDPAURegisterVideoSurfaceNV
#define glVDPAURegisterOutputSurfaceNV OGL__glVDPAURegisterOutputSurfaceNV
#define glVDPAUIsSurfaceNV             OGL__glVDPAUIsSurfaceNV
#define glVDPAUUnregisterSurfaceNV     OGL__glVDPAUUnregisterSurfaceNV
#define glVDPAUGetSurfaceivNV          OGL__glVDPAUGetSurfaceivNV
#define glVDPAUSurfaceAccessNV         OGL__glVDPAUSurfaceAccessNV
#define glVDPAUMapSurfacesNV           OGL__glVDPAUMapSurfacesNV
#define glVDPAUUnmapSurfacesNV         OGL__glVDPAUUnmapSurfacesNV

#endif // GL_NV_vdpau_interop

#endif // OPENGL_INCLUDE_GL_NV_vdpau_interop

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_vdpau_interop2

#ifndef GL_NV_vdpau_interop2
#define GL_NV_vdpau_interop2 1

OPENGL_INIT_PROC(glVDPAURegisterVideoSurfaceWithPictureStructureNV, GLvdpauSurfaceNV, const void *vdpSurface, GLenum target, GLsizei numTextureNames, const GLuint *textureNames, GLboolean isFrameStructure);
#define glVDPAURegisterVideoSurfaceWithPictureStructureNV OGL__glVDPAURegisterVideoSurfaceWithPictureStructureNV

#endif // GL_NV_vdpau_interop2

#endif // OPENGL_INCLUDE_GL_NV_vdpau_interop2

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_vertex_array_range

#ifndef GL_NV_vertex_array_range
#define GL_NV_vertex_array_range 1

#define GL_VERTEX_ARRAY_RANGE_NV                0x851D
#define GL_VERTEX_ARRAY_RANGE_LENGTH_NV         0x851E
#define GL_VERTEX_ARRAY_RANGE_VALID_NV          0x851F
#define GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_NV    0x8520
#define GL_VERTEX_ARRAY_RANGE_POINTER_NV        0x8521

OPENGL_INIT_PROC(glFlushVertexArrayRangeNV, void, void);
OPENGL_INIT_PROC(glVertexArrayRangeNV,      void, GLsizei length, const void *pointer);

#define glFlushVertexArrayRangeNV OGL__glFlushVertexArrayRangeNV
#define glVertexArrayRangeNV      OGL__glVertexArrayRangeNV

#endif // GL_NV_vertex_array_range

#endif // OPENGL_INCLUDE_GL_NV_vertex_array_range

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_vertex_array_range2
#define GL_NV_vertex_array_range2 1

#define GL_VERTEX_ARRAY_RANGE_WITHOUT_FLUSH_NV    0x8533

#endif // GL_NV_vertex_array_range2

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_vertex_attrib_integer_64bit

#ifndef GL_NV_vertex_attrib_integer_64bit
#define GL_NV_vertex_attrib_integer_64bit 1

OPENGL_INIT_PROC(glVertexAttribL1i64NV,     void, GLuint index, GLint64EXT x);
OPENGL_INIT_PROC(glVertexAttribL2i64NV,     void, GLuint index, GLint64EXT x, GLint64EXT y);
OPENGL_INIT_PROC(glVertexAttribL3i64NV,     void, GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z);
OPENGL_INIT_PROC(glVertexAttribL4i64NV,     void, GLuint index, GLint64EXT x, GLint64EXT y, GLint64EXT z, GLint64EXT w);
OPENGL_INIT_PROC(glVertexAttribL1i64vNV,    void, GLuint index, const GLint64EXT *v);
OPENGL_INIT_PROC(glVertexAttribL2i64vNV,    void, GLuint index, const GLint64EXT *v);
OPENGL_INIT_PROC(glVertexAttribL3i64vNV,    void, GLuint index, const GLint64EXT *v);
OPENGL_INIT_PROC(glVertexAttribL4i64vNV,    void, GLuint index, const GLint64EXT *v);
OPENGL_INIT_PROC(glVertexAttribL1ui64NV,    void, GLuint index, GLuint64EXT x);
OPENGL_INIT_PROC(glVertexAttribL2ui64NV,    void, GLuint index, GLuint64EXT x, GLuint64EXT y);
OPENGL_INIT_PROC(glVertexAttribL3ui64NV,    void, GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z);
OPENGL_INIT_PROC(glVertexAttribL4ui64NV,    void, GLuint index, GLuint64EXT x, GLuint64EXT y, GLuint64EXT z, GLuint64EXT w);
OPENGL_INIT_PROC(glVertexAttribL1ui64vNV,   void, GLuint index, const GLuint64EXT *v);
OPENGL_INIT_PROC(glVertexAttribL2ui64vNV,   void, GLuint index, const GLuint64EXT *v);
OPENGL_INIT_PROC(glVertexAttribL3ui64vNV,   void, GLuint index, const GLuint64EXT *v);
OPENGL_INIT_PROC(glVertexAttribL4ui64vNV,   void, GLuint index, const GLuint64EXT *v);
OPENGL_INIT_PROC(glGetVertexAttribLi64vNV,  void, GLuint index, GLenum pname, GLint64EXT *params);
OPENGL_INIT_PROC(glGetVertexAttribLui64vNV, void, GLuint index, GLenum pname, GLuint64EXT *params);
OPENGL_INIT_PROC(glVertexAttribLFormatNV,   void, GLuint index, GLint size, GLenum type, GLsizei stride);

#define glVertexAttribL1i64NV     OGL__glVertexAttribL1i64NV
#define glVertexAttribL2i64NV     OGL__glVertexAttribL2i64NV
#define glVertexAttribL3i64NV     OGL__glVertexAttribL3i64NV
#define glVertexAttribL4i64NV     OGL__glVertexAttribL4i64NV
#define glVertexAttribL1i64vNV    OGL__glVertexAttribL1i64vNV
#define glVertexAttribL2i64vNV    OGL__glVertexAttribL2i64vNV
#define glVertexAttribL3i64vNV    OGL__glVertexAttribL3i64vNV
#define glVertexAttribL4i64vNV    OGL__glVertexAttribL4i64vNV
#define glVertexAttribL1ui64NV    OGL__glVertexAttribL1ui64NV
#define glVertexAttribL2ui64NV    OGL__glVertexAttribL2ui64NV
#define glVertexAttribL3ui64NV    OGL__glVertexAttribL3ui64NV
#define glVertexAttribL4ui64NV    OGL__glVertexAttribL4ui64NV
#define glVertexAttribL1ui64vNV   OGL__glVertexAttribL1ui64vNV
#define glVertexAttribL2ui64vNV   OGL__glVertexAttribL2ui64vNV
#define glVertexAttribL3ui64vNV   OGL__glVertexAttribL3ui64vNV
#define glVertexAttribL4ui64vNV   OGL__glVertexAttribL4ui64vNV
#define glGetVertexAttribLi64vNV  OGL__glGetVertexAttribLi64vNV
#define glGetVertexAttribLui64vNV OGL__glGetVertexAttribLui64vNV
#define glVertexAttribLFormatNV   OGL__glVertexAttribLFormatNV

#endif // GL_NV_vertex_attrib_integer_64bit

#endif // OPENGL_INCLUDE_GL_NV_vertex_attrib_integer_64bit

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_vertex_buffer_unified_memory

#ifndef GL_NV_vertex_buffer_unified_memory
#define GL_NV_vertex_buffer_unified_memory 1

#define GL_VERTEX_ATTRIB_ARRAY_UNIFIED_NV      0x8F1E
#define GL_ELEMENT_ARRAY_UNIFIED_NV            0x8F1F
#define GL_VERTEX_ATTRIB_ARRAY_ADDRESS_NV      0x8F20
#define GL_VERTEX_ARRAY_ADDRESS_NV             0x8F21
#define GL_NORMAL_ARRAY_ADDRESS_NV             0x8F22
#define GL_COLOR_ARRAY_ADDRESS_NV              0x8F23
#define GL_INDEX_ARRAY_ADDRESS_NV              0x8F24
#define GL_TEXTURE_COORD_ARRAY_ADDRESS_NV      0x8F25
#define GL_EDGE_FLAG_ARRAY_ADDRESS_NV          0x8F26
#define GL_SECONDARY_COLOR_ARRAY_ADDRESS_NV    0x8F27
#define GL_FOG_COORD_ARRAY_ADDRESS_NV          0x8F28
#define GL_ELEMENT_ARRAY_ADDRESS_NV            0x8F29
#define GL_VERTEX_ATTRIB_ARRAY_LENGTH_NV       0x8F2A
#define GL_VERTEX_ARRAY_LENGTH_NV              0x8F2B
#define GL_NORMAL_ARRAY_LENGTH_NV              0x8F2C
#define GL_COLOR_ARRAY_LENGTH_NV               0x8F2D
#define GL_INDEX_ARRAY_LENGTH_NV               0x8F2E
#define GL_TEXTURE_COORD_ARRAY_LENGTH_NV       0x8F2F
#define GL_EDGE_FLAG_ARRAY_LENGTH_NV           0x8F30
#define GL_SECONDARY_COLOR_ARRAY_LENGTH_NV     0x8F31
#define GL_FOG_COORD_ARRAY_LENGTH_NV           0x8F32
#define GL_ELEMENT_ARRAY_LENGTH_NV             0x8F33
#define GL_DRAW_INDIRECT_UNIFIED_NV            0x8F40
#define GL_DRAW_INDIRECT_ADDRESS_NV            0x8F41
#define GL_DRAW_INDIRECT_LENGTH_NV             0x8F42

OPENGL_INIT_PROC(glBufferAddressRangeNV,   void, GLenum pname, GLuint index, GLuint64EXT address, GLsizeiptr length);
OPENGL_INIT_PROC(glVertexFormatNV,         void, GLint size, GLenum type, GLsizei stride);
OPENGL_INIT_PROC(glNormalFormatNV,         void, GLenum type, GLsizei stride);
OPENGL_INIT_PROC(glColorFormatNV,          void, GLint size, GLenum type, GLsizei stride);
OPENGL_INIT_PROC(glIndexFormatNV,          void, GLenum type, GLsizei stride);
OPENGL_INIT_PROC(glTexCoordFormatNV,       void, GLint size, GLenum type, GLsizei stride);
OPENGL_INIT_PROC(glEdgeFlagFormatNV,       void, GLsizei stride);
OPENGL_INIT_PROC(glSecondaryColorFormatNV, void, GLint size, GLenum type, GLsizei stride);
OPENGL_INIT_PROC(glFogCoordFormatNV,       void, GLenum type, GLsizei stride);
OPENGL_INIT_PROC(glVertexAttribFormatNV,   void, GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
OPENGL_INIT_PROC(glVertexAttribIFormatNV,  void, GLuint index, GLint size, GLenum type, GLsizei stride);
OPENGL_INIT_PROC(glGetIntegerui64i_vNV,    void, GLenum value, GLuint index, GLuint64EXT *result);

#define glBufferAddressRangeNV   OGL__glBufferAddressRangeNV
#define glVertexFormatNV         OGL__glVertexFormatNV
#define glNormalFormatNV         OGL__glNormalFormatNV
#define glColorFormatNV          OGL__glColorFormatNV
#define glIndexFormatNV          OGL__glIndexFormatNV
#define glTexCoordFormatNV       OGL__glTexCoordFormatNV
#define glEdgeFlagFormatNV       OGL__glEdgeFlagFormatNV
#define glSecondaryColorFormatNV OGL__glSecondaryColorFormatNV
#define glFogCoordFormatNV       OGL__glFogCoordFormatNV
#define glVertexAttribFormatNV   OGL__glVertexAttribFormatNV
#define glVertexAttribIFormatNV  OGL__glVertexAttribIFormatNV
#define glGetIntegerui64i_vNV    OGL__glGetIntegerui64i_vNV

#endif // GL_NV_vertex_buffer_unified_memory

#endif // OPENGL_INCLUDE_GL_NV_vertex_buffer_unified_memory

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_vertex_program

#ifndef GL_NV_vertex_program
#define GL_NV_vertex_program 1

#define GL_VERTEX_PROGRAM_NV                  0x8620
#define GL_VERTEX_STATE_PROGRAM_NV            0x8621
#define GL_ATTRIB_ARRAY_SIZE_NV               0x8623
#define GL_ATTRIB_ARRAY_STRIDE_NV             0x8624
#define GL_ATTRIB_ARRAY_TYPE_NV               0x8625
#define GL_CURRENT_ATTRIB_NV                  0x8626
#define GL_PROGRAM_LENGTH_NV                  0x8627
#define GL_PROGRAM_STRING_NV                  0x8628
#define GL_MODELVIEW_PROJECTION_NV            0x8629
#define GL_IDENTITY_NV                        0x862A
#define GL_INVERSE_NV                         0x862B
#define GL_TRANSPOSE_NV                       0x862C
#define GL_INVERSE_TRANSPOSE_NV               0x862D
#define GL_MAX_TRACK_MATRIX_STACK_DEPTH_NV    0x862E
#define GL_MAX_TRACK_MATRICES_NV              0x862F
#define GL_MATRIX0_NV                         0x8630
#define GL_MATRIX1_NV                         0x8631
#define GL_MATRIX2_NV                         0x8632
#define GL_MATRIX3_NV                         0x8633
#define GL_MATRIX4_NV                         0x8634
#define GL_MATRIX5_NV                         0x8635
#define GL_MATRIX6_NV                         0x8636
#define GL_MATRIX7_NV                         0x8637
#define GL_CURRENT_MATRIX_STACK_DEPTH_NV      0x8640
#define GL_CURRENT_MATRIX_NV                  0x8641
#define GL_VERTEX_PROGRAM_POINT_SIZE_NV       0x8642
#define GL_VERTEX_PROGRAM_TWO_SIDE_NV         0x8643
#define GL_PROGRAM_PARAMETER_NV               0x8644
#define GL_ATTRIB_ARRAY_POINTER_NV            0x8645
#define GL_PROGRAM_TARGET_NV                  0x8646
#define GL_PROGRAM_RESIDENT_NV                0x8647
#define GL_TRACK_MATRIX_NV                    0x8648
#define GL_TRACK_MATRIX_TRANSFORM_NV          0x8649
#define GL_VERTEX_PROGRAM_BINDING_NV          0x864A
#define GL_PROGRAM_ERROR_POSITION_NV          0x864B
#define GL_VERTEX_ATTRIB_ARRAY0_NV            0x8650
#define GL_VERTEX_ATTRIB_ARRAY1_NV            0x8651
#define GL_VERTEX_ATTRIB_ARRAY2_NV            0x8652
#define GL_VERTEX_ATTRIB_ARRAY3_NV            0x8653
#define GL_VERTEX_ATTRIB_ARRAY4_NV            0x8654
#define GL_VERTEX_ATTRIB_ARRAY5_NV            0x8655
#define GL_VERTEX_ATTRIB_ARRAY6_NV            0x8656
#define GL_VERTEX_ATTRIB_ARRAY7_NV            0x8657
#define GL_VERTEX_ATTRIB_ARRAY8_NV            0x8658
#define GL_VERTEX_ATTRIB_ARRAY9_NV            0x8659
#define GL_VERTEX_ATTRIB_ARRAY10_NV           0x865A
#define GL_VERTEX_ATTRIB_ARRAY11_NV           0x865B
#define GL_VERTEX_ATTRIB_ARRAY12_NV           0x865C
#define GL_VERTEX_ATTRIB_ARRAY13_NV           0x865D
#define GL_VERTEX_ATTRIB_ARRAY14_NV           0x865E
#define GL_VERTEX_ATTRIB_ARRAY15_NV           0x865F
#define GL_MAP1_VERTEX_ATTRIB0_4_NV           0x8660
#define GL_MAP1_VERTEX_ATTRIB1_4_NV           0x8661
#define GL_MAP1_VERTEX_ATTRIB2_4_NV           0x8662
#define GL_MAP1_VERTEX_ATTRIB3_4_NV           0x8663
#define GL_MAP1_VERTEX_ATTRIB4_4_NV           0x8664
#define GL_MAP1_VERTEX_ATTRIB5_4_NV           0x8665
#define GL_MAP1_VERTEX_ATTRIB6_4_NV           0x8666
#define GL_MAP1_VERTEX_ATTRIB7_4_NV           0x8667
#define GL_MAP1_VERTEX_ATTRIB8_4_NV           0x8668
#define GL_MAP1_VERTEX_ATTRIB9_4_NV           0x8669
#define GL_MAP1_VERTEX_ATTRIB10_4_NV          0x866A
#define GL_MAP1_VERTEX_ATTRIB11_4_NV          0x866B
#define GL_MAP1_VERTEX_ATTRIB12_4_NV          0x866C
#define GL_MAP1_VERTEX_ATTRIB13_4_NV          0x866D
#define GL_MAP1_VERTEX_ATTRIB14_4_NV          0x866E
#define GL_MAP1_VERTEX_ATTRIB15_4_NV          0x866F
#define GL_MAP2_VERTEX_ATTRIB0_4_NV           0x8670
#define GL_MAP2_VERTEX_ATTRIB1_4_NV           0x8671
#define GL_MAP2_VERTEX_ATTRIB2_4_NV           0x8672
#define GL_MAP2_VERTEX_ATTRIB3_4_NV           0x8673
#define GL_MAP2_VERTEX_ATTRIB4_4_NV           0x8674
#define GL_MAP2_VERTEX_ATTRIB5_4_NV           0x8675
#define GL_MAP2_VERTEX_ATTRIB6_4_NV           0x8676
#define GL_MAP2_VERTEX_ATTRIB7_4_NV           0x8677
#define GL_MAP2_VERTEX_ATTRIB8_4_NV           0x8678
#define GL_MAP2_VERTEX_ATTRIB9_4_NV           0x8679
#define GL_MAP2_VERTEX_ATTRIB10_4_NV          0x867A
#define GL_MAP2_VERTEX_ATTRIB11_4_NV          0x867B
#define GL_MAP2_VERTEX_ATTRIB12_4_NV          0x867C
#define GL_MAP2_VERTEX_ATTRIB13_4_NV          0x867D
#define GL_MAP2_VERTEX_ATTRIB14_4_NV          0x867E
#define GL_MAP2_VERTEX_ATTRIB15_4_NV          0x867F

OPENGL_INIT_PROC(glAreProgramsResidentNV,     GLboolean, GLsizei n, const GLuint *programs, GLboolean *residences);
OPENGL_INIT_PROC(glBindProgramNV,             void,      GLenum target, GLuint id);
OPENGL_INIT_PROC(glDeleteProgramsNV,          void,      GLsizei n, const GLuint *programs);
OPENGL_INIT_PROC(glExecuteProgramNV,          void,      GLenum target, GLuint id, const GLfloat *params);
OPENGL_INIT_PROC(glGenProgramsNV,             void,      GLsizei n, GLuint *programs);
OPENGL_INIT_PROC(glGetProgramParameterdvNV,   void,      GLenum target, GLuint index, GLenum pname, GLdouble *params);
OPENGL_INIT_PROC(glGetProgramParameterfvNV,   void,      GLenum target, GLuint index, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetProgramivNV,            void,      GLuint id, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetProgramStringNV,        void,      GLuint id, GLenum pname, GLubyte *program);
OPENGL_INIT_PROC(glGetTrackMatrixivNV,        void,      GLenum target, GLuint address, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetVertexAttribdvNV,       void,      GLuint index, GLenum pname, GLdouble *params);
OPENGL_INIT_PROC(glGetVertexAttribfvNV,       void,      GLuint index, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetVertexAttribivNV,       void,      GLuint index, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetVertexAttribPointervNV, void,      GLuint index, GLenum pname, void **pointer);
OPENGL_INIT_PROC(glIsProgramNV,               GLboolean, GLuint id);
OPENGL_INIT_PROC(glLoadProgramNV,             void,      GLenum target, GLuint id, GLsizei len, const GLubyte *program);
OPENGL_INIT_PROC(glProgramParameter4dNV,      void,      GLenum target, GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
OPENGL_INIT_PROC(glProgramParameter4dvNV,     void,      GLenum target, GLuint index, const GLdouble *v);
OPENGL_INIT_PROC(glProgramParameter4fNV,      void,      GLenum target, GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
OPENGL_INIT_PROC(glProgramParameter4fvNV,     void,      GLenum target, GLuint index, const GLfloat *v);
OPENGL_INIT_PROC(glProgramParameters4dvNV,    void,      GLenum target, GLuint index, GLsizei count, const GLdouble *v);
OPENGL_INIT_PROC(glProgramParameters4fvNV,    void,      GLenum target, GLuint index, GLsizei count, const GLfloat *v);
OPENGL_INIT_PROC(glRequestResidentProgramsNV, void,      GLsizei n, const GLuint *programs);
OPENGL_INIT_PROC(glTrackMatrixNV,             void,      GLenum target, GLuint address, GLenum matrix, GLenum transform);
OPENGL_INIT_PROC(glVertexAttribPointerNV,     void,      GLuint index, GLint fsize, GLenum type, GLsizei stride, const void *pointer);
OPENGL_INIT_PROC(glVertexAttrib1dNV,          void,      GLuint index, GLdouble x);
OPENGL_INIT_PROC(glVertexAttrib1dvNV,         void,      GLuint index, const GLdouble *v);
OPENGL_INIT_PROC(glVertexAttrib1fNV,          void,      GLuint index, GLfloat x);
OPENGL_INIT_PROC(glVertexAttrib1fvNV,         void,      GLuint index, const GLfloat *v);
OPENGL_INIT_PROC(glVertexAttrib1sNV,          void,      GLuint index, GLshort x);
OPENGL_INIT_PROC(glVertexAttrib1svNV,         void,      GLuint index, const GLshort *v);
OPENGL_INIT_PROC(glVertexAttrib2dNV,          void,      GLuint index, GLdouble x, GLdouble y);
OPENGL_INIT_PROC(glVertexAttrib2dvNV,         void,      GLuint index, const GLdouble *v);
OPENGL_INIT_PROC(glVertexAttrib2fNV,          void,      GLuint index, GLfloat x, GLfloat y);
OPENGL_INIT_PROC(glVertexAttrib2fvNV,         void,      GLuint index, const GLfloat *v);
OPENGL_INIT_PROC(glVertexAttrib2sNV,          void,      GLuint index, GLshort x, GLshort y);
OPENGL_INIT_PROC(glVertexAttrib2svNV,         void,      GLuint index, const GLshort *v);
OPENGL_INIT_PROC(glVertexAttrib3dNV,          void,      GLuint index, GLdouble x, GLdouble y, GLdouble z);
OPENGL_INIT_PROC(glVertexAttrib3dvNV,         void,      GLuint index, const GLdouble *v);
OPENGL_INIT_PROC(glVertexAttrib3fNV,          void,      GLuint index, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glVertexAttrib3fvNV,         void,      GLuint index, const GLfloat *v);
OPENGL_INIT_PROC(glVertexAttrib3sNV,          void,      GLuint index, GLshort x, GLshort y, GLshort z);
OPENGL_INIT_PROC(glVertexAttrib3svNV,         void,      GLuint index, const GLshort *v);
OPENGL_INIT_PROC(glVertexAttrib4dNV,          void,      GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
OPENGL_INIT_PROC(glVertexAttrib4dvNV,         void,      GLuint index, const GLdouble *v);
OPENGL_INIT_PROC(glVertexAttrib4fNV,          void,      GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
OPENGL_INIT_PROC(glVertexAttrib4fvNV,         void,      GLuint index, const GLfloat *v);
OPENGL_INIT_PROC(glVertexAttrib4sNV,          void,      GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
OPENGL_INIT_PROC(glVertexAttrib4svNV,         void,      GLuint index, const GLshort *v);
OPENGL_INIT_PROC(glVertexAttrib4ubNV,         void,      GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
OPENGL_INIT_PROC(glVertexAttrib4ubvNV,        void,      GLuint index, const GLubyte *v);
OPENGL_INIT_PROC(glVertexAttribs1dvNV,        void,      GLuint index, GLsizei count, const GLdouble *v);
OPENGL_INIT_PROC(glVertexAttribs1fvNV,        void,      GLuint index, GLsizei count, const GLfloat *v);
OPENGL_INIT_PROC(glVertexAttribs1svNV,        void,      GLuint index, GLsizei count, const GLshort *v);
OPENGL_INIT_PROC(glVertexAttribs2dvNV,        void,      GLuint index, GLsizei count, const GLdouble *v);
OPENGL_INIT_PROC(glVertexAttribs2fvNV,        void,      GLuint index, GLsizei count, const GLfloat *v);
OPENGL_INIT_PROC(glVertexAttribs2svNV,        void,      GLuint index, GLsizei count, const GLshort *v);
OPENGL_INIT_PROC(glVertexAttribs3dvNV,        void,      GLuint index, GLsizei count, const GLdouble *v);
OPENGL_INIT_PROC(glVertexAttribs3fvNV,        void,      GLuint index, GLsizei count, const GLfloat *v);
OPENGL_INIT_PROC(glVertexAttribs3svNV,        void,      GLuint index, GLsizei count, const GLshort *v);
OPENGL_INIT_PROC(glVertexAttribs4dvNV,        void,      GLuint index, GLsizei count, const GLdouble *v);
OPENGL_INIT_PROC(glVertexAttribs4fvNV,        void,      GLuint index, GLsizei count, const GLfloat *v);
OPENGL_INIT_PROC(glVertexAttribs4svNV,        void,      GLuint index, GLsizei count, const GLshort *v);
OPENGL_INIT_PROC(glVertexAttribs4ubvNV,       void,      GLuint index, GLsizei count, const GLubyte *v);

#define glAreProgramsResidentNV     OGL__glAreProgramsResidentNV
#define glBindProgramNV             OGL__glBindProgramNV
#define glDeleteProgramsNV          OGL__glDeleteProgramsNV
#define glExecuteProgramNV          OGL__glExecuteProgramNV
#define glGenProgramsNV             OGL__glGenProgramsNV
#define glGetProgramParameterdvNV   OGL__glGetProgramParameterdvNV
#define glGetProgramParameterfvNV   OGL__glGetProgramParameterfvNV
#define glGetProgramivNV            OGL__glGetProgramivNV
#define glGetProgramStringNV        OGL__glGetProgramStringNV
#define glGetTrackMatrixivNV        OGL__glGetTrackMatrixivNV
#define glGetVertexAttribdvNV       OGL__glGetVertexAttribdvNV
#define glGetVertexAttribfvNV       OGL__glGetVertexAttribfvNV
#define glGetVertexAttribivNV       OGL__glGetVertexAttribivNV
#define glGetVertexAttribPointervNV OGL__glGetVertexAttribPointervNV
#define glIsProgramNV               OGL__glIsProgramNV
#define glLoadProgramNV             OGL__glLoadProgramNV
#define glProgramParameter4dNV      OGL__glProgramParameter4dNV
#define glProgramParameter4dvNV     OGL__glProgramParameter4dvNV
#define glProgramParameter4fNV      OGL__glProgramParameter4fNV
#define glProgramParameter4fvNV     OGL__glProgramParameter4fvNV
#define glProgramParameters4dvNV    OGL__glProgramParameters4dvNV
#define glProgramParameters4fvNV    OGL__glProgramParameters4fvNV
#define glRequestResidentProgramsNV OGL__glRequestResidentProgramsNV
#define glTrackMatrixNV             OGL__glTrackMatrixNV
#define glVertexAttribPointerNV     OGL__glVertexAttribPointerNV
#define glVertexAttrib1dNV          OGL__glVertexAttrib1dNV
#define glVertexAttrib1dvNV         OGL__glVertexAttrib1dvNV
#define glVertexAttrib1fNV          OGL__glVertexAttrib1fNV
#define glVertexAttrib1fvNV         OGL__glVertexAttrib1fvNV
#define glVertexAttrib1sNV          OGL__glVertexAttrib1sNV
#define glVertexAttrib1svNV         OGL__glVertexAttrib1svNV
#define glVertexAttrib2dNV          OGL__glVertexAttrib2dNV
#define glVertexAttrib2dvNV         OGL__glVertexAttrib2dvNV
#define glVertexAttrib2fNV          OGL__glVertexAttrib2fNV
#define glVertexAttrib2fvNV         OGL__glVertexAttrib2fvNV
#define glVertexAttrib2sNV          OGL__glVertexAttrib2sNV
#define glVertexAttrib2svNV         OGL__glVertexAttrib2svNV
#define glVertexAttrib3dNV          OGL__glVertexAttrib3dNV
#define glVertexAttrib3dvNV         OGL__glVertexAttrib3dvNV
#define glVertexAttrib3fNV          OGL__glVertexAttrib3fNV
#define glVertexAttrib3fvNV         OGL__glVertexAttrib3fvNV
#define glVertexAttrib3sNV          OGL__glVertexAttrib3sNV
#define glVertexAttrib3svNV         OGL__glVertexAttrib3svNV
#define glVertexAttrib4dNV          OGL__glVertexAttrib4dNV
#define glVertexAttrib4dvNV         OGL__glVertexAttrib4dvNV
#define glVertexAttrib4fNV          OGL__glVertexAttrib4fNV
#define glVertexAttrib4fvNV         OGL__glVertexAttrib4fvNV
#define glVertexAttrib4sNV          OGL__glVertexAttrib4sNV
#define glVertexAttrib4svNV         OGL__glVertexAttrib4svNV
#define glVertexAttrib4ubNV         OGL__glVertexAttrib4ubNV
#define glVertexAttrib4ubvNV        OGL__glVertexAttrib4ubvNV
#define glVertexAttribs1dvNV        OGL__glVertexAttribs1dvNV
#define glVertexAttribs1fvNV        OGL__glVertexAttribs1fvNV
#define glVertexAttribs1svNV        OGL__glVertexAttribs1svNV
#define glVertexAttribs2dvNV        OGL__glVertexAttribs2dvNV
#define glVertexAttribs2fvNV        OGL__glVertexAttribs2fvNV
#define glVertexAttribs2svNV        OGL__glVertexAttribs2svNV
#define glVertexAttribs3dvNV        OGL__glVertexAttribs3dvNV
#define glVertexAttribs3fvNV        OGL__glVertexAttribs3fvNV
#define glVertexAttribs3svNV        OGL__glVertexAttribs3svNV
#define glVertexAttribs4dvNV        OGL__glVertexAttribs4dvNV
#define glVertexAttribs4fvNV        OGL__glVertexAttribs4fvNV
#define glVertexAttribs4svNV        OGL__glVertexAttribs4svNV
#define glVertexAttribs4ubvNV       OGL__glVertexAttribs4ubvNV

#endif // GL_NV_vertex_program

#endif // OPENGL_INCLUDE_GL_NV_vertex_program

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_vertex_program1_1
#define GL_NV_vertex_program1_1 1

#endif // GL_NV_vertex_program1_1

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_vertex_program2
#define GL_NV_vertex_program2 1

#endif // GL_NV_vertex_program2

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_vertex_program2_option
#define GL_NV_vertex_program2_option 1

#endif // GL_NV_vertex_program2_option

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_vertex_program3
#define GL_NV_vertex_program3 1

#endif // GL_NV_vertex_program3

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_vertex_program4

#ifndef GL_NV_vertex_program4
#define GL_NV_vertex_program4 1

#define GL_VERTEX_ATTRIB_ARRAY_INTEGER_NV    0x88FD

OPENGL_INIT_PROC(glVertexAttribI1iEXT,      void, GLuint index, GLint x);
OPENGL_INIT_PROC(glVertexAttribI2iEXT,      void, GLuint index, GLint x, GLint y);
OPENGL_INIT_PROC(glVertexAttribI3iEXT,      void, GLuint index, GLint x, GLint y, GLint z);
OPENGL_INIT_PROC(glVertexAttribI4iEXT,      void, GLuint index, GLint x, GLint y, GLint z, GLint w);
OPENGL_INIT_PROC(glVertexAttribI1uiEXT,     void, GLuint index, GLuint x);
OPENGL_INIT_PROC(glVertexAttribI2uiEXT,     void, GLuint index, GLuint x, GLuint y);
OPENGL_INIT_PROC(glVertexAttribI3uiEXT,     void, GLuint index, GLuint x, GLuint y, GLuint z);
OPENGL_INIT_PROC(glVertexAttribI4uiEXT,     void, GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
OPENGL_INIT_PROC(glVertexAttribI1ivEXT,     void, GLuint index, const GLint *v);
OPENGL_INIT_PROC(glVertexAttribI2ivEXT,     void, GLuint index, const GLint *v);
OPENGL_INIT_PROC(glVertexAttribI3ivEXT,     void, GLuint index, const GLint *v);
OPENGL_INIT_PROC(glVertexAttribI4ivEXT,     void, GLuint index, const GLint *v);
OPENGL_INIT_PROC(glVertexAttribI1uivEXT,    void, GLuint index, const GLuint *v);
OPENGL_INIT_PROC(glVertexAttribI2uivEXT,    void, GLuint index, const GLuint *v);
OPENGL_INIT_PROC(glVertexAttribI3uivEXT,    void, GLuint index, const GLuint *v);
OPENGL_INIT_PROC(glVertexAttribI4uivEXT,    void, GLuint index, const GLuint *v);
OPENGL_INIT_PROC(glVertexAttribI4bvEXT,     void, GLuint index, const GLbyte *v);
OPENGL_INIT_PROC(glVertexAttribI4svEXT,     void, GLuint index, const GLshort *v);
OPENGL_INIT_PROC(glVertexAttribI4ubvEXT,    void, GLuint index, const GLubyte *v);
OPENGL_INIT_PROC(glVertexAttribI4usvEXT,    void, GLuint index, const GLushort *v);
OPENGL_INIT_PROC(glVertexAttribIPointerEXT, void, GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
OPENGL_INIT_PROC(glGetVertexAttribIivEXT,   void, GLuint index, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetVertexAttribIuivEXT,  void, GLuint index, GLenum pname, GLuint *params);

#define glVertexAttribI1iEXT      OGL__glVertexAttribI1iEXT
#define glVertexAttribI2iEXT      OGL__glVertexAttribI2iEXT
#define glVertexAttribI3iEXT      OGL__glVertexAttribI3iEXT
#define glVertexAttribI4iEXT      OGL__glVertexAttribI4iEXT
#define glVertexAttribI1uiEXT     OGL__glVertexAttribI1uiEXT
#define glVertexAttribI2uiEXT     OGL__glVertexAttribI2uiEXT
#define glVertexAttribI3uiEXT     OGL__glVertexAttribI3uiEXT
#define glVertexAttribI4uiEXT     OGL__glVertexAttribI4uiEXT
#define glVertexAttribI1ivEXT     OGL__glVertexAttribI1ivEXT
#define glVertexAttribI2ivEXT     OGL__glVertexAttribI2ivEXT
#define glVertexAttribI3ivEXT     OGL__glVertexAttribI3ivEXT
#define glVertexAttribI4ivEXT     OGL__glVertexAttribI4ivEXT
#define glVertexAttribI1uivEXT    OGL__glVertexAttribI1uivEXT
#define glVertexAttribI2uivEXT    OGL__glVertexAttribI2uivEXT
#define glVertexAttribI3uivEXT    OGL__glVertexAttribI3uivEXT
#define glVertexAttribI4uivEXT    OGL__glVertexAttribI4uivEXT
#define glVertexAttribI4bvEXT     OGL__glVertexAttribI4bvEXT
#define glVertexAttribI4svEXT     OGL__glVertexAttribI4svEXT
#define glVertexAttribI4ubvEXT    OGL__glVertexAttribI4ubvEXT
#define glVertexAttribI4usvEXT    OGL__glVertexAttribI4usvEXT
#define glVertexAttribIPointerEXT OGL__glVertexAttribIPointerEXT
#define glGetVertexAttribIivEXT   OGL__glGetVertexAttribIivEXT
#define glGetVertexAttribIuivEXT  OGL__glGetVertexAttribIuivEXT

#endif // GL_NV_vertex_program4

#endif // OPENGL_INCLUDE_GL_NV_vertex_program4

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_video_capture

#ifndef GL_NV_video_capture
#define GL_NV_video_capture 1

#define GL_VIDEO_BUFFER_NV                             0x9020
#define GL_VIDEO_BUFFER_BINDING_NV                     0x9021
#define GL_FIELD_UPPER_NV                              0x9022
#define GL_FIELD_LOWER_NV                              0x9023
#define GL_NUM_VIDEO_CAPTURE_STREAMS_NV                0x9024
#define GL_NEXT_VIDEO_CAPTURE_BUFFER_STATUS_NV         0x9025
#define GL_VIDEO_CAPTURE_TO_422_SUPPORTED_NV           0x9026
#define GL_LAST_VIDEO_CAPTURE_STATUS_NV                0x9027
#define GL_VIDEO_BUFFER_PITCH_NV                       0x9028
#define GL_VIDEO_COLOR_CONVERSION_MATRIX_NV            0x9029
#define GL_VIDEO_COLOR_CONVERSION_MAX_NV               0x902A
#define GL_VIDEO_COLOR_CONVERSION_MIN_NV               0x902B
#define GL_VIDEO_COLOR_CONVERSION_OFFSET_NV            0x902C
#define GL_VIDEO_BUFFER_INTERNAL_FORMAT_NV             0x902D
#define GL_PARTIAL_SUCCESS_NV                          0x902E
#define GL_SUCCESS_NV                                  0x902F
#define GL_FAILURE_NV                                  0x9030
#define GL_YCBYCR8_422_NV                              0x9031
#define GL_YCBAYCR8A_4224_NV                           0x9032
#define GL_Z6Y10Z6CB10Z6Y10Z6CR10_422_NV               0x9033
#define GL_Z6Y10Z6CB10Z6A10Z6Y10Z6CR10Z6A10_4224_NV    0x9034
#define GL_Z4Y12Z4CB12Z4Y12Z4CR12_422_NV               0x9035
#define GL_Z4Y12Z4CB12Z4A12Z4Y12Z4CR12Z4A12_4224_NV    0x9036
#define GL_Z4Y12Z4CB12Z4CR12_444_NV                    0x9037
#define GL_VIDEO_CAPTURE_FRAME_WIDTH_NV                0x9038
#define GL_VIDEO_CAPTURE_FRAME_HEIGHT_NV               0x9039
#define GL_VIDEO_CAPTURE_FIELD_UPPER_HEIGHT_NV         0x903A
#define GL_VIDEO_CAPTURE_FIELD_LOWER_HEIGHT_NV         0x903B
#define GL_VIDEO_CAPTURE_SURFACE_ORIGIN_NV             0x903C

OPENGL_INIT_PROC(glBeginVideoCaptureNV,             void,   GLuint video_capture_slot);
OPENGL_INIT_PROC(glBindVideoCaptureStreamBufferNV,  void,   GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLintptrARB offset);
OPENGL_INIT_PROC(glBindVideoCaptureStreamTextureNV, void,   GLuint video_capture_slot, GLuint stream, GLenum frame_region, GLenum target, GLuint texture);
OPENGL_INIT_PROC(glEndVideoCaptureNV,               void,   GLuint video_capture_slot);
OPENGL_INIT_PROC(glGetVideoCaptureivNV,             void,   GLuint video_capture_slot, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetVideoCaptureStreamivNV,       void,   GLuint video_capture_slot, GLuint stream, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetVideoCaptureStreamfvNV,       void,   GLuint video_capture_slot, GLuint stream, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetVideoCaptureStreamdvNV,       void,   GLuint video_capture_slot, GLuint stream, GLenum pname, GLdouble *params);
OPENGL_INIT_PROC(glVideoCaptureNV,                  GLenum, GLuint video_capture_slot, GLuint *sequence_num, GLuint64EXT *capture_time);
OPENGL_INIT_PROC(glVideoCaptureStreamParameterivNV, void,   GLuint video_capture_slot, GLuint stream, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glVideoCaptureStreamParameterfvNV, void,   GLuint video_capture_slot, GLuint stream, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glVideoCaptureStreamParameterdvNV, void,   GLuint video_capture_slot, GLuint stream, GLenum pname, const GLdouble *params);

#define glBeginVideoCaptureNV             OGL__glBeginVideoCaptureNV
#define glBindVideoCaptureStreamBufferNV  OGL__glBindVideoCaptureStreamBufferNV
#define glBindVideoCaptureStreamTextureNV OGL__glBindVideoCaptureStreamTextureNV
#define glEndVideoCaptureNV               OGL__glEndVideoCaptureNV
#define glGetVideoCaptureivNV             OGL__glGetVideoCaptureivNV
#define glGetVideoCaptureStreamivNV       OGL__glGetVideoCaptureStreamivNV
#define glGetVideoCaptureStreamfvNV       OGL__glGetVideoCaptureStreamfvNV
#define glGetVideoCaptureStreamdvNV       OGL__glGetVideoCaptureStreamdvNV
#define glVideoCaptureNV                  OGL__glVideoCaptureNV
#define glVideoCaptureStreamParameterivNV OGL__glVideoCaptureStreamParameterivNV
#define glVideoCaptureStreamParameterfvNV OGL__glVideoCaptureStreamParameterfvNV
#define glVideoCaptureStreamParameterdvNV OGL__glVideoCaptureStreamParameterdvNV

#endif // GL_NV_video_capture

#endif // OPENGL_INCLUDE_GL_NV_video_capture

/* -------------------------------------------------------------------------- */

#ifndef GL_NV_viewport_array2
#define GL_NV_viewport_array2 1

#endif // GL_NV_viewport_array2

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_NV_viewport_swizzle

#ifndef GL_NV_viewport_swizzle
#define GL_NV_viewport_swizzle 1

#define GL_VIEWPORT_SWIZZLE_POSITIVE_X_NV    0x9350
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_X_NV    0x9351
#define GL_VIEWPORT_SWIZZLE_POSITIVE_Y_NV    0x9352
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_Y_NV    0x9353
#define GL_VIEWPORT_SWIZZLE_POSITIVE_Z_NV    0x9354
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_Z_NV    0x9355
#define GL_VIEWPORT_SWIZZLE_POSITIVE_W_NV    0x9356
#define GL_VIEWPORT_SWIZZLE_NEGATIVE_W_NV    0x9357
#define GL_VIEWPORT_SWIZZLE_X_NV             0x9358
#define GL_VIEWPORT_SWIZZLE_Y_NV             0x9359
#define GL_VIEWPORT_SWIZZLE_Z_NV             0x935A
#define GL_VIEWPORT_SWIZZLE_W_NV             0x935B

OPENGL_INIT_PROC(glViewportSwizzleNV, void, GLuint index, GLenum swizzlex, GLenum swizzley, GLenum swizzlez, GLenum swizzlew);
#define glViewportSwizzleNV OGL__glViewportSwizzleNV

#endif // GL_NV_viewport_swizzle

#endif // OPENGL_INCLUDE_GL_NV_viewport_swizzle

/* -------------------------------------------------------------------------- */

#ifndef GL_OML_interlace
#define GL_OML_interlace 1

#define GL_INTERLACE_OML         0x8980
#define GL_INTERLACE_READ_OML    0x8981

#endif // GL_OML_interlace

/* -------------------------------------------------------------------------- */

#ifndef GL_OML_resample
#define GL_OML_resample 1

#define GL_PACK_RESAMPLE_OML         0x8984
#define GL_UNPACK_RESAMPLE_OML       0x8985
#define GL_RESAMPLE_REPLICATE_OML    0x8986
#define GL_RESAMPLE_ZERO_FILL_OML    0x8987
#define GL_RESAMPLE_AVERAGE_OML      0x8988
#define GL_RESAMPLE_DECIMATE_OML     0x8989

#endif // GL_OML_resample

/* -------------------------------------------------------------------------- */

#ifndef GL_OML_subsample
#define GL_OML_subsample 1

#define GL_FORMAT_SUBSAMPLE_24_24_OML      0x8982
#define GL_FORMAT_SUBSAMPLE_244_244_OML    0x8983

#endif // GL_OML_subsample

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_OVR_multiview

#ifndef GL_OVR_multiview
#define GL_OVR_multiview 1

#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_NUM_VIEWS_OVR          0x9630
#define GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_BASE_VIEW_INDEX_OVR    0x9632
#define GL_MAX_VIEWS_OVR                                         0x9631
#define GL_FRAMEBUFFER_INCOMPLETE_VIEW_TARGETS_OVR               0x9633

OPENGL_INIT_PROC(glFramebufferTextureMultiviewOVR, void, GLenum target, GLenum attachment, GLuint texture, GLint level, GLint baseViewIndex, GLsizei numViews);
#define glFramebufferTextureMultiviewOVR OGL__glFramebufferTextureMultiviewOVR

#endif // GL_OVR_multiview

#endif // OPENGL_INCLUDE_GL_OVR_multiview

/* -------------------------------------------------------------------------- */

#ifndef GL_OVR_multiview2
#define GL_OVR_multiview2 1

#endif // GL_OVR_multiview2

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_PGI_misc_hints

#ifndef GL_PGI_misc_hints
#define GL_PGI_misc_hints 1

#define GL_PREFER_DOUBLEBUFFER_HINT_PGI      0x1A1F8
#define GL_CONSERVE_MEMORY_HINT_PGI          0x1A1FD
#define GL_RECLAIM_MEMORY_HINT_PGI           0x1A1FE
#define GL_NATIVE_GRAPHICS_HANDLE_PGI        0x1A202
#define GL_NATIVE_GRAPHICS_BEGIN_HINT_PGI    0x1A203
#define GL_NATIVE_GRAPHICS_END_HINT_PGI      0x1A204
#define GL_ALWAYS_FAST_HINT_PGI              0x1A20C
#define GL_ALWAYS_SOFT_HINT_PGI              0x1A20D
#define GL_ALLOW_DRAW_OBJ_HINT_PGI           0x1A20E
#define GL_ALLOW_DRAW_WIN_HINT_PGI           0x1A20F
#define GL_ALLOW_DRAW_FRG_HINT_PGI           0x1A210
#define GL_ALLOW_DRAW_MEM_HINT_PGI           0x1A211
#define GL_STRICT_DEPTHFUNC_HINT_PGI         0x1A216
#define GL_STRICT_LIGHTING_HINT_PGI          0x1A217
#define GL_STRICT_SCISSOR_HINT_PGI           0x1A218
#define GL_FULL_STIPPLE_HINT_PGI             0x1A219
#define GL_CLIP_NEAR_HINT_PGI                0x1A220
#define GL_CLIP_FAR_HINT_PGI                 0x1A221
#define GL_WIDE_LINE_HINT_PGI                0x1A222
#define GL_BACK_NORMALS_HINT_PGI             0x1A223

OPENGL_INIT_PROC(glHintPGI, void, GLenum target, GLint mode);
#define glHintPGI OGL__glHintPGI

#endif // GL_PGI_misc_hints

#endif // OPENGL_INCLUDE_GL_PGI_misc_hints

/* -------------------------------------------------------------------------- */

#ifndef GL_PGI_vertex_hints
#define GL_PGI_vertex_hints 1

#define GL_VERTEX_DATA_HINT_PGI               0x1A22A
#define GL_VERTEX_CONSISTENT_HINT_PGI         0x1A22B
#define GL_MATERIAL_SIDE_HINT_PGI             0x1A22C
#define GL_MAX_VERTEX_HINT_PGI                0x1A22D
#define GL_COLOR3_BIT_PGI                     0x00010000
#define GL_COLOR4_BIT_PGI                     0x00020000
#define GL_EDGEFLAG_BIT_PGI                   0x00040000
#define GL_INDEX_BIT_PGI                      0x00080000
#define GL_MAT_AMBIENT_BIT_PGI                0x00100000
#define GL_MAT_AMBIENT_AND_DIFFUSE_BIT_PGI    0x00200000
#define GL_MAT_DIFFUSE_BIT_PGI                0x00400000
#define GL_MAT_EMISSION_BIT_PGI               0x00800000
#define GL_MAT_COLOR_INDEXES_BIT_PGI          0x01000000
#define GL_MAT_SHININESS_BIT_PGI              0x02000000
#define GL_MAT_SPECULAR_BIT_PGI               0x04000000
#define GL_NORMAL_BIT_PGI                     0x08000000
#define GL_TEXCOORD1_BIT_PGI                  0x10000000
#define GL_TEXCOORD2_BIT_PGI                  0x20000000
#define GL_TEXCOORD3_BIT_PGI                  0x40000000
#define GL_TEXCOORD4_BIT_PGI                  0x80000000
#define GL_VERTEX23_BIT_PGI                   0x00000004
#define GL_VERTEX4_BIT_PGI                    0x00000008

#endif // GL_PGI_vertex_hints

/* -------------------------------------------------------------------------- */

#ifndef GL_REND_screen_coordinates
#define GL_REND_screen_coordinates 1

#define GL_SCREEN_COORDINATES_REND    0x8490
#define GL_INVERTED_SCREEN_W_REND     0x8491

#endif // GL_REND_screen_coordinates

/* -------------------------------------------------------------------------- */

#ifndef GL_S3_s3tc
#define GL_S3_s3tc 1

#define GL_RGB_S3TC           0x83A0
#define GL_RGB4_S3TC          0x83A1
#define GL_RGBA_S3TC          0x83A2
#define GL_RGBA4_S3TC         0x83A3
#define GL_RGBA_DXT5_S3TC     0x83A4
#define GL_RGBA4_DXT5_S3TC    0x83A5

#endif // GL_S3_s3tc

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SGIS_detail_texture

#ifndef GL_SGIS_detail_texture
#define GL_SGIS_detail_texture 1

#define GL_DETAIL_TEXTURE_2D_SGIS             0x8095
#define GL_DETAIL_TEXTURE_2D_BINDING_SGIS     0x8096
#define GL_LINEAR_DETAIL_SGIS                 0x8097
#define GL_LINEAR_DETAIL_ALPHA_SGIS           0x8098
#define GL_LINEAR_DETAIL_COLOR_SGIS           0x8099
#define GL_DETAIL_TEXTURE_LEVEL_SGIS          0x809A
#define GL_DETAIL_TEXTURE_MODE_SGIS           0x809B
#define GL_DETAIL_TEXTURE_FUNC_POINTS_SGIS    0x809C

OPENGL_INIT_PROC(glDetailTexFuncSGIS,    void, GLenum target, GLsizei n, const GLfloat *points);
OPENGL_INIT_PROC(glGetDetailTexFuncSGIS, void, GLenum target, GLfloat *points);

#define glDetailTexFuncSGIS    OGL__glDetailTexFuncSGIS
#define glGetDetailTexFuncSGIS OGL__glGetDetailTexFuncSGIS

#endif // GL_SGIS_detail_texture

#endif // OPENGL_INCLUDE_GL_SGIS_detail_texture

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SGIS_fog_function

#ifndef GL_SGIS_fog_function
#define GL_SGIS_fog_function 1

#define GL_FOG_FUNC_SGIS               0x812A
#define GL_FOG_FUNC_POINTS_SGIS        0x812B
#define GL_MAX_FOG_FUNC_POINTS_SGIS    0x812C

OPENGL_INIT_PROC(glFogFuncSGIS,    void, GLsizei n, const GLfloat *points);
OPENGL_INIT_PROC(glGetFogFuncSGIS, void, GLfloat *points);

#define glFogFuncSGIS    OGL__glFogFuncSGIS
#define glGetFogFuncSGIS OGL__glGetFogFuncSGIS

#endif // GL_SGIS_fog_function

#endif // OPENGL_INCLUDE_GL_SGIS_fog_function

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIS_generate_mipmap
#define GL_SGIS_generate_mipmap 1

#define GL_GENERATE_MIPMAP_SGIS         0x8191
#define GL_GENERATE_MIPMAP_HINT_SGIS    0x8192

#endif // GL_SGIS_generate_mipmap

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SGIS_multisample

#ifndef GL_SGIS_multisample
#define GL_SGIS_multisample 1

#define GL_MULTISAMPLE_SGIS             0x809D
#define GL_SAMPLE_ALPHA_TO_MASK_SGIS    0x809E
#define GL_SAMPLE_ALPHA_TO_ONE_SGIS     0x809F
#define GL_SAMPLE_MASK_SGIS             0x80A0
#define GL_1PASS_SGIS                   0x80A1
#define GL_2PASS_0_SGIS                 0x80A2
#define GL_2PASS_1_SGIS                 0x80A3
#define GL_4PASS_0_SGIS                 0x80A4
#define GL_4PASS_1_SGIS                 0x80A5
#define GL_4PASS_2_SGIS                 0x80A6
#define GL_4PASS_3_SGIS                 0x80A7
#define GL_SAMPLE_BUFFERS_SGIS          0x80A8
#define GL_SAMPLES_SGIS                 0x80A9
#define GL_SAMPLE_MASK_VALUE_SGIS       0x80AA
#define GL_SAMPLE_MASK_INVERT_SGIS      0x80AB
#define GL_SAMPLE_PATTERN_SGIS          0x80AC

OPENGL_INIT_PROC(glSampleMaskSGIS,    void, GLclampf value, GLboolean invert);
OPENGL_INIT_PROC(glSamplePatternSGIS, void, GLenum pattern);

#define glSampleMaskSGIS    OGL__glSampleMaskSGIS
#define glSamplePatternSGIS OGL__glSamplePatternSGIS

#endif // GL_SGIS_multisample

#endif // OPENGL_INCLUDE_GL_SGIS_multisample

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SGIS_pixel_texture

#ifndef GL_SGIS_pixel_texture
#define GL_SGIS_pixel_texture 1

#define GL_PIXEL_TEXTURE_SGIS                  0x8353
#define GL_PIXEL_FRAGMENT_RGB_SOURCE_SGIS      0x8354
#define GL_PIXEL_FRAGMENT_ALPHA_SOURCE_SGIS    0x8355
#define GL_PIXEL_GROUP_COLOR_SGIS              0x8356

OPENGL_INIT_PROC(glPixelTexGenParameteriSGIS,     void, GLenum pname, GLint param);
OPENGL_INIT_PROC(glPixelTexGenParameterivSGIS,    void, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glPixelTexGenParameterfSGIS,     void, GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glPixelTexGenParameterfvSGIS,    void, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glGetPixelTexGenParameterivSGIS, void, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetPixelTexGenParameterfvSGIS, void, GLenum pname, GLfloat *params);

#define glPixelTexGenParameteriSGIS     OGL__glPixelTexGenParameteriSGIS
#define glPixelTexGenParameterivSGIS    OGL__glPixelTexGenParameterivSGIS
#define glPixelTexGenParameterfSGIS     OGL__glPixelTexGenParameterfSGIS
#define glPixelTexGenParameterfvSGIS    OGL__glPixelTexGenParameterfvSGIS
#define glGetPixelTexGenParameterivSGIS OGL__glGetPixelTexGenParameterivSGIS
#define glGetPixelTexGenParameterfvSGIS OGL__glGetPixelTexGenParameterfvSGIS

#endif // GL_SGIS_pixel_texture

#endif // OPENGL_INCLUDE_GL_SGIS_pixel_texture

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIS_point_line_texgen
#define GL_SGIS_point_line_texgen 1

#define GL_EYE_DISTANCE_TO_POINT_SGIS       0x81F0
#define GL_OBJECT_DISTANCE_TO_POINT_SGIS    0x81F1
#define GL_EYE_DISTANCE_TO_LINE_SGIS        0x81F2
#define GL_OBJECT_DISTANCE_TO_LINE_SGIS     0x81F3
#define GL_EYE_POINT_SGIS                   0x81F4
#define GL_OBJECT_POINT_SGIS                0x81F5
#define GL_EYE_LINE_SGIS                    0x81F6
#define GL_OBJECT_LINE_SGIS                 0x81F7

#endif // GL_SGIS_point_line_texgen

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SGIS_point_parameters

#ifndef GL_SGIS_point_parameters
#define GL_SGIS_point_parameters 1

#define GL_POINT_SIZE_MIN_SGIS               0x8126
#define GL_POINT_SIZE_MAX_SGIS               0x8127
#define GL_POINT_FADE_THRESHOLD_SIZE_SGIS    0x8128
#define GL_DISTANCE_ATTENUATION_SGIS         0x8129

OPENGL_INIT_PROC(glPointParameterfSGIS,  void, GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glPointParameterfvSGIS, void, GLenum pname, const GLfloat *params);

#define glPointParameterfSGIS  OGL__glPointParameterfSGIS
#define glPointParameterfvSGIS OGL__glPointParameterfvSGIS

#endif // GL_SGIS_point_parameters

#endif // OPENGL_INCLUDE_GL_SGIS_point_parameters

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SGIS_sharpen_texture

#ifndef GL_SGIS_sharpen_texture
#define GL_SGIS_sharpen_texture 1

#define GL_LINEAR_SHARPEN_SGIS                 0x80AD
#define GL_LINEAR_SHARPEN_ALPHA_SGIS           0x80AE
#define GL_LINEAR_SHARPEN_COLOR_SGIS           0x80AF
#define GL_SHARPEN_TEXTURE_FUNC_POINTS_SGIS    0x80B0

OPENGL_INIT_PROC(glSharpenTexFuncSGIS,    void, GLenum target, GLsizei n, const GLfloat *points);
OPENGL_INIT_PROC(glGetSharpenTexFuncSGIS, void, GLenum target, GLfloat *points);

#define glSharpenTexFuncSGIS    OGL__glSharpenTexFuncSGIS
#define glGetSharpenTexFuncSGIS OGL__glGetSharpenTexFuncSGIS

#endif // GL_SGIS_sharpen_texture

#endif // OPENGL_INCLUDE_GL_SGIS_sharpen_texture

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SGIS_texture4D

#ifndef GL_SGIS_texture4D
#define GL_SGIS_texture4D 1

#define GL_PACK_SKIP_VOLUMES_SGIS      0x8130
#define GL_PACK_IMAGE_DEPTH_SGIS       0x8131
#define GL_UNPACK_SKIP_VOLUMES_SGIS    0x8132
#define GL_UNPACK_IMAGE_DEPTH_SGIS     0x8133
#define GL_TEXTURE_4D_SGIS             0x8134
#define GL_PROXY_TEXTURE_4D_SGIS       0x8135
#define GL_TEXTURE_4DSIZE_SGIS         0x8136
#define GL_TEXTURE_WRAP_Q_SGIS         0x8137
#define GL_MAX_4D_TEXTURE_SIZE_SGIS    0x8138
#define GL_TEXTURE_4D_BINDING_SGIS     0x814F

OPENGL_INIT_PROC(glTexImage4DSGIS,    void, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLint border, GLenum format, GLenum type, const void *pixels);
OPENGL_INIT_PROC(glTexSubImage4DSGIS, void, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint woffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei size4d, GLenum format, GLenum type, const void *pixels);

#define glTexImage4DSGIS    OGL__glTexImage4DSGIS
#define glTexSubImage4DSGIS OGL__glTexSubImage4DSGIS

#endif // GL_SGIS_texture4D

#endif // OPENGL_INCLUDE_GL_SGIS_texture4D

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIS_texture_border_clamp
#define GL_SGIS_texture_border_clamp 1

#define GL_CLAMP_TO_BORDER_SGIS    0x812D

#endif // GL_SGIS_texture_border_clamp

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SGIS_texture_color_mask

#ifndef GL_SGIS_texture_color_mask
#define GL_SGIS_texture_color_mask 1

#define GL_TEXTURE_COLOR_WRITEMASK_SGIS    0x81EF

OPENGL_INIT_PROC(glTextureColorMaskSGIS, void, GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
#define glTextureColorMaskSGIS OGL__glTextureColorMaskSGIS

#endif // GL_SGIS_texture_color_mask

#endif // OPENGL_INCLUDE_GL_SGIS_texture_color_mask

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIS_texture_edge_clamp
#define GL_SGIS_texture_edge_clamp 1

#define GL_CLAMP_TO_EDGE_SGIS    0x812F

#endif // GL_SGIS_texture_edge_clamp

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SGIS_texture_filter4

#ifndef GL_SGIS_texture_filter4
#define GL_SGIS_texture_filter4 1

#define GL_FILTER4_SGIS                 0x8146
#define GL_TEXTURE_FILTER4_SIZE_SGIS    0x8147

OPENGL_INIT_PROC(glGetTexFilterFuncSGIS, void, GLenum target, GLenum filter, GLfloat *weights);
OPENGL_INIT_PROC(glTexFilterFuncSGIS,    void, GLenum target, GLenum filter, GLsizei n, const GLfloat *weights);

#define glGetTexFilterFuncSGIS OGL__glGetTexFilterFuncSGIS
#define glTexFilterFuncSGIS    OGL__glTexFilterFuncSGIS

#endif // GL_SGIS_texture_filter4

#endif // OPENGL_INCLUDE_GL_SGIS_texture_filter4

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIS_texture_lod
#define GL_SGIS_texture_lod 1

#define GL_TEXTURE_MIN_LOD_SGIS       0x813A
#define GL_TEXTURE_MAX_LOD_SGIS       0x813B
#define GL_TEXTURE_BASE_LEVEL_SGIS    0x813C
#define GL_TEXTURE_MAX_LEVEL_SGIS     0x813D

#endif // GL_SGIS_texture_lod

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIS_texture_select
#define GL_SGIS_texture_select 1

#define GL_DUAL_ALPHA4_SGIS              0x8110
#define GL_DUAL_ALPHA8_SGIS              0x8111
#define GL_DUAL_ALPHA12_SGIS             0x8112
#define GL_DUAL_ALPHA16_SGIS             0x8113
#define GL_DUAL_LUMINANCE4_SGIS          0x8114
#define GL_DUAL_LUMINANCE8_SGIS          0x8115
#define GL_DUAL_LUMINANCE12_SGIS         0x8116
#define GL_DUAL_LUMINANCE16_SGIS         0x8117
#define GL_DUAL_INTENSITY4_SGIS          0x8118
#define GL_DUAL_INTENSITY8_SGIS          0x8119
#define GL_DUAL_INTENSITY12_SGIS         0x811A
#define GL_DUAL_INTENSITY16_SGIS         0x811B
#define GL_DUAL_LUMINANCE_ALPHA4_SGIS    0x811C
#define GL_DUAL_LUMINANCE_ALPHA8_SGIS    0x811D
#define GL_QUAD_ALPHA4_SGIS              0x811E
#define GL_QUAD_ALPHA8_SGIS              0x811F
#define GL_QUAD_LUMINANCE4_SGIS          0x8120
#define GL_QUAD_LUMINANCE8_SGIS          0x8121
#define GL_QUAD_INTENSITY4_SGIS          0x8122
#define GL_QUAD_INTENSITY8_SGIS          0x8123
#define GL_DUAL_TEXTURE_SELECT_SGIS      0x8124
#define GL_QUAD_TEXTURE_SELECT_SGIS      0x8125

#endif // GL_SGIS_texture_select

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SGIX_async

#ifndef GL_SGIX_async
#define GL_SGIX_async 1

#define GL_ASYNC_MARKER_SGIX    0x8329

OPENGL_INIT_PROC(glAsyncMarkerSGIX,        void,      GLuint marker);
OPENGL_INIT_PROC(glFinishAsyncSGIX,        GLint,     GLuint *markerp);
OPENGL_INIT_PROC(glPollAsyncSGIX,          GLint,     GLuint *markerp);
OPENGL_INIT_PROC(glGenAsyncMarkersSGIX,    GLuint,    GLsizei range);
OPENGL_INIT_PROC(glDeleteAsyncMarkersSGIX, void,      GLuint marker, GLsizei range);
OPENGL_INIT_PROC(glIsAsyncMarkerSGIX,      GLboolean, GLuint marker);

#define glAsyncMarkerSGIX        OGL__glAsyncMarkerSGIX
#define glFinishAsyncSGIX        OGL__glFinishAsyncSGIX
#define glPollAsyncSGIX          OGL__glPollAsyncSGIX
#define glGenAsyncMarkersSGIX    OGL__glGenAsyncMarkersSGIX
#define glDeleteAsyncMarkersSGIX OGL__glDeleteAsyncMarkersSGIX
#define glIsAsyncMarkerSGIX      OGL__glIsAsyncMarkerSGIX

#endif // GL_SGIX_async

#endif // OPENGL_INCLUDE_GL_SGIX_async

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_async_histogram
#define GL_SGIX_async_histogram 1

#define GL_ASYNC_HISTOGRAM_SGIX        0x832C
#define GL_MAX_ASYNC_HISTOGRAM_SGIX    0x832D

#endif // GL_SGIX_async_histogram

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_async_pixel
#define GL_SGIX_async_pixel 1

#define GL_ASYNC_TEX_IMAGE_SGIX          0x835C
#define GL_ASYNC_DRAW_PIXELS_SGIX        0x835D
#define GL_ASYNC_READ_PIXELS_SGIX        0x835E
#define GL_MAX_ASYNC_TEX_IMAGE_SGIX      0x835F
#define GL_MAX_ASYNC_DRAW_PIXELS_SGIX    0x8360
#define GL_MAX_ASYNC_READ_PIXELS_SGIX    0x8361

#endif // GL_SGIX_async_pixel

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_blend_alpha_minmax
#define GL_SGIX_blend_alpha_minmax 1

#define GL_ALPHA_MIN_SGIX    0x8320
#define GL_ALPHA_MAX_SGIX    0x8321

#endif // GL_SGIX_blend_alpha_minmax

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_calligraphic_fragment
#define GL_SGIX_calligraphic_fragment 1

#define GL_CALLIGRAPHIC_FRAGMENT_SGIX    0x8183

#endif // GL_SGIX_calligraphic_fragment

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_clipmap
#define GL_SGIX_clipmap 1

#define GL_LINEAR_CLIPMAP_LINEAR_SGIX            0x8170
#define GL_TEXTURE_CLIPMAP_CENTER_SGIX           0x8171
#define GL_TEXTURE_CLIPMAP_FRAME_SGIX            0x8172
#define GL_TEXTURE_CLIPMAP_OFFSET_SGIX           0x8173
#define GL_TEXTURE_CLIPMAP_VIRTUAL_DEPTH_SGIX    0x8174
#define GL_TEXTURE_CLIPMAP_LOD_OFFSET_SGIX       0x8175
#define GL_TEXTURE_CLIPMAP_DEPTH_SGIX            0x8176
#define GL_MAX_CLIPMAP_DEPTH_SGIX                0x8177
#define GL_MAX_CLIPMAP_VIRTUAL_DEPTH_SGIX        0x8178
#define GL_NEAREST_CLIPMAP_NEAREST_SGIX          0x844D
#define GL_NEAREST_CLIPMAP_LINEAR_SGIX           0x844E
#define GL_LINEAR_CLIPMAP_NEAREST_SGIX           0x844F

#endif // GL_SGIX_clipmap

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_convolution_accuracy
#define GL_SGIX_convolution_accuracy 1

#define GL_CONVOLUTION_HINT_SGIX    0x8316

#endif // GL_SGIX_convolution_accuracy

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_depth_pass_instrument
#define GL_SGIX_depth_pass_instrument 1

#endif // GL_SGIX_depth_pass_instrument

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_depth_texture
#define GL_SGIX_depth_texture 1

#define GL_DEPTH_COMPONENT16_SGIX    0x81A5
#define GL_DEPTH_COMPONENT24_SGIX    0x81A6
#define GL_DEPTH_COMPONENT32_SGIX    0x81A7

#endif // GL_SGIX_depth_texture

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SGIX_flush_raster

#ifndef GL_SGIX_flush_raster
#define GL_SGIX_flush_raster 1

OPENGL_INIT_PROC(glFlushRasterSGIX, void, void);
#define glFlushRasterSGIX OGL__glFlushRasterSGIX

#endif // GL_SGIX_flush_raster

#endif // OPENGL_INCLUDE_GL_SGIX_flush_raster

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_fog_offset
#define GL_SGIX_fog_offset 1

#define GL_FOG_OFFSET_SGIX          0x8198
#define GL_FOG_OFFSET_VALUE_SGIX    0x8199

#endif // GL_SGIX_fog_offset

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SGIX_fragment_lighting

#ifndef GL_SGIX_fragment_lighting
#define GL_SGIX_fragment_lighting 1

#define GL_FRAGMENT_LIGHTING_SGIX                            0x8400
#define GL_FRAGMENT_COLOR_MATERIAL_SGIX                      0x8401
#define GL_FRAGMENT_COLOR_MATERIAL_FACE_SGIX                 0x8402
#define GL_FRAGMENT_COLOR_MATERIAL_PARAMETER_SGIX            0x8403
#define GL_MAX_FRAGMENT_LIGHTS_SGIX                          0x8404
#define GL_MAX_ACTIVE_LIGHTS_SGIX                            0x8405
#define GL_CURRENT_RASTER_NORMAL_SGIX                        0x8406
#define GL_LIGHT_ENV_MODE_SGIX                               0x8407
#define GL_FRAGMENT_LIGHT_MODEL_LOCAL_VIEWER_SGIX            0x8408
#define GL_FRAGMENT_LIGHT_MODEL_TWO_SIDE_SGIX                0x8409
#define GL_FRAGMENT_LIGHT_MODEL_AMBIENT_SGIX                 0x840A
#define GL_FRAGMENT_LIGHT_MODEL_NORMAL_INTERPOLATION_SGIX    0x840B
#define GL_FRAGMENT_LIGHT0_SGIX                              0x840C
#define GL_FRAGMENT_LIGHT1_SGIX                              0x840D
#define GL_FRAGMENT_LIGHT2_SGIX                              0x840E
#define GL_FRAGMENT_LIGHT3_SGIX                              0x840F
#define GL_FRAGMENT_LIGHT4_SGIX                              0x8410
#define GL_FRAGMENT_LIGHT5_SGIX                              0x8411
#define GL_FRAGMENT_LIGHT6_SGIX                              0x8412
#define GL_FRAGMENT_LIGHT7_SGIX                              0x8413

OPENGL_INIT_PROC(glFragmentColorMaterialSGIX, void, GLenum face, GLenum mode);
OPENGL_INIT_PROC(glFragmentLightfSGIX,        void, GLenum light, GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glFragmentLightfvSGIX,       void, GLenum light, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glFragmentLightiSGIX,        void, GLenum light, GLenum pname, GLint param);
OPENGL_INIT_PROC(glFragmentLightivSGIX,       void, GLenum light, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glFragmentLightModelfSGIX,   void, GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glFragmentLightModelfvSGIX,  void, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glFragmentLightModeliSGIX,   void, GLenum pname, GLint param);
OPENGL_INIT_PROC(glFragmentLightModelivSGIX,  void, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glFragmentMaterialfSGIX,     void, GLenum face, GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glFragmentMaterialfvSGIX,    void, GLenum face, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glFragmentMaterialiSGIX,     void, GLenum face, GLenum pname, GLint param);
OPENGL_INIT_PROC(glFragmentMaterialivSGIX,    void, GLenum face, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glGetFragmentLightfvSGIX,    void, GLenum light, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetFragmentLightivSGIX,    void, GLenum light, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glGetFragmentMaterialfvSGIX, void, GLenum face, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetFragmentMaterialivSGIX, void, GLenum face, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glLightEnviSGIX,             void, GLenum pname, GLint param);

#define glFragmentColorMaterialSGIX OGL__glFragmentColorMaterialSGIX
#define glFragmentLightfSGIX        OGL__glFragmentLightfSGIX
#define glFragmentLightfvSGIX       OGL__glFragmentLightfvSGIX
#define glFragmentLightiSGIX        OGL__glFragmentLightiSGIX
#define glFragmentLightivSGIX       OGL__glFragmentLightivSGIX
#define glFragmentLightModelfSGIX   OGL__glFragmentLightModelfSGIX
#define glFragmentLightModelfvSGIX  OGL__glFragmentLightModelfvSGIX
#define glFragmentLightModeliSGIX   OGL__glFragmentLightModeliSGIX
#define glFragmentLightModelivSGIX  OGL__glFragmentLightModelivSGIX
#define glFragmentMaterialfSGIX     OGL__glFragmentMaterialfSGIX
#define glFragmentMaterialfvSGIX    OGL__glFragmentMaterialfvSGIX
#define glFragmentMaterialiSGIX     OGL__glFragmentMaterialiSGIX
#define glFragmentMaterialivSGIX    OGL__glFragmentMaterialivSGIX
#define glGetFragmentLightfvSGIX    OGL__glGetFragmentLightfvSGIX
#define glGetFragmentLightivSGIX    OGL__glGetFragmentLightivSGIX
#define glGetFragmentMaterialfvSGIX OGL__glGetFragmentMaterialfvSGIX
#define glGetFragmentMaterialivSGIX OGL__glGetFragmentMaterialivSGIX
#define glLightEnviSGIX             OGL__glLightEnviSGIX

#endif // GL_SGIX_fragment_lighting

#endif // OPENGL_INCLUDE_GL_SGIX_fragment_lighting

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SGIX_framezoom

#ifndef GL_SGIX_framezoom
#define GL_SGIX_framezoom 1

#define GL_FRAMEZOOM_SGIX               0x818B
#define GL_FRAMEZOOM_FACTOR_SGIX        0x818C
#define GL_MAX_FRAMEZOOM_FACTOR_SGIX    0x818D

OPENGL_INIT_PROC(glFrameZoomSGIX, void, GLint factor);
#define glFrameZoomSGIX OGL__glFrameZoomSGIX

#endif // GL_SGIX_framezoom

#endif // OPENGL_INCLUDE_GL_SGIX_framezoom

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SGIX_igloo_interface

#ifndef GL_SGIX_igloo_interface
#define GL_SGIX_igloo_interface 1

OPENGL_INIT_PROC(glIglooInterfaceSGIX, void, GLenum pname, const void *params);
#define glIglooInterfaceSGIX OGL__glIglooInterfaceSGIX

#endif // GL_SGIX_igloo_interface

#endif // OPENGL_INCLUDE_GL_SGIX_igloo_interface

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SGIX_instruments

#ifndef GL_SGIX_instruments
#define GL_SGIX_instruments 1

#define GL_INSTRUMENT_BUFFER_POINTER_SGIX    0x8180
#define GL_INSTRUMENT_MEASUREMENTS_SGIX      0x8181

OPENGL_INIT_PROC(glGetInstrumentsSGIX,    GLint, void);
OPENGL_INIT_PROC(glInstrumentsBufferSGIX, void,  GLsizei size, GLint *buffer);
OPENGL_INIT_PROC(glPollInstrumentsSGIX,   GLint, GLint *marker_p);
OPENGL_INIT_PROC(glReadInstrumentsSGIX,   void,  GLint marker);
OPENGL_INIT_PROC(glStartInstrumentsSGIX,  void,  void);
OPENGL_INIT_PROC(glStopInstrumentsSGIX,   void,  GLint marker);

#define glGetInstrumentsSGIX    OGL__glGetInstrumentsSGIX
#define glInstrumentsBufferSGIX OGL__glInstrumentsBufferSGIX
#define glPollInstrumentsSGIX   OGL__glPollInstrumentsSGIX
#define glReadInstrumentsSGIX   OGL__glReadInstrumentsSGIX
#define glStartInstrumentsSGIX  OGL__glStartInstrumentsSGIX
#define glStopInstrumentsSGIX   OGL__glStopInstrumentsSGIX

#endif // GL_SGIX_instruments

#endif // OPENGL_INCLUDE_GL_SGIX_instruments

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_interlace
#define GL_SGIX_interlace 1

#define GL_INTERLACE_SGIX    0x8094

#endif // GL_SGIX_interlace

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_ir_instrument1
#define GL_SGIX_ir_instrument1 1

#define GL_IR_INSTRUMENT1_SGIX    0x817F

#endif // GL_SGIX_ir_instrument1

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SGIX_list_priority

#ifndef GL_SGIX_list_priority
#define GL_SGIX_list_priority 1

#define GL_LIST_PRIORITY_SGIX    0x8182

OPENGL_INIT_PROC(glGetListParameterfvSGIX, void, GLuint list, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetListParameterivSGIX, void, GLuint list, GLenum pname, GLint *params);
OPENGL_INIT_PROC(glListParameterfSGIX,     void, GLuint list, GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glListParameterfvSGIX,    void, GLuint list, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glListParameteriSGIX,     void, GLuint list, GLenum pname, GLint param);
OPENGL_INIT_PROC(glListParameterivSGIX,    void, GLuint list, GLenum pname, const GLint *params);

#define glGetListParameterfvSGIX OGL__glGetListParameterfvSGIX
#define glGetListParameterivSGIX OGL__glGetListParameterivSGIX
#define glListParameterfSGIX     OGL__glListParameterfSGIX
#define glListParameterfvSGIX    OGL__glListParameterfvSGIX
#define glListParameteriSGIX     OGL__glListParameteriSGIX
#define glListParameterivSGIX    OGL__glListParameterivSGIX

#endif // GL_SGIX_list_priority

#endif // OPENGL_INCLUDE_GL_SGIX_list_priority

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SGIX_pixel_texture

#ifndef GL_SGIX_pixel_texture
#define GL_SGIX_pixel_texture 1

#define GL_PIXEL_TEX_GEN_SGIX         0x8139
#define GL_PIXEL_TEX_GEN_MODE_SGIX    0x832B

OPENGL_INIT_PROC(glPixelTexGenSGIX, void, GLenum mode);
#define glPixelTexGenSGIX OGL__glPixelTexGenSGIX

#endif // GL_SGIX_pixel_texture

#endif // OPENGL_INCLUDE_GL_SGIX_pixel_texture

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_pixel_tiles
#define GL_SGIX_pixel_tiles 1

#define GL_PIXEL_TILE_BEST_ALIGNMENT_SGIX     0x813E
#define GL_PIXEL_TILE_CACHE_INCREMENT_SGIX    0x813F
#define GL_PIXEL_TILE_WIDTH_SGIX              0x8140
#define GL_PIXEL_TILE_HEIGHT_SGIX             0x8141
#define GL_PIXEL_TILE_GRID_WIDTH_SGIX         0x8142
#define GL_PIXEL_TILE_GRID_HEIGHT_SGIX        0x8143
#define GL_PIXEL_TILE_GRID_DEPTH_SGIX         0x8144
#define GL_PIXEL_TILE_CACHE_SIZE_SGIX         0x8145

#endif // GL_SGIX_pixel_tiles

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SGIX_polynomial_ffd

#ifndef GL_SGIX_polynomial_ffd
#define GL_SGIX_polynomial_ffd 1

#define GL_TEXTURE_DEFORMATION_BIT_SGIX     0x00000001
#define GL_GEOMETRY_DEFORMATION_BIT_SGIX    0x00000002
#define GL_GEOMETRY_DEFORMATION_SGIX        0x8194
#define GL_TEXTURE_DEFORMATION_SGIX         0x8195
#define GL_DEFORMATIONS_MASK_SGIX           0x8196
#define GL_MAX_DEFORMATION_ORDER_SGIX       0x8197

OPENGL_INIT_PROC(glDeformationMap3dSGIX,           void, GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, GLdouble w1, GLdouble w2, GLint wstride, GLint worder, const GLdouble *points);
OPENGL_INIT_PROC(glDeformationMap3fSGIX,           void, GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, GLfloat w1, GLfloat w2, GLint wstride, GLint worder, const GLfloat *points);
OPENGL_INIT_PROC(glDeformSGIX,                     void, GLbitfield mask);
OPENGL_INIT_PROC(glLoadIdentityDeformationMapSGIX, void, GLbitfield mask);

#define glDeformationMap3dSGIX           OGL__glDeformationMap3dSGIX
#define glDeformationMap3fSGIX           OGL__glDeformationMap3fSGIX
#define glDeformSGIX                     OGL__glDeformSGIX
#define glLoadIdentityDeformationMapSGIX OGL__glLoadIdentityDeformationMapSGIX

#endif // GL_SGIX_polynomial_ffd

#endif // OPENGL_INCLUDE_GL_SGIX_polynomial_ffd

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SGIX_reference_plane

#ifndef GL_SGIX_reference_plane
#define GL_SGIX_reference_plane 1

#define GL_REFERENCE_PLANE_SGIX             0x817D
#define GL_REFERENCE_PLANE_EQUATION_SGIX    0x817E

OPENGL_INIT_PROC(glReferencePlaneSGIX, void, const GLdouble *equation);
#define glReferencePlaneSGIX OGL__glReferencePlaneSGIX

#endif // GL_SGIX_reference_plane

#endif // OPENGL_INCLUDE_GL_SGIX_reference_plane

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_resample
#define GL_SGIX_resample 1

#define GL_PACK_RESAMPLE_SGIX         0x842E
#define GL_UNPACK_RESAMPLE_SGIX       0x842F
#define GL_RESAMPLE_REPLICATE_SGIX    0x8433
#define GL_RESAMPLE_ZERO_FILL_SGIX    0x8434
#define GL_RESAMPLE_DECIMATE_SGIX     0x8430

#endif // GL_SGIX_resample

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_scalebias_hint
#define GL_SGIX_scalebias_hint 1

#define GL_SCALEBIAS_HINT_SGIX    0x8322

#endif // GL_SGIX_scalebias_hint

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_shadow
#define GL_SGIX_shadow 1

#define GL_TEXTURE_COMPARE_SGIX             0x819A
#define GL_TEXTURE_COMPARE_OPERATOR_SGIX    0x819B
#define GL_TEXTURE_LEQUAL_R_SGIX            0x819C
#define GL_TEXTURE_GEQUAL_R_SGIX            0x819D

#endif // GL_SGIX_shadow

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_shadow_ambient
#define GL_SGIX_shadow_ambient 1

#define GL_SHADOW_AMBIENT_SGIX    0x80BF

#endif // GL_SGIX_shadow_ambient

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SGIX_sprite

#ifndef GL_SGIX_sprite
#define GL_SGIX_sprite 1

#define GL_SPRITE_SGIX                   0x8148
#define GL_SPRITE_MODE_SGIX              0x8149
#define GL_SPRITE_AXIS_SGIX              0x814A
#define GL_SPRITE_TRANSLATION_SGIX       0x814B
#define GL_SPRITE_AXIAL_SGIX             0x814C
#define GL_SPRITE_OBJECT_ALIGNED_SGIX    0x814D
#define GL_SPRITE_EYE_ALIGNED_SGIX       0x814E

OPENGL_INIT_PROC(glSpriteParameterfSGIX,  void, GLenum pname, GLfloat param);
OPENGL_INIT_PROC(glSpriteParameterfvSGIX, void, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glSpriteParameteriSGIX,  void, GLenum pname, GLint param);
OPENGL_INIT_PROC(glSpriteParameterivSGIX, void, GLenum pname, const GLint *params);

#define glSpriteParameterfSGIX  OGL__glSpriteParameterfSGIX
#define glSpriteParameterfvSGIX OGL__glSpriteParameterfvSGIX
#define glSpriteParameteriSGIX  OGL__glSpriteParameteriSGIX
#define glSpriteParameterivSGIX OGL__glSpriteParameterivSGIX

#endif // GL_SGIX_sprite

#endif // OPENGL_INCLUDE_GL_SGIX_sprite

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_subsample
#define GL_SGIX_subsample 1

#define GL_PACK_SUBSAMPLE_RATE_SGIX      0x85A0
#define GL_UNPACK_SUBSAMPLE_RATE_SGIX    0x85A1
#define GL_PIXEL_SUBSAMPLE_4444_SGIX     0x85A2
#define GL_PIXEL_SUBSAMPLE_2424_SGIX     0x85A3
#define GL_PIXEL_SUBSAMPLE_4242_SGIX     0x85A4

#endif // GL_SGIX_subsample

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SGIX_tag_sample_buffer

#ifndef GL_SGIX_tag_sample_buffer
#define GL_SGIX_tag_sample_buffer 1

OPENGL_INIT_PROC(glTagSampleBufferSGIX, void, void);
#define glTagSampleBufferSGIX OGL__glTagSampleBufferSGIX

#endif // GL_SGIX_tag_sample_buffer

#endif // OPENGL_INCLUDE_GL_SGIX_tag_sample_buffer

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_texture_add_env
#define GL_SGIX_texture_add_env 1

#define GL_TEXTURE_ENV_BIAS_SGIX    0x80BE

#endif // GL_SGIX_texture_add_env

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_texture_coordinate_clamp
#define GL_SGIX_texture_coordinate_clamp 1

#define GL_TEXTURE_MAX_CLAMP_S_SGIX    0x8369
#define GL_TEXTURE_MAX_CLAMP_T_SGIX    0x836A
#define GL_TEXTURE_MAX_CLAMP_R_SGIX    0x836B

#endif // GL_SGIX_texture_coordinate_clamp

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_texture_lod_bias
#define GL_SGIX_texture_lod_bias 1

#define GL_TEXTURE_LOD_BIAS_S_SGIX    0x818E
#define GL_TEXTURE_LOD_BIAS_T_SGIX    0x818F
#define GL_TEXTURE_LOD_BIAS_R_SGIX    0x8190

#endif // GL_SGIX_texture_lod_bias

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_texture_multi_buffer
#define GL_SGIX_texture_multi_buffer 1

#define GL_TEXTURE_MULTI_BUFFER_HINT_SGIX    0x812E

#endif // GL_SGIX_texture_multi_buffer

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_texture_scale_bias
#define GL_SGIX_texture_scale_bias 1

#define GL_POST_TEXTURE_FILTER_BIAS_SGIX           0x8179
#define GL_POST_TEXTURE_FILTER_SCALE_SGIX          0x817A
#define GL_POST_TEXTURE_FILTER_BIAS_RANGE_SGIX     0x817B
#define GL_POST_TEXTURE_FILTER_SCALE_RANGE_SGIX    0x817C

#endif // GL_SGIX_texture_scale_bias

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_vertex_preclip
#define GL_SGIX_vertex_preclip 1

#define GL_VERTEX_PRECLIP_SGIX         0x83EE
#define GL_VERTEX_PRECLIP_HINT_SGIX    0x83EF

#endif // GL_SGIX_vertex_preclip

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_ycrcb
#define GL_SGIX_ycrcb 1

#define GL_YCRCB_422_SGIX    0x81BB
#define GL_YCRCB_444_SGIX    0x81BC

#endif // GL_SGIX_ycrcb

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_ycrcb_subsample
#define GL_SGIX_ycrcb_subsample 1

#endif // GL_SGIX_ycrcb_subsample

/* -------------------------------------------------------------------------- */

#ifndef GL_SGIX_ycrcba
#define GL_SGIX_ycrcba 1

#define GL_YCRCB_SGIX     0x8318
#define GL_YCRCBA_SGIX    0x8319

#endif // GL_SGIX_ycrcba

/* -------------------------------------------------------------------------- */

#ifndef GL_SGI_color_matrix
#define GL_SGI_color_matrix 1

#define GL_COLOR_MATRIX_SGI                     0x80B1
#define GL_COLOR_MATRIX_STACK_DEPTH_SGI         0x80B2
#define GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI     0x80B3
#define GL_POST_COLOR_MATRIX_RED_SCALE_SGI      0x80B4
#define GL_POST_COLOR_MATRIX_GREEN_SCALE_SGI    0x80B5
#define GL_POST_COLOR_MATRIX_BLUE_SCALE_SGI     0x80B6
#define GL_POST_COLOR_MATRIX_ALPHA_SCALE_SGI    0x80B7
#define GL_POST_COLOR_MATRIX_RED_BIAS_SGI       0x80B8
#define GL_POST_COLOR_MATRIX_GREEN_BIAS_SGI     0x80B9
#define GL_POST_COLOR_MATRIX_BLUE_BIAS_SGI      0x80BA
#define GL_POST_COLOR_MATRIX_ALPHA_BIAS_SGI     0x80BB

#endif // GL_SGI_color_matrix

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SGI_color_table

#ifndef GL_SGI_color_table
#define GL_SGI_color_table 1

#define GL_COLOR_TABLE_SGI                            0x80D0
#define GL_POST_CONVOLUTION_COLOR_TABLE_SGI           0x80D1
#define GL_POST_COLOR_MATRIX_COLOR_TABLE_SGI          0x80D2
#define GL_PROXY_COLOR_TABLE_SGI                      0x80D3
#define GL_PROXY_POST_CONVOLUTION_COLOR_TABLE_SGI     0x80D4
#define GL_PROXY_POST_COLOR_MATRIX_COLOR_TABLE_SGI    0x80D5
#define GL_COLOR_TABLE_SCALE_SGI                      0x80D6
#define GL_COLOR_TABLE_BIAS_SGI                       0x80D7
#define GL_COLOR_TABLE_FORMAT_SGI                     0x80D8
#define GL_COLOR_TABLE_WIDTH_SGI                      0x80D9
#define GL_COLOR_TABLE_RED_SIZE_SGI                   0x80DA
#define GL_COLOR_TABLE_GREEN_SIZE_SGI                 0x80DB
#define GL_COLOR_TABLE_BLUE_SIZE_SGI                  0x80DC
#define GL_COLOR_TABLE_ALPHA_SIZE_SGI                 0x80DD
#define GL_COLOR_TABLE_LUMINANCE_SIZE_SGI             0x80DE
#define GL_COLOR_TABLE_INTENSITY_SIZE_SGI             0x80DF

OPENGL_INIT_PROC(glColorTableSGI,               void, GLenum target, GLenum internalformat, GLsizei width, GLenum format, GLenum type, const void *table);
OPENGL_INIT_PROC(glColorTableParameterfvSGI,    void, GLenum target, GLenum pname, const GLfloat *params);
OPENGL_INIT_PROC(glColorTableParameterivSGI,    void, GLenum target, GLenum pname, const GLint *params);
OPENGL_INIT_PROC(glCopyColorTableSGI,           void, GLenum target, GLenum internalformat, GLint x, GLint y, GLsizei width);
OPENGL_INIT_PROC(glGetColorTableSGI,            void, GLenum target, GLenum format, GLenum type, void *table);
OPENGL_INIT_PROC(glGetColorTableParameterfvSGI, void, GLenum target, GLenum pname, GLfloat *params);
OPENGL_INIT_PROC(glGetColorTableParameterivSGI, void, GLenum target, GLenum pname, GLint *params);

#define glColorTableSGI               OGL__glColorTableSGI
#define glColorTableParameterfvSGI    OGL__glColorTableParameterfvSGI
#define glColorTableParameterivSGI    OGL__glColorTableParameterivSGI
#define glCopyColorTableSGI           OGL__glCopyColorTableSGI
#define glGetColorTableSGI            OGL__glGetColorTableSGI
#define glGetColorTableParameterfvSGI OGL__glGetColorTableParameterfvSGI
#define glGetColorTableParameterivSGI OGL__glGetColorTableParameterivSGI

#endif // GL_SGI_color_table

#endif // OPENGL_INCLUDE_GL_SGI_color_table

/* -------------------------------------------------------------------------- */

#ifndef GL_SGI_texture_color_table
#define GL_SGI_texture_color_table 1

#define GL_TEXTURE_COLOR_TABLE_SGI          0x80BC
#define GL_PROXY_TEXTURE_COLOR_TABLE_SGI    0x80BD

#endif // GL_SGI_texture_color_table

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SUNX_constant_data

#ifndef GL_SUNX_constant_data
#define GL_SUNX_constant_data 1

#define GL_UNPACK_CONSTANT_DATA_SUNX     0x81D5
#define GL_TEXTURE_CONSTANT_DATA_SUNX    0x81D6

OPENGL_INIT_PROC(glFinishTextureSUNX, void, void);
#define glFinishTextureSUNX OGL__glFinishTextureSUNX

#endif // GL_SUNX_constant_data

#endif // OPENGL_INCLUDE_GL_SUNX_constant_data

/* -------------------------------------------------------------------------- */

#ifndef GL_SUN_convolution_border_modes
#define GL_SUN_convolution_border_modes 1

#define GL_WRAP_BORDER_SUN    0x81D4

#endif // GL_SUN_convolution_border_modes

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SUN_global_alpha

#ifndef GL_SUN_global_alpha
#define GL_SUN_global_alpha 1

#define GL_GLOBAL_ALPHA_SUN           0x81D9
#define GL_GLOBAL_ALPHA_FACTOR_SUN    0x81DA

OPENGL_INIT_PROC(glGlobalAlphaFactorbSUN,  void, GLbyte factor);
OPENGL_INIT_PROC(glGlobalAlphaFactorsSUN,  void, GLshort factor);
OPENGL_INIT_PROC(glGlobalAlphaFactoriSUN,  void, GLint factor);
OPENGL_INIT_PROC(glGlobalAlphaFactorfSUN,  void, GLfloat factor);
OPENGL_INIT_PROC(glGlobalAlphaFactordSUN,  void, GLdouble factor);
OPENGL_INIT_PROC(glGlobalAlphaFactorubSUN, void, GLubyte factor);
OPENGL_INIT_PROC(glGlobalAlphaFactorusSUN, void, GLushort factor);
OPENGL_INIT_PROC(glGlobalAlphaFactoruiSUN, void, GLuint factor);

#define glGlobalAlphaFactorbSUN  OGL__glGlobalAlphaFactorbSUN
#define glGlobalAlphaFactorsSUN  OGL__glGlobalAlphaFactorsSUN
#define glGlobalAlphaFactoriSUN  OGL__glGlobalAlphaFactoriSUN
#define glGlobalAlphaFactorfSUN  OGL__glGlobalAlphaFactorfSUN
#define glGlobalAlphaFactordSUN  OGL__glGlobalAlphaFactordSUN
#define glGlobalAlphaFactorubSUN OGL__glGlobalAlphaFactorubSUN
#define glGlobalAlphaFactorusSUN OGL__glGlobalAlphaFactorusSUN
#define glGlobalAlphaFactoruiSUN OGL__glGlobalAlphaFactoruiSUN

#endif // GL_SUN_global_alpha

#endif // OPENGL_INCLUDE_GL_SUN_global_alpha

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SUN_mesh_array

#ifndef GL_SUN_mesh_array
#define GL_SUN_mesh_array 1

#define GL_QUAD_MESH_SUN        0x8614
#define GL_TRIANGLE_MESH_SUN    0x8615

OPENGL_INIT_PROC(glDrawMeshArraysSUN, void, GLenum mode, GLint first, GLsizei count, GLsizei width);
#define glDrawMeshArraysSUN OGL__glDrawMeshArraysSUN

#endif // GL_SUN_mesh_array

#endif // OPENGL_INCLUDE_GL_SUN_mesh_array

/* -------------------------------------------------------------------------- */

#ifndef GL_SUN_slice_accum
#define GL_SUN_slice_accum 1

#define GL_SLICE_ACCUM_SUN    0x85CC

#endif // GL_SUN_slice_accum

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SUN_triangle_list

#ifndef GL_SUN_triangle_list
#define GL_SUN_triangle_list 1

#define GL_RESTART_SUN                           0x0001
#define GL_REPLACE_MIDDLE_SUN                    0x0002
#define GL_REPLACE_OLDEST_SUN                    0x0003
#define GL_TRIANGLE_LIST_SUN                     0x81D7
#define GL_REPLACEMENT_CODE_SUN                  0x81D8
#define GL_REPLACEMENT_CODE_ARRAY_SUN            0x85C0
#define GL_REPLACEMENT_CODE_ARRAY_TYPE_SUN       0x85C1
#define GL_REPLACEMENT_CODE_ARRAY_STRIDE_SUN     0x85C2
#define GL_REPLACEMENT_CODE_ARRAY_POINTER_SUN    0x85C3
#define GL_R1UI_V3F_SUN                          0x85C4
#define GL_R1UI_C4UB_V3F_SUN                     0x85C5
#define GL_R1UI_C3F_V3F_SUN                      0x85C6
#define GL_R1UI_N3F_V3F_SUN                      0x85C7
#define GL_R1UI_C4F_N3F_V3F_SUN                  0x85C8
#define GL_R1UI_T2F_V3F_SUN                      0x85C9
#define GL_R1UI_T2F_N3F_V3F_SUN                  0x85CA
#define GL_R1UI_T2F_C4F_N3F_V3F_SUN              0x85CB

OPENGL_INIT_PROC(glReplacementCodeuiSUN,      void, GLuint code);
OPENGL_INIT_PROC(glReplacementCodeusSUN,      void, GLushort code);
OPENGL_INIT_PROC(glReplacementCodeubSUN,      void, GLubyte code);
OPENGL_INIT_PROC(glReplacementCodeuivSUN,     void, const GLuint *code);
OPENGL_INIT_PROC(glReplacementCodeusvSUN,     void, const GLushort *code);
OPENGL_INIT_PROC(glReplacementCodeubvSUN,     void, const GLubyte *code);
OPENGL_INIT_PROC(glReplacementCodePointerSUN, void, GLenum type, GLsizei stride, const void **pointer);

#define glReplacementCodeuiSUN      OGL__glReplacementCodeuiSUN
#define glReplacementCodeusSUN      OGL__glReplacementCodeusSUN
#define glReplacementCodeubSUN      OGL__glReplacementCodeubSUN
#define glReplacementCodeuivSUN     OGL__glReplacementCodeuivSUN
#define glReplacementCodeusvSUN     OGL__glReplacementCodeusvSUN
#define glReplacementCodeubvSUN     OGL__glReplacementCodeubvSUN
#define glReplacementCodePointerSUN OGL__glReplacementCodePointerSUN

#endif // GL_SUN_triangle_list

#endif // OPENGL_INCLUDE_GL_SUN_triangle_list

/* -------------------------------------------------------------------------- */

#ifdef OPENGL_INCLUDE_GL_SUN_vertex

#ifndef GL_SUN_vertex
#define GL_SUN_vertex 1

OPENGL_INIT_PROC(glColor4ubVertex2fSUN,                                    void, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y);
OPENGL_INIT_PROC(glColor4ubVertex2fvSUN,                                   void, const GLubyte *c, const GLfloat *v);
OPENGL_INIT_PROC(glColor4ubVertex3fSUN,                                    void, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glColor4ubVertex3fvSUN,                                   void, const GLubyte *c, const GLfloat *v);
OPENGL_INIT_PROC(glColor3fVertex3fSUN,                                     void, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glColor3fVertex3fvSUN,                                    void, const GLfloat *c, const GLfloat *v);
OPENGL_INIT_PROC(glNormal3fVertex3fSUN,                                    void, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glNormal3fVertex3fvSUN,                                   void, const GLfloat *n, const GLfloat *v);
OPENGL_INIT_PROC(glColor4fNormal3fVertex3fSUN,                             void, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glColor4fNormal3fVertex3fvSUN,                            void, const GLfloat *c, const GLfloat *n, const GLfloat *v);
OPENGL_INIT_PROC(glTexCoord2fVertex3fSUN,                                  void, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glTexCoord2fVertex3fvSUN,                                 void, const GLfloat *tc, const GLfloat *v);
OPENGL_INIT_PROC(glTexCoord4fVertex4fSUN,                                  void, GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
OPENGL_INIT_PROC(glTexCoord4fVertex4fvSUN,                                 void, const GLfloat *tc, const GLfloat *v);
OPENGL_INIT_PROC(glTexCoord2fColor4ubVertex3fSUN,                          void, GLfloat s, GLfloat t, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glTexCoord2fColor4ubVertex3fvSUN,                         void, const GLfloat *tc, const GLubyte *c, const GLfloat *v);
OPENGL_INIT_PROC(glTexCoord2fColor3fVertex3fSUN,                           void, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glTexCoord2fColor3fVertex3fvSUN,                          void, const GLfloat *tc, const GLfloat *c, const GLfloat *v);
OPENGL_INIT_PROC(glTexCoord2fNormal3fVertex3fSUN,                          void, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glTexCoord2fNormal3fVertex3fvSUN,                         void, const GLfloat *tc, const GLfloat *n, const GLfloat *v);
OPENGL_INIT_PROC(glTexCoord2fColor4fNormal3fVertex3fSUN,                   void, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glTexCoord2fColor4fNormal3fVertex3fvSUN,                  void, const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
OPENGL_INIT_PROC(glTexCoord4fColor4fNormal3fVertex4fSUN,                   void, GLfloat s, GLfloat t, GLfloat p, GLfloat q, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
OPENGL_INIT_PROC(glTexCoord4fColor4fNormal3fVertex4fvSUN,                  void, const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
OPENGL_INIT_PROC(glReplacementCodeuiVertex3fSUN,                           void, GLuint rc, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glReplacementCodeuiVertex3fvSUN,                          void, const GLuint *rc, const GLfloat *v);
OPENGL_INIT_PROC(glReplacementCodeuiColor4ubVertex3fSUN,                   void, GLuint rc, GLubyte r, GLubyte g, GLubyte b, GLubyte a, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glReplacementCodeuiColor4ubVertex3fvSUN,                  void, const GLuint *rc, const GLubyte *c, const GLfloat *v);
OPENGL_INIT_PROC(glReplacementCodeuiColor3fVertex3fSUN,                    void, GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glReplacementCodeuiColor3fVertex3fvSUN,                   void, const GLuint *rc, const GLfloat *c, const GLfloat *v);
OPENGL_INIT_PROC(glReplacementCodeuiNormal3fVertex3fSUN,                   void, GLuint rc, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glReplacementCodeuiNormal3fVertex3fvSUN,                  void, const GLuint *rc, const GLfloat *n, const GLfloat *v);
OPENGL_INIT_PROC(glReplacementCodeuiColor4fNormal3fVertex3fSUN,            void, GLuint rc, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glReplacementCodeuiColor4fNormal3fVertex3fvSUN,           void, const GLuint *rc, const GLfloat *c, const GLfloat *n, const GLfloat *v);
OPENGL_INIT_PROC(glReplacementCodeuiTexCoord2fVertex3fSUN,                 void, GLuint rc, GLfloat s, GLfloat t, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glReplacementCodeuiTexCoord2fVertex3fvSUN,                void, const GLuint *rc, const GLfloat *tc, const GLfloat *v);
OPENGL_INIT_PROC(glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN,         void, GLuint rc, GLfloat s, GLfloat t, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN,        void, const GLuint *rc, const GLfloat *tc, const GLfloat *n, const GLfloat *v);
OPENGL_INIT_PROC(glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN,  void, GLuint rc, GLfloat s, GLfloat t, GLfloat r, GLfloat g, GLfloat b, GLfloat a, GLfloat nx, GLfloat ny, GLfloat nz, GLfloat x, GLfloat y, GLfloat z);
OPENGL_INIT_PROC(glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN, void, const GLuint *rc, const GLfloat *tc, const GLfloat *c, const GLfloat *n, const GLfloat *v);

#define glColor4ubVertex2fSUN                                    OGL__glColor4ubVertex2fSUN
#define glColor4ubVertex2fvSUN                                   OGL__glColor4ubVertex2fvSUN
#define glColor4ubVertex3fSUN                                    OGL__glColor4ubVertex3fSUN
#define glColor4ubVertex3fvSUN                                   OGL__glColor4ubVertex3fvSUN
#define glColor3fVertex3fSUN                                     OGL__glColor3fVertex3fSUN
#define glColor3fVertex3fvSUN                                    OGL__glColor3fVertex3fvSUN
#define glNormal3fVertex3fSUN                                    OGL__glNormal3fVertex3fSUN
#define glNormal3fVertex3fvSUN                                   OGL__glNormal3fVertex3fvSUN
#define glColor4fNormal3fVertex3fSUN                             OGL__glColor4fNormal3fVertex3fSUN
#define glColor4fNormal3fVertex3fvSUN                            OGL__glColor4fNormal3fVertex3fvSUN
#define glTexCoord2fVertex3fSUN                                  OGL__glTexCoord2fVertex3fSUN
#define glTexCoord2fVertex3fvSUN                                 OGL__glTexCoord2fVertex3fvSUN
#define glTexCoord4fVertex4fSUN                                  OGL__glTexCoord4fVertex4fSUN
#define glTexCoord4fVertex4fvSUN                                 OGL__glTexCoord4fVertex4fvSUN
#define glTexCoord2fColor4ubVertex3fSUN                          OGL__glTexCoord2fColor4ubVertex3fSUN
#define glTexCoord2fColor4ubVertex3fvSUN                         OGL__glTexCoord2fColor4ubVertex3fvSUN
#define glTexCoord2fColor3fVertex3fSUN                           OGL__glTexCoord2fColor3fVertex3fSUN
#define glTexCoord2fColor3fVertex3fvSUN                          OGL__glTexCoord2fColor3fVertex3fvSUN
#define glTexCoord2fNormal3fVertex3fSUN                          OGL__glTexCoord2fNormal3fVertex3fSUN
#define glTexCoord2fNormal3fVertex3fvSUN                         OGL__glTexCoord2fNormal3fVertex3fvSUN
#define glTexCoord2fColor4fNormal3fVertex3fSUN                   OGL__glTexCoord2fColor4fNormal3fVertex3fSUN
#define glTexCoord2fColor4fNormal3fVertex3fvSUN                  OGL__glTexCoord2fColor4fNormal3fVertex3fvSUN
#define glTexCoord4fColor4fNormal3fVertex4fSUN                   OGL__glTexCoord4fColor4fNormal3fVertex4fSUN
#define glTexCoord4fColor4fNormal3fVertex4fvSUN                  OGL__glTexCoord4fColor4fNormal3fVertex4fvSUN
#define glReplacementCodeuiVertex3fSUN                           OGL__glReplacementCodeuiVertex3fSUN
#define glReplacementCodeuiVertex3fvSUN                          OGL__glReplacementCodeuiVertex3fvSUN
#define glReplacementCodeuiColor4ubVertex3fSUN                   OGL__glReplacementCodeuiColor4ubVertex3fSUN
#define glReplacementCodeuiColor4ubVertex3fvSUN                  OGL__glReplacementCodeuiColor4ubVertex3fvSUN
#define glReplacementCodeuiColor3fVertex3fSUN                    OGL__glReplacementCodeuiColor3fVertex3fSUN
#define glReplacementCodeuiColor3fVertex3fvSUN                   OGL__glReplacementCodeuiColor3fVertex3fvSUN
#define glReplacementCodeuiNormal3fVertex3fSUN                   OGL__glReplacementCodeuiNormal3fVertex3fSUN
#define glReplacementCodeuiNormal3fVertex3fvSUN                  OGL__glReplacementCodeuiNormal3fVertex3fvSUN
#define glReplacementCodeuiColor4fNormal3fVertex3fSUN            OGL__glReplacementCodeuiColor4fNormal3fVertex3fSUN
#define glReplacementCodeuiColor4fNormal3fVertex3fvSUN           OGL__glReplacementCodeuiColor4fNormal3fVertex3fvSUN
#define glReplacementCodeuiTexCoord2fVertex3fSUN                 OGL__glReplacementCodeuiTexCoord2fVertex3fSUN
#define glReplacementCodeuiTexCoord2fVertex3fvSUN                OGL__glReplacementCodeuiTexCoord2fVertex3fvSUN
#define glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN         OGL__glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN
#define glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN        OGL__glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN
#define glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN  OGL__glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN
#define glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN OGL__glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN

#endif // GL_SUN_vertex

#endif // OPENGL_INCLUDE_GL_SUN_vertex

/* -------------------------------------------------------------------------- */

#ifndef GL_WIN_phong_shading
#define GL_WIN_phong_shading 1

#define GL_PHONG_WIN         0x80EA
#define GL_PHONG_HINT_WIN    0x80EB

#endif // GL_WIN_phong_shading

/* -------------------------------------------------------------------------- */

#ifndef GL_WIN_specular_fog
#define GL_WIN_specular_fog 1

#define GL_FOG_SPECULAR_TEXTURE_WIN    0x80EC

#endif // GL_WIN_specular_fog

/* -------------------------------------------------------------------------- */

EXTERN_C_END /*****************************************************************/

/* -------------------------------------------------------------------------- */

/*////////////////////////////////////////////////////////////////////////////*/

#endif /* GL_H__ /////////////////////////////////////////////////////////////*/

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
