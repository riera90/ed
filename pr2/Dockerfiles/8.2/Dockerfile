FROM gcc:8.2
ADD . /app
WORKDIR /app
CMD sleep 5 && make clean && make config && make googletest && make clean
