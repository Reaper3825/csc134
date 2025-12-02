/*
CSC 134
M4T1 - Gold
Austin Wadkins
12/2/25
*/
#include <iostream>
#include <string>
#include <iomanip> // Needed for formatting table output

using namespace std;

// Function prototypes for the new exercises
void exercise1_sanityDrain();
void exercise2_characterCreationStats();
void exercise3_clueInventory();

int main() {
    int choice;

    do {
        cout << "\n===== THE MANOR'S WHISPER =====" << endl;
        cout << "1. Exercise 1: Sanity Drain Simulation" << endl;
        cout << "2. Exercise 2: Character Creation Stat Roll" << endl;
        cout << "3. Exercise 3: Clue Inventory System" << endl;
        cout << "4. Run All Exercises" << endl;
        cout << "5. Exit" << endl;
        cout << "=================================" << endl;
        cout << "Choice: ";

        // Clear previous input state if needed (good practice)
        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue; // Skip the rest of the loop and start over
        }

        switch(choice) {
            case 1:
                exercise1_sanityDrain();
                break;
            case 2:
                exercise2_characterCreationStats();
                break;
            case 3:
                exercise3_clueInventory();
                break;
            case 4:
                exercise1_sanityDrain();
                cout << endl;
                exercise2_characterCreationStats();
                cout << endl;
                exercise3_clueInventory();
                break;
            case 5:
                cout << "The manor falls silent... for now." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}

// --------------------------------------------------------------------

/*
EXERCISE 1: SANITY DRAIN SIMULATION
CONCEPT: while loop (repeat until condition changes)
Simulate a character losing Sanity as they explore a frightening area.
*/
void exercise1_sanityDrain() {
    cout << "\n=== EXERCISE 1: SANITY DRAIN SIMULATION ===" << endl;

    // Start with high sanity, and a "breaking point"
    int currentSanity = 90;
    const int MIN_SANITY = 0;
    const int SANITY_LOSS_PER_EVENT = 15;

    cout << "Starting Sanity: " << currentSanity << " / 100" << endl;
    cout << "A cold wind whispers through the manor..." << endl << endl;

    // Implement the sanity drain loop: show an event counter
    int event = 1;
    while (currentSanity > MIN_SANITY) {
        currentSanity = currentSanity - SANITY_LOSS_PER_EVENT;

        // Ensure sanity doesn't drop below MIN_SANITY
        if (currentSanity < MIN_SANITY) {
            currentSanity = MIN_SANITY;
        }

        cout << "Event " << event << ": Sanity: " << currentSanity << " / 100" << endl;
        ++event;
    }

    // Display a "Broken" or "Safe" message when done
    cout << endl;
    if (currentSanity == MIN_SANITY) {
        cout << "Their mind shatters under the manor's whisper! (BROKEN)" << endl;
    } else {
        cout << "They stagger away, clutching their sanity." << endl;
    }
}

// --------------------------------------------------------------------

/*
EXERCISE 2: CHARACTER CREATION STAT ROLL
CONCEPT: for loop (count through a sequence)
Display how character stats increase across levels/tiers based on initial rolls.
*/
void exercise2_characterCreationStats() {
    cout << "\n=== EXERCISE 2: CHARACTER CREATION STAT ROLL ===" << endl;

    // Base stats (Imagine these are random rolls at Level 0)
    const int BASE_BODY = 15;      // How much damage they can take
    const int BASE_REFLEXES = 7;   // How well they dodge or react
    const int BASE_SANITY = 10;    // How well they resist psychological damage

    // FORMULAS (Rewritten for your stats and level tiers 1-5)
    // - Body       = baseBody (15) + (level * 3)
    // - Reflexes   = baseReflexes (7) + (level * 2)
    // - Sanity     = baseSanity (10) + (level * 1)

    cout << "Initial Stat Rolls (Tiers 1 to 5):" << endl;
    cout << " Tier | BODY | REFLEXES | SANITY" << endl;
    cout << "------|------|----------|-------" << endl;

    // Total Growth trackers
    int totalBodyGrowth = 0;
    int totalReflexesGrowth = 0;
    int totalSanityGrowth = 0;

    // Stat tiers 1-5: calculate and print stats per level
    for (int level = 1; level <= 5; level++) {
        // Calculate current stats
        int body = BASE_BODY + (level * 3);
        int reflexes = BASE_REFLEXES + (level * 2);
        int sanity = BASE_SANITY + (level * 1);

        // Display formatted row
        cout << setw(5) << level << " |";
        cout << setw(5) << body << " |";
        cout << setw(9) << reflexes << " |";
        cout << setw(6) << sanity << endl;

        // Track growth (optional)
        if (level == 5) { // Calculate total growth at the final tier (Level 5 vs Level 1 stats)
            int bodyLevel1 = BASE_BODY + (1 * 3);
            int reflexesLevel1 = BASE_REFLEXES + (1 * 2);
            int sanityLevel1 = BASE_SANITY + (1 * 1);

            totalBodyGrowth = body - bodyLevel1;
            totalReflexesGrowth = reflexes - reflexesLevel1;
            totalSanityGrowth = sanity - sanityLevel1;
        }
    }

    // Display total growth
    cout << "\nTotal Growth (Tier 1 to 5): ";
    cout << "BODY +" << totalBodyGrowth << ", ";
    cout << "REFLEXES +" << totalReflexesGrowth << ", ";
    cout << "SANITY +" << totalSanityGrowth << endl;
}

// --------------------------------------------------------------------

/*
EXERCISE 3: CLUE INVENTORY SYSTEM
CONCEPT: arrays + loops (managing collections)
Manage the clues found by the player.
*/
void exercise3_clueInventory() {
    cout << "\n=== EXERCISE 3: CLUE INVENTORY SYSTEM ===" << endl;

    // Clue inventory (5 items)
    const int INVENTORY_SIZE = 5;
    string clues[INVENTORY_SIZE] = {
        "Whispering Lullaby Record",
        "Rusty Iron Candelabrum",
        "Torn Wedding Veil",
        "Locked Music Box",
        "Ashen Portrait"
    };

    // Display all clues using a for loop
    cout << "=== CLUE INVENTORY ===" << endl;
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        cout << (i + 1) << ". " << clues[i] << endl; // Display 1-indexed number
    }
    cout << "======================" << endl << endl;

    // Get search term from user
    auto toLower= [](const string &s) {
        string out = s;
        for (size_t i = 0; i < out.size(); ++i) {
            unsigned char c = out[i];
            if (c >= 'A' && c <= 'Z') out[i] = char(c - 'A' + 'a');
        }
        return out;
    };

    auto isSpaceChar = [](unsigned char c) {
        return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f';
    };

    auto trim = [&](const string &s) {
        size_t start = 0;
        while (start < s.size() && isSpaceChar((unsigned char)s[start])) start++;
        size_t end = s.size();
        while (end > start && isSpaceChar((unsigned char)s[end-1])) end--;
        return s.substr(start, end - start);
    };

    string searchTerm;
    cout << "Enter a CLUE to search for: ";
    cin.ignore(10000, '\n'); // Clear the input from previous cin >> choice;
    getline(cin, searchTerm);
    searchTerm = trim(searchTerm);

    if (searchTerm.empty()) {
        cout << "No search term entered. Aborting search." << endl;
        return;
    }

    // Search for the item using a loop (case-insensitive, partial match)
    bool found = false;
    int position = -1;

    // HINT: for (int i = 0; i < INVENTORY_SIZE; i++)
    // Case-insensitive substring search
    string lowerSearch = toLower(searchTerm);
    for (int i = 0; i < INVENTORY_SIZE; i++) {
        string lowerClue = toLower(clues[i]);
        if (lowerClue.find(lowerSearch) != string::npos) {
            found = true;
            position = i; // Store the 0-indexed position
            break; // Stop searching once found
        }
    }

    // Display search results
    if (found) {
        cout << "Found \"" << searchTerm << "\" in slot "
             << (position + 1) << "!" << endl; // Display 1-indexed position
    } else {
        cout << "\"" << searchTerm << "\" not found in the inventory." << endl;
    }
}