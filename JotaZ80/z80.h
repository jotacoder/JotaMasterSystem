/** JotaMasterSystem: A Master System Emulator
 * Copyright (c) Juan José Chica <jotacoder@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
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
