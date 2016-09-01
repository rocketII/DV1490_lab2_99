2016-08-31:

Stack.cpp

Här ska det endast finnas en pekar-variabel, top. Variabeln ptr deklareras i den/de funktioner där denna behövs. Annars ok.

CircularDoubleDirectedList.h

kan det vara så att exterminate->next är nullptr om det är en cirkulär lista???? Du har följande i remove-funktionen - if(exterminate->next != nullptr)

motsvarande gällande exterminate->prev...

om storleken på listan är 2 så utförs if( this->operator==(item)) vilket innebär att listan jämförs med item?? samma kontroll görs om storleken är 1

Du får kontrollera din kod och rätta till så att den blir korrekt. Lämna därefter in den igen. Dock senast 2016-09-04 kl. 23.59.
