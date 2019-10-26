#ifndef MNEMONIC_HPP
#define MNEMONIC_HPP

#include <string>

#include "dictionary.hpp"

namespace BIP39 {

class Mnemonic {
   public:
    Mnemonic(std::string entropy, const BIP39::Dictionary& dict);
    Mnemonic(const std::wstring& phrase,
             const BIP39::Dictionary& dict);

    std::string getEntropy() const;
    std::wstring getPhrase() const;
    std::string getSeed() const;

    static bool checkPhraseSeedPair(const std::wstring& phrase,
                                    const std::string& seed,
                                    const BIP39::Dictionary& dict);
   private:
    std::string originalEntropy_;
    std::wstring phrase_;
    std::string seed_;

    static std::string generateSeed(const std::wstring& mnemonic);
    void addToPhrase(const std::wstring& word);
};

}  // end namespace BIP39

#endif
