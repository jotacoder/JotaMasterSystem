/** JotaMasterSystem: A Master System Emulator
 * Copyright (c) Juan José Chica <jotacoder@gmail.com>
 * Insert MIT license here.
 */

#include <QCoreApplication>
#include <iostream>

#include "z80.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  jota::Z80 cpu;

  cpu.m_main.BC = 256;

  std::cout<<"BC "<<(int)cpu.m_main.BC<<std::endl;
  std::cout<<"B "<<(int)cpu.m_main.B<<std::endl;
  std::cout<<"C "<<(int)cpu.m_main.C<<std::endl;

  return a.exec();
}
