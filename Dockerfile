FROM alpine:latest

WORKDIR /opt/app

COPY Main.cpp .
COPY RecordSave.cpp .   
COPY CoreGame.cpp .

RUN apk update && apk add bash && apk add g++
RUN g++ Main.cpp -o Baseball
CMD ["./Baseball"]
