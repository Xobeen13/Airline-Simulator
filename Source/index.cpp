#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>
#include <chrono>
#include "../Headers/Aircraft.h"


using namespace std;

class Route {
	private:

	Aircraft Plane;
	string CityDepart;
	string CityArrival;
	float Dist;
	float Tickprice;
	float FlightTime;
	int LocalDepTime;
	int LocalArrTime;
	public:
	
};
/* Function
- Declares Variables for each piece of data in file
- Opens file and checks if it is open
- Reads file using for loop and then correctly assigns each piece of data to the alligned variable
- inputs Airport Code, lattitude, and longtude to umap
*/
unordered_map<string, pair<float,float> > AirportList (){


    unordered_map<string, pair<float,float> > CoordList;
    string Icao, Iata, Airport, Country;
	string City;
	string LatDeg, LatMin, LatSec, LatDir, Altitude; 		
	string LongDeg, LongMin, LongSec, LongDir;
	float Lat, Long;
	string line, LatDec, LongDec;
    
	ifstream GAD("../Data/GlobalAirportDatabase.txt");
    if(!GAD.is_open())
    {
        cout << "File not open" << endl;
    }
	if (GAD.is_open())
	{
	
		while(getline(GAD, line))
		{	
			stringstream ss(line);
			getline(ss, Icao, ':');
			getline(ss, Iata, ':');
			getline(ss, Airport, ':');
			getline(ss, City, ':');
			getline(ss, Country, ':');
			getline(ss, LatDeg, ':');
			getline(ss, LatMin, ':');
			getline(ss, LatSec, ':');
			getline(ss, LatDir, ':');
			getline(ss, LongDeg, ':');
			getline(ss, LongMin, ':');
			getline(ss, LongSec, ':');
			getline(ss, LongDir, ':');
			getline(ss, Altitude, ':');
			getline(ss, LatDec, ':');
			Lat = stof(LatDec);

			getline(ss, LongDec, ':');
			Long = stof(LongDec);
            if(Lat!=0 && Long !=0){
                CoordList.insert(make_pair(Iata,make_pair(Lat, Long)));
            }
		}
	}

	GAD.close();
    return CoordList;

}
//Prints out Umap
void PrintList(unordered_map<string, pair<float,float> > &CoordinatesList){
    for (auto &it:CoordinatesList) {
    //it.first (string), it.second.first (x slot), it.second.first (y slot)
        cout << it.first << ": Lattitude-" << it.second.first << " Longitude-" << it.second.second << endl;

    }
}
//Converts degrees to radians
float deg2rad(float deg){
	return deg * M_PI / 180.0;
}

/*
Takes a departure and arrival city and uses the Umap to find their global positioning and calculate the total distance between
the two cities
*/
float CoordDist(unordered_map<string, pair<float,float> > &CoordinatesList){
	string AirKeyDepart, AirKeyArrival;
	float LatDep, LatArr, LongDep, LongArr, DistLat, DistLong, TotDist, AHavSin, CHavSin;
	const float EarthRad = 6371.0;

	cout << "Departure Airport Code: ";
	cin >> AirKeyDepart;
	cout << endl << "Arrival Airport Code: ";
	cin >> AirKeyArrival;

	auto depart = CoordinatesList.find(AirKeyDepart);
	auto arrival = CoordinatesList.find(AirKeyArrival);

	if (depart != CoordinatesList.end() && arrival != CoordinatesList.end()) {
        LatDep = depart -> second.first;
		LongDep = depart -> second.second;
		LatArr = arrival -> second.first;
		LongArr = arrival -> second.second;
    } else {
        cout << "Key not found." << endl;
    }

	// Convert latitude and longitude from degrees to radians
    LatDep = deg2rad(LatDep);
    LongDep = deg2rad(LongDep);
    LatArr = deg2rad(LatArr);
    LongArr = deg2rad(LongArr);

	//Haversine Formula implementation
	DistLat = LatArr - LatDep;
	DistLong = LongArr - LongDep;

	AHavSin = pow(sin(DistLat / 2.0), 2) + cos(LatDep) * cos(LatArr) * pow(sin(DistLong / 2.0), 2);
    CHavSin = 2 * atan2(sqrt(AHavSin), sqrt(1 - AHavSin));
    TotDist = EarthRad * CHavSin;

	cout << "Distance from " << AirKeyDepart << " to " << AirKeyArrival << ": " << TotDist << "Km";
	return TotDist;
}



int main(){
//Umap decleared

unordered_map<string, pair<float,float> > CoordinatesList;

CoordinatesList = AirportList();	

//PrintList(CoordinatesList);
CoordDist(CoordinatesList);	
}


