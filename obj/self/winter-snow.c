//Created by waiwai@2001/03/23
//��Өѩ��(winter-snow)
// [1;31m���ļ���ֹ���ĺ��ƶ�[0m

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "��Өѩ��" NOR, ({ "winter snow", "winter", "snow" }) );
	set_weight( 100 );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "Ƭ");
		set("long", "����һƬ��Ө��ѩ�����Ƕ����ľ��顣\n");
		set("value", 100);
		set("can_auction", 1);
		set("des", 1); // dropʱ��ʧ��־
		set("material", "ice");//��ˮ�������־
    };
	// dropʱ���ض������Ϣ
	set_temp("drop_msg", this_object()->query("name")+CYN" �����ţ���ʧ�ڿ����в����ˡ�����\n"NOR);

	setup();
}

