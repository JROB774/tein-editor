#pragma once

typedef GLuint Shader;

STDDEF Shader load_shader_from_source (const char*               _source);
FILDEF Shader load_shader_from_file   (const char*            _file_name);
FILDEF Shader load_shader_from_data   (const std::vector<u8>& _file_data);
FILDEF void   free_shader             (Shader _program);
