#include "stm32f1xx_hal.h"



extern I2C_HandleTypeDef hi2c1;

//

#define ADDR 0x48 << 1


#define TEMP_READ 0x00
#define CONFIGURATION 0x01
#define THYST 0x02
#define TOS 0x03



uint8_t LM75_Temp_9BIT_Read_Reg(uint8_t reg);
uint8_t LM75A_Read_Config();
