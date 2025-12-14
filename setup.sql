CREATE TABLE IF NOT EXISTS hangman_game(
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    palavra TEXT NOT NULL UNIQUE,
    dica TEXT NOT NULL, 
    dificuldade INTEGER NOT NULL CHECK(dificuldade IN(1,2,3))
);

INSERT INTO hangman_game (palavra, dica, dificuldade) VALUES ('ABACAXI', 'FRUTA COM COROA', 1); 
INSERT INTO hangman_game (palavra, dica, dificuldade) VALUES ('TECLADO', 'PERIFÉRICO', 2);