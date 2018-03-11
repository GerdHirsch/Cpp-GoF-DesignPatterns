#ifndef DIALOG_H
#define DIALOG_H

#include "Button.h"
#include "ListBox.h"
#include "TextField.h"

/* Dialog fungiert als "Mediator" f�r seine Kollegen/"Kind"-Komponenten
 * ListBox, OkButton, CancelButton und TextView.
 * Dialog ist Listener f�r ListBox events und verwendet ButtonAdapter als Listener f�r die Button events.
 */
class Dialog : public ListBoxListener
{
public:
	Dialog() : 
		okButtonAdapter(this, &Dialog::onOkButtonClicked),
		cancelButtonAdapter(this, &Dialog::onCancelButtonClicked)
	{
		okButton.addButtonEventListener(&okButtonAdapter);
		cancelButton.addButtonEventListener(&cancelButtonAdapter);
		listBox.addItemSelectedListener(this);
	}

	//Nur f�r Simulationszwecke
	Button& getOkButton()
	{
		return okButton;
	}
	//Nur f�r Simulationszwecke
	Button& getCancelButton()
	{
		return cancelButton;
	}

	//Nur f�r Simulationszwecke
	ListBox& getListBox()
	{
		return listBox;
	}
private:
	void onItemSelected(ListBoxEvent listBoxEvent)
	{
		std::cout << "Dialog::onItemSelected() => ListBox.getSelectedItem()" << std::endl;
		std::string text = listBox.getSelectedItem();
		std::cout << "Dialog::onItemSelected() => TextField.setText(listBox.getSelectedItem())" << std::endl;
		textField.setText(text);
	}
protected:
	void onOkButtonClicked(ButtonEvent buttonEvent)
	{
		std::cout << "Dialog::onOkButtonClicked()" << std::endl;
	}
	
	void onCancelButtonClicked(ButtonEvent buttonEvent)
	{
		std::cout << "Dialog::onCancelButtonClicked()" << std::endl;
	}

private:
	Button okButton;
	ButtonListenerAdapter<Dialog> okButtonAdapter;

	Button cancelButton;
	ButtonListenerAdapter<Dialog> cancelButtonAdapter;

	ListBox listBox;
	TextField textField;
};


#endif //DIALOG_H