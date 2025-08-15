# Bitwise Decision Network (v1)

**Core Question:** Can we make relevant, intelligent decisions given an input by using only bitwise operations?

## Project Overview

This is an exploratory proof-of-concept project investigating whether bitwise operations can approximate neural network decision-making behaviors. The goal was to see if we could trade some accuracy for significant gains in speed and efficiency by replacing floating-point operations with bitwise manipulation.

**Note:** This codebase is 100% human-written - no AI assistance was used in the implementation. This was intentional to ensure a deep understanding of the fundamentals.

## What Was Built

### Core Architecture
- **OperationNode**: Individual processing units that apply bitwise operations (AND/OR) with configurable masks to input sections
- **NodeSet**: Collections of nodes that process 64-bit inputs in chunks, similar to CNN kernels but using bitwise ops
- **TicTacToePlugin**: Practical application layer for testing the decision network

### Key Features
- Section-based input processing (dividing 64-bit inputs into configurable chunks)
- Mask-based operations for selective bit manipulation  
- Modular node architecture allowing different operation types
- Test-driven development with GoogleTest framework

## The Exploration Process

This project deliberately embraced a messy, exploratory approach:

1. **Started with a question** - can bitwise ops make intelligent decisions?
2. **Built incrementally** - OperationNode → NodeSet → TicTacToePlugin
3. **Tested practically** - ported to TicTacToe for real-world validation
4. **Extended testing** - used AI swarms to stress-test the decision network
5. **Learned iteratively** - discovered architectural insights for v2

## Key Discoveries

- Bitwise operations can indeed make structured decisions
- Section-based processing provides flexibility in input handling
- Simple AND/OR operations with masks can create complex behaviors
- The architecture works but needs better metrics and evaluation methods

## Testing & Validation

The network was tested through multiple phases:
1. Unit tests for individual components
2. Integration tests for the full NodeSet
3. Practical application via TicTacToe gameplay (fully integrated in separate project)
4. Stress testing using AI swarm methodologies (in separate project)

## What's Next

Lessons learned from this exploration are informing v2, which will feature:
- Proper metrics for measuring decision accuracy vs speed
- Cleaner architecture and file organization
- More sophisticated bitwise operations
- Better evaluation frameworks

## Technical Details

**Language:** C++  
**Testing:** GoogleTest  
**Architecture:** Modular node-based processing  
**Build System:** Batch files for component-wise building  

The project demonstrates both the feasibility of bitwise decision networks and the value of exploratory programming - sometimes you need to build it messy first to understand what clean should look like.
