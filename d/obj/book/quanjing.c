//Cracked by Roath
// literate.c

inherit ITEM;

void create()
{
        set_name("��ȭ����", ({"quan jing", "jing", "book"}));
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("value", 600);
	set("long", "һ�������ĵ�С���ӣ�����Щ�ַ���
��עС�֣�����ƽ�ݴ�\n");
        set("material", "paper");
        set("skill", ([
                        "name": "unarmed",
                        "exp_required": 300,
                        "sen_cost": 25,
                        "difficulty": 25,
                        "max_skill": 50,
]) );
        }
}

