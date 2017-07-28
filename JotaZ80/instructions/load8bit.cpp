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

int Z80::ld_A_A()
{
  registers().A = registers().A;
  return 4;
}

int Z80::ld_A_B()
{
  registers().A = registers().B;
  return 4;
}

int Z80::ld_A_C()
{
  registers().A = registers().C;
  return 4;
}

int Z80::ld_A_D()
{
  registers().A = registers().D;
  return 4;
}

int Z80::ld_A_E()
{
  registers().A = registers().E;
  return 4;
}
int Z80::ld_A_H()
{
  registers().A = registers().H;
  return 4;
}

int Z80::ld_A_L()
{
  registers().A = registers().L;
  return 4;
}

int Z80::ld_B_A()
{
  registers().B = registers().A;
  return 4;
}

int Z80::ld_B_B()
{
  registers().B = registers().B;
  return 4;
}

int Z80::ld_B_C()
{
  registers().B = registers().C;
  return 4;
}

int Z80::ld_B_D()
{
  registers().B = registers().D;
  return 4;
}

int Z80::ld_B_E()
{
  registers().B = registers().E;
  return 4;
}
int Z80::ld_B_H()
{
  registers().B = registers().H;
  return 4;
}

int Z80::ld_B_L()
{
  registers().B = registers().L;
  return 4;
}

int Z80::ld_C_A()
{
  registers().C = registers().A;
  return 4;
}

int Z80::ld_C_B()
{
  registers().C = registers().B;
  return 4;
}

int Z80::ld_C_C()
{
  registers().C = registers().C;
  return 4;
}

int Z80::ld_C_D()
{
  registers().C = registers().D;
  return 4;
}

int Z80::ld_C_E()
{
  registers().C = registers().E;
  return 4;
}
int Z80::ld_C_H()
{
  registers().C = registers().H;
  return 4;
}

int Z80::ld_C_L()
{
  registers().C = registers().L;
  return 4;
}

int Z80::ld_D_A()
{
  registers().D = registers().A;
  return 4;
}

int Z80::ld_D_B()
{
  registers().D = registers().B;
  return 4;
}

int Z80::ld_D_C()
{
  registers().D = registers().C;
  return 4;
}

int Z80::ld_D_D()
{
  registers().D = registers().D;
  return 4;
}

int Z80::ld_D_E()
{
  registers().D = registers().E;
  return 4;
}
int Z80::ld_D_H()
{
  registers().D = registers().H;
  return 4;
}

int Z80::ld_D_L()
{
  registers().D = registers().L;
  return 4;
}

int Z80::ld_E_A()
{
  registers().E = registers().A;
  return 4;
}

int Z80::ld_E_B()
{
  registers().E = registers().B;
  return 4;
}

int Z80::ld_E_C()
{
  registers().E = registers().C;
  return 4;
}

int Z80::ld_E_D()
{
  registers().E = registers().D;
  return 4;
}

int Z80::ld_E_E()
{
  registers().E = registers().E;
  return 4;
}
int Z80::ld_E_H()
{
  registers().E = registers().H;
  return 4;
}

int Z80::ld_E_L()
{
  registers().E = registers().L;
  return 4;
}

int Z80::ld_H_A()
{
  registers().H = registers().A;
  return 4;
}

int Z80::ld_H_B()
{
  registers().H = registers().B;
  return 4;
}

int Z80::ld_H_C()
{
  registers().H = registers().C;
  return 4;
}

int Z80::ld_H_D()
{
  registers().H = registers().D;
  return 4;
}

int Z80::ld_H_E()
{
  registers().H = registers().E;
  return 4;
}
int Z80::ld_H_H()
{
  registers().H = registers().H;
  return 4;
}

int Z80::ld_H_L()
{
  registers().H = registers().L;
  return 4;
}

int Z80::ld_L_A()
{
  registers().L = registers().A;
  return 4;
}

int Z80::ld_L_B()
{
  registers().L = registers().B;
  return 4;
}

int Z80::ld_L_C()
{
  registers().L = registers().C;
  return 4;
}

int Z80::ld_L_D()
{
  registers().L = registers().D;
  return 4;
}

int Z80::ld_L_E()
{
  registers().L = registers().E;
  return 4;
}
int Z80::ld_L_H()
{
  registers().L = registers().H;
  return 4;
}

int Z80::ld_L_L()
{
  registers().L = registers().L;
  return 4;
}

//   ld r, n
//--------------------
int Z80::ld_A_n()
{
  uint8 n = fetch();
  registers().A = n;
  return 7;
}

int Z80::ld_B_n()
{
  uint8 n = fetch();
  registers().B = n;
  return 7;
}

int Z80::ld_C_n()
{
  uint8 n = fetch();
  registers().C = n;
  return 7;
}

int Z80::ld_D_n()
{
  uint8 n = fetch();
  registers().D = n;
  return 7;
}

int Z80::ld_E_n()
{
  uint8 n = fetch();
  registers().E = n;
  return 7;
}

int Z80::ld_H_n()
{
  uint8 n = fetch();
  registers().H = n;
  return 7;
}

int Z80::ld_L_n()
{
  uint8 n = fetch();
  registers().L = n;
  return 7;
}

int Z80::ld_A_$HL$()
{
  uint8 v = m_memory->read(registers().HL);
  registers().A = v;
  return 7;
}

int Z80::ld_B_$HL$()
{
  uint8 v = m_memory->read(registers().HL);
  registers().B = v;
  return 7;
}
int Z80::ld_C_$HL$()
{
  uint8 v = m_memory->read(registers().HL);
  registers().C = v;
  return 7;
}

int Z80::ld_D_$HL$()
{
  uint8 v = m_memory->read(registers().HL);
  registers().D = v;
  return 7;
}

int Z80::ld_E_$HL$()
{
  uint8 v = m_memory->read(registers().HL);
  registers().E = v;
  return 7;
}

int Z80::ld_H_$HL$()
{
  uint8 v = m_memory->read(registers().HL);
  registers().H = v;
  return 7;
}

int Z80::ld_L_$HL$()
{
  uint8 v = m_memory->read(registers().HL);
  registers().L = v;
  return 7;
}

int Z80::ld_A_$IX_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(indexation().IX + d);
  registers().A = v;
  return 19;
}

int Z80::ld_B_$IX_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(indexation().IX + d);
  registers().B = v;
  return 19;
}

int Z80::ld_C_$IX_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(indexation().IX + d);
  registers().C = v;
  return 19;
}

int Z80::ld_D_$IX_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(indexation().IX + d);
  registers().D = v;
  return 19;
}

int Z80::ld_E_$IX_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(indexation().IX + d);
  registers().E = v;
  return 19;
}

int Z80::ld_H_$IX_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(indexation().IX + d);
  registers().H = v;
  return 19;
}

int Z80::ld_L_$IX_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(indexation().IX + d);
  registers().L = v;
  return 19;
}


int Z80::ld_A_$IY_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(indexation().IY + d);
  registers().A = v;
  return 19;
}

int Z80::ld_B_$IY_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(indexation().IY + d);
  registers().B = v;
  return 19;
}

int Z80::ld_C_$IY_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(indexation().IY + d);
  registers().C = v;
  return 19;
}

int Z80::ld_D_$IY_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(indexation().IY + d);
  registers().D = v;
  return 19;
}

int Z80::ld_E_$IY_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(indexation().IY + d);
  registers().E = v;
  return 19;
}

int Z80::ld_H_$IY_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(indexation().IY + d);
  registers().H = v;
  return 19;
}

int Z80::ld_L_$IY_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(indexation().IY + d);
  registers().L = v;
  return 19;
}

int Z80::ld_$HL$_A()
{
  m_memory->write(registers().HL, registers().A);
  return 7;
}

int Z80::ld_$HL$_B()
{
  m_memory->write(registers().HL, registers().B);
  return 7;
}

int Z80::ld_$HL$_C()
{
  m_memory->write(registers().HL, registers().C);
  return 7;
}

int Z80::ld_$HL$_D()
{
  m_memory->write(registers().HL, registers().D);
  return 7;
}

int Z80::ld_$HL$_E()
{
  m_memory->write(registers().HL, registers().E);
  return 7;
}

int Z80::ld_$HL$_H()
{
  m_memory->write(registers().HL, registers().H);
  return 7;
}

int Z80::ld_$HL$_L()
{
  m_memory->write(registers().HL, registers().L);
  return 7;
}

int Z80::ld_$IX_plus_d$_A()
{
  int8_t d = fetch();
  m_memory->write(indexation().IX + d, registers().A);
  return 19;
}

int Z80::ld_$IX_plus_d$_B()
{
  int8_t d = fetch();
  m_memory->write(indexation().IX + d, registers().B);
  return 19;
}

int Z80::ld_$IX_plus_d$_C()
{
  int8_t d = fetch();
  m_memory->write(indexation().IX + d, registers().C);
  return 19;
}

int Z80::ld_$IX_plus_d$_D()
{
  int8_t d = fetch();
  m_memory->write(indexation().IX + d, registers().D);
  return 19;
}

int Z80::ld_$IX_plus_d$_E()
{
  int8_t d = fetch();
  m_memory->write(indexation().IX + d, registers().E);
  return 19;
}

int Z80::ld_$IX_plus_d$_H()
{
  int8_t d = fetch();
  m_memory->write(indexation().IX + d, registers().H);
  return 19;
}

int Z80::ld_$IX_plus_d$_L()
{
  int8_t d = fetch();
  m_memory->write(indexation().IX + d, registers().L);
  return 19;
}

int Z80::ld_$IY_plus_d$_A()
{
  int8_t d = fetch();
  m_memory->write(indexation().IY + d, registers().A);
  return 19;
}

int Z80::ld_$IY_plus_d$_B()
{
  int8_t d = fetch();
  m_memory->write(indexation().IY + d, registers().B);
  return 19;
}

int Z80::ld_$IY_plus_d$_C()
{
  int8_t d = fetch();
  m_memory->write(indexation().IY + d, registers().C);
  return 19;
}

int Z80::ld_$IY_plus_d$_D()
{
  int8_t d = fetch();
  m_memory->write(indexation().IY + d, registers().D);
  return 19;
}

int Z80::ld_$IY_plus_d$_E()
{
  int8_t d = fetch();
  m_memory->write(indexation().IY + d, registers().E);
  return 19;
}

int Z80::ld_$IY_plus_d$_H()
{
  int8_t d = fetch();
  m_memory->write(indexation().IY + d, registers().H);
  return 19;
}

int Z80::ld_$IY_plus_d$_L()
{
  int8_t d = fetch();
  m_memory->write(indexation().IY + d, registers().L);
  return 19;
}
int Z80::ld_$HL$_n()
{
  uint8 n = fetch();
  m_memory->write(registers().HL, n);
  return 10;
}

int Z80::ld_$IX_plus_d$_n()
{
  int8_t d = fetch();
  uint8 n = fetch();
  m_memory->write(indexation().IX + d, n);
  return 19;
}

int Z80::ld_$IY_plus_d$_n()
{
  int8_t d = fetch();
  uint8 n = fetch();
  m_memory->write(indexation().IY + d, n);
  return 19;
}

int Z80::ld_A_$BC$()
{
  uint8 v = m_memory->read(registers().BC);
  registers().A = v;
  return 7;
}

int Z80::ld_A_$DE$()
{
  uint8 v = m_memory->read(registers().DE);
  registers().A = v;
  return 7;
}

int Z80::ld_A_$nn$()
{
  uint8 low = fetch();
  uint8 high = fetch();

  uint16 address = make16(high, low);

  uint8 v = m_memory->read(address);
  registers().A = v;
  return 13;
}

int Z80::ld_$BC$_A()
{
  m_memory->write(registers().BC, registers().A);
  return 7;
}

int Z80::ld_$DE$_A()
{
  m_memory->write(registers().DE, registers().A);
  return 7;
}

int Z80::ld_$nn$_A()
{
  uint8 low = fetch();
  uint8 high = fetch();

  uint16 address = make16(high, low);

  m_memory->write(address, registers().A);
  return 13;
}

int Z80::ld_A_I()
{
  registers().A = interrupt();
  return 9;
}

int Z80::ld_A_R()
{
  registers().A = refresh();
  return 9;
}

int Z80::ld_I_A()
{
  interrupt() = registers().A;
  return 9;
}

int Z80::ld_R_A()
{
  refresh() = registers().A;
  return 9;
}


}

