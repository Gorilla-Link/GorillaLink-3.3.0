#ifndef DEVICE_NAME
#define DEVICE_NAME "Namimno Flash"
#endif

#define USE_TX_BACKPACK
#define CRITICAL_FLASH

// GPIO pin definitions
#define GPIO_PIN_RST            PB4
#define GPIO_PIN_BUSY           PB5
#define GPIO_PIN_DIO1           PB6
#define GPIO_PIN_DIO2           PB7
#define GPIO_PIN_NSS            PA4
#define GPIO_PIN_MOSI           PA7
#define GPIO_PIN_MISO           PA6
#define GPIO_PIN_SCK            PA5
// SKY65383-11 front end control
#define GPIO_PIN_RX_ENABLE      PA8     // CRX
#define GPIO_PIN_TX_ENABLE      PA11    // CTX
#define GPIO_PIN_PA_ENABLE      PA12    // CSD

/* S.Port input signal */
#define GPIO_PIN_RCSIGNAL_RX        PB11 /* USART3 */
#define GPIO_PIN_RCSIGNAL_TX        PB10 /* USART3 */
#define GPIO_PIN_BUFFER_OE          PA1
#define GPIO_PIN_BUFFER_OE_INVERTED 1
#define GPIO_PIN_FAN_EN             PB1
/* Backpack logger connection */
#define GPIO_PIN_DEBUG_RX       PA10
#define GPIO_PIN_DEBUG_TX       PA9
/* WS2812 led */
#define GPIO_PIN_LED_WS2812         PB0
#define GPIO_PIN_LED_WS2812_FAST    PB_0

// Output Power
#define MinPower PWR_25mW
#define MaxPower PWR_1000mW
#define POWER_OUTPUT_VALUES {-18,-15,-12,-8,-5,3}
