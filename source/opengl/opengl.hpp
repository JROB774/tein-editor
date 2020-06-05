/*******************************************************************************
 * Utilities for loading various OpenGL procedures and extensions.
 * Available Under Public Domain or MIT License (See EOF)
 * Released 05-06-2020
 * Version 1.0.2
 * Authored by Joshua Robertson
 *
*******************************************************************************/

////////////////////////////////////////////////////////////////////////////////
//
// Controls whether or not to include the OpenGL compatibility profile.
//
// #define OPENGL_USE_COMPATIBILITY_PROFILE
//
////////////////////////////////////////////////////////////////////////////////
//
// Specifies which versions of OpenGL should be included and loaded.
//
// #define OPENGL_LOAD_GL_VERSION_MAJOR 3
// #define OPENGL_LOAD_GL_VERSION_MINOR 3
//
////////////////////////////////////////////////////////////////////////////////
//
// Specfies which OpenGL extensions should be included.
//
// #define OPENGL_INCLUDE_GL_ARB_ES3_2_compatibility
// #define OPENGL_INCLUDE_GL_ARB_bindless_texture
// #define OPENGL_INCLUDE_GL_ARB_cl_event
// #define OPENGL_INCLUDE_GL_ARB_color_buffer_float
// #define OPENGL_INCLUDE_GL_ARB_compute_variable_group_size
// #define OPENGL_INCLUDE_GL_ARB_debug_output
// #define OPENGL_INCLUDE_GL_ARB_draw_buffers
// #define OPENGL_INCLUDE_GL_ARB_draw_buffers_blend
// #define OPENGL_INCLUDE_GL_ARB_draw_instanced
// #define OPENGL_INCLUDE_GL_ARB_fragment_program
// #define OPENGL_INCLUDE_GL_ARB_geometry_shader4
// #define OPENGL_INCLUDE_GL_ARB_gl_spirv
// #define OPENGL_INCLUDE_GL_ARB_gpu_shader_int64
// #define OPENGL_INCLUDE_GL_ARB_imaging
// #define OPENGL_INCLUDE_GL_ARB_indirect_parameters
// #define OPENGL_INCLUDE_GL_ARB_instanced_arrays
// #define OPENGL_INCLUDE_GL_ARB_matrix_palette
// #define OPENGL_INCLUDE_GL_ARB_multisample
// #define OPENGL_INCLUDE_GL_ARB_multitexture
// #define OPENGL_INCLUDE_GL_ARB_occlusion_query
// #define OPENGL_INCLUDE_GL_ARB_parallel_shader_compile
// #define OPENGL_INCLUDE_GL_ARB_point_parameters
// #define OPENGL_INCLUDE_GL_ARB_robustness
// #define OPENGL_INCLUDE_GL_ARB_sample_locations
// #define OPENGL_INCLUDE_GL_ARB_sample_shading
// #define OPENGL_INCLUDE_GL_ARB_shader_objects
// #define OPENGL_INCLUDE_GL_ARB_shading_language_include
// #define OPENGL_INCLUDE_GL_ARB_sparse_buffer
// #define OPENGL_INCLUDE_GL_ARB_sparse_texture
// #define OPENGL_INCLUDE_GL_ARB_texture_buffer_object
// #define OPENGL_INCLUDE_GL_ARB_texture_compression
// #define OPENGL_INCLUDE_GL_ARB_transpose_matrix
// #define OPENGL_INCLUDE_GL_ARB_vertex_blend
// #define OPENGL_INCLUDE_GL_ARB_vertex_buffer_object
// #define OPENGL_INCLUDE_GL_ARB_vertex_program
// #define OPENGL_INCLUDE_GL_ARB_vertex_shader
// #define OPENGL_INCLUDE_GL_ARB_window_pos
// #define OPENGL_INCLUDE_GL_KHR_blend_equation_advanced
// #define OPENGL_INCLUDE_GL_OES_byte_coordinates
// #define OPENGL_INCLUDE_GL_OES_fixed_point
// #define OPENGL_INCLUDE_GL_OES_query_matrix
// #define OPENGL_INCLUDE_GL_OES_single_precision
// #define OPENGL_INCLUDE_GL_3DFX_tbuffer
// #define OPENGL_INCLUDE_GL_AMD_debug_output
// #define OPENGL_INCLUDE_GL_AMD_draw_buffers_blend
// #define OPENGL_INCLUDE_GL_AMD_framebuffer_multisample_advanced
// #define OPENGL_INCLUDE_GL_AMD_framebuffer_sample_positions
// #define OPENGL_INCLUDE_GL_AMD_gpu_shader_int64
// #define OPENGL_INCLUDE_GL_AMD_interleaved_elements
// #define OPENGL_INCLUDE_GL_AMD_multi_draw_indirect
// #define OPENGL_INCLUDE_GL_AMD_name_gen_delete
// #define OPENGL_INCLUDE_GL_AMD_occlusion_query_event
// #define OPENGL_INCLUDE_GL_AMD_performance_monitor
// #define OPENGL_INCLUDE_GL_AMD_sample_positions
// #define OPENGL_INCLUDE_GL_AMD_sparse_texture
// #define OPENGL_INCLUDE_GL_AMD_stencil_operation_extended
// #define OPENGL_INCLUDE_GL_AMD_vertex_shader_tessellator
// #define OPENGL_INCLUDE_GL_APPLE_element_array
// #define OPENGL_INCLUDE_GL_APPLE_fence
// #define OPENGL_INCLUDE_GL_APPLE_flush_buffer_range
// #define OPENGL_INCLUDE_GL_APPLE_object_purgeable
// #define OPENGL_INCLUDE_GL_APPLE_texture_range
// #define OPENGL_INCLUDE_GL_APPLE_vertex_array_object
// #define OPENGL_INCLUDE_GL_APPLE_vertex_array_range
// #define OPENGL_INCLUDE_GL_APPLE_vertex_program_evaluators
// #define OPENGL_INCLUDE_GL_ATI_draw_buffers
// #define OPENGL_INCLUDE_GL_ATI_element_array
// #define OPENGL_INCLUDE_GL_ATI_envmap_bumpmap
// #define OPENGL_INCLUDE_GL_ATI_fragment_shader
// #define OPENGL_INCLUDE_GL_ATI_map_object_buffer
// #define OPENGL_INCLUDE_GL_ATI_pn_triangles
// #define OPENGL_INCLUDE_GL_ATI_separate_stencil
// #define OPENGL_INCLUDE_GL_ATI_vertex_array_object
// #define OPENGL_INCLUDE_GL_ATI_vertex_attrib_array_object
// #define OPENGL_INCLUDE_GL_ATI_vertex_streams
// #define OPENGL_INCLUDE_GL_EXT_EGL_image_storage
// #define OPENGL_INCLUDE_GL_EXT_bindable_uniform
// #define OPENGL_INCLUDE_GL_EXT_blend_color
// #define OPENGL_INCLUDE_GL_EXT_blend_equation_separate
// #define OPENGL_INCLUDE_GL_EXT_blend_func_separate
// #define OPENGL_INCLUDE_GL_EXT_blend_minmax
// #define OPENGL_INCLUDE_GL_EXT_color_subtable
// #define OPENGL_INCLUDE_GL_EXT_compiled_vertex_array
// #define OPENGL_INCLUDE_GL_EXT_convolution
// #define OPENGL_INCLUDE_GL_EXT_coordinate_frame
// #define OPENGL_INCLUDE_GL_EXT_copy_texture
// #define OPENGL_INCLUDE_GL_EXT_cull_vertex
// #define OPENGL_INCLUDE_GL_EXT_debug_label
// #define OPENGL_INCLUDE_GL_EXT_debug_marker
// #define OPENGL_INCLUDE_GL_EXT_depth_bounds_test
// #define OPENGL_INCLUDE_GL_EXT_direct_state_access
// #define OPENGL_INCLUDE_GL_EXT_draw_buffers2
// #define OPENGL_INCLUDE_GL_EXT_draw_instanced
// #define OPENGL_INCLUDE_GL_EXT_draw_range_elements
// #define OPENGL_INCLUDE_GL_EXT_external_buffer
// #define OPENGL_INCLUDE_GL_EXT_fog_coord
// #define OPENGL_INCLUDE_GL_EXT_framebuffer_blit
// #define OPENGL_INCLUDE_GL_EXT_framebuffer_multisample
// #define OPENGL_INCLUDE_GL_EXT_framebuffer_object
// #define OPENGL_INCLUDE_GL_EXT_geometry_shader4
// #define OPENGL_INCLUDE_GL_EXT_gpu_program_parameters
// #define OPENGL_INCLUDE_GL_EXT_gpu_shader4
// #define OPENGL_INCLUDE_GL_EXT_histogram
// #define OPENGL_INCLUDE_GL_EXT_index_func
// #define OPENGL_INCLUDE_GL_EXT_index_material
// #define OPENGL_INCLUDE_GL_EXT_light_texture
// #define OPENGL_INCLUDE_GL_EXT_memory_object
// #define OPENGL_INCLUDE_GL_EXT_memory_object_fd
// #define OPENGL_INCLUDE_GL_EXT_memory_object_win32
// #define OPENGL_INCLUDE_GL_EXT_multi_draw_arrays
// #define OPENGL_INCLUDE_GL_EXT_multisample
// #define OPENGL_INCLUDE_GL_EXT_paletted_texture
// #define OPENGL_INCLUDE_GL_EXT_pixel_transform
// #define OPENGL_INCLUDE_GL_EXT_point_parameters
// #define OPENGL_INCLUDE_GL_EXT_polygon_offset
// #define OPENGL_INCLUDE_GL_EXT_polygon_offset_clamp
// #define OPENGL_INCLUDE_GL_EXT_provoking_vertex
// #define OPENGL_INCLUDE_GL_EXT_raster_multisample
// #define OPENGL_INCLUDE_GL_EXT_secondary_color
// #define OPENGL_INCLUDE_GL_EXT_semaphore
// #define OPENGL_INCLUDE_GL_EXT_semaphore_fd
// #define OPENGL_INCLUDE_GL_EXT_semaphore_win32
// #define OPENGL_INCLUDE_GL_EXT_separate_shader_objects
// #define OPENGL_INCLUDE_GL_EXT_shader_framebuffer_fetch_non_coherent
// #define OPENGL_INCLUDE_GL_EXT_shader_image_load_store
// #define OPENGL_INCLUDE_GL_EXT_stencil_clear_tag
// #define OPENGL_INCLUDE_GL_EXT_stencil_two_side
// #define OPENGL_INCLUDE_GL_EXT_subtexture
// #define OPENGL_INCLUDE_GL_EXT_texture3D
// #define OPENGL_INCLUDE_GL_EXT_texture_array
// #define OPENGL_INCLUDE_GL_EXT_texture_buffer_object
// #define OPENGL_INCLUDE_GL_EXT_texture_integer
// #define OPENGL_INCLUDE_GL_EXT_texture_object
// #define OPENGL_INCLUDE_GL_EXT_texture_perturb_normal
// #define OPENGL_INCLUDE_GL_EXT_timer_query
// #define OPENGL_INCLUDE_GL_EXT_transform_feedback
// #define OPENGL_INCLUDE_GL_EXT_vertex_array
// #define OPENGL_INCLUDE_GL_EXT_vertex_attrib_64bit
// #define OPENGL_INCLUDE_GL_EXT_vertex_shader
// #define OPENGL_INCLUDE_GL_EXT_vertex_weighting
// #define OPENGL_INCLUDE_GL_EXT_win32_keyed_mutex
// #define OPENGL_INCLUDE_GL_EXT_window_rectangles
// #define OPENGL_INCLUDE_GL_EXT_x11_sync_object
// #define OPENGL_INCLUDE_GL_GREMEDY_frame_terminator
// #define OPENGL_INCLUDE_GL_GREMEDY_string_marker
// #define OPENGL_INCLUDE_GL_HP_image_transform
// #define OPENGL_INCLUDE_GL_IBM_multimode_draw_arrays
// #define OPENGL_INCLUDE_GL_IBM_static_data
// #define OPENGL_INCLUDE_GL_IBM_vertex_array_lists
// #define OPENGL_INCLUDE_GL_INGR_blend_func_separate
// #define OPENGL_INCLUDE_GL_INTEL_framebuffer_CMAA
// #define OPENGL_INCLUDE_GL_INTEL_map_texture
// #define OPENGL_INCLUDE_GL_INTEL_parallel_arrays
// #define OPENGL_INCLUDE_GL_INTEL_performance_query
// #define OPENGL_INCLUDE_GL_MESA_framebuffer_flip_y
// #define OPENGL_INCLUDE_GL_MESA_resize_buffers
// #define OPENGL_INCLUDE_GL_MESA_window_pos
// #define OPENGL_INCLUDE_GL_NVX_conditional_render
// #define OPENGL_INCLUDE_GL_NVX_gpu_multicast2
// #define OPENGL_INCLUDE_GL_NVX_linked_gpu_multicast
// #define OPENGL_INCLUDE_GL_NVX_progress_fence
// #define OPENGL_INCLUDE_GL_NV_alpha_to_coverage_dither_control
// #define OPENGL_INCLUDE_GL_NV_bindless_multi_draw_indirect
// #define OPENGL_INCLUDE_GL_NV_bindless_multi_draw_indirect_count
// #define OPENGL_INCLUDE_GL_NV_bindless_texture
// #define OPENGL_INCLUDE_GL_NV_blend_equation_advanced
// #define OPENGL_INCLUDE_GL_NV_clip_space_w_scaling
// #define OPENGL_INCLUDE_GL_NV_command_list
// #define OPENGL_INCLUDE_GL_NV_conditional_render
// #define OPENGL_INCLUDE_GL_NV_conservative_raster
// #define OPENGL_INCLUDE_GL_NV_conservative_raster_dilate
// #define OPENGL_INCLUDE_GL_NV_conservative_raster_pre_snap_triangles
// #define OPENGL_INCLUDE_GL_NV_copy_image
// #define OPENGL_INCLUDE_GL_NV_depth_buffer_float
// #define OPENGL_INCLUDE_GL_NV_draw_texture
// #define OPENGL_INCLUDE_GL_NV_draw_vulkan_image
// #define OPENGL_INCLUDE_GL_NV_evaluators
// #define OPENGL_INCLUDE_GL_NV_explicit_multisample
// #define OPENGL_INCLUDE_GL_NV_fence
// #define OPENGL_INCLUDE_GL_NV_fragment_coverage_to_color
// #define OPENGL_INCLUDE_GL_NV_fragment_program
// #define OPENGL_INCLUDE_GL_NV_framebuffer_mixed_samples
// #define OPENGL_INCLUDE_GL_NV_framebuffer_multisample_coverage
// #define OPENGL_INCLUDE_GL_NV_geometry_program4
// #define OPENGL_INCLUDE_GL_NV_gpu_multicast
// #define OPENGL_INCLUDE_GL_NV_gpu_program4
// #define OPENGL_INCLUDE_GL_NV_gpu_program5
// #define OPENGL_INCLUDE_GL_NV_half_float
// #define OPENGL_INCLUDE_GL_NV_memory_attachment
// #define OPENGL_INCLUDE_GL_NV_mesh_shader
// #define OPENGL_INCLUDE_GL_NV_occlusion_query
// #define OPENGL_INCLUDE_GL_NV_parameter_buffer_object
// #define OPENGL_INCLUDE_GL_NV_path_rendering
// #define OPENGL_INCLUDE_GL_NV_pixel_data_range
// #define OPENGL_INCLUDE_GL_NV_point_sprite
// #define OPENGL_INCLUDE_GL_NV_present_video
// #define OPENGL_INCLUDE_GL_NV_primitive_restart
// #define OPENGL_INCLUDE_GL_NV_query_resource
// #define OPENGL_INCLUDE_GL_NV_query_resource_tag
// #define OPENGL_INCLUDE_GL_NV_register_combiners
// #define OPENGL_INCLUDE_GL_NV_register_combiners2
// #define OPENGL_INCLUDE_GL_NV_sample_locations
// #define OPENGL_INCLUDE_GL_NV_scissor_exclusive
// #define OPENGL_INCLUDE_GL_NV_shader_buffer_load
// #define OPENGL_INCLUDE_GL_NV_shading_rate_image
// #define OPENGL_INCLUDE_GL_NV_texture_barrier
// #define OPENGL_INCLUDE_GL_NV_texture_multisample
// #define OPENGL_INCLUDE_GL_NV_transform_feedback
// #define OPENGL_INCLUDE_GL_NV_transform_feedback2
// #define OPENGL_INCLUDE_GL_NV_vdpau_interop
// #define OPENGL_INCLUDE_GL_NV_vdpau_interop2
// #define OPENGL_INCLUDE_GL_NV_vertex_array_range
// #define OPENGL_INCLUDE_GL_NV_vertex_attrib_integer_64bit
// #define OPENGL_INCLUDE_GL_NV_vertex_buffer_unified_memory
// #define OPENGL_INCLUDE_GL_NV_vertex_program
// #define OPENGL_INCLUDE_GL_NV_vertex_program4
// #define OPENGL_INCLUDE_GL_NV_video_capture
// #define OPENGL_INCLUDE_GL_NV_viewport_swizzle
// #define OPENGL_INCLUDE_GL_OVR_multiview
// #define OPENGL_INCLUDE_GL_PGI_misc_hints
// #define OPENGL_INCLUDE_GL_SGIS_detail_texture
// #define OPENGL_INCLUDE_GL_SGIS_fog_function
// #define OPENGL_INCLUDE_GL_SGIS_multisample
// #define OPENGL_INCLUDE_GL_SGIS_pixel_texture
// #define OPENGL_INCLUDE_GL_SGIS_point_parameters
// #define OPENGL_INCLUDE_GL_SGIS_sharpen_texture
// #define OPENGL_INCLUDE_GL_SGIS_texture4D
// #define OPENGL_INCLUDE_GL_SGIS_texture_color_mask
// #define OPENGL_INCLUDE_GL_SGIS_texture_filter4
// #define OPENGL_INCLUDE_GL_SGIX_async
// #define OPENGL_INCLUDE_GL_SGIX_flush_raster
// #define OPENGL_INCLUDE_GL_SGIX_fragment_lighting
// #define OPENGL_INCLUDE_GL_SGIX_framezoom
// #define OPENGL_INCLUDE_GL_SGIX_igloo_interface
// #define OPENGL_INCLUDE_GL_SGIX_instruments
// #define OPENGL_INCLUDE_GL_SGIX_list_priority
// #define OPENGL_INCLUDE_GL_SGIX_pixel_texture
// #define OPENGL_INCLUDE_GL_SGIX_polynomial_ffd
// #define OPENGL_INCLUDE_GL_SGIX_reference_plane
// #define OPENGL_INCLUDE_GL_SGIX_sprite
// #define OPENGL_INCLUDE_GL_SGIX_tag_sample_buffer
// #define OPENGL_INCLUDE_GL_SGI_color_table
// #define OPENGL_INCLUDE_GL_SUNX_constant_data
// #define OPENGL_INCLUDE_GL_SUN_global_alpha
// #define OPENGL_INCLUDE_GL_SUN_mesh_array
// #define OPENGL_INCLUDE_GL_SUN_triangle_list
// #define OPENGL_INCLUDE_GL_SUN_vertex
//
////////////////////////////////////////////////////////////////////////////////
//
// Specfies which WGL extensions should be included.
//
// #define OPENGL_INCLUDE_WGL_ARB_buffer_region
// #define OPENGL_INCLUDE_WGL_ARB_create_context
// #define OPENGL_INCLUDE_WGL_ARB_extensions_string
// #define OPENGL_INCLUDE_WGL_ARB_make_current_read
// #define OPENGL_INCLUDE_WGL_ARB_pbuffer
// #define OPENGL_INCLUDE_WGL_ARB_pixel_format
// #define OPENGL_INCLUDE_WGL_ARB_render_texture
// #define OPENGL_INCLUDE_WGL_3DL_stereo_control
// #define OPENGL_INCLUDE_WGL_AMD_gpu_association
// #define OPENGL_INCLUDE_WGL_EXT_display_color_table
// #define OPENGL_INCLUDE_WGL_EXT_extensions_string
// #define OPENGL_INCLUDE_WGL_EXT_make_current_read
// #define OPENGL_INCLUDE_WGL_EXT_pbuffer
// #define OPENGL_INCLUDE_WGL_EXT_pixel_format
// #define OPENGL_INCLUDE_WGL_EXT_swap_control
// #define OPENGL_INCLUDE_WGL_I3D_digital_video_control
// #define OPENGL_INCLUDE_WGL_I3D_gamma
// #define OPENGL_INCLUDE_WGL_I3D_genlock
// #define OPENGL_INCLUDE_WGL_I3D_image_buffer
// #define OPENGL_INCLUDE_WGL_I3D_swap_frame_lock
// #define OPENGL_INCLUDE_WGL_I3D_swap_frame_usage
// #define OPENGL_INCLUDE_WGL_NV_DX_interop
// #define OPENGL_INCLUDE_WGL_NV_copy_image
// #define OPENGL_INCLUDE_WGL_NV_delay_before_swap
// #define OPENGL_INCLUDE_WGL_NV_gpu_affinity
// #define OPENGL_INCLUDE_WGL_NV_present_video
// #define OPENGL_INCLUDE_WGL_NV_swap_group
// #define OPENGL_INCLUDE_WGL_NV_video_capture
// #define OPENGL_INCLUDE_WGL_NV_video_output
// #define OPENGL_INCLUDE_WGL_OML_sync_control
//
////////////////////////////////////////////////////////////////////////////////

#ifndef OPENGL_HPP__ /*///////////////////////////////////////////////////////*/
#define OPENGL_HPP__

/*////////////////////////////////////////////////////////////////////////////*/

/* -------------------------------------------------------------------------- */

#define OPENGL_VERSION_MAJOR 1
#define OPENGL_VERSION_MINOR 0
#define OPENGL_VERSION_PATCH 2

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_STATIC)
#define OPENGLDEF static
#else
#define OPENGLDEF
#endif

/* -------------------------------------------------------------------------- */

#if defined(_WIN32) && !defined(APIENTRY) && !defined(__CYGWIN__) && !defined(__SCITECH_SNAP__)
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif
#include <windows.h>
#endif

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

// Default version of OpenGL that we will target if not specified is 3.3.
#ifndef OPENGL_LOAD_GL_VERSION_MAJOR
#define OPENGL_LOAD_GL_VERSION_MAJOR 3
#endif
#ifndef OPENGL_LOAD_GL_VERSION_MINOR
#define OPENGL_LOAD_GL_VERSION_MINOR 3
#endif

/* -------------------------------------------------------------------------- */

#if (OPENGL_LOAD_GL_VERSION_MAJOR == 1 && OPENGL_LOAD_GL_VERSION_MINOR >= 0) || \
    (OPENGL_LOAD_GL_VERSION_MAJOR  > 1)
#define OPENGL_LOAD_GL_VERSION_1_0 1
#endif
#if (OPENGL_LOAD_GL_VERSION_MAJOR == 1 && OPENGL_LOAD_GL_VERSION_MINOR >= 1) || \
    (OPENGL_LOAD_GL_VERSION_MAJOR  > 1)
#define OPENGL_LOAD_GL_VERSION_1_1 1
#endif
#if (OPENGL_LOAD_GL_VERSION_MAJOR == 1 && OPENGL_LOAD_GL_VERSION_MINOR >= 2) || \
    (OPENGL_LOAD_GL_VERSION_MAJOR  > 1)
#define OPENGL_LOAD_GL_VERSION_1_2 1
#endif
#if (OPENGL_LOAD_GL_VERSION_MAJOR == 1 && OPENGL_LOAD_GL_VERSION_MINOR >= 3) || \
    (OPENGL_LOAD_GL_VERSION_MAJOR  > 1)
#define OPENGL_LOAD_GL_VERSION_1_3 1
#endif
#if (OPENGL_LOAD_GL_VERSION_MAJOR == 1 && OPENGL_LOAD_GL_VERSION_MINOR >= 4) || \
    (OPENGL_LOAD_GL_VERSION_MAJOR  > 1)
#define OPENGL_LOAD_GL_VERSION_1_4 1
#endif
#if (OPENGL_LOAD_GL_VERSION_MAJOR == 1 && OPENGL_LOAD_GL_VERSION_MINOR >= 5) || \
    (OPENGL_LOAD_GL_VERSION_MAJOR  > 1)
#define OPENGL_LOAD_GL_VERSION_1_5 1
#endif
#if (OPENGL_LOAD_GL_VERSION_MAJOR == 2 && OPENGL_LOAD_GL_VERSION_MINOR >= 0) || \
    (OPENGL_LOAD_GL_VERSION_MAJOR  > 2)
#define OPENGL_LOAD_GL_VERSION_2_0 1
#endif
#if (OPENGL_LOAD_GL_VERSION_MAJOR == 2 && OPENGL_LOAD_GL_VERSION_MINOR >= 1) || \
    (OPENGL_LOAD_GL_VERSION_MAJOR  > 2)
#define OPENGL_LOAD_GL_VERSION_2_1 1
#endif
#if (OPENGL_LOAD_GL_VERSION_MAJOR == 3 && OPENGL_LOAD_GL_VERSION_MINOR >= 0) || \
    (OPENGL_LOAD_GL_VERSION_MAJOR  > 3)
#define OPENGL_LOAD_GL_VERSION_3_0 1
#endif
#if (OPENGL_LOAD_GL_VERSION_MAJOR == 3 && OPENGL_LOAD_GL_VERSION_MINOR >= 1) || \
    (OPENGL_LOAD_GL_VERSION_MAJOR  > 3)
#define OPENGL_LOAD_GL_VERSION_3_1 1
#endif
#if (OPENGL_LOAD_GL_VERSION_MAJOR == 3 && OPENGL_LOAD_GL_VERSION_MINOR >= 2) || \
    (OPENGL_LOAD_GL_VERSION_MAJOR  > 3)
#define OPENGL_LOAD_GL_VERSION_3_2 1
#endif
#if (OPENGL_LOAD_GL_VERSION_MAJOR == 3 && OPENGL_LOAD_GL_VERSION_MINOR >= 3) || \
    (OPENGL_LOAD_GL_VERSION_MAJOR  > 3)
#define OPENGL_LOAD_GL_VERSION_3_3 1
#endif
#if (OPENGL_LOAD_GL_VERSION_MAJOR == 4 && OPENGL_LOAD_GL_VERSION_MINOR >= 0) || \
    (OPENGL_LOAD_GL_VERSION_MAJOR  > 4)
#define OPENGL_LOAD_GL_VERSION_4_0 1
#endif
#if (OPENGL_LOAD_GL_VERSION_MAJOR == 4 && OPENGL_LOAD_GL_VERSION_MINOR >= 1) || \
    (OPENGL_LOAD_GL_VERSION_MAJOR  > 4)
#define OPENGL_LOAD_GL_VERSION_4_1 1
#endif
#if (OPENGL_LOAD_GL_VERSION_MAJOR == 4 && OPENGL_LOAD_GL_VERSION_MINOR >= 2) || \
    (OPENGL_LOAD_GL_VERSION_MAJOR  > 4)
#define OPENGL_LOAD_GL_VERSION_4_2 1
#endif
#if (OPENGL_LOAD_GL_VERSION_MAJOR == 4 && OPENGL_LOAD_GL_VERSION_MINOR >= 3) || \
    (OPENGL_LOAD_GL_VERSION_MAJOR  > 4)
#define OPENGL_LOAD_GL_VERSION_4_3 1
#endif
#if (OPENGL_LOAD_GL_VERSION_MAJOR == 4 && OPENGL_LOAD_GL_VERSION_MINOR >= 4) || \
    (OPENGL_LOAD_GL_VERSION_MAJOR  > 4)
#define OPENGL_LOAD_GL_VERSION_4_4 1
#endif
#if (OPENGL_LOAD_GL_VERSION_MAJOR == 4 && OPENGL_LOAD_GL_VERSION_MINOR >= 5) || \
    (OPENGL_LOAD_GL_VERSION_MAJOR  > 4)
#define OPENGL_LOAD_GL_VERSION_4_5 1
#endif
#if (OPENGL_LOAD_GL_VERSION_MAJOR == 4 && OPENGL_LOAD_GL_VERSION_MINOR >= 6) || \
    (OPENGL_LOAD_GL_VERSION_MAJOR  > 4)
#define OPENGL_LOAD_GL_VERSION_4_6 1
#endif

/* -------------------------------------------------------------------------- */

#define OPENGL_INIT_PROC(name, ret, ...)              \
typedef ret (APIENTRYP OGLPROC__##name)(__VA_ARGS__); \
GLAPI OGLPROC__##name OGL__##name;                    \
OGLPROC__##name OGL__##name = NULL

#define OPENGL_LOAD_PROC(name, proc_loader)           \
OGL__##name = (OGLPROC__##name)((proc_loader)(#name))

/* -------------------------------------------------------------------------- */

#define OPENGL_CREATE_GL_EXTENSION_LOADER(ext, procs)          \
OPENGLDEF inline bool load_##ext (OpenGL_Proc_Loader loader)   \
{                                                              \
    if (!opengl_has_gl_extension(#ext, loader)) return false;  \
    if (!loader)                                return false;  \
    procs;                                                     \
    return true;                                               \
}

#define OPENGL_CREATE_WGL_EXTENSION_LOADER(ext, procs)         \
OPENGLDEF inline bool load_##ext (OpenGL_Proc_Loader loader)   \
{                                                              \
    if (!opengl_has_wgl_extension(#ext, loader)) return false; \
    if (!loader)                                 return false; \
    procs;                                                     \
    return true;                                               \
}

/* -------------------------------------------------------------------------- */

// By default we include these so that opengl_has_wgl_extension() can work.
#define OPENGL_INCLUDE_WGL_ARB_extensions_string
#define OPENGL_INCLUDE_WGL_EXT_extensions_string

/* -------------------------------------------------------------------------- */

#include "GL/KHR/khrplatform.h"

#include "GL/gl.h"
#include "GL/wgl.h"

/* -------------------------------------------------------------------------- */

typedef void* (*OpenGL_Proc_Loader)(const char* proc_name);

/* -------------------------------------------------------------------------- */

OPENGLDEF void* default_opengl_proc_loader (const char* proc_name);

OPENGLDEF bool load_opengl_procs    (OpenGL_Proc_Loader loader);
OPENGLDEF bool is_opengl_proc_valid (void* proc);

OPENGLDEF bool opengl_has_gl_extension  (const char* ext, OpenGL_Proc_Loader loader);
OPENGLDEF bool opengl_has_wgl_extension (const char* ext, OpenGL_Proc_Loader loader);

/* -------------------------------------------------------------------------- */

/*////////////////////////////////////////////////////////////////////////////*/

#endif OPENGL_HPP__ /*////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/
/*////////////////////////////// IMPLEMENTATION //////////////////////////////*/
/*////////////////////////////////////////////////////////////////////////////*/

#ifdef OPENGL_IMPLEMENTATION /*///////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/

/* -------------------------------------------------------------------------- */

static inline bool internal__load_GL_VERSION_1_0 (OpenGL_Proc_Loader loader);
static inline bool internal__load_GL_VERSION_1_1 (OpenGL_Proc_Loader loader);
static inline bool internal__load_GL_VERSION_1_2 (OpenGL_Proc_Loader loader);
static inline bool internal__load_GL_VERSION_1_3 (OpenGL_Proc_Loader loader);
static inline bool internal__load_GL_VERSION_1_4 (OpenGL_Proc_Loader loader);
static inline bool internal__load_GL_VERSION_1_5 (OpenGL_Proc_Loader loader);
static inline bool internal__load_GL_VERSION_2_0 (OpenGL_Proc_Loader loader);
static inline bool internal__load_GL_VERSION_2_1 (OpenGL_Proc_Loader loader);
static inline bool internal__load_GL_VERSION_3_0 (OpenGL_Proc_Loader loader);
static inline bool internal__load_GL_VERSION_3_1 (OpenGL_Proc_Loader loader);
static inline bool internal__load_GL_VERSION_3_2 (OpenGL_Proc_Loader loader);
static inline bool internal__load_GL_VERSION_3_3 (OpenGL_Proc_Loader loader);
static inline bool internal__load_GL_VERSION_4_0 (OpenGL_Proc_Loader loader);
static inline bool internal__load_GL_VERSION_4_1 (OpenGL_Proc_Loader loader);
static inline bool internal__load_GL_VERSION_4_2 (OpenGL_Proc_Loader loader);
static inline bool internal__load_GL_VERSION_4_3 (OpenGL_Proc_Loader loader);
static inline bool internal__load_GL_VERSION_4_4 (OpenGL_Proc_Loader loader);
static inline bool internal__load_GL_VERSION_4_5 (OpenGL_Proc_Loader loader);
static inline bool internal__load_GL_VERSION_4_6 (OpenGL_Proc_Loader loader);

/* -------------------------------------------------------------------------- */

OPENGLDEF void* default_opengl_proc_loader (const char* proc_name)
{
    void* proc = wglGetProcAddress(proc_name);
    if (!is_opengl_proc_valid(proc))
    {
        proc = GetProcAddress(LoadLibraryA("opengl32.dll"), proc_name);
    }
    return proc;
}

/* -------------------------------------------------------------------------- */

OPENGLDEF bool load_opengl_procs (OpenGL_Proc_Loader loader)
{
    if (!loader) return false;

    internal__load_GL_VERSION_1_0(loader);
    internal__load_GL_VERSION_1_1(loader);
    internal__load_GL_VERSION_1_2(loader);
    internal__load_GL_VERSION_1_3(loader);
    internal__load_GL_VERSION_1_4(loader);
    internal__load_GL_VERSION_1_5(loader);
    internal__load_GL_VERSION_2_0(loader);
    internal__load_GL_VERSION_2_1(loader);
    internal__load_GL_VERSION_3_0(loader);
    internal__load_GL_VERSION_3_1(loader);
    internal__load_GL_VERSION_3_2(loader);
    internal__load_GL_VERSION_3_3(loader);
    internal__load_GL_VERSION_4_0(loader);
    internal__load_GL_VERSION_4_1(loader);
    internal__load_GL_VERSION_4_2(loader);
    internal__load_GL_VERSION_4_3(loader);
    internal__load_GL_VERSION_4_4(loader);
    internal__load_GL_VERSION_4_5(loader);
    internal__load_GL_VERSION_4_6(loader);

    return true;
}

OPENGLDEF bool is_opengl_proc_valid (void* proc)
{
    // Certain GL proc loaders (e.g. Windows) may return non-null values
    // to represent failure -- depening on the implementation. So it is
    // preferred that this function be used to check if a proc is valid.
    //
    // https://www.khronos.org/opengl/wiki/Load_OpenGL_Functions#Windows

    return !((proc == (void*)0x0) || (proc == (void*)0x1) ||
             (proc == (void*)0x2) || (proc == (void*)0x3) ||
             (proc == (void*) -1));
}

/* -------------------------------------------------------------------------- */

OPENGLDEF bool opengl_has_gl_extension (const char* ext, OpenGL_Proc_Loader loader)
{
    #if (OPENGL_LOAD_GL_VERSION_MAJOR >= 3)
    GLint num_exts = 0;
    glGetIntegerv(GL_NUM_EXTENSIONS, &num_exts);
    for (int i=0; i<num_exts; ++i)
    {
        const char* curr_ext = (const char*)glGetStringi(GL_EXTENSIONS,i);
        if (strcmp(curr_ext, ext) == 0)
        {
            return true;
        }
    }
    #else
    const char* exts = (const char*)glGetString(GL_EXTENSIONS);
    if (exts)
    {
        return (strstr(exts, ext) != NULL);
    }
    #endif // (OPENGL_LOAD_GL_VERSION_MAJOR >= 3)
    return false;
}

OPENGLDEF bool opengl_has_wgl_extension (const char* ext, OpenGL_Proc_Loader loader)
{
    OPENGL_LOAD_PROC(wglGetExtensionsStringARB, loader); // @Improve: Not actually used yet...
    OPENGL_LOAD_PROC(wglGetExtensionsStringEXT, loader);
    if (wglGetExtensionsStringEXT)
    {
        const char* exts = wglGetExtensionsStringEXT();
        if (exts)
        {
            return (strstr(exts, ext) != NULL);
        }
    }
    return false;
}

/* -------------------------------------------------------------------------- */

static bool internal__load_GL_VERSION_1_0 (OpenGL_Proc_Loader loader)
{
    #if defined(OPENGL_LOAD_GL_VERSION_1_0)
    OPENGL_LOAD_PROC(glCullFace,               loader);
    OPENGL_LOAD_PROC(glFrontFace,              loader);
    OPENGL_LOAD_PROC(glHint,                   loader);
    OPENGL_LOAD_PROC(glLineWidth,              loader);
    OPENGL_LOAD_PROC(glPointSize,              loader);
    OPENGL_LOAD_PROC(glPolygonMode,            loader);
    OPENGL_LOAD_PROC(glScissor,                loader);
    OPENGL_LOAD_PROC(glTexParameterf,          loader);
    OPENGL_LOAD_PROC(glTexParameterfv,         loader);
    OPENGL_LOAD_PROC(glTexParameteri,          loader);
    OPENGL_LOAD_PROC(glTexParameteriv,         loader);
    OPENGL_LOAD_PROC(glTexImage1D,             loader);
    OPENGL_LOAD_PROC(glTexImage2D,             loader);
    OPENGL_LOAD_PROC(glDrawBuffer,             loader);
    OPENGL_LOAD_PROC(glClear,                  loader);
    OPENGL_LOAD_PROC(glClearColor,             loader);
    OPENGL_LOAD_PROC(glClearStencil,           loader);
    OPENGL_LOAD_PROC(glClearDepth,             loader);
    OPENGL_LOAD_PROC(glStencilMask,            loader);
    OPENGL_LOAD_PROC(glColorMask,              loader);
    OPENGL_LOAD_PROC(glDepthMask,              loader);
    OPENGL_LOAD_PROC(glDisable,                loader);
    OPENGL_LOAD_PROC(glEnable,                 loader);
    OPENGL_LOAD_PROC(glFinish,                 loader);
    OPENGL_LOAD_PROC(glFlush,                  loader);
    OPENGL_LOAD_PROC(glBlendFunc,              loader);
    OPENGL_LOAD_PROC(glLogicOp,                loader);
    OPENGL_LOAD_PROC(glStencilFunc,            loader);
    OPENGL_LOAD_PROC(glStencilOp,              loader);
    OPENGL_LOAD_PROC(glDepthFunc,              loader);
    OPENGL_LOAD_PROC(glPixelStoref,            loader);
    OPENGL_LOAD_PROC(glPixelStorei,            loader);
    OPENGL_LOAD_PROC(glReadBuffer,             loader);
    OPENGL_LOAD_PROC(glReadPixels,             loader);
    OPENGL_LOAD_PROC(glGetBooleanv,            loader);
    OPENGL_LOAD_PROC(glGetDoublev,             loader);
    OPENGL_LOAD_PROC(glGetError,               loader);
    OPENGL_LOAD_PROC(glGetFloatv,              loader);
    OPENGL_LOAD_PROC(glGetIntegerv,            loader);
    OPENGL_LOAD_PROC(glGetString,              loader);
    OPENGL_LOAD_PROC(glGetTexImage,            loader);
    OPENGL_LOAD_PROC(glGetTexParameterfv,      loader);
    OPENGL_LOAD_PROC(glGetTexParameteriv,      loader);
    OPENGL_LOAD_PROC(glGetTexLevelParameterfv, loader);
    OPENGL_LOAD_PROC(glGetTexLevelParameteriv, loader);
    OPENGL_LOAD_PROC(glIsEnabled,              loader);
    OPENGL_LOAD_PROC(glDepthRange,             loader);
    OPENGL_LOAD_PROC(glViewport,               loader);
    OPENGL_LOAD_PROC(glNewList,                loader);
    #if defined(OPENGL_USE_COMPATIBILITY_PROFILE)
    OPENGL_LOAD_PROC(glEndList,                loader);
    OPENGL_LOAD_PROC(glCallList,               loader);
    OPENGL_LOAD_PROC(glCallLists,              loader);
    OPENGL_LOAD_PROC(glDeleteLists,            loader);
    OPENGL_LOAD_PROC(glGenLists,               loader);
    OPENGL_LOAD_PROC(glListBase,               loader);
    OPENGL_LOAD_PROC(glBegin,                  loader);
    OPENGL_LOAD_PROC(glBitmap,                 loader);
    OPENGL_LOAD_PROC(glColor3b,                loader);
    OPENGL_LOAD_PROC(glColor3bv,               loader);
    OPENGL_LOAD_PROC(glColor3d,                loader);
    OPENGL_LOAD_PROC(glColor3dv,               loader);
    OPENGL_LOAD_PROC(glColor3f,                loader);
    OPENGL_LOAD_PROC(glColor3fv,               loader);
    OPENGL_LOAD_PROC(glColor3i,                loader);
    OPENGL_LOAD_PROC(glColor3iv,               loader);
    OPENGL_LOAD_PROC(glColor3s,                loader);
    OPENGL_LOAD_PROC(glColor3sv,               loader);
    OPENGL_LOAD_PROC(glColor3ub,               loader);
    OPENGL_LOAD_PROC(glColor3ubv,              loader);
    OPENGL_LOAD_PROC(glColor3ui,               loader);
    OPENGL_LOAD_PROC(glColor3uiv,              loader);
    OPENGL_LOAD_PROC(glColor3us,               loader);
    OPENGL_LOAD_PROC(glColor3usv,              loader);
    OPENGL_LOAD_PROC(glColor4b,                loader);
    OPENGL_LOAD_PROC(glColor4bv,               loader);
    OPENGL_LOAD_PROC(glColor4d,                loader);
    OPENGL_LOAD_PROC(glColor4dv,               loader);
    OPENGL_LOAD_PROC(glColor4f,                loader);
    OPENGL_LOAD_PROC(glColor4fv,               loader);
    OPENGL_LOAD_PROC(glColor4i,                loader);
    OPENGL_LOAD_PROC(glColor4iv,               loader);
    OPENGL_LOAD_PROC(glColor4s,                loader);
    OPENGL_LOAD_PROC(glColor4sv,               loader);
    OPENGL_LOAD_PROC(glColor4ub,               loader);
    OPENGL_LOAD_PROC(glColor4ubv,              loader);
    OPENGL_LOAD_PROC(glColor4ui,               loader);
    OPENGL_LOAD_PROC(glColor4uiv,              loader);
    OPENGL_LOAD_PROC(glColor4us,               loader);
    OPENGL_LOAD_PROC(glColor4usv,              loader);
    OPENGL_LOAD_PROC(glEdgeFlag,               loader);
    OPENGL_LOAD_PROC(glEdgeFlagv,              loader);
    OPENGL_LOAD_PROC(glEnd,                    loader);
    OPENGL_LOAD_PROC(glIndexd,                 loader);
    OPENGL_LOAD_PROC(glIndexdv,                loader);
    OPENGL_LOAD_PROC(glIndexf,                 loader);
    OPENGL_LOAD_PROC(glIndexfv,                loader);
    OPENGL_LOAD_PROC(glIndexi,                 loader);
    OPENGL_LOAD_PROC(glIndexiv,                loader);
    OPENGL_LOAD_PROC(glIndexs,                 loader);
    OPENGL_LOAD_PROC(glIndexsv,                loader);
    OPENGL_LOAD_PROC(glNormal3b,               loader);
    OPENGL_LOAD_PROC(glNormal3bv,              loader);
    OPENGL_LOAD_PROC(glNormal3d,               loader);
    OPENGL_LOAD_PROC(glNormal3dv,              loader);
    OPENGL_LOAD_PROC(glNormal3f,               loader);
    OPENGL_LOAD_PROC(glNormal3fv,              loader);
    OPENGL_LOAD_PROC(glNormal3i,               loader);
    OPENGL_LOAD_PROC(glNormal3uv,              loader);
    OPENGL_LOAD_PROC(glNormal3s,               loader);
    OPENGL_LOAD_PROC(glNormal3sv,              loader);
    OPENGL_LOAD_PROC(glRasterPos2d,            loader);
    OPENGL_LOAD_PROC(glRasterPos2dv,           loader);
    OPENGL_LOAD_PROC(glRasterPos2f,            loader);
    OPENGL_LOAD_PROC(glRasterPos2fv,           loader);
    OPENGL_LOAD_PROC(glRasterPos2i,            loader);
    OPENGL_LOAD_PROC(glRasterPos2iv,           loader);
    OPENGL_LOAD_PROC(glRasterPos2s,            loader);
    OPENGL_LOAD_PROC(glRasterPos2sv,           loader);
    OPENGL_LOAD_PROC(glRasterPos3d,            loader);
    OPENGL_LOAD_PROC(glRasterPos3dv,           loader);
    OPENGL_LOAD_PROC(glRasterPos3f,            loader);
    OPENGL_LOAD_PROC(glRasterPos3fv,           loader);
    OPENGL_LOAD_PROC(glRasterPos3i,            loader);
    OPENGL_LOAD_PROC(glRasterPos3iv,           loader);
    OPENGL_LOAD_PROC(glRasterPos3s,            loader);
    OPENGL_LOAD_PROC(glRasterPos3sv,           loader);
    OPENGL_LOAD_PROC(glRasterPos4d,            loader);
    OPENGL_LOAD_PROC(glRasterPos4dv,           loader);
    OPENGL_LOAD_PROC(glRasterPos4f,            loader);
    OPENGL_LOAD_PROC(glRasterPos4fv,           loader);
    OPENGL_LOAD_PROC(glRasterPos4i,            loader);
    OPENGL_LOAD_PROC(glRasterPos4iv,           loader);
    OPENGL_LOAD_PROC(glRasterPos4s,            loader);
    OPENGL_LOAD_PROC(glRasterPos4sv,           loader);
    OPENGL_LOAD_PROC(glRectd,                  loader);
    OPENGL_LOAD_PROC(glRectdv,                 loader);
    OPENGL_LOAD_PROC(glRectf,                  loader);
    OPENGL_LOAD_PROC(glRectfv,                 loader);
    OPENGL_LOAD_PROC(glRecti,                  loader);
    OPENGL_LOAD_PROC(glRectiv,                 loader);
    OPENGL_LOAD_PROC(glRects,                  loader);
    OPENGL_LOAD_PROC(glRectsv,                 loader);
    OPENGL_LOAD_PROC(glTexCoord1d,             loader);
    OPENGL_LOAD_PROC(glTexCoord1dv,            loader);
    OPENGL_LOAD_PROC(glTexCoord1f,             loader);
    OPENGL_LOAD_PROC(glTexCoord1fv,            loader);
    OPENGL_LOAD_PROC(glTexCoord1i,             loader);
    OPENGL_LOAD_PROC(glTexCoord1iv,            loader);
    OPENGL_LOAD_PROC(glTexCoord1s,             loader);
    OPENGL_LOAD_PROC(glTexCoord1sv,            loader);
    OPENGL_LOAD_PROC(glTexCoord2d,             loader);
    OPENGL_LOAD_PROC(glTexCoord2dv,            loader);
    OPENGL_LOAD_PROC(glTexCoord2f,             loader);
    OPENGL_LOAD_PROC(glTexCoord2fv,            loader);
    OPENGL_LOAD_PROC(glTexCoord2i,             loader);
    OPENGL_LOAD_PROC(glTexCoord2iv,            loader);
    OPENGL_LOAD_PROC(glTexCoord2s,             loader);
    OPENGL_LOAD_PROC(glTexCoord2sv,            loader);
    OPENGL_LOAD_PROC(glTexCoord3d,             loader);
    OPENGL_LOAD_PROC(glTexCoord3dv,            loader);
    OPENGL_LOAD_PROC(glTexCoord3f,             loader);
    OPENGL_LOAD_PROC(glTexCoord3fv,            loader);
    OPENGL_LOAD_PROC(glTexCoord3i,             loader);
    OPENGL_LOAD_PROC(glTexCoord3iv,            loader);
    OPENGL_LOAD_PROC(glTexCoord3s,             loader);
    OPENGL_LOAD_PROC(glTexCoord3sv,            loader);
    OPENGL_LOAD_PROC(glTexCoord4d,             loader);
    OPENGL_LOAD_PROC(glTexCoord4dv,            loader);
    OPENGL_LOAD_PROC(glTexCoord4f,             loader);
    OPENGL_LOAD_PROC(glTexCoord4fv,            loader);
    OPENGL_LOAD_PROC(glTexCoord4i,             loader);
    OPENGL_LOAD_PROC(glTexCoord4iv,            loader);
    OPENGL_LOAD_PROC(glTexCoord4s,             loader);
    OPENGL_LOAD_PROC(glTexCoord4sv,            loader);
    OPENGL_LOAD_PROC(glVertex2d,               loader);
    OPENGL_LOAD_PROC(glVertex2dv,              loader);
    OPENGL_LOAD_PROC(glVertex2f,               loader);
    OPENGL_LOAD_PROC(glVertex2fv,              loader);
    OPENGL_LOAD_PROC(glVertex2i,               loader);
    OPENGL_LOAD_PROC(glVertex2iv,              loader);
    OPENGL_LOAD_PROC(glVertex2s,               loader);
    OPENGL_LOAD_PROC(glVertex2sv,              loader);
    OPENGL_LOAD_PROC(glVertex3d,               loader);
    OPENGL_LOAD_PROC(glVertex3dv,              loader);
    OPENGL_LOAD_PROC(glVertex3f,               loader);
    OPENGL_LOAD_PROC(glVertex3fv,              loader);
    OPENGL_LOAD_PROC(glVertex3i,               loader);
    OPENGL_LOAD_PROC(glVertex3iv,              loader);
    OPENGL_LOAD_PROC(glVertex3s,               loader);
    OPENGL_LOAD_PROC(glVertex3sv,              loader);
    OPENGL_LOAD_PROC(glVertex4d,               loader);
    OPENGL_LOAD_PROC(glVertex4dv,              loader);
    OPENGL_LOAD_PROC(glVertex4f,               loader);
    OPENGL_LOAD_PROC(glVertex4fv,              loader);
    OPENGL_LOAD_PROC(glVertex4i,               loader);
    OPENGL_LOAD_PROC(glVertex4iv,              loader);
    OPENGL_LOAD_PROC(glVertex4s,               loader);
    OPENGL_LOAD_PROC(glVertex4sv,              loader);
    OPENGL_LOAD_PROC(glClipPlane,              loader);
    OPENGL_LOAD_PROC(glColorMaterial,          loader);
    OPENGL_LOAD_PROC(glFogf,                   loader);
    OPENGL_LOAD_PROC(glFogfv,                  loader);
    OPENGL_LOAD_PROC(glFogi,                   loader);
    OPENGL_LOAD_PROC(glFogiv,                  loader);
    OPENGL_LOAD_PROC(glLightf,                 loader);
    OPENGL_LOAD_PROC(glLightfv,                loader);
    OPENGL_LOAD_PROC(glLighti,                 loader);
    OPENGL_LOAD_PROC(glLightiv,                loader);
    OPENGL_LOAD_PROC(glLightModelf,            loader);
    OPENGL_LOAD_PROC(glLightModelfv,           loader);
    OPENGL_LOAD_PROC(glLightModeli,            loader);
    OPENGL_LOAD_PROC(glLightModeliv,           loader);
    OPENGL_LOAD_PROC(glLineStipple,            loader);
    OPENGL_LOAD_PROC(glMaterialf,              loader);
    OPENGL_LOAD_PROC(glMaterialfv,             loader);
    OPENGL_LOAD_PROC(glMateriali,              loader);
    OPENGL_LOAD_PROC(glMaterialiv,             loader);
    OPENGL_LOAD_PROC(glPolygonStipple,         loader);
    OPENGL_LOAD_PROC(glShadeModel,             loader);
    OPENGL_LOAD_PROC(glTexEnvf,                loader);
    OPENGL_LOAD_PROC(glTexEnvfv,               loader);
    OPENGL_LOAD_PROC(glTexEnvi,                loader);
    OPENGL_LOAD_PROC(glTexEnviv,               loader);
    OPENGL_LOAD_PROC(glTexGend,                loader);
    OPENGL_LOAD_PROC(glTexGendv,               loader);
    OPENGL_LOAD_PROC(glTexGenf,                loader);
    OPENGL_LOAD_PROC(glTexGenfv,               loader);
    OPENGL_LOAD_PROC(glTexGeni,                loader);
    OPENGL_LOAD_PROC(glTexGeniv,               loader);
    OPENGL_LOAD_PROC(glFeedbackBuffer,         loader);
    OPENGL_LOAD_PROC(glSelectBuffer,           loader);
    OPENGL_LOAD_PROC(glRenderMode,             loader);
    OPENGL_LOAD_PROC(glInitNames,              loader);
    OPENGL_LOAD_PROC(glLoadName,               loader);
    OPENGL_LOAD_PROC(glPassThrough,            loader);
    OPENGL_LOAD_PROC(glPopName,                loader);
    OPENGL_LOAD_PROC(glPushName,               loader);
    OPENGL_LOAD_PROC(glClearAccum,             loader);
    OPENGL_LOAD_PROC(glClearIndex,             loader);
    OPENGL_LOAD_PROC(glIndexMask,              loader);
    OPENGL_LOAD_PROC(glAccum,                  loader);
    OPENGL_LOAD_PROC(glPopAttrib,              loader);
    OPENGL_LOAD_PROC(glPushAttrib,             loader);
    OPENGL_LOAD_PROC(glMap1d,                  loader);
    OPENGL_LOAD_PROC(glMap1f,                  loader);
    OPENGL_LOAD_PROC(glMap2d,                  loader);
    OPENGL_LOAD_PROC(glMap2f,                  loader);
    OPENGL_LOAD_PROC(glMapGrid1d,              loader);
    OPENGL_LOAD_PROC(glMapGrid1f,              loader);
    OPENGL_LOAD_PROC(glMapGrid2d,              loader);
    OPENGL_LOAD_PROC(glMapGrid2f,              loader);
    OPENGL_LOAD_PROC(glEvalCoord1d,            loader);
    OPENGL_LOAD_PROC(glEvalCoord1dv,           loader);
    OPENGL_LOAD_PROC(glEvalCoord1f,            loader);
    OPENGL_LOAD_PROC(glEvalCoord1fv,           loader);
    OPENGL_LOAD_PROC(glEvalCoord2d,            loader);
    OPENGL_LOAD_PROC(glEvalCoord2dv,           loader);
    OPENGL_LOAD_PROC(glEvalCoord2f,            loader);
    OPENGL_LOAD_PROC(glEvalCoord2fv,           loader);
    OPENGL_LOAD_PROC(glEvalMesh1,              loader);
    OPENGL_LOAD_PROC(glEvalPoint1,             loader);
    OPENGL_LOAD_PROC(glEvalMesh2,              loader);
    OPENGL_LOAD_PROC(glEvalPoint2,             loader);
    OPENGL_LOAD_PROC(glAlphaFunc,              loader);
    OPENGL_LOAD_PROC(glPixelZoom,              loader);
    OPENGL_LOAD_PROC(glPixelTransferf,         loader);
    OPENGL_LOAD_PROC(glPixelTransferi,         loader);
    OPENGL_LOAD_PROC(glPixelMapfv,             loader);
    OPENGL_LOAD_PROC(glPixelMapuiv,            loader);
    OPENGL_LOAD_PROC(glPixelMapusv,            loader);
    OPENGL_LOAD_PROC(glCopyPixels,             loader);
    OPENGL_LOAD_PROC(glDrawPixels,             loader);
    OPENGL_LOAD_PROC(glGetClipPlane,           loader);
    OPENGL_LOAD_PROC(glGetLightfv,             loader);
    OPENGL_LOAD_PROC(glGetLightiv,             loader);
    OPENGL_LOAD_PROC(glGetMapdv,               loader);
    OPENGL_LOAD_PROC(glGetMapfv,               loader);
    OPENGL_LOAD_PROC(glGetMapiv,               loader);
    OPENGL_LOAD_PROC(glGetMaterialfv,          loader);
    OPENGL_LOAD_PROC(glGetMaterialiv,          loader);
    OPENGL_LOAD_PROC(glGetPixelMapfv,          loader);
    OPENGL_LOAD_PROC(glGetPixelMapuiv,         loader);
    OPENGL_LOAD_PROC(glGetPixelMapusv,         loader);
    OPENGL_LOAD_PROC(glGetPolygonStipple,      loader);
    OPENGL_LOAD_PROC(glGetTexEnvfv,            loader);
    OPENGL_LOAD_PROC(glGetTexEnviv,            loader);
    OPENGL_LOAD_PROC(glGetTexGendv,            loader);
    OPENGL_LOAD_PROC(glGetTexGenfv,            loader);
    OPENGL_LOAD_PROC(glGetTexGeniv,            loader);
    OPENGL_LOAD_PROC(glIsList,                 loader);
    OPENGL_LOAD_PROC(glFrustum,                loader);
    OPENGL_LOAD_PROC(glLoadIdentity,           loader);
    OPENGL_LOAD_PROC(glLoadMatrixf,            loader);
    OPENGL_LOAD_PROC(glLoadMatrixd,            loader);
    OPENGL_LOAD_PROC(glMatrixMode,             loader);
    OPENGL_LOAD_PROC(glMultMatrixf,            loader);
    OPENGL_LOAD_PROC(glMultMatrixd,            loader);
    OPENGL_LOAD_PROC(glOrtho,                  loader);
    OPENGL_LOAD_PROC(glPopMatrix,              loader);
    OPENGL_LOAD_PROC(glPushMatrix,             loader);
    OPENGL_LOAD_PROC(glRotated,                loader);
    OPENGL_LOAD_PROC(glRotatef,                loader);
    OPENGL_LOAD_PROC(glScaled,                 loader);
    OPENGL_LOAD_PROC(glScalef,                 loader);
    OPENGL_LOAD_PROC(glTranslated,             loader);
    OPENGL_LOAD_PROC(glTranslatef,             loader);
    #endif // OPENGL_USE_COMPATIBILITY_PROFILE
    #endif // OPENGL_LOAD_GL_VERSION_1_0
    return true;
}

/* -------------------------------------------------------------------------- */

static bool internal__load_GL_VERSION_1_1 (OpenGL_Proc_Loader loader)
{
    #if defined(OPENGL_LOAD_GL_VERSION_1_1)
    OPENGL_LOAD_PROC(glDrawArrays,          loader);
    OPENGL_LOAD_PROC(glDrawElements,        loader);
    OPENGL_LOAD_PROC(glGetPointerv,         loader);
    OPENGL_LOAD_PROC(glPolygonOffset,       loader);
    OPENGL_LOAD_PROC(glCopyTexImage1D,      loader);
    OPENGL_LOAD_PROC(glCopyTexImage2D,      loader);
    OPENGL_LOAD_PROC(glCopyTexSubImage1D,   loader);
    OPENGL_LOAD_PROC(glCopyTexSubImage2D,   loader);
    OPENGL_LOAD_PROC(glTexSubImage1D,       loader);
    OPENGL_LOAD_PROC(glTexSubImage2D,       loader);
    OPENGL_LOAD_PROC(glBindTexture,         loader);
    OPENGL_LOAD_PROC(glDeleteTextures,      loader);
    OPENGL_LOAD_PROC(glGenTextures,         loader);
    OPENGL_LOAD_PROC(glIsTexture,           loader);
    #if defined(OPENGL_USE_COMPATIBILITY_PROFILE)
    OPENGL_LOAD_PROC(glArrayElement,        loader);
    OPENGL_LOAD_PROC(glColorPointer,        loader);
    OPENGL_LOAD_PROC(glDisableClientState,  loader);
    OPENGL_LOAD_PROC(glEdgeFlagPointer,     loader);
    OPENGL_LOAD_PROC(glEnableClientState,   loader);
    OPENGL_LOAD_PROC(glIndexPointer,        loader);
    OPENGL_LOAD_PROC(glInterleavedArrays,   loader);
    OPENGL_LOAD_PROC(glNormalPointer,       loader);
    OPENGL_LOAD_PROC(glTexCoordPointer,     loader);
    OPENGL_LOAD_PROC(glVertexPointer,       loader);
    OPENGL_LOAD_PROC(glAreTexturesResident, loader);
    OPENGL_LOAD_PROC(glPrioritizeTextures,  loader);
    OPENGL_LOAD_PROC(glIndexub,             loader);
    OPENGL_LOAD_PROC(glIndexubv,            loader);
    OPENGL_LOAD_PROC(glPopClientAttrib,     loader);
    OPENGL_LOAD_PROC(glPushClientAttrib,    loader);
    #endif // OPENGL_USE_COMPATIBILITY_PROFILE
    #endif // OPENGL_LOAD_GL_VERSION_1_1
    return true;
}

/* -------------------------------------------------------------------------- */

static bool internal__load_GL_VERSION_1_2 (OpenGL_Proc_Loader loader)
{
    #if defined(OPENGL_LOAD_GL_VERSION_1_2)
    OPENGL_LOAD_PROC(glDrawRangeElements, loader);
    OPENGL_LOAD_PROC(glTexImage3D,        loader);
    OPENGL_LOAD_PROC(glTexSubImage3D,     loader);
    OPENGL_LOAD_PROC(glCopyTexSubImage3D, loader);
    #endif // OPENGL_LOAD_GL_VERSION_1_2
    return true;
}

/* -------------------------------------------------------------------------- */

static bool internal__load_GL_VERSION_1_3 (OpenGL_Proc_Loader loader)
{
    #if defined(OPENGL_LOAD_GL_VERSION_1_3)
    OPENGL_LOAD_PROC(glActiveTexture,           loader);
    OPENGL_LOAD_PROC(glSampleCoverage,          loader);
    OPENGL_LOAD_PROC(glCompressedTexImage3D,    loader);
    OPENGL_LOAD_PROC(glCompressedTexImage2D,    loader);
    OPENGL_LOAD_PROC(glCompressedTexImage1D,    loader);
    OPENGL_LOAD_PROC(glCompressedTexSubImage3D, loader);
    OPENGL_LOAD_PROC(glCompressedTexSubImage2D, loader);
    OPENGL_LOAD_PROC(glCompressedTexSubImage1D, loader);
    OPENGL_LOAD_PROC(glGetCompressedTexImage,   loader);
    #if defined(OPENGL_USE_COMPATIBILITY_PROFILE)
    OPENGL_LOAD_PROC(glClientActiveTexture,     loader);
    OPENGL_LOAD_PROC(glMultiTexCoord1d,         loader);
    OPENGL_LOAD_PROC(glMultiTexCoord1dv,        loader);
    OPENGL_LOAD_PROC(glMultiTexCoord1f,         loader);
    OPENGL_LOAD_PROC(glMultiTexCoord1fv,        loader);
    OPENGL_LOAD_PROC(glMultiTexCoord1i,         loader);
    OPENGL_LOAD_PROC(glMultiTexCoord1iv,        loader);
    OPENGL_LOAD_PROC(glMultiTexCoord1s,         loader);
    OPENGL_LOAD_PROC(glMultiTexCoord1sv,        loader);
    OPENGL_LOAD_PROC(glMultiTexCoord2d,         loader);
    OPENGL_LOAD_PROC(glMultiTexCoord2dv,        loader);
    OPENGL_LOAD_PROC(glMultiTexCoord2f,         loader);
    OPENGL_LOAD_PROC(glMultiTexCoord2fv,        loader);
    OPENGL_LOAD_PROC(glMultiTexCoord2i,         loader);
    OPENGL_LOAD_PROC(glMultiTexCoord2iv,        loader);
    OPENGL_LOAD_PROC(glMultiTexCoord2s,         loader);
    OPENGL_LOAD_PROC(glMultiTexCoord2sv,        loader);
    OPENGL_LOAD_PROC(glMultiTexCoord3d,         loader);
    OPENGL_LOAD_PROC(glMultiTexCoord3dv,        loader);
    OPENGL_LOAD_PROC(glMultiTexCoord3f,         loader);
    OPENGL_LOAD_PROC(glMultiTexCoord3fv,        loader);
    OPENGL_LOAD_PROC(glMultiTexCoord3i,         loader);
    OPENGL_LOAD_PROC(glMultiTexCoord3iv,        loader);
    OPENGL_LOAD_PROC(glMultiTexCoord3s,         loader);
    OPENGL_LOAD_PROC(glMultiTexCoord3sv,        loader);
    OPENGL_LOAD_PROC(glMultiTexCoord4d,         loader);
    OPENGL_LOAD_PROC(glMultiTexCoord4dv,        loader);
    OPENGL_LOAD_PROC(glMultiTexCoord4f,         loader);
    OPENGL_LOAD_PROC(glMultiTexCoord4fv,        loader);
    OPENGL_LOAD_PROC(glMultiTexCoord4i,         loader);
    OPENGL_LOAD_PROC(glMultiTexCoord4iv,        loader);
    OPENGL_LOAD_PROC(glMultiTexCoord4s,         loader);
    OPENGL_LOAD_PROC(glMultiTexCoord4sv,        loader);
    OPENGL_LOAD_PROC(glLoadTransposeMatrixf,    loader);
    OPENGL_LOAD_PROC(glLoadTransposeMatrixd,    loader);
    OPENGL_LOAD_PROC(glMultTransposeMatrixf,    loader);
    OPENGL_LOAD_PROC(glMultTransposeMatrixd,    loader);
    #endif // OPENGL_USE_COMPATIBILITY_PROFILE
    #endif // OPENGL_LOAD_GL_VERSION_1_3
    return true;
}

/* -------------------------------------------------------------------------- */

static bool internal__load_GL_VERSION_1_4 (OpenGL_Proc_Loader loader)
{
    #if defined(OPENGL_LOAD_GL_VERSION_1_4)
    OPENGL_LOAD_PROC(glBlendFuncSeparate,     loader);
    OPENGL_LOAD_PROC(glMultiDrawArrays,       loader);
    OPENGL_LOAD_PROC(glMultiDrawElements,     loader);
    OPENGL_LOAD_PROC(glPointParameterf,       loader);
    OPENGL_LOAD_PROC(glPointParameterfv,      loader);
    OPENGL_LOAD_PROC(glPointParameteri,       loader);
    OPENGL_LOAD_PROC(glPointParameteriv,      loader);
    OPENGL_LOAD_PROC(glBlendColor,            loader);
    OPENGL_LOAD_PROC(glBlendEquation,         loader);
    #if defined(OPENGL_USE_COMPATIBILITY_PROFILE)
    OPENGL_LOAD_PROC(glFogCoordf,             loader);
    OPENGL_LOAD_PROC(glFogCoordfv,            loader);
    OPENGL_LOAD_PROC(glFogCoordd,             loader);
    OPENGL_LOAD_PROC(glFogCoorddv,            loader);
    OPENGL_LOAD_PROC(glFogCoordPointer,       loader);
    OPENGL_LOAD_PROC(glSecondaryColor3b,      loader);
    OPENGL_LOAD_PROC(glSecondaryColor3bv,     loader);
    OPENGL_LOAD_PROC(glSecondaryColor3d,      loader);
    OPENGL_LOAD_PROC(glSecondaryColor3dv,     loader);
    OPENGL_LOAD_PROC(glSecondaryColor3f,      loader);
    OPENGL_LOAD_PROC(glSecondaryColor3fv,     loader);
    OPENGL_LOAD_PROC(glSecondaryColor3i,      loader);
    OPENGL_LOAD_PROC(glSecondaryColor3iv,     loader);
    OPENGL_LOAD_PROC(glSecondaryColor3s,      loader);
    OPENGL_LOAD_PROC(glSecondaryColor3sv,     loader);
    OPENGL_LOAD_PROC(glSecondaryColor3ub,     loader);
    OPENGL_LOAD_PROC(glSecondaryColor3ubv,    loader);
    OPENGL_LOAD_PROC(glSecondaryColor3ui,     loader);
    OPENGL_LOAD_PROC(glSecondaryColor3uiv,    loader);
    OPENGL_LOAD_PROC(glSecondaryColor3us,     loader);
    OPENGL_LOAD_PROC(glSecondaryColor3usv,    loader);
    OPENGL_LOAD_PROC(glSecondaryColorPointer, loader);
    OPENGL_LOAD_PROC(glWindowPos2d,           loader);
    OPENGL_LOAD_PROC(glWindowPos2dv,          loader);
    OPENGL_LOAD_PROC(glWindowPos2f,           loader);
    OPENGL_LOAD_PROC(glWindowPos2fv,          loader);
    OPENGL_LOAD_PROC(glWindowPos2i,           loader);
    OPENGL_LOAD_PROC(glWindowPos2iv,          loader);
    OPENGL_LOAD_PROC(glWindowPos2s,           loader);
    OPENGL_LOAD_PROC(glWindowPos2sv,          loader);
    OPENGL_LOAD_PROC(glWindowPos3d,           loader);
    OPENGL_LOAD_PROC(glWindowPos3dv,          loader);
    OPENGL_LOAD_PROC(glWindowPos3f,           loader);
    OPENGL_LOAD_PROC(glWindowPos3fv,          loader);
    OPENGL_LOAD_PROC(glWindowPos3i,           loader);
    OPENGL_LOAD_PROC(glWindowPos3iv,          loader);
    OPENGL_LOAD_PROC(glWindowPos3s,           loader);
    OPENGL_LOAD_PROC(glWindowPos3sv,          loader);
    #endif // OPENGL_USE_COMPATIBILITY_PROFILE
    #endif // OPENGL_LOAD_GL_VERSION_1_4
    return true;
}

/* -------------------------------------------------------------------------- */

static bool internal__load_GL_VERSION_1_5 (OpenGL_Proc_Loader loader)
{
    #if defined(OPENGL_LOAD_GL_VERSION_1_5)
    OPENGL_LOAD_PROC(glGenQueries,           loader);
    OPENGL_LOAD_PROC(glDeleteQueries,        loader);
    OPENGL_LOAD_PROC(glIsQuery,              loader);
    OPENGL_LOAD_PROC(glBeginQuery,           loader);
    OPENGL_LOAD_PROC(glEndQuery,             loader);
    OPENGL_LOAD_PROC(glGetQueryiv,           loader);
    OPENGL_LOAD_PROC(glGetQueryObjectiv,     loader);
    OPENGL_LOAD_PROC(glGetQueryObjectuiv,    loader);
    OPENGL_LOAD_PROC(glBindBuffer,           loader);
    OPENGL_LOAD_PROC(glDeleteBuffers,        loader);
    OPENGL_LOAD_PROC(glGenBuffers,           loader);
    OPENGL_LOAD_PROC(glIsBuffer,             loader);
    OPENGL_LOAD_PROC(glBufferData,           loader);
    OPENGL_LOAD_PROC(glBufferSubData,        loader);
    OPENGL_LOAD_PROC(glGetBufferSubData,     loader);
    OPENGL_LOAD_PROC(glMapBuffer,            loader);
    OPENGL_LOAD_PROC(glUnmapBuffer,          loader);
    OPENGL_LOAD_PROC(glGetBufferParameteriv, loader);
    OPENGL_LOAD_PROC(glGetBufferPointerv,    loader);
    #endif // OPENGL_LOAD_GL_VERSION_1_5
    return true;
}

/* -------------------------------------------------------------------------- */

static bool internal__load_GL_VERSION_2_0 (OpenGL_Proc_Loader loader)
{
    #if defined(OPENGL_LOAD_GL_VERSION_2_0)
    OPENGL_LOAD_PROC(glBlendEquationSeparate,    loader);
    OPENGL_LOAD_PROC(glDrawBuffers,              loader);
    OPENGL_LOAD_PROC(glStencilOpSeparate,        loader);
    OPENGL_LOAD_PROC(glStencilFuncSeparate,      loader);
    OPENGL_LOAD_PROC(glStencilMaskSeparate,      loader);
    OPENGL_LOAD_PROC(glAttachShader,             loader);
    OPENGL_LOAD_PROC(glBindAttribLocation,       loader);
    OPENGL_LOAD_PROC(glCompileShader,            loader);
    OPENGL_LOAD_PROC(glCreateProgram,            loader);
    OPENGL_LOAD_PROC(glCreateShader,             loader);
    OPENGL_LOAD_PROC(glDeleteProgram,            loader);
    OPENGL_LOAD_PROC(glDeleteShader,             loader);
    OPENGL_LOAD_PROC(glDetachShader,             loader);
    OPENGL_LOAD_PROC(glDisableVertexAttribArray, loader);
    OPENGL_LOAD_PROC(glEnableVertexAttribArray,  loader);
    OPENGL_LOAD_PROC(glGetActiveAttrib,          loader);
    OPENGL_LOAD_PROC(glGetActiveUniform,         loader);
    OPENGL_LOAD_PROC(glGetAttachedShaders,       loader);
    OPENGL_LOAD_PROC(glGetAttribLocation,        loader);
    OPENGL_LOAD_PROC(glGetProgramiv,             loader);
    OPENGL_LOAD_PROC(glGetProgramInfoLog,        loader);
    OPENGL_LOAD_PROC(glGetShaderiv,              loader);
    OPENGL_LOAD_PROC(glGetShaderInfoLog,         loader);
    OPENGL_LOAD_PROC(glGetShaderSource,          loader);
    OPENGL_LOAD_PROC(glGetUniformLocation,       loader);
    OPENGL_LOAD_PROC(glGetUniformfv,             loader);
    OPENGL_LOAD_PROC(glGetUniformiv,             loader);
    OPENGL_LOAD_PROC(glGetVertexAttribdv,        loader);
    OPENGL_LOAD_PROC(glGetVertexAttribfv,        loader);
    OPENGL_LOAD_PROC(glGetVertexAttribiv,        loader);
    OPENGL_LOAD_PROC(glGetVertexAttribPointerv,  loader);
    OPENGL_LOAD_PROC(glIsProgram,                loader);
    OPENGL_LOAD_PROC(glIsShader,                 loader);
    OPENGL_LOAD_PROC(glLinkProgram,              loader);
    OPENGL_LOAD_PROC(glShaderSource,             loader);
    OPENGL_LOAD_PROC(glUseProgram,               loader);
    OPENGL_LOAD_PROC(glUniform1f,                loader);
    OPENGL_LOAD_PROC(glUniform2f,                loader);
    OPENGL_LOAD_PROC(glUniform3f,                loader);
    OPENGL_LOAD_PROC(glUniform4f,                loader);
    OPENGL_LOAD_PROC(glUniform1i,                loader);
    OPENGL_LOAD_PROC(glUniform2i,                loader);
    OPENGL_LOAD_PROC(glUniform3i,                loader);
    OPENGL_LOAD_PROC(glUniform4i,                loader);
    OPENGL_LOAD_PROC(glUniform1fv,               loader);
    OPENGL_LOAD_PROC(glUniform2fv,               loader);
    OPENGL_LOAD_PROC(glUniform3fv,               loader);
    OPENGL_LOAD_PROC(glUniform4fv,               loader);
    OPENGL_LOAD_PROC(glUniform1iv,               loader);
    OPENGL_LOAD_PROC(glUniform2iv,               loader);
    OPENGL_LOAD_PROC(glUniform3iv,               loader);
    OPENGL_LOAD_PROC(glUniform4iv,               loader);
    OPENGL_LOAD_PROC(glUniformMatrix2fv,         loader);
    OPENGL_LOAD_PROC(glUniformMatrix3fv,         loader);
    OPENGL_LOAD_PROC(glUniformMatrix4fv,         loader);
    OPENGL_LOAD_PROC(glValidateProgram,          loader);
    OPENGL_LOAD_PROC(glVertexAttrib1d,           loader);
    OPENGL_LOAD_PROC(glVertexAttrib1dv,          loader);
    OPENGL_LOAD_PROC(glVertexAttrib1f,           loader);
    OPENGL_LOAD_PROC(glVertexAttrib1fv,          loader);
    OPENGL_LOAD_PROC(glVertexAttrib1s,           loader);
    OPENGL_LOAD_PROC(glVertexAttrib1sv,          loader);
    OPENGL_LOAD_PROC(glVertexAttrib2d,           loader);
    OPENGL_LOAD_PROC(glVertexAttrib2dv,          loader);
    OPENGL_LOAD_PROC(glVertexAttrib2f,           loader);
    OPENGL_LOAD_PROC(glVertexAttrib2fv,          loader);
    OPENGL_LOAD_PROC(glVertexAttrib2s,           loader);
    OPENGL_LOAD_PROC(glVertexAttrib2sv,          loader);
    OPENGL_LOAD_PROC(glVertexAttrib3d,           loader);
    OPENGL_LOAD_PROC(glVertexAttrib3dv,          loader);
    OPENGL_LOAD_PROC(glVertexAttrib3f,           loader);
    OPENGL_LOAD_PROC(glVertexAttrib3fv,          loader);
    OPENGL_LOAD_PROC(glVertexAttrib3s,           loader);
    OPENGL_LOAD_PROC(glVertexAttrib3sv,          loader);
    OPENGL_LOAD_PROC(glVertexAttrib4Nbv,         loader);
    OPENGL_LOAD_PROC(glVertexAttrib4Niv,         loader);
    OPENGL_LOAD_PROC(glVertexAttrib4Nsv,         loader);
    OPENGL_LOAD_PROC(glVertexAttrib4Nub,         loader);
    OPENGL_LOAD_PROC(glVertexAttrib4Nubv,        loader);
    OPENGL_LOAD_PROC(glVertexAttrib4Nuiv,        loader);
    OPENGL_LOAD_PROC(glVertexAttrib4Nusv,        loader);
    OPENGL_LOAD_PROC(glVertexAttrib4bv,          loader);
    OPENGL_LOAD_PROC(glVertexAttrib4d,           loader);
    OPENGL_LOAD_PROC(glVertexAttrib4dv,          loader);
    OPENGL_LOAD_PROC(glVertexAttrib4f,           loader);
    OPENGL_LOAD_PROC(glVertexAttrib4fv,          loader);
    OPENGL_LOAD_PROC(glVertexAttrib4iv,          loader);
    OPENGL_LOAD_PROC(glVertexAttrib4s,           loader);
    OPENGL_LOAD_PROC(glVertexAttrib4sv,          loader);
    OPENGL_LOAD_PROC(glVertexAttrib4ubv,         loader);
    OPENGL_LOAD_PROC(glVertexAttrib4uiv,         loader);
    OPENGL_LOAD_PROC(glVertexAttrib4usv,         loader);
    OPENGL_LOAD_PROC(glVertexAttribPointer,      loader);
    #endif // OPENGL_LOAD_GL_VERSION_2_0
    return true;
}

/* -------------------------------------------------------------------------- */

static bool internal__load_GL_VERSION_2_1 (OpenGL_Proc_Loader loader)
{
    #if defined(OPENGL_LOAD_GL_VERSION_2_1)
    OPENGL_LOAD_PROC(glUniformMatrix2x3fv, loader);
    OPENGL_LOAD_PROC(glUniformMatrix3x2fv, loader);
    OPENGL_LOAD_PROC(glUniformMatrix2x4fv, loader);
    OPENGL_LOAD_PROC(glUniformMatrix4x2fv, loader);
    OPENGL_LOAD_PROC(glUniformMatrix3x4fv, loader);
    OPENGL_LOAD_PROC(glUniformMatrix4x3fv, loader);
    #endif // OPENGL_LOAD_GL_VERSION_2_1
    return true;
}

/* -------------------------------------------------------------------------- */

static bool internal__load_GL_VERSION_3_0 (OpenGL_Proc_Loader loader)
{
    #if defined(OPENGL_LOAD_GL_VERSION_3_0)
    OPENGL_LOAD_PROC(glColorMaski,                          loader);
    OPENGL_LOAD_PROC(glGetBooleani_v,                       loader);
    OPENGL_LOAD_PROC(glGetIntegeri_v,                       loader);
    OPENGL_LOAD_PROC(glEnablei,                             loader);
    OPENGL_LOAD_PROC(glDisablei,                            loader);
    OPENGL_LOAD_PROC(glIsEnabledi,                          loader);
    OPENGL_LOAD_PROC(glBeginTransformFeedback,              loader);
    OPENGL_LOAD_PROC(glEndTransformFeedback,                loader);
    OPENGL_LOAD_PROC(glBindBufferRange,                     loader);
    OPENGL_LOAD_PROC(glBindBufferBase,                      loader);
    OPENGL_LOAD_PROC(glTransformFeedbackVaryings,           loader);
    OPENGL_LOAD_PROC(glGetTransformFeedbackVarying,         loader);
    OPENGL_LOAD_PROC(glClampColor,                          loader);
    OPENGL_LOAD_PROC(glBeginConditionalRender,              loader);
    OPENGL_LOAD_PROC(glEndConditionalRender,                loader);
    OPENGL_LOAD_PROC(glVertexAttribIPointer,                loader);
    OPENGL_LOAD_PROC(glGetVertexAttribIiv,                  loader);
    OPENGL_LOAD_PROC(glGetVertexAttribIuiv,                 loader);
    OPENGL_LOAD_PROC(glVertexAttribI1i,                     loader);
    OPENGL_LOAD_PROC(glVertexAttribI2i,                     loader);
    OPENGL_LOAD_PROC(glVertexAttribI3i,                     loader);
    OPENGL_LOAD_PROC(glVertexAttribI4i,                     loader);
    OPENGL_LOAD_PROC(glVertexAttribI1ui,                    loader);
    OPENGL_LOAD_PROC(glVertexAttribI2ui,                    loader);
    OPENGL_LOAD_PROC(glVertexAttribI3ui,                    loader);
    OPENGL_LOAD_PROC(glVertexAttribI4ui,                    loader);
    OPENGL_LOAD_PROC(glVertexAttribI1iv,                    loader);
    OPENGL_LOAD_PROC(glVertexAttribI2iv,                    loader);
    OPENGL_LOAD_PROC(glVertexAttribI3iv,                    loader);
    OPENGL_LOAD_PROC(glVertexAttribI4iv,                    loader);
    OPENGL_LOAD_PROC(glVertexAttribI1uiv,                   loader);
    OPENGL_LOAD_PROC(glVertexAttribI2uiv,                   loader);
    OPENGL_LOAD_PROC(glVertexAttribI3uiv,                   loader);
    OPENGL_LOAD_PROC(glVertexAttribI4uiv,                   loader);
    OPENGL_LOAD_PROC(glVertexAttribI4bv,                    loader);
    OPENGL_LOAD_PROC(glVertexAttribI4sv,                    loader);
    OPENGL_LOAD_PROC(glVertexAttribI4ubv,                   loader);
    OPENGL_LOAD_PROC(glVertexAttribI4usv,                   loader);
    OPENGL_LOAD_PROC(glGetUniformuiv,                       loader);
    OPENGL_LOAD_PROC(glBindFragDataLocation,                loader);
    OPENGL_LOAD_PROC(glGetFragDataLocation,                 loader);
    OPENGL_LOAD_PROC(glUniform1ui,                          loader);
    OPENGL_LOAD_PROC(glUniform2ui,                          loader);
    OPENGL_LOAD_PROC(glUniform3ui,                          loader);
    OPENGL_LOAD_PROC(glUniform4ui,                          loader);
    OPENGL_LOAD_PROC(glUniform1uiv,                         loader);
    OPENGL_LOAD_PROC(glUniform2uiv,                         loader);
    OPENGL_LOAD_PROC(glUniform3uiv,                         loader);
    OPENGL_LOAD_PROC(glUniform4uiv,                         loader);
    OPENGL_LOAD_PROC(glTexParameterIiv,                     loader);
    OPENGL_LOAD_PROC(glTexParameterIuiv,                    loader);
    OPENGL_LOAD_PROC(glGetTexParameterIiv,                  loader);
    OPENGL_LOAD_PROC(glGetTexParameterIuiv,                 loader);
    OPENGL_LOAD_PROC(glClearBufferiv,                       loader);
    OPENGL_LOAD_PROC(glClearBufferuiv,                      loader);
    OPENGL_LOAD_PROC(glClearBufferfv,                       loader);
    OPENGL_LOAD_PROC(glClearBufferfi,                       loader);
    OPENGL_LOAD_PROC(glGetStringi,                          loader);
    OPENGL_LOAD_PROC(glIsRenderbuffer,                      loader);
    OPENGL_LOAD_PROC(glBindRenderbuffer,                    loader);
    OPENGL_LOAD_PROC(glDeleteRenderbuffers,                 loader);
    OPENGL_LOAD_PROC(glGenRenderbuffers,                    loader);
    OPENGL_LOAD_PROC(glRenderbufferStorage,                 loader);
    OPENGL_LOAD_PROC(glGetRenderbufferParameteriv,          loader);
    OPENGL_LOAD_PROC(glIsFramebuffer,                       loader);
    OPENGL_LOAD_PROC(glBindFramebuffer,                     loader);
    OPENGL_LOAD_PROC(glDeleteFramebuffers,                  loader);
    OPENGL_LOAD_PROC(glGenFramebuffers,                     loader);
    OPENGL_LOAD_PROC(glCheckFramebufferStatus,              loader);
    OPENGL_LOAD_PROC(glFramebufferTexture1D,                loader);
    OPENGL_LOAD_PROC(glFramebufferTexture2D,                loader);
    OPENGL_LOAD_PROC(glFramebufferTexture3D,                loader);
    OPENGL_LOAD_PROC(glFramebufferRenderbuffer,             loader);
    OPENGL_LOAD_PROC(glGetFramebufferAttachmentParameteriv, loader);
    OPENGL_LOAD_PROC(glGenerateMipmap,                      loader);
    OPENGL_LOAD_PROC(glBlitFramebuffer,                     loader);
    OPENGL_LOAD_PROC(glRenderbufferStorageMultisample,      loader);
    OPENGL_LOAD_PROC(glFramebufferTextureLayer,             loader);
    OPENGL_LOAD_PROC(glMapBufferRange,                      loader);
    OPENGL_LOAD_PROC(glFlushMappedBufferRange,              loader);
    OPENGL_LOAD_PROC(glBindVertexArray,                     loader);
    OPENGL_LOAD_PROC(glDeleteVertexArrays,                  loader);
    OPENGL_LOAD_PROC(glGenVertexArrays,                     loader);
    OPENGL_LOAD_PROC(glIsVertexArray,                       loader);
    #endif // OPENGL_LOAD_GL_VERSION_3_0
    return true;
}

/* -------------------------------------------------------------------------- */

static bool internal__load_GL_VERSION_3_1 (OpenGL_Proc_Loader loader)
{
    #if defined(OPENGL_LOAD_GL_VERSION_3_1)
    OPENGL_LOAD_PROC(glDrawArraysInstanced,       loader);
    OPENGL_LOAD_PROC(glDrawElementsInstanced,     loader);
    OPENGL_LOAD_PROC(glTexBuffer,                 loader);
    OPENGL_LOAD_PROC(glPrimitiveRestartIndex,     loader);
    OPENGL_LOAD_PROC(glCopyBufferSubData,         loader);
    OPENGL_LOAD_PROC(glGetUniformIndices,         loader);
    OPENGL_LOAD_PROC(glGetActiveUniformsiv,       loader);
    OPENGL_LOAD_PROC(glGetActiveUniformName,      loader);
    OPENGL_LOAD_PROC(glGetUniformBlockIndex,      loader);
    OPENGL_LOAD_PROC(glGetActiveUniformBlockiv,   loader);
    OPENGL_LOAD_PROC(glGetActiveUniformBlockName, loader);
    OPENGL_LOAD_PROC(glUniformBlockBinding,       loader);
    #endif // OPENGL_LOAD_GL_VERSION_3_1
    return true;
}

/* -------------------------------------------------------------------------- */

static bool internal__load_GL_VERSION_3_2 (OpenGL_Proc_Loader loader)
{
    #if defined(OPENGL_LOAD_GL_VERSION_3_2)
    OPENGL_LOAD_PROC(glDrawElementsBaseVertex,          loader);
    OPENGL_LOAD_PROC(glDrawRangeElementsBaseVertex,     loader);
    OPENGL_LOAD_PROC(glDrawElementsInstancedBaseVertex, loader);
    OPENGL_LOAD_PROC(glMultiDrawElementsBaseVertex,     loader);
    OPENGL_LOAD_PROC(glProvokingVertex,                 loader);
    OPENGL_LOAD_PROC(glFenceSync,                       loader);
    OPENGL_LOAD_PROC(glIsSync,                          loader);
    OPENGL_LOAD_PROC(glDeleteSync,                      loader);
    OPENGL_LOAD_PROC(glClientWaitSync,                  loader);
    OPENGL_LOAD_PROC(glWaitSync,                        loader);
    OPENGL_LOAD_PROC(glGetInteger64v,                   loader);
    OPENGL_LOAD_PROC(glGetSynciv,                       loader);
    OPENGL_LOAD_PROC(glGetInteger64i_v,                 loader);
    OPENGL_LOAD_PROC(glGetBufferParameteri64v,          loader);
    OPENGL_LOAD_PROC(glFramebufferTexture,              loader);
    OPENGL_LOAD_PROC(glTexImage2DMultisample,           loader);
    OPENGL_LOAD_PROC(glTexImage3DMultisample,           loader);
    OPENGL_LOAD_PROC(glGetMultisamplefv,                loader);
    OPENGL_LOAD_PROC(glSampleMaski,                     loader);
    #endif // OPENGL_LOAD_GL_VERSION_3_2
    return true;
}

/* -------------------------------------------------------------------------- */

static bool internal__load_GL_VERSION_3_3 (OpenGL_Proc_Loader loader)
{
    #if defined(OPENGL_LOAD_GL_VERSION_3_3)
    OPENGL_LOAD_PROC(glBindFragDataLocationIndexed, loader);
    OPENGL_LOAD_PROC(glGetFragDataIndex,            loader);
    OPENGL_LOAD_PROC(glGenSamplers,                 loader);
    OPENGL_LOAD_PROC(glDeleteSamplers,              loader);
    OPENGL_LOAD_PROC(glIsSampler,                   loader);
    OPENGL_LOAD_PROC(glBindSampler,                 loader);
    OPENGL_LOAD_PROC(glSamplerParameteri,           loader);
    OPENGL_LOAD_PROC(glSamplerParameteriv,          loader);
    OPENGL_LOAD_PROC(glSamplerParameterf,           loader);
    OPENGL_LOAD_PROC(glSamplerParameterfv,          loader);
    OPENGL_LOAD_PROC(glSamplerParameterIiv,         loader);
    OPENGL_LOAD_PROC(glSamplerParameterIuiv,        loader);
    OPENGL_LOAD_PROC(glGetSamplerParameteriv,       loader);
    OPENGL_LOAD_PROC(glGetSamplerParameterIiv,      loader);
    OPENGL_LOAD_PROC(glGetSamplerParameterfv,       loader);
    OPENGL_LOAD_PROC(glGetSamplerParameterIuiv,     loader);
    OPENGL_LOAD_PROC(glQueryCounter,                loader);
    OPENGL_LOAD_PROC(glGetQueryObjecti64v,          loader);
    OPENGL_LOAD_PROC(glGetQueryObjectui64v,         loader);
    OPENGL_LOAD_PROC(glVertexAttribDivisor,         loader);
    OPENGL_LOAD_PROC(glVertexAttribP1ui,            loader);
    OPENGL_LOAD_PROC(glVertexAttribP1uiv,           loader);
    OPENGL_LOAD_PROC(glVertexAttribP2ui,            loader);
    OPENGL_LOAD_PROC(glVertexAttribP2uiv,           loader);
    OPENGL_LOAD_PROC(glVertexAttribP3ui,            loader);
    OPENGL_LOAD_PROC(glVertexAttribP3uiv,           loader);
    OPENGL_LOAD_PROC(glVertexAttribP4ui,            loader);
    OPENGL_LOAD_PROC(glVertexAttribP4uiv,           loader);
    #if defined(OPENGL_USE_COMPATIBILITY_PROFILE)
    OPENGL_LOAD_PROC(glVertexP2ui,                  loader);
    OPENGL_LOAD_PROC(glVertexP2uiv,                 loader);
    OPENGL_LOAD_PROC(glVertexP3ui,                  loader);
    OPENGL_LOAD_PROC(glVertexP3uiv,                 loader);
    OPENGL_LOAD_PROC(glVertexP4ui,                  loader);
    OPENGL_LOAD_PROC(glVertexP4uiv,                 loader);
    OPENGL_LOAD_PROC(glTexCoordP1ui,                loader);
    OPENGL_LOAD_PROC(glTexCoordP1uiv,               loader);
    OPENGL_LOAD_PROC(glTexCoordP2ui,                loader);
    OPENGL_LOAD_PROC(glTexCoordP2uiv,               loader);
    OPENGL_LOAD_PROC(glTexCoordP3ui,                loader);
    OPENGL_LOAD_PROC(glTexCoordP3uiv,               loader);
    OPENGL_LOAD_PROC(glTexCoordP4ui,                loader);
    OPENGL_LOAD_PROC(glTexCoordP4uiv,               loader);
    OPENGL_LOAD_PROC(glMultiTexCoordP1ui,           loader);
    OPENGL_LOAD_PROC(glMultiTexCoordP1uiv,          loader);
    OPENGL_LOAD_PROC(glMultiTexCoordP2ui,           loader);
    OPENGL_LOAD_PROC(glMultiTexCoordP2uiv,          loader);
    OPENGL_LOAD_PROC(glMultiTexCoordP3ui,           loader);
    OPENGL_LOAD_PROC(glMultiTexCoordP3uiv,          loader);
    OPENGL_LOAD_PROC(glMultiTexCoordP4ui,           loader);
    OPENGL_LOAD_PROC(glMultiTexCoordP4uiv,          loader);
    OPENGL_LOAD_PROC(glNormalP3ui,                  loader);
    OPENGL_LOAD_PROC(glNormalP3uiv,                 loader);
    OPENGL_LOAD_PROC(glColorP3ui,                   loader);
    OPENGL_LOAD_PROC(glColorP3uiv,                  loader);
    OPENGL_LOAD_PROC(glColorP4ui,                   loader);
    OPENGL_LOAD_PROC(glColorP4uiv,                  loader);
    OPENGL_LOAD_PROC(glSecondaryColorP3ui,          loader);
    OPENGL_LOAD_PROC(glSecondaryColorP3uiv,         loader);
    #endif // OPENGL_USE_COMPATIBILITY_PROFILE
    #endif // OPENGL_LOAD_GL_VERSION_3_3
    return true;
}

/* -------------------------------------------------------------------------- */

static bool internal__load_GL_VERSION_4_0 (OpenGL_Proc_Loader loader)
{
    #if defined(OPENGL_LOAD_GL_VERSION_4_0)
    OPENGL_LOAD_PROC(glMinSampleShading,               loader);
    OPENGL_LOAD_PROC(glBlendEquationi,                 loader);
    OPENGL_LOAD_PROC(glBlendEquationSeparatei,         loader);
    OPENGL_LOAD_PROC(glBlendFunci,                     loader);
    OPENGL_LOAD_PROC(glBlendFuncSeparatei,             loader);
    OPENGL_LOAD_PROC(glDrawArraysIndirect,             loader);
    OPENGL_LOAD_PROC(glDrawElementsIndirect,           loader);
    OPENGL_LOAD_PROC(glUniform1d,                      loader);
    OPENGL_LOAD_PROC(glUniform2d,                      loader);
    OPENGL_LOAD_PROC(glUniform3d,                      loader);
    OPENGL_LOAD_PROC(glUniform4d,                      loader);
    OPENGL_LOAD_PROC(glUniform1dv,                     loader);
    OPENGL_LOAD_PROC(glUniform2dv,                     loader);
    OPENGL_LOAD_PROC(glUniform3dv,                     loader);
    OPENGL_LOAD_PROC(glUniform4dv,                     loader);
    OPENGL_LOAD_PROC(glUniformMatrix2dv,               loader);
    OPENGL_LOAD_PROC(glUniformMatrix3dv,               loader);
    OPENGL_LOAD_PROC(glUniformMatrix4dv,               loader);
    OPENGL_LOAD_PROC(glUniformMatrix2x3dv,             loader);
    OPENGL_LOAD_PROC(glUniformMatrix2x4dv,             loader);
    OPENGL_LOAD_PROC(glUniformMatrix3x2dv,             loader);
    OPENGL_LOAD_PROC(glUniformMatrix3x4dv,             loader);
    OPENGL_LOAD_PROC(glUniformMatrix4x2dv,             loader);
    OPENGL_LOAD_PROC(glUniformMatrix4x3dv,             loader);
    OPENGL_LOAD_PROC(glGetUniformdv,                   loader);
    OPENGL_LOAD_PROC(glGetSubroutineUniformLocation,   loader);
    OPENGL_LOAD_PROC(glGetSubroutineIndex,             loader);
    OPENGL_LOAD_PROC(glGetActiveSubroutineUniformiv,   loader);
    OPENGL_LOAD_PROC(glGetActiveSubroutineUniformName, loader);
    OPENGL_LOAD_PROC(glGetActiveSubroutineName,        loader);
    OPENGL_LOAD_PROC(glUniformSubroutinesuiv,          loader);
    OPENGL_LOAD_PROC(glGetUniformSubroutineuiv,        loader);
    OPENGL_LOAD_PROC(glGetProgramStageiv,              loader);
    OPENGL_LOAD_PROC(glPatchParameteri,                loader);
    OPENGL_LOAD_PROC(glPatchParameterfv,               loader);
    OPENGL_LOAD_PROC(glBindTransformFeedback,          loader);
    OPENGL_LOAD_PROC(glDeleteTransformFeedbacks,       loader);
    OPENGL_LOAD_PROC(glGenTransformFeedbacks,          loader);
    OPENGL_LOAD_PROC(glIsTransformFeedback,            loader);
    OPENGL_LOAD_PROC(glPauseTransformFeedback,         loader);
    OPENGL_LOAD_PROC(glResumeTransformFeedback,        loader);
    OPENGL_LOAD_PROC(glDrawTransformFeedback,          loader);
    OPENGL_LOAD_PROC(glDrawTransformFeedbackStream,    loader);
    OPENGL_LOAD_PROC(glBeginQueryIndexed,              loader);
    OPENGL_LOAD_PROC(glEndQueryIndexed,                loader);
    OPENGL_LOAD_PROC(glGetQueryIndexediv,              loader);
    #endif // OPENGL_LOAD_GL_VERSION_4_0
    return true;
}

/* -------------------------------------------------------------------------- */

static bool internal__load_GL_VERSION_4_1 (OpenGL_Proc_Loader loader)
{
    #if defined(OPENGL_LOAD_GL_VERSION_4_1)
    OPENGL_LOAD_PROC(glReleaseShaderCompiler,     loader);
    OPENGL_LOAD_PROC(glShaderBinary,              loader);
    OPENGL_LOAD_PROC(glGetShaderPrecisionFormat,  loader);
    OPENGL_LOAD_PROC(glDepthRangef,               loader);
    OPENGL_LOAD_PROC(glClearDepthf,               loader);
    OPENGL_LOAD_PROC(glGetProgramBinary,          loader);
    OPENGL_LOAD_PROC(glProgramBinary,             loader);
    OPENGL_LOAD_PROC(glProgramParameteri,         loader);
    OPENGL_LOAD_PROC(glUseProgramStages,          loader);
    OPENGL_LOAD_PROC(glActiveShaderProgram,       loader);
    OPENGL_LOAD_PROC(glCreateShaderProgramv,      loader);
    OPENGL_LOAD_PROC(glBindProgramPipeline,       loader);
    OPENGL_LOAD_PROC(glDeleteProgramPipelines,    loader);
    OPENGL_LOAD_PROC(glGenProgramPipelines,       loader);
    OPENGL_LOAD_PROC(glIsProgramPipeline,         loader);
    OPENGL_LOAD_PROC(glGetProgramPipelineiv,      loader);
    OPENGL_LOAD_PROC(glProgramUniform1i,          loader);
    OPENGL_LOAD_PROC(glProgramUniform1iv,         loader);
    OPENGL_LOAD_PROC(glProgramUniform1f,          loader);
    OPENGL_LOAD_PROC(glProgramUniform1fv,         loader);
    OPENGL_LOAD_PROC(glProgramUniform1d,          loader);
    OPENGL_LOAD_PROC(glProgramUniform1dv,         loader);
    OPENGL_LOAD_PROC(glProgramUniform1ui,         loader);
    OPENGL_LOAD_PROC(glProgramUniform1uiv,        loader);
    OPENGL_LOAD_PROC(glProgramUniform2i,          loader);
    OPENGL_LOAD_PROC(glProgramUniform2iv,         loader);
    OPENGL_LOAD_PROC(glProgramUniform2f,          loader);
    OPENGL_LOAD_PROC(glProgramUniform2fv,         loader);
    OPENGL_LOAD_PROC(glProgramUniform2d,          loader);
    OPENGL_LOAD_PROC(glProgramUniform2dv,         loader);
    OPENGL_LOAD_PROC(glProgramUniform2ui,         loader);
    OPENGL_LOAD_PROC(glProgramUniform2uiv,        loader);
    OPENGL_LOAD_PROC(glProgramUniform3i,          loader);
    OPENGL_LOAD_PROC(glProgramUniform3iv,         loader);
    OPENGL_LOAD_PROC(glProgramUniform3f,          loader);
    OPENGL_LOAD_PROC(glProgramUniform3fv,         loader);
    OPENGL_LOAD_PROC(glProgramUniform3d,          loader);
    OPENGL_LOAD_PROC(glProgramUniform3dv,         loader);
    OPENGL_LOAD_PROC(glProgramUniform3ui,         loader);
    OPENGL_LOAD_PROC(glProgramUniform3uiv,        loader);
    OPENGL_LOAD_PROC(glProgramUniform4i,          loader);
    OPENGL_LOAD_PROC(glProgramUniform4iv,         loader);
    OPENGL_LOAD_PROC(glProgramUniform4f,          loader);
    OPENGL_LOAD_PROC(glProgramUniform4fv,         loader);
    OPENGL_LOAD_PROC(glProgramUniform4d,          loader);
    OPENGL_LOAD_PROC(glProgramUniform4dv,         loader);
    OPENGL_LOAD_PROC(glProgramUniform4ui,         loader);
    OPENGL_LOAD_PROC(glProgramUniform4uiv,        loader);
    OPENGL_LOAD_PROC(glProgramUniformMatrix2fv,   loader);
    OPENGL_LOAD_PROC(glProgramUniformMatrix3fv,   loader);
    OPENGL_LOAD_PROC(glProgramUniformMatrix4fv,   loader);
    OPENGL_LOAD_PROC(glProgramUniformMatrix2dv,   loader);
    OPENGL_LOAD_PROC(glProgramUniformMatrix3dv,   loader);
    OPENGL_LOAD_PROC(glProgramUniformMatrix4dv,   loader);
    OPENGL_LOAD_PROC(glProgramUniformMatrix2x3fv, loader);
    OPENGL_LOAD_PROC(glProgramUniformMatrix3x2fv, loader);
    OPENGL_LOAD_PROC(glProgramUniformMatrix2x4fv, loader);
    OPENGL_LOAD_PROC(glProgramUniformMatrix4x2fv, loader);
    OPENGL_LOAD_PROC(glProgramUniformMatrix3x4fv, loader);
    OPENGL_LOAD_PROC(glProgramUniformMatrix4x3fv, loader);
    OPENGL_LOAD_PROC(glProgramUniformMatrix2x3dv, loader);
    OPENGL_LOAD_PROC(glProgramUniformMatrix3x2dv, loader);
    OPENGL_LOAD_PROC(glProgramUniformMatrix2x4dv, loader);
    OPENGL_LOAD_PROC(glProgramUniformMatrix4x2dv, loader);
    OPENGL_LOAD_PROC(glProgramUniformMatrix3x4dv, loader);
    OPENGL_LOAD_PROC(glProgramUniformMatrix4x3dv, loader);
    OPENGL_LOAD_PROC(glValidateProgramPipeline,   loader);
    OPENGL_LOAD_PROC(glGetProgramPipelineInfoLog, loader);
    OPENGL_LOAD_PROC(glVertexAttribL1d,           loader);
    OPENGL_LOAD_PROC(glVertexAttribL2d,           loader);
    OPENGL_LOAD_PROC(glVertexAttribL3d,           loader);
    OPENGL_LOAD_PROC(glVertexAttribL4d,           loader);
    OPENGL_LOAD_PROC(glVertexAttribL1dv,          loader);
    OPENGL_LOAD_PROC(glVertexAttribL2dv,          loader);
    OPENGL_LOAD_PROC(glVertexAttribL3dv,          loader);
    OPENGL_LOAD_PROC(glVertexAttribL4dv,          loader);
    OPENGL_LOAD_PROC(glVertexAttribLPointer,      loader);
    OPENGL_LOAD_PROC(glGetVertexAttribLdv,        loader);
    OPENGL_LOAD_PROC(glViewportArrayv,            loader);
    OPENGL_LOAD_PROC(glViewportIndexedf,          loader);
    OPENGL_LOAD_PROC(glViewportIndexedfv,         loader);
    OPENGL_LOAD_PROC(glScissorArrayv,             loader);
    OPENGL_LOAD_PROC(glScissorIndexed,            loader);
    OPENGL_LOAD_PROC(glScissorIndexedv,           loader);
    OPENGL_LOAD_PROC(glDepthRangeArrayv,          loader);
    OPENGL_LOAD_PROC(glDepthRangeIndexed,         loader);
    OPENGL_LOAD_PROC(glGetFloati_v,               loader);
    OPENGL_LOAD_PROC(glGetDoublei_v,              loader);
    #endif // OPENGL_LOAD_GL_VERSION_4_1
    return true;
}

/* -------------------------------------------------------------------------- */

static bool internal__load_GL_VERSION_4_2 (OpenGL_Proc_Loader loader)
{
    #if defined(OPENGL_LOAD_GL_VERSION_4_2)
    OPENGL_LOAD_PROC(glDrawArraysInstancedBaseInstance,             loader);
    OPENGL_LOAD_PROC(glDrawElementsInstancedBaseInstance,           loader);
    OPENGL_LOAD_PROC(glDrawElementsInstancedBaseVertexBaseInstance, loader);
    OPENGL_LOAD_PROC(glGetInternalformativ,                         loader);
    OPENGL_LOAD_PROC(glGetActiveAtomicCounterBufferiv,              loader);
    OPENGL_LOAD_PROC(glBindImageTexture,                            loader);
    OPENGL_LOAD_PROC(glMemoryBarrier,                               loader);
    OPENGL_LOAD_PROC(glTexStorage1D,                                loader);
    OPENGL_LOAD_PROC(glTexStorage2D,                                loader);
    OPENGL_LOAD_PROC(glTexStorage3D,                                loader);
    OPENGL_LOAD_PROC(glDrawTransformFeedbackInstanced,              loader);
    OPENGL_LOAD_PROC(glDrawTransformFeedbackStreamInstanced,        loader);
    #endif // OPENGL_LOAD_GL_VERSION_4_2
    return true;
}

/* -------------------------------------------------------------------------- */

static bool internal__load_GL_VERSION_4_3 (OpenGL_Proc_Loader loader)
{
    #if defined(OPENGL_LOAD_GL_VERSION_4_3)
    OPENGL_LOAD_PROC(glClearBufferData,                 loader);
    OPENGL_LOAD_PROC(glClearBufferSubData,              loader);
    OPENGL_LOAD_PROC(glDispatchCompute,                 loader);
    OPENGL_LOAD_PROC(glDispatchComputeIndirect,         loader);
    OPENGL_LOAD_PROC(glCopyImageSubData,                loader);
    OPENGL_LOAD_PROC(glFramebufferParameteri,           loader);
    OPENGL_LOAD_PROC(glGetFramebufferParameteriv,       loader);
    OPENGL_LOAD_PROC(glGetInternalformati64v,           loader);
    OPENGL_LOAD_PROC(glInvalidateTexSubImage,           loader);
    OPENGL_LOAD_PROC(glInvalidateTexImage,              loader);
    OPENGL_LOAD_PROC(glInvalidateBufferSubData,         loader);
    OPENGL_LOAD_PROC(glInvalidateBufferData,            loader);
    OPENGL_LOAD_PROC(glInvalidateFramebuffer,           loader);
    OPENGL_LOAD_PROC(glInvalidateSubFramebuffer,        loader);
    OPENGL_LOAD_PROC(glMultiDrawArraysIndirect,         loader);
    OPENGL_LOAD_PROC(glMultiDrawElementsIndirect,       loader);
    OPENGL_LOAD_PROC(glGetProgramInterfaceiv,           loader);
    OPENGL_LOAD_PROC(glGetProgramResourceIndex,         loader);
    OPENGL_LOAD_PROC(glGetProgramResourceName,          loader);
    OPENGL_LOAD_PROC(glGetProgramResourceiv,            loader);
    OPENGL_LOAD_PROC(glGetProgramResourceLocation,      loader);
    OPENGL_LOAD_PROC(glGetProgramResourceLocationIndex, loader);
    OPENGL_LOAD_PROC(glShaderStorageBlockBinding,       loader);
    OPENGL_LOAD_PROC(glTexBufferRange,                  loader);
    OPENGL_LOAD_PROC(glTexStorage2DMultisample,         loader);
    OPENGL_LOAD_PROC(glTexStorage3DMultisample,         loader);
    OPENGL_LOAD_PROC(glTextureView,                     loader);
    OPENGL_LOAD_PROC(glBindVertexBuffer,                loader);
    OPENGL_LOAD_PROC(glVertexAttribFormat,              loader);
    OPENGL_LOAD_PROC(glVertexAttribIFormat,             loader);
    OPENGL_LOAD_PROC(glVertexAttribLFormat,             loader);
    OPENGL_LOAD_PROC(glVertexAttribBinding,             loader);
    OPENGL_LOAD_PROC(glVertexBindingDivisor,            loader);
    OPENGL_LOAD_PROC(glDebugMessageControl,             loader);
    OPENGL_LOAD_PROC(glDebugMessageInsert,              loader);
    OPENGL_LOAD_PROC(glDebugMessageCallback,            loader);
    OPENGL_LOAD_PROC(glGetDebugMessageLog,              loader);
    OPENGL_LOAD_PROC(glPushDebugGroup,                  loader);
    OPENGL_LOAD_PROC(glPopDebugGroup,                   loader);
    OPENGL_LOAD_PROC(glObjectLabel,                     loader);
    OPENGL_LOAD_PROC(glGetObjectLabel,                  loader);
    OPENGL_LOAD_PROC(glObjectPtrLabel,                  loader);
    OPENGL_LOAD_PROC(glGetObjectPtrLabel,               loader);
    #endif // OPENGL_LOAD_GL_VERSION_4_3
    return true;
}

/* -------------------------------------------------------------------------- */

static bool internal__load_GL_VERSION_4_4 (OpenGL_Proc_Loader loader)
{
    #if defined(OPENGL_LOAD_GL_VERSION_4_4)
    OPENGL_LOAD_PROC(glBufferStorage,     loader);
    OPENGL_LOAD_PROC(glClearTexImage,     loader);
    OPENGL_LOAD_PROC(glClearTexSubImage,  loader);
    OPENGL_LOAD_PROC(glBindBuffersBase,   loader);
    OPENGL_LOAD_PROC(glBindBuffersRange,  loader);
    OPENGL_LOAD_PROC(glBindTextures,      loader);
    OPENGL_LOAD_PROC(glBindSamplers,      loader);
    OPENGL_LOAD_PROC(glBindImageTextures, loader);
    OPENGL_LOAD_PROC(glBindVertexBuffers, loader);
    #endif // OPENGL_LOAD_GL_VERSION_4_4
    return true;
}

/* -------------------------------------------------------------------------- */

static bool internal__load_GL_VERSION_4_5 (OpenGL_Proc_Loader loader)
{
    #if defined(OPENGL_LOAD_GL_VERSION_4_5)
    OPENGL_LOAD_PROC(glClipControl,                              loader);
    OPENGL_LOAD_PROC(glCreateTransformFeedbacks,                 loader);
    OPENGL_LOAD_PROC(glTransformFeedbackBufferBase,              loader);
    OPENGL_LOAD_PROC(glTransformFeedbackBufferRange,             loader);
    OPENGL_LOAD_PROC(glGetTransformFeedbackiv,                   loader);
    OPENGL_LOAD_PROC(glGetTransformFeedbacki_v,                  loader);
    OPENGL_LOAD_PROC(glGetTransformFeedbacki64_v,                loader);
    OPENGL_LOAD_PROC(glCreateBuffers,                            loader);
    OPENGL_LOAD_PROC(glNamedBufferStorage,                       loader);
    OPENGL_LOAD_PROC(glNamedBufferData,                          loader);
    OPENGL_LOAD_PROC(glNamedBufferSubData,                       loader);
    OPENGL_LOAD_PROC(glCopyNamedBufferSubData,                   loader);
    OPENGL_LOAD_PROC(glClearNamedBufferData,                     loader);
    OPENGL_LOAD_PROC(glClearNamedBufferSubData,                  loader);
    OPENGL_LOAD_PROC(glMapNamedBuffer,                           loader);
    OPENGL_LOAD_PROC(glMapNamedBufferRange,                      loader);
    OPENGL_LOAD_PROC(glUnmapNamedBuffer,                         loader);
    OPENGL_LOAD_PROC(glFlushMappedNamedBufferRange,              loader);
    OPENGL_LOAD_PROC(glGetNamedBufferParameteriv,                loader);
    OPENGL_LOAD_PROC(glGetNamedBufferParameteri64v,              loader);
    OPENGL_LOAD_PROC(glGetNamedBufferPointerv,                   loader);
    OPENGL_LOAD_PROC(glGetNamedBufferSubData,                    loader);
    OPENGL_LOAD_PROC(glCreateFramebuffers,                       loader);
    OPENGL_LOAD_PROC(glNamedFramebufferRenderbuffer,             loader);
    OPENGL_LOAD_PROC(glNamedFramebufferParameteri,               loader);
    OPENGL_LOAD_PROC(glNamedFramebufferTexture,                  loader);
    OPENGL_LOAD_PROC(glNamedFramebufferTextureLayer,             loader);
    OPENGL_LOAD_PROC(glNamedFramebufferDrawBuffer,               loader);
    OPENGL_LOAD_PROC(glNamedFramebufferDrawBuffers,              loader);
    OPENGL_LOAD_PROC(glNamedFramebufferReadBuffer,               loader);
    OPENGL_LOAD_PROC(glInvalidateNamedFramebufferData,           loader);
    OPENGL_LOAD_PROC(glInvalidateNamedFramebufferSubData,        loader);
    OPENGL_LOAD_PROC(glClearNamedFramebufferiv,                  loader);
    OPENGL_LOAD_PROC(glClearNamedFramebufferuiv,                 loader);
    OPENGL_LOAD_PROC(glClearNamedFramebufferfv,                  loader);
    OPENGL_LOAD_PROC(glClearNamedFramebufferfi,                  loader);
    OPENGL_LOAD_PROC(glBlitNamedFramebuffer,                     loader);
    OPENGL_LOAD_PROC(glCheckNamedFramebufferStatus,              loader);
    OPENGL_LOAD_PROC(glGetNamedFramebufferParameteriv,           loader);
    OPENGL_LOAD_PROC(glGetNamedFramebufferAttachmentParameteriv, loader);
    OPENGL_LOAD_PROC(glCreateRenderbuffers,                      loader);
    OPENGL_LOAD_PROC(glNamedRenderbufferStorage,                 loader);
    OPENGL_LOAD_PROC(glNamedRenderbufferStorageMultisample,      loader);
    OPENGL_LOAD_PROC(glGetNamedRenderbufferParameteriv,          loader);
    OPENGL_LOAD_PROC(glCreateTextures,                           loader);
    OPENGL_LOAD_PROC(glTextureBuffer,                            loader);
    OPENGL_LOAD_PROC(glTextureBufferRange,                       loader);
    OPENGL_LOAD_PROC(glTextureStorage1D,                         loader);
    OPENGL_LOAD_PROC(glTextureStorage2D,                         loader);
    OPENGL_LOAD_PROC(glTextureStorage3D,                         loader);
    OPENGL_LOAD_PROC(glTextureStorage2DMultisample,              loader);
    OPENGL_LOAD_PROC(glTextureStorage3DMultisample,              loader);
    OPENGL_LOAD_PROC(glTextureSubImage1D,                        loader);
    OPENGL_LOAD_PROC(glTextureSubImage2D,                        loader);
    OPENGL_LOAD_PROC(glTextureSubImage3D,                        loader);
    OPENGL_LOAD_PROC(glCompressedTextureSubImage1D,              loader);
    OPENGL_LOAD_PROC(glCompressedTextureSubImage2D,              loader);
    OPENGL_LOAD_PROC(glCompressedTextureSubImage3D,              loader);
    OPENGL_LOAD_PROC(glCopyTextureSubImage1D,                    loader);
    OPENGL_LOAD_PROC(glCopyTextureSubImage2D,                    loader);
    OPENGL_LOAD_PROC(glCopyTextureSubImage3D,                    loader);
    OPENGL_LOAD_PROC(glTextureParameterf,                        loader);
    OPENGL_LOAD_PROC(glTextureParameterfv,                       loader);
    OPENGL_LOAD_PROC(glTextureParameteri,                        loader);
    OPENGL_LOAD_PROC(glTextureParameterIiv,                      loader);
    OPENGL_LOAD_PROC(glTextureParameterIuiv,                     loader);
    OPENGL_LOAD_PROC(glTextureParameteriv,                       loader);
    OPENGL_LOAD_PROC(glGenerateTextureMipmap,                    loader);
    OPENGL_LOAD_PROC(glBindTextureUnit,                          loader);
    OPENGL_LOAD_PROC(glGetTextureImage,                          loader);
    OPENGL_LOAD_PROC(glGetCompressedTextureImage,                loader);
    OPENGL_LOAD_PROC(glGetTextureLevelParameterfv,               loader);
    OPENGL_LOAD_PROC(glGetTextureLevelParameteriv,               loader);
    OPENGL_LOAD_PROC(glGetTextureParameterfv,                    loader);
    OPENGL_LOAD_PROC(glGetTextureParameterIiv,                   loader);
    OPENGL_LOAD_PROC(glGetTextureParameterIuiv,                  loader);
    OPENGL_LOAD_PROC(glGetTextureParameteriv,                    loader);
    OPENGL_LOAD_PROC(glCreateVertexArrays,                       loader);
    OPENGL_LOAD_PROC(glDisableVertexArrayAttrib,                 loader);
    OPENGL_LOAD_PROC(glEnableVertexArrayAttrib,                  loader);
    OPENGL_LOAD_PROC(glVertexArrayElementBuffer,                 loader);
    OPENGL_LOAD_PROC(glVertexArrayVertexBuffer,                  loader);
    OPENGL_LOAD_PROC(glVertexArrayVertexBuffers,                 loader);
    OPENGL_LOAD_PROC(glVertexArrayAttribBinding,                 loader);
    OPENGL_LOAD_PROC(glVertexArrayAttribFormat,                  loader);
    OPENGL_LOAD_PROC(glVertexArrayAttribIFormat,                 loader);
    OPENGL_LOAD_PROC(glVertexArrayAttribLFormat,                 loader);
    OPENGL_LOAD_PROC(glVertexArrayBindingDivisor,                loader);
    OPENGL_LOAD_PROC(glGetVertexArrayiv,                         loader);
    OPENGL_LOAD_PROC(glGetVertexArrayIndexediv,                  loader);
    OPENGL_LOAD_PROC(glGetVertexArrayIndexed64iv,                loader);
    OPENGL_LOAD_PROC(glCreateSamplers,                           loader);
    OPENGL_LOAD_PROC(glCreateProgramPipelines,                   loader);
    OPENGL_LOAD_PROC(glCreateQueries,                            loader);
    OPENGL_LOAD_PROC(glGetQueryBufferObjecti64v,                 loader);
    OPENGL_LOAD_PROC(glGetQueryBufferObjectiv,                   loader);
    OPENGL_LOAD_PROC(glGetQueryBufferObjectui64v,                loader);
    OPENGL_LOAD_PROC(glGetQueryBufferObjectuiv,                  loader);
    OPENGL_LOAD_PROC(glMemoryBarrierByRegion,                    loader);
    OPENGL_LOAD_PROC(glGetTextureSubImage,                       loader);
    OPENGL_LOAD_PROC(glGetCompressedTextureSubImage,             loader);
    OPENGL_LOAD_PROC(glGetGraphicsResetStatus,                   loader);
    OPENGL_LOAD_PROC(glGetnCompressedTexImage,                   loader);
    OPENGL_LOAD_PROC(glGetnTexImage,                             loader);
    OPENGL_LOAD_PROC(glGetnUniformdv,                            loader);
    OPENGL_LOAD_PROC(glGetnUniformfv,                            loader);
    OPENGL_LOAD_PROC(glGetnUniformiv,                            loader);
    OPENGL_LOAD_PROC(glGetnUniformuiv,                           loader);
    OPENGL_LOAD_PROC(glReadnPixels,                              loader);
    OPENGL_LOAD_PROC(glTextureBarrier,                           loader);
    #if defined(OPENGL_USE_COMPATIBILITY_PROFILE)
    OPENGL_LOAD_PROC(glGetnMapdv,                                loader);
    OPENGL_LOAD_PROC(glGetnMapfv,                                loader);
    OPENGL_LOAD_PROC(glGetnMapiv,                                loader);
    OPENGL_LOAD_PROC(glGetnPixelMapfv,                           loader);
    OPENGL_LOAD_PROC(glGetnPixelMapuiv,                          loader);
    OPENGL_LOAD_PROC(glGetnPixelMapusv,                          loader);
    OPENGL_LOAD_PROC(glGetnPolygonStipple,                       loader);
    OPENGL_LOAD_PROC(glGetnColorTable,                           loader);
    OPENGL_LOAD_PROC(glGetnConvolutionFilter,                    loader);
    OPENGL_LOAD_PROC(glGetnSeparableFilter,                      loader);
    OPENGL_LOAD_PROC(glGetnHistogram,                            loader);
    OPENGL_LOAD_PROC(glGetnMinmax,                               loader);
    #endif // OPENGL_USE_COMPATIBILITY_PROFILE
    #endif // OPENGL_LOAD_GL_VERSION_4_5
    return true;
}

/* -------------------------------------------------------------------------- */

static bool internal__load_GL_VERSION_4_6 (OpenGL_Proc_Loader loader)
{
    #if defined(OPENGL_LOAD_GL_VERSION_4_6)
    OPENGL_LOAD_PROC(glMultiDrawArraysIndirectCount,   loader);
    OPENGL_LOAD_PROC(glMultiDrawElementsIndirectCount, loader);
    OPENGL_LOAD_PROC(glPolygonOffsetClamp,             loader);
    OPENGL_LOAD_PROC(glSpecializeShader,               loader);
    #endif // OPENGL_LOAD_GL_VERSION_4_6
    return true;
}

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_ES3_2_compatibility)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_ES3_2_compatibility,
OPENGL_LOAD_PROC(glPrimitiveBoundingBoxARB, loader));
#endif // OPENGL_INCLUDE_GL_ARB_ES3_2_compatibility

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_bindless_texture)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_bindless_texture,
OPENGL_LOAD_PROC(glGetTextureHandleARB,             loader);
OPENGL_LOAD_PROC(glGetTextureSamplerHandleARB,      loader);
OPENGL_LOAD_PROC(glMakeTextureHandleResidentARB,    loader);
OPENGL_LOAD_PROC(glMakeTextureHandleNonResidentARB, loader);
OPENGL_LOAD_PROC(glGetImageHandleARB,               loader);
OPENGL_LOAD_PROC(glMakeImageHandleResidentARB,      loader);
OPENGL_LOAD_PROC(glMakeImageHandleNonResidentARB,   loader);
OPENGL_LOAD_PROC(glUniformHandleui64ARB,            loader);
OPENGL_LOAD_PROC(glUniformHandleui64vARB,           loader);
OPENGL_LOAD_PROC(glProgramUniformHandleui64ARB,     loader);
OPENGL_LOAD_PROC(glProgramUniformHandleui64vARB,    loader);
OPENGL_LOAD_PROC(glIsTextureHandleResidentARB,      loader);
OPENGL_LOAD_PROC(glIsImageHandleResidentARB,        loader);
OPENGL_LOAD_PROC(glVertexAttribL1ui64ARB,           loader);
OPENGL_LOAD_PROC(glVertexAttribL1ui64vARB,          loader);
OPENGL_LOAD_PROC(glGetVertexAttribLui64vARB,        loader));
#endif // OPENGL_INCLUDE_GL_ARB_bindless_texture

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_cl_event)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_cl_event,
OPENGL_LOAD_PROC(glCreateSyncFromCLeventARB, loader));
#endif // OPENGL_INCLUDE_GL_ARB_cl_event

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_color_buffer_float)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_color_buffer_float,
OPENGL_LOAD_PROC(glClampColorARB, loader));
#endif // OPENGL_INCLUDE_GL_ARB_color_buffer_float

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_compute_variable_group_size)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_compute_variable_group_size,
OPENGL_LOAD_PROC(glDispatchComputeGroupSizeARB, loader));
#endif // OPENGL_INCLUDE_GL_ARB_compute_variable_group_size

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_debug_output)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_debug_output,
OPENGL_LOAD_PROC(glDebugMessageControlARB,  loader);
OPENGL_LOAD_PROC(glDebugMessageInsertARB,   loader);
OPENGL_LOAD_PROC(glDebugMessageCallbackARB, loader);
OPENGL_LOAD_PROC(glGetDebugMessageLogARB,   loader));
#endif // OPENGL_INCLUDE_GL_ARB_debug_output

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_draw_buffers)
#OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_draw_buffers,
OPENGL_LOAD_PROC(glDrawBuffersARB, loader));
#endif // OPENGL_INCLUDE_GL_ARB_draw_buffers

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_draw_buffers_blend)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_draw_buffers_blend,
OPENGL_LOAD_PROC(glBlendEquationiARB,         loader);
OPENGL_LOAD_PROC(glBlendEquationSeparateiARB, loader);
OPENGL_LOAD_PROC(glBlendFunciARB,             loader);
OPENGL_LOAD_PROC(glBlendFuncSeparateiARB,     loader));
#endif // OPENGL_INCLUDE_GL_ARB_draw_buffers_blend

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_draw_instanced)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_draw_instanced,
OPENGL_LOAD_PROC(glDrawArraysInstancedARB,   loader);
OPENGL_LOAD_PROC(glDrawElementsInstancedARB, loader));
#endif // OPENGL_INCLUDE_GL_ARB_draw_instanced

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_fragment_program)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_fragment_program,
OPENGL_LOAD_PROC(glProgramStringARB,              loader);
OPENGL_LOAD_PROC(glBindProgramARB,                loader);
OPENGL_LOAD_PROC(glDeleteProgramsARB,             loader);
OPENGL_LOAD_PROC(glGenProgramsARB,                loader);
OPENGL_LOAD_PROC(glProgramEnvParameter4dARB,      loader);
OPENGL_LOAD_PROC(glProgramEnvParameter4dvARB,     loader);
OPENGL_LOAD_PROC(glProgramEnvParameter4fARB,      loader);
OPENGL_LOAD_PROC(glProgramEnvParameter4fvARB,     loader);
OPENGL_LOAD_PROC(glProgramLocalParameter4dARB,    loader);
OPENGL_LOAD_PROC(glProgramLocalParameter4dvARB,   loader);
OPENGL_LOAD_PROC(glProgramLocalParameter4fARB,    loader);
OPENGL_LOAD_PROC(glProgramLocalParameter4fvARB,   loader);
OPENGL_LOAD_PROC(glGetProgramEnvParameterdvARB,   loader);
OPENGL_LOAD_PROC(glGetProgramEnvParameterfvARB,   loader);
OPENGL_LOAD_PROC(glGetProgramLocalParameterdvARB, loader);
OPENGL_LOAD_PROC(glGetProgramLocalParameterfvARB, loader);
OPENGL_LOAD_PROC(glGetProgramivARB,               loader);
OPENGL_LOAD_PROC(glGetProgramStringARB,           loader);
OPENGL_LOAD_PROC(glIsProgramARB,                  loader));
#endif // OPENGL_INCLUDE_GL_ARB_fragment_program

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_geometry_shader4)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_geometry_shader4,
OPENGL_LOAD_PROC(glProgramParameteriARB,       loader);
OPENGL_LOAD_PROC(glFramebufferTextureARB,      loader);
OPENGL_LOAD_PROC(glFramebufferTextureLayerARB, loader);
OPENGL_LOAD_PROC(glFramebufferTextureFaceARB,  loader));
#endif // OPENGL_INCLUDE_GL_ARB_geometry_shader4

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_gl_spirv)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_gl_spirv,
OPENGL_LOAD_PROC(glSpecializeShaderARB, loader));
#endif // OPENGL_INCLUDE_GL_ARB_gl_spirv

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_gpu_shader_int64)
OPENGL_CREATE_GL_EXTENSION_LOADER(
_GL_ARB_gpu_shader_int64,
OPENGL_LOAD_PROC(glUniform1i64ARB,          loader);
OPENGL_LOAD_PROC(glUniform2i64ARB,          loader);
OPENGL_LOAD_PROC(glUniform3i64ARB,          loader);
OPENGL_LOAD_PROC(glUniform4i64ARB,          loader);
OPENGL_LOAD_PROC(glUniform1i64vARB,         loader);
OPENGL_LOAD_PROC(glUniform2i64vARB,         loader);
OPENGL_LOAD_PROC(glUniform3i64vARB,         loader);
OPENGL_LOAD_PROC(glUniform4i64vARB,         loader);
OPENGL_LOAD_PROC(glUniform1ui64ARB,         loader);
OPENGL_LOAD_PROC(glUniform2ui64ARB,         loader);
OPENGL_LOAD_PROC(glUniform3ui64ARB,         loader);
OPENGL_LOAD_PROC(glUniform4ui64ARB,         loader);
OPENGL_LOAD_PROC(glUniform1ui64vARB,        loader);
OPENGL_LOAD_PROC(glUniform2ui64vARB,        loader);
OPENGL_LOAD_PROC(glUniform3ui64vARB,        loader);
OPENGL_LOAD_PROC(glUniform4ui64vARB,        loader);
OPENGL_LOAD_PROC(glGetUniformi64vARB,       loader);
OPENGL_LOAD_PROC(glGetUniformui64vARB,      loader);
OPENGL_LOAD_PROC(glGetnUniformi64vARB,      loader);
OPENGL_LOAD_PROC(glGetnUniformui64vARB,     loader);
OPENGL_LOAD_PROC(glProgramUniform1i64ARB,   loader);
OPENGL_LOAD_PROC(glProgramUniform2i64ARB,   loader);
OPENGL_LOAD_PROC(glProgramUniform3i64ARB,   loader);
OPENGL_LOAD_PROC(glProgramUniform4i64ARB,   loader);
OPENGL_LOAD_PROC(glProgramUniform1i64vARB,  loader);
OPENGL_LOAD_PROC(glProgramUniform2i64vARB,  loader);
OPENGL_LOAD_PROC(glProgramUniform3i64vARB,  loader);
OPENGL_LOAD_PROC(glProgramUniform4i64vARB,  loader);
OPENGL_LOAD_PROC(glProgramUniform1ui64ARB,  loader);
OPENGL_LOAD_PROC(glProgramUniform2ui64ARB,  loader);
OPENGL_LOAD_PROC(glProgramUniform3ui64ARB,  loader);
OPENGL_LOAD_PROC(glProgramUniform4ui64ARB,  loader);
OPENGL_LOAD_PROC(glProgramUniform1ui64vARB, loader);
OPENGL_LOAD_PROC(glProgramUniform2ui64vARB, loader);
OPENGL_LOAD_PROC(glProgramUniform3ui64vARB, loader);
OPENGL_LOAD_PROC(glProgramUniform4ui64vARB, loader));
#endif // OPENGL_INCLUDE_GL_ARB_gpu_shader_int64

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_imaging)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_imaging,
OPENGL_LOAD_PROC(glColorTable,                loader);
OPENGL_LOAD_PROC(glColorTableParameterfv,     loader);
OPENGL_LOAD_PROC(glColorTableParameteriv,     loader);
OPENGL_LOAD_PROC(glCopyColorTable,            loader);
OPENGL_LOAD_PROC(glGetColorTable,             loader);
OPENGL_LOAD_PROC(glGetColorTableParameterfv,  loader);
OPENGL_LOAD_PROC(glGetColorTableParameteriv,  loader);
OPENGL_LOAD_PROC(glColorSubTable,             loader);
OPENGL_LOAD_PROC(glCopyColorSubTable,         loader);
OPENGL_LOAD_PROC(glConvolutionFilter1D,       loader);
OPENGL_LOAD_PROC(glConvolutionFilter2D,       loader);
OPENGL_LOAD_PROC(glConvolutionParameterf,     loader);
OPENGL_LOAD_PROC(glConvolutionParameterfv,    loader);
OPENGL_LOAD_PROC(glConvolutionParameteri,     loader);
OPENGL_LOAD_PROC(glConvolutionParameteriv,    loader);
OPENGL_LOAD_PROC(glCopyConvolutionFilter1D,   loader);
OPENGL_LOAD_PROC(glCopyConvolutionFilter2D,   loader);
OPENGL_LOAD_PROC(glGetConvolutionFilter,      loader);
OPENGL_LOAD_PROC(glGetConvolutionParameterfv, loader);
OPENGL_LOAD_PROC(glGetConvolutionParameteriv, loader);
OPENGL_LOAD_PROC(glGetSeparableFilter,        loader);
OPENGL_LOAD_PROC(glSeparableFilter2D,         loader);
OPENGL_LOAD_PROC(glGetHistogram,              loader);
OPENGL_LOAD_PROC(glGetHistogramParameterfv,   loader);
OPENGL_LOAD_PROC(glGetHistogramParameteriv,   loader);
OPENGL_LOAD_PROC(glGetMinmax,                 loader);
OPENGL_LOAD_PROC(glGetMinmaxParameterfv,      loader);
OPENGL_LOAD_PROC(glGetMinmaxParameteriv,      loader);
OPENGL_LOAD_PROC(glHistogram,                 loader);
OPENGL_LOAD_PROC(glMinmax,                    loader);
OPENGL_LOAD_PROC(glResetHistogram,            loader);
OPENGL_LOAD_PROC(glResetMinmax,               loader));
#endif // OPENGL_INCLUDE_GL_ARB_imaging

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_indirect_parameters)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_indirect_parameters,
OPENGL_LOAD_PROC(glMultiDrawArraysIndirectCountARB,   loader);
OPENGL_LOAD_PROC(glMultiDrawElementsIndirectCountARB, loader));
#endif // OPENGL_INCLUDE_GL_ARB_indirect_parameters

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_instanced_arrays)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_instanced_arrays,
OPENGL_LOAD_PROC(glVertexAttribDivisorARB, loader));
#endif // OPENGL_INCLUDE_GL_ARB_instanced_arrays

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_matrix_palette)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_matrix_palette,
OPENGL_LOAD_PROC(glCurrentPaletteMatrixARB, loader);
OPENGL_LOAD_PROC(glMatrixIndexubvARB,       loader);
OPENGL_LOAD_PROC(glMatrixIndexusvARB,       loader);
OPENGL_LOAD_PROC(glMatrixIndexuivARB,       loader);
OPENGL_LOAD_PROC(glMatrixIndexPointerARB,   loader));
#endif // OPENGL_INCLUDE_GL_ARB_matrix_palette

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_multisample)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_multisample,
OPENGL_LOAD_PROC(glSampleCoverageARB, loader));
#endif // OPENGL_INCLUDE_GL_ARB_multisample

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_multitexture)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_multitexture,
OPENGL_LOAD_PROC(glActiveTextureARB,       loader);
OPENGL_LOAD_PROC(glClientActiveTextureARB, loader);
OPENGL_LOAD_PROC(glMultiTexCoord1dARB,     loader);
OPENGL_LOAD_PROC(glMultiTexCoord1dvARB,    loader);
OPENGL_LOAD_PROC(glMultiTexCoord1fARB,     loader);
OPENGL_LOAD_PROC(glMultiTexCoord1fvARB,    loader);
OPENGL_LOAD_PROC(glMultiTexCoord1iARB,     loader);
OPENGL_LOAD_PROC(glMultiTexCoord1ivARB,    loader);
OPENGL_LOAD_PROC(glMultiTexCoord1sARB,     loader);
OPENGL_LOAD_PROC(glMultiTexCoord1svARB,    loader);
OPENGL_LOAD_PROC(glMultiTexCoord2dARB,     loader);
OPENGL_LOAD_PROC(glMultiTexCoord2dvARB,    loader);
OPENGL_LOAD_PROC(glMultiTexCoord2fARB,     loader);
OPENGL_LOAD_PROC(glMultiTexCoord2fvARB,    loader);
OPENGL_LOAD_PROC(glMultiTexCoord2iARB,     loader);
OPENGL_LOAD_PROC(glMultiTexCoord2ivARB,    loader);
OPENGL_LOAD_PROC(glMultiTexCoord2sARB,     loader);
OPENGL_LOAD_PROC(glMultiTexCoord2svARB,    loader);
OPENGL_LOAD_PROC(glMultiTexCoord3dARB,     loader);
OPENGL_LOAD_PROC(glMultiTexCoord3dvARB,    loader);
OPENGL_LOAD_PROC(glMultiTexCoord3fARB,     loader);
OPENGL_LOAD_PROC(glMultiTexCoord3fvARB,    loader);
OPENGL_LOAD_PROC(glMultiTexCoord3iARB,     loader);
OPENGL_LOAD_PROC(glMultiTexCoord3ivARB,    loader);
OPENGL_LOAD_PROC(glMultiTexCoord3sARB,     loader);
OPENGL_LOAD_PROC(glMultiTexCoord3svARB,    loader);
OPENGL_LOAD_PROC(glMultiTexCoord4dARB,     loader);
OPENGL_LOAD_PROC(glMultiTexCoord4dvARB,    loader);
OPENGL_LOAD_PROC(glMultiTexCoord4fARB,     loader);
OPENGL_LOAD_PROC(glMultiTexCoord4fvARB,    loader);
OPENGL_LOAD_PROC(glMultiTexCoord4iARB,     loader);
OPENGL_LOAD_PROC(glMultiTexCoord4ivARB,    loader);
OPENGL_LOAD_PROC(glMultiTexCoord4sARB,     loader);
OPENGL_LOAD_PROC(glMultiTexCoord4svARB,    loader));
#endif // OPENGL_INCLUDE_GL_ARB_multitexture

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_occlusion_query)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_occlusion_query,
OPENGL_LOAD_PROC(glGenQueriesARB,        loader);
OPENGL_LOAD_PROC(glDeleteQueriesARB,     loader);
OPENGL_LOAD_PROC(glIsQueryARB,           loader);
OPENGL_LOAD_PROC(glBeginQueryARB,        loader);
OPENGL_LOAD_PROC(glEndQueryARB,          loader);
OPENGL_LOAD_PROC(glGetQueryivARB,        loader);
OPENGL_LOAD_PROC(glGetQueryObjectivARB,  loader);
OPENGL_LOAD_PROC(glGetQueryObjectuivARB, loader));
#endif // OPENGL_INCLUDE_GL_ARB_occlusion_query

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_parallel_shader_compile)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_parallel_shader_compile,
OPENGL_LOAD_PROC(glMaxShaderCompilerThreadsARB, loader));
#endif // OPENGL_INCLUDE_GL_ARB_parallel_shader_compile

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_point_parameters)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_point_parameters,
OPENGL_LOAD_PROC(glPointParameterfARB,  loader);
OPENGL_LOAD_PROC(glPointParameterfvARB, loader));
#endif // OPENGL_INCLUDE_GL_ARB_point_parameters

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_robustness)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_robustness,
OPENGL_LOAD_PROC(glGetGraphicsResetStatusARB, loader);
OPENGL_LOAD_PROC(glGetnTexImageARB,           loader);
OPENGL_LOAD_PROC(glReadnPixelsARB,            loader);
OPENGL_LOAD_PROC(glGetnCompressedTexImageARB, loader);
OPENGL_LOAD_PROC(glGetnUniformfvARB,          loader);
OPENGL_LOAD_PROC(glGetnUniformivARB,          loader);
OPENGL_LOAD_PROC(glGetnUniformuivARB,         loader);
OPENGL_LOAD_PROC(glGetnUniformdvARB,          loader);
OPENGL_LOAD_PROC(glGetnMapdvARB,              loader);
OPENGL_LOAD_PROC(glGetnMapfvARB,              loader);
OPENGL_LOAD_PROC(glGetnMapivARB,              loader);
OPENGL_LOAD_PROC(glGetnPixelMapfvARB,         loader);
OPENGL_LOAD_PROC(glGetnPixelMapuivARB,        loader);
OPENGL_LOAD_PROC(glGetnPixelMapusvARB,        loader);
OPENGL_LOAD_PROC(glGetnPolygonStippleARB,     loader);
OPENGL_LOAD_PROC(glGetnColorTableARB,         loader);
OPENGL_LOAD_PROC(glGetnConvolutionFilterARB,  loader);
OPENGL_LOAD_PROC(glGetnSeparableFilterARB,    loader);
OPENGL_LOAD_PROC(glGetnHistogramARB,          loader);
OPENGL_LOAD_PROC(glGetnMinmaxARB,             loader));
#endif // OPENGL_INCLUDE_GL_ARB_robustness

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_sample_locations)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_sample_locations,
OPENGL_LOAD_PROC(glFramebufferSampleLocationsfvARB,      loader);
OPENGL_LOAD_PROC(glNamedFramebufferSampleLocationsfvARB, loader);
OPENGL_LOAD_PROC(glEvaluateDepthValuesARB,               loader));
#endif // OPENGL_INCLUDE_GL_ARB_sample_locations

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_sample_shading)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_sample_shading,
OPENGL_LOAD_PROC(glMinSampleShadingARB, loader));
#endif // OPENGL_INCLUDE_GL_ARB_sample_shading

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_shader_objects)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_shader_objects,
OPENGL_LOAD_PROC(glDeleteObjectARB,         loader);
OPENGL_LOAD_PROC(glGetHandleARB,            loader);
OPENGL_LOAD_PROC(glDetachObjectARB,         loader);
OPENGL_LOAD_PROC(glCreateShaderObjectARB,   loader);
OPENGL_LOAD_PROC(glShaderSourceARB,         loader);
OPENGL_LOAD_PROC(glCompileShaderARB,        loader);
OPENGL_LOAD_PROC(glCreateProgramObjectARB,  loader);
OPENGL_LOAD_PROC(glAttachObjectARB,         loader);
OPENGL_LOAD_PROC(glLinkProgramARB,          loader);
OPENGL_LOAD_PROC(glUseProgramObjectARB,     loader);
OPENGL_LOAD_PROC(glValidateProgramARB,      loader);
OPENGL_LOAD_PROC(glUniform1fARB,            loader);
OPENGL_LOAD_PROC(glUniform2fARB,            loader);
OPENGL_LOAD_PROC(glUniform3fARB,            loader);
OPENGL_LOAD_PROC(glUniform4fARB,            loader);
OPENGL_LOAD_PROC(glUniform1iARB,            loader);
OPENGL_LOAD_PROC(glUniform2iARB,            loader);
OPENGL_LOAD_PROC(glUniform3iARB,            loader);
OPENGL_LOAD_PROC(glUniform4iARB,            loader);
OPENGL_LOAD_PROC(glUniform1fvARB,           loader);
OPENGL_LOAD_PROC(glUniform2fvARB,           loader);
OPENGL_LOAD_PROC(glUniform3fvARB,           loader);
OPENGL_LOAD_PROC(glUniform4fvARB,           loader);
OPENGL_LOAD_PROC(glUniform1ivARB,           loader);
OPENGL_LOAD_PROC(glUniform2ivARB,           loader);
OPENGL_LOAD_PROC(glUniform3ivARB,           loader);
OPENGL_LOAD_PROC(glUniform4ivARB,           loader);
OPENGL_LOAD_PROC(glUniformMatrix2fvARB,     loader);
OPENGL_LOAD_PROC(glUniformMatrix3fvARB,     loader);
OPENGL_LOAD_PROC(glUniformMatrix4fvARB,     loader);
OPENGL_LOAD_PROC(glGetObjectParameterfvARB, loader);
OPENGL_LOAD_PROC(glGetObjectParameterivARB, loader);
OPENGL_LOAD_PROC(glGetInfoLogARB,           loader);
OPENGL_LOAD_PROC(glGetAttachedObjectsARB,   loader);
OPENGL_LOAD_PROC(glGetUniformLocationARB,   loader);
OPENGL_LOAD_PROC(glGetActiveUniformARB,     loader);
OPENGL_LOAD_PROC(glGetUniformfvARB,         loader);
OPENGL_LOAD_PROC(glGetUniformivARB,         loader);
OPENGL_LOAD_PROC(glGetShaderSourceARB,      loader));
#endif // OPENGL_INCLUDE_GL_ARB_shader_objects

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_shading_language_include)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_shading_language_include,
OPENGL_LOAD_PROC(glNamedStringARB,          loader);
OPENGL_LOAD_PROC(glDeleteNamedStringARB,    loader);
OPENGL_LOAD_PROC(glCompileShaderIncludeARB, loader);
OPENGL_LOAD_PROC(glIsNamedStringARB,        loader);
OPENGL_LOAD_PROC(glGetNamedStringARB,       loader);
OPENGL_LOAD_PROC(glGetNamedStringivARB,     loader));
#endif // OPENGL_INCLUDE_GL_ARB_shading_language_include

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_sparse_buffer)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_sparse_buffer,
OPENGL_LOAD_PROC(glBufferPageCommitmentARB,      loader);
OPENGL_LOAD_PROC(glNamedBufferPageCommitmentEXT, loader);
OPENGL_LOAD_PROC(glNamedBufferPageCommitmentARB, loader));
#endif // OPENGL_INCLUDE_GL_ARB_sparse_buffer

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_sparse_texture)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_sparse_texture,
OPENGL_LOAD_PROC(glTexPageCommitmentARB, loader));
#endif // OPENGL_INCLUDE_GL_ARB_sparse_texture

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_texture_buffer_object)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_texture_buffer_object,
OPENGL_LOAD_PROC(glTexBufferARB, loader));
#endif // OPENGL_INCLUDE_GL_ARB_texture_buffer_object

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_texture_compression)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_texture_compression,
OPENGL_LOAD_PROC(glCompressedTexImage3DARB,    loader);
OPENGL_LOAD_PROC(glCompressedTexImage2DARB,    loader);
OPENGL_LOAD_PROC(glCompressedTexImage1DARB,    loader);
OPENGL_LOAD_PROC(glCompressedTexSubImage3DARB, loader);
OPENGL_LOAD_PROC(glCompressedTexSubImage2DARB, loader);
OPENGL_LOAD_PROC(glCompressedTexSubImage1DARB, loader);
OPENGL_LOAD_PROC(glGetCompressedTexImageARB,   loader));
#endif // OPENGL_INCLUDE_GL_ARB_texture_compression

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_transpose_matrix)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_transpose_matrix,
OPENGL_LOAD_PROC(glLoadTransposeMatrixfARB, loader);
OPENGL_LOAD_PROC(glLoadTransposeMatrixdARB, loader);
OPENGL_LOAD_PROC(glMultTransposeMatrixfARB, loader);
OPENGL_LOAD_PROC(glMultTransposeMatrixdARB, loader));
#endif // OPENGL_INCLUDE_GL_ARB_transpose_matrix

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_vertex_blend)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_vertex_blend,
OPENGL_LOAD_PROC(glWeightbvARB,      loader);
OPENGL_LOAD_PROC(glWeightsvARB,      loader);
OPENGL_LOAD_PROC(glWeightivARB,      loader);
OPENGL_LOAD_PROC(glWeightfvARB,      loader);
OPENGL_LOAD_PROC(glWeightdvARB,      loader);
OPENGL_LOAD_PROC(glWeightubvARB,     loader);
OPENGL_LOAD_PROC(glWeightusvARB,     loader);
OPENGL_LOAD_PROC(glWeightuivARB,     loader);
OPENGL_LOAD_PROC(glWeightPointerARB, loader);
OPENGL_LOAD_PROC(glVertexBlendARB,   loader));
#endif // OPENGL_INCLUDE_GL_ARB_vertex_blend

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_vertex_buffer_object)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_vertex_buffer_object,
OPENGL_LOAD_PROC(glBindBufferARB,           loader);
OPENGL_LOAD_PROC(glDeleteBuffersARB,        loader);
OPENGL_LOAD_PROC(glGenBuffersARB,           loader);
OPENGL_LOAD_PROC(glIsBufferARB,             loader);
OPENGL_LOAD_PROC(glBufferDataARB,           loader);
OPENGL_LOAD_PROC(glBufferSubDataARB,        loader);
OPENGL_LOAD_PROC(glGetBufferSubDataARB,     loader);
OPENGL_LOAD_PROC(glMapBufferARB,            loader);
OPENGL_LOAD_PROC(glUnmapBufferARB,          loader);
OPENGL_LOAD_PROC(glGetBufferParameterivARB, loader);
OPENGL_LOAD_PROC(glGetBufferPointervARB,    loader));
#endif // OPENGL_INCLUDE_GL_ARB_vertex_buffer_object

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_vertex_program)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_vertex_program,
OPENGL_LOAD_PROC(glVertexAttrib1dARB,           loader);
OPENGL_LOAD_PROC(glVertexAttrib1dvARB,          loader);
OPENGL_LOAD_PROC(glVertexAttrib1fARB,           loader);
OPENGL_LOAD_PROC(glVertexAttrib1fvARB,          loader);
OPENGL_LOAD_PROC(glVertexAttrib1sARB,           loader);
OPENGL_LOAD_PROC(glVertexAttrib1svARB,          loader);
OPENGL_LOAD_PROC(glVertexAttrib2dARB,           loader);
OPENGL_LOAD_PROC(glVertexAttrib2dvARB,          loader);
OPENGL_LOAD_PROC(glVertexAttrib2fARB,           loader);
OPENGL_LOAD_PROC(glVertexAttrib2fvARB,          loader);
OPENGL_LOAD_PROC(glVertexAttrib2sARB,           loader);
OPENGL_LOAD_PROC(glVertexAttrib2svARB,          loader);
OPENGL_LOAD_PROC(glVertexAttrib3dARB,           loader);
OPENGL_LOAD_PROC(glVertexAttrib3dvARB,          loader);
OPENGL_LOAD_PROC(glVertexAttrib3fARB,           loader);
OPENGL_LOAD_PROC(glVertexAttrib3fvARB,          loader);
OPENGL_LOAD_PROC(glVertexAttrib3sARB,           loader);
OPENGL_LOAD_PROC(glVertexAttrib3svARB,          loader);
OPENGL_LOAD_PROC(glVertexAttrib4NbvARB,         loader);
OPENGL_LOAD_PROC(glVertexAttrib4NivARB,         loader);
OPENGL_LOAD_PROC(glVertexAttrib4NsvARB,         loader);
OPENGL_LOAD_PROC(glVertexAttrib4NubARB,         loader);
OPENGL_LOAD_PROC(glVertexAttrib4NubvARB,        loader);
OPENGL_LOAD_PROC(glVertexAttrib4NuivARB,        loader);
OPENGL_LOAD_PROC(glVertexAttrib4NusvARB,        loader);
OPENGL_LOAD_PROC(glVertexAttrib4bvARB,          loader);
OPENGL_LOAD_PROC(glVertexAttrib4dARB,           loader);
OPENGL_LOAD_PROC(glVertexAttrib4dvARB,          loader);
OPENGL_LOAD_PROC(glVertexAttrib4fARB,           loader);
OPENGL_LOAD_PROC(glVertexAttrib4fvARB,          loader);
OPENGL_LOAD_PROC(glVertexAttrib4ivARB,          loader);
OPENGL_LOAD_PROC(glVertexAttrib4sARB,           loader);
OPENGL_LOAD_PROC(glVertexAttrib4svARB,          loader);
OPENGL_LOAD_PROC(glVertexAttrib4ubvARB,         loader);
OPENGL_LOAD_PROC(glVertexAttrib4uivARB,         loader);
OPENGL_LOAD_PROC(glVertexAttrib4usvARB,         loader);
OPENGL_LOAD_PROC(glVertexAttribPointerARB,      loader);
OPENGL_LOAD_PROC(glEnableVertexAttribArrayARB,  loader);
OPENGL_LOAD_PROC(glDisableVertexAttribArrayARB, loader);
OPENGL_LOAD_PROC(glGetVertexAttribdvARB,        loader);
OPENGL_LOAD_PROC(glGetVertexAttribfvARB,        loader);
OPENGL_LOAD_PROC(glGetVertexAttribivARB,        loader);
OPENGL_LOAD_PROC(glGetVertexAttribPointervARB,  loader));
#endif // OPENGL_INCLUDE_GL_ARB_vertex_program

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_vertex_shader)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_vertex_shader,
OPENGL_LOAD_PROC(glBindAttribLocationARB, loader);
OPENGL_LOAD_PROC(glGetActiveAttribARB,    loader);
OPENGL_LOAD_PROC(glGetAttribLocationARB,  loader));
#endif // OPENGL_INCLUDE_GL_ARB_vertex_shader

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ARB_window_pos)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ARB_window_pos,
OPENGL_LOAD_PROC(glWindowPos2dARB,  loader);
OPENGL_LOAD_PROC(glWindowPos2dvARB, loader);
OPENGL_LOAD_PROC(glWindowPos2fARB,  loader);
OPENGL_LOAD_PROC(glWindowPos2fvARB, loader);
OPENGL_LOAD_PROC(glWindowPos2iARB,  loader);
OPENGL_LOAD_PROC(glWindowPos2ivARB, loader);
OPENGL_LOAD_PROC(glWindowPos2sARB,  loader);
OPENGL_LOAD_PROC(glWindowPos2svARB, loader);
OPENGL_LOAD_PROC(glWindowPos3dARB,  loader);
OPENGL_LOAD_PROC(glWindowPos3dvARB, loader);
OPENGL_LOAD_PROC(glWindowPos3fARB,  loader);
OPENGL_LOAD_PROC(glWindowPos3fvARB, loader);
OPENGL_LOAD_PROC(glWindowPos3iARB,  loader);
OPENGL_LOAD_PROC(glWindowPos3ivARB, loader);
OPENGL_LOAD_PROC(glWindowPos3sARB,  loader);
OPENGL_LOAD_PROC(glWindowPos3svARB, loader));
#endif // OPENGL_INCLUDE_GL_ARB_window_pos

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_KHR_blend_equation_advanced)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_KHR_blend_equation_advanced,
OPENGL_LOAD_PROC(glBlendBarrierKHR, loader));
#endif // OPENGL_INCLUDE_GL_KHR_blend_equation_advanced

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_OES_byte_coordinates)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_OES_byte_coordinates,
OPENGL_LOAD_PROC(glMultiTexCoord1bOES,  loader);
OPENGL_LOAD_PROC(glMultiTexCoord1bvOES, loader);
OPENGL_LOAD_PROC(glMultiTexCoord2bOES,  loader);
OPENGL_LOAD_PROC(glMultiTexCoord2bvOES, loader);
OPENGL_LOAD_PROC(glMultiTexCoord3bOES,  loader);
OPENGL_LOAD_PROC(glMultiTexCoord3bvOES, loader);
OPENGL_LOAD_PROC(glMultiTexCoord4bOES,  loader);
OPENGL_LOAD_PROC(glMultiTexCoord4bvOES, loader);
OPENGL_LOAD_PROC(glTexCoord1bOES,       loader);
OPENGL_LOAD_PROC(glTexCoord1bvOES,      loader);
OPENGL_LOAD_PROC(glTexCoord2bOES,       loader);
OPENGL_LOAD_PROC(glTexCoord2bvOES,      loader);
OPENGL_LOAD_PROC(glTexCoord3bOES,       loader);
OPENGL_LOAD_PROC(glTexCoord3bvOES,      loader);
OPENGL_LOAD_PROC(glTexCoord4bOES,       loader);
OPENGL_LOAD_PROC(glTexCoord4bvOES,      loader);
OPENGL_LOAD_PROC(glVertex2bOES,         loader);
OPENGL_LOAD_PROC(glVertex2bvOES,        loader);
OPENGL_LOAD_PROC(glVertex3bOES,         loader);
OPENGL_LOAD_PROC(glVertex3bvOES,        loader);
OPENGL_LOAD_PROC(glVertex4bOES,         loader);
OPENGL_LOAD_PROC(glVertex4bvOES,        loader));
#endif // OPENGL_INCLUDE_GL_OES_byte_coordinates

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_OES_fixed_point)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_OES_fixed_point,
OPENGL_LOAD_PROC(glAlphaFuncxOES,                loader);
OPENGL_LOAD_PROC(glClearColorxOES,               loader);
OPENGL_LOAD_PROC(glClearDepthxOES,               loader);
OPENGL_LOAD_PROC(glClipPlanexOES,                loader);
OPENGL_LOAD_PROC(glColor4xOES,                   loader);
OPENGL_LOAD_PROC(glDepthRangexOES,               loader);
OPENGL_LOAD_PROC(glFogxOES,                      loader);
OPENGL_LOAD_PROC(glFogxvOES,                     loader);
OPENGL_LOAD_PROC(glFrustumxOES,                  loader);
OPENGL_LOAD_PROC(glGetClipPlanexOES,             loader);
OPENGL_LOAD_PROC(glGetFixedvOES,                 loader);
OPENGL_LOAD_PROC(glGetTexEnvxvOES,               loader);
OPENGL_LOAD_PROC(glGetTexParameterxvOES,         loader);
OPENGL_LOAD_PROC(glLightModelxOES,               loader);
OPENGL_LOAD_PROC(glLightModelxvOES,              loader);
OPENGL_LOAD_PROC(glLightxOES,                    loader);
OPENGL_LOAD_PROC(glLightxvOES,                   loader);
OPENGL_LOAD_PROC(glLineWidthxOES,                loader);
OPENGL_LOAD_PROC(glLoadMatrixxOES,               loader);
OPENGL_LOAD_PROC(glMaterialxOES,                 loader);
OPENGL_LOAD_PROC(glMaterialxvOES,                loader);
OPENGL_LOAD_PROC(glMultMatrixxOES,               loader);
OPENGL_LOAD_PROC(glMultiTexCoord4xOES,           loader);
OPENGL_LOAD_PROC(glNormal3xOES,                  loader);
OPENGL_LOAD_PROC(glOrthoxOES,                    loader);
OPENGL_LOAD_PROC(glPointParameterxvOES,          loader);
OPENGL_LOAD_PROC(glPointSizexOES,                loader);
OPENGL_LOAD_PROC(glPolygonOffsetxOES,            loader);
OPENGL_LOAD_PROC(glRotatexOES,                   loader);
OPENGL_LOAD_PROC(glScalexOES,                    loader);
OPENGL_LOAD_PROC(glTexEnvxOES,                   loader);
OPENGL_LOAD_PROC(glTexEnvxvOES,                  loader);
OPENGL_LOAD_PROC(glTexParameterxOES,             loader);
OPENGL_LOAD_PROC(glTexParameterxvOES,            loader);
OPENGL_LOAD_PROC(glTranslatexOES,                loader);
OPENGL_LOAD_PROC(glAccumxOES,                    loader);
OPENGL_LOAD_PROC(glBitmapxOES,                   loader);
OPENGL_LOAD_PROC(glBlendColorxOES,               loader);
OPENGL_LOAD_PROC(glClearAccumxOES,               loader);
OPENGL_LOAD_PROC(glColor3xOES,                   loader);
OPENGL_LOAD_PROC(glColor3xvOES,                  loader);
OPENGL_LOAD_PROC(glColor4xvOES,                  loader);
OPENGL_LOAD_PROC(glConvolutionParameterxOES,     loader);
OPENGL_LOAD_PROC(glConvolutionParameterxvOES,    loader);
OPENGL_LOAD_PROC(glEvalCoord1xOES,               loader);
OPENGL_LOAD_PROC(glEvalCoord1xvOES,              loader);
OPENGL_LOAD_PROC(glEvalCoord2xOES,               loader);
OPENGL_LOAD_PROC(glEvalCoord2xvOES,              loader);
OPENGL_LOAD_PROC(glFeedbackBufferxOES,           loader);
OPENGL_LOAD_PROC(glGetConvolutionParameterxvOES, loader);
OPENGL_LOAD_PROC(glGetHistogramParameterxvOES,   loader);
OPENGL_LOAD_PROC(glGetLightxOES,                 loader);
OPENGL_LOAD_PROC(glGetMapxvOES,                  loader);
OPENGL_LOAD_PROC(glGetMaterialxOES,              loader);
OPENGL_LOAD_PROC(glGetPixelMapxv,                loader);
OPENGL_LOAD_PROC(glGetTexGenxvOES,               loader);
OPENGL_LOAD_PROC(glGetTexLevelParameterxvOES,    loader);
OPENGL_LOAD_PROC(glIndexxOES,                    loader);
OPENGL_LOAD_PROC(glIndexxvOES,                   loader);
OPENGL_LOAD_PROC(glLoadTransposeMatrixxOES,      loader);
OPENGL_LOAD_PROC(glMap1xOES,                     loader);
OPENGL_LOAD_PROC(glMap2xOES,                     loader);
OPENGL_LOAD_PROC(glMapGrid1xOES,                 loader);
OPENGL_LOAD_PROC(glMapGrid2xOES,                 loader);
OPENGL_LOAD_PROC(glMultTransposeMatrixxOES,      loader);
OPENGL_LOAD_PROC(glMultiTexCoord1xOES,           loader);
OPENGL_LOAD_PROC(glMultiTexCoord1xvOES,          loader);
OPENGL_LOAD_PROC(glMultiTexCoord2xOES,           loader);
OPENGL_LOAD_PROC(glMultiTexCoord2xvOES,          loader);
OPENGL_LOAD_PROC(glMultiTexCoord3xOES,           loader);
OPENGL_LOAD_PROC(glMultiTexCoord3xvOES,          loader);
OPENGL_LOAD_PROC(glMultiTexCoord4xvOES,          loader);
OPENGL_LOAD_PROC(glNormal3xvOES,                 loader);
OPENGL_LOAD_PROC(glPassThroughxOES,              loader);
OPENGL_LOAD_PROC(glPixelMapx,                    loader);
OPENGL_LOAD_PROC(glPixelStorex,                  loader);
OPENGL_LOAD_PROC(glPixelTransferxOES,            loader);
OPENGL_LOAD_PROC(glPixelZoomxOES,                loader);
OPENGL_LOAD_PROC(glPrioritizeTexturesxOES,       loader);
OPENGL_LOAD_PROC(glRasterPos2xOES,               loader);
OPENGL_LOAD_PROC(glRasterPos2xvOES,              loader);
OPENGL_LOAD_PROC(glRasterPos3xOES,               loader);
OPENGL_LOAD_PROC(glRasterPos3xvOES,              loader);
OPENGL_LOAD_PROC(glRasterPos4xOES,               loader);
OPENGL_LOAD_PROC(glRasterPos4xvOES,              loader);
OPENGL_LOAD_PROC(glRectxOES,                     loader);
OPENGL_LOAD_PROC(glRectxvOES,                    loader);
OPENGL_LOAD_PROC(glTexCoord1xOES,                loader);
OPENGL_LOAD_PROC(glTexCoord1xvOES,               loader);
OPENGL_LOAD_PROC(glTexCoord2xOES,                loader);
OPENGL_LOAD_PROC(glTexCoord2xvOES,               loader);
OPENGL_LOAD_PROC(glTexCoord3xOES,                loader);
OPENGL_LOAD_PROC(glTexCoord3xvOES,               loader);
OPENGL_LOAD_PROC(glTexCoord4xOES,                loader);
OPENGL_LOAD_PROC(glTexCoord4xvOES,               loader);
OPENGL_LOAD_PROC(glTexGenxOES,                   loader);
OPENGL_LOAD_PROC(glTexGenxvOES,                  loader);
OPENGL_LOAD_PROC(glVertex2xOES,                  loader);
OPENGL_LOAD_PROC(glVertex2xvOES,                 loader);
OPENGL_LOAD_PROC(glVertex3xOES,                  loader);
OPENGL_LOAD_PROC(glVertex3xvOES,                 loader);
OPENGL_LOAD_PROC(glVertex4xOES,                  loader);
OPENGL_LOAD_PROC(glVertex4xvOES,                 loader));
#endif // OPENGL_INCLUDE_GL_OES_fixed_point

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_OES_query_matrix)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_OES_query_matrix,
OPENGL_LOAD_PROC(glQueryMatrixxOES, loader));
#endif // OPENGL_INCLUDE_GL_OES_query_matrix

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_OES_single_precision)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_OES_single_precision,
OPENGL_LOAD_PROC(glClearDepthfOES,   loader);
OPENGL_LOAD_PROC(glClipPlanefOES,    loader);
OPENGL_LOAD_PROC(glDepthRangefOES,   loader);
OPENGL_LOAD_PROC(glFrustumfOES,      loader);
OPENGL_LOAD_PROC(glGetClipPlanefOES, loader);
OPENGL_LOAD_PROC(glOrthofOES,        loader));
#endif // OPENGL_INCLUDE_GL_OES_single_precision

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_3DFX_tbuffer)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_3DFX_tbuffer,
OPENGL_LOAD_PROC(glTbufferMask3DFX, loader));
#endif // OPENGL_INCLUDE_GL_3DFX_tbuffer

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_AMD_debug_output)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_AMD_debug_output,
OPENGL_LOAD_PROC(glDebugMessageEnableAMD,   loader);
OPENGL_LOAD_PROC(glDebugMessageInsertAMD,   loader);
OPENGL_LOAD_PROC(glDebugMessageCallbackAMD, loader);
OPENGL_LOAD_PROC(glGetDebugMessageLogAMD,   loader));
#endif // OPENGL_INCLUDE_GL_AMD_debug_output

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_AMD_draw_buffers_blend)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_AMD_draw_buffers_blend,
OPENGL_LOAD_PROC(glBlendFuncIndexedAMD,             loader);
OPENGL_LOAD_PROC(glBlendFuncSeparateIndexedAMD,     loader);
OPENGL_LOAD_PROC(glBlendEquationIndexedAMD,         loader);
OPENGL_LOAD_PROC(glBlendEquationSeparateIndexedAMD, loader));
#endif // OPENGL_INCLUDE_GL_AMD_draw_buffers_blend

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_AMD_framebuffer_multisample_advanced)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_AMD_framebuffer_multisample_advanced,
OPENGL_LOAD_PROC(glRenderbufferStorageMultisampleAdvancedAMD,      loader);
OPENGL_LOAD_PROC(glNamedRenderbufferStorageMultisampleAdvancedAMD, loader));
#endif // OPENGL_INCLUDE_GL_AMD_framebuffer_multisample_advanced

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_AMD_framebuffer_sample_positions)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_AMD_framebuffer_sample_positions,
OPENGL_LOAD_PROC(glFramebufferSamplePositionsfvAMD,      loader);
OPENGL_LOAD_PROC(glNamedFramebufferSamplePositionsfvAMD, loader);
OPENGL_LOAD_PROC(glGetFramebufferParameterfvAMD,         loader);
OPENGL_LOAD_PROC(glGetNamedFramebufferParameterfvAMD,    loader));
#endif // OPENGL_INCLUDE_GL_AMD_framebuffer_sample_positions

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_AMD_gpu_shader_int64)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_AMD_gpu_shader_int64,
OPENGL_LOAD_PROC(glUniform1i64NV,          loader);
OPENGL_LOAD_PROC(glUniform2i64NV,          loader);
OPENGL_LOAD_PROC(glUniform3i64NV,          loader);
OPENGL_LOAD_PROC(glUniform4i64NV,          loader);
OPENGL_LOAD_PROC(glUniform1i64vNV,         loader);
OPENGL_LOAD_PROC(glUniform2i64vNV,         loader);
OPENGL_LOAD_PROC(glUniform3i64vNV,         loader);
OPENGL_LOAD_PROC(glUniform4i64vNV,         loader);
OPENGL_LOAD_PROC(glUniform1ui64NV,         loader);
OPENGL_LOAD_PROC(glUniform2ui64NV,         loader);
OPENGL_LOAD_PROC(glUniform3ui64NV,         loader);
OPENGL_LOAD_PROC(glUniform4ui64NV,         loader);
OPENGL_LOAD_PROC(glUniform1ui64vNV,        loader);
OPENGL_LOAD_PROC(glUniform2ui64vNV,        loader);
OPENGL_LOAD_PROC(glUniform3ui64vNV,        loader);
OPENGL_LOAD_PROC(glUniform4ui64vNV,        loader);
OPENGL_LOAD_PROC(glGetUniformi64vNV,       loader);
OPENGL_LOAD_PROC(glGetUniformui64vNV,      loader);
OPENGL_LOAD_PROC(glProgramUniform1i64NV,   loader);
OPENGL_LOAD_PROC(glProgramUniform2i64NV,   loader);
OPENGL_LOAD_PROC(glProgramUniform3i64NV,   loader);
OPENGL_LOAD_PROC(glProgramUniform4i64NV,   loader);
OPENGL_LOAD_PROC(glProgramUniform1i64vNV,  loader);
OPENGL_LOAD_PROC(glProgramUniform2i64vNV,  loader);
OPENGL_LOAD_PROC(glProgramUniform3i64vNV,  loader);
OPENGL_LOAD_PROC(glProgramUniform4i64vNV,  loader);
OPENGL_LOAD_PROC(glProgramUniform1ui64NV,  loader);
OPENGL_LOAD_PROC(glProgramUniform2ui64NV,  loader);
OPENGL_LOAD_PROC(glProgramUniform3ui64NV,  loader);
OPENGL_LOAD_PROC(glProgramUniform4ui64NV,  loader);
OPENGL_LOAD_PROC(glProgramUniform1ui64vNV, loader);
OPENGL_LOAD_PROC(glProgramUniform2ui64vNV, loader);
OPENGL_LOAD_PROC(glProgramUniform3ui64vNV, loader);
OPENGL_LOAD_PROC(glProgramUniform4ui64vNV, loader));
#endif // OPENGL_INCLUDE_GL_AMD_gpu_shader_int64

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_AMD_interleaved_elements)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_AMD_interleaved_elements,
OPENGL_LOAD_PROC(glVertexAttribParameteriAMD, loader));
#endif // OPENGL_INCLUDE_GL_AMD_interleaved_elements

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_AMD_multi_draw_indirect)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_AMD_multi_draw_indirect,
OPENGL_LOAD_PROC(glMultiDrawArraysIndirectAMD,   loader);
OPENGL_LOAD_PROC(glMultiDrawElementsIndirectAMD, loader));
#endif // OPENGL_INCLUDE_GL_AMD_multi_draw_indirect

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_AMD_name_gen_delete)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_AMD_name_gen_delete,
OPENGL_LOAD_PROC(glGenNamesAMD,    loader);
OPENGL_LOAD_PROC(glDeleteNamesAMD, loader);
OPENGL_LOAD_PROC(glIsNameAMD,      loader));
#endif // OPENGL_INCLUDE_GL_AMD_name_gen_delete

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_AMD_occlusion_query_event)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_AMD_occlusion_query_event,
OPENGL_LOAD_PROC(glQueryObjectParameteruiAMD, loader));
#endif // OPENGL_INCLUDE_GL_AMD_occlusion_query_event

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_AMD_performance_monitor)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_AMD_performance_monitor,
OPENGL_LOAD_PROC(glGetPerfMonitorGroupsAMD,        loader);
OPENGL_LOAD_PROC(glGetPerfMonitorCountersAMD,      loader);
OPENGL_LOAD_PROC(glGetPerfMonitorGroupStringAMD,   loader);
OPENGL_LOAD_PROC(glGetPerfMonitorCounterStringAMD, loader);
OPENGL_LOAD_PROC(glGetPerfMonitorCounterInfoAMD,   loader);
OPENGL_LOAD_PROC(glGenPerfMonitorsAMD,             loader);
OPENGL_LOAD_PROC(glDeletePerfMonitorsAMD,          loader);
OPENGL_LOAD_PROC(glSelectPerfMonitorCountersAMD,   loader);
OPENGL_LOAD_PROC(glBeginPerfMonitorAMD,            loader);
OPENGL_LOAD_PROC(glEndPerfMonitorAMD,              loader);
OPENGL_LOAD_PROC(glGetPerfMonitorCounterDataAMD,   loader));
#endif // OPENGL_INCLUDE_GL_AMD_performance_monitor

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_AMD_sample_positions)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_AMD_sample_positions,
OPENGL_LOAD_PROC(glSetMultisamplefvAMD, loader));
#endif // OPENGL_INCLUDE_GL_AMD_sample_positions

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_AMD_sparse_texture)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_AMD_sparse_texture,
OPENGL_LOAD_PROC(glTexStorageSparseAMD,     loader);
OPENGL_LOAD_PROC(glTextureStorageSparseAMD, loader));
#endif // OPENGL_INCLUDE_GL_AMD_sparse_texture

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_AMD_stencil_operation_extended)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_AMD_stencil_operation_extended,
OPENGL_LOAD_PROC(glStencilOpValueAMD, loader));
#endif // OPENGL_INCLUDE_GL_AMD_stencil_operation_extended

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_AMD_vertex_shader_tessellator)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_AMD_vertex_shader_tessellator,
OPENGL_LOAD_PROC(glTessellationFactorAMD, loader);
OPENGL_LOAD_PROC(glTessellationModeAMD,   loader));
#endif // OPENGL_INCLUDE_GL_AMD_vertex_shader_tessellator

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_APPLE_element_array)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_APPLE_element_array,
OPENGL_LOAD_PROC(glElementPointerAPPLE,             loader);
OPENGL_LOAD_PROC(glDrawElementArrayAPPLE,           loader);
OPENGL_LOAD_PROC(glDrawRangeElementArrayAPPLE,      loader);
OPENGL_LOAD_PROC(glMultiDrawElementArrayAPPLE,      loader);
OPENGL_LOAD_PROC(glMultiDrawRangeElementArrayAPPLE, loader));
#endif // OPENGL_INCLUDE_GL_APPLE_element_array

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_APPLE_fence)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_APPLE_fence,
OPENGL_LOAD_PROC(glGenFencesAPPLE,    loader);
OPENGL_LOAD_PROC(glDeleteFencesAPPLE, loader);
OPENGL_LOAD_PROC(glSetFenceAPPLE,     loader);
OPENGL_LOAD_PROC(glIsFenceAPPLE,      loader);
OPENGL_LOAD_PROC(glTestFenceAPPLE,    loader);
OPENGL_LOAD_PROC(glFinishFenceAPPLE,  loader);
OPENGL_LOAD_PROC(glTestObjectAPPLE,   loader);
OPENGL_LOAD_PROC(glFinishObjectAPPLE, loader));
#endif // OPENGL_INCLUDE_GL_APPLE_fence

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_APPLE_flush_buffer_range)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_APPLE_flush_buffer_range,
OPENGL_LOAD_PROC(glBufferParameteriAPPLE,       loader);
OPENGL_LOAD_PROC(glFlushMappedBufferRangeAPPLE, loader));
#endif // OPENGL_INCLUDE_GL_APPLE_flush_buffer_range

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_APPLE_object_purgeable)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_APPLE_object_purgeable,
OPENGL_LOAD_PROC(glObjectPurgeableAPPLE,      loader);
OPENGL_LOAD_PROC(glObjectUnpurgeableAPPLE,    loader);
OPENGL_LOAD_PROC(glGetObjectParameterivAPPLE, loader));
#endif // OPENGL_INCLUDE_GL_APPLE_object_purgeable

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_APPLE_texture_range)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_APPLE_texture_range,
OPENGL_LOAD_PROC(glTextureRangeAPPLE,            loader);
OPENGL_LOAD_PROC(glGetTexParameterPointervAPPLE, loader));
#endif // OPENGL_INCLUDE_GL_APPLE_texture_range

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_APPLE_vertex_array_object)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_APPLE_vertex_array_object,
OPENGL_LOAD_PROC(glBindVertexArrayAPPLE,    loader);
OPENGL_LOAD_PROC(glDeleteVertexArraysAPPLE, loader);
OPENGL_LOAD_PROC(glGenVertexArraysAPPLE,    loader);
OPENGL_LOAD_PROC(glIsVertexArrayAPPLE,      loader));
#endif // OPENGL_INCLUDE_GL_APPLE_vertex_array_object

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_APPLE_vertex_array_range)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_APPLE_vertex_array_range,
OPENGL_LOAD_PROC(glVertexArrayRangeAPPLE,      loader);
OPENGL_LOAD_PROC(glFlushVertexArrayRangeAPPLE, loader);
OPENGL_LOAD_PROC(glVertexArrayParameteriAPPLE, loader));
#endif // OPENGL_INCLUDE_GL_APPLE_vertex_array_range

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_APPLE_vertex_program_evaluators)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_APPLE_vertex_program_evaluators,
OPENGL_LOAD_PROC(glEnableVertexAttribAPPLE,    loader);
OPENGL_LOAD_PROC(glDisableVertexAttribAPPLE,   loader);
OPENGL_LOAD_PROC(glIsVertexAttribEnabledAPPLE, loader);
OPENGL_LOAD_PROC(glMapVertexAttrib1dAPPLE,     loader);
OPENGL_LOAD_PROC(glMapVertexAttrib1fAPPLE,     loader);
OPENGL_LOAD_PROC(glMapVertexAttrib2dAPPLE,     loader);
OPENGL_LOAD_PROC(glMapVertexAttrib2fAPPLE,     loader));
#endif // OPENGL_INCLUDE_GL_APPLE_vertex_program_evaluators

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ATI_draw_buffers)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ATI_draw_buffers,
OPENGL_LOAD_PROC(glDrawBuffersATI, loader));
#endif // OPENGL_INCLUDE_GL_ATI_draw_buffers

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ATI_element_array)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ATI_element_array,
OPENGL_LOAD_PROC(glElementPointerATI,        loader);
OPENGL_LOAD_PROC(glDrawElementArrayATI,      loader);
OPENGL_LOAD_PROC(glDrawRangeElementArrayATI, loader));
#endif // OPENGL_INCLUDE_GL_ATI_element_array

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ATI_envmap_bumpmap)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ATI_envmap_bumpmap,
OPENGL_LOAD_PROC(glTexBumpParameterivATI,    loader);
OPENGL_LOAD_PROC(glTexBumpParameterfvATI,    loader);
OPENGL_LOAD_PROC(glGetTexBumpParameterivATI, loader);
OPENGL_LOAD_PROC(glGetTexBumpParameterfvATI, loader));
#endif // OPENGL_INCLUDE_GL_ATI_envmap_bumpmap

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ATI_fragment_shader)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ATI_fragment_shader,
OPENGL_LOAD_PROC(glGenFragmentShadersATI,        loader);
OPENGL_LOAD_PROC(glBindFragmentShaderATI,        loader);
OPENGL_LOAD_PROC(glDeleteFragmentShaderATI,      loader);
OPENGL_LOAD_PROC(glBeginFragmentShaderATI,       loader);
OPENGL_LOAD_PROC(glEndFragmentShaderATI,         loader);
OPENGL_LOAD_PROC(glPassTexCoordATI,              loader);
OPENGL_LOAD_PROC(glSampleMapATI,                 loader);
OPENGL_LOAD_PROC(glColorFragmentOp1ATI,          loader);
OPENGL_LOAD_PROC(glColorFragmentOp2ATI,          loader);
OPENGL_LOAD_PROC(glColorFragmentOp3ATI,          loader);
OPENGL_LOAD_PROC(glAlphaFragmentOp1ATI,          loader);
OPENGL_LOAD_PROC(glAlphaFragmentOp2ATI,          loader);
OPENGL_LOAD_PROC(glAlphaFragmentOp3ATI,          loader);
OPENGL_LOAD_PROC(glSetFragmentShaderConstantATI, loader));
#endif // OPENGL_INCLUDE_GL_ATI_fragment_shader

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ATI_map_object_buffer)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ATI_map_object_buffer,
OPENGL_LOAD_PROC(glMapObjectBufferATI,   loader);
OPENGL_LOAD_PROC(glUnmapObjectBufferATI, loader));
#endif // OPENGL_INCLUDE_GL_ATI_map_object_buffer

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ATI_pn_triangles)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ATI_pn_triangles,
OPENGL_LOAD_PROC(glPNTrianglesiATI, loader);
OPENGL_LOAD_PROC(glPNTrianglesfATI, loader));
#endif // OPENGL_INCLUDE_GL_ATI_pn_triangles

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ATI_separate_stencil)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ATI_separate_stencil,
OPENGL_LOAD_PROC(glStencilOpSeparateATI,   loader);
OPENGL_LOAD_PROC(glStencilFuncSeparateATI, loader));
#endif // OPENGL_INCLUDE_GL_ATI_separate_stencil

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ATI_vertex_array_object)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ATI_vertex_array_object,
OPENGL_LOAD_PROC(glNewObjectBufferATI,         loader);
OPENGL_LOAD_PROC(glIsObjectBufferATI,          loader);
OPENGL_LOAD_PROC(glUpdateObjectBufferATI,      loader);
OPENGL_LOAD_PROC(glGetObjectBufferfvATI,       loader);
OPENGL_LOAD_PROC(glGetObjectBufferivATI,       loader);
OPENGL_LOAD_PROC(glFreeObjectBufferATI,        loader);
OPENGL_LOAD_PROC(glArrayObjectATI,             loader);
OPENGL_LOAD_PROC(glGetArrayObjectfvATI,        loader);
OPENGL_LOAD_PROC(glGetArrayObjectivATI,        loader);
OPENGL_LOAD_PROC(glVariantArrayObjectATI,      loader);
OPENGL_LOAD_PROC(glGetVariantArrayObjectfvATI, loader);
OPENGL_LOAD_PROC(glGetVariantArrayObjectivATI, loader));
#endif // OPENGL_INCLUDE_GL_ATI_vertex_array_object

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ATI_vertex_attrib_array_object)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ATI_vertex_attrib_array_object,
OPENGL_LOAD_PROC(glVertexAttribArrayObjectATI,      loader);
OPENGL_LOAD_PROC(glGetVertexAttribArrayObjectfvATI, loader);
OPENGL_LOAD_PROC(glGetVertexAttribArrayObjectivATI, loader));
#endif // OPENGL_INCLUDE_GL_ATI_vertex_attrib_array_object

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_ATI_vertex_streams)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_ATI_vertex_streams,
OPENGL_LOAD_PROC(glVertexStream1sATI,           loader);
OPENGL_LOAD_PROC(glVertexStream1svATI,          loader);
OPENGL_LOAD_PROC(glVertexStream1iATI,           loader);
OPENGL_LOAD_PROC(glVertexStream1ivATI,          loader);
OPENGL_LOAD_PROC(glVertexStream1fATI,           loader);
OPENGL_LOAD_PROC(glVertexStream1fvATI,          loader);
OPENGL_LOAD_PROC(glVertexStream1dATI,           loader);
OPENGL_LOAD_PROC(glVertexStream1dvATI,          loader);
OPENGL_LOAD_PROC(glVertexStream2sATI,           loader);
OPENGL_LOAD_PROC(glVertexStream2svATI,          loader);
OPENGL_LOAD_PROC(glVertexStream2iATI,           loader);
OPENGL_LOAD_PROC(glVertexStream2ivATI,          loader);
OPENGL_LOAD_PROC(glVertexStream2fATI,           loader);
OPENGL_LOAD_PROC(glVertexStream2fvATI,          loader);
OPENGL_LOAD_PROC(glVertexStream2dATI,           loader);
OPENGL_LOAD_PROC(glVertexStream2dvATI,          loader);
OPENGL_LOAD_PROC(glVertexStream3sATI,           loader);
OPENGL_LOAD_PROC(glVertexStream3svATI,          loader);
OPENGL_LOAD_PROC(glVertexStream3iATI,           loader);
OPENGL_LOAD_PROC(glVertexStream3ivATI,          loader);
OPENGL_LOAD_PROC(glVertexStream3fATI,           loader);
OPENGL_LOAD_PROC(glVertexStream3fvATI,          loader);
OPENGL_LOAD_PROC(glVertexStream3dATI,           loader);
OPENGL_LOAD_PROC(glVertexStream3dvATI,          loader);
OPENGL_LOAD_PROC(glVertexStream4sATI,           loader);
OPENGL_LOAD_PROC(glVertexStream4svATI,          loader);
OPENGL_LOAD_PROC(glVertexStream4iATI,           loader);
OPENGL_LOAD_PROC(glVertexStream4ivATI,          loader);
OPENGL_LOAD_PROC(glVertexStream4fATI,           loader);
OPENGL_LOAD_PROC(glVertexStream4fvATI,          loader);
OPENGL_LOAD_PROC(glVertexStream4dATI,           loader);
OPENGL_LOAD_PROC(glVertexStream4dvATI,          loader);
OPENGL_LOAD_PROC(glNormalStream3bATI,           loader);
OPENGL_LOAD_PROC(glNormalStream3bvATI,          loader);
OPENGL_LOAD_PROC(glNormalStream3sATI,           loader);
OPENGL_LOAD_PROC(glNormalStream3svATI,          loader);
OPENGL_LOAD_PROC(glNormalStream3iATI,           loader);
OPENGL_LOAD_PROC(glNormalStream3ivATI,          loader);
OPENGL_LOAD_PROC(glNormalStream3fATI,           loader);
OPENGL_LOAD_PROC(glNormalStream3fvATI,          loader);
OPENGL_LOAD_PROC(glNormalStream3dATI,           loader);
OPENGL_LOAD_PROC(glNormalStream3dvATI,          loader);
OPENGL_LOAD_PROC(glClientActiveVertexStreamATI, loader);
OPENGL_LOAD_PROC(glVertexBlendEnviATI,          loader);
OPENGL_LOAD_PROC(glVertexBlendEnvfATI,          loader));
#endif // OPENGL_INCLUDE_GL_ATI_vertex_streams

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_EGL_image_storage)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_EGL_image_storage,
OPENGL_LOAD_PROC(glEGLImageTargetTexStorageEXT,     loader);
OPENGL_LOAD_PROC(glEGLImageTargetTextureStorageEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_EGL_image_storage

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_bindable_uniform)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_bindable_uniform,
OPENGL_LOAD_PROC(glUniformBufferEXT,        loader);
OPENGL_LOAD_PROC(glGetUniformBufferSizeEXT, loader);
OPENGL_LOAD_PROC(glGetUniformOffsetEXT,     loader));
#endif // OPENGL_INCLUDE_GL_EXT_bindable_uniform

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_blend_color)
OPENGL_CREATE_GL_EXTENSION_LOADER(
_GL_EXT_blend_color,
OPENGL_LOAD_PROC(glBlendColorEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_blend_color

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_blend_equation_separate)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_blend_equation_separate,
OPENGL_LOAD_PROC(glBlendEquationSeparateEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_blend_equation_separate

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_blend_func_separate)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_blend_func_separate,
OPENGL_LOAD_PROC(glBlendFuncSeparateEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_blend_func_separate

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_blend_minmax)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_blend_minmax,
OPENGL_LOAD_PROC(glBlendEquationEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_blend_minmax

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_color_subtable)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_color_subtable,
OPENGL_LOAD_PROC(glColorSubTableEXT,     loader);
OPENGL_LOAD_PROC(glCopyColorSubTableEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_color_subtable

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_compiled_vertex_array)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_compiled_vertex_array,
OPENGL_LOAD_PROC(glLockArraysEXT,   loader);
OPENGL_LOAD_PROC(glUnlockArraysEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_compiled_vertex_array

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_convolution)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_convolution,
OPENGL_LOAD_PROC(glConvolutionFilter1DEXT,       loader);
OPENGL_LOAD_PROC(glConvolutionFilter2DEXT,       loader);
OPENGL_LOAD_PROC(glConvolutionParameterfEXT,     loader);
OPENGL_LOAD_PROC(glConvolutionParameterfvEXT,    loader);
OPENGL_LOAD_PROC(glConvolutionParameteriEXT,     loader);
OPENGL_LOAD_PROC(glConvolutionParameterivEXT,    loader);
OPENGL_LOAD_PROC(glCopyConvolutionFilter1DEXT,   loader);
OPENGL_LOAD_PROC(glCopyConvolutionFilter2DEXT,   loader);
OPENGL_LOAD_PROC(glGetConvolutionFilterEXT,      loader);
OPENGL_LOAD_PROC(glGetConvolutionParameterfvEXT, loader);
OPENGL_LOAD_PROC(glGetConvolutionParameterivEXT, loader);
OPENGL_LOAD_PROC(glGetSeparableFilterEXT,        loader);
OPENGL_LOAD_PROC(glSeparableFilter2DEXT,         loader));
#endif // OPENGL_INCLUDE_GL_EXT_convolution

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_coordinate_frame)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_coordinate_frame,
OPENGL_LOAD_PROC(glTangent3bEXT,       loader);
OPENGL_LOAD_PROC(glTangent3bvEXT,      loader);
OPENGL_LOAD_PROC(glTangent3dEXT,       loader);
OPENGL_LOAD_PROC(glTangent3dvEXT,      loader);
OPENGL_LOAD_PROC(glTangent3fEXT,       loader);
OPENGL_LOAD_PROC(glTangent3fvEXT,      loader);
OPENGL_LOAD_PROC(glTangent3iEXT,       loader);
OPENGL_LOAD_PROC(glTangent3ivEXT,      loader);
OPENGL_LOAD_PROC(glTangent3sEXT,       loader);
OPENGL_LOAD_PROC(glTangent3svEXT,      loader);
OPENGL_LOAD_PROC(glBinormal3bEXT,      loader);
OPENGL_LOAD_PROC(glBinormal3bvEXT,     loader);
OPENGL_LOAD_PROC(glBinormal3dEXT,      loader);
OPENGL_LOAD_PROC(glBinormal3dvEXT,     loader);
OPENGL_LOAD_PROC(glBinormal3fEXT,      loader);
OPENGL_LOAD_PROC(glBinormal3fvEXT,     loader);
OPENGL_LOAD_PROC(glBinormal3iEXT,      loader);
OPENGL_LOAD_PROC(glBinormal3ivEXT,     loader);
OPENGL_LOAD_PROC(glBinormal3sEXT,      loader);
OPENGL_LOAD_PROC(glBinormal3svEXT,     loader);
OPENGL_LOAD_PROC(glTangentPointerEXT,  loader);
OPENGL_LOAD_PROC(glBinormalPointerEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_coordinate_frame

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_copy_texture)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_copy_texture,
OPENGL_LOAD_PROC(glCopyTexImage1DEXT,    loader);
OPENGL_LOAD_PROC(glCopyTexImage2DEXT,    loader);
OPENGL_LOAD_PROC(glCopyTexSubImage1DEXT, loader);
OPENGL_LOAD_PROC(glCopyTexSubImage2DEXT, loader);
OPENGL_LOAD_PROC(glCopyTexSubImage3DEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_copy_texture

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_cull_vertex)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_cull_vertex,
OPENGL_LOAD_PROC(glCullParameterdvEXT, loader);
OPENGL_LOAD_PROC(glCullParameterfvEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_cull_vertex

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_debug_label)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_debug_label,
OPENGL_LOAD_PROC(glLabelObjectEXT,    loader);
OPENGL_LOAD_PROC(glGetObjectLabelEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_debug_label

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_debug_marker)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_debug_marker,
OPENGL_LOAD_PROC(glInsertEventMarkerEXT, loader);
OPENGL_LOAD_PROC(glPushGroupMarkerEXT,   loader);
OPENGL_LOAD_PROC(glPopGroupMarkerEXT,    loader));
#endif // OPENGL_INCLUDE_GL_EXT_debug_marker

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_depth_bounds_test)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_depth_bounds_test,
OPENGL_LOAD_PROC(glDepthBoundsEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_depth_bounds_test

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_direct_state_access)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_direct_state_access,
OPENGL_LOAD_PROC(glMatrixLoadfEXT,                                 loader);
OPENGL_LOAD_PROC(glMatrixLoaddEXT,                                 loader);
OPENGL_LOAD_PROC(glMatrixMultfEXT,                                 loader);
OPENGL_LOAD_PROC(glMatrixMultdEXT,                                 loader);
OPENGL_LOAD_PROC(glMatrixLoadIdentityEXT,                          loader);
OPENGL_LOAD_PROC(glMatrixRotatefEXT,                               loader);
OPENGL_LOAD_PROC(glMatrixRotatedEXT,                               loader);
OPENGL_LOAD_PROC(glMatrixScalefEXT,                                loader);
OPENGL_LOAD_PROC(glMatrixScaledEXT,                                loader);
OPENGL_LOAD_PROC(glMatrixTranslatefEXT,                            loader);
OPENGL_LOAD_PROC(glMatrixTranslatedEXT,                            loader);
OPENGL_LOAD_PROC(glMatrixFrustumEXT,                               loader);
OPENGL_LOAD_PROC(glMatrixOrthoEXT,                                 loader);
OPENGL_LOAD_PROC(glMatrixPopEXT,                                   loader);
OPENGL_LOAD_PROC(glMatrixPushEXT,                                  loader);
OPENGL_LOAD_PROC(glClientAttribDefaultEXT,                         loader);
OPENGL_LOAD_PROC(glPushClientAttribDefaultEXT,                     loader);
OPENGL_LOAD_PROC(glTextureParameterfEXT,                           loader);
OPENGL_LOAD_PROC(glTextureParameterfvEXT,                          loader);
OPENGL_LOAD_PROC(glTextureParameteriEXT,                           loader);
OPENGL_LOAD_PROC(glTextureParameterivEXT,                          loader);
OPENGL_LOAD_PROC(glTextureImage1DEXT,                              loader);
OPENGL_LOAD_PROC(glTextureImage2DEXT,                              loader);
OPENGL_LOAD_PROC(glTextureSubImage1DEXT,                           loader);
OPENGL_LOAD_PROC(glTextureSubImage2DEXT,                           loader);
OPENGL_LOAD_PROC(glCopyTextureImage1DEXT,                          loader);
OPENGL_LOAD_PROC(glCopyTextureImage2DEXT,                          loader);
OPENGL_LOAD_PROC(glCopyTextureSubImage1DEXT,                       loader);
OPENGL_LOAD_PROC(glCopyTextureSubImage2DEXT,                       loader);
OPENGL_LOAD_PROC(glGetTextureImageEXT,                             loader);
OPENGL_LOAD_PROC(glGetTextureParameterfvEXT,                       loader);
OPENGL_LOAD_PROC(glGetTextureParameterivEXT,                       loader);
OPENGL_LOAD_PROC(glGetTextureLevelParameterfvEXT,                  loader);
OPENGL_LOAD_PROC(glGetTextureLevelParameterivEXT,                  loader);
OPENGL_LOAD_PROC(glTextureImage3DEXT,                              loader);
OPENGL_LOAD_PROC(glTextureSubImage3DEXT,                           loader);
OPENGL_LOAD_PROC(glCopyTextureSubImage3DEXT,                       loader);
OPENGL_LOAD_PROC(glBindMultiTextureEXT,                            loader);
OPENGL_LOAD_PROC(glMultiTexCoordPointerEXT,                        loader);
OPENGL_LOAD_PROC(glMultiTexEnvfEXT,                                loader);
OPENGL_LOAD_PROC(glMultiTexEnvfvEXT,                               loader);
OPENGL_LOAD_PROC(glMultiTexEnviEXT,                                loader);
OPENGL_LOAD_PROC(glMultiTexEnvivEXT,                               loader);
OPENGL_LOAD_PROC(glMultiTexGendEXT,                                loader);
OPENGL_LOAD_PROC(glMultiTexGendvEXT,                               loader);
OPENGL_LOAD_PROC(glMultiTexGenfEXT,                                loader);
OPENGL_LOAD_PROC(glMultiTexGenfvEXT,                               loader);
OPENGL_LOAD_PROC(glMultiTexGeniEXT,                                loader);
OPENGL_LOAD_PROC(glMultiTexGenivEXT,                               loader);
OPENGL_LOAD_PROC(glGetMultiTexEnvfvEXT,                            loader);
OPENGL_LOAD_PROC(glGetMultiTexEnvivEXT,                            loader);
OPENGL_LOAD_PROC(glGetMultiTexGendvEXT,                            loader);
OPENGL_LOAD_PROC(glGetMultiTexGenfvEXT,                            loader);
OPENGL_LOAD_PROC(glGetMultiTexGenivEXT,                            loader);
OPENGL_LOAD_PROC(glMultiTexParameteriEXT,                          loader);
OPENGL_LOAD_PROC(glMultiTexParameterivEXT,                         loader);
OPENGL_LOAD_PROC(glMultiTexParameterfEXT,                          loader);
OPENGL_LOAD_PROC(glMultiTexParameterfvEXT,                         loader);
OPENGL_LOAD_PROC(glMultiTexImage1DEXT,                             loader);
OPENGL_LOAD_PROC(glMultiTexImage2DEXT,                             loader);
OPENGL_LOAD_PROC(glMultiTexSubImage1DEXT,                          loader);
OPENGL_LOAD_PROC(glMultiTexSubImage2DEXT,                          loader);
OPENGL_LOAD_PROC(glCopyMultiTexImage1DEXT,                         loader);
OPENGL_LOAD_PROC(glCopyMultiTexImage2DEXT,                         loader);
OPENGL_LOAD_PROC(glCopyMultiTexSubImage1DEXT,                      loader);
OPENGL_LOAD_PROC(glCopyMultiTexSubImage2DEXT,                      loader);
OPENGL_LOAD_PROC(glGetMultiTexImageEXT,                            loader);
OPENGL_LOAD_PROC(glGetMultiTexParameterfvEXT,                      loader);
OPENGL_LOAD_PROC(glGetMultiTexParameterivEXT,                      loader);
OPENGL_LOAD_PROC(glGetMultiTexLevelParameterfvEXT,                 loader);
OPENGL_LOAD_PROC(glGetMultiTexLevelParameterivEXT,                 loader);
OPENGL_LOAD_PROC(glMultiTexImage3DEXT,                             loader);
OPENGL_LOAD_PROC(glMultiTexSubImage3DEXT,                          loader);
OPENGL_LOAD_PROC(glCopyMultiTexSubImage3DEXT,                      loader);
OPENGL_LOAD_PROC(glEnableClientStateIndexedEXT,                    loader);
OPENGL_LOAD_PROC(glDisableClientStateIndexedEXT,                   loader);
OPENGL_LOAD_PROC(glGetFloatIndexedvEXT,                            loader);
OPENGL_LOAD_PROC(glGetDoubleIndexedvEXT,                           loader);
OPENGL_LOAD_PROC(glGetPointerIndexedvEXT,                          loader);
OPENGL_LOAD_PROC(glEnableIndexedEXT,                               loader);
OPENGL_LOAD_PROC(glDisableIndexedEXT,                              loader);
OPENGL_LOAD_PROC(glIsEnabledIndexedEXT,                            loader);
OPENGL_LOAD_PROC(glGetIntegerIndexedvEXT,                          loader);
OPENGL_LOAD_PROC(glGetBooleanIndexedvEXT,                          loader);
OPENGL_LOAD_PROC(glCompressedTextureImage3DEXT,                    loader);
OPENGL_LOAD_PROC(glCompressedTextureImage2DEXT,                    loader);
OPENGL_LOAD_PROC(glCompressedTextureImage1DEXT,                    loader);
OPENGL_LOAD_PROC(glCompressedTextureSubImage3DEXT,                 loader);
OPENGL_LOAD_PROC(glCompressedTextureSubImage2DEXT,                 loader);
OPENGL_LOAD_PROC(glCompressedTextureSubImage1DEXT,                 loader);
OPENGL_LOAD_PROC(glGetCompressedTextureImageEXT,                   loader);
OPENGL_LOAD_PROC(glCompressedMultiTexImage3DEXT,                   loader);
OPENGL_LOAD_PROC(glCompressedMultiTexImage2DEXT,                   loader);
OPENGL_LOAD_PROC(glCompressedMultiTexImage1DEXT,                   loader);
OPENGL_LOAD_PROC(glCompressedMultiTexSubImage3DEXT,                loader);
OPENGL_LOAD_PROC(glCompressedMultiTexSubImage2DEXT,                loader);
OPENGL_LOAD_PROC(glCompressedMultiTexSubImage1DEXT,                loader);
OPENGL_LOAD_PROC(glGetCompressedMultiTexImageEXT,                  loader);
OPENGL_LOAD_PROC(glMatrixLoadTransposefEXT,                        loader);
OPENGL_LOAD_PROC(glMatrixLoadTransposedEXT,                        loader);
OPENGL_LOAD_PROC(glMatrixMultTransposefEXT,                        loader);
OPENGL_LOAD_PROC(glMatrixMultTransposedEXT,                        loader);
OPENGL_LOAD_PROC(glNamedBufferDataEXT,                             loader);
OPENGL_LOAD_PROC(glNamedBufferSubDataEXT,                          loader);
OPENGL_LOAD_PROC(glMapNamedBufferEXT,                              loader);
OPENGL_LOAD_PROC(glUnmapNamedBufferEXT,                            loader);
OPENGL_LOAD_PROC(glGetNamedBufferParameterivEXT,                   loader);
OPENGL_LOAD_PROC(glGetNamedBufferPointervEXT,                      loader);
OPENGL_LOAD_PROC(glGetNamedBufferSubDataEXT,                       loader);
OPENGL_LOAD_PROC(glProgramUniform1fEXT,                            loader);
OPENGL_LOAD_PROC(glProgramUniform2fEXT,                            loader);
OPENGL_LOAD_PROC(glProgramUniform3fEXT,                            loader);
OPENGL_LOAD_PROC(glProgramUniform4fEXT,                            loader);
OPENGL_LOAD_PROC(glProgramUniform1iEXT,                            loader);
OPENGL_LOAD_PROC(glProgramUniform2iEXT,                            loader);
OPENGL_LOAD_PROC(glProgramUniform3iEXT,                            loader);
OPENGL_LOAD_PROC(glProgramUniform4iEXT,                            loader);
OPENGL_LOAD_PROC(glProgramUniform1fvEXT,                           loader);
OPENGL_LOAD_PROC(glProgramUniform2fvEXT,                           loader);
OPENGL_LOAD_PROC(glProgramUniform3fvEXT,                           loader);
OPENGL_LOAD_PROC(glProgramUniform4fvEXT,                           loader);
OPENGL_LOAD_PROC(glProgramUniform1ivEXT,                           loader);
OPENGL_LOAD_PROC(glProgramUniform2ivEXT,                           loader);
OPENGL_LOAD_PROC(glProgramUniform3ivEXT,                           loader);
OPENGL_LOAD_PROC(glProgramUniform4ivEXT,                           loader);
OPENGL_LOAD_PROC(glProgramUniformMatrix2fvEXT,                     loader);
OPENGL_LOAD_PROC(glProgramUniformMatrix3fvEXT,                     loader);
OPENGL_LOAD_PROC(glProgramUniformMatrix4fvEXT,                     loader);
OPENGL_LOAD_PROC(glProgramUniformMatrix2x3fvEXT,                   loader);
OPENGL_LOAD_PROC(glProgramUniformMatrix3x2fvEXT,                   loader);
OPENGL_LOAD_PROC(glProgramUniformMatrix2x4fvEXT,                   loader);
OPENGL_LOAD_PROC(glProgramUniformMatrix4x2fvEXT,                   loader);
OPENGL_LOAD_PROC(glProgramUniformMatrix3x4fvEXT,                   loader);
OPENGL_LOAD_PROC(glProgramUniformMatrix4x3fvEXT,                   loader);
OPENGL_LOAD_PROC(glTextureBufferEXT,                               loader);
OPENGL_LOAD_PROC(glMultiTexBufferEXT,                              loader);
OPENGL_LOAD_PROC(glTextureParameterIivEXT,                         loader);
OPENGL_LOAD_PROC(glTextureParameterIuivEXT,                        loader);
OPENGL_LOAD_PROC(glGetTextureParameterIivEXT,                      loader);
OPENGL_LOAD_PROC(glGetTextureParameterIuivEXT,                     loader);
OPENGL_LOAD_PROC(glMultiTexParameterIivEXT,                        loader);
OPENGL_LOAD_PROC(glMultiTexParameterIuivEXT,                       loader);
OPENGL_LOAD_PROC(glGetMultiTexParameterIivEXT,                     loader);
OPENGL_LOAD_PROC(glGetMultiTexParameterIuivEXT,                    loader);
OPENGL_LOAD_PROC(glProgramUniform1uiEXT,                           loader);
OPENGL_LOAD_PROC(glProgramUniform2uiEXT,                           loader);
OPENGL_LOAD_PROC(glProgramUniform3uiEXT,                           loader);
OPENGL_LOAD_PROC(glProgramUniform4uiEXT,                           loader);
OPENGL_LOAD_PROC(glProgramUniform1uivEXT,                          loader);
OPENGL_LOAD_PROC(glProgramUniform2uivEXT,                          loader);
OPENGL_LOAD_PROC(glProgramUniform3uivEXT,                          loader);
OPENGL_LOAD_PROC(glProgramUniform4uivEXT,                          loader);
OPENGL_LOAD_PROC(glNamedProgramLocalParameters4fvEXT,              loader);
OPENGL_LOAD_PROC(glNamedProgramLocalParameterI4iEXT,               loader);
OPENGL_LOAD_PROC(glNamedProgramLocalParameterI4ivEXT,              loader);
OPENGL_LOAD_PROC(glNamedProgramLocalParametersI4ivEXT,             loader);
OPENGL_LOAD_PROC(glNamedProgramLocalParameterI4uiEXT,              loader);
OPENGL_LOAD_PROC(glNamedProgramLocalParameterI4uivEXT,             loader);
OPENGL_LOAD_PROC(glNamedProgramLocalParametersI4uivEXT,            loader);
OPENGL_LOAD_PROC(glGetNamedProgramLocalParameterIivEXT,            loader);
OPENGL_LOAD_PROC(glGetNamedProgramLocalParameterIuivEXT,           loader);
OPENGL_LOAD_PROC(glEnableClientStateiEXT,                          loader);
OPENGL_LOAD_PROC(glDisableClientStateiEXT,                         loader);
OPENGL_LOAD_PROC(glGetFloati_vEXT,                                 loader);
OPENGL_LOAD_PROC(glGetDoublei_vEXT,                                loader);
OPENGL_LOAD_PROC(glGetPointeri_vEXT,                               loader);
OPENGL_LOAD_PROC(glNamedProgramStringEXT,                          loader);
OPENGL_LOAD_PROC(glNamedProgramLocalParameter4dEXT,                loader);
OPENGL_LOAD_PROC(glNamedProgramLocalParameter4dvEXT,               loader);
OPENGL_LOAD_PROC(glNamedProgramLocalParameter4fEXT,                loader);
OPENGL_LOAD_PROC(glNamedProgramLocalParameter4fvEXT,               loader);
OPENGL_LOAD_PROC(glGetNamedProgramLocalParameterdvEXT,             loader);
OPENGL_LOAD_PROC(glGetNamedProgramLocalParameterfvEXT,             loader);
OPENGL_LOAD_PROC(glGetNamedProgramivEXT,                           loader);
OPENGL_LOAD_PROC(glGetNamedProgramStringEXT,                       loader);
OPENGL_LOAD_PROC(glNamedRenderbufferStorageEXT,                    loader);
OPENGL_LOAD_PROC(glGetNamedRenderbufferParameterivEXT,             loader);
OPENGL_LOAD_PROC(glNamedRenderbufferStorageMultisampleEXT,         loader);
OPENGL_LOAD_PROC(glNamedRenderbufferStorageMultisampleCoverageEXT, loader);
OPENGL_LOAD_PROC(glCheckNamedFramebufferStatusEXT,                 loader);
OPENGL_LOAD_PROC(glNamedFramebufferTexture1DEXT,                   loader);
OPENGL_LOAD_PROC(glNamedFramebufferTexture2DEXT,                   loader);
OPENGL_LOAD_PROC(glNamedFramebufferTexture3DEXT,                   loader);
OPENGL_LOAD_PROC(glNamedFramebufferRenderbufferEXT,                loader);
OPENGL_LOAD_PROC(glGetNamedFramebufferAttachmentParameterivEXT,    loader);
OPENGL_LOAD_PROC(glGenerateTextureMipmapEXT,                       loader);
OPENGL_LOAD_PROC(glGenerateMultiTexMipmapEXT,                      loader);
OPENGL_LOAD_PROC(glFramebufferDrawBufferEXT,                       loader);
OPENGL_LOAD_PROC(glFramebufferDrawBuffersEXT,                      loader);
OPENGL_LOAD_PROC(glFramebufferReadBufferEXT,                       loader);
OPENGL_LOAD_PROC(glGetFramebufferParameterivEXT,                   loader);
OPENGL_LOAD_PROC(glNamedCopyBufferSubDataEXT,                      loader);
OPENGL_LOAD_PROC(glNamedFramebufferTextureEXT,                     loader);
OPENGL_LOAD_PROC(glNamedFramebufferTextureLayerEXT,                loader);
OPENGL_LOAD_PROC(glNamedFramebufferTextureFaceEXT,                 loader);
OPENGL_LOAD_PROC(glTextureRenderbufferEXT,                         loader);
OPENGL_LOAD_PROC(glMultiTexRenderbufferEXT,                        loader);
OPENGL_LOAD_PROC(glVertexArrayVertexOffsetEXT,                     loader);
OPENGL_LOAD_PROC(glVertexArrayColorOffsetEXT,                      loader);
OPENGL_LOAD_PROC(glVertexArrayEdgeFlagOffsetEXT,                   loader);
OPENGL_LOAD_PROC(glVertexArrayIndexOffsetEXT,                      loader);
OPENGL_LOAD_PROC(glVertexArrayNormalOffsetEXT,                     loader);
OPENGL_LOAD_PROC(glVertexArrayTexCoordOffsetEXT,                   loader);
OPENGL_LOAD_PROC(glVertexArrayMultiTexCoordOffsetEXT,              loader);
OPENGL_LOAD_PROC(glVertexArrayFogCoordOffsetEXT,                   loader);
OPENGL_LOAD_PROC(glVertexArraySecondaryColorOffsetEXT,             loader);
OPENGL_LOAD_PROC(glVertexArrayVertexAttribOffsetEXT,               loader);
OPENGL_LOAD_PROC(glVertexArrayVertexAttribIOffsetEXT,              loader);
OPENGL_LOAD_PROC(glEnableVertexArrayEXT,                           loader);
OPENGL_LOAD_PROC(glDisableVertexArrayEXT,                          loader);
OPENGL_LOAD_PROC(glEnableVertexArrayAttribEXT,                     loader);
OPENGL_LOAD_PROC(glDisableVertexArrayAttribEXT,                    loader);
OPENGL_LOAD_PROC(glGetVertexArrayIntegervEXT,                      loader);
OPENGL_LOAD_PROC(glGetVertexArrayPointervEXT,                      loader);
OPENGL_LOAD_PROC(glGetVertexArrayIntegeri_vEXT,                    loader);
OPENGL_LOAD_PROC(glGetVertexArrayPointeri_vEXT,                    loader);
OPENGL_LOAD_PROC(glMapNamedBufferRangeEXT,                         loader);
OPENGL_LOAD_PROC(glFlushMappedNamedBufferRangeEXT,                 loader);
OPENGL_LOAD_PROC(glNamedBufferStorageEXT,                          loader);
OPENGL_LOAD_PROC(glClearNamedBufferDataEXT,                        loader);
OPENGL_LOAD_PROC(glClearNamedBufferSubDataEXT,                     loader);
OPENGL_LOAD_PROC(glNamedFramebufferParameteriEXT,                  loader);
OPENGL_LOAD_PROC(glGetNamedFramebufferParameterivEXT,              loader);
OPENGL_LOAD_PROC(glProgramUniform1dEXT,                            loader);
OPENGL_LOAD_PROC(glProgramUniform2dEXT,                            loader);
OPENGL_LOAD_PROC(glProgramUniform3dEXT,                            loader);
OPENGL_LOAD_PROC(glProgramUniform4dEXT,                            loader);
OPENGL_LOAD_PROC(glProgramUniform1dvEXT,                           loader);
OPENGL_LOAD_PROC(glProgramUniform2dvEXT,                           loader);
OPENGL_LOAD_PROC(glProgramUniform3dvEXT,                           loader);
OPENGL_LOAD_PROC(glProgramUniform4dvEXT,                           loader);
OPENGL_LOAD_PROC(glProgramUniformMatrix2dvEXT,                     loader);
OPENGL_LOAD_PROC(glProgramUniformMatrix3dvEXT,                     loader);
OPENGL_LOAD_PROC(glProgramUniformMatrix4dvEXT,                     loader);
OPENGL_LOAD_PROC(glProgramUniformMatrix2x3dvEXT,                   loader);
OPENGL_LOAD_PROC(glProgramUniformMatrix2x4dvEXT,                   loader);
OPENGL_LOAD_PROC(glProgramUniformMatrix3x2dvEXT,                   loader);
OPENGL_LOAD_PROC(glProgramUniformMatrix3x4dvEXT,                   loader);
OPENGL_LOAD_PROC(glProgramUniformMatrix4x2dvEXT,                   loader);
OPENGL_LOAD_PROC(glProgramUniformMatrix4x3dvEXT,                   loader);
OPENGL_LOAD_PROC(glTextureBufferRangeEXT,                          loader);
OPENGL_LOAD_PROC(glTextureStorage1DEXT,                            loader);
OPENGL_LOAD_PROC(glTextureStorage2DEXT,                            loader);
OPENGL_LOAD_PROC(glTextureStorage3DEXT,                            loader);
OPENGL_LOAD_PROC(glTextureStorage2DMultisampleEXT,                 loader);
OPENGL_LOAD_PROC(glTextureStorage3DMultisampleEXT,                 loader);
OPENGL_LOAD_PROC(glVertexArrayBindVertexBufferEXT,                 loader);
OPENGL_LOAD_PROC(glVertexArrayVertexAttribFormatEXT,               loader);
OPENGL_LOAD_PROC(glVertexArrayVertexAttribIFormatEXT,              loader);
OPENGL_LOAD_PROC(glVertexArrayVertexAttribLFormatEXT,              loader);
OPENGL_LOAD_PROC(glVertexArrayVertexAttribBindingEXT,              loader);
OPENGL_LOAD_PROC(glVertexArrayVertexBindingDivisorEXT,             loader);
OPENGL_LOAD_PROC(glVertexArrayVertexAttribLOffsetEXT,              loader);
OPENGL_LOAD_PROC(glTexturePageCommitmentEXT,                       loader);
OPENGL_LOAD_PROC(glVertexArrayVertexAttribDivisorEXT,              loader));
#endif // OPENGL_INCLUDE_GL_EXT_direct_state_access

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_draw_buffers2)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_draw_buffers2,
OPENGL_LOAD_PROC(glColorMaskIndexedEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_draw_buffers2

/* -------------------------------------------------------------------------- */

#if defined(OPENG_INCLUDE_GL_EXT_draw_instanced)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_draw_instanced,
OPENGL_LOAD_PROC(glDrawArraysInstancedEXT,   loader);
OPENGL_LOAD_PROC(glDrawElementsInstancedEXT, loader));
#endif // OPENG_INCLUDE_GL_EXT_draw_instanced

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_draw_range_elements)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_draw_range_elements,
OPENGL_LOAD_PROC(glDrawRangeElementsEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_draw_range_elements

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_external_buffer)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_external_buffer,
OPENGL_LOAD_PROC(glBufferStorageExternalEXT,      loader);
OPENGL_LOAD_PROC(glNamedBufferStorageExternalEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_external_buffer

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_fog_coord)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_fog_coord,
OPENGL_LOAD_PROC(glFogCoordfEXT,       loader);
OPENGL_LOAD_PROC(glFogCoordfvEXT,      loader);
OPENGL_LOAD_PROC(glFogCoorddEXT,       loader);
OPENGL_LOAD_PROC(glFogCoorddvEXT,      loader);
OPENGL_LOAD_PROC(glFogCoordPointerEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_fog_coord

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_framebuffer_blit)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_framebuffer_blit,
OPENGL_LOAD_PROC(glBlitFramebufferEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_framebuffer_blit

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_framebuffer_multisample)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_framebuffer_multisample,
OPENGL_LOAD_PROC(glRenderbufferStorageMultisampleEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_framebuffer_multisample

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_framebuffer_object)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_framebuffer_object,
OPENGL_LOAD_PROC(glIsRenderbufferEXT,                      loader);
OPENGL_LOAD_PROC(glBindRenderbufferEXT,                    loader);
OPENGL_LOAD_PROC(glDeleteRenderbuffersEXT,                 loader);
OPENGL_LOAD_PROC(glGenRenderbuffersEXT,                    loader);
OPENGL_LOAD_PROC(glRenderbufferStorageEXT,                 loader);
OPENGL_LOAD_PROC(glGetRenderbufferParameterivEXT,          loader);
OPENGL_LOAD_PROC(glIsFramebufferEXT,                       loader);
OPENGL_LOAD_PROC(glBindFramebufferEXT,                     loader);
OPENGL_LOAD_PROC(glDeleteFramebuffersEXT,                  loader);
OPENGL_LOAD_PROC(glGenFramebuffersEXT,                     loader);
OPENGL_LOAD_PROC(glCheckFramebufferStatusEXT,              loader);
OPENGL_LOAD_PROC(glFramebufferTexture1DEXT,                loader);
OPENGL_LOAD_PROC(glFramebufferTexture2DEXT,                loader);
OPENGL_LOAD_PROC(glFramebufferTexture3DEXT,                loader);
OPENGL_LOAD_PROC(glFramebufferRenderbufferEXT,             loader);
OPENGL_LOAD_PROC(glGetFramebufferAttachmentParameterivEXT, loader);
OPENGL_LOAD_PROC(glGenerateMipmapEXT,                      loader));
#endif // OPENGL_INCLUDE_GL_EXT_framebuffer_object

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_geometry_shader4)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_geometry_shader4,
OPENGL_LOAD_PROC(glProgramParameteriEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_geometry_shader4

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_gpu_program_parameters)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_gpu_program_parameters,
OPENGL_LOAD_PROC(glProgramEnvParameters4fvEXT,   loader);
OPENGL_LOAD_PROC(glProgramLocalParameters4fvEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_gpu_program_parameters

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_gpu_shader4)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_gpu_shader4,
OPENGL_LOAD_PROC(glGetUniformuivEXT,        loader);
OPENGL_LOAD_PROC(glBindFragDataLocationEXT, loader);
OPENGL_LOAD_PROC(glGetFragDataLocationEXT,  loader);
OPENGL_LOAD_PROC(glUniform1uiEXT,           loader);
OPENGL_LOAD_PROC(glUniform2uiEXT,           loader);
OPENGL_LOAD_PROC(glUniform3uiEXT,           loader);
OPENGL_LOAD_PROC(glUniform4uiEXT,           loader);
OPENGL_LOAD_PROC(glUniform1uivEXT,          loader);
OPENGL_LOAD_PROC(glUniform2uivEXT,          loader);
OPENGL_LOAD_PROC(glUniform3uivEXT,          loader);
OPENGL_LOAD_PROC(glUniform4uivEXT,          loader));
#endif // OPENGL_INCLUDE_GL_EXT_gpu_shader4

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_histogram)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_histogram,
OPENGL_LOAD_PROC(glGetHistogramEXT,            loader);
OPENGL_LOAD_PROC(glGetHistogramParameterfvEXT, loader);
OPENGL_LOAD_PROC(glGetHistogramParameterivEXT, loader);
OPENGL_LOAD_PROC(glGetMinmaxEXT,               loader);
OPENGL_LOAD_PROC(glGetMinmaxParameterfvEXT,    loader);
OPENGL_LOAD_PROC(glGetMinmaxParameterivEXT,    loader);
OPENGL_LOAD_PROC(glHistogramEXT,               loader);
OPENGL_LOAD_PROC(glMinmaxEXT,                  loader);
OPENGL_LOAD_PROC(glResetHistogramEXT,          loader);
OPENGL_LOAD_PROC(glResetMinmaxEXT,             loader));
#endif // OPENGL_INCLUDE_GL_EXT_histogram

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_index_func)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_index_func,
OPENGL_LOAD_PROC(glIndexFuncEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_index_func

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_index_material)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_index_material,
OPENGL_LOAD_PROC(glIndexMaterialEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_index_material

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_light_texture)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_light_texture,
OPENGL_LOAD_PROC(glApplyTextureEXT,    loader);
OPENGL_LOAD_PROC(glTextureLightEXT,    loader);
OPENGL_LOAD_PROC(glTextureMaterialEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_light_texture

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_memory_object)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_memory_object,
OPENGL_LOAD_PROC(glGetUnsignedBytevEXT,               loader);
OPENGL_LOAD_PROC(glGetUnsignedBytei_vEXT,             loader);
OPENGL_LOAD_PROC(glDeleteMemoryObjectsEXT,            loader);
OPENGL_LOAD_PROC(glIsMemoryObjectEXT,                 loader);
OPENGL_LOAD_PROC(glCreateMemoryObjectsEXT,            loader);
OPENGL_LOAD_PROC(glMemoryObjectParameterivEXT,        loader);
OPENGL_LOAD_PROC(glGetMemoryObjectParameterivEXT,     loader);
OPENGL_LOAD_PROC(glTexStorageMem2DEXT,                loader);
OPENGL_LOAD_PROC(glTexStorageMem2DMultisampleEXT,     loader);
OPENGL_LOAD_PROC(glTexStorageMem3DEXT,                loader);
OPENGL_LOAD_PROC(glTexStorageMem3DMultisampleEXT,     loader);
OPENGL_LOAD_PROC(glBufferStorageMemEXT,               loader);
OPENGL_LOAD_PROC(glTextureStorageMem2DEXT,            loader);
OPENGL_LOAD_PROC(glTextureStorageMem2DMultisampleEXT, loader);
OPENGL_LOAD_PROC(glTextureStorageMem3DEXT,            loader);
OPENGL_LOAD_PROC(glTextureStorageMem3DMultisampleEXT, loader);
OPENGL_LOAD_PROC(glNamedBufferStorageMemEXT,          loader);
OPENGL_LOAD_PROC(glTexStorageMem1DEXT,                loader);
OPENGL_LOAD_PROC(glTextureStorageMem1DEXT,            loader));
#endif // OPENGL_INCLUDE_GL_EXT_memory_object

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_memory_object_fd)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_memory_object_fd,
OPENGL_LOAD_PROC(glImportMemoryFdEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_memory_object_fd

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_memory_object_win32)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_memory_object_win32,
OPENGL_LOAD_PROC(glImportMemoryWin32HandleEXT, loader);
OPENGL_LOAD_PROC(glImportMemoryWin32NameEXT,   loader));
#endif // OPENGL_INCLUDE_GL_EXT_memory_object_win32

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_multi_draw_arrays)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_multi_draw_arrays,
OPENGL_LOAD_PROC(glMultiDrawArraysEXT,   loader);
OPENGL_LOAD_PROC(glMultiDrawElementsEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_multi_draw_arrays

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_multisample)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_multisample,
OPENGL_LOAD_PROC(glSampleMaskEXT,    loader);
OPENGL_LOAD_PROC(glSamplePatternEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_multisample

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_paletted_texture)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_paletted_texture,
OPENGL_LOAD_PROC(glColorTableEXT,               loader);
OPENGL_LOAD_PROC(glGetColorTableEXT,            loader);
OPENGL_LOAD_PROC(glGetColorTableParameterivEXT, loader);
OPENGL_LOAD_PROC(glGetColorTableParameterfvEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_paletted_texture

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_pixel_transform)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_pixel_transform,
OPENGL_LOAD_PROC(glPixelTransformParameteriEXT,     loader);
OPENGL_LOAD_PROC(glPixelTransformParameterfEXT,     loader);
OPENGL_LOAD_PROC(glPixelTransformParameterivEXT,    loader);
OPENGL_LOAD_PROC(glPixelTransformParameterfvEXT,    loader);
OPENGL_LOAD_PROC(glGetPixelTransformParameterivEXT, loader);
OPENGL_LOAD_PROC(glGetPixelTransformParameterfvEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_pixel_transform

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_point_parameters)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_point_parameters,
OPENGL_LOAD_PROC(glPointParameterfEXT,  loader);
OPENGL_LOAD_PROC(glPointParameterfvEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_point_parameters

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_polygon_offset)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_polygon_offset,
OPENGL_LOAD_PROC(glPolygonOffsetEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_polygon_offset

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_polygon_offset_clamp)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_polygon_offset_clamp,
OPENGL_LOAD_PROC(glPolygonOffsetClampEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_polygon_offset_clamp

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_provoking_vertex)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_provoking_vertex,
OPENGL_LOAD_PROC(glProvokingVertexEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_provoking_vertex

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_raster_multisample)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_raster_multisample,
OPENGL_LOAD_PROC(glRasterSamplesEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_raster_multisample

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_secondary_color)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_secondary_color,
OPENGL_LOAD_PROC(glSecondaryColor3bEXT,      loader);
OPENGL_LOAD_PROC(glSecondaryColor3bvEXT,     loader);
OPENGL_LOAD_PROC(glSecondaryColor3dEXT,      loader);
OPENGL_LOAD_PROC(glSecondaryColor3dvEXT,     loader);
OPENGL_LOAD_PROC(glSecondaryColor3fEXT,      loader);
OPENGL_LOAD_PROC(glSecondaryColor3fvEXT,     loader);
OPENGL_LOAD_PROC(glSecondaryColor3iEXT,      loader);
OPENGL_LOAD_PROC(glSecondaryColor3ivEXT,     loader);
OPENGL_LOAD_PROC(glSecondaryColor3sEXT,      loader);
OPENGL_LOAD_PROC(glSecondaryColor3svEXT,     loader);
OPENGL_LOAD_PROC(glSecondaryColor3ubEXT,     loader);
OPENGL_LOAD_PROC(glSecondaryColor3ubvEXT,    loader);
OPENGL_LOAD_PROC(glSecondaryColor3uiEXT,     loader);
OPENGL_LOAD_PROC(glSecondaryColor3uivEXT,    loader);
OPENGL_LOAD_PROC(glSecondaryColor3usEXT,     loader);
OPENGL_LOAD_PROC(glSecondaryColor3usvEXT,    loader);
OPENGL_LOAD_PROC(glSecondaryColorPointerEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_secondary_color

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_semaphore)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_semaphore,
OPENGL_LOAD_PROC(glGenSemaphoresEXT,              loader);
OPENGL_LOAD_PROC(glDeleteSemaphoresEXT,           loader);
OPENGL_LOAD_PROC(glIsSemaphoreEXT,                loader);
OPENGL_LOAD_PROC(glSemaphoreParameterui64vEXT,    loader);
OPENGL_LOAD_PROC(glGetSemaphoreParameterui64vEXT, loader);
OPENGL_LOAD_PROC(glWaitSemaphoreEXT,              loader);
OPENGL_LOAD_PROC(glSignalSemaphoreEXT,            loader));
#endif // OPENGL_INCLUDE_GL_EXT_semaphore

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_semaphore_fd)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_semaphore_fd,
OPENGL_LOAD_PROC(glImportSemaphoreFdEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_semaphore_fd

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_semaphore_win32)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_semaphore_win32,
OPENGL_LOAD_PROC(glImportSemaphoreWin32HandleEXT, loader);
OPENGL_LOAD_PROC(glImportSemaphoreWin32NameEXT,   loader));
#endif // OPENGL_INCLUDE_GL_EXT_semaphore_win32

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_separate_shader_objects)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_separate_shader_objects,
OPENGL_LOAD_PROC(glUseShaderProgramEXT,    loader);
OPENGL_LOAD_PROC(glActiveProgramEXT,       loader);
OPENGL_LOAD_PROC(glCreateShaderProgramEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_separate_shader_objects

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_shader_framebuffer_fetch_non_coherent)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_shader_framebuffer_fetch_non_coherent,
OPENGL_LOAD_PROC(glFramebufferFetchBarrierEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_shader_framebuffer_fetch_non_coherent

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_shader_image_load_store)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_shader_image_load_store,
OPENGL_LOAD_PROC(glBindImageTextureEXT, loader);
OPENGL_LOAD_PROC(glMemoryBarrierEXT,    loader));
#endif // OPENGL_INCLUDE_GL_EXT_shader_image_load_store

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_stencil_clear_tag)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_stencil_clear_tag,
OPENGL_LOAD_PROC(glStencilClearTagEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_stencil_clear_tag

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_stencil_two_side)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_stencil_two_side,
OPENGL_LOAD_PROC(glActiveStencilFaceEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_stencil_two_side

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_subtexture)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_subtexture,
OPENGL_LOAD_PROC(glTexSubImage1DEXT, loader);
OPENGL_LOAD_PROC(glTexSubImage2DEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_subtexture

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_texture3D)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_texture3D,
OPENGL_LOAD_PROC(glTexImage3DEXT,    loader);
OPENGL_LOAD_PROC(glTexSubImage3DEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_texture3D

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_texture_array)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_texture_array,
OPENGL_LOAD_PROC(glFramebufferTextureLayerEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_texture_array

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_texture_buffer_object)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_texture_buffer_object,
OPENGL_LOAD_PROC(glTexBufferEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_texture_buffer_object

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_texture_integer)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_texture_integer,
OPENGL_LOAD_PROC(glTexParameterIivEXT,     loader);
OPENGL_LOAD_PROC(glTexParameterIuivEXT,    loader);
OPENGL_LOAD_PROC(glGetTexParameterIivEXT,  loader);
OPENGL_LOAD_PROC(glGetTexParameterIuivEXT, loader);
OPENGL_LOAD_PROC(glClearColorIiEXT,        loader);
OPENGL_LOAD_PROC(glClearColorIuiEXT,       loader));
#endif // OPENGL_INCLUDE_GL_EXT_texture_integer

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_texture_object)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_texture_object,
OPENGL_LOAD_PROC(glAreTexturesResidentEXT, loader);
OPENGL_LOAD_PROC(glBindTextureEXT,         loader);
OPENGL_LOAD_PROC(glDeleteTexturesEXT,      loader);
OPENGL_LOAD_PROC(glGenTexturesEXT,         loader);
OPENGL_LOAD_PROC(glIsTextureEXT,           loader);
OPENGL_LOAD_PROC(glPrioritizeTexturesEXT,  loader));
#endif // OPENGL_INCLUDE_GL_EXT_texture_object

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_texture_perturb_normal)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_texture_perturb_normal,
OPENGL_LOAD_PROC(glTextureNormalEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_texture_perturb_normal

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_timer_query)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_timer_query,
OPENGL_LOAD_PROC(glGetQueryObjecti64vEXT,  loader);
OPENGL_LOAD_PROC(glGetQueryObjectui64vEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_timer_query

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_transform_feedback)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_transform_feedback,
OPENGL_LOAD_PROC(glBeginTransformFeedbackEXT,      loader);
OPENGL_LOAD_PROC(glEndTransformFeedbackEXT,        loader);
OPENGL_LOAD_PROC(glBindBufferRangeEXT,             loader);
OPENGL_LOAD_PROC(glBindBufferOffsetEXT,            loader);
OPENGL_LOAD_PROC(glBindBufferBaseEXT,              loader);
OPENGL_LOAD_PROC(glTransformFeedbackVaryingsEXT,   loader);
OPENGL_LOAD_PROC(glGetTransformFeedbackVaryingEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_transform_feedback

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_vertex_array)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_vertex_array,
OPENGL_LOAD_PROC(glArrayElementEXT,    loader);
OPENGL_LOAD_PROC(glColorPointerEXT,    loader);
OPENGL_LOAD_PROC(glDrawArraysEXT,      loader);
OPENGL_LOAD_PROC(glEdgeFlagPointerEXT, loader);
OPENGL_LOAD_PROC(glGetPointervEXT,     loader);
OPENGL_LOAD_PROC(glIndexPointerEXT,    loader);
OPENGL_LOAD_PROC(glNormalPointerEXT,   loader);
OPENGL_LOAD_PROC(glTexCoordPointerEXT, loader);
OPENGL_LOAD_PROC(glVertexPointerEXT,   loader));
#endif // OPENGL_INCLUDE_GL_EXT_vertex_array

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_vertex_attrib_64bit)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_vertex_attrib_64bit,
OPENGL_LOAD_PROC(glVertexAttribL1dEXT,      loader);
OPENGL_LOAD_PROC(glVertexAttribL2dEXT,      loader);
OPENGL_LOAD_PROC(glVertexAttribL3dEXT,      loader);
OPENGL_LOAD_PROC(glVertexAttribL4dEXT,      loader);
OPENGL_LOAD_PROC(glVertexAttribL1dvEXT,     loader);
OPENGL_LOAD_PROC(glVertexAttribL2dvEXT,     loader);
OPENGL_LOAD_PROC(glVertexAttribL3dvEXT,     loader);
OPENGL_LOAD_PROC(glVertexAttribL4dvEXT,     loader);
OPENGL_LOAD_PROC(glVertexAttribLPointerEXT, loader);
OPENGL_LOAD_PROC(glGetVertexAttribLdvEXT,   loader));
#endif // OPENGL_INCLUDE_GL_EXT_vertex_attrib_64bit

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_vertex_shader)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_vertex_shader,
OPENGL_LOAD_PROC(glBeginVertexShaderEXT,         loader);
OPENGL_LOAD_PROC(glEndVertexShaderEXT,           loader);
OPENGL_LOAD_PROC(glBindVertexShaderEXT,          loader);
OPENGL_LOAD_PROC(glGenVertexShadersEXT,          loader);
OPENGL_LOAD_PROC(glDeleteVertexShaderEXT,        loader);
OPENGL_LOAD_PROC(glShaderOp1EXT,                 loader);
OPENGL_LOAD_PROC(glShaderOp2EXT,                 loader);
OPENGL_LOAD_PROC(glShaderOp3EXT,                 loader);
OPENGL_LOAD_PROC(glSwizzleEXT,                   loader);
OPENGL_LOAD_PROC(glWriteMaskEXT,                 loader);
OPENGL_LOAD_PROC(glInsertComponentEXT,           loader);
OPENGL_LOAD_PROC(glExtractComponentEXT,          loader);
OPENGL_LOAD_PROC(glGenSymbolsEXT,                loader);
OPENGL_LOAD_PROC(glSetInvariantEXT,              loader);
OPENGL_LOAD_PROC(glSetLocalConstantEXT,          loader);
OPENGL_LOAD_PROC(glVariantbvEXT,                 loader);
OPENGL_LOAD_PROC(glVariantsvEXT,                 loader);
OPENGL_LOAD_PROC(glVariantivEXT,                 loader);
OPENGL_LOAD_PROC(glVariantfvEXT,                 loader);
OPENGL_LOAD_PROC(glVariantdvEXT,                 loader);
OPENGL_LOAD_PROC(glVariantubvEXT,                loader);
OPENGL_LOAD_PROC(glVariantusvEXT,                loader);
OPENGL_LOAD_PROC(glVariantuivEXT,                loader);
OPENGL_LOAD_PROC(glVariantPointerEXT,            loader);
OPENGL_LOAD_PROC(glEnableVariantClientStateEXT,  loader);
OPENGL_LOAD_PROC(glDisableVariantClientStateEXT, loader);
OPENGL_LOAD_PROC(glBindLightParameterEXT,        loader);
OPENGL_LOAD_PROC(glBindMaterialParameterEXT,     loader);
OPENGL_LOAD_PROC(glBindTexGenParameterEXT,       loader);
OPENGL_LOAD_PROC(glBindTextureUnitParameterEXT,  loader);
OPENGL_LOAD_PROC(glBindParameterEXT,             loader);
OPENGL_LOAD_PROC(glIsVariantEnabledEXT,          loader);
OPENGL_LOAD_PROC(glGetVariantBooleanvEXT,        loader);
OPENGL_LOAD_PROC(glGetVariantIntegervEXT,        loader);
OPENGL_LOAD_PROC(glGetVariantFloatvEXT,          loader);
OPENGL_LOAD_PROC(glGetVariantPointervEXT,        loader);
OPENGL_LOAD_PROC(glGetInvariantBooleanvEXT,      loader);
OPENGL_LOAD_PROC(glGetInvariantIntegervEXT,      loader);
OPENGL_LOAD_PROC(glGetInvariantFloatvEXT,        loader);
OPENGL_LOAD_PROC(glGetLocalConstantBooleanvEXT,  loader);
OPENGL_LOAD_PROC(glGetLocalConstantIntegervEXT,  loader);
OPENGL_LOAD_PROC(glGetLocalConstantFloatvEXT,    loader));
#endif // OPENGL_INCLUDE_GL_EXT_vertex_shader

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_vertex_weighting)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_vertex_weighting,
OPENGL_LOAD_PROC(glVertexWeightfEXT,       loader);
OPENGL_LOAD_PROC(glVertexWeightfvEXT,      loader);
OPENGL_LOAD_PROC(glVertexWeightPointerEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_vertex_weighting

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_win32_keyed_mutex)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_win32_keyed_mutex,
OPENGL_LOAD_PROC(glAcquireKeyedMutexWin32EXT, loader);
OPENGL_LOAD_PROC(glReleaseKeyedMutexWin32EXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_win32_keyed_mutex

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_window_rectangles)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_window_rectangles,
OPENGL_LOAD_PROC(glWindowRectanglesEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_window_rectangles

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_EXT_x11_sync_object)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_EXT_x11_sync_object,
OPENGL_LOAD_PROC(glImportSyncEXT, loader));
#endif // OPENGL_INCLUDE_GL_EXT_x11_sync_object

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_GREMEDY_frame_terminator)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_GREMEDY_frame_terminator,
OPENGL_LOAD_PROC(glFrameTerminatorGREMEDY, loader));
#endif // OPENGL_INCLUDE_GL_GREMEDY_frame_terminator

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_GREMEDY_string_marker)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_GREMEDY_string_marker,
OPENGL_LOAD_PROC(glStringMarkerGREMEDY, loader));
#endif // OPENGL_INCLUDE_GL_GREMEDY_string_marker

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_HP_image_transform)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_HP_image_transform,
OPENGL_LOAD_PROC(glImageTransformParameteriHP,     loader);
OPENGL_LOAD_PROC(glImageTransformParameterfHP,     loader);
OPENGL_LOAD_PROC(glImageTransformParameterivHP,    loader);
OPENGL_LOAD_PROC(glImageTransformParameterfvHP,    loader);
OPENGL_LOAD_PROC(glGetImageTransformParameterivHP, loader);
OPENGL_LOAD_PROC(glGetImageTransformParameterfvHP, loader));
#endif // OPENGL_INCLUDE_GL_HP_image_transform

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_IBM_multimode_draw_arrays)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_IBM_multimode_draw_arrays,
OPENGL_LOAD_PROC(glMultiModeDrawArraysIBM,   loader);
OPENGL_LOAD_PROC(glMultiModeDrawElementsIBM, loader));
#endif // OPENGL_INCLUDE_GL_IBM_multimode_draw_arrays

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_IBM_static_data)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_IBM_static_data,
OPENGL_LOAD_PROC(glFlushStaticDataIBM, loader));
#endif // OPENGL_INCLUDE_GL_IBM_static_data

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_IBM_vertex_array_lists)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_IBM_vertex_array_lists,
OPENGL_LOAD_PROC(glColorPointerListIBM,          loader);
OPENGL_LOAD_PROC(glSecondaryColorPointerListIBM, loader);
OPENGL_LOAD_PROC(glEdgeFlagPointerListIBM,       loader);
OPENGL_LOAD_PROC(glFogCoordPointerListIBM,       loader);
OPENGL_LOAD_PROC(glIndexPointerListIBM,          loader);
OPENGL_LOAD_PROC(glNormalPointerListIBM,         loader);
OPENGL_LOAD_PROC(glTexCoordPointerListIBM,       loader);
OPENGL_LOAD_PROC(glVertexPointerListIBM,         loader));
#endif // OPENGL_INCLUDE_GL_IBM_vertex_array_lists

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_INGR_blend_func_separate)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_INGR_blend_func_separate,
OPENGL_LOAD_PROC(glBlendFuncSeparateINGR, loader));
#endif // OPENGL_INCLUDE_GL_INGR_blend_func_separate

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_INTEL_framebuffer_CMAA)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_INTEL_framebuffer_CMAA,
OPENGL_LOAD_PROC(glApplyFramebufferAttachmentCMAAINTEL, loader));
#endif // OPENGL_INCLUDE_GL_INTEL_framebuffer_CMAA

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_INTEL_map_texture)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_INTEL_map_texture,
OPENGL_LOAD_PROC(glSyncTextureINTEL,    loader);
OPENGL_LOAD_PROC(glUnmapTexture2DINTEL, loader);
OPENGL_LOAD_PROC(glMapTexture2DINTEL,   loader));
#endif // OPENGL_INCLUDE_GL_INTEL_map_texture

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_INTEL_parallel_arrays)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_INTEL_parallel_arrays,
OPENGL_LOAD_PROC(glVertexPointervINTEL,   loader);
OPENGL_LOAD_PROC(glNormalPointervINTEL,   loader);
OPENGL_LOAD_PROC(glColorPointervINTEL,    loader);
OPENGL_LOAD_PROC(glTexCoordPointervINTEL, loader));
#endif // OPENGL_INCLUDE_GL_INTEL_parallel_arrays

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_INTEL_performance_query)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_INTEL_performance_query,
OPENGL_LOAD_PROC(glBeginPerfQueryINTEL,       loader);
OPENGL_LOAD_PROC(glCreatePerfQueryINTEL,      loader);
OPENGL_LOAD_PROC(glDeletePerfQueryINTEL,      loader);
OPENGL_LOAD_PROC(glEndPerfQueryINTEL,         loader);
OPENGL_LOAD_PROC(glGetFirstPerfQueryIdINTEL,  loader);
OPENGL_LOAD_PROC(glGetNextPerfQueryIdINTEL,   loader);
OPENGL_LOAD_PROC(glGetPerfCounterInfoINTEL,   loader);
OPENGL_LOAD_PROC(glGetPerfQueryDataINTEL,     loader);
OPENGL_LOAD_PROC(glGetPerfQueryIdByNameINTEL, loader);
OPENGL_LOAD_PROC(glGetPerfQueryInfoINTEL,     loader));
#endif // OPENGL_INCLUDE_GL_INTEL_performance_query

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_MESA_framebuffer_flip_y)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_MESA_framebuffer_flip_y,
OPENGL_LOAD_PROC(glFramebufferParameteriMESA,     loader);
OPENGL_LOAD_PROC(glGetFramebufferParameterivMESA, loader));
#endif // OPENGL_INCLUDE_GL_MESA_framebuffer_flip_y

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_MESA_resize_buffers)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_MESA_resize_buffers,
OPENGL_LOAD_PROC(glResizeBuffersMESA, loader));
#endif // OPENGL_INCLUDE_GL_MESA_resize_buffers

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_MESA_window_pos)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_MESA_window_pos,
OPENGL_LOAD_PROC(glWindowPos2dMESA,  loader);
OPENGL_LOAD_PROC(glWindowPos2dvMESA, loader);
OPENGL_LOAD_PROC(glWindowPos2fMESA,  loader);
OPENGL_LOAD_PROC(glWindowPos2fvMESA, loader);
OPENGL_LOAD_PROC(glWindowPos2iMESA,  loader);
OPENGL_LOAD_PROC(glWindowPos2ivMESA, loader);
OPENGL_LOAD_PROC(glWindowPos2sMESA,  loader);
OPENGL_LOAD_PROC(glWindowPos2svMESA, loader);
OPENGL_LOAD_PROC(glWindowPos3dMESA,  loader);
OPENGL_LOAD_PROC(glWindowPos3dvMESA, loader);
OPENGL_LOAD_PROC(glWindowPos3fMESA,  loader);
OPENGL_LOAD_PROC(glWindowPos3fvMESA, loader);
OPENGL_LOAD_PROC(glWindowPos3iMESA,  loader);
OPENGL_LOAD_PROC(glWindowPos3ivMESA, loader);
OPENGL_LOAD_PROC(glWindowPos3sMESA,  loader);
OPENGL_LOAD_PROC(glWindowPos3svMESA, loader);
OPENGL_LOAD_PROC(glWindowPos4dMESA,  loader);
OPENGL_LOAD_PROC(glWindowPos4dvMESA, loader);
OPENGL_LOAD_PROC(glWindowPos4fMESA,  loader);
OPENGL_LOAD_PROC(glWindowPos4fvMESA, loader);
OPENGL_LOAD_PROC(glWindowPos4iMESA,  loader);
OPENGL_LOAD_PROC(glWindowPos4ivMESA, loader);
OPENGL_LOAD_PROC(glWindowPos4sMESA,  loader);
OPENGL_LOAD_PROC(glWindowPos4svMESA, loader));
#endif // OPENGL_INCLUDE_GL_MESA_window_pos

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NVX_conditional_render)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NVX_conditional_render,
OPENGL_LOAD_PROC(glBeginConditionalRenderNVX, loader);
OPENGL_LOAD_PROC(glEndConditionalRenderNVX,   loader));
#endif // OPENGL_INCLUDE_GL_NVX_conditional_render

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NVX_gpu_multicast2)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NVX_gpu_multicast2,
OPENGL_LOAD_PROC(glUploadGpuMaskNVX,                   loader);
OPENGL_LOAD_PROC(glMulticastViewportArrayvNVX,         loader);
OPENGL_LOAD_PROC(glMulticastViewportPositionWScaleNVX, loader);
OPENGL_LOAD_PROC(glMulticastScissorArrayvNVX,          loader);
OPENGL_LOAD_PROC(glAsyncCopyBufferSubDataNVX,          loader);
OPENGL_LOAD_PROC(glAsyncCopyImageSubDataNVX,           loader));
#endif // OPENGL_INCLUDE_GL_NVX_gpu_multicast2

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NVX_linked_gpu_multicast)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NVX_linked_gpu_multicast,
OPENGL_LOAD_PROC(glLGPUNamedBufferSubDataNVX, loader);
OPENGL_LOAD_PROC(glLGPUCopyImageSubDataNVX,   loader);
OPENGL_LOAD_PROC(glLGPUInterlockNVX,          loader));
#endif // OPENGL_INCLUDE_GL_NVX_linked_gpu_multicast

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NVX_progress_fence)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NVX_progress_fence
OPENGL_LOAD_PROC(glCreateProgressFenceNVX,     loader);
OPENGL_LOAD_PROC(glSignalSemaphoreui64NVX,     loader);
OPENGL_LOAD_PROC(glWaitSemaphoreui64NVX,       loader);
OPENGL_LOAD_PROC(glClientWaitSemaphoreui64NVX, loader));
#endif // OPENGL_INCLUDE_GL_NVX_progress_fence

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_alpha_to_coverage_dither_control)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_alpha_to_coverage_dither_control,
OPENGL_LOAD_PROC(glAlphaToCoverageDitherControlNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_alpha_to_coverage_dither_control

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_bindless_multi_draw_indirect)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_bindless_multi_draw_indirect,
OPENGL_LOAD_PROC(glMultiDrawArraysIndirectBindlessNV,   loader);
OPENGL_LOAD_PROC(glMultiDrawElementsIndirectBindlessNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_bindless_multi_draw_indirect

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_bindless_multi_draw_indirect_count)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_bindless_multi_draw_indirect_count
OPENGL_LOAD_PROC(glMultiDrawArraysIndirectBindlessCountNV,   loader);
OPENGL_LOAD_PROC(glMultiDrawElementsIndirectBindlessCountNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_bindless_multi_draw_indirect_count

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_bindless_texture)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_bindless_texture,
OPENGL_LOAD_PROC(glGetTextureHandleNV,             loader);
OPENGL_LOAD_PROC(glGetTextureSamplerHandleNV,      loader);
OPENGL_LOAD_PROC(glMakeTextureHandleResidentNV,    loader);
OPENGL_LOAD_PROC(glMakeTextureHandleNonResidentNV, loader);
OPENGL_LOAD_PROC(glGetImageHandleNV,               loader);
OPENGL_LOAD_PROC(glMakeImageHandleResidentNV,      loader);
OPENGL_LOAD_PROC(glMakeImageHandleNonResidentNV,   loader);
OPENGL_LOAD_PROC(glUniformHandleui64NV,            loader);
OPENGL_LOAD_PROC(glUniformHandleui64vNV,           loader);
OPENGL_LOAD_PROC(glProgramUniformHandleui64NV,     loader);
OPENGL_LOAD_PROC(glProgramUniformHandleui64vNV,    loader);
OPENGL_LOAD_PROC(glIsTextureHandleResidentNV,      loader);
OPENGL_LOAD_PROC(glIsImageHandleResidentNV,        loader));
#endif // OPENGL_INCLUDE_GL_NV_bindless_texture

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_blend_equation_advanced)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_blend_equation_advanced,
OPENGL_LOAD_PROC(glBlendParameteriNV, loader);
OPENGL_LOAD_PROC(glBlendBarrierNV,    loader));
#endif // OPENGL_INCLUDE_GL_NV_blend_equation_advanced

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_clip_space_w_scaling)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_clip_space_w_scaling,
OPENGL_LOAD_PROC(glViewportPositionWScaleNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_clip_space_w_scaling

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_command_list)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_command_list,
OPENGL_LOAD_PROC(glCreateStatesNV,                 loader);
OPENGL_LOAD_PROC(glDeleteStatesNV,                 loader);
OPENGL_LOAD_PROC(glIsStateNV,                      loader);
OPENGL_LOAD_PROC(glStateCaptureNV,                 loader);
OPENGL_LOAD_PROC(glGetCommandHeaderNV,             loader);
OPENGL_LOAD_PROC(glGetStageIndexNV,                loader);
OPENGL_LOAD_PROC(glDrawCommandsNV,                 loader);
OPENGL_LOAD_PROC(glDrawCommandsAddressNV,          loader);
OPENGL_LOAD_PROC(glDrawCommandsStatesNV,           loader);
OPENGL_LOAD_PROC(glDrawCommandsStatesAddressNV,    loader);
OPENGL_LOAD_PROC(glCreateCommandListsNV,           loader);
OPENGL_LOAD_PROC(glDeleteCommandListsNV,           loader);
OPENGL_LOAD_PROC(glIsCommandListNV,                loader);
OPENGL_LOAD_PROC(glListDrawCommandsStatesClientNV, loader);
OPENGL_LOAD_PROC(glCommandListSegmentsNV,          loader);
OPENGL_LOAD_PROC(glCompileCommandListNV,           loader);
OPENGL_LOAD_PROC(glCallCommandListNV,              loader));
#endif // OPENGL_INCLUDE_GL_NV_command_list

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_conditional_render)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_conditional_render,
OPENGL_LOAD_PROC(glBeginConditionalRenderNV, loader);
OPENGL_LOAD_PROC(glEndConditionalRenderNV,   loader));
#endif // OPENGL_INCLUDE_GL_NV_conditional_render

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_conservative_raster)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_conservative_raster,
OPENGL_LOAD_PROC(glSubpixelPrecisionBiasNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_conservative_raster

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_conservative_raster_dilate)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_conservative_raster_dilate,
OPENGL_LOAD_PROC(glConservativeRasterParameterfNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_conservative_raster_dilate

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_conservative_raster_pre_snap_triangles)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_conservative_raster_pre_snap_triangles,
OPENGL_LOAD_PROC(glConservativeRasterParameteriNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_conservative_raster_pre_snap_triangles

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_copy_image)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_copy_image,
OPENGL_LOAD_PROC(glCopyImageSubDataNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_copy_image

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_depth_buffer_float)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_depth_buffer_float,
OPENGL_LOAD_PROC(glDepthRangedNV,  loader);
OPENGL_LOAD_PROC(glClearDepthdNV,  loader);
OPENGL_LOAD_PROC(glDepthBoundsdNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_depth_buffer_float

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_draw_texture)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_draw_texture,
OPENGL_LOAD_PROC(glDrawTextureNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_draw_texture

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_draw_vulkan_image)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_draw_vulkan_image,
OPENGL_LOAD_PROC(glDrawVkImageNV,       loader);
OPENGL_LOAD_PROC(glGetVkProcAddrNV,     loader);
OPENGL_LOAD_PROC(glWaitVkSemaphoreNV,   loader);
OPENGL_LOAD_PROC(glSignalVkSemaphoreNV, loader);
OPENGL_LOAD_PROC(glSignalVkFenceNV,     loader));
#endif // OPENGL_INCLUDE_GL_NV_draw_vulkan_image

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_evaluators)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_evaluators,
OPENGL_LOAD_PROC(glMapControlPointsNV,        loader);
OPENGL_LOAD_PROC(glMapParameterivNV,          loader);
OPENGL_LOAD_PROC(glMapParameterfvNV,          loader);
OPENGL_LOAD_PROC(glGetMapControlPointsNV,     loader);
OPENGL_LOAD_PROC(glGetMapParameterivNV,       loader);
OPENGL_LOAD_PROC(glGetMapParameterfvNV,       loader);
OPENGL_LOAD_PROC(glGetMapAttribParameterivNV, loader);
OPENGL_LOAD_PROC(glGetMapAttribParameterfvNV, loader);
OPENGL_LOAD_PROC(glEvalMapsNV,                loader));
#endif // OPENGL_INCLUDE_GL_NV_evaluators

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_explicit_multisample)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_explicit_multisample,
OPENGL_LOAD_PROC(glGetMultisamplefvNV,  loader);
OPENGL_LOAD_PROC(glSampleMaskIndexedNV, loader);
OPENGL_LOAD_PROC(glTexRenderbufferNV,   loader));
#endif // OPENGL_INCLUDE_GL_NV_explicit_multisample

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_fence)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_fence,
OPENGL_LOAD_PROC(glDeleteFencesNV, loader);
OPENGL_LOAD_PROC(glGenFencesNV,    loader);
OPENGL_LOAD_PROC(glIsFenceNV,      loader);
OPENGL_LOAD_PROC(glTestFenceNV,    loader);
OPENGL_LOAD_PROC(glGetFenceivNV,   loader);
OPENGL_LOAD_PROC(glFinishFenceNV,  loader);
OPENGL_LOAD_PROC(glSetFenceNV,     loader));
#endif // OPENGL_INCLUDE_GL_NV_fence

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_fragment_coverage_to_color)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_fragment_coverage_to_color,
OPENGL_LOAD_PROC(glFragmentCoverageColorNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_fragment_coverage_to_color

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_fragment_program)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_fragment_program,
OPENGL_LOAD_PROC(glProgramNamedParameter4fNV,    loader);
OPENGL_LOAD_PROC(glProgramNamedParameter4fvNV,   loader);
OPENGL_LOAD_PROC(glProgramNamedParameter4dNV,    loader);
OPENGL_LOAD_PROC(glProgramNamedParameter4dvNV,   loader);
OPENGL_LOAD_PROC(glGetProgramNamedParameterfvNV, loader);
OPENGL_LOAD_PROC(glGetProgramNamedParameterdvNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_fragment_program

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_framebuffer_mixed_samples)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_framebuffer_mixed_samples,
OPENGL_LOAD_PROC(glCoverageModulationTableNV,    loader);
OPENGL_LOAD_PROC(glGetCoverageModulationTableNV, loader);
OPENGL_LOAD_PROC(glCoverageModulationNV,         loader));
#endif // OPENGL_INCLUDE_GL_NV_framebuffer_mixed_samples

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_framebuffer_multisample_coverage)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_framebuffer_multisample_coverage,
OPENGL_LOAD_PROC(glRenderbufferStorageMultisampleCoverageNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_framebuffer_multisample_coverage

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_geometry_program4)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_geometry_program4,
OPENGL_LOAD_PROC(glProgramVertexLimitNV,      loader);
OPENGL_LOAD_PROC(glFramebufferTextureEXT,     loader);
OPENGL_LOAD_PROC(glFramebufferTextureFaceEXT, loader));
#endif // OPENGL_INCLUDE_GL_NV_geometry_program4

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_gpu_multicast)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_gpu_multicast,
OPENGL_LOAD_PROC(glRenderGpuMaskNV,                         loader);
OPENGL_LOAD_PROC(glMulticastBufferSubDataNV,                loader);
OPENGL_LOAD_PROC(glMulticastCopyBufferSubDataNV,            loader);
OPENGL_LOAD_PROC(glMulticastCopyImageSubDataNV,             loader);
OPENGL_LOAD_PROC(glMulticastBlitFramebufferNV,              loader);
OPENGL_LOAD_PROC(glMulticastFramebufferSampleLocationsfvNV, loader);
OPENGL_LOAD_PROC(glMulticastBarrierNV,                      loader);
OPENGL_LOAD_PROC(glMulticastWaitSyncNV,                     loader);
OPENGL_LOAD_PROC(glMulticastGetQueryObjectivNV,             loader);
OPENGL_LOAD_PROC(glMulticastGetQueryObjectuivNV,            loader);
OPENGL_LOAD_PROC(glMulticastGetQueryObjecti64vNV,           loader);
OPENGL_LOAD_PROC(glMulticastGetQueryObjectui64vNV,          loader));
#endif // OPENGL_INCLUDE_GL_NV_gpu_multicast

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_gpu_program4)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_gpu_program4,
OPENGL_LOAD_PROC(glProgramLocalParameterI4iNV,     loader);
OPENGL_LOAD_PROC(glProgramLocalParameterI4ivNV,    loader);
OPENGL_LOAD_PROC(glProgramLocalParametersI4ivNV,   loader);
OPENGL_LOAD_PROC(glProgramLocalParameterI4uiNV,    loader);
OPENGL_LOAD_PROC(glProgramLocalParameterI4uivNV,   loader);
OPENGL_LOAD_PROC(glProgramLocalParametersI4uivNV,  loader);
OPENGL_LOAD_PROC(glProgramEnvParameterI4iNV,       loader);
OPENGL_LOAD_PROC(glProgramEnvParameterI4ivNV,      loader);
OPENGL_LOAD_PROC(glProgramEnvParametersI4ivNV,     loader);
OPENGL_LOAD_PROC(glProgramEnvParameterI4uiNV,      loader);
OPENGL_LOAD_PROC(glProgramEnvParameterI4uivNV,     loader);
OPENGL_LOAD_PROC(glProgramEnvParametersI4uivNV,    loader);
OPENGL_LOAD_PROC(glGetProgramLocalParameterIivNV,  loader);
OPENGL_LOAD_PROC(glGetProgramLocalParameterIuivNV, loader);
OPENGL_LOAD_PROC(glGetProgramEnvParameterIivNV,    loader);
OPENGL_LOAD_PROC(glGetProgramEnvParameterIuivNV,   loader));
#endif // OPENGL_INCLUDE_GL_NV_gpu_program4

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_gpu_program5)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_gpu_program5,
OPENGL_LOAD_PROC(glProgramSubroutineParametersuivNV,   loader);
OPENGL_LOAD_PROC(glGetProgramSubroutineParameteruivNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_gpu_program5

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_half_float)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_half_float,
OPENGL_LOAD_PROC(glVertex2hNV,          loader);
OPENGL_LOAD_PROC(glVertex2hvNV,         loader);
OPENGL_LOAD_PROC(glVertex3hNV,          loader);
OPENGL_LOAD_PROC(glVertex3hvNV,         loader);
OPENGL_LOAD_PROC(glVertex4hNV,          loader);
OPENGL_LOAD_PROC(glVertex4hvNV,         loader);
OPENGL_LOAD_PROC(glNormal3hNV,          loader);
OPENGL_LOAD_PROC(glNormal3hvNV,         loader);
OPENGL_LOAD_PROC(glColor3hNV,           loader);
OPENGL_LOAD_PROC(glColor3hvNV,          loader);
OPENGL_LOAD_PROC(glColor4hNV,           loader);
OPENGL_LOAD_PROC(glColor4hvNV,          loader);
OPENGL_LOAD_PROC(glTexCoord1hNV,        loader);
OPENGL_LOAD_PROC(glTexCoord1hvNV,       loader);
OPENGL_LOAD_PROC(glTexCoord2hNV,        loader);
OPENGL_LOAD_PROC(glTexCoord2hvNV,       loader);
OPENGL_LOAD_PROC(glTexCoord3hNV,        loader);
OPENGL_LOAD_PROC(glTexCoord3hvNV,       loader);
OPENGL_LOAD_PROC(glTexCoord4hNV,        loader);
OPENGL_LOAD_PROC(glTexCoord4hvNV,       loader);
OPENGL_LOAD_PROC(glMultiTexCoord1hNV,   loader);
OPENGL_LOAD_PROC(glMultiTexCoord1hvNV,  loader);
OPENGL_LOAD_PROC(glMultiTexCoord2hNV,   loader);
OPENGL_LOAD_PROC(glMultiTexCoord2hvNV,  loader);
OPENGL_LOAD_PROC(glMultiTexCoord3hNV,   loader);
OPENGL_LOAD_PROC(glMultiTexCoord3hvNV,  loader);
OPENGL_LOAD_PROC(glMultiTexCoord4hNV,   loader);
OPENGL_LOAD_PROC(glMultiTexCoord4hvNV,  loader);
OPENGL_LOAD_PROC(glFogCoordhNV,         loader);
OPENGL_LOAD_PROC(glFogCoordhvNV,        loader);
OPENGL_LOAD_PROC(glSecondaryColor3hNV,  loader);
OPENGL_LOAD_PROC(glSecondaryColor3hvNV, loader);
OPENGL_LOAD_PROC(glVertexWeighthNV,     loader);
OPENGL_LOAD_PROC(glVertexWeighthvNV,    loader);
OPENGL_LOAD_PROC(glVertexAttrib1hNV,    loader);
OPENGL_LOAD_PROC(glVertexAttrib1hvNV,   loader);
OPENGL_LOAD_PROC(glVertexAttrib2hNV,    loader);
OPENGL_LOAD_PROC(glVertexAttrib2hvNV,   loader);
OPENGL_LOAD_PROC(glVertexAttrib3hNV,    loader);
OPENGL_LOAD_PROC(glVertexAttrib3hvNV,   loader);
OPENGL_LOAD_PROC(glVertexAttrib4hNV,    loader);
OPENGL_LOAD_PROC(glVertexAttrib4hvNV,   loader);
OPENGL_LOAD_PROC(glVertexAttribs1hvNV,  loader);
OPENGL_LOAD_PROC(glVertexAttribs2hvNV,  loader);
OPENGL_LOAD_PROC(glVertexAttribs3hvNV,  loader);
OPENGL_LOAD_PROC(glVertexAttribs4hvNV,  loader));
#endif // OPENGL_INCLUDE_GL_NV_half_float

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_memory_attachment)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_memory_attachment,
OPENGL_LOAD_PROC(glGetMemoryObjectDetachedResourcesuivNV, loader);
OPENGL_LOAD_PROC(glResetMemoryObjectParameterNV,          loader);
OPENGL_LOAD_PROC(glTexAttachMemoryNV,                     loader);
OPENGL_LOAD_PROC(glBufferAttachMemoryNV,                  loader);
OPENGL_LOAD_PROC(glTextureAttachMemoryNV,                 loader);
OPENGL_LOAD_PROC(glNamedBufferAttachMemoryNV,             loader));
#endif // OPENGL_INCLUDE_GL_NV_memory_attachment

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_mesh_shader)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_mesh_shader,
OPENGL_LOAD_PROC(glDrawMeshTasksNV,                   loader);
OPENGL_LOAD_PROC(glDrawMeshTasksIndirectNV,           loader);
OPENGL_LOAD_PROC(glMultiDrawMeshTasksIndirectNV,      loader);
OPENGL_LOAD_PROC(glMultiDrawMeshTasksIndirectCountNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_mesh_shader

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_occlusion_query)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_occlusion_query,
OPENGL_LOAD_PROC(glGenOcclusionQueriesNV,    loader);
OPENGL_LOAD_PROC(glDeleteOcclusionQueriesNV, loader);
OPENGL_LOAD_PROC(glIsOcclusionQueryNV,       loader);
OPENGL_LOAD_PROC(glBeginOcclusionQueryNV,    loader);
OPENGL_LOAD_PROC(glEndOcclusionQueryNV,      loader);
OPENGL_LOAD_PROC(glGetOcclusionQueryivNV,    loader);
OPENGL_LOAD_PROC(glGetOcclusionQueryuivNV,   loader));
#endif // OPENGL_INCLUDE_GL_NV_occlusion_query

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_parameter_buffer_object)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_parameter_buffer_object,
OPENGL_LOAD_PROC(glProgramBufferParametersfvNV,   loader);
OPENGL_LOAD_PROC(glProgramBufferParametersIivNV,  loader);
OPENGL_LOAD_PROC(glProgramBufferParametersIuivNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_parameter_buffer_object

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_path_rendering)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_path_rendering,
OPENGL_LOAD_PROC(glGenPathsNV,                            loader);
OPENGL_LOAD_PROC(glDeletePathsNV,                         loader);
OPENGL_LOAD_PROC(glIsPathNV,                              loader);
OPENGL_LOAD_PROC(glPathCommandsNV,                        loader);
OPENGL_LOAD_PROC(glPathCoordsNV,                          loader);
OPENGL_LOAD_PROC(glPathSubCommandsNV,                     loader);
OPENGL_LOAD_PROC(glPathSubCoordsNV,                       loader);
OPENGL_LOAD_PROC(glPathStringNV,                          loader);
OPENGL_LOAD_PROC(glPathGlyphsNV,                          loader);
OPENGL_LOAD_PROC(glPathGlyphRangeNV,                      loader);
OPENGL_LOAD_PROC(glWeightPathsNV,                         loader);
OPENGL_LOAD_PROC(glCopyPathNV,                            loader);
OPENGL_LOAD_PROC(glInterpolatePathsNV,                    loader);
OPENGL_LOAD_PROC(glTransformPathNV,                       loader);
OPENGL_LOAD_PROC(glPathParameterivNV,                     loader);
OPENGL_LOAD_PROC(glPathParameteriNV,                      loader);
OPENGL_LOAD_PROC(glPathParameterfvNV,                     loader);
OPENGL_LOAD_PROC(glPathParameterfNV,                      loader);
OPENGL_LOAD_PROC(glPathDashArrayNV,                       loader);
OPENGL_LOAD_PROC(glPathStencilFuncNV,                     loader);
OPENGL_LOAD_PROC(glPathStencilDepthOffsetNV,              loader);
OPENGL_LOAD_PROC(glStencilFillPathNV,                     loader);
OPENGL_LOAD_PROC(glStencilStrokePathNV,                   loader);
OPENGL_LOAD_PROC(glStencilFillPathInstancedNV,            loader);
OPENGL_LOAD_PROC(glStencilStrokePathInstancedNV,          loader);
OPENGL_LOAD_PROC(glPathCoverDepthFuncNV,                  loader);
OPENGL_LOAD_PROC(glCoverFillPathNV,                       loader);
OPENGL_LOAD_PROC(glCoverStrokePathNV,                     loader);
OPENGL_LOAD_PROC(glCoverFillPathInstancedNV,              loader);
OPENGL_LOAD_PROC(glCoverStrokePathInstancedNV,            loader);
OPENGL_LOAD_PROC(glGetPathParameterivNV,                  loader);
OPENGL_LOAD_PROC(glGetPathParameterfvNV,                  loader);
OPENGL_LOAD_PROC(glGetPathCommandsNV,                     loader);
OPENGL_LOAD_PROC(glGetPathCoordsNV,                       loader);
OPENGL_LOAD_PROC(glGetPathDashArrayNV,                    loader);
OPENGL_LOAD_PROC(glGetPathMetricsNV,                      loader);
OPENGL_LOAD_PROC(glGetPathMetricRangeNV,                  loader);
OPENGL_LOAD_PROC(glGetPathSpacingNV,                      loader);
OPENGL_LOAD_PROC(glIsPointInFillPathNV,                   loader);
OPENGL_LOAD_PROC(glIsPointInStrokePathNV,                 loader);
OPENGL_LOAD_PROC(glGetPathLengthNV,                       loader);
OPENGL_LOAD_PROC(glPointAlongPathNV,                      loader);
OPENGL_LOAD_PROC(glMatrixLoad3x2fNV,                      loader);
OPENGL_LOAD_PROC(glMatrixLoad3x3fNV,                      loader);
OPENGL_LOAD_PROC(glMatrixLoadTranspose3x3fNV,             loader);
OPENGL_LOAD_PROC(glMatrixMult3x2fNV,                      loader);
OPENGL_LOAD_PROC(glMatrixMult3x3fNV,                      loader);
OPENGL_LOAD_PROC(glMatrixMultTranspose3x3fNV,             loader);
OPENGL_LOAD_PROC(glStencilThenCoverFillPathNV,            loader);
OPENGL_LOAD_PROC(glStencilThenCoverStrokePathNV,          loader);
OPENGL_LOAD_PROC(glStencilThenCoverFillPathInstancedNV,   loader);
OPENGL_LOAD_PROC(glStencilThenCoverStrokePathInstancedNV, loader);
OPENGL_LOAD_PROC(glPathGlyphIndexRangeNV,                 loader);
OPENGL_LOAD_PROC(glPathGlyphIndexArrayNV,                 loader);
OPENGL_LOAD_PROC(glPathMemoryGlyphIndexArrayNV,           loader);
OPENGL_LOAD_PROC(glProgramPathFragmentInputGenNV,         loader);
OPENGL_LOAD_PROC(glGetProgramResourcefvNV,                loader);
OPENGL_LOAD_PROC(glPathColorGenNV,                        loader);
OPENGL_LOAD_PROC(glPathTexGenNV,                          loader);
OPENGL_LOAD_PROC(glPathFogGenNV,                          loader);
OPENGL_LOAD_PROC(glGetPathColorGenivNV,                   loader);
OPENGL_LOAD_PROC(glGetPathColorGenfvNV,                   loader);
OPENGL_LOAD_PROC(glGetPathTexGenivNV,                     loader);
OPENGL_LOAD_PROC(glGetPathTexGenfvNV,                     loader));
#endif // OPENGL_INCLUDE_GL_NV_path_rendering

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_pixel_data_range)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_pixel_data_range,
OPENGL_LOAD_PROC(glPixelDataRangeNV,      loader);
OPENGL_LOAD_PROC(glFlushPixelDataRangeNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_pixel_data_range

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_point_sprite)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_point_sprite,
OPENGL_LOAD_PROC(glPointParameteriNV,  loader);
OPENGL_LOAD_PROC(glPointParameterivNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_point_sprite

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_present_video)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_present_video,
OPENGL_LOAD_PROC(glPresentFrameKeyedNV,    loader);
OPENGL_LOAD_PROC(glPresentFrameDualFillNV, loader);
OPENGL_LOAD_PROC(glGetVideoivNV,           loader);
OPENGL_LOAD_PROC(glGetVideouivNV,          loader);
OPENGL_LOAD_PROC(glGetVideoi64vNV,         loader);
OPENGL_LOAD_PROC(glGetVideoui64vNV,        loader));
#endif // OPENGL_INCLUDE_GL_NV_present_video

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_primitive_restart)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_primitive_restart,
OPENGL_LOAD_PROC(glPrimitiveRestartNV,      loader);
OPENGL_LOAD_PROC(glPrimitiveRestartIndexNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_primitive_restart

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_query_resource)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_query_resource,
OPENGL_LOAD_PROC(glQueryResourceNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_query_resource

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_query_resource_tag)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_query_resource_tag,
OPENGL_LOAD_PROC(glGenQueryResourceTagNV,    loader);
OPENGL_LOAD_PROC(glDeleteQueryResourceTagNV, loader);
OPENGL_LOAD_PROC(glQueryResourceTagNV,       loader));
#endif // OPENGL_INCLUDE_GL_NV_query_resource_tag

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_register_combiners)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_register_combiners,
OPENGL_LOAD_PROC(glCombinerParameterfvNV,              loader);
OPENGL_LOAD_PROC(glCombinerParameterfNV,               loader);
OPENGL_LOAD_PROC(glCombinerParameterivNV,              loader);
OPENGL_LOAD_PROC(glCombinerParameteriNV,               loader);
OPENGL_LOAD_PROC(glCombinerInputNV,                    loader);
OPENGL_LOAD_PROC(glCombinerOutputNV,                   loader);
OPENGL_LOAD_PROC(glFinalCombinerInputNV,               loader);
OPENGL_LOAD_PROC(glGetCombinerInputParameterfvNV,      loader);
OPENGL_LOAD_PROC(glGetCombinerInputParameterivNV,      loader);
OPENGL_LOAD_PROC(glGetCombinerOutputParameterfvNV,     loader);
OPENGL_LOAD_PROC(glGetCombinerOutputParameterivNV,     loader);
OPENGL_LOAD_PROC(glGetFinalCombinerInputParameterfvNV, loader);
OPENGL_LOAD_PROC(glGetFinalCombinerInputParameterivNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_register_combiners

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_register_combiners2)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_register_combiners2,
OPENGL_LOAD_PROC(glCombinerStageParameterfvNV,    loader);
OPENGL_LOAD_PROC(glGetCombinerStageParameterfvNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_register_combiners2

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_sample_locations)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_sample_locations,
OPENGL_LOAD_PROC(glFramebufferSampleLocationsfvNV,      loader);
OPENGL_LOAD_PROC(glNamedFramebufferSampleLocationsfvNV, loader);
OPENGL_LOAD_PROC(glResolveDepthValuesNV,                loader));
#endif // OPENGL_INCLUDE_GL_NV_sample_locations

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_scissor_exclusive)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_scissor_exclusive,
OPENGL_LOAD_PROC(glScissorExclusiveNV,       loader);
OPENGL_LOAD_PROC(glScissorExclusiveArrayvNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_scissor_exclusive

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_shader_buffer_load)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_shader_buffer_load,
OPENGL_LOAD_PROC(glMakeBufferResidentNV,           loader);
OPENGL_LOAD_PROC(glMakeBufferNonResidentNV,        loader);
OPENGL_LOAD_PROC(glIsBufferResidentNV,             loader);
OPENGL_LOAD_PROC(glMakeNamedBufferResidentNV,      loader);
OPENGL_LOAD_PROC(glMakeNamedBufferNonResidentNV,   loader);
OPENGL_LOAD_PROC(glIsNamedBufferResidentNV,        loader);
OPENGL_LOAD_PROC(glGetBufferParameterui64vNV,      loader);
OPENGL_LOAD_PROC(glGetNamedBufferParameterui64vNV, loader);
OPENGL_LOAD_PROC(glGetIntegerui64vNV,              loader);
OPENGL_LOAD_PROC(glUniformui64NV,                  loader);
OPENGL_LOAD_PROC(glUniformui64vNV,                 loader);
OPENGL_LOAD_PROC(glProgramUniformui64NV,           loader);
OPENGL_LOAD_PROC(glProgramUniformui64vNV,          loader));
#endif // OPENGL_INCLUDE_GL_NV_shader_buffer_load

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_shading_rate_image)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_shading_rate_image,
OPENGL_LOAD_PROC(glBindShadingRateImageNV,           loader);
OPENGL_LOAD_PROC(glGetShadingRateImagePaletteNV,     loader);
OPENGL_LOAD_PROC(glGetShadingRateSampleLocationivNV, loader);
OPENGL_LOAD_PROC(glShadingRateImageBarrierNV,        loader);
OPENGL_LOAD_PROC(glShadingRateImagePaletteNV,        loader);
OPENGL_LOAD_PROC(glShadingRateSampleOrderNV,         loader);
OPENGL_LOAD_PROC(glShadingRateSampleOrderCustomNV,   loader));
#endif // OPENGL_INCLUDE_GL_NV_shading_rate_image

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_texture_barrier)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_texture_barrier,
OPENGL_LOAD_PROC(glTextureBarrierNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_texture_barrier

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_texture_multisample)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_texture_multisample,
OPENGL_LOAD_PROC(glTexImage2DMultisampleCoverageNV,     loader);
OPENGL_LOAD_PROC(glTexImage3DMultisampleCoverageNV,     loader);
OPENGL_LOAD_PROC(glTextureImage2DMultisampleNV,         loader);
OPENGL_LOAD_PROC(glTextureImage3DMultisampleNV,         loader);
OPENGL_LOAD_PROC(glTextureImage2DMultisampleCoverageNV, loader);
OPENGL_LOAD_PROC(glTextureImage3DMultisampleCoverageNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_texture_multisample

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_transform_feedback)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_transform_feedback,
OPENGL_LOAD_PROC(glBeginTransformFeedbackNV,         loader);
OPENGL_LOAD_PROC(glEndTransformFeedbackNV,           loader);
OPENGL_LOAD_PROC(glTransformFeedbackAttribsNV,       loader);
OPENGL_LOAD_PROC(glBindBufferRangeNV,                loader);
OPENGL_LOAD_PROC(glBindBufferOffsetNV,               loader);
OPENGL_LOAD_PROC(glBindBufferBaseNV,                 loader);
OPENGL_LOAD_PROC(glTransformFeedbackVaryingsNV,      loader);
OPENGL_LOAD_PROC(glActiveVaryingNV,                  loader);
OPENGL_LOAD_PROC(glGetVaryingLocationNV,             loader);
OPENGL_LOAD_PROC(glGetActiveVaryingNV,               loader);
OPENGL_LOAD_PROC(glGetTransformFeedbackVaryingNV,    loader);
OPENGL_LOAD_PROC(glTransformFeedbackStreamAttribsNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_transform_feedback

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_transform_feedback2)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_transform_feedback2,
OPENGL_LOAD_PROC(glBindTransformFeedbackNV,    loader);
OPENGL_LOAD_PROC(glDeleteTransformFeedbacksNV, loader);
OPENGL_LOAD_PROC(glGenTransformFeedbacksNV,    loader);
OPENGL_LOAD_PROC(glIsTransformFeedbackNV,      loader);
OPENGL_LOAD_PROC(glPauseTransformFeedbackNV,   loader);
OPENGL_LOAD_PROC(glResumeTransformFeedbackNV,  loader);
OPENGL_LOAD_PROC(glDrawTransformFeedbackNV,    loader));
#endif // OPENGL_INCLUDE_GL_NV_transform_feedback2

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_vdpau_interop)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_vdpau_interop,
OPENGL_LOAD_PROC(glVDPAUInitNV,                  loader);
OPENGL_LOAD_PROC(glVDPAUFiniNV,                  loader);
OPENGL_LOAD_PROC(glVDPAURegisterVideoSurfaceNV,  loader);
OPENGL_LOAD_PROC(glVDPAURegisterOutputSurfaceNV, loader);
OPENGL_LOAD_PROC(glVDPAUIsSurfaceNV,             loader);
OPENGL_LOAD_PROC(glVDPAUUnregisterSurfaceNV,     loader);
OPENGL_LOAD_PROC(glVDPAUGetSurfaceivNV,          loader);
OPENGL_LOAD_PROC(glVDPAUSurfaceAccessNV,         loader);
OPENGL_LOAD_PROC(glVDPAUMapSurfacesNV,           loader);
OPENGL_LOAD_PROC(glVDPAUUnmapSurfacesNV,         loader));
#endif // OPENGL_INCLUDE_GL_NV_vdpau_interop

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_vdpau_interop2)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_vdpau_interop2,
OPENGL_LOAD_PROC(glVDPAURegisterVideoSurfaceWithPictureStructureNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_vdpau_interop2

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_vertex_array_range)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_vertex_array_range,
OPENGL_LOAD_PROC(glFlushVertexArrayRangeNV, loader);
OPENGL_LOAD_PROC(glVertexArrayRangeNV,      loader));
#endif // OPENGL_INCLUDE_GL_NV_vertex_array_range

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_vertex_attrib_integer_64bit)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_vertex_attrib_integer_64bit,
OPENGL_LOAD_PROC(glVertexAttribL1i64NV,     loader);
OPENGL_LOAD_PROC(glVertexAttribL2i64NV,     loader);
OPENGL_LOAD_PROC(glVertexAttribL3i64NV,     loader);
OPENGL_LOAD_PROC(glVertexAttribL4i64NV,     loader);
OPENGL_LOAD_PROC(glVertexAttribL1i64vNV,    loader);
OPENGL_LOAD_PROC(glVertexAttribL2i64vNV,    loader);
OPENGL_LOAD_PROC(glVertexAttribL3i64vNV,    loader);
OPENGL_LOAD_PROC(glVertexAttribL4i64vNV,    loader);
OPENGL_LOAD_PROC(glVertexAttribL1ui64NV,    loader);
OPENGL_LOAD_PROC(glVertexAttribL2ui64NV,    loader);
OPENGL_LOAD_PROC(glVertexAttribL3ui64NV,    loader);
OPENGL_LOAD_PROC(glVertexAttribL4ui64NV,    loader);
OPENGL_LOAD_PROC(glVertexAttribL1ui64vNV,   loader);
OPENGL_LOAD_PROC(glVertexAttribL2ui64vNV,   loader);
OPENGL_LOAD_PROC(glVertexAttribL3ui64vNV,   loader);
OPENGL_LOAD_PROC(glVertexAttribL4ui64vNV,   loader);
OPENGL_LOAD_PROC(glGetVertexAttribLi64vNV,  loader);
OPENGL_LOAD_PROC(glGetVertexAttribLui64vNV, loader);
OPENGL_LOAD_PROC(glVertexAttribLFormatNV,   loader));
#endif // OPENGL_INCLUDE_GL_NV_vertex_attrib_integer_64bit

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_vertex_buffer_unified_memory)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_vertex_buffer_unified_memory,
OPENGL_LOAD_PROC(glBufferAddressRangeNV,   loader);
OPENGL_LOAD_PROC(glVertexFormatNV,         loader);
OPENGL_LOAD_PROC(glNormalFormatNV,         loader);
OPENGL_LOAD_PROC(glColorFormatNV,          loader);
OPENGL_LOAD_PROC(glIndexFormatNV,          loader);
OPENGL_LOAD_PROC(glTexCoordFormatNV,       loader);
OPENGL_LOAD_PROC(glEdgeFlagFormatNV,       loader);
OPENGL_LOAD_PROC(glSecondaryColorFormatNV, loader);
OPENGL_LOAD_PROC(glFogCoordFormatNV,       loader);
OPENGL_LOAD_PROC(glVertexAttribFormatNV,   loader);
OPENGL_LOAD_PROC(glVertexAttribIFormatNV,  loader);
OPENGL_LOAD_PROC(glGetIntegerui64i_vNV,    loader));
#endif // OPENGL_INCLUDE_GL_NV_vertex_buffer_unified_memory

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_vertex_program)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_vertex_program,
OPENGL_LOAD_PROC(glAreProgramsResidentNV,     loader);
OPENGL_LOAD_PROC(glBindProgramNV,             loader);
OPENGL_LOAD_PROC(glDeleteProgramsNV,          loader);
OPENGL_LOAD_PROC(glExecuteProgramNV,          loader);
OPENGL_LOAD_PROC(glGenProgramsNV,             loader);
OPENGL_LOAD_PROC(glGetProgramParameterdvNV,   loader);
OPENGL_LOAD_PROC(glGetProgramParameterfvNV,   loader);
OPENGL_LOAD_PROC(glGetProgramivNV,            loader);
OPENGL_LOAD_PROC(glGetProgramStringNV,        loader);
OPENGL_LOAD_PROC(glGetTrackMatrixivNV,        loader);
OPENGL_LOAD_PROC(glGetVertexAttribdvNV,       loader);
OPENGL_LOAD_PROC(glGetVertexAttribfvNV,       loader);
OPENGL_LOAD_PROC(glGetVertexAttribivNV,       loader);
OPENGL_LOAD_PROC(glGetVertexAttribPointervNV, loader);
OPENGL_LOAD_PROC(glIsProgramNV,               loader);
OPENGL_LOAD_PROC(glLoadProgramNV,             loader);
OPENGL_LOAD_PROC(glProgramParameter4dNV,      loader);
OPENGL_LOAD_PROC(glProgramParameter4dvNV,     loader);
OPENGL_LOAD_PROC(glProgramParameter4fNV,      loader);
OPENGL_LOAD_PROC(glProgramParameter4fvNV,     loader);
OPENGL_LOAD_PROC(glProgramParameters4dvNV,    loader);
OPENGL_LOAD_PROC(glProgramParameters4fvNV,    loader);
OPENGL_LOAD_PROC(glRequestResidentProgramsNV, loader);
OPENGL_LOAD_PROC(glTrackMatrixNV,             loader);
OPENGL_LOAD_PROC(glVertexAttribPointerNV,     loader);
OPENGL_LOAD_PROC(glVertexAttrib1dNV,          loader);
OPENGL_LOAD_PROC(glVertexAttrib1dvNV,         loader);
OPENGL_LOAD_PROC(glVertexAttrib1fNV,          loader);
OPENGL_LOAD_PROC(glVertexAttrib1fvNV,         loader);
OPENGL_LOAD_PROC(glVertexAttrib1sNV,          loader);
OPENGL_LOAD_PROC(glVertexAttrib1svNV,         loader);
OPENGL_LOAD_PROC(glVertexAttrib2dNV,          loader);
OPENGL_LOAD_PROC(glVertexAttrib2dvNV,         loader);
OPENGL_LOAD_PROC(glVertexAttrib2fNV,          loader);
OPENGL_LOAD_PROC(glVertexAttrib2fvNV,         loader);
OPENGL_LOAD_PROC(glVertexAttrib2sNV,          loader);
OPENGL_LOAD_PROC(glVertexAttrib2svNV,         loader);
OPENGL_LOAD_PROC(glVertexAttrib3dNV,          loader);
OPENGL_LOAD_PROC(glVertexAttrib3dvNV,         loader);
OPENGL_LOAD_PROC(glVertexAttrib3fNV,          loader);
OPENGL_LOAD_PROC(glVertexAttrib3fvNV,         loader);
OPENGL_LOAD_PROC(glVertexAttrib3sNV,          loader);
OPENGL_LOAD_PROC(glVertexAttrib3svNV,         loader);
OPENGL_LOAD_PROC(glVertexAttrib4dNV,          loader);
OPENGL_LOAD_PROC(glVertexAttrib4dvNV,         loader);
OPENGL_LOAD_PROC(glVertexAttrib4fNV,          loader);
OPENGL_LOAD_PROC(glVertexAttrib4fvNV,         loader);
OPENGL_LOAD_PROC(glVertexAttrib4sNV,          loader);
OPENGL_LOAD_PROC(glVertexAttrib4svNV,         loader);
OPENGL_LOAD_PROC(glVertexAttrib4ubNV,         loader);
OPENGL_LOAD_PROC(glVertexAttrib4ubvNV,        loader);
OPENGL_LOAD_PROC(glVertexAttribs1dvNV,        loader);
OPENGL_LOAD_PROC(glVertexAttribs1fvNV,        loader);
OPENGL_LOAD_PROC(glVertexAttribs1svNV,        loader);
OPENGL_LOAD_PROC(glVertexAttribs2dvNV,        loader);
OPENGL_LOAD_PROC(glVertexAttribs2fvNV,        loader);
OPENGL_LOAD_PROC(glVertexAttribs2svNV,        loader);
OPENGL_LOAD_PROC(glVertexAttribs3dvNV,        loader);
OPENGL_LOAD_PROC(glVertexAttribs3fvNV,        loader);
OPENGL_LOAD_PROC(glVertexAttribs3svNV,        loader);
OPENGL_LOAD_PROC(glVertexAttribs4dvNV,        loader);
OPENGL_LOAD_PROC(glVertexAttribs4fvNV,        loader);
OPENGL_LOAD_PROC(glVertexAttribs4svNV,        loader);
OPENGL_LOAD_PROC(glVertexAttribs4ubvNV,       loader));
#endif // OPENGL_INCLUDE_GL_NV_vertex_program

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_vertex_program4)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_vertex_program4,
OPENGL_LOAD_PROC(glVertexAttribI1iEXT,      loader);
OPENGL_LOAD_PROC(glVertexAttribI2iEXT,      loader);
OPENGL_LOAD_PROC(glVertexAttribI3iEXT,      loader);
OPENGL_LOAD_PROC(glVertexAttribI4iEXT,      loader);
OPENGL_LOAD_PROC(glVertexAttribI1uiEXT,     loader);
OPENGL_LOAD_PROC(glVertexAttribI2uiEXT,     loader);
OPENGL_LOAD_PROC(glVertexAttribI3uiEXT,     loader);
OPENGL_LOAD_PROC(glVertexAttribI4uiEXT,     loader);
OPENGL_LOAD_PROC(glVertexAttribI1ivEXT,     loader);
OPENGL_LOAD_PROC(glVertexAttribI2ivEXT,     loader);
OPENGL_LOAD_PROC(glVertexAttribI3ivEXT,     loader);
OPENGL_LOAD_PROC(glVertexAttribI4ivEXT,     loader);
OPENGL_LOAD_PROC(glVertexAttribI1uivEXT,    loader);
OPENGL_LOAD_PROC(glVertexAttribI2uivEXT,    loader);
OPENGL_LOAD_PROC(glVertexAttribI3uivEXT,    loader);
OPENGL_LOAD_PROC(glVertexAttribI4uivEXT,    loader);
OPENGL_LOAD_PROC(glVertexAttribI4bvEXT,     loader);
OPENGL_LOAD_PROC(glVertexAttribI4svEXT,     loader);
OPENGL_LOAD_PROC(glVertexAttribI4ubvEXT,    loader);
OPENGL_LOAD_PROC(glVertexAttribI4usvEXT,    loader);
OPENGL_LOAD_PROC(glVertexAttribIPointerEXT, loader);
OPENGL_LOAD_PROC(glGetVertexAttribIivEXT,   loader);
OPENGL_LOAD_PROC(glGetVertexAttribIuivEXT,  loader));
#endif // OPENGL_INCLUDE_GL_NV_vertex_program3

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_video_capture)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_video_capture,
OPENGL_LOAD_PROC(glBeginVideoCaptureNV,             loader);
OPENGL_LOAD_PROC(glBindVideoCaptureStreamBufferNV,  loader);
OPENGL_LOAD_PROC(glBindVideoCaptureStreamTextureNV, loader);
OPENGL_LOAD_PROC(glEndVideoCaptureNV,               loader);
OPENGL_LOAD_PROC(glGetVideoCaptureivNV,             loader);
OPENGL_LOAD_PROC(glGetVideoCaptureStreamivNV,       loader);
OPENGL_LOAD_PROC(glGetVideoCaptureStreamfvNV,       loader);
OPENGL_LOAD_PROC(glGetVideoCaptureStreamdvNV,       loader);
OPENGL_LOAD_PROC(glVideoCaptureNV,                  loader);
OPENGL_LOAD_PROC(glVideoCaptureStreamParameterivNV, loader);
OPENGL_LOAD_PROC(glVideoCaptureStreamParameterfvNV, loader);
OPENGL_LOAD_PROC(glVideoCaptureStreamParameterdvNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_video_capture

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_NV_viewport_swizzle)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_NV_viewport_swizzle,
OPENGL_LOAD_PROC(glViewportSwizzleNV, loader));
#endif // OPENGL_INCLUDE_GL_NV_viewport_swizzle

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_OVR_multiview)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_OVR_multiview,
OPENGL_LOAD_PROC(glFramebufferTextureMultiviewOVR, loader));
#endif // OPENGL_INCLUDE_GL_OVR_multiview

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_PGI_misc_hints)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_PGI_misc_hints,
OPENGL_LOAD_PROC(glHintPGI, loader));
#endif // OPENGL_INCLUDE_GL_PGI_misc_hints

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SGIS_detail_texture)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SGIS_detail_texture,
OPENGL_LOAD_PROC(glDetailTexFuncSGIS,    loader);
OPENGL_LOAD_PROC(glGetDetailTexFuncSGIS, loader));
#endif // OPENGL_INCLUDE_GL_SGIS_detail_texture

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SGIS_fog_function)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SGIS_fog_function,
OPENGL_LOAD_PROC(glFogFuncSGIS,    loader);
OPENGL_LOAD_PROC(glGetFogFuncSGIS, loader));
#endif // OPENGL_INCLUDE_GL_SGIS_fog_function

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SGIS_multisample)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SGIS_multisample,
OPENGL_LOAD_PROC(glSampleMaskSGIS,    loader);
OPENGL_LOAD_PROC(glSamplePatternSGIS, loader));
#endif // OPENGL_INCLUDE_GL_SGIS_multisample

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SGIS_pixel_texture)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SGIS_pixel_texture,
OPENGL_LOAD_PROC(glPixelTexGenParameteriSGIS,     loader);
OPENGL_LOAD_PROC(glPixelTexGenParameterivSGIS,    loader);
OPENGL_LOAD_PROC(glPixelTexGenParameterfSGIS,     loader);
OPENGL_LOAD_PROC(glPixelTexGenParameterfvSGIS,    loader);
OPENGL_LOAD_PROC(glGetPixelTexGenParameterivSGIS, loader);
OPENGL_LOAD_PROC(glGetPixelTexGenParameterfvSGIS, loader));
#endif // OPENGL_INCLUDE_GL_SGIS_pixel_texture

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SGIS_point_parameters)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SGIS_point_parameters,
OPENGL_LOAD_PROC(glPointParameterfSGIS,  loader);
OPENGL_LOAD_PROC(glPointParameterfvSGIS, loader));
#endif // OPENGL_INCLUDE_GL_SGIS_point_parameters

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SGIS_sharpen_texture)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SGIS_sharpen_texture,
OPENGL_LOAD_PROC(glSharpenTexFuncSGIS,    loader);
OPENGL_LOAD_PROC(glGetSharpenTexFuncSGIS, loader));
#endif // OPENGL_INCLUDE_GL_SGIS_sharpen_texture

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SGIS_texture4D)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SGIS_texture4D,
OPENGL_LOAD_PROC(glTexImage4DSGIS,    loader);
OPENGL_LOAD_PROC(glTexSubImage4DSGIS, loader));
#endif // OPENGL_INCLUDE_GL_SGIS_texture4D

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SGIS_texture_color_mask)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SGIS_texture_color_mask,
OPENGL_LOAD_PROC(glTextureColorMaskSGIS, loader));
#endif // OPENGL_INCLUDE_GL_SGIS_texture_color_mask

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SGIS_texture_filter4)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SGIS_texture_filter4,
OPENGL_LOAD_PROC(glGetTexFilterFuncSGIS, loader);
OPENGL_LOAD_PROC(glTexFilterFuncSGIS,    loader));
#endif // OPENGL_INCLUDE_GL_SGIS_texture_filter4

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SGIX_async)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SGIX_async,
OPENGL_LOAD_PROC(glAsyncMarkerSGIX,        loader);
OPENGL_LOAD_PROC(glFinishAsyncSGIX,        loader);
OPENGL_LOAD_PROC(glPollAsyncSGIX,          loader);
OPENGL_LOAD_PROC(glGenAsyncMarkersSGIX,    loader);
OPENGL_LOAD_PROC(glDeleteAsyncMarkersSGIX, loader);
OPENGL_LOAD_PROC(glIsAsyncMarkerSGIX,      loader));
#endif // OPENGL_INCLUDE_GL_SGIX_async

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SGIX_flush_raster)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SGIX_flush_raster,
OPENGL_LOAD_PROC(glFlushRasterSGIX, loader));
#endif // OPENGL_INCLUDE_GL_SGIX_flush_raster

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SGIX_fragment_lighting)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SGIX_fragment_lighting,
OPENGL_LOAD_PROC(glFragmentColorMaterialSGIX, loader);
OPENGL_LOAD_PROC(glFragmentLightfSGIX,        loader);
OPENGL_LOAD_PROC(glFragmentLightfvSGIX,       loader);
OPENGL_LOAD_PROC(glFragmentLightiSGIX,        loader);
OPENGL_LOAD_PROC(glFragmentLightivSGIX,       loader);
OPENGL_LOAD_PROC(glFragmentLightModelfSGIX,   loader);
OPENGL_LOAD_PROC(glFragmentLightModelfvSGIX,  loader);
OPENGL_LOAD_PROC(glFragmentLightModeliSGIX,   loader);
OPENGL_LOAD_PROC(glFragmentLightModelivSGIX,  loader);
OPENGL_LOAD_PROC(glFragmentMaterialfSGIX,     loader);
OPENGL_LOAD_PROC(glFragmentMaterialfvSGIX,    loader);
OPENGL_LOAD_PROC(glFragmentMaterialiSGIX,     loader);
OPENGL_LOAD_PROC(glFragmentMaterialivSGIX,    loader);
OPENGL_LOAD_PROC(glGetFragmentLightfvSGIX,    loader);
OPENGL_LOAD_PROC(glGetFragmentLightivSGIX,    loader);
OPENGL_LOAD_PROC(glGetFragmentMaterialfvSGIX, loader);
OPENGL_LOAD_PROC(glGetFragmentMaterialivSGIX, loader);
OPENGL_LOAD_PROC(glLightEnviSGIX,             loader));
#endif // OPENGL_INCLUDE_GL_SGIX_fragment_lighting

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SGIX_framezoom)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SGIX_framezoom,
OPENGL_LOAD_PROC(glFrameZoomSGIX, loader));
#endif // OPENGL_INCLUDE_GL_SGIX_framezoom

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SGIX_igloo_interface)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SGIX_igloo_interface,
OPENGL_LOAD_PROC(glIglooInterfaceSGIX, loader));
#endif // OPENGL_INCLUDE_GL_SGIX_igloo_interface

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SGIX_instruments)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SGIX_instruments,
OPENGL_LOAD_PROC(glGetInstrumentsSGIX,    loader);
OPENGL_LOAD_PROC(glInstrumentsBufferSGIX, loader);
OPENGL_LOAD_PROC(glPollInstrumentsSGIX,   loader);
OPENGL_LOAD_PROC(glReadInstrumentsSGIX,   loader);
OPENGL_LOAD_PROC(glStartInstrumentsSGIX,  loader);
OPENGL_LOAD_PROC(glStopInstrumentsSGIX,   loader));
#endif // OPENGL_INCLUDE_GL_SGIX_instruments

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SGIX_list_priority)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SGIX_list_priority,
OPENGL_LOAD_PROC(glGetListParameterfvSGIX, loader);
OPENGL_LOAD_PROC(glGetListParameterivSGIX, loader);
OPENGL_LOAD_PROC(glListParameterfSGIX,     loader);
OPENGL_LOAD_PROC(glListParameterfvSGIX,    loader);
OPENGL_LOAD_PROC(glListParameteriSGIX,     loader);
OPENGL_LOAD_PROC(glListParameterivSGIX,    loader));
#endif // OPENGL_INCLUDE_GL_SGIX_list_priority

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SGIX_pixel_texture)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SGIX_pixel_texture,
OPENGL_LOAD_PROC(glPixelTexGenSGIX, loader));
#endif // OPENGL_INCLUDE_GL_SGIX_pixel_texture

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SGIX_polynomial_ffd)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SGIX_polynomial_ffd,
OPENGL_LOAD_PROC(glDeformationMap3dSGIX,           loader);
OPENGL_LOAD_PROC(glDeformationMap3fSGIX,           loader);
OPENGL_LOAD_PROC(glDeformSGIX,                     loader);
OPENGL_LOAD_PROC(glLoadIdentityDeformationMapSGIX, loader));
#endif // OPENGL_INCLUDE_GL_SGIX_polynomial_ffd

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SGIX_reference_plane)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SGIX_reference_plane,
OPENGL_LOAD_PROC(glReferencePlaneSGIX, loader));
#endif // OPENGL_INCLUDE_GL_SGIX_reference_plane

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SGIX_sprite)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SGIX_sprite,
OPENGL_LOAD_PROC(glSpriteParameterfSGIX,  loader);
OPENGL_LOAD_PROC(glSpriteParameterfvSGIX, loader);
OPENGL_LOAD_PROC(glSpriteParameteriSGIX,  loader);
OPENGL_LOAD_PROC(glSpriteParameterivSGIX, loader));
#endif // OPENGL_INCLUDE_GL_SGIX_sprite

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SGIX_tag_sample_buffer)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SGIX_tag_sample_buffer,
OPENGL_LOAD_PROC(glTagSampleBufferSGIX, loader));
#endif // OPENGL_INCLUDE_GL_SGIX_tag_sample_buffer

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SGI_color_table)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SGI_color_table,
OPENGL_LOAD_PROC(glColorTableSGI,               loader);
OPENGL_LOAD_PROC(glColorTableParameterfvSGI,    loader);
OPENGL_LOAD_PROC(glColorTableParameterivSGI,    loader);
OPENGL_LOAD_PROC(glCopyColorTableSGI,           loader);
OPENGL_LOAD_PROC(glGetColorTableSGI,            loader);
OPENGL_LOAD_PROC(glGetColorTableParameterfvSGI, loader);
OPENGL_LOAD_PROC(glGetColorTableParameterivSGI, loader));
#endif // OPENGL_INCLUDE_GL_SGI_color_table

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SUNX_constant_data)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SUNX_constant_data,
OPENGL_LOAD_PROC(glFinishTextureSUNX, loader));
#endif // OPENGL_INCLUDE_GL_SUNX_constant_data

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SUN_global_alpha)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SUN_global_alpha,
OPENGL_LOAD_PROC(glGlobalAlphaFactorbSUN,  loader);
OPENGL_LOAD_PROC(glGlobalAlphaFactorsSUN,  loader);
OPENGL_LOAD_PROC(glGlobalAlphaFactoriSUN,  loader);
OPENGL_LOAD_PROC(glGlobalAlphaFactorfSUN,  loader);
OPENGL_LOAD_PROC(glGlobalAlphaFactordSUN,  loader);
OPENGL_LOAD_PROC(glGlobalAlphaFactorubSUN, loader);
OPENGL_LOAD_PROC(glGlobalAlphaFactorusSUN, loader);
OPENGL_LOAD_PROC(glGlobalAlphaFactoruiSUN, loader));
#endif // OPENGL_INCLUDE_GL_SUN_global_alpha

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SUN_mesh_array)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SUN_mesh_array,
OPENGL_LOAD_PROC(glDrawMeshArraysSUN, loader));
#endif // OPENGL_INCLUDE_GL_SUN_mesh_array

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SUN_triangle_list)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SUN_triangle_list,
OPENGL_LOAD_PROC(glReplacementCodeuiSUN,      loader);
OPENGL_LOAD_PROC(glReplacementCodeusSUN,      loader);
OPENGL_LOAD_PROC(glReplacementCodeubSUN,      loader);
OPENGL_LOAD_PROC(glReplacementCodeuivSUN,     loader);
OPENGL_LOAD_PROC(glReplacementCodeusvSUN,     loader);
OPENGL_LOAD_PROC(glReplacementCodeubvSUN,     loader);
OPENGL_LOAD_PROC(glReplacementCodePointerSUN, loader));
#endif // OPENGL_INCLUDE_GL_SUN_triangle_list

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_GL_SUN_vertex)
OPENGL_CREATE_GL_EXTENSION_LOADER(
GL_SUN_vertex,
OPENGL_LOAD_PROC(glColor4ubVertex2fSUN,                                    loader);
OPENGL_LOAD_PROC(glColor4ubVertex2fvSUN,                                   loader);
OPENGL_LOAD_PROC(glColor4ubVertex3fSUN,                                    loader);
OPENGL_LOAD_PROC(glColor4ubVertex3fvSUN,                                   loader);
OPENGL_LOAD_PROC(glColor3fVertex3fSUN,                                     loader);
OPENGL_LOAD_PROC(glColor3fVertex3fvSUN,                                    loader);
OPENGL_LOAD_PROC(glNormal3fVertex3fSUN,                                    loader);
OPENGL_LOAD_PROC(glNormal3fVertex3fvSUN,                                   loader);
OPENGL_LOAD_PROC(glColor4fNormal3fVertex3fSUN,                             loader);
OPENGL_LOAD_PROC(glColor4fNormal3fVertex3fvSUN,                            loader);
OPENGL_LOAD_PROC(glTexCoord2fVertex3fSUN,                                  loader);
OPENGL_LOAD_PROC(glTexCoord2fVertex3fvSUN,                                 loader);
OPENGL_LOAD_PROC(glTexCoord4fVertex4fSUN,                                  loader);
OPENGL_LOAD_PROC(glTexCoord4fVertex4fvSUN,                                 loader);
OPENGL_LOAD_PROC(glTexCoord2fColor4ubVertex3fSUN,                          loader);
OPENGL_LOAD_PROC(glTexCoord2fColor4ubVertex3fvSUN,                         loader);
OPENGL_LOAD_PROC(glTexCoord2fColor3fVertex3fSUN,                           loader);
OPENGL_LOAD_PROC(glTexCoord2fColor3fVertex3fvSUN,                          loader);
OPENGL_LOAD_PROC(glTexCoord2fNormal3fVertex3fSUN,                          loader);
OPENGL_LOAD_PROC(glTexCoord2fNormal3fVertex3fvSUN,                         loader);
OPENGL_LOAD_PROC(glTexCoord2fColor4fNormal3fVertex3fSUN,                   loader);
OPENGL_LOAD_PROC(glTexCoord2fColor4fNormal3fVertex3fvSUN,                  loader);
OPENGL_LOAD_PROC(glTexCoord4fColor4fNormal3fVertex4fSUN,                   loader);
OPENGL_LOAD_PROC(glTexCoord4fColor4fNormal3fVertex4fvSUN,                  loader);
OPENGL_LOAD_PROC(glReplacementCodeuiVertex3fSUN,                           loader);
OPENGL_LOAD_PROC(glReplacementCodeuiVertex3fvSUN,                          loader);
OPENGL_LOAD_PROC(glReplacementCodeuiColor4ubVertex3fSUN,                   loader);
OPENGL_LOAD_PROC(glReplacementCodeuiColor4ubVertex3fvSUN,                  loader);
OPENGL_LOAD_PROC(glReplacementCodeuiColor3fVertex3fSUN,                    loader);
OPENGL_LOAD_PROC(glReplacementCodeuiColor3fVertex3fvSUN,                   loader);
OPENGL_LOAD_PROC(glReplacementCodeuiNormal3fVertex3fSUN,                   loader);
OPENGL_LOAD_PROC(glReplacementCodeuiNormal3fVertex3fvSUN,                  loader);
OPENGL_LOAD_PROC(glReplacementCodeuiColor4fNormal3fVertex3fSUN,            loader);
OPENGL_LOAD_PROC(glReplacementCodeuiColor4fNormal3fVertex3fvSUN,           loader);
OPENGL_LOAD_PROC(glReplacementCodeuiTexCoord2fVertex3fSUN,                 loader);
OPENGL_LOAD_PROC(glReplacementCodeuiTexCoord2fVertex3fvSUN,                loader);
OPENGL_LOAD_PROC(glReplacementCodeuiTexCoord2fNormal3fVertex3fSUN,         loader);
OPENGL_LOAD_PROC(glReplacementCodeuiTexCoord2fNormal3fVertex3fvSUN,        loader);
OPENGL_LOAD_PROC(glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fSUN,  loader);
OPENGL_LOAD_PROC(glReplacementCodeuiTexCoord2fColor4fNormal3fVertex3fvSUN, loader));
#endif // OPENGL_INCLUDE_GL_SUN_vertex

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_ARB_buffer_region)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_ARB_buffer_region,
GLL_LOADPORC(wglCreateBufferRegionARB,  loader);
GLL_LOADPORC(wglDeleteBufferRegionARB,  loader);
GLL_LOADPORC(wglSaveBufferRegionARB,    loader);
GLL_LOADPORC(wglRestoreBufferRegionARB, loader));
#endif // OPENGL_INCLUDE_WGL_ARB_buffer_region

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_ARB_create_context)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_ARB_create_context,
OPENGL_LOAD_PROC(wglCreateContextAttribsARB, loader));
#endif // OPENGL_INCLUDE_WGL_ARB_create_context

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_ARB_extensions_string)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_ARB_extensions_string,
OPENGL_LOAD_PROC(wglGetExtensionsStringARB, loader));
#endif // OPENGL_INCLUDE_WGL_ARB_extensions_string

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_ARB_make_current_read)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_ARB_make_current_read,
OPENGL_LOAD_PROC(wglMakeContextCurrentARB, loader);
OPENGL_LOAD_PROC(wglGetCurrentReadDCARB,   loader));
#endif // OPENGL_INCLUDE_WGL_ARB_make_current_read

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_ARB_pbuffer)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_ARB_pbuffer,
OPENGL_LOAD_PROC(wglCreatePbufferARB,    loader);
OPENGL_LOAD_PROC(wglGetPbufferDCARB,     loader);
OPENGL_LOAD_PROC(wglReleasePbufferDCARB, loader);
OPENGL_LOAD_PROC(wglDestroyPbufferARB,   loader);
OPENGL_LOAD_PROC(wglQueryPbufferARB,     loader));
#endif // OPENGL_INCLUDE_WGL_ARB_pbuffer

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_ARB_pixel_format)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_ARB_pixel_format,
OPENGL_LOAD_PROC(wglGetPixelFormatAttribivARB, loader);
OPENGL_LOAD_PROC(wglGetPixelFormatAttribfvARB, loader);
OPENGL_LOAD_PROC(wglChoosePixelFormatARB,      loader));
#endif // OPENGL_INCLUDE_WGL_ARB_pixel_format

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_ARB_render_texture)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_ARB_render_texture,
OPENGL_LOAD_PROC(wglBindTexImageARB,     loader);
OPENGL_LOAD_PROC(wglReleaseTexImageARB,  loader);
OPENGL_LOAD_PROC(wglSetPbufferAttribARB, loader));
#endif // OPENGL_INCLUDE_WGL_ARB_render_texture

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_3DL_stereo_control)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_3DL_stereo_control,
OPENGL_LOAD_PROC(wglSetStereoEmitterState3DL, loader));
#endif // OPENGL_INCLUDE_WGL_3DL_stereo_control

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_AMD_gpu_association)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_AMD_gpu_association,
OPENGL_LOAD_PROC(wglGetGPUIDsAMD,                      loader);
OPENGL_LOAD_PROC(wglGetGPUInfoAMD,                     loader);
OPENGL_LOAD_PROC(wglGetContextGPUIDAMD,                loader);
OPENGL_LOAD_PROC(wglCreateAssociatedContextAMD,        loader);
OPENGL_LOAD_PROC(wglCreateAssociatedContextAttribsAMD, loader);
OPENGL_LOAD_PROC(wglDeleteAssociatedContextAMD,        loader);
OPENGL_LOAD_PROC(wglMakeAssociatedContextCurrentAMD,   loader);
OPENGL_LOAD_PROC(wglGetCurrentAssociatedContextAMD,    loader);
OPENGL_LOAD_PROC(wglBlitContextFramebufferAMD,         loader));
#endif // OPENGL_INCLUDE_WGL_AMD_gpu_association

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_EXT_display_color_table)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_EXT_display_color_table,
OPENGL_LOAD_PROC(wglCreateDisplayColorTableEXT,  loader);
OPENGL_LOAD_PROC(wglLoadDisplayColorTableEXT,    loader);
OPENGL_LOAD_PROC(wglBindDisplayColorTableEXT,    loader);
OPENGL_LOAD_PROC(wglDestroyDisplayColorTableEXT, loader));
#endif // OPENGL_INCLUDE_WGL_EXT_display_color_table

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_EXT_extensions_string)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_EXT_extensions_string,
OPENGL_LOAD_PROC(wglGetExtensionsStringEXT, loader));
#endif // OPENGL_INCLUDE_WGL_EXT_extensions_string

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_EXT_make_current_read)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_EXT_make_current_read,
OPENGL_LOAD_PROC(wglMakeContextCurrentEXT, loader);
OPENGL_LOAD_PROC(wglGetCurrentReadDCEXT,   loader));
#endif // OPENGL_INCLUDE_WGL_EXT_make_current_read

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_EXT_pbuffer)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_EXT_pbuffer,
OPENGL_LOAD_PROC(wglCreatePbufferEXT,    loader);
OPENGL_LOAD_PROC(wglGetPbufferDCEXT,     loader);
OPENGL_LOAD_PROC(wglReleasePbufferDCEXT, loader);
OPENGL_LOAD_PROC(wglDestroyPbufferEXT,   loader);
OPENGL_LOAD_PROC(wglQueryPbufferEXT,     loader));
#endif // OPENGL_INCLUDE_WGL_EXT_pbuffer

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_EXT_pixel_format)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_EXT_pixel_format,
OPENGL_LOAD_PROC(wglGetPixelFormatAttribivEXT, loader);
OPENGL_LOAD_PROC(wglGetPixelFormatAttribfvEXT, loader);
OPENGL_LOAD_PROC(wglChoosePixelFormatEXT,      loader));
#endif // OPENGL_INCLUDE_WGL_EXT_pixel_format

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_EXT_swap_control)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_EXT_swap_control,
OPENGL_LOAD_PROC(wglSwapIntervalEXT,    loader);
OPENGL_LOAD_PROC(wglGetSwapIntervalEXT, loader));
#endif // OPENGL_INCLUDE_WGL_EXT_swap_control

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_I3D_digital_video_control)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_I3D_digital_video_control,
OPENGL_LOAD_PROC(wglGetDigitalVideoParametersI3D, loader);
OPENGL_LOAD_PROC(wglSetDigitalVideoParametersI3D, loader));
#endif // OPENGL_INCLUDE_WGL_I3D_digital_video_control

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_I3D_gamma)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_I3D_gamma,
OPENGL_LOAD_PROC(wglGetGammaTableParametersI3D, loader);
OPENGL_LOAD_PROC(wglSetGammaTableParametersI3D, loader);
OPENGL_LOAD_PROC(wglGetGammaTableI3D,           loader);
OPENGL_LOAD_PROC(wglSetGammaTableI3D,           loader));
#endif // OPENGL_INCLUDE_WGL_I3D_gamma

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_I3D_genlock)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_I3D_genlock,
OPENGL_LOAD_PROC(wglEnableGenlockI3D,              loader);
OPENGL_LOAD_PROC(wglDisableGenlockI3D,             loader);
OPENGL_LOAD_PROC(wglIsEnabledGenlockI3D,           loader);
OPENGL_LOAD_PROC(wglGenlockSourceI3D,              loader);
OPENGL_LOAD_PROC(wglGetGenlockSourceI3D,           loader);
OPENGL_LOAD_PROC(wglGenlockSourceEdgeI3D,          loader);
OPENGL_LOAD_PROC(wglGetGenlockSourceEdgeI3D,       loader);
OPENGL_LOAD_PROC(wglGenlockSampleRateI3D,          loader);
OPENGL_LOAD_PROC(wglGetGenlockSampleRateI3D,       loader);
OPENGL_LOAD_PROC(wglGenlockSourceDelayI3D,         loader);
OPENGL_LOAD_PROC(wglGetGenlockSourceDelayI3D,      loader);
OPENGL_LOAD_PROC(wglQueryGenlockMaxSourceDelayI3D, loader));
#endif // OPENGL_INCLUDE_WGL_I3D_genlock

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_I3D_image_buffer)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_I3D_image_buffer,
OPENGL_LOAD_PROC(wglCreateImageBufferI3D,          loader);
OPENGL_LOAD_PROC(wglDestroyImageBufferI3D,         loader);
OPENGL_LOAD_PROC(wglAssociateImageBufferEventsI3D, loader);
OPENGL_LOAD_PROC(wglReleaseImageBufferEventsI3D,   loader));
#endif // OPENGL_INCLUDE_WGL_I3D_image_buffer

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_I3D_swap_frame_lock)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_I3D_swap_frame_lock,
OPENGL_LOAD_PROC(wglEnableFrameLockI3D,      loader);
OPENGL_LOAD_PROC(wglDisableFrameLockI3D,     loader);
OPENGL_LOAD_PROC(wglIsEnabledFrameLockI3D,   loader);
OPENGL_LOAD_PROC(wglQueryFrameLockMasterI3D, loader));
#endif // OPENGL_INCLUDE_WGL_I3D_swap_frame_lock

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_I3D_swap_frame_usage)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_I3D_swap_frame_usage,
OPENGL_LOAD_PROC(wglGetFrameUsageI3D,      loader);
OPENGL_LOAD_PROC(wglBeginFrameTrackingI3D, loader);
OPENGL_LOAD_PROC(wglEndFrameTrackingI3D,   loader);
OPENGL_LOAD_PROC(wglQueryFrameTrackingI3D, loader));
#endif // OPENGL_INCLUDE_WGL_I3D_swap_frame_usage

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_NV_DX_interop)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_NV_DX_interop,
OPENGL_LOAD_PROC(wglDXSetResourceShareHandleNV, loader);
OPENGL_LOAD_PROC(wglDXOpenDeviceNV,             loader);
OPENGL_LOAD_PROC(wglDXCloseDeviceNV,            loader);
OPENGL_LOAD_PROC(wglDXRegisterObjectNV,         loader);
OPENGL_LOAD_PROC(wglDXUnregisterObjectNV,       loader);
OPENGL_LOAD_PROC(wglDXObjectAccessNV,           loader);
OPENGL_LOAD_PROC(wglDXLockObjectsNV,            loader);
OPENGL_LOAD_PROC(wglDXUnlockObjectsNV,          loader));
#endif // OPENGL_INCLUDE_WGL_NV_DX_interop

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_NV_copy_image)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_NV_copy_image,
OPENGL_LOAD_PROC(wglCopyImageSubDataNV, loader));
#endif // OPENGL_INCLUDE_WGL_NV_copy_image

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_NV_delay_before_swap)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_NV_delay_before_swap,
OPENGL_LOAD_PROC(wglDelayBeforeSwapNV, loader));
#endif // OPENGL_INCLUDE_WGL_NV_delay_before_swap

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_NV_gpu_affinity)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_NV_gpu_affinity,
OPENGL_LOAD_PROC(wglEnumGpusNV,               loader);
OPENGL_LOAD_PROC(wglEnumGpuDevicesNV,         loader);
OPENGL_LOAD_PROC(wglCreateAffinityDCNV,       loader);
OPENGL_LOAD_PROC(wglEnumGpusFromAffinityDCNV, loader);
OPENGL_LOAD_PROC(wglDeleteDCNV,               loader));
#endif // OPENGL_INCLUDE_WGL_NV_gpu_affinity

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_NV_present_video)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_NV_present_video,
OPENGL_LOAD_PROC(wglEnumerateVideoDevicesNV, loader);
OPENGL_LOAD_PROC(wglBindVideoDeviceNV,       loader);
OPENGL_LOAD_PROC(wglQueryCurrentContextNV,   loader));
#endif // OPENGL_INCLUDE_WGL_NV_present_video

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_NV_swap_group)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_NV_swap_group,
OPENGL_LOAD_PROC(wglJoinSwapGroupNV,      loader);
OPENGL_LOAD_PROC(wglBindSwapBarrierNV,    loader);
OPENGL_LOAD_PROC(wglQuerySwapGroupNV,     loader);
OPENGL_LOAD_PROC(wglQueryMaxSwapGroupsNV, loader);
OPENGL_LOAD_PROC(wglQueryFrameCountNV,    loader);
OPENGL_LOAD_PROC(wglResetFrameCountNV,    loader));
#endif // OPENGL_INCLUDE_WGL_NV_swap_group

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_NV_video_capture)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_NV_video_capture,
OPENGL_LOAD_PROC(wglBindVideoCaptureDeviceNV,       loader);
OPENGL_LOAD_PROC(wglEnumerateVideoCaptureDevicesNV, loader);
OPENGL_LOAD_PROC(wglLockVideoCaptureDeviceNV,       loader);
OPENGL_LOAD_PROC(wglQueryVideoCaptureDeviceNV,      loader);
OPENGL_LOAD_PROC(wglReleaseVideoCaptureDeviceNV,    loader));
#endif // OPENGL_INCLUDE_WGL_NV_video_capture

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_NV_video_output)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_NV_video_output,
OPENGL_LOAD_PROC(wglGetVideoDeviceNV,     loader);
OPENGL_LOAD_PROC(wglReleaseVideoDeviceNV, loader);
OPENGL_LOAD_PROC(wglBindVideoImageNV,     loader);
OPENGL_LOAD_PROC(wglReleaseVideoImageNV,  loader);
OPENGL_LOAD_PROC(wglSendPbufferToVideoNV, loader);
OPENGL_LOAD_PROC(wglGetVideoInfoNV,       loader));
#endif // OPENGL_INCLUDE_WGL_NV_video_output

/* -------------------------------------------------------------------------- */

#if defined(OPENGL_INCLUDE_WGL_OML_sync_control)
OPENGL_CREATE_WGL_EXTENSION_LOADER(
WGL_OML_sync_control,
OPENGL_LOAD_PROC(wglGetSyncValuesOML,       loader);
OPENGL_LOAD_PROC(wglGetMscRateOML,          loader);
OPENGL_LOAD_PROC(wglSwapBuffersMscOML,      loader);
OPENGL_LOAD_PROC(wglSwapLayerBuffersMscOML, loader);
OPENGL_LOAD_PROC(wglWaitForMscOML,          loader);
OPENGL_LOAD_PROC(wglWaitForSbcOML,          loader));
#endif // OPENGL_INCLUDE_WGL_OML_sync_control

/* -------------------------------------------------------------------------- */

#undef OPENGL_CREATE_GL_EXTENSION_LOADER
#undef OPENGL_CREATE_WGL_EXTENSION_LOADER

#undef OPENGL_INIT_PROC
#undef OPENGL_LOAD_PROC

#undef OPENGL_LOAD_GL_VERSION_1_0
#undef OPENGL_LOAD_GL_VERSION_1_1
#undef OPENGL_LOAD_GL_VERSION_1_2
#undef OPENGL_LOAD_GL_VERSION_1_3
#undef OPENGL_LOAD_GL_VERSION_1_4
#undef OPENGL_LOAD_GL_VERSION_1_5
#undef OPENGL_LOAD_GL_VERSION_2_0
#undef OPENGL_LOAD_GL_VERSION_2_1
#undef OPENGL_LOAD_GL_VERSION_3_0
#undef OPENGL_LOAD_GL_VERSION_3_1
#undef OPENGL_LOAD_GL_VERSION_3_2
#undef OPENGL_LOAD_GL_VERSION_3_3
#undef OPENGL_LOAD_GL_VERSION_4_0
#undef OPENGL_LOAD_GL_VERSION_4_1
#undef OPENGL_LOAD_GL_VERSION_4_2
#undef OPENGL_LOAD_GL_VERSION_4_3
#undef OPENGL_LOAD_GL_VERSION_4_4
#undef OPENGL_LOAD_GL_VERSION_4_5
#undef OPENGL_LOAD_GL_VERSION_4_6

/* -------------------------------------------------------------------------- */

/*////////////////////////////////////////////////////////////////////////////*/

#endif /* OPENGL_IMPLEMENTATION //////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/
/*////////////////////////////////////////////////////////////////////////////*/
/*////////////////////////////////////////////////////////////////////////////*/

/*******************************************************************************
 *
 * REVISION HISTORY:
 *
 * v1.0.2  [05-06-2020]  Added a needed cast to opengl_has_gl_extension.
 * v1.0.1  [28-05-2020]  Added version number defines.
 * v1.0.0  [28-05-2020]  Initial release.
 *
*******************************************************************************/

/*******************************************************************************
 *
 * THIS SOFTWARE IS AVAILABLE UNDER 2 LICENSES -- CHOOSE WHICHEVER YOU PREFER.
 *
 *******************************************************************************
 *
 * ALTERNATIVE A - MIT License
 *
 * Copyright (c) 2020 Joshua Robertson
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
