#ifndef _VL53L0X_PLATFORM_H_
#define _VL53L0X_PLATFORM_H_

#include "stm32l4xx_hal.h"
#include "vl53l0x_def.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    I2C_HandleTypeDef *i2cHandle;
    uint8_t I2cDevAddr;
    uint8_t comms_type;
    uint32_t comms_speed_khz;
} VL53L0X_Dev_t;

typedef VL53L0X_Dev_t *VL53L0X_DEV;

int VL53L0X_WriteMulti(VL53L0X_DEV Dev, uint8_t index, uint8_t *pdata, uint32_t count);
int VL53L0X_ReadMulti(VL53L0X_DEV Dev, uint8_t index, uint8_t *pdata, uint32_t count);
int VL53L0X_WrByte(VL53L0X_DEV Dev, uint8_t index, uint8_t data);
int VL53L0X_WrWord(VL53L0X_DEV Dev, uint8_t index, uint16_t data);
int VL53L0X_WrDWord(VL53L0X_DEV Dev, uint8_t index, uint32_t data);
int VL53L0X_RdByte(VL53L0X_DEV Dev, uint8_t index, uint8_t *data);
int VL53L0X_RdWord(VL53L0X_DEV Dev, uint8_t index, uint16_t *data);
int VL53L0X_RdDWord(VL53L0X_DEV Dev, uint8_t index, uint32_t *data);
int VL53L0X_PollingDelay(VL53L0X_DEV Dev);

#ifdef __cplusplus
}
#endif

#endif // _VL53L0X_PLATFORM_H_
