// magic_seal.c

inherit ITEM;

void create()
{
	set_name("����", ({"seal"}) );
	set_weight(5);
	set("long",
		"����һ�Ż��õķ��䣬�� attach ָ����Խ�������ĳ��(��ĳ��)���ϡ�\n");
	set("unit", "��");
}

int unequip()
{
	set("equipped", 0);
	return 1;
}

void init()
{
	add_action("do_attach", "attach");
}

int do_attach(string arg)
{
	string sheet, dest;
	object ob;
	function f;

	if( !arg || sscanf(arg, "%s to %s", sheet, dest)!=2 )
		return notify_fail("ָ���ʽ��attach <����> to <Ŀ��>\n");
	
	if( !id(sheet) ) return 0;

	ob = present(dest, this_player());
	if( !ob ) ob = present(dest, environment(this_player()));
	if( !ob ) return notify_fail("��Ҫ��ʲô����ʹ�����ŷ��䣿\n");

	if( !functionp(f = query("attach_func", 1)) )
		return notify_fail("���ŷ�û���á�\n");

	if( evaluate(f, ob) ) {
		if( ob!=this_player() )
			message_vision("$N�ó�һ��" + name() + "��$nһ����\n", this_player(), ob);
		if( ob && ob->is_character() ) {
			move(ob);
			set("equipped", "sealed");
			set("no_drop", "�����������ܶ����������� detach��\n");
		} else destruct(this_object());
		return 1;
	} else 
		return 0;
}
