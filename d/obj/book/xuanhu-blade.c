// literate.c

inherit ITEM;

void create()
{
        set_name("���������޵�����", ({"xuanhu book", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("value", 0);
		set("no_sell", 1);
		set("no_put", 1);
	set("long","һ���������޵����Ļ��ᡣ\n");
        set("material", "paper");
        set("skill", ([
                        "name": "xuanhu-blade",
                        "exp_required": 100000,
                        "sen_cost": 40,
                        "difficulty": 40,
                        "max_skill": 200,
]) );
        }
}

