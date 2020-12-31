pdf: pull compile

compile:
	docker run --rm --volume "`pwd`:/data" --user `id -u`:`id -g` pandoc/latex README.md -o README.pdf --variable urlcolor=cyan

pull:
	docker pull pandoc/latex


.PHONY: pdf compile pull

