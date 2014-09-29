LabConnect - Interface
======================

Worum geht es?
--------------

Diese Benutzeroberfläche wurde von uns für unsere Abschlussprüfung entwickelt, um eine zentrale Software zum automatisierten und vereinfachten steuern unserer entwickelten Hardware bieten zu können. Ziel ist es das von Malte entwickelte Netzteil und den von Hendrik entwickelten DDS-Signalgenerator über den PC fernsteuerbar zu machen, um sie beispielsweise an einem automatisierten Messplatz einzusetzen.

Was sind die Ziele?
-------------------

Folgende Funktionen sollen in die Software implementiert werden:
* Allgemeine Funktionen:
 * Erkennen der angeschlossenen LabConnect-Geräte beim starten der Software
 * Indentifikations Button, um Geräte unterscheiden zu können
 * Templates für jedes Gerät mit geräteabhängigen Maximalwerten

* DDS-Signalgenerator:
 * Einstellen der Frequenz
 * Einstellen der Signalform (Sinus, Dreieck, Rechteck)
 * Sweep-Verläufe
 * Springen zwischen zwei Frequenzen
 * Ausgangssignal deaktivieren

* PWM-Netzteil:
 * Einstellen der Spannung
 * Einstellen der Strombegrenzung
 * Ausgabe der aktuellen Werte (Strom, Spannung, Leistung)
 * Spannungs- und Stromverläufe
