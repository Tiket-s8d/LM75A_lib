#include "LM75A.h"

uint8_t LM75_Temp_Read_Reg(uint8_t reg){
	char data_write[2] = {reg, CONFIGURATION};
	HAL_I2C_Master_Transmit(&hi2c1, ADDR, data_write, 2, HAL_MAX_DELAY);
	uint16_t value;
	HAL_I2C_Master_Receive(&hi2c1, ADDR, &value, 2, HAL_MAX_DELAY);
	value = ((( value >> 8 ) | ( value << 8 )) >> 7) & 0x01FF;

	if( value & 0x0100 ){
		value = (0x01FE ^ value) + 2;
		return (float)( value * (-0.5f) );
	}
	else{
		return (float)( value * 0.5f );
	}


}
uint8_t LM75_Read_THYST(){
	return LM75_Temp_9BIT_Read_Reg(THYST);
}

uint8_t LM75_Read_TOS(){
	return LM75_Temp_9BIT_Read_Reg(TOS);
}

void LM75_Temp_WriteReg(uint8_t reg, uint8_t temp){
	uint8_t arr[2] = {reg,temp};
	HAL_I2C_Master_Transmit(&hi2c1, ADDR, arr,2,HAL_MAX_DELAY);


}

uint8_t LM75A_ReadConfig(){
	HAL_I2C_Master_Transmit(&hi2c1, ADDR, CONFIGURATION,1,HAL_MAX_DELAY);
	uint8_t config;
	HAL_I2C_Master_Receive(&hi2c1, ADDR, &config, 1, HAL_MAX_DELAY);
	return config;
}

