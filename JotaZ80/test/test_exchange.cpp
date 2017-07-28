#include "gmock/gmock.h"

#include "z80.h"
using namespace jota;

class Exchange : public testing::Test
{
public:
  Memory *mem;
  Z80 *cpu;

  virtual void SetUp()
  {
    mem = new Memory();
    cpu = new Z80(mem);
  }

  virtual void TearDown()
  {
    delete mem;
    delete cpu;
  }
};

TEST_F(Exchange, EX_DE_HL)
{
  mem->write(0, 0xEB);  // Opcode

  cpu->registers().DE = 69;
  cpu->registers().HL = 5;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().DE, 5);
  EXPECT_EQ(cpu->registers().HL, 69);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Exchange, EX_AF_AFalt)
{
  mem->write(0, 0x08);  // Opcode

  cpu->registers().AF = 69;
  cpu->alternatives().AF = 5;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().AF, 5);
  EXPECT_EQ(cpu->alternatives().AF, 69);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Exchange, EXX)
{
  mem->write(0, 0xD9);  // Opcode

  cpu->registers().BC = 1020;
  cpu->registers().DE = 1069;
  cpu->registers().HL = 1005;
  cpu->alternatives().BC = 2020;
  cpu->alternatives().DE = 2069;
  cpu->alternatives().HL = 2005;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().BC, 2020);
  EXPECT_EQ(cpu->registers().DE, 2069);
  EXPECT_EQ(cpu->registers().HL, 2005);
  EXPECT_EQ(cpu->alternatives().BC, 1020);
  EXPECT_EQ(cpu->alternatives().DE, 1069);
  EXPECT_EQ(cpu->alternatives().HL, 1005);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Exchange, EX_$SP$_HL)
{
  mem->write(0, 0xE3);  // Opcode

  cpu->registers().HL = 0x7012;
  cpu->stack_pointer() = 0x8856;

  mem->write(0x8856, 0x11);
  mem->write(0x8857, 0x22);

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().HL, 0x2211);
  EXPECT_EQ(mem->read(0x8856), 0x12);
  EXPECT_EQ(mem->read(0x8857), 0x70);
  EXPECT_EQ(cpu->stack_pointer(), 0x8856);
  EXPECT_EQ(ticks, 19);
}

TEST_F(Exchange, EX_$SP$_IX)
{
  mem->write(0, 0xDD);  // Opcode
  mem->write(1, 0xE3);  // SubOpcode

  cpu->indexation().IX = 0x7012;
  cpu->stack_pointer() = 0x8856;

  mem->write(0x8856, 0x11);
  mem->write(0x8857, 0x22);

  int ticks = cpu->run();

  EXPECT_EQ(cpu->indexation().IX, 0x2211);
  EXPECT_EQ(mem->read(0x8856), 0x12);
  EXPECT_EQ(mem->read(0x8857), 0x70);
  EXPECT_EQ(cpu->stack_pointer(), 0x8856);
  EXPECT_EQ(ticks, 23);
}

TEST_F(Exchange, EX_$SP$_IY)
{
  mem->write(0, 0xFD);  // Opcode
  mem->write(1, 0xE3);  // SubOpcode

  cpu->indexation().IY = 0x7012;
  cpu->stack_pointer() = 0x8856;

  mem->write(0x8856, 0x11);
  mem->write(0x8857, 0x22);

  int ticks = cpu->run();

  EXPECT_EQ(cpu->indexation().IY, 0x2211);
  EXPECT_EQ(mem->read(0x8856), 0x12);
  EXPECT_EQ(mem->read(0x8857), 0x70);
  EXPECT_EQ(cpu->stack_pointer(), 0x8856);
  EXPECT_EQ(ticks, 23);
}
