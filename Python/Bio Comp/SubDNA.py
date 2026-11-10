from os import name, system

# Quantidade máxima de ocorrências cujos índices serão impressos.
LIMITE_EXIBICAO = 10

def limpa(): # funcao para limpar o terminal
    if name == 'nt':
        system('cls')
    else:
        system('clear')

def buscarCadeias(padrao, sequencia):
    # Procura subcadeias contíguas e guarda o índice inicial de cada uma.
    indices = []
    if not padrao or not sequencia:
        return indices

    # Avança uma posição após cada resultado para também encontrar sobreposições.
    posicao = sequencia.find(padrao)
    while posicao != -1:
        indices.append(posicao)
        posicao = sequencia.find(padrao, posicao + 1)

    return indices

def contagensSufixos(padrao, sequencia):
    # A tabela guarda quantas formas existem de completar cada trecho do padrão
    # a partir de cada posição da sequência.
    tamanho_padrao = len(padrao)
    tamanho_sequencia = len(sequencia)
    contagens = [[0] * (tamanho_sequencia + 1) for _ in range(tamanho_padrao + 1)]

    # Um padrão vazio já foi completado, independentemente da posição.
    contagens[tamanho_padrao] = [1] * (tamanho_sequencia + 1)

    # Preenche a tabela de trás para frente para reutilizar resultados calculados.
    for i in range(tamanho_padrao - 1, -1, -1):
        for j in range(tamanho_sequencia - 1, -1, -1):
            # Ignora a posição atual da sequência.
            contagens[i][j] = contagens[i][j + 1]
            # Se as letras coincidem, soma as formas de completar após essa posição.
            if padrao[i] == sequencia[j]:
                contagens[i][j] += contagens[i + 1][j + 1]

    return contagens


def indiceInicial(valores, alvo):
    # Busca binária pelo primeiro índice de valores que seja >= alvo.
    inicio = 0
    fim = len(valores)
    while inicio < fim:
        meio = (inicio + fim) // 2
        if valores[meio] < alvo:
            inicio = meio + 1
        else:
            fim = meio
    return inicio


def enumerarSequencias(padrao, posicoes, contagens, idx_padrao, idx_seq, caminho):
    # Quando todas as letras do padrão foram encontradas, retorna os índices.
    if idx_padrao == len(padrao):
        yield caminho
        return

    # Considera apenas posições da letra atual que vêm depois da última escolhida.
    candidatas = posicoes.get(padrao[idx_padrao], [])
    inicio = indiceInicial(candidatas, idx_seq)
    for i in range(inicio, len(candidatas)):
        pos = candidatas[i]
        # Evita explorar caminhos que, segundo a tabela, não podem ser completados.
        if contagens[idx_padrao + 1][pos + 1]:
            yield from enumerarSequencias(
                padrao, posicoes, contagens, idx_padrao + 1, pos + 1, caminho + [pos]
            )


def posicoesPorLetra(sequencia):
    # Mapeia cada letra para os índices em que ela aparece na sequência.
    posicoes = {}
    for i, letra in enumerate(sequencia):
        posicoes.setdefault(letra, []).append(i)
    return posicoes


def buscaSequencias(padrao, sequencia, idx_padrao=0, idx_seq=0, caminho=None):
    # Inicializa a busca; os parâmetros opcionais permitem continuar de um estado.
    if caminho is None:
        caminho = []

    # Calcula previamente a quantidade de continuações possíveis e usa os índices
    # agrupados por letra para enumerar apenas combinações válidas.
    contagens = contagensSufixos(padrao, sequencia)
    yield from enumerarSequencias(
        padrao,
        posicoesPorLetra(sequencia),
        contagens,
        idx_padrao,
        idx_seq,
        caminho,
    )


def subCadeias(cadeias, sequencia):
    # Exibe ocorrências contíguas e seus índices iniciais para cada padrão.
    print("\nSub-cadeias\n")
    for i, padrao in enumerate(cadeias, start=1):
        indices = buscarCadeias(padrao, sequencia)
        if indices:
            posicoes = ", ".join(map(str, indices))
            print(f"{i}) {padrao}: {len(indices)} ocorrência(s) com inícios em [{posicoes}].")
        else:
            print(f"{i}) {padrao}: Nenhuma ocorrência encontrada.")
    print("-" * 50)


def subSequencias(sequencias, sequencia_principal):
    # Exibe o total de subsequências e os índices das primeiras ocorrências.
    print("\nSub-sequencias\n")
    posicoes = posicoesPorLetra(sequencia_principal)
    for i, padrao in enumerate(sequencias, start=1):
        # A tabela fornece a contagem total sem precisar enumerar todos os caminhos.
        contagens = contagensSufixos(padrao, sequencia_principal)
        total = contagens[0][0]
        print(f"{i}) {padrao}: Total de ocorrências: {total}.")

        # Gera e imprime no máximo o limite definido, embora a contagem seja completa.
        caminhos = enumerarSequencias(padrao, posicoes, contagens, 0, 0, [])
        for numero, caminho in enumerate(caminhos, start=1):
            print(f"    Ocorrência {numero}: índices -> {caminho}")
            if numero == LIMITE_EXIBICAO:
                break
        if total > LIMITE_EXIBICAO:
            print(f"    Exibindo apenas as primeiras {LIMITE_EXIBICAO} ocorrências.")
    print("-" * 50)


def testa():
    limpa()
    # Lê a sequência em que os padrões serão procurados.
    sequencia_teste = input("Digite a sequencia que deseja testar:\n")
    
    print("-" * 50)
    
    sub_cadeias = ["TTGACA", "TATATT", "CGCGCGCGCG"]
    sub_sequencias = ["TTGACATATATT", "CGCGCGCGCG", "ATCCAGAATTCTCGGA"]
    
    # Executa as duas buscas e mostra seus resultados.
    subCadeias(sub_cadeias, sequencia_teste)
    subSequencias(sub_sequencias, sequencia_teste)

def main():
    y = True
    while y:
        testa()
        if input("Gostaria de testar outra sequencia? (s/n) ") != "s":
            y = False


if __name__ == "__main__":
    main()