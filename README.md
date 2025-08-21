UTF-8 Validator in C++
Overview

This project is a UTF-8 validation library written in modern C++.
It provides a simple, self-contained way to check whether a given string is a valid UTF-8 sequence.

The project also includes a mini test suite with both valid and invalid cases, making it easy to verify correctness.

UTF-8 validation is essential in:

Cybersecurity → Detect malformed byte sequences (used in exploits).

Networking → Ensure data integrity across protocols.

Compilers & Parsers → Enforce Unicode compliance.

Data Pipelines → Cleanse text streams.

Features:

-Validate UTF-8 strings without external dependencies

-Detect invalid byte sequences

-Lightweight, single-file implementation

-Includes automated test cases
