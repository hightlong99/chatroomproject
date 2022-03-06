#pragma once
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <signal.h>


#define BUFFER_SZ 2048
#define MAX_CLIENTS 100

static unsigned int cli_count = 0;
static int uid = 10;
  