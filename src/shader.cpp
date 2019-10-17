FILDEF GLuint internal__compile_shader (const GLchar* _source, GLenum _type)
{
    GLuint shader = glCreateShader(_type);
    glShaderSource(shader, 1, &_source, NULL);
    glCompileShader(shader);

    // Determine the info log length and then temp allocate a buffer.
    GLint info_log_length;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info_log_length);
    char* info_log = cstd_malloc(char, info_log_length);
    if (info_log) {
        defer { cstd_free(info_log); };

        GLint compile_success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_success);
        if (!compile_success) {
            glGetShaderInfoLog(shader, info_log_length, NULL, info_log);
            LOG_ERROR(ERR_MIN, "Failed to compile shader:\n%s", info_log);
        }
    }

    return shader;
}

STDDEF Shader load_shader_from_source (const char* _source)
{
    std::string vert_src = _source;
    std::string frag_src = _source;

    string_replace(vert_src, " vert()", " main()");
    string_replace(frag_src, " frag()", " main()");

    string_replace(vert_src, "COMPILING_VERTEX_PROGRAM",   "1");
    string_replace(vert_src, "COMPILING_FRAGMENT_PROGRAM", "0");

    string_replace(frag_src, "COMPILING_VERTEX_PROGRAM",   "0");
    string_replace(frag_src, "COMPILING_FRAGMENT_PROGRAM", "1");

    const GLchar* vsrc = CAST(const GLchar*, vert_src.c_str());
    const GLchar* fsrc = CAST(const GLchar*, frag_src.c_str());

    GLuint vert = internal__compile_shader(vsrc, GL_VERTEX_SHADER);
    GLuint frag = internal__compile_shader(fsrc, GL_FRAGMENT_SHADER);

    defer { glDeleteShader(vert); glDeleteShader(frag); };

    // If either of the shaders failed to compile we return failure.
    if (!vert) { return NULL; }
    if (!frag) { return NULL; }

    Shader program = glCreateProgram();

    glAttachShader(program, vert);
    glAttachShader(program, frag);

    glLinkProgram(program);

    // Determine the info log length and then temp allocate a buffer.
    GLint info_log_length;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &info_log_length);
    char* info_log = cstd_malloc(char, info_log_length);
    if (info_log) {
        defer { cstd_free(info_log); };

        GLint link_success;
        glGetProgramiv(program, GL_LINK_STATUS, &link_success);
        if (!link_success) {
            glGetProgramInfoLog(program, info_log_length, NULL, info_log);
            LOG_ERROR(ERR_MIN, "Failed to link shader:\n%s", info_log);

            // Failed to create program so we free and leave.
            glDeleteProgram(program);
            return NULL;
        }
    }

    return program;
}

FILDEF Shader load_shader_from_file (const char* _file_name)
{
    // Build an absolute path to the file based on the executable location.
    std::string file_name(make_path_absolute(_file_name));

    char* source = read_entire_file(file_name.c_str());
    if (!source) {
        LOG_ERROR(ERR_MIN, "Failed to load shader '%s'!", file_name.c_str());
        return NULL;
    }
    defer { cstd_free(source); };

    Shader shader = load_shader_from_source(source);
    if (!shader) {
        LOG_ERROR(ERR_MIN, "Failed to build shader '%s'!", file_name.c_str());
    } /*else {
        LOG_DEBUG("Loaded Shader \"%s\"", file_name.c_str());
    }*/

    return shader;
}

FILDEF Shader load_shader_from_data (const std::vector<u8>& _file_data)
{
    std::string source(_file_data.begin(), _file_data.end());
    return load_shader_from_source(source.c_str());
}

FILDEF void free_shader (Shader _program)
{
    glDeleteProgram(_program);
}
