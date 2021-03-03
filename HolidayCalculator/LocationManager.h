#pragma once
class LocationManager
{
	std::vector<Location> _vec_locations;
public:
	LocationManager() {}

	void add_location(Location location) { _vec_locations.push_back(location); }
	std::vector<Location>* get_vec_locations_ptr() { return &_vec_locations; }
};

