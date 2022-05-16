#ifndef AOS_GPS_C_H
#define AOS_GPS_C_H

#include "driver/uart.h"

#ifdef __cplusplus
extern "C" {
#endif

struct uBloxGPS;
typedef struct uBloxGPS uBloxGPS_t;

uBloxGPS_t *init_Gps(uart_port_t port, int tx, int rx);
void destroy_Gps(uBloxGPS_t *gps);

float gps_GetLat(uBloxGPS_t *gps);
float gps_GetLng(uBloxGPS_t *gps);

#ifdef __cplusplus
}
#endif

#endif // AOS_GPS_C_H