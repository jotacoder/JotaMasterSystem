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
class Z80;
typedef int (Z80::*instruction_ptr)();

class Z80
{
public:
  Z80(Memory *memory);

  /// Do 1 instrucction cycle.
  int run();

  /// Getter main register
  inline RegistersZ80& registers() { return m_main; }

  ///Getter alternatives registers
  inline RegistersZ80& alternatives() { return m_alternatives; }

  ///Getter indexation registers
  inline IndexZ80& indexation() { return m_index; }

  ///Getter stack pointer register
  inline uint16& stack_pointer() { return m_SP; }

  ///Getter interrupt register
  inline uint8& interrupt() { return m_I; }

  ///Getter refresh register
  inline uint8& refresh() { return m_R; }



private:
  /// Fetch the instruction or operand from memory
  uint8 fetch();

  /// Decode and execute an intruction.
  int decodeAndExecute(const uint8 &opcode);

  /// Decode and execute an intruction for 0xDD SubOpcode.
  int decodeAndExecuteDD();

  /// Decode and execute an intruction for 0xFD SubOpcode.
  int decodeAndExecuteFD();

  /// Decode and execute an intruction for 0xED SubOpcode.
  int decodeAndExecuteED();

  /// Initialize the assignaments for decode tables
  void initializeDecodeTables();


private:

  Memory        *m_memory;         ///< 64K bytes of memory

  RegistersZ80  m_main;           ///< Main registers
  RegistersZ80  m_alternatives;   ///< Alternative registers
  IndexZ80      m_index;          ///< Index registers
  uint16        m_PC;             ///< Program counter
  uint16        m_SP;             ///< Stack pointer
  uint8         m_I;              ///< Interrupt register
  uint8         m_R;              ///< Refresh memory register

  instruction_ptr m_decodetable[256] = {};
  instruction_ptr m_decodetableDD[256] = {};
  instruction_ptr m_decodetableFD[256] = {};
  instruction_ptr m_decodetableED[256] = {};


private:
  /***************************************************************
   *                INSTRUCTION DECLARATIONS                     *
   * ************************************************************/

  // Load 8 bit
  //-------------------
  // LD r, r
  int ld_A_A();
  int ld_A_B();
  int ld_A_C();
  int ld_A_D();
  int ld_A_E();
  int ld_A_H();
  int ld_A_L();
  int ld_B_A();
  int ld_B_B();
  int ld_B_C();
  int ld_B_D();
  int ld_B_E();
  int ld_B_H();
  int ld_B_L();
  int ld_C_A();
  int ld_C_B();
  int ld_C_C();
  int ld_C_D();
  int ld_C_E();
  int ld_C_H();
  int ld_C_L();
  int ld_D_A();
  int ld_D_B();
  int ld_D_C();
  int ld_D_D();
  int ld_D_E();
  int ld_D_H();
  int ld_D_L();
  int ld_E_A();
  int ld_E_B();
  int ld_E_C();
  int ld_E_D();
  int ld_E_E();
  int ld_E_H();
  int ld_E_L();
  int ld_H_A();
  int ld_H_B();
  int ld_H_C();
  int ld_H_D();
  int ld_H_E();
  int ld_H_H();
  int ld_H_L();
  int ld_L_A();
  int ld_L_B();
  int ld_L_C();
  int ld_L_D();
  int ld_L_E();
  int ld_L_H();
  int ld_L_L();
  // LD r,n
  int ld_A_n();
  int ld_B_n();
  int ld_C_n();
  int ld_D_n();
  int ld_E_n();
  int ld_H_n();
  int ld_L_n();
  // LD r,(HL)
  int ld_A_$HL$();
  int ld_B_$HL$();
  int ld_C_$HL$();
  int ld_D_$HL$();
  int ld_E_$HL$();
  int ld_H_$HL$();
  int ld_L_$HL$();
  // LD r, (IX+d)
  int ld_A_$IX_plus_d$();
  int ld_B_$IX_plus_d$();
  int ld_C_$IX_plus_d$();
  int ld_D_$IX_plus_d$();
  int ld_E_$IX_plus_d$();
  int ld_H_$IX_plus_d$();
  int ld_L_$IX_plus_d$();
  // LD r, (IY+d)
  int ld_A_$IY_plus_d$();
  int ld_B_$IY_plus_d$();
  int ld_C_$IY_plus_d$();
  int ld_D_$IY_plus_d$();
  int ld_E_$IY_plus_d$();
  int ld_H_$IY_plus_d$();
  int ld_L_$IY_plus_d$();
  // LD (HL), r
  int ld_$HL$_A();
  int ld_$HL$_B();
  int ld_$HL$_C();
  int ld_$HL$_D();
  int ld_$HL$_E();
  int ld_$HL$_H();
  int ld_$HL$_L();
  // LD (IX+d), r
  int ld_$IX_plus_d$_A();
  int ld_$IX_plus_d$_B();
  int ld_$IX_plus_d$_C();
  int ld_$IX_plus_d$_D();
  int ld_$IX_plus_d$_E();
  int ld_$IX_plus_d$_H();
  int ld_$IX_plus_d$_L();
  // LD (IY+d), r
  int ld_$IY_plus_d$_A();
  int ld_$IY_plus_d$_B();
  int ld_$IY_plus_d$_C();
  int ld_$IY_plus_d$_D();
  int ld_$IY_plus_d$_E();
  int ld_$IY_plus_d$_H();
  int ld_$IY_plus_d$_L();
  // LD (HL), n
  int ld_$HL$_n();
  // LD (IX+d),n
  int ld_$IX_plus_d$_n();
  // LD (IY+d), n
  int ld_$IY_plus_d$_n();
  // LD A, (BC)
  int ld_A_$BC$();
  // LD A, (DE)
  int ld_A_$DE$();
  // LD A, (nn)
  int ld_A_$nn$();
  // LD (BC), A
  int ld_$BC$_A();
  // LD (DE), A
  int ld_$DE$_A();
  // LD (nn), A
  int ld_$nn$_A();
  // LD A, I
  int ld_A_I();
  // LD A, R
  int ld_A_R();
  // LD I, A
  int ld_I_A();
  // LD R, A
  int ld_R_A();


  // Load 16 bit
  //-------------------
  // LD dd, nn
  int ld_BC_nn();
  int ld_DE_nn();
  int ld_HL_nn();
  int ld_SP_nn();
  // LD IX, nn
  int ld_IX_nn();
  // LD IY, nn
  int ld_IY_nn();
  // LD HL, (nn)
  int ld_HL_$nn$();
  // LD dd, (nn)
  int ld_BC_$nn$();
  int ld_DE_$nn$();
  int ld_HL_$nn$2();
  int ld_SP_$nn$();
  // LD IX, (nn)
  int ld_IX_$nn$();
  // LD IY, (nn)
  int ld_IY_$nn$();
  // LD (nn), HL
  int ld_$nn$_HL();
  // LD (nn), dd
  int ld_$nn$_BC();
  int ld_$nn$_DE();
  int ld_$nn$_HL2();
  int ld_$nn$_SP();
  // LD (nn), IX
  int ld_$nn$_IX();
  // LD (nn), IY
  int ld_$nn$_IY();
  // LD SP, HL
  int ld_SP_HL();
  // LD SP, IX
  int ld_SP_IX();
  // LD SP, IY
  int ld_SP_IY();



};



}
#endif // Z80_H
