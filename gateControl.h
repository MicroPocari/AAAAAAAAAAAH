#include <iostream>
#include <string>
#include "E101.h"

using namespace std;
class gateControl
{
	private:
	char serverAddr[15] = {'1','3','0','.','1','9','5','.','6','.','1','9','6'};
	int port = 1024;
	char message[24] = {'P','l','e','a','s','e'};
	int recieve;
	
	public:
	void OPENTEHGATES();

};

void gateControl::OPENTEHGATES()
{
	//first, connect to server!
	connect_to_server(serverAddr, port);
	
	//second, send message!
	send_to_server(message);
	
	//third, get the password
	receive_from_server(message);
	
	//char password[24] = (char)recieve;
	
	//now OPEN TEEEH GAAATES!!!!
	send_to_server(message);
}
