FROM gcc:5.3
COPY . /app
WORKDIR /app
CMD make clean && make config && make ./output/bin.out
