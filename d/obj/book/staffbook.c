//Cracked by Roath
// literate.c

inherit ITEM;

void create()
{
        set_name("���ȷ���Ҫ��", ({"staff book", "book"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 2000);
		set("no_sell", 1);
        set("long", "һ��������С���ӣ�����Щ�ȷ���ͼ�⣮\n");
        set("material", "paper");
        set("skill", ([
                        "name": "staff",
                        "exp_required": 5000,
                        "sen_cost": 25,
                        "difficulty": 25,
                        "max_skill": 60,
]) );
        }
}


