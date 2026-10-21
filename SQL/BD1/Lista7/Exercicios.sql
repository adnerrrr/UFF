-- SQLite

-- 1. Inserir um voo 904, com RouteID 1003 e AircraftID 3223.

INSERT INTO Flight VALUES (904, 1003, 3223);

-- 2. Inserir um AircraftType 787 com name 'Boeing 787-9'

INSERT INTO Aircrafttype VALUES (787, "Boeing 787-9");

-- 3. Atualizar CurrSeats (somando 2) da tabela stats para o vôo 652, de '2009-01-20', classe 3.

UPDATE Stats
SET CurrSeats = CurrSeats + 2
WHERE FlightID = 652
AND FlightDate = "2009-01-20"
AND ClassID = 3;

-- 4. Atualizar CurrSeats (somando 5) e CurrPrice (aumentando em 20%) da tabela
-- stats para o vôo 652, de '2009-01-20', classe 2.

UPDATE Stats
SET CurrSeats = CurrSeats + 5, CurrPrice = CurrPrice * 1.2
WHERE FlightID = 652
AND FlightDate = "2009-01-20"
AND ClassID = 2;

-- 5. Alterar o ID do vôo 535, passando para 915 (essa operação deve acusar erro
-- devido às restrições de integridade).

UPDATE Flight SET FlightID = 915
WHERE FlightID = 535;

-- 6. Alterar para 0 o RouteStatus de todas as rotas que partem do aeroporto ORY
-- (AirportCode).

UPDATE Route SET RouteStatus = 0
WHERE Origin = (SELECT AirportID
                FROM Airport
                WHERE AirportCode = 'ORY');

-- 7. Excluir todos os passageiros (tabela pax) do vôo 652.

DELETE FROM pax
WHERE FlightID = 652;

-- 8. Excluir as informações da tabela stats para o vôo 876 do dia '2009-04-01'.

DELETE FROM stats
WHERE FlightID = 876
AND FlightDate = "2009-04-01";