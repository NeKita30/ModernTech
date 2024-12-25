FROM ubuntu:20.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y libgtest-dev libopencv-dev cmake build-essential && \
    apt-get clean

WORKDIR /app

COPY . /app

RUN cmake -S . -B build && cmake --build build