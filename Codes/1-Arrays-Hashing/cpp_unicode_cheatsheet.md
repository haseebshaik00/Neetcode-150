# C++ Character Types, Unicode, and Encodings — Cheat Sheet

## 1) Big picture

### Unicode
Unicode is the **set of characters + code points**.

Examples:
- `A` -> `U+0041`
- `é` -> `U+00E9`
- `你` -> `U+4F60`
- `😂` -> `U+1F602`

A **code point** is the number assigned to a character.

### UTF-8 / UTF-16 / UTF-32
These are **encodings** — how a Unicode code point is stored in memory.

- **UTF-8**: uses **1 to 4 code units** - 1 byte size
- **UTF-16**: uses **1 or 2 code units**, where each code unit is **2 bytes**
- **UTF-32**: uses **1 code unit of 4 bytes**

---

## 2) C++ character types

| Type | Size | Represents | Typical use | Important note |
|---|---:|---|---|---|
| `char` | 1 byte | one byte | `std::string` | In UTF-8 text, one visible character may use multiple `char`s |
| `wchar_t` | platform-dependent | wide character | legacy/platform APIs | Not fixed-width; 2 bytes on some systems, 4 on others |
| `char8_t` | 1 byte | UTF-8 code unit | UTF-8 text | One Unicode character may need 1–4 code units |
| `char16_t` | 2 bytes | UTF-16 code unit | UTF-16 text | Some characters use 1 code unit, some use 2 |
| `char32_t` | 4 bytes | UTF-32 code unit / usually one code point | Unicode-safe conceptual handling | One Unicode code point fits directly here |

### Important corrections
- There is **no `char64_t`** in C++.
- There is **no `charw_t`** in C++.
- The correct type is **`wchar_t`**.

---

## 3) C++ string types

| Type | Stores | Good for | Watch out |
|---|---|---|---|
| `std::string` | sequence of `char` | normal text / byte storage | `size()` = bytes, not always visible characters |
| `std::u8string` | sequence of `char8_t` | UTF-8 text | still variable-length per character |
| `std::u16string` | sequence of `char16_t` | UTF-16 text | some characters take 2 code units |
| `std::u32string` | sequence of `char32_t` | Unicode code-point-level work | uses more memory |

---

## 4) Unicode vs UTF

| Term | Meaning |
|---|---|
| Unicode | the character set / code points |
| UTF-8 | encoding of Unicode using 1–4 code units of 1 byte |
| UTF-16 | encoding of Unicode using 1–2 16-bit code units |
| UTF-32 | encoding of Unicode using 1 32-bit code unit |

---

## 5) How many bytes a character may take

| Character | Code point | UTF-8 | UTF-16 | UTF-32 |
|---|---|---:|---:|---:|
| `A` | `U+0041` | 1 byte | 2 bytes | 4 bytes |
| `é` | `U+00E9` | 2 bytes | 2 bytes | 4 bytes |
| `你` | `U+4F60` | 3 bytes | 2 bytes | 4 bytes |
| `😂` | `U+1F602` | 4 bytes | 4 bytes (2 code units) | 4 bytes |

### Key clarification
Emoji **can absolutely be stored in UTF-8**.

They just usually take **4 bytes**, not 1 byte.

So:
- `'A'` in UTF-8 -> 1 byte
- `'😂'` in UTF-8 -> 4 bytes

---

## 6) Example: how decimal 17 is stored

If by **17** you mean the Unicode code point **`U+0011`** (decimal 17), then:

### Decimal 17 in binary

```text
10001
```

Padded forms:
- 8-bit: `00010001`
- 16-bit: `00000000 00010001`
- 32-bit: `00000000 00000000 00000000 00010001`

### UTF-8
For `U+0000` to `U+007F`, UTF-8 uses **1 byte**.

```text
00010001
```

Hex:

```text
0x11
```

### UTF-16
UTF-16 uses **1 code unit of 16 bits** here.

```text
00000000 00010001
```

Hex:

```text
0x0011
```

Bytes depend on endianness:
- Big-endian: `00 11`
- Little-endian: `11 00`

### UTF-32
UTF-32 uses **1 code unit of 32 bits**.

```text
00000000 00000000 00000000 00010001
```

Hex:

```text
0x00000011
```

Bytes:
- Big-endian: `00 00 00 11`
- Little-endian: `11 00 00 00`

### Final comparison for `U+0011`
- **UTF-8:** `11` -> 1 byte
- **UTF-16:** `00 11` -> 2 bytes
- **UTF-32:** `00 00 00 11` -> 4 bytes

---

## 7) `std::string` and storage size

A `std::string` does **not** have a tiny fixed limit like 256 or 1024 bytes.
It is dynamic.

In practice it is limited by:
- available memory
- implementation limits
- `max_size()`

### Important rule
A `std::string` stores **bytes**, not necessarily visible characters.

Examples:

```cpp
std::string a = "Hello";
// size() == 5
```

```cpp
std::string b = "😂";
// size() is usually 4 in UTF-8
// size() is 1 in UTF-32  
```

So:
- ASCII text: often 1 character = 1 byte
- UTF-8 text: 1 visible character may take 1 to 4 bytes
---

## 8) Why `count[26]` works in LeetCode 242

For **LC 242: Valid Anagram**, the usual assumption is:
- input contains only lowercase English letters
- so only `a` to `z` exist
- that gives exactly **26 characters**

That is why this works:

```cpp
int count[26] = {0};
```

Mapping:
- `count[0]` -> `'a'`
- `count[1]` -> `'b'`
- ...
- `count[25]` -> `'z'`

### Complexity
- **Time:** `O(n)`
- **Space:** `O(1)` because 26 is constant

---

## 9) When `count[26]` stops working

If input can contain:
- uppercase letters
- punctuation
- accented letters
- Hindi / Arabic / Chinese
- emoji

then `count[26]` is no longer enough.

### Better idea
Use a hash map.

#### For ASCII / arbitrary byte-based text
```cpp
unordered_map<char, int> freq;
```

#### For conceptually Unicode-aware counting
```cpp
unordered_map<char32_t, int> freq;
```

### Important nuance
`unordered_map<char, int>` still uses **1-byte `char`**, so it is fine for ASCII / bytes, but not truly enough for full Unicode code points in UTF-8 text.

For real Unicode-safe handling, you would first decode text into code points, then count something like `char32_t` values.

---

## 10) Interview-safe answers

| Question | Crisp answer |
|---|---|
| Why `count[26]` in LC 242? | Because input is lowercase English letters only |
| Why not always array? | Arbitrary charset means fixed 26 no longer works |
| What to use then? | `unordered_map<... , int>` |
| ASCII/arbitrary bytes? | `unordered_map<char, int>` |
| True Unicode-aware concept? | `unordered_map<char32_t, int>` |
| Is there `char64_t`? | No, Unicode already fits in `char32_t` |
| Is there `charw_t`? | No, you mean `wchar_t` |

### Strong interview line
> For lowercase English letters, I use a 26-size array, which gives `O(n)` time and `O(1)` space. If the input can contain arbitrary characters, I’d switch to a hash map for frequency counting. For full Unicode, I’d also consider encoding, because `std::string` may hold UTF-8 bytes rather than one byte per character.

---

## 11) Most important takeaway

| Thing | Remember |
|---|---|
| `char` | byte |
| `std::string` | stores bytes |
| UTF-8 | variable-length |
| emoji in UTF-8 | yes, but usually 4 bytes |
| `wchar_t` | wide char, but platform-dependent |
| `char32_t` | clearest conceptual type for one Unicode code point |
---

## 12) Tiny revision sheet

- Unicode = characters + code points
- UTF-8 / UTF-16 / UTF-32 = ways to encode/store Unicode
- `char` = 1 byte
- `std::string` stores bytes
- UTF-8 is variable-length
- emoji can be stored in UTF-8, usually in 4 bytes
- `wchar_t` exists, `charw_t` does not
- `char64_t` does not exist
- `char32_t` is the clean conceptual choice for one Unicode code point
- LC 242 uses `count[26]` only because input is lowercase English letters
