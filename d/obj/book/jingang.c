//Cracked by Roath
// jingang.c

inherit ITEM;

void create()
{
	set_name("����վ���", ({"jingang", "jing", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	set("long",
"��հ��������۾����Ƿ�ҵ��Ӳ��������ž��顣\n");
        set("material", "paper");
        set("value", 1000);
        set("skill", ([
			"name": "buddhism",
                        "dx_required": 1000,
                        "sen_cost": 30,
                        "difficulty": 30,
			"max_skill": 40,
]) );
        }
}

