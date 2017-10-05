#include "unity.h"

/*******************************************************************************
* Mocks
*******************************************************************************/
#include "mock_simple_buffer.h"

/*******************************************************************************
* MODULE UNDER TEST
*******************************************************************************/
#include "uart.h"

/*******************************************************************************
* Defines
*******************************************************************************/
#define MAX_BUFFER_SIZE 1
/*******************************************************************************
* Local Data
*******************************************************************************/
static uint16_t fake_ubbr;
static sbd_t fake_rx_buf;
static sbd_t fake_tx_buf;
static uint8_t fake_rx_buf_mem[MAX_BUFFER_SIZE];
static uint8_t fake_tx_buf_mem[MAX_BUFFER_SIZE];
/*******************************************************************************
* Setup and Teardown
*******************************************************************************/
void setUp(void)
{
  sb_attr_t fake_rx_buf_attr;
  fake_rx_buf_attr.buf_mem = &fake_rx_buf_mem;
  fake_rx_buf_attr.max_num_elem = MAX_BUFFER_SIZE;

  sb_attr_t fake_tx_buf_attr;
  fake_tx_buf_attr.buf_mem = &fake_tx_buf_mem;
  fake_tx_buf_attr.max_num_elem = MAX_BUFFER_SIZE;

  sb_construct_ExpectAndReturn(&fake_rx_buf_attr, &fake_rx_buf, SB_ERR_NONE);
  sb_construct_ExpectAndReturn(&fake_tx_buf_attr, &fake_tx_buf, SB_ERR_NONE);

  uart_attr_t config;
  config.baud = 1;
  config.ubbr_address = &fake_ubbr;
  config.rx_buf_attr = fake_rx_buf_attr;
  config.rx_buf = fake_rx_buf;
  config.tx_buf_attr = fake_tx_buf_attr;
  config.tx_buf = fake_tx_buf;

  uart_init(config);
}

void tearDown(void)
{
}

/*******************************************************************************
* Tests
*******************************************************************************/
void test_init_sets_config_vals(void)
{
  TEST_ASSERT(fake_ubbr == 1);
}
