#include <stdio.h>
#define STUDENT_NUMBER  10 // 学生数量
#define COURSE_NUMBER 8 //课程数量
#define STRING_LENGTH 12 //字符串最大长度
int main()
{
    char stu_name[STUDENT_NUMBER][STRING_LENGTH]; // 存放学习姓名
    char course_name[COURSE_NUMBER][STRING_LENGTH]; // 课程名称
    double score[STUDENT_NUMBER][COURSE_NUMBER];    // 学生分数
    double stu_sum[STUDENT_NUMBER]; // 每个学生的总分
    double course_total[COURSE_NUMBER]; //每门课程的总分
    double stu_avg[STUDENT_NUMBER];     //学生平均分
    double course_avg[COURSE_NUMBER]; // 课程平均分
    double sum = 0;
    int i, j;
    for (i = 0; i < COURSE_NUMBER; i++)
    {
        printf("请输入第%d门课程名称: \n", (i + 1));
        scanf("%s", course_name[i]);
    }
    
    // 学生姓名及其成绩输入
    for (i = 0; i < STUDENT_NUMBER; i++)
    {
        printf("请输入第%d名同学的姓名: \n", (i + 1));
        scanf("%s", stu_name[i]);
        stu_sum[i] = 0;
        stu_avg[i] = 0;
        
         for (j = 0; j < COURSE_NUMBER; j++)
        {
            
            printf("请输入%s的%s成绩：", stu_name[i], course_name[j]);
            scanf("%lf", &score[i][j]);
            stu_sum[i] += score[i][j]; //累计某个学生的成绩
            course_total[j] += score[i][j]; // 累计某门课程的分数
        }
        stu_avg[i] = (stu_sum[i] / COURSE_NUMBER); // 求某个学生的平均分
    }

    // 输出展示
    //表头展示
    printf("%-12s", "姓名");
    for (i = 0; i < COURSE_NUMBER; i++)
    {
        printf("%-12s", course_name[i]);
    }
    printf("%-12s", "总分");
    printf("%-12s", "平均分");
    printf("\n");
    // 学生成绩展示
    for (i = 0; i < STUDENT_NUMBER; i++)
    {
        printf("%-12s", stu_name[i]);
        for (j = 0; j < COURSE_NUMBER; j++)
        {
            printf("%-12.0lf", score[i][j]);
        }
        printf("%-12.0lf", stu_sum[i]);
        printf("%-12.0lf", stu_avg[i]);
        printf("\n");
    }
    // 末行统计展示
    printf("%-12s", "");
    for (j = 0; j < COURSE_NUMBER; j++)
    {
        course_avg[j] = course_total[j] / STUDENT_NUMBER;
        sum += course_avg[j];
        printf("%-12.0lf", course_avg[j]);
    }
    printf("%-12s", "");
    printf("%-12.0lf", (sum / COURSE_NUMBER));
    printf("\n");
    return 0;
}