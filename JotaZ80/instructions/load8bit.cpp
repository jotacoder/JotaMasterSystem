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

namespace jota
{

int Z80::ld_A_A()
{
  m_main.A = m_main.A;
  return 4;
}

int Z80::ld_A_B()
{
  m_main.A = m_main.B;
  return 4;
}

int Z80::ld_A_C()
{
  m_main.A = m_main.C;
  return 4;
}

int Z80::ld_A_D()
{
  m_main.A = m_main.D;
  return 4;
}

int Z80::ld_A_E()
{
  m_main.A = m_main.E;
  return 4;
}
int Z80::ld_A_H()
{
  m_main.A = m_main.H;
  return 4;
}

int Z80::ld_A_L()
{
  m_main.A = m_main.L;
  return 4;
}

int Z80::ld_B_A()
{
  m_main.B = m_main.A;
  return 4;
}

int Z80::ld_B_B()
{
  m_main.B = m_main.B;
  return 4;
}

int Z80::ld_B_C()
{
  m_main.B = m_main.C;
  return 4;
}

int Z80::ld_B_D()
{
  m_main.B = m_main.D;
  return 4;
}

int Z80::ld_B_E()
{
  m_main.B = m_main.E;
  return 4;
}
int Z80::ld_B_H()
{
  m_main.B = m_main.H;
  return 4;
}

int Z80::ld_B_L()
{
  m_main.B = m_main.L;
  return 4;
}

int Z80::ld_C_A()
{
  m_main.C = m_main.A;
  return 4;
}

int Z80::ld_C_B()
{
  m_main.C = m_main.B;
  return 4;
}

int Z80::ld_C_C()
{
  m_main.C = m_main.C;
  return 4;
}

int Z80::ld_C_D()
{
  m_main.C = m_main.D;
  return 4;
}

int Z80::ld_C_E()
{
  m_main.C = m_main.E;
  return 4;
}
int Z80::ld_C_H()
{
  m_main.C = m_main.H;
  return 4;
}

int Z80::ld_C_L()
{
  m_main.C = m_main.L;
  return 4;
}

int Z80::ld_D_A()
{
  m_main.D = m_main.A;
  return 4;
}

int Z80::ld_D_B()
{
  m_main.D = m_main.B;
  return 4;
}

int Z80::ld_D_C()
{
  m_main.D = m_main.C;
  return 4;
}

int Z80::ld_D_D()
{
  m_main.D = m_main.D;
  return 4;
}

int Z80::ld_D_E()
{
  m_main.D = m_main.E;
  return 4;
}
int Z80::ld_D_H()
{
  m_main.D = m_main.H;
  return 4;
}

int Z80::ld_D_L()
{
  m_main.D = m_main.L;
  return 4;
}

int Z80::ld_E_A()
{
  m_main.E = m_main.A;
  return 4;
}

int Z80::ld_E_B()
{
  m_main.E = m_main.B;
  return 4;
}

int Z80::ld_E_C()
{
  m_main.E = m_main.C;
  return 4;
}

int Z80::ld_E_D()
{
  m_main.E = m_main.D;
  return 4;
}

int Z80::ld_E_E()
{
  m_main.E = m_main.E;
  return 4;
}
int Z80::ld_E_H()
{
  m_main.E = m_main.H;
  return 4;
}

int Z80::ld_E_L()
{
  m_main.E = m_main.L;
  return 4;
}

int Z80::ld_H_A()
{
  m_main.H = m_main.A;
  return 4;
}

int Z80::ld_H_B()
{
  m_main.H = m_main.B;
  return 4;
}

int Z80::ld_H_C()
{
  m_main.H = m_main.C;
  return 4;
}

int Z80::ld_H_D()
{
  m_main.H = m_main.D;
  return 4;
}

int Z80::ld_H_E()
{
  m_main.H = m_main.E;
  return 4;
}
int Z80::ld_H_H()
{
  m_main.H = m_main.H;
  return 4;
}

int Z80::ld_H_L()
{
  m_main.H = m_main.L;
  return 4;
}

int Z80::ld_L_A()
{
  m_main.L = m_main.A;
  return 4;
}

int Z80::ld_L_B()
{
  m_main.L = m_main.B;
  return 4;
}

int Z80::ld_L_C()
{
  m_main.L = m_main.C;
  return 4;
}

int Z80::ld_L_D()
{
  m_main.L = m_main.D;
  return 4;
}

int Z80::ld_L_E()
{
  m_main.L = m_main.E;
  return 4;
}
int Z80::ld_L_H()
{
  m_main.L = m_main.H;
  return 4;
}

int Z80::ld_L_L()
{
  m_main.L = m_main.L;
  return 4;
}

//   ld r, n
//--------------------
int Z80::ld_A_n()
{
  uint8 n = fetch();
  m_main.A = n;
  return 7;
}

int Z80::ld_B_n()
{
  uint8 n = fetch();
  m_main.B = n;
  return 7;
}

int Z80::ld_C_n()
{
  uint8 n = fetch();
  m_main.C = n;
  return 7;
}

int Z80::ld_D_n()
{
  uint8 n = fetch();
  m_main.D = n;
  return 7;
}

int Z80::ld_E_n()
{
  uint8 n = fetch();
  m_main.E = n;
  return 7;
}

int Z80::ld_H_n()
{
  uint8 n = fetch();
  m_main.H = n;
  return 7;
}

int Z80::ld_L_n()
{
  uint8 n = fetch();
  m_main.L = n;
  return 7;
}

int Z80::ld_A_$HL$()
{
  uint8 v = m_memory->read(m_main.HL);
  m_main.A = v;
  return 7;
}

int Z80::ld_B_$HL$()
{
  uint8 v = m_memory->read(m_main.HL);
  m_main.B = v;
  return 7;
}
int Z80::ld_C_$HL$()
{
  uint8 v = m_memory->read(m_main.HL);
  m_main.C = v;
  return 7;
}

int Z80::ld_D_$HL$()
{
  uint8 v = m_memory->read(m_main.HL);
  m_main.D = v;
  return 7;
}

int Z80::ld_E_$HL$()
{
  uint8 v = m_memory->read(m_main.HL);
  m_main.E = v;
  return 7;
}

int Z80::ld_H_$HL$()
{
  uint8 v = m_memory->read(m_main.HL);
  m_main.H = v;
  return 7;
}

int Z80::ld_L_$HL$()
{
  uint8 v = m_memory->read(m_main.HL);
  m_main.L = v;
  return 7;
}

int Z80::ld_A_$IX_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(m_index.IX + d);
  m_main.A = v;
  return 19;
}

int Z80::ld_B_$IX_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(m_index.IX + d);
  m_main.B = v;
  return 19;
}

int Z80::ld_C_$IX_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(m_index.IX + d);
  m_main.C = v;
  return 19;
}

int Z80::ld_D_$IX_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(m_index.IX + d);
  m_main.D = v;
  return 19;
}

int Z80::ld_E_$IX_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(m_index.IX + d);
  m_main.E = v;
  return 19;
}

int Z80::ld_H_$IX_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(m_index.IX + d);
  m_main.H = v;
  return 19;
}

int Z80::ld_L_$IX_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(m_index.IX + d);
  m_main.L = v;
  return 19;
}


int Z80::ld_A_$IY_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(m_index.IY + d);
  m_main.A = v;
  return 19;
}

int Z80::ld_B_$IY_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(m_index.IY + d);
  m_main.B = v;
  return 19;
}

int Z80::ld_C_$IY_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(m_index.IY + d);
  m_main.C = v;
  return 19;
}

int Z80::ld_D_$IY_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(m_index.IY + d);
  m_main.D = v;
  return 19;
}

int Z80::ld_E_$IY_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(m_index.IY + d);
  m_main.E = v;
  return 19;
}

int Z80::ld_H_$IY_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(m_index.IY + d);
  m_main.H = v;
  return 19;
}

int Z80::ld_L_$IY_plus_d$()
{
  int8_t d = fetch();
  uint8 v = m_memory->read(m_index.IY + d);
  m_main.L = v;
  return 19;
}

int Z80::ld_$HL$_A()
{
  m_memory->write(m_main.HL, m_main.A);
  return 7;
}

int Z80::ld_$HL$_B()
{
  m_memory->write(m_main.HL, m_main.B);
  return 7;
}

int Z80::ld_$HL$_C()
{
  m_memory->write(m_main.HL, m_main.C);
  return 7;
}

int Z80::ld_$HL$_D()
{
  m_memory->write(m_main.HL, m_main.D);
  return 7;
}

int Z80::ld_$HL$_E()
{
  m_memory->write(m_main.HL, m_main.E);
  return 7;
}

int Z80::ld_$HL$_H()
{
  m_memory->write(m_main.HL, m_main.H);
  return 7;
}

int Z80::ld_$HL$_L()
{
  m_memory->write(m_main.HL, m_main.L);
  return 7;
}

int Z80::ld_$IX_plus_d$_A()
{
  int8_t d = fetch();
  m_memory->write(m_index.IX + d, m_main.A);
  return 19;
}

int Z80::ld_$IX_plus_d$_B()
{
  int8_t d = fetch();
  m_memory->write(m_index.IX + d, m_main.B);
  return 19;
}

int Z80::ld_$IX_plus_d$_C()
{
  int8_t d = fetch();
  m_memory->write(m_index.IX + d, m_main.C);
  return 19;
}

int Z80::ld_$IX_plus_d$_D()
{
  int8_t d = fetch();
  m_memory->write(m_index.IX + d, m_main.D);
  return 19;
}

int Z80::ld_$IX_plus_d$_E()
{
  int8_t d = fetch();
  m_memory->write(m_index.IX + d, m_main.E);
  return 19;
}

int Z80::ld_$IX_plus_d$_H()
{
  int8_t d = fetch();
  m_memory->write(m_index.IX + d, m_main.H);
  return 19;
}

int Z80::ld_$IX_plus_d$_L()
{
  int8_t d = fetch();
  m_memory->write(m_index.IX + d, m_main.L);
  return 19;
}

int Z80::ld_$IY_plus_d$_A()
{
  int8_t d = fetch();
  m_memory->write(m_index.IY + d, m_main.A);
  return 19;
}

int Z80::ld_$IY_plus_d$_B()
{
  int8_t d = fetch();
  m_memory->write(m_index.IY + d, m_main.B);
  return 19;
}

int Z80::ld_$IY_plus_d$_C()
{
  int8_t d = fetch();
  m_memory->write(m_index.IY + d, m_main.C);
  return 19;
}

int Z80::ld_$IY_plus_d$_D()
{
  int8_t d = fetch();
  m_memory->write(m_index.IY + d, m_main.D);
  return 19;
}

int Z80::ld_$IY_plus_d$_E()
{
  int8_t d = fetch();
  m_memory->write(m_index.IY + d, m_main.E);
  return 19;
}

int Z80::ld_$IY_plus_d$_H()
{
  int8_t d = fetch();
  m_memory->write(m_index.IY + d, m_main.H);
  return 19;
}

int Z80::ld_$IY_plus_d$_L()
{
  int8_t d = fetch();
  m_memory->write(m_index.IY + d, m_main.L);
  return 19;
}
int Z80::ld_$HL$_n()
{
  uint8 n = fetch();
  m_memory->write(m_main.HL, n);
  return 10;
}

int Z80::ld_$IX_plus_d$_n()
{
  int8_t d = fetch();
  uint8 n = fetch();
  m_memory->write(m_index.IX + d, n);
  return 19;
}

int Z80::ld_$IY_plus_d$_n()
{
  int8_t d = fetch();
  uint8 n = fetch();
  m_memory->write(m_index.IY + d, n);
  return 19;
}

int Z80::ld_A_$BC$()
{
  uint8 v = m_memory->read(m_main.BC);
  m_main.A = v;
  return 7;
}

int Z80::ld_A_$DE$()
{
  uint8 v = m_memory->read(m_main.DE);
  m_main.A = v;
  return 7;
}

}
