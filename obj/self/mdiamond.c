/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
//Last modified by waiwai@2002/12/05

#include <armor.h>

inherit OTHERS;

void create()
{
	set_name(HIW "��֮��ʯ" NOR, ({ "magic diamond" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIW "һ�Ż���������Ĺ�ʵ���ʯ��"
                    "�����Բ�ͬѰ���ĸо���\n" NOR);
                set("value", 200000);
		set("unit", "��");
                set("can_be_enchased", 1);
                set("magic/type", "lighting");
                set("magic/power", 150);
	}
        setup();
}
