#include "gmock/gmock.h"

#include "z80.h"
#include "utils.h"

using namespace jota;

class Load16bit : public testing::Test
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


TEST_F(Load16bit, LD_BC_nn)
{
  mem->write(0, 0x01);  // Opcode
  mem->write(1, 220);   // low
  mem->write(2, 5);     // high

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().BC, 1500);
  EXPECT_EQ(ticks, 10);
}

TEST_F(Load16bit, LD_DE_nn)
{
  mem->write(0, 0x11);  // Opcode
  mem->write(1, 220);   // low
  mem->write(2, 5);     // high

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().DE, 1500);
  EXPECT_EQ(ticks, 10);
}

TEST_F(Load16bit, LD_HL_nn)
{
  mem->write(0, 0x21);  // Opcode
  mem->write(1, 220);   // low
  mem->write(2, 5);     // high

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().HL, 1500);
  EXPECT_EQ(ticks, 10);
}

TEST_F(Load16bit, LD_SP_nn)
{
  mem->write(0, 0x31);  // Opcode
  mem->write(1, 220);   // low
  mem->write(2, 5);     // high

  int ticks = cpu->run();

  EXPECT_EQ(cpu->stack_pointer(), 1500);
  EXPECT_EQ(ticks, 10);
}

TEST_F(Load16bit, LD_IX_nn)
{
  mem->write(0, 0xDD);  // Opcode
  mem->write(1, 0x21);  // Opcode
  mem->write(2, 220);   // low
  mem->write(3, 5);     // high

  int ticks = cpu->run();

  EXPECT_EQ(cpu->indexation().IX, 1500);
  EXPECT_EQ(ticks, 14);
}

TEST_F(Load16bit, LD_IY_nn)
{
  mem->write(0, 0xFD);  // Opcode
  mem->write(1, 0x21);  // Opcode
  mem->write(2, 220);   // low
  mem->write(3, 5);     // high

  int ticks = cpu->run();

  EXPECT_EQ(cpu->indexation().IY, 1500);
  EXPECT_EQ(ticks, 14);
}

TEST_F(Load16bit, LD_HL_$nn$)
{
  mem->write(0, 0x2A);  // Opcode
  mem->write(1, 232);   // low 1000
  mem->write(2, 3);     // high 1000

  // Write @1000 the value 1500
  mem->write(1000, 220); // low 1500
  mem->write(1001, 5);   // high 1500

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().HL, 1500);
  EXPECT_EQ(ticks, 16);
}



TEST_F(Load16bit, LD_BC_$nn$)
{
  mem->write(0, 0xED);  // Opcode
  mem->write(1, 0x4B);  // SubOpcode
  mem->write(2, 232);   // low 1000
  mem->write(3, 3);     // high 1000

  // Write @1000 the value 1500
  mem->write(1000, 220); // low 1500
  mem->write(1001, 5);   // high 1500

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().BC, 1500);
  EXPECT_EQ(ticks, 20);
}

TEST_F(Load16bit, LD_DE_$nn$)
{
  mem->write(0, 0xED);  // Opcode
  mem->write(1, 0x5B);  // SubOpcode
  mem->write(2, 232);   // low 1000
  mem->write(3, 3);     // high 1000

  // Write @1000 the value 1500
  mem->write(1000, 220); // low 1500
  mem->write(1001, 5);   // high 1500

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().DE, 1500);
  EXPECT_EQ(ticks, 20);
}

TEST_F(Load16bit, LD_HL_$nn$2)
{
  mem->write(0, 0xED);  // Opcode
  mem->write(1, 0x6B);  // SubOpcode
  mem->write(2, 232);   // low 1000
  mem->write(3, 3);     // high 1000

  // Write @1000 the value 1500
  mem->write(1000, 220); // low 1500
  mem->write(1001, 5);   // high 1500

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().HL, 1500);
  EXPECT_EQ(ticks, 20);
}

TEST_F(Load16bit, LD_SP_$nn$)
{
  mem->write(0, 0xED);  // Opcode
  mem->write(1, 0x7B);  // SubOpcode
  mem->write(2, 232);   // low 1000
  mem->write(3, 3);     // high 1000

  // Write @1000 the value 1500
  mem->write(1000, 220); // low 1500
  mem->write(1001, 5);   // high 1500

  int ticks = cpu->run();

  EXPECT_EQ(cpu->stack_pointer(), 1500);
  EXPECT_EQ(ticks, 20);
}

TEST_F(Load16bit, LD_IX_$nn$)
{
  mem->write(0, 0xDD);  // Opcode
  mem->write(1, 0x2A);  // SubOpcode
  mem->write(2, 232);   // low 1000
  mem->write(3, 3);     // high 1000

  // Write @1000 the value 1500
  mem->write(1000, 220); // low 1500
  mem->write(1001, 5);   // high 1500

  int ticks = cpu->run();

  EXPECT_EQ(cpu->indexation().IX, 1500);
  EXPECT_EQ(ticks, 20);
}

TEST_F(Load16bit, LD_IY_$nn$)
{
  mem->write(0, 0xFD);  // Opcode
  mem->write(1, 0x2A);  // SubOpcode
  mem->write(2, 232);   // low 1000
  mem->write(3, 3);     // high 1000

  // Write @1000 the value 1500
  mem->write(1000, 220); // low 1500
  mem->write(1001, 5);   // high 1500

  int ticks = cpu->run();

  EXPECT_EQ(cpu->indexation().IY, 1500);
  EXPECT_EQ(ticks, 20);
}

TEST_F(Load16bit, LD_$nn$_HL)
{
  mem->write(0, 0x22);  // Opcode
  mem->write(1, 232);   // low 1000
  mem->write(2, 3);     // high 1000

  cpu->registers().HL = 1500;

  int ticks = cpu->run();

  // Read the value @1000
  uint8 low = mem->read(1000);
  uint8 high = mem->read(1001);

  uint16 value = make16(high, low);

  EXPECT_EQ(value, 1500);
  EXPECT_EQ(ticks, 16);
}

TEST_F(Load16bit, LD_$nn$_BC)
{
  mem->write(0, 0xED);  // Opcode
  mem->write(1, 0x43);  // SubOpcode
  mem->write(2, 232);   // low 1000
  mem->write(3, 3);     // high 1000

  cpu->registers().BC = 1500;

  int ticks = cpu->run();

  // Read the value @1000
  uint8 low = mem->read(1000);
  uint8 high = mem->read(1001);

  uint16 value = make16(high, low);

  EXPECT_EQ(value, 1500);
  EXPECT_EQ(ticks, 20);
}

TEST_F(Load16bit, LD_$nn$_DE)
{
  mem->write(0, 0xED);  // Opcode
  mem->write(1, 0x53);  // SubOpcode
  mem->write(2, 232);   // low 1000
  mem->write(3, 3);     // high 1000

  cpu->registers().DE = 1500;

  int ticks = cpu->run();

  // Read the value @1000
  uint8 low = mem->read(1000);
  uint8 high = mem->read(1001);

  uint16 value = make16(high, low);

  EXPECT_EQ(value, 1500);
  EXPECT_EQ(ticks, 20);
}


TEST_F(Load16bit, LD_$nn$_HL2)
{
  mem->write(0, 0xED);  // Opcode
  mem->write(1, 0x63);  // SubOpcode
  mem->write(2, 232);   // low 1000
  mem->write(3, 3);     // high 1000

  cpu->registers().HL = 1500;

  int ticks = cpu->run();

  // Read the value @1000
  uint8 low = mem->read(1000);
  uint8 high = mem->read(1001);

  uint16 value = make16(high, low);

  EXPECT_EQ(value, 1500);
  EXPECT_EQ(ticks, 20);
}


TEST_F(Load16bit, LD_$nn$_SP)
{
  mem->write(0, 0xED);  // Opcode
  mem->write(1, 0x73);  // SubOpcode
  mem->write(2, 232);   // low 1000
  mem->write(3, 3);     // high 1000

  cpu->stack_pointer() = 1500;

  int ticks = cpu->run();

  // Read the value @1000
  uint8 low = mem->read(1000);
  uint8 high = mem->read(1001);

  uint16 value = make16(high, low);

  EXPECT_EQ(value, 1500);
  EXPECT_EQ(ticks, 20);
}

TEST_F(Load16bit, LD_$nn$_IX)
{
  mem->write(0, 0xDD);  // Opcode
  mem->write(1, 0x22);  // SubOpcode
  mem->write(2, 232);   // low 1000
  mem->write(3, 3);     // high 1000

  cpu->indexation().IX = 1500;

  int ticks = cpu->run();

  // Read the value @1000
  uint8 low = mem->read(1000);
  uint8 high = mem->read(1001);

  uint16 value = make16(high, low);

  EXPECT_EQ(value, 1500);
  EXPECT_EQ(ticks, 20);
}

TEST_F(Load16bit, LD_$nn$_IY)
{
  mem->write(0, 0xFD);  // Opcode
  mem->write(1, 0x22);  // SubOpcode
  mem->write(2, 232);   // low 1000
  mem->write(3, 3);     // high 1000

  cpu->indexation().IY = 1500;

  int ticks = cpu->run();

  // Read the value @1000
  uint8 low = mem->read(1000);
  uint8 high = mem->read(1001);

  uint16 value = make16(high, low);

  EXPECT_EQ(value, 1500);
  EXPECT_EQ(ticks, 20);
}

TEST_F(Load16bit, LD_SP_HL)
{
  mem->write(0, 0xF9);  // Opcode

  cpu->registers().HL = 1500;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->stack_pointer(), 1500);
  EXPECT_EQ(ticks, 6);
}

TEST_F(Load16bit, LD_SP_IX)
{
  mem->write(0, 0xDD);  // Opcode
  mem->write(1, 0xF9);  // SubOpcode

  cpu->indexation().IX = 1500;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->stack_pointer(), 1500);
  EXPECT_EQ(ticks, 10);
}

TEST_F(Load16bit, LD_SP_IY)
{
  mem->write(0, 0xFD);  // Opcode
  mem->write(1, 0xF9);  // SubOpcode

  cpu->indexation().IY = 1500;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->stack_pointer(), 1500);
  EXPECT_EQ(ticks, 10);
}

