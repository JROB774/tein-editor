#version 130

#if COMPILING_VERTEX_PROGRAM
    void vert(){
        gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;
        gl_FrontColor = gl_Color;
    }
#elif COMPILING_FRAGMENT_PROGRAM
    void frag(){
        gl_FragColor = gl_Color;
    }
#endif
