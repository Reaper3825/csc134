#include <iostream>
#include <string>
using namespace std;

// Function prototypes
void exercise1_healthRegen();
void exercise2_levelUpStats();
void exercise3_inventorySystem();

int main() {
    int choice;

    cout << "==================================" << endl;
    cout << "    LAB 7: LOOP FUNDAMENTALS      " << endl;
    cout << "==================================" << endl;
    cout << "1. Exercise 1: Health Regeneration" << endl;
    cout << "2. Exercise 2: Level Up Stats" << endl;
    cout << "3. Exercise 3: Inventory System" << endl;
    cout << "4. Run All Exercises" << endl;
    cout << "5. Exit" << endl;
    cout << "==================================" << endl;
    cout << "Choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            exercise1_healthRegen();
            break;
        case 2:
            exercise2_levelUpStats();
            break;
        case 3:
            exercise3_inventorySystem();
            break;
        case 4:
            exercise1_healthRegen();
            cout << endl;
            exercise2_levelUpStats();
            cout << endl;
            exercise3_inventorySystem();
            break;
        case 5:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}

// ===============================
// Exercise 1: Health Regeneration
// ===============================
void exercise1_healthRegen() {
    cout << "\n=== EXERCISE 1: HEALTH REGENERATION ===" << endl;

    int health = 30;
    int maxHealth = 100;

    cout << "Starting health: " << health << "/" << maxHealth << endl;
    cout << "Resting to recover health..." << endl;

    // while loop to recover health
    while (health < maxHealth) {
        health = health + 10;
        if (health > maxHealth) {
            health = maxHealth;
        }
        cout << "Health: " << health << "/" << maxHealth << endl;
    }

    cout << "Fully recovered!" << endl;
}

// ===============================
// Exercise 2: Level Up Stats
// ===============================
void exercise2_levelUpStats() {
    cout << "\n=== EXERCISE 2: LEVEL UP STATS ===" << endl;

    int baseStrength = 10;
    int baseDexterity = 8;
    int baseIntelligence = 12;

    cout << "Level | STR | DEX | INT" << endl;
    cout << "------------------------" << endl;

    int strAt1, dexAt1, intAt1;
    int strAt10, dexAt10, intAt10;

    for (int level = 1; level <= 10; level++) {
        int strength = baseStrength + (level * 2);
        int dexterity = baseDexterity + (level * 3);
        int intelligence = baseIntelligence + (level * 1);

        cout << "  " << level << "   |  " << strength
             << "  |  " << dexterity << "  |  " << intelligence << endl;

        if (level == 1) {
            strAt1 = strength;
            dexAt1 = dexterity;
            intAt1 = intelligence;
        }
        if (level == 10) {
            strAt10 = strength;
            dexAt10 = dexterity;
            intAt10 = intelligence;
        }
    }

    cout << "------------------------" << endl;
    cout << "Total Growth: STR +" << (strAt10 - strAt1)
         << ", DEX +" << (dexAt10 - dexAt1)
         << ", INT +" << (intAt10 - intAt1) << endl;
}

// ===============================
// Exercise 3: Inventory System
// ===============================
void exercise3_inventorySystem() {
    cout << "\n=== EXERCISE 3: INVENTORY SYSTEM ===" << endl;

    string equipment[5] = {
        "Iron Sword",
        "Leather Armor",
        "Health Potion",
        "Magic Ring",
        "Rope"
    };

    cout << "=== YOUR INVENTORY ===" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << equipment[i] << endl;
    }
    cout << "======================" << endl;

    cin.ignore();
    string searchTerm;
    cout << "Enter item to search for: ";
    getline(cin, searchTerm);

    bool found = false;
    int position = -1;

    for (int i = 0; i < 5; i++) {
        if (equipment[i] == searchTerm) {
            found = true;
            position = i;
            break;
        }
    }

    if (found) {
        cout << "Found \"" << searchTerm << "\" in slot " << (position + 1) << "!" << endl;
    } else {
        cout << "\"" << searchTerm << "\" not found in inventory." << endl;
    }
}
