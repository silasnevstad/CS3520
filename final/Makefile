CC = g++ -std=c++17
CFLAGS = -Wall -Wextra -pedantic
OBJS = main.o Court.o Reservation.o Schedule.o PickleballReservationSystem.o User.o ClubMember.o ClubCoach.o ClubOfficer.o time_utils.o DataPersistence.o

all: pickleball_reservation_system

pickleball_reservation_system: $(OBJS)
	$(CC) $(CFLAGS) -o pickleball_reservation_system $(OBJS)

main.o: main.cpp PickleballReservationSystem.h
	$(CC) $(CFLAGS) -c main.cpp

Court.o: Court.cpp Court.h Reservation.h
	$(CC) $(CFLAGS) -c Court.cpp

Reservation.o: Reservation.cpp Reservation.h time_utils.h
	$(CC) $(CFLAGS) -c Reservation.cpp

Schedule.o: Schedule.cpp Schedule.h Court.h Reservation.h
	$(CC) $(CFLAGS) -c Schedule.cpp

PickleballReservationSystem.o: PickleballReservationSystem.cpp PickleballReservationSystem.h Court.h Reservation.h Schedule.h User.h ClubMember.h ClubCoach.h ClubOfficer.h time_utils.h DataPersistence.h
	$(CC) $(CFLAGS) -c PickleballReservationSystem.cpp

User.o: User.cpp User.h
	$(CC) $(CFLAGS) -c User.cpp

ClubMember.o: ClubMember.cpp ClubMember.h User.h
	$(CC) $(CFLAGS) -c ClubMember.cpp

ClubCoach.o: ClubCoach.cpp ClubCoach.h User.h
	$(CC) $(CFLAGS) -c ClubCoach.cpp

ClubOfficer.o: ClubOfficer.cpp ClubOfficer.h User.h
	$(CC) $(CFLAGS) -c ClubOfficer.cpp

time_utils.o: time_utils.cpp time_utils.h
	$(CC) $(CFLAGS) -c time_utils.cpp

DataPersistence.o: DataPersistence.cpp DataPersistence.h User.h Schedule.h
	$(CC) $(CFLAGS) -c DataPersistence.cpp

clean:
	rm -f *.o pickleball_reservation_system
