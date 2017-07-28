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

int Z80::push_BC()
{
  stack_pointer()--;
  m_memory->write(stack_pointer(), registers().B);
  stack_pointer()--;
  m_memory->write(stack_pointer(), registers().C);

  return 11;
}

int Z80::push_DE()
{
  stack_pointer()--;
  m_memory->write(stack_pointer(), registers().D);
  stack_pointer()--;
  m_memory->write(stack_pointer(), registers().E);

  return 11;
}

int Z80::push_HL()
{
  stack_pointer()--;
  m_memory->write(stack_pointer(), registers().H);
  stack_pointer()--;
  m_memory->write(stack_pointer(), registers().L);

  return 11;
}

int Z80::push_AF()
{
  stack_pointer()--;
  m_memory->write(stack_pointer(), registers().A);
  stack_pointer()--;
  m_memory->write(stack_pointer(), registers().F);

  return 11;
}

int Z80::push_IX()
{
  stack_pointer()--;
  m_memory->write(stack_pointer(), indexation().IXh);
  stack_pointer()--;
  m_memory->write(stack_pointer(), indexation().IXl);

  return 15;
}

int Z80::push_IY()
{
  stack_pointer()--;
  m_memory->write(stack_pointer(), indexation().IYh);
  stack_pointer()--;
  m_memory->write(stack_pointer(), indexation().IYl);

  return 15;
}

int Z80::pop_BC()
{
 registers().C = m_memory->read(stack_pointer());
 stack_pointer()++;
 registers().B = m_memory->read(stack_pointer());
 stack_pointer()++;

 return 10;
}

int Z80::pop_DE()
{
 registers().E = m_memory->read(stack_pointer());
 stack_pointer()++;
 registers().D = m_memory->read(stack_pointer());
 stack_pointer()++;

 return 10;
}

int Z80::pop_HL()
{
 registers().L = m_memory->read(stack_pointer());
 stack_pointer()++;
 registers().H = m_memory->read(stack_pointer());
 stack_pointer()++;

 return 10;
}

int Z80::pop_AF()
{
 registers().F = m_memory->read(stack_pointer());
 stack_pointer()++;
 registers().A = m_memory->read(stack_pointer());
 stack_pointer()++;

 return 10;
}

int Z80::pop_IX()
{
 indexation().IXl = m_memory->read(stack_pointer());
 stack_pointer()++;
 indexation().IXh = m_memory->read(stack_pointer());
 stack_pointer()++;

 return 14;
}

int Z80::pop_IY()
{
 indexation().IYl = m_memory->read(stack_pointer());
 stack_pointer()++;
 indexation().IYh = m_memory->read(stack_pointer());
 stack_pointer()++;

 return 14;
}

}
