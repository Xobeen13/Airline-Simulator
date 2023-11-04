#include "Aircraft.h"
#include "../Headers/Route.h"
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
	Route(){
    std::string CityDepart = "City1";
	std::string CityArrival = "City2";
	Aircraft Plane;
	float Dist; 
	float Tickprice;
	float FlightTime;
	int LocalDepTime;
	int LocalArrTime;
    }

};