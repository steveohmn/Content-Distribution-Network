#ifndef ORIGIN_CLIENT_RECEIVER_H
#define ORIGIN_CLIENT_RECEIVER_H

#include "cpprest/http_listener.h"

using namespace web;
using namespace http;
using namespace utility;
using namespace http::experimental::listener;


class OriginClientReceiver {
public:
    OriginClientReceiver() {}
    OriginClientReceiver(utility::string_t url);
    static void intialize(const string_t& address);
    static void shutDown();
    static OriginClientReceiver* getInstance() { return m_instance; }

    pplx::task<void> open() { return m_listener.open(); }
    pplx::task<void> close() { return m_listener.close(); }

private:

    void handle_get(http_request message);
    void handle_put(http_request message);
    void handle_post(http_request message);
    void handle_delete(http_request message);

    http_listener m_listener;
    static OriginClientReceiver* m_instance;
};

OriginClientReceiver* OriginClientReceiver::m_instance = NULL;

#endif