//Last modified by waiwai@2002/12/05

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(BLINK HIY "����" NOR, ({ "star", "xingxing" }) );
	set_weight(30);
	if( clonep() )
		set_default_object(__FILE__);
        else {
	        set("long", HIW "�������ժ����һ�����ǣ���ɲ����ý�Ǯ��"
                            "�����ģ���ôҲ����һ�����Ⱒ��\n" NOR);
               set("value", 1);
		set("can_auction", 1);
		 set("unit", "��");
	}
        setup();
}
