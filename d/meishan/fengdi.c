//  ����֮��  ������
//  by happ@YSZZ 2000.04.09
//  .... 

inherit ROOM;

void create ()
{
  set ("short", "�ȵ�");
  set ("long", @LONG

���Ϸ����Ƿɷ�壬��Ҳ������Լ�����ô�ᵽ����ط��ġ��Ա�
�ĵ��Ϻ��������Щʲô������

LONG);
  set("outdoors", 1);
  setup();
}

void init()
{
        add_action("do_climb", "climb");
        add_action("do_dig","dig");
}

int do_climb(string arg)
{
        object ob = this_player();
 
                 if( ! arg || arg != "cliff" )
                        return notify_fail("��Ҫ��ʲô��\n");

                if ( random(4) == 2 )
                   {
                     message_vision("ֻ��$Nһͷ����������\n",ob);
                     ob->unconcious();
                    return 1;
                    }
            message_vision("ֻ��$NС�ĵ�������ȥ��\n",ob);
            ob->move("/d/meishan/cuiping");
            return 1;
}

int do_dig(string arg)
{
        object ob = this_player();
        object wield;
        object zhu=new("/d/obj/baowu/tuzhu");
                
        if ( ! arg || arg != "di" )
                return notify_fail("��Ҫ��ʲô��\n");

        if( ob->query_temp("tz_find") )
                return notify_fail("����ô��ô̰�ġ�\n");

        if(!wield=ob->query_temp("weapon"))
                return notify_fail("������û��������\n");

        if(((string)wield->query("skill_type")!="sword"
             && ((string)wield->query("skill_type")!="blade")))
                return notify_fail("��Ӧ���Ұѽ������ǵ�ʲô�ġ�\n");

        if( random(6) == 3 )
            {
         ob->add("kee",-50);
         message_vision("$N��������һ�ᣬͻȻ�о��и��������ڵ��¡�\n",ob);
         message_vision("$N��Ȼ����һ�������顣\n",ob);
         zhu->move(ob);
         ob->set_temp("tz_find",1);
         return 1;
             }
        ob->add("kee",-50);
        message_vision("$N���˴����ľ���ʲôҲû���ڵ���\n",ob);
        return 1;
}
