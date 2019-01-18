//Cracked by Roath
//wulongtea.c ������
//by yfengf

#include <ansi.h>

inherit ITEM;

void init();
void do_eat();

void create()
{
	set_name(YEL"������"NOR,({"wulong tea","wulong cha","tea", "cha"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", 
"����һ���ϺõĶ�����������ÿ�ι�����������õġ�");
		set("unit", "��");
        set("value", 1);
        set("drink_supply", 35);
    }
	
	setup();
}

void init()
{
	add_action("do_drink", "drink");
}


int do_drink(string arg)
{
	if( !this_object()->id(arg) ) 
		return 0;
	if( this_player()->is_busy() )
        	return notify_fail("����һ��������û����ɡ�\n");
    	if((int)this_player()->query("water")>= (int)this_player()->max_water_capacity() )
		return notify_fail("���Ѿ���̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");
	if( this_player()->is_fighting() )
		return notify_fail("����ר�Ĵ�ܣ��������ٺȲ�Ҳ���١�\n");

	set("value", 0); //��ȹ����Ͳ�ֵǮ�ˡ�
    	this_player()->add("water", (int)query("drink_supply"));
	this_player()->start_busy(1);
	add("remaining", -1);
	if ( query("remaining") )
	{
		message_vision("$N����"+YEL"������"NOR+"��������ζ��Ʒ�˼��ڡ�\n"+
      		"һ������ֱ����Ƣ��$N���þ���ö��ˡ�\n", this_player());
	}
	else 
	{ 
		message_vision("$N�����С������ʣ�µ�"+YEL"������"NOR+"һ��������\n"+
      		"һ������ֱ����Ƣ��$N���þ���ö��ˡ�\n", this_player());
		destruct(this_object());
	}
	return 1;
}
