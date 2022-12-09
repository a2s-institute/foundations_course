filename=Introduction_to_Robotics

pdf:
	mkdir -p build
	pdflatex --output-directory build ${filename}
	bibtex build/${filename}||true
	pdflatex --output-directory build ${filename}
	pdflatex --output-directory build ${filename}
	mv build/${filename}.pdf .

read:
	evince build/${filename}.pdf &

clean:
	rm -f build/${filename}.{ps,pdf,log,aux,out,dvi,bbl,blg}

