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
typedef struct uart_attr_t {
  uint8_t baud;
  uint16_t *ubbr_address;
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
