FROM ubuntu

RUN ln -snf /usr/share/zoneinfo/$CONTAINER_TIMEZONE /etc/localtime && echo $CONTAINER_TIMEZONE > /etc/timezone

RUN apt-get update -y
RUN apt-get install build-essential -y
RUN apt-get install g++ -y
RUN apt-get install -y cmake
RUN apt-get install valgrind -y

RUN mkdir /home/app
RUN mkdir /home/app/AccLib.Tests.GoogleTests

COPY AccLib /home/app/AccLib

COPY AccLib.Tests.GoogleTests/string_tests.cpp /home/app/AccLib.Tests.GoogleTests/
COPY AccLib.Tests.GoogleTests/unique_pointer_tests.cpp /home/app/AccLib.Tests.GoogleTests/
COPY AccLib.Tests.GoogleTests/vector_tests.cpp /home/app/AccLib.Tests.GoogleTests/

COPY AccLib.Tests.GoogleTests/CMakeLists.txt /home/app/AccLib.Tests.GoogleTests/

WORKDIR /home/app/AccLib.Tests.GoogleTests
RUN cmake -S . -B build
RUN cmake --build build
