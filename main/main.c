#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "esp_log.h"
#include "driver/gpio.h"

void app_main(void)
{
	esp_log_level_set("*", ESP_LOG_INFO);
	ESP_LOGI("app_main" , "Application start...");
	gpio_set_direction(GPIO_NUM_36, GPIO_MODE_INPUT);
	gpio_set_direction(GPIO_NUM_39, GPIO_MODE_INPUT);
	gpio_set_direction(GPIO_NUM_23, GPIO_MODE_OUTPUT);
	uint8_t buttonStatus = 0;
	uint8_t buttonStatus1 = 0;
	uint8_t ledStatus = 0;
	uint8_t InfoStatus = 0;
	while (true) {
        sleep(1);
        buttonStatus = gpio_get_level(GPIO_NUM_36);
        buttonStatus1 = gpio_get_level(GPIO_NUM_39);
        ESP_LOGI("app_main", "Button 1 status = %d",buttonStatus);
        ESP_LOGI("app_main", "Button 2 status = %d",buttonStatus1);
        if(buttonStatus == 0)
        {
        	ledStatus = ! ledStatus;
			ESP_LOGW("app_main", "LED 1 status = %d", ledStatus);
			gpio_set_level(GPIO_NUM_23, ledStatus);
        }
        if(buttonStatus1 == 0)
        {
        	InfoStatus = ! InfoStatus;
        	if(InfoStatus == 1 )
        		esp_log_level_set("*", ESP_LOG_INFO);
        	else
        		esp_log_level_set("*", ESP_LOG_WARN);
        }

    }
}
