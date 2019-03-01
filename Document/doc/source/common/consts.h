// 接收客户端信息的缓冲区
static const uint32_t RECV_BUF_LEN = 16 * 1024;

// connsvr处理最大连接数量
static const uint32_t MAX_SOCKET_NUM = 500;

static const uint32_t SOCK_RECV_BUFFER = 512 * 1024;
static const uint32_t SOCK_SEND_BUFFER = 512 * 1024;
// const int STR_COMM_LEN = 128;
static const uint32_t LISTEN_BACKLOG = 512;

// CS&SS通讯包包头中长度字段占用的大小
static const uint32_t PKGHEAD_FIELD_SIZE = sizeof(int);
static const uint32_t CMD_FIELD_SIZE = sizeof(int);
static const uint32_t ERR_CODE_FIELD_SIZE = sizeof(int);
static const uint32_t OTHER_FIELD_SIZE = sizeof(int16_t);
static const uint32_t US_SN_FIELD_SIZE = sizeof(int);
static const uint32_t DS_SN_FIELD_SIZE = sizeof(int);
static const uint32_t PARAM_FIELD_SIZE = sizeof(uint64_t);

// CS通信包最小长度(包头占用空间大小)
static const uint32_t CS_PKGHEAD_SIZE = PKGHEAD_FIELD_SIZE + CMD_FIELD_SIZE + ERR_CODE_FIELD_SIZE +
    OTHER_FIELD_SIZE + US_SN_FIELD_SIZE + DS_SN_FIELD_SIZE;
// SS通信包最小长度(包头占用空间大小)目前相对于CS_PKGHEAD_SIZE少上行包下行包序号
static const uint32_t SS_PKGHEAD_SIZE =
    PKGHEAD_FIELD_SIZE + CMD_FIELD_SIZE + ERR_CODE_FIELD_SIZE + OTHER_FIELD_SIZE + PARAM_FIELD_SIZE;

// CS&SS通信包最大长度
static const uint32_t MAX_PKG_LEN = 10 * 1024 * 1024;
// CS&SS打包临时缓冲区大小
static const uint32_t PKG_OPT_BUFFSIZE = RECV_BUF_LEN * 2;

// connsvr一次从消息队列中取得的最大消息包数,即一次最多发送给client的消息回包数
static const uint32_t MAX_SEND_PKGNUM = 512;

//每帧最大处理消息数量
static const uint32_t MAX_LOOP_PER_FRAME = 30;

// 统计间隔时间
static const uint32_t STAT_TIME = 5;