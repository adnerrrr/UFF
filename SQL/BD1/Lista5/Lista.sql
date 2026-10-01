-- SQLite
--1 - Faça uma consulta que mostre o número de vôos por rota, mesmo que tal rota não
--possua vôos. A saída de seu comando SQL deverá possuir duas colunas, sendo a primeira
--correspondente ao atributo RouteID da tabela route, e a outra correspondente ao número
--de vôos das rotas (o nome dessa coluna deve ser Quant).

SELECT r.RouteID, COUNT(FlightID) AS Quant
FROM route r LEFT JOIN flight f
ON r.RouteID = f.RouteID
GROUP BY r.RouteID;

--2 - Faça uma consulta SQL que mostra os tipos de aeronaves (tabela aircrafttype) que não
--possuem aeronaves registradas no banco (tabela aircratf). Sua consulta deverá retornar
--duas colunas, sendo a primeira correspondente ao atributo AircraftID da
--tabela aircraft (com valores nulos) e a segunda correspondente ao
--atributo AircraftName da tabela aircrafttype.

SELECT a.AircraftID, at.AircraftName
FROM aircrafttype at LEFT JOIN aircraft a
ON (a.AircraftTypeID = at.AircraftTypeID)
WHERE a.AircraftID IS NULL

--3 - Use a cláusula COUNT() para calcular quantos aviões de cada tipo a compania possui.
--Sua consulta deverá possuir duas colunas, sendo a primeira correspondente ao
--atributo AircraftName, e a segunda contendo o número de aeronaves de cada tipo. Se a
--compania não possuir aeronave de um determinado tipo, deverá ser mostrado o valor 0 para
--esse tipo.

SELECT at.AircraftName, COUNT(AircraftID)
FROM aircrafttype at LEFT JOIN aircraft a
ON at.AircraftTypeID = a.AircraftTypeID
GROUP BY at.AircraftName

--4 - Faça uma consulta que retorna o AirportCode dos aeroportos e a quantidade de rotas
--que usam esse aeroporto como ponto de partida (coluna Origin da tabela route), mas
--apenas para os aeroportos que são origem de mais de 2 rotas.

SELECT a.AirportCode, COUNT(RouteID)
FROM airport a JOIN route r
ON a.AirportID = r.Origin
GROUP BY AirportCode
HAVING COUNT(RouteID) > 2

--5 - Faça uma consulta que retorna o ID da rota, os códigos dos aeroportos de origem e
--destino de cada rota, o id do vôo e horários de partida dos vôos. As seguintes colunas devem
--aparecer no resultado (nessa ordem): RouteID, FromAirport, ToAirport, FlightID, DepTime,
--DepDay.

SELECT r.RouteID, a1.AirportCode AS FromAirport, a2.AirportCode AS ToAirport, f.FlightID, fd.DepTime, fd.DepDay
FROM route r JOIN airport a1 ON r.Origin = a1.AirportID
             JOIN airport a2 ON r.Destination = a2.AirportID
             JOIN flight f ON f.RouteID = r.RouteID
             JOIN flightdep fd ON f.FlightID = fd.FlightID
        
--6 - Faça uma consulta que seleciona o flightID de voos que não operam no domingo (DepDay
--= 1 na tabela flightdep). O retorno deve estar ordenado por FlightID.
SELECT FlightID FROM flight
EXCEPT
SELECT FlightID FROM flightdep WHERE DepDay = 1
ORDER BY FlightID;

--7 - Faça uma consulta que seleciona o nome do aeroporto de origem (numa coluna
--chamada FromAirport), o nome do aeroporto de destino (numa coluna chamada ToAirport)
--e o nome da classe do vôo que tem preço base mais barato (BasePrice da tabela
--flightclass).
SELECT a1.AirportName AS FromAirport, a2.AirportName AS ToAirport, c.ClassName
FROM route r JOIN airport a1 ON r.Origin = a1.AirportID
             JOIN airport a2 ON r.Destination = a2.AirportID
             JOIN flight f ON r.RouteID = f.RouteID
             JOIN flightclass fc ON f.FlightID = fc.FlightID
             JOIN class c ON fc.ClassID = c.ClassID
WHERE fc.BasePrice = (SELECT MIN(BasePrice) FROM flightclass);

--8 - Faça uma consulta que seleciona o nome do aeroporto de origem (numa coluna
--chamada FromAirport), o nome do aeroporto de destino (numa coluna chamada ToAirport),
--a data de partida (FlightDate) e o nome da classe do vôo que tem preço atual mais caro
--(CurrPrice da tabela stats).
SELECT a1.AirportName AS FromAirport, a2.AirportName AS ToAirport, s.FlightDate, c.ClassName
FROM route r JOIN airport a1 ON r.Origin = a1.AirportID
             JOIN airport a2 ON r.Destination = a2.AirportID
             JOIN flight f ON r.RouteID = f.RouteID
             JOIN stats s ON s.FlightID = f.FlightID
             JOIN class c ON s.ClassID = c.ClassID
WHERE s.CurrPrice = (SELECT MAX(CurrPrice) FROM stats)

--PARTE DOIS (com db de movies)

--9 - Faça uma consulta que retorna o nome do gênero e a quantidade de filmes de cada
--gênero. A coluna de quantidade deve se chamar "quant".
SELECT g.name, COUNT(mg.movie_id) AS quant
FROM genres g JOIN movies_genres mg ON g.genre_id = mg.genre_id
GROUP BY g.name;

--10 - Faça uma consulta que retorna o nome e o ano de lançamento do filme mais antigo
--(menor ano de lançamento).
SELECT m.name, m.year
FROM movies m
WHERE m.year = (SELECT MIN(year) FROM movies);

--11 - Faça uma consulta que retorna o primeiro nome e sobrenome do diretor do filme que
--possui o maior rank.
SELECT d.first_name, d.last_name
FROM directors d JOIN movies_directors md ON d.director_id = md.director_id
                 JOIN movies m ON md.movie_id = m.movie_id
WHERE m.rank = (SELECT MAX(rank)
                FROM movies)

-- 12 - Faça uma consulta que retorna os nomes dos atores (primeiro nome e sobrenome) e a
-- quantidade de papéis que eles desempenharam nos filmes, mas apenas para os que
-- possuem mais de 2 papéis. A quantidade de papéis deve ser retornada numa coluna
-- chamada quant.
SELECT a.first_name, a.last_name, COUNT(r.role) AS quant
FROM actors a JOIN roles r ON a.actor_id = r.actor_id
GROUP BY a.first_name, a.last_name
HAVING COUNT(r.role) > 2;

-- 13 - Faça uma consulta que retorna os títulos dos filmes para os quais não há nenhum papel
-- registrado na tabela roles.
SELECT name FROM movies
EXCEPT
SELECT m.name 
FROM movies m JOIN roles r ON m.movie_id = r.movie_id;

-- 14 - Faça uma consulta que retorna a média do rank dos filmes, por ano de lançamento. A
-- consulta deve retornar o ano e a média do rank dos filmes daquele ano (renomeie essa
-- coluna para media). O resultado deve estar ordenado de forma decrescente pela média.
SELECT m.year, AVG(m.rank) AS media
FROM movies m
GROUP BY m.year
ORDER BY AVG(m.rank) DESC

--15 - Faça uma consulta que retorna a soma do rank dos filmes lançados em 1994. A coluna
--com a soma deve se chamar soma.
SELECT SUM(m.rank) AS soma
FROM movies m
WHERE m.year = 1994

--16 - Faça uma consulta que retorna o nome do diretor (primeiro nome e sobrenome) e o
--nome do gênero que esse diretor tem mais probabilidade (coluna prob da tabela
--directors_genres) de atuar. A consulta deve retornar o nome do diretor, o nome do gênero e
--a probabilidade.
SELECT d.first_name, d.last_name, g.name, dg.prob
FROM directors d 
JOIN directors_genres dg ON d.director_id = dg.director_id
JOIN genres g ON dg.genre_id = g.genre_id
WHERE dg.prob = (
    SELECT MAX(prob) 
    FROM directors_genres dg2 
    WHERE dg2.director_id = d.director_id
);

-- 17 - Faça uma consulta que retorna a quantidade de atores de cada gênero. A consulta deve
-- retornar o gênero e a respectiva quantidade numa coluna chamada quant.
SELECT a.gender, COUNT(*) AS quant
FROM actors a
GROUP BY a.gender

-- 18 - Faça uma consulta que retorna o primeiro nome mais popular entre os atores (ou seja,
-- o que aparece mais vezes nessa tabela).
SELECT a.first_name
FROM actors a
GROUP BY a.first_name
ORDER BY COUNT(*) DESC
LIMIT 1