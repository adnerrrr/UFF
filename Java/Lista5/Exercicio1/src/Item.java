public class Item {
    Produto produto;
    int quantidade;

    public Item(Produto produto, int quantidade) {
        this.produto = produto;
        this.quantidade = quantidade;
    }

    public double custoTotal() {
        return produto.custo * quantidade;
    }
}