//Created by waiwai@2002/12/05
//343�������ɫ���֮��

#include <ansi.h>

inherit ITEM;

void create()
{
	string *colors = ({ HIW, HIR, HIY, HIC, HIM, HIG, HIB });
	set_name(colors[random(sizeof(colors))]+"��"+colors[random(sizeof(colors))]+
"��"+colors[random(sizeof(colors))]+"ʯ"NOR, ({ "yuhua stone", "stone" }) );
	set_weight(500);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	set("long", "һ��ɫ�ʰ�쵵�Сʯ�ӣ�ÿһ�����ƺ��ڽ�����һ�����¡�\n");
	set("unit", "��");
	set("value", 5000);
//	set("no_sell", 1);
	}
}

