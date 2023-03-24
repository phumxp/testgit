#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

#define OFF 0
#define ON 1
#define LEDPin 25

void app_main(void)
{
    gpio_config_t _config = {};

    _config.pin_bit_mask = (1 << LEDPin);
    _config.mode = GPIO_MODE_OUTPUT;
    _config.pull_up_en = GPIO_PULLUP_DISABLE;
    _config.pull_down_en = GPIO_PULLDOWN_DISABLE;
    _config.intr_type = GPIO_INTR_DISABLE;

    gpio_config(&_config);

    while (true)
    {
        gpio_set_level(LEDPin, OFF);
        printf("LED OFF\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        gpio_set_level(LEDPin, ON);
        printf("LED ON\n");
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
