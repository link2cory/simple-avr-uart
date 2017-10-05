#include "uart.h"

/*******************************************************************************
* PUBLIC FUNCTION DEFINITIONS
*******************************************************************************/
void uart_init(uart_attr_t config) {
  sb_construct(&config.rx_buf_attr, &config.rx_buf);
  sb_construct(&config.tx_buf_attr, &config.tx_buf);

  *(config.ubbr_address) = config.baud;
}
