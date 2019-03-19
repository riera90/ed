FROM gcc:8.2
COPY . /app
WORKDIR /app
CMD sleep 25 && make clean && make config && make googletest
