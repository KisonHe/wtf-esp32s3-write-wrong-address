/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include "sdkconfig.h"
#include <esp_log.h>
#include <esp_system.h>
#include <nvs.h>
#include <nvs_flash.h>
#include "captive_portal.h"

static const char* TAG = "main";

static const char* hexchar = "0123456789abcdef";

void foo_the_system(){
    char * data = "WIFI:S:ip_can_hub_0000;T:WPA;P:hexman1234";
    char * labelText = "WIFI:ip_can_hub_0000\nPassword:hexman1234";

    uint8_t mac[8]={0};

    data[18] = hexchar[(mac[4]&0xF0)>>8];
    data[19] = hexchar[mac[4]&0x0F];
    data[20] = hexchar[(mac[5]&0xF0)>>8];
    data[21] = hexchar[mac[5]&0x0F];
    labelText[16] = hexchar[(mac[4]&0xF0)>>8];
    labelText[17] = hexchar[mac[4]&0x0F];
    labelText[18] = hexchar[(mac[5]&0xF0)>>8];
    labelText[19] = hexchar[mac[5]&0x0F];
}

void nvs_init(){
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        // NVS partition was truncated and needs to be erased
        // Retry nvs_flash_init
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }
    ESP_ERROR_CHECK( err );

    nvs_handle_t my_handle;
    err = nvs_open("storage", NVS_READWRITE, &my_handle);

    if (err != ESP_OK) {
        ESP_LOGE(TAG,"Error (%s) opening NVS handle!\n", esp_err_to_name(err));
        esp_restart();
    }
}

extern "C" void app_main() {
    // init nvs
    nvs_init();

    foo_the_system();

    start_portal();
}
