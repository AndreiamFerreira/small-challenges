import java.util.Scanner;
/*
 Nome: Andréia Ferreira
 07/02/2022
 */

public class RunROB {

    public static void main(String[] args) {
        test();
    }

    public static final void test() {

        int rexPosition, bobPosition, oliPosition;

        Scanner scanner = new Scanner(System.in);

        System.out.println("------------------------BOB, ROB E OLI------------------------"
                + "\n\nATENÇÃO: Digite apenas números inteiros");

        System.out.println("Digite a posicao de Rex:\n");
        rexPosition = scanner.nextInt();

        System.out.println("Digite a posicao de Bob:\n");
        bobPosition = scanner.nextInt();

        System.out.println("Digite a posicao de Oli:\n");
        oliPosition = scanner.nextInt();

        scanner.close();
	    /*
		CONDIÇÃO: só entra em loop caso nenhum dos 3 estejam ocupando a mesma posição

		*/
        while ((rexPosition != bobPosition) && (oliPosition != rexPosition) && (bobPosition != oliPosition)) {
            System.out.println("-----------------------");
            System.out.println("Oli: posicao " + oliPosition);

            if ((rexPosition > oliPosition)) {
                rexPosition -= 1;
                System.out.println("Rex: posicao " + r
            }
            if (bobPosition > oliPosition) {
                bobPosition -= 1;
                System.out.println("Bob: posicao" + oliPosition);

            }

            if (rexPosition < oliPosition) {
                rexPosition += 1;
                System.out.println("Rex: posicao " + rexPosition);

            }
            if (bobPosition < oliPosition) {
                bobPosition += 1;
                System.out.println("Posição Bob: " + bobPosition);

            }

            System.out.println("\nVENCEDOR: ");
            if (rexPosition == oliPosition) {
                System.out.println("REX");

            } else if (bobPosition == oliPosition) {
                System.out.println("BOB");

            } else {
                System.out.println("OLI");
            }
        }
    }
}



