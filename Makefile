updateinfo.o:updateinfo.cpp datastructure.h
	g++ -c $<
updatestatus.o:updatestatus.cpp datastructure.h
	g++ -c $<
procurement.o:procurement.cpp updatestatus.cpp  datastructure.h
	g++ -c $<
main.o:main.cpp updateinfo.cpp updatestatus.cpp procurement.cpp
	g++ -c $<
build:main.o updateinfo.o updatestatus.o procurement.o
	g++ $^ -o $@
clean:
	rm main.o updateinfo.o updatestatus.o procurement.o build
