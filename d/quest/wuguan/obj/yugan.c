//Cracked by Roath
//yugan.c ���



inherit ITEM;



void create()

{

        set_name( "���", ({ "yu gan" , "gan"}));

	set_weight(4000);

	if( clonep() )

		set_default_object(__FILE__);

	else {

		set("unit", "��");

                set("long", "����һ����ͨ�����,����������ϸ��Ҳ��֪�����������ܲ��ܵ����㡣\n");

		set("value", 0);

		set("material", "wood");

	}

	setup();

}



