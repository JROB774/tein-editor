#version 330

uniform mat4 projection;
uniform mat4 modelview;

#if COMPILING_VERTEX_PROGRAM
    layout (location = 0) in vec2 in_pos;
    layout (location = 2) in vec4 in_color;
    out vec4 color;
    void vert(){
        gl_Position = projection * modelview * vec4(in_pos,0,1);
        color = in_color;
    }
#elif COMPILING_FRAGMENT_PROGRAM
    in vec4 color;
    out vec4 frag_color;
    void frag(){
        frag_color = color;
    }
#endif
