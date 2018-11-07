sample.pdf: sample.dat
	python sample.py
	rm f
	rm sample.dat
sample.dat: sample.cpp
	g++ sample.cpp -o f
	./f 2000 0 1

