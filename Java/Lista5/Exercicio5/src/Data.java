public class Data {
    // Encapsulamento: atributos protegidos
    private int dia;
    private int mes;
    private int ano;

    // Construtor: torna obrigatória a inserção dos dados na criação
    public Data(int dia, int mes, int ano) {
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }

    public boolean dataValida() {
        if (this.mes < 1 || this.mes > 12) {
            return false;
        }

        if (this.dia < 1) {
            return false;
        }

        int maxDias = 31;

        if (this.mes == 4 || this.mes == 6 || this.mes == 9 || this.mes == 11) {
            maxDias = 30;
        } else if (this.mes == 2) {
            if (verificarBissexto(this.ano)) { // verificar max de dias de acordo com o tipo do ano
                maxDias = 29;
            } else {
                maxDias = 28;
            }
        }

        return this.dia <= maxDias;
    }

    // Método auxiliar privado
    private boolean verificarBissexto(int anoAnalise) {
        return (anoAnalise % 4 == 0 && anoAnalise % 100 != 0) || (anoAnalise % 400 == 0);
    }

    public boolean anoBissexto() {
        if (!dataValida()) {
            return false;
        }
        return verificarBissexto(this.ano);
    }

    // Separador default "/"
    public void imprime() {
        imprime("/");
    }

    public void imprime(String separador) {
        if (dataValida()) {
            System.out.println(this.dia + separador + this.mes + separador + this.ano);
        } else {
            System.out.println("INVÁLIDA");
        }
    }
}