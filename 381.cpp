#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

enum grade {
    A = 4,
    B = 3,
    C = 2,
    D = 1,
    F = 0
};

typedef struct _student {
    int number_of_tests;
    int grades[10];
    int bonus;
    int absences;
    double average;
    grade final_grade;
} student;

student students[30];

void drop_students_lowest_grade(int number_of_students, int number_of_tests) {
    if (number_of_tests < 3)
        return;

    rep (i, number_of_students) {
        sort(students[i].grades, students[i].grades + number_of_tests, greater<int>());
        students[i].number_of_tests--;
    }
}

void compute_students_averages(int number_of_students) {
    rep (i, number_of_students) {
        double sum = 0;

        rep (j, students[i].number_of_tests) {
            sum += students[i].grades[j];
        }

        students[i].average = sum / students[i].number_of_tests;
    }
}

double compute_class_mean(int number_of_students) {
    double sum = 0;

    rep (i, number_of_students) {
        sum += students[i].average;
    }

    return sum / number_of_students;
}

double computer_class_standard_deviation(int number_of_students, double class_mean) {
    double sum = 0;

    rep (i, number_of_students) {
        sum += (students[i].average - class_mean) * (students[i].average - class_mean);
    }

    return sqrt(sum / number_of_students);
}

void adjust_students_averages(int number_of_students) {
    rep (i, number_of_students) {
        int increase = (students[i].bonus / 2) * 3;

        students[i].average += increase;
    }
}

void determine_students_unadjusted_grades(int number_of_students, double class_mean, double class_sd) {
    rep (i, number_of_students) {
        if (students[i].average >= class_mean + class_sd) {
            students[i].final_grade = A;
        } else if (students[i].average >= class_mean) {
            students[i].final_grade = B;
        } else if (students[i].average >= class_mean - class_sd) {
            students[i].final_grade = C;
        } else {
            students[i].final_grade = D;
        }
    }
}

void increase_final_grade(student &s) {
    switch (s.final_grade) {
        case B:
            s.final_grade = A;
            break;
        case C:
            s.final_grade = B;
            break;
        case D:
            s.final_grade = C;
            break;
        case F:
            s.final_grade = D;
            break;
        default:
            break;
    }
}

void decrease_final_grade(student &s) {
    switch (s.final_grade) {
        case A:
            s.final_grade = B;
            break;
        case B:
            s.final_grade = C;
            break;
        case C:
            s.final_grade = D;
            break;
        case D:
            s.final_grade = F;
            break;
        default:
            break;
    }
}

void adjust_grades_based_on_attendance(int number_of_students) {
    rep (i, number_of_students) {
        if (students[i].absences == 0) {
            increase_final_grade(students[i]);
        } else {
            int decreases = students[i].absences / 4;

            rep (j, decreases) {
                decrease_final_grade(students[i]);
            }
        }
    }
}

double count_average_grade_point_of_class(int number_of_students) {
    double sum = 0;

    rep (i, number_of_students) {
        sum += int(students[i].final_grade);
    }

    return sum / number_of_students;
}

int main(void) {
    int n, s, t;

    cin >> n;

    cout << "MAKING THE GRADE OUTPUT" << endl;

    while (n--) {
        cin >> s >> t;

        rep (i, s) {
            students[i].number_of_tests = t;

            rep (j, t) {
                cin >> students[i].grades[j];
            }

            cin >> students[i].bonus;
            cin >> students[i].absences;
        }

        drop_students_lowest_grade(s, t);
        compute_students_averages(s);
        double class_mean = compute_class_mean(s);
        double class_sd = computer_class_standard_deviation(s, class_mean);
        adjust_students_averages(s);
        determine_students_unadjusted_grades(s, class_mean, class_sd);
        adjust_grades_based_on_attendance(s);

        cout << fixed << setprecision(1) << count_average_grade_point_of_class(s) << endl;
    }

    cout << "END OF OUTPUT" << endl;

    return 0;
}
