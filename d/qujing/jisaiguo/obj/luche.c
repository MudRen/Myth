inherit ITEM;

void create()
{
        set_name("С¿��", ({ "che" }));
	set_weight(500000);
        set_max_encumbrance(1000000);
	set("unit", "��");
	set("value", 1);
        set("no_get", 1);
        set("long", "�˻���С¿��������װ��(load)��\n");
}

void init()
{
        add_action("do_load", "load");
	add_action("do_get", "get");
	add_action("do_put", "put");
}

int do_load(string arg)
{
        object ob;

        if( !arg ) return 0;

	if( (arg!="box") && (arg!="big box"))
		return
notify_fail("����ʽ����˵����ֻװ������Ļ���\n");

        ob = present(arg, this_player());
        if( !ob ) return notify_fail("��Ҫװʲô��С¿����\n");

        message_vision("$N��$nװ����С¿����\n", this_player(), ob);
        ob->move(this_object());
        this_player()->add_temp("wage_deserved", 1);

        if( sizeof(all_inventory()) >= 10 ) {
                write("����ʽС����һ�����С¿�����ˡ�\n");

                destruct(this_object());
        }

        return 1;
}
int put(string arg)
{	        
	if( sscanf(arg, "%s in che"))
		return notify_fail("ʲô��\n");
	return 1;
}

int get(string arg)
{	if( sscanf(arg, "%s from che"))
  		return notify_fail("ʲô��\n");
	return 1;
}

