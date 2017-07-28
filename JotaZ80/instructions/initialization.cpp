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
#include <string.h>

namespace jota
{

void Z80::initializeDecodeTables()
{
  for(int i = 0; i < 256; ++i)
  {
     m_decodetable[i] = NULL;
     m_decodetableDD[i] = NULL;
     m_decodetableFD[i] = NULL;
     m_decodetableED[i] = NULL;
  }


  // Subocode tables
  m_decodetable[0xDD]   = &Z80::decodeAndExecuteDD;
  m_decodetable[0xFD]   = &Z80::decodeAndExecuteFD;
  m_decodetable[0xED]   = &Z80::decodeAndExecuteED;

  // LD r,r'
  m_decodetable[0x7F]   = &Z80::ld_A_A;
  m_decodetable[0x78]   = &Z80::ld_A_B;
  m_decodetable[0x79]   = &Z80::ld_A_C;
  m_decodetable[0x7A]   = &Z80::ld_A_D;
  m_decodetable[0x7B]   = &Z80::ld_A_E;
  m_decodetable[0x7C]   = &Z80::ld_A_H;
  m_decodetable[0x7D]   = &Z80::ld_A_L;
  m_decodetable[0x47]   = &Z80::ld_B_A;
  m_decodetable[0x40]   = &Z80::ld_B_B;
  m_decodetable[0x41]   = &Z80::ld_B_C;
  m_decodetable[0x42]   = &Z80::ld_B_D;
  m_decodetable[0x43]   = &Z80::ld_B_E;
  m_decodetable[0x44]   = &Z80::ld_B_H;
  m_decodetable[0x45]   = &Z80::ld_B_L;
  m_decodetable[0x4F]   = &Z80::ld_C_A;
  m_decodetable[0x48]   = &Z80::ld_C_B;
  m_decodetable[0x49]   = &Z80::ld_C_C;
  m_decodetable[0x4A]   = &Z80::ld_C_D;
  m_decodetable[0x4B]   = &Z80::ld_C_E;
  m_decodetable[0x4C]   = &Z80::ld_C_H;
  m_decodetable[0x4D]   = &Z80::ld_C_L;
  m_decodetable[0x57]   = &Z80::ld_D_A;
  m_decodetable[0x50]   = &Z80::ld_D_B;
  m_decodetable[0x51]   = &Z80::ld_D_C;
  m_decodetable[0x52]   = &Z80::ld_D_D;
  m_decodetable[0x53]   = &Z80::ld_D_E;
  m_decodetable[0x54]   = &Z80::ld_D_H;
  m_decodetable[0x55]   = &Z80::ld_D_L;
  m_decodetable[0x5F]   = &Z80::ld_E_A;
  m_decodetable[0x58]   = &Z80::ld_E_B;
  m_decodetable[0x59]   = &Z80::ld_E_C;
  m_decodetable[0x5A]   = &Z80::ld_E_D;
  m_decodetable[0x5B]   = &Z80::ld_E_E;
  m_decodetable[0x5C]   = &Z80::ld_E_H;
  m_decodetable[0x5D]   = &Z80::ld_E_L;
  m_decodetable[0x67]   = &Z80::ld_H_A;
  m_decodetable[0x60]   = &Z80::ld_H_B;
  m_decodetable[0x61]   = &Z80::ld_H_C;
  m_decodetable[0x62]   = &Z80::ld_H_D;
  m_decodetable[0x63]   = &Z80::ld_H_E;
  m_decodetable[0x64]   = &Z80::ld_H_H;
  m_decodetable[0x65]   = &Z80::ld_H_L;
  m_decodetable[0x6F]   = &Z80::ld_L_A;
  m_decodetable[0x68]   = &Z80::ld_L_B;
  m_decodetable[0x69]   = &Z80::ld_L_C;
  m_decodetable[0x6A]   = &Z80::ld_L_D;
  m_decodetable[0x6B]   = &Z80::ld_L_E;
  m_decodetable[0x6C]   = &Z80::ld_L_H;
  m_decodetable[0x6D]   = &Z80::ld_L_L;
  // LD r, n
  m_decodetable[0x3E]   = &Z80::ld_A_n;
  m_decodetable[0x06]   = &Z80::ld_B_n;
  m_decodetable[0x0E]   = &Z80::ld_C_n;
  m_decodetable[0x16]   = &Z80::ld_D_n;
  m_decodetable[0x1E]   = &Z80::ld_E_n;
  m_decodetable[0x26]   = &Z80::ld_H_n;
  m_decodetable[0x2E]   = &Z80::ld_L_n;
  // LD r, (HL)
  m_decodetable[0x7E]   = &Z80::ld_A_$HL$;
  m_decodetable[0x46]   = &Z80::ld_B_$HL$;
  m_decodetable[0x4E]   = &Z80::ld_C_$HL$;
  m_decodetable[0x56]   = &Z80::ld_D_$HL$;
  m_decodetable[0x5E]   = &Z80::ld_E_$HL$;
  m_decodetable[0x66]   = &Z80::ld_H_$HL$;
  m_decodetable[0x6E]   = &Z80::ld_L_$HL$;
  // LD r, (IX+d)
  m_decodetableDD[0x7E] = &Z80::ld_A_$IX_plus_d$;
  m_decodetableDD[0x46] = &Z80::ld_B_$IX_plus_d$;
  m_decodetableDD[0x4E] = &Z80::ld_C_$IX_plus_d$;
  m_decodetableDD[0x56] = &Z80::ld_D_$IX_plus_d$;
  m_decodetableDD[0x5E] = &Z80::ld_E_$IX_plus_d$;
  m_decodetableDD[0x66] = &Z80::ld_H_$IX_plus_d$;
  m_decodetableDD[0x6E] = &Z80::ld_L_$IX_plus_d$;
  // LD r, (IY+d)
  m_decodetableFD[0x7E] = &Z80::ld_A_$IY_plus_d$;
  m_decodetableFD[0x46] = &Z80::ld_B_$IY_plus_d$;
  m_decodetableFD[0x4E] = &Z80::ld_C_$IY_plus_d$;
  m_decodetableFD[0x56] = &Z80::ld_D_$IY_plus_d$;
  m_decodetableFD[0x5E] = &Z80::ld_E_$IY_plus_d$;
  m_decodetableFD[0x66] = &Z80::ld_H_$IY_plus_d$;
  m_decodetableFD[0x6E] = &Z80::ld_L_$IY_plus_d$;
  // LD (HL), r
  m_decodetable[0x77]   = &Z80::ld_$HL$_A;
  m_decodetable[0x70]   = &Z80::ld_$HL$_B;
  m_decodetable[0x71]   = &Z80::ld_$HL$_C;
  m_decodetable[0x72]   = &Z80::ld_$HL$_D;
  m_decodetable[0x73]   = &Z80::ld_$HL$_E;
  m_decodetable[0x74]   = &Z80::ld_$HL$_H;
  m_decodetable[0x75]   = &Z80::ld_$HL$_L;
  // LD (IX+d), r
  m_decodetableDD[0x77] = &Z80::ld_$IX_plus_d$_A;
  m_decodetableDD[0x70] = &Z80::ld_$IX_plus_d$_B;
  m_decodetableDD[0x71] = &Z80::ld_$IX_plus_d$_C;
  m_decodetableDD[0x72] = &Z80::ld_$IX_plus_d$_D;
  m_decodetableDD[0x73] = &Z80::ld_$IX_plus_d$_E;
  m_decodetableDD[0x74] = &Z80::ld_$IX_plus_d$_H;
  m_decodetableDD[0x75] = &Z80::ld_$IX_plus_d$_L;
  // LD (IY+d), r
  m_decodetableFD[0x77] = &Z80::ld_$IY_plus_d$_A;
  m_decodetableFD[0x70] = &Z80::ld_$IY_plus_d$_B;
  m_decodetableFD[0x71] = &Z80::ld_$IY_plus_d$_C;
  m_decodetableFD[0x72] = &Z80::ld_$IY_plus_d$_D;
  m_decodetableFD[0x73] = &Z80::ld_$IY_plus_d$_E;
  m_decodetableFD[0x74] = &Z80::ld_$IY_plus_d$_H;
  m_decodetableFD[0x75] = &Z80::ld_$IY_plus_d$_L;
  // LD (HL), n
  m_decodetable[0x36]   = &Z80::ld_$HL$_n;
  // LD (IX+d),n
  m_decodetableDD[0x36] = &Z80::ld_$IX_plus_d$_n;
  // LD (IY+d),n
  m_decodetableFD[0x36] = &Z80::ld_$IY_plus_d$_n;
  // LD A, (BC)
  m_decodetable[0x0A]   = &Z80::ld_A_$BC$;
  // LD A, (DE)
  m_decodetable[0x1A]   = &Z80::ld_A_$DE$;
  // LD A, (nn)
  m_decodetable[0x3A]   = &Z80::ld_A_$nn$;
  // LD (BC), A
  m_decodetable[0x02]   = &Z80::ld_$BC$_A;
  // LD (DE), A
  m_decodetable[0x12]   = &Z80::ld_$DE$_A;
  // LD (nn), A
  m_decodetable[0x32]   = &Z80::ld_$nn$_A;
  // LD A, I
  m_decodetableED[0x57] = &Z80::ld_A_I;
  // LD A, R
  m_decodetableED[0x5F] = &Z80::ld_A_R;
  // LD I, A
  m_decodetableED[0x47] = &Z80::ld_I_A;
  // LD R, A
  m_decodetableED[0x4F] = &Z80::ld_R_A;

  // Load 16 bit
  //-------------------
  //LD dd, nn
  m_decodetable[0x01]   = &Z80::ld_BC_nn;
  m_decodetable[0x11]   = &Z80::ld_DE_nn;
  m_decodetable[0x21]   = &Z80::ld_HL_nn;
  m_decodetable[0x31]   = &Z80::ld_SP_nn;  
  // LD IX, nn
  m_decodetableDD[0x21] = &Z80::ld_IX_nn;
  // LD IY, nn
  m_decodetableFD[0x21] = &Z80::ld_IY_nn;
  // LD HL, (nn)
  m_decodetable[0x2A] = &Z80::ld_HL_$nn$;
  // LD dd, (nn)
  m_decodetableED[0x4B] = &Z80::ld_BC_$nn$;
  m_decodetableED[0x5B] = &Z80::ld_DE_$nn$;
  m_decodetableED[0x6B] = &Z80::ld_HL_$nn$2;
  m_decodetableED[0x7B] = &Z80::ld_SP_$nn$;
  // LD IX, (nn)
  m_decodetableDD[0x2A] = &Z80::ld_IX_$nn$;
  // LD IY, (nn)
  m_decodetableFD[0x2A] = &Z80::ld_IY_$nn$;
  // LD (nn), HL
  m_decodetable[0x22]   = &Z80::ld_$nn$_HL;
  // LD (nn), dd
  m_decodetableED[0x43] = &Z80::ld_$nn$_BC;
  m_decodetableED[0x53] = &Z80::ld_$nn$_DE;
  m_decodetableED[0x63] = &Z80::ld_$nn$_HL2;
  m_decodetableED[0x73] = &Z80::ld_$nn$_SP;
  // LD (nn), IX
  m_decodetableDD[0x22] = &Z80::ld_$nn$_IX;
  // LD (nn), IY
  m_decodetableFD[0x22] = &Z80::ld_$nn$_IY;
  // LD SP, HL
  m_decodetable[0xF9]   = &Z80::ld_SP_HL;
  // LD SP, IX
  m_decodetableDD[0xF9] = &Z80::ld_SP_IX;
  // LD SP, IY
  m_decodetableFD[0xF9] = &Z80::ld_SP_IY;

  // Stack
  //-------------------
  // PUSH qq
  m_decodetable[0xC5]   = &Z80::push_BC;
  m_decodetable[0xD5]   = &Z80::push_DE;
  m_decodetable[0xE5]   = &Z80::push_HL;
  m_decodetable[0xF5]   = &Z80::push_AF;
  // PUSH IX
  m_decodetableDD[0xE5] = &Z80::push_IX;
  // PUSH IY
  m_decodetableFD[0xE5] = &Z80::push_IY;

  // POP BC
  m_decodetable[0xC1]   = &Z80::pop_BC;
  m_decodetable[0xD1]   = &Z80::pop_DE;
  m_decodetable[0xE1]   = &Z80::pop_HL;
  m_decodetable[0xF1]   = &Z80::pop_AF;
  // POP IX
  m_decodetableDD[0xE1] = &Z80::pop_IX;
  // POP IY
  m_decodetableFD[0xE1] = &Z80::pop_IY;

  // Exchange
  //------------------
  // EX DE, HL
  m_decodetable[0xEB]   = &Z80::ex_DE_HL;
  // EX AF, AF'
  m_decodetable[0x08]   = &Z80::ex_AF_AFalt;
  // EXX
  m_decodetable[0xD9]   = &Z80::exx;
  // EX (SP), HL
  m_decodetable[0xE3]   = &Z80::ex_$SP$_HL;
  // EX (SP), IX
  m_decodetableDD[0xE3] = &Z80::ex_$SP$_IX;
  // EX (SP), IY
  m_decodetableFD[0xE3] = &Z80::ex_$SP$_IY;

}

}
