// �϶� 

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�ƽ����Ĳ϶�", ({"jiu dou", "dou"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "һ����ҩ�ƽ����Ĳ϶�����˵�����ر�ϲ���ԡ�\n");
                set("unit", "��");
		set("value", 20000);
		set("food_remaining", 1);
		set("food_supply", 1);
	}
}
