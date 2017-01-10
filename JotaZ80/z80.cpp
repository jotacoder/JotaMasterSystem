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

  uint8 n;    // valor en codigo
  uint8 v;    // valor de memoria
  int8_t d;    // desplazamiento de una direccion
  uint8 subopcode;

  switch (opcode)
  {
  case 0xDD:
    subopcode = fetch();
    ticks = decodeAndExecuteDD(subopcode);
    break;

  case 0xFD:
    subopcode = fetch();
    ticks = decodeAndExecuteFD(subopcode);
    break;


  //-------------------------
  //    Grupo Carga 8-bit
  //-------------------------

  //  LD R, R'
  case 0x7F: // LD A, A
    m_main.A = m_main.A;
    ticks = 4;
    break;

  case 0x78: // LD A, B
    m_main.A = m_main.B;
    ticks = 4;
    break;

  case 0x79: // LD A, C
    m_main.A = m_main.C;
    ticks = 4;
    break;

  case 0x7A: // LD A, D
    m_main.A = m_main.D;
    ticks = 4;
    break;

  case 0x7B: // LD A, E
    m_main.A = m_main.E;
    ticks = 4;
    break;

  case 0x7C: // LD A, H
    m_main.A = m_main.H;
    ticks = 4;
    break;

  case 0x7D: // LD A, L
    m_main.A = m_main.L;
    ticks = 4;
    break;

  case 0x47: // LD B, A
    m_main.B = m_main.A;
    ticks = 4;
    break;

  case 0x40: // LD B, B
    m_main.B = m_main.B;
    ticks = 4;
    break;

  case 0x41: // LD B, C
    m_main.B = m_main.C;
    ticks = 4;
    break;

  case 0x42: // LD B, D
    m_main.B = m_main.D;
    ticks = 4;
    break;

  case 0x43: // LD B, E
    m_main.B = m_main.E;
    ticks = 4;
    break;

  case 0x44: // LD B, H
    m_main.B = m_main.H;
    ticks = 4;
    break;

  case 0x45: // LD B, L
    m_main.B = m_main.L;
    ticks = 4;
    break;

  case 0x4F: // LD C, A
    m_main.C = m_main.A;
    ticks = 4;
    break;

  case 0x48: // LD C, B
    m_main.C = m_main.B;
    ticks = 4;
    break;

  case 0x49: // LD C, C
    m_main.C = m_main.C;
    ticks = 4;
    break;

  case 0x4A: // LD C, D
    m_main.C = m_main.D;
    ticks = 4;
    break;

  case 0x4B: // LD C, E
    m_main.C = m_main.E;
    ticks = 4;
    break;

  case 0x4C: // LD C, H
    m_main.C = m_main.H;
    ticks = 4;
    break;

  case 0x4D: // LD C, L
    m_main.C = m_main.L;
    ticks = 4;
    break;

  case 0x57: // LD D, A
    m_main.D = m_main.A;
    ticks = 4;
    break;

  case 0x50: // LD D, B
    m_main.D = m_main.B;
    ticks = 4;
    break;

  case 0x51: // LD D, C
    m_main.D = m_main.C;
    ticks = 4;
    break;

  case 0x52: // LD D,D
    m_main.D = m_main.D;
    ticks = 4;
    break;

  case 0x53: // LD D, E
    m_main.D = m_main.E;
    ticks = 4;
    break;

  case 0x54: // LD D, H
    m_main.D = m_main.H;
    ticks = 4;
    break;

  case 0x55: // LD D, L
    m_main.D = m_main.L;
    ticks = 4;
    break;

  case 0x5F: // LD E, A
    m_main.E = m_main.A;
    ticks = 4;
    break;

  case 0x58: // LD E, B
    m_main.E = m_main.B;
    ticks = 4;
    break;

  case 0x59: // LD E, C
    m_main.E = m_main.C;
    ticks = 4;
    break;

  case 0x5A: // LD E, D
    m_main.E = m_main.D;
    ticks = 4;
    break;

  case 0x5B: // LD E, E
    m_main.E = m_main.E;
    ticks = 4;
    break;

  case 0x5C: // LD E, H
    m_main.E = m_main.H;
    ticks = 4;
    break;

  case 0x5D: // LD E, L
    m_main.E = m_main.L;
    ticks = 4;
    break;

  case 0x67: // LD H, A
    m_main.H = m_main.A;
    ticks = 4;
    break;

  case 0x60: // LD H, B
    m_main.H = m_main.B;
    ticks = 4;
    break;

  case 0x61: // LD H, C
    m_main.H = m_main.C;
    ticks = 4;
    break;

  case 0x62: // LD H, D
    m_main.H = m_main.D;
    ticks = 4;
    break;

  case 0x63: // LD H, E
    m_main.H = m_main.E;
    ticks = 4;
    break;

  case 0x64: // LD H, H
    m_main.H = m_main.H;
    ticks = 4;
    break;

  case 0x65: // LD H, L
    m_main.H = m_main.L;
    ticks = 4;
    break;

  case 0x6F: // LD L, A
    m_main.L = m_main.A;
    ticks = 4;
    break;

  case 0x68: // LD L, B
    m_main.L = m_main.B;
    ticks = 4;
    break;

  case 0x69: // LD L, C
    m_main.L = m_main.C;
    ticks = 4;
    break;

  case 0x6A: // LD L, D
    m_main.L = m_main.D;
    ticks = 4;
    break;

  case 0x6B: // LD L, E
    m_main.L = m_main.E;
    ticks = 4;
    break;

  case 0x6C: // LD L, H
    m_main.L = m_main.H;
    ticks = 4;
    break;

  case 0x6D: // LD L, L
    m_main.L = m_main.L;
    ticks = 4;
    break;


  // LD r, n
  case 0x3E: // LD A, n
    n = fetch();
    m_main.A = n;
    ticks = 7;
    break;

  case 0x06: // LD B, n
    n = fetch();
    m_main.B = n;
    ticks = 7;
    break;

  case 0x0E: // LD C, n
    n = fetch();
    m_main.C = n;
    ticks = 7;
    break;

  case 0x16: // LD D, n
    n = fetch();
    m_main.D = n;
    ticks = 7;
    break;

  case 0x1E: // LD E, n
    n = fetch();
    m_main.E = n;
    ticks = 7;
    break;

  case 0x26: // LD H, n
    n = fetch();
    m_main.H = n;
    ticks = 7;
    break;

  case 0x2E: // LD L, n
    n = fetch();
    m_main.L = n;
    ticks = 7;
    break;

  // LD r,(HL)
  case 0x7E: // LD A,(HL)
    v = m_memory->read(m_main.HL);
    m_main.A = v;
    ticks = 7;
    break;

  case 0x46: // LD B,(HL)
    v = m_memory->read(m_main.HL);
    m_main.B = v;
    ticks = 7;
    break;

  case 0x4E: // LD C,(HL)
    v = m_memory->read(m_main.HL);
    m_main.C = v;
    ticks = 7;
    break;

  case 0x56: // LD D,(HL)
    v = m_memory->read(m_main.HL);
    m_main.D = v;
    ticks = 7;
    break;

  case 0x5E: // LD E,(HL)
    v = m_memory->read(m_main.HL);
    m_main.E = v;
    ticks = 7;
    break;

  case 0x66: // LD H,(HL)
    v = m_memory->read(m_main.HL);
    m_main.H = v;
    ticks = 7;
    break;

  case 0x6E: // LD L,(HL)
    v = m_memory->read(m_main.HL);
    m_main.L = v;
    ticks = 7;
    break;

  // LD (HL), A
  case 0x77: // LD (HL), A
    m_memory->write(m_main.HL, m_main.A);
    ticks = 7;
    break;

  case 0x70: // LD (HL), B
    m_memory->write(m_main.HL, m_main.B);
    ticks = 7;
    break;

  case 0x71: // LD (HL), C
    m_memory->write(m_main.HL, m_main.C);
    ticks = 7;
    break;

  case 0x72: // LD (HL), D
    m_memory->write(m_main.HL, m_main.D);
    ticks = 7;
    break;

  case 0x73: // LD (HL), E
    m_memory->write(m_main.HL, m_main.E);
    ticks = 7;
    break;

  case 0x74: // LD (HL), H
    m_memory->write(m_main.HL, m_main.H);
    ticks = 7;
    break;

  case 0x75: // LD (HL), L
    m_memory->write(m_main.HL, m_main.L);
    ticks = 7;
    break;

  case 0x36: // LD (HL), n
    n = fetch();
    m_memory->write(m_main.HL, n);
    ticks = 10;
    break;

  case 0x0A: // LD A,(BC)
    v = m_memory->read(m_main.BC);
    m_main.A = v;
    ticks = 7;
    break;

  case 0x1A: // LD A,(DE)
    v = m_memory->read(m_main.DE);
    m_main.A = v;
    ticks = 7;
    break;

  default:
    break;
  }

  return ticks;
}


int Z80::decodeAndExecuteDD(const uint8 &subopcode)
{
  int ticks = 0;

  uint8 n;     // valor en codigo
  uint8 v;     // valor de memoria
  int8_t d;    // desplazamiento de una direccion

  switch (subopcode)
  {
  // LD r,(IX+d)
  case 0x7E:  // LD A,(IX+d)
    d = fetch();
    v = m_memory->read(m_index.IX + d);
    m_main.A = v;
    ticks = 19;
    break;

  case 0x46:  // LD B,(IX+d)
    d = fetch();
    v = m_memory->read(m_index.IX + d);
    m_main.B = v;
    ticks = 19;
    break;

  case 0x4E:  // LD C,(IX+d)
    d = fetch();
    v = m_memory->read(m_index.IX + d);
    m_main.C = v;
    ticks = 19;
    break;

  case 0x56:  // LD D,(IX+d)
    d = fetch();
    v = m_memory->read(m_index.IX + d);
    m_main.D = v;
    ticks = 19;
    break;

  case 0x5E:  // LD E,(IX+d)
    d = fetch();
    v = m_memory->read(m_index.IX + d);
    m_main.E = v;
    ticks = 19;
    break;

  case 0x66:  // LD H,(IX+d)
    d = fetch();
    v = m_memory->read(m_index.IX + d);
    m_main.H = v;
    ticks = 19;
    break;

  case 0x6E:  // LD L,(IX+d)
    d = fetch();
    v = m_memory->read(m_index.IX + d);
    m_main.L = v;
    ticks = 19;
    break;

  // LD r,(IX+d)
  case 0x77:  // LD A,(IX+d)
    d = fetch();
    m_memory->write(m_index.IX + d, m_main.A);
    ticks = 19;
    break;

  case 0x70:  // LD B,(IX+d)
    d = fetch();
    m_memory->write(m_index.IX + d, m_main.B);
    ticks = 19;
    break;

  case 0x71:  // LD C,(IX+d)
    d = fetch();
    m_memory->write(m_index.IX + d, m_main.C);
    ticks = 19;
    break;

  case 0x72:  // LD D,(IX+d)
    d = fetch();
    m_memory->write(m_index.IX + d, m_main.D);
    ticks = 19;
    break;

  case 0x73:  // LD E,(IX+d)
    d = fetch();
    m_memory->write(m_index.IX + d, m_main.E);
    ticks = 19;
    break;

  case 0x74:  // LD H,(IX+d)
    d = fetch();
    m_memory->write(m_index.IX + d, m_main.H);
    ticks = 19;
    break;

  case 0x75:  // LD A,(IX+d)
    d = fetch();
    m_memory->write(m_index.IX + d, m_main.L);
    ticks = 19;
    break;

  case 0x36: // LD (IX+d), n
    d = fetch();
    n = fetch();
    m_memory->write(m_index.IX + d, n);
    ticks = 19;
    break;






  default:
    break;
  }

  return ticks;
}


int Z80::decodeAndExecuteFD(const uint8 &subopcode)
{
  int ticks = 0;

  uint8 n;     // valor en codigo
  uint8 v;     // valor de memoria
  int8_t d;    // desplazamiento de una direccion

  switch (subopcode)
  {

  // LD r,(IY+d)
  case 0x7E:  // LD A,(IY+d)
    d = fetch();
    v = m_memory->read(m_index.IY + d);
    m_main.A = v;
    ticks = 19;
    break;

  case 0x46:  // LD B,(IY+d)
    d = fetch();
    v = m_memory->read(m_index.IY + d);
    m_main.B = v;
    ticks = 19;
    break;

  case 0x4E:  // LD C,(IY+d)
    d = fetch();
    v = m_memory->read(m_index.IY + d);
    m_main.C = v;
    ticks = 19;
    break;

  case 0x56:  // LD D,(IY+d)
    d = fetch();
    v = m_memory->read(m_index.IY + d);
    m_main.D = v;
    ticks = 19;
    break;

  case 0x5E:  // LD E,(IY+d)
    d = fetch();
    v = m_memory->read(m_index.IY + d);
    m_main.E = v;
    ticks = 19;
    break;

  case 0x66:  // LD H,(IY+d)
    d = fetch();
    v = m_memory->read(m_index.IY + d);
    m_main.H = v;
    ticks = 19;
    break;

  case 0x6E:  // LD L,(IY+d)
    d = fetch();
    v = m_memory->read(m_index.IY + d);
    m_main.L = v;
    ticks = 19;
    break;

  // LD r,(IY+d)
  case 0x77:  // LD A,(IY+d)
    d = fetch();
    m_memory->write(m_index.IY + d, m_main.A);
    ticks = 19;
    break;

  case 0x70:  // LD B,(IY+d)
    d = fetch();
    m_memory->write(m_index.IY + d, m_main.B);
    ticks = 19;
    break;

  case 0x71:  // LD C,(IY+d)
    d = fetch();
    m_memory->write(m_index.IY + d, m_main.C);
    ticks = 19;
    break;

  case 0x72:  // LD D,(IY+d)
    d = fetch();
    m_memory->write(m_index.IY + d, m_main.D);
    ticks = 19;
    break;

  case 0x73:  // LD E,(IY+d)
    d = fetch();
    m_memory->write(m_index.IY + d, m_main.E);
    ticks = 19;
    break;

  case 0x74:  // LD H,(IY+d)
    d = fetch();
    m_memory->write(m_index.IY + d, m_main.H);
    ticks = 19;
    break;

  case 0x75:  // LD A,(IY+d)
    d = fetch();
    m_memory->write(m_index.IY + d, m_main.L);
    ticks = 19;
    break;

  case 0x36: // LD (IY+d), n
    d = fetch();
    n = fetch();
    m_memory->write(m_index.IY + d, n);
    ticks = 19;
    break;

  default:
    break;
  }

  return ticks;
}

}
