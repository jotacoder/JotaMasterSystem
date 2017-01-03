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

#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>

namespace jota
{

/// 8bit unsigned integer
typedef uint8_t     uint8;

/// 16bit unsigned integer
typedef uint16_t    uint16;


/// General registers for Z80 CPU
union RegistersZ80
{
  struct {uint16 AF, BC, DE, HL;};
  #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  struct {uint8 F, A, C, B, E, D, L, H;};
  #else
  struct {uint8 A, F, B, C, D, E, H, L;};
  #endif
};

/// Index registers for Z80 CPU
union IndexZ80
{
  struct {uint16 IX, IY;};
  #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  struct {uint8 IXl, IXh, IYl, IYh;};
  #else
  struct {uint8 IXh, IXl, IYh, IYl;};
  #endif
};

}


#endif // TYPES_H
