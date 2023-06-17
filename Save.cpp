#include <fstream>
#include <sstream>

//Bisogna capire dove va messo il salvataggio. Si attiva alla pressione di 'Esc' ?

void room::saveRoomState(pRL roomList) {
    std::ofstream file("room_state.txt");
    // Scorrere la lista delle stanze e salvare le informazioni di tutte le  mappe nel file
    pRL currentRoom = roomList;
    while (currentRoom != NULL) {
        file << currentRoom->roomID << " " << currentRoom->roomType << "\n";  //In file sono scritte id, spazio, tipo stanza
        currentRoom = currentRoom->next;
    }

    file.close();
}

pRL room::loadRoomState() {
    std::ifstream file("room_state.txt");
    pRL head = NULL;
    pRL currentRoom = NULL;
 
    int roomID, roomType;

    // Leggere le informazioni dal file e creare la lista delle stanze
    while (file >> roomID >> roomType) {  // Vuol dire che fa il while finchè nel file sono presenti almeno un roomid e un roomtype
        pRL newRoom = new roomList;
        newRoom->roomID = roomID;
        newRoom->roomType = roomType;
        newRoom->next = NULL;

        if (head == NULL) {
            head = newRoom;
            currentRoom = newRoom;
        } else {
            currentRoom->next = newRoom;
            currentRoom = newRoom;
        }
    }

    file.close();

    return head;
}

void saveCharacter() {                    //Accorpate tutte le caratteristiche compresa score.
        std::ofstream outFile("player.txt");

        if (outFile.is_open()) {
            outFile << player.power << std::endl;
            outFile << player.coins << std::endl;
            outFile << player.health << std::endl;
            outFile << player.specialPowers << std::endl;
            outFile << player.score << std::endl;

            outFile.close();
        }
    }

    void loadCharacter() {
        std::ifstream inFile("player.txt");

        if (inFile.is_open()) {
            std::string line;

            std::getline(inFile, line);
            character.power = std::stoi(line);

            std::getline(inFile, line);
            character.coins = std::stoi(line);

            std::getline(inFile, line);
            character.health = std::stoi(line);

            std::getline(inFile, line);
            character.specialPowers = std::stoi(line);

            std::getline(inFile, line);
            character.score = std::stoi(line);

            inFile.close();
        }
    }


// Esempio di salvataggio dello stato delle stanze
// room::pRL roomList = ...;  // La tua lista delle stanze
// room::saveRoomState(roomList);


// Esempio di caricamento dello stato delle stanze
// room::pRL roomList = room::loadRoomState();

//roomid è il generativo
//roomtype è ciò che determina il tipo di stanza
