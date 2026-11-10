from os import name, system

def limpa(): # funcao para limpar o terminal
    if name == 'nt':
        system('cls')
    else:
        system('clear')


def calcular_pontuacao(a, b, match, mismatch):
    """Retorna a pontuação de match se as bases forem iguais, ou mismatch se forem diferentes."""
    if a == b:
        return match
    return mismatch


def print_alinhamento(seq_s, match_line, seq_t, score, tipo="Alinhamento"):
    print(f"\n--- {tipo} ---")
    print(f"Score (Similaridade): {score}")
    tamanho_linha = 80
    for i in range(0, len(seq_s), tamanho_linha):
        print(f"s: {seq_s[i:i+tamanho_linha]}")
        print(f"   {match_line[i:i+tamanho_linha]}")
        print(f"t: {seq_t[i:i+tamanho_linha]}\n")


def alinhamento_global(s, t, match, mismatch, gap):

    m, n = len(s), len(t)
    
    # Inicialização da Matriz com listas de listas
    H = [[0] * (n + 1) for _ in range(m + 1)]
    
    # Penalidades de gap iniciais
    for i in range(1, m + 1):
        H[i][0] = i * gap
    for j in range(1, n + 1):
        H[0][j] = j * gap
        
    # Preenchimento da Matriz
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            diagonal = H[i-1][j-1] + calcular_pontuacao(s[i-1], t[j-1], match, mismatch)
            cima = H[i-1][j] + gap
            esquerda = H[i][j-1] + gap
            H[i][j] = max(diagonal, cima, esquerda)
            
    # O score final do alinhamento global está no canto inferior direito
    score = H[m][n]
    
    # 3. Traceback
    align_s, align_t, match_line = "", "", ""
    i, j = m, n
    
    while i > 0 or j > 0:
        if i > 0 and j > 0 and H[i][j] == H[i-1][j-1] + calcular_pontuacao(s[i-1], t[j-1], match, mismatch):
            align_s = s[i-1] + align_s
            align_t = t[j-1] + align_t
            match_line = ("|" if s[i-1] == t[j-1] else ".") + match_line
            i -= 1
            j -= 1
        elif i > 0 and H[i][j] == H[i-1][j] + gap:
            align_s = s[i-1] + align_s
            align_t = "-" + align_t
            match_line = " " + match_line
            i -= 1
        else:
            align_s = "-" + align_s
            align_t = t[j-1] + align_t
            match_line = " " + match_line
            j -= 1
            
    return align_s, align_t, match_line, score


def alinhamento_semiglobal(s, t, match, mismatch, gap):
    
    m, n = len(s), len(t)
    H = [[0] * (n + 1) for _ in range(m + 1)]
    
    # 1. Preenchimento da Matriz (linha 0 e coluna 0 ficam com 0)
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            diagonal = H[i-1][j-1] + calcular_pontuacao(s[i-1], t[j-1], match, mismatch)
            cima = H[i-1][j] + gap
            esquerda = H[i][j-1] + gap
            H[i][j] = max(diagonal, cima, esquerda)
            
    # 2. Identificação do Ponto de Partida
    max_score = float('-inf')
    start_i, start_j = m, n
    
    for i in range(m + 1):
        if H[i][n] > max_score:
            max_score, start_i, start_j = H[i][n], i, n
    for j in range(n + 1):
        if H[m][j] > max_score:
            max_score, start_i, start_j = H[m][j], m, j

    score = max_score
    align_s, align_t, match_line = "", "", ""
    i, j = start_i, start_j
    
    while i < m:
        align_s += s[i]
        align_t += "-"
        match_line += " "
        i += 1
    while j < n:
        align_s += "-"
        align_t += t[j]
        match_line += " "
        j += 1
        
    i, j = start_i, start_j
    
    # 3. Traceback
    while i > 0 and j > 0:
        if H[i][j] == H[i-1][j-1] + calcular_pontuacao(s[i-1], t[j-1], match, mismatch):
            align_s = s[i-1] + align_s
            align_t = t[j-1] + align_t
            match_line = ("|" if s[i-1] == t[j-1] else ".") + match_line
            i -= 1
            j -= 1
        elif H[i][j] == H[i-1][j] + gap:
            align_s = s[i-1] + align_s
            align_t = "-" + align_t
            match_line = " " + match_line
            i -= 1
        else:
            align_s = "-" + align_s
            align_t = t[j-1] + align_t
            match_line = " " + match_line
            j -= 1
            
    while i > 0:
        align_s = s[i-1] + align_s
        align_t = "-" + align_t
        match_line = " " + match_line
        i -= 1
    while j > 0:
        align_s = "-" + align_s
        align_t = t[j-1] + align_t
        match_line = " " + match_line
        j -= 1

    return align_s, align_t, match_line, score


def alinhamento_local(s, t, match, mismatch, gap, num_trechos=3):
    
    m, n = len(s), len(t)
    H = [[0] * (n + 1) for _ in range(m + 1)]
    
    # 1. Preenchimento da Matriz
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            diagonal = H[i-1][j-1] + calcular_pontuacao(s[i-1], t[j-1], match, mismatch)
            cima = H[i-1][j] + gap
            esquerda = H[i][j-1] + gap
            H[i][j] = max(0, diagonal, cima, esquerda)
            
    trechos_encontrados = []
    
    # 2. Busca iterativa pelos N melhores trechos
    for _ in range(num_trechos):
        # Encontra o maior valor
        max_score = 0
        max_i, max_j = 0, 0
        for i in range(m + 1):
            for j in range(n + 1):
                if H[i][j] > max_score:
                    max_score = H[i][j]
                    max_i, max_j = i, j
        
        if max_score == 0:
            break
            
        i, j = max_i, max_j
        align_s, align_t, match_line = "", "", ""
        
        # 3. Traceback
        while i > 0 and j > 0 and H[i][j] > 0:
            current_val = H[i][j]
            H[i][j] = 0 # Zera a célula para permitir achar outros trechos
            
            if current_val == H[i-1][j-1] + calcular_pontuacao(s[i-1], t[j-1], match, mismatch):
                align_s = s[i-1] + align_s
                align_t = t[j-1] + align_t
                match_line = ("|" if s[i-1] == t[j-1] else ".") + match_line
                i -= 1
                j -= 1
            elif current_val == H[i-1][j] + gap:
                align_s = s[i-1] + align_s
                align_t = "-" + align_t
                match_line = " " + match_line
                i -= 1
            else:
                align_s = "-" + align_s
                align_t = t[j-1] + align_t
                match_line = " " + match_line
                j -= 1
                
        trechos_encontrados.append((max_score, align_s, align_t, match_line))
        
    return trechos_encontrados

def main():
    y = True
    while y:
        limpa()
        s = input("Digite a sequencia S:\n")
        t = input("Digite a sequencia T:\n")

        if input("\nPor padrao botei os seguintes valores:\n -match = 1\n -mismatch = -1\n -gap = -1\nDeseja alterar esses valores? (s/n) ") == "s":
            match = int(input("Qual valor de match deseja usar?\n-> "))
            mismatch = int(input("Qual valor de mismatch deseja usar?\n-> "))
            gap = int(input("Qual valor de gap deseja usar?\n-> "))

        else:
            match = 1
            mismatch = -1
            gap = -1

        limpa()
        
        print(f"\nTestando as sequencias {s} e {t} com\nos valores de match = {match}, mismatch = {mismatch} e gap = {gap}\n")

        s_g, t_g, match_g, score_g = alinhamento_global(s, t, match, mismatch, gap)
        print_alinhamento(s_g, match_g, t_g, score_g, "Alinhamento Global")
        
        s_sg, t_sg, match_sg, score_sg = alinhamento_semiglobal(s, t, match, mismatch, gap)
        print_alinhamento(s_sg, match_sg, t_sg, score_sg, "Alinhamento Semi-global")

        trechos_locais = alinhamento_local(s, t, match, mismatch, gap)
    
        for idx, (score, s_loc, t_loc, m_loc) in enumerate(trechos_locais):
            print_alinhamento(s_loc, m_loc, t_loc, score, f"Alinhamento Local - Trecho {idx+1}")

        if input("Gostaria de testar outra sequencia? (s/n) ") != "s":
            y = False

if __name__ == "__main__":
    main()
