// Room: jiaoli.c
// AceP
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED "������" NOR, ({"jiaozi", "jiao"}));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ��Ư���Ļ��Σ����Ķ��Ӳ����ţ��Ľ����Ŵ�컨���ĸ����Ӷ��òʴ����š�\n"
"����ǰ��ĸ����Ϳ��Խ�ȥ����Ȼ��ֻ�д��޵������Ӳ������⻨�Ρ�\n");
		set("unit", "��");
		set("value", 3000);
		set("no_drop", "�������������뿪�㡣\n");
		set("no_get", "�������������뿪�Ƕ���\n");
	}

	setup();
}
