// monster.c

#include <race/monster.h>

void setup_monster(object ob)
{
	mapping my;

	my = ob->query_entire_dbase();

	my["unit"] = "ֻ";
	
	if( undefinedp(my["gender"]) ) my["gender"] = "����";
	if( undefinedp(my["age"]) ) my["age"] = random(80) + 5;

	if( undefinedp(my["str"]) ) my["str"] = random(41) + 10;
	if( undefinedp(my["int"]) ) my["int"] = random(41) + 10;
	if( undefinedp(my["per"]) ) my["per"] = random(11) + 10;
	if( undefinedp(my["con"]) ) my["con"] = random(41) + 10;

	if( undefinedp(my["max_gin"]) ) {
		if( my["age"] <= 3 ) my["max_gin"] = 50;
		else if( my["age"] <= 10 ) my["max_gin"] = 50 + (my["age"] - 3) * 30;
		else if( my["age"] <= 60 ) my["max_gin"] = 260 + (my["age"] - 10) * 5;
		else my["max_gin"] = my["max_gin"] = 510 + (my["age"] - 60);
	}
	if( undefinedp(my["max_kee"]) ) {
                if( my["age"] <= 10 ) my["max_kee"] = 200;
                else if( my["age"] <= 30 ) my["max_kee"] = 200 + (my["age"] - 10) * 40;
                else my["max_kee"] = my["max_kee"] = 1000 + (my["age"] - 30) * 15;
	}
	if( undefinedp(my["max_sen"]) ) {
                if( my["age"] <= 30 ) my["max_sen"] = 100;
                else my["max_sen"] = 100 + (my["age"] - 30) * 15;
	}

	//	NOTE: monster has no initial limbs defined, you must define it yourself.
	//	ob->init_limbs(LIMBS);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 2000);
}

