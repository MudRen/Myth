// yunnandrug.c ���ϰ�ҩ

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("���ϰ�ҩ", ({"yunnan baiyao", "baiyao", "yao","drug"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ƿ");
		set("long", "����һƿ���ص����ϰ�ҩ��ʡ�ŵ��á�\n");
		set("value", 5000);
		set("no_sell",1);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
		return notify_fail("��Ҫ��ʲôҩ��\n");
	if ((int)this_player()->query("eff_kee") == 
	    (int)this_player()->query("max_kee"))
		return notify_fail("û�����ҳ�ҩ��\n");
	else {
		this_player()->receive_curing("kee", 50);
		message_vision("$N����ƿ���ϰ�ҩ������һ��������������ȥ��\n", this_player());
		destruct(this_object());
		return 1;
	}
}

