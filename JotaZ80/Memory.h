#ifndef MEMORY_H
#define MEMORY_H


#include "types.h"
namespace jota
{

class Memory
{
public:
  Memory();

  void write(const uint16 &address, const uint8 &value);
  const uint8 &read(const uint16 &address) const ;

private:
    uint8 m_memory[65536];  ///< 64K bytes of memory

};

}


#endif // MEMORY_H
