// human.c

// A normal human is at least 40 kg weight
#define BASE_WEIGHT 40000

inherit F_DBASE;

mapping *combat_action = ({
	([	"action":		"$N��ȭ����$n��$l",
		"damage_type":	"����",
	]),
	([	"action":		"$N��$n��$lһץ",
		"damage_type":	"ץ��",
	]),
	([	"action":		"$N��$n��$l�ݺݵ�����һ��",
		"damage_type":	"����",
	]),
	([	"action":		"$N����ȭͷ��$n��$l��ȥ",
		"damage_type":	"����",
	]),
	([	"action":		"$N��׼$n��$l�����ӳ�һȭ",
		"damage_type":	"����",
	]),
});

void create()
{
	seteuid(getuid());
}

void setup_human(object ob)
{
	mapping my;
	int  qi, shen;

	my = ob->query_entire_dbase();

	ob->set("default_actions", (: call_other, __FILE__, "query_action" :));
	
	if( undefinedp(my["age"]) ) my["age"] = random(30) + 15;

	if( undefinedp(my["str"]) ) my["str"] = random(21) + 10;
	if( undefinedp(my["cor"]) ) my["cor"] = random(21) + 10;
	if( undefinedp(my["int"]) ) my["int"] = random(21) + 10;
	if( undefinedp(my["spi"]) ) my["spi"] = random(21) + 10;
	if( undefinedp(my["cps"]) ) my["cps"] = random(21) + 10;
	if( undefinedp(my["per"]) ) my["per"] = random(21) + 10;
	if( undefinedp(my["con"]) ) my["con"] = random(21) + 10;
	if( undefinedp(my["kar"]) ) my["kar"] = random(21) + 10;

/*
		if( ob->query("guild") == "fighter" )  {
		   qi = my["con"] + my["con"] / 2;
		   shen = my["spi"] - my["spi"] / 2;
		}
		else if( ob->query("guild") == "magician" )  {
		   qi = my["con"] - my["con"] / 2;
		   shen = my["spi"] + my["spi"] / 2;
		}
		else  {
		   qi = my["con"];
		   shen = my["spi"];
		}
*/

		qi= (my["con"]+my["str"])/2;
		shen= (my["spi"]+my["int"])/2;

	if( userp(ob) || undefinedp(my["max_gin"]) ) {
		if( my["age"] <= 14 ) my["max_gin"] = 100;
		else if( my["age"] <= 30 ) my["max_gin"] = 100 + (my["age"] - 14) * my["spi"];
		else if( my["age"] <= 50 ) my["max_gin"] = 100 + 16 * my["spi"];
		else my["max_gin"] = 100 + 16 * my["spi"]  - (my["age"] - 50) * 5;
		if( my["max_atman"] > 1000 ) my["max_gin"] += 250;
		//here max_atman>1000 is no use.
		else if( my["max_atman"] > 0 ) my["max_gin"] += my["max_atman"] / 4;
		if(my["max_gin"]<1) my["max_gin"]=1;//mon 1/28/98
	}
	if( userp(ob) || undefinedp(my["max_kee"]) ) {
		if( my["age"] <= 14 ) my["max_kee"] = 10*qi;
		else if( my["age"] <= 30 ) my["max_kee"] = (my["age"] - 4) * qi;
		else my["max_kee"] = 26 * qi; 
		if( my["max_force"] > 0 ) my["max_kee"] += my["max_force"] / 4;

		if(my["max_kee"]<1) my["max_kee"]=1;//mon 1/28/98
	}
	if( userp(ob) || undefinedp(my["max_sen"]) ) {
		if( my["age"] <= 14 ) my["max_sen"] = 10*shen;
		else if( my["age"] <= 30 ) my["max_sen"] = (my["age"] - 4) *
		shen;
		else if( my["age"] <= 40 ) my["max_sen"] = 26 * shen;
		else {
		//when age>40, max_sen will drop...but if you have
		//"always_young"(defined in "look.c"), only drop 
		//to atmost your "faked_age"...weiqi,062897.
			if( my["always_young"] ){
			   if( my["fake_age"] <= 40 )
			      my["max_sen"] = 26 * shen;
			   else 
			      my["max_sen"] = 26 * shen - (my["fake_age"]
- 40) * 5;
			}
			else 
			      my["max_sen"] = 26 * shen -
			      (my["age"] - 40) * 5;
		}	
		if( my["max_mana"] > 0 ) my["max_sen"] += my["max_mana"]/4;
		if(my["max_sen"]<1) my["max_sen"]=1;//mon 1/28/98
	}

	if( undefinedp(my["unit"])) my["unit"]="λ";
	if( undefinedp(my["gender"])) my["gender"]="����";
	if( undefinedp(my["can_speak"])) my["can_speak"]=1;
	if( undefinedp(my["attitude"])) my["attitude"]="peaceful";
	if( undefinedp(my["limbs"])) my["limbs"]=({
		"ͷ��",	"����",	"�ؿ�",	"����",	"���",	"�Ҽ�",	"���",
		"�ұ�",	"����",	"����",	"����",	"С��",	"����",	"����",
		"���",	"�ҽ�"
	}) ;

//	ob->set_default_object(__FILE__);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 2000);
}

mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}
