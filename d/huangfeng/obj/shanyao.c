// created by angell 1/1/2001
// room: /d/qujing/huangfeng/obj/shanyao.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("ɽҩ", ({"shan yao", "yao"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
                set("long", "Ұ����ɽҩ��������ζ������\n");
                set("unit", "��");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
