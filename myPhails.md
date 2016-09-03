2016-08-31:
DEADLINE 4 SEP.
Stack.cpp

hint: Här ska det endast finnas en pekar-variabel, top. Variabeln ptr deklareras i den/de funktioner där denna behövs. Annars ok. top ska peka på den senast inlagda (som ju är på toppen i en stack(det sist inlagda elementet)). Top ska peka på den som är "först", dvs den som lagts till senast och som har adressen till den de är på "andra plats" .. 
lösning: *top[2] där [0] ger top, [1] ger näst top.

CircularDoubleDirectedList.h

kan det vara så att exterminate->next är nullptr om det är en cirkulär lista???? Du har följande i remove-funktionen - if(exterminate->next != nullptr)

motsvarande gällande exterminate->prev...
Q: Så vad du menar är att en cirkulär lista förekommer ingen nullptr pga cirkulärt beteende därvid är if-satserna som frågar om    skiljt från nullptr onödiga i remove?
A: Ja, det finns inga noder som har nullptr på sina pekare.

om storleken på listan är 2 så utförs if( this->operator==(item)) vilket innebär att listan jämförs med item?? samma kontroll görs om storleken är 1

Q:  I operatorn är det tänkt att man här ska jämföra två player objekt(player klassen har en == operator)?
A:  Du måste nå player objektet i noden, this blir hela listan.

Du får kontrollera din kod och rätta till så att den blir korrekt. Lämna därefter in den igen. Dock senast 2016-09-04 kl. 23.59.
