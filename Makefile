updateinfo.o:updateinfo.cpp datastructure.h
	g++ -c $<
updatestatus.o:updatestatus.cpp datastructure.h
	g++ -c $<
procurement.o:procurement.cpp updatestatus.cpp  datastructure.h
	g++ -c $<
main.o:main.cpp updateinfo.cpp updatestatus.cpp procurement.cpp
	g++ -c $<
alert.o: alert.cpp datastructure.h
	g++ -c $<
pos.o: pos.cpp datastructure.h
	g++ -c $<
deleteitem.o: deleteitem.cpp datastructure.h
	g++ -c $<
build:main.o updateinfo.o updatestatus.o procurement.o alert.o pos.o deleteitem.o
	g++ $^ -o $@
clean:
	rm main.o updateinfo.o updatestatus.o procurement.o build alert.o pos.o deleteitem.o
