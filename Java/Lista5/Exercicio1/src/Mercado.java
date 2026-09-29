public class Mercado {
    Cliente cliente;
    Item[] itens;
    int totalItens;
    String formaPagamento;

    public Mercado(Cliente cliente, int capacidade) {
        this.cliente = cliente;
        this.itens = new Item[capacidade];
        this.totalItens = 0;
    }

    public void adicionarItem(Item item) {
        itens[totalItens] = item;
        totalItens++;
    }

    public void definirPagamento(String formaPagamento) {
        this.formaPagamento = formaPagamento;
    }

    public double calcularTotal() {
        double total = 0;
        for (int i = 0; i < totalItens; i++) {
            itens[i].custoTotal();
        }
        return total;
    }
}
