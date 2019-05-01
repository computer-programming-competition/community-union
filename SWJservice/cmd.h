#ifndef CMD_H
#define CMD_H

//服务器------->客户端
#define     Activity_send          0x0F01   //fa song huo dong xing xi
#define     Clear_activity         0x0F02   //
//#define     QFile_send             0x0F03   //发送文件
//#define     Struct_send            0x0F03   //发送结构体
//#define     Register_answer        0x0F04   //注册结果
//#define     Msg_send               0x0F05   //发送的信息
//#define     Add_group              0x0F06   //添加聊天室

//客户端------->服务器
#define     ReleaseActivity        0x0D01   //fa bu huo dong
#define     FlushActivity          0x0D02   //
//#define     Msg                    0x0D03   //客户端发送聊天信息
//#define     Connet_Success         0x0D04   //连接成功应答包

#endif // CMD_H
