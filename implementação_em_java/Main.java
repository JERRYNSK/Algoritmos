


import java.lang.Math;
import java.util.Random;

public class Main {

    void imprime(){
        System.out.println("OIIIIIIIIII");
    }
    public static void main(String[] args) {
        int soma = 0;
        for (int i = 1; i <= 10; i++){
            if(i % 2 !=  0){
                soma += i;
            }
        }
        System.out.println(1 % 2);

    }

    static int questionOne(int[] array){

        int biggest = array[0];
        int secondBig = array[0];
        for(int i = 0; i < array.length; i++){
            if(biggest < array[i]){
                secondBig = biggest;
                biggest = array[i];
            }
        }
        return secondBig;
    }
    static boolean questionTwo(String fila){
        if(fila.length() % 2 != 1) return false;
        int i = 0, j = fila.length() - 1;
        while(i < j){
            if(fila.charAt(i) == fila.charAt(j)) break;
            i++;
            j--;
        }

        return i < j;
    }

}
class Rec {
    public Rec() {

    }

    int rec(int a) {
            if (a < 10) {
                System.out.println(a);
                rec(a + 1);
            }
            return a;
    }
    int somaArray(int array[], int len){
        if(len == 0){
            return array[len];
        }
        return array[len] + somaArray(array, len - 1);
    }
    int countArray(int[] array, int n){
        if(n > array.length){
            return n - 1;
        }
        return countArray(array, n + 1);
    }
    int maiorValorArray(int[] array, int n){
        int holder = 0;
        if(n >= array.length) return array[0];
        if(array[0] < array[n]){
            holder = array[0];
            array[0] = array[n];
            array[n] = holder;
        }
        return maiorValorArray(array, n + 1);
    }
    boolean buscaBinaria(int[] array, int value, int r, int l){
        int meio = (l + r)/ 2;
        if(array[meio] < value){
            r = meio + 1;
        }
        else if(array[meio] > value){
            l = meio;
        }
        else {
            return true;
        }
        if(r >= l ) return false;
        return buscaBinaria(array, value, r, l);
    }

    int countReverse(int lim){
        if(lim <= 0) return lim;
        return countReverse(lim - 1);
    }
    // {2,9,4,2,7}
    int quicksort(int[] array, int i, int j){
        int pivot = (j + i) / 2;
        pivot = switchPlace(array, pivot, i, j);
        if(i < j) {
            //direita
            quicksort(array, pivot, j);
            //esquerda
            quicksort(array, i, pivot - 1);
        }
        return array[pivot];

    }
    int switchPlace(int array[], int pivot, int i, int j){
        int holder;
        int numberPivot = array[pivot];

        while(i < j){
            if(array[i] >= numberPivot && numberPivot >= array[j]){
                holder = array[i];
                array[i] = array[j];
                array[j] = holder;
                i++;
                j--;
                continue;
            }
            if(array[i] <= numberPivot) i++;
            if(array[j] >= numberPivot) j--;

        }
        return i;
    }


}

class TableMap {
    public final Node array[];
    public TableMap(int len){
        this.array = new Node[len];
    }
    private int hash(String key){
        int amount = Math.abs(key.hashCode() % array.length);
        return amount;
    }
    void addElement(String key, int value){
        //pode sobrescrever valores ou adicionar novos, é proposital
        int index = hash(key);

        if(array[index] != null){
            Node actualNode = array[index];
            Node nextNode = array[index].next;
            while(true){
                if(actualNode.key.equals(key)){
                    actualNode.value = value;
                    break;
                }
                if(nextNode == null){
                    actualNode.next = new Node(key, value, null);
                    break;
                }
                actualNode = nextNode;
                nextNode = actualNode.next;
            }
        } else {
            array[index] = new Node(key, value, null);
        }

    }
    int getElement(String key){
        int index = hash(key);
        if (array[index] == null){
            throw new NullPointerException("VAZIO");
        } else {
            Node actualNode = array[index];
            Node nextNode = array[index].next;
            while(nextNode != null){
                if(actualNode.key.equals(key)) return actualNode.value;
                actualNode = nextNode;
                nextNode = actualNode.next;
            }
            return actualNode.value;
        }

    }

    public int size(){
        return this.array.length;
    }


    class Node {
        String key;
        int value;
        Node next;
        public Node(String key, int value, Node node){
            this.key = key;
            this.value = value;
            this.next = node;
        }

    }
}

