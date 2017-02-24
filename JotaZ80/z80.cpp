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

#include "z80.h"
#include <assert.h>
namespace jota
{


Z80::Z80(Memory *memory): m_memory(memory)
{
  m_PC = 0;
  m_SP = 0;

  m_main.AF = 0;
  m_main.BC = 0;
  m_main.DE = 0;
  m_main.HL = 0;

  m_alternatives.AF = 0;
  m_alternatives.BC = 0;
  m_alternatives.DE = 0;
  m_alternatives.HL = 0;

  m_index.IX = 0;
  m_index.IY = 0;

  initializeDecodeTables();
}

int Z80::run()
{
  uint8 opcode = fetch();
  return decodeAndExecute(opcode);
}

uint8 Z80::fetch()
{
  uint8 data = m_memory->read(m_PC);
  m_PC++;
  return data;
}

int Z80::decodeAndExecute(const uint8 &opcode)
{
  int ticks = 0;

  assert(m_decodetable[opcode] != NULL);

  ticks = (this->*(m_decodetable[opcode]))();
  return ticks;
}

int Z80::decodeAndExecuteDD()
{
  uint8 subopcode = fetch();

  assert(m_decodetableDD[subopcode] != NULL);

  int ticks = (this->*(m_decodetableDD[subopcode]))();
  return ticks;
}

int Z80::decodeAndExecuteFD()
{
  uint8 subopcode = fetch();

  assert(m_decodetableDD[subopcode] != NULL);

  int ticks = (this->*(m_decodetableFD[subopcode]))();
  return ticks;
}

}
