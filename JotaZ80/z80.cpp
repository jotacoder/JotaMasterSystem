#include "z80.h"
namespace jota
{


Z80::Z80()
{

}

void Z80::run()
{
  uint8 opcode = fetch();
  decodeAndExecute(opcode);
}

uint8 Z80::fetch()
{
  uint8 data = m_memory[m_PC];
  m_PC++;
  return data;
}

int Z80::decodeAndExecute(const uint8 &opcode)
{
  int ticks = 0;

  switch (opcode) {
  case 0x00: // NOP
    ticks = 5; //random
    break;

  default:
    break;
  }

  return ticks;
}

}
