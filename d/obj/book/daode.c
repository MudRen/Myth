//Cracked by Roath
// literate.c

inherit ITEM;

void create()
{
        set_name("�����¾���", ({"daodejing", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("material", "paper");
	set("value", 100);
	set("long", "���Ҿ��䣭�����¾�");
        set("skill", ([
                        "name": "spells",
                        "dx_required": 2000,
                        "sen_cost": 25,
                        "difficulty": 25,
                        "max_skill": 50,
]) );
        }
}

