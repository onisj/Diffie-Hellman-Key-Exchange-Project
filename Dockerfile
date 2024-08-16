# Use an official Ubuntu as a parent image
FROM ubuntu:20.04

# Set environment variables
ENV DEBIAN_FRONTEND=noninteractive

# Install required packages
RUN apt-get update && \
    apt-get install -y \
    g++ \
    gdb \
    make \
    vim \
    wget \
    tar

# Download and install SystemC
RUN wget https://www.accellera.org/images/downloads/standards/systemc/systemc-2.3.3.tar.gz && \
    tar -xzf systemc-2.3.3.tar.gz && \
    cd systemc-2.3.3 && \
    mkdir build && \
    cd build && \
    ../configure --prefix=/usr/local/systemc-2.3.3 && \
    make && \
    make install

# Set SystemC environment variables
ENV SYSTEMC_HOME=/usr/local/systemc-2.3.3
ENV LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$SYSTEMC_HOME/lib-linux64
ENV CPLUS_INCLUDE_PATH=$CPLUS_INCLUDE_PATH:$SYSTEMC_HOME/include

# Set the working directory in the container
WORKDIR /usr/src/myapp

# Copy the current directory contents into the container at /usr/src/myapp
COPY . .

# Build the project
RUN make

# Command to run the executable
CMD ["./out"]
