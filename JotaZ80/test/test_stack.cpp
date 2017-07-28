#include "gmock/gmock.h"

#include "z80.h"
using namespace jota;

class Stack : public testing::Test
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

TEST_F(Stack, PUSH_BC)
{
  mem->write(0, 0xC5);  // Opcode

  cpu->registers().BC = 0x2233;
  cpu->stack_pointer() = 0x1007;

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(0x1006), 0x22);
  EXPECT_EQ(mem->read(0x1005), 0x33);
  EXPECT_EQ(cpu->stack_pointer(), 0x1005);
  EXPECT_EQ(ticks, 11);
}

TEST_F(Stack, PUSH_DE)
{
  mem->write(0, 0xD5);  // Opcode

  cpu->registers().DE = 0x2233;
  cpu->stack_pointer() = 0x1007;

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(0x1006), 0x22);
  EXPECT_EQ(mem->read(0x1005), 0x33);
  EXPECT_EQ(cpu->stack_pointer(), 0x1005);
  EXPECT_EQ(ticks, 11);
}

TEST_F(Stack, PUSH_HL)
{
  mem->write(0, 0xE5);  // Opcode

  cpu->registers().HL = 0x2233;
  cpu->stack_pointer() = 0x1007;

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(0x1006), 0x22);
  EXPECT_EQ(mem->read(0x1005), 0x33);
  EXPECT_EQ(cpu->stack_pointer(), 0x1005);
  EXPECT_EQ(ticks, 11);
}

TEST_F(Stack, PUSH_AF)
{
  mem->write(0, 0xF5);  // Opcode

  cpu->registers().AF = 0x2233;
  cpu->stack_pointer() = 0x1007;

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(0x1006), 0x22);
  EXPECT_EQ(mem->read(0x1005), 0x33);
  EXPECT_EQ(cpu->stack_pointer(), 0x1005);
  EXPECT_EQ(ticks, 11);
}

TEST_F(Stack, PUSH_IX)
{
  mem->write(0, 0xDD);  // Opcode
  mem->write(1, 0xE5);  // SubOpcode

  cpu->indexation().IX = 0x2233;
  cpu->stack_pointer() = 0x1007;

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(0x1006), 0x22);
  EXPECT_EQ(mem->read(0x1005), 0x33);
  EXPECT_EQ(cpu->stack_pointer(), 0x1005);
  EXPECT_EQ(ticks, 15);
}

TEST_F(Stack, PUSH_IY)
{
  mem->write(0, 0xFD);  // Opcode
  mem->write(1, 0xE5);  // SubOpcode

  cpu->indexation().IY = 0x2233;
  cpu->stack_pointer() = 0x1007;

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(0x1006), 0x22);
  EXPECT_EQ(mem->read(0x1005), 0x33);
  EXPECT_EQ(cpu->stack_pointer(), 0x1005);
  EXPECT_EQ(ticks, 15);
}

TEST_F(Stack, POP_BC)
{
  mem->write(0, 0xC1);  // Opcode

  cpu->stack_pointer() = 0x1000;

  mem->write(0x1000, 0x55);
  mem->write(0x1001, 0x33);

  int ticks = cpu->run();
  EXPECT_EQ(cpu->registers().BC, 0x3355);
  EXPECT_EQ(cpu->stack_pointer(), 0x1002);
  EXPECT_EQ(ticks, 10);
}

TEST_F(Stack, POP_DE)
{
  mem->write(0, 0xD1);  // Opcode

  cpu->stack_pointer() = 0x1000;

  mem->write(0x1000, 0x55);
  mem->write(0x1001, 0x33);

  int ticks = cpu->run();
  EXPECT_EQ(cpu->registers().DE, 0x3355);
  EXPECT_EQ(cpu->stack_pointer(), 0x1002);
  EXPECT_EQ(ticks, 10);
}

TEST_F(Stack, POP_HL)
{
  mem->write(0, 0xE1);  // Opcode

  cpu->stack_pointer() = 0x1000;

  mem->write(0x1000, 0x55);
  mem->write(0x1001, 0x33);

  int ticks = cpu->run();
  EXPECT_EQ(cpu->registers().HL, 0x3355);
  EXPECT_EQ(cpu->stack_pointer(), 0x1002);
  EXPECT_EQ(ticks, 10);
}

TEST_F(Stack, POP_AF)
{
  mem->write(0, 0xF1);  // Opcode

  cpu->stack_pointer() = 0x1000;

  mem->write(0x1000, 0x55);
  mem->write(0x1001, 0x33);

  int ticks = cpu->run();
  EXPECT_EQ(cpu->registers().AF, 0x3355);
  EXPECT_EQ(cpu->stack_pointer(), 0x1002);
  EXPECT_EQ(ticks, 10);
}

TEST_F(Stack, POP_IX)
{
  mem->write(0, 0xDD);  // Opcode
  mem->write(1, 0xE1);  // SubOpcode

  cpu->stack_pointer() = 0x1000;

  mem->write(0x1000, 0x55);
  mem->write(0x1001, 0x33);

  int ticks = cpu->run();
  EXPECT_EQ(cpu->indexation().IX, 0x3355);
  EXPECT_EQ(cpu->stack_pointer(), 0x1002);
  EXPECT_EQ(ticks, 14);
}

TEST_F(Stack, POP_IY)
{
  mem->write(0, 0xFD);  // Opcode
  mem->write(1, 0xE1);  // SubOpcode

  cpu->stack_pointer() = 0x1000;

  mem->write(0x1000, 0x55);
  mem->write(0x1001, 0x33);

  int ticks = cpu->run();
  EXPECT_EQ(cpu->indexation().IY, 0x3355);
  EXPECT_EQ(cpu->stack_pointer(), 0x1002);
  EXPECT_EQ(ticks, 14);
}
