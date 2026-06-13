CC     = gcc
CFLAGS = -Wall -g
LDFLAGS = -lm

all:
	$(CC) $(CFLAGS) sim/simulator.c -o simulator $(LDFLAGS)
	$(CC) $(CFLAGS) fw/main.c fw/parser.c fw/sensors.c fw/outputs.c fw/scheduler.c -o firmware $(LDFLAGS)

test:
	$(CC) $(CFLAGS) test/test_parser.c fw/parser.c -o test_parser $(LDFLAGS)
	./test_parser

clean:
	rm -f simulator firmware test_parser