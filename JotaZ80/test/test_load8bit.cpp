#include "gmock/gmock.h"

#include "z80.h"
using namespace jota;

class Load8bit : public testing::Test
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

//----------------------------------------
//    Load8bit Register to Register
//----------------------------------------
TEST_F(Load8bit, LD_A_A)
{
  mem->write(0, 0x7F);  // Opcode
  cpu->registers().A = 10;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().A, 10);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_A_B)
{
  mem->write(0, 0x78);  // Opcode
  cpu->registers().B = 10;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().A, 10);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_A_C)
{
  mem->write(0, 0x79);  // Opcode
  cpu->registers().C = 10;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().A, 10);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_A_D)
{
  mem->write(0, 0x7A);  // Opcode
  cpu->registers().D = 10;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().A, 10);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_A_E)
{
  mem->write(0, 0x7B);  // Opcode
  cpu->registers().E = 10;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().A, 10);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_A_H)
{
  mem->write(0, 0x7C);  // Opcode
  cpu->registers().H = 10;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().A, 10);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_A_L)
{
  mem->write(0, 0x7D);  // Opcode
  cpu->registers().L = 10;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().A, 10);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_B_A)
{
  mem->write(0, 0x47);  // Opcode
  cpu->registers().A = 10;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().B, 10);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_B_B)
{
  mem->write(0, 0x40);  // Opcode
  cpu->registers().B = 10;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().B, 10);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_B_C)
{
  mem->write(0, 0x41);  // Opcode
  cpu->registers().C = 10;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().B, 10);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_B_D)
{
  mem->write(0, 0x42);  // Opcode
  cpu->registers().D = 10;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().B, 10);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_B_E)
{
  mem->write(0, 0x43);  // Opcode
  cpu->registers().E = 10;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().B, 10);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_B_H)
{
  mem->write(0, 0x44);  // Opcode
  cpu->registers().H = 10;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().B, 10);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_B_L)
{
  mem->write(0, 0x45);  // Opcode
  cpu->registers().L = 10;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().B, 10);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_C_A)
{
  mem->write(0, 0x4F);  // Opcode
  cpu->registers().A = 69;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().C, 69);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_C_B)
{
  mem->write(0, 0x48);  // Opcode
  cpu->registers().B = 69;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().C, 69);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_C_C)
{
  mem->write(0, 0x49);  // Opcode
  cpu->registers().C = 69;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().C, 69);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_C_D)
{
  mem->write(0, 0x4A);  // Opcode
  cpu->registers().D = 69;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().C, 69);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_C_E)
{
  mem->write(0, 0x4B);  // Opcode
  cpu->registers().E = 69;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().C, 69);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_C_H)
{
  mem->write(0, 0x4C);  // Opcode
  cpu->registers().H = 69;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().C, 69);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_C_L)
{
  mem->write(0, 0x4D);  // Opcode
  cpu->registers().L = 69;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().C, 69);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_D_A)
{
  mem->write(0, 0x57);  // Opcode
  cpu->registers().A = 128;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().D, 128);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_D_B)
{
  mem->write(0, 0x50);  // Opcode
  cpu->registers().B = 128;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().D, 128);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_D_C)
{
  mem->write(0, 0x51);  // Opcode
  cpu->registers().C = 128;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().D, 128);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_D_D)
{
  mem->write(0, 0x52);  // Opcode
  cpu->registers().D = 128;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().D, 128);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_D_E)
{
  mem->write(0, 0x53);  // Opcode
  cpu->registers().E = 128;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().D, 128);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_D_H)
{
  mem->write(0, 0x54);  // Opcode
  cpu->registers().H = 128;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().D, 128);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_D_L)
{
  mem->write(0, 0x55);  // Opcode
  cpu->registers().L = 128;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().D, 128);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_E_A)
{
  mem->write(0, 0x5F);  // Opcode
  cpu->registers().A = 200;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().E, 200);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_E_B)
{
  mem->write(0, 0x58);  // Opcode
  cpu->registers().B = 200;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().E, 200);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_E_C)
{
  mem->write(0, 0x59);  // Opcode
  cpu->registers().C = 200;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().E, 200);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_E_D)
{
  mem->write(0, 0x5A);  // Opcode
  cpu->registers().D = 200;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().E, 200);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_E_E)
{
  mem->write(0, 0x5B);  // Opcode
  cpu->registers().E = 200;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().E, 200);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_E_H)
{
  mem->write(0, 0x5C);  // Opcode
  cpu->registers().H = 200;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().E, 200);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_E_L)
{
  mem->write(0, 0x5D);  // Opcode
  cpu->registers().L = 200;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().E, 200);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_H_A)
{
  mem->write(0, 0x67);  // Opcode
  cpu->registers().A = 200;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().H, 200);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_H_B)
{
  mem->write(0, 0x60);  // Opcode
  cpu->registers().B = 200;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().H, 200);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_H_C)
{
  mem->write(0, 0x61);  // Opcode
  cpu->registers().C = 200;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().H, 200);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_H_D)
{
  mem->write(0, 0x62);  // Opcode
  cpu->registers().D = 200;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().H, 200);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_H_E)
{
  mem->write(0, 0x63);  // Opcode
  cpu->registers().E = 200;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().H, 200);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_H_H)
{
  mem->write(0, 0x64);  // Opcode
  cpu->registers().H = 200;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().H, 200);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_H_L)
{
  mem->write(0, 0x65);  // Opcode
  cpu->registers().L = 200;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().H, 200);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_L_A)
{
  mem->write(0, 0x6F);  // Opcode
  cpu->registers().A = 222;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().L, 222);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_L_B)
{
  mem->write(0, 0x68);  // Opcode
  cpu->registers().B = 222;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().L, 222);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_L_C)
{
  mem->write(0, 0x69);  // Opcode
  cpu->registers().C = 222;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().L, 222);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_L_D)
{
  mem->write(0, 0x6A);  // Opcode
  cpu->registers().D = 222;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().L, 222);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_L_E)
{
  mem->write(0, 0x6B);  // Opcode
  cpu->registers().E = 222;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().L, 222);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_L_H)
{
  mem->write(0, 0x6C);  // Opcode
  cpu->registers().H = 222;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().L, 222);
  EXPECT_EQ(ticks, 4);
}

TEST_F(Load8bit, LD_L_L)
{
  mem->write(0, 0x6D);  // Opcode
  cpu->registers().L = 222;

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().L, 222);
  EXPECT_EQ(ticks, 4);
}

//----------------------------------------
//    Load8bit Code value to Register
//----------------------------------------
TEST_F(Load8bit, LD_A_n)
{
  mem->write(0, 0x3E);  // Opcode
  mem->write(1, 10);    // Operando n

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().A, 10);
  EXPECT_EQ(ticks, 7);
}

TEST_F(Load8bit, LD_B_n)
{
  mem->write(0, 0x06);  // Opcode
  mem->write(1, 10);    // Operando n

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().B, 10);
  EXPECT_EQ(ticks, 7);
}

TEST_F(Load8bit, LD_C_n)
{
  mem->write(0, 0x0E);  // Opcode
  mem->write(1, 69);    // Operando n

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().C, 69);
  EXPECT_EQ(ticks, 7);
}


TEST_F(Load8bit, LD_D_n)
{
  mem->write(0, 0x16);  // Opcode
  mem->write(1, 100);    // Operando n

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().D, 100);
  EXPECT_EQ(ticks, 7);
}

TEST_F(Load8bit, LD_E_n)
{
  mem->write(0, 0x1E);  // Opcode
  mem->write(1, 100);    // Operando n

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().E, 100);
  EXPECT_EQ(ticks, 7);
}

TEST_F(Load8bit, LD_H_n)
{
  mem->write(0, 0x26);  // Opcode
  mem->write(1, 100);    // Operando n

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().H, 100);
  EXPECT_EQ(ticks, 7);
}

TEST_F(Load8bit, LD_L_n)
{
  mem->write(0, 0x2E);  // Opcode
  mem->write(1, 100);    // Operando n

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().L, 100);
  EXPECT_EQ(ticks, 7);
}

//-----------------------------------------
// Load8bit Data in HL address to Register
//-----------------------------------------

TEST_F(Load8bit, LD_A_$HL$)
{
  mem->write(0, 0x7E);        // Opcode
  cpu->registers().HL = 1000; // Address
  mem->write(1000, 100);      // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().A, 100);
  EXPECT_EQ(ticks, 7);
}

TEST_F(Load8bit, LD_B_$HL$)
{
  mem->write(0, 0x46);        // Opcode
  cpu->registers().HL = 1000; // Address
  mem->write(1000, 100);      // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().B, 100);
  EXPECT_EQ(ticks, 7);
}

TEST_F(Load8bit, LD_C_$HL$)
{
  mem->write(0, 0x4E);        // Opcode
  cpu->registers().HL = 1000; // Address
  mem->write(1000, 100);      // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().C, 100);
  EXPECT_EQ(ticks, 7);
}

TEST_F(Load8bit, LD_D_$HL$)
{
  mem->write(0, 0x56);        // Opcode
  cpu->registers().HL = 1000; // Address
  mem->write(1000, 100);      // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().D, 100);
  EXPECT_EQ(ticks, 7);
}

TEST_F(Load8bit, LD_E_$HL$)
{
  mem->write(0, 0x5E);        // Opcode
  cpu->registers().HL = 1000; // Address
  mem->write(1000, 100);      // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().E, 100);
  EXPECT_EQ(ticks, 7);
}

TEST_F(Load8bit, LD_H_$HL$)
{
  mem->write(0, 0x66);        // Opcode
  cpu->registers().HL = 1000; // Address
  mem->write(1000, 100);      // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().H, 100);
  EXPECT_EQ(ticks, 7);
}

TEST_F(Load8bit, LD_L_$HL$)
{
  mem->write(0, 0x6E);        // Opcode
  cpu->registers().HL = 1000; // Address
  mem->write(1000, 100);      // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().L, 100);
  EXPECT_EQ(ticks, 7);
}

//-----------------------------------------------------------
// Load8bit Data in IX address plus displacement to Register
//-----------------------------------------------------------
TEST_F(Load8bit, LD_A_$IX_plus_d$)
{
  mem->write(0, 0xDD);          // Opcode
  mem->write(1, 0x7E);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IX = 1000;  // Address
  mem->write(1010, 200);        // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().A, 200);
  EXPECT_EQ(ticks, 19);
}

TEST_F(Load8bit, LD_B_$IX_plus_d$)
{
  mem->write(0, 0xDD);          // Opcode
  mem->write(1, 0x46);          // SubOpcode
  mem->write(2, -10);           // displacement
  cpu->indexation().IX = 1000;  // Address
  mem->write(990, 200);         // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().B, 200);
  EXPECT_EQ(ticks, 19);
}

TEST_F(Load8bit, LD_C_$IX_plus_d$)
{
  mem->write(0, 0xDD);          // Opcode
  mem->write(1, 0x4E);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IX = 1000;  // Address
  mem->write(1010, 200);        // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().C, 200);
  EXPECT_EQ(ticks, 19);
}

TEST_F(Load8bit, LD_D_$IX_plus_d$)
{
  mem->write(0, 0xDD);          // Opcode
  mem->write(1, 0x56);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IX = 1000;  // Address
  mem->write(1010, 200);        // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().D, 200);
  EXPECT_EQ(ticks, 19);
}

TEST_F(Load8bit, LD_E_$IX_plus_d$)
{
  mem->write(0, 0xDD);          // Opcode
  mem->write(1, 0x5E);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IX = 1000;  // Address
  mem->write(1010, 200);        // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().E, 200);
  EXPECT_EQ(ticks, 19);
}

TEST_F(Load8bit, LD_H_$IX_plus_d$)
{
  mem->write(0, 0xDD);          // Opcode
  mem->write(1, 0x66);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IX = 1000;  // Address
  mem->write(1010, 200);        // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().H, 200);
  EXPECT_EQ(ticks, 19);
}

TEST_F(Load8bit, LD_L_$IX_plus_d$)
{
  mem->write(0, 0xDD);          // Opcode
  mem->write(1, 0x6E);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IX = 1000;  // Address
  mem->write(1010, 200);        // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().L, 200);
  EXPECT_EQ(ticks, 19);
}

//-----------------------------------------------------------
// Load8bit Data in IY address plus displacement to Register
//-----------------------------------------------------------
TEST_F(Load8bit, LD_A_$IY_plus_d$)
{
  mem->write(0, 0xFD);          // Opcode
  mem->write(1, 0x7E);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IY = 1000;  // Address
  mem->write(1010, 200);        // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().A, 200);
  EXPECT_EQ(ticks, 19);
}

TEST_F(Load8bit, LD_B_$IY_plus_d$)
{
  mem->write(0, 0xFD);          // Opcode
  mem->write(1, 0x46);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IY = 1000;  // Address
  mem->write(1010, 200);        // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().B, 200);
  EXPECT_EQ(ticks, 19);
}

TEST_F(Load8bit, LD_C_$IY_plus_d$)
{
  mem->write(0, 0xFD);          // Opcode
  mem->write(1, 0x4E);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IY = 1000;  // Address
  mem->write(1010, 200);        // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().C, 200);
  EXPECT_EQ(ticks, 19);
}

TEST_F(Load8bit, LD_D_$IY_plus_d$)
{
  mem->write(0, 0xFD);          // Opcode
  mem->write(1, 0x56);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IY = 1000;  // Address
  mem->write(1010, 200);        // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().D, 200);
  EXPECT_EQ(ticks, 19);
}

TEST_F(Load8bit, LD_E_$IY_plus_d$)
{
  mem->write(0, 0xFD);          // Opcode
  mem->write(1, 0x5E);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IY = 1000;  // Address
  mem->write(1010, 200);        // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().E, 200);
  EXPECT_EQ(ticks, 19);
}

TEST_F(Load8bit, LD_H_$IY_plus_d$)
{
  mem->write(0, 0xFD);          // Opcode
  mem->write(1, 0x66);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IY = 1000;  // Address
  mem->write(1010, 200);        // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().H, 200);
  EXPECT_EQ(ticks, 19);
}

TEST_F(Load8bit, LD_L_$IY_plus_d$)
{
  mem->write(0, 0xFD);          // Opcode
  mem->write(1, 0x6E);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IY = 1000;  // Address
  mem->write(1010, 200);        // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().L, 200);
  EXPECT_EQ(ticks, 19);
}

//-----------------------------------------
// Load8bit Register to Data in HL address
//-----------------------------------------
TEST_F(Load8bit, LD_$HL$_A)
{
  mem->write(0, 0x77);        // Opcode
  cpu->registers().HL = 1000; // Address
  cpu->registers().A = 100;   // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(1000), 100);
  EXPECT_EQ(ticks, 7);
}

TEST_F(Load8bit, LD_$HL$_B)
{
  mem->write(0, 0x70);        // Opcode
  cpu->registers().HL = 1000; // Address
  cpu->registers().B = 100;   // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(1000), 100);
  EXPECT_EQ(ticks, 7);
}

TEST_F(Load8bit, LD_$HL$_C)
{
  mem->write(0, 0x71);        // Opcode
  cpu->registers().HL = 1000; // Address
  cpu->registers().C = 100;   // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(1000), 100);
  EXPECT_EQ(ticks, 7);
}

TEST_F(Load8bit, LD_$HL$_D)
{
  mem->write(0, 0x72);        // Opcode
  cpu->registers().HL = 1000; // Address
  cpu->registers().D = 100;   // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(1000), 100);
  EXPECT_EQ(ticks, 7);
}

TEST_F(Load8bit, LD_$HL$_E)
{
  mem->write(0, 0x73);        // Opcode
  cpu->registers().HL = 1000; // Address
  cpu->registers().E = 100;   // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(1000), 100);
  EXPECT_EQ(ticks, 7);
}

TEST_F(Load8bit, LD_$HL$_H)
{
  mem->write(0, 0x74);        // Opcode
  cpu->registers().HL = 1000; // Address
  //cpu->registers().H = 3;      // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(1000), 3);
  EXPECT_EQ(ticks, 7);
}

TEST_F(Load8bit, LD_$HL$_L)
{
  mem->write(0, 0x75);        // Opcode
  cpu->registers().HL = 1000; // Address
  //cpu->registers().L = 232;   // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(1000), 232);
  EXPECT_EQ(ticks, 7);
}

//-----------------------------------------------------------
// Load8bit Register to Data in IX address plus displacement
//-----------------------------------------------------------
TEST_F(Load8bit, LD_$IX_plus_d$_A)
{
  mem->write(0, 0xDD);          // Opcode
  mem->write(1, 0x77);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IX = 1000;  // Address
  cpu->registers().A = 200;     // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(1010), 200);
  EXPECT_EQ(ticks, 19);
}

TEST_F(Load8bit, LD_$IX_plus_d$_B)
{
  mem->write(0, 0xDD);          // Opcode
  mem->write(1, 0x70);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IX = 1000;  // Address
  cpu->registers().B = 200;     // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(1010), 200);
  EXPECT_EQ(ticks, 19);
}

TEST_F(Load8bit, LD_$IX_plus_d$_C)
{
  mem->write(0, 0xDD);          // Opcode
  mem->write(1, 0x71);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IX = 1000;  // Address
  cpu->registers().C = 200;     // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(1010), 200);
  EXPECT_EQ(ticks, 19);
}

TEST_F(Load8bit, LD_$IX_plus_d$_D)
{
  mem->write(0, 0xDD);          // Opcode
  mem->write(1, 0x72);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IX = 1000;  // Address
  cpu->registers().D = 200;     // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(1010), 200);
  EXPECT_EQ(ticks, 19);
}

TEST_F(Load8bit, LD_$IX_plus_d$_E)
{
  mem->write(0, 0xDD);          // Opcode
  mem->write(1, 0x73);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IX = 1000;  // Address
  cpu->registers().E = 200;     // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(1010), 200);
  EXPECT_EQ(ticks, 19);
}

TEST_F(Load8bit, LD_$IX_plus_d$_H)
{
  mem->write(0, 0xDD);          // Opcode
  mem->write(1, 0x74);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IX = 1000;  // Address
  cpu->registers().H = 200;     // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(1010), 200);
  EXPECT_EQ(ticks, 19);
}

TEST_F(Load8bit, LD_$IX_plus_d$_L)
{
  mem->write(0, 0xDD);          // Opcode
  mem->write(1, 0x75);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IX = 1000;  // Address
  cpu->registers().L = 200;     // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(1010), 200);
  EXPECT_EQ(ticks, 19);
}

//-----------------------------------------------------------
// Load8bit Register to Data in IY address plus displacement
//-----------------------------------------------------------
TEST_F(Load8bit, LD_$IY_plus_d$_A)
{
  mem->write(0, 0xFD);          // Opcode
  mem->write(1, 0x77);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IY = 1000;  // Address
  cpu->registers().A = 200;     // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(1010), 200);
  EXPECT_EQ(ticks, 19);
}

TEST_F(Load8bit, LD_$IY_plus_d$_B)
{
  mem->write(0, 0xFD);          // Opcode
  mem->write(1, 0x70);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IY = 1000;  // Address
  cpu->registers().B = 200;     // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(1010), 200);
  EXPECT_EQ(ticks, 19);
}

TEST_F(Load8bit, LD_$IY_plus_d$_C)
{
  mem->write(0, 0xFD);          // Opcode
  mem->write(1, 0x71);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IY = 1000;  // Address
  cpu->registers().C = 200;     // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(1010), 200);
  EXPECT_EQ(ticks, 19);
}

TEST_F(Load8bit, LD_$IY_plus_d$_D)
{
  mem->write(0, 0xFD);          // Opcode
  mem->write(1, 0x72);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IY = 1000;  // Address
  cpu->registers().D = 200;     // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(1010), 200);
  EXPECT_EQ(ticks, 19);
}

TEST_F(Load8bit, LD_$IY_plus_d$_E)
{
  mem->write(0, 0xFD);          // Opcode
  mem->write(1, 0x73);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IY = 1000;  // Address
  cpu->registers().E = 200;     // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(1010), 200);
  EXPECT_EQ(ticks, 19);
}

TEST_F(Load8bit, LD_$IY_plus_d$_H)
{
  mem->write(0, 0xFD);          // Opcode
  mem->write(1, 0x74);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IY = 1000;  // Address
  cpu->registers().H = 200;     // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(1010), 200);
  EXPECT_EQ(ticks, 19);
}

TEST_F(Load8bit, LD_$IY_plus_d$_L)
{
  mem->write(0, 0xFD);          // Opcode
  mem->write(1, 0x75);          // SubOpcode
  mem->write(2, 10);            // displacement
  cpu->indexation().IY = 1000;  // Address
  cpu->registers().L = 200;     // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(1010), 200);
  EXPECT_EQ(ticks, 19);
}

//-------------------------------------------
// Load8bit Code value to Data in HL address
//-------------------------------------------
TEST_F(Load8bit, LD_$HL$_n)
{
  mem->write(0, 0x36);        // Opcode
  mem->write(1, 100);         // Operando n
  cpu->registers().HL = 1000; // Address

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(1000), 100);
  EXPECT_EQ(ticks, 10);
}

//-------------------------------------------------------------
// Load8bit Code value to Data in IX address plus displacement
//-------------------------------------------------------------
TEST_F(Load8bit, LD_$IX_plus_d$_n)
{
  mem->write(0, 0xDD);          // Opcode
  mem->write(1, 0x36);          // SubOpcode
  mem->write(2, 10);            // Operand1 displacement
  mem->write(3, 200);           // Operand2 n
  cpu->indexation().IX = 1000;  // Address

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(1010), 200);
  EXPECT_EQ(ticks, 19);
}

//-------------------------------------------------------------
// Load8bit Code value to Data in IY address plus displacement
//-------------------------------------------------------------
TEST_F(Load8bit, LD_$IY_plus_d$_n)
{
  mem->write(0, 0xFD);          // Opcode
  mem->write(1, 0x36);          // SubOpcode
  mem->write(2, 10);            // Operand1 displacement
  mem->write(3, 200);           // Operand2 n
  cpu->indexation().IY = 1000;  // Address

  int ticks = cpu->run();

  EXPECT_EQ(mem->read(1010), 200);
  EXPECT_EQ(ticks, 19);
}

//-------------------------------------------
// Load8bit Data in BC address to Register A
//-------------------------------------------
TEST_F(Load8bit, LD_A_$BC$)
{
  mem->write(0, 0x0A);        // Opcode
  cpu->registers().BC = 1000; // Address
  mem->write(1000, 100);      // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().A, 100);
  EXPECT_EQ(ticks, 7);
}

//-------------------------------------------
// Load8bit Data in DE address to Register A
//-------------------------------------------

TEST_F(Load8bit, LD_A_$DE$)
{
  mem->write(0, 0x1A);        // Opcode
  cpu->registers().DE = 1000; // Address
  mem->write(1000, 100);      // Data to load

  int ticks = cpu->run();

  EXPECT_EQ(cpu->registers().A, 100);
  EXPECT_EQ(ticks, 7);
}

