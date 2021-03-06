#include "gtest/gtest.h"
#include<random>
#include<string>
#include "Student.h"
#include "Deanery.h"
#include "Group.h"


//task1 ON/OFF
TEST(lab5,task1_1)
{
	setlocale(LC_ALL, "rus");
	Student a(38, "Безухов Владимир Алексеевич");

	Group H("New");
	random_device ran;
	for (int i = 0; i < 5; i++)
	{
		a.AddMark(ran() % 10 + 1);
	}
	a.AverageMark();
	H.AddStudent(&a, &H);
	H.AverageInGroup();
	H.HeadElection();
}

TEST(lab5,task1_2)
{
	setlocale(LC_ALL, "rus");
	Deanery dean;
	for (int i = 0; i < 30; i++)
	{
		dean.CreateStudentsFromFile();
	}
	for (int j = 0; j < 3; j++)
	{
		dean.CreateGroupsFromFile();
	}
	for (int k = 0; k < 5; k++)
	{
		dean.AddMarks();
	}
	dean.ChooseHeads();
	dean.StudentDeduction();
	dean.GetStatistic("12");
	dean.StudentTransferToGroup(12, "ПМИ");
	dean.GetStatistic("12");
	dean.GetStatistic("ПМИ");
	dean.SaveDataInFiles();
}
