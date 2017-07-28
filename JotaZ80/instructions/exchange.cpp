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

#include <algorithm>

namespace jota
{

int Z80::ex_DE_HL()
{
  std::swap(registers().DE, registers().HL);

  return 4;
}

int Z80::ex_AF_AFalt()
{
  std::swap(registers().AF, alternatives().AF);

  return 4;
}

int Z80::exx()
{
  std::swap(registers().BC, alternatives().BC);
  std::swap(registers().DE, alternatives().DE);
  std::swap(registers().HL, alternatives().HL);

  return 4;
}

int Z80::ex_$SP$_HL()
{
  uint8 top = m_memory->read(stack_pointer());
  std::swap(top , registers().L);
  m_memory->write(stack_pointer(), top);

  uint8 top1 = m_memory->read(stack_pointer()+1);
  std::swap(top1 , registers().H);
  m_memory->write(stack_pointer()+1, top1);

  return 19;
}

int Z80::ex_$SP$_IX()
{
  uint8 top = m_memory->read(stack_pointer());
  std::swap(top , indexation().IXl);
  m_memory->write(stack_pointer(), top);

  uint8 top1 = m_memory->read(stack_pointer()+1);
  std::swap(top1 , indexation().IXh);
  m_memory->write(stack_pointer()+1, top1);

  return 23;
}

int Z80::ex_$SP$_IY()
{
  uint8 top = m_memory->read(stack_pointer());
  std::swap(top , indexation().IYl);
  m_memory->write(stack_pointer(), top);

  uint8 top1 = m_memory->read(stack_pointer()+1);
  std::swap(top1 , indexation().IYh);
  m_memory->write(stack_pointer()+1, top1);

  return 23;
}

}
