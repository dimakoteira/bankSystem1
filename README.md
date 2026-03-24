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
###  💱 Currency Exchange System (New!)
A comprehensive global currency management module that includes:
* **Live Database:** Access to a worldwide list of countries, currency codes, and exchange rates.
* **Update Rates:** Ability to modify exchange rates dynamically.
* **Currency Calculator:** Built-in tool to convert amounts between any two global currencies based on their USD rate.

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

| 🏠 Main Menu | 💱 Currency Exchange | 📊 Transactions |
| :---: | :---: | :---: |
| ![Main]( <img width="1277" height="554" alt="Screenshot 2026-03-24 222508" src="https://github.com/user-attachments/assets/9decf179-1a9b-469c-9915-960ee79007a6" />)
| ![Currency](<img width="1396" height="485" alt="image" src="https://github.com/user-attachments/assets/42c7e6f1-ef9b-4808-a5af-0d84c9381f05" />) 
| ![Trans](<img width="1455" height="433" alt="image" src="https://github.com/user-attachments/assets/58f6b7ff-33ea-4367-a0c6-55cde7c3b167" />) 
|
| *The heart of the system* | *Global rate management* | *Financial operations* |

| 📝 Transfer Log | 👥 Manage Users | 🔐 Login Register |
| :---: | :---: | :---: |
| ![Log](<img width="1613" height="573" alt="image" src="https://github.com/user-attachments/assets/3058d2ef-c2c5-4402-91f2-eaecb871ae4f" />
) | ![Users](<img width="1316" height="551" alt="image" src="https://github.com/user-attachments/assets/6635cc02-5752-47f6-b8d3-53f5a29557f8" />
) | ![Login](<img width="1526" height="961" alt="image" src="https://github.com/user-attachments/assets/738db18b-3de4-4df8-ac65-1ce385dcfe88" />
) |
| *Transaction history* | *Staff & Permission control* | *Security & Audit trails* |



|
