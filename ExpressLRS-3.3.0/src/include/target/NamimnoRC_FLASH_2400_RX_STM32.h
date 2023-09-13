#ifndef DEVICE_NAME
#define DEVICE_NAME "Namimno 2G4RX"
#endif

// GPIO pin definitions
#define GPIO_PIN_RST            PB4
#define GPIO_PIN_BUSY           PB5
#define GPIO_PIN_DIO1           PB6
#define GPIO_PIN_DIO2           PB7
#define GPIO_PIN_NSS            PA4
#define GPIO_PIN_MOSI           PA7
#define GPIO_PIN_MISO           PA6
#define GPIO_PIN_SCK            PA5
#define GPIO_PIN_LED_RED        PA1

#define GPIO_PIN_RCSIGNAL_RX    PA10
#define GPIO_PIN_RCSIGNAL_TX    PA9

// Output Power - default for SX120

#define POWER_OUTPUT_FIXED 13 //MAX power for 2400 RXes that doesn't have PA is 12.5dbm
