//Cracked by Roath
// literate.c

inherit ITEM;

void create()
{
        set_name("��ȭ�����š�", ({"unarmed book", "book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "��ȭ�����š�\n");
		set("value", 1000);
        set("material", "paper");
        set("skill", ([
                        "name": "unarmed",
                        "exp_required": 100,
                        "sen_cost": 20,
                        "difficulty": 20,
                        "max_skill": 20,
]) );
        }
}

