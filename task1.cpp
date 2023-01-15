#include <iostream>
#include <thread>
#include <chrono>


unsigned int clientsQty = 0;

class Clients
{
public:
	void enlargeQueue()
	{
		while (clientsQty != 20)
		{
			++clientsQty;
			std::cout << clientsQty << " ";
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}
};

class Clerk
{
public:
	void reduceQueue()
	{
		while (clientsQty != 0)
		{
			--clientsQty;
			std::cout << clientsQty << " ";
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}
	}
};

int main(int argc, char** argv)
{
	Clients clients;
	Clerk clerk;
	std::thread t1(&Clients::enlargeQueue, &clients);
	std::thread t2(&Clerk::reduceQueue, &clerk);
	t1.join();
	t2.join();

	return 0;
}