#include <iostream>
#include "enemies.hpp"
#include <string>

#include <random>

bool running = 1;



using namespace std;

int main() {
	std::string name;
	std::cout << "Enter your name: ";
	std::getline(std::cin, name);
	std::cout << "Welcome, " << name << "!\n";


	// Player stats
	int health = 20;
	int attack = 5;
	int defense = 3;
	int potion = 1; // Inventory: 1 healing potion

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> encounter_dist(0, 2); // 3 possible encounters

	std::cout << "Your stats:\n";
	std::cout << "Health:  " << health << "\n";
	std::cout << "Attack:  " << attack << "\n";
	std::cout << "Defense: " << defense << "\n";
	std::cout << "Inventory: " << potion << " potion(s)\n\n";

	std::cout << "You stand at a fork in the road.\n";
	std::cout << "1. Go left into the dark forest.\n";
	std::cout << "2. Go right toward the sunny hills.\n";
	std::cout << "Choose (1 or 2): ";
	int choice;
	std::cin >> choice;

	auto combat = [&](std::string enemy_name, int base_health, int base_attack, int scale) {
		int enemy_health = base_health + scale * 2;
		int enemy_attack = base_attack + scale;
		std::cout << "\nA wild " << enemy_name << " appears!\n";
		while (health > 0 && enemy_health > 0) {
			std::cout << "\nChoose your action: 1. Attack  2. Retreat\nAction: ";
			int action;
			std::cin >> action;
			if (action == 2) {
				std::cout << "\nYou retreat from the fight and escape safely, but your adventure ends here.\n";
				return false;
			}
			// Attack
			enemy_health -= std::max(1, attack - scale);
			std::cout << "You hit the " << enemy_name << "! " << enemy_name << " health: " << enemy_health << "\n";
			if (enemy_health <= 0) break;
			health -= std::max(1, enemy_attack - defense);
			std::cout << "The " << enemy_name << " hits you! Your health: " << health << "\n";
			if (health <= 7 && potion > 0) {
				char use_potion;
				std::cout << "You have a potion. Use it? (y/n): ";
				std::cin >> use_potion;
				if (use_potion == 'y' || use_potion == 'Y') {
					health += 10;
					potion--;
					std::cout << "You drink the potion! Health: " << health << ", Potions left: " << potion << "\n";
				}
			}
		}
		if (health > 0 && enemy_health <= 0) {
			std::cout << "\nYou defeated the " << enemy_name << "!\n";
			attack += 1;
			std::cout << "Your attack increases to " << attack << "!\n";
			potion++;
			std::cout << "You find a potion. You now have " << potion << " potion(s).\n";
			return true;
		} else if (health > 0 && enemy_health > 0) {
			// Player retreated
			return false;
		} else {
			std::cout << "\nYou were defeated by the " << enemy_name << ".\n";
			std::cout << "You have lost the fight. Better luck next time!\n";
			std::cout << "Game Over.\n";
			return false;
		}
	};

	if (choice == 1) {
		std::cout << "\nYou enter the forest...\n";
		// Random encounter in the forest
		int encounter = encounter_dist(gen);
		int scale = (attack + defense) / 4;
		bool survived = true;
		if (encounter == 0) {
			survived = combat("Wolf", 10, 4, scale);
		} else if (encounter == 1) {
			survived = combat("Bandit", 12, 6, scale);
		} else {
			survived = combat("Goblin", 8, 5, scale);
		}
		if (!survived) {
			std::cout << "\nYour adventure ends here.\n";
			return 0;
		}
		// Second random encounter
		std::cout << "\nYou move deeper into the forest...\n";
		int encounter2 = encounter_dist(gen);
		if (encounter2 == 0) {
			survived = combat("Bear", 15, 7, scale+1);
		} else if (encounter2 == 1) {
			survived = combat("Orc", 14, 8, scale+1);
		} else {
			survived = combat("Witch", 10, 9, scale+2);
		}
		if (!survived) {
			std::cout << "\nYour adventure ends here.\n";
			return 0;
		}
		std::cout << "\nYou escape the forest victorious!\n";
		std::cout << "\nCongratulations! You have won all your battles and completed your adventure!\n";
	} else if (choice == 2) {
		std::cout << "\nYou walk into the hills and find a peaceful village.\n";
		std::cout << "Do you: 1. Explore the village, 2. Keep walking? ";
		int hill_choice;
		std::cin >> hill_choice;
		if (hill_choice == 1) {
			std::cout << "\nYou make new friends and enjoy a feast!\n";
			health += 5;
			std::cout << "Your health increases to " << health << "!\n";
			std::cout << "A merchant gives you a potion.\n";
			potion++;
			std::cout << "You now have " << potion << " potion(s).\n";
		} else {
			std::cout << "\nYou keep walking and discover a beautiful lake.\n";
			defense += 1;
			std::cout << "You feel refreshed. Your defense increases to " << defense << "!\n";
		}
	} else {
		std::cout << "\nYou stand still, unable to decide. The adventure ends before it begins.\n";
	}

	// Final stats and inventory
	std::cout << "\nFinal stats:\n";
	std::cout << "Health:  " << health << "\n";
	std::cout << "Attack:  " << attack << "\n";
	std::cout << "Defense: " << defense << "\n";
	std::cout << "Potions: " << potion << "\n";

	std::cout << "\nThanks for playing, " << name << "!\n";
	return 0;
}