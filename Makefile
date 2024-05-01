CC = gcc
CFLAGS = -g -std=c2x -Wall -Wextra -Werror

SRC_DIR = src
BIN_DIR = bin
RELEASE_DIR = release

$(BIN_DIR)/rsrcer: $(SRC_DIR)/rsrcer.c
	@mkdir -p bin
	@$(CC) $(CFLAGS) -o $(BIN_DIR)/rsrcer $(SRC_DIR)/rsrcer.c

.PHONY: zip push clean

# zip the release
zip:
	@mkdir -p $(RELEASE_DIR)
	@7z a -tzip $(RELEASE_DIR)/rsrcer-$(ver).zip $(BIN_DIR)/*

#push to Github
push:
	@git add .
	@git commit -m "$(msg)"
	@git push origin main

# Publish a release
release:
	@git tag -a $(ver) -m "Release $(ver)"
	@git push origin $(ver)
	@gh release create $(ver)
	@gh release upload $(ver) $(RELEASE_DIR)/rsrcer-$(ver).zip

# remove all .exe
clear:
	@rm -r bin