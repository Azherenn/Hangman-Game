CREATE TABLE IF NOT EXISTS hangman_game(
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    palavra TEXT NOT NULL UNIQUE,
    dica TEXT NOT NULL, 
    dificuldade INTEGER NOT NULL CHECK(dificuldade IN(1,2,3))
);

INSERT INTO hangman_game (palavra, dica, dificuldade) VALUES ('ABACAXI', 'FRUTA COM COROA', 1); 
INSERT INTO hangman_game (palavra, dica, dificuldade) VALUES ('TECLADO', 'PERIFÉRICO', 2);
INSERT INTO hangman_game (palavra, dica, dificuldade) VALUES ('UVA', 'Fruta pequena e roxa', 1);
INSERT INTO hangman_game (palavra, dica, dificuldade) VALUES ('SOL', 'Estrela que aquece a Terra', 1);
INSERT INTO hangman_game (palavra, dica, dificuldade) VALUES ('BOLA', 'Objeto redondo usado em esportes', 1);
INSERT INTO hangman_game (palavra, dica, dificuldade) VALUES ('MALA', 'Usada para carregar roupas na viagem', 1);
INSERT INTO hangman_game (palavra, dica, dificuldade) VALUES ('PATO', 'Ave que nada e faz qua-qua', 1);
INSERT INTO hangman_game (palavra, dica, dificuldade) VALUES ('ROSA', 'Flor popular e perfumada', 1);
INSERT INTO hangman_game (palavra, dica, dificuldade) VALUES ('GATO', 'Animal de estimação que mia', 1);
INSERT INTO hangman_game (palavra, dica, dificuldade) VALUES ('CADEIRA', 'Móvel para sentar', 2);
INSERT INTO hangman_game (palavra, dica, dificuldade) VALUES ('JANELA', 'Abertura na parede para luz e ar', 2);
INSERT INTO hangman_game (palavra, dica, dificuldade) VALUES ('GUITARRA', 'Instrumento musical de cordas', 2);
INSERT INTO hangman_game (palavra, dica, dificuldade) VALUES ('FLORESTA', 'Lugar com muitas árvores', 2);
INSERT INTO hangman_game (palavra, dica, dificuldade) VALUES ('PLANETA', 'Corpo celeste como a Terra ou Marte', 2);
INSERT INTO hangman_game (palavra, dica, dificuldade) VALUES ('CASTELO', 'Residência fortificada de reis', 2);
INSERT INTO hangman_game (palavra, dica, dificuldade) VALUES ('VAMPIRO', 'Monstro lendário que bebe sangue', 2);
INSERT INTO hangman_game (palavra, dica, dificuldade) VALUES ('ASTRONAUTA', 'Viajante do espaço', 3);
INSERT INTO hangman_game (palavra, dica, dificuldade) VALUES ('HELICOPTERO', 'Aeronave com hélices no topo', 3);
INSERT INTO hangman_game (palavra, dica, dificuldade) VALUES ('ORNITORRINCO', 'Mamífero que põe ovos', 3);
INSERT INTO hangman_game (palavra, dica, dificuldade) VALUES ('ENGENHARIA', 'Área que projeta e constrói coisas', 3);
INSERT INTO hangman_game (palavra, dica, dificuldade) VALUES ('UNIVERSIDADE', 'Instituição de ensino superior', 3);
INSERT INTO hangman_game (palavra, dica, dificuldade) VALUES ('XILOFONE', 'Instrumento musical de percussão', 3);
INSERT INTO hangman_game (palavra, dica, dificuldade) VALUES ('LABIRINTO', 'Caminho confuso e difícil de sair', 3);