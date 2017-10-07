#include "uart.h"
/*******************************************************************************
* Private Typedefs
*******************************************************************************/
typedef struct uart_config_t {
  uint16_t *ubbr;
  uint8_t *ucsra;
  uint8_t *ucsrb;
  uint8_t *ucsrc;
  uint8_t *udr;
} uart_config_t;
/*******************************************************************************
* Private Data
*******************************************************************************/
static uart_config_t _config;
static sbd_t rx_buf;
static sbd_t tx_buf;

/*******************************************************************************
* Public Function Definitions
*******************************************************************************/
void uart_init(uart_attr_t params) {
  // construct the buffers
  sb_construct(&params.rx_buf_attr, &params.rx_buf);
  sb_construct(&params.tx_buf_attr, &params.tx_buf);

  rx_buf = params.rx_buf;
  tx_buf = params.tx_buf;

  _config.ubbr = params.ubbr;
  _config.ucsra = params.ucsra;
  _config.ucsrb = params.ucsrb;
  _config.ucsrc = params.ucsrc;
  _config.udr = params.udr;

  // initialize registers
  *_config.ubbr = params.baud;
  *_config.ucsra = 0;
  *_config.ucsrb = 216;
  *_config.ucsrc = 13;
}

void uart_send_next() {
  uint8_t data;
  sb_get(rx_buf, &data);
  *_config.udr = data;
}
