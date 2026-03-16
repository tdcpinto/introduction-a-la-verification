TO_CLEAN=.pdf .aux .toc .nav .snm .log .out _minted-* build_py_tex build .bbl .blg

all: compile_no_solutions compile_with_solutions
xall: compile_no_solutions compile_with_solutions

compile_with_solutions:
	pdflatex -jobname=main_with_solutions -shell-escape "\def\WITHSOLUTIONS{1}\input{main.tex}" && \
	pdflatex -jobname=main_with_solutions -shell-escape "\def\WITHSOLUTIONS{1}\input{main.tex}" && \
	pdflatex -jobname=main_with_solutions -shell-escape "\def\WITHSOLUTIONS{1}\input{main.tex}"

compile_no_solutions:
	pdflatex -jobname=main_no_solutions -shell-escape main.tex && \
	pdflatex -jobname=main_no_solutions -shell-escape main.tex && \
	pdflatex -jobname=main_no_solutions -shell-escape main.tex

openpdf:
	$(info OK)

clean:
	@for pattern in ${TO_CLEAN}; do \
		files=`find . -regex .*\$${pattern}`; \
		rm -rf $${files}; \
	done