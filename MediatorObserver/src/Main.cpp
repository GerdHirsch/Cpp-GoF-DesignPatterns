#include <iostream>

#include "Button.h"
#include "Dialog.h"
#include "ListBox.h"

using namespace std;

int main()
{
	cout << "main create dialog" << endl;

	Dialog dialog;
	//ListBoxEvent lbEvent(&dialog.getListBox());
	//Direkter Zugriff auf die Methode ist nicht erlaubt, da sie private ist
	//So kann verdeutlicht werden, dass diese Methode nicht einfach von jedem aufgerufen
	//werden soll.
	//dialog.onItemSelected(lbEvent);
	//Über einen ListBoxListener* ist es jedoch möglich
	//ListBoxListener* pLBL = &dialog;
	//pLBL->onItemSelected(lbEvent);

	Button& button = dialog.getOkButton();
	cout << "main okButton.simulateButtonClicked()" << endl;
	button.simulateButtonClicked();

	button = dialog.getCancelButton();
	cout << "main cancelButton.simulateButtonClicked()" << endl;
	button.simulateButtonClicked();

	ListBox& listBox = dialog.getListBox();
	cout << "main listBox.simulateItemSelected(5)" << endl;
	listBox.simulateItemSelected(5);
}