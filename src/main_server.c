#include "tcp_server.h"
#include <stdio.h>
#include <stdlib.h>

#include "config.h"

int main(int argc, char *argv[]) {

  const char *IP;
  int PORT;
  char *buffer;

  if (argc != 3) {
    printf("Default parameters in use, if you wish to configure :\n");
    printf("%s <SERVER IP> <SERVER PORT>\n", argv[0]);
    IP = "192.168.1.1";
    PORT = 5000;

  } else {
    printf("Personalized parameters in use : \n");
    printf("Server IP adress : %s\n", argv[1]);
    printf("Server port : %s\n", argv[2]);
    IP = argv[1];
    PORT = atoi(argv[2]);
  }

  // Extract port from command-line arguments
  int serverPort = atoi(argv[1]);
  if (serverPort <= 0) {
    fprintf(stderr, "Invalid port number: %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  // Initialize TCP parameters
  config serverConfig;
  serverConfig.serverIP = IP;
  serverConfig.serverPort = PORT;
  serverConfig.bufferSize = 2048;
  buffer = malloc(sizeof(char) * serverConfig.bufferSize);

  // Start the TCP server
  printf("Starting server on port %d...\n", serverConfig.serverPort);
  if (startTCPServer(serverConfig.serverIP, serverConfig.serverPort, buffer,
                     serverConfig.bufferSize) != 0) {
    fprintf(stderr, "Failed to start TCP server\n");
    return EXIT_FAILURE;
  }

  printf("Server stopped\n");
  return EXIT_SUCCESS;
}
