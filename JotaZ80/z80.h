/** JotaMasterSystem: A Master System Emulator
 * Copyright (c) Juan José Chica <jotacoder@gmail.com>
 * Insert MIT license here.
 */

#ifndef Z80_H
#define Z80_H

#include "types.h"
#include "Memory.h"
namespace jota
{

class Z80
{
public:
  Z80();

  /// Do 1 instrucction cycle.
  void run();

private:
  /// Fetch the instruction or operand from memory
  uint8 fetch();

  /// Decode and execute an intruction.
  int decodeAndExecute(const uint8 &opcode);

  /// Decode and execute an intruction for 0xDD SubOpcode.
  int decodeAndExecuteDD(const uint8 &subopcode);

  /// Decode and execute an intruction for 0xFD SubOpcode.
  int decodeAndExecuteFD(const uint8 &subopcode);


public: //private

  Memory        m_memory;         ///< 64K bytes of memory

  RegistersZ80  m_main;           ///< Main registers
  RegistersZ80  m_alternatives;   ///< Alternative registers
  IndexZ80      m_index;          ///< Index registers
  uint16        m_PC;             ///< Program counter
  uint16        m_SP;             ///< Stack pointer

};

}
#endif // Z80_H
