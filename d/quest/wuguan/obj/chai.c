//Cracked by Roath
//chai.c ��

inherit ITEM;

void create()
{
        set_name( "��", ({"chai"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", 
"����һ�������Ĳ�𣬿���ȥ�������ˮƽ�����ߣ��������ëë�ڲڡ�\n");
		set("value", 0);
		set("material", "wood");
	}
	setup();
}

