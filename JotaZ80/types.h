/** JotaMasterSystem: A Master System Emulator
 * Copyright (c) Juan José Chica <jotacoder@gmail.com>
 * Insert MIT license here.
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
