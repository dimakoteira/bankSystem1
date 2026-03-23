# 🏦 Bank Management System (C++)

A robust, enterprise-level **Bank Management System** built using **Object-Oriented Programming (OOP)** principles. This project is not just a banking tool, but a demonstration of scalable software architecture using custom-built utility libraries.

---

## 🚀 Key Software Engineering Concepts
* **Encapsulation & Data Integrity:** Ensuring sensitive bank data is protected and accessed through secure methods.
* **Abstraction:** Complex logic is hidden behind simple class interfaces.
* **Inheritance:** Leveraging a hierarchical structure for Persons, Clients, and Users.
* **Persistent Storage:** Data is managed through optimized flat-file handling.

---

## 🛠 Custom Libraries & Infrastructure
This project integrates several custom-built utility classes that I developed to streamline common programming tasks:
* **`clsString.h`:** Advanced string manipulation and parsing.
* **`clsDate.h`:** Robust date and time management, used for logging and transaction timestamps.
* **`clsInputValidate.h`:** Ensuring system stability by validating all user inputs and preventing crashes.
* **`Util.h`:** A collection of helper functions for encryption, randomizing, and system utilities.

---

## 🌟 Features
### 🔐 Security & Authentication
* **Encrypted Storage:** User passwords in the database files are fully **encrypted** for maximum security.
* **Login/Logout System:** Secure session management for different system operators.
* **Permissions System:** Granular control over what each user can see or do.

### 💰 Transactions & Auditing
* **Full Banking Operations:** Deposit, Withdraw, and Transfer between accounts.
* **Transfer Log:** Every cent moved is recorded in a dedicated `TransferLog.txt`.
* **Login Register:** Comprehensive tracking of all login attempts for security auditing.

---

## 📁 Folder Structure
* `/src`: Core system logic.
* `/lib`: Custom headers and UI Screen classes.
* `/data`: Secure file-based data storage.
---

## ⚙️ Setup
1. Clone the repo.
2. Open in **Visual Studio**.
3. Ensure the `/data` folder is present in the root directory.
4. Run `bankSystem.cpp`.
## 📸 Screenshots

| Main Menu | Transactions | Transfer Log |
| :---: | :---: | :---: |
| ![Main](https://github.com/user-attachments/assets/f9be0489-f690-4323-a5dd-2297fecd7302) | ![Trans](<img width="1148" height="523" alt="Screenshot 2026-03-23 145112" src="https://github.com/user-attachments/assets/dff32958-f69d-4f3d-8d74-f01f8643a833" />
 | ![Log](<img width="1454" height="478" alt="Screenshot 2026-03-23 150452" src="https://github.com/user-attachments/assets/0d8efdf1-859f-4ca5-8adf-4d8738a91309" />
 |

| Manage Users | Login Register |
| :---: | :---: |
| ![Users] <img width="1208" height="519" alt="Screenshot 2026-03-23 145211" src="https://github.com/user-attachments/assets/b3795356-2f76-429f-a89f-c04ad2384995" />
 | ![Login](<img width="1339" height="704" alt="Screenshot 2026-03-23 145227" src="https://github.com/user-attachments/assets/35afff6d-0133-4f7c-9f32-2f791a92f8be" />
|
