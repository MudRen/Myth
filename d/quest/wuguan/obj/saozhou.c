//Cracked by Roath
//saozhou.c ɨ��

inherit ITEM;

void create()
{
        set_name( "ɨ��", ({ "sao zhou"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ��ɨ���õĴ�ɨ�㣬ͺͺ��ɨ��ͷ�����������ɨ�����Ͼ�Ҫ�������ˡ�\n");
		set("value", 0);
		set("material", "wood");
	}
	setup();
}

