LATEX = latex
DVIPDF = dvipdf
PDFTOPS = pdftops
PSNUP = psnup
PS2PDF = ps2pdf

CLEANBASE =	lecture1 lecture2 lecture3 lecture4 lecture5 \
		exercise1 exercise2 exercise3 exercise4 exercise5 debugexample

CLEANEXT = .log .aux .out .dvi .toc .nav .snm .vrb .pdf .hpdf .htx .ps

.SUFFIXES: .tex .pdf .hpdf

all:		exercises handouts lectures

exercises:	exercise1.pdf exercise2.pdf exercise3.pdf exercise4.pdf exercise5.pdf debugexample.pdf

handouts:	lecture1.hpdf lecture2.hpdf lecture3.hpdf lecture4.hpdf lecture5.hpdf

lectures:	lecture1.pdf lecture2.pdf lecture3.pdf lecture4.pdf lecture5.pdf

# Modify the 1st line of the .tex file FROM:
# \documentclass[table]{beamer}
# TO
# \documentclass[table,handout]{beamer}
# Then make it and munge it into 4 slides per page
.tex.hpdf:
		cp $< $*.handout.htx
		sed -e '1s/table/table,handout/' -i $*.handout.htx
		$(LATEX) $*.handout.htx
		$(LATEX) $*.handout.htx
		$(DVIPDF) $*.handout.dvi

		$(PDFTOPS) -paper A4 -expand $*.handout.pdf
		$(PSNUP) -4 -b2mm $*.handout.ps > $*.ps
		rm $*.handout.ps
		mv $*.ps $*.handout.ps
		$(PS2PDF) $*.handout.ps

		cp $*.handout.pdf $@

# Standard rule to texify a 
.tex.pdf:
		$(LATEX) $<
		$(LATEX) $<
		$(DVIPDF) $*.dvi

clean:
		for base in $(CLEANBASE); do \
			for ext in $(CLEANEXT); do \
				touch $$base$$ext $$base.handout$$ext ; \
				rm -f $$base$$ext $$base.handout$$ext ; \
			done ; \
		done
			
