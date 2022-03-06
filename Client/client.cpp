#include "header.h"
#include "handle.h"
//#include "handle.cpp"
// Global variables

int main(int argc, char **argv){
	if(argc != 2){
		//printf("Usage: %s <port>\n", argv[0]);
		cout<<"Usage: "<< argv[0]<< " <port> \n";
		return EXIT_FAILURE;
	}

	char *ip = "127.0.0.1";
	int port = atoi(argv[1]);

	signal(SIGINT, catch_ctrl_c_and_exit);

	printf("Please enter your name: ");
    fgets(name, 32, stdin);
 	str_trim_lf(name, strlen(name));


	if (strlen(name) > 32 || strlen(name) < 2){
		printf("Name must be less than 30 and more than 2 characters.\n");
		return EXIT_FAILURE;
	}
	 struct sockaddr_in server_addr;    
	 	/* Socket settings */	
	 sockfd = socket(AF_INET, SOCK_STREAM, 0);
 	 server_addr.sin_family = AF_INET;
 	 server_addr.sin_addr.s_addr = inet_addr(ip);
 	 server_addr.sin_port = htons(port);


  // Connect to Server
  int err = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (err == -1) {
		printf("ERROR: connect\n");
		return EXIT_FAILURE;
  	}
	// Send name
	send(sockfd, name, 32, 0);

	printf("=== WELCOME TO THE CHATROOM ===\n");

	pthread_t send_msg_thread;
  if(pthread_create(&send_msg_thread, NULL, &send_msg_handler, NULL) != 0){
		printf("ERROR: pthread\n");
    return EXIT_FAILURE;
	}

	pthread_t recv_msg_thread;
  if(pthread_create(&recv_msg_thread, NULL, &recv_msg_handler, NULL) != 0){
		printf("ERROR: pthread\n");
		return EXIT_FAILURE;
	}

	while (1){
		if(flag){
			printf("\nBye\n");
			break;
    }
	}

	close(sockfd);

	return EXIT_SUCCESS;
}
