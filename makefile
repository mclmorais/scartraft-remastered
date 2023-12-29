CC = g++
CFLAGS = $(shell pkg-config \
	allegro-5 \
	allegro_font-5 \
	allegro_image-5 \
	allegro_primitives-5 \
	allegro_font-5 \
	allegro_ttf-5 \
	allegro_audio-5 \
	allegro_acodec-5 \
	--libs --cflags)

hello: src/main.cpp src/plotter.cpp src/bitmap-loader.cpp
	$(CC) src/main.cpp src/plotter.cpp src/bitmap-loader.cpp -o out/scartraft $(CFLAGS)
