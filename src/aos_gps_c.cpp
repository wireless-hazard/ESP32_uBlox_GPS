#include "aos_gps.h"
#include "aos_gps_c.h"

struct uBloxGPS{
	void *gps_ptr;	
};



uBloxGPS_t *init_Gps(uart_port_t port, int tx, int rx)
{
	uBloxGPS_t *m;
	Gps *obj;

	m      = (typeof(m))malloc(sizeof(*m));
	obj    = new Gps();
	m->gps_ptr = obj;

	obj->init(port, tx, rx);

	return m;
}

void destroy_Gps(uBloxGPS_t *gps)
{
	if (gps != nullptr){
		delete static_cast<Gps *>(gps->gps_ptr);
		free(gps);
	}
}

float gps_GetLat(uBloxGPS_t *gps)
{
	Gps *obj;
	float lat = 0;

	if (gps != nullptr){
		obj = static_cast<Gps *>(gps->gps_ptr);
		lat = obj->getLat();
	}

	return lat;
}

float gps_GetLng(uBloxGPS_t *gps)
{
	Gps *obj;
	float lng = 0;

	if (gps != nullptr){
		obj = static_cast<Gps *>(gps->gps_ptr);
		lng = obj->getLng();
	}

	return lng;
}