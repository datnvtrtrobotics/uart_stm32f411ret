/*
 * uart_f411.h
 *
 *  Created on: Jul 11, 2024
 *      Author: tdat
 */


#ifndef UART_F411_H
#define UART_F411_H

#include "stm32f4xx_hal.h"
extern uint8_t data;

#define BUFFER_SIZE 100
typedef struct {
	      uint8_t buffer[BUFFER_SIZE];
	      volatile uint16_t head;
	      volatile uint16_t tail;
} CircularBuffer;
extern CircularBuffer rxBuffer;

// Buffer definitions
//#define BUFFER_SIZE 128
//extern char rx_buffer[BUFFER_SIZE];
extern uint16_t buffer_index;

void Config_uart(void);
void CircularBuffer_Write(CircularBuffer *cb, uint8_t data);
int CircularBuffer_Read(CircularBuffer *cb, uint8_t *data);
void CheckAndPrintReceivedData();
void handle_uart(void);

// UART communication functions
int UART_Available(void);
uint8_t UART_Read(void);
void UART_Print(const char *str);
void UART_Println(const uint8_t *str);

// Define GPIO Pins and Ports if not defined elsewhere
#ifndef LD2_Pin
#define LD2_Pin GPIO_PIN_5
#endif

#ifndef B1_Pin
#define B1_Pin GPIO_PIN_13
#endif

#ifndef B1_GPIO_Port
#define B1_GPIO_Port GPIOC
#endif


#endif /* UART_F411_H */
