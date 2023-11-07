import java.util.*;

public class SimpleTwoPassAssembler {
    public static void main(String[] args) {
        List<String> inputProgram = Arrays.asList(
                "START 1000",
                "LABEL1 LDA 2000",
                "ORG 3000",
                "LABEL2 STA 4000",
                "END"
                
        );

        // Pass 1: Build the symbol table and calculate the location counter
        Map<String, Integer> symbolTable = new HashMap<>();
        int locationCounter = 0;

        for (String line : inputProgram) {
            String[] tokens = line.split("\\s+");
            String label = tokens[0];

            if (!label.equals("START") && !label.equals("END")) {
                if (!label.equals("ORG")) {
                    symbolTable.put(label, locationCounter);
                }

                if (tokens.length > 1) {
                    if (tokens[1].equals("ORG")) {
                        locationCounter = Integer.parseInt(tokens[2]);
                    } else {
                        locationCounter += 1; // Increment the location counter
                    }
                }
            }
        }

        // Pass 2: Generate machine code
        List<String> machineCode = new ArrayList<>();

        for (String line : inputProgram) {
            String[] tokens = line.split("\\s+");

            if (tokens.length > 2) {
                String opcode = tokens[1];
                String operand = tokens[2];

                if (opcode.equals("LDA")) {
                    machineCode.add("00" + operand);
                } else if (opcode.equals("STA")) {
                    machineCode.add("01" + operand);
                }
            }
        }

        // Print the symbol table
        System.out.println("Symbol Table:");
        for (Map.Entry<String, Integer> entry : symbolTable.entrySet()) {
            System.out.println(entry.getKey() + " = " + entry.getValue());
        }

        // Print the machine code
        System.out.println("Machine Code:");
        for (String code : machineCode) {
            System.out.println(code);
        }
    }
}