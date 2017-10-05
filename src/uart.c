#include "uart.h"

/*******************************************************************************
* PUBLIC FUNCTION DEFINITIONS
*******************************************************************************/
void uart_init(uart_attr_t config) {
  // construct the buffers
  sb_construct(&config.rx_buf_attr, &config.rx_buf);
  sb_construct(&config.tx_buf_attr, &config.tx_buf);

  // initialize registers
  *config.ubbr = config.baud;
  *config.ucsra = 0;
  *config.ucsrb = 216;
  *config.ucsrc = 13;

}
