#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Job {
    int jobID;
    char customerName[50];
    char contact[20];
    char vehicleType[30];
    char vehicleNumber[20];
    char problem[100];
    char date[15];
    char status[20];
    float partsCost;
    float laborCost;
};

struct Job jobs[MAX];
int jobCount = 0;

//file for save data
void saveToFile() {
    FILE *fp = fopen("jobs.txt", "w");
    for (int i = 0; i < jobCount; i++) {
        fprintf(fp, "%d,%s,%s,%s,%s,%s,%s,%s,%.2f,%.2f\n",
            jobs[i].jobID, jobs[i].customerName, jobs[i].contact,
            jobs[i].vehicleType, jobs[i].vehicleNumber, jobs[i].problem,
            jobs[i].date, jobs[i].status, jobs[i].partsCost, jobs[i].laborCost);
    }
    fclose(fp);
}

void loadFromFile() {
    FILE *fp = fopen("jobs.txt", "r");
    if (!fp) return;
    while (fscanf(fp, "%d: %49[^,],%19[^,],%29[^,],%19[^,],%99[^,],%14[^,],%19[^,],%f,%f\n",
        &jobs[jobCount].jobID, jobs[jobCount].customerName, jobs[jobCount].contact,
        jobs[jobCount].vehicleType, jobs[jobCount].vehicleNumber, jobs[jobCount].problem,
        jobs[jobCount].date, jobs[jobCount].status, &jobs[jobCount].partsCost, &jobs[jobCount].laborCost) == 10) {
        jobCount++;
    }
    fclose(fp);
}


//Ui design functions
void printLine() {
    printf("====================================================\n");
}

void header(const char *title) {
    printLine();
    printf("\t%s\n", title);
    printLine();
}


//1. Add a new job
void addJob() {
    if (jobCount >= MAX) return;
    struct Job newJob;
    newJob.jobID = (jobCount == 0) ? 1 : jobs[jobCount - 1].jobID + 1;

    header("ADD NEW JOB");
    printf("Enter customer name: ");  
    fgets(newJob.customerName, 50, stdin); 
    strtok(newJob.customerName, "\n");
    printf("Enter contact number: "); 
    fgets(newJob.contact, 20, stdin); 
    strtok(newJob.contact, "\n");
    printf("Enter vehicle type: "); 
    fgets(newJob.vehicleType, 30, stdin); 
    strtok(newJob.vehicleType, "\n");
    printf("Enter vehicle number: "); 
    fgets(newJob.vehicleNumber, 20, stdin); 
    strtok(newJob.vehicleNumber, "\n");
    printf("Describe the problem: "); 
    fgets(newJob.problem, 100, stdin); 
    strtok(newJob.problem, "\n");
    printf("Enter job date (dd/mm/yyyy): "); 
    fgets(newJob.date, 15, stdin); 
    strtok(newJob.date, "\n");
    strcpy(newJob.status, "Pending");
    printf("Enter parts cost: $ "); scanf("%f", &newJob.partsCost);
    printf("Enter labor cost: $ "); scanf("%f", &newJob.laborCost);

    jobs[jobCount++] = newJob;
    saveToFile();
    printf("\n Job successfully added!\n");
}

//2. View all jobs
void viewAllJobs() {
    header("ALL JOB RECORDS");
    if (jobCount == 0) {
        printf("No jobs found.\n");
        return;
    }

    for (int i = 0; i < jobCount; i++) {
        printf("[%d] %s (%s) - %s\n", jobs[i].jobID, jobs[i].customerName, jobs[i].vehicleNumber, jobs[i].status);
    }
}

//3. Update job status
void updateJobStatus() {
    header("UPDATE JOB STATUS");
    int id;
    printf("Enter Job ID: "); scanf("%d", &id);
    getchar(); 

    for (int i = 0; i < jobCount; i++) {
        if (jobs[i].jobID == id) {
            printf("Current Status: %s\n", jobs[i].status);

            if (strcmp(jobs[i].status, "Pending") == 0)
                strcpy(jobs[i].status, "In Progress");
            else if (strcmp(jobs[i].status, "In Progress") == 0)
                strcpy(jobs[i].status, "Completed");
            else {
                printf("Job already completed.\n");
                return;
            }

            saveToFile();
            printf("✅ Status updated to: %s\n", jobs[i].status);
            return;
        }
    }

    printf(" Job ID not found.\n");
}

//4. Search job by ID
void searchJobByID() {
    header("SEARCH JOB BY ID");
    int id;
    printf("Enter Job ID: "); 
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < jobCount; i++) {
        if (jobs[i].jobID == id) {
            printLine();
            printf("Job ID: %d\n", jobs[i].jobID);
            printf("Customer: %s\n", jobs[i].customerName);
            printf("Contact: %s\n", jobs[i].contact);
            printf("Vehicle: %s %s\n", jobs[i].vehicleType, jobs[i].vehicleNumber);
            printf("Problem: %s\n", jobs[i].problem);
            printf("Date: %s\n", jobs[i].date);
            printf("Status: %s\n", jobs[i].status);
            printf("Parts: $%.2f\n", jobs[i].partsCost);
            printf("Labor: $%.2f\n", jobs[i].laborCost);
            printLine();
            return;
        }
    }

    printf("Job ID not found.\n");
}


//5. Delete a job
void deleteJob() {
    header("DELETE JOB");
    int id;
    printf("Enter Job ID to delete: "); 
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < jobCount; i++) {
        if (jobs[i].jobID == id) {
            for (int j = i; j < jobCount - 1; j++)
                jobs[j] = jobs[j + 1];
            jobCount--;
            saveToFile();
            printf("Job deleted successfully.\n");
            return;
        }
    }

    printf("Job ID not found.\n");
}


//6. Generate invoice
void generateInvoice() {
    header("GENERATE INVOICE");
    int id;
    printf("Enter Job ID: "); 
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < jobCount; i++) {
        if (jobs[i].jobID == id) {
            float total = jobs[i].partsCost + jobs[i].laborCost;
            printLine();
            printf("Invoice for Job ID: %d\n", jobs[i].jobID);
            printf("Customer: %s\n", jobs[i].customerName);
            printf("Vehicle: %s (%s)\n", jobs[i].vehicleType, jobs[i].vehicleNumber);
            printf("Parts Cost: $%.2f\n", jobs[i].partsCost);
            printf("Labor Cost: $%.2f\n", jobs[i].laborCost);
            printf("-----------\nTotal Due: $%.2f\n", total);
            printLine();
            return;
        }
    }

    printf("Job ID not found.\n");
}


//main function
int main() {
    int choice;

    loadFromFile();

    do {
        header("GARAGE SERVICE MANAGEMENT");
        printf("1. Add New Job\n");
        printf("2. View All Jobs\n");
        printf("3. Update Job Status\n");
        printf("4. Search Job by ID\n");
        printf("5. Delete a Job\n");
        printf("6. Generate Invoice\n");
        printf("7. Exit\n");
        printf("Choose an option: "); 
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1: addJob(); break;
            case 2: viewAllJobs(); break;
            case 3: updateJobStatus(); break;
            case 4: searchJobByID(); break;
            case 5: deleteJob(); break;
            case 6: generateInvoice(); break;
            case 7: printf("Thank you for using the system!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }

    } while (choice != 7);

    return 0;
}