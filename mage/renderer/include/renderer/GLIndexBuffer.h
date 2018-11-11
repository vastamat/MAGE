#pragma once

#include <cstdint>

namespace mage
{
namespace graphics
{

// ------------------------------------------------------------------------------

class GLIndexBuffer
{
public:
  GLIndexBuffer();
  ~GLIndexBuffer();

  // ------------------------------------------------------------------------------

  void SetData(std::uint32_t* _data, std::uint32_t _count);

  // ------------------------------------------------------------------------------

  void SetData(std::uint16_t* _data, std::uint32_t _count);

  // ------------------------------------------------------------------------------

  void Bind() const;

  // ------------------------------------------------------------------------------

  void Unbind() const;

  // ------------------------------------------------------------------------------

  std::uint32_t GetCount() const noexcept;

  // ------------------------------------------------------------------------------

private:
  std::uint32_t m_handle;
  std::uint32_t m_count;
};

// ------------------------------------------------------------------------------

} // namespace graphics
} // namespace mage