// created by angell 1/1/2001
// room: /d/qujing/huangfeng/obj/yutou

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("��ͷ", ({"yu tou","yutou"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "һ�����ͷ��\n");
                set("unit", "��");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
