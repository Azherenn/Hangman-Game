import sqlite3
import pandas as pd 

conexao = sqlite3.connect('dados.db')
df = pd.read_sql("SELECT * FROM hangman_game", conexao)
df.to_csv("database.txt", sep=';', index=False, header=False)
conexao.close()

