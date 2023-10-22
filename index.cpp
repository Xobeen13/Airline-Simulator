#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;
/* Function
- Declares Variables for each piece of data in file
- Opens file and checks if it is open
- Reads file using for loop and then correctly assigns each piece of data to the alligned variable
- inputs Airport Code
*/
unordered_map<string, pair<float,float> > AirportList (){


    unordered_map<string, pair<float,float> > CoordList;
    string AirportCode, iata, Airport, Country;
	string City;
	string LatDeg, LatMin, LatSec, LatDir, Altitude; 		
	string LongDeg, LongMin, LongSec, LongDir;
	float Lat, Long;
	string line, LatDec, LongDec;
    
	ifstream GAD("GlobalAirportDatabase.txt");
    if(!GAD.is_open())
    {
        cout << "File not open" << endl;
    }
	if (GAD.is_open())
	{
	
		while(getline(GAD, line))
		{	
			stringstream ss(line);
			getline(ss, AirportCode, ':');
			getline(ss, iata, ':');
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
                CoordList.insert(make_pair(AirportCode,make_pair(Lat, Long)));
            }
		}
	}

	GAD.close();
    return CoordList;

}
void PrintList(unordered_map<string, pair<float,float> > &CoordinatesList){


    
    for (auto &it:CoordinatesList) {
    //it.first (string), it.second.first (x slot), it.second.first (y slot)
        cout << it.first << ": Lattitude-" << it.second.first << " Longitude-" << it.second.second << endl;

    }
}

int main(){
//Opens airport text file and checks if it opened correctly

unordered_map<string, pair<float,float> > CoordinatesList;

CoordinatesList = AirportList();	

PrintList(CoordinatesList);	

}


