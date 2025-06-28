# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I.

# Executable target name
TARGET = my_server_app

# Source files
SRC = \
    main.cpp \
    core/Request.cpp \
    core/Response.cpp \
    core/TokenStore.cpp \
    server/AuthMiddleware.cpp \
    server/RequestParser.cpp \
    server/Router.cpp \
    server/TCPServer.cpp \
    utils/StringUtils.cpp \
    utils/TokenGenerator.cpp \
    controllers/UserController.cpp \
    controllers/LoginController.cpp \
    controllers/AdminController.cpp

# Object files
OBJS = $(SRC:.cpp=.o)

# Default rule
all: $(TARGET)

# Link object files
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ -lws2_32

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)
