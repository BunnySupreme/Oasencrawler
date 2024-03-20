# Oasencrawler
Implementieren Sie eine zweidimensionale Spielwelt, die von einem benutzergesteuerten
Charakter erforscht wird. Der Charakter gewinnt das Spiel, wenn er alle Relikte, die in
der Welt verteilt sind, findet und verliert, wenn er durch die Gefahren der Welt stirbt.
Folgende Punkte m¨ussen dabei beachtet werden:
• ¨Uberpr¨ufen Sie alle Parameter¨ubergaben an Funktionen und Benutzereingaben auf
Fehler und verhindern Sie so, dass Ihr Programm bei ung¨ultigen Eingaben nicht mehr
richtig funktioniert, Eingaben sollen so lange wiederholt werden, bis sie korrekt sind
und der Spielfluss erst dann fortgesetzt werden.
• Testen Sie Ihren Code ausgiebig und ber¨ucksichtigen Sie Randbedingungen.
Stufe 1
Folgende Elemente sollen als Klassen implementiert werden:
• Die Spielwelt: Verwenden Sie ein zweidimensionales Array mit den Dimensionen 5x5
um die einzelnen Spielfelder darzustellen. Je nachdem, welcher Wert gespeichert wird,
handelt es sich um ein anderes Feld. Die Spielwelt soll zu Beginn zuf¨allig generiert
werden, verwenden Sie dazu die rand()-Funktion um zuf¨allige Werte zu generieren und
damit bestimmen zu k¨onnen, welche Art von Feld erstellt wird. Es gibt verschiedene
Typen von Feldern mit ihren jeweiligen Wahrscheinlichkeiten bei der Erstellung:
– Leere Felder 4
10 : Betritt ein Charakter ein leeres Feld passiert nichts.
– Gefahren 4
10 : Betritt ein Charakter Gefahrenfelder, wird er mit einer Wahrschein-
lichkeit von 1
6 verletzt und verliert einen Lebenspunkt, hat er dann keine Leben-
spunkte mehr, verliert er das Spiel.
– Brunnen 1
10 : Der Charakter kann sich ausruhen und erh¨alt einen Lebenspunkt.
– Relikte 1
10 : Der Charakter erh¨alt einen Reliktpunkt, gibt es dann keine Relikte
mehr, gewinnt er das Spiel. Bei der Erstellung der Welt muss sichergestellt
werden, dass zumindest ein Relikt vorhanden ist.
1
Alle Felder werden zu leeren Feldern, nachdem der Charakter sie betreten hat.
• Der Charakter: Der Charakter verf¨ugt ¨uber einen Lebenspunkte- und Reliktpunktewert.
Weiters soll seine Position in der Spielwelt durch eine x- und y-Koordinate angegeben
werden. Zu Beginn hat der Charakter 5 Lebens- und 0 Reliktpunkte. Er startet bei
den Koordinaten (0|0)
Nachdem die Spielwelt erstellt wurde, soll es m¨oglich sein, den Charakter durch Benutzereingaben
zu steuern. Nach jeder Bewegung soll das Feld, auf das sich der Charakter bewegt hat, abge-
handelt werden, solange bis eine der Abbruchbedingungen f¨ur das Spiel erreicht wurde.
Stufe 2
Erweitern Sie das Spiel um einen oder mehrere Gegner, die den Charakter jagen und das Spiel
so erschweren. Das Spiel soll nun nicht mehr aufh¨oren, wenn der Charakter alle Relikte findet,
stattdessen soll die Welt mit neuen Feldern bef¨ullt und das Spiel dann fortgesetzt werden.
Immer wenn der Charakter alle Relikte gefunden hat, soll weiters der Schwierigkeitsgrad des
Spiels ansteigen, wie genau Sie das ausgestalten wollen, bleibt Ihnen ¨uberlassen.
Stufe 3
Der Charakter soll nun zus¨atzlich drei verschiedene Attribute besitzen. Die Gefahrenfelder
sollen einem dieser Attribute entsprechen. Betritt der Charakter nun ein Gefahrenfeld, muss
er mit seinem entsprechenden Attribut eine Probe bestehen, wie diese aussieht, k¨onnen Sie
selbst gestalten. Besteht er diese Probe, verliert er keinen Lebenspunkt. Zus¨atzlich soll
der Charakter bei Brunnen und Relikten Gegenst¨ande finden k¨onnen. Diese Gegenst¨ande
entsprechen ebenfalls einem der drei Attribute und haben einen Effekt, der ausgel¨ost wird,
wenn der Charakter auf ein Gefahrenfeld des entsprechenden Attributs geht, auch hier sollen
Sie den Effekt selbst gestalten. Zum Beispiel k¨onnte er einen Unsichtbarkeit strank finden,
der ihn eine fehlgeschlagene Attributsprobe ignorieren l¨asst und dann abgelegt wird.
Anforderungen
• Fehler¨uberpr¨ufung der Inputs
• Erstellung eines UML-Diagramms, welches die Klassenstruktur darstellt
• Stufe 1
– Bef¨ullung der Spielwelt (2D-Array) mit zuf¨alligen Werten (Leere Felder, Gefahren-
felder, Brunnen, Relikte)
– Implementierung des Charakters (Lebenspunkte, Reliktpunkte) inkl. Steuerung
– Visualisierung der Spielwelt und des Charakters als Konsolenausgabe
– Endlosschleife f¨ur das Spiel
• Stufe 2
2
– Implementierung von mindestens einen Gegner mit Hindernislogik
– Neugenerierung der Spielwelt nach dem Finden aller Relikte
– Erh¨ohung des Schwierigkeitsgrads nach dem Finden aller Relikte
• Stufe 3
– Implementierung von 3 Attributwerten f¨ur den Charakter
– ¨Uberpr¨ufung der Attribute bei Interaktionen mit Gefahrenfeldern
– Implementierung von mindestens 3 Gegenst¨anden (mindestens 1 je Attribut)