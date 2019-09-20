#!/bin/bash

pdflatex article.tex
bibtex article
pdflatex article.tex
pdflatex article.tex
