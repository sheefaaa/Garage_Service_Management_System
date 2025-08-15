# 🚗 Garage Service Management System

## 📌 Overview

The **Garage Service Management System** is a **C language project** that helps manage garage repair jobs.
It allows users to **add, view, search, update, delete, and generate invoices** for jobs.
Data is stored in a file (`jobs.txt`) so that records are saved even after the program is closed.

---

## ✨ Features

* **Add New Job** – Record customer, vehicle, and repair details.
* **View All Jobs** – Display a list of all jobs.
* **Update Job Status** – Change status from *Pending* → *In Progress* → *Completed*.
* **Search Job by ID** – Find detailed information about a specific job.
* **Delete a Job** – Remove job records.
* **Generate Invoice** – Calculate and display total repair costs.
* **File Storage** – All jobs are saved in `jobs.txt` for future use.

---

## 🗂 File Structure

```
garage_project/
│
├── main.c        # Main C program (Garage Service Management System)
├── jobs.txt      # Data file (created automatically after first save)
└── README.md     # This documentation file
```

---

## ⚙️ How to Compile and Run

### **Compile**

```bash
gcc main.c -o garage
```

### **Run**

```bash
./garage
```

---

## 📖 How to Use the Program

When you run the program, you will see the **main menu**:

```
============================================
    GARAGE SERVICE MANAGEMENT
============================================
1. Add New Job
2. View All Jobs
3. Update Job Status
4. Search Job by ID
5. Delete a Job
6. Generate Invoice
7. Exit
Choose an option:
```

### **Example Workflow**

1. Choose **1** to *Add New Job* and enter details.
2. Choose **2** to *View All Jobs*.
3. Choose **3** to *Update Job Status*.
4. Choose **6** to *Generate Invoice*.
5. Choose **7** to *Exit*.

---

## 💾 Data Storage

* Jobs are stored in a file called **`jobs.txt`** in the format:

```
jobID,customerName,contact,vehicleType,vehicleNumber,problem,date,status,partsCost,laborCost
```

* Example:

```
1,John Doe,1234567890,Car,ABC123,Engine Problem,15/08/2025,Pending,200.00,150.00
```

---

## 🛠 Requirements

* **C Compiler** (GCC recommended)
* Works on **Windows**, **Linux**, or **MacOS**

---

## 📌 Notes for Beginners

* **`readLine()`** function is used to read strings safely.
* Always remove leftover newline after `scanf()` to prevent input skipping.
* The program overwrites `jobs.txt` whenever a job is updated or deleted to keep data fresh.

---

## 👨‍💻 Author

Developed by **\[Your Name]** as a beginner-friendly C project.

---

Do you want me to make a **more professional GitHub-style README** with **images and example screenshots** so it looks visually appealing for a project submission? That would make it look very polished.
