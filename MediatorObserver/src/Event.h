#ifndef EVENT_H
#define EVENT_H

/*
 * Basisklasse f�r die Event-Klassen.
 * Enth�lt den Sender (Den Versender des Events).
 */
template<class SENDER>
class Event
{
public:
	Event(SENDER* sender) : sender(sender)
	{

	}

	SENDER* getSender()
	{
		return sender;
	}

private:
	SENDER* sender;
};

#endif //EVENT_H