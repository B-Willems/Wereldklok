# Wereldklok

## What to send to the service

### gettime

Het commando gettime wordt gebruikt om de tijd in een bepaalde stad op te vragen, dit doe je door het commando gettime>"Stad" door te sturen naar benternet.
Voorbeeld: "gettime>Berlin". 

Als je dit commando verstuurd zal de service antwoorden met de huidige tijd in de respectievelijke tijdzone op het adres "givetime>".
Voorbeeld: "givetime>time in Berlin is: 13:24:24".

Het is ook mogelijk om de Greenwich mean time op te vragen door het commando "gettime>GMT" op te vragen.

De mogelijk op de vragen steden zijn de steden weergegeven op volgende wikipedia pagina: https://en.wikipedia.org/wiki/List_of_UTC_time_offsets

### sterrebeeld

Je kan ook een datum doorsturen naar de service met het commando sterrebeeld>"dag">"maand". Als antwoord zal je het sterrebeeld van die datum als antwoord krijgen op het adres "givesterrebeeld>".
Voorbeeld: "sterrebeeld>5>1" krijgt als antwoord: "givesterrebeeld>uw sterrebeeld is steenbok".

### error message

Als u een foutief commando doorgeeft, of de service kan uw commando niet verwerken, dan zal u op het adres "givetime>" een foutmelding krijgen. Achteraan wordt dan weergegeven hoe de service jouw commando heeft aangekregen. Zo kan je de fout eruithalen en achterhalen hoe het juiste commando gestuurd moet worden.

### schematische voorstelling

![alt text](https://github.com/B-Willems/Wereldklok/blob/master/uitleg_wereldklok.png "schematische voorstelling")
