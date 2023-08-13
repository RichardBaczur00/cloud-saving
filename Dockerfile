FROM ubuntu:18.04

WORKDIR /app

RUN apt-get update \
  && apt-get install -y ssh \
    build-essential \
    gcc \
    g++ \
    gdb \
    clang \
    cmake \
    rsync \
    tar \
    python \
    libjson-c-dev \
  && apt-get clean

RUN useradd -m user && yes password | passwd user

COPY . .

RUN make

CMD ["./main"]