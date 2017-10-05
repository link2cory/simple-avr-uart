#ifndef _UART_H
#define _UART_H

/*******************************************************************************
* INCLUDES
*******************************************************************************/
#include <stdint.h>
#include "simple_buffer.h"
/*******************************************************************************
* PUBLIC TYPEDEFS
*******************************************************************************/
typedef enum uart_stopbits_t {
  UART_STOPBITS_TWO
} uart_stopbits_t;

typedef enum uart_character_size_t {
  UART_CHARACTER_SIZE_EIGHT
} uart_character_size_t;


typedef struct uart_attr_t {
  uint8_t baud;
  uint16_t *ubbr;
  uint8_t *ucsra;
  uint8_t *ucsrb;
  uint8_t *ucsrc;
  uint8_t stop_bits;
  uint8_t character_size;

  sb_attr_t rx_buf_attr;
  sb_attr_t tx_buf_attr;
  sbd_t rx_buf;
  sbd_t tx_buf;
} uart_attr_t;

/*******************************************************************************
* PUBLIC FUNCTION DECLARATIONS
*******************************************************************************/
void uart_init(uart_attr_t);

#endif // _UART_H
