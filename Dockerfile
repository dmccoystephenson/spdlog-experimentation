FROM ubuntu:18.04
USER root

# add build tools
RUN apt-get update && apt-get install -y software-properties-common wget git make gcc-7 g++-7 gcc-7-base && update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-7 100 && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-7 100

# install cmake
RUN apt-get install -y cmake

# install spdlog
RUN apt-get install -y libspdlog-dev

# add source and build files
ADD . /src
WORKDIR /src

# build
RUN chmod +x cr.sh
CMD ./cr.sh