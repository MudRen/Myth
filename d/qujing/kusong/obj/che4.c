//Cracked by Roath

inherit ITEM;


void create()
{
        set_name("��", ({ "huo che"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("no_get",1);
                set("long","һ���ܲ�Ѱ���ĳ���\n");
        }
}

void init()
{
        add_action("do_break","break");
}

int do_break(string arg)
{
        object ob = this_player();
        object where = environment();
        object hong=find_living("honghai er");

        if( ! arg || arg != "huo che" )
                return notify_fail("��Ҫ��ʲô��\n");

        if( this_object()->query_temp("bad") )
                return notify_fail("���Ѿ����һ��ˡ�\n");

        if( ob->query("force") < 500 )
                return notify_fail("�������������\n");

        if( present("honghai er",where) )
                {
               tell_object(ob,"�캢��������һ��������ס�֡�\n"); 
               hong->kill_ob(ob);
               return 1;
                }

        message_vision("ֻ��$N���Ż𳵺�������ȥ��û���ʱ�䣬�𳵾ͱ��Ҹ�ϡ���á�\n",ob);
        ob->set_temp("che4_broken",1);
        call_out("honghaier_appearing",1,ob);ob->set("force",10);
        destruct(this_object());
        return 1;
}
void honghaier_appearing (object who)
{
	object honghaier = new ("/d/qujing/kusong/npc/honghaier");   
	honghaier->announce_success (who);
	
}   