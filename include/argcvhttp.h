#ifndef __ARGCV_HTTP_H__
#define __ARGCV_HTTP_H__

// Make this header file easier to include in C++ code
#ifdef __cplusplus
extern "C" {
#endif


#define _ARGCV_HTTP_STATUS_100	"Continue"	//继续。客户端应继续其请求
#define _ARGCV_HTTP_STATUS_101	"Switching Protocols"	//切换协议。服务器根据客户端的请求切换协议。只能切换到更高级的协议，例如，切换到HTTP的新版本协议
#define _ARGCV_HTTP_STATUS_200	"OK"	//请求成功。一般用于GET与POST请求
#define _ARGCV_HTTP_STATUS_201	"Created"	//已创建。成功请求并创建了新的资源
#define _ARGCV_HTTP_STATUS_202	"Accepted"	//已接受。已经接受请求，但未处理完成
#define _ARGCV_HTTP_STATUS_203	"Non-Authoritative Information"	//非授权信息。请求成功。但返回的meta信息不在原始的服务器，而是一个副本
#define _ARGCV_HTTP_STATUS_204	"No Content"	//无内容。服务器成功处理，但未返回内容。在未更新网页的情况下，可确保浏览器继续显示当前文档
#define _ARGCV_HTTP_STATUS_205	"Reset Content"	//重置内容。服务器处理成功，用户终端（例如：浏览器）应重置文档视图。可通过此返回码清除浏览器的表单域
#define _ARGCV_HTTP_STATUS_206	"Partial Content"	//部分内容。服务器成功处理了部分GET请求
#define _ARGCV_HTTP_STATUS_300	"Multiple Choices"	//多种选择。请求的资源可包括多个位置，相应可返回一个资源特征与地址的列表用于用户终端（例如：浏览器）选择
#define _ARGCV_HTTP_STATUS_301	"Moved Permanently"	//永久移动。请求的资源已被永久的移动到新URI，返回信息会包括新的URI，浏览器会自动定向到新URI。今后任何新的请求都应使用新的URI代替
#define _ARGCV_HTTP_STATUS_302	"Found"	//临时移动。与301类似。但资源只是临时被移动。客户端应继续使用原有URI
#define _ARGCV_HTTP_STATUS_303	"See Other"	//查看其它地址。与301类似。使用GET和POST请求查看
#define _ARGCV_HTTP_STATUS_304	"Not Modified"	//未修改。所请求的资源未修改，服务器返回此状态码时，不会返回任何资源。客户端通常会缓存访问过的资源，通过提供一个头信息指出客户端希望只返回在指定日期之后修改的资源
#define _ARGCV_HTTP_STATUS_305	"Use Proxy"	//使用代理。所请求的资源必须通过代理访问
#define _ARGCV_HTTP_STATUS_306	"Unused"	//已经被废弃的HTTP状态码
#define _ARGCV_HTTP_STATUS_307	"Temporary Redirect"	//临时重定向。与302类似。使用GET请求重定向
#define _ARGCV_HTTP_STATUS_400	"Bad Request"	//客户端请求的语法错误，服务器无法理解
#define _ARGCV_HTTP_STATUS_401	"Unauthorized"	//请求要求用户的身份认证
#define _ARGCV_HTTP_STATUS_402	"Payment Required"	//保留，将来使用
#define _ARGCV_HTTP_STATUS_403	"Forbidden"	//服务器理解请求客户端的请求，但是拒绝执行此请求
#define _ARGCV_HTTP_STATUS_404	"Not Found"	//服务器无法根据客户端的请求找到资源（网页）。通过此代码，网站设计人员可设置"您所请求的资源无法找到"的个性页面
#define _ARGCV_HTTP_STATUS_405	"Method Not Allowed"	//客户端请求中的方法被禁止
#define _ARGCV_HTTP_STATUS_406	"Not Acceptable"	//服务器无法根据客户端请求的内容特性完成请求
#define _ARGCV_HTTP_STATUS_407	"Proxy Authentication Required"	//请求要求代理的身份认证，与401类似，但请求者应当使用代理进行授权
#define _ARGCV_HTTP_STATUS_408	"Request Time-out"	//服务器等待客户端发送的请求时间过长，超时
#define _ARGCV_HTTP_STATUS_409	"Conflict"	//服务器完成客户端的PUT请求是可能返回此代码，服务器处理请求时发生了冲突
#define _ARGCV_HTTP_STATUS_410	"Gone"	//客户端请求的资源已经不存在。410不同于404，如果资源以前有现在被永久删除了可使用410代码，网站设计人员可通过301代码指定资源的新位置
#define _ARGCV_HTTP_STATUS_411	"Length Required"	//服务器无法处理客户端发送的不带Content-Length的请求信息
#define _ARGCV_HTTP_STATUS_412	"Precondition Failed"	//客户端请求信息的先决条件错误
#define _ARGCV_HTTP_STATUS_413	"Request Entity Too Large"	//由于请求的实体过大，服务器无法处理，因此拒绝请求。为防止客户端的连续请求，服务器可能会关闭连接。如果只是服务器暂时无法处理，则会包含一个Retry-After的响应信息
#define _ARGCV_HTTP_STATUS_414	"Request-URI Too Large"	//请求的URI过长（URI通常为网址），服务器无法处理
#define _ARGCV_HTTP_STATUS_415	"Unsupported Media Type"	//服务器无法处理请求附带的媒体格式
#define _ARGCV_HTTP_STATUS_416	"Requested range not satisfiable"	//客户端请求的范围无效
#define _ARGCV_HTTP_STATUS_417	"Expectation Failed"	//服务器无法满足Expect的请求头信息
#define _ARGCV_HTTP_STATUS_500	"Internal Server Error"	//服务器内部错误，无法完成请求
#define _ARGCV_HTTP_STATUS_501	"Not Implemented"	//服务器不支持请求的功能，无法完成请求
#define _ARGCV_HTTP_STATUS_502	"Bad Gateway"	//充当网关或代理的服务器，从远端服务器接收到了一个无效的请求
#define _ARGCV_HTTP_STATUS_503	"Service Unavailable"	//由于超载或系统维护，服务器暂时的无法处理客户端的请求。延时的长度可包含在服务器的Retry-After头信息中
#define _ARGCV_HTTP_STATUS_504	"Gateway Time-out"	//充当网关或代理的服务器，未及时从远端服务器获取请求
#define _ARGCV_HTTP_STATUS_505	"HTTP Version not supported"	//服务器不支持请求的HTTP协议的版本，无法完成处理

#define ARGCV_HTTP_VERSION_1_1 1
#define ARGCV_HTTP_VERSION_1_0 0

char * argcv_http_request_get_url(const char * url);

int url_parse(const char * url,char * host , char * port);


#ifdef __cplusplus
}
#endif

#endif // __ARGCV_HTTP_H__
