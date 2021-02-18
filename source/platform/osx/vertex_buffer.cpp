FILDEF void create_vertex_buffer (Vertex_Buffer& buffer)
{
    glGenVertexArrays(1, &buffer.vao);
    glBindVertexArray(buffer.vao);

    glGenBuffers(1, &buffer.vbo);
    glBindBuffer(GL_ARRAY_BUFFER, buffer.vbo);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), CAST(void*, offsetof(Vertex, position)));
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), CAST(void*, offsetof(Vertex, texcoord)));
    glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), CAST(void*, offsetof(Vertex, outcolor)));

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
}
FILDEF void free_vertex_buffer (Vertex_Buffer& buffer)
{
    glDeleteVertexArrays(1, &buffer.vao);
    glDeleteBuffers(1, &buffer.vbo);
    buffer.verts.clear();
}

FILDEF void put_buffer_vertex (Vertex_Buffer& buffer, Vertex vertex)
{
    buffer.verts.push_back(vertex);
}

FILDEF void draw_vertex_buffer (Vertex_Buffer& buffer, Buffer_Mode mode)
{
    if (buffer.verts.empty()) return; // There's nothing to draw.
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
