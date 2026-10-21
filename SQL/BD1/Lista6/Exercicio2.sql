-- SQLite

-- 1. Adicionar restrição na tabela Produto, para que Peso tenha que ser > 0

PRAGMA foreign_keys = OFF;
BEGIN;
CREATE TABLE produto_novo (
    CodProd integer NOT NULL PRIMARY KEY,
    DescrProd VARCHAR(100) NOT NULL,
    Peso float NOT NULL
    CONSTRAINT ck_peso_positivo CHECK (Peso > 0)
);
INSERT INTO produto_novo
SELECT CodProd, DescrProd, Peso
FROM produto;
DROP TABLE produto;
ALTER TABLE produto_novo RENAME TO produto;
PRAGMA foreign_key_check;
COMMIT;
PRAGMA foreign_keys = ON;

-- 2. Adicionar restrição na tabela MaqProd, para que tempo tenha que ser > 0

PRAGMA foreign_keys = OFF;
BEGIN;
CREATE TABLE maquina_produto_nova(
    CodMaq integer NOT NULL,
    CodProd integer NOT NULL,
    Tempo float NOT NULL CHECK (Tempo > 0),
    PRIMARY KEY (CodMaq, CodProd),
    FOREIGN KEY (CodMaq) REFERENCES maquina(CodMaq),
    FOREIGN KEY (CodProd) REFERENCES produto(CodProd)
);
INSERT INTO maquina_produto_nova
SELECT CodMaq, CodProd, Tempo
FROM MaqProd;
DROP TABLE MaqProd;
ALTER TABLE maquina_produto_nova RENAME TO MaqProd;
COMMIT;
PRAGMA foreign_keys = ON;

-- 3. Excluir a restrição adicionada no exercício 1.

PRAGMA foreign_keys = OFF;
BEGIN;
CREATE TABLE produto_novo (
    CodProd integer NOT NULL PRIMARY KEY,
    DescrProd VARCHAR(100) NOT NULL,
    Peso float NOT NULL
);
INSERT INTO produto_novo
SELECT CodProd, DescrProd, Peso
FROM produto;
DROP TABLE produto;
ALTER TABLE produto_novo RENAME TO produto;
COMMIT;
PRAGMA foreign_keys = ON;

-- 4. Alterar a tabela Produto para adicionar uma coluna PRECO do tipo FLOAT.

ALTER TABLE produto ADD COLUMN Preco float;

-- 5. Excluir a coluna quant da tabela ComposProd.

ALTER TABLE ComposProd DROP COLUMN Quant;

-- 6. Excluir a tabela ComposProd.

DROP TABLE ComposProd;

-- 7. Mudar o tipo da coluna nomeMaq da tabela Maquina para VARCHAR(50).

PRAGMA FOREIGN_KEYS = OFF;
BEGIN;
CREATE TABLE maquina_nova (
    CodMaq integer NOT NULL,
    NomeMaq varchar(50) NOT NULL,
    PRIMARY KEY (CodMaq)
);
INSERT INTO maquina_nova
SELECT CodMaq, NomeMaq FROM maquina;
DROP TABLE maquina;
ALTER TABLE maquina_nova RENAME TO maquina;
COMMIT;
PRAGMA FOREIGN_KEYS = ON;