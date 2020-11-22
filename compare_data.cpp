#include <iostream>
#include <fstream>
#include "compare_data.h"
string compare_carbo(string username, int gender)
{
	Person_info pinfo(username);
	string carbo_comment;
	double carbo_value = 0;
	double carbo_average;
	for (int i = 0; i < pinfo.numOfDate(); i++) {
		carbo_value += pinfo.getOneDay(i).get_carbo();
	}
	carbo_average = carbo_value / pinfo.numOfDate();

	if (gender == MAN) {
		if (carbo_average > MAN_AVERAGE_CAR)
			carbo_comment = "No More Carbo!";
		else if (carbo_average == MAN_AVERAGE_CAR)
			carbo_comment = "It is Reasonable! GOOD!";
		else if (carbo_average < MAN_AVERAGE_CAR)
			carbo_comment = "Please More Carbo!";
	}
	else if (gender == WOMAN) {
		if (carbo_average > WOMAN_AVERAGE_CAR)
			carbo_comment = "No More Carbo!";
		else if (carbo_average == WOMAN_AVERAGE_CAR)
			carbo_comment = "It is Reasonable! GOOD!";
		else if (carbo_average < WOMAN_AVERAGE_CAR)
			carbo_comment = "Please More Carbo!";
	}
	return carbo_comment;
}
string compare_protein(string username, int gender)
{
	Person_info pinfo(username);
	string protein_comment;
	double protein_value = 0;
	double protein_average;
	for (int i = 0; i < pinfo.numOfDate(); i++) {
		protein_value += pinfo.getOneDay(i).get_protein();
	}
	protein_average = protein_value / pinfo.numOfDate();

	if (gender == MAN) {
		if (protein_average > MAN_AVERAGE_PRO)
			protein_comment = "No More Protein!";
		else if (protein_average == MAN_AVERAGE_PRO)
			protein_comment = "It is Reasonable! GOOD!";
		else if (protein_average < MAN_AVERAGE_PRO)
			protein_comment = "Please More Protein!";
	}
	else if (gender == WOMAN) {
		if (protein_average > WOMAN_AVERAGE_PRO)
			protein_comment = "No More Protein!";
		else if (protein_average == WOMAN_AVERAGE_PRO)
			protein_comment = "It is Reasonable! GOOD!";
		else if (protein_average < WOMAN_AVERAGE_PRO)
			protein_comment = "Please More Protein!";
	}
	return protein_comment;
}
string compare_fat(string username, int gender)
{
	Person_info pinfo(username);
	string fat_comment;
	double fat_value = 0;
	double fat_average;
	for (int i = 0; i < pinfo.numOfDate(); i++) {
		fat_value += pinfo.getOneDay(i).get_fat();
	}
	fat_average = fat_value / pinfo.numOfDate();

	if (gender == MAN) {
		if (fat_average > MAN_AVERAGE_FAT)
			fat_comment = "No More Fat!";
		else if (fat_average == MAN_AVERAGE_FAT)
			fat_comment = "It is Reasonable! GOOD!";
		else if (fat_average < MAN_AVERAGE_FAT)
			fat_comment = "Please More Fat!";
	}
	else if (gender == WOMAN) {
		if (fat_average > WOMAN_AVERAGE_FAT)
			fat_comment = "No More Fat!";
		else if (fat_average == WOMAN_AVERAGE_FAT)
			fat_comment = "It is Reasonable! GOOD!";
		else if (fat_average < WOMAN_AVERAGE_PRO)
			fat_comment = "Please More Fat!";
	}
	return fat_comment;
}
string compare_calorie(string username, int gender)
{
	Person_info pinfo(username);
	string calorie_comment;
	double calorie_value = 0;
	double calorie_average;
	for (int i = 0; i < pinfo.numOfDate(); i++) {
		calorie_value += pinfo.getOneDay(i).get_calorie();
	}
	calorie_average = calorie_value / pinfo.numOfDate();

	if (gender == MAN) {
		if (calorie_average > MAN_AVERAGE_CAL)
			calorie_comment = "No More Calorie!";
		else if (calorie_average == MAN_AVERAGE_CAL)
			calorie_comment = "It is Reasonable! GOOD!";
		else if (calorie_average < MAN_AVERAGE_CAL)
			calorie_comment = "Please More Calorie!";
	}
	else if (gender == WOMAN) {
		if (calorie_average > WOMAN_AVERAGE_CAL)
			calorie_comment = "No More Calorie!";
		else if (calorie_average == WOMAN_AVERAGE_CAL)
			calorie_comment = "It is Reasonable! GOOD!";
		else if (calorie_average < WOMAN_AVERAGE_CAL)
			calorie_comment = "Please More Calorie!";
	}
	return calorie_comment;
}
string compare_recent_carbo(string username, int gender)
{
	Person_info pinfo(username);
	string carbo_comment;
	double recent_carbo = pinfo.getOneDay(pinfo.numOfDate() - 1).get_carbo();
	if (gender == MAN) {
		if (recent_carbo > MAN_AVERAGE_CAR)
			carbo_comment = "Recently, You ate too much carbo!";
		else if (recent_carbo == MAN_AVERAGE_CAR)
			carbo_comment = "It is Reasonable! GOOD!";
		else if (recent_carbo < MAN_AVERAGE_CAR)
			carbo_comment = "Recently, You need to eat More carbo!";
	}
	else if (gender == WOMAN) {
		if (recent_carbo > WOMAN_AVERAGE_CAR)
			carbo_comment = "Recently, You ate too much carbo!";
		else if (recent_carbo == WOMAN_AVERAGE_CAR)
			carbo_comment = "It is Reasonable! GOOD!";
		else if (recent_carbo < WOMAN_AVERAGE_CAR)
			carbo_comment = "Recently, You need to eat More carbo!";
	}
	return carbo_comment;
}
string compare_recent_protein(string username, int gender)
{
	Person_info pinfo(username);
	string protein_comment;
	double recent_protein = pinfo.getOneDay(pinfo.numOfDate() - 1).get_protein();
	if (gender == MAN) {
		if (recent_protein > MAN_AVERAGE_PRO)
			protein_comment = "Recently, You ate too much protein!";
		else if (recent_protein == MAN_AVERAGE_PRO)
			protein_comment = "It is Reasonable! GOOD!";
		else if (recent_protein < MAN_AVERAGE_PRO)
			protein_comment = "Recently, You need to eat More protein!";
	}
	else if (gender == WOMAN) {
		if (recent_protein > WOMAN_AVERAGE_PRO)
			protein_comment = "Recently, You ate too much carbo!";
		else if (recent_protein == WOMAN_AVERAGE_PRO)
			protein_comment = "It is Reasonable! GOOD!";
		else if (recent_protein < WOMAN_AVERAGE_PRO)
			protein_comment = "Recently, You need to eat More protein!";
	}
	return protein_comment;
}
string compare_recent_fat(string username, int gender)
{
	Person_info pinfo(username);
	string fat_comment;
	double recent_fat = pinfo.getOneDay(pinfo.numOfDate() - 1).get_fat();
	if (gender == MAN) {
		if (recent_fat > MAN_AVERAGE_FAT)
			fat_comment = "Recently, You ate too much fat!";
		else if (recent_fat == MAN_AVERAGE_FAT)
			fat_comment = "It is Reasonable! GOOD!";
		else if (recent_fat < MAN_AVERAGE_FAT)
			fat_comment = "Recently, You need to eat More fat!";
	}
	else if (gender == WOMAN) {
		if (recent_fat > WOMAN_AVERAGE_FAT)
			fat_comment = "Recently, You ate too much fat!";
		else if (recent_fat == WOMAN_AVERAGE_FAT)
			fat_comment = "It is Reasonable! GOOD!";
		else if (recent_fat < WOMAN_AVERAGE_FAT)
			fat_comment = "Recently, You need to eat More fat!";
	}
	return fat_comment;
}
string compare_recent_calorie(string username, int gender)
{
	Person_info pinfo(username);
	string calorie_comment;
	double recent_calorie = pinfo.getOneDay(pinfo.numOfDate() - 1).get_calorie();
	if (gender == MAN) {
		if (recent_calorie > MAN_AVERAGE_CAL)
			calorie_comment = "Recently, You ate too much calorie!";
		else if (recent_calorie == MAN_AVERAGE_CAL)
			calorie_comment = "It is Reasonable! GOOD!";
		else if (recent_calorie < MAN_AVERAGE_CAL)
			calorie_comment = "Recently, You need to eat More calorie!";
	}
	else if (gender == WOMAN) {
		if (recent_calorie > WOMAN_AVERAGE_CAL)
			calorie_comment = "Recently, You ate too much calorie!";
		else if (recent_calorie == WOMAN_AVERAGE_CAL)
			calorie_comment = "It is Reasonable! GOOD!";
		else if (recent_calorie < WOMAN_AVERAGE_CAL)
			calorie_comment = "Recently, You need to eat More calorie!";
	}
	return calorie_comment;
}