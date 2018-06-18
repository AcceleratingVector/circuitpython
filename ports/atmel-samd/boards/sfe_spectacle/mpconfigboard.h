#define MICROPY_HW_BOARD_NAME "SparkFun Spectacle"
#define MICROPY_HW_MCU_NAME "samd21g18"

//#define MICROPY_HW_NEOPIXEL (&pin_PA06)

// Clock rates are off: Salae reads 12MHz which is the limit even though we set it to the safer 8MHz.
#define SPI_FLASH_BAUDRATE  (8000000)

#define SPI_FLASH_MOSI_PIN          PIN_PB10
#define SPI_FLASH_MISO_PIN          PIN_PA12
#define SPI_FLASH_SCK_PIN           PIN_PB11
#define SPI_FLASH_CS_PIN            PIN_PA07
#define SPI_FLASH_MOSI_PIN_FUNCTION PINMUX_PB10D_SERCOM4_PAD2
#define SPI_FLASH_MISO_PIN_FUNCTION PINMUX_PA12D_SERCOM4_PAD0
#define SPI_FLASH_SCK_PIN_FUNCTION  PINMUX_PB11D_SERCOM4_PAD3
#define SPI_FLASH_SERCOM            SERCOM4
#define SPI_FLASH_SERCOM_INDEX      4
#define SPI_FLASH_MOSI_PAD          2
#define SPI_FLASH_MISO_PAD          0
#define SPI_FLASH_SCK_PAD           3
// <o> Transmit Data Pinout
// <0x0=>PAD[0,1]_DO_SCK
// <0x1=>PAD[2,3]_DO_SCK
// <0x2=>PAD[3,1]_DO_SCK
// <0x3=>PAD[0,3]_DO_SCK
// KDB - Not sure on these
// KDB - Set DIPO to 0 -- "Same as MISO pad"
// KDB - DOPO = 0, firmware doesnt work. Set to 1 - Works.
#define SPI_FLASH_DOPO              1   
#define SPI_FLASH_DIPO              0   // same as MISO pad

// These are pins not to reset.
// KDB - this has the SPI and USB pins. Note this is broken up by ports 
//#define MICROPY_PORT_A        (PORT_PA06 | PORT_PA08 | PORT_PA09 | PORT_PA13 | PORT_PA14 | PORT_PA24 | PORT_PA25)
#define MICROPY_PORT_A        (PORT_PA07 | PORT_PA12 | PORT_PA24 | PORT_PA25)
#define MICROPY_PORT_B        (PORT_PB10 | PORT_PB11 )
#define MICROPY_PORT_C        ( 0 )

#include "external_flash/external_flash.h"

// If you change this, then make sure to update the linker scripts as well to
// make sure you don't overwrite code.
#define CIRCUITPY_INTERNAL_NVM_SIZE 256

#define BOARD_FLASH_SIZE (0x00040000 - 0x2000 - CIRCUITPY_INTERNAL_NVM_SIZE)

#include "external_flash/devices.h"

// KDB Change
// This is a list of possible Flash components for the board
// This are defined in the file:
//  circuitpython/ports/atmel-samd/external_flash/devices.h
//
// This file contains defs for known modules. Use the following macros to define the 
// list. On startup, the system loops over the list and compairs module ID to 
// what is defined on this list. 
//
// Spectacle contains a WINBOND 25Q32FV. After some testing, the 
// following parameters were set for this module:
//      man id:    	0xef
//      type:   	0x40
//      cap:    	0x16
//
// The module is running in SPI mode, not QSPI. Also it's 4MB
//  
/*
#define EXTERNAL_FLASH_DEVICE_COUNT 2
#define EXTERNAL_FLASH_DEVICES S25FL216K, \
                               GD25Q16C
  */
                               
#define EXTERNAL_FLASH_DEVICE_COUNT 1
#define EXTERNAL_FLASH_DEVICES W25Q32FV
/*
#define EXTERNAL_FLASH_DEVICES W25Q32FV, \
								W25Q32FVa, \
								W25Q32FVb, \
								W25Q32FVc
*/
// End KDB Change
#include "external_flash/external_flash.h"

#define BOARD_HAS_CRYSTAL 1

#define DEFAULT_I2C_BUS_SCL (&pin_PA23)
#define DEFAULT_I2C_BUS_SDA (&pin_PA22)

#define DEFAULT_SPI_BUS_SCK (&pin_PB11)
#define DEFAULT_SPI_BUS_MOSI (&pin_PB10)
#define DEFAULT_SPI_BUS_MISO (&pin_PA12)

#define DEFAULT_UART_BUS_RX (&pin_PA11)
#define DEFAULT_UART_BUS_TX (&pin_PA10)

// USB is always used internally so skip the pin objects for it.
#define IGNORE_PIN_PA24     1
#define IGNORE_PIN_PA25     1
