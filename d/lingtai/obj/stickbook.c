// literate.c

inherit ITEM;

void create()
{
        set_name("������Ҫ", ({"stick book", "book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
	set("long", "һ��һ�߼�����Ⱦ����ǰ����Щ����������ͼ�⣮\n");
        set("material", "paper");
        set("skill", ([
                        "name": "literate",
                        "exp_required": 1000,
                        "sen_cost": 20,
                        "difficulty": 20,
                        "max_skill": 30,
]) );
        }
}

