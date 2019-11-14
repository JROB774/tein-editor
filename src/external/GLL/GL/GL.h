/*******************************************************************************
 * Modified version of GL headers providing the compatibility GL functionality.
 * Copyright (c) 2013-2018 The Khronos Group Inc.
 * Authored By The Khronos Group (Modifications By Joshua Robertson)
 *
*******************************************************************************/

/*============================================================================*/
/*============================ OpenGL Version 4.6 ============================*/
/*============================================================================*/

#ifndef __GLL_GL_H__ /*///////////////////////////////////////////////////////*/
#define __GLL_GL_H__

/* -------------------------------------------------------------------------- */

#ifndef __gl_h__
#define __gl_h__
#endif
#ifndef __GL_H__
#define __GL_H__
#endif

/* -------------------------------------------------------------------------- */

#ifndef APIENTRY
#define APIENTRY
#endif
#ifndef APIENTRYP
#define APIENTRYP APIENTRY*
#endif
#ifndef GLAPI
#define GLAPI extern
#endif

/* -------------------------------------------------------------------------- */

#ifdef __cplusplus
extern "C" {
#endif

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

/* -------------------------------------------------------------------------- */

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

GLL_INITPROC(glCullFace,               void,           GLenum mode);
GLL_INITPROC(glFrontFace,              void,           GLenum mode);
GLL_INITPROC(glHint,                   void,           GLenum target, GLenum mode);
GLL_INITPROC(glLineWidth,              void,           GLfloat width);
GLL_INITPROC(glPointSize,              void,           GLfloat size);
GLL_INITPROC(glPolygonMode,            void,           GLenum face, GLenum mode);
GLL_INITPROC(glScissor,                void,           GLint x, GLint y, GLsizei width, GLsizei height);
GLL_INITPROC(glTexParameterf,          void,           GLenum target, GLenum pname, GLfloat param);
GLL_INITPROC(glTexParameterfv,         void,           GLenum target, GLenum pname, const GLfloat *params);
GLL_INITPROC(glTexParameteri,          void,           GLenum target, GLenum pname, GLint param);
GLL_INITPROC(glTexParameteriv,         void,           GLenum target, GLenum pname, const GLint *params);
GLL_INITPROC(glTexImage1D,             void,           GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
GLL_INITPROC(glTexImage2D,             void,           GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
GLL_INITPROC(glDrawBuffer,             void,           GLenum buf);
GLL_INITPROC(glClear,                  void,           GLbitfield mask);
GLL_INITPROC(glClearColor,             void,           GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLL_INITPROC(glClearStencil,           void,           GLint s);
GLL_INITPROC(glClearDepth,             void,           GLdouble depth);
GLL_INITPROC(glStencilMask,            void,           GLuint mask);
GLL_INITPROC(glColorMask,              void,           GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
GLL_INITPROC(glDepthMask,              void,           GLboolean flag);
GLL_INITPROC(glDisable,                void,           GLenum cap);
GLL_INITPROC(glEnable,                 void,           GLenum cap);
GLL_INITPROC(glFinish,                 void,           void);
GLL_INITPROC(glFlush,                  void,           void);
GLL_INITPROC(glBlendFunc,              void,           GLenum sfactor, GLenum dfactor);
GLL_INITPROC(glLogicOp,                void,           GLenum opcode);
GLL_INITPROC(glStencilFunc,            void,           GLenum func, GLint ref, GLuint mask);
GLL_INITPROC(glStencilOp,              void,           GLenum fail, GLenum zfail, GLenum zpass);
GLL_INITPROC(glDepthFunc,              void,           GLenum func);
GLL_INITPROC(glPixelStoref,            void,           GLenum pname, GLfloat param);
GLL_INITPROC(glPixelStorei,            void,           GLenum pname, GLint param);
GLL_INITPROC(glReadBuffer,             void,           GLenum src);
GLL_INITPROC(glReadPixels,             void,           GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
GLL_INITPROC(glGetBooleanv,            void,           GLenum pname, GLboolean *data);
GLL_INITPROC(glGetDoublev,             void,           GLenum pname, GLdouble *data);
GLL_INITPROC(glGetError,               GLenum,         void);
GLL_INITPROC(glGetFloatv,              void,           GLenum pname, GLfloat *data);
GLL_INITPROC(glGetIntegerv,            void,           GLenum pname, GLint *data);
GLL_INITPROC(glGetString,              const GLubyte*, GLenum name);
GLL_INITPROC(glGetTexImage,            void,           GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
GLL_INITPROC(glGetTexParameterfv,      void,           GLenum target, GLenum pname, GLfloat *params);
GLL_INITPROC(glGetTexParameteriv,      void,           GLenum target, GLenum pname, GLint *params);
GLL_INITPROC(glGetTexLevelParameterfv, void,           GLenum target, GLint level, GLenum pname, GLfloat *params);
GLL_INITPROC(glGetTexLevelParameteriv, void,           GLenum target, GLint level, GLenum pname, GLint *params);
GLL_INITPROC(glIsEnabled,              GLboolean,      GLenum cap);
GLL_INITPROC(glDepthRange,             void,           GLdouble n, GLdouble f);
GLL_INITPROC(glViewport,               void,           GLint x, GLint y, GLsizei width, GLsizei height);
GLL_INITPROC(glNewList,                void,           GLuint list, GLenum mode);
GLL_INITPROC(glEndList,                void,           void);
GLL_INITPROC(glCallList,               void,           GLuint list);
GLL_INITPROC(glCallLists,              void,           GLsizei n, GLenum type, const void *lists);
GLL_INITPROC(glDeleteLists,            void,           GLuint list, GLsizei range);
GLL_INITPROC(glGenLists,               GLuint,         GLsizei range);
GLL_INITPROC(glListBase,               void,           GLuint base);
GLL_INITPROC(glBegin,                  void,           GLenum mode);
GLL_INITPROC(glBitmap,                 void,           GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte *bitmap);
GLL_INITPROC(glColor3b,                void,           GLbyte red, GLbyte green, GLbyte blue);
GLL_INITPROC(glColor3bv,               void,           const GLbyte *v);
GLL_INITPROC(glColor3d,                void,           GLdouble red, GLdouble green, GLdouble blue);
GLL_INITPROC(glColor3dv,               void,           const GLdouble *v);
GLL_INITPROC(glColor3f,                void,           GLfloat red, GLfloat green, GLfloat blue);
GLL_INITPROC(glColor3fv,               void,           const GLfloat *v);
GLL_INITPROC(glColor3i,                void,           GLint red, GLint green, GLint blue);
GLL_INITPROC(glColor3iv,               void,           const GLint *v);
GLL_INITPROC(glColor3s,                void,           GLshort red, GLshort green, GLshort blue);
GLL_INITPROC(glColor3sv,               void,           const GLshort *v);
GLL_INITPROC(glColor3ub,               void,           GLubyte red, GLubyte green, GLubyte blue);
GLL_INITPROC(glColor3ubv,              void,           const GLubyte *v);
GLL_INITPROC(glColor3ui,               void,           GLuint red, GLuint green, GLuint blue);
GLL_INITPROC(glColor3uiv,              void,           const GLuint *v);
GLL_INITPROC(glColor3us,               void,           GLushort red, GLushort green, GLushort blue);
GLL_INITPROC(glColor3usv,              void,           const GLushort *v);
GLL_INITPROC(glColor4b,                void,           GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha);
GLL_INITPROC(glColor4bv,               void,           const GLbyte *v);
GLL_INITPROC(glColor4d,                void,           GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha);
GLL_INITPROC(glColor4dv,               void,           const GLdouble *v);
GLL_INITPROC(glColor4f,                void,           GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLL_INITPROC(glColor4fv,               void,           const GLfloat *v);
GLL_INITPROC(glColor4i,                void,           GLint red, GLint green, GLint blue, GLint alpha);
GLL_INITPROC(glColor4iv,               void,           const GLint *v);
GLL_INITPROC(glColor4s,                void,           GLshort red, GLshort green, GLshort blue, GLshort alpha);
GLL_INITPROC(glColor4sv,               void,           const GLshort *v);
GLL_INITPROC(glColor4ub,               void,           GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha);
GLL_INITPROC(glColor4ubv,              void,           const GLubyte *v);
GLL_INITPROC(glColor4ui,               void,           GLuint red, GLuint green, GLuint blue, GLuint alpha);
GLL_INITPROC(glColor4uiv,              void,           const GLuint *v);
GLL_INITPROC(glColor4us,               void,           GLushort red, GLushort green, GLushort blue, GLushort alpha);
GLL_INITPROC(glColor4usv,              void,           const GLushort *v);
GLL_INITPROC(glEdgeFlag,               void,           GLboolean flag);
GLL_INITPROC(glEdgeFlagv,              void,           const GLboolean *flag);
GLL_INITPROC(glEnd,                    void,           void);
GLL_INITPROC(glIndexd,                 void,           GLdouble c);
GLL_INITPROC(glIndexdv,                void,           const GLdouble *c);
GLL_INITPROC(glIndexf,                 void,           GLfloat c);
GLL_INITPROC(glIndexfv,                void,           const GLfloat *c);
GLL_INITPROC(glIndexi,                 void,           GLint c);
GLL_INITPROC(glIndexiv,                void,           const GLint *c);
GLL_INITPROC(glIndexs,                 void,           GLshort c);
GLL_INITPROC(glIndexsv,                void,           const GLshort *c);
GLL_INITPROC(glNormal3b,               void,           GLbyte nx, GLbyte ny, GLbyte nz);
GLL_INITPROC(glNormal3bv,              void,           const GLbyte *v);
GLL_INITPROC(glNormal3d,               void,           GLdouble nx, GLdouble ny, GLdouble nz);
GLL_INITPROC(glNormal3dv,              void,           const GLdouble *v);
GLL_INITPROC(glNormal3f,               void,           GLfloat nx, GLfloat ny, GLfloat nz);
GLL_INITPROC(glNormal3fv,              void,           const GLfloat *v);
GLL_INITPROC(glNormal3i,               void,           GLint nx, GLint ny, GLint nz);
GLL_INITPROC(glNormal3uv,              void,           const GLint *v);
GLL_INITPROC(glNormal3s,               void,           GLshort nx, GLshort ny, GLshort nz);
GLL_INITPROC(glNormal3sv,              void,           const GLshort *v);
GLL_INITPROC(glRasterPos2d,            void,           GLdouble x, GLdouble y);
GLL_INITPROC(glRasterPos2dv,           void,           const GLdouble *v);
GLL_INITPROC(glRasterPos2f,            void,           GLfloat x, GLfloat y);
GLL_INITPROC(glRasterPos2fv,           void,           const GLfloat *v);
GLL_INITPROC(glRasterPos2i,            void,           GLint x, GLint y);
GLL_INITPROC(glRasterPos2iv,           void,           const GLint *v);
GLL_INITPROC(glRasterPos2s,            void,           GLshort x, GLshort y);
GLL_INITPROC(glRasterPos2sv,           void,           const GLshort *v);
GLL_INITPROC(glRasterPos3d,            void,           GLdouble x, GLdouble y, GLdouble z);
GLL_INITPROC(glRasterPos3dv,           void,           const GLdouble *v);
GLL_INITPROC(glRasterPos3f,            void,           GLfloat x, GLfloat y, GLfloat z);
GLL_INITPROC(glRasterPos3fv,           void,           const GLfloat *v);
GLL_INITPROC(glRasterPos3i,            void,           GLint x, GLint y, GLint z);
GLL_INITPROC(glRasterPos3iv,           void,           const GLint *v);
GLL_INITPROC(glRasterPos3s,            void,           GLshort x, GLshort y, GLshort z);
GLL_INITPROC(glRasterPos3sv,           void,           const GLshort *v);
GLL_INITPROC(glRasterPos4d,            void,           GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLL_INITPROC(glRasterPos4dv,           void,           const GLdouble *v);
GLL_INITPROC(glRasterPos4f,            void,           GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLL_INITPROC(glRasterPos4fv,           void,           const GLfloat *v);
GLL_INITPROC(glRasterPos4i,            void,           GLint x, GLint y, GLint z, GLint w);
GLL_INITPROC(glRasterPos4iv,           void,           const GLint *v);
GLL_INITPROC(glRasterPos4s,            void,           GLshort x, GLshort y, GLshort z, GLshort w);
GLL_INITPROC(glRasterPos4sv,           void,           const GLshort *v);
GLL_INITPROC(glRectd,                  void,           GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2);
GLL_INITPROC(glRectdv,                 void,           const GLdouble *v1, const GLdouble *v2);
GLL_INITPROC(glRectf,                  void,           GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2);
GLL_INITPROC(glRectfv,                 void,           const GLfloat *v1, const GLfloat *v2);
GLL_INITPROC(glRecti,                  void,           GLint x1, GLint y1, GLint x2, GLint y2);
GLL_INITPROC(glRectiv,                 void,           const GLint *v1, const GLint *v2);
GLL_INITPROC(glRects,                  void,           GLshort x1, GLshort y1, GLshort x2, GLshort y2);
GLL_INITPROC(glRectsv,                 void,           const GLshort *v1, const GLshort *v2);
GLL_INITPROC(glTexCoord1d,             void,           GLdouble s);
GLL_INITPROC(glTexCoord1dv,            void,           const GLdouble *v);
GLL_INITPROC(glTexCoord1f,             void,           GLfloat s);
GLL_INITPROC(glTexCoord1fv,            void,           const GLfloat *v);
GLL_INITPROC(glTexCoord1i,             void,           GLint s);
GLL_INITPROC(glTexCoord1iv,            void,           const GLint *v);
GLL_INITPROC(glTexCoord1s,             void,           GLshort s);
GLL_INITPROC(glTexCoord1sv,            void,           const GLshort *v);
GLL_INITPROC(glTexCoord2d,             void,           GLdouble s, GLdouble t);
GLL_INITPROC(glTexCoord2dv,            void,           const GLdouble *v);
GLL_INITPROC(glTexCoord2f,             void,           GLfloat s, GLfloat t);
GLL_INITPROC(glTexCoord2fv,            void,           const GLfloat *v);
GLL_INITPROC(glTexCoord2i,             void,           GLint s, GLint t);
GLL_INITPROC(glTexCoord2iv,            void,           const GLint *v);
GLL_INITPROC(glTexCoord2s,             void,           GLshort s, GLshort t);
GLL_INITPROC(glTexCoord2sv,            void,           const GLshort *v);
GLL_INITPROC(glTexCoord3d,             void,           GLdouble s, GLdouble t, GLdouble r);
GLL_INITPROC(glTexCoord3dv,            void,           const GLdouble *v);
GLL_INITPROC(glTexCoord3f,             void,           GLfloat s, GLfloat t, GLfloat r);
GLL_INITPROC(glTexCoord3fv,            void,           const GLfloat *v);
GLL_INITPROC(glTexCoord3i,             void,           GLint s, GLint t, GLint r);
GLL_INITPROC(glTexCoord3iv,            void,           const GLint *v);
GLL_INITPROC(glTexCoord3s,             void,           GLshort s, GLshort t, GLshort r);
GLL_INITPROC(glTexCoord3sv,            void,           const GLshort *v);
GLL_INITPROC(glTexCoord4d,             void,           GLdouble s, GLdouble t, GLdouble r, GLdouble q);
GLL_INITPROC(glTexCoord4dv,            void,           const GLdouble *v);
GLL_INITPROC(glTexCoord4f,             void,           GLfloat s, GLfloat t, GLfloat r, GLfloat q);
GLL_INITPROC(glTexCoord4fv,            void,           const GLfloat *v);
GLL_INITPROC(glTexCoord4i,             void,           GLint s, GLint t, GLint r, GLint q);
GLL_INITPROC(glTexCoord4iv,            void,           const GLint *v);
GLL_INITPROC(glTexCoord4s,             void,           GLshort s, GLshort t, GLshort r, GLshort q);
GLL_INITPROC(glTexCoord4sv,            void,           const GLshort *v);
GLL_INITPROC(glVertex2d,               void,           GLdouble x, GLdouble y);
GLL_INITPROC(glVertex2dv,              void,           const GLdouble *v);
GLL_INITPROC(glVertex2f,               void,           GLfloat x, GLfloat y);
GLL_INITPROC(glVertex2fv,              void,           const GLfloat *v);
GLL_INITPROC(glVertex2i,               void,           GLint x, GLint y);
GLL_INITPROC(glVertex2iv,              void,           const GLint *v);
GLL_INITPROC(glVertex2s,               void,           GLshort x, GLshort y);
GLL_INITPROC(glVertex2sv,              void,           const GLshort *v);
GLL_INITPROC(glVertex3d,               void,           GLdouble x, GLdouble y, GLdouble z);
GLL_INITPROC(glVertex3dv,              void,           const GLdouble *v);
GLL_INITPROC(glVertex3f,               void,           GLfloat x, GLfloat y, GLfloat z);
GLL_INITPROC(glVertex3fv,              void,           const GLfloat *v);
GLL_INITPROC(glVertex3i,               void,           GLint x, GLint y, GLint z);
GLL_INITPROC(glVertex3iv,              void,           const GLint *v);
GLL_INITPROC(glVertex3s,               void,           GLshort x, GLshort y, GLshort z);
GLL_INITPROC(glVertex3sv,              void,           const GLshort *v);
GLL_INITPROC(glVertex4d,               void,           GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLL_INITPROC(glVertex4dv,              void,           const GLdouble *v);
GLL_INITPROC(glVertex4f,               void,           GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLL_INITPROC(glVertex4fv,              void,           const GLfloat *v);
GLL_INITPROC(glVertex4i,               void,           GLint x, GLint y, GLint z, GLint w);
GLL_INITPROC(glVertex4iv,              void,           const GLint *v);
GLL_INITPROC(glVertex4s,               void,           GLshort x, GLshort y, GLshort z, GLshort w);
GLL_INITPROC(glVertex4sv,              void,           const GLshort *v);
GLL_INITPROC(glClipPlane,              void,           GLenum plane, const GLdouble *equation);
GLL_INITPROC(glColorMaterial,          void,           GLenum face, GLenum mode);
GLL_INITPROC(glFogf,                   void,           GLenum pname, GLfloat param);
GLL_INITPROC(glFogfv,                  void,           GLenum pname, const GLfloat *params);
GLL_INITPROC(glFogi,                   void,           GLenum pname, GLint param);
GLL_INITPROC(glFogiv,                  void,           GLenum pname, const GLint *params);
GLL_INITPROC(glLightf,                 void,           GLenum light, GLenum pname, GLfloat param);
GLL_INITPROC(glLightfv,                void,           GLenum light, GLenum pname, const GLfloat *params);
GLL_INITPROC(glLighti,                 void,           GLenum light, GLenum pname, GLint param);
GLL_INITPROC(glLightiv,                void,           GLenum light, GLenum pname, const GLint *params);
GLL_INITPROC(glLightModelf,            void,           GLenum pname, GLfloat param);
GLL_INITPROC(glLightModelfv,           void,           GLenum pname, const GLfloat *params);
GLL_INITPROC(glLightModeli,            void,           GLenum pname, GLint param);
GLL_INITPROC(glLightModeliv,           void,           GLenum pname, const GLint *params);
GLL_INITPROC(glLineStipple,            void,           GLint factor, GLushort pattern);
GLL_INITPROC(glMaterialf,              void,           GLenum face, GLenum pname, GLfloat param);
GLL_INITPROC(glMaterialfv,             void,           GLenum face, GLenum pname, const GLfloat *params);
GLL_INITPROC(glMateriali,              void,           GLenum face, GLenum pname, GLint param);
GLL_INITPROC(glMaterialiv,             void,           GLenum face, GLenum pname, const GLint *params);
GLL_INITPROC(glPolygonStipple,         void,           const GLubyte *mask);
GLL_INITPROC(glShadeModel,             void,           GLenum mode);
GLL_INITPROC(glTexEnvf,                void,           GLenum target, GLenum pname, GLfloat param);
GLL_INITPROC(glTexEnvfv,               void,           GLenum target, GLenum pname, const GLfloat *params);
GLL_INITPROC(glTexEnvi,                void,           GLenum target, GLenum pname, GLint param);
GLL_INITPROC(glTexEnviv,               void,           GLenum target, GLenum pname, const GLint *params);
GLL_INITPROC(glTexGend,                void,           GLenum coord, GLenum pname, GLdouble param);
GLL_INITPROC(glTexGendv,               void,           GLenum coord, GLenum pname, const GLdouble *params);
GLL_INITPROC(glTexGenf,                void,           GLenum coord, GLenum pname, GLfloat param);
GLL_INITPROC(glTexGenfv,               void,           GLenum coord, GLenum pname, const GLfloat *params);
GLL_INITPROC(glTexGeni,                void,           GLenum coord, GLenum pname, GLint param);
GLL_INITPROC(glTexGeniv,               void,           GLenum coord, GLenum pname, const GLint *params);
GLL_INITPROC(glFeedbackBuffer,         void,           GLsizei size, GLenum type, GLfloat *buffer);
GLL_INITPROC(glSelectBuffer,           void,           GLsizei size, GLuint *buffer);
GLL_INITPROC(glRenderMode,             GLint,          GLenum mode);
GLL_INITPROC(glInitNames,              void,           void);
GLL_INITPROC(glLoadName,               void,           GLuint name);
GLL_INITPROC(glPassThrough,            void,           GLfloat token);
GLL_INITPROC(glPopName,                void,           void);
GLL_INITPROC(glPushName,               void,           GLuint name);
GLL_INITPROC(glClearAccum,             void,           GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLL_INITPROC(glClearIndex,             void,           GLfloat c);
GLL_INITPROC(glIndexMask,              void,           GLuint mask);
GLL_INITPROC(glAccum,                  void,           GLenum op, GLfloat value);
GLL_INITPROC(glPopAttrib,              void,           void);
GLL_INITPROC(glPushAttrib,             void,           GLbitfield mask);
GLL_INITPROC(glMap1d,                  void,           GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble *points);
GLL_INITPROC(glMap1f,                  void,           GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat *points);
GLL_INITPROC(glMap2d,                  void,           GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble *points);
GLL_INITPROC(glMap2f,                  void,           GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat *points);
GLL_INITPROC(glMapGrid1d,              void,           GLint un, GLdouble u1, GLdouble u2);
GLL_INITPROC(glMapGrid1f,              void,           GLint un, GLfloat u1, GLfloat u2);
GLL_INITPROC(glMapGrid2d,              void,           GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2);
GLL_INITPROC(glMapGrid2f,              void,           GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2);
GLL_INITPROC(glEvalCoord1d,            void,           GLdouble u);
GLL_INITPROC(glEvalCoord1dv,           void,           const GLdouble *u);
GLL_INITPROC(glEvalCoord1f,            void,           GLfloat u);
GLL_INITPROC(glEvalCoord1fv,           void,           const GLfloat *u);
GLL_INITPROC(glEvalCoord2d,            void,           GLdouble u, GLdouble v);
GLL_INITPROC(glEvalCoord2dv,           void,           const GLdouble *u);
GLL_INITPROC(glEvalCoord2f,            void,           GLfloat u, GLfloat v);
GLL_INITPROC(glEvalCoord2fv,           void,           const GLfloat *u);
GLL_INITPROC(glEvalMesh1,              void,           GLenum mode, GLint i1, GLint i2);
GLL_INITPROC(glEvalPoint1,             void,           GLint i);
GLL_INITPROC(glEvalMesh2,              void,           GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2);
GLL_INITPROC(glEvalPoint2,             void,           GLint i, GLint j);
GLL_INITPROC(glAlphaFunc,              void,           GLenum func, GLfloat ref);
GLL_INITPROC(glPixelZoom,              void,           GLfloat xfactor, GLfloat yfactor);
GLL_INITPROC(glPixelTransferf,         void,           GLenum pname, GLfloat param);
GLL_INITPROC(glPixelTransferi,         void,           GLenum pname, GLint param);
GLL_INITPROC(glPixelMapfv,             void,           GLenum map, GLsizei mapsize, const GLfloat *values);
GLL_INITPROC(glPixelMapuiv,            void,           GLenum map, GLsizei mapsize, const GLuint *values);
GLL_INITPROC(glPixelMapusv,            void,           GLenum map, GLsizei mapsize, const GLushort *values);
GLL_INITPROC(glCopyPixels,             void,           GLint x, GLint y, GLsizei width, GLsizei height, GLenum type);
GLL_INITPROC(glDrawPixels,             void,           GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLL_INITPROC(glGetClipPlane,           void,           GLenum plane, GLdouble *equation);
GLL_INITPROC(glGetLightfv,             void,           GLenum light, GLenum pname, GLfloat *params);
GLL_INITPROC(glGetLightiv,             void,           GLenum light, GLenum pname, GLint *params);
GLL_INITPROC(glGetMapdv,               void,           GLenum target, GLenum query, GLdouble *v);
GLL_INITPROC(glGetMapfv,               void,           GLenum target, GLenum query, GLfloat *v);
GLL_INITPROC(glGetMapiv,               void,           GLenum target, GLenum query, GLint *v);
GLL_INITPROC(glGetMaterialfv,          void,           GLenum face, GLenum pname, GLfloat *params);
GLL_INITPROC(glGetMaterialiv,          void,           GLenum face, GLenum pname, GLint *params);
GLL_INITPROC(glGetPixelMapfv,          void,           GLenum map, GLfloat *values);
GLL_INITPROC(glGetPixelMapuiv,         void,           GLenum map, GLuint *values);
GLL_INITPROC(glGetPixelMapusv,         void,           GLenum map, GLushort *values);
GLL_INITPROC(glGetPolygonStipple,      void,           GLubyte *mask);
GLL_INITPROC(glGetTexEnvfv,            void,           GLenum target, GLenum pname, GLfloat *params);
GLL_INITPROC(glGetTexEnviv,            void,           GLenum target, GLenum pname, GLint *params);
GLL_INITPROC(glGetTexGendv,            void,           GLenum coord, GLenum pname, GLdouble *params);
GLL_INITPROC(glGetTexGenfv,            void,           GLenum coord, GLenum pname, GLfloat *params);
GLL_INITPROC(glGetTexGeniv,            void,           GLenum coord, GLenum pname, GLint *params);
GLL_INITPROC(glIsList,                 GLboolean,      GLuint list);
GLL_INITPROC(glFrustum,                void,           GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
GLL_INITPROC(glLoadIdentity,           void,           void);
GLL_INITPROC(glLoadMatrixf,            void,           const GLfloat *m);
GLL_INITPROC(glLoadMatrixd,            void,           const GLdouble *m);
GLL_INITPROC(glMatrixMode,             void,           GLenum mode);
GLL_INITPROC(glMultMatrixf,            void,           const GLfloat *m);
GLL_INITPROC(glMultMatrixd,            void,           const GLdouble *m);
GLL_INITPROC(glOrtho,                  void,           GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar);
GLL_INITPROC(glPopMatrix,              void,           void);
GLL_INITPROC(glPushMatrix,             void,           void);
GLL_INITPROC(glRotated,                void,           GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
GLL_INITPROC(glRotatef,                void,           GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
GLL_INITPROC(glScaled,                 void,           GLdouble x, GLdouble y, GLdouble z);
GLL_INITPROC(glScalef,                 void,           GLfloat x, GLfloat y, GLfloat z);
GLL_INITPROC(glTranslated,             void,           GLdouble x, GLdouble y, GLdouble z);
GLL_INITPROC(glTranslatef,             void,           GLfloat x, GLfloat y, GLfloat z);

#define glCullFace               GLL_glCullFace
#define glFrontFace              GLL_glFrontFace
#define glHint                   GLL_glHint
#define glLineWidth              GLL_glLineWidth
#define glPointSize              GLL_glPointSize
#define glPolygonMode            GLL_glPolygonMode
#define glScissor                GLL_glScissor
#define glTexParameterf          GLL_glTexParameterf
#define glTexParameterfv         GLL_glTexParameterfv
#define glTexParameteri          GLL_glTexParameteri
#define glTexParameteriv         GLL_glTexParameteriv
#define glTexImage1D             GLL_glTexImage1D
#define glTexImage2D             GLL_glTexImage2D
#define glDrawBuffer             GLL_glDrawBuffer
#define glClear                  GLL_glClear
#define glClearColor             GLL_glClearColor
#define glClearStencil           GLL_glClearStencil
#define glClearDepth             GLL_glClearDepth
#define glStencilMask            GLL_glStencilMask
#define glColorMask              GLL_glColorMask
#define glDepthMask              GLL_glDepthMask
#define glDisable                GLL_glDisable
#define glEnable                 GLL_glEnable
#define glFinish                 GLL_glFinish
#define glFlush                  GLL_glFlush
#define glBlendFunc              GLL_glBlendFunc
#define glLogicOp                GLL_glLogicOp
#define glStencilFunc            GLL_glStencilFunc
#define glStencilOp              GLL_glStencilOp
#define glDepthFunc              GLL_glDepthFunc
#define glPixelStoref            GLL_glPixelStoref
#define glPixelStorei            GLL_glPixelStorei
#define glReadBuffer             GLL_glReadBuffer
#define glReadPixels             GLL_glReadPixels
#define glGetBooleanv            GLL_glGetBooleanv
#define glGetDoublev             GLL_glGetDoublev
#define glGetError               GLL_glGetError
#define glGetFloatv              GLL_glGetFloatv
#define glGetIntegerv            GLL_glGetIntegerv
#define glGetString              GLL_glGetString
#define glGetTexImage            GLL_glGetTexImage
#define glGetTexParameterfv      GLL_glGetTexParameterfv
#define glGetTexParameteriv      GLL_glGetTexParameteriv
#define glGetTexLevelParameterfv GLL_glGetTexLevelParameterfv
#define glGetTexLevelParameteriv GLL_glGetTexLevelParameteriv
#define glIsEnabled              GLL_glIsEnabled
#define glDepthRange             GLL_glDepthRange
#define glViewport               GLL_glViewport
#define glNewList                GLL_glNewList
#define glEndList                GLL_glEndList
#define glCallList               GLL_glCallList
#define glCallLists              GLL_glCallLists
#define glDeleteLists            GLL_glDeleteLists
#define glGenLists               GLL_glGenLists
#define glListBase               GLL_glListBase
#define glBegin                  GLL_glBegin
#define glBitmap                 GLL_glBitmap
#define glColor3b                GLL_glColor3b
#define glColor3bv               GLL_glColor3bv
#define glColor3d                GLL_glColor3d
#define glColor3dv               GLL_glColor3dv
#define glColor3f                GLL_glColor3f
#define glColor3fv               GLL_glColor3fv
#define glColor3i                GLL_glColor3i
#define glColor3iv               GLL_glColor3iv
#define glColor3s                GLL_glColor3s
#define glColor3sv               GLL_glColor3sv
#define glColor3ub               GLL_glColor3ub
#define glColor3ubv              GLL_glColor3ubv
#define glColor3ui               GLL_glColor3ui
#define glColor3uiv              GLL_glColor3uiv
#define glColor3us               GLL_glColor3us
#define glColor3usv              GLL_glColor3usv
#define glColor4b                GLL_glColor4b
#define glColor4bv               GLL_glColor4bv
#define glColor4d                GLL_glColor4d
#define glColor4dv               GLL_glColor4dv
#define glColor4f                GLL_glColor4f
#define glColor4fv               GLL_glColor4fv
#define glColor4i                GLL_glColor4i
#define glColor4iv               GLL_glColor4iv
#define glColor4s                GLL_glColor4s
#define glColor4sv               GLL_glColor4sv
#define glColor4ub               GLL_glColor4ub
#define glColor4ubv              GLL_glColor4ubv
#define glColor4ui               GLL_glColor4ui
#define glColor4uiv              GLL_glColor4uiv
#define glColor4us               GLL_glColor4us
#define glColor4usv              GLL_glColor4usv
#define glEdgeFlag               GLL_glEdgeFlag
#define glEdgeFlagv              GLL_glEdgeFlagv
#define glEnd                    GLL_glEnd
#define glIndexd                 GLL_glIndexd
#define glIndexdv                GLL_glIndexdv
#define glIndexf                 GLL_glIndexf
#define glIndexfv                GLL_glIndexfv
#define glIndexi                 GLL_glIndexi
#define glIndexiv                GLL_glIndexiv
#define glIndexs                 GLL_glIndexs
#define glIndexsv                GLL_glIndexsv
#define glNormal3b               GLL_glNormal3b
#define glNormal3bv              GLL_glNormal3bv
#define glNormal3d               GLL_glNormal3d
#define glNormal3dv              GLL_glNormal3dv
#define glNormal3f               GLL_glNormal3f
#define glNormal3fv              GLL_glNormal3fv
#define glNormal3i               GLL_glNormal3i
#define glNormal3uv              GLL_glNormal3uv
#define glNormal3s               GLL_glNormal3s
#define glNormal3sv              GLL_glNormal3sv
#define glRasterPos2d            GLL_glRasterPos2d
#define glRasterPos2dv           GLL_glRasterPos2dv
#define glRasterPos2f            GLL_glRasterPos2f
#define glRasterPos2fv           GLL_glRasterPos2fv
#define glRasterPos2i            GLL_glRasterPos2i
#define glRasterPos2iv           GLL_glRasterPos2iv
#define glRasterPos2s            GLL_glRasterPos2s
#define glRasterPos2sv           GLL_glRasterPos2sv
#define glRasterPos3d            GLL_glRasterPos3d
#define glRasterPos3dv           GLL_glRasterPos3dv
#define glRasterPos3f            GLL_glRasterPos3f
#define glRasterPos3fv           GLL_glRasterPos3fv
#define glRasterPos3i            GLL_glRasterPos3i
#define glRasterPos3iv           GLL_glRasterPos3iv
#define glRasterPos3s            GLL_glRasterPos3s
#define glRasterPos3sv           GLL_glRasterPos3sv
#define glRasterPos4d            GLL_glRasterPos4d
#define glRasterPos4dv           GLL_glRasterPos4dv
#define glRasterPos4f            GLL_glRasterPos4f
#define glRasterPos4fv           GLL_glRasterPos4fv
#define glRasterPos4i            GLL_glRasterPos4i
#define glRasterPos4iv           GLL_glRasterPos4iv
#define glRasterPos4s            GLL_glRasterPos4s
#define glRasterPos4sv           GLL_glRasterPos4sv
#define glRectd                  GLL_glRectd
#define glRectdv                 GLL_glRectdv
#define glRectf                  GLL_glRectf
#define glRectfv                 GLL_glRectfv
#define glRecti                  GLL_glRecti
#define glRectiv                 GLL_glRectiv
#define glRects                  GLL_glRects
#define glRectsv                 GLL_glRectsv
#define glTexCoord1d             GLL_glTexCoord1d
#define glTexCoord1dv            GLL_glTexCoord1dv
#define glTexCoord1f             GLL_glTexCoord1f
#define glTexCoord1fv            GLL_glTexCoord1fv
#define glTexCoord1i             GLL_glTexCoord1i
#define glTexCoord1iv            GLL_glTexCoord1iv
#define glTexCoord1s             GLL_glTexCoord1s
#define glTexCoord1sv            GLL_glTexCoord1sv
#define glTexCoord2d             GLL_glTexCoord2d
#define glTexCoord2dv            GLL_glTexCoord2dv
#define glTexCoord2f             GLL_glTexCoord2f
#define glTexCoord2fv            GLL_glTexCoord2fv
#define glTexCoord2i             GLL_glTexCoord2i
#define glTexCoord2iv            GLL_glTexCoord2iv
#define glTexCoord2s             GLL_glTexCoord2s
#define glTexCoord2sv            GLL_glTexCoord2sv
#define glTexCoord3d             GLL_glTexCoord3d
#define glTexCoord3dv            GLL_glTexCoord3dv
#define glTexCoord3f             GLL_glTexCoord3f
#define glTexCoord3fv            GLL_glTexCoord3fv
#define glTexCoord3i             GLL_glTexCoord3i
#define glTexCoord3iv            GLL_glTexCoord3iv
#define glTexCoord3s             GLL_glTexCoord3s
#define glTexCoord3sv            GLL_glTexCoord3sv
#define glTexCoord4d             GLL_glTexCoord4d
#define glTexCoord4dv            GLL_glTexCoord4dv
#define glTexCoord4f             GLL_glTexCoord4f
#define glTexCoord4fv            GLL_glTexCoord4fv
#define glTexCoord4i             GLL_glTexCoord4i
#define glTexCoord4iv            GLL_glTexCoord4iv
#define glTexCoord4s             GLL_glTexCoord4s
#define glTexCoord4sv            GLL_glTexCoord4sv
#define glVertex2d               GLL_glVertex2d
#define glVertex2dv              GLL_glVertex2dv
#define glVertex2f               GLL_glVertex2f
#define glVertex2fv              GLL_glVertex2fv
#define glVertex2i               GLL_glVertex2i
#define glVertex2iv              GLL_glVertex2iv
#define glVertex2s               GLL_glVertex2s
#define glVertex2sv              GLL_glVertex2sv
#define glVertex3d               GLL_glVertex3d
#define glVertex3dv              GLL_glVertex3dv
#define glVertex3f               GLL_glVertex3f
#define glVertex3fv              GLL_glVertex3fv
#define glVertex3i               GLL_glVertex3i
#define glVertex3iv              GLL_glVertex3iv
#define glVertex3s               GLL_glVertex3s
#define glVertex3sv              GLL_glVertex3sv
#define glVertex4d               GLL_glVertex4d
#define glVertex4dv              GLL_glVertex4dv
#define glVertex4f               GLL_glVertex4f
#define glVertex4fv              GLL_glVertex4fv
#define glVertex4i               GLL_glVertex4i
#define glVertex4iv              GLL_glVertex4iv
#define glVertex4s               GLL_glVertex4s
#define glVertex4sv              GLL_glVertex4sv
#define glClipPlane              GLL_glClipPlane
#define glColorMaterial          GLL_glColorMaterial
#define glFogf                   GLL_glFogf
#define glFogfv                  GLL_glFogfv
#define glFogi                   GLL_glFogi
#define glFogiv                  GLL_glFogiv
#define glLightf                 GLL_glLightf
#define glLightfv                GLL_glLightfv
#define glLighti                 GLL_glLighti
#define glLightiv                GLL_glLightiv
#define glLightModelf            GLL_glLightModelf
#define glLightModelfv           GLL_glLightModelfv
#define glLightModeli            GLL_glLightModeli
#define glLightModeliv           GLL_glLightModeliv
#define glLineStipple            GLL_glLineStipple
#define glMaterialf              GLL_glMaterialf
#define glMaterialfv             GLL_glMaterialfv
#define glMateriali              GLL_glMateriali
#define glMaterialiv             GLL_glMaterialiv
#define glPolygonStipple         GLL_glPolygonStipple
#define glShadeModel             GLL_glShadeModel
#define glTexEnvf                GLL_glTexEnvf
#define glTexEnvfv               GLL_glTexEnvfv
#define glTexEnvi                GLL_glTexEnvi
#define glTexEnviv               GLL_glTexEnviv
#define glTexGend                GLL_glTexGend
#define glTexGendv               GLL_glTexGendv
#define glTexGenf                GLL_glTexGenf
#define glTexGenfv               GLL_glTexGenfv
#define glTexGeni                GLL_glTexGeni
#define glTexGeniv               GLL_glTexGeniv
#define glFeedbackBuffer         GLL_glFeedbackBuffer
#define glSelectBuffer           GLL_glSelectBuffer
#define glRenderMode             GLL_glRenderMode
#define glInitNames              GLL_glInitNames
#define glLoadName               GLL_glLoadName
#define glPassThrough            GLL_glPassThrough
#define glPopName                GLL_glPopName
#define glPushName               GLL_glPushName
#define glClearAccum             GLL_glClearAccum
#define glClearIndex             GLL_glClearIndex
#define glIndexMask              GLL_glIndexMask
#define glAccum                  GLL_glAccum
#define glPopAttrib              GLL_glPopAttrib
#define glPushAttrib             GLL_glPushAttrib
#define glMap1d                  GLL_glMap1d
#define glMap1f                  GLL_glMap1f
#define glMap2d                  GLL_glMap2d
#define glMap2f                  GLL_glMap2f
#define glMapGrid1d              GLL_glMapGrid1d
#define glMapGrid1f              GLL_glMapGrid1f
#define glMapGrid2d              GLL_glMapGrid2d
#define glMapGrid2f              GLL_glMapGrid2f
#define glEvalCoord1d            GLL_glEvalCoord1d
#define glEvalCoord1dv           GLL_glEvalCoord1dv
#define glEvalCoord1f            GLL_glEvalCoord1f
#define glEvalCoord1fv           GLL_glEvalCoord1fv
#define glEvalCoord2d            GLL_glEvalCoord2d
#define glEvalCoord2dv           GLL_glEvalCoord2dv
#define glEvalCoord2f            GLL_glEvalCoord2f
#define glEvalCoord2fv           GLL_glEvalCoord2fv
#define glEvalMesh1              GLL_glEvalMesh1
#define glEvalPoint1             GLL_glEvalPoint1
#define glEvalMesh2              GLL_glEvalMesh2
#define glEvalPoint2             GLL_glEvalPoint2
#define glAlphaFunc              GLL_glAlphaFunc
#define glPixelZoom              GLL_glPixelZoom
#define glPixelTransferf         GLL_glPixelTransferf
#define glPixelTransferi         GLL_glPixelTransferi
#define glPixelMapfv             GLL_glPixelMapfv
#define glPixelMapuiv            GLL_glPixelMapuiv
#define glPixelMapusv            GLL_glPixelMapusv
#define glCopyPixels             GLL_glCopyPixels
#define glDrawPixels             GLL_glDrawPixels
#define glGetClipPlane           GLL_glGetClipPlane
#define glGetLightfv             GLL_glGetLightfv
#define glGetLightiv             GLL_glGetLightiv
#define glGetMapdv               GLL_glGetMapdv
#define glGetMapfv               GLL_glGetMapfv
#define glGetMapiv               GLL_glGetMapiv
#define glGetMaterialfv          GLL_glGetMaterialfv
#define glGetMaterialiv          GLL_glGetMaterialiv
#define glGetPixelMapfv          GLL_glGetPixelMapfv
#define glGetPixelMapuiv         GLL_glGetPixelMapuiv
#define glGetPixelMapusv         GLL_glGetPixelMapusv
#define glGetPolygonStipple      GLL_glGetPolygonStipple
#define glGetTexEnvfv            GLL_glGetTexEnvfv
#define glGetTexEnviv            GLL_glGetTexEnviv
#define glGetTexGendv            GLL_glGetTexGendv
#define glGetTexGenfv            GLL_glGetTexGenfv
#define glGetTexGeniv            GLL_glGetTexGeniv
#define glIsList                 GLL_glIsList
#define glFrustum                GLL_glFrustum
#define glLoadIdentity           GLL_glLoadIdentity
#define glLoadMatrixf            GLL_glLoadMatrixf
#define glLoadMatrixd            GLL_glLoadMatrixd
#define glMatrixMode             GLL_glMatrixMode
#define glMultMatrixf            GLL_glMultMatrixf
#define glMultMatrixd            GLL_glMultMatrixd
#define glOrtho                  GLL_glOrtho
#define glPopMatrix              GLL_glPopMatrix
#define glPushMatrix             GLL_glPushMatrix
#define glRotated                GLL_glRotated
#define glRotatef                GLL_glRotatef
#define glScaled                 GLL_glScaled
#define glScalef                 GLL_glScalef
#define glTranslated             GLL_glTranslated
#define glTranslatef             GLL_glTranslatef

#endif // GL_VERSION_1_0

/* -------------------------------------------------------------------------- */

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

GLL_INITPROC(glDrawArrays,          void,      GLenum mode, GLint first, GLsizei count);
GLL_INITPROC(glDrawElements,        void,      GLenum mode, GLsizei count, GLenum type, const void *indices);
GLL_INITPROC(glGetPointerv,         void,      GLenum pname, void **params);
GLL_INITPROC(glPolygonOffset,       void,      GLfloat factor, GLfloat units);
GLL_INITPROC(glCopyTexImage1D,      void,      GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
GLL_INITPROC(glCopyTexImage2D,      void,      GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GLL_INITPROC(glCopyTexSubImage1D,   void,      GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLL_INITPROC(glCopyTexSubImage2D,   void,      GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLL_INITPROC(glTexSubImage1D,       void,      GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
GLL_INITPROC(glTexSubImage2D,       void,      GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLL_INITPROC(glBindTexture,         void,      GLenum target, GLuint texture);
GLL_INITPROC(glDeleteTextures,      void,      GLsizei n, const GLuint *textures);
GLL_INITPROC(glGenTextures,         void,      GLsizei n, GLuint *textures);
GLL_INITPROC(glIsTexture,           GLboolean, GLuint texture);
GLL_INITPROC(glArrayElement,        void,      GLint i);
GLL_INITPROC(glColorPointer,        void,      GLint size, GLenum type, GLsizei stride, const void *pointer);
GLL_INITPROC(glDisableClientState,  void,      GLenum array);
GLL_INITPROC(glEdgeFlagPointer,     void,      GLsizei stride, const void *pointer);
GLL_INITPROC(glEnableClientState,   void,      GLenum array);
GLL_INITPROC(glIndexPointer,        void,      GLenum type, GLsizei stride, const void *pointer);
GLL_INITPROC(glInterleavedArrays,   void,      GLenum format, GLsizei stride, const void *pointer);
GLL_INITPROC(glNormalPointer,       void,      GLenum type, GLsizei stride, const void *pointer);
GLL_INITPROC(glTexCoordPointer,     void,      GLint size, GLenum type, GLsizei stride, const void *pointer);
GLL_INITPROC(glVertexPointer,       void,      GLint size, GLenum type, GLsizei stride, const void *pointer);
GLL_INITPROC(glAreTexturesResident, GLboolean, GLsizei n, const GLuint *textures, GLboolean *residences);
GLL_INITPROC(glPrioritizeTextures,  void,      GLsizei n, const GLuint *textures, const GLfloat *priorities);
GLL_INITPROC(glIndexub,             void,      GLubyte c);
GLL_INITPROC(glIndexubv,            void,      const GLubyte *c);
GLL_INITPROC(glPopClientAttrib,     void,      void);
GLL_INITPROC(glPushClientAttrib,    void,      GLbitfield mask);

#define glDrawArrays          GLL_glDrawArrays
#define glDrawElements        GLL_glDrawElements
#define glGetPointerv         GLL_glGetPointerv
#define glPolygonOffset       GLL_glPolygonOffset
#define glCopyTexImage1D      GLL_glCopyTexImage1D
#define glCopyTexImage2D      GLL_glCopyTexImage2D
#define glCopyTexSubImage1D   GLL_glCopyTexSubImage1D
#define glCopyTexSubImage2D   GLL_glCopyTexSubImage2D
#define glTexSubImage1D       GLL_glTexSubImage1D
#define glTexSubImage2D       GLL_glTexSubImage2D
#define glBindTexture         GLL_glBindTexture
#define glDeleteTextures      GLL_glDeleteTextures
#define glGenTextures         GLL_glGenTextures
#define glIsTexture           GLL_glIsTexture
#define glArrayElement        GLL_glArrayElement
#define glColorPointer        GLL_glColorPointer
#define glDisableClientState  GLL_glDisableClientState
#define glEdgeFlagPointer     GLL_glEdgeFlagPointer
#define glEnableClientState   GLL_glEnableClientState
#define glIndexPointer        GLL_glIndexPointer
#define glInterleavedArrays   GLL_glInterleavedArrays
#define glNormalPointer       GLL_glNormalPointer
#define glTexCoordPointer     GLL_glTexCoordPointer
#define glVertexPointer       GLL_glVertexPointer
#define glAreTexturesResident GLL_glAreTexturesResident
#define glPrioritizeTextures  GLL_glPrioritizeTextures
#define glIndexub             GLL_glIndexub
#define glIndexubv            GLL_glIndexubv
#define glPopClientAttrib     GLL_glPopClientAttrib
#define glPushClientAttrib    GLL_glPushClientAttrib

#endif // GL_VERSION_1_1

/* -------------------------------------------------------------------------- */

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

GLL_INITPROC(glDrawRangeElements, void, GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices);
GLL_INITPROC(glTexImage3D,        void, GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void *pixels);
GLL_INITPROC(glTexSubImage3D,     void, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLL_INITPROC(glCopyTexSubImage3D, void, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);

#define glDrawRangeElements GLL_glDrawRangeElements
#define glTexImage3D        GLL_glTexImage3D
#define glTexSubImage3D     GLL_glTexSubImage3D
#define glCopyTexSubImage3D GLL_glCopyTexSubImage3D

#endif // GL_VERSION_1_2

/* -------------------------------------------------------------------------- */

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

GLL_INITPROC(glActiveTexture,           void, GLenum texture);
GLL_INITPROC(glSampleCoverage,          void, GLfloat value, GLboolean invert);
GLL_INITPROC(glCompressedTexImage3D,    void, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void *data);
GLL_INITPROC(glCompressedTexImage2D,    void, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data);
GLL_INITPROC(glCompressedTexImage1D,    void, GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void *data);
GLL_INITPROC(glCompressedTexSubImage3D, void, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
GLL_INITPROC(glCompressedTexSubImage2D, void, GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
GLL_INITPROC(glCompressedTexSubImage1D, void, GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
GLL_INITPROC(glGetCompressedTexImage,   void, GLenum target, GLint level, void *img);
GLL_INITPROC(glClientActiveTexture,     void, GLenum texture);
GLL_INITPROC(glMultiTexCoord1d,         void, GLenum target, GLdouble s);
GLL_INITPROC(glMultiTexCoord1dv,        void, GLenum target, const GLdouble *v);
GLL_INITPROC(glMultiTexCoord1f,         void, GLenum target, GLfloat s);
GLL_INITPROC(glMultiTexCoord1fv,        void, GLenum target, const GLfloat *v);
GLL_INITPROC(glMultiTexCoord1i,         void, GLenum target, GLint s);
GLL_INITPROC(glMultiTexCoord1iv,        void, GLenum target, const GLint *v);
GLL_INITPROC(glMultiTexCoord1s,         void, GLenum target, GLshort s);
GLL_INITPROC(glMultiTexCoord1sv,        void, GLenum target, const GLshort *v);
GLL_INITPROC(glMultiTexCoord2d,         void, GLenum target, GLdouble s, GLdouble t);
GLL_INITPROC(glMultiTexCoord2dv,        void, GLenum target, const GLdouble *v);
GLL_INITPROC(glMultiTexCoord2f,         void, GLenum target, GLfloat s, GLfloat t);
GLL_INITPROC(glMultiTexCoord2fv,        void, GLenum target, const GLfloat *v);
GLL_INITPROC(glMultiTexCoord2i,         void, GLenum target, GLint s, GLint t);
GLL_INITPROC(glMultiTexCoord2iv,        void, GLenum target, const GLint *v);
GLL_INITPROC(glMultiTexCoord2s,         void, GLenum target, GLshort s, GLshort t);
GLL_INITPROC(glMultiTexCoord2sv,        void, GLenum target, const GLshort *v);
GLL_INITPROC(glMultiTexCoord3d,         void, GLenum target, GLdouble s, GLdouble t, GLdouble r);
GLL_INITPROC(glMultiTexCoord3dv,        void, GLenum target, const GLdouble *v);
GLL_INITPROC(glMultiTexCoord3f,         void, GLenum target, GLfloat s, GLfloat t, GLfloat r);
GLL_INITPROC(glMultiTexCoord3fv,        void, GLenum target, const GLfloat *v);
GLL_INITPROC(glMultiTexCoord3i,         void, GLenum target, GLint s, GLint t, GLint r);
GLL_INITPROC(glMultiTexCoord3iv,        void, GLenum target, const GLint *v);
GLL_INITPROC(glMultiTexCoord3s,         void, GLenum target, GLshort s, GLshort t, GLshort r);
GLL_INITPROC(glMultiTexCoord3sv,        void, GLenum target, const GLshort *v);
GLL_INITPROC(glMultiTexCoord4d,         void, GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q);
GLL_INITPROC(glMultiTexCoord4dv,        void, GLenum target, const GLdouble *v);
GLL_INITPROC(glMultiTexCoord4f,         void, GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q);
GLL_INITPROC(glMultiTexCoord4fv,        void, GLenum target, const GLfloat *v);
GLL_INITPROC(glMultiTexCoord4i,         void, GLenum target, GLint s, GLint t, GLint r, GLint q);
GLL_INITPROC(glMultiTexCoord4iv,        void, GLenum target, const GLint *v);
GLL_INITPROC(glMultiTexCoord4s,         void, GLenum target, GLshort s, GLshort t, GLshort r, GLshort q);
GLL_INITPROC(glMultiTexCoord4sv,        void, GLenum target, const GLshort *v);
GLL_INITPROC(glLoadTransposeMatrixf,    void, const GLfloat *m);
GLL_INITPROC(glLoadTransposeMatrixd,    void, const GLdouble *m);
GLL_INITPROC(glMultTransposeMatrixf,    void, const GLfloat *m);
GLL_INITPROC(glMultTransposeMatrixd,    void, const GLdouble *m);

#define glActiveTexture           GLL_glActiveTexture
#define glSampleCoverage          GLL_glSampleCoverage
#define glCompressedTexImage3D    GLL_glCompressedTexImage3D
#define glCompressedTexImage2D    GLL_glCompressedTexImage2D
#define glCompressedTexImage1D    GLL_glCompressedTexImage1D
#define glCompressedTexSubImage3D GLL_glCompressedTexSubImage3D
#define glCompressedTexSubImage2D GLL_glCompressedTexSubImage2D
#define glCompressedTexSubImage1D GLL_glCompressedTexSubImage1D
#define glGetCompressedTexImage   GLL_glGetCompressedTexImage
#define glClientActiveTexture     GLL_glClientActiveTexture
#define glMultiTexCoord1d         GLL_glMultiTexCoord1d
#define glMultiTexCoord1dv        GLL_glMultiTexCoord1dv
#define glMultiTexCoord1f         GLL_glMultiTexCoord1f
#define glMultiTexCoord1fv        GLL_glMultiTexCoord1fv
#define glMultiTexCoord1i         GLL_glMultiTexCoord1i
#define glMultiTexCoord1iv        GLL_glMultiTexCoord1iv
#define glMultiTexCoord1s         GLL_glMultiTexCoord1s
#define glMultiTexCoord1sv        GLL_glMultiTexCoord1sv
#define glMultiTexCoord2d         GLL_glMultiTexCoord2d
#define glMultiTexCoord2dv        GLL_glMultiTexCoord2dv
#define glMultiTexCoord2f         GLL_glMultiTexCoord2f
#define glMultiTexCoord2fv        GLL_glMultiTexCoord2fv
#define glMultiTexCoord2i         GLL_glMultiTexCoord2i
#define glMultiTexCoord2iv        GLL_glMultiTexCoord2iv
#define glMultiTexCoord2s         GLL_glMultiTexCoord2s
#define glMultiTexCoord2sv        GLL_glMultiTexCoord2sv
#define glMultiTexCoord3d         GLL_glMultiTexCoord3d
#define glMultiTexCoord3dv        GLL_glMultiTexCoord3dv
#define glMultiTexCoord3f         GLL_glMultiTexCoord3f
#define glMultiTexCoord3fv        GLL_glMultiTexCoord3fv
#define glMultiTexCoord3i         GLL_glMultiTexCoord3i
#define glMultiTexCoord3iv        GLL_glMultiTexCoord3iv
#define glMultiTexCoord3s         GLL_glMultiTexCoord3s
#define glMultiTexCoord3sv        GLL_glMultiTexCoord3sv
#define glMultiTexCoord4d         GLL_glMultiTexCoord4d
#define glMultiTexCoord4dv        GLL_glMultiTexCoord4dv
#define glMultiTexCoord4f         GLL_glMultiTexCoord4f
#define glMultiTexCoord4fv        GLL_glMultiTexCoord4fv
#define glMultiTexCoord4i         GLL_glMultiTexCoord4i
#define glMultiTexCoord4iv        GLL_glMultiTexCoord4iv
#define glMultiTexCoord4s         GLL_glMultiTexCoord4s
#define glMultiTexCoord4sv        GLL_glMultiTexCoord4sv
#define glLoadTransposeMatrixf    GLL_glLoadTransposeMatrixf
#define glLoadTransposeMatrixd    GLL_glLoadTransposeMatrixd
#define glMultTransposeMatrixf    GLL_glMultTransposeMatrixf
#define glMultTransposeMatrixd    GLL_glMultTransposeMatrixd

#endif // GL_VERSION_1_3

/* -------------------------------------------------------------------------- */

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

GLL_INITPROC(glBlendFuncSeparate,     void, GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha);
GLL_INITPROC(glMultiDrawArrays,       void, GLenum mode, const GLint *first, const GLsizei *count, GLsizei drawcount);
GLL_INITPROC(glMultiDrawElements,     void, GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount);
GLL_INITPROC(glPointParameterf,       void, GLenum pname, GLfloat param);
GLL_INITPROC(glPointParameterfv,      void, GLenum pname, const GLfloat *params);
GLL_INITPROC(glPointParameteri,       void, GLenum pname, GLint param);
GLL_INITPROC(glPointParameteriv,      void, GLenum pname, const GLint *params);
GLL_INITPROC(glBlendColor,            void, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLL_INITPROC(glBlendEquation,         void, GLenum mode);
GLL_INITPROC(glFogCoordf,             void, GLfloat coord);
GLL_INITPROC(glFogCoordfv,            void, const GLfloat *coord);
GLL_INITPROC(glFogCoordd,             void, GLdouble coord);
GLL_INITPROC(glFogCoorddv,            void, const GLdouble *coord);
GLL_INITPROC(glFogCoordPointer,       void, GLenum type, GLsizei stride, const void *pointer);
GLL_INITPROC(glSecondaryColor3b,      void, GLbyte red, GLbyte green, GLbyte blue);
GLL_INITPROC(glSecondaryColor3bv,     void, const GLbyte *v);
GLL_INITPROC(glSecondaryColor3d,      void, GLdouble red, GLdouble green, GLdouble blue);
GLL_INITPROC(glSecondaryColor3dv,     void, const GLdouble *v);
GLL_INITPROC(glSecondaryColor3f,      void, GLfloat red, GLfloat green, GLfloat blue);
GLL_INITPROC(glSecondaryColor3fv,     void, const GLfloat *v);
GLL_INITPROC(glSecondaryColor3i,      void, GLint red, GLint green, GLint blue);
GLL_INITPROC(glSecondaryColor3iv,     void, const GLint *v);
GLL_INITPROC(glSecondaryColor3s,      void, GLshort red, GLshort green, GLshort blue);
GLL_INITPROC(glSecondaryColor3sv,     void, const GLshort *v);
GLL_INITPROC(glSecondaryColor3ub,     void, GLubyte red, GLubyte green, GLubyte blue);
GLL_INITPROC(glSecondaryColor3ubv,    void, const GLubyte *v);
GLL_INITPROC(glSecondaryColor3ui,     void, GLuint red, GLuint green, GLuint blue);
GLL_INITPROC(glSecondaryColor3uiv,    void, const GLuint *v);
GLL_INITPROC(glSecondaryColor3us,     void, GLushort red, GLushort green, GLushort blue);
GLL_INITPROC(glSecondaryColor3usv,    void, const GLushort *v);
GLL_INITPROC(glSecondaryColorPointer, void, GLint size, GLenum type, GLsizei stride, const void *pointer);
GLL_INITPROC(glWindowPos2d,           void, GLdouble x, GLdouble y);
GLL_INITPROC(glWindowPos2dv,          void, const GLdouble *v);
GLL_INITPROC(glWindowPos2f,           void, GLfloat x, GLfloat y);
GLL_INITPROC(glWindowPos2fv,          void, const GLfloat *v);
GLL_INITPROC(glWindowPos2i,           void, GLint x, GLint y);
GLL_INITPROC(glWindowPos2iv,          void, const GLint *v);
GLL_INITPROC(glWindowPos2s,           void, GLshort x, GLshort y);
GLL_INITPROC(glWindowPos2sv,          void, const GLshort *v);
GLL_INITPROC(glWindowPos3d,           void, GLdouble x, GLdouble y, GLdouble z);
GLL_INITPROC(glWindowPos3dv,          void, const GLdouble *v);
GLL_INITPROC(glWindowPos3f,           void, GLfloat x, GLfloat y, GLfloat z);
GLL_INITPROC(glWindowPos3fv,          void, const GLfloat *v);
GLL_INITPROC(glWindowPos3i,           void, GLint x, GLint y, GLint z);
GLL_INITPROC(glWindowPos3iv,          void, const GLint *v);
GLL_INITPROC(glWindowPos3s,           void, GLshort x, GLshort y, GLshort z);
GLL_INITPROC(glWindowPos3sv,          void, const GLshort *v);

#define glBlendFuncSeparate     GLL_glBlendFuncSeparate
#define glMultiDrawArrays       GLL_glMultiDrawArrays
#define glMultiDrawElements     GLL_glMultiDrawElements
#define glPointParameterf       GLL_glPointParameterf
#define glPointParameterfv      GLL_glPointParameterfv
#define glPointParameteri       GLL_glPointParameteri
#define glPointParameteriv      GLL_glPointParameteriv
#define glBlendColor            GLL_glBlendColor
#define glBlendEquation         GLL_glBlendEquation
#define glFogCoordf             GLL_glFogCoordf
#define glFogCoordfv            GLL_glFogCoordfv
#define glFogCoordd             GLL_glFogCoordd
#define glFogCoorddv            GLL_glFogCoorddv
#define glFogCoordPointer       GLL_glFogCoordPointer
#define glSecondaryColor3b      GLL_glSecondaryColor3b
#define glSecondaryColor3bv     GLL_glSecondaryColor3bv
#define glSecondaryColor3d      GLL_glSecondaryColor3d
#define glSecondaryColor3dv     GLL_glSecondaryColor3dv
#define glSecondaryColor3f      GLL_glSecondaryColor3f
#define glSecondaryColor3fv     GLL_glSecondaryColor3fv
#define glSecondaryColor3i      GLL_glSecondaryColor3i
#define glSecondaryColor3iv     GLL_glSecondaryColor3iv
#define glSecondaryColor3s      GLL_glSecondaryColor3s
#define glSecondaryColor3sv     GLL_glSecondaryColor3sv
#define glSecondaryColor3ub     GLL_glSecondaryColor3ub
#define glSecondaryColor3ubv    GLL_glSecondaryColor3ubv
#define glSecondaryColor3ui     GLL_glSecondaryColor3ui
#define glSecondaryColor3uiv    GLL_glSecondaryColor3uiv
#define glSecondaryColor3us     GLL_glSecondaryColor3us
#define glSecondaryColor3usv    GLL_glSecondaryColor3usv
#define glSecondaryColorPointer GLL_glSecondaryColorPointer
#define glWindowPos2d           GLL_glWindowPos2d
#define glWindowPos2dv          GLL_glWindowPos2dv
#define glWindowPos2f           GLL_glWindowPos2f
#define glWindowPos2fv          GLL_glWindowPos2fv
#define glWindowPos2i           GLL_glWindowPos2i
#define glWindowPos2iv          GLL_glWindowPos2iv
#define glWindowPos2s           GLL_glWindowPos2s
#define glWindowPos2sv          GLL_glWindowPos2sv
#define glWindowPos3d           GLL_glWindowPos3d
#define glWindowPos3dv          GLL_glWindowPos3dv
#define glWindowPos3f           GLL_glWindowPos3f
#define glWindowPos3fv          GLL_glWindowPos3fv
#define glWindowPos3i           GLL_glWindowPos3i
#define glWindowPos3iv          GLL_glWindowPos3iv
#define glWindowPos3s           GLL_glWindowPos3s
#define glWindowPos3sv          GLL_glWindowPos3sv

#endif // GL_VERSION_1_4

/* -------------------------------------------------------------------------- */

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

GLL_INITPROC(glGenQueries,           void,      GLsizei n, GLuint *ids);
GLL_INITPROC(glDeleteQueries,        void,      GLsizei n, const GLuint *ids);
GLL_INITPROC(glIsQuery,              GLboolean, GLuint id);
GLL_INITPROC(glBeginQuery,           void,      GLenum target, GLuint id);
GLL_INITPROC(glEndQuery,             void,      GLenum target);
GLL_INITPROC(glGetQueryiv,           void,      GLenum target, GLenum pname, GLint *params);
GLL_INITPROC(glGetQueryObjectiv,     void,      GLuint id, GLenum pname, GLint *params);
GLL_INITPROC(glGetQueryObjectuiv,    void,      GLuint id, GLenum pname, GLuint *params);
GLL_INITPROC(glBindBuffer,           void,      GLenum target, GLuint buffer);
GLL_INITPROC(glDeleteBuffers,        void,      GLsizei n, const GLuint *buffers);
GLL_INITPROC(glGenBuffers,           void,      GLsizei n, GLuint *buffers);
GLL_INITPROC(glIsBuffer,             GLboolean, GLuint buffer);
GLL_INITPROC(glBufferData,           void,      GLenum target, GLsizeiptr size, const void *data, GLenum usage);
GLL_INITPROC(glBufferSubData,        void,      GLenum target, GLintptr offset, GLsizeiptr size, const void *data);
GLL_INITPROC(glGetBufferSubData,     void,      GLenum target, GLintptr offset, GLsizeiptr size, void *data);
GLL_INITPROC(glMapBuffer,            void*,     GLenum target, GLenum access);
GLL_INITPROC(glUnmapBuffer,          GLboolean, GLenum target);
GLL_INITPROC(glGetBufferParameteriv, void,      GLenum target, GLenum pname, GLint *params);
GLL_INITPROC(glGetBufferPointerv,    void,      GLenum target, GLenum pname, void **params);

#define glGenQueries           GLL_glGenQueries
#define glDeleteQueries        GLL_glDeleteQueries
#define glIsQuery              GLL_glIsQuery
#define glBeginQuery           GLL_glBeginQuery
#define glEndQuery             GLL_glEndQuery
#define glGetQueryiv           GLL_glGetQueryiv
#define glGetQueryObjectiv     GLL_glGetQueryObjectiv
#define glGetQueryObjectuiv    GLL_glGetQueryObjectuiv
#define glBindBuffer           GLL_glBindBuffer
#define glDeleteBuffers        GLL_glDeleteBuffers
#define glGenBuffers           GLL_glGenBuffers
#define glIsBuffer             GLL_glIsBuffer
#define glBufferData           GLL_glBufferData
#define glBufferSubData        GLL_glBufferSubData
#define glGetBufferSubData     GLL_glGetBufferSubData
#define glMapBuffer            GLL_glMapBuffer
#define glUnmapBuffer          GLL_glUnmapBuffer
#define glGetBufferParameteriv GLL_glGetBufferParameteriv
#define glGetBufferPointerv    GLL_glGetBufferPointerv

#endif // GL_VERSION_1_5

/* -------------------------------------------------------------------------- */

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

GLL_INITPROC(glBlendEquationSeparate,    void,      GLenum modeRGB, GLenum modeAlpha);
GLL_INITPROC(glDrawBuffers,              void,      GLsizei n, const GLenum *bufs);
GLL_INITPROC(glStencilOpSeparate,        void,      GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass);
GLL_INITPROC(glStencilFuncSeparate,      void,      GLenum face, GLenum func, GLint ref, GLuint mask);
GLL_INITPROC(glStencilMaskSeparate,      void,      GLenum face, GLuint mask);
GLL_INITPROC(glAttachShader,             void,      GLuint program, GLuint shader);
GLL_INITPROC(glBindAttribLocation,       void,      GLuint program, GLuint index, const GLchar *name);
GLL_INITPROC(glCompileShader,            void,      GLuint shader);
GLL_INITPROC(glCreateProgram,            GLuint,    void);
GLL_INITPROC(glCreateShader,             GLuint,    GLenum type);
GLL_INITPROC(glDeleteProgram,            void,      GLuint program);
GLL_INITPROC(glDeleteShader,             void,      GLuint shader);
GLL_INITPROC(glDetachShader,             void,      GLuint program, GLuint shader);
GLL_INITPROC(glDisableVertexAttribArray, void,      GLuint index);
GLL_INITPROC(glEnableVertexAttribArray,  void,      GLuint index);
GLL_INITPROC(glGetActiveAttrib,          void,      GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
GLL_INITPROC(glGetActiveUniform,         void,      GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLint *size, GLenum *type, GLchar *name);
GLL_INITPROC(glGetAttachedShaders,       void,      GLuint program, GLsizei maxCount, GLsizei *count, GLuint *shaders);
GLL_INITPROC(glGetAttribLocation,        GLint,     GLuint program, const GLchar *name);
GLL_INITPROC(glGetProgramiv,             void,      GLuint program, GLenum pname, GLint *params);
GLL_INITPROC(glGetProgramInfoLog,        void,      GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLL_INITPROC(glGetShaderiv,              void,      GLuint shader, GLenum pname, GLint *params);
GLL_INITPROC(glGetShaderInfoLog,         void,      GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLL_INITPROC(glGetShaderSource,          void,      GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *source);
GLL_INITPROC(glGetUniformLocation,       GLint,     GLuint program, const GLchar *name);
GLL_INITPROC(glGetUniformfv,             void,      GLuint program, GLint location, GLfloat *params);
GLL_INITPROC(glGetUniformiv,             void,      GLuint program, GLint location, GLint *params);
GLL_INITPROC(glGetVertexAttribdv,        void,      GLuint index, GLenum pname, GLdouble *params);
GLL_INITPROC(glGetVertexAttribfv,        void,      GLuint index, GLenum pname, GLfloat *params);
GLL_INITPROC(glGetVertexAttribiv,        void,      GLuint index, GLenum pname, GLint *params);
GLL_INITPROC(glGetVertexAttribPointerv,  void,      GLuint index, GLenum pname, void **pointer);
GLL_INITPROC(glIsProgram,                GLboolean, GLuint program);
GLL_INITPROC(glIsShader,                 GLboolean, GLuint shader);
GLL_INITPROC(glLinkProgram,              void,      GLuint program);
GLL_INITPROC(glShaderSource,             void,      GLuint shader, GLsizei count, const GLchar *const*string, const GLint *length);
GLL_INITPROC(glUseProgram,               void,      GLuint program);
GLL_INITPROC(glUniform1f,                void,      GLint location, GLfloat v0);
GLL_INITPROC(glUniform2f,                void,      GLint location, GLfloat v0, GLfloat v1);
GLL_INITPROC(glUniform3f,                void,      GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLL_INITPROC(glUniform4f,                void,      GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLL_INITPROC(glUniform1i,                void,      GLint location, GLint v0);
GLL_INITPROC(glUniform2i,                void,      GLint location, GLint v0, GLint v1);
GLL_INITPROC(glUniform3i,                void,      GLint location, GLint v0, GLint v1, GLint v2);
GLL_INITPROC(glUniform4i,                void,      GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLL_INITPROC(glUniform1fv,               void,      GLint location, GLsizei count, const GLfloat *value);
GLL_INITPROC(glUniform2fv,               void,      GLint location, GLsizei count, const GLfloat *value);
GLL_INITPROC(glUniform3fv,               void,      GLint location, GLsizei count, const GLfloat *value);
GLL_INITPROC(glUniform4fv,               void,      GLint location, GLsizei count, const GLfloat *value);
GLL_INITPROC(glUniform1iv,               void,      GLint location, GLsizei count, const GLint *value);
GLL_INITPROC(glUniform2iv,               void,      GLint location, GLsizei count, const GLint *value);
GLL_INITPROC(glUniform3iv,               void,      GLint location, GLsizei count, const GLint *value);
GLL_INITPROC(glUniform4iv,               void,      GLint location, GLsizei count, const GLint *value);
GLL_INITPROC(glUniformMatrix2fv,         void,      GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLL_INITPROC(glUniformMatrix3fv,         void,      GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLL_INITPROC(glUniformMatrix4fv,         void,      GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLL_INITPROC(glValidateProgram,          void,      GLuint program);
GLL_INITPROC(glVertexAttrib1d,           void,      GLuint index, GLdouble x);
GLL_INITPROC(glVertexAttrib1dv,          void,      GLuint index, const GLdouble *v);
GLL_INITPROC(glVertexAttrib1f,           void,      GLuint index, GLfloat x);
GLL_INITPROC(glVertexAttrib1fv,          void,      GLuint index, const GLfloat *v);
GLL_INITPROC(glVertexAttrib1s,           void,      GLuint index, GLshort x);
GLL_INITPROC(glVertexAttrib1sv,          void,      GLuint index, const GLshort *v);
GLL_INITPROC(glVertexAttrib2d,           void,      GLuint index, GLdouble x, GLdouble y);
GLL_INITPROC(glVertexAttrib2dv,          void,      GLuint index, const GLdouble *v);
GLL_INITPROC(glVertexAttrib2f,           void,      GLuint index, GLfloat x, GLfloat y);
GLL_INITPROC(glVertexAttrib2fv,          void,      GLuint index, const GLfloat *v);
GLL_INITPROC(glVertexAttrib2s,           void,      GLuint index, GLshort x, GLshort y);
GLL_INITPROC(glVertexAttrib2sv,          void,      GLuint index, const GLshort *v);
GLL_INITPROC(glVertexAttrib3d,           void,      GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLL_INITPROC(glVertexAttrib3dv,          void,      GLuint index, const GLdouble *v);
GLL_INITPROC(glVertexAttrib3f,           void,      GLuint index, GLfloat x, GLfloat y, GLfloat z);
GLL_INITPROC(glVertexAttrib3fv,          void,      GLuint index, const GLfloat *v);
GLL_INITPROC(glVertexAttrib3s,           void,      GLuint index, GLshort x, GLshort y, GLshort z);
GLL_INITPROC(glVertexAttrib3sv,          void,      GLuint index, const GLshort *v);
GLL_INITPROC(glVertexAttrib4Nbv,         void,      GLuint index, const GLbyte *v);
GLL_INITPROC(glVertexAttrib4Niv,         void,      GLuint index, const GLint *v);
GLL_INITPROC(glVertexAttrib4Nsv,         void,      GLuint index, const GLshort *v);
GLL_INITPROC(glVertexAttrib4Nub,         void,      GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w);
GLL_INITPROC(glVertexAttrib4Nubv,        void,      GLuint index, const GLubyte *v);
GLL_INITPROC(glVertexAttrib4Nuiv,        void,      GLuint index, const GLuint *v);
GLL_INITPROC(glVertexAttrib4Nusv,        void,      GLuint index, const GLushort *v);
GLL_INITPROC(glVertexAttrib4bv,          void,      GLuint index, const GLbyte *v);
GLL_INITPROC(glVertexAttrib4d,           void,      GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLL_INITPROC(glVertexAttrib4dv,          void,      GLuint index, const GLdouble *v);
GLL_INITPROC(glVertexAttrib4f,           void,      GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
GLL_INITPROC(glVertexAttrib4fv,          void,      GLuint index, const GLfloat *v);
GLL_INITPROC(glVertexAttrib4iv,          void,      GLuint index, const GLint *v);
GLL_INITPROC(glVertexAttrib4s,           void,      GLuint index, GLshort x, GLshort y, GLshort z, GLshort w);
GLL_INITPROC(glVertexAttrib4sv,          void,      GLuint index, const GLshort *v);
GLL_INITPROC(glVertexAttrib4ubv,         void,      GLuint index, const GLubyte *v);
GLL_INITPROC(glVertexAttrib4uiv,         void,      GLuint index, const GLuint *v);
GLL_INITPROC(glVertexAttrib4usv,         void,      GLuint index, const GLushort *v);
GLL_INITPROC(glVertexAttribPointer,      void,      GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer);

#define glBlendEquationSeparate    GLL_glBlendEquationSeparate
#define glDrawBuffers              GLL_glDrawBuffers
#define glStencilOpSeparate        GLL_glStencilOpSeparate
#define glStencilFuncSeparate      GLL_glStencilFuncSeparate
#define glStencilMaskSeparate      GLL_glStencilMaskSeparate
#define glAttachShader             GLL_glAttachShader
#define glBindAttribLocation       GLL_glBindAttribLocation
#define glCompileShader            GLL_glCompileShader
#define glCreateProgram            GLL_glCreateProgram
#define glCreateShader             GLL_glCreateShader
#define glDeleteProgram            GLL_glDeleteProgram
#define glDeleteShader             GLL_glDeleteShader
#define glDetachShader             GLL_glDetachShader
#define glDisableVertexAttribArray GLL_glDisableVertexAttribArray
#define glEnableVertexAttribArray  GLL_glEnableVertexAttribArray
#define glGetActiveAttrib          GLL_glGetActiveAttrib
#define glGetActiveUniform         GLL_glGetActiveUniform
#define glGetAttachedShaders       GLL_glGetAttachedShaders
#define glGetAttribLocation        GLL_glGetAttribLocation
#define glGetProgramiv             GLL_glGetProgramiv
#define glGetProgramInfoLog        GLL_glGetProgramInfoLog
#define glGetShaderiv              GLL_glGetShaderiv
#define glGetShaderInfoLog         GLL_glGetShaderInfoLog
#define glGetShaderSource          GLL_glGetShaderSource
#define glGetUniformLocation       GLL_glGetUniformLocation
#define glGetUniformfv             GLL_glGetUniformfv
#define glGetUniformiv             GLL_glGetUniformiv
#define glGetVertexAttribdv        GLL_glGetVertexAttribdv
#define glGetVertexAttribfv        GLL_glGetVertexAttribfv
#define glGetVertexAttribiv        GLL_glGetVertexAttribiv
#define glGetVertexAttribPointerv  GLL_glGetVertexAttribPointerv
#define glIsProgram                GLL_glIsProgram
#define glIsShader                 GLL_glIsShader
#define glLinkProgram              GLL_glLinkProgram
#define glShaderSource             GLL_glShaderSource
#define glUseProgram               GLL_glUseProgram
#define glUniform1f                GLL_glUniform1f
#define glUniform2f                GLL_glUniform2f
#define glUniform3f                GLL_glUniform3f
#define glUniform4f                GLL_glUniform4f
#define glUniform1i                GLL_glUniform1i
#define glUniform2i                GLL_glUniform2i
#define glUniform3i                GLL_glUniform3i
#define glUniform4i                GLL_glUniform4i
#define glUniform1fv               GLL_glUniform1fv
#define glUniform2fv               GLL_glUniform2fv
#define glUniform3fv               GLL_glUniform3fv
#define glUniform4fv               GLL_glUniform4fv
#define glUniform1iv               GLL_glUniform1iv
#define glUniform2iv               GLL_glUniform2iv
#define glUniform3iv               GLL_glUniform3iv
#define glUniform4iv               GLL_glUniform4iv
#define glUniformMatrix2fv         GLL_glUniformMatrix2fv
#define glUniformMatrix3fv         GLL_glUniformMatrix3fv
#define glUniformMatrix4fv         GLL_glUniformMatrix4fv
#define glValidateProgram          GLL_glValidateProgram
#define glVertexAttrib1d           GLL_glVertexAttrib1d
#define glVertexAttrib1dv          GLL_glVertexAttrib1dv
#define glVertexAttrib1f           GLL_glVertexAttrib1f
#define glVertexAttrib1fv          GLL_glVertexAttrib1fv
#define glVertexAttrib1s           GLL_glVertexAttrib1s
#define glVertexAttrib1sv          GLL_glVertexAttrib1sv
#define glVertexAttrib2d           GLL_glVertexAttrib2d
#define glVertexAttrib2dv          GLL_glVertexAttrib2dv
#define glVertexAttrib2f           GLL_glVertexAttrib2f
#define glVertexAttrib2fv          GLL_glVertexAttrib2fv
#define glVertexAttrib2s           GLL_glVertexAttrib2s
#define glVertexAttrib2sv          GLL_glVertexAttrib2sv
#define glVertexAttrib3d           GLL_glVertexAttrib3d
#define glVertexAttrib3dv          GLL_glVertexAttrib3dv
#define glVertexAttrib3f           GLL_glVertexAttrib3f
#define glVertexAttrib3fv          GLL_glVertexAttrib3fv
#define glVertexAttrib3s           GLL_glVertexAttrib3s
#define glVertexAttrib3sv          GLL_glVertexAttrib3sv
#define glVertexAttrib4Nbv         GLL_glVertexAttrib4Nbv
#define glVertexAttrib4Niv         GLL_glVertexAttrib4Niv
#define glVertexAttrib4Nsv         GLL_glVertexAttrib4Nsv
#define glVertexAttrib4Nub         GLL_glVertexAttrib4Nub
#define glVertexAttrib4Nubv        GLL_glVertexAttrib4Nubv
#define glVertexAttrib4Nuiv        GLL_glVertexAttrib4Nuiv
#define glVertexAttrib4Nusv        GLL_glVertexAttrib4Nusv
#define glVertexAttrib4bv          GLL_glVertexAttrib4bv
#define glVertexAttrib4d           GLL_glVertexAttrib4d
#define glVertexAttrib4dv          GLL_glVertexAttrib4dv
#define glVertexAttrib4f           GLL_glVertexAttrib4f
#define glVertexAttrib4fv          GLL_glVertexAttrib4fv
#define glVertexAttrib4iv          GLL_glVertexAttrib4iv
#define glVertexAttrib4s           GLL_glVertexAttrib4s
#define glVertexAttrib4sv          GLL_glVertexAttrib4sv
#define glVertexAttrib4ubv         GLL_glVertexAttrib4ubv
#define glVertexAttrib4uiv         GLL_glVertexAttrib4uiv
#define glVertexAttrib4usv         GLL_glVertexAttrib4usv
#define glVertexAttribPointer      GLL_glVertexAttribPointer

#endif // GL_VERSION_2_0

/* -------------------------------------------------------------------------- */

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

GLL_INITPROC(glUniformMatrix2x3fv, void, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLL_INITPROC(glUniformMatrix3x2fv, void, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLL_INITPROC(glUniformMatrix2x4fv, void, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLL_INITPROC(glUniformMatrix4x2fv, void, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLL_INITPROC(glUniformMatrix3x4fv, void, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLL_INITPROC(glUniformMatrix4x3fv, void, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);

#define glUniformMatrix2x3fv GLL_glUniformMatrix2x3fv
#define glUniformMatrix3x2fv GLL_glUniformMatrix3x2fv
#define glUniformMatrix2x4fv GLL_glUniformMatrix2x4fv
#define glUniformMatrix4x2fv GLL_glUniformMatrix4x2fv
#define glUniformMatrix3x4fv GLL_glUniformMatrix3x4fv
#define glUniformMatrix4x3fv GLL_glUniformMatrix4x3fv

#endif // GL_VERSION_2_1

/* -------------------------------------------------------------------------- */

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

GLL_INITPROC(glColorMaski,                          void,           GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a);
GLL_INITPROC(glGetBooleani_v,                       void,           GLenum target, GLuint index, GLboolean *data);
GLL_INITPROC(glGetIntegeri_v,                       void,           GLenum target, GLuint index, GLint *data);
GLL_INITPROC(glEnablei,                             void,           GLenum target, GLuint index);
GLL_INITPROC(glDisablei,                            void,           GLenum target, GLuint index);
GLL_INITPROC(glIsEnabledi,                          GLboolean,      GLenum target, GLuint index);
GLL_INITPROC(glBeginTransformFeedback,              void,           GLenum primitiveMode);
GLL_INITPROC(glEndTransformFeedback,                void,           void);
GLL_INITPROC(glBindBufferRange,                     void,           GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLL_INITPROC(glBindBufferBase,                      void,           GLenum target, GLuint index, GLuint buffer);
GLL_INITPROC(glTransformFeedbackVaryings,           void,           GLuint program, GLsizei count, const GLchar *const*varyings, GLenum bufferMode);
GLL_INITPROC(glGetTransformFeedbackVarying,         void,           GLuint program, GLuint index, GLsizei bufSize, GLsizei *length, GLsizei *size, GLenum *type, GLchar *name);
GLL_INITPROC(glClampColor,                          void,           GLenum target, GLenum clamp);
GLL_INITPROC(glBeginConditionalRender,              void,           GLuint id, GLenum mode);
GLL_INITPROC(glEndConditionalRender,                void,           void);
GLL_INITPROC(glVertexAttribIPointer,                void,           GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
GLL_INITPROC(glGetVertexAttribIiv,                  void,           GLuint index, GLenum pname, GLint *params);
GLL_INITPROC(glGetVertexAttribIuiv,                 void,           GLuint index, GLenum pname, GLuint *params);
GLL_INITPROC(glVertexAttribI1i,                     void,           GLuint index, GLint x);
GLL_INITPROC(glVertexAttribI2i,                     void,           GLuint index, GLint x, GLint y);
GLL_INITPROC(glVertexAttribI3i,                     void,           GLuint index, GLint x, GLint y, GLint z);
GLL_INITPROC(glVertexAttribI4i,                     void,           GLuint index, GLint x, GLint y, GLint z, GLint w);
GLL_INITPROC(glVertexAttribI1ui,                    void,           GLuint index, GLuint x);
GLL_INITPROC(glVertexAttribI2ui,                    void,           GLuint index, GLuint x, GLuint y);
GLL_INITPROC(glVertexAttribI3ui,                    void,           GLuint index, GLuint x, GLuint y, GLuint z);
GLL_INITPROC(glVertexAttribI4ui,                    void,           GLuint index, GLuint x, GLuint y, GLuint z, GLuint w);
GLL_INITPROC(glVertexAttribI1iv,                    void,           GLuint index, const GLint *v);
GLL_INITPROC(glVertexAttribI2iv,                    void,           GLuint index, const GLint *v);
GLL_INITPROC(glVertexAttribI3iv,                    void,           GLuint index, const GLint *v);
GLL_INITPROC(glVertexAttribI4iv,                    void,           GLuint index, const GLint *v);
GLL_INITPROC(glVertexAttribI1uiv,                   void,           GLuint index, const GLuint *v);
GLL_INITPROC(glVertexAttribI2uiv,                   void,           GLuint index, const GLuint *v);
GLL_INITPROC(glVertexAttribI3uiv,                   void,           GLuint index, const GLuint *v);
GLL_INITPROC(glVertexAttribI4uiv,                   void,           GLuint index, const GLuint *v);
GLL_INITPROC(glVertexAttribI4bv,                    void,           GLuint index, const GLbyte *v);
GLL_INITPROC(glVertexAttribI4sv,                    void,           GLuint index, const GLshort *v);
GLL_INITPROC(glVertexAttribI4ubv,                   void,           GLuint index, const GLubyte *v);
GLL_INITPROC(glVertexAttribI4usv,                   void,           GLuint index, const GLushort *v);
GLL_INITPROC(glGetUniformuiv,                       void,           GLuint program, GLint location, GLuint *params);
GLL_INITPROC(glBindFragDataLocation,                void,           GLuint program, GLuint color, const GLchar *name);
GLL_INITPROC(glGetFragDataLocation,                 GLint,          GLuint program, const GLchar *name);
GLL_INITPROC(glUniform1ui,                          void,           GLint location, GLuint v0);
GLL_INITPROC(glUniform2ui,                          void,           GLint location, GLuint v0, GLuint v1);
GLL_INITPROC(glUniform3ui,                          void,           GLint location, GLuint v0, GLuint v1, GLuint v2);
GLL_INITPROC(glUniform4ui,                          void,           GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLL_INITPROC(glUniform1uiv,                         void,           GLint location, GLsizei count, const GLuint *value);
GLL_INITPROC(glUniform2uiv,                         void,           GLint location, GLsizei count, const GLuint *value);
GLL_INITPROC(glUniform3uiv,                         void,           GLint location, GLsizei count, const GLuint *value);
GLL_INITPROC(glUniform4uiv,                         void,           GLint location, GLsizei count, const GLuint *value);
GLL_INITPROC(glTexParameterIiv,                     void,           GLenum target, GLenum pname, const GLint *params);
GLL_INITPROC(glTexParameterIuiv,                    void,           GLenum target, GLenum pname, const GLuint *params);
GLL_INITPROC(glGetTexParameterIiv,                  void,           GLenum target, GLenum pname, GLint *params);
GLL_INITPROC(glGetTexParameterIuiv,                 void,           GLenum target, GLenum pname, GLuint *params);
GLL_INITPROC(glClearBufferiv,                       void,           GLenum buffer, GLint drawbuffer, const GLint *value);
GLL_INITPROC(glClearBufferuiv,                      void,           GLenum buffer, GLint drawbuffer, const GLuint *value);
GLL_INITPROC(glClearBufferfv,                       void,           GLenum buffer, GLint drawbuffer, const GLfloat *value);
GLL_INITPROC(glClearBufferfi,                       void,           GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
GLL_INITPROC(glGetStringi,                          const GLubyte*, GLenum name, GLuint index);
GLL_INITPROC(glIsRenderbuffer,                      GLboolean,      GLuint renderbuffer);
GLL_INITPROC(glBindRenderbuffer,                    void,           GLenum target, GLuint renderbuffer);
GLL_INITPROC(glDeleteRenderbuffers,                 void,           GLsizei n, const GLuint *renderbuffers);
GLL_INITPROC(glGenRenderbuffers,                    void,           GLsizei n, GLuint *renderbuffers);
GLL_INITPROC(glRenderbufferStorage,                 void,           GLenum target, GLenum internalformat, GLsizei width, GLsizei height);
GLL_INITPROC(glGetRenderbufferParameteriv,          void,           GLenum target, GLenum pname, GLint *params);
GLL_INITPROC(glIsFramebuffer,                       GLboolean,      GLuint framebuffer);
GLL_INITPROC(glBindFramebuffer,                     void,           GLenum target, GLuint framebuffer);
GLL_INITPROC(glDeleteFramebuffers,                  void,           GLsizei n, const GLuint *framebuffers);
GLL_INITPROC(glGenFramebuffers,                     void,           GLsizei n, GLuint *framebuffers);
GLL_INITPROC(glCheckFramebufferStatus,              GLenum,         GLenum target);
GLL_INITPROC(glFramebufferTexture1D,                void,           GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLL_INITPROC(glFramebufferTexture2D,                void,           GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level);
GLL_INITPROC(glFramebufferTexture3D,                void,           GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset);
GLL_INITPROC(glFramebufferRenderbuffer,             void,           GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLL_INITPROC(glGetFramebufferAttachmentParameteriv, void,           GLenum target, GLenum attachment, GLenum pname, GLint *params);
GLL_INITPROC(glGenerateMipmap,                      void,           GLenum target);
GLL_INITPROC(glBlitFramebuffer,                     void,           GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLL_INITPROC(glRenderbufferStorageMultisample,      void,           GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLL_INITPROC(glFramebufferTextureLayer,             void,           GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLL_INITPROC(glMapBufferRange,                      void*,          GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLL_INITPROC(glFlushMappedBufferRange,              void,           GLenum target, GLintptr offset, GLsizeiptr length);
GLL_INITPROC(glBindVertexArray,                     void,           GLuint array);
GLL_INITPROC(glDeleteVertexArrays,                  void,           GLsizei n, const GLuint *arrays);
GLL_INITPROC(glGenVertexArrays,                     void,           GLsizei n, GLuint *arrays);
GLL_INITPROC(glIsVertexArray,                       GLboolean,      GLuint array);

#define glColorMaski                          GLL_glColorMaski
#define glGetBooleani_v                       GLL_glGetBooleani_v
#define glGetIntegeri_v                       GLL_glGetIntegeri_v
#define glEnablei                             GLL_glEnablei
#define glDisablei                            GLL_glDisablei
#define glIsEnabledi                          GLL_glIsEnabledi
#define glBeginTransformFeedback              GLL_glBeginTransformFeedback
#define glEndTransformFeedback                GLL_glEndTransformFeedback
#define glBindBufferRange                     GLL_glBindBufferRange
#define glBindBufferBase                      GLL_glBindBufferBase
#define glTransformFeedbackVaryings           GLL_glTransformFeedbackVaryings
#define glGetTransformFeedbackVarying         GLL_glGetTransformFeedbackVarying
#define glClampColor                          GLL_glClampColor
#define glBeginConditionalRender              GLL_glBeginConditionalRender
#define glEndConditionalRender                GLL_glEndConditionalRender
#define glVertexAttribIPointer                GLL_glVertexAttribIPointer
#define glGetVertexAttribIiv                  GLL_glGetVertexAttribIiv
#define glGetVertexAttribIuiv                 GLL_glGetVertexAttribIuiv
#define glVertexAttribI1i                     GLL_glVertexAttribI1i
#define glVertexAttribI2i                     GLL_glVertexAttribI2i
#define glVertexAttribI3i                     GLL_glVertexAttribI3i
#define glVertexAttribI4i                     GLL_glVertexAttribI4i
#define glVertexAttribI1ui                    GLL_glVertexAttribI1ui
#define glVertexAttribI2ui                    GLL_glVertexAttribI2ui
#define glVertexAttribI3ui                    GLL_glVertexAttribI3ui
#define glVertexAttribI4ui                    GLL_glVertexAttribI4ui
#define glVertexAttribI1iv                    GLL_glVertexAttribI1iv
#define glVertexAttribI2iv                    GLL_glVertexAttribI2iv
#define glVertexAttribI3iv                    GLL_glVertexAttribI3iv
#define glVertexAttribI4iv                    GLL_glVertexAttribI4iv
#define glVertexAttribI1uiv                   GLL_glVertexAttribI1uiv
#define glVertexAttribI2uiv                   GLL_glVertexAttribI2uiv
#define glVertexAttribI3uiv                   GLL_glVertexAttribI3uiv
#define glVertexAttribI4uiv                   GLL_glVertexAttribI4uiv
#define glVertexAttribI4bv                    GLL_glVertexAttribI4bv
#define glVertexAttribI4sv                    GLL_glVertexAttribI4sv
#define glVertexAttribI4ubv                   GLL_glVertexAttribI4ubv
#define glVertexAttribI4usv                   GLL_glVertexAttribI4usv
#define glGetUniformuiv                       GLL_glGetUniformuiv
#define glBindFragDataLocation                GLL_glBindFragDataLocation
#define glGetFragDataLocation                 GLL_glGetFragDataLocation
#define glUniform1ui                          GLL_glUniform1ui
#define glUniform2ui                          GLL_glUniform2ui
#define glUniform3ui                          GLL_glUniform3ui
#define glUniform4ui                          GLL_glUniform4ui
#define glUniform1uiv                         GLL_glUniform1uiv
#define glUniform2uiv                         GLL_glUniform2uiv
#define glUniform3uiv                         GLL_glUniform3uiv
#define glUniform4uiv                         GLL_glUniform4uiv
#define glTexParameterIiv                     GLL_glTexParameterIiv
#define glTexParameterIuiv                    GLL_glTexParameterIuiv
#define glGetTexParameterIiv                  GLL_glGetTexParameterIiv
#define glGetTexParameterIuiv                 GLL_glGetTexParameterIuiv
#define glClearBufferiv                       GLL_glClearBufferiv
#define glClearBufferuiv                      GLL_glClearBufferuiv
#define glClearBufferfv                       GLL_glClearBufferfv
#define glClearBufferfi                       GLL_glClearBufferfi
#define glGetStringi                          GLL_glGetStringi
#define glIsRenderbuffer                      GLL_glIsRenderbuffer
#define glBindRenderbuffer                    GLL_glBindRenderbuffer
#define glDeleteRenderbuffers                 GLL_glDeleteRenderbuffers
#define glGenRenderbuffers                    GLL_glGenRenderbuffers
#define glRenderbufferStorage                 GLL_glRenderbufferStorage
#define glGetRenderbufferParameteriv          GLL_glGetRenderbufferParameteriv
#define glIsFramebuffer                       GLL_glIsFramebuffer
#define glBindFramebuffer                     GLL_glBindFramebuffer
#define glDeleteFramebuffers                  GLL_glDeleteFramebuffers
#define glGenFramebuffers                     GLL_glGenFramebuffers
#define glCheckFramebufferStatus              GLL_glCheckFramebufferStatus
#define glFramebufferTexture1D                GLL_glFramebufferTexture1D
#define glFramebufferTexture2D                GLL_glFramebufferTexture2D
#define glFramebufferTexture3D                GLL_glFramebufferTexture3D
#define glFramebufferRenderbuffer             GLL_glFramebufferRenderbuffer
#define glGetFramebufferAttachmentParameteriv GLL_glGetFramebufferAttachmentParameteriv
#define glGenerateMipmap                      GLL_glGenerateMipmap
#define glBlitFramebuffer                     GLL_glBlitFramebuffer
#define glRenderbufferStorageMultisample      GLL_glRenderbufferStorageMultisample
#define glFramebufferTextureLayer             GLL_glFramebufferTextureLayer
#define glMapBufferRange                      GLL_glMapBufferRange
#define glFlushMappedBufferRange              GLL_glFlushMappedBufferRange
#define glBindVertexArray                     GLL_glBindVertexArray
#define glDeleteVertexArrays                  GLL_glDeleteVertexArrays
#define glGenVertexArrays                     GLL_glGenVertexArrays
#define glIsVertexArray                       GLL_glIsVertexArray

#endif // GL_VERSION_3_0

/* -------------------------------------------------------------------------- */

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

GLL_INITPROC(glDrawArraysInstanced,       void,   GLenum mode, GLint first, GLsizei count, GLsizei instancecount);
GLL_INITPROC(glDrawElementsInstanced,     void,   GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount);
GLL_INITPROC(glTexBuffer,                 void,   GLenum target, GLenum internalformat, GLuint buffer);
GLL_INITPROC(glPrimitiveRestartIndex,     void,   GLuint index);
GLL_INITPROC(glCopyBufferSubData,         void,   GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLL_INITPROC(glGetUniformIndices,         void,   GLuint program, GLsizei uniformCount, const GLchar *const*uniformNames, GLuint *uniformIndices);
GLL_INITPROC(glGetActiveUniformsiv,       void,   GLuint program, GLsizei uniformCount, const GLuint *uniformIndices, GLenum pname, GLint *params);
GLL_INITPROC(glGetActiveUniformName,      void,   GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformName);
GLL_INITPROC(glGetUniformBlockIndex,      GLuint, GLuint program, const GLchar *uniformBlockName);
GLL_INITPROC(glGetActiveUniformBlockiv,   void,   GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint *params);
GLL_INITPROC(glGetActiveUniformBlockName, void,   GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei *length, GLchar *uniformBlockName);
GLL_INITPROC(glUniformBlockBinding,       void,   GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding);

#define glDrawArraysInstanced       GLL_glDrawArraysInstanced
#define glDrawElementsInstanced     GLL_glDrawElementsInstanced
#define glTexBuffer                 GLL_glTexBuffer
#define glPrimitiveRestartIndex     GLL_glPrimitiveRestartIndex
#define glCopyBufferSubData         GLL_glCopyBufferSubData
#define glGetUniformIndices         GLL_glGetUniformIndices
#define glGetActiveUniformsiv       GLL_glGetActiveUniformsiv
#define glGetActiveUniformName      GLL_glGetActiveUniformName
#define glGetUniformBlockIndex      GLL_glGetUniformBlockIndex
#define glGetActiveUniformBlockiv   GLL_glGetActiveUniformBlockiv
#define glGetActiveUniformBlockName GLL_glGetActiveUniformBlockName
#define glUniformBlockBinding       GLL_glUniformBlockBinding

#endif // GL_VERSION_3_1

/* -------------------------------------------------------------------------- */

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

GLL_INITPROC(glDrawElementsBaseVertex,          void,      GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
GLL_INITPROC(glDrawRangeElementsBaseVertex,     void,      GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
GLL_INITPROC(glDrawElementsInstancedBaseVertex, void,      GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
GLL_INITPROC(glMultiDrawElementsBaseVertex,     void,      GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei drawcount, const GLint *basevertex);
GLL_INITPROC(glProvokingVertex,                 void,      GLenum mode);
GLL_INITPROC(glFenceSync,                       GLsync,    GLenum condition, GLbitfield flags);
GLL_INITPROC(glIsSync,                          GLboolean, GLsync sync);
GLL_INITPROC(glDeleteSync,                      void,      GLsync sync);
GLL_INITPROC(glClientWaitSync,                  GLenum,    GLsync sync, GLbitfield flags, GLuint64 timeout);
GLL_INITPROC(glWaitSync,                        void,      GLsync sync, GLbitfield flags, GLuint64 timeout);
GLL_INITPROC(glGetInteger64v,                   void,      GLenum pname, GLint64 *data);
GLL_INITPROC(glGetSynciv,                       void,      GLsync sync, GLenum pname, GLsizei bufSize, GLsizei *length, GLint *values);
GLL_INITPROC(glGetInteger64i_v,                 void,      GLenum target, GLuint index, GLint64 *data);
GLL_INITPROC(glGetBufferParameteri64v,          void,      GLenum target, GLenum pname, GLint64 *params);
GLL_INITPROC(glFramebufferTexture,              void,      GLenum target, GLenum attachment, GLuint texture, GLint level);
GLL_INITPROC(glTexImage2DMultisample,           void,      GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLL_INITPROC(glTexImage3DMultisample,           void,      GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLL_INITPROC(glGetMultisamplefv,                void,      GLenum pname, GLuint index, GLfloat *val);
GLL_INITPROC(glSampleMaski,                     void,      GLuint maskNumber, GLbitfield mask);

#define glDrawElementsBaseVertex          GLL_glDrawElementsBaseVertex
#define glDrawRangeElementsBaseVertex     GLL_glDrawRangeElementsBaseVertex
#define glDrawElementsInstancedBaseVertex GLL_glDrawElementsInstancedBaseVertex
#define glMultiDrawElementsBaseVertex     GLL_glMultiDrawElementsBaseVertex
#define glProvokingVertex                 GLL_glProvokingVertex
#define glFenceSync                       GLL_glFenceSync
#define glIsSync                          GLL_glIsSync
#define glDeleteSync                      GLL_glDeleteSync
#define glClientWaitSync                  GLL_glClientWaitSync
#define glWaitSync                        GLL_glWaitSync
#define glGetInteger64v                   GLL_glGetInteger64v
#define glGetSynciv                       GLL_glGetSynciv
#define glGetInteger64i_v                 GLL_glGetInteger64i_v
#define glGetBufferParameteri64v          GLL_glGetBufferParameteri64v
#define glFramebufferTexture              GLL_glFramebufferTexture
#define glTexImage2DMultisample           GLL_glTexImage2DMultisample
#define glTexImage3DMultisample           GLL_glTexImage3DMultisample
#define glGetMultisamplefv                GLL_glGetMultisamplefv
#define glSampleMaski                     GLL_glSampleMaski

#endif // GL_VERSION_3_2

/* -------------------------------------------------------------------------- */

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

GLL_INITPROC(glBindFragDataLocationIndexed, void,      GLuint program, GLuint colorNumber, GLuint index, const GLchar *name);
GLL_INITPROC(glGetFragDataIndex,            GLint,     GLuint program, const GLchar *name);
GLL_INITPROC(glGenSamplers,                 void,      GLsizei count, GLuint *samplers);
GLL_INITPROC(glDeleteSamplers,              void,      GLsizei count, const GLuint *samplers);
GLL_INITPROC(glIsSampler,                   GLboolean, GLuint sampler);
GLL_INITPROC(glBindSampler,                 void,      GLuint unit, GLuint sampler);
GLL_INITPROC(glSamplerParameteri,           void,      GLuint sampler, GLenum pname, GLint param);
GLL_INITPROC(glSamplerParameteriv,          void,      GLuint sampler, GLenum pname, const GLint *param);
GLL_INITPROC(glSamplerParameterf,           void,      GLuint sampler, GLenum pname, GLfloat param);
GLL_INITPROC(glSamplerParameterfv,          void,      GLuint sampler, GLenum pname, const GLfloat *param);
GLL_INITPROC(glSamplerParameterIiv,         void,      GLuint sampler, GLenum pname, const GLint *param);
GLL_INITPROC(glSamplerParameterIuiv,        void,      GLuint sampler, GLenum pname, const GLuint *param);
GLL_INITPROC(glGetSamplerParameteriv,       void,      GLuint sampler, GLenum pname, GLint *params);
GLL_INITPROC(glGetSamplerParameterIiv,      void,      GLuint sampler, GLenum pname, GLint *params);
GLL_INITPROC(glGetSamplerParameterfv,       void,      GLuint sampler, GLenum pname, GLfloat *params);
GLL_INITPROC(glGetSamplerParameterIuiv,     void,      GLuint sampler, GLenum pname, GLuint *params);
GLL_INITPROC(glQueryCounter,                void,      GLuint id, GLenum target);
GLL_INITPROC(glGetQueryObjecti64v,          void,      GLuint id, GLenum pname, GLint64 *params);
GLL_INITPROC(glGetQueryObjectui64v,         void,      GLuint id, GLenum pname, GLuint64 *params);
GLL_INITPROC(glVertexAttribDivisor,         void,      GLuint index, GLuint divisor);
GLL_INITPROC(glVertexAttribP1ui,            void,      GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLL_INITPROC(glVertexAttribP1uiv,           void,      GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLL_INITPROC(glVertexAttribP2ui,            void,      GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLL_INITPROC(glVertexAttribP2uiv,           void,      GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLL_INITPROC(glVertexAttribP3ui,            void,      GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLL_INITPROC(glVertexAttribP3uiv,           void,      GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLL_INITPROC(glVertexAttribP4ui,            void,      GLuint index, GLenum type, GLboolean normalized, GLuint value);
GLL_INITPROC(glVertexAttribP4uiv,           void,      GLuint index, GLenum type, GLboolean normalized, const GLuint *value);
GLL_INITPROC(glVertexP2ui,                  void,      GLenum type, GLuint value);
GLL_INITPROC(glVertexP2uiv,                 void,      GLenum type, const GLuint *value);
GLL_INITPROC(glVertexP3ui,                  void,      GLenum type, GLuint value);
GLL_INITPROC(glVertexP3uiv,                 void,      GLenum type, const GLuint *value);
GLL_INITPROC(glVertexP4ui,                  void,      GLenum type, GLuint value);
GLL_INITPROC(glVertexP4uiv,                 void,      GLenum type, const GLuint *value);
GLL_INITPROC(glTexCoordP1ui,                void,      GLenum type, GLuint coords);
GLL_INITPROC(glTexCoordP1uiv,               void,      GLenum type, const GLuint *coords);
GLL_INITPROC(glTexCoordP2ui,                void,      GLenum type, GLuint coords);
GLL_INITPROC(glTexCoordP2uiv,               void,      GLenum type, const GLuint *coords);
GLL_INITPROC(glTexCoordP3ui,                void,      GLenum type, GLuint coords);
GLL_INITPROC(glTexCoordP3uiv,               void,      GLenum type, const GLuint *coords);
GLL_INITPROC(glTexCoordP4ui,                void,      GLenum type, GLuint coords);
GLL_INITPROC(glTexCoordP4uiv,               void,      GLenum type, const GLuint *coords);
GLL_INITPROC(glMultiTexCoordP1ui,           void,      GLenum texture, GLenum type, GLuint coords);
GLL_INITPROC(glMultiTexCoordP1uiv,          void,      GLenum texture, GLenum type, const GLuint *coords);
GLL_INITPROC(glMultiTexCoordP2ui,           void,      GLenum texture, GLenum type, GLuint coords);
GLL_INITPROC(glMultiTexCoordP2uiv,          void,      GLenum texture, GLenum type, const GLuint *coords);
GLL_INITPROC(glMultiTexCoordP3ui,           void,      GLenum texture, GLenum type, GLuint coords);
GLL_INITPROC(glMultiTexCoordP3uiv,          void,      GLenum texture, GLenum type, const GLuint *coords);
GLL_INITPROC(glMultiTexCoordP4ui,           void,      GLenum texture, GLenum type, GLuint coords);
GLL_INITPROC(glMultiTexCoordP4uiv,          void,      GLenum texture, GLenum type, const GLuint *coords);
GLL_INITPROC(glNormalP3ui,                  void,      GLenum type, GLuint coords);
GLL_INITPROC(glNormalP3uiv,                 void,      GLenum type, const GLuint *coords);
GLL_INITPROC(glColorP3ui,                   void,      GLenum type, GLuint color);
GLL_INITPROC(glColorP3uiv,                  void,      GLenum type, const GLuint *color);
GLL_INITPROC(glColorP4ui,                   void,      GLenum type, GLuint color);
GLL_INITPROC(glColorP4uiv,                  void,      GLenum type, const GLuint *color);
GLL_INITPROC(glSecondaryColorP3ui,          void,      GLenum type, GLuint color);
GLL_INITPROC(glSecondaryColorP3uiv,         void,      GLenum type, const GLuint *color);

#define glBindFragDataLocationIndexed GLL_glBindFragDataLocationIndexed
#define glGetFragDataIndex            GLL_glGetFragDataIndex
#define glGenSamplers                 GLL_glGenSamplers
#define glDeleteSamplers              GLL_glDeleteSamplers
#define glIsSampler                   GLL_glIsSampler
#define glBindSampler                 GLL_glBindSampler
#define glSamplerParameteri           GLL_glSamplerParameteri
#define glSamplerParameteriv          GLL_glSamplerParameteriv
#define glSamplerParameterf           GLL_glSamplerParameterf
#define glSamplerParameterfv          GLL_glSamplerParameterfv
#define glSamplerParameterIiv         GLL_glSamplerParameterIiv
#define glSamplerParameterIuiv        GLL_glSamplerParameterIuiv
#define glGetSamplerParameteriv       GLL_glGetSamplerParameteriv
#define glGetSamplerParameterIiv      GLL_glGetSamplerParameterIiv
#define glGetSamplerParameterfv       GLL_glGetSamplerParameterfv
#define glGetSamplerParameterIuiv     GLL_glGetSamplerParameterIuiv
#define glQueryCounter                GLL_glQueryCounter
#define glGetQueryObjecti64v          GLL_glGetQueryObjecti64v
#define glGetQueryObjectui64v         GLL_glGetQueryObjectui64v
#define glVertexAttribDivisor         GLL_glVertexAttribDivisor
#define glVertexAttribP1ui            GLL_glVertexAttribP1ui
#define glVertexAttribP1uiv           GLL_glVertexAttribP1uiv
#define glVertexAttribP2ui            GLL_glVertexAttribP2ui
#define glVertexAttribP2uiv           GLL_glVertexAttribP2uiv
#define glVertexAttribP3ui            GLL_glVertexAttribP3ui
#define glVertexAttribP3uiv           GLL_glVertexAttribP3uiv
#define glVertexAttribP4ui            GLL_glVertexAttribP4ui
#define glVertexAttribP4uiv           GLL_glVertexAttribP4uiv
#define glVertexP2ui                  GLL_glVertexP2ui
#define glVertexP2uiv                 GLL_glVertexP2uiv
#define glVertexP3ui                  GLL_glVertexP3ui
#define glVertexP3uiv                 GLL_glVertexP3uiv
#define glVertexP4ui                  GLL_glVertexP4ui
#define glVertexP4uiv                 GLL_glVertexP4uiv
#define glTexCoordP1ui                GLL_glTexCoordP1ui
#define glTexCoordP1uiv               GLL_glTexCoordP1uiv
#define glTexCoordP2ui                GLL_glTexCoordP2ui
#define glTexCoordP2uiv               GLL_glTexCoordP2uiv
#define glTexCoordP3ui                GLL_glTexCoordP3ui
#define glTexCoordP3uiv               GLL_glTexCoordP3uiv
#define glTexCoordP4ui                GLL_glTexCoordP4ui
#define glTexCoordP4uiv               GLL_glTexCoordP4uiv
#define glMultiTexCoordP1ui           GLL_glMultiTexCoordP1ui
#define glMultiTexCoordP1uiv          GLL_glMultiTexCoordP1uiv
#define glMultiTexCoordP2ui           GLL_glMultiTexCoordP2ui
#define glMultiTexCoordP2uiv          GLL_glMultiTexCoordP2uiv
#define glMultiTexCoordP3ui           GLL_glMultiTexCoordP3ui
#define glMultiTexCoordP3uiv          GLL_glMultiTexCoordP3uiv
#define glMultiTexCoordP4ui           GLL_glMultiTexCoordP4ui
#define glMultiTexCoordP4uiv          GLL_glMultiTexCoordP4uiv
#define glNormalP3ui                  GLL_glNormalP3ui
#define glNormalP3uiv                 GLL_glNormalP3uiv
#define glColorP3ui                   GLL_glColorP3ui
#define glColorP3uiv                  GLL_glColorP3uiv
#define glColorP4ui                   GLL_glColorP4ui
#define glColorP4uiv                  GLL_glColorP4uiv
#define glSecondaryColorP3ui          GLL_glSecondaryColorP3ui
#define glSecondaryColorP3uiv         GLL_glSecondaryColorP3uiv

#endif // GL_VERSION_3_3

/* -------------------------------------------------------------------------- */

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

GLL_INITPROC(glMinSampleShading,               void,      GLfloat value);
GLL_INITPROC(glBlendEquationi,                 void,      GLuint buf, GLenum mode);
GLL_INITPROC(glBlendEquationSeparatei,         void,      GLuint buf, GLenum modeRGB, GLenum modeAlpha);
GLL_INITPROC(glBlendFunci,                     void,      GLuint buf, GLenum src, GLenum dst);
GLL_INITPROC(glBlendFuncSeparatei,             void,      GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha);
GLL_INITPROC(glDrawArraysIndirect,             void,      GLenum mode, const void *indirect);
GLL_INITPROC(glDrawElementsIndirect,           void,      GLenum mode, GLenum type, const void *indirect);
GLL_INITPROC(glUniform1d,                      void,      GLint location, GLdouble x);
GLL_INITPROC(glUniform2d,                      void,      GLint location, GLdouble x, GLdouble y);
GLL_INITPROC(glUniform3d,                      void,      GLint location, GLdouble x, GLdouble y, GLdouble z);
GLL_INITPROC(glUniform4d,                      void,      GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLL_INITPROC(glUniform1dv,                     void,      GLint location, GLsizei count, const GLdouble *value);
GLL_INITPROC(glUniform2dv,                     void,      GLint location, GLsizei count, const GLdouble *value);
GLL_INITPROC(glUniform3dv,                     void,      GLint location, GLsizei count, const GLdouble *value);
GLL_INITPROC(glUniform4dv,                     void,      GLint location, GLsizei count, const GLdouble *value);
GLL_INITPROC(glUniformMatrix2dv,               void,      GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLL_INITPROC(glUniformMatrix3dv,               void,      GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLL_INITPROC(glUniformMatrix4dv,               void,      GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLL_INITPROC(glUniformMatrix2x3dv,             void,      GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLL_INITPROC(glUniformMatrix2x4dv,             void,      GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLL_INITPROC(glUniformMatrix3x2dv,             void,      GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLL_INITPROC(glUniformMatrix3x4dv,             void,      GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLL_INITPROC(glUniformMatrix4x2dv,             void,      GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLL_INITPROC(glUniformMatrix4x3dv,             void,      GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLL_INITPROC(glGetUniformdv,                   void,      GLuint program, GLint location, GLdouble *params);
GLL_INITPROC(glGetSubroutineUniformLocation,   GLint,     GLuint program, GLenum shadertype, const GLchar *name);
GLL_INITPROC(glGetSubroutineIndex,             GLuint,    GLuint program, GLenum shadertype, const GLchar *name);
GLL_INITPROC(glGetActiveSubroutineUniformiv,   void,      GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint *values);
GLL_INITPROC(glGetActiveSubroutineUniformName, void,      GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
GLL_INITPROC(glGetActiveSubroutineName,        void,      GLuint program, GLenum shadertype, GLuint index, GLsizei bufsize, GLsizei *length, GLchar *name);
GLL_INITPROC(glUniformSubroutinesuiv,          void,      GLenum shadertype, GLsizei count, const GLuint *indices);
GLL_INITPROC(glGetUniformSubroutineuiv,        void,      GLenum shadertype, GLint location, GLuint *params);
GLL_INITPROC(glGetProgramStageiv,              void,      GLuint program, GLenum shadertype, GLenum pname, GLint *values);
GLL_INITPROC(glPatchParameteri,                void,      GLenum pname, GLint value);
GLL_INITPROC(glPatchParameterfv,               void,      GLenum pname, const GLfloat *values);
GLL_INITPROC(glBindTransformFeedback,          void,      GLenum target, GLuint id);
GLL_INITPROC(glDeleteTransformFeedbacks,       void,      GLsizei n, const GLuint *ids);
GLL_INITPROC(glGenTransformFeedbacks,          void,      GLsizei n, GLuint *ids);
GLL_INITPROC(glIsTransformFeedback,            GLboolean, GLuint id);
GLL_INITPROC(glPauseTransformFeedback,         void,      void);
GLL_INITPROC(glResumeTransformFeedback,        void,      void);
GLL_INITPROC(glDrawTransformFeedback,          void,      GLenum mode, GLuint id);
GLL_INITPROC(glDrawTransformFeedbackStream,    void,      GLenum mode, GLuint id, GLuint stream);
GLL_INITPROC(glBeginQueryIndexed,              void,      GLenum target, GLuint index, GLuint id);
GLL_INITPROC(glEndQueryIndexed,                void,      GLenum target, GLuint index);
GLL_INITPROC(glGetQueryIndexediv,              void,      GLenum target, GLuint index, GLenum pname, GLint *params);

#define glMinSampleShading               GLL_glMinSampleShading
#define glBlendEquationi                 GLL_glBlendEquationi
#define glBlendEquationSeparatei         GLL_glBlendEquationSeparatei
#define glBlendFunci                     GLL_glBlendFunci
#define glBlendFuncSeparatei             GLL_glBlendFuncSeparatei
#define glDrawArraysIndirect             GLL_glDrawArraysIndirect
#define glDrawElementsIndirect           GLL_glDrawElementsIndirect
#define glUniform1d                      GLL_glUniform1d
#define glUniform2d                      GLL_glUniform2d
#define glUniform3d                      GLL_glUniform3d
#define glUniform4d                      GLL_glUniform4d
#define glUniform1dv                     GLL_glUniform1dv
#define glUniform2dv                     GLL_glUniform2dv
#define glUniform3dv                     GLL_glUniform3dv
#define glUniform4dv                     GLL_glUniform4dv
#define glUniformMatrix2dv               GLL_glUniformMatrix2dv
#define glUniformMatrix3dv               GLL_glUniformMatrix3dv
#define glUniformMatrix4dv               GLL_glUniformMatrix4dv
#define glUniformMatrix2x3dv             GLL_glUniformMatrix2x3dv
#define glUniformMatrix2x4dv             GLL_glUniformMatrix2x4dv
#define glUniformMatrix3x2dv             GLL_glUniformMatrix3x2dv
#define glUniformMatrix3x4dv             GLL_glUniformMatrix3x4dv
#define glUniformMatrix4x2dv             GLL_glUniformMatrix4x2dv
#define glUniformMatrix4x3dv             GLL_glUniformMatrix4x3dv
#define glGetUniformdv                   GLL_glGetUniformdv
#define glGetSubroutineUniformLocation   GLL_glGetSubroutineUniformLocation
#define glGetSubroutineIndex             GLL_glGetSubroutineIndex
#define glGetActiveSubroutineUniformiv   GLL_glGetActiveSubroutineUniformiv
#define glGetActiveSubroutineUniformName GLL_glGetActiveSubroutineUniformName
#define glGetActiveSubroutineName        GLL_glGetActiveSubroutineName
#define glUniformSubroutinesuiv          GLL_glUniformSubroutinesuiv
#define glGetUniformSubroutineuiv        GLL_glGetUniformSubroutineuiv
#define glGetProgramStageiv              GLL_glGetProgramStageiv
#define glPatchParameteri                GLL_glPatchParameteri
#define glPatchParameterfv               GLL_glPatchParameterfv
#define glBindTransformFeedback          GLL_glBindTransformFeedback
#define glDeleteTransformFeedbacks       GLL_glDeleteTransformFeedbacks
#define glGenTransformFeedbacks          GLL_glGenTransformFeedbacks
#define glIsTransformFeedback            GLL_glIsTransformFeedback
#define glPauseTransformFeedback         GLL_glPauseTransformFeedback
#define glResumeTransformFeedback        GLL_glResumeTransformFeedback
#define glDrawTransformFeedback          GLL_glDrawTransformFeedback
#define glDrawTransformFeedbackStream    GLL_glDrawTransformFeedbackStream
#define glBeginQueryIndexed              GLL_glBeginQueryIndexed
#define glEndQueryIndexed                GLL_glEndQueryIndexed
#define glGetQueryIndexediv              GLL_glGetQueryIndexediv

#endif // GL_VERSION_4_0

/* -------------------------------------------------------------------------- */

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

GLL_INITPROC(glReleaseShaderCompiler,     void,      void);
GLL_INITPROC(glShaderBinary,              void,      GLsizei count, const GLuint *shaders, GLenum binaryformat, const void *binary, GLsizei length);
GLL_INITPROC(glGetShaderPrecisionFormat,  void,      GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision);
GLL_INITPROC(glDepthRangef,               void,      GLfloat n, GLfloat f);
GLL_INITPROC(glClearDepthf,               void,      GLfloat d);
GLL_INITPROC(glGetProgramBinary,          void,      GLuint program, GLsizei bufSize, GLsizei *length, GLenum *binaryFormat, void *binary);
GLL_INITPROC(glProgramBinary,             void,      GLuint program, GLenum binaryFormat, const void *binary, GLsizei length);
GLL_INITPROC(glProgramParameteri,         void,      GLuint program, GLenum pname, GLint value);
GLL_INITPROC(glUseProgramStages,          void,      GLuint pipeline, GLbitfield stages, GLuint program);
GLL_INITPROC(glActiveShaderProgram,       void,      GLuint pipeline, GLuint program);
GLL_INITPROC(glCreateShaderProgramv,      GLuint,    GLenum type, GLsizei count, const GLchar *const*strings);
GLL_INITPROC(glBindProgramPipeline,       void,      GLuint pipeline);
GLL_INITPROC(glDeleteProgramPipelines,    void,      GLsizei n, const GLuint *pipelines);
GLL_INITPROC(glGenProgramPipelines,       void,      GLsizei n, GLuint *pipelines);
GLL_INITPROC(glIsProgramPipeline,         GLboolean, GLuint pipeline);
GLL_INITPROC(glGetProgramPipelineiv,      void,      GLuint pipeline, GLenum pname, GLint *params);
GLL_INITPROC(glProgramUniform1i,          void,      GLuint program, GLint location, GLint v0);
GLL_INITPROC(glProgramUniform1iv,         void,      GLuint program, GLint location, GLsizei count, const GLint *value);
GLL_INITPROC(glProgramUniform1f,          void,      GLuint program, GLint location, GLfloat v0);
GLL_INITPROC(glProgramUniform1fv,         void,      GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLL_INITPROC(glProgramUniform1d,          void,      GLuint program, GLint location, GLdouble v0);
GLL_INITPROC(glProgramUniform1dv,         void,      GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLL_INITPROC(glProgramUniform1ui,         void,      GLuint program, GLint location, GLuint v0);
GLL_INITPROC(glProgramUniform1uiv,        void,      GLuint program, GLint location, GLsizei count, const GLuint *value);
GLL_INITPROC(glProgramUniform2i,          void,      GLuint program, GLint location, GLint v0, GLint v1);
GLL_INITPROC(glProgramUniform2iv,         void,      GLuint program, GLint location, GLsizei count, const GLint *value);
GLL_INITPROC(glProgramUniform2f,          void,      GLuint program, GLint location, GLfloat v0, GLfloat v1);
GLL_INITPROC(glProgramUniform2fv,         void,      GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLL_INITPROC(glProgramUniform2d,          void,      GLuint program, GLint location, GLdouble v0, GLdouble v1);
GLL_INITPROC(glProgramUniform2dv,         void,      GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLL_INITPROC(glProgramUniform2ui,         void,      GLuint program, GLint location, GLuint v0, GLuint v1);
GLL_INITPROC(glProgramUniform2uiv,        void,      GLuint program, GLint location, GLsizei count, const GLuint *value);
GLL_INITPROC(glProgramUniform3i,          void,      GLuint program, GLint location, GLint v0, GLint v1, GLint v2);
GLL_INITPROC(glProgramUniform3iv,         void,      GLuint program, GLint location, GLsizei count, const GLint *value);
GLL_INITPROC(glProgramUniform3f,          void,      GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2);
GLL_INITPROC(glProgramUniform3fv,         void,      GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLL_INITPROC(glProgramUniform3d,          void,      GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2);
GLL_INITPROC(glProgramUniform3dv,         void,      GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLL_INITPROC(glProgramUniform3ui,         void,      GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2);
GLL_INITPROC(glProgramUniform3uiv,        void,      GLuint program, GLint location, GLsizei count, const GLuint *value);
GLL_INITPROC(glProgramUniform4i,          void,      GLuint program, GLint location, GLint v0, GLint v1, GLint v2, GLint v3);
GLL_INITPROC(glProgramUniform4iv,         void,      GLuint program, GLint location, GLsizei count, const GLint *value);
GLL_INITPROC(glProgramUniform4f,          void,      GLuint program, GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3);
GLL_INITPROC(glProgramUniform4fv,         void,      GLuint program, GLint location, GLsizei count, const GLfloat *value);
GLL_INITPROC(glProgramUniform4d,          void,      GLuint program, GLint location, GLdouble v0, GLdouble v1, GLdouble v2, GLdouble v3);
GLL_INITPROC(glProgramUniform4dv,         void,      GLuint program, GLint location, GLsizei count, const GLdouble *value);
GLL_INITPROC(glProgramUniform4ui,         void,      GLuint program, GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3);
GLL_INITPROC(glProgramUniform4uiv,        void,      GLuint program, GLint location, GLsizei count, const GLuint *value);
GLL_INITPROC(glProgramUniformMatrix2fv,   void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLL_INITPROC(glProgramUniformMatrix3fv,   void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLL_INITPROC(glProgramUniformMatrix4fv,   void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLL_INITPROC(glProgramUniformMatrix2dv,   void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLL_INITPROC(glProgramUniformMatrix3dv,   void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLL_INITPROC(glProgramUniformMatrix4dv,   void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLL_INITPROC(glProgramUniformMatrix2x3fv, void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLL_INITPROC(glProgramUniformMatrix3x2fv, void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLL_INITPROC(glProgramUniformMatrix2x4fv, void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLL_INITPROC(glProgramUniformMatrix4x2fv, void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLL_INITPROC(glProgramUniformMatrix3x4fv, void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLL_INITPROC(glProgramUniformMatrix4x3fv, void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value);
GLL_INITPROC(glProgramUniformMatrix2x3dv, void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLL_INITPROC(glProgramUniformMatrix3x2dv, void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLL_INITPROC(glProgramUniformMatrix2x4dv, void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLL_INITPROC(glProgramUniformMatrix4x2dv, void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLL_INITPROC(glProgramUniformMatrix3x4dv, void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLL_INITPROC(glProgramUniformMatrix4x3dv, void,      GLuint program, GLint location, GLsizei count, GLboolean transpose, const GLdouble *value);
GLL_INITPROC(glValidateProgramPipeline,   void,      GLuint pipeline);
GLL_INITPROC(glGetProgramPipelineInfoLog, void,      GLuint pipeline, GLsizei bufSize, GLsizei *length, GLchar *infoLog);
GLL_INITPROC(glVertexAttribL1d,           void,      GLuint index, GLdouble x);
GLL_INITPROC(glVertexAttribL2d,           void,      GLuint index, GLdouble x, GLdouble y);
GLL_INITPROC(glVertexAttribL3d,           void,      GLuint index, GLdouble x, GLdouble y, GLdouble z);
GLL_INITPROC(glVertexAttribL4d,           void,      GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w);
GLL_INITPROC(glVertexAttribL1dv,          void,      GLuint index, const GLdouble *v);
GLL_INITPROC(glVertexAttribL2dv,          void,      GLuint index, const GLdouble *v);
GLL_INITPROC(glVertexAttribL3dv,          void,      GLuint index, const GLdouble *v);
GLL_INITPROC(glVertexAttribL4dv,          void,      GLuint index, const GLdouble *v);
GLL_INITPROC(glVertexAttribLPointer,      void,      GLuint index, GLint size, GLenum type, GLsizei stride, const void *pointer);
GLL_INITPROC(glGetVertexAttribLdv,        void,      GLuint index, GLenum pname, GLdouble *params);
GLL_INITPROC(glViewportArrayv,            void,      GLuint first, GLsizei count, const GLfloat *v);
GLL_INITPROC(glViewportIndexedf,          void,      GLuint index, GLfloat x, GLfloat y, GLfloat w, GLfloat h);
GLL_INITPROC(glViewportIndexedfv,         void,      GLuint index, const GLfloat *v);
GLL_INITPROC(glScissorArrayv,             void,      GLuint first, GLsizei count, const GLint *v);
GLL_INITPROC(glScissorIndexed,            void,      GLuint index, GLint left, GLint bottom, GLsizei width, GLsizei height);
GLL_INITPROC(glScissorIndexedv,           void,      GLuint index, const GLint *v);
GLL_INITPROC(glDepthRangeArrayv,          void,      GLuint first, GLsizei count, const GLdouble *v);
GLL_INITPROC(glDepthRangeIndexed,         void,      GLuint index, GLdouble n, GLdouble f);
GLL_INITPROC(glGetFloati_v,               void,      GLenum target, GLuint index, GLfloat *data);
GLL_INITPROC(glGetDoublei_v,              void,      GLenum target, GLuint index, GLdouble *data);

#define glReleaseShaderCompiler     GLL_glReleaseShaderCompiler
#define glShaderBinary              GLL_glShaderBinary
#define glGetShaderPrecisionFormat  GLL_glGetShaderPrecisionFormat
#define glDepthRangef               GLL_glDepthRangef
#define glClearDepthf               GLL_glClearDepthf
#define glGetProgramBinary          GLL_glGetProgramBinary
#define glProgramBinary             GLL_glProgramBinary
#define glProgramParameteri         GLL_glProgramParameteri
#define glUseProgramStages          GLL_glUseProgramStages
#define glActiveShaderProgram       GLL_glActiveShaderProgram
#define glCreateShaderProgramv      GLL_glCreateShaderProgramv
#define glBindProgramPipeline       GLL_glBindProgramPipeline
#define glDeleteProgramPipelines    GLL_glDeleteProgramPipelines
#define glGenProgramPipelines       GLL_glGenProgramPipelines
#define glIsProgramPipeline         GLL_glIsProgramPipeline
#define glGetProgramPipelineiv      GLL_glGetProgramPipelineiv
#define glProgramUniform1i          GLL_glProgramUniform1i
#define glProgramUniform1iv         GLL_glProgramUniform1iv
#define glProgramUniform1f          GLL_glProgramUniform1f
#define glProgramUniform1fv         GLL_glProgramUniform1fv
#define glProgramUniform1d          GLL_glProgramUniform1d
#define glProgramUniform1dv         GLL_glProgramUniform1dv
#define glProgramUniform1ui         GLL_glProgramUniform1ui
#define glProgramUniform1uiv        GLL_glProgramUniform1uiv
#define glProgramUniform2i          GLL_glProgramUniform2i
#define glProgramUniform2iv         GLL_glProgramUniform2iv
#define glProgramUniform2f          GLL_glProgramUniform2f
#define glProgramUniform2fv         GLL_glProgramUniform2fv
#define glProgramUniform2d          GLL_glProgramUniform2d
#define glProgramUniform2dv         GLL_glProgramUniform2dv
#define glProgramUniform2ui         GLL_glProgramUniform2ui
#define glProgramUniform2uiv        GLL_glProgramUniform2uiv
#define glProgramUniform3i          GLL_glProgramUniform3i
#define glProgramUniform3iv         GLL_glProgramUniform3iv
#define glProgramUniform3f          GLL_glProgramUniform3f
#define glProgramUniform3fv         GLL_glProgramUniform3fv
#define glProgramUniform3d          GLL_glProgramUniform3d
#define glProgramUniform3dv         GLL_glProgramUniform3dv
#define glProgramUniform3ui         GLL_glProgramUniform3ui
#define glProgramUniform3uiv        GLL_glProgramUniform3uiv
#define glProgramUniform4i          GLL_glProgramUniform4i
#define glProgramUniform4iv         GLL_glProgramUniform4iv
#define glProgramUniform4f          GLL_glProgramUniform4f
#define glProgramUniform4fv         GLL_glProgramUniform4fv
#define glProgramUniform4d          GLL_glProgramUniform4d
#define glProgramUniform4dv         GLL_glProgramUniform4dv
#define glProgramUniform4ui         GLL_glProgramUniform4ui
#define glProgramUniform4uiv        GLL_glProgramUniform4uiv
#define glProgramUniformMatrix2fv   GLL_glProgramUniformMatrix2fv
#define glProgramUniformMatrix3fv   GLL_glProgramUniformMatrix3fv
#define glProgramUniformMatrix4fv   GLL_glProgramUniformMatrix4fv
#define glProgramUniformMatrix2dv   GLL_glProgramUniformMatrix2dv
#define glProgramUniformMatrix3dv   GLL_glProgramUniformMatrix3dv
#define glProgramUniformMatrix4dv   GLL_glProgramUniformMatrix4dv
#define glProgramUniformMatrix2x3fv GLL_glProgramUniformMatrix2x3fv
#define glProgramUniformMatrix3x2fv GLL_glProgramUniformMatrix3x2fv
#define glProgramUniformMatrix2x4fv GLL_glProgramUniformMatrix2x4fv
#define glProgramUniformMatrix4x2fv GLL_glProgramUniformMatrix4x2fv
#define glProgramUniformMatrix3x4fv GLL_glProgramUniformMatrix3x4fv
#define glProgramUniformMatrix4x3fv GLL_glProgramUniformMatrix4x3fv
#define glProgramUniformMatrix2x3dv GLL_glProgramUniformMatrix2x3dv
#define glProgramUniformMatrix3x2dv GLL_glProgramUniformMatrix3x2dv
#define glProgramUniformMatrix2x4dv GLL_glProgramUniformMatrix2x4dv
#define glProgramUniformMatrix4x2dv GLL_glProgramUniformMatrix4x2dv
#define glProgramUniformMatrix3x4dv GLL_glProgramUniformMatrix3x4dv
#define glProgramUniformMatrix4x3dv GLL_glProgramUniformMatrix4x3dv
#define glValidateProgramPipeline   GLL_glValidateProgramPipeline
#define glGetProgramPipelineInfoLog GLL_glGetProgramPipelineInfoLog
#define glVertexAttribL1d           GLL_glVertexAttribL1d
#define glVertexAttribL2d           GLL_glVertexAttribL2d
#define glVertexAttribL3d           GLL_glVertexAttribL3d
#define glVertexAttribL4d           GLL_glVertexAttribL4d
#define glVertexAttribL1dv          GLL_glVertexAttribL1dv
#define glVertexAttribL2dv          GLL_glVertexAttribL2dv
#define glVertexAttribL3dv          GLL_glVertexAttribL3dv
#define glVertexAttribL4dv          GLL_glVertexAttribL4dv
#define glVertexAttribLPointer      GLL_glVertexAttribLPointer
#define glGetVertexAttribLdv        GLL_glGetVertexAttribLdv
#define glViewportArrayv            GLL_glViewportArrayv
#define glViewportIndexedf          GLL_glViewportIndexedf
#define glViewportIndexedfv         GLL_glViewportIndexedfv
#define glScissorArrayv             GLL_glScissorArrayv
#define glScissorIndexed            GLL_glScissorIndexed
#define glScissorIndexedv           GLL_glScissorIndexedv
#define glDepthRangeArrayv          GLL_glDepthRangeArrayv
#define glDepthRangeIndexed         GLL_glDepthRangeIndexed
#define glGetFloati_v               GLL_glGetFloati_v
#define glGetDoublei_v              GLL_glGetDoublei_v

#endif // GL_VERSION_4_1

/* -------------------------------------------------------------------------- */

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

GLL_INITPROC(glDrawArraysInstancedBaseInstance,             void, GLenum mode, GLint first, GLsizei count, GLsizei instancecount, GLuint baseinstance);
GLL_INITPROC(glDrawElementsInstancedBaseInstance,           void, GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLuint baseinstance);
GLL_INITPROC(glDrawElementsInstancedBaseVertexBaseInstance, void, GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex, GLuint baseinstance);
GLL_INITPROC(glGetInternalformativ,                         void, GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint *params);
GLL_INITPROC(glGetActiveAtomicCounterBufferiv,              void, GLuint program, GLuint bufferIndex, GLenum pname, GLint *params);
GLL_INITPROC(glBindImageTexture,                            void, GLuint unit, GLuint texture, GLint level, GLboolean layered, GLint layer, GLenum access, GLenum format);
GLL_INITPROC(glMemoryBarrier,                               void, GLbitfield barriers);
GLL_INITPROC(glTexStorage1D,                                void, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width);
GLL_INITPROC(glTexStorage2D,                                void, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GLL_INITPROC(glTexStorage3D,                                void, GLenum target, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
GLL_INITPROC(glDrawTransformFeedbackInstanced,              void, GLenum mode, GLuint id, GLsizei instancecount);
GLL_INITPROC(glDrawTransformFeedbackStreamInstanced,        void, GLenum mode, GLuint id, GLuint stream, GLsizei instancecount);

#define glDrawArraysInstancedBaseInstance             GLL_glDrawArraysInstancedBaseInstance
#define glDrawElementsInstancedBaseInstance           GLL_glDrawElementsInstancedBaseInstance
#define glDrawElementsInstancedBaseVertexBaseInstance GLL_glDrawElementsInstancedBaseVertexBaseInstance
#define glGetInternalformativ                         GLL_glGetInternalformativ
#define glGetActiveAtomicCounterBufferiv              GLL_glGetActiveAtomicCounterBufferiv
#define glBindImageTexture                            GLL_glBindImageTexture
#define glMemoryBarrier                               GLL_glMemoryBarrier
#define glTexStorage1D                                GLL_glTexStorage1D
#define glTexStorage2D                                GLL_glTexStorage2D
#define glTexStorage3D                                GLL_glTexStorage3D
#define glDrawTransformFeedbackInstanced              GLL_glDrawTransformFeedbackInstanced
#define glDrawTransformFeedbackStreamInstanced        GLL_glDrawTransformFeedbackStreamInstanced

#endif // GL_VERSION_4_2

/* -------------------------------------------------------------------------- */

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

GLL_INITPROC(glClearBufferData,                 void,   GLenum target, GLenum internalformat, GLenum format, GLenum type, const void *data);
GLL_INITPROC(glClearBufferSubData,              void,   GLenum target, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
GLL_INITPROC(glDispatchCompute,                 void,   GLuint num_groups_x, GLuint num_groups_y, GLuint num_groups_z);
GLL_INITPROC(glDispatchComputeIndirect,         void,   GLintptr indirect);
GLL_INITPROC(glCopyImageSubData,                void,   GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
GLL_INITPROC(glFramebufferParameteri,           void,   GLenum target, GLenum pname, GLint param);
GLL_INITPROC(glGetFramebufferParameteriv,       void,   GLenum target, GLenum pname, GLint *params);
GLL_INITPROC(glGetInternalformati64v,           void,   GLenum target, GLenum internalformat, GLenum pname, GLsizei bufSize, GLint64 *params);
GLL_INITPROC(glInvalidateTexSubImage,           void,   GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth);
GLL_INITPROC(glInvalidateTexImage,              void,   GLuint texture, GLint level);
GLL_INITPROC(glInvalidateBufferSubData,         void,   GLuint buffer, GLintptr offset, GLsizeiptr length);
GLL_INITPROC(glInvalidateBufferData,            void,   GLuint buffer);
GLL_INITPROC(glInvalidateFramebuffer,           void,   GLenum target, GLsizei numAttachments, const GLenum *attachments);
GLL_INITPROC(glInvalidateSubFramebuffer,        void,   GLenum target, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
GLL_INITPROC(glMultiDrawArraysIndirect,         void,   GLenum mode, const void *indirect, GLsizei drawcount, GLsizei stride);
GLL_INITPROC(glMultiDrawElementsIndirect,       void,   GLenum mode, GLenum type, const void *indirect, GLsizei drawcount, GLsizei stride);
GLL_INITPROC(glGetProgramInterfaceiv,           void,   GLuint program, GLenum programInterface, GLenum pname, GLint *params);
GLL_INITPROC(glGetProgramResourceIndex,         GLuint, GLuint program, GLenum programInterface, const GLchar *name);
GLL_INITPROC(glGetProgramResourceName,          void,   GLuint program, GLenum programInterface, GLuint index, GLsizei bufSize, GLsizei *length, GLchar *name);
GLL_INITPROC(glGetProgramResourceiv,            void,   GLuint program, GLenum programInterface, GLuint index, GLsizei propCount, const GLenum *props, GLsizei bufSize, GLsizei *length, GLint *params);
GLL_INITPROC(glGetProgramResourceLocation,      GLint,  GLuint program, GLenum programInterface, const GLchar *name);
GLL_INITPROC(glGetProgramResourceLocationIndex, GLint,  GLuint program, GLenum programInterface, const GLchar *name);
GLL_INITPROC(glShaderStorageBlockBinding,       void,   GLuint program, GLuint storageBlockIndex, GLuint storageBlockBinding);
GLL_INITPROC(glTexBufferRange,                  void,   GLenum target, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLL_INITPROC(glTexStorage2DMultisample,         void,   GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLL_INITPROC(glTexStorage3DMultisample,         void,   GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLL_INITPROC(glTextureView,                     void,   GLuint texture, GLenum target, GLuint origtexture, GLenum internalformat, GLuint minlevel, GLuint numlevels, GLuint minlayer, GLuint numlayers);
GLL_INITPROC(glBindVertexBuffer,                void,   GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLL_INITPROC(glVertexAttribFormat,              void,   GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLL_INITPROC(glVertexAttribIFormat,             void,   GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLL_INITPROC(glVertexAttribLFormat,             void,   GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLL_INITPROC(glVertexAttribBinding,             void,   GLuint attribindex, GLuint bindingindex);
GLL_INITPROC(glVertexBindingDivisor,            void,   GLuint bindingindex, GLuint divisor);
GLL_INITPROC(glDebugMessageControl,             void,   GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
GLL_INITPROC(glDebugMessageInsert,              void,   GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
GLL_INITPROC(glDebugMessageCallback,            void,   GLDEBUGPROC callback, const void *userParam);
GLL_INITPROC(glGetDebugMessageLog,              GLuint, GLuint count, GLsizei bufSize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog);
GLL_INITPROC(glPushDebugGroup,                  void,   GLenum source, GLuint id, GLsizei length, const GLchar *message);
GLL_INITPROC(glPopDebugGroup,                   void,   void);
GLL_INITPROC(glObjectLabel,                     void,   GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
GLL_INITPROC(glGetObjectLabel,                  void,   GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
GLL_INITPROC(glObjectPtrLabel,                  void,   const void *ptr, GLsizei length, const GLchar *label);
GLL_INITPROC(glGetObjectPtrLabel,               void,   const void *ptr, GLsizei bufSize, GLsizei *length, GLchar *label);

#define glClearBufferData                 GLL_glClearBufferData
#define glClearBufferSubData              GLL_glClearBufferSubData
#define glDispatchCompute                 GLL_glDispatchCompute
#define glDispatchComputeIndirect         GLL_glDispatchComputeIndirect
#define glCopyImageSubData                GLL_glCopyImageSubData
#define glFramebufferParameteri           GLL_glFramebufferParameteri
#define glGetFramebufferParameteriv       GLL_glGetFramebufferParameteriv
#define glGetInternalformati64v           GLL_glGetInternalformati64v
#define glInvalidateTexSubImage           GLL_glInvalidateTexSubImage
#define glInvalidateTexImage              GLL_glInvalidateTexImage
#define glInvalidateBufferSubData         GLL_glInvalidateBufferSubData
#define glInvalidateBufferData            GLL_glInvalidateBufferData
#define glInvalidateFramebuffer           GLL_glInvalidateFramebuffer
#define glInvalidateSubFramebuffer        GLL_glInvalidateSubFramebuffer
#define glMultiDrawArraysIndirect         GLL_glMultiDrawArraysIndirect
#define glMultiDrawElementsIndirect       GLL_glMultiDrawElementsIndirect
#define glGetProgramInterfaceiv           GLL_glGetProgramInterfaceiv
#define glGetProgramResourceIndex         GLL_glGetProgramResourceIndex
#define glGetProgramResourceName          GLL_glGetProgramResourceName
#define glGetProgramResourceiv            GLL_glGetProgramResourceiv
#define glGetProgramResourceLocation      GLL_glGetProgramResourceLocation
#define glGetProgramResourceLocationIndex GLL_glGetProgramResourceLocationIndex
#define glShaderStorageBlockBinding       GLL_glShaderStorageBlockBinding
#define glTexBufferRange                  GLL_glTexBufferRange
#define glTexStorage2DMultisample         GLL_glTexStorage2DMultisample
#define glTexStorage3DMultisample         GLL_glTexStorage3DMultisample
#define glTextureView                     GLL_glTextureView
#define glBindVertexBuffer                GLL_glBindVertexBuffer
#define glVertexAttribFormat              GLL_glVertexAttribFormat
#define glVertexAttribIFormat             GLL_glVertexAttribIFormat
#define glVertexAttribLFormat             GLL_glVertexAttribLFormat
#define glVertexAttribBinding             GLL_glVertexAttribBinding
#define glVertexBindingDivisor            GLL_glVertexBindingDivisor
#define glDebugMessageControl             GLL_glDebugMessageControl
#define glDebugMessageInsert              GLL_glDebugMessageInsert
#define glDebugMessageCallback            GLL_glDebugMessageCallback
#define glGetDebugMessageLog              GLL_glGetDebugMessageLog
#define glPushDebugGroup                  GLL_glPushDebugGroup
#define glPopDebugGroup                   GLL_glPopDebugGroup
#define glObjectLabel                     GLL_glObjectLabel
#define glGetObjectLabel                  GLL_glGetObjectLabel
#define glObjectPtrLabel                  GLL_glObjectPtrLabel
#define glGetObjectPtrLabel               GLL_glGetObjectPtrLabel

#endif // GL_VERSION_4_3

/* -------------------------------------------------------------------------- */

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

GLL_INITPROC(glBufferStorage,     void, GLenum target, GLsizeiptr size, const void *data, GLbitfield flags);
GLL_INITPROC(glClearTexImage,     void, GLuint texture, GLint level, GLenum format, GLenum type, const void *data);
GLL_INITPROC(glClearTexSubImage,  void, GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *data);
GLL_INITPROC(glBindBuffersBase,   void, GLenum target, GLuint first, GLsizei count, const GLuint *buffers);
GLL_INITPROC(glBindBuffersRange,  void, GLenum target, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizeiptr *sizes);
GLL_INITPROC(glBindTextures,      void, GLuint first, GLsizei count, const GLuint *textures);
GLL_INITPROC(glBindSamplers,      void, GLuint first, GLsizei count, const GLuint *samplers);
GLL_INITPROC(glBindImageTextures, void, GLuint first, GLsizei count, const GLuint *textures);
GLL_INITPROC(glBindVertexBuffers, void, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);

#define glBufferStorage     GLL_glBufferStorage
#define glClearTexImage     GLL_glClearTexImage
#define glClearTexSubImage  GLL_glClearTexSubImage
#define glBindBuffersBase   GLL_glBindBuffersBase
#define glBindBuffersRange  GLL_glBindBuffersRange
#define glBindTextures      GLL_glBindTextures
#define glBindSamplers      GLL_glBindSamplers
#define glBindImageTextures GLL_glBindImageTextures
#define glBindVertexBuffers GLL_glBindVertexBuffers

#endif // GL_VERSION_4_4

/* -------------------------------------------------------------------------- */

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

GLL_INITPROC(glClipControl,                              void,      GLenum origin, GLenum depth);
GLL_INITPROC(glCreateTransformFeedbacks,                 void,      GLsizei n, GLuint *ids);
GLL_INITPROC(glTransformFeedbackBufferBase,              void,      GLuint xfb, GLuint index, GLuint buffer);
GLL_INITPROC(glTransformFeedbackBufferRange,             void,      GLuint xfb, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLL_INITPROC(glGetTransformFeedbackiv,                   void,      GLuint xfb, GLenum pname, GLint *param);
GLL_INITPROC(glGetTransformFeedbacki_v,                  void,      GLuint xfb, GLenum pname, GLuint index, GLint *param);
GLL_INITPROC(glGetTransformFeedbacki64_v,                void,      GLuint xfb, GLenum pname, GLuint index, GLint64 *param);
GLL_INITPROC(glCreateBuffers,                            void,      GLsizei n, GLuint *buffers);
GLL_INITPROC(glNamedBufferStorage,                       void,      GLuint buffer, GLsizeiptr size, const void *data, GLbitfield flags);
GLL_INITPROC(glNamedBufferData,                          void,      GLuint buffer, GLsizeiptr size, const void *data, GLenum usage);
GLL_INITPROC(glNamedBufferSubData,                       void,      GLuint buffer, GLintptr offset, GLsizeiptr size, const void *data);
GLL_INITPROC(glCopyNamedBufferSubData,                   void,      GLuint readBuffer, GLuint writeBuffer, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size);
GLL_INITPROC(glClearNamedBufferData,                     void,      GLuint buffer, GLenum internalformat, GLenum format, GLenum type, const void *data);
GLL_INITPROC(glClearNamedBufferSubData,                  void,      GLuint buffer, GLenum internalformat, GLintptr offset, GLsizeiptr size, GLenum format, GLenum type, const void *data);
GLL_INITPROC(glMapNamedBuffer,                           void*,     GLuint buffer, GLenum access);
GLL_INITPROC(glMapNamedBufferRange,                      void*,     GLuint buffer, GLintptr offset, GLsizeiptr length, GLbitfield access);
GLL_INITPROC(glUnmapNamedBuffer,                         GLboolean, GLuint buffer);
GLL_INITPROC(glFlushMappedNamedBufferRange,              void,      GLuint buffer, GLintptr offset, GLsizeiptr length);
GLL_INITPROC(glGetNamedBufferParameteriv,                void,      GLuint buffer, GLenum pname, GLint *params);
GLL_INITPROC(glGetNamedBufferParameteri64v,              void,      GLuint buffer, GLenum pname, GLint64 *params);
GLL_INITPROC(glGetNamedBufferPointerv,                   void,      GLuint buffer, GLenum pname, void **params);
GLL_INITPROC(glGetNamedBufferSubData,                    void,      GLuint buffer, GLintptr offset, GLsizeiptr size, void *data);
GLL_INITPROC(glCreateFramebuffers,                       void,      GLsizei n, GLuint *framebuffers);
GLL_INITPROC(glNamedFramebufferRenderbuffer,             void,      GLuint framebuffer, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer);
GLL_INITPROC(glNamedFramebufferParameteri,               void,      GLuint framebuffer, GLenum pname, GLint param);
GLL_INITPROC(glNamedFramebufferTexture,                  void,      GLuint framebuffer, GLenum attachment, GLuint texture, GLint level);
GLL_INITPROC(glNamedFramebufferTextureLayer,             void,      GLuint framebuffer, GLenum attachment, GLuint texture, GLint level, GLint layer);
GLL_INITPROC(glNamedFramebufferDrawBuffer,               void,      GLuint framebuffer, GLenum buf);
GLL_INITPROC(glNamedFramebufferDrawBuffers,              void,      GLuint framebuffer, GLsizei n, const GLenum *bufs);
GLL_INITPROC(glNamedFramebufferReadBuffer,               void,      GLuint framebuffer, GLenum src);
GLL_INITPROC(glInvalidateNamedFramebufferData,           void,      GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments);
GLL_INITPROC(glInvalidateNamedFramebufferSubData,        void,      GLuint framebuffer, GLsizei numAttachments, const GLenum *attachments, GLint x, GLint y, GLsizei width, GLsizei height);
GLL_INITPROC(glClearNamedFramebufferiv,                  void,      GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLint *value);
GLL_INITPROC(glClearNamedFramebufferuiv,                 void,      GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLuint *value);
GLL_INITPROC(glClearNamedFramebufferfv,                  void,      GLuint framebuffer, GLenum buffer, GLint drawbuffer, const GLfloat *value);
GLL_INITPROC(glClearNamedFramebufferfi,                  void,      GLuint framebuffer, GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil);
GLL_INITPROC(glBlitNamedFramebuffer,                     void,      GLuint readFramebuffer, GLuint drawFramebuffer, GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter);
GLL_INITPROC(glCheckNamedFramebufferStatus,              GLenum,    GLuint framebuffer, GLenum target);
GLL_INITPROC(glGetNamedFramebufferParameteriv,           void,      GLuint framebuffer, GLenum pname, GLint *param);
GLL_INITPROC(glGetNamedFramebufferAttachmentParameteriv, void,      GLuint framebuffer, GLenum attachment, GLenum pname, GLint *params);
GLL_INITPROC(glCreateRenderbuffers,                      void,      GLsizei n, GLuint *renderbuffers);
GLL_INITPROC(glNamedRenderbufferStorage,                 void,      GLuint renderbuffer, GLenum internalformat, GLsizei width, GLsizei height);
GLL_INITPROC(glNamedRenderbufferStorageMultisample,      void,      GLuint renderbuffer, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height);
GLL_INITPROC(glGetNamedRenderbufferParameteriv,          void,      GLuint renderbuffer, GLenum pname, GLint *params);
GLL_INITPROC(glCreateTextures,                           void,      GLenum target, GLsizei n, GLuint *textures);
GLL_INITPROC(glTextureBuffer,                            void,      GLuint texture, GLenum internalformat, GLuint buffer);
GLL_INITPROC(glTextureBufferRange,                       void,      GLuint texture, GLenum internalformat, GLuint buffer, GLintptr offset, GLsizeiptr size);
GLL_INITPROC(glTextureStorage1D,                         void,      GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width);
GLL_INITPROC(glTextureStorage2D,                         void,      GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height);
GLL_INITPROC(glTextureStorage3D,                         void,      GLuint texture, GLsizei levels, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth);
GLL_INITPROC(glTextureStorage2DMultisample,              void,      GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations);
GLL_INITPROC(glTextureStorage3DMultisample,              void,      GLuint texture, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations);
GLL_INITPROC(glTextureSubImage1D,                        void,      GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
GLL_INITPROC(glTextureSubImage2D,                        void,      GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLL_INITPROC(glTextureSubImage3D,                        void,      GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void *pixels);
GLL_INITPROC(glCompressedTextureSubImage1D,              void,      GLuint texture, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void *data);
GLL_INITPROC(glCompressedTextureSubImage2D,              void,      GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data);
GLL_INITPROC(glCompressedTextureSubImage3D,              void,      GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void *data);
GLL_INITPROC(glCopyTextureSubImage1D,                    void,      GLuint texture, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLL_INITPROC(glCopyTextureSubImage2D,                    void,      GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLL_INITPROC(glCopyTextureSubImage3D,                    void,      GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLL_INITPROC(glTextureParameterf,                        void,      GLuint texture, GLenum pname, GLfloat param);
GLL_INITPROC(glTextureParameterfv,                       void,      GLuint texture, GLenum pname, const GLfloat *param);
GLL_INITPROC(glTextureParameteri,                        void,      GLuint texture, GLenum pname, GLint param);
GLL_INITPROC(glTextureParameterIiv,                      void,      GLuint texture, GLenum pname, const GLint *params);
GLL_INITPROC(glTextureParameterIuiv,                     void,      GLuint texture, GLenum pname, const GLuint *params);
GLL_INITPROC(glTextureParameteriv,                       void,      GLuint texture, GLenum pname, const GLint *param);
GLL_INITPROC(glGenerateTextureMipmap,                    void,      GLuint texture);
GLL_INITPROC(glBindTextureUnit,                          void,      GLuint unit, GLuint texture);
GLL_INITPROC(glGetTextureImage,                          void,      GLuint texture, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
GLL_INITPROC(glGetCompressedTextureImage,                void,      GLuint texture, GLint level, GLsizei bufSize, void *pixels);
GLL_INITPROC(glGetTextureLevelParameterfv,               void,      GLuint texture, GLint level, GLenum pname, GLfloat *params);
GLL_INITPROC(glGetTextureLevelParameteriv,               void,      GLuint texture, GLint level, GLenum pname, GLint *params);
GLL_INITPROC(glGetTextureParameterfv,                    void,      GLuint texture, GLenum pname, GLfloat *params);
GLL_INITPROC(glGetTextureParameterIiv,                   void,      GLuint texture, GLenum pname, GLint *params);
GLL_INITPROC(glGetTextureParameterIuiv,                  void,      GLuint texture, GLenum pname, GLuint *params);
GLL_INITPROC(glGetTextureParameteriv,                    void,      GLuint texture, GLenum pname, GLint *params);
GLL_INITPROC(glCreateVertexArrays,                       void,      GLsizei n, GLuint *arrays);
GLL_INITPROC(glDisableVertexArrayAttrib,                 void,      GLuint vaobj, GLuint index);
GLL_INITPROC(glEnableVertexArrayAttrib,                  void,      GLuint vaobj, GLuint index);
GLL_INITPROC(glVertexArrayElementBuffer,                 void,      GLuint vaobj, GLuint buffer);
GLL_INITPROC(glVertexArrayVertexBuffer,                  void,      GLuint vaobj, GLuint bindingindex, GLuint buffer, GLintptr offset, GLsizei stride);
GLL_INITPROC(glVertexArrayVertexBuffers,                 void,      GLuint vaobj, GLuint first, GLsizei count, const GLuint *buffers, const GLintptr *offsets, const GLsizei *strides);
GLL_INITPROC(glVertexArrayAttribBinding,                 void,      GLuint vaobj, GLuint attribindex, GLuint bindingindex);
GLL_INITPROC(glVertexArrayAttribFormat,                  void,      GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
GLL_INITPROC(glVertexArrayAttribIFormat,                 void,      GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLL_INITPROC(glVertexArrayAttribLFormat,                 void,      GLuint vaobj, GLuint attribindex, GLint size, GLenum type, GLuint relativeoffset);
GLL_INITPROC(glVertexArrayBindingDivisor,                void,      GLuint vaobj, GLuint bindingindex, GLuint divisor);
GLL_INITPROC(glGetVertexArrayiv,                         void,      GLuint vaobj, GLenum pname, GLint *param);
GLL_INITPROC(glGetVertexArrayIndexediv,                  void,      GLuint vaobj, GLuint index, GLenum pname, GLint *param);
GLL_INITPROC(glGetVertexArrayIndexed64iv,                void,      GLuint vaobj, GLuint index, GLenum pname, GLint64 *param);
GLL_INITPROC(glCreateSamplers,                           void,      GLsizei n, GLuint *samplers);
GLL_INITPROC(glCreateProgramPipelines,                   void,      GLsizei n, GLuint *pipelines);
GLL_INITPROC(glCreateQueries,                            void,      GLenum target, GLsizei n, GLuint *ids);
GLL_INITPROC(glGetQueryBufferObjecti64v,                 void,      GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLL_INITPROC(glGetQueryBufferObjectiv,                   void,      GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLL_INITPROC(glGetQueryBufferObjectui64v,                void,      GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLL_INITPROC(glGetQueryBufferObjectuiv,                  void,      GLuint id, GLuint buffer, GLenum pname, GLintptr offset);
GLL_INITPROC(glMemoryBarrierByRegion,                    void,      GLbitfield barriers);
GLL_INITPROC(glGetTextureSubImage,                       void,      GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
GLL_INITPROC(glGetCompressedTextureSubImage,             void,      GLuint texture, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLsizei bufSize, void *pixels);
GLL_INITPROC(glGetGraphicsResetStatus,                   GLenum,    void);
GLL_INITPROC(glGetnCompressedTexImage,                   void,      GLenum target, GLint lod, GLsizei bufSize, void *pixels);
GLL_INITPROC(glGetnTexImage,                             void,      GLenum target, GLint level, GLenum format, GLenum type, GLsizei bufSize, void *pixels);
GLL_INITPROC(glGetnUniformdv,                            void,      GLuint program, GLint location, GLsizei bufSize, GLdouble *params);
GLL_INITPROC(glGetnUniformfv,                            void,      GLuint program, GLint location, GLsizei bufSize, GLfloat *params);
GLL_INITPROC(glGetnUniformiv,                            void,      GLuint program, GLint location, GLsizei bufSize, GLint *params);
GLL_INITPROC(glGetnUniformuiv,                           void,      GLuint program, GLint location, GLsizei bufSize, GLuint *params);
GLL_INITPROC(glReadnPixels,                              void,      GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, GLsizei bufSize, void *data);
GLL_INITPROC(glTextureBarrier,                           void,      void);
GLL_INITPROC(glGetnMapdv,                                void,      GLenum target, GLenum query, GLsizei bufSize, GLdouble *v);
GLL_INITPROC(glGetnMapfv,                                void,      GLenum target, GLenum query, GLsizei bufSize, GLfloat *v);
GLL_INITPROC(glGetnMapiv,                                void,      GLenum target, GLenum query, GLsizei bufSize, GLint *v);
GLL_INITPROC(glGetnPixelMapfv,                           void,      GLenum map, GLsizei bufSize, GLfloat *values);
GLL_INITPROC(glGetnPixelMapuiv,                          void,      GLenum map, GLsizei bufSize, GLuint *values);
GLL_INITPROC(glGetnPixelMapusv,                          void,      GLenum map, GLsizei bufSize, GLushort *values);
GLL_INITPROC(glGetnPolygonStipple,                       void,      GLsizei bufSize, GLubyte *pattern);
GLL_INITPROC(glGetnColorTable,                           void,      GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *table);
GLL_INITPROC(glGetnConvolutionFilter,                    void,      GLenum target, GLenum format, GLenum type, GLsizei bufSize, void *image);
GLL_INITPROC(glGetnSeparableFilter,                      void,      GLenum target, GLenum format, GLenum type, GLsizei rowBufSize, void *row, GLsizei columnBufSize, void *column, void *span);
GLL_INITPROC(glGetnHistogram,                            void,      GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);
GLL_INITPROC(glGetnMinmax,                               void,      GLenum target, GLboolean reset, GLenum format, GLenum type, GLsizei bufSize, void *values);

#define glClipControl                              GLL_glClipControl
#define glCreateTransformFeedbacks                 GLL_glCreateTransformFeedbacks
#define glTransformFeedbackBufferBase              GLL_glTransformFeedbackBufferBase
#define glTransformFeedbackBufferRange             GLL_glTransformFeedbackBufferRange
#define glGetTransformFeedbackiv                   GLL_glGetTransformFeedbackiv
#define glGetTransformFeedbacki_v                  GLL_glGetTransformFeedbacki_v
#define glGetTransformFeedbacki64_v                GLL_glGetTransformFeedbacki64_v
#define glCreateBuffers                            GLL_glCreateBuffers
#define glNamedBufferStorage                       GLL_glNamedBufferStorage
#define glNamedBufferData                          GLL_glNamedBufferData
#define glNamedBufferSubData                       GLL_glNamedBufferSubData
#define glCopyNamedBufferSubData                   GLL_glCopyNamedBufferSubData
#define glClearNamedBufferData                     GLL_glClearNamedBufferData
#define glClearNamedBufferSubData                  GLL_glClearNamedBufferSubData
#define glMapNamedBuffer                           GLL_glMapNamedBuffer
#define glMapNamedBufferRange                      GLL_glMapNamedBufferRange
#define glUnmapNamedBuffer                         GLL_glUnmapNamedBuffer
#define glFlushMappedNamedBufferRange              GLL_glFlushMappedNamedBufferRange
#define glGetNamedBufferParameteriv                GLL_glGetNamedBufferParameteriv
#define glGetNamedBufferParameteri64v              GLL_glGetNamedBufferParameteri64v
#define glGetNamedBufferPointerv                   GLL_glGetNamedBufferPointerv
#define glGetNamedBufferSubData                    GLL_glGetNamedBufferSubData
#define glCreateFramebuffers                       GLL_glCreateFramebuffers
#define glNamedFramebufferRenderbuffer             GLL_glNamedFramebufferRenderbuffer
#define glNamedFramebufferParameteri               GLL_glNamedFramebufferParameteri
#define glNamedFramebufferTexture                  GLL_glNamedFramebufferTexture
#define glNamedFramebufferTextureLayer             GLL_glNamedFramebufferTextureLayer
#define glNamedFramebufferDrawBuffer               GLL_glNamedFramebufferDrawBuffer
#define glNamedFramebufferDrawBuffers              GLL_glNamedFramebufferDrawBuffers
#define glNamedFramebufferReadBuffer               GLL_glNamedFramebufferReadBuffer
#define glInvalidateNamedFramebufferData           GLL_glInvalidateNamedFramebufferData
#define glInvalidateNamedFramebufferSubData        GLL_glInvalidateNamedFramebufferSubData
#define glClearNamedFramebufferiv                  GLL_glClearNamedFramebufferiv
#define glClearNamedFramebufferuiv                 GLL_glClearNamedFramebufferuiv
#define glClearNamedFramebufferfv                  GLL_glClearNamedFramebufferfv
#define glClearNamedFramebufferfi                  GLL_glClearNamedFramebufferfi
#define glBlitNamedFramebuffer                     GLL_glBlitNamedFramebuffer
#define glCheckNamedFramebufferStatus              GLL_glCheckNamedFramebufferStatus
#define glGetNamedFramebufferParameteriv           GLL_glGetNamedFramebufferParameteriv
#define glGetNamedFramebufferAttachmentParameteriv GLL_glGetNamedFramebufferAttachmentParameteriv
#define glCreateRenderbuffers                      GLL_glCreateRenderbuffers
#define glNamedRenderbufferStorage                 GLL_glNamedRenderbufferStorage
#define glNamedRenderbufferStorageMultisample      GLL_glNamedRenderbufferStorageMultisample
#define glGetNamedRenderbufferParameteriv          GLL_glGetNamedRenderbufferParameteriv
#define glCreateTextures                           GLL_glCreateTextures
#define glTextureBuffer                            GLL_glTextureBuffer
#define glTextureBufferRange                       GLL_glTextureBufferRange
#define glTextureStorage1D                         GLL_glTextureStorage1D
#define glTextureStorage2D                         GLL_glTextureStorage2D
#define glTextureStorage3D                         GLL_glTextureStorage3D
#define glTextureStorage2DMultisample              GLL_glTextureStorage2DMultisample
#define glTextureStorage3DMultisample              GLL_glTextureStorage3DMultisample
#define glTextureSubImage1D                        GLL_glTextureSubImage1D
#define glTextureSubImage2D                        GLL_glTextureSubImage2D
#define glTextureSubImage3D                        GLL_glTextureSubImage3D
#define glCompressedTextureSubImage1D              GLL_glCompressedTextureSubImage1D
#define glCompressedTextureSubImage2D              GLL_glCompressedTextureSubImage2D
#define glCompressedTextureSubImage3D              GLL_glCompressedTextureSubImage3D
#define glCopyTextureSubImage1D                    GLL_glCopyTextureSubImage1D
#define glCopyTextureSubImage2D                    GLL_glCopyTextureSubImage2D
#define glCopyTextureSubImage3D                    GLL_glCopyTextureSubImage3D
#define glTextureParameterf                        GLL_glTextureParameterf
#define glTextureParameterfv                       GLL_glTextureParameterfv
#define glTextureParameteri                        GLL_glTextureParameteri
#define glTextureParameterIiv                      GLL_glTextureParameterIiv
#define glTextureParameterIuiv                     GLL_glTextureParameterIuiv
#define glTextureParameteriv                       GLL_glTextureParameteriv
#define glGenerateTextureMipmap                    GLL_glGenerateTextureMipmap
#define glBindTextureUnit                          GLL_glBindTextureUnit
#define glGetTextureImage                          GLL_glGetTextureImage
#define glGetCompressedTextureImage                GLL_glGetCompressedTextureImage
#define glGetTextureLevelParameterfv               GLL_glGetTextureLevelParameterfv
#define glGetTextureLevelParameteriv               GLL_glGetTextureLevelParameteriv
#define glGetTextureParameterfv                    GLL_glGetTextureParameterfv
#define glGetTextureParameterIiv                   GLL_glGetTextureParameterIiv
#define glGetTextureParameterIuiv                  GLL_glGetTextureParameterIuiv
#define glGetTextureParameteriv                    GLL_glGetTextureParameteriv
#define glCreateVertexArrays                       GLL_glCreateVertexArrays
#define glDisableVertexArrayAttrib                 GLL_glDisableVertexArrayAttrib
#define glEnableVertexArrayAttrib                  GLL_glEnableVertexArrayAttrib
#define glVertexArrayElementBuffer                 GLL_glVertexArrayElementBuffer
#define glVertexArrayVertexBuffer                  GLL_glVertexArrayVertexBuffer
#define glVertexArrayVertexBuffers                 GLL_glVertexArrayVertexBuffers
#define glVertexArrayAttribBinding                 GLL_glVertexArrayAttribBinding
#define glVertexArrayAttribFormat                  GLL_glVertexArrayAttribFormat
#define glVertexArrayAttribIFormat                 GLL_glVertexArrayAttribIFormat
#define glVertexArrayAttribLFormat                 GLL_glVertexArrayAttribLFormat
#define glVertexArrayBindingDivisor                GLL_glVertexArrayBindingDivisor
#define glGetVertexArrayiv                         GLL_glGetVertexArrayiv
#define glGetVertexArrayIndexediv                  GLL_glGetVertexArrayIndexediv
#define glGetVertexArrayIndexed64iv                GLL_glGetVertexArrayIndexed64iv
#define glCreateSamplers                           GLL_glCreateSamplers
#define glCreateProgramPipelines                   GLL_glCreateProgramPipelines
#define glCreateQueries                            GLL_glCreateQueries
#define glGetQueryBufferObjecti64v                 GLL_glGetQueryBufferObjecti64v
#define glGetQueryBufferObjectiv                   GLL_glGetQueryBufferObjectiv
#define glGetQueryBufferObjectui64v                GLL_glGetQueryBufferObjectui64v
#define glGetQueryBufferObjectuiv                  GLL_glGetQueryBufferObjectuiv
#define glMemoryBarrierByRegion                    GLL_glMemoryBarrierByRegion
#define glGetTextureSubImage                       GLL_glGetTextureSubImage
#define glGetCompressedTextureSubImage             GLL_glGetCompressedTextureSubImage
#define glGetGraphicsResetStatus                   GLL_glGetGraphicsResetStatus
#define glGetnCompressedTexImage                   GLL_glGetnCompressedTexImage
#define glGetnTexImage                             GLL_glGetnTexImage
#define glGetnUniformdv                            GLL_glGetnUniformdv
#define glGetnUniformfv                            GLL_glGetnUniformfv
#define glGetnUniformiv                            GLL_glGetnUniformiv
#define glGetnUniformuiv                           GLL_glGetnUniformuiv
#define glReadnPixels                              GLL_glReadnPixels
#define glTextureBarrier                           GLL_glTextureBarrier
#define glGetnMapdv                                GLL_glGetnMapdv
#define glGetnMapfv                                GLL_glGetnMapfv
#define glGetnMapiv                                GLL_glGetnMapiv
#define glGetnPixelMapfv                           GLL_glGetnPixelMapfv
#define glGetnPixelMapuiv                          GLL_glGetnPixelMapuiv
#define glGetnPixelMapusv                          GLL_glGetnPixelMapusv
#define glGetnPolygonStipple                       GLL_glGetnPolygonStipple
#define glGetnColorTable                           GLL_glGetnColorTable
#define glGetnConvolutionFilter                    GLL_glGetnConvolutionFilter
#define glGetnSeparableFilter                      GLL_glGetnSeparableFilter
#define glGetnHistogram                            GLL_glGetnHistogram
#define glGetnMinmax                               GLL_glGetnMinmax

#endif // GL_VERSION_4_5

/* -------------------------------------------------------------------------- */

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

GLL_INITPROC(glMultiDrawArraysIndirectCount,   void, GLenum mode, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
GLL_INITPROC(glMultiDrawElementsIndirectCount, void, GLenum mode, GLenum type, const void *indirect, GLintptr drawcount, GLsizei maxdrawcount, GLsizei stride);
GLL_INITPROC(glPolygonOffsetClamp,             void, GLfloat factor, GLfloat units, GLfloat clamp);
GLL_INITPROC(glSpecializeShader,               void, GLuint shader, const GLchar *pEntryPoint, GLuint numSpecializationConstants, const GLuint *pConstantIndex, const GLuint *pConstantValue);

#define glMultiDrawArraysIndirectCount   GLL_glMultiDrawArraysIndirectCount
#define glMultiDrawElementsIndirectCount GLL_glMultiDrawElementsIndirectCount
#define glPolygonOffsetClamp             GLL_glPolygonOffsetClamp
#define glSpecializeShader               GLL_glSpecializeShader

#endif // GL_VERSION_4_6

/* -------------------------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

/* -------------------------------------------------------------------------- */

#endif /* __GLL_GL_H__ ///////////////////////////////////////////////////////*/

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
