#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h> // for opendir() function
#include <sys/stat.h> // for mkdir() function
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAX_STUDENTS 100
struct CEA201 {
    char student_name[50];
    float assignment1_grade;
    float assignment2_grade;
    float exercise1_grade;
    float exercise2_grade;
    float exercise3_grade;
    float exercise4_grade;
    float final_exam_grade;
    float average_grade;
};

struct CSI104 {
    char student_name[50];
    float group_presentation1_grade;
    float group_presentation2_grade;
    float lab1_grade;
    float lab2_grade;
    float progress_test1_grade;
    float progress_test2_grade;
    float progress_test3_grade;
    float progress_test4_grade;
    float final_exam_grade;
    float average_grade;
};


struct MAE101 {
    char student_name[50];
    float assignment1_grade;
    float assignment2_grade;
    float assignment3_grade;
    float progress_test1_grade;
    float progress_test2_grade;
    float progress_test3_grade;
    float final_exam_grade;
    float average_grade;
};


struct PRF192 {
    char student_name[50];
    float assignment_grade;
    float progress_test1_grade;
    float progress_test2_grade;
    float workshop1_grade;
    float workshop2_grade;
    float workshop3_grade;
    float workshop4_grade;
    float workshop5_grade;
    float practical_exam_grade;
    float final_exam_grade;
    float average_grade;
};


struct student {
    int index;
    char name[50];
    char id[10];
    struct CEA201 cea201_data;
    struct CSI104 csi104_data;
    struct MAE101 mae101_data;
    struct PRF192 prf192_data;
};

void print_students(struct student students[], int num_students);
void add_student(struct student students[], int *num_students);
void remove_student(struct student students[], int *num_students);
void cea201_process(struct student students[], int num_students, int index_to_change);
void csi104_process(struct student students[], int num_students, int index_to_change);
void mae101_process(struct student students[], int num_students, int index_to_change);
void prf192_process(struct student students[], int num_students, int index_to_change);
void show_student_component_points(struct student students[], int *num_students, char* subjectName);
void create_folder(const char* path);
void delete_file(char* filename);


int main() {
	printf("Component points management software for subject CEA201, CSI104, MAE101, PRF192\n");
	printf("-------------------------------------------------------------------------------\n");
	create_folder("PRF192");
	create_folder("MAE101");
	create_folder("CSI104");
	create_folder("CEA201");
    struct student students[MAX_STUDENTS];
    int num_students = 0;

    // Read student list from file
	FILE *fp;
	fp = fopen("studentList.txt", "r");
	if (fp != NULL) {
	    char line[100];
	    while (fgets(line, 100, fp) != NULL) {
	        struct student s;
	        char *token;
	        char *delimiter = "-\n";
	        
	        // Extract the student index
	        token = strtok(line, delimiter);
	        s.index = atoi(token);
	        
	        // Extract the student name
	        token = strtok(NULL, delimiter);
	        strcpy(s.name, token);
	        
	        // Extract the student ID
	        token = strtok(NULL, delimiter);
	        strcpy(s.id, token);
	        
	        students[num_students] = s;
	        num_students++;
	    }
	    fclose(fp);
	}
	int i;
    int choice;
    int index_to_change = 0;
    int temp_c;
    do {
        printf("Please select an option:\n");
        printf("1  - Print the list of students\n");
        printf("2  - Add a student\n");
        printf("3  - Remove a student\n");
        printf("4  - Update component points of subject cea201 for a student\n");
        printf("5  - Update component points of subject csi104 for a student\n");
        printf("6  - Update component points of subject mae101 for a student\n");
        printf("7  - Update component points of subject PRF192 for a student\n");
        printf("8  - Print component points of subject CEA201 for a student\n");
        printf("9  - Print component points of subject CSI104 for a student\n");
        printf("10 - Print component points of subject MAE101 for a student\n");
        printf("11 - Print component points of subject PRF192 for a student\n");
        printf("12 - Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while ((getchar()) != '\n');

        switch (choice) {
            case 1:
                print_students(students, num_students);
                break;
            case 2:
                add_student(students, &num_students);
                break;
            case 3:
            	print_students(students, num_students);
                remove_student(students, &num_students);
                break;
            case 4:
            	print_students(students, num_students);
			    printf("Enter the index of the student to update: ");
			    scanf("%d", &index_to_change);
				while ((temp_c = getchar()) != '\n' && temp_c != EOF);
			    if (index_to_change < 1 || index_to_change > num_students) {
			        printf("Error: invalid index\n");
			        return;
			    }
				cea201_process(students, num_students, index_to_change);
				break;
            case 5:
            	print_students(students, num_students);
			    printf("Enter the index of the student to update: ");
			    scanf("%d", &index_to_change);
				while ((temp_c = getchar()) != '\n' && temp_c != EOF);
			    if (index_to_change < 1 || index_to_change > num_students) {
			        printf("Error: invalid index\n");
			        return;
			    }
				csi104_process(students, num_students, index_to_change);
				break;
            case 6:
            	print_students(students, num_students);
			    printf("Enter the index of the student to update: ");
			    scanf("%d", &index_to_change);
				while ((temp_c = getchar()) != '\n' && temp_c != EOF);
			    if (index_to_change < 1 || index_to_change > num_students) {
			        printf("Error: invalid index\n");
			        return;
			    }
				mae101_process(students, num_students, index_to_change);
				break;
            case 7:
            	print_students(students, num_students);
			    printf("Enter the index of the student to update: ");
			    scanf("%d", &index_to_change);
				while ((temp_c = getchar()) != '\n' && temp_c != EOF);
			    if (index_to_change < 1 || index_to_change > num_students) {
			        printf("Error: invalid index\n");
			        return;
			    }
				prf192_process(students, num_students, index_to_change);
				break;
			case 8:
				print_students(students, num_students);
				show_student_component_points(students, &num_students, "CEA201");
				break;
			case 9:
				print_students(students, num_students);
				show_student_component_points(students, &num_students, "CSI104");
				break;
			case 10:
				print_students(students, num_students);
				show_student_component_points(students, &num_students, "MAE101");
				break;
			case 11:
				print_students(students, num_students);
				show_student_component_points(students, &num_students, "PRF192");
				break;
            case 12:
                break; 	
            default:
                printf("Error: invalid choice\n");
                break;
        }
    } while (choice != 12);

    // Write updated student list to file
    fp = fopen("studentList.txt", "w");
    if (fp != NULL) {
        // write each student to the file
        int i;
        for (i = 0; i < num_students; i++) {
            fprintf(fp, "%d-%s-%s\n", students[i].index, students[i].name, students[i].id);
        }
        fclose(fp);
        printf("Student list saved to file.\n");
    } else {
        printf("Error: Unable to write to file.\n");
    }

    return 0;
}

void delete_file(char* filename) {
    // Check if file exists
    if (access(filename, F_OK) != -1) {
        // Delete file if it exists
        if (remove(filename) == 0) {
            printf("File %s deleted.\n", filename);
        }
    }
}


void create_folder(const char *path) {
    struct stat st = {0};
    
    // Check if folder exists
    if (opendir(path) == NULL) {
        // Create folder if it doesn't exist
        if (stat(path, &st) == -1) {
            mkdir(path); // 0700 sets permissions to rwx for owner only
        }
    }
    else {
        return ;
    }
    
}

void print_students(struct student students[], int num_students) {
	if(num_students == 0){
		printf("The list is empty\n");
		printf("--------------------------------------------------------\n");
		return;
	}
    FILE *fp;
    fp = fopen("studentList.txt", "r");
    if (fp == NULL) {
        printf("List of students:\n");
        int i;
        for (i = 0; i < num_students; i++) {
            printf("%-2d - %-20s - %10s\n", students[i].index, students[i].name, students[i].id);
        }
    }
    else {
        printf("List of students:\n");
        printf("--------------------------------------------------------\n");
        int i;
        for (i = 0; i < num_students; i++) {
            printf("%-2d - % - 25s-%10s\n", students[i].index, students[i].name, students[i].id);
        }
    }
    printf("--------------------------------------------------------\n");
}

void add_student(struct student students[], int *num_students) {
    struct student newStudent;
    printf("\nEnter the student's name: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = 0; // remove newline character
    printf("\nEnter the student's ID: ");
    scanf("%s", newStudent.id);
    getchar(); // consume the newline character left in the input buffer by scanf
    newStudent.index = *num_students + 1;
    students[*num_students] = newStudent;
    (*num_students)++;
    printf("\nStudent added to the list.\n");

    // Write updated student list to file
    FILE *fp;
    fp = fopen("studentList.txt", "w");
    if (fp != NULL) {
        // write each student to the file
        int i;
        for (i = 0; i < *num_students; i++) {
            fprintf(fp, "%d - %s - %s\n", students[i].index, students[i].name, students[i].id);
        }
        fclose(fp);
        printf("Student list saved to file.\n");
    } else {
        printf("Error: Unable to write to file.\n");
    }
}


void show_student_component_points(struct student students[], int *num_students, char* subjectName) {
	char filename[100];
    int index_to_update;
    printf("Enter the index of the student you want to show: ");
    scanf("%d", &index_to_update);
    if (index_to_update < 1 || index_to_update > *num_students) {
        printf("Error: invalid index\n");
        return;
    }

	FILE *file;
    char c;

    sprintf(filename,"%s/ %s.txt", subjectName, students[index_to_update-1].id);
	printf("-------------------------------------------------------------------------------\n");
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file. File does not exist or could not be opened.\n");
        return;
    }

    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }
	
    fclose(file);
    printf("-------------------------------------------------------------------------------\n");
    return;
}


void remove_student(struct student students[], int *num_students) {
    int index_to_remove;
    printf("Enter the index of the student to remove: ");
    scanf("%d", &index_to_remove);
    if (index_to_remove < 1 || index_to_remove > *num_students) {
        printf("Error: invalid index\n");
        return;
    }
    int i;
	char filename[100];
	sprintf(filename, "PRF192/ %s.txt", students[index_to_remove-1].id);
	delete_file(filename);   
	sprintf(filename, "CSI104/ %s.txt", students[index_to_remove-1].id);
	delete_file(filename);   
	sprintf(filename, "CEA201/ %s.txt", students[index_to_remove-1].id);
	delete_file(filename);   
	sprintf(filename, "MAE101/ %s.txt", students[index_to_remove-1].id);
	delete_file(filename);   
    for (i = index_to_remove - 1; i < *num_students - 1; i++) {
        students[i] = students[i + 1];
        students[i].index--;
    }
    (*num_students)--;
    printf("Student removed from the list.\n");

    // Write updated student list to file
    FILE *fp = fopen("studentList.txt", "w");
    if (fp != NULL) {
        // Write each student to the file
        int i;
        for (i = 0; i < *num_students; i++) {
            fprintf(fp, "%d-%s-%s\n", students[i].index, students[i].name, students[i].id);
        }
        fclose(fp);
    } else {
        printf("Error: Unable to write to file.\n");
    }
}

void cea201_process(struct student students[], int num_students, int index_to_change) {
    struct CEA201 student_cea_point;
    char student_name[50], input[50], filename[100];
    int choice, i;
    float grade;
    FILE *file;
    sprintf(filename, "CEA201/ %s.txt", students[index_to_change-1].id); // generate filename based on student name

    // load previous grades from file if it exists
    if (access(filename, F_OK) != -1) {
        file = fopen(filename, "r");
        if (file == NULL) {
            printf("Error opening file\n");
            return;
        }
        fscanf(file, "Student Name: %[^\n]\n", student_cea_point.student_name);
        fscanf(file, "Assignment 1: %f\n", &student_cea_point.assignment1_grade);
        fscanf(file, "Assignment 2: %f\n", &student_cea_point.assignment2_grade);
        fscanf(file, "Exercise 1: %f\n", &student_cea_point.exercise1_grade);
        fscanf(file, "Exercise 2: %f\n", &student_cea_point.exercise2_grade);
        fscanf(file, "Exercise 3: %f\n", &student_cea_point.exercise3_grade);
        fscanf(file, "Exercise 4: %f\n", &student_cea_point.exercise4_grade);
        fscanf(file, "Final Exam: %f\n", &student_cea_point.final_exam_grade);
        fscanf(file, "Average grade: %f\n", &student_cea_point.average_grade);
        fclose(file);
    }
    else {
    	strcpy(student_cea_point.student_name, students[index_to_change-1].name);
        student_cea_point.assignment1_grade = 0;
        student_cea_point.assignment2_grade = 0;
        student_cea_point.exercise1_grade = 0;
        student_cea_point.exercise2_grade = 0;
        student_cea_point.exercise3_grade = 0;
        student_cea_point.exercise4_grade = 0;
        student_cea_point.final_exam_grade = 0;
        student_cea_point.average_grade = 0.1*(student_cea_point.assignment1_grade + student_cea_point.assignment2_grade) 
										+ 0.075*(student_cea_point.exercise1_grade + student_cea_point.exercise2_grade + student_cea_point.exercise3_grade + student_cea_point.exercise4_grade);
										+ 0.4*(student_cea_point.final_exam_grade);
    }

    for (i = 0; i < num_students; i++) {
        if (students[i].index == index_to_change) {
            // student found
            students[i].cea201_data = student_cea_point;
		    do{
		        printf("Choose grade to enter:\n");
		        printf("1. Assignment 1\n");
		        printf("2. Assignment 2\n");
		        printf("3. Exercise 1\n");
		        printf("4. Exercise 2\n");
		        printf("5. Exercise 3\n");
		        printf("6. Exercise 4\n");
		        printf("7. Final Exam\n");
		        printf("8. Exit\n");
		        printf("Enter choice (1-8): ");
		        fgets(input, sizeof(input), stdin);
		        sscanf(input, "%d", &choice);
		        fflush(stdin);
		// continue writing program
				switch (choice) {
				case 1:
				printf("Enter grade for Assignment 1: ");
				fgets(input, sizeof(input), stdin);
				sscanf(input, "%f", &grade);
				student_cea_point.assignment1_grade = grade;
				break;
				case 2:
				printf("Enter grade for Assignment 2: ");
				fgets(input, sizeof(input), stdin);
				sscanf(input, "%f", &grade);
				student_cea_point.assignment2_grade = grade;
				break;
				case 3:
				printf("Enter grade for Exercise 1: ");
				fgets(input, sizeof(input), stdin);
				sscanf(input, "%f", &grade);
				student_cea_point.exercise1_grade = grade;
				break;
				case 4:
				printf("Enter grade for Exercise 2: ");
				fgets(input, sizeof(input), stdin);
				sscanf(input, "%f", &grade);
				student_cea_point.exercise2_grade = grade;
				break;
				case 5:
				printf("Enter grade for Exercise 3: ");
				fgets(input, sizeof(input), stdin);
				sscanf(input, "%f", &grade);
				student_cea_point.exercise3_grade = grade;
				break;
				case 6:
				printf("Enter grade for Exercise 4: ");
				fgets(input, sizeof(input), stdin);
				sscanf(input, "%f", &grade);
				student_cea_point.exercise4_grade = grade;
				break;
				case 7:
				printf("Enter grade for Final Exam: ");
				fgets(input, sizeof(input), stdin);
				sscanf(input, "%f", &grade);
				student_cea_point.final_exam_grade = grade;
				break;
				case 8:
				break;
				default:
				printf("Invalid choice\n");
				break;
				}
				} while (choice != 8);
	// write updated grades to file
	student_cea_point.average_grade = 0.1*(student_cea_point.assignment1_grade + student_cea_point.assignment2_grade) 
									+ 0.075*(student_cea_point.exercise1_grade + student_cea_point.exercise2_grade + student_cea_point.exercise3_grade + student_cea_point.exercise4_grade);
									+ 0.4*(student_cea_point.final_exam_grade);
	file = fopen(filename, "w");
	if (file == NULL) {
	    printf("Error opening file\n");
	    return;
	}
	fprintf(file, "Student Name: %s\n", student_cea_point.student_name);
	fprintf(file, "Assignment 1: %.2f\n", student_cea_point.assignment1_grade);
	fprintf(file, "Assignment 2: %.2f\n", student_cea_point.assignment2_grade);
	fprintf(file, "Exercise 1: %.2f\n", student_cea_point.exercise1_grade);
	fprintf(file, "Exercise 2: %.2f\n", student_cea_point.exercise2_grade);
	fprintf(file, "Exercise 3: %.2f\n", student_cea_point.exercise3_grade);
	fprintf(file, "Exercise 4: %.2f\n", student_cea_point.exercise4_grade);
	fprintf(file, "Final Exam: %.2f\n", student_cea_point.final_exam_grade);
	fprintf(file, "Average grade: %.2f\n", student_cea_point.average_grade);
	fclose(file);
		}
	}
}


void csi104_process(struct student students[], int num_students, int index_to_change) {
    struct CSI104 student_csi_point;
    char student_name[50], input[50], filename[100];
    int choice, i;
    float grade;
    FILE *file;
    sprintf(filename, "CSI104/ %s.txt", students[index_to_change-1].id); // generate filename based on student name

    // load previous grades from file if it exists
    if (access(filename, F_OK) != -1) {
        file = fopen(filename, "r");
        if (file == NULL) {
            printf("Error opening file\n");
            return;
        }
        fscanf(file, "Student Name: %[^\n]\n", student_csi_point.student_name);
        fscanf(file, "Group presentation 1: %f\n", &student_csi_point.group_presentation1_grade);
        fscanf(file, "Group presentation 2: %f\n", &student_csi_point.group_presentation2_grade);
        fscanf(file, "Lab 1: %f\n", &student_csi_point.lab1_grade);
        fscanf(file, "Lab 2: %f\n", &student_csi_point.lab2_grade);
        fscanf(file, "Progress test 1: %f\n", &student_csi_point.progress_test1_grade);
        fscanf(file, "Progress test 2: %f\n", &student_csi_point.progress_test2_grade);
        fscanf(file, "Progress test 3: %f\n", &student_csi_point.progress_test3_grade);
        fscanf(file, "Final Exam: %f\n", &student_csi_point.final_exam_grade);
        fscanf(file, "Average grade: %f\n", &student_csi_point.average_grade);
        fclose(file);
    }
    else {
        strcpy(student_csi_point.student_name, students[index_to_change-1].name);
        student_csi_point.group_presentation1_grade = 0;
        student_csi_point.group_presentation2_grade = 0;
        student_csi_point.lab1_grade = 0;
        student_csi_point.lab2_grade = 0;
        student_csi_point.progress_test1_grade = 0;
        student_csi_point.progress_test2_grade = 0;
        student_csi_point.progress_test3_grade = 0;
        student_csi_point.final_exam_grade = 0;
    	student_csi_point.average_grade = 0.05*(student_csi_point.group_presentation1_grade + student_csi_point.group_presentation2_grade)
    									+ 0.1*(student_csi_point.lab1_grade + student_csi_point.lab2_grade)
    									+ 0.1*(student_csi_point.progress_test1_grade + student_csi_point.progress_test2_grade+ student_csi_point.progress_test3_grade)
    									+ 0.4*(student_csi_point.final_exam_grade);
    }

    for (i = 0; i < num_students; i++) {
        if (students[i].index == index_to_change) {
            // student found
            students[i].csi104_data = student_csi_point;
            do {
                printf("Choose grade to enter:\n");
                printf("1. Group presentation 1\n");
                printf("2. Group presentation 2\n");
                printf("3. Lab 1\n");
                printf("4. Lab 2\n");
                printf("5. Progress test 1\n");
                printf("6. Progress test 2\n");
                printf("7. Progress test 3\n");
                printf("8. Final Exam\n");
                printf("9. Exit\n");
                printf("Enter choice (1-9): ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%d", &choice);
                fflush(stdin);
                // continue writing program
				switch (choice) {
				case 1:
					printf("Enter grade for Group presentation 1: ");
					fgets(input, sizeof(input), stdin);
					sscanf(input, "%f", &grade);
					student_csi_point.group_presentation1_grade = grade;
					break;
				case 2:
					printf("Enter grade for Group presentation 2: ");
					fgets(input, sizeof(input), stdin);
					sscanf(input, "%f", &grade);
					student_csi_point.group_presentation2_grade = grade;
					break;
				case 3:
					printf("Enter grade for Lab 1: ");
					fgets(input, sizeof(input), stdin);
					sscanf(input, "%f", &grade);
					student_csi_point.lab1_grade = grade;
					break;
				case 4:
					printf("Enter grade for Lab 2: ");
					fgets(input, sizeof(input), stdin);
					sscanf(input, "%f", &grade);
					student_csi_point.lab2_grade = grade;
					break;
				case 5:
					printf("Enter grade for Progress test 1: ");
					fgets(input, sizeof(input), stdin);
					sscanf(input, "%f", &grade);
					student_csi_point.progress_test1_grade = grade;
					break;
				case 6:
					printf("Enter grade for Progress test 2: ");
					fgets(input, sizeof(input), stdin);
					sscanf(input, "%f", &grade);
					student_csi_point.progress_test2_grade = grade;
					break;
				case 7:
					printf("Enter grade for Progress test 3: ");
					fgets(input, sizeof(input), stdin);
					sscanf(input, "%f", &grade);
					student_csi_point.progress_test3_grade = grade;
					break;
				case 8:
					printf("Enter grade for Final Exam: ");
					fgets(input, sizeof(input), stdin);
					sscanf(input, "%f", &grade);
					student_csi_point.final_exam_grade = grade;
					break;
				case 9:
					break;
				default:
					printf("Invalid choice\n");
					break;
					}
				} while (choice != 9);
	// write updated grades to file
    student_csi_point.average_grade = 0.05*(student_csi_point.group_presentation1_grade + student_csi_point.group_presentation2_grade)
    									+ 0.1*(student_csi_point.lab1_grade + student_csi_point.lab2_grade)
    									+ 0.1*(student_csi_point.progress_test1_grade + student_csi_point.progress_test2_grade+ student_csi_point.progress_test3_grade)
    									+ 0.4*(student_csi_point.final_exam_grade);
	file = fopen(filename, "w");
	if (file == NULL) {
	    printf("Error opening file\n");
	    return;
	}
    fprintf(file, "Student Name: %s\n", student_csi_point.student_name);
    fprintf(file, "Group presentation 1: %.2f\n", student_csi_point.group_presentation1_grade);
    fprintf(file, "Group presentation 2: %.2f\n", student_csi_point.group_presentation2_grade);
    fprintf(file, "Lab 1: %.2f\n", student_csi_point.lab1_grade);
    fprintf(file, "Lab 2: %.2f\n", student_csi_point.lab2_grade);
    fprintf(file, "Progress test 1: %.2f\n", student_csi_point.progress_test1_grade);
    fprintf(file, "Progress test 2: %.2f\n", student_csi_point.progress_test2_grade);
    fprintf(file, "Progress test 3: %.2f\n", student_csi_point.progress_test3_grade);
    fprintf(file, "Final Exam: %.2f\n", student_csi_point.final_exam_grade);
    fprintf(file, "Average grade: %.2f\n", student_csi_point.average_grade);
    
	fclose(file);
		}
	}
}




void prf192_process(struct student students[], int num_students, int index_to_change) {
    struct PRF192 student_prf_point;
    char student_name[50], input[50], filename[100];
    int choice, i;
    float grade;
    FILE *file;
    sprintf(filename, "PRF192/ %s.txt", students[index_to_change-1].id); // generate filename based on student name

    // load previous grades from file if it exists
    if (access(filename, F_OK) != -1) {
        file = fopen(filename, "r");
        if (file == NULL) {
            printf("Error opening file\n");
            return;
        }
        
	    fscanf(file, "Student Name: %[^\n]\n", student_prf_point.student_name);
	    fscanf(file, "Assignment: %f\n", &student_prf_point.assignment_grade);
	    fscanf(file, "Progress test 1: %f\n", &student_prf_point.progress_test1_grade);
	    fscanf(file, "Progress test 2: %f\n", &student_prf_point.progress_test2_grade);
	    fscanf(file, "Workshop 1: %f\n", &student_prf_point.workshop1_grade);
	    fscanf(file, "Workshop 2: %f\n", &student_prf_point.workshop2_grade);
	    fscanf(file, "Workshop 3: %f\n", &student_prf_point.workshop3_grade);
	    fscanf(file, "Workshop 4: %f\n", &student_prf_point.workshop4_grade);
	    fscanf(file, "Workshop 5: %f\n", &student_prf_point.workshop5_grade);
	    fscanf(file, "Practical Exam: %f\n", &student_prf_point.practical_exam_grade);
	    fscanf(file, "Final Exam: %f\n", &student_prf_point.final_exam_grade);
	    fscanf(file, "Average grade: %f\n", &student_prf_point.average_grade);
        fclose(file);
    }
    else {
        strcpy(student_prf_point.student_name, students[index_to_change-1].name);
        student_prf_point.assignment_grade = 0;
        student_prf_point.progress_test1_grade = 0;
        student_prf_point.progress_test2_grade = 0;
		student_prf_point.workshop1_grade = 0;
		student_prf_point.workshop2_grade = 0;
		student_prf_point.workshop3_grade = 0;
		student_prf_point.workshop4_grade = 0;
		student_prf_point.workshop5_grade = 0;
		student_prf_point.practical_exam_grade = 0;
        student_prf_point.final_exam_grade = 0;
        student_prf_point.average_grade = 0.1* (student_prf_point.assignment_grade)
										+ 0.05 *(student_prf_point.progress_test1_grade + student_prf_point.progress_test1_grade)
										+ 0.02 *(student_prf_point.workshop1_grade + student_prf_point.workshop2_grade + student_prf_point.workshop3_grade+ student_prf_point.workshop4_grade+ student_prf_point.workshop5_grade)
										+ 0.4 * student_prf_point.practical_exam_grade
										+ 0.3 *student_prf_point.final_exam_grade ;
    }

    for (i = 0; i < num_students; i++) {
        if (students[i].index == index_to_change) {
            // student found
            students[i].prf192_data = student_prf_point;
            do {
                printf("Choose grade to enter:\n");
                printf("1. Assignment\n");
                printf("2. Progress test 1\n");
                printf("3. Progress test 2\n");
                printf("4. Workshop 1\n");
                printf("5. Workshop 1\n");
                printf("6. Workshop 1\n");
                printf("7. Workshop 1\n");
                printf("8. Workshop 1\n");
                printf("9. Practical Exam\n");
                printf("10. Final Exam\n");
                printf("11. Exit\n");
                printf("Enter choice (1-11): ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%d", &choice);
                fflush(stdin);
                // continue writing program
				switch (choice) {
				case 1:
					printf("Enter grade for Assignment: ");
					fgets(input, sizeof(input), stdin);
					sscanf(input, "%f", &grade);
					student_prf_point.assignment_grade = grade;
					break;
				case 2:
					printf("Enter grade for Progress test 1: ");
					fgets(input, sizeof(input), stdin);
					sscanf(input, "%f", &grade);
					student_prf_point.progress_test1_grade = grade;
					break;
				case 3:
					printf("Enter grade for Progress test 2: ");
					fgets(input, sizeof(input), stdin);
					sscanf(input, "%f", &grade);
					student_prf_point.progress_test1_grade = grade;
					break;
				case 4:
					printf("Enter grade for Workshop 1: ");
					fgets(input, sizeof(input), stdin);
					sscanf(input, "%f", &grade);
					student_prf_point.workshop1_grade = grade;
					break;
				case 5:
					printf("Enter grade for Workshop 2: ");
					fgets(input, sizeof(input), stdin);
					sscanf(input, "%f", &grade);
					student_prf_point.workshop2_grade = grade;
					break;
				case 6:
					printf("Enter grade for Workshop 3: ");
					fgets(input, sizeof(input), stdin);
					sscanf(input, "%f", &grade);
					student_prf_point.workshop3_grade = grade;
					break;
				case 7:
					printf("Enter grade for Workshop 4: ");
					fgets(input, sizeof(input), stdin);
					sscanf(input, "%f", &grade);
					student_prf_point.workshop4_grade = grade;
					break;
				case 8:
					printf("Enter grade for Workshop 5: ");
					fgets(input, sizeof(input), stdin);
					sscanf(input, "%f", &grade);
					student_prf_point.workshop5_grade = grade;
					break;
				case 9:
					printf("Enter grade for Practical Exam: ");
					fgets(input, sizeof(input), stdin);
					sscanf(input, "%f", &grade);
					student_prf_point.practical_exam_grade = grade;
					break;
				case 10:
					printf("Enter grade for Final Exam: ");
					fgets(input, sizeof(input), stdin);
					sscanf(input, "%f", &grade);
					student_prf_point.final_exam_grade = grade;
					break;
				case 11:
					break;
				default:
					printf("Invalid choice\n");
					break;
					}
				} while (choice != 11);
	// write updated grades to file
    student_prf_point.average_grade = 0.1* (student_prf_point.assignment_grade)
										+ 0.05 *(student_prf_point.progress_test1_grade + student_prf_point.progress_test1_grade)
										+ 0.02 *(student_prf_point.workshop1_grade + student_prf_point.workshop2_grade + student_prf_point.workshop3_grade+ student_prf_point.workshop4_grade+ student_prf_point.workshop5_grade)
										+ 0.4 * student_prf_point.practical_exam_grade
										+ 0.3 *student_prf_point.final_exam_grade ;
	file = fopen(filename, "w");
	if (file == NULL) {
	    printf("Error opening file\n");
	    return;
	}
	    fprintf(file, "Student Name: %s\n", student_prf_point.student_name);
	    fprintf(file, "Assignment: %.2f\n", student_prf_point.assignment_grade);
	    fprintf(file, "Progress test 1: %.2f\n", student_prf_point.progress_test1_grade);
	    fprintf(file, "Progress test 2: %.2f\n", student_prf_point.progress_test2_grade);
	    fprintf(file, "Workshop 1: %.2f\n", student_prf_point.workshop1_grade);
	    fprintf(file, "Workshop 2: %.2f\n", student_prf_point.workshop2_grade);
	    fprintf(file, "Workshop 3: %.2f\n", student_prf_point.workshop3_grade);
	    fprintf(file, "Workshop 4: %.2f\n", student_prf_point.workshop4_grade);
	    fprintf(file, "Workshop 5: %.2f\n", student_prf_point.workshop5_grade);
	    fprintf(file, "Practical Exam: %.2f\n", student_prf_point.practical_exam_grade);
	    fprintf(file, "Final Exam: %.2f\n", student_prf_point.final_exam_grade);
	    fprintf(file, "Average grade: %.2f\n", student_prf_point.average_grade);
	    
	fclose(file);
		}
	}
}




void mae101_process(struct student students[], int num_students, int index_to_change) {
    struct MAE101 student_mae_point;
    char student_name[50], input[50], filename[100];
    int choice, i;
    float grade;
    FILE *file;
    sprintf(filename, "MAE101/ %s.txt", students[index_to_change-1].id); // generate filename based on student name

    // load previous grades from file if it exists
    if (access(filename, F_OK) != -1) {
        file = fopen(filename, "r");
        if (file == NULL) {
            printf("Error opening file\n");
            return;
        }
        
	    fscanf(file, "Student Name: %[^\n]\n", student_mae_point.student_name);
	    fscanf(file, "Assignment 1: %f\n", &student_mae_point.assignment1_grade);
	    fscanf(file, "Assignment 2: %f\n", &student_mae_point.assignment2_grade);
	    fscanf(file, "Assignment 3: %f\n", &student_mae_point.assignment3_grade);
	    fscanf(file, "Progress test 1: %f\n", &student_mae_point.progress_test1_grade);
	    fscanf(file, "Progress test 2: %f\n", &student_mae_point.progress_test2_grade);
	    fscanf(file, "Progress test 3: %f\n", &student_mae_point.progress_test3_grade);
	    fscanf(file, "Final Exam: %f\n", &student_mae_point.final_exam_grade);
	    fscanf(file, "Average grade: %f\n", &student_mae_point.average_grade);
        fclose(file);
    }
    else {
        strcpy(student_mae_point.student_name, students[index_to_change-1].name);
        student_mae_point.assignment1_grade = 0;
        student_mae_point.assignment2_grade = 0;
		student_mae_point.assignment3_grade = 0;
        student_mae_point.progress_test1_grade = 0;
        student_mae_point.progress_test2_grade = 0;
        student_mae_point.progress_test3_grade = 0;
        student_mae_point.final_exam_grade = 0;
        student_mae_point.average_grade = 0.1* (student_mae_point.assignment1_grade + student_mae_point.assignment2_grade+ student_mae_point.assignment3_grade)
										+ 0.1* (student_mae_point.progress_test1_grade+ student_mae_point.progress_test2_grade + student_mae_point.progress_test3_grade)
										+ 0.4 * student_mae_point.final_exam_grade;
    }

    for (i = 0; i < num_students; i++) {
        if (students[i].index == index_to_change) {
            // student found
            students[i].mae101_data = student_mae_point;
            do {
                printf("Choose grade to enter:\n");
                printf("1. Assignment 1\n");
                printf("2. Assignment 2\n");
                printf("3. Assignment 3\n");
                printf("4. Progress test 1\n");
                printf("5. Progress test 2\n");
                printf("6. Progress test 3\n");
                printf("7. Final Exam\n");
                printf("8. Exit\n");
                printf("Enter choice (1-8): ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%d", &choice);
                fflush(stdin);
                // continue writing program
				switch (choice) {
				case 1:
					printf("Enter grade for Assignment 1: ");
					fgets(input, sizeof(input), stdin);
					sscanf(input, "%f", &grade);
					student_mae_point.assignment1_grade = grade;
					break;
				case 2:
					printf("Enter grade for Assignment 2: ");
					fgets(input, sizeof(input), stdin);
					sscanf(input, "%f", &grade);
					student_mae_point.assignment2_grade = grade;
					break;
				case 3:
					printf("Enter grade for Assignment 3: ");
					fgets(input, sizeof(input), stdin);
					sscanf(input, "%f", &grade);
					student_mae_point.assignment3_grade = grade;
					break;
				case 4:
					printf("Enter grade for Progress test 1: ");
					fgets(input, sizeof(input), stdin);
					sscanf(input, "%f", &grade);
					student_mae_point.progress_test1_grade = grade;
					break;
				case 5:
					printf("Enter grade for Progress test 2: ");
					fgets(input, sizeof(input), stdin);
					sscanf(input, "%f", &grade);
					student_mae_point.progress_test2_grade = grade;
					break;
				case 6:
					printf("Enter grade for Progress test 3: ");
					fgets(input, sizeof(input), stdin);
					sscanf(input, "%f", &grade);
					student_mae_point.progress_test3_grade = grade;
					break;
				case 7:
					printf("Enter grade for Final Exam: ");
					fgets(input, sizeof(input), stdin);
					sscanf(input, "%f", &grade);
					student_mae_point.final_exam_grade = grade;
					break;
				case 8:
					break;
				default:
					printf("Invalid choice\n");
					break;
					}
				} while (choice != 8);
	// write updated grades to file
    student_mae_point.average_grade = 0.1* (student_mae_point.assignment1_grade + student_mae_point.assignment2_grade+ student_mae_point.assignment3_grade)
										+ 0.1* (student_mae_point.progress_test1_grade+ student_mae_point.progress_test2_grade + student_mae_point.progress_test3_grade)
										+ 0.4 * student_mae_point.final_exam_grade;
	file = fopen(filename, "w");
	if (file == NULL) {
	    printf("Error opening file\n");
	    return;
	}
    fprintf(file, "Student Name: %s\n", student_mae_point.student_name);
    fprintf(file, "Assignment 1: %.2f\n", student_mae_point.assignment1_grade);
    fprintf(file, "Assignment 2: %.2f\n", student_mae_point.assignment2_grade);
    fprintf(file, "Assignment 3: %.2f\n", student_mae_point.assignment3_grade);
    fprintf(file, "Progress test 1: %.2f\n", student_mae_point.progress_test1_grade);
    fprintf(file, "Progress test 2: %.2f\n", student_mae_point.progress_test2_grade);
    fprintf(file, "Progress test 3: %.2f\n", student_mae_point.progress_test3_grade);
    fprintf(file, "Final Exam: %d.2f\n", student_mae_point.final_exam_grade);
    fprintf(file, "Average grade: %.2f\n", student_mae_point.average_grade);
    
	fclose(file);
		}
	}
}
