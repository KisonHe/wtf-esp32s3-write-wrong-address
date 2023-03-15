## How to reproduce error

copy `components/captive_portal/index.html.large` to `components/captive_portal/index.html`, run `idf flash monitor`, join the wifi, go to `192.168.4.1` ESP32 will crash.

But, if you copy `components/captive_portal/index.html.small` to `components/captive_portal/index.html`, strangely esp32s3 will not crash

## system version 

ESP-IDF:          v4.4.3-347-g9ee3c8337d

