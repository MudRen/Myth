inherit ITEM;

void kick();

void create()
{
        set_name("��ʯ",({"stone"}));
        set_weight(500000);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("long", "һ������ߵ���ʯ��\n");
                set("unit", "��");
    }

        setup();
}

void init()
{
        add_action("do_kick", "kick");
}


int do_kick(string arg)
{
	object ob;
	
	if(arg=="stone") {
		message_vision("$Nһ���ߵ���ʯͷ�ϣ�ʹ�������ҽУ�\n\n", this_player());
		message("vision", "��ʯ���˶�����վ��������\n\n", environment());
		seteuid(getuid());
		if(ob=new("/d/qujing/bibotan/npc/shitoujing"))
		ob->move(environment(this_object()));
		message_vision("ʯͷ������$Nһ�ۣ�˵��������ô��ôС�ľ����������������������أ�\n",this_player());
		call_out("destroy", 1, this_object());
		return 1;
	}
	return 1;
}
void destroy(object me)
{
        destruct(me);
        return;
}

