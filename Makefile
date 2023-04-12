DEBUG_FLAG = -g
RELEASE_FLAG = -s -static -O3
BUILD_PATH = build

debug: $(BUILD_PATH)/debug/debug.exe
release: $(BUILD_PATH)/release/release.exe

$(BUILD_PATH)/debug/debug.exe: src/main.cpp include/cstatistic.h
	g++ $(DEBUG_FLAG) src/main.cpp -I include -o $(BUILD_PATH)/debug/debug.exe
$(BUILD_PATH)/release/release.exe: src/main.cpp include/cstatistic.h
	g++ $(RELEASE_FLAG) src/main.cpp -I include -o $(BUILD_PATH)/release/release.exe