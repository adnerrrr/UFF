public class Conversor {
    // Encapsulamento: Guarda o valor base em segundos
    private int tempoTotalSegundos;

    public Conversor(int segundos) {
        this.tempoTotalSegundos = segundos;
    }

    // Subprogramação: Método focado em obter as horas
    public int obterHoras() {
        return this.tempoTotalSegundos / 3600;
    }

    // Subprogramação: Método focado em obter os minutos restantes
    public int obterMinutos() {
        int restoDosSegundos = this.tempoTotalSegundos % 3600;
        return restoDosSegundos / 60;
    }

    // Subprogramação: Método focado em obter os segundos restantes
    public int obterSegundosRestantes() {
        int restoDosSegundos = this.tempoTotalSegundos % 3600;
        return restoDosSegundos % 60;
    }
}