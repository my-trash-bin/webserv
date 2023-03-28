#ifndef __METAINFO__HPP__
#define __METAINFO__HPP__

#include <string>
#include <vector>

// upstream info ==============================================================
struct UpstreamPathInfo {
  std::string type; // type of upstream path ex. "server"
  std::string host; // host of upstream path
  int port;         // port of upstream path
  int weight;       // weight of upstream path
};

struct UpstreamInfo {
  std::vector<UpstreamPathInfo> upstream_path_info;
};

// location info ==============================================================
struct rewriteInfo {
  std::string regex; // regex of rewrite
  std::string path;  // path of rewrite
  std::string type;  // type of rewrite
};

struct CgiInfo {
  std::string extension; // extension of cgi
  std::string path;      // path of cgi
};

struct ExpireTime {
  bool is_max;        // MAX flag
  std::string period; // period of expire time ex. "D", "M", "Y"
  int time;           // time of expire time
};

struct LocationInfo {
  std::string location_path; // location path of server ex. location "/test"
  std::string root;          // root directory of server
  std::string proxy_pass;    // proxy_pass url of server
  bool autoindex;            // autoindex flag of server

  rewriteInfo rewrite_info; // rewrite info of server
  ExpireTime expire_time;   // expire time of server
  std::vector<CgiInfo> cgi_info;
};

// server info ================================================================
struct ServerInfo {
  int listen_port;         // listen port
  std::string server_name; // server name
  std::string root;        // root directory of server
  std::string index;       // index file path of server
  std::string error_page;  // error page path of server
  std::string access_log;  // access log path of server
  std::string error_log;   // error log path of server
  std::vector<LocationInfo> location_info;
};

// protocol block info ========================================================
struct LogInfo {
  std::string log_path; // log path
  std::string log_type; // log type
};

struct ProtocolBlock {
  std::string protocol_name;      // protocol name
  std::string protocol_version;   // protocol version
  size_t client_max_body_size;    // client max body size
  std::string default_error_page; // default error page path
  std::string default_type;       // default type

  std::vector<LogInfo> log_info; // log info ex. access_log, error_log...
  std::vector<ServerInfo> server_info;
  std::vector<UpstreamInfo> upstream_info;
};

// global info ================================================================
struct WebServerMetaInfo {
  std::string server_name;  // server name
  int worker_processes;     // number of worker processes
  int worker_connections;   // number of worker connections
  int worker_rlimit_nofile; // number of worker rlimit nofile

  std::vector<ProtocolBlock> protocol_block;
};

#endif // __METAINFO__HPP__
