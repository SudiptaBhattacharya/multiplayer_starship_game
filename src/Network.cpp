#include "../include/Network.h"

Network::Network() {
    socket.setBlocking(false); // Set socket to non-blocking
}
bool Network::setServer(int port) {
    if (listener.listen(port) == Socket::Done && listener.accept(socket) == Socket::Done) {
        std::cout << "Connected as Server" << std::endl;
        return true;
    }
    return false;
}
bool Network::setClient(int port, IpAddress ip) {
    if (socket.connect(ip,port) == Socket::Done) {
        std::cout << "Connected as Client" << std::endl;
        return true;
    }
    return false;
}
bool Network::sendPosition(const Vector2f &position) {
    packet << position.x << position.y;
    if (socket.send(packet) != Socket::Done) {
        std::cerr << "Error sending data!" << std::endl;
        return false;
    }
    return true;
}
bool Network::receivePosition(Vector2f &position) {
    if (socket.receive(packet) == Socket::Done) {
        if (packet >> position.x >> position.y) {
            position.x = position.x;
            position.y = position.y;
            packet.clear(); // Clear packet after reading
            return true;
        }
    } else if (socket.receive(packet) == Socket::NotReady) {
        // Socket not ready yet, no need to print errors
    }
    return false;
}
void Network::disconnect() {
    socket.disconnect();
    listener.close();
}