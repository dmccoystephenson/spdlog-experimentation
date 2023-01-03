FROM ubuntu:18.04
USER root

# update
RUN apt-get update

# add build tools
RUN apt-get install -y g++

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