#include "renderer/GLVertexArray.h"

#include "renderer/GLCommon.h"

#include <GLEW/glew.h>

namespace mage
{
namespace graphics
{

// ------------------------------------------------------------------------------

GLVertexArray::GLVertexArray() { GLCall(glGenVertexArrays(1, &m_handle)); }

// ------------------------------------------------------------------------------

GLVertexArray::~GLVertexArray()
{
  if (m_handle != 0)
  {
    GLCall(glDeleteVertexArrays(1, &m_handle));
    m_handle = 0;
  }
}

// ------------------------------------------------------------------------------

GLVertexArray::GLVertexArray(GLVertexArray&& _moved)
    : m_handle(std::move(_moved.m_handle))
{
  _moved.m_handle = 0;
}

// ------------------------------------------------------------------------------

GLVertexArray& GLVertexArray::operator=(GLVertexArray&& _moved)
{
  m_handle = std::move(_moved.m_handle);
  _moved.m_handle = 0;
  return *this;
}

// ------------------------------------------------------------------------------

void GLVertexArray::AttachVertexBuffer(const GLVertexBuffer& _buffer,
                                       const GLBufferLayout& _layout) const
{
  Bind();
  _buffer.Bind();
  _layout.Apply();
  Unbind();
  _buffer.Unbind();
}

// ------------------------------------------------------------------------------

void GLVertexArray::Bind() const { GLCall(glBindVertexArray(m_handle)); }

// ------------------------------------------------------------------------------

void GLVertexArray::Unbind() const { GLCall(glBindVertexArray(0)); }

// ------------------------------------------------------------------------------

void GLVertexArray::Draw(std::uint32_t _count) const
{
  GLCall(glDrawElements(GL_TRIANGLES, _count, GL_UNSIGNED_INT, nullptr));
}

// ------------------------------------------------------------------------------

} // namespace graphics
} // namespace mage
