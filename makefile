makemain: main.c parsecities.h adjmatrix.h
	gcc main.c parsecities.h adjmatrix.h -o a.out

clean:
	rm a.out

