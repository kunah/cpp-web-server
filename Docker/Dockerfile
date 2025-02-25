FROM ubuntu:22.04

RUN apt-get update
RUN apt-get upgrade -y
RUN apt-get -y install g++ cmake

ADD ../ /workspace
WORKDIR /workspace/build

RUN rm -rf *
RUN cmake ..
RUN make -j

WORKDIR /run/bin

RUN mv /workspace/build/cpp_web_server .
RUN mv /workspace/build/dist .

RUN rm -rf /workspace

CMD ./cpp_web_server