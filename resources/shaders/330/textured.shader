#version 330

uniform sampler2D texture0;

uniform mat4 projection;
uniform mat4 modelview;

#if COMPILING_VERTEX_PROGRAM
    layout (location = 0) in vec2 in_pos;
    layout (location = 1) in vec2 in_texcoord;
    layout (location = 2) in vec4 in_color;
    out vec2 texcoord;
    out vec4 color;
    void vert(){
        gl_Position = projection * modelview * vec4(in_pos,0,1);
        texcoord = in_texcoord;
        color = in_color;
    }
#elif COMPILING_FRAGMENT_PROGRAM
    in vec2 texcoord;
    in vec4 color;
    out vec4 frag_color;
    void frag(){
        frag_color = texture(texture0, texcoord) * color;
    }
#endif
