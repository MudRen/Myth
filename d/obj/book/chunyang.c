//Cracked by Roath
//chunyang.c

inherit ITEM;

void create()
{
	set_name("�������ĵá�", ({"chunyang xinde","xinde","book", "shu"}));
	set_weight(1000);
	if( clonep() ) 
		set_default_object(__FILE__);
	else 
	{
		set("unit", "��");
		set("long", "һ��С���ӡ��������ɷ���Ĵ��֡������ĵá��»���һ��С�֣�����������\n");
		set("material", "paper");
		set("value", 1000);
		set("skill", ([
			"name": "taiyi",
			"dx_required": 1000,
			"sen_cost": 40,
			"difficulty": 30,
			"max_skill": 40,
		]) );
	}
}

