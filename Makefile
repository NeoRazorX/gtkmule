OBJS = gtkmule.o main.o
CFLAGS = -g -Wall

all: $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o gtkmule `pkg-config gtkmm-2.4 --cflags --libs libglademm-2.4 libnotifymm-1.0 appindicator-0.1 unique-1.0`

main.o: main.cpp
	$(CXX) $(CFLAGS) -c main.cpp -o main.o `pkg-config gtkmm-2.4 --cflags --libs libglademm-2.4 libnotifymm-1.0 appindicator-0.1 unique-1.0`

gtkmule.o: gtkmule.h gtkmule.cpp
	$(CXX) $(CFLAGS) -c gtkmule.cpp -o gtkmule.o `pkg-config gtkmm-2.4 --cflags --libs libglademm-2.4 libnotifymm-1.0 appindicator-0.1`

clean:
	$(RM) -f *.o *~ *.bak gtkmule
