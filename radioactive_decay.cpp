#include <iostream>
#include <vector>
#include <random>
#include <string>
#include <iomanip>

// Ekrana ilerleme çubuğu (progress bar) basan fonksiyon (Unicode hatası düzeltildi)
std::string draw_bar(double percentage, int width = 20) {
    int filled = static_cast<int>(percentage * width);
    if (filled < 0) filled = 0;
    if (filled > width) filled = width;

    std::string filled_bar = "";
    std::string empty_bar = "";

    // UTF-8 karakterleri güvenli bir şekilde string'e ekliyoruz
    for (int i = 0; i < filled; ++i) filled_bar += "█";
    for (int i = 0; i < (width - filled); ++i) empty_bar += "░";

    return filled_bar + empty_bar;
}

int main() {
    // Monte Carlo Simülasyon Parametreleri
    const int INITIAL_ATOMS = 10000; // Başlangıç atom sayısı
    const double DECAY_PROBABILITY = 0.05; // Her adımda erime olasılığı (%5)
    const int TIME_STEPS = 60; // Toplam simülasyon süresi

    int current_atoms = INITIAL_ATOMS;

    // Rastgele sayı üretici (Monte Carlo kalbi)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    std::cout << "========================================================\n";
    std::cout << "    MONTE CARLO SIMULATION: RADIOACTIVE DECAY (C++17)   \n";
    std::cout << "========================================================\n";
    std::cout << "Initial Atoms: " << INITIAL_ATOMS << " | Decay Prob: " << (DECAY_PROBABILITY * 100) << "%\n\n";
    std::cout << std::left << std::setw(8) << "Time" 
              << std::setw(15) << "Active Atoms" 
              << "Visual Scale (Remaining %)\n";
    std::cout << "--------------------------------------------------------\n";

    for (int t = 0; t <= TIME_STEPS; ++t) {
        double remaining_ratio = static_cast<double>(current_atoms) / INITIAL_ATOMS;
        
        // Verileri ekrana hizalı şekilde basıyoruz
        std::cout << std::left << std::setw(8) << t 
                  << std::setw(15) << current_atoms 
                  << "[" << draw_bar(remaining_ratio) << "] " 
                  << std::fixed << std::setprecision(1) << (remaining_ratio * 100) << "%\n";

        // Bir sonraki adımda kaç atomun eriyeceğini hesaplayan Monte Carlo döngüsü
        int decayed_this_step = 0;
        for (int i = 0; i < current_atoms; ++i) {
            if (dis(gen) < DECAY_PROBABILITY) {
                decayed_this_step++;
            }
        }
        current_atoms -= decayed_this_step;

        // Atomlar tamamen biterse simülasyonu erken sonlandır
        if (current_atoms <= 0) {
            std::cout << "\n[!] All atoms have decayed at time step " << t << ".\n";
            break;
        }
    }
    std::cout << "========================================================\n";

    return 0;
}
