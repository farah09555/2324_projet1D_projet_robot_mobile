#include "vl53l0x_platform.h"

int VL53L0X_WriteMulti(VL53L0X_DEV Dev, uint8_t index, uint8_t *pdata, uint32_t count) {
    uint8_t buffer[count + 1];
    buffer[0] = index;
    for (uint32_t i = 0; i < count; i++) {
        buffer[i + 1] = pdata[i];
    }
    if (HAL_I2C_Master_Transmit(Dev->i2cHandle, Dev->I2cDevAddr, buffer, count + 1, HAL_MAX_DELAY) != HAL_OK) {
        return -1;
    }
    return 0;
}

int VL53L0X_ReadMulti(VL53L0X_DEV Dev, uint8_t index, uint8_t *pdata, uint32_t count) {
    if (HAL_I2C_Master_Transmit(Dev->i2cHandle, Dev->I2cDevAddr, &index, 1, HAL_MAX_DELAY) != HAL_OK) {
        return -1;
    }
    if (HAL_I2C_Master_Receive(Dev->i2cHandle, Dev->I2cDevAddr, pdata, count, HAL_MAX_DELAY) != HAL_OK) {
        return -1;
    }
    return 0;
}

int VL53L0X_WrByte(VL53L0X_DEV Dev, uint8_t index, uint8_t data) {
    uint8_t buffer[2];
    buffer[0] = index;
    buffer[1] = data;
    if (HAL_I2C_Master_Transmit(Dev->i2cHandle, Dev->I2cDevAddr, buffer, 2, HAL_MAX_DELAY) != HAL_OK) {
        return -1;
    }
    return 0;
}

int VL53L0X_WrWord(VL53L0X_DEV Dev, uint8_t index, uint16_t data) {
    uint8_t buffer[3];
    buffer[0] = index;
    buffer[1] = (data >> 8) & 0xFF;
    buffer[2] = data & 0xFF;
    if (HAL_I2C_Master_Transmit(Dev->i2cHandle, Dev->I2cDevAddr, buffer, 3, HAL_MAX_DELAY) != HAL_OK) {
        return -1;
    }
    return 0;
}

int VL53L0X_WrDWord(VL53L0X_DEV Dev, uint8_t index, uint32_t data) {
    uint8_t buffer[5];
    buffer[0] = index;
    buffer[1] = (data >> 24) & 0xFF;
    buffer[2] = (data >> 16) & 0xFF;
    buffer[3] = (data >> 8) & 0xFF;
    buffer[4] = data & 0xFF;
    if (HAL_I2C_Master_Transmit(Dev->i2cHandle, Dev->I2cDevAddr, buffer, 5, HAL_MAX_DELAY) != HAL_OK) {
        return -1;
    }
    return 0;
}

int VL53L0X_RdByte(VL53L0X_DEV Dev, uint8_t index, uint8_t *data) {
    if (HAL_I2C_Master_Transmit(Dev->i2cHandle, Dev->I2cDevAddr, &index, 1, HAL_MAX_DELAY) != HAL_OK) {
        return -1;
    }
    if (HAL_I2C_Master_Receive(Dev->i2cHandle, Dev->I2cDevAddr, data, 1, HAL_MAX_DELAY) != HAL_OK) {
        return -1;
    }
    return 0;
}

int VL53L0X_RdWord(VL53L0X_DEV Dev, uint8_t index, uint16_t *data) {
    uint8_t buffer[2];
    if (HAL_I2C_Master_Transmit(Dev->i2cHandle, Dev->I2cDevAddr, &index, 1, HAL_MAX_DELAY) != HAL_OK) {
        return -1;
    }
    if (HAL_I2C_Master_Receive(Dev->i2cHandle, Dev->I2cDevAddr, buffer, 2, HAL_MAX_DELAY) != HAL_OK) {
        return -1;
    }
    *data = (buffer[0] << 8) | buffer[1];
    return 0;
}

int VL53L0X_RdDWord(VL53L0X_DEV Dev, uint8_t index, uint32_t *data) {
    uint8_t buffer[4];
    if (HAL_I2C_Master_Transmit(Dev->i2cHandle, Dev->I2cDevAddr, &index, 1, HAL_MAX_DELAY) != HAL_OK) {
        return -1;
    }
    if (HAL_I2C_Master_Receive(Dev->i2cHandle, Dev->I2cDevAddr, buffer, 4, HAL_MAX_DELAY) != HAL_OK) {
        return -1;
    }
    *data = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | buffer[3];
    return 0;
}

int VL53L0X_PollingDelay(VL53L0X_DEV Dev) {
    HAL_Delay(1);
    return 0;
}
