#ifndef SENSOR_H
#define SENSOR_H

typedef struct
{
    int id;
    double temperature;
    int active;
} Sensor;

/*
 * Erstellt ein dynamisches Array aus Sensoren.
 * Alle Sensoren sollen mit 0 initialisiert werden.
 */
Sensor *create_sensor_array(int count);

/*
 * Berechnet die Durchschnittstemperatur aller aktiven Sensoren.
 * Gibt 0 zurück wenn keine aktiven Sensoren existieren.
 */
double average_active_temperature(const Sensor *sensors, int count);

/*
 * Deaktiviert alle Sensoren deren Temperatur kleiner als threshold ist.
 */
void deactivate_below_threshold(Sensor *sensors, int count, double threshold);

/*
 * Gibt den Index des Sensors mit der höchsten Temperatur zurück.
 * Gibt -1 bei Fehler zurück.
 */
int find_hottest_sensor(const Sensor *sensors, int count);

#endif