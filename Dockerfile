FROM ubuntu:latest

RUN sudo apt-get update
RUN sudo apt-get install -y gcc make cmake git

ENV PORT=8080

CMD [ "echo", "Hello World" ]