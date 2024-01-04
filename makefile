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

hello: 
	$(CC) \
	src/main.cpp \
	src/plotter.cpp \
	src/bitmap-loader.cpp \
	src/towers/engines/tower-engine.cpp \
	src/towers/entities/tower-loader.cpp \
	src/towers/entities/tower.cpp \
	src/towers/entities/tower-plotter.cpp \
	src/creeps/creep-engine.cpp \
	src/creeps/creep-loader.cpp \
	src/creeps/creep.cpp \
	src/creeps/creep-plotter.cpp \
	src/player/player-engine.cpp \
	-o out/scartraft \
	$(CFLAGS)
