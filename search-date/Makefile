MAINFILE = exercise
SRC = $(shell pwd)
BUILD_DIR = _build


# ***********************************************************
# ****** MAIN

.PHONY: all
all:  # all do nothing by default

pdf: pdf3  # default
pdf1: pdflatex bib pdflatex
pdf2: pdfdocker
pdf3: blang-latex-docker

prettify: backup tabs2spaces rmTrailingSpaces

# ***********************************************************
# ****** BUILD RECIPES

# build using blang docker config
blang-latex-docker: latexdockercmd.sh
	./latexdockercmd.sh pdflatex ${MAINFILE}.tex

latexdockercmd.sh:
	wget https://raw.githubusercontent.com/blang/latex-docker/master/latexdockercmd.sh
	chmod +x latexdockercmd.sh

# build using docker
pdfdocker:
	docker pull dxjoke/tectonic-docker
	docker run --mount src=$(SRC),target=/usr/src/tex,type=bind dxjoke/tectonic-docker /bin/sh -c "tectonic --keep-intermediates --reruns 0 $MAINFILE.tex; biber $MAINFILE; tectonic $MAINFILE.tex"

# build using pdflatex
pdflatex: 
	pdflatex $(MAINFILE)
bib:
	biber $(MAINFILE)

# read
read:
	evince $(MAINFILE).pdf &

# edit
edit:
	emacs ${MAINFILE}.tex

# backup
backup:
	cp ${MAINFILE}.tex ${MAINFILE}.tex.bak
restore:
	cp ${MAINFILE}.tex.bak ${MAINFILE}.tex

# convert a tab to 4 spaces 
tabs2spaces:
	expand -t 4 ${MAINFILE}.tex > ${MAINFILE}.tex.tmp
	mv ${MAINFILE}.tex.tmp ${MAINFILE}.tex

# remove trailing spaces
rmTrailingSpaces:
# do nothing for now
# FIXME: the $ si interpreted in bash end cause the sed command to fail!
# sed --in-place "s/[[:space:]]\+$//" ${MAINFILE}.tex

# ***********************************************************
# ****** CLEAN RECIPES
.PHONY: clean
clean:
	-rm -f *.aux
	-rm -f *.log
	-rm -f *.toc
	-rm -f *.bbl
	-rm -f *.blg
	-rm -f *.out
	-rm -f make/bib

.PHONY: cleanall
cleanall: clean
	-rm -f *.pdf
	-rm -f *.ps
	-rm -f *.dvi
	-rm -rf ./make
	-rm -f *.mtc*
	-rm -f *.maf
	-rm -f *.listing
	-rm -f *.loa
	-rm -f *.lof
	-rm -f *.lot
	-rm -f *.bcf
	-rm -f *.fls
	-rm -f *.pyg
	-rm -f *.run.xml
	-rm -rf $(BUILD_DIR)
