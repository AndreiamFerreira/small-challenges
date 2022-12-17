import java.util.Scanner;

/*
Nome: Andréia Ferreira
07/02/2022
*/

    public class Criptografia {

        public static void main(String[] args) {
            int rotations;
            String userMessage;

            Scanner scanner = new Scanner(System.in);

            System.out.println("Digite o numero de rotações: ");
            rotations = Integer.parseInt(scanner.nextLine());

            System.out.println("\nDigite a mensagem: ");
            userMessage = scanner.nextLine();

            System.out.println(criptografia(userMessage, rotations));

            scanner.close();
        }

        public static final StringBuilder criptografia(String userMessage, int rotations) {
            int initialPosition, newPosition;
            char cyphered_letter;
            StringBuilder cyphered_text = new StringBuilder();

            // converte em uma 'sequencia'
            for (char character : userMessage.toCharArray()) {

                if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')) {

                    // calcula a posicao inicial do caractere dentro do alfabeto a partir da letra a
                    initialPosition = character - 'a';

                    /*
                     * calcula a nova posicao do caractere no alfabeto a partir da soma do numero de
                     * rotacoes com a posicao inicial
                     */

                    newPosition = (initialPosition + rotations) % 26;

                    cyphered_letter = (char) ('a' + newPosition);
                    cyphered_text.append(cyphered_letter);
                } else {
                    cyphered_text.append(character);
                }
            }
            return cyphered_text;

        }
    }

