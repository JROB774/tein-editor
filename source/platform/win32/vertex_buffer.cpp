FILDEF void create_vertex_buffer (Vertex_Buffer& buffer)
{
    glGenVertexArrays(1, &buffer.vao);
    glBindVertexArray(buffer.vao);

    glGenBuffers(1, &buffer.vbo);
    glBindBuffer(GL_ARRAY_BUFFER, buffer.vbo);

    glVertexPointer  (2, GL_FLOAT, sizeof(Vertex), (void*)(0*sizeof(float)));
    glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), (void*)(2*sizeof(float)));
    glColorPointer   (4, GL_FLOAT, sizeof(Vertex), (void*)(4*sizeof(float)));

    glEnableClientState(GL_VERTEX_ARRAY       );
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY        );
}

FILDEF void free_vertex_buffer (Vertex_Buffer& buffer)
{
    if (glDeleteVertexArrays) glDeleteVertexArrays(1, &buffer.vao);
    if (glDeleteBuffers) glDeleteBuffers(1, &buffer.vbo);

    buffer.verts.clear();
}

FILDEF void put_buffer_vertex (Vertex_Buffer& buffer, Vertex v)
{
    buffer.verts.push_back(v);
}

FILDEF void draw_vertex_buffer (Vertex_Buffer& buffer, Buffer_Mode mode)
{
    if (buffer.verts.empty()) return;

    glBindVertexArray(buffer.vao);
    glBindBuffer(GL_ARRAY_BUFFER, buffer.vbo);

    GLsizeiptr size = buffer.verts.size() * sizeof(Vertex);
    glBufferData(GL_ARRAY_BUFFER, size, &buffer.verts[0], GL_DYNAMIC_DRAW);

    glDrawArrays(CAST(GLenum, mode), 0, CAST(GLsizei, buffer.verts.size()));
}

FILDEF void clear_vertex_buffer (Vertex_Buffer& buffer)
{
    buffer.verts.clear();
}
