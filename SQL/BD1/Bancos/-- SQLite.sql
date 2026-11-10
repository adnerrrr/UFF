-- SQLite
-- 1 – Insira um departamento na tabela de departamentos. O departamento deve se chamar
-- Logística, ter código 6. O CPF do gerente é 66688444400 e o gerente iniciou em '2020-10-01'.

INSERT INTO Departamento (Nome, COD_DEPTO, Cpf_Gerente, Data_Inicio_Gerente)
VALUES ('Logistica', 6, '66688444400', '2020-10-01');

-- 2- Insira um departamento na tabela de departamentos. O departamento deve se chamar
-- Finanças, ter código 7. Depois, atualize esse departamento para incluir a informação do
-- gerente. O departamento deve ser gerenciado pelo empregado Franklin. Faça a atualização
-- do CPF do gerente na tabela de departamento usando uma subconsulta na tabela de
-- empregado. A data de início do gerente no departamento é '2024-11-05'.

INSERT INTO Departamento (Nome, Cod_Depto)
VALUES ('Financas', 7);
UPDATE Departamento
SET Cpf_Gerente = ( SELECT Cpf
                    FROM Empregado
                    WHERE Nome = 'Franklin'),
    Data_Inicio_Gerente = '2024-11-05'
WHERE Cod_Depto = 7;

-- 3 – Apague os dependentes do empregado chamado Franklin.

DELETE FROM Dependente
WHERE Emp_Cpf IN    (SELECT Cpf
                    FROM Empregado
                    WHERE Nome = 'Franklin');

-- 4 – Faça uma consulta que retorna o nome do empregado que mais trabalha em projetos
-- (maior número de horas).

SELECT e.nome
FROM Empregado AS e
JOIN Trabalha_em AS t ON t.Cpf = e.Cpf
GROUP BY e.Cpf, e.nome
HAVING Sum(t.horas) =   (SELECT MAX(total)
                        FROM    (SELECT SUM(horas) AS total
                                FROM Trabalha_Em AS t
                                GROUP BY Cpf));

-- 5 – Atualize a tabela de Projetos, transferindo todos os projetos do departamento 1 para o
-- departamento 6.

UPDATE Projeto
SET Cod_Proj = 6
WHERE Cod_Proj = 1;

-- 6 – Aumente o salário dos empregados do departamento de Pesquisa em 20%.

UPDATE Empregado
SET Salario = Salario * 1.2
WHERE Cod_Depto IN (SELECT Cod_Depto
                    FROM Departamento
                    WHERE Nome = "Pesquisa");

-- 7 – Aumente o salário do funcionário que ganha menos do que todos os outros. O aumento
-- deve ser de 500.

UPDATE Empregado
SET Salario = Salario + 500
WHERE Salario = (SELECT MIN(salario)
                FROM Empregado);

-- 8 – A funcionária Jennifer foi demitida. Apague a tupla correspondente do banco de dados.
-- Os funcionários que ela gerenciava devem agora ser gerenciados pelo funcionário Ramesh.

UPDATE Empregado
SET Cpf_Supervisor =    (SELECT CPF
                        FROM Empregado
                        WHERE Nome = 'Ramesh')
WHERE Cpf_Supervisor = (SELECT Cpf
                        FROM Empregado
                        WHERE Nome = 'Jennifer');
DELETE FROM Empregado
WHERE Nome = 'Jennifer';

-- 9 – Dê um aumento de salário de 1000 para o funcionário que tem o maior número de
-- dependentes.

UPDATE Empregado
SET Salario = Salario + 1000
WHERE Cpf IN    (SELECT Emp_Cpf
                FROM Dependente
                GROUP BY Emp_Cpf
                HAVING COUNT(*) =   (SELECT MAX(qtd)
                                    FROM    (SELECT COUNT(*) AS qtd
                                            FROM Dependente
                                            GROUP BY Emp_Cpf)));

-- 10 – Altere o sobrenome dos dependentes do empregado 'John' para 'Smith-Oneal'.

UPDATE Dependente
SET Sobrenome = 'Smith-Oneal'
WHERE Emp_Cpf IN    (SELECT e.Cpf
                    FROM Empregado AS e
                    WHERE e.Nome = 'John');

-- 11 – Insira uma nova localização para o departamento de Pesquisa. Primeiro, faça uma
-- consulta para descobrir qual o código do departamento de pesquisa. Depois insira a
-- localização “Stadord” para esse departamento

SELECT Cod_Depto
FROM Departamento
WHERE Nome = 'Pesquisa';
INSERT INTO Depto_Localizacoes (Cod_Depto, Local)
SELECT Cod_Depto, 'Stafford'
FROM Departamento
WHERE Nome = 'Pesquisa';