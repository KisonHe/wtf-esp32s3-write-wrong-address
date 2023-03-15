#pragma once
#ifdef __cplusplus
extern "C" {
#endif

extern char CAPTIVE_PORTAL_WIFI_SSID[];
extern char CAPTIVE_PORTAL_WIFI_PASSWD[];
void ssid_passwd_init();
void start_portal(void);

#ifdef __cplusplus
}
#endif

