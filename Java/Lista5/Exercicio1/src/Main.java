public class Main {
    public static void main(String[] args) {

        // Criando objetos Produto (instâncias da classe Produto)
        Produto arroz = new Produto("Arroz 5kg", 50, 22.90);
        Produto feijao = new Produto("Feijão 1kg", 30, 8.50);
        Produto cafe = new Produto("Café 500g", 25, 14.90);

        // Criando o cliente
        Cliente cliente = new Cliente("Maria");

        // Criando os itens do pedido — cada item referencia um Produto
        Item item1 = new Item(arroz, 2);
        Item item2 = new Item(feijao, 3);
        Item item3 = new Item(cafe, 1);

        // Criando o pedido — capacidade 3 itens
        Mercado pedido = new Mercado(cliente, 3);
        pedido.adicionarItem(item1);
        pedido.adicionarItem(item2);
        pedido.adicionarItem(item3);
        pedido.definirPagamento("Cartão");
    }
}