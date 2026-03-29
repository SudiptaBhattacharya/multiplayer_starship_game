#ifndef NETWORK_H
#define NETWORK_H
#include <string>
#include <SFML/Network.hpp>
#include <iostream>
using namespace sf;

class Network {
    public:
        Network();
        bool setServer(int port);
        bool setClient(int port, IpAddress ip);
        bool sendPosition(const Vector2f &position);
        bool receivePosition(Vector2f &position);
        void disconnect();
    private:
        TcpSocket socket;
        TcpListener listener;
        Packet packet;
};

#endif