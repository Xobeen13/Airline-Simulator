#ifndef AIRCRAFT_CLASS_H
#define AIRCRAFT_CLASS_H
#include <string>



class Aircraft {

	private:
	std::string AircraftName;
	int FuelPerKm, Range, CarrCap;

	public:
	Aircraft();

	Aircraft(std::string CraftName, std::string Fig, int FuelConsump, int FlightDist, int Cap);

	std::string getCraftName();

	int getFuelPerKm();

	int getRange();
	int getCarrCap();

	void setCraftName(std::string CraftName);
	
	void setFuelPerKm(int Fuel);

	void setRange(int P_range);

	void setCarrCap(int cap);

};

#endif AIRCRAFT_CLASS_H