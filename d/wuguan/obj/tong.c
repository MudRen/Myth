//Cracked by Roath
// tong.c ˮͰ
// by yfengf

inherit ITEM;

void create()
{
        set_name( "ˮͰ", ({"shui tong","tong"}));
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", 
"����һ����ˮ��Ͱ��\n");
		set("value", 5000);
		set("material", "wood");
	}
	setup();
}

