//Cracked by Roath
//mabu.c Ĩ��



inherit ITEM;



void create()

{

        set_name( "Ĩ��", ({ "ma bu"}));

	set_weight(2000);

	if( clonep() )

		set_default_object(__FILE__);

	else 

	{

		set("unit", "��");

        set("long", 

		"����һ��Ĩ��,������������ɫ�ģ����������Ѿ�ϴ�÷����ˡ�\n");

		set("value",0);

	}

	setup();

}



