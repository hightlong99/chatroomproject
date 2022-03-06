#pragma once

#include "header.h"
#include "handle.cpp"
void str_overwrite_stdout();
void catch_ctrl_c_and_exit(int sig);
void *send_msg_handler(void *arg);
void *recv_msg_handler(void *arg);