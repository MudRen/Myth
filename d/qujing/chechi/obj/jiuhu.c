// by snowcat oct 24 1997

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("�ƺ�", ({"jiuhu", "hu"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��װ�а��վƵľƺ���\n");
		set("unit", "��");
		set("value", 250);
		set("max_liquid", 12);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "���վ�",
		"remaining": 12,
		"drunk_apply": 20,
	]));
}
