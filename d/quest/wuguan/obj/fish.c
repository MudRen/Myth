//Cracked by Roath
//fish.c ��

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(CYN "����"NOR, ({ "li yu","yu","fish"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", 
"����һ����ɫ������,����������û�ж����⣬�������Ҳ\n
��֪�������������������������ԡ�\n");
		set("value", 0);
	}
	setup();
}

