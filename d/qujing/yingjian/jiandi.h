void init()
{
    object where=this_object();

    add_action("do_feel","tang");
}

int do_feel(string arg)
{
        object me = this_player();
        string place;
        object yao;

        if ( me->is_busy() )
                return notify_fail("����æ���أ�\n");

        if( ! arg || arg != "stone" )
                return notify_fail("��Ҫ��ʲô?\n");
        if( me->query("obstacle/yj") == "done" )
                return notify_fail("��ʲôҲû���ʵ���\n");

        if( me->query_temp("find") )
                return notify_fail("���Ѿ�����ĳ���ط�������ˣ�������ȥ�ң�\n");       

        if( random(5) < 2 )
        {
        place = "/d/qujing/yingjian/jiandi1";
        place[strlen(place)-1] = '0'+random(10);
        message_vision("$N��ϸ�����ʽ��µ�ʯͷ,������Χ��ɺ��������һ�£�\n",me);
message_vision("���ȥ�ң���Ȼһ��������ַ������ˣ�\n",me);
        place->set("exits/down", __DIR__"shanhu");
        me->start_busy(1);     
        me->set_temp("find",1);
remove_call_out("delete");
call_out("delete", 30, place); 
        return 1;
        }

        tell_object(me,"���ˣ��㾪����ˮ�֣�\n");
        yao=new(__DIR__"npc/yao");
        yao->move(environment(me));
        yao->set_leader(me);
        return 1;
        }

void delete(object room)
{
      if(!room) return;
if (room->query("exits/down") ){
room->delete("exits/down");
}
else return;
}
