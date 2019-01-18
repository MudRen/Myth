// lingdan.c �鵤 

inherit ITEM;

void destroy();

void init()
{
//	if (!wizardp(this_player())) {
//		set("no_give", "�����������������ˡ�\n");
//		set("no_drop", "��ô������鵤����������! \n");
//	}
	add_action("do_eat", "eat");
	call_out("destroy", 120);
}

void create()
{
	set_name("�鵤", ({"lingdan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����ص��鵤������ȥ�ܹ�������Ѫ������ʱ��һ��ҩ�Ծͻ���ʧ���鵤Ҳ����Ӱ���ٵġ�\n");
		set("value", 5000);
        set("drug_type", "��Ʒ");
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");
	if ((int)this_player()->query("eff_sen") == 
	    (int)this_player()->query("max_sen"))
		return notify_fail("�����ھ�Ѫ���㡣\n");
	else {
		this_player()->receive_curing("sen", 50);
		message_vision("$N����һ���鵤������һ�ӣ���Ҳû����������ȥ��\n", this_player());
		destruct(this_object());
		return 1;
	}
}

void destroy()
{
destruct(this_object());
}

