#include <ios>
#include <iostream>
#include <string.h>
using namespace std;

struct SubjectClassNode{
    long subjectClassID;
    long subjectID;
    int semester;
    float processWeight;    //trong so qua trinh
    float finalWeight;      // trong so cuoi ki
    float processScore;     // diem qua trinh 
    float finalScore;       // diem cuoi ki 
    int subjectWeight;    // so tin hoc phan 
    float subjectScore;
    SubjectClassNode* next;
};

struct StudentNode{
    long studentID;
    char name[100];
    char classID[20];
    SubjectClassNode* subjectClasses;  // danh sach lop hoc phan
    StudentNode* next;
};

// tao 1 phan tu lop hoc moi
SubjectClassNode* createSubjectClassNode(long subjectClassID, long subjectID, int semester, float processWeight, float finalWeight, float processScore, float finalScore, int subjectWeight){
    SubjectClassNode* newSubjectClassNode = new SubjectClassNode;
    newSubjectClassNode->subjectClassID = subjectClassID;
    newSubjectClassNode->subjectID = subjectID;
    newSubjectClassNode->semester = semester;
    newSubjectClassNode->processWeight = processWeight;
    newSubjectClassNode->finalWeight = finalWeight;
    newSubjectClassNode->processScore = processScore;
    newSubjectClassNode->finalScore = finalScore;
    newSubjectClassNode->subjectWeight = subjectWeight;
    newSubjectClassNode->next = NULL;
    return newSubjectClassNode;
}
// them phan tu lop hoc moi vao danh sach hoc phan cua sinh vien (them vao cuoi danh sach)
void addSubjectClassNode(StudentNode* &student, SubjectClassNode* subjectClass){
    subjectClass->next = NULL;
    if(student->subjectClasses == NULL){ // neu danh sach hien tai rong
        student->subjectClasses =  subjectClass; //gan subjectClass vao dau danh sach 
    }
    else {
        //duyet danh sach den phan tu cuoi cung
        SubjectClassNode* temp = student->subjectClasses;
        while (temp->next != NULL) {
           temp = temp->next; 
        }
        temp->next = subjectClass;
    }
}


// tao 1 phan tu sinh vien moi 
StudentNode* createStudent(long studentID, char* name, char* classID){
    StudentNode* newStudentNode = new StudentNode;
    newStudentNode->studentID = studentID;
    //sao chep chuoi 'name' vao name cua node
    strncpy(newStudentNode->name, name, sizeof(newStudentNode->name)-1);
    newStudentNode->name[sizeof(newStudentNode->name)-1] = '\0'; // dam bao chuoi duoc ket thuc dung
    strncpy(newStudentNode->classID, classID, sizeof(newStudentNode->classID)-1);
    newStudentNode->classID[sizeof(newStudentNode->classID)-1] = '\0'; // dam bao chuoi duoc ket thuc dung
    
    return newStudentNode;
}
// them 1 sinh vien vao danh sach sinh vien (them vao cuoi danh sach)
void addStudent(StudentNode* &studentList, StudentNode* student){
    if(studentList == NULL){
        studentList = student;
        student->next = NULL;
        return;
    }
    else {
        StudentNode* temp = studentList;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        student->next = NULL;
        temp->next = student;
        return;
    }
}
// tinh diem CPA 
float calculateCPA(StudentNode* student){
    if((student == NULL)||(student->subjectClasses == NULL)){
        cout << "Khong co sinh vien nay, hoac sinh vien nay khong co mon hoc nao\n";
        return 0;
    }
    float CPA = 0;
    float sum_subjectScore = 0;
    int sum_subjectWeight = 0;
    SubjectClassNode* temp = student->subjectClasses;
    while(temp != NULL){
        temp->subjectScore = temp->processScore * temp->processWeight + temp->finalScore * temp->finalWeight;
        sum_subjectWeight = sum_subjectWeight + temp->subjectWeight;
        sum_subjectScore = sum_subjectScore + temp->subjectScore * temp->subjectWeight;
        temp = temp->next;
    }
    if(sum_subjectWeight == 0){
        cout << "Khong co tin chi de tinh CPA\n";
    }
    CPA = sum_subjectScore / sum_subjectWeight;
    return CPA;
}


int main(){
    StudentNode* studentList = NULL;
    StudentNode* student1 = createStudent(20213977, "Nguyen Kien", "148563");
    addStudent(studentList, student1);

    SubjectClassNode* subject1 = createSubjectClassNode(148563, 2200, 20241, 0.3, 0.7, 9, 7, 2);
    addSubjectClassNode(student1, subject1);
    float CPA = calculateCPA(student1);
    cout << " CPA cua sinh vien: " << CPA << endl;

}
