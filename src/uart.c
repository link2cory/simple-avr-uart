#include "uart.h"

/*******************************************************************************
* PUBLIC FUNCTION DEFINITIONS
*******************************************************************************/
void uart_init(uart_attr_t config) {
  *(config.ubbr_address) = config.baud;
}
