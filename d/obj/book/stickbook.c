//Cracked by Roath
// literate.c

inherit ITEM;

void create()
{
        set_name("�鲼ͷ", ({"piece", "book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 600);
	set("long", "һ��һ�߼�����Ⱦ����ǰ����Щ����������ͼ�⣮\n");
        set("material", "paper");
        set("skill", ([
                        "name": "stick",
                        "exp_required": 1000,
                        "sen_cost": 20,
                        "difficulty": 20,
                        "max_skill": 30,
]) );
        }
}

