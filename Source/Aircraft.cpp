#include "../Headers/Aircraft.h"
#include <string>

class Aircraft {

	private:
	std::string AircraftName;
	int FuelPerKm, Range, CarrCap;

	public:
	Aircraft(){
	std::string AircraftName = "Plane Name";
	int FuelPerKm = 5; 
	int Range = 1000;
	int CarrCap = 100;
	}

	Aircraft(std::string CraftName, std::string Fig, int FuelConsump, int FlightDist, int Cap){

	std::string AircraftName = CraftName;
	int FuelPerKm = FuelConsump; 
	int Range = FlightDist;
	int CarrCap = Cap;
	}

	std::string getCraftName(){
		return AircraftName;
	}

	int getFuelPerKm(){
		return FuelPerKm;
	}

	int getRange(){
		return Range;
	}
	int getCarrCap(){
		return CarrCap;
	}

	void setCraftName(std::string CraftName){
		AircraftName = CraftName;
	}
	
	void setFuelPerKm(int Fuel){
		FuelPerKm = Fuel;
	}

	void setRange(int P_range){
		Range = P_range;
	}

	void setCarrCap(int cap){
		CarrCap = cap;
	}

};