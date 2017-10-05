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
#define EXPECTED_UCSRCA 0
#define EXPECTED_UCSRCB 216
/*******************************************************************************
* Local Data
*******************************************************************************/
uart_attr_t config;
// fake registers
static uint16_t fake_ubbr;
static uint8_t fake_ucsra;
static uint8_t fake_ucsrb;
static uint8_t fake_ucsrc;

// fake buffers
static sbd_t fake_rx_buf;
static sbd_t fake_tx_buf;
static uint8_t fake_rx_buf_mem[MAX_BUFFER_SIZE];
static uint8_t fake_tx_buf_mem[MAX_BUFFER_SIZE];
/*******************************************************************************
* Setup and Teardown
*******************************************************************************/
void setUp(void)
{
  // setup buffers
  sb_attr_t fake_rx_buf_attr;
  fake_rx_buf_attr.buf_mem = &fake_rx_buf_mem;
  fake_rx_buf_attr.max_num_elem = MAX_BUFFER_SIZE;

  sb_attr_t fake_tx_buf_attr;
  fake_tx_buf_attr.buf_mem = &fake_tx_buf_mem;
  fake_tx_buf_attr.max_num_elem = MAX_BUFFER_SIZE;

  sb_construct_ExpectAndReturn(&fake_rx_buf_attr, &fake_rx_buf, SB_ERR_NONE);
  sb_construct_ExpectAndReturn(&fake_tx_buf_attr, &fake_tx_buf, SB_ERR_NONE);

  config.rx_buf_attr = fake_rx_buf_attr;
  config.rx_buf = fake_rx_buf;
  config.tx_buf_attr = fake_tx_buf_attr;
  config.tx_buf = fake_tx_buf;

  // setup registers
  config.baud = 1;
  config.ubbr = &fake_ubbr;
  config.ucsra = &fake_ucsra;
  config.ucsrb = &fake_ucsrb;
  config.ucsrc = &fake_ucsrc;
  config.stop_bits = UART_STOPBITS_TWO;
  config.character_size = UART_CHARACTER_SIZE_EIGHT;

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

  TEST_ASSERT(fake_ucsra == 0);
  TEST_ASSERT(fake_ucsrb == 216);
  TEST_ASSERT(fake_ucsrc == 13);
}

void test_init_sets_character_size(void)
{
  TEST_ASSERT(fake_ucsrc == 13);
}
