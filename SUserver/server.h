#ifndef SERVER_H
#define SERVER_H
#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <vector>
using namespace boost::asio;
using std::cout;            using std::endl;
using std::string;          using std::vector;
typedef boost::shared_ptr<ip::tcp::socket> socket_ptr; //简化定义
class Server
{
public:
    Server();
    void connect();//客户端连接
    void receiveMessage(socket_ptr sock);  //接受信息
    void readdata(socket_ptr &sock);       //读取数据
    bool verifyaccount(string account);
//    void writedata();
//    void dealMessage(std::string sig,vector<string> str,socket_ptr sock);
};

#endif // SERVER_H
