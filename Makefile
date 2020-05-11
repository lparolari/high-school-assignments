DIST_DIR=".dist"

build:
	python build.py

clean:
	rm -r ${DIST_DIR}

.PHONY: clear