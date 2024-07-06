/*
 * uart.c
 *
 *  Created on: Jul 7, 2024
 *      Author: tdat
 */


#include "stm32f4xx_hal.h"
#include "uart.h"


UART_Driver uart1 = { .huart.Instance = USART1, .isInitialized = 0 };
UART_Driver uart2 = { .huart.Instance = USART2, .isInitialized = 0 };
UART_Driver uart6 = { .huart.Instance = USART6, .isInitialized = 0 };

// Hàm trợ giúp khởi tạo GPIO cho UART
static void UART_MspInit(UART_HandleTypeDef *huart) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    if (huart->Instance == USART1) {
        __HAL_RCC_USART1_CLK_ENABLE();
        __HAL_RCC_GPIOA_CLK_ENABLE();

        GPIO_InitStruct.Pin = GPIO_PIN_9 ;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = GPIO_PIN_10;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    }
    if (huart->Instance == USART2) {
        __HAL_RCC_USART2_CLK_ENABLE();
        __HAL_RCC_GPIOA_CLK_ENABLE();

        GPIO_InitStruct.Pin = GPIO_PIN_2;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = GPIO_PIN_3;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    }
    if (huart->Instance == USART6) {
        __HAL_RCC_USART6_CLK_ENABLE();
        __HAL_RCC_GPIOC_CLK_ENABLE();

        GPIO_InitStruct.Pin = GPIO_PIN_6;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

        GPIO_InitStruct.Pin = GPIO_PIN_7;
        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_NOPULL;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    }
}

int UART_Init(UART_Driver *uart, UART_Config config) {
    if (uart->isInitialized) {
        return -1; // UART đã được khởi tạo trước đó
    }

    uart->config = config;
    // uart->huart.Instance = USART1; // Thay đổi cho phù hợp với UART cần dùng
    uart->huart.Init.BaudRate = config.baudRate;
    uart->huart.Init.WordLength = config.wordLength;
    uart->huart.Init.StopBits = config.stopBits;
    uart->huart.Init.Parity = config.parity;
    uart->huart.Init.Mode = UART_MODE_TX_RX;
    uart->huart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    uart->huart.Init.OverSampling = UART_OVERSAMPLING_16;

    UART_MspInit(&uart->huart);

    if (HAL_UART_Init(&uart->huart) != HAL_OK) {
        return 1; // Khởi tạo thất bại
    }

    uart->isInitialized = 1;
    return 0; // Khởi tạo thành công
}

int init(UART_HandleTypeDef *huart, UART_Config config) {
//    if (huart == &uart1.huart) {
//        uart1.huart.Instance = USART1;
//        return UART_Init(&uart1, config);
//    } else if (huart == &uart2.huart) {
//        uart2.huart.Instance = USART2;
//        return UART_Init(&uart2, config);
//    } else if (huart == &uart3.huart) {
//        uart3.huart.Instance = USART3;
//        return UART_Init(&uart3, config);
	    if (huart->Instance == USART1) {
	        return UART_Init(&uart1, config);
	    } else if (huart->Instance == USART2) {
	        return UART_Init(&uart2, config);
	    } else if (huart->Instance == USART6) {
	        return UART_Init(&uart6, config);
    } else {
        return 1; // Không tìm thấy UART phù hợp
    }
}

size_t read(uint8_t *buff, size_t len) {
    if (HAL_UART_Receive(&uart1.huart, buff, len, HAL_MAX_DELAY) == HAL_OK) {
        return len;
    } else if (HAL_UART_Receive(&uart2.huart, buff, len, HAL_MAX_DELAY) == HAL_OK) {
        return len;
    } else if (HAL_UART_Receive(&uart6.huart, buff, len, HAL_MAX_DELAY) == HAL_OK) {
        return len;
    }
    return 0;  // No data received
}
uint8_t readbyte() {
    uint8_t data;
    if (HAL_UART_Receive(&uart1.huart, &data, 1, HAL_MAX_DELAY) == HAL_OK) {
        return data;
    } else if (HAL_UART_Receive(&uart2.huart, &data, 1, HAL_MAX_DELAY) == HAL_OK) {
        return data;
    } else if (HAL_UART_Receive(&uart6.huart, &data, 1, HAL_MAX_DELAY) == HAL_OK) {
        return data;
    }
    return 0xFF;  // No data received
}

size_t write(uint8_t *buff, size_t len) {
    if (HAL_UART_Transmit(&uart1.huart, buff, len, HAL_MAX_DELAY) == HAL_OK) {
        return len;
    } else if (HAL_UART_Transmit(&uart2.huart, buff, len, HAL_MAX_DELAY) == HAL_OK) {
        return len;
    } else if (HAL_UART_Transmit(&uart6.huart, buff, len, HAL_MAX_DELAY) == HAL_OK) {
        return len;
    }
    return 0;  // No data written
}
int writebyte(char byte) {
    if (HAL_UART_Transmit(&uart1.huart,(uint8_t *) &byte, 1, HAL_MAX_DELAY) == HAL_OK) {
        return 0;  // Write successful
    } else if (HAL_UART_Transmit(&uart1.huart,(uint8_t *) &byte, 1, HAL_MAX_DELAY) == HAL_TIMEOUT) {
        return 1;  // Timeout
    } else if (HAL_UART_Transmit(&uart2.huart, (uint8_t *)&byte, 1, HAL_MAX_DELAY) == HAL_OK) {
        return 0;  // Write successful
    } else if (HAL_UART_Transmit(&uart2.huart,(uint8_t *) &byte, 1, HAL_MAX_DELAY) == HAL_TIMEOUT) {
        return 1;  // Timeout
    } else if (HAL_UART_Transmit(&uart6.huart, (uint8_t *)&byte, 1, HAL_MAX_DELAY) == HAL_OK) {
        return 0;  // Write successful
    } else if (HAL_UART_Transmit(&uart6.huart,(uint8_t *) &byte, 1, HAL_MAX_DELAY) == HAL_TIMEOUT) {
        return 1;  // Timeout
    } else {
        return -1;  // Error
    }
}

