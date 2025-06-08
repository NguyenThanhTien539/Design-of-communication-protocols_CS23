FROM ubuntu:24.04

# Cài g++ và telnet để build và test
RUN apt-get update && apt-get install -y \
    g++ \
    telnet \
    && rm -rf /var/lib/apt/lists/*

# Copy toàn bộ mã nguồn vào /app
WORKDIR /app
COPY . .

# Build server (nếu có script build.sh thì dùng)
RUN chmod +x build.sh && ./build.sh

# Expose cổng server
EXPOSE 8085

# Chạy server khi container start
CMD ["./cs23_server", "8085"]
