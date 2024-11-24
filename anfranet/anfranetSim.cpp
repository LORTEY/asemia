#include <iostream>
#include <vector>
#include <random>
class device
{
	public:
		static std::vector<device*> allDevices;
		int location_y;
		int location_x;
		device()
	       	{
			allDevices.push_back(this);
		}
		void initialize(int x, int y)
		{
			location_x = x;
			location_y = y;
		}
		void print_location()
		{
			std::cout<<this->location_y;
			std::cout<<this->location_x;
		}
		static std::vector<device*> check_location(int x, int y, int range_square)
		{
			static std::vector<device*> qualifingDevices;
			for (device* element : allDevices)
			{
				if ((element->location_y - y)*(element->location_y - y) < range_square && (element->location_x - x)*(element->location_x - x) < range_square)
				{
					qualifingDevices.push_back(element);
				}
			}
			return qualifingDevices;
		}
};

std::vector<device*> device::allDevices;

int main()
{
	device* devices = new device[10];
	for (int i = 0; i < 10; i ++)
	{
		devices[i] = device();
		devices[i].initialize(i,i);
	}
	
	std::vector<device*> returnedValues = devices[0].check_location(4,4,1);
	for (device* element : returnedValues)
	{
		std::cout<<element->location_y;
	}
	return 0;
}
