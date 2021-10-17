FROM ubuntu

RUN apt-get update -y
RUN apt-get install build-essential -y
RUN apt-get install g++ -y

RUN mkdir /home/app
COPY . /home/app

WORKDIR /home/app

#RUN make AccLib
#CMD ["./Debug/AccLib.exe"]
