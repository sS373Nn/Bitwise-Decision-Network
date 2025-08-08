# Neural Network & Bitwise Learning Resources

## Core Concepts We're Implementing

### Q-Learning (Reinforcement Learning)
**What it is:** Value-based learning that builds a table of "how good is this action in this state"
**Why relevant:** Matches your board state memory bank concept perfectly

**Resources:**
- **📚 Book**: "Reinforcement Learning: An Introduction" by Sutton & Barto
  - Chapter 6 (Temporal-Difference Learning) - Core Q-Learning
  - Chapter 4 (Dynamic Programming) - Foundation concepts
  - Available free: http://incompleteideas.net/book/the-book.html
- **🎥 Video Series**: DeepLizard Q-Learning Playlist
  - Start with "What is Reinforcement Learning?"
  - "Q-Learning Explained" episode is essential
- **🖥️ Interactive**: OpenAI Gym tutorials
  - Hands-on TicTacToe and simple game implementations
- **📄 Paper**: "Playing Atari with Deep Reinforcement Learning" (DeepMind 2013)
  - Shows Q-Learning scaling to complex games

### Hopfield Networks (Associative Memory)
**What it is:** Pattern storage and retrieval system that "remembers" complete patterns
**Why relevant:** Could store optimal board configurations and retrieve similar ones

**Resources:**
- **📚 Book**: "Neural Networks and Deep Learning" by Michael Nielsen
  - Chapter 7 covers Hopfield networks with great visuals
  - Free online: http://neuralnetworksanddeeplearning.com/
- **📄 Classic Paper**: "Neural networks and physical systems with emergent collective computational abilities" (Hopfield, 1982)
  - The original paper - surprisingly readable
- **🔥 Recent Paper**: "Hopfield Networks is All You Need" (2020)
  - Modern take connecting to transformer attention mechanisms
- **💻 Implementation**: "Hopfield Network from Scratch" tutorials
  - Search for Python implementations to understand concepts

### Binary Neural Networks (Our Direct Inspiration)
**What it is:** Neural networks using only +1/-1 weights and binary activations
**Why relevant:** Exactly what we're building with bitwise operations

**Resources:**
- **📄 Key Paper**: "BinaryConnect: Training Deep Neural Networks with binary weights" (2015)
- **📄 Advanced**: "XNOR-Net: ImageNet Classification Using Binary Convolutional Neural Networks" (2016)
- **📚 Survey**: "Binary Neural Networks: A Survey" (2020) - Great overview
- **💻 Code**: GitHub search "binary neural networks" for implementations

## Bitwise Operations & Optimization

### Bit Manipulation Fundamentals
- **📚 Book**: "Hacker's Delight" by Henry S. Warren Jr.
  - The bible of bit manipulation tricks
  - Chapter 2 (Basics) and Chapter 5 (Counting Bits) most relevant
- **🖥️ Interactive**: "Bit Twiddling Hacks" website
  - Stanford CS resource with practical examples
- **💻 Practice**: LeetCode bit manipulation problems

### Fast Approximation Methods
- **📄 Classic**: "Fast Inverse Square Root" (Quake III engine)
  - Famous example of bit-level hacking for speed
- **📚 Book**: "Computer Graphics: Principles and Practice"
  - Chapter on approximation methods in graphics (similar trade-offs)

## Game AI & Decision Systems

### TicTacToe AI Approaches
- **📄 Paper**: "Tic-Tac-Toe: Understanding the Minimax Algorithm" (educational)
- **💻 Tutorial**: "Building a TicTacToe AI" (multiple approaches comparison)

### Chess & Complex Games
- **📚 Book**: "Deep Blue: An Artificial Intelligence Milestone" by IBM team
- **📄 Paper**: "Mastering Chess and Shogi by Self-Play with a General Reinforcement Learning Algorithm" (AlphaZero)

## Mathematics Behind the Scenes

### Information Theory (for understanding bit patterns)
- **📚 Book**: "Elements of Information Theory" by Cover & Thomas
  - Chapter 1-2 for entropy and information content
- **🎥 Video**: 3Blue1Brown series on Information Theory

### Linear Algebra (neural network foundations)
- **🎥 Video**: 3Blue1Brown "Essence of Linear Algebra" series
- **📚 Book**: "Linear Algebra Done Right" by Sheldon Axler

## Practical Implementation Guides

### C++ Optimization Techniques
- **📚 Book**: "Optimized C++" by Kurt Guntheroth
- **💻 Resource**: Intel Intrinsics Guide (for SIMD operations)

### Cross-Platform Development (Windows/Linux)
- **📚 Book**: "Professional CMake" by Craig Scott
- **💻 Resource**: Microsoft WSL documentation

## Project-Specific Inspiration

### Similar Projects to Study
- **💻 GitHub**: Search for "binary neural networks C++"
- **💻 GitHub**: "bitwise game AI" repositories
- **📄 Papers**: "Approximate Computing" survey papers

## Bedtime Reading Order Recommendation
1. Start with Nielsen's Neural Networks book (Chapters 1-3 for foundations)
2. Sutton & Barto Q-Learning chapter (Chapter 6)
3. Hopfield's original paper (surprisingly accessible!)
4. Browse "Hacker's Delight" for bit manipulation inspiration
5. AlphaZero paper for inspiration on where this could lead

## Quick Reference Links
- **Q-Learning Tutorial**: https://www.learndatasci.com/tutorials/reinforcement-q-learning-scratch-python-openai-gym/
- **Hopfield Network Visualization**: https://ml4a.github.io/ml4a/neural_networks/
- **Bit Manipulation Cheat Sheet**: https://graphics.stanford.edu/~seander/bithacks.html

---
*This list will grow as we discover new relevant resources during development!*