cat > README.md << 'EOF'
# 🔐 Cybersecurity Lab 5

## 📖 Description

This project demonstrates password cracking techniques in C on Linux systems.

The lab includes:
- PIN brute-force attacks
- Dictionary attacks
- Recursive password cracking
- Parsing shadow-style password files

---

## 🛠 Topics Covered

- Password Cracking
- Dictionary Attack
- Brute Force Attack
- Linux Shadow Files
- Cryptographic Hashes
- crypt() Function in C

---

## 💻 Language

C

---

## ⚙️ Compilation

### PIN Cracker
```bash
gcc pin_crack.c -o pin_crack -lcrypt
./pin_crack
```

### Dictionary Attack
```bash
gcc dictionary_attack.c -o dictionary_attack -lcrypt
./dictionary_attack
```

### Shadow Parser
```bash
gcc shadow_parse.c -o shadow_parse -lcrypt
./shadow_parse
```

### Recursive Cracker
```bash
gcc recursive_crack.c -o recursive_crack -lcrypt
./recursive_crack
```

---

## 📂 Files

- pin_crack.c
- dictionary_attack.c
- recursive_crack.c
- shadow_parse.c
- dictionary.txt
- shadow.txt
- notes.txt

---

## 🎯 Goal

The goal of this lab is to understand how password cracking techniques work and why strong passwords are important in cybersecurity.
EOF

git add .
git commit -m "Add README"
git push
