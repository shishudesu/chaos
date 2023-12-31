//
// Created by shishu on 1/6/24.
//
#ifndef CHAOS_UTILS_H
#define CHAOS_UTILS_H

#include<rtc/rtc.hpp>

#include <random>
#include <nlohmann/json.hpp>

#include "Chaos.h"

using nlohmann::json;

using namespace std::chrono_literals;

using std::weak_ptr;
using std::shared_ptr;

template <class T> weak_ptr<T> make_weak_ptr(shared_ptr<T> ptr) {return ptr;}

std::string get_random_id(size_t length);

shared_ptr<rtc::PeerConnection> create_peer_connection(const rtc::Configuration& rtc_config, const weak_ptr<rtc::WebSocket>& weak_websocket, std::string client_id);
void setup_datachannel_handlers(const shared_ptr<rtc::DataChannel>& t_datachannel, const std::string& client_id);
void send_message(const weak_ptr<rtc::DataChannel>& weak_data_channel, std::string message_content);

#endif //CHAOS_UTILS_H