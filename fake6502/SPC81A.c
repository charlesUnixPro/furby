#include <stdio.h>
#include <stdint.h>

//
// SPC81A.pdf

// 6.1 Max clock rate 6,0 MHz

// 6.4. ROM Area
// The SPC81A provides an 80K-byte ROM that can be defined as
// the program area, audio data area, or both. To access ROM,
// users should program the BANK SELECT Register, choose bank,
// and access address to fetch data.

// 6.5. RAM Area
// The SPC81A total RAM consists of 128 bytes (including Stack) at
// locations from $80 through $FF.

#define RAM_START 0x0080
#define RAM_SIZE  0x0080

uint8_t RAM[RAM_SIZE];

// 6.6 Map of Memory and I/Os

// *I/O PORT:               *MEMORY MAP (From ROM view)
//
//  - PORT IOA $0002        $0000  +----------------------+
//    PORT IOB $0003               | HW register, I/Os    |
//    PORT IOC $0005        $0080  +----------------------+
//    PORT IOD $0006               | USER RAM and STACK   |
//                          $0100  +----------------------+
//  - I/O CONFIG $0000             |        UNUSED        |
//               $0001      $0200  +----------------------+
//                                 | SUNPLUS TEST PROGRAM |
//  * NMI SOURCE:           $0600  +----------------------+
//                                 | USER'S PROGRAM &     |
//   - INTA (from TIMER A)         | DATA AREA            |
//                                 | ROM BANK #0          |
//  * INT SOURCE           $08000  +----------------------+
//                                 | ROM BANK #1          |
//   - INTA (from TIMER A) $10000  |                      |
//   - INTB (from TIMER B)         | UNUSED               |
//   - CPU CLK / 1024      $14000  |                      |
//   - CPU CLK / 8192              | ROM BANK #2          |
//   - CPU CLK / 65536     $17FFF  +----------------------+ 
//   - EXT INT

uint8_t io_config_0;
uint8_t io_config_1;
uint8_t port_ioa;
uint8_t port_iob;
uint8_t port_ioc;
uint8_t port_iod;

#define ROM_BANK_0_START 0x0600
#define ROM_BANK_0_SIZE  0x7A00  // 31232.
uint8_t ROM_BANK_0[ROM_BANK_0_SIZE];

#define ROM_BANK_1_START 0x8000
#define ROM_BANK_1_SIZE  0x8000  // 32768.
uint8_t ROM_BANK_1[ROM_BANK_1_SIZE];

#define ROM_BANK_2_START 0x14000
#define ROM_BANK_2_SIZE  0x4000  // 16384.
uint8_t ROM_BANK_2[ROM_BANK_2_SIZE];

// 6.8. Speech and Melody
// Since the SPC81A provides a large ROM and wide range of CPU
// operation speeds, it is most suitable for speech and melody
// synthesis.
// 
// For speech synthesis, the SPC81A can provide NMI for accurate
// sampling frequency. Users can record or synthesize the sound
// and digitize it into the ROM. The sound data can be played back
// in the sequence of the control functions as designed by the user's
// program. Several algorithms are recommended for high fidelity
// and compression of sound including PCM, LOG PCM, and
// ADPCM.
// 
// For melody synthesis, the SPC81A provides the dual tone mode.
// After selecting the dual tone mode, users only need to fill either
// TMA or TMB, or both TMA and TMB to generate expected
// frequency for each channel. The hardware will toggle the tone
// wave automatically without entering into an interrupt service
// routine. Users are able to simulate musical instruments or sound
// effects by simply controlling the envelope of tone output.

// 6.9. Volume Control Function
// The SPC81A contains a volume control function that provides an
// 8-step volume controller to control current D/A output. A volume
// control function selector (Enable/Disable) register and controller
// register is provided.

// 6.10. Serial Interface I/O
// The SPC81A provides serial interface I/O mode for those
// applications required large ROM/RAM. Serial Interface I/O Port
// can be used to read/write data from/to extra memory. The
// interface I/O Register is the control register for programming
// interface I/O.

// 6.11. Multi-Duty-Cycle Mode
// The SPC81A provides three output waveforms, 1/2, 1/3, and 1/4
// duty cycles. The Control Register should be used to select 1/2,
// 1/3 or 1/4 duty cycle and the IOA2 should be programmed as the
// multi-duty cycle output port. Users can use the combinations of
// these duty cycles for remote-control purposes.

// 6.13. Power Savings Mode
// The SPC81A provides a power savings mode (Standby mode) for
// those applications that require very low stand-by current. To
// enter standby mode, the Wake-Up Register should be enabled
// and then stop the CPU clock by writing the STOP CLOCK
// Register. The CPU will then go to the stand-by mode. In such a
// mode, RAM and I/Os will remain in their previous states until being
// awakened. Port IOD7-0 is the only wake-up source in the
// SPC81A. After the SPC81A is awakened, the internal CPU will
// go to the RESET State (Tw ≧ 65536 x T1) and then continue
// processing the program. Wakeup Reset will not affect RAM or
// I/Os (FIG.1).

// 6.14. Timer/Counter
// The SPC81A contains two 12-bit timer/counters, TMA and TMB
// respectively. TMA can be specified as a timer or a counter, but
// TMB can only be used as a timer. In the timer mode, TMA and
// TMB are re-loaded up-counters. When timer overflows from
// $0FFF to $0000, the carry signal will make the timer automatically
// reload to the user’s pre-set value and be up-counted again. At the
// same time, the carry signal will generate the INT signal if the
// corresponding bit is enabled in the INT ENABLE Register. If TMA
// is specified as a counter, users can reset by loading #0 into the
// counter. After the counter has been activated, the value of the
// counter can also be read from the counters at the same time.

// Timer/Counter         Clock Source
// TMA 12-BIT TIMER      CPU CLOCK (T) or T/4
// TMA 12-BIT COUNTER    T/64, T/8192, T/65536 or EXT CLK
// TMB 12-BIT TIMER      T or T/4
// MODE SELECT REGISTER  TMA only, select timer or counter
// TIMER CLOCK SELECTOR  Select T or T/4

void write6502(uint16_t address, uint8_t value)
  {
    if (address <= 0x0006)
      {
        switch (address)
          {
            case 0x0000:
              printf ("I/O CONFIG $0000 set to $%02x\n", value);
              io_config_0 = value;
              return;

            case 0x0001:
              printf ("I/O CONFIG $0001 set to $%02x\n", value);
              io_config_1 = value;
              return;

            case 0x0002:
              printf ("I/O PORT IOA  $0002 set to $%02x\n", value);
              port_ioa = value;
              return;

            case 0x0003:
              printf ("I/O PORT IOB  $0003 set to $%02x\n", value);
              port_iob = value;
              return;

            case 0x0004:
              goto write_error;

            case 0x0005:
              printf ("I/O PORT IOC  $0005 set to $%02x\n", value);
              port_ioc = value;
              return;

            case 0x0006:
              port_iod = value;
              printf ("I/O PORT IOD  $0006 set to $%02x\n", value);
              return;
          }
      }

    if (address >= RAM_START && address < RAM_START + RAM_SIZE)
       {
         RAM[address - RAM_START] = value;
       }

write_error:;
    printf ("Memory write to non-existent or read-only address: $%02x --> $%04x\n",
            value, address);
  }


uint8_t read6502(uint16_t address)
  {
    if (address <= 0x0006)
      {
        switch (address)
          {
            case 0x0000:
              printf ("I/O CONFIG $0000 read value of $%02x\n", io_config_0);
              return io_config_0;

            case 0x0001:
              printf ("I/O CONFIG $0001 read value of $%02x\n", io_config_1);
              return io_config_1;

            case 0x0002:
              printf ("I/O PORT IOA  $0002 read value of $%02x\n", port_ioa);
              return port_ioa;

            case 0x0003:
              printf ("I/O PORT IOB  $0003 read value of $%02x\n", port_iob);
              return port_iob;

            case 0x0004:
              goto read_error;

            case 0x0005:
              printf ("I/O PORT IOC  $0005 read value of $%02x\n", port_ioc);
              return port_ioc;

            case 0x0006:
              printf ("I/O PORT IOD  $0006 read value of $%02x\n", port_iod);
              return port_iod;
          }
      }

   if (address >= RAM_START && address < RAM_START + RAM_SIZE)
       {
         printf ("RAM read address $%04x value $%02x\n", address, RAM[address - RAM_START]);
         return RAM[address - RAM_START];
       }

   if (address >= ROM_BANK_0_START && address < ROM_BANK_0_START + ROM_BANK_0_START)
       {
         printf ("ROM bank 0 read address $%04x value $%02x\n", address, ROM_BANK_0[address - ROM_BANK_0_START]);
         return ROM_BANK_0[address - ROM_BANK_0_START];
       }


   if (address >= ROM_BANK_1_START && (uint32_t) address < (uint32_t) ROM_BANK_1_START + (uint32_t) ROM_BANK_1_START)
       {
         printf ("ROM bank 1 read address $%04x value $%02x\n", address, ROM_BANK_1[address - ROM_BANK_1_START]);
         return ROM_BANK_1[address - ROM_BANK_1_START];
       }


read_error:;
    printf ("Memory read form non-existent address: $%04x\n",
            address);
    return 0xFF;
  }

void reset6502 (void);
void exec6502 (uint32_t tick_count);
int main (int argc, char * argv [])
  {
    reset6502 ();
    exec6502 (10);
  }

