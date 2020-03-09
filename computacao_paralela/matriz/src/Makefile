CC=gcc
OUTDIR=../

matriz-ijk: matriz-ijk.c
	$(CC) -o $(OUTDIR)matriz-ijk matriz-ijk.c

matriz-ijk-O3: matriz-ijk.c
	$(CC) -O3 -o $(OUTDIR)matriz-ijk-O3 matriz-ijk.c

matriz-ikj: matriz-ikj.c
	$(CC) -o $(OUTDIR)matriz-ikj matriz-ikj.c

matriz-ikj-O3: matriz-ikj.c
	$(CC) -O3 -o $(OUTDIR)matriz-ikj-O3 matriz-ikj.c

.PHONY : all
all: matriz-ijk matriz-ijk-O3 matriz-ikj matriz-ikj-O3

.PHONY: clean
clean:
	rm $(OUTDIR)/matriz-ikj-O3 $(OUTDIR)/matriz-ikj $(OUTDIR)/matriz-ijk-O3 $(OUTDIR)/matriz-ijk
