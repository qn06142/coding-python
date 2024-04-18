#include <iostream>
#include <set>
#include <vector>
#include <string>

std::vector<bool> sieve_of_eratosthenes(int n) {
  std::vector<bool> primes(n + 1, true);
  for (int p = 2; p * p <= n; ++p) {
    if (primes[p]) {
      for (int i = p * p; i <= n; i += p) {
        primes[i] = false;
      }
    }
  }
  return primes;
}

std::set<int> get_primes(int n) {
  std::vector<bool> primes = sieve_of_eratosthenes(n);
  std::set<int> prime_numbers;
  for (int i = 2; i <= n; ++i) {
    if (primes[i]) {
      prime_numbers.insert(i);
    }
  }
  return prime_numbers;
}

int count_primes(std::string& str, const std::set<int>& primes) {
  int count = 0;
  for (int i = 0; i < str.length(); ++i) {
    for (int j = i + 1; j <= str.length(); ++j) {
      std::string sub_str = str.substr(i, j - i);
      if (!sub_str.empty()) {
        int sub_int = std::stoi(sub_str);
        if (primes.find(sub_int) != primes.end()) {
          count++;
        }
      }
    }
  }
  return count;
}

int main() {
  std::string inp;
  std::getline(std::cin, inp);

  int n = std::stoi(inp);
  std::set<int> primes1 = get_primes(n);

  int count = count_primes(inp, primes1);

  if (count > 0) {
    std::cout << count << std::endl;
  } else {
    std::cout << "No primes" << std::endl;
  }

  return 0;
}

