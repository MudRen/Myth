//Cracked by Roath
// pa_book.c

inherit ITEM;

void create()
{
        set_name("�����ؾ���", ({"parry book", "book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 600);
		set("long", "һ��С���ӣ�����ЩС�˱������ʽ��\n");
        set("material", "paper");
        set("skill", ([
    			"name": "parry",
			"exp_required": 5000,
			"sen_cost": 20,
			"difficulty": 25,
			"max_skill": 60,
]) );
        }
}

