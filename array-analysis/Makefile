MAINFILE=README

PANDOC_ARGS=--rm --volume "`pwd`:/data" --user `id -u`:`id -g`
PANDOC_ARGS_EXTRA=--variable urlcolor=blue

pdf: ${MAINFILE}.pdf
.PHONY: pdf

# main recipes

${MAINFILE}.pdf:
	docker run ${PANDOC_ARGS} pandoc/latex -o ${MAINFILE}.pdf ${MAINFILE}.md ${PANDOC_ARGS_EXTRA}

# utils

clean: clear
clear:
	rm -f ${MAINFILE}.pdf

.PHONY: clean clear
