//Created by waiwai@2001/03/23
//��֮����(springA-rain)
// [1;31m���ļ���ֹ���ĺ��ƶ�[0m

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIG "��֮����" NOR, ({ "summerA rain", "summerA", "rain" }) );
	set_weight( 100 );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�ξ�Ө����֮���ص���Ρ�\n");
		set("value", 100);
		set("can_auction", 1);
		set("des", 1); // dropʱ��ʧ��־
		set("material", "water");//ˮ�������־
    };
	// dropʱ���ض������Ϣ
	set_temp("drop_msg", this_object()->query("name")+CYN" �����ţ���ʧ�ڿ����в����ˡ�����\n"NOR);

	setup();
}

