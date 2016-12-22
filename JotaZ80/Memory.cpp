#include "Memory.h"
namespace jota
{

Memory::Memory()
{

}


void Memory::write(const uint16 &address, const uint8 &value)
{
  m_memory[address] = value;
}

const uint8& Memory::read(const uint16 &address) const
{
  return m_memory[address];
}

}
