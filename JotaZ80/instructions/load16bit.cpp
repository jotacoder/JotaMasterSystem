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
#include "utils.h"

namespace jota
{

int Z80::ld_BC_nn()
{
  uint8 low = fetch();
  uint8 high = fetch();

  uint16 value = make16(high, low);
  registers().BC = value;
  return 10;
}

int Z80::ld_DE_nn()
{
  uint8 low = fetch();
  uint8 high = fetch();

  uint16 value = make16(high, low);
  registers().DE = value;
  return 10;
}

int Z80::ld_HL_nn()
{
  uint8 low = fetch();
  uint8 high = fetch();

  uint16 value = make16(high, low);
  registers().HL = value;
  return 10;
}
int Z80::ld_SP_nn()
{
  uint8 low = fetch();
  uint8 high = fetch();

  uint16 value = make16(high, low);
  stack_pointer() = value;
  return 10;
}

int Z80::ld_IX_nn()
{
  uint8 low = fetch();
  uint8 high = fetch();

  uint16 value = make16(high, low);
  indexation().IX = value;
  return 14;
}

int Z80::ld_IY_nn()
{
  uint8 low = fetch();
  uint8 high = fetch();

  uint16 value = make16(high, low);
  indexation().IY = value;
  return 14;
}

int Z80::ld_HL_$nn$()
{
  uint8 low = fetch();
  uint8 high = fetch();

  uint16 address = make16(high, low);

  registers().L = m_memory->read(address);
  registers().H = m_memory->read(address+1);

  return 16;
}

int Z80::ld_BC_$nn$()
{
  uint8 low = fetch();
  uint8 high = fetch();

  uint16 address = make16(high, low);

  registers().C = m_memory->read(address);
  registers().B = m_memory->read(address+1);

  return 20;
}

int Z80::ld_DE_$nn$()
{
  uint8 low = fetch();
  uint8 high = fetch();

  uint16 address = make16(high, low);

  registers().E = m_memory->read(address);
  registers().D = m_memory->read(address+1);

  return 20;
}

int Z80::ld_HL_$nn$2()
{
  uint8 low = fetch();
  uint8 high = fetch();

  uint16 address = make16(high, low);

  registers().L = m_memory->read(address);
  registers().H = m_memory->read(address+1);

  return 20;
}

int Z80::ld_SP_$nn$()
{
  uint8 low = fetch();
  uint8 high = fetch();

  uint16 address = make16(high, low);

  low = m_memory->read(address);
  high = m_memory->read(address+1);

  stack_pointer() =  make16(high, low);

  return 20;
}


int Z80::ld_IX_$nn$()
{
  uint8 low = fetch();
  uint8 high = fetch();

  uint16 address = make16(high, low);

  low = m_memory->read(address);
  high = m_memory->read(address+1);

  indexation().IX =  make16(high, low);

  return 20;
}

int Z80::ld_IY_$nn$()
{
  uint8 low = fetch();
  uint8 high = fetch();

  uint16 address = make16(high, low);

  low = m_memory->read(address);
  high = m_memory->read(address+1);

  indexation().IY =  make16(high, low);

  return 20;
}

int Z80::ld_$nn$_HL()
{
  uint8 low = fetch();
  uint8 high = fetch();

  uint16 address = make16(high, low);

  m_memory->write(address, registers().L);
  m_memory->write(address+1, registers().H);

  return 16;
}

int Z80::ld_$nn$_BC()
{
  uint8 low = fetch();
  uint8 high = fetch();

  uint16 address = make16(high, low);

  m_memory->write(address, registers().C);
  m_memory->write(address+1, registers().B);

  return 20;
}

int Z80::ld_$nn$_DE()
{
  uint8 low = fetch();
  uint8 high = fetch();

  uint16 address = make16(high, low);

  m_memory->write(address, registers().E);
  m_memory->write(address+1, registers().D);

  return 20;
}

int Z80::ld_$nn$_HL2()
{
  uint8 low = fetch();
  uint8 high = fetch();

  uint16 address = make16(high, low);

  m_memory->write(address, registers().L);
  m_memory->write(address+1, registers().H);

  return 20;
}

int Z80::ld_$nn$_SP()
{
  uint8 low = fetch();
  uint8 high = fetch();

  uint16 address = make16(high, low);

  m_memory->write(address, extractLow(stack_pointer()));
  m_memory->write(address+1, extractHigh(stack_pointer()));

  return 20;
}

int Z80::ld_$nn$_IX()
{
  uint8 low = fetch();
  uint8 high = fetch();

  uint16 address = make16(high, low);

  m_memory->write(address, indexation().IXl);
  m_memory->write(address+1, indexation().IXh);

  return 20;
}

int Z80::ld_$nn$_IY()
{
  uint8 low = fetch();
  uint8 high = fetch();

  uint16 address = make16(high, low);

  m_memory->write(address, indexation().IYl);
  m_memory->write(address+1, indexation().IYh);

  return 20;
}

int Z80::ld_SP_HL()
{
  stack_pointer() = registers().HL;
  return 6;
}

int Z80::ld_SP_IX()
{
  stack_pointer() = indexation().IX;
  return 10;
}

int Z80::ld_SP_IY()
{
  stack_pointer() = indexation().IY;
  return 10;
}


}
