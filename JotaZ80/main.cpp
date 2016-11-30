#include <QCoreApplication>
#include <iostream>
#include <stdint.h>

union RegistersZ80
{
  struct {uint16_t AF, BC, DE, HL, IX, IY;};
  #if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  struct {uint8_t F, A, C, B, E, D, L, H, IXl, IXh, IYl, IYh;};
  #else
  struct {uint8_t A, F, B, C, D, E, H, L, IXh, IXl, IYh, IYl;};
  #endif
};

struct ContextZ80
{
  RegistersZ80 regs;
  RegistersZ80 alt;

  uint16_t PC;
  uint16_t SP;
};



int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  ContextZ80 context;

  context.regs.BC = 256;

  std::cout<<"BC "<<(int)context.regs.BC<<std::endl;
  std::cout<<"B "<<(int)context.regs.B<<std::endl;
  std::cout<<"C "<<(int)context.regs.C<<std::endl;

  return a.exec();
}
