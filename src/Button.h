#ifndef BUTTON_H
#define BUTTON_H

#include "Event.h"
#include "ObserverManager.h"

class Button;

class ButtonEvent : public Event<Button>
{
public:
	ButtonEvent(Button* button) : Event(button)
	{
	}

};

class ButtonListener
{
public:
	virtual void onClick(ButtonEvent buttonEvent) = 0;
	virtual void onMouseDown(ButtonEvent buttonEvent) = 0;
	virtual void onMouseUp(ButtonEvent buttonEvent) = 0;
};

template<class OBSERVER>
class ButtonListenerAdapter : public ButtonListener
{
public:
	typedef void (OBSERVER::*EventHandler)(ButtonEvent buttonEvent);

	ButtonListenerAdapter(OBSERVER* observer, 
							EventHandler onClick, 
							EventHandler onMouseDown = 0, 
							EventHandler onMouseUp = 0)
		: 
		observer(observer), 
		_onClick(onClick), 
		_onMouseDown(onMouseDown), 
		_onMouseUp(onMouseUp) {}

	virtual void onClick(ButtonEvent buttonEvent)
	{
		if(_onClick != 0)
			(observer->*_onClick)(buttonEvent);
	}
	
	virtual void onMouseDown(ButtonEvent buttonEvent)
	{
		if(_onMouseDown != 0)
			(observer->*_onMouseDown)(buttonEvent);
	}
	
	virtual void onMouseUp(ButtonEvent buttonEvent)
	{
		if(_onMouseUp != 0)
			(observer->*_onMouseUp)(buttonEvent);	
	}

private:
	OBSERVER* observer;
	EventHandler _onClick;
	EventHandler _onMouseDown;
	EventHandler _onMouseUp;
};

class Button
{
public:

	void addButtonEventListener(ButtonListener* listener)
	{
		manager.add(listener);
	}

	void removeButtonEventListener(ButtonListener* listener)
	{
		manager.remove(listener);
	}

	void simulateButtonClicked()
	{
		ButtonEvent buttonEvent(this);
		manager.notify(&ButtonListener::onClick, buttonEvent);
	}
private:
	ObserverManager<ButtonListener, ButtonEvent> manager;
};

#endif //BUTTON_H