#ifndef ROUTE_CLASS_H
#define ROUTE_CLASS_H

#include "Aircraft.h"
#include <string>

class Route {
	private:
	std::string CityDepart;
	std::string CityArrival;
	Aircraft Plane;
	float Dist;
	float Tickprice;
	float FlightTime;
	int LocalDepTime;
	int LocalArrTime;

	public:
	Route();

};

#endif ROUTE_CLASS_H