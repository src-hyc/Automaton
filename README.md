# Automaton

Automaton is a C++ library with implementation of different types of automata.

## Installation

Run the following commands in terminal to install Automaton.

```bash
git clone https://github.com/src-hyc/Automaton.git
cd Automaton
make && make install
```

## Usage

Create a file `DFA_EvenLength.cpp` with content

```cpp
#include "DeterministicFiniteAutomaton.hpp"

#include <unordered_set>
#include <unordered_map>
#include <iostream>

using namespace Automaton;
using namespace std;

Symbol s;
State sEven, sOdd;

const State *transitionFunction(const State *state, const Symbol *symbol) {
	if (state == &sEven) {
		return &sOdd;
	} else if (state == &sOdd) {
		return &sEven;
	}
	return state;
}

int main() {
	/**
	 * +---------+   symbol   +------+
	 * |         | ---------> |      |
	 * | sEven!* |            | sOdd |
	 * |         | <--------- |      |
	 * +---------+   symbol   +------+
	 *
	 * ! accepted states
	 * * the initial state
	 */
	DeterministicFiniteAutomaton<const State *> evenAutomaton({&s}, &sEven, transitionFunction, {&sEven, &sOdd}, {&sEven});
	// does the automaton accept a string of length 2
	// outputs 1
	cout << evenAutomaton.accept({&s, &s}) << endl;
	// does the automaton accept a string of length 5
	// outputs 0
	cout << evenAutomaton.accept({&s, &s, &s, &s, &s}) << endl;
	return 0;
}
```

Then run in terminal:

```bash
g++ --std=c++17 -o DFA_EvenLength DFA_EvenLength.cpp
./DFA_EvenLength
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)
