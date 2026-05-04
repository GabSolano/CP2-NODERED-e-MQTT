CREATE TABLE dados_sensores (
    id NUMBER GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    temperatura NUMBER(5,2) NOT NULL,
    umidade NUMBER(5,2),
    luminosidade NUMBER,
    data_hora TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);