FROM ros:foxy as hakoniwa-ros2pdu-dev

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
	git	\
	build-essential	\
	gcc	\
	g++	\
	vim	\
	libssl-dev \
	make	\
	autoconf \
	automake \
	pkg-config \
	curl \
	libffi-dev \
	python3-dev \
	python3-pip \
	&& apt-get clean \
	&& rm -rf /var/lib/apt/lists/*


RUN mkdir /root/workspace
WORKDIR /root/workspace

# jinja2
RUN pip install jinja2

#install python
RUN apt update &&  apt install -y python && \
	curl https://bootstrap.pypa.io/pip/2.7/get-pip.py -o get-pip.py && \
	python get-pip.py && \
	pip install jinja2

RUN apt install -y wget

#hakoniwa-core
WORKDIR /root/workspace/hako
RUN git clone --recursive https://github.com/toppers/hakoniwa-core-cpp-client.git
WORKDIR /root/workspace/hako/hakoniwa-core-cpp-client
RUN bash build.bash

ENV PATH /root/workspace/hako/hakoniwa-core-cpp-client/cmake-build/core/sample/base-procs/hako-master/:${PATH}
ENV PATH /root/workspace/hako/hakoniwa-core-cpp-client/cmake-build/core/sample/base-procs/hako-cmd/:${PATH}

WORKDIR /root/workspace

