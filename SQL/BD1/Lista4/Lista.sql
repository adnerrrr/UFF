-- SQLite
--1
SELECT r.RouteId, r.Origin AS ORIGIN, r.Destination AS DESTINATION
FROM route r JOIN airport a1 
ON r.Origin = a1.AirportID
WHERE a1.AirportCode LIKE 'LHR' OR a1.AirportCode LIKE 'AMS';

--2
SELECT r.RouteId, r.Origin AS ORIGIN, r.Destination AS DESTINATION
FROM route r JOIN airport a1 
ON r.Origin = a1.AirportID
WHERE a1.AirportCode LIKE 'LHR'
UNION
SELECT r.RouteId, r.Origin AS ORIGIN, r.Destination AS DESTINATION
FROM route r JOIN airport a1 
ON r.Origin = a1.AirportID
WHERE a1.AirportCode LIKE 'AMS';

--3
SELECT r.RouteID, a1.AirportCode AS Origem, a2.AirportCode AS Destino
FROM route r JOIN airport a1 ON r.Origin = a1.AirportID
             JOIN airport a2 ON r.Destination = a2.AirportID
ORDER BY Origem, Destino

--4
SELECT f.FlightID, f.RouteID, f.AircraftID, fd.DepDay, fd.DepTime
FROM flight f JOIN flightdep fd
ON f.FlightID = fd.FlightID
ORDER BY f.FlightID

--5
SELECT f.FlightID, fc.ClassID
FROM flight f LEFT JOIN flightclass fc
ON f.FlightID = fc.FlightID

--6
SELECT DISTINCT f.*
FROM flight f JOIN pax p
ON f.FlightID = p.FlightID

--7
SELECT f.FlightID, p.PaxName
FROM flight f LEFT JOIN pax p
ON f.FlightID = p.FlightID
ORDER BY f.FlightID, p.PaxName

--8
SELECT f.FlightID
FROM flight f
EXCEPT
SELECT p.FlightID
FROM pax p

--9
SELECT f.FlightID, a1.AirportCode AS Origem, a2.AirportCode AS Destino
FROM flight f JOIN route r ON f.RouteID = r.RouteID 
              JOIN airport a1 ON r.Origin = a1.AirportID
              JOIN airport a2 ON r.Destination = a2.AirportID
EXCEPT
SELECT f.FlightID, a1.AirportCode AS Origem, a2.AirportCode AS Destino
FROM flight f JOIN route r ON f.RouteID = r.RouteID 
              JOIN airport a1 ON r.Origin = a1.AirportID
              JOIN airport a2 ON r.Destination = a2.AirportID
              JOIN pax p ON f.FlightID = p.FlightID